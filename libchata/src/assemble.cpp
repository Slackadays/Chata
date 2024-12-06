#include "libchata.hpp"
#include <filesystem>
#include <fstream>
#include <iostream>
#include <bitset>
#include <variant>

namespace libchata_internal {

chatavector<chatastring> code_labels;

enum class RV32IInstructions {
    LUI,
    AUIPC,
    JAL,
    JALR,
    BEQ,
    BNE,
    BLT,
    BGE,
    BLTU,
    BGEU,
    LB,
    LH,
    LW,
    LBU,
    LHU,
    SB,
    SH,
    SW,
    ADDI,
    SLTI,
    SLTIU,
    XORI,
    ORI,
    ANDI,
    SLLI,
    SRLI,
    SRAI,
    ADD,
    SUB,
    SLL,
    SLT,
    SLTU,
    XOR,
    SRL,
    SRA,
    OR,
    AND,
    FENCE,
    FENCETSO,
    PAUSE,
    ECALL,
    EBREAK
};

enum class RV64IInstructions {
    LWU,
    LD,
    SD,
    ADDIW,
    SLLIW,
    SRLIW,
    SRAIW,
    ADDW,
    SUBW,
    SLLW,
    SRLW,
    SRAW
};

enum class RV32FInstructions {
    FMADDS,
    FMSUBS,
    FNMSUBS,
    FNMADDS,
    FADDS,
    FSUBS,
    FMULS,
    FDIVS,
    FSQRTS,
    FSGNJS,
    FSGNJNS,
    FSGNJXS,
    FMINS,
    FMAXS,
    FCVTWS,
    FCVTWUS,
    FMVXW,
    FEQS,
    FLTS,
    FLES,
    FCLASSS,
    FCVTSW,
    FCVTSWU,
    FMVWX,
    FLW,
    FSW
};

enum class RV64FInstructions {
    FCVTLS,
    FCVTLUS,
    FCVTSL,
    FCVTSLU
};

enum class 

enum class InstructionType {
    R,
    I,
    S,
    B,
    U,
    J
};

struct instruction {
    std::variant<RV32IInstructions, chatastring> inst;
    InstructionType type;
    chatastring rd;
    chatastring rs1;
    chatastring rs2;
    chatastring imm;
};

struct assembly_context {
    int line = 1;
    int column = 0;
    chatastring inst;
    chatastring arg1;
    chatastring arg2;
    chatastring arg3;
};

instruction make_R_type_inst(assembly_context& c) {
    instruction i;
    i.inst = c.inst;
    i.type = InstructionType::R;
    i.rd = c.arg1;
    i.rs1 = c.arg2;
    i.rs2 = c.arg3;
    return i;
}

instruction make_I_type_inst(assembly_context& c) {
    instruction i;
    i.inst = c.inst;
    i.type = InstructionType::I;
    i.rd = c.arg1;
    i.rs1 = c.arg2;
    i.imm = c.arg3;
    return i;
}

instruction make_S_type_inst(assembly_context& c) {
    instruction i;
    i.inst = c.inst;
    i.type = InstructionType::S;
    i.rs1 = c.arg1;
    i.rs2 = c.arg2;
    i.imm = c.arg3;
    return i;
}

instruction make_B_type_inst(assembly_context& c) {
    instruction i;
    i.inst = c.inst;
    i.type = InstructionType::B;
    i.rs1 = c.arg1;
    i.rs2 = c.arg2;
    i.imm = c.arg3;
    return i;
}

instruction make_U_type_inst(assembly_context& c) {
    instruction i;
    i.inst = c.inst;
    i.type = InstructionType::U;
    i.rd = c.arg1;
    i.imm = c.arg2;
    return i;
}

instruction make_UJ_type_inst(assembly_context& c) {
    instruction i;
    i.inst = c.inst;
    i.type = InstructionType::J;
    i.rd = c.arg1;
    i.rs1 = c.arg2;
    i.imm = c.arg3;
    return i;
}

void parse_this_line(chatastring& this_line, assembly_context& c) {
    for (int i = 0; i < this_line.size(); i++) {
        auto ch = [&]() {
            return this_line.at(i);
        };
        for (; i < this_line.size() && std::isspace(ch()); i++) {
            c.column++;
        }
        for (; i < this_line.size() && (std::islower(ch()) || ch() == '.'); i++) {
            c.inst.push_back(ch());
            c.column++;
        }
        std::cout << "Instruction candidate: " << instruction << std::endl;
        if (instruction.front() == '.' || instruction.front() == '#' || instruction.back() == ':') {
            std::cout << "Looks like this is a label or a comment or a directive" << std::endl;
            break;
        }
        for (; i < this_line.size() && (std::isblank(ch()) || ch() == ','); i++) {
            c.column++;
        }
        for (; i < this_line.size() && (!std::isblank(ch()) && ch() != ','); i++) {
            c.arg1.push_back(ch());
            c.column++;
        }
        for (; i < this_line.size() && (std::isblank(ch()) || ch() == ','); i++) {
            c.column++;
        }
        for (; i < this_line.size() && (!std::isblank(ch()) && ch() != ','); i++) {
            c.arg2.push_back(ch());
            c.column++;
        }
        for (; i < this_line.size() && (std::isblank(ch()) || ch() == ','); i++) {
            c.column++;
        }
        for (; i < this_line.size() && (!std::isblank(ch()) && ch() != ','); i++) {
            c.arg3.push_back(ch());
            c.column++;
        }
    }
}

void act_on_this_line(chatavector<instruction>& instructions, assembly_context& c) {
    auto is = [&](const chatastring& inst) {
        return c.inst == inst;
    };
    if (is("lui")) {
        instructions.push_back(make_U_type_inst(c));
    } else if (is("auipc")) {
        instructions.push_back(make_U_type_inst(c));
    } else if (is("jal")) {
        instructions.push_back(make_UJ_type_inst(c));
    } else if (is("jalr")) {
        instructions.push_back(make_I_type_inst(c));
    } else if (is("beq")) {
        instructions.push_back(make_B_type_inst(c));
    } else if (is("bne")) {
        instructions.push_back(make_B_type_inst(c));
    } else if (is("blt")) {
        instructions.push_back(make_B_type_inst(c));
    } else if (is("bge")) {
        instructions.push_back(make_B_type_inst(c));
    } else if (is("bltu")) {
        instructions.push_back(make_B_type_inst(c));
    } else if (is("bgeu")) {
        instructions.push_back(make_B_type_inst(c));
    } else if (is("lb")) {
        instructions.push_back(make_I_type_inst(c));
    } else if (is("lh")) {
        instructions.push_back(make_I_type_inst(c));
    } else if (is("lw")) {
        instructions.push_back(make_I_type_inst(c));
    } else if (is("lbu")) {
        instructions.push_back(make_I_type_inst(c));
    } else if (is("lhu")) {
        instructions.push_back(make_I_type_inst(c));
    } else if (is("sb")) {
        instructions.push_back(make_S_type_inst(c));
    } else if (is("sh")) {
        instructions.push_back(make_S_type_inst(c));
    } else if (is("sw")) {
        instructions.push_back(make_S_type_inst(c));
    } else if (is("addi")) {
        instructions.push_back(make_I_type_inst(c));
    } else if (is("slti")) {
        instructions.push_back(make_I_type_inst(c));
    } else if (is("sltiu")) {
        instructions.push_back(make_I_type_inst(c));
    } else if (is("xori")) {
        instructions.push_back(make_I_type_inst(c));
    } else if (is("ori")) {
        instructions.push_back(make_I_type_inst(c));
    } else if (is("andi")) {
        instructions.push_back(make_I_type_inst(c));
    } else if (is("slli")) {
        instructions.push_back(make_I_type_inst(c));
    } else if (is("srli")) {
        instructions.push_back(make_I_type_inst(c));
    } else if (is("srai")) {
        instructions.push_back(make_I_type_inst(c));
    } else if (is("add")) {
        instructions.push_back(make_R_type_inst(c));
    } else if (is("sub")) {
        instructions.push_back(make_R_type_inst(c));
    } else if (is("sll")) {
        instructions.push_back(make_R_type_inst(c));
    } else if (is("slt")) {
        instructions.push_back(make_R_type_inst(c));
    } else if (is("sltu")) {
        instructions.push_back(make_R_type_inst(c));
    } else if (is("xor")) {
        instructions.push_back(make_R_type_inst(c));
    } else if (is("srl")) {
        instructions.push_back(make_R_type_inst(c));
    } else if (is("sra")) {
        instructions.push_back(make_R_type_inst(c));
    } else if (is("or")) {
        instructions.push_back(make_R_type_inst(c));
    } else if (is("and")) {
        instructions.push_back(make_R_type_inst(c));
    } else if (is("fence")) {
        instructions.push_back(make_I_type_inst(c));
    } else if (is("fence.tso")) {
        instructions.push_back(make_I_type_inst(c));
    } else if (is("pause")) {
        instructions.push_back(make_I_type_inst(c));
    } else if (is("ecall")) {
        instructions.push_back(make_I_type_inst(c));
    } else if (is("ebreak")) {
        instructions.push_back(make_I_type_inst(c));
    }
    
}

chatastring new_assembler(const chatastring& data) {
    chatavector<instruction> instructions;
    int line = 1;
    int column = 0;
    chatastring machine_code;
    chatastring this_line;
    for (int i = 0; i < data.size(); i++) {
        if (data.at(i) == '\n') {
            //chatastring inst, arg1, arg2, arg3; // RISC-V instructions will only ever have up to 3 arguments
            struct assembly_context c;
            parse_this_line(this_line, c);
            act_on_this_line(instructions, c);
            this_line.clear();
            line++;
            column = 0;
            continue;
        }
        this_line.push_back(data.at(i));
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