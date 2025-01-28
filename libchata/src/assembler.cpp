// SPDX-License-Identifier: MPL-2.0
#include "assembler.hpp"
#include "csrs.hpp"
#include "debug.hpp"
#include "instructions.hpp"
#include "libchata.hpp"
#include "pseudoinstructions.hpp"
#include "registers.hpp"
#include <algorithm>
#include <cstdint>
#include <filesystem>
#include <fstream>
#include <iostream>
#include <string>
#include <utility>

namespace libchata_internal {

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

const rvregister& string_to_register(const chatastring& str, assembly_context& c) {
    //return registers[4];
    if (auto reg = fast_reg_search(str); reg != reg_search_failed) {
        return registers[reg];
    }
    throw ChataError(ChataErrorType::Compiler, "Invalid register " + str, c.line, c.column);
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

const uint16_t& decode_csr(const chatastring& csr) {
    if (auto res = fast_csr_search(csr); res != csr_search_failed) {
        return csrs[res].second;
    }
    throw ChataError(ChataErrorType::Compiler, "Invalid CSR " + csr);
}

uint8_t decode_vsew(const chatastring& str) {
    if (fast_eq(str, "e8")) {
        return 0b000;
    } else if (fast_eq(str, "e16")) {
        return 0b001;
    } else if (fast_eq(str, "e32")) {
        return 0b010;
    } else if (fast_eq(str, "e64")) {
        return 0b011;
    } else {
        throw ChataError(ChataErrorType::Compiler, "Invalid VSEW " + str);
    }
}

std::optional<uint8_t> decode_vlmul(const chatastring& str) {
    if (fast_eq(str, "m1")) {
        return 0b000;
    } else if (fast_eq(str, "m2")) {
        return 0b001;
    } else if (fast_eq(str, "m4")) {
        return 0b010;
    } else if (fast_eq(str, "m8")) {
        return 0b011;
    } else {
        return std::nullopt;
    }
}

void handle_super_special_snowflakes(int32_t& imm, uint8_t& rd, uint8_t& rs1, const RVInstructionID& id, assembly_context& c) {
    using enum RVInstructionID;
    if (id == FENCE) {
        imm |= decode_fence(c.arg1) << 4; // Add pred
        imm |= decode_fence(c.arg2);      // Add succ
        DBG(std::cout << "FENCE instruction made" << std::endl;)
    } else if (id == FENCETSO) {
        imm = 0b100000110011; // Set imm to the TSO fence value
        DBG(std::cout << "FENCE.TSO instruction made" << std::endl;)
    } else if (id == PAUSE) {
        imm = 0b000000010000; // Set imm to the PAUSE value
        DBG(std::cout << "PAUSE instruction made" << std::endl;)
    } else if (id == ECALL) {
        imm = 0b000000000000; // Set imm to the ECALL value
        DBG(std::cout << "ECALL instruction made" << std::endl;)
    } else if (id == EBREAK) {
        imm = 0b000000000001; // Set imm to the EBREAK value
        DBG(std::cout << "EBREAK instruction made" << std::endl;)
    } else if (id == FENCEI) {
        imm = 0b000000000000; // Set imm to the FENCE.I value
        DBG(std::cout << "FENCE.I instruction made" << std::endl;)
    } else if (id == CSRRW || id == CSRRS || id == CSRRC) {
        rd = string_to_register(c.arg1, c).encoding;
        imm = decode_csr(c.arg2);
        rs1 = string_to_register(c.arg3, c).encoding;
        DBG(std::cout << "CSR instruction made" << std::endl;)
    } else if (id == CSRRWI || id == CSRRSI || id == CSRRCI) {
        rd = string_to_register(c.arg1, c).encoding;
        imm = decode_csr(c.arg2);
        if (auto num = to_num<int>(c.arg3); num.has_value()) {
            rs1 = num.value();
        } else {
            throw ChataError(ChataErrorType::Compiler, "Invalid immediate " + c.arg3, c.line, c.column);
        }
        DBG(std::cout << "CSRI instruction made" << std::endl;)
    } else if (id == WRSNTO) {
        imm = 0b000000001101; // Set imm to the WRSNTO value
        DBG(std::cout << "WRSNTO instruction made" << std::endl;)
    } else if (id == WRSSTO) {
        imm = 0b000000011101; // Set imm to the WRSSTO value
        DBG(std::cout << "WRSSTO instruction made" << std::endl;)
    } else if (id == CNOP) {
        imm = 0b000000000000; // Set imm to the CNOP value
        DBG(std::cout << "CNOP instruction made" << std::endl;)
    } else if (id == CEBREAK) {
        imm = 0b000000000000;
        DBG(std::cout << "CEBREAK instruction made" << std::endl;)
    }
}

std::pair<int, chatastring> decode_offset_plus_reg(const chatastring& str) {
    int offset = 0;
    int j = 0;
    if (str.front() == '-') {
        j++;
    }
    auto is_digit = [](const char& c) {
        return c >= '0' && c <= '9';
    };
    for (; is_digit(str.at(j)); j++) {
        offset = offset * 10 + (str.at(j) - '0');
    }
    if (str.front() == '-') {
        offset = -offset;
    }
    if (str.at(j) != '(') {
        throw ChataError(ChataErrorType::Compiler, "Invalid immediate " + str);
    }
    j++;
    chatastring reg;
    reg.reserve(32);
    for (; str.at(j) != ')'; j++) {
        reg.push_back(str.at(j));
    }
    return {offset, reg};
}

void make_inst(assembly_context& c) {
    DBG(std::cout << "Instruction: " << c.inst << std::endl;)
    DBG(std::cout << "arg1: " << c.arg1 << std::endl;)
    DBG(std::cout << "arg2: " << c.arg2 << std::endl;)
    DBG(std::cout << "arg3: " << c.arg3 << std::endl;)

    if (!c.supported_sets.empty()) {
        for (const auto& set : c.supported_sets) {
            if (instructions.at(c.inst_offset).set != set && instructions.at(c.inst_offset).subset != set) {
                DBG(std::cout << "Skipping instruction " << c.inst << " because it's not in the supported sets" << std::endl;)
                return;
            }
        }
    }

    DBG(std::cout << "Making instruction" << std::endl;)

    int32_t imm = 0;
    uint8_t rd = 0;
    uint8_t rs1 = 0;
    uint8_t rs2 = 0;
    uint8_t rs3 = 0;
    uint8_t frm = 0;

    auto base_i = instructions.at(c.inst_offset); // Don't make this one auto&, it's slower
    auto& name = base_i.name;
    auto& type = base_i.type;
    auto& id = base_i.id;
    auto& set = base_i.set;
    auto& funct = base_i.funct;
    auto& bytes = base_i.bytes;
    auto& opcode = base_i.opcode;
    auto& ssargs = base_i.ssargs;

    if (bytes == 4) {
        c.machine_code.insert(c.machine_code.end(), {0, 0, 0, 0});
    } else if (bytes == 2) {
        c.machine_code.insert(c.machine_code.end(), {0, 0});
    }

    uint32_t inst = 0;

    inst |= opcode;

    /*i.inst_offset = fast_instr_search("add");
    //i.inst_offset = 27;
    rd = 0;
    rs1 = 1;
    rs2 = 2;
    c.instruction_bytes += 4;
    return i;*/

    // std::cout << "i.name = " << base_i.name << std::endl;

    using enum RVInstructionFormat;
    using enum RVInstructionID;

    if (ssargs.super_special_snowflake) {
        handle_super_special_snowflakes(imm, rd, rs1, id, c);
        if (type == I) {
            DBG(std::cout << "Encoding I-type instruction with name " << name << std::endl;)
            inst |= rd << 7;     // Add rd
            inst |= funct << 12; // Add funct3
            inst |= rs1 << 15;   // Add rs1
            inst |= imm << 20;   // Add imm
        } else if (type == CI) {
            inst |= ((imm >> 6) & 0b1111) << 2; // Add offset[9:6]
            inst |= ((imm >> 4) & 0b1) << 6;    // Add offset[4]
            inst |= ((imm >> 5) & 0b1) << 12;   // Add offset[5]
            inst |= rd << 7;                    // Add rd
            if (id == CEBREAK) {
                inst |= funct << 12; // Add funct4
            } else {
                inst |= funct << 13; // Add funct3
            }
        }

        reinterpret_cast<uint32_t&>(c.machine_code[c.machine_code.size() - bytes]) = inst;
        return;
    }

    if (type == R || type == R4) {
        /*rd = 0b00000;
        rs1 = 0b00000;
        rs2 = 0b00000;
        imm = 0;*/

        if (type == R) {
            if (ssargs.use_imm_for_rs2) {
                if (auto num = to_num<int>(c.arg3); num.has_value()) {
                    imm = num.value();
                } else {
                    throw ChataError(ChataErrorType::Compiler, "Invalid immediate " + c.arg3, c.line, c.column);
                }
            }
        }
        rd = string_to_register(c.arg1, c).encoding;
        if (set == RVInstructionSet::RV32A || set == RVInstructionSet::RV64A) { // The RV32A and RV64A sets sometimes use registers that look like (a0)
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
            if (id != LRW && id != LRWAQ && id != LRWRL && id != LRWAQRL && id != LRD && id != LRDAQ && id != LRDRL && id != LRDAQRL) {
                std::swap(c.arg2, c.arg3); // For the case of instr rd, rs2, (rs1)
            }
        }
        rs1 = string_to_register(c.arg2, c).encoding;
        auto no_rs2 = ssargs.custom_reg_val.has_value();
        if (!no_rs2) {
            if (ssargs.use_imm_for_rs2) {
                rs2 = imm;
            } else {
                rs2 = string_to_register(c.arg3, c).encoding;
            }
        } else {
            rs2 = ssargs.custom_reg_val.value();
        }
        if (type == R) {
            if (!c.arg4.empty() && no_rs2) {
                frm = decode_frm(c.arg4);
            } else if (!c.arg5.empty() && !no_rs2) {
                frm = decode_frm(c.arg5);
            } else {
                if (ssargs.use_frm_for_funct3) {
                    frm = 0b111;
                }
            }

            DBG(std::cout << "Encoding R-type instruction with name " << name << std::endl;)
            inst |= rd << 7; // Add rd
            if (ssargs.use_frm_for_funct3) {
                inst |= frm << 12; // Add frm
            } else {
                inst |= (funct & 0b111) << 12; // Add funct3
            }
            inst |= rs1 << 15;          // Add rs1
            inst |= rs2 << 20;          // Add rs2
            inst |= (funct >> 3) << 25; // Add funct7
        } else if (type == R4) {
            rs3 = string_to_register(c.arg4, c).encoding;
            if (!c.arg5.empty()) {
                frm = decode_frm(c.arg5);
            } else {
                if (ssargs.use_frm_for_funct3) {
                    frm = 0b111;
                }
            }

            DBG(std::cout << "Encoding R4-type instruction with name " << name << std::endl;)
            inst |= rd << 7; // Add rd
            if (ssargs.use_frm_for_funct3) {
                inst |= frm << 12; // Add frm
            } else {
                inst |= (funct & 0b111) << 12; // Add funct3
            }
            inst |= rs1 << 15;          // Add rs1
            inst |= rs2 << 20;          // Add rs2
            inst |= (funct >> 3) << 25; // Add funct2
            inst |= rs3 << 27;          // Add rs3
        }
    } else if (type == I || type == S) {
        /*rd = 0b00000;
        rs1 = 0b00000;
        rs2 = 0b00000;
        imm = 0;*/

        if (auto num = to_num<int>(c.arg3); num.has_value()) {
            imm = num.value();
            rs1 = string_to_register(c.arg2, c).encoding;
        } else {
            auto [offset, reg] = decode_offset_plus_reg(c.arg2);
            imm = offset;
            rs1 = string_to_register(reg, c).encoding;
        }
        if (type == I) {
            rd = string_to_register(c.arg1, c).encoding;
        } else if (type == S) {
            rs2 = string_to_register(c.arg1, c).encoding;
        }

        if (type == I) {
            DBG(std::cout << "Encoding I-type instruction with name " << name << std::endl;)
            inst |= rd << 7;     // Add rd
            inst |= funct << 12; // Add funct3
            inst |= rs1 << 15;   // Add rs1
            inst |= imm << 20;   // Add imm
        } else if (type == S) {
            DBG(std::cout << "Encoding S-type instruction with name " << name << std::endl;)
            inst |= (imm & 0b11111) << 7; // Add imm[4:0]
            inst |= funct << 12;          // Add funct3
            inst |= rs1 << 15;            // Add rs1
            inst |= rs2 << 20;            // Add rs2
            inst |= (imm >> 5) << 25;     // Add imm[11:5]
        }
    } else if (type == Branch) {
        if (auto num = to_num<int>(c.arg3); num.has_value()) {
            imm = num.value();
        } else {
            imm = string_to_label(c.arg3, c);
            c.label_locs.push_back(label_loc {.loc = c.machine_code.size() - bytes, .id = imm, .i_bytes = bytes, .is_dest = false, .format = Branch});
        }
        rs1 = string_to_register(c.arg1, c).encoding;
        rs2 = string_to_register(c.arg2, c).encoding;

        DBG(std::cout << "Encoding Branch-type instruction with name " << name << std::endl;)
        inst |= ((imm >> 11) & 0b1) << 7;      // Add imm[11]
        inst |= ((imm >> 1) & 0b1111) << 8;    // Add imm[4:1]
        inst |= funct << 12;                   // Add funct3
        inst |= rs1 << 15;                     // Add rs1
        inst |= rs2 << 20;                     // Add rs2
        inst |= ((imm >> 5) & 0b111111) << 25; // Add imm[10:5]
        inst |= ((imm >> 12) & 0b1) << 31;     // Add imm[12]
    } else if (type == U) {
        if (auto num = to_num<int>(c.arg2); num.has_value()) {
            imm = num.value();
        } else {
            throw ChataError(ChataErrorType::Compiler, "Invalid immediate " + c.arg2, c.line, c.column);
        }
        rd = string_to_register(c.arg1, c).encoding;

        DBG(std::cout << "Encoding U-type instruction with name " << name << std::endl;)
        inst |= rd << 7;   // Add rd
        inst |= imm << 12; // Add imm[31:12]
    } else if (type == J) {
        if (auto num = to_num<int>(c.arg2); num.has_value()) {
            imm = num.value();
        } else {
            imm = string_to_label(c.arg2, c);
            c.label_locs.push_back(label_loc {.loc = c.machine_code.size() - bytes, .id = imm, .i_bytes = bytes, .is_dest = false, .format = J});
        }
        rd = string_to_register(c.arg1, c).encoding;

        DBG(std::cout << "Encoding J-type instruction with name " << name << std::endl;)
        inst |= rd << 7;                           // Add rd
        inst |= ((imm >> 12) & 0b11111111) << 12;  // Add imm[19:12]
        inst |= ((imm >> 11) & 0b1) << 20;         // Add imm[11]
        inst |= ((imm >> 1) & 0b1111111111) << 21; // Add imm[10:1]
        inst |= ((imm >> 20) & 0b1) << 31;         // Add imm[20]
    } else if (type == CJ) {
        if (auto num = to_num<int>(c.arg1); num.has_value()) {
            imm = num.value();
        } else {
            imm = string_to_label(c.arg1, c);
            c.label_locs.push_back(label_loc {.loc = c.machine_code.size() - bytes, .id = imm, .i_bytes = bytes, .is_dest = false, .format = CJ});
        }

        DBG(std::cout << "Encoding CJ-type instruction with name " << name << std::endl;)
        inst |= ((imm >> 5) & 0b1) << 2;   // Add offset[5]
        inst |= ((imm >> 1) & 0b111) << 3; // Add offset[3:1]
        inst |= ((imm >> 7) & 0b1) << 6;   // Add offset[7]
        inst |= ((imm >> 6) & 0b1) << 7;   // Add offset[6]
        inst |= ((imm >> 10) & 0b1) << 8;  // Add offset[10]
        inst |= ((imm >> 8) & 0b11) << 9;  // Add offset[9:8]
        inst |= ((imm >> 4) & 0b1) << 11;  // Add offset[4]
        inst |= ((imm >> 11) & 0b1) << 12; // Add offset[11]
        inst |= funct << 13;               // Add funct3
    } else if (type == CL) {
        if (auto num = to_num<int>(c.arg3); num.has_value()) {
            imm = num.value();
            rs1 = string_to_register(c.arg2, c).encoding & 0b111;
        } else {
            auto [offset, reg] = decode_offset_plus_reg(c.arg2);
            imm = offset;
            rs1 = string_to_register(reg, c).encoding & 0b111;
        }
        rd = string_to_register(c.arg1, c).encoding & 0b111;

        DBG(std::cout << "Encoding CL-type instruction with name " << name << std::endl;)
        inst |= rd << 2;                      // Add rd' (just 3 bits)
        if (id == CLW || id == CFLW) {        // offset[2|6]
            inst |= ((imm >> 6) & 0b1) << 5;  // Add offset[6]
            inst |= ((imm >> 2) & 0b1) << 6;  // Add offset[2]
        } else if (id == CLD || id == CFLD) { // offset[7:6]
            inst |= ((imm >> 6) & 0b11) << 5; // Add offset[7:6]
        }
        inst |= rs1 << 7;                   // Add rs1' (just 3 bits)
        inst |= ((imm >> 3) & 0b111) << 10; // Add offset[5:3]
        inst |= funct << 13;                // Add funct3
    } else if (type == CS) {
        if (auto num = to_num<int>(c.arg3); num.has_value()) {
            imm = num.value();
            rs1 = string_to_register(c.arg2, c).encoding & 0b111;
        } else {
            auto [offset, reg] = decode_offset_plus_reg(c.arg2);
            imm = offset;
            rs1 = string_to_register(reg, c).encoding & 0b111;
        }
        rs2 = string_to_register(c.arg1, c).encoding & 0b111;

        DBG(std::cout << "Encoding CS-type instruction with name " << name << std::endl;)
        inst |= rs2 << 2;                     // Add rs2' (just 3 bits)
        if (id == CSW || id == CFSW) {        // offset[2|6]
            inst |= ((imm >> 6) & 0b1) << 5;  // Add offset[6]
            inst |= ((imm >> 2) & 0b1) << 6;  // Add offset[2]
        } else if (id == CSD || id == CFSD) { // offset[7:6]
            inst |= ((imm >> 6) & 0b11) << 5; // Add offset[7:6]
        }
        inst |= rs1 << 7;                   // Add rs1' (just 3 bits)
        inst |= ((imm >> 3) & 0b111) << 10; // Add offset[5:3]
        inst |= funct << 13;                // Add funct3
    } else if (type == CB) {
        if (auto num = to_num<int>(c.arg2); num.has_value()) {
            imm = num.value();
        } else {
            imm = string_to_label(c.arg2, c);
            c.label_locs.push_back(label_loc {.loc = c.machine_code.size() - bytes, .id = imm, .i_bytes = bytes, .is_dest = false, .format = CB});
        }
        rs1 = string_to_register(c.arg1, c).encoding & 0b111;

        DBG(std::cout << "Encoding CB-type instruction with name " << name << std::endl;)
        if (id == CSRLI || id == CSRAI || id == CANDI) { // shamt[5], shamt[4:0]
            inst |= (imm & 0b11111) << 2;                // Add shamt[4:0]
            inst |= ((imm >> 5) & 0b1) << 12;            // Add shamt[5]
        } else {
            inst |= ((imm >> 5) & 0b1) << 2;   // Add offset[5]
            inst |= ((imm >> 1) & 0b11) << 3;  // Add offset[2:1]
            inst |= ((imm >> 6) & 0b11) << 5;  // Add offset[7:6]
            inst |= ((imm >> 3) & 0b11) << 10; // Add offset[4:3]
            inst |= ((imm >> 8) & 0b1) << 12;  // Add offset[8]
        }
        inst |= rs1 << 7; // Add rs1' (just 3 bits)
        if (id == CSRLI || id == CSRAI || id == CANDI) {
            inst |= (funct & 0b11) << 10;         // Add funct2
            inst |= ((funct >> 2) & 0b111) << 13; // Add funct3
        } else {
            inst |= funct << 13; // Add funct3
        }
    } else if (type == CR) {
        rd = string_to_register(c.arg1, c).encoding;
        if (ssargs.custom_reg_val.has_value()) {
            rs2 = ssargs.custom_reg_val.value();
        } else {
            rs2 = string_to_register(c.arg2, c).encoding;
        }

        DBG(std::cout << "Encoding CR-type instruction with name " << name << std::endl;)
        inst |= rs2 << 2;    // Add rs2
        inst |= rd << 7;     // Add rd
        inst |= funct << 12; // Add funct4
    } else if (type == CI) {

        rd = string_to_register(c.arg1, c).encoding;
        if (auto num = to_num<int>(c.arg2); num.has_value()) {
            imm = num.value();
        } else {
            auto [offset, reg] = decode_offset_plus_reg(c.arg2); // discard reg
            imm = offset;
        }

        DBG(std::cout << "Encoding CI-type instruction with name " << name << std::endl;)
        if (id == CLWSP || id == CFLWSP) {                                    // offset[4:2|7:6]
            inst |= ((imm >> 6) & 0b11) << 2;                                 // Add offset[7:6]
            inst |= ((imm >> 2) & 0b1111) << 4;                               // Add offset[4:2]
            inst |= ((imm >> 5) & 0b1) << 12;                                 // Add offset[5]
        } else if (id == CLDSP || id == CFLDSP) {                             // offset[4:3|8:6]
            inst |= ((imm >> 6) & 0b111) << 2;                                // Add offset[8:6]
            inst |= ((imm >> 3) & 0b11) << 5;                                 // Add offset[4:3]
            inst |= ((imm >> 5) & 0b1) << 12;                                 // Add offset[5]
        } else if (id == CLI || id == CADDI || id == CADDIW || id == CSLLI) { // imm[5], imm[4:0]
            inst |= (imm & 0b11111) << 2;                                     // Add imm[4:0]
            inst |= ((imm >> 5) & 0b1) << 12;                                 // Add imm[5]
        } else if (id == CLUI) {                                              // nzimm[17], imm[16:12]
            inst |= ((imm >> 12) & 0b11111) << 2;                             // Add imm[16:12]
            inst |= ((imm >> 17) & 0b1) << 12;                                // Add nzimm[17]
        } else if (id == CADDI16SP) {                                         // nzimm[9], nzimm[4|6|8:7|5]
            inst |= ((imm >> 5) & 0b1) << 2;                                  // Add nzimm[5]
            inst |= ((imm >> 7) & 0b11) << 3;                                 // Add nzimm[8:7]
            inst |= ((imm >> 6) & 0b1) << 5;                                  // Add nzimm[6]
            inst |= ((imm >> 4) & 0b1) << 6;                                  // Add nzimm[4]
            inst |= ((imm >> 9) & 0b1) << 12;                                 // Add nzimm[9]
        } else {                                                              // offset[4|9:6]
            inst |= ((imm >> 6) & 0b1111) << 2;                               // Add offset[9:6]
            inst |= ((imm >> 4) & 0b1) << 6;                                  // Add offset[4]
            inst |= ((imm >> 5) & 0b1) << 12;                                 // Add offset[5]
        }
        inst |= rd << 7;     // Add rd
        inst |= funct << 13; // Add funct3
    } else if (type == CSS) {
        rs2 = string_to_register(c.arg1, c).encoding;
        if (auto num = to_num<int>(c.arg2); num.has_value()) {
            imm = num.value();
        } else {
            auto [offset, reg] = decode_offset_plus_reg(c.arg2); // discard reg
            imm = offset;
        }

        DBG(std::cout << "Encoding CSS-type instruction with name " << name << std::endl;)
        inst |= rs2 << 2;                         // Add rs2
        if (id == CSWSP || id == CFSWSP) {        // offset[5:2|7:6]
            inst |= ((imm >> 6) & 0b11) << 7;     // Add offset[7:6]
            inst |= ((imm >> 2) & 0b1111) << 9;   // Add offset[5:2]
        } else if (id == CSDSP || id == CFSDSP) { // offset[5:3|8:6]
            inst |= ((imm >> 6) & 0b111) << 7;    // Add offset[8:6]
            inst |= ((imm >> 3) & 0b111) << 10;   // Add offset[5:3]
        } else {                                  // offset[5:4|9:6]
            inst |= ((imm >> 6) & 0b1111) << 7;   // Add offset[9:6]
            inst |= ((imm >> 4) & 0b11) << 11;    // Add offset[5:4]
        }
        inst |= funct << 13; // Add funct3
    } else if (type == CIW) {
        rd = string_to_register(c.arg1, c).encoding & 0b111; // Only use the lower 3 bits
        if (auto num = to_num<int>(c.arg2); num.has_value()) {
            imm = num.value();
        } else {
            throw ChataError(ChataErrorType::Compiler, "Invalid immediate " + c.arg2, c.line, c.column);
        }

        DBG(std::cout << "Encoding CIW-type instruction with name " << name << std::endl;)
        inst |= rd << 2;                    // Add rd' (just 3 bits)
        inst |= ((imm >> 3) & 0b1) << 5;    // Add nzuimm[3]
        inst |= ((imm >> 2) & 0b1) << 6;    // Add nzuimm[2]
        inst |= ((imm >> 6) & 0b1111) << 7; // Add nzuimm[9:6]
        inst |= ((imm >> 4) & 0b11) << 11;  // Add nzuimm[5:4]
        inst |= funct << 13;                // Add funct3
    } else if (type == CA) {
        rd = string_to_register(c.arg1, c).encoding & 0b111; // Only use the lower 3 bits
        rs2 = string_to_register(c.arg2, c).encoding & 0b111;

        DBG(std::cout << "Encoding CA-type instruction with name " << name << std::endl;)
        inst |= rs2 << 2;            // Add rs2' (just 3 bits)
        inst |= (funct & 0b11) << 5; // Add funct2
        inst |= rd << 7;             // Add rd' (just 3 bits)
        inst |= (funct >> 2) << 10;  // Add funct6
    } else if (type == VL) {

    } else if (type == VLS) {

    } else if (type == VLX) {

    } else if (type == VS) {

    } else if (type == VSS) {

    } else if (type == VSX) {

    } else if (type == VLR) {

    } else if (type == VSR) {

    } else if (type == IVV) {

    } else if (type == FVV) {

    } else if (type == MVV) {

    } else if (type == IVI) {

    } else if (type == IVX) {

    } else if (type == FVF) {

    } else if (type == MVX) {

    } else if (type == CLB) {

    } else if (type == CSBfmt) {

    } else if (type == CLHfmt) {

    } else if (type == CSHfmt) {

    } else if (type == CU) {

    } else if (type == CMMV) {
         
    } else if (type == CMJTfmt) {
        
    } else if (type == CMPP) {

    }

    DBG(std::cout << "Instruction made" << std::endl;)

    reinterpret_cast<uint32_t&>(c.machine_code[c.machine_code.size() - bytes]) = inst;
}

void solve_label_offsets(assembly_context& c) {
    using enum RVInstructionFormat;
    for (size_t i = 0; i < c.label_locs.size(); i++) {
        if (!c.label_locs.at(i).is_dest) {
            for (size_t j = 0; j < c.label_locs.size(); j++) {
                if (c.label_locs.at(j).is_dest && c.label_locs.at(j).id == c.label_locs.at(i).id) {
                    uint32_t inst = 0;
                    if (c.label_locs.at(i).i_bytes == 2) {
                        inst = reinterpret_cast<uint16_t&>(c.machine_code.at(c.label_locs.at(i).loc));
                    } else if (c.label_locs.at(i).i_bytes == 4) {
                        inst = reinterpret_cast<uint32_t&>(c.machine_code.at(c.label_locs.at(i).loc));
                    }
                    int32_t offset = c.label_locs.at(j).loc - c.label_locs.at(i).loc;

                    //std::cout << "Loc for i: " << c.label_locs.at(i).loc << ", loc for j: " << c.label_locs.at(j).loc << std::endl;

                    //std::cout << "Offset for label " << c.label_locs.at(i).id << ": " << offset << std::endl;

                    if (c.label_locs.at(i).format == Branch) {
                        inst &= 0b00000001111111111111000001111111;
                        inst |= ((offset >> 11) & 0b1) << 7;      // Add imm[11]
                        inst |= ((offset >> 1) & 0b1111) << 8;    // Add imm[4:1]
                        inst |= ((offset >> 5) & 0b111111) << 25; // Add imm[10:5]
                        inst |= ((offset >> 12) & 0b1) << 31;     // Add imm[12]
                    } else if (c.label_locs.at(i).format == J) {
                        inst &= 0b00000000000000000000111111111111;
                        inst |= ((offset >> 12) & 0b11111111) << 12;  // Add imm[19:12]
                        inst |= ((offset >> 11) & 0b1) << 20;         // Add imm[11]
                        inst |= ((offset >> 1) & 0b1111111111) << 21; // Add imm[10:1]
                        inst |= ((offset >> 20) & 0b1) << 31;         // Add imm[20]
                    } else if (c.label_locs.at(i).format == CJ) {
                        inst &= 0b1110000000000011;
                        inst |= ((offset >> 5) & 0b1) << 2;   // Add offset[5]
                        inst |= ((offset >> 1) & 0b111) << 3; // Add offset[3:1]
                        inst |= ((offset >> 7) & 0b1) << 6;   // Add offset[7]
                        inst |= ((offset >> 6) & 0b1) << 7;   // Add offset[6]
                        inst |= ((offset >> 10) & 0b1) << 8;  // Add offset[10]
                        inst |= ((offset >> 8) & 0b11) << 9;  // Add offset[9:8]
                        inst |= ((offset >> 4) & 0b1) << 11;  // Add offset[4]
                        inst |= ((offset >> 11) & 0b1) << 12; // Add offset[11]
                    } else if (c.label_locs.at(i).format == CB) {
                        inst &= 0b1110001110000011;
                        inst |= ((offset >> 5) & 0b1) << 2;   // Add offset[5]
                        inst |= ((offset >> 1) & 0b11) << 3;  // Add offset[2:1]
                        inst |= ((offset >> 6) & 0b11) << 5;  // Add offset[7:6]
                        inst |= ((offset >> 3) & 0b11) << 10; // Add offset[4:3]
                        inst |= ((offset >> 8) & 0b1) << 12;  // Add offset[8]
                    }

                    if (c.label_locs.at(i).i_bytes == 2) {
                        reinterpret_cast<uint16_t&>(c.machine_code.data()[c.label_locs.at(i).loc]) = inst;
                    } else if (c.label_locs.at(i).i_bytes == 4) {
                        reinterpret_cast<uint32_t&>(c.machine_code.data()[c.label_locs.at(i).loc]) = inst;
                    }
                }
            }
        }
    }
}

chatavector<RVInstructionSet> decode_sets(const chatastring& str) {
    // Example: For an input str that looks like "rv64ifma", this function will return a vector containing RV64I, RV64F, RV64M, and RV64A
    chatavector<RVInstructionSet> sets;
    chatastring search_str;
    for (const char& c : str) {
        search_str.push_back(c);
        // for (const auto& name : instruction_set
    }
}

uint8_t decode_opcode(const chatastring& str) {
    using namespace opcode;
    if (fast_eq(str, "LOAD")) {
        return OP_LOAD;
    } else if (fast_eq(str, "STORE")) {
        return OP_STORE;
    } else if (fast_eq(str, "MADD")) {
        return OP_MADD;
    } else if (fast_eq(str, "BRANCH")) {
        return OP_BRANCH;
    } else if (fast_eq(str, "LOAD_FP")) {
        return OP_LOAD_FP;
    } else if (fast_eq(str, "STORE_FP")) {
        return OP_STORE_FP;
    } else if (fast_eq(str, "MSUB")) {
        return OP_MSUB;
    } else if (fast_eq(str, "JALR")) {
        return OP_JALR;
    } else if (fast_eq(str, "CUSTOM_0")) {
        return OP_CUSTOM_0;
    } else if (fast_eq(str, "CUSTOM_1")) {
        return OP_CUSTOM_1;
    } else if (fast_eq(str, "NMSUB")) {
        return OP_NMSUB;
    } else if (fast_eq(str, "RESERVED")) {
        return OP_RESERVED;
    } else if (fast_eq(str, "MISC_MEM")) {
        return OP_MISC_MEM;
    } else if (fast_eq(str, "AMO")) {
        return OP_AMO;
    } else if (fast_eq(str, "NMADD")) {
        return OP_NMADD;
    } else if (fast_eq(str, "JAL")) {
        return OP_JAL;
    } else if (fast_eq(str, "IMM")) {
        return OP_IMM;
    } else if (fast_eq(str, "OP")) {
        return OP_OP;
    } else if (fast_eq(str, "FP")) {
        return OP_FP;
    } else if (fast_eq(str, "SYSTEM")) {
        return OP_SYSTEM;
    } else if (fast_eq(str, "AUIPC")) {
        return OP_AUIPC;
    } else if (fast_eq(str, "LUI")) {
        return OP_LUI;
    } else if (fast_eq(str, "V")) {
        return OP_V;
    } else if (fast_eq(str, "VE")) {
        return OP_VE;
    } else if (fast_eq(str, "IMM_32")) {
        return OP_IMM_32;
    } else if (fast_eq(str, "OP_32")) {
        return OP_32;
    } else if (fast_eq(str, "CUSTOM_2")) {
        return OP_CUSTOM_2;
    } else if (fast_eq(str, "CUSTOM_3")) {
        return OP_CUSTOM_3;
    } else if (fast_eq(str, "C0")) {
        return OP_C0;
    } else if (fast_eq(str, "C1")) {
        return OP_C1;
    } else if (fast_eq(str, "C2")) {
        return OP_C2;
    } else {
        throw ChataError(ChataErrorType::Compiler, "Invalid opcode " + str);
    }
}

void handle_directives(assembly_context& c) {
    if (c.inst.back() == ':') {
        DBG(std::cout << "Looks like this is a label, adding it" << std::endl;)
        c.label_locs.push_back(label_loc {.loc = c.machine_code.size(), .id = string_to_label(c.inst, c), .is_dest = true});
        return;
    }
    if (c.inst.front() != '.') {
        DBG(std::cout << "Not a directive, skipping" << std::endl;)
        return;
    }
    DBG(std::cout << "Looks like this is a directive" << std::endl;)
    if (fast_eq(c.inst, ".option")) {
        DBG(std::cout << "Option directive" << std::endl;)
        if (fast_eq(c.arg1, "arch")) {
            using enum RVInstructionSet;
            const std::array<std::pair<std::string_view, RVInstructionSet>, 21> arch_option_names = {
                    {{"rv32i", RV32I}, {"rv64i", RV64I}, {"m", RV32M}, // Using RV32M although it means M in general
                     {"a", RV32A},     {"f", RV32F},     {"d", RV32D},   {"q", RV32Q}, {"zifencei", Zifencei}, {"zicsr", Zicsr}, {"zawrs", Zawrs}, {"zicond", Zicond}, {"zacas", Zacas},
                     {"zcb", Zcb},     {"zbb", Zbb},     {"zcmp", Zcmp}, {"c", C},     {"zcd", Zcd},           {"zcf", Zcf},     {"zcmt", Zcmt},   {"b", B},           {"v", V}}};

            auto get_arches_from_string = [&](const std::string_view& str) {
                chatavector<RVInstructionSet> arches;
                chatastring temp;
                for (const char& c : str) {
                    temp.push_back(c);
                    for (const auto& [name, arch] : arch_option_names) {
                        if (fast_eq(temp, name)) {
                            arches.push_back(arch);
                            DBG(std::cout << "Found arch: " << temp << std::endl;)
                            temp.clear();
                            break;
                        }
                    }
                }
                return arches;
            };

            if (c.arg2.front() == '+') {
                DBG(std::cout << "Adding arches" << std::endl;)
                c.arg2.erase(0, 1);
                auto arches = get_arches_from_string(c.arg2);
                c.supported_sets.insert(c.supported_sets.end(), arches.begin(), arches.end());
            } else if (c.arg2.front() == '-') {
                DBG(std::cout << "Removing arches" << std::endl;)
                c.arg2.erase(0, 1);
                auto arches = get_arches_from_string(c.arg2);
                for (const auto& arch : arches) {
                    c.supported_sets.erase(std::remove(c.supported_sets.begin(), c.supported_sets.end(), arch), c.supported_sets.end());
                }
            } else {
                DBG(std::cout << "Setting arches" << std::endl;)
                c.supported_sets = get_arches_from_string(c.arg2);
            }
        } else if (fast_eq(c.arg1, "push")) {
            DBG(std::cout << "Pushing options" << std::endl;)
            c.options.push_back(c.options.back());
        } else if (fast_eq(c.arg1, "pop")) {
            DBG(std::cout << "Popping options" << std::endl;)
            c.options.pop_back();
        }
    } else if (fast_eq(c.inst, ".insn")) {
        DBG(std::cout << "Instruction directive" << std::endl;)
        // .insn <value> = make an instruction with content <value>
        // .insn <insn_length>, <value> = make an instruction with length <insn_length> and content <value> (verify length)
        // .insn <type> <fields> = make an instruction with type <type> and fields <fields>
        
        uint32_t custom_inst;
        using enum RVInstructionFormat;
        const std::array<std::pair<std::string_view, RVInstructionFormat>, 38> type_names = {
                {{"r", R},     {"i", I},        {"s", S},        {"b", Branch},   {"u", U},     {"j", J},       {"r4", R4},        {"cr", CR},    {"ci", CI},   {"css", CSS},
                 {"ciw", CIW}, {"cl", CL},      {"cs", CS},      {"ca", CA},      {"cb", CB},   {"cj", CJ},     {"vl", VL},        {"vls", VLS},  {"vlx", VLX}, {"vs", VS},
                 {"vss", VSS}, {"vsx", VSX},    {"vlr", VLR},    {"ivv", IVV},    {"fvv", FVV}, {"mvv", MVV},   {"ivi", IVI},      {"ivx", IVX},  {"fvf", FVF}, {"mvx", MVX},
                 {"clb", CLB}, {"csb", CSBfmt}, {"clh", CLHfmt}, {"csh", CSHfmt}, {"cu", CU},   {"cmmv", CMMV}, {"cmjt", CMJTfmt}, {"cmpp", CMPP}}};
        uint8_t required_length = 0;
        if (!c.arg1.empty() && c.arg2.empty()) {
            if (auto num = to_num<uint32_t>(c.arg1); num.has_value()) {
                custom_inst = num.value();
            }
        } else if (!c.arg1.empty() && !c.arg2.empty()) {
            RVInstructionFormat this_type;
            bool is_type = false;
            for (const auto& [name, type] : type_names) {
                if (fast_eq(c.arg1, name)) {
                    is_type = true;
                    this_type = type;
                    break;
                }
            }
            if (is_type) {
                auto get_extra_args = [&]() -> chatavector<chatastring> {
                    // Parse all the extra args from c.arg_extra, which are separated by commas and whitespace
                    chatavector<chatastring> args;
                    chatastring temp;
                    auto is_whitespace = [](const char& c) {
                        return c == ' ' || c == '\t';
                    };
                    for (const char& c : c.arg_extra) {
                        if (c == ',') {
                            args.push_back(temp);
                            temp.clear();
                        } else if (is_whitespace(c)) {
                            continue;
                        } else {
                            temp.push_back(c);
                        }
                    }
                    if (!temp.empty()) {
                        args.push_back(temp);
                    }
                    return args;
                };

                uint8_t opcode = to_num<uint8_t>(c.arg2).value();
                custom_inst |= opcode;
                if (this_type == R && get_extra_args().size() == 1) {
                    uint8_t func3 = to_num<uint8_t>(c.arg3).value();
                    uint8_t func7 = to_num<uint8_t>(c.arg4).value();
                    uint8_t rd = to_num<uint8_t>(c.arg5).value();
                    uint8_t rs1 = to_num<uint8_t>(c.arg6).value();
                    uint8_t rs2 = to_num<uint8_t>(get_extra_args().at(0)).value();

                    custom_inst = (rd << 7) | (func3 << 12) | (rs1 << 15) | (rs2 << 20) | (func7 << 25);
                } else if (this_type == R && get_extra_args().size() == 2) { // R with 4 args
                    uint8_t func3 = to_num<uint8_t>(c.arg3).value();
                    uint8_t func2 = to_num<uint8_t>(c.arg4).value();
                    uint8_t rd = to_num<uint8_t>(c.arg5).value();
                    uint8_t rs1 = to_num<uint8_t>(c.arg6).value();
                    uint8_t rs2 = to_num<uint8_t>(get_extra_args().at(0)).value();
                    uint8_t rs3 = to_num<uint8_t>(get_extra_args().at(1)).value();

                    custom_inst = (rd << 7) | (func3 << 12) | (rs1 << 15) | (rs2 << 20) | (func2 << 25) | (rs3 << 27);
                } else if (this_type == R4) {
                    uint8_t func3 = to_num<uint8_t>(c.arg3).value();
                    uint8_t func2 = to_num<uint8_t>(c.arg4).value();
                    uint8_t rd = to_num<uint8_t>(c.arg5).value();
                    uint8_t rs1 = to_num<uint8_t>(c.arg6).value();
                    uint8_t rs2 = to_num<uint8_t>(get_extra_args().at(0)).value();
                    uint8_t rs3 = to_num<uint8_t>(get_extra_args().at(1)).value();

                    custom_inst = (rd << 7) | (func3 << 12) | (rs1 << 15) | (rs2 << 20) | (func2 << 25) | (rs3 << 27);
                }
            } else {
                if (auto num = to_num<uint32_t>(c.arg2); num.has_value()) {
                    custom_inst = num.value();
                }
                if (auto num = to_num<uint8_t>(c.arg1); num.has_value()) {
                    required_length = num.value();
                }
            }
        }

        auto inst_len = [&] {
            if (custom_inst & 0xFFFF0000) {
                return 4;
            } else {
                return 2;
            }
        };

        if (!c.arg1.empty() && !c.arg2.empty()) {
            if (required_length != inst_len()) {
                throw ChataError(ChataErrorType::Assembler, "Instruction length mismatch: expected " + to_chatastring(required_length) + ", got " + to_chatastring(inst_len()), c.line, c.column);
            }
        }
        if (inst_len() == 4) {
            c.machine_code.push_back(custom_inst & 0xFF);
            c.machine_code.push_back((custom_inst >> 8) & 0xFF);
            c.machine_code.push_back((custom_inst >> 16) & 0xFF);
            c.machine_code.push_back((custom_inst >> 24) & 0xFF);
        } else {
            c.machine_code.push_back(custom_inst & 0xFF);
            c.machine_code.push_back((custom_inst >> 8) & 0xFF);
        }
    } else if (fast_eq(c.inst, ".equ")) {
        DBG(std::cout << "Constant directive" << std::endl;)
        // .equ <name>, <value> = define a constant with name <name> and value <value>

        if (c.arg1.empty() || c.arg2.empty()) {
            throw ChataError(ChataErrorType::Assembler, "Invalid .equ directive", c.line, c.column);
        }

        if (auto num = to_num<int32_t>(c.arg2); num.has_value()) {
            c.constants.push_back({c.arg1, num.value()});
        } else {
            throw ChataError(ChataErrorType::Assembler, "Invalid constant value " + c.arg2, c.line, c.column);
        }
    }
}

void parse_this_line(size_t& i, const std::string_view& data, assembly_context& c) {
    /*c.inst = "addi";
    c.arg1 = "zero";
    c.arg2 = "zero";
    c.arg3 = "0";
    while (i < data.size() && data.at(i) != '\n') {
        i++;
    }
    while (i < data.size() && data.at(i) == '\n') {
        i++;
    }
    return;*/

    c.inst.clear();
    auto is_whitespace = [](const char& c) {
        return c == '\t' || c == ' ';
    };
    auto ch = [&]() {
        DBG(return data.at(i);)
        return data[i];
    };
    auto not_at_end = [](const char& c) {
        return c != '\n' && c != '#';
    };
    while (i < data.size()) {
        char temp = ch();
        if (not_at_end(temp) && is_whitespace(temp)) {
            i++;
        } else {
            break;
        }
    }
    while (i < data.size() && not_at_end(ch()) && !is_whitespace(ch())) {
        c.inst.push_back(ch());
        i++;
    }
    DBG(std::cout << "Instruction candidate: " << c.inst << std::endl;)
    while (i < data.size() && not_at_end(ch()) && is_whitespace(ch())) {
        i++;
    }
    auto parse_arg = [&](chatastring& arg) {
        arg.clear();
        while (i < data.size() && not_at_end(ch()) && ch() != ',' && !is_whitespace(ch())) {
            arg.push_back(ch());
            i++;
        }
        if (i < data.size() && not_at_end(ch())) {
            i++;
        }
        while (i < data.size() && not_at_end(ch()) && is_whitespace(ch())) {
            i++;
        }
    };
    parse_arg(c.arg1);
    if (!c.arg1.empty()) {
        parse_arg(c.arg2);
        if (!c.arg2.empty()) {
            parse_arg(c.arg3);
            if (!c.arg3.empty()) {
                parse_arg(c.arg4);
                if (!c.arg4.empty()) {
                    parse_arg(c.arg5);
                    if (!c.arg5.empty()) {
                        parse_arg(c.arg6);
                        if (!c.arg6.empty()) {
                            c.arg_extra.clear();
                            while (i < data.size() && ch() != '\n') {
                                c.arg_extra.push_back(ch());
                                i++;
                            }
                        }
                    }
                }
            }
        }
    }
    while (i < data.size() && ch() != '\n') {
        i++;
    }
    while (i < data.size() && ch() == '\n') {
        i++;
    }
}

chatavector<uint8_t> assemble_code(const std::string_view& data, const chatavector<RVInstructionSet> supported_sets) {
    // auto then = std::chrono::high_resolution_clock::now();

    struct assembly_context c;

    c.supported_sets = supported_sets;

    using enum RVInstructionSet;

    if (!c.supported_sets.empty()) {
        if (std::find(c.supported_sets.begin(), c.supported_sets.end(), RV32I) == c.supported_sets.end()
            && std::find(c.supported_sets.begin(), c.supported_sets.end(), RV64I) == c.supported_sets.end()) {
            throw ChataError(ChataErrorType::Assembler, "The set of supported RISC-V instruction sets must include at least RV32I or RV64I");
        }
    }

    c.inst.reserve(32);
    c.arg1.reserve(32);
    c.arg2.reserve(32);
    c.arg3.reserve(32);
    c.arg4.reserve(32);
    c.arg5.reserve(32);
    c.arg6.reserve(32);
    c.arg_extra.reserve(32);
    c.machine_code.reserve(128000);

    for (size_t i = 0; i < data.size();) {
        parse_this_line(i, data, c);
        if (c.inst_offset = fast_instr_search(c.inst); c.inst_offset != instr_search_failed) {
            make_inst(c);
        } else if (!make_inst_from_pseudoinst(c)) {
            handle_directives(c);
        }
        c.line++;
    }

    solve_label_offsets(c);

    // auto now = std::chrono::high_resolution_clock::now();
    // auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(now - then);
    // std::cout << "Assembling took " << duration.count() << "ms" << std::endl;

#if !defined(DEBUG)
    return c.machine_code;
#endif
#if defined(DEBUG)

    DBG(std::cout << "Ok, here's the assembled code:" << std::endl;)
    // Show the code in hex form
    DBG(for (auto c : c.machine_code) { printf("%02x ", c); })

    DBG(std::cout << "Let's compare this against the reference, gcc as" << std::endl;)

    std::ofstream out("temp.s");
    out << data;
    out.close();

    int res = std::system("riscv64-linux-gnu-as -march=rv64gdc temp.s -o temp.o");

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

    return c.machine_code;
#endif
}

} // namespace libchata_internal