// SPDX-License-Identifier: MPL-2.0
#include "debug.hpp"
#include "instructions.hpp"
#include "libchata.hpp"
#include "registers.hpp"
#include <bitset>
#include <cstdint>
#include <filesystem>
#include <fstream>
#include <iostream>
#include <string>
#include <utility>
#include <variant>

namespace libchata_internal {

struct instruction {
    RVInstructionID inst;
    RVInstructionFormat type;
    uint8_t rd = 0;
    uint8_t rs1 = 0;
    uint8_t rs2 = 0;
    uint8_t rs3 = 0;
    uint8_t frm = 0;
    int imm = 0;
    bool imm_is_label = false;
};

struct assembly_context {
    chatavector<std::variant<instruction, int>> nodes;
    chatavector<std::pair<chatastring, int>> labels;
    int line = 1;
    int column = 0;
    chatastring inst;
    chatastring arg1;
    chatastring arg2;
    chatastring arg3;
    chatastring arg4;
    chatastring arg5;
};

int string_to_label(chatastring& str, assembly_context& c) {
    while (str.back() == ':') {
        str.pop_back();
    }

    DBG(std::cout << "Converting label " << str << " to int" << std::endl;)

    // Search for the label in the existing labels
    for (const auto& label : c.labels) {
        DBG(std::cout << "Evaluating existing label " << label.first << std::endl;)
        if (label.first == str) {
            DBG(std::cout << "Label " << str << " already exists with value " << label.second << std::endl;)
            return label.second; // Return the existing value
        }
    }

    // If the label doesn't exist, add it and increment the highest value
    int new_label = -1;
    for (const auto& label : c.labels) {
        new_label = std::max(new_label, label.second);
    }
    new_label++;
    c.labels.emplace_back(str, new_label);

    DBG(std::cout << "Label " << str << " added with value " << new_label << std::endl;)

    return new_label;
}

RVInstructionID string_to_instruction(const chatastring& str, assembly_context& c) {
    for (auto& i : instructions) {
        if (i.name == str) {
            return i.id;
        }
    }
    throw ChataError(ChataErrorType::Compiler, "Invalid instruction " + str, c.line, c.column);
}

RVInstructionFormat string_to_instruction_type(const chatastring& str, assembly_context& c) {
    for (auto& i : instructions) {
        if (i.name == str) {
            return i.type;
        }
    }
    throw ChataError(ChataErrorType::Compiler, "Invalid instruction type", c.line, c.column);
}

rvregister string_to_register(const chatastring& str, assembly_context& c) {
    for (auto& r : registers) {
        if (r.name == str || r.alias == str) {
            return r;
        }
    }
    throw ChataError(ChataErrorType::Compiler, "Invalid register " + str, c.line, c.column);
}

rvinstruction get_inst_by_id(RVInstructionID id) {
    for (auto& i : instructions) {
        if (i.id == id) {
            return i;
        }
    }
    throw ChataError(ChataErrorType::Assembler, "Invalid instruction ID " + to_chatastring(std::to_underlying(id)));
}

bool is_pseudoinst(const chatastring& inst) {
    return inst == "li" || inst == "la" || inst == "mv" || inst == "not" || inst == "neg" || inst == "bgt" || inst == "ble" || inst == "bgtu" || inst == "bleu" || inst == "beqz" || inst == "bnez"
           || inst == "bgez" || inst == "blez" || inst == "bgtz" || inst == "j" || inst == "call" || inst == "ret" || inst == "nop" || inst == "fmv.s.x" || inst == "fmv.x.s";
}

uint8_t decode_frm(chatastring& frm) {
    if (frm == "rne") {
        return 0b000;
    } else if (frm == "rtz") {
        return 0b001;
    } else if (frm == "rdn") {
        return 0b010;
    } else if (frm == "rup") {
        return 0b011;
    } else if (frm == "rmm") {
        return 0b100;
    } else if (frm == "dyn") {
        return 0b111;
    } else {
        throw ChataError(ChataErrorType::Compiler, "Invalid rounding mode " + frm);
    }
}

instruction make_inst(assembly_context& c) {
    DBG(std::cout << "Making instruction" << std::endl;)
    DBG(std::cout << "Instruction: " << c.inst << std::endl;)
    DBG(std::cout << "arg1: " << c.arg1 << std::endl;)
    DBG(std::cout << "arg2: " << c.arg2 << std::endl;)
    DBG(std::cout << "arg3: " << c.arg3 << std::endl;)

    instruction i;

    i.inst = string_to_instruction(c.inst, c);
    i.type = string_to_instruction_type(c.inst, c);
    using enum RVInstructionFormat;

    if (i.type == I || i.type == S) {
        try {
            i.imm = to_int(c.arg3);
            i.rs1 = string_to_register(c.arg2, c).encoding;
        } catch (...) {
            // Check if arg2 fits the template offset(reg)
            int offset = 0;
            int j = 0;
            for (; std::isdigit(c.arg2.at(j)); j++) {
                offset = offset * 10 + (c.arg2.at(j) - '0');
            }
            i.imm = offset;
            if (c.arg2.at(j) != '(') {
                throw ChataError(ChataErrorType::Compiler, "Invalid immediate", c.line, c.column);
            }
            j++;
            chatastring reg;
            for (; c.arg2.at(j) != ')'; j++) {
                reg.push_back(c.arg2.at(j));
            }
            i.rs1 = string_to_register(reg, c).encoding;
        }
    } else if (i.type == B) {
        try {
            i.imm = to_int(c.arg3);
        } catch (...) {
            i.imm = string_to_label(c.arg3, c);
            i.imm_is_label = true;
        }
    } else if (i.type == U) {
        try {
            i.imm = to_int(c.arg2);
        } catch (...) {
            throw ChataError(ChataErrorType::Compiler, "Invalid immediate", c.line, c.column);
        }
    } else if (i.type == J) {
        try {
            i.imm = to_int(c.arg2);
        } catch (...) {
            i.imm = string_to_label(c.arg2, c);
            i.imm_is_label = true;
        }
    }

    if (i.type == R || i.type == R4) {
        i.rd = string_to_register(c.arg1, c).encoding;
        i.rs1 = string_to_register(c.arg2, c).encoding;
        auto this_inst = get_inst_by_id(i.inst);
        auto no_rs2 = this_inst.ssargs.has_value() && this_inst.ssargs.value().rs2.has_value();
        if (!no_rs2) {
            i.rs2 = string_to_register(c.arg3, c).encoding;
        } else {
            i.rs2 = this_inst.ssargs.value().rs2.value();
        }
        if (i.type == R) {
            if (!c.arg4.empty() && no_rs2) {
                i.frm = decode_frm(c.arg4);
            } else if (!c.arg5.empty() && !no_rs2) {
                i.frm = decode_frm(c.arg5);
            } else {
                if (this_inst.ssargs.has_value() && this_inst.ssargs.value().use_rm_for_funct3.has_value() && this_inst.ssargs.value().use_rm_for_funct3.value()) {
                    i.frm = 0b111;
                }
            }
        } else if (i.type == R4) {
            i.rs3 = string_to_register(c.arg4, c).encoding;
            if (!c.arg5.empty()) {
                i.frm = decode_frm(c.arg5);
            } else {
                if (this_inst.ssargs.has_value() && this_inst.ssargs.value().use_rm_for_funct3.has_value() && this_inst.ssargs.value().use_rm_for_funct3.value()) {
                    i.frm = 0b111;
                }
            }
        }
    } else if (i.type == I) {
        i.rd = string_to_register(c.arg1, c).encoding;
    } else if (i.type == S) {
        i.rs2 = string_to_register(c.arg1, c).encoding;
    } else if (i.type == B) {
        i.rs1 = string_to_register(c.arg1, c).encoding;
        i.rs2 = string_to_register(c.arg2, c).encoding;
    } else if (i.type == U) {
        i.rd = string_to_register(c.arg1, c).encoding;
    } else if (i.type == J) {
        i.rd = string_to_register(c.arg1, c).encoding;
    }

    DBG(std::cout << "Instruction made" << std::endl;)

    return i;
}

chatavector<instruction> make_inst_from_pseudoinst(assembly_context& c) {
    if (c.inst == "li") { // li rd, imm -> lui rd, imm[31:12]; addi rd, rd, imm[11:0]
        // Case 1: imm is a 12-bit signed integer
        int imm;
        try {
            imm = to_int(c.arg2);
        } catch (...) {
            throw ChataError(ChataErrorType::Compiler, "Invalid immediate " + c.arg2, c.line, c.column);
        }
        if (imm >= -2048 && imm <= 2047) {
            c.inst = "addi";
            c.arg2 = "zero";
            c.arg3 = to_chatastring(imm);
            return {make_inst(c)};
        }
        // Case 2: imm is anything else, split into two instructions, the first assigning the upper 20 bits and the second the lower 12 bits
        c.inst = "lui";
        c.arg2 = to_chatastring(imm >> 12);
        instruction i1 = make_inst(c);
        c.inst = "addi";
        c.arg2 = c.arg1;
        c.arg3 = to_chatastring(imm & 0xFFF);
        instruction i2 = make_inst(c);
        return {i1, i2};
    } else if (c.inst == "la") { // la rd, imm -> auipc rd, imm[31:12]; addi rd, rd, imm[11:0]
        // Case 1: imm is a 12-bit signed integer
        int imm;
        try {
            imm = to_int(c.arg2);
        } catch (...) {
            throw ChataError(ChataErrorType::Compiler, "Invalid immediate " + c.arg2, c.line, c.column);
        }
        if (imm >= -2048 && imm <= 2047) {
            c.inst = "addi";
            c.arg2 = "zero";
            c.arg3 = to_chatastring(imm);
            return {make_inst(c)};
        }
        // Case 2: imm is anything else, split into two instructions, the first assigning the upper 20 bits and the second the lower 12 bits
        c.inst = "auipc";
        c.arg2 = to_chatastring(imm >> 12);
        instruction i1 = make_inst(c);
        c.inst = "addi";
        c.arg2 = c.arg1;
        c.arg3 = to_chatastring(imm & 0xFFF);
        instruction i2 = make_inst(c);
        return {i1, i2};

    } else if (c.inst == "mv") { // mv rd, rs -> addi rd, rs, 0
        c.inst = "addi";
        c.arg3 = "0";
        return {make_inst(c)};
    } else if (c.inst == "not") { // not rd, rs -> xori rd, rs, -1
        c.inst = "xori";
        c.arg3 = "-1";
        return {make_inst(c)};
    } else if (c.inst == "neg") { // neg rd, rs -> sub rd, zero, rs
        c.inst = "sub";
        c.arg3 = c.arg2;
        c.arg2 = "zero";
        return {make_inst(c)};
    } else if (c.inst == "bgt") { // bgt rs1, rs2, label|imm -> blt rs2, rs1, label|imm
        c.inst = "blt";
        std::swap(c.arg1, c.arg2);
        return {make_inst(c)};
    } else if (c.inst == "ble") { // ble rs1, rs2, label|imm -> bge rs2, rs1, label|imm
        c.inst = "bge";
        std::swap(c.arg1, c.arg2);
        return {make_inst(c)};
    } else if (c.inst == "bgtu") { // bgtu rs1, rs2, label|imm -> bltu rs2, rs1, label|imm
        c.inst = "bltu";
        std::swap(c.arg1, c.arg2);
        return {make_inst(c)};
    } else if (c.inst == "bleu") { // bleu rs1, rs2, label|imm -> bgeu rs2, rs1, label|imm
        c.inst = "bgeu";
        std::swap(c.arg1, c.arg2);
        return {make_inst(c)};
    } else if (c.inst == "beqz") { // beqz rs, label|imm -> beq rs, zero, label|imm
        c.inst = "beq";
        c.arg3 = c.arg2;
        c.arg2 = "zero";
        return {make_inst(c)};
    } else if (c.inst == "bnez") { // bnez rs, label|imm -> bne rs, zero, label|imm
        c.inst = "bne";
        c.arg3 = c.arg2;
        c.arg2 = "zero";
        return {make_inst(c)};
    } else if (c.inst == "bgez") { // bgez rs, label|imm -> bge rs, zero, label|imm
        c.inst = "bge";
        c.arg3 = c.arg2;
        c.arg2 = "zero";
        return {make_inst(c)};
    } else if (c.inst == "blez") { // blez rs, label|imm -> bge zero, rs, label|imm
        c.inst = "bge";
        c.arg3 = c.arg2;
        c.arg2 = c.arg1;
        c.arg1 = "zero";
        return {make_inst(c)};
    } else if (c.inst == "bgtz") { // bgtz rs, label|imm -> blt zero, rs, label|imm
        c.inst = "blt";
        c.arg3 = c.arg2;
        c.arg2 = c.arg1;
        c.arg1 = "zero";
        return {make_inst(c)};
    } else if (c.inst == "j") {
        c.inst = "jal";
        c.arg2 = c.arg1;
        c.arg1 = "zero";
        return {make_inst(c)};

    } else if (c.inst == "call") {
        // Case 1: imm is a 12-bit signed integer
        int imm;
        try {
            imm = to_int(c.arg1);
        } catch (...) {
            throw ChataError(ChataErrorType::Compiler, "Invalid immediate " + c.arg1, c.line, c.column);
        }
        if (imm >= -2048 && imm <= 2047) {
            c.inst = "jalr";
            c.arg3 = c.arg1;
            c.arg2 = "ra";
            c.arg1 = "ra";
            return {make_inst(c)};
        }
        // Case 2: imm is anything else, split into two instructions, the first assigning the upper 20 bits and the second the lower 12 bits

    } else if (c.inst == "ret") {
        c.inst = "jalr";
        c.arg1 = "zero";
        c.arg2 = "ra";
        c.arg3 = "0";
        return {make_inst(c)};
    } else if (c.inst == "nop") {
        c.inst = "addi";
        c.arg1 = "zero";
        c.arg2 = "zero";
        c.arg3 = "0";
        return {make_inst(c)};
    } else if (c.inst == "fmv.s.x") {
        c.inst = "fmv.w.x";
        return {make_inst(c)};
    } else if (c.inst == "fmv.x.s") {
        c.inst = "fcvt.x.w";
        return {make_inst(c)};
    }
    return {};
}

void parse_this_line(chatastring& this_line, assembly_context& c) {
    c.inst.clear();
    c.arg1.clear();
    c.arg2.clear();
    c.arg3.clear();
    c.arg4.clear();
    c.arg5.clear();
    for (size_t i = 0; i < this_line.size(); i++) {
        auto ch = [&]() {
            return this_line.at(i);
        };
        for (; i < this_line.size() && std::isspace(ch()); i++) {
            c.column++;
        }
        for (; i < this_line.size() && !std::isblank(ch()); i++) {
            c.inst.push_back(ch());
            c.column++;
        }
        DBG(std::cout << "Instruction candidate: " << c.inst << std::endl;)
        if (c.inst.front() == '.' || c.inst.front() == '#' || c.inst.back() == ':') {
            DBG(std::cout << "Looks like this is a label or a comment or a directive" << std::endl;)
            // if (c.inst.find(generated_label_prefix) != std::string::npos) {
            if (c.inst.back() == ':') {
                DBG(std::cout << "Looks like this is a label!" << std::endl;)
                c.nodes.push_back(string_to_label(c.inst, c));
            }
            break;
        }
        auto parse_arg = [&](chatastring& arg) {
            for (; i < this_line.size() && (std::isblank(ch()) || ch() == ','); i++) {
                c.column++;
            }
            for (; i < this_line.size() && (!std::isblank(ch()) && ch() != ','); i++) {
                arg.push_back(ch());
                c.column++;
            }
        };
        parse_arg(c.arg1);
        parse_arg(c.arg2);
        parse_arg(c.arg3);
        parse_arg(c.arg4);
        parse_arg(c.arg5);
    }
}

void solve_label_offsets(assembly_context& c) {
    auto bytes_in_instruction = [](const instruction& i) {
        using enum RVInstructionFormat;
        if (i.type == R || i.type == R4 || i.type == I || i.type == S || i.type == B || i.type == U || i.type == J) {
            return 4;
        } else if (i.type == CR || i.type == CI || i.type == CSS || i.type == CIW || i.type == CL || i.type == CS || i.type == CA || i.type == CB || i.type == CJ) {
            return 2;
        }
        throw ChataError(ChataErrorType::Assembler, "Invalid instruction type");
    };

    for (size_t i = 0; i < c.nodes.size(); i++) {
        if (std::holds_alternative<instruction>(c.nodes.at(i))) {
            auto& inst = std::get<instruction>(c.nodes.at(i));
            if (inst.imm_is_label) {
                DBG(std::cout << "Label " << inst.imm << " found, searching for offset" << std::endl;)
                auto search_for_label = [&](int end, int step) {
                    int label_offset = 0;
                    for (int j = i + step; j != end; j += step) {
                        if (std::holds_alternative<int>(c.nodes.at(j))) {
                            if (std::get<int>(c.nodes.at(j)) == inst.imm) {
                                label_offset += bytes_in_instruction(inst);
                                DBG(std::cout << "Found offset for label " << inst.imm << ": " << label_offset << std::endl;)
                                inst.imm = label_offset;
                                inst.imm_is_label = false;
                                break;
                            }
                        }
                        if (std::holds_alternative<instruction>(c.nodes.at(j))) {
                            label_offset += bytes_in_instruction(std::get<instruction>(c.nodes.at(j)));
                        }
                    }
                    return label_offset;
                };
                int label_offset = search_for_label(c.nodes.size(), 1);
                if (inst.imm_is_label) {
                    DBG(std::cout << "Label not found, searching backwards" << std::endl;)
                    label_offset = search_for_label(-1, -1);
                }
                if (inst.imm_is_label) {
                    throw ChataError(ChataErrorType::Assembler, "Label " + to_chatastring(inst.imm) + " not found", 0, 0);
                }
            }
        }
    }
}

chatastring generate_machine_code(assembly_context& c) {
    chatastring machine_code;
    for (auto& n : c.nodes) {
        if (!std::holds_alternative<instruction>(n)) {
            continue;
        }
        auto i = std::get<instruction>(n);
        uint32_t inst = 0;
        int bytes = 4;
        auto core_inst = get_inst_by_id(i.inst);
        inst |= core_inst.opcode;
        using enum RVInstructionFormat;
        if (i.type == R) {
            DBG(std::cout << "Encoding R-type instruction with name " << core_inst.name << std::endl;)
            inst |= i.rd << 7;     // Add rd
            if (core_inst.ssargs.has_value() && core_inst.ssargs.value().use_rm_for_funct3.has_value() && core_inst.ssargs.value().use_rm_for_funct3.value()) {
                inst |= i.frm << 12; // Add frm
            } else {
                inst |= (core_inst.funct & 0b111) << 12;       // Add funct3
            }
            inst |= i.rs1 << 15; // Add rs1
            inst |= i.rs2 << 20; // Add rs2
            inst |= (core_inst.funct >> 3) << 25;          // Add funct7
        } else if (i.type == I) {
            DBG(std::cout << "Encoding I-type instruction with name " << core_inst.name << std::endl;)
            inst |= i.rd << 7;   // Add rd
            inst |= core_inst.funct << 12;               // Add funct3
            inst |= i.rs1 << 15; // Add rs1
            inst |= i.imm << 20;                         // Add imm
        } else if (i.type == S) {
            DBG(std::cout << "Encoding S-type instruction with name " << core_inst.name << std::endl;)
            inst |= (i.imm & 0b11111) << 7;              // Add imm[4:0]
            inst |= core_inst.funct << 12;               // Add funct3
            inst |= i.rs1 << 15; // Add rs1
            inst |= i.rs2 << 20; // Add rs2
            inst |= (i.imm >> 5) << 25;                  // Add imm[11:5]
        } else if (i.type == B) {
            DBG(std::cout << "Encoding B-type instruction with name " << core_inst.name << std::endl;)
            inst |= ((i.imm >> 11) & 0b1) << 7;          // Add imm[11]
            inst |= ((i.imm >> 1) & 0b1111) << 8;              // Add imm[4:1]
            inst |= core_inst.funct << 12;               // Add funct3
            inst |= i.rs1 << 15; // Add rs1
            inst |= i.rs2 << 20; // Add rs2
            inst |= ((i.imm >> 5) & 0b111111) << 25;                  // Add imm[10:5]
            inst |= ((i.imm >> 12) & 0b1) << 31;                 // Add imm[12]
        } else if (i.type == U) {
            DBG(std::cout << "Encoding U-type instruction with name " << core_inst.name << std::endl;)
            inst |= i.rd << 7; // Add rd
            inst |= i.imm << 12;                       // Add imm[31:12]
        } else if (i.type == J) {
            DBG(std::cout << "Encoding J-type instruction with name " << core_inst.name << std::endl;)
            inst |= i.rd << 7;       // Add rd
            inst |= ((i.imm >> 12) & 0b11111111) << 12;              // Add imm[19:12]
            inst |= ((i.imm >> 11) & 0b1) << 20;          // Add imm[11]
            inst |= ((i.imm >> 1) & 0b1111111111) << 21;           // Add imm[10:1]
            inst |= ((i.imm >> 20) & 0b1) << 31; // Add imm[20]
        } else if (i.type == R4) {
            DBG(std::cout << "Encoding R4-type instruction with name " << core_inst.name << std::endl;)
            inst |= i.rd << 7;     // Add rd
            inst |= (core_inst.funct & 0b111) << 12;       // Add funct3
            inst |= i.rs1 << 15; // Add rs1
            inst |= i.rs2 << 20; // Add rs2
            inst |= (core_inst.funct >> 3) << 25;          // Add funct2
            inst |= i.rs3 << 27; // Add rs3
        } else if (i.type == CR) {

        } else if (i.type == CI) {

        } else if (i.type == CSS) {

        } else if (i.type == CIW) {

        } else if (i.type == CL) {

        } else if (i.type == CS) {

        } else if (i.type == CA) {

        } else if (i.type == CB) {

        } else if (i.type == CJ) {
        }
        if (bytes == 4) {
            machine_code.push_back((inst >> 0) & 0xFF);
            machine_code.push_back((inst >> 8) & 0xFF);
            machine_code.push_back((inst >> 16) & 0xFF);
            machine_code.push_back((inst >> 24) & 0xFF);
        } else if (bytes == 2) {
            machine_code.push_back((inst >> 0) & 0xFF);
            machine_code.push_back((inst >> 8) & 0xFF);
        }
    }
    return machine_code;
}

chatastring new_assembler(const chatastring& data) {
    chatastring machine_code;
    chatastring this_line;
    struct assembly_context c;
    for (size_t i = 0; i < data.size(); i++) {
        this_line.push_back(data.at(i));
        if (data.at(i) == '\n' || i == data.size() - 1) {
            if (data.at(i) == '\n') {
                this_line.pop_back();
            }
            parse_this_line(this_line, c);
            for (auto& i : instructions) {
                if (i.name == c.inst) {
                    c.nodes.push_back(make_inst(c));
                    break;
                } else if (is_pseudoinst(c.inst)) {
                    for (auto& inst : make_inst_from_pseudoinst(c)) {
                        c.nodes.push_back(inst);
                    }
                    break;
                }
            }
            this_line.clear();
            c.line++;
            c.column = 0;
            continue;
        }
    }

    for (auto& i : c.nodes) {
        if (!std::holds_alternative<instruction>(i)) {
            DBG(std::cout << "Label: " << std::get<int>(i) << std::endl;)
            continue;
        }
        auto this_i = std::get<instruction>(i);
        chatastring string_representation;
        for (auto& inst : instructions) {
            if (inst.id == this_i.inst) {
                string_representation = inst.name;
                break;
            }
        }
        DBG(std::cout << "Instruction: " << string_representation << std::endl;)
        if (this_i.type == RVInstructionFormat::R) {
            DBG(std::cout << "Instruction type: R" << std::endl;)
        } else if (this_i.type == RVInstructionFormat::I) {
            DBG(std::cout << "Instruction type: I" << std::endl;)
        } else if (this_i.type == RVInstructionFormat::S) {
            DBG(std::cout << "Instruction type: S" << std::endl;)
        } else if (this_i.type == RVInstructionFormat::B) {
            DBG(std::cout << "Instruction type: B" << std::endl;)
        } else if (this_i.type == RVInstructionFormat::U) {
            DBG(std::cout << "Instruction type: U" << std::endl;)
        } else if (this_i.type == RVInstructionFormat::J) {
            DBG(std::cout << "Instruction type: J" << std::endl;)
        }
        for (auto& reg : registers) {
            if (reg.encoding == this_i.rd) {
                DBG(std::cout << "rd: " << reg.alias << std::endl;)
            }
            if (reg.encoding == this_i.rs1) {
                DBG(std::cout << "rs1: " << reg.alias << std::endl;)
            }
            if (reg.encoding == this_i.rs2) {
                DBG(std::cout << "rs2: " << reg.alias << std::endl;)
            }
        }
        if (!this_i.imm_is_label) {
            DBG(std::cout << "offset: " << this_i.imm << std::endl;)
        } else {
            DBG(std::cout << "label: " << this_i.imm << std::endl;)
        }
    }

    solve_label_offsets(c);

    machine_code = generate_machine_code(c);

    DBG(std::cout << "Ok, here's the assembled code:" << std::endl;)
    // Show the code in hex form
    for (auto c : machine_code) {
        printf("%02x ", c);
    }

    DBG(std::cout << "Let's compare this against the reference, gcc as" << std::endl;)

    std::ofstream out("temp.s");
    out << data;
    out.close();

    int res = std::system("riscv64-linux-gnu-as temp.s -o temp.o");

    if (res != 0) {
        // DBG(std::cout << "error in command riscv64-linux-gnu-as temp.s -o temp.o" << std::endl;)
            // exit(1);
        throw ChataError(ChataErrorType::Assembler, "error in command riscv64-linux-gnu-as temp.s -o temp.o", 0, 0);
    }

    res = std::system("riscv64-linux-gnu-objcopy -O binary temp.o temp.bin");

    if (res != 0) {
        // DBG(std::cout << "error in command riscv64-linux-gnu-objcopy -O binary temp.o temp.bin" << std::endl;)
        // exit(1);
        throw ChataError(ChataErrorType::Assembler, "error in command riscv64-linux-gnu-objcopy -O binary temp.o temp.bin", 0, 0);
    }

    std::ifstream in("temp.bin", std::ios::binary);
    chatastring result((std::istreambuf_iterator<char>(in)), std::istreambuf_iterator<char>());
    in.close();

    std::filesystem::remove("temp.s");
    // std::filesystem::remove("temp.o");
    std::filesystem::remove("temp.bin");

    DBG(std::cout << "Ok, here's the reference code:" << std::endl;)
    // Show the code in hex form
    for (auto c : result) {
        printf("%02x ", c);
    }

    exit(0);

    return machine_code;
}

chatastring assemble_code(const chatastring& data) {
    bool use_new_assembler = true;

    if (!use_new_assembler) {
        // Assemble by putting everything into a .s file, then invoke as, then convert to binary with objcopy

        std::ofstream out("temp.s");
        out << data;
        out.close();

        int res = std::system("riscv64-linux-gnu-as temp.s -o temp.o");

        if (res != 0) {
            // DBG(std::cout << "error in command riscv64-linux-gnu-as temp.s -o temp.o" << std::endl;)
            // exit(1);
            throw ChataError(ChataErrorType::Assembler, "error in command riscv64-linux-gnu-as temp.s -o temp.o", 0, 0);
        }

        res = std::system("riscv64-linux-gnu-objcopy -O binary temp.o temp.bin");

        if (res != 0) {
            // DBG(std::cout << "error in command riscv64-linux-gnu-objcopy -O binary temp.o temp.bin" << std::endl;)
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