// SPDX-License-Identifier: MPL-2.0
#include "assembler.hpp"
#include "csrs.hpp"
#include "debug.hpp"
#include "instructions.hpp"
#include "libchata.hpp"
#include "pseudoinstructions.hpp"
#include "registers.hpp"
#include <cstdint>
#include <filesystem>
#include <fstream>
#include <iostream>
#include <string>
#include <utility>
#include <algorithm>

namespace libchata_internal {

using enum InstrImmPurpose;

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

void handle_super_special_snowflakes(instruction& i, const rvinstruction& base_i, assembly_context& c) {
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
        if (auto num = to_num<int>(c.arg3); num.has_value()) {
            i.rs1 = num.value();
        } else {
            throw ChataError(ChataErrorType::Compiler, "Invalid immediate " + c.arg3, c.line, c.column);
        }
        DBG(std::cout << "CSRI instruction made" << std::endl;)
    } else if (base_i.id == WRSNTO) {
        i.imm = 0b000000001101; // Set imm to the WRSNTO value
        DBG(std::cout << "WRSNTO instruction made" << std::endl;)
    } else if (base_i.id == WRSSTO) {
        i.imm = 0b000000011101; // Set imm to the WRSSTO value
        DBG(std::cout << "WRSSTO instruction made" << std::endl;)
    } else if (base_i.id == CNOP) {
        i.imm = 0b000000000000; // Set imm to the CNOP value
        DBG(std::cout << "CNOP instruction made" << std::endl;)
    } else if (base_i.id == CEBREAK) {
        i.imm = 0b000000000000;
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
    for (; str.at(j) != ')'; j++) {
        reg.push_back(str.at(j));
    }
    return {offset, reg};
}

instruction make_inst(assembly_context& c) {
    DBG(std::cout << "Making instruction" << std::endl;)
    DBG(std::cout << "Instruction: " << c.inst << std::endl;)
    DBG(std::cout << "arg1: " << c.arg1 << std::endl;)
    DBG(std::cout << "arg2: " << c.arg2 << std::endl;)
    DBG(std::cout << "arg3: " << c.arg3 << std::endl;)

    instruction i;

    /*i.inst_offset = fast_instr_search("add");
    //i.inst_offset = 27;
    i.rd = 0;
    i.rs1 = 1;
    i.rs2 = 2;
    c.instruction_bytes += 4;
    return i;*/

    i.inst_offset = c.inst_offset;

    auto& base_i = instructions.at(i.inst_offset);

    // std::cout << "i.name = " << base_i.name << std::endl;

    c.instruction_bytes += base_i.bytes;

    using enum RVInstructionFormat;

    if (base_i.ssargs.super_special_snowflake) {
        handle_super_special_snowflakes(i, base_i, c);
    } else if (base_i.type == R || base_i.type == R4) {
        /*i.rd = 0b00000;
        i.rs1 = 0b00000;
        i.rs2 = 0b00000;
        i.imm = 0;*/

        if (base_i.type == R) {
            if (base_i.ssargs.use_imm_for_rs2) {
                if (auto num = to_num<int>(c.arg3); num.has_value()) {
                    i.imm = num.value();
                } else {
                    throw ChataError(ChataErrorType::Compiler, "Invalid immediate " + c.arg3, c.line, c.column);
                }
            }
        }
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
        auto no_rs2 = base_i.ssargs.custom_reg_val.has_value();
        if (!no_rs2) {
            if (base_i.ssargs.use_imm_for_rs2) {
                i.rs2 = i.imm;
            } else {
                i.rs2 = string_to_register(c.arg3, c).encoding;
            }
        } else {
            i.rs2 = base_i.ssargs.custom_reg_val.value();
        }
        if (base_i.type == R) {
            if (!c.arg4.empty() && no_rs2) {
                i.frm = decode_frm(c.arg4);
            } else if (!c.arg5.empty() && !no_rs2) {
                i.frm = decode_frm(c.arg5);
            } else {
                if (base_i.ssargs.use_frm_for_funct3) {
                    i.frm = 0b111;
                }
            }
        } else if (base_i.type == R4) {
            i.rs3 = string_to_register(c.arg4, c).encoding;
            if (!c.arg5.empty()) {
                i.frm = decode_frm(c.arg5);
            } else {
                if (base_i.ssargs.use_frm_for_funct3) {
                    i.frm = 0b111;
                }
            }
        }
    } else if (base_i.type == I || base_i.type == S) {
        /*i.rd = 0b00000;
        i.rs1 = 0b00000;
        i.rs2 = 0b00000;
        i.imm = 0;*/

        if (auto num = to_num<int>(c.arg3); num.has_value()) {
            i.imm = num.value();
            i.rs1 = string_to_register(c.arg2, c).encoding;
        } else {
            auto [offset, reg] = decode_offset_plus_reg(c.arg2);
            i.imm = offset;
            i.rs1 = string_to_register(reg, c).encoding;
        }
        if (base_i.type == I) {
            i.rd = string_to_register(c.arg1, c).encoding;
        } else if (base_i.type == S) {
            i.rs2 = string_to_register(c.arg1, c).encoding;
        }
    } else if (base_i.type == Branch) {
        if (auto num = to_num<int>(c.arg3); num.has_value()) {
            i.imm = num.value();
        } else {
            i.imm = string_to_label(c.arg3, c);
            i.imm_purpose = LABEL_DEST;
        }
        i.rs1 = string_to_register(c.arg1, c).encoding;
        i.rs2 = string_to_register(c.arg2, c).encoding;
    } else if (base_i.type == U) {
        if (auto num = to_num<int>(c.arg2); num.has_value()) {
            i.imm = num.value();
        } else {
            throw ChataError(ChataErrorType::Compiler, "Invalid immediate " + c.arg2, c.line, c.column);
        }
        i.rd = string_to_register(c.arg1, c).encoding;
    } else if (base_i.type == J) {
        if (auto num = to_num<int>(c.arg2); num.has_value()) {
            i.imm = num.value();
        } else {
            i.imm = string_to_label(c.arg2, c);
            i.imm_purpose = LABEL_DEST;
        }
        i.rd = string_to_register(c.arg1, c).encoding;
    } else if (base_i.type == CJ) {
        if (auto num = to_num<int>(c.arg1); num.has_value()) {
            i.imm = num.value();
        } else {
            i.imm = string_to_label(c.arg1, c);
            i.imm_purpose = LABEL_DEST;
        }
    } else if (base_i.type == CL) {
        if (auto num = to_num<int>(c.arg3); num.has_value()) {
            i.imm = num.value();
            i.rs1 = string_to_register(c.arg2, c).encoding & 0b111;
        } else {
            auto [offset, reg] = decode_offset_plus_reg(c.arg2);
            i.imm = offset;
            i.rs1 = string_to_register(reg, c).encoding & 0b111;
        }
        i.rd = string_to_register(c.arg1, c).encoding & 0b111;
    } else if (base_i.type == CS) {
        if (auto num = to_num<int>(c.arg3); num.has_value()) {
            i.imm = num.value();
            i.rs1 = string_to_register(c.arg2, c).encoding & 0b111;
        } else {
            auto [offset, reg] = decode_offset_plus_reg(c.arg2);
            i.imm = offset;
            i.rs1 = string_to_register(reg, c).encoding & 0b111;
        }
        i.rs2 = string_to_register(c.arg1, c).encoding & 0b111;
    } else if (base_i.type == CB) {
        if (auto num = to_num<int>(c.arg2); num.has_value()) {
            i.imm = num.value();
        } else {
            i.imm = string_to_label(c.arg2, c);
            i.imm_purpose = LABEL_NODE;
        }
        i.rs1 = string_to_register(c.arg1, c).encoding & 0b111;
    } else if (base_i.type == CR) {
        i.rd = string_to_register(c.arg1, c).encoding;
        if (base_i.ssargs.custom_reg_val.has_value()) {
            i.rs2 = base_i.ssargs.custom_reg_val.value();
        } else {
            i.rs2 = string_to_register(c.arg2, c).encoding;
        }
    } else if (base_i.type == CI) {
        i.rd = string_to_register(c.arg1, c).encoding;
        if (auto num = to_num<int>(c.arg2); num.has_value()) {
            i.imm = num.value();
        } else {
            auto [offset, reg] = decode_offset_plus_reg(c.arg2); // discard reg
            i.imm = offset;
        }
    } else if (base_i.type == CSS) {
        i.rs2 = string_to_register(c.arg1, c).encoding;
        if (auto num = to_num<int>(c.arg2); num.has_value()) {
            i.imm = num.value();
        } else {
            auto [offset, reg] = decode_offset_plus_reg(c.arg2); // discard reg
            i.imm = offset;
        }
    } else if (base_i.type == CIW) {
        i.rd = string_to_register(c.arg1, c).encoding & 0b111; // Only use the lower 3 bits
        if (auto num = to_num<int>(c.arg2); num.has_value()) {
            i.imm = num.value();
        } else {
            throw ChataError(ChataErrorType::Compiler, "Invalid immediate " + c.arg2, c.line, c.column);
        }
    } else if (base_i.type == CA) {
        i.rd = string_to_register(c.arg1, c).encoding & 0b111; // Only use the lower 3 bits
        i.rs2 = string_to_register(c.arg2, c).encoding & 0b111;
    }

    DBG(std::cout << "Instruction made" << std::endl;)

    return i;
}

// The generate_pseudoinstruction_converter.py script generated the following code. DO NOT MODIFY!
// Start make_inst_from_pseudoinst
chatavector<instruction> make_inst_from_pseudoinst(assembly_context& c) {
    if (c.inst.size() < 1) return {};
    if (c.inst[0] == 'b') {
        if (c.inst.size() < 2) return {};
        if (c.inst[1] == 'e') {
            if (c.inst.size() < 3) return {};
            if (c.inst[2] == 'q') {
                if (c.inst.size() < 4) return {};
                if (c.inst[3] == 'z') {
                    if (c.inst.size() < 5) return beqz_instr(c);
                }
            }
        }
        if (c.inst[1] == 'g') {
            if (c.inst.size() < 3) return {};
            if (c.inst[2] == 'e') {
                if (c.inst.size() < 4) return {};
                if (c.inst[3] == 'z') {
                    if (c.inst.size() < 5) return bgez_instr(c);
                }
            }
            if (c.inst[2] == 't') {
                if (c.inst.size() < 4) return bgt_instr(c);
                if (c.inst[3] == 'z') {
                    if (c.inst.size() < 5) return bgtz_instr(c);
                }
                if (c.inst[3] == 'u') {
                    if (c.inst.size() < 5) return bgtu_instr(c);
                }
            }
        }
        if (c.inst[1] == 'l') {
            if (c.inst.size() < 3) return {};
            if (c.inst[2] == 'e') {
                if (c.inst.size() < 4) return ble_instr(c);
                if (c.inst[3] == 'z') {
                    if (c.inst.size() < 5) return blez_instr(c);
                }
                if (c.inst[3] == 'u') {
                    if (c.inst.size() < 5) return bleu_instr(c);
                }
            }
        }
        if (c.inst[1] == 'n') {
            if (c.inst.size() < 3) return {};
            if (c.inst[2] == 'e') {
                if (c.inst.size() < 4) return {};
                if (c.inst[3] == 'z') {
                    if (c.inst.size() < 5) return bnez_instr(c);
                }
            }
        }
    }
    if (c.inst[0] == 'l') {
        if (c.inst.size() < 2) return {};
        if (c.inst[1] == 'a') {
            if (c.inst.size() < 3) return la_instr(c);
        }
        if (c.inst[1] == 'i') {
            if (c.inst.size() < 3) return li_instr(c);
        }
    }
    if (c.inst[0] == 'n') {
        if (c.inst.size() < 2) return {};
        if (c.inst[1] == 'e') {
            if (c.inst.size() < 3) return {};
            if (c.inst[2] == 'g') {
                if (c.inst.size() < 4) return neg_instr(c);
            }
        }
        if (c.inst[1] == 'o') {
            if (c.inst.size() < 3) return {};
            if (c.inst[2] == 't') {
                if (c.inst.size() < 4) return not_instr(c);
            }
            if (c.inst[2] == 'p') {
                if (c.inst.size() < 4) return nop_instr(c);
            }
        }
    }
    if (c.inst[0] == 'c') {
        if (c.inst.size() < 2) return {};
        if (c.inst[1] == 'a') {
            if (c.inst.size() < 3) return {};
            if (c.inst[2] == 'l') {
                if (c.inst.size() < 4) return {};
                if (c.inst[3] == 'l') {
                    if (c.inst.size() < 5) return call_instr(c);
                }
            }
        }
        if (c.inst[1] == 's') {
            if (c.inst.size() < 3) return {};
            if (c.inst[2] == 'r') {
                if (c.inst.size() < 4) return {};
                if (c.inst[3] == 'c') {
                    if (c.inst.size() < 5) return csrc_instr(c);
                    if (c.inst[4] == 'i') {
                        if (c.inst.size() < 6) return csrci_instr(c);
                    }
                }
                if (c.inst[3] == 's') {
                    if (c.inst.size() < 5) return csrs_instr(c);
                    if (c.inst[4] == 'i') {
                        if (c.inst.size() < 6) return csrsi_instr(c);
                    }
                }
                if (c.inst[3] == 'r') {
                    if (c.inst.size() < 5) return csrr_instr(c);
                }
                if (c.inst[3] == 'w') {
                    if (c.inst.size() < 5) return csrw_instr(c);
                    if (c.inst[4] == 'i') {
                        if (c.inst.size() < 6) return csrwi_instr(c);
                    }
                }
            }
        }
    }
    if (c.inst[0] == 'r') {
        if (c.inst.size() < 2) return {};
        if (c.inst[1] == 'e') {
            if (c.inst.size() < 3) return {};
            if (c.inst[2] == 't') {
                if (c.inst.size() < 4) return ret_instr(c);
            }
        }
        if (c.inst[1] == 'd') {
            if (c.inst.size() < 3) return {};
            if (c.inst[2] == 't') {
                if (c.inst.size() < 4) return {};
                if (c.inst[3] == 'i') {
                    if (c.inst.size() < 5) return {};
                    if (c.inst[4] == 'm') {
                        if (c.inst.size() < 6) return {};
                        if (c.inst[5] == 'e') {
                            if (c.inst.size() < 7) return rdtime_instr(c);
                            if (c.inst[6] == 'h') {
                                if (c.inst.size() < 8) return rdtimeh_instr(c);
                            }
                        }
                    }
                }
            }
            if (c.inst[2] == 'c') {
                if (c.inst.size() < 4) return {};
                if (c.inst[3] == 'y') {
                    if (c.inst.size() < 5) return {};
                    if (c.inst[4] == 'c') {
                        if (c.inst.size() < 6) return {};
                        if (c.inst[5] == 'l') {
                            if (c.inst.size() < 7) return {};
                            if (c.inst[6] == 'e') {
                                if (c.inst.size() < 8) return rdcycle_instr(c);
                                if (c.inst[7] == 'h') {
                                    if (c.inst.size() < 9) return rdcycleh_instr(c);
                                }
                            }
                        }
                    }
                }
            }
            if (c.inst[2] == 'i') {
                if (c.inst.size() < 4) return {};
                if (c.inst[3] == 'n') {
                    if (c.inst.size() < 5) return {};
                    if (c.inst[4] == 's') {
                        if (c.inst.size() < 6) return {};
                        if (c.inst[5] == 't') {
                            if (c.inst.size() < 7) return {};
                            if (c.inst[6] == 'r') {
                                if (c.inst.size() < 8) return {};
                                if (c.inst[7] == 'e') {
                                    if (c.inst.size() < 9) return {};
                                    if (c.inst[8] == 't') {
                                        if (c.inst.size() < 10) return rdinstret_instr(c);
                                        if (c.inst[9] == 'h') {
                                            if (c.inst.size() < 11) return rdinstreth_instr(c);
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    if (c.inst[0] == 'f') {
        if (c.inst.size() < 2) return {};
        if (c.inst[1] == 's') {
            if (c.inst.size() < 3) return {};
            if (c.inst[2] == 'c') {
                if (c.inst.size() < 4) return {};
                if (c.inst[3] == 's') {
                    if (c.inst.size() < 5) return {};
                    if (c.inst[4] == 'r') {
                        if (c.inst.size() < 6) return fscsr_instr(c);
                    }
                }
            }
            if (c.inst[2] == 'r') {
                if (c.inst.size() < 4) return {};
                if (c.inst[3] == 'm') {
                    if (c.inst.size() < 5) return fsrm_instr(c);
                    if (c.inst[4] == 'i') {
                        if (c.inst.size() < 6) return fsrmi_instr(c);
                    }
                }
            }
            if (c.inst[2] == 'f') {
                if (c.inst.size() < 4) return {};
                if (c.inst[3] == 'l') {
                    if (c.inst.size() < 5) return {};
                    if (c.inst[4] == 'a') {
                        if (c.inst.size() < 6) return {};
                        if (c.inst[5] == 'g') {
                            if (c.inst.size() < 7) return {};
                            if (c.inst[6] == 's') {
                                if (c.inst.size() < 8) return fsflags_instr(c);
                                if (c.inst[7] == 'i') {
                                    if (c.inst.size() < 9) return fsflagsi_instr(c);
                                }
                            }
                        }
                    }
                }
            }
        }
        if (c.inst[1] == 'r') {
            if (c.inst.size() < 3) return {};
            if (c.inst[2] == 'c') {
                if (c.inst.size() < 4) return {};
                if (c.inst[3] == 's') {
                    if (c.inst.size() < 5) return {};
                    if (c.inst[4] == 'r') {
                        if (c.inst.size() < 6) return frcsr_instr(c);
                    }
                }
            }
            if (c.inst[2] == 'r') {
                if (c.inst.size() < 4) return {};
                if (c.inst[3] == 'm') {
                    if (c.inst.size() < 5) return frrm_instr(c);
                }
            }
            if (c.inst[2] == 'f') {
                if (c.inst.size() < 4) return {};
                if (c.inst[3] == 'l') {
                    if (c.inst.size() < 5) return {};
                    if (c.inst[4] == 'a') {
                        if (c.inst.size() < 6) return {};
                        if (c.inst[5] == 'g') {
                            if (c.inst.size() < 7) return {};
                            if (c.inst[6] == 's') {
                                if (c.inst.size() < 8) return frflags_instr(c);
                            }
                        }
                    }
                }
            }
        }
        if (c.inst[1] == 'm') {
            if (c.inst.size() < 3) return {};
            if (c.inst[2] == 'v') {
                if (c.inst.size() < 4) return {};
                if (c.inst[3] == 's') {
                    if (c.inst.size() < 5) return {};
                    if (c.inst[4] == 'x') {
                        if (c.inst.size() < 6) return fmvsx_instr(c);
                    }
                }
                if (c.inst[3] == 'x') {
                    if (c.inst.size() < 5) return {};
                    if (c.inst[4] == 's') {
                        if (c.inst.size() < 6) return fmvxs_instr(c);
                    }
                }
            }
        }
    }
    if (c.inst[0] == 'm') {
        if (c.inst.size() < 2) return {};
        if (c.inst[1] == 'v') {
            if (c.inst.size() < 3) return mv_instr(c);
        }
    }
    if (c.inst[0] == 'j') {
        if (c.inst.size() < 2) return j_instr(c);
    }
    return {};
}
// End make_inst_from_pseudoinst

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
                                if (step == 1) {
                                    label_offset += instructions.at(inst.inst_offset).bytes;
                                }
                                DBG(std::cout << "Found offset for label " << inst.imm << ": " << label_offset << std::endl;)
                                inst.imm = label_offset;
                                inst.imm_purpose = INSTR_IMM;
                                break;
                            }
                        }
                        if (c.nodes.at(j).imm_purpose != LABEL_NODE) {
                            label_offset += instructions.at(c.nodes.at(j).inst_offset).bytes * step;
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

void generate_machine_code(assembly_context& c) {
    size_t offset = 0;
    for (auto& i : c.nodes) {
        if (i.imm_purpose == LABEL_NODE) {
            continue;
        } else if (i.imm_purpose == RAW_INSTR) {
            reinterpret_cast<uint32_t&>(c.machine_code.data()[offset]) = i.imm;
            offset += i.inst_offset;
            continue;
        }
        uint32_t inst = 0;
        auto base_i = instructions.at(i.inst_offset); // Don't make this one auto&, it's slower
        inst |= base_i.opcode;
        using enum RVInstructionFormat;
        using enum RVInstructionID;
        if (base_i.type == R) {
            DBG(std::cout << "Encoding R-type instruction with name " << base_i.name << std::endl;)
            inst |= i.rd << 7; // Add rd
            if (base_i.ssargs.use_frm_for_funct3) {
                inst |= i.frm << 12; // Add frm
            } else {
                inst |= (base_i.funct & 0b111) << 12; // Add funct3
            }
            inst |= i.rs1 << 15;               // Add rs1
            inst |= i.rs2 << 20;               // Add rs2
            inst |= (base_i.funct >> 3) << 25; // Add funct7
        } else if (base_i.type == I) {
            DBG(std::cout << "Encoding I-type instruction with name " << base_i.name << std::endl;)
            inst |= i.rd << 7;          // Add rd
            inst |= base_i.funct << 12; // Add funct3
            inst |= i.rs1 << 15;        // Add rs1
            inst |= i.imm << 20;        // Add imm
        } else if (base_i.type == S) {
            DBG(std::cout << "Encoding S-type instruction with name " << base_i.name << std::endl;)
            inst |= (i.imm & 0b11111) << 7; // Add imm[4:0]
            inst |= base_i.funct << 12;     // Add funct3
            inst |= i.rs1 << 15;            // Add rs1
            inst |= i.rs2 << 20;            // Add rs2
            inst |= (i.imm >> 5) << 25;     // Add imm[11:5]
        } else if (base_i.type == Branch) {
            DBG(std::cout << "Encoding Branch-type instruction with name " << base_i.name << std::endl;)
            inst |= ((i.imm >> 11) & 0b1) << 7;      // Add imm[11]
            inst |= ((i.imm >> 1) & 0b1111) << 8;    // Add imm[4:1]
            inst |= base_i.funct << 12;              // Add funct3
            inst |= i.rs1 << 15;                     // Add rs1
            inst |= i.rs2 << 20;                     // Add rs2
            inst |= ((i.imm >> 5) & 0b111111) << 25; // Add imm[10:5]
            inst |= ((i.imm >> 12) & 0b1) << 31;     // Add imm[12]
        } else if (base_i.type == U) {
            DBG(std::cout << "Encoding U-type instruction with name " << base_i.name << std::endl;)
            inst |= i.rd << 7;   // Add rd
            inst |= i.imm << 12; // Add imm[31:12]
        } else if (base_i.type == J) {
            DBG(std::cout << "Encoding J-type instruction with name " << base_i.name << std::endl;)
            inst |= i.rd << 7;                           // Add rd
            inst |= ((i.imm >> 12) & 0b11111111) << 12;  // Add imm[19:12]
            inst |= ((i.imm >> 11) & 0b1) << 20;         // Add imm[11]
            inst |= ((i.imm >> 1) & 0b1111111111) << 21; // Add imm[10:1]
            inst |= ((i.imm >> 20) & 0b1) << 31;         // Add imm[20]
        } else if (base_i.type == R4) {
            DBG(std::cout << "Encoding R4-type instruction with name " << base_i.name << std::endl;)
            inst |= i.rd << 7; // Add rd
            if (base_i.ssargs.use_frm_for_funct3) {
                inst |= i.frm << 12; // Add frm
            } else {
                inst |= (base_i.funct & 0b111) << 12; // Add funct3
            }
            inst |= i.rs1 << 15;               // Add rs1
            inst |= i.rs2 << 20;               // Add rs2
            inst |= (base_i.funct >> 3) << 25; // Add funct2
            inst |= i.rs3 << 27;               // Add rs3
        } else if (base_i.type == CI) {
            DBG(std::cout << "Encoding CI-type instruction with name " << base_i.name << std::endl;)
            if (base_i.id == CLWSP || base_i.id == CFLWSP) {                                                  // offset[4:2|7:6]
                inst |= ((i.imm >> 6) & 0b11) << 2;                                                           // Add offset[7:6]
                inst |= ((i.imm >> 2) & 0b1111) << 4;                                                         // Add offset[4:2]
                inst |= ((i.imm >> 5) & 0b1) << 12;                                                           // Add offset[5]
            } else if (base_i.id == CLDSP || base_i.id == CFLDSP) {                                           // offset[4:3|8:6]
                inst |= ((i.imm >> 6) & 0b111) << 2;                                                          // Add offset[8:6]
                inst |= ((i.imm >> 3) & 0b11) << 5;                                                           // Add offset[4:3]
                inst |= ((i.imm >> 5) & 0b1) << 12;                                                           // Add offset[5]
            } else if (base_i.id == CLI || base_i.id == CADDI || base_i.id == CADDIW || base_i.id == CSLLI) { // imm[5], imm[4:0]
                inst |= (i.imm & 0b11111) << 2;                                                               // Add imm[4:0]
                inst |= ((i.imm >> 5) & 0b1) << 12;                                                           // Add imm[5]
            } else if (base_i.id == CLUI) {                                                                   // nzimm[17], imm[16:12]
                inst |= ((i.imm >> 12) & 0b11111) << 2;                                                       // Add imm[16:12]
                inst |= ((i.imm >> 17) & 0b1) << 12;                                                          // Add nzimm[17]
            } else if (base_i.id == CADDI16SP) {                                                              // nzimm[9], nzimm[4|6|8:7|5]
                inst |= ((i.imm >> 5) & 0b1) << 2;                                                            // Add nzimm[5]
                inst |= ((i.imm >> 7) & 0b11) << 3;                                                           // Add nzimm[8:7]
                inst |= ((i.imm >> 6) & 0b1) << 5;                                                            // Add nzimm[6]
                inst |= ((i.imm >> 4) & 0b1) << 6;                                                            // Add nzimm[4]
                inst |= ((i.imm >> 9) & 0b1) << 12;                                                           // Add nzimm[9]
            } else {                                                                                          // offset[4|9:6]
                inst |= ((i.imm >> 6) & 0b1111) << 2;                                                         // Add offset[9:6]
                inst |= ((i.imm >> 4) & 0b1) << 6;                                                            // Add offset[4]
                inst |= ((i.imm >> 5) & 0b1) << 12;                                                           // Add offset[5]
            }
            inst |= i.rd << 7; // Add rd
            if (base_i.id == CEBREAK) {
                inst |= base_i.funct << 12; // Add funct4
            } else {
                inst |= base_i.funct << 13; // Add funct3
            }
        } else if (base_i.type == CR) {
            DBG(std::cout << "Encoding CR-type instruction with name " << base_i.name << std::endl;)
            inst |= i.rs2 << 2;         // Add rs2
            inst |= i.rd << 7;          // Add rd
            inst |= base_i.funct << 12; // Add funct4
        } else if (base_i.type == CSS) {
            DBG(std::cout << "Encoding CSS-type instruction with name " << base_i.name << std::endl;)
            inst |= i.rs2 << 2;                                     // Add rs2
            if (base_i.id == CSWSP || base_i.id == CFSWSP) {        // offset[5:2|7:6]
                inst |= ((i.imm >> 6) & 0b11) << 7;                 // Add offset[7:6]
                inst |= ((i.imm >> 2) & 0b1111) << 9;               // Add offset[5:2]
            } else if (base_i.id == CSDSP || base_i.id == CFSDSP) { // offset[5:3|8:6]
                inst |= ((i.imm >> 6) & 0b111) << 7;                // Add offset[8:6]
                inst |= ((i.imm >> 3) & 0b111) << 10;               // Add offset[5:3]
            } else {                                                // offset[5:4|9:6]
                inst |= ((i.imm >> 6) & 0b1111) << 7;               // Add offset[9:6]
                inst |= ((i.imm >> 4) & 0b11) << 11;                // Add offset[5:4]
            }
            inst |= base_i.funct << 13; // Add funct3
        } else if (base_i.type == CIW) {
            DBG(std::cout << "Encoding CIW-type instruction with name " << base_i.name << std::endl;)
            inst |= i.rd << 2;                    // Add rd' (just 3 bits)
            inst |= ((i.imm >> 3) & 0b1) << 5;    // Add nzuimm[3]
            inst |= ((i.imm >> 2) & 0b1) << 6;    // Add nzuimm[2]
            inst |= ((i.imm >> 6) & 0b1111) << 7; // Add nzuimm[9:6]
            inst |= ((i.imm >> 4) & 0b11) << 11;  // Add nzuimm[5:4]
            inst |= base_i.funct << 13;           // Add funct3
        } else if (base_i.type == CL) {
            DBG(std::cout << "Encoding CL-type instruction with name " << base_i.name << std::endl;)
            inst |= i.rd << 2;                                  // Add rd' (just 3 bits)
            if (base_i.id == CLW || base_i.id == CFLW) {        // offset[2|6]
                inst |= ((i.imm >> 6) & 0b1) << 5;              // Add offset[6]
                inst |= ((i.imm >> 2) & 0b1) << 6;              // Add offset[2]
            } else if (base_i.id == CLD || base_i.id == CFLD) { // offset[7:6]
                inst |= ((i.imm >> 6) & 0b11) << 5;             // Add offset[7:6]
            }
            inst |= i.rs1 << 7;                   // Add rs1' (just 3 bits)
            inst |= ((i.imm >> 3) & 0b111) << 10; // Add offset[5:3]
            inst |= base_i.funct << 13;           // Add funct3
        } else if (base_i.type == CS) {
            DBG(std::cout << "Encoding CS-type instruction with name " << base_i.name << std::endl;)
            inst |= i.rs2 << 2;                                 // Add rs2' (just 3 bits)
            if (base_i.id == CSW || base_i.id == CFSW) {        // offset[2|6]
                inst |= ((i.imm >> 6) & 0b1) << 5;              // Add offset[6]
                inst |= ((i.imm >> 2) & 0b1) << 6;              // Add offset[2]
            } else if (base_i.id == CSD || base_i.id == CFSD) { // offset[7:6]
                inst |= ((i.imm >> 6) & 0b11) << 5;             // Add offset[7:6]
            }
            inst |= i.rs1 << 7;                   // Add rs1' (just 3 bits)
            inst |= ((i.imm >> 3) & 0b111) << 10; // Add offset[5:3]
            inst |= base_i.funct << 13;           // Add funct3
        } else if (base_i.type == CA) {
            DBG(std::cout << "Encoding CA-type instruction with name " << base_i.name << std::endl;)
            inst |= i.rs2 << 2;                 // Add rs2' (just 3 bits)
            inst |= (base_i.funct & 0b11) << 5; // Add funct2
            inst |= i.rd << 7;                  // Add rd' (just 3 bits)
            inst |= (base_i.funct >> 2) << 10;  // Add funct6
        } else if (base_i.type == CB) {
            DBG(std::cout << "Encoding CB-type instruction with name " << base_i.name << std::endl;)
            if (base_i.id == CSRLI || base_i.id == CSRAI || base_i.id == CANDI) { // shamt[5], shamt[4:0]
                inst |= (i.imm & 0b11111) << 2;                                   // Add shamt[4:0]
                inst |= ((i.imm >> 5) & 0b1) << 12;                               // Add shamt[5]
            } else {
                inst |= ((i.imm >> 5) & 0b1) << 2;   // Add offset[5]
                inst |= ((i.imm >> 1) & 0b11) << 3;  // Add offset[2:1]
                inst |= ((i.imm >> 6) & 0b11) << 5;  // Add offset[7:6]
                inst |= ((i.imm >> 3) & 0b11) << 10; // Add offset[4:3]
                inst |= ((i.imm >> 8) & 0b1) << 12;  // Add offset[8]
            }
            inst |= i.rs1 << 7; // Add rs1' (just 3 bits)
            if (base_i.id == CSRLI || base_i.id == CSRAI || base_i.id == CANDI) {
                inst |= (base_i.funct & 0b11) << 10;         // Add funct2
                inst |= ((base_i.funct >> 2) & 0b111) << 13; // Add funct3
            } else {
                inst |= base_i.funct << 13; // Add funct3
            }
        } else if (base_i.type == CJ) {
            DBG(std::cout << "Encoding CJ-type instruction with name " << base_i.name << std::endl;)
            inst |= ((i.imm >> 5) & 0b1) << 2;   // Add offset[5]
            inst |= ((i.imm >> 1) & 0b111) << 3; // Add offset[3:1]
            inst |= ((i.imm >> 7) & 0b1) << 6;   // Add offset[7]
            inst |= ((i.imm >> 6) & 0b1) << 7;   // Add offset[6]
            inst |= ((i.imm >> 10) & 0b1) << 8;  // Add offset[10]
            inst |= ((i.imm >> 8) & 0b11) << 9;  // Add offset[9:8]
            inst |= ((i.imm >> 4) & 0b1) << 11;  // Add offset[4]
            inst |= ((i.imm >> 11) & 0b1) << 12; // Add offset[11]
            inst |= base_i.funct << 13;          // Add funct3
        }
        reinterpret_cast<uint32_t&>(c.machine_code.data()[offset]) = inst;
        offset += base_i.bytes;
    }
}

chatavector<RVInstructionSet> decode_sets(const chatastring& str) {
    // Example: For an input str that looks like "rv64ifma", this function will return a vector containing RV64I, RV64F, RV64M, and RV64A
    chatavector<RVInstructionSet> sets;
    chatastring search_str;
    for (const char& c : str) {
        search_str.push_back(c);
        //for (const auto& name : instruction_set
    }
}

void handle_directives(assembly_context& c) {
    if (c.inst.back() == ':') {
        DBG(std::cout << "Looks like this is a label, adding it" << std::endl;)
        c.nodes.push_back(instruction {.imm = string_to_label(c.inst, c), .imm_purpose = LABEL_NODE});
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
            const std::array<std::pair<std::string_view, RVInstructionSet>, 21> arch_option_names = {{
                {"rv32i", RV32I},
                {"rv64i", RV64I},
                {"m", RV32M}, // Using RV32M although it means M in general
                {"a", RV32A},
                {"f", RV32F},
                {"d", RV32D},
                {"q", RV32Q},
                {"zifencei", Zifencei},
                {"zicsr", Zicsr},
                {"zawrs", Zawrs},
                {"zicond", Zicond},
                {"zacas", Zacas},
                {"zcb", Zcb},
                {"zbb", Zbb},
                {"zcmp", Zcmp},
                {"c", C},
                {"zcd", Zcd},
                {"zcf", Zcf},
                {"zcmt", Zcmt},
                {"b", B},
                {"v", V}
            }};

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
            c.options.push_back({});
        } else if (fast_eq(c.arg1, "pop")) {
            DBG(std::cout << "Popping options" << std::endl;)
            c.options.pop_back();
        }
    } else if (fast_eq(c.inst, ".insn")) {
        DBG(std::cout << "Instruction directive" << std::endl;)
        // .insn <value> = make an instruction with content <value>
        // .insn <insn_length>, <value> = make an instruction with length <insn_length> and content <value> (verify length)
        // .insn <type> <fields> = make an instruction with type <type> and fields <fields>
        instruction i;
        uint8_t required_length = 0;
        if (!c.arg1.empty() && c.arg2.empty()) {
            if (auto num = to_num<uint32_t>(c.arg1); num.has_value()) {
                i.imm = num.value();
                i.imm_purpose = InstrImmPurpose::RAW_INSTR;
            }
        } else if (!c.arg1.empty() && !c.arg2.empty()) {
            if (auto num = to_num<uint32_t>(c.arg2); num.has_value()) {
                i.imm = num.value();
                i.imm_purpose = InstrImmPurpose::RAW_INSTR;
            }
            if (auto num = to_num<uint8_t>(c.arg1); num.has_value()) {
                required_length = num.value();
            }
        }
        if (i.imm & 0xFFFF0000) {
            i.inst_offset = 4;
        } else {
            i.inst_offset = 2;
        }
        if (!c.arg1.empty() && !c.arg2.empty()) {
            if (required_length != i.inst_offset) {
                throw ChataError(ChataErrorType::Assembler, "Instruction length mismatch: expected " + to_chatastring(required_length) + ", got " + to_chatastring(i.inst_offset));
            }
        }
        c.instruction_bytes += i.inst_offset;
        c.nodes.push_back(i);
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
        return data.at(i);
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
                            parse_arg(c.arg7);
                        }
                    }
                }
            }
        }
    }
    while (i < data.size() && data.at(i) != '\n') {
        i++;
    }
    while (i < data.size() && data.at(i) == '\n') {
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

    for (size_t i = 0; i < data.size();) {
        parse_this_line(i, data, c);
        if (c.inst_offset = fast_instr_search(c.inst); c.inst_offset != instr_search_failed) {
            c.nodes.push_back(make_inst(c));
        } else if (auto instrs = make_inst_from_pseudoinst(c); !instrs.empty()) {
            for (auto& inst : instrs) {
                c.nodes.push_back(inst);
            }
        } else {
            handle_directives(c);
        }
        c.line++;
    }

    c.machine_code.resize(c.instruction_bytes);

    solve_label_offsets(c);

    generate_machine_code(c);

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