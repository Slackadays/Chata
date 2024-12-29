// SPDX-License-Identifier: MPL-2.0
#include "debug.hpp"
#include "instructions.hpp"
#include "libchata.hpp"
#include "registers.hpp"
#include "csrs.hpp"
#include <cstdint>
#include <filesystem>
#include <fstream>
#include <iostream>
#include <string>
#include <utility>

namespace libchata_internal {

enum class InstrImmPurpose : uint8_t {
    INSTR_IMM,
    LABEL_DEST,
    LABEL_NODE
};

using enum InstrImmPurpose;

struct instruction {
    uint16_t inst_offset = 0; // The offset from the instructions array at which our instruction is (saves memory and prevents O(n) lookups)
    uint8_t rd = 0;
    uint8_t rs1 = 0;
    uint8_t rs2 = 0;
    uint8_t rs3 = 0;
    uint8_t frm = 0;
    int32_t imm = 0;
    InstrImmPurpose imm_purpose = INSTR_IMM;
};

struct assembly_context {
    chatavector<instruction> nodes;
    size_t instruction_bytes = 0;
    chatavector<std::pair<chatastring, int>> labels;
    int line = 1;
    int column = 0;
    uint16_t inst_offset = 0;
    chatastring inst;
    chatastring arg1;
    chatastring arg2;
    chatastring arg3;
    chatastring arg4;
    chatastring arg5;
    chatastring arg6;
};

bool fast_eq(const auto& first, const std::string_view& second) {
    if (first.size() != second.size()) { // First make sure the sizes are equal because no two strings can ever be the same if they have different sizes. Also, this lets us save on future bound checks
                                         // because we're already checking it here.
        return false;
    }
    for (size_t i = 0; i < first.size(); i++) {
        if (first[i] != second[i]) {
            [[likely]] return false;
        } else {
            [[unlikely]] continue;
        }
    }
    return true;
}

int string_to_label(chatastring& str, assembly_context& c) {
    while (str.back() == ':') {
        str.pop_back();
    }

    DBG(std::cout << "Converting label " << str << " to int" << std::endl;)

    // Search for the label in the existing labels
    for (const auto& label : c.labels) {
        DBG(std::cout << "Evaluating existing label " << label.first << std::endl;)
        if (fast_eq(label.first, str)) {
            DBG(std::cout << "Label " << str << " already exists with value " << label.second << std::endl;)
            return label.second;
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

rvregister string_to_register(const chatastring& str, assembly_context& c) {
    if (auto reg = fast_reg_search(str); reg != reg_search_failed) {
        return registers[reg];
    }
    throw ChataError(ChataErrorType::Compiler, "Invalid register " + str, c.line, c.column);
}

uint16_t get_inst_offset_by_id(const RVInstructionID& id) {
    for (size_t i = 0; i < instructions.size(); i++) {
        if (instructions.at(i).id == id) {
            return i;
        }
    }
    throw ChataError(ChataErrorType::Assembler, "Invalid instruction ID " + to_chatastring(std::to_underlying(id)));
}

uint8_t decode_frm(const chatastring& frm) {
    if (fast_eq(frm, "rne")) {
        return 0b000;
    } else if (fast_eq(frm, "rtz")) {
        return 0b001;
    } else if (fast_eq(frm, "rdn")) {
        return 0b010;
    } else if (fast_eq(frm, "rup")) {
        return 0b011;
    } else if (fast_eq(frm, "rmm")) {
        return 0b100;
    } else if (fast_eq(frm, "dyn")) {
        return 0b111;
    } else {
        throw ChataError(ChataErrorType::Compiler, "Invalid rounding mode " + frm);
    }
}

uint8_t decode_fence(const chatastring& setting) {
    if (fast_eq(setting, "r")) {
        return 0b0010;
    } else if (fast_eq(setting, "w")) {
        return 0b0001;
    } else if (fast_eq(setting, "rw")) {
        return 0b0011;
    } else {
        throw ChataError(ChataErrorType::Compiler, "Invalid fence setting " + setting);
    }
}

uint16_t decode_csr(const chatastring& csr) {
    for (const auto& c : csrs) {
        if (fast_eq(csr, c.first)) {
            return c.second;
        }
    }
    throw ChataError(ChataErrorType::Compiler, "Invalid CSR " + csr);
}

bool handle_super_special_snowflakes(instruction& i, const rvinstruction& base_i, assembly_context& c) {
    using enum RVInstructionID;
    if (base_i.id == FENCE) {
        i.imm |= decode_fence(c.arg1) << 4; // Add pred
        i.imm |= decode_fence(c.arg2);      // Add succ
        DBG(std::cout << "FENCE instruction made" << std::endl;)
    } else if (base_i.id == FENCETSO) {
        i.imm = 0b100000110011; // Set imm to the TSO fence value
        DBG(std::cout << "FENCE.TSO instruction made" << std::endl;)
    } else if (base_i.id == PAUSE) {
        i.imm = 0b000000010000; // Set imm to the PAUSE value
        DBG(std::cout << "PAUSE instruction made" << std::endl;)
    } else if (base_i.id == ECALL) {
        i.imm = 0b000000000000; // Set imm to the ECALL value
        DBG(std::cout << "ECALL instruction made" << std::endl;)
    } else if (base_i.id == EBREAK) {
        i.imm = 0b000000000001; // Set imm to the EBREAK value
        DBG(std::cout << "EBREAK instruction made" << std::endl;)
    } else if (base_i.id == FENCEI) {
        i.imm = 0b000000000000; // Set imm to the FENCE.I value
        DBG(std::cout << "FENCE.I instruction made" << std::endl;)
    } else if (base_i.id == CSRRW || base_i.id == CSRRS || base_i.id == CSRRC) {
        i.rd = string_to_register(c.arg1, c).encoding;
        i.imm = decode_csr(c.arg2);
        i.rs1 = string_to_register(c.arg3, c).encoding;
        DBG(std::cout << "CSR instruction made" << std::endl;)
    } else if (base_i.id == CSRRWI || base_i.id == CSRRSI || base_i.id == CSRRCI) {
        i.rd = string_to_register(c.arg1, c).encoding;
        i.imm = decode_csr(c.arg2);
        if (auto num = to_int(c.arg3); num.has_value()) {
            i.rs1 = num.value();
        } else {
            throw ChataError(ChataErrorType::Compiler, "Invalid immediate " + c.arg3, c.line, c.column);
        }
        DBG(std::cout << "CSR instruction made" << std::endl;)
    } else if (base_i.id == WRSNTO) {
        i.imm = 0b000000001101; // Set imm to the WRSNTO value
        DBG(std::cout << "WRSNTO instruction made" << std::endl;)
    } else if (base_i.id == WRSSTO) {
        i.imm = 0b000000011101; // Set imm to the WRSSTO value
        DBG(std::cout << "WRSSTO instruction made" << std::endl;)
    } else {
        return false;
    }
    return true;
}

size_t bytes_in_instruction(const rvinstruction& i) {
    uint8_t len_bits = i.opcode & 0b11;
    if (len_bits == 0b00 || len_bits == 0b01 || len_bits == 0b10) {
        return 2;
    } else if (len_bits == 0b11) {
        return 4;
    }
    throw ChataError(ChataErrorType::Assembler, "Invalid instruction length");
}

size_t bytes_in_instruction(const instruction& i) {
    return bytes_in_instruction(instructions.at(i.inst_offset));
}

instruction make_inst(assembly_context& c) {
    DBG(std::cout << "Making instruction" << std::endl;)
    DBG(std::cout << "Instruction: " << c.inst << std::endl;)
    DBG(std::cout << "arg1: " << c.arg1 << std::endl;)
    DBG(std::cout << "arg2: " << c.arg2 << std::endl;)
    DBG(std::cout << "arg3: " << c.arg3 << std::endl;)

    instruction i;

    /*i.inst_offset = get_inst_offset_by_id(RVInstructionID::ADD);
    i.rd = 0;
    i.rs1 = 1;
    i.rs2 = 2;
    c.instruction_bytes += 4;
    return i;*/

    i.inst_offset = c.inst_offset;

    auto base_i = instructions.at(i.inst_offset);

    c.instruction_bytes += bytes_in_instruction(base_i);

    if (handle_super_special_snowflakes(i, base_i, c)) {
        return i;
    }

    using enum RVInstructionFormat;

    if (base_i.type == R) {
        if (base_i.ssargs.use_imm_for_rs2.has_value() && base_i.ssargs.use_imm_for_rs2.value()) {
            if (auto num = to_int(c.arg3); num.has_value()) {
                i.imm = num.value();
            } else {
                throw ChataError(ChataErrorType::Compiler, "Invalid immediate " + c.arg3, c.line, c.column);
            }
        }
    } else if (base_i.type == I || base_i.type == S) {
        if (auto num = to_int(c.arg3); num.has_value()) {
            i.imm = num.value();
            i.rs1 = string_to_register(c.arg2, c).encoding;
        } else {
            // Check if arg2 fits the template offset(reg)
            int offset = 0;
            int j = 0;
            for (; std::isdigit(c.arg2.at(j)); j++) {
                offset = offset * 10 + (c.arg2.at(j) - '0');
            }
            i.imm = offset;
            if (c.arg2.at(j) != '(') {
                throw ChataError(ChataErrorType::Compiler, "Invalid immediate " + c.arg2, c.line, c.column);
            }
            j++;
            chatastring reg;
            for (; c.arg2.at(j) != ')'; j++) {
                reg.push_back(c.arg2.at(j));
            }
            i.rs1 = string_to_register(reg, c).encoding;
        }
    } else if (base_i.type == B) {
        if (auto num = to_int(c.arg3); num.has_value()) {
            i.imm = num.value();
        } else {
            i.imm = string_to_label(c.arg3, c);
            // i.imm_is_label_dest = true;
            i.imm_purpose = LABEL_DEST;
        }
    } else if (base_i.type == U) {
        if (auto num = to_int(c.arg2); num.has_value()) {
            i.imm = num.value();
        } else {
            throw ChataError(ChataErrorType::Compiler, "Invalid immediate " + c.arg2, c.line, c.column);
        }
    } else if (base_i.type == J) {
        if (auto num = to_int(c.arg2); num.has_value()) {
            i.imm = num.value();
        } else {
            i.imm = string_to_label(c.arg2, c);
            // i.imm_is_label_dest = true;
            i.imm_purpose = LABEL_DEST;
        }
    }

    if (base_i.type == R || base_i.type == R4) {
        i.rd = string_to_register(c.arg1, c).encoding;
        if (base_i.set == RVInstructionSet::RV32A || base_i.set == RVInstructionSet::RV64A) { // The RV32A and RV64A sets sometimes use registers that look like (a0)
            if (c.arg2.front() == '0') {
                c.arg2.erase(0, 1);
            }
            if (c.arg2.front() == '(') {
                c.arg2.erase(0, 1);
            }
            if (c.arg2.back() == ')') {
                c.arg2.pop_back();
            }
            if (c.arg3.front() == '0') {
                c.arg3.erase(0, 1);
            }
            if (c.arg3.front() == '(') {
                c.arg3.erase(0, 1);
            }
            if (c.arg3.back() == ')') {
                c.arg3.pop_back();
            }
            using enum RVInstructionID;
            if (base_i.id != LRW && base_i.id != LRWAQ && base_i.id != LRWRL && base_i.id != LRWAQRL && base_i.id != LRD && base_i.id != LRDAQ && base_i.id != LRDRL && base_i.id != LRDAQRL) {
                std::swap(c.arg2, c.arg3); // For the case of instr rd, rs2, (rs1)
            }
        }
        i.rs1 = string_to_register(c.arg2, c).encoding;
        auto no_rs2 = base_i.ssargs.rs2.has_value();
        if (!no_rs2) {
            if (base_i.ssargs.use_imm_for_rs2.has_value() && base_i.ssargs.use_imm_for_rs2.value()) {
                i.rs2 = i.imm;
            } else {
                i.rs2 = string_to_register(c.arg3, c).encoding;
            }
        } else {
            i.rs2 = base_i.ssargs.rs2.value();
        }
        if (base_i.type == R) {
            if (!c.arg4.empty() && no_rs2) {
                i.frm = decode_frm(c.arg4);
            } else if (!c.arg5.empty() && !no_rs2) {
                i.frm = decode_frm(c.arg5);
            } else {
                if (base_i.ssargs.use_rm_for_funct3.has_value() && base_i.ssargs.use_rm_for_funct3.value()) {
                    i.frm = 0b111;
                }
            }
        } else if (base_i.type == R4) {
            i.rs3 = string_to_register(c.arg4, c).encoding;
            if (!c.arg5.empty()) {
                i.frm = decode_frm(c.arg5);
            } else {
                if (base_i.ssargs.use_rm_for_funct3.has_value() && base_i.ssargs.use_rm_for_funct3.value()) {
                    i.frm = 0b111;
                }
            }
        }
    } else if (base_i.type == I) {
        i.rd = string_to_register(c.arg1, c).encoding;
    } else if (base_i.type == S) {
        i.rs2 = string_to_register(c.arg1, c).encoding;
    } else if (base_i.type == B) {
        i.rs1 = string_to_register(c.arg1, c).encoding;
        i.rs2 = string_to_register(c.arg2, c).encoding;
    } else if (base_i.type == U) {
        i.rd = string_to_register(c.arg1, c).encoding;
    } else if (base_i.type == J) {
        i.rd = string_to_register(c.arg1, c).encoding;
    } else if (base_i.type == CR) {

    } else if (base_i.type == CI) {
        
    } else if (base_i.type == CSS) {

    } else if (base_i.type == CIW) {

    } else if (base_i.type == CL) {

    } else if (base_i.type == CS) {

    } else if (base_i.type == CA) {

    } else if (base_i.type == CB) {

    } else if (base_i.type == CJ) {

    }

    DBG(std::cout << "Instruction made" << std::endl;)

    return i;
}

chatavector<instruction> make_inst_from_pseudoinst(assembly_context& c) {
    using enum RVInstructionID;
    if (fast_eq(c.inst, "li")) { // li rd, imm -> lui rd, imm[31:12]; addi rd, rd, imm[11:0]
        // Case 1: imm is a 12-bit signed integer
        int imm;
        if (auto num = to_int(c.arg2); num.has_value()) {
            imm = num.value();
        } else {
            throw ChataError(ChataErrorType::Compiler, "Invalid immediate " + c.arg2, c.line, c.column);
        }
        if (imm >= -2048 && imm <= 2047) {
            c.inst_offset = get_inst_offset_by_id(ADDI);
            c.arg2 = "zero";
            c.arg3 = to_chatastring(imm);
            return {make_inst(c)};
        }
        // Case 2: imm is anything else, split into two instructions, the first assigning the upper 20 bits and the second the lower 12 bits
        c.inst_offset = get_inst_offset_by_id(LUI);
        c.arg2 = to_chatastring(imm >> 12);
        instruction i1 = make_inst(c);
        c.inst_offset = get_inst_offset_by_id(ADDI);
        c.arg2 = c.arg1;
        c.arg3 = to_chatastring(imm & 0xFFF);
        instruction i2 = make_inst(c);
        return {i1, i2};
    } else if (fast_eq(c.inst, "la")) { // la rd, imm -> auipc rd, imm[31:12]; addi rd, rd, imm[11:0]
        // Case 1: imm is a 12-bit signed integer
        int imm;
        if (auto num = to_int(c.arg2); num.has_value()) {
            imm = num.value();
        } else {
            throw ChataError(ChataErrorType::Compiler, "Invalid immediate " + c.arg2, c.line, c.column);
        }
        if (imm >= -2048 && imm <= 2047) {
            c.inst_offset = get_inst_offset_by_id(ADDI);
            c.arg2 = "zero";
            c.arg3 = to_chatastring(imm);
            return {make_inst(c)};
        }
        // Case 2: imm is anything else, split into two instructions, the first assigning the upper 20 bits and the second the lower 12 bits
        c.inst_offset = get_inst_offset_by_id(AUIPC);
        c.arg2 = to_chatastring(imm >> 12);
        instruction i1 = make_inst(c);
        c.inst_offset = get_inst_offset_by_id(ADDI);
        c.arg2 = c.arg1;
        c.arg3 = to_chatastring(imm & 0xFFF);
        instruction i2 = make_inst(c);
        return {i1, i2};

    } else if (fast_eq(c.inst, "mv")) { // mv rd, rs -> addi rd, rs, 0
        c.inst_offset = get_inst_offset_by_id(ADDI);
        c.arg3 = "0";
        return {make_inst(c)};
    } else if (fast_eq(c.inst, "not")) { // not rd, rs -> xori rd, rs, -1
        c.inst_offset = get_inst_offset_by_id(XORI);
        c.arg3 = "-1";
        return {make_inst(c)};
    } else if (fast_eq(c.inst, "neg")) { // neg rd, rs -> sub rd, zero, rs
        c.inst_offset = get_inst_offset_by_id(SUB);
        c.arg3 = c.arg2;
        c.arg2 = "zero";
        return {make_inst(c)};
    } else if (fast_eq(c.inst, "bgt")) { // bgt rs1, rs2, label|imm -> blt rs2, rs1, label|imm
        c.inst_offset = get_inst_offset_by_id(BLT);
        std::swap(c.arg1, c.arg2);
        return {make_inst(c)};
    } else if (fast_eq(c.inst, "ble")) { // ble rs1, rs2, label|imm -> bge rs2, rs1, label|imm
        c.inst_offset = get_inst_offset_by_id(BGE);
        std::swap(c.arg1, c.arg2);
        return {make_inst(c)};
    } else if (fast_eq(c.inst, "bgtu")) { // bgtu rs1, rs2, label|imm -> bltu rs2, rs1, label|imm
        c.inst_offset = get_inst_offset_by_id(BLTU);
        std::swap(c.arg1, c.arg2);
        return {make_inst(c)};
    } else if (fast_eq(c.inst, "bleu")) { // bleu rs1, rs2, label|imm -> bgeu rs2, rs1, label|imm
        c.inst_offset = get_inst_offset_by_id(BGEU);
        std::swap(c.arg1, c.arg2);
        return {make_inst(c)};
    } else if (fast_eq(c.inst, "beqz")) { // beqz rs, label|imm -> beq rs, zero, label|imm
        c.inst_offset = get_inst_offset_by_id(BEQ);
        c.arg3 = c.arg2;
        c.arg2 = "zero";
        return {make_inst(c)};
    } else if (fast_eq(c.inst, "bnez")) { // bnez rs, label|imm -> bne rs, zero, label|imm
        c.inst_offset = get_inst_offset_by_id(BNE);
        c.arg3 = c.arg2;
        c.arg2 = "zero";
        return {make_inst(c)};
    } else if (fast_eq(c.inst, "bgez")) { // bgez rs, label|imm -> bge rs, zero, label|imm
        c.inst_offset = get_inst_offset_by_id(BGE);
        c.arg3 = c.arg2;
        c.arg2 = "zero";
        return {make_inst(c)};
    } else if (fast_eq(c.inst, "blez")) { // blez rs, label|imm -> bge zero, rs, label|imm
        c.inst_offset = get_inst_offset_by_id(BGE);
        c.arg3 = c.arg2;
        c.arg2 = c.arg1;
        c.arg1 = "zero";
        return {make_inst(c)};
    } else if (fast_eq(c.inst, "bgtz")) { // bgtz rs, label|imm -> blt zero, rs, label|imm
        c.inst_offset = get_inst_offset_by_id(BLT);
        c.arg3 = c.arg2;
        c.arg2 = c.arg1;
        c.arg1 = "zero";
        return {make_inst(c)};
    } else if (fast_eq(c.inst, "j")) {
        c.inst_offset = get_inst_offset_by_id(JAL);
        c.arg2 = c.arg1;
        c.arg1 = "zero";
        return {make_inst(c)};

    } else if (fast_eq(c.inst, "call")) {
        // Case 1: imm is a 12-bit signed integer
        int imm;
        if (auto num = to_int(c.arg1); num.has_value()) {
            imm = num.value();
        } else {
            throw ChataError(ChataErrorType::Compiler, "Invalid immediate " + c.arg1, c.line, c.column);
        }
        if (imm >= -2048 && imm <= 2047) {
            c.inst_offset = get_inst_offset_by_id(JALR);
            c.arg3 = c.arg1;
            c.arg2 = "ra";
            c.arg1 = "ra";
            return {make_inst(c)};
        }
        // Case 2: imm is anything else, split into two instructions, the first assigning the upper 20 bits and the second the lower 12 bits

    } else if (fast_eq(c.inst, "ret")) {
        c.inst_offset = get_inst_offset_by_id(JALR);
        c.arg1 = "zero";
        c.arg2 = "ra";
        c.arg3 = "0";
        return {make_inst(c)};
    } else if (fast_eq(c.inst, "nop")) {
        c.inst_offset = get_inst_offset_by_id(ADDI);
        c.arg1 = "zero";
        c.arg2 = "zero";
        c.arg3 = "0";
        return {make_inst(c)};
    } else if (fast_eq(c.inst, "fmv.s.x")) {
        c.inst_offset = get_inst_offset_by_id(FMVWX);
        return {make_inst(c)};
    } else if (fast_eq(c.inst, "fmv.x.s")) {
        c.inst_offset = get_inst_offset_by_id(FMVXW);
        return {make_inst(c)};
    }
    return {};
}

void solve_label_offsets(assembly_context& c) {
    for (size_t i = 0; i < c.nodes.size(); i++) {
        if (c.nodes.at(i).imm_purpose != LABEL_NODE) {
            auto& inst = c.nodes.at(i);
            if (inst.imm_purpose == LABEL_DEST) {
                DBG(std::cout << "Label " << inst.imm << " found, searching for offset" << std::endl;)
                auto search_for_label = [&](int end, int step) {
                    int label_offset = 0;
                    for (int j = i + step; j != end; j += step) {
                        if (c.nodes.at(j).imm_purpose == LABEL_NODE) {
                            if (c.nodes.at(j).imm == inst.imm) {
                                label_offset += bytes_in_instruction(inst);
                                DBG(std::cout << "Found offset for label " << inst.imm << ": " << label_offset << std::endl;)
                                inst.imm = label_offset;
                                inst.imm_purpose = INSTR_IMM;
                                break;
                            }
                        }
                        if (c.nodes.at(j).imm_purpose != LABEL_NODE) {
                            label_offset += bytes_in_instruction(c.nodes.at(j));
                        }
                    }
                    return label_offset;
                };
                int label_offset = search_for_label(c.nodes.size(), 1);
                if (inst.imm_purpose == LABEL_DEST) {
                    DBG(std::cout << "Label not found, searching backwards" << std::endl;)
                    label_offset = search_for_label(-1, -1);
                }
                if (inst.imm_purpose == LABEL_DEST) {
                    throw ChataError(ChataErrorType::Assembler, "Label " + to_chatastring(inst.imm) + " not found", 0, 0);
                }
            }
        }
    }
}

chatavector<uint8_t> generate_machine_code(assembly_context& c) {
    chatavector<uint8_t> machine_code;
    machine_code.resize(c.instruction_bytes);
    size_t offset = 0;
    for (auto& i : c.nodes) {
        if (i.imm_purpose == LABEL_NODE) {
            continue;
        }
        uint32_t inst = 0;
        size_t i_size = 0;
        auto base_inst = instructions.at(i.inst_offset);
        inst |= base_inst.opcode;
        using enum RVInstructionFormat;
        if (base_inst.type == R) {
            DBG(std::cout << "Encoding R-type instruction with name " << base_inst.name << std::endl;)
            inst |= i.rd << 7; // Add rd
            if (base_inst.ssargs.use_rm_for_funct3.has_value() && base_inst.ssargs.use_rm_for_funct3.value()) {
                inst |= i.frm << 12; // Add frm
            } else {
                inst |= (base_inst.funct & 0b111) << 12; // Add funct3
            }
            inst |= i.rs1 << 15;                  // Add rs1
            inst |= i.rs2 << 20;                  // Add rs2
            inst |= (base_inst.funct >> 3) << 25; // Add funct7
            i_size = 4;
        } else if (base_inst.type == I) {
            DBG(std::cout << "Encoding I-type instruction with name " << base_inst.name << std::endl;)
            inst |= i.rd << 7;             // Add rd
            inst |= base_inst.funct << 12; // Add funct3
            inst |= i.rs1 << 15;           // Add rs1
            inst |= i.imm << 20;           // Add imm
            i_size = 4;
        } else if (base_inst.type == S) {
            DBG(std::cout << "Encoding S-type instruction with name " << base_inst.name << std::endl;)
            inst |= (i.imm & 0b11111) << 7; // Add imm[4:0]
            inst |= base_inst.funct << 12;  // Add funct3
            inst |= i.rs1 << 15;            // Add rs1
            inst |= i.rs2 << 20;            // Add rs2
            inst |= (i.imm >> 5) << 25;     // Add imm[11:5]
            i_size = 4;
        } else if (base_inst.type == B) {
            DBG(std::cout << "Encoding B-type instruction with name " << base_inst.name << std::endl;)
            inst |= ((i.imm >> 11) & 0b1) << 7;      // Add imm[11]
            inst |= ((i.imm >> 1) & 0b1111) << 8;    // Add imm[4:1]
            inst |= base_inst.funct << 12;           // Add funct3
            inst |= i.rs1 << 15;                     // Add rs1
            inst |= i.rs2 << 20;                     // Add rs2
            inst |= ((i.imm >> 5) & 0b111111) << 25; // Add imm[10:5]
            inst |= ((i.imm >> 12) & 0b1) << 31;     // Add imm[12]
            i_size = 4;
        } else if (base_inst.type == U) {
            DBG(std::cout << "Encoding U-type instruction with name " << base_inst.name << std::endl;)
            inst |= i.rd << 7;   // Add rd
            inst |= i.imm << 12; // Add imm[31:12]
            i_size = 4;
        } else if (base_inst.type == J) {
            DBG(std::cout << "Encoding J-type instruction with name " << base_inst.name << std::endl;)
            inst |= i.rd << 7;                           // Add rd
            inst |= ((i.imm >> 12) & 0b11111111) << 12;  // Add imm[19:12]
            inst |= ((i.imm >> 11) & 0b1) << 20;         // Add imm[11]
            inst |= ((i.imm >> 1) & 0b1111111111) << 21; // Add imm[10:1]
            inst |= ((i.imm >> 20) & 0b1) << 31;         // Add imm[20]
            i_size = 4;
        } else if (base_inst.type == R4) {
            DBG(std::cout << "Encoding R4-type instruction with name " << base_inst.name << std::endl;)
            inst |= i.rd << 7; // Add rd
            if (base_inst.ssargs.use_rm_for_funct3.has_value() && base_inst.ssargs.use_rm_for_funct3.value()) {
                inst |= i.frm << 12; // Add frm
            } else {
                inst |= (base_inst.funct & 0b111) << 12; // Add funct3
            }
            inst |= i.rs1 << 15;                  // Add rs1
            inst |= i.rs2 << 20;                  // Add rs2
            inst |= (base_inst.funct >> 3) << 25; // Add funct2
            inst |= i.rs3 << 27;                  // Add rs3
            i_size = 4;
        } else if (base_inst.type == CR) {

        } else if (base_inst.type == CI) {

        } else if (base_inst.type == CSS) {

        } else if (base_inst.type == CIW) {

        } else if (base_inst.type == CL) {

        } else if (base_inst.type == CS) {

        } else if (base_inst.type == CA) {

        } else if (base_inst.type == CB) {

        } else if (base_inst.type == CJ) {
        }
        if (i_size == 4) {
            reinterpret_cast<uint32_t&>(machine_code.data()[offset]) = inst;
            offset += 4;
        } else if (i_size == 2) {
            reinterpret_cast<uint16_t&>(machine_code.data()[offset]) = inst;
            offset += 2;
        }
    }
    return machine_code;
}

void parse_this_line(size_t& i, const chatastring& data, assembly_context& c) {
    c.inst.clear();
    auto is_whitespace = [](const char& c) {
        return c == '\t' || c == ' ';
    };
    while (i < data.size() && data.at(i) != '\n') {
        auto ch = [&]() {
            return data.at(i);
        };
        for (; i < data.size() && is_whitespace(ch()) && ch() != '\n'; i++) {
            c.column++;
        }
        for (; i < data.size() && !is_whitespace(ch()) && ch() != '\n'; i++) {
            c.inst.push_back(ch());
            c.column++;
        }
        DBG(std::cout << "Instruction candidate: " << c.inst << std::endl;)
        if (c.inst.front() == '.' || c.inst.front() == '#' || c.inst.back() == ':') {
            DBG(std::cout << "Looks like this is a label or a comment or a directive" << std::endl;)
            if (c.inst.back() == ':') {
                DBG(std::cout << "Looks like this is a label!" << std::endl;)
                c.nodes.push_back(instruction {.imm = string_to_label(c.inst, c), .imm_purpose = LABEL_NODE});
            }
            break;
        }
        auto parse_arg = [&](chatastring& arg) {
            arg.clear();
            for (; i < data.size() && (is_whitespace(ch()) || ch() == ',') && ch() != '\n'; i++) {
                c.column++;
            }
            for (; i < data.size() && !(is_whitespace(ch()) || ch() == ',') && ch() != '\n'; i++) {
                arg.push_back(ch());
                c.column++;
            }
        };
        parse_arg(c.arg1);
        parse_arg(c.arg2);
        parse_arg(c.arg3);
        parse_arg(c.arg4);
        parse_arg(c.arg5);
        parse_arg(c.arg6);
    }
    while (i < data.size() && data.at(i) == '\n') {
        i++;
    }
}

chatavector<uint8_t> assemble_code(const chatastring& data) {
    chatavector<uint8_t> machine_code;
    struct assembly_context c;

    //auto then = std::chrono::high_resolution_clock::now();

    for (size_t i = 0; i < data.size();) {
            parse_this_line(i, data, c);
            if (auto instrs = make_inst_from_pseudoinst(c); !instrs.empty()) {
                for (auto& inst : instrs) {
                    c.nodes.push_back(inst);
                }
            } else {
                if (c.inst_offset = fast_instr_search(c.inst); c.inst_offset != instr_search_failed) {
                    c.nodes.push_back(make_inst(c));
                }
            }
            c.inst_offset = 0;
            c.line++;
            c.column = 0;
    }

    solve_label_offsets(c);

    machine_code = generate_machine_code(c);

    //auto now = std::chrono::high_resolution_clock::now();
    //auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(now - then);
    //std::cout << "Assembling took " << duration.count() << "ms" << std::endl;

#if !defined(DEBUG)
    return machine_code;
#endif
#if defined(DEBUG)

    DBG(std::cout << "Ok, here's the assembled code:" << std::endl;)
    // Show the code in hex form
    DBG(for (auto c : machine_code) { printf("%02x ", c); })

    DBG(std::cout << "Let's compare this against the reference, gcc as" << std::endl;)

    std::ofstream out("temp.s");
    out << data;
    out.close();

    int res = std::system("riscv64-linux-gnu-as -march=rv64gqc temp.s -o temp.o");

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
    DBG(for (auto c : result) { printf("%02x ", c); })

    // exit(0);

    return machine_code;
#endif
}

} // namespace libchata_internal