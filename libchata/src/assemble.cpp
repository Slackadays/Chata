#include "libchata.hpp"
#include <filesystem>
#include <fstream>
#include <iostream>
#include <bitset>

namespace libchata_internal {

struct instruction_parameters {
    chatastring rd;
    chatastring rs1;
    chatastring rs2;
    int imm;
};

chatastring add_instr(chatastring& line) {
    chatastring result;
    result.resize(4);
    chatastring operand_1, operand_2, operand_3;
    int i = 0;
    auto ch = [&]() {
        return line.at(i);
    };
    for (; i < line.size() && std::isblank(ch()); i++) {}
    for (; i < line.size() && is_register_character(ch()); i++) {
        operand_1.push_back(ch());
    }
    for (; i < line.size() && (std::isblank(ch()) || ch() == ','); i++) {}
    for (; i < line.size() && is_register_character(ch()); i++) {
        operand_2.push_back(ch());
    }
    for (; i < line.size() && (std::isblank(ch()) || ch() == ','); i++) {}
    for (; i < line.size() && is_register_character(ch()); i++) {
        operand_3.push_back(ch());
    }
    std::cout << "Operand 1: " << operand_1 << std::endl;
    std::cout << "Operand 2: " << operand_2 << std::endl;
    std::cout << "Operand 3: " << operand_3 << std::endl;
    if (!is_one_of(operand_1, valid_integer_registers)) {
        throw ChataError(ChataErrorType::Assembler, "Error! " + operand_1 + " is not a valid integer register", 0, 0);
    }
    if (!is_one_of(operand_2, valid_integer_registers)) {
        throw ChataError(ChataErrorType::Assembler, "Error! " + operand_2 + " is not a valid integer register", 0, 0);
    }
    if (!is_one_of(operand_3, valid_integer_registers)) {
        throw ChataError(ChataErrorType::Assembler, "Error! " + operand_3 + " is not a valid integer register", 0, 0);
    }
    operand_1 = make_base_register(operand_1);
    operand_2 = make_base_register(operand_2);
    operand_3 = make_base_register(operand_3);
    // Start by setting result to 0110011
    result = 0b0110011;
    // Now add the destination register
    result |= (extract_number_from_string(operand_1) << 7);
    // Now add 000 for the funct3 field (already done)
    // Now add the source register 1
    result |= (extract_number_from_string(operand_2) << 15);
    // Now add the source register 2
    result |= (extract_number_from_string(operand_3) << 20);
    // Now add 0000000 for the funct7 field (already done)
    return result;
}

chatastring new_assembler(const chatastring& data) {
    int line = 1;
    int column = 0;
    chatastring machine_code;
    for (int i = 0; i < data.size(); i++) {
        auto ch = [&]() {
            return data.at(i);
        };
        chatastring this_line;
        chatastring instruction;
        for (; i < data.size() && std::isspace(ch()); i++) {
            column++;
        }
        for (; i < data.size() && is_register_character(ch()); i++) {
            this_line.push_back(ch());
            instruction.push_back(ch());
            column++;
        }
        std::cout << "Instruction candidate: " << instruction << std::endl;
        if (instruction.front() == '.' || instruction.front() == '#' || instruction.back() == ':') {
            std::cout << "Looks like this is a label or a comment or a directive" << std::endl;
            continue;
        }
        for (int j = i; j < data.size(); j++) {
            this_line.push_back(data.at(j));
        }
        if (instruction == "add") {
            machine_code += add_instr(this_line);
        //} else if (instruction == 
        }
    }
    return machine_code;
}

chatastring assemble_code(const chatastring& data) {
    bool use_new_assembler = false;

    if (!use_new_assembler) {
    // Assemble by putting everything into a .s file, then invoke as, then convert to binary with objcopy

    std::ofstream out("temp.s");
    out << data;
    out.close();

    int res = std::system("riscv64-linux-gnu-as temp.s -o temp.o");

    if (res != 0) {
        // std::cout << "error in command riscv64-linux-gnu-as temp.s -o temp.o" << std::endl;
        // exit(1);
        throw ChataError(ChataErrorType::Assembler, "error in command riscv64-linux-gnu-as temp.s -o temp.o", 0, 0);
    }

    res = std::system("riscv64-linux-gnu-objcopy -O binary temp.o temp.bin");

    if (res != 0) {
        // std::cout << "error in command riscv64-linux-gnu-objcopy -O binary temp.o temp.bin" << std::endl;
        // exit(1);
        throw ChataError(ChataErrorType::Assembler, "error in command riscv64-linux-gnu-objcopy -O binary temp.o temp.bin", 0, 0);
    }

    std::ifstream in("temp.bin", std::ios::binary);
    chatastring result((std::istreambuf_iterator<char>(in)), std::istreambuf_iterator<char>());
    in.close();

    std::filesystem::remove("temp.s");
    // std::filesystem::remove("temp.o");
    std::filesystem::remove("temp.bin");

    return result;
    } else {
        return new_assembler(data);
    }
}

} // namespace libchata_internal