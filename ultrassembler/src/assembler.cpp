// SPDX-License-Identifier: MPL-2.0
#include "assembler.hpp"
#include "csrs.hpp"
#include "debug.hpp"
#include "instructions.hpp"
#include "pseudoinstructions.hpp"
#include "registers.hpp"
#include "ultrassembler.hpp"
#include <algorithm>
#include <cmath>
#include <cstdint>
#include <filesystem>
#include <fstream>
#include <iostream>
#include <limits>
#include <memory>
#include <string>
#include <utility>

namespace ultrassembler_internal {

int string_to_label(ultrastring& str, assembly_context& c) {
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

template <typename T>
std::optional<T> decode_constant(const ultrastring& constant, assembly_context& c) {
    if (c.constants.empty()) {
        return std::nullopt;
    }
    if (constant.size() > 5) {
        if (constant[0] == '%') {
            ultrastring unwrapped = constant.substr(4, constant.size() - 5);
            if (constant[1] == 'l' && constant[2] == 'o' && constant[3] == '(' && constant[constant.size() - 1] == ')') {
                for (const auto& con : c.constants) {
                    if (fast_eq(con.first, unwrapped)) {
                        auto num = to_num<T>(con.second);
                        if (num.has_value()) {
                            return (num.value() << 20) >> 20; // This preserves the sign bit
                        }
                    }
                }
            } else if (constant[1] == 'h' && constant[2] == 'i' && constant[3] == '(' && constant[constant.size() - 1] == ')') {
                for (const auto& con : c.constants) {
                    if (fast_eq(con.first, unwrapped)) {
                        auto num = to_num<T>(con.second);
                        if (num.has_value()) {
                            return (num.value() >> 12) & 0xFFFFF;
                        }
                    }
                }
            } else {
                throw UltraError(UltraErrorType::Compiler, "Invalid relocation mode " + constant);
            }
        }
    } else {
        for (const auto& con : c.constants) {
            if (fast_eq(con.first, constant)) {
                return to_num<T>(con.second);
            }
        }
    }
    return std::nullopt;
}

template <typename T>
std::optional<T> decode_imm(const ultrastring& imm, assembly_context& c) {
    if (auto num = to_num<T>(imm); num.has_value()) {
        return num;
    } else {
        return decode_constant<T>(imm, c);
    }
}

inline const rvregister& decode_register(const ultrastring& str) {
    // return registers[4];
    if (auto reg = fast_reg_search(str); reg != reg_search_failed) {
        return registers[reg];
    } else {
        throw UltraError(UltraErrorType::Compiler, "Invalid register " + str);
    }
}

uint8_t decode_frm(const ultrastring& frm) {
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
        throw UltraError(UltraErrorType::Compiler, "Invalid rounding mode " + frm);
    }
}

uint8_t decode_fence(const ultrastring& setting) {
    if (fast_eq(setting, "r")) {
        return 0b0010;
    } else if (fast_eq(setting, "w")) {
        return 0b0001;
    } else if (fast_eq(setting, "rw")) {
        return 0b0011;
    } else {
        throw UltraError(UltraErrorType::Compiler, "Invalid fence setting " + setting);
    }
}

const uint16_t& decode_csr(const ultrastring& csr) {
    if (auto res = fast_csr_search(csr); res != csr_search_failed) {
        return csrs[res].second;
    }
    throw UltraError(UltraErrorType::Compiler, "Invalid CSR " + csr);
}

std::optional<uint8_t> decode_vsew(const ultrastring& str) {
    if (fast_eq(str, "e8")) {
        return 0b000;
    } else if (fast_eq(str, "e16")) {
        return 0b001;
    } else if (fast_eq(str, "e32")) {
        return 0b010;
    } else if (fast_eq(str, "e64")) {
        return 0b011;
    } else if (fast_eq(str, "e128")) {
        return 0b100;
    } else {
        return std::nullopt;
    }
}

std::optional<uint8_t> decode_vlmul(const ultrastring& str) {
    if (fast_eq(str, "m1")) {
        return 0b000;
    } else if (fast_eq(str, "m2")) {
        return 0b001;
    } else if (fast_eq(str, "m4")) {
        return 0b010;
    } else if (fast_eq(str, "m8")) {
        return 0b011;
    } else if (fast_eq(str, "mf8")) {
        return 0b101;
    } else if (fast_eq(str, "mf4")) {
        return 0b110;
    } else if (fast_eq(str, "mf2")) {
        return 0b111;
    } else {
        return std::nullopt;
    }
}

std::optional<uint8_t> decode_vediv(const ultrastring& str) {
    if (fast_eq(str, "d1")) {
        return 0b00;
    } else if (fast_eq(str, "d2")) {
        return 0b01;
    } else if (fast_eq(str, "d4")) {
        return 0b10;
    } else if (fast_eq(str, "d8")) {
        return 0b11;
    } else {
        return std::nullopt;
    }
}

uint8_t decode_fli_imm(const float& value) {
    if (value == -1.0) {
        return 0;
    } else if (value == std::numeric_limits<float>::min()) {
        return 1;
    } else if (value == 1.0 * std::pow(2, -16)) {
        return 2;
    } else if (value == 1.0 * std::pow(2, -15)) {
        return 3;
    } else if (value == 1.0 * std::pow(2, -8)) {
        return 4;
    } else if (value == 1.0 * std::pow(2, -7)) {
        return 5;
    } else if (value == 0.0625) {
        return 6;
    } else if (value == 0.125) {
        return 7;
    } else if (value == 0.25) {
        return 8;
    } else if (value == 0.3125) {
        return 9;
    } else if (value == 0.375) {
        return 10;
    } else if (value == 0.4375) {
        return 11;
    } else if (value == 0.5) {
        return 12;
    } else if (value == 0.625) {
        return 13;
    } else if (value == 0.75) {
        return 14;
    } else if (value == 0.875) {
        return 15;
    } else if (value == 1.0) {
        return 16;
    } else if (value == 1.25) {
        return 17;
    } else if (value == 1.5) {
        return 18;
    } else if (value == 1.75) {
        return 19;
    } else if (value == 2.0) {
        return 20;
    } else if (value == 2.5) {
        return 21;
    } else if (value == 3.0) {
        return 22;
    } else if (value == 4.0) {
        return 23;
    } else if (value == 8.0) {
        return 24;
    } else if (value == 16.0) {
        return 25;
    } else if (value == 128.0) {
        return 26;
    } else if (value == 256.0) {
        return 27;
    } else if (value == std::pow(2, 15)) {
        return 28;
    } else if (value == std::pow(2, 16)) {
        return 29;
    } else if (std::isinf(value) && value > 0) {
        return 30;
    } else if (std::isnan(value)) {
        return 31;
    } else {
        throw UltraError(UltraErrorType::Compiler, "Invalid fli floating-point immediate " + to_ultrastring(value));
    }
}

std::pair<int32_t, ultrastring> decode_offset_plus_reg(const ultrastring& str, assembly_context& c) {
    int32_t offset = 0;
    ultrastring temp;
    size_t j = 0;
    for (; j < str.size() && str.at(j) != '('; j++) {
        temp.push_back(str.at(j));
    }
    auto res = decode_imm<int32_t>(temp, c);
    if (res.has_value()) {
        offset = res.value();
    }
    j++;
    temp.clear();
    for (; j < str.size() && str.at(j) != ')'; j++) {
        temp.push_back(str.at(j));
    }
    return {offset, temp};
}

void remove_extraneous_parentheses(ultrastring& str) {
    if (str.back() == ')') { // Do this first to prevent more copies later
        str.pop_back();
    }
    if (str.front() == '0') {
        str.erase(0, 1);
    }
    if (str.front() == '(') {
        str.erase(0, 1);
    }
}

void handle_super_special_snowflakes(int32_t& imm, uint8_t& rd, uint8_t& rs1, const RVInstructionID& id, assembly_context& c) {
    using enum RVInstructionID;
    if (id == FENCE) {
        imm |= decode_fence(c.arg1) << 4; // Add pred
        imm |= decode_fence(c.arg2);      // Add succ
        DBG(std::cout << "FENCE instruction made" << std::endl;)
    } else if (id == CSRRW || id == CSRRS || id == CSRRC) {
        rd = decode_register(c.arg1).encoding;
        imm = decode_csr(c.arg2);
        rs1 = decode_register(c.arg3).encoding;
        DBG(std::cout << "CSR instruction made" << std::endl;)
    } else if (id == CSRRWI || id == CSRRSI || id == CSRRCI) {
        rd = decode_register(c.arg1).encoding;
        imm = decode_csr(c.arg2);
        if (auto num = decode_imm<int32_t>(c.arg3, c); num.has_value()) {
            rs1 = num.value();
        } else {
            throw UltraError(UltraErrorType::Compiler, "Invalid immediate " + c.arg3, c.line, c.column);
        }
        DBG(std::cout << "CSRI instruction made" << std::endl;)
    } else if (id == VSETVLI || id == VSETIVLI || id == THVSETVLI) {
        rd = decode_register(c.arg1).encoding;

        if (id == VSETVLI || id == THVSETVLI) {
            rs1 = decode_register(c.arg2).encoding;
        } else {
            auto res = decode_imm<int32_t>(c.arg2, c);
            if (res.has_value()) {
                rs1 = res.value();
            } else {
                throw UltraError(UltraErrorType::Compiler, "Invalid immediate " + c.arg2, c.line, c.column);
            }

            imm |= 0b11 << 10;
        }

        auto sew = decode_vsew(c.arg3);
        if (sew.has_value()) {
            if (id == THVSETVLI) {
                imm |= sew.value() << 2;
            } else {
                imm |= sew.value() << 3;
            }
        } else {
            throw UltraError(UltraErrorType::Compiler, "Invalid VSEW " + c.arg3, c.line, c.column);
        }
        if (c.arg4.empty()) {
            return;
        } else if (c.arg4 == "ta") {
            imm |= 0b1 << 6;
            if (c.arg5 == "ma") {
                imm |= 0b1 << 7;
            }
        } else if (c.arg4 == "ma") {
            imm |= 0b1 << 7;
            if (c.arg5 == "ta") {
                imm |= 0b1 << 6;
            }
        } else if (c.arg4 == "tu") {
            if (c.arg5 == "ma") {
                imm |= 0b1 << 7;
            }
        } else if (auto lmul = decode_vlmul(c.arg4); lmul.has_value()) {
            imm |= lmul.value();
            if (c.arg5 == "ta") {
                imm |= 0b1 << 6;
                if (c.arg6 == "ma") {
                    imm |= 0b1 << 7;
                }
            } else if (c.arg5 == "ma") {
                imm |= 0b1 << 7;
                if (c.arg6 == "ta") {
                    imm |= 0b1 << 6;
                }
            } else if (c.arg5 == "tu") {
                if (c.arg6 == "ma") {
                    imm |= 0b1 << 7;
                }
            } else if (auto ediv = decode_vediv(c.arg5); ediv.has_value()) {
                imm |= ediv.value() << 5;
            }
        } else {
            throw UltraError(UltraErrorType::Compiler, "Invalid vtypei " + c.arg4, c.line, c.column);
        }
    }
}

template <auto bits>
void verify_imm(const auto& imm) {
    using T = decltype(bits);
    if constexpr (std::is_signed_v<T>) {
        if (imm < -(1 << (bits - 1)) || imm >= (1 << (bits - 1))) {
            throw UltraError(
                    UltraErrorType::Compiler,
                    "Immediate " + to_ultrastring(imm) + " is out of range [" + to_ultrastring(-(1 << (bits - 1))) + ", " + to_ultrastring((1 << (bits - 1))) + ")",
                    0,
                    0
            );
        }
    } else if constexpr (std::is_unsigned_v<T>) {
        if (imm < 0 || imm >= (1u << bits)) {
            throw UltraError(UltraErrorType::Compiler, "Immediate " + to_ultrastring(imm) + " is out of range [0, " + to_ultrastring((1u << bits)) + ")", 0, 0);
        }
    }
}

void make_inst(assembly_context& c) {
    DBG(std::cout << "Instruction: " << c.inst << std::endl;)
    DBG(std::cout << "arg1: " << c.arg1 << std::endl;)
    DBG(std::cout << "arg2: " << c.arg2 << std::endl;)
    DBG(std::cout << "arg3: " << c.arg3 << std::endl;)

    if (!c.supported_sets.empty()) {
        /*for (const auto& set : c.supported_sets) {
            if (instructions.at(c.inst_offset).set != set && instructions.at(c.inst_offset).subset != set) {
                DBG(std::cout << "Skipping instruction " << c.inst << " because it's not in the supported sets" << std::endl;)
                return;
            }
        }*/
        DBG(std::cout << "Skipping this step because it's unimplemented" << std::endl;)
    }

    DBG(std::cout << "Making instruction" << std::endl;)

    int32_t imm = 0;
    uint8_t rd = 0;
    uint8_t rs1 = 0;
    uint8_t rs2 = 0;
    uint8_t rs3 = 0;
    uint8_t frm = 0;

    auto base_i = instructions.at(c.inst_offset); // Don't make this one auto&, it's slower
    auto& type = base_i.type;
    auto& id = base_i.id;
    auto& reqs = base_i.requirements;
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
    using enum RVInSetMinReqs;

    if (ssargs.super_special_snowflake) {
        handle_super_special_snowflakes(imm, rd, rs1, id, c);
        DBG(std::cout << "Encoding I-type special snowflake instruction with name " << c.inst << std::endl;)
        inst |= rd << 7;     // Add rd
        inst |= funct << 12; // Add funct3
        inst |= rs1 << 15;   // Add rs1
        inst |= imm << 20;   // Add imm
        reinterpret_cast<uint32_t&>(c.machine_code[c.machine_code.size() - bytes]) = inst;
        return;
    }

    if (type == R) {
        /*rd = 0b00000;
        rs1 = 0b00000;
        rs2 = 0b00000;
        imm = 0;*/

        if (ssargs.get_imm_for_rs) {
            if (auto num = decode_imm<int32_t>(c.arg3, c); num.has_value()) {
                // Check for unsigned 5b
                verify_imm<5u>(num.value());
                imm = num.value();
            } else {
                throw UltraError(UltraErrorType::Compiler, "Invalid immediate " + c.arg3, c.line, c.column);
            }
        }
        rd = decode_register(c.arg1).encoding;
        if (opcode == opcode::OP_AMO) { // The A and Zacas sets sometimes use registers that look like (a0)
            remove_extraneous_parentheses(c.arg2);
            remove_extraneous_parentheses(c.arg3);
            using enum RVInstructionID;
            if (id != LRW && id != LRWAQ && id != LRWRL && id != LRWAQRL && id != LRD && id != LRDAQ && id != LRDRL && id != LRDAQRL) {
                std::swap(c.arg2, c.arg3); // For the case of instr rd, rs2, (rs1)
            }
        }
        if (id == FLIS || id == FLID || id == FLIQ || id == FLIH) {
            if (auto num = to_num<float>(c.arg2); num.has_value()) {
                rs1 = decode_fli_imm(num.value());
            } else if (fast_eq(c.arg2, "min")) {
                rs1 = decode_fli_imm(std::numeric_limits<float>::min());
            } else if (fast_eq(c.arg2, "inf")) {
                rs1 = decode_fli_imm(std::numeric_limits<float>::infinity());
            } else if (fast_eq(c.arg2, "nan")) {
                rs1 = decode_fli_imm(std::numeric_limits<float>::quiet_NaN());
            } else {
                throw UltraError(UltraErrorType::Compiler, "Invalid immediate " + c.arg2, c.line, c.column);
            }
        } else {
            rs1 = decode_register(c.arg2).encoding;
        }
        auto no_rs2 = ssargs.custom_reg_val.has_value();
        if (!no_rs2) {
            if (ssargs.get_imm_for_rs) {
                rs2 = imm;
            } else {
                if (reqs == XTheadMemPair) {
                    remove_extraneous_parentheses(c.arg3);
                }
                rs2 = decode_register(c.arg3).encoding;
            }
        } else {
            rs2 = ssargs.custom_reg_val.value();
            if (id == AES64KS1I) {
                rs2 |= imm;
            }
        }

        if (id == AES32DSI || id == AES32DSMI || id == AES32ESI || id == AES32ESMI || id == SM4ED || id == SM4KS) {
            uint8_t bs = decode_imm<int32_t>(c.arg4, c).value();
            inst |= (bs & 0b11) << 30; // Add bs[1:0]
        } else if (id == THSFENCEVMAS) {
            rs2 = rs1;
            rs1 = rd;
            rd = 0b00000;
        } else if (id == THADDSL || reqs == XTheadMemIdx || reqs == XTheadFMemIdx) {
            if (auto num = decode_imm<int32_t>(c.arg4, c); num.has_value()) {
                imm = num.value();
            } else {
                throw UltraError(UltraErrorType::Compiler, "Invalid immediate " + c.arg4, c.line, c.column);
            }
            funct |= (imm & 0b11) << 3; // Add imm2
        } else if (reqs == XTheadMemPair) {
            std::swap(rs1, rs2);
            if (auto num = decode_imm<int32_t>(c.arg4, c); num.has_value()) {
                funct |= num.value() << 3;
                verify_imm<2u>(num.value()); // Check for unsigned 2b
            } else {
                throw UltraError(UltraErrorType::Compiler, "Invalid immediate " + c.arg4, c.line, c.column);
            }
        } else if (opcode != opcode::OP_IMM) {
            if (!c.arg4.empty() && opcode == opcode::OP_FP) {
                frm = decode_frm(c.arg4);
            } else if (!c.arg5.empty() && !no_rs2) {
                frm = decode_frm(c.arg5);
            } else if (!c.arg3.empty() && no_rs2) {
                frm = decode_frm(c.arg3);
            } else {
                if (ssargs.use_frm_for_funct3) {
                    frm = 0b111;
                }
            }
        }

        DBG(std::cout << "Encoding R-type instruction with name " << c.inst << std::endl;)
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
        rd = decode_register(c.arg1).encoding;
        rs1 = decode_register(c.arg2).encoding;
        auto no_rs2 = ssargs.custom_reg_val.has_value();
        if (!no_rs2) {
            if (ssargs.get_imm_for_rs) {
                rs2 = imm;
            } else {
                rs2 = decode_register(c.arg3).encoding;
            }
        } else {
            rs2 = ssargs.custom_reg_val.value();
        }
        rs3 = decode_register(c.arg4).encoding;
        if (!c.arg5.empty()) {
            frm = decode_frm(c.arg5);
        } else {
            if (ssargs.use_frm_for_funct3) {
                frm = 0b111;
            }
        }

        DBG(std::cout << "Encoding R4-type instruction with name " << c.inst << std::endl;)
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
    } else if (type == I) {
        /*rd = 0b00000;
        rs1 = 0b00000;
        rs2 = 0b00000;+
        imm = 0;*/

        if (ssargs.use_funct_for_imm) {
            imm = (funct >> 3) & 0b111111111111; // put funct12 in imm and don't sign extend

            if (id == PREFETCHI || id == PREFETCHR || id == PREFETCHW) {
                auto [offset, reg] = decode_offset_plus_reg(c.arg1, c);
                if (reg.empty()) {
                    throw UltraError(UltraErrorType::Compiler, "Invalid prefetch argument " + c.arg1, c.line, c.column);
                }
                if (auto reg_res = fast_reg_search(reg); reg_res != reg_search_failed) {
                    rs1 = decode_register(reg).encoding;
                } else {
                    throw UltraError(UltraErrorType::Compiler, "Invalid register in prefetch argument " + c.arg1, c.line, c.column);
                }
                imm |= ((offset >> 5) & 0b111111) << 5; // Add offset[11:5]
            } else if (id == THSRRI || id == THTST) {
                rd = decode_register(c.arg1).encoding;
                rs1 = decode_register(c.arg2).encoding;
                if (auto num = decode_imm<int32_t>(c.arg3, c); num.has_value()) {
                    imm |= num.value();
                    verify_imm<6u>(num.value()); // Check for unsigned 6b
                } else {
                    throw UltraError(UltraErrorType::Compiler, "Invalid immediate " + c.arg2, c.line, c.column);
                }
            } else if (id == THSRRIW) {
                rd = decode_register(c.arg1).encoding;
                rs1 = decode_register(c.arg2).encoding;
                if (auto num = decode_imm<int32_t>(c.arg3, c); num.has_value()) {
                    imm |= num.value();
                    verify_imm<5u>(num.value()); // Check for unsigned 5b
                } else {
                    throw UltraError(UltraErrorType::Compiler, "Invalid immediate " + c.arg2, c.line, c.column);
                }
            } else if (reqs == XTheadMemIdx) {
                rd = decode_register(c.arg1).encoding;
                remove_extraneous_parentheses(c.arg2);
                rs1 = decode_register(c.arg2).encoding;
                if (auto num = decode_imm<int32_t>(c.arg3, c); num.has_value()) {
                    imm |= num.value();
                    verify_imm<5>(num.value()); // Check for signed 5b
                } else {
                    throw UltraError(UltraErrorType::Compiler, "Invalid immediate " + c.arg2, c.line, c.column);
                }

                uint8_t imm2 = 0;
                if (auto num = decode_imm<int32_t>(c.arg4, c); num.has_value()) {
                    imm2 = num.value();
                } else {
                    throw UltraError(UltraErrorType::Compiler, "Invalid immediate " + c.arg4, c.line, c.column);
                }
                verify_imm<2u>(imm2); // Check for unsigned 2b
                imm |= imm2 << 5;     // Add imm2
            } else {
                if (ssargs.custom_reg_val.has_value() && !ssargs.no_rs1) {
                    rd = ssargs.custom_reg_val.value();
                    remove_extraneous_parentheses(c.arg1);
                    rs1 = decode_register(c.arg1).encoding;
                } else if (ssargs.custom_reg_val.has_value()) {
                    rd = ssargs.custom_reg_val.value();
                } else {
                    rd = decode_register(c.arg1).encoding;
                    rs1 = decode_register(c.arg2).encoding;
                }
            }
        } else if (id == THEXT || id == THEXTU) {
            rd = decode_register(c.arg1).encoding;
            rs1 = decode_register(c.arg2).encoding;
            if (auto num = decode_imm<int32_t>(c.arg3, c); num.has_value()) {
                imm |= num.value() << 6;     // add imm1
                verify_imm<5u>(num.value()); // Check for unsigned 5b
            } else {
                throw UltraError(UltraErrorType::Compiler, "Invalid immediate " + c.arg3, c.line, c.column);
            }
            if (auto num = decode_imm<int32_t>(c.arg4, c); num.has_value()) {
                imm |= num.value();          // add imm2
                verify_imm<5u>(num.value()); // Check for unsigned 5b
            } else {
                throw UltraError(UltraErrorType::Compiler, "Invalid immediate " + c.arg4, c.line, c.column);
            }
        } else if (auto num = decode_imm<int32_t>(c.arg3, c); num.has_value()) {
            imm = num.value();
            verify_imm<12>(imm); // Check for signed 12b
            rd = decode_register(c.arg1).encoding;
            rs1 = decode_register(c.arg2).encoding;
        } else {
            auto [offset, reg] = decode_offset_plus_reg(c.arg2, c);
            imm = offset;
            verify_imm<12>(imm); // Check for signed 12b
            rd = decode_register(c.arg1).encoding;
            rs1 = decode_register(reg).encoding;
        }

        DBG(std::cout << "Encoding I-type instruction with name " << c.inst << std::endl;)
        inst |= rd << 7;               // Add rd
        inst |= (funct & 0b111) << 12; // Add funct3, trim to last 3b for some which have longer functs
        inst |= rs1 << 15;             // Add rs1
        inst |= imm << 20;             // Add imm
    } else if (type == S) {
        if (auto num = decode_imm<int32_t>(c.arg3, c); num.has_value()) {
            imm = num.value();
            verify_imm<12>(imm); // Check for signed 12b
            rs1 = decode_register(c.arg2).encoding;
        } else {
            auto [offset, reg] = decode_offset_plus_reg(c.arg2, c);
            imm = offset;
            verify_imm<12>(imm); // Check for signed 12b
            rs1 = decode_register(reg).encoding;
        }
        rs2 = decode_register(c.arg1).encoding;

        DBG(std::cout << "Encoding S-type instruction with name " << c.inst << std::endl;)
        inst |= (imm & 0b11111) << 7; // Add imm[4:0]
        inst |= funct << 12;          // Add funct3
        inst |= rs1 << 15;            // Add rs1
        inst |= rs2 << 20;            // Add rs2
        inst |= (imm >> 5) << 25;     // Add imm[11:5]
    } else if (type == Branch) {
        if (c.arg3.size() >= 3 && c.arg3.front() == '.' && (c.arg3[1] == '+' || c.arg3[1] == '-')) { // the .+imm or .-imm relative case
            c.arg3.erase(0, 1);
            if (c.arg3.front() == '+') {
                c.arg3.erase(0, 1);
            }
            if (auto num = to_num<int32_t>(c.arg3); num.has_value()) {
                imm = num.value();
                verify_imm<13>(imm);
            } else {
                throw UltraError(UltraErrorType::Compiler, "Invalid relative immediate " + c.arg3, c.line, c.column);
            }
        } else if (auto num = to_num<int32_t>(c.arg3); num.has_value()) { // the plain imm constant case
            if (c.options.size() > 0 && c.options.back().plain_jump_offset) { // the plain jump offset case
                imm = num.value();
                verify_imm<13>(imm); // Check for signed 13b
            } else {
                // calculate the offset assuming that imm is an absolute address
                imm = num.value() - (c.machine_code.size() - bytes);
                verify_imm<13>(imm); // Check for signed 13b
            }
        } else {
            imm = string_to_label(c.arg3, c);
            c.label_locs.push_back(label_loc {.loc = c.machine_code.size() - bytes, .id = imm, .i_bytes = bytes, .is_dest = false, .format = Branch});
        }
        rs1 = decode_register(c.arg1).encoding;
        rs2 = decode_register(c.arg2).encoding;

        DBG(std::cout << "Encoding Branch-type instruction with name " << c.inst << std::endl;)
        inst |= ((imm >> 11) & 0b1) << 7;      // Add imm[11]
        inst |= ((imm >> 1) & 0b1111) << 8;    // Add imm[4:1]
        inst |= funct << 12;                   // Add funct3
        inst |= rs1 << 15;                     // Add rs1
        inst |= rs2 << 20;                     // Add rs2
        inst |= ((imm >> 5) & 0b111111) << 25; // Add imm[10:5]
        inst |= ((imm >> 12) & 0b1) << 31;     // Add imm[12]
    } else if (type == U) {
        if (auto num = decode_imm<int32_t>(c.arg2, c); num.has_value()) {
            imm = num.value();
        } else {
            throw UltraError(UltraErrorType::Compiler, "Invalid immediate " + c.arg2, c.line, c.column);
        }
        rd = decode_register(c.arg1).encoding;

        DBG(std::cout << "Encoding U-type instruction with name " << c.inst << std::endl;)
        inst |= rd << 7;   // Add rd
        inst |= imm << 12; // Add imm[31:12]
    } else if (type == J) {
        if (c.arg2.size() >= 3 && c.arg2.front() == '.' && (c.arg2[1] == '+' || c.arg2[1] == '-')) { // the .+imm or .-imm relative case
            c.arg2.erase(0, 1);
            if (c.arg2.front() == '+') {
                c.arg2.erase(0, 1);
            }
            if (auto num = to_num<int32_t>(c.arg2); num.has_value()) {
                imm = num.value();
                verify_imm<21>(imm);
            } else {
                throw UltraError(UltraErrorType::Compiler, "Invalid relative immediate " + c.arg2, c.line, c.column);
            }
        } else if (auto num = to_num<int32_t>(c.arg2); num.has_value()) { // the plain imm constant case
            if (c.options.size() > 0 && c.options.back().plain_jump_offset) { // the plain jump offset case
                imm = num.value();
                verify_imm<21>(imm);
            } else {
                // calculate the offset assuming that imm is an absolute address
                imm = num.value() - (c.machine_code.size() - bytes);
                verify_imm<21>(imm);
            }
        } else {
            imm = string_to_label(c.arg2, c);
            c.label_locs.push_back(label_loc {.loc = c.machine_code.size() - bytes, .id = imm, .i_bytes = bytes, .is_dest = false, .format = J});
        }
        rd = decode_register(c.arg1).encoding;

        DBG(std::cout << "Encoding J-type instruction with name " << c.inst << std::endl;)
        inst |= rd << 7;                           // Add rd
        inst |= ((imm >> 12) & 0b11111111) << 12;  // Add imm[19:12]
        inst |= ((imm >> 11) & 0b1) << 20;         // Add imm[11]
        inst |= ((imm >> 1) & 0b1111111111) << 21; // Add imm[10:1]
        inst |= ((imm >> 20) & 0b1) << 31;         // Add imm[20]
    } else if (type == CJ) {
        if (c.arg1.size() >= 3 && c.arg1.front() == '.' && (c.arg1[1] == '+' || c.arg1[1] == '-')) { // the .+imm or .-imm relative case
            c.arg1.erase(0, 1);
            if (c.arg1.front() == '+') {
                c.arg1.erase(0, 1);
            }
            if (auto num = to_num<int32_t>(c.arg1); num.has_value()) {
                imm = num.value();
                verify_imm<12>(imm);
            } else {
                throw UltraError(UltraErrorType::Compiler, "Invalid relative immediate " + c.arg3, c.line, c.column);
            }
        } else if (auto num = to_num<int32_t>(c.arg1); num.has_value()) { // the plain imm constant case
            if (c.options.size() > 0 && c.options.back().plain_jump_offset) { // the plain jump offset case
                imm = num.value();
                verify_imm<12>(imm); // Check for signed 13b
            } else {
                // calculate the offset assuming that imm is an absolute address
                imm = num.value() - (c.machine_code.size() - bytes);
                verify_imm<12>(imm); // Check for signed 13b
            }
        } else {
            imm = string_to_label(c.arg1, c);
            c.label_locs.push_back(label_loc {.loc = c.machine_code.size() - bytes, .id = imm, .i_bytes = bytes, .is_dest = false, .format = CJ});
        }

        DBG(std::cout << "Encoding CJ-type instruction with name " << c.inst << std::endl;)
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
        if (auto num = decode_imm<int32_t>(c.arg3, c); num.has_value()) {
            imm = num.value();
            rs1 = decode_register(c.arg2).encoding & 0b111;
        } else {
            auto [offset, reg] = decode_offset_plus_reg(c.arg2, c);
            imm = offset;
            rs1 = decode_register(reg).encoding & 0b111;
        }
        rd = decode_register(c.arg1).encoding & 0b111;

        DBG(std::cout << "Encoding CL-type instruction with name " << c.inst << std::endl;)
        inst |= rd << 2;                      // Add rd' (just 3 bits)
        if (id == CLW || id == CFLW) {        // offset[2|6]
            verify_imm<7u>(imm);              // Check for unsigned 7b
            inst |= ((imm >> 6) & 0b1) << 5;  // Add offset[6]
            inst |= ((imm >> 2) & 0b1) << 6;  // Add offset[2]
        } else if (id == CLD || id == CFLD) { // offset[7:6]
            verify_imm<8u>(imm);              // Check for unsigned 8b
            inst |= ((imm >> 6) & 0b11) << 5; // Add offset[7:6]
        }
        inst |= rs1 << 7;                   // Add rs1' (just 3 bits)
        inst |= ((imm >> 3) & 0b111) << 10; // Add offset[5:3]
        inst |= funct << 13;                // Add funct3
    } else if (type == CS) {
        if (auto num = decode_imm<int32_t>(c.arg3, c); num.has_value()) {
            imm = num.value();
            rs1 = decode_register(c.arg2).encoding & 0b111;
        } else {
            auto [offset, reg] = decode_offset_plus_reg(c.arg2, c);
            imm = offset;
            rs1 = decode_register(reg).encoding & 0b111;
        }
        rs2 = decode_register(c.arg1).encoding & 0b111;

        DBG(std::cout << "Encoding CS-type instruction with name " << c.inst << std::endl;)
        inst |= rs2 << 2;                     // Add rs2' (just 3 bits)
        if (id == CSW || id == CFSW) {        // offset[2|6]
            verify_imm<7u>(imm);              // Check for unsigned 7b
            inst |= ((imm >> 6) & 0b1) << 5;  // Add offset[6]
            inst |= ((imm >> 2) & 0b1) << 6;  // Add offset[2]
        } else if (id == CSD || id == CFSD) { // offset[7:6]
            verify_imm<8u>(imm);              // Check for unsigned 8b
            inst |= ((imm >> 6) & 0b11) << 5; // Add offset[7:6]
        }
        inst |= rs1 << 7;                   // Add rs1' (just 3 bits)
        inst |= ((imm >> 3) & 0b111) << 10; // Add offset[5:3]
        inst |= funct << 13;                // Add funct3
    } else if (type == CB) {
        if (c.arg2.size() >= 3 && c.arg2.front() == '.' && (c.arg2[1] == '+' || c.arg2[1] == '-')) { // the .+imm or .-imm relative case
            c.arg2.erase(0, 1);
            if (c.arg2.front() == '+') {
                c.arg2.erase(0, 1);
            }
            if (auto num = to_num<int32_t>(c.arg2); num.has_value()) {
                imm = num.value();
            } else {
                throw UltraError(UltraErrorType::Compiler, "Invalid relative immediate " + c.arg3, c.line, c.column);
            }
        } else if (auto num = to_num<int32_t>(c.arg2); num.has_value()) { // the plain imm constant case
            if (c.options.size() > 0 && c.options.back().plain_jump_offset) { // the plain jump offset case
                imm = num.value();
            } else {
                // calculate the offset assuming that imm is an absolute address
                imm = num.value() - (c.machine_code.size() - bytes);
            }
        } else {
            imm = string_to_label(c.arg2, c);
            c.label_locs.push_back(label_loc {.loc = c.machine_code.size() - bytes, .id = imm, .i_bytes = bytes, .is_dest = false, .format = CB});
        }
        rs1 = decode_register(c.arg1).encoding & 0b111;

        DBG(std::cout << "Encoding CB-type instruction with name " << c.inst << std::endl;)
        if (id == CSRLI || id == CSRAI || id == CANDI) { // shamt[5], shamt[4:0]
            verify_imm<6u>(imm);                         // Check for unsigned 6b
            inst |= (imm & 0b11111) << 2;                // Add shamt[4:0]
            inst |= ((imm >> 5) & 0b1) << 12;            // Add shamt[5]
        } else {
            verify_imm<9>(imm);                // Check for signed 9b
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
        if (!ssargs.no_rs1) {
            rd = decode_register(c.arg1).encoding;
        }

        if (ssargs.custom_reg_val.has_value()) {
            rs2 = ssargs.custom_reg_val.value();
        } else {
            rs2 = decode_register(c.arg2).encoding;
        }

        DBG(std::cout << "Encoding CR-type instruction with name " << c.inst << std::endl;)
        inst |= rs2 << 2;    // Add rs2
        inst |= rd << 7;     // Add rd
        inst |= funct << 12; // Add funct4
    } else if (type == CI) {

        if (ssargs.custom_reg_val.has_value()) {
            rd = ssargs.custom_reg_val.value();
            if (ssargs.use_funct_for_imm) {
                imm = (funct & 0b111111);
            }
        } else {
            rd = decode_register(c.arg1).encoding;
            if (auto num = decode_imm<int32_t>(c.arg2, c); num.has_value()) {
                imm = num.value();
            } else {
                auto [offset, reg] = decode_offset_plus_reg(c.arg2, c); // discard reg
                imm = offset;
            }
        }

        DBG(std::cout << "Encoding CI-type instruction with name " << c.inst << std::endl;)
        if (id == CLWSP || id == CFLWSP) {                     // offset[4:2|7:6]
            verify_imm<8u>(imm);                               // Check for unsigned 8b
            inst |= ((imm >> 6) & 0b11) << 2;                  // Add offset[7:6]
            inst |= ((imm >> 2) & 0b1111) << 4;                // Add offset[4:2]
            inst |= ((imm >> 5) & 0b1) << 12;                  // Add offset[5]
        } else if (id == CLDSP || id == CFLDSP) {              // offset[4:3|8:6]
            verify_imm<9u>(imm);                               // Check for unsigned 9b
            inst |= ((imm >> 6) & 0b111) << 2;                 // Add offset[8:6]
            inst |= ((imm >> 3) & 0b11) << 5;                  // Add offset[4:3]
            inst |= ((imm >> 5) & 0b1) << 12;                  // Add offset[5]
        } else if (id == CLI || id == CADDI || id == CADDIW) { // imm[5], imm[4:0]
            verify_imm<6>(imm);                                // Check for signed 6b
            inst |= (imm & 0b11111) << 2;                      // Add imm[4:0]
            inst |= ((imm >> 5) & 0b1) << 12;                  // Add imm[5]
        } else if (id == CSLLI) {                              // imm[5], imm[4:0]
            verify_imm<6u>(imm);                               // Check for unsigned 6b
            inst |= (imm & 0b11111) << 2;                      // Add imm[4:0]
            inst |= ((imm >> 5) & 0b1) << 12;                  // Add imm[5]
        } else if (id == CLUI) {                               // nzimm[17], imm[16:12]
            verify_imm<6>(imm);                                // Check for signed 6b
            inst |= ((imm >> 12) & 0b11111) << 2;              // Add imm[16:12]
            inst |= ((imm >> 17) & 0b1) << 12;                 // Add nzimm[17]
        } else if (id == CADDI16SP) {                          // nzimm[9], nzimm[4|6|8:7|5]
            verify_imm<10>(imm);                               // Check for signed 10b
            inst |= ((imm >> 5) & 0b1) << 2;                   // Add nzimm[5]
            inst |= ((imm >> 7) & 0b11) << 3;                  // Add nzimm[8:7]
            inst |= ((imm >> 6) & 0b1) << 5;                   // Add nzimm[6]
            inst |= ((imm >> 4) & 0b1) << 6;                   // Add nzimm[4]
            inst |= ((imm >> 9) & 0b1) << 12;                  // Add nzimm[9]
        } else {                                               // offset[4|9:6]
            inst |= ((imm >> 6) & 0b1111) << 2;                // Add offset[9:6]
            inst |= ((imm >> 4) & 0b1) << 6;                   // Add offset[4]
            inst |= ((imm >> 5) & 0b1) << 12;                  // Add offset[5]
        }
        inst |= rd << 7;     // Add rd
        inst |= funct << 13; // Add funct3
    } else if (type == CSS) {
        rs2 = decode_register(c.arg1).encoding;
        if (auto num = decode_imm<int32_t>(c.arg2, c); num.has_value()) {
            imm = num.value();
        } else {
            auto [offset, reg] = decode_offset_plus_reg(c.arg2, c); // discard reg
            imm = offset;
        }

        DBG(std::cout << "Encoding CSS-type instruction with name " << c.inst << std::endl;)
        inst |= rs2 << 2;                         // Add rs2
        if (id == CSWSP || id == CFSWSP) {        // offset[5:2|7:6]
            verify_imm<8u>(imm);                  // Check for unsigned 8b
            inst |= ((imm >> 6) & 0b11) << 7;     // Add offset[7:6]
            inst |= ((imm >> 2) & 0b1111) << 9;   // Add offset[5:2]
        } else if (id == CSDSP || id == CFSDSP) { // offset[5:3|8:6]
            verify_imm<9u>(imm);                  // Check for unsigned 9b
            inst |= ((imm >> 6) & 0b111) << 7;    // Add offset[8:6]
            inst |= ((imm >> 3) & 0b111) << 10;   // Add offset[5:3]
        } else {                                  // offset[5:4|9:6]
            inst |= ((imm >> 6) & 0b1111) << 7;   // Add offset[9:6]
            inst |= ((imm >> 4) & 0b11) << 11;    // Add offset[5:4]
        }
        inst |= funct << 13; // Add funct3
    } else if (type == CIW) {
        rd = decode_register(c.arg1).encoding & 0b111; // Only use the lower 3 bits
        if (auto num = decode_imm<int32_t>(c.arg2, c); num.has_value()) {
            imm = num.value();
        } else {
            throw UltraError(UltraErrorType::Compiler, "Invalid immediate " + c.arg2, c.line, c.column);
        }

        DBG(std::cout << "Encoding CIW-type instruction with name " << c.inst << std::endl;)
        inst |= rd << 2;                    // Add rd' (just 3 bits)
        inst |= ((imm >> 3) & 0b1) << 5;    // Add nzuimm[3]
        inst |= ((imm >> 2) & 0b1) << 6;    // Add nzuimm[2]
        inst |= ((imm >> 6) & 0b1111) << 7; // Add nzuimm[9:6]
        inst |= ((imm >> 4) & 0b11) << 11;  // Add nzuimm[5:4]
        inst |= funct << 13;                // Add funct3
    } else if (type == CA) {
        rd = decode_register(c.arg1).encoding & 0b111; // Only use the lower 3 bits
        rs2 = decode_register(c.arg2).encoding & 0b111;

        DBG(std::cout << "Encoding CA-type instruction with name " << c.inst << std::endl;)
        inst |= rs2 << 2;            // Add rs2' (just 3 bits)
        inst |= (funct & 0b11) << 5; // Add funct2
        inst |= rd << 7;             // Add rd' (just 3 bits)
        inst |= (funct >> 2) << 10;  // Add funct6
    } else if (type == VL || type == VS || type == VLR || type == VSR) {
        rd = decode_register(c.arg1).encoding;
        remove_extraneous_parentheses(c.arg2);
        rs1 = decode_register(c.arg2).encoding;

        DBG(std::cout << "Encoding VL or VS or VLR or VSR-type instruction with name " << c.inst << std::endl;)

        inst |= rd << 7;               // Add rd
        inst |= (funct & 0b111) << 12; // Add width
        inst |= rs1 << 15;             // Add rs1
        inst |= (funct >> 3) << 20;    // Add lumop, vm, mop, mew, nf

        if (fast_eq(c.arg3, "v0.t")) {
            inst &= ~(1 << 25); // Clear the 25th bit
        }
    } else if (type == VLS || type == VLX || type == VSS || type == VSX) {
        rd = decode_register(c.arg1).encoding;
        remove_extraneous_parentheses(c.arg2);
        rs1 = decode_register(c.arg2).encoding;
        rs2 = decode_register(c.arg3).encoding;

        DBG(std::cout << "Encoding VLS or VLX or VSS or VSX-type instruction with name " << c.inst << std::endl;)

        inst |= rd << 7;               // Add rd
        inst |= (funct & 0b111) << 12; // Add width
        inst |= rs1 << 15;             // Add rs1
        inst |= rs2 << 20;             // Add rs2
        inst |= (funct >> 3) << 25;    // Add vm, mop, mew, nf

        if (fast_eq(c.arg4, "v0.t")) {
            inst &= ~(1 << 25); // Clear the 25th bit
        }
    } else if (type == IVV || type == FVV || type == MVV || type == IVX || type == FVF || type == MVX) {
        rd = decode_register(c.arg1).encoding;

        if (id == VIDV || id == THVIDV) {
            rs2 = 0;
        } else {
            rs2 = decode_register(c.arg2).encoding;
        }

        if (ssargs.custom_reg_val.has_value()) {
            rs1 = ssargs.custom_reg_val.value();
        } else if (ssargs.get_imm_for_rs) {
            if (auto num = decode_imm<int32_t>(c.arg3, c); num.has_value()) {
                rs1 = num.value();
            } else {
                throw UltraError(UltraErrorType::Compiler, "Invalid immediate " + c.arg3, c.line, c.column);
            }
        } else {
            if (reqs == XTheadZvamo) {
                remove_extraneous_parentheses(c.arg3);
            }
            rs1 = decode_register(c.arg3).encoding;
        }

        if (ssargs.swap_rs1_rs2) {
            std::swap(rs1, rs2);
        }

        DBG(std::cout << "Encoding IVV or FVV or MVV or IVX or FVF or MVX-type instruction with name " << c.inst << std::endl;)

        inst |= rd << 7;               // Add rd
        inst |= (funct & 0b111) << 12; // Add width
        inst |= rs1 << 15;             // Add vs1
        inst |= rs2 << 20;             // Add vs2
        inst |= (funct >> 3) << 25;    // Add vm, funct6

        if (ssargs.custom_reg_val.has_value()) {
            if (fast_eq(c.arg3, "v0.t")) {
                inst &= ~(1 << 25); // Clear the 25th bit
            }
        } else {
            if (fast_eq(c.arg4, "v0.t")) {
                inst &= ~(1 << 25);
            }
        }
    } else if (type == IVI) {
        rd = decode_register(c.arg1).encoding;

        if (ssargs.custom_reg_val.has_value()) {
            rs2 = ssargs.custom_reg_val.value();

            if (auto num = decode_imm<int32_t>(c.arg2, c); num.has_value()) {
                imm = num.value();
                verify_imm<5>(imm); // Check for signed 5b
            } else {
                throw UltraError(UltraErrorType::Compiler, "Invalid immediate " + c.arg2, c.line, c.column);
            }
        } else {
            rs2 = decode_register(c.arg2).encoding;

            if (auto num = decode_imm<int32_t>(c.arg3, c); num.has_value()) {
                imm = num.value();

                if (id == VSLLVI || id == VSRLVI || id == VSRAVI || id == VNSRLWI || id == VNSRAWI || id == VSSRLVI || id == VSSRAVI || id == VNCLIPUWI || id == VNCLIPWI || id == VSLIDEUPVI
                    || id == VSLIDEDOWNVI || id == VRGATHERVI || id == VWSLLVI) {
                    verify_imm<5u>(imm); // Check for unsigned 5b
                } else if (id == VRORVI) {
                    verify_imm<6u>(imm); // Check for unsigned 6b
                } else {
                    verify_imm<5>(imm); // Check for signed 5b
                }

                if (id == VRORVI) {
                    inst |= ((imm >> 5) & 0b1) << 26; // Add i5
                }
            } else {
                throw UltraError(UltraErrorType::Compiler, "Invalid immediate " + c.arg3, c.line, c.column);
            }
        }

        DBG(std::cout << "Encoding IVI-type instruction with name " << c.inst << std::endl;)

        inst |= rd << 7;               // Add rd
        inst |= (funct & 0b111) << 12; // Add width
        inst |= (imm & 0b11111) << 15; // Add imm[4:0]
        inst |= rs2 << 20;             // Add vs2
        inst |= (funct >> 3) << 25;    // Add vm, funct6

        if (fast_eq(c.arg4, "v0.t")) {
            inst &= ~(1 << 25); // Clear the 25th bit
        }
    } else if (type == CLB) {
        rd = decode_register(c.arg1).encoding & 0b111; // Only use the lower 3 bits
        if (auto num = decode_imm<int32_t>(c.arg3, c); num.has_value()) {
            imm = num.value() & 0b11;
            rs1 = decode_register(c.arg2).encoding & 0b111;
        } else {
            auto [offset, reg] = decode_offset_plus_reg(c.arg2, c);
            imm = offset & 0b11;
            rs1 = decode_register(reg).encoding & 0b111;
        }

        DBG(std::cout << "Encoding CLB-type instruction with name " << c.inst << std::endl;)

        inst |= rd << 2;          // Add rd' (just 3 bits)
        inst |= (imm >> 1) << 5;  // Add uimm[1]
        inst |= (imm & 0b1) << 6; // Add uimm[0]
        inst |= rs1 << 7;         // Add rs1' (just 3 bits)
        inst |= funct << 10;      // Add funct6
    } else if (type == CSBfmt) {
        rs2 = decode_register(c.arg1).encoding & 0b111;
        if (auto num = decode_imm<int32_t>(c.arg3, c); num.has_value()) {
            imm = num.value() & 0b11;
            rs1 = decode_register(c.arg2).encoding & 0b111;
        } else {
            auto [offset, reg] = decode_offset_plus_reg(c.arg2, c);
            imm = offset & 0b11;
            rs1 = decode_register(reg).encoding & 0b111;
        }

        DBG(std::cout << "Encoding CSB-type instruction with name " << c.inst << std::endl;)

        inst |= rs2 << 2;         // Add rs2' (just 3 bits)
        inst |= (imm >> 1) << 5;  // Add uimm[1]
        inst |= (imm & 0b1) << 6; // Add uimm[0]
        inst |= rs1 << 7;         // Add rs1' (just 3 bits)
        inst |= funct << 10;      // Add funct6
    } else if (type == CLHfmt) {
        rd = decode_register(c.arg1).encoding & 0b111; // Only use the lower 3 bits
        if (auto num = decode_imm<int32_t>(c.arg3, c); num.has_value()) {
            imm = num.value() & 0b11;
            rs1 = decode_register(c.arg2).encoding & 0b111;
        } else {
            auto [offset, reg] = decode_offset_plus_reg(c.arg2, c);
            imm = offset & 0b11;
            rs1 = decode_register(reg).encoding & 0b111;
        }

        DBG(std::cout << "Encoding CLH-type instruction with name " << c.inst << std::endl;)

        inst |= rd << 2;            // Add rd' (just 3 bits)
        inst |= (imm >> 1) << 5;    // Add uimm[1]
        inst |= (funct & 0b1) << 6; // Add funct1
        inst |= rs1 << 7;           // Add rs1' (just 3 bits)
        inst |= (funct >> 1) << 10; // Add funct6
    } else if (type == CSHfmt) {
        rs2 = decode_register(c.arg1).encoding & 0b111;
        if (auto num = decode_imm<int32_t>(c.arg3, c); num.has_value()) {
            imm = (num.value() >> 1) & 0b1;
            rs1 = decode_register(c.arg2).encoding & 0b111;
        } else {
            auto [offset, reg] = decode_offset_plus_reg(c.arg2, c);
            imm = (offset >> 1) & 0b1;
            rs1 = decode_register(reg).encoding & 0b111;
        }

        DBG(std::cout << "Encoding CSH-type instruction with name " << c.inst << std::endl;)

        inst |= rs2 << 2;           // Add rs2' (just 3 bits)
        inst |= imm << 5;           // Add uimm[0]
        inst |= (funct & 0b1) << 6; // Add funct1
        inst |= rs1 << 7;           // Add rs1' (just 3 bits)
        inst |= (funct >> 1) << 10; // Add funct6
    } else if (type == CU) {
        rd = decode_register(c.arg1).encoding & 0b111; // Only use the lower 3 bits

        DBG(std::cout << "Encoding CU-type instruction with name " << c.inst << std::endl;)

        inst |= (funct & 0b11111) << 2; // Add funct5
        inst |= rd << 7;                // Add rd' (just 3 bits)
        inst |= (funct >> 5) << 10;     // Add funct6
    } else if (type == CMMV) {
        rs1 = decode_register(c.arg1).encoding & 0b111;
        rs2 = decode_register(c.arg2).encoding & 0b111;

        DBG(std::cout << "Encoding CMMV-type instruction with name " << c.inst << std::endl;)

        inst |= rs2 << 2;            // Add rs2' (just 3 bits)
        inst |= (funct & 0b11) << 5; // Add funct2
        inst |= rs1 << 7;            // Add rs1' (just 3 bits)
        inst |= (funct >> 2) << 10;  // Add funct6
    } else if (type == CMJTfmt) {
        if (auto num = decode_imm<int32_t>(c.arg1, c); num.has_value()) {
            imm = num.value();
        } else {
            throw UltraError(UltraErrorType::Compiler, "Invalid index " + c.arg1, c.line, c.column);
        }

        DBG(std::cout << "Encoding CMJT-type instruction with name " << c.inst << std::endl;)

        inst |= (imm & 0b11111111) << 2; // Add imm[7:0]
        inst |= funct << 10;             // Add funct6

    } else if (type == CMPP) { // This one's weird. These instructions look like "inst {ra, s0-s11}, offset", where the part in brackets is a register list. To Ultrassembler, this looks like "inst"
                               // "{ra" "s0-s11}" "offset" so we need to just look at the components instead. Here's all the potential cases for the range:
                               /*
                           case 4: {reg_list="ra"; xreg_list="x1";}
                           case 5: {reg_list="ra, s0"; xreg_list="x1, x8";}
                           case 6: {reg_list="ra, s0-s1"; xreg_list="x1, x8-x9";}
                           case 7: {reg_list="ra, s0-s2"; xreg_list="x1, x8-x9, x18";}
                           case 8: {reg_list="ra, s0-s3"; xreg_list="x1, x8-x9, x18-x19";}
                           case 9: {reg_list="ra, s0-s4"; xreg_list="x1, x8-x9, x18-x20";}
                           case 10: {reg_list="ra, s0-s5"; xreg_list="x1, x8-x9, x18-x21";}
                           case 11: {reg_list="ra, s0-s6"; xreg_list="x1, x8-x9, x18-x22";}
                           case 12: {reg_list="ra, s0-s7"; xreg_list="x1, x8-x9, x18-x23";}
                           case 13: {reg_list="ra, s0-s8"; xreg_list="x1, x8-x9, x18-x24";}
                           case 14: {reg_list="ra, s0-s9"; xreg_list="x1, x8-x9, x18-x25";}
                           case 15: {reg_list="ra, s0-s11"; xreg_list="x1, x8-x9, x18-x27";}
                               */
        DBG(std::cout << "Encoding CMPP-type instruction with name " << c.inst << std::endl;)
        uint8_t rlist = 0;

        if (c.arg1.front() == '{') {
            c.arg1.erase(0, 1);
        }

        if (c.arg1.back() == '}') {
            c.arg1.pop_back();
        }

        if (c.arg2.back() == '}') {
            c.arg2.pop_back();
        }

        if (c.arg3.back() == '}') {
            c.arg3.pop_back();
        }

        if (fast_eq(c.arg1, "ra")) {
            if (c.arg3.empty()) {
                rlist = 4;
            } else if (fast_eq(c.arg2, "s0")) {
                rlist = 5;
            } else if (fast_eq(c.arg2, "s0-s1")) {
                rlist = 6;
            } else if (fast_eq(c.arg2, "s0-s2")) {
                rlist = 7;
            } else if (fast_eq(c.arg2, "s0-s3")) {
                rlist = 8;
            } else if (fast_eq(c.arg2, "s0-s4")) {
                rlist = 9;
            } else if (fast_eq(c.arg2, "s0-s5")) {
                rlist = 10;
            } else if (fast_eq(c.arg2, "s0-s6")) {
                rlist = 11;
            } else if (fast_eq(c.arg2, "s0-s7")) {
                rlist = 12;
            } else if (fast_eq(c.arg2, "s0-s8")) {
                rlist = 13;
            } else if (fast_eq(c.arg2, "s0-s9")) {
                rlist = 14;
            } else if (fast_eq(c.arg2, "s0-s11")) {
                rlist = 15;
            }
        } else if (fast_eq(c.arg1, "x1")) {
            if (c.arg3.empty()) {
                rlist = 4;
            } else if (fast_eq(c.arg2, "x8")) {
                rlist = 5;
            } else if (fast_eq(c.arg2, "x8-x9")) {
                if (c.arg4.empty()) {
                    rlist = 6;
                } else if (fast_eq(c.arg3, "x18")) {
                    rlist = 7;
                } else if (fast_eq(c.arg3, "x18-x19")) {
                    rlist = 8;
                } else if (fast_eq(c.arg3, "x18-x20")) {
                    rlist = 9;
                } else if (fast_eq(c.arg3, "x18-x21")) {
                    rlist = 10;
                } else if (fast_eq(c.arg3, "x18-x22")) {
                    rlist = 11;
                } else if (fast_eq(c.arg3, "x18-x23")) {
                    rlist = 12;
                } else if (fast_eq(c.arg3, "x18-x24")) {
                    rlist = 13;
                } else if (fast_eq(c.arg3, "x18-x25")) {
                    rlist = 14;
                } else if (fast_eq(c.arg3, "x18-x27")) {
                    rlist = 15;
                }
            }
        }

        // imm = stack_adj
        if (c.arg3.empty()) {
            if (auto num = decode_imm<int32_t>(c.arg2, c); num.has_value()) {
                imm = num.value();
            } else {
                throw UltraError(UltraErrorType::Compiler, "Invalid immediate " + c.arg2, c.line, c.column);
            }
        } else if (c.arg4.empty()) {
            if (auto num = decode_imm<int32_t>(c.arg3, c); num.has_value()) {
                imm = num.value();
            } else {
                throw UltraError(UltraErrorType::Compiler, "Invalid immediate " + c.arg3, c.line, c.column);
            }
        } else {
            if (auto num = decode_imm<int32_t>(c.arg4, c); num.has_value()) {
                imm = num.value();
            } else {
                throw UltraError(UltraErrorType::Compiler, "Invalid immediate " + c.arg4, c.line, c.column);
            }
        }

        if (id == CMPUSH) {
            if (imm > 0) {
                throw UltraError(UltraErrorType::Compiler, "Invalid stack adjustment " + c.arg3, c.line, c.column);
            } else {
                imm = -imm;
            }
        } else if (id == CMPOP || id == CMPOPRET || id == CMPOPRETZ) {
            if (imm < 0) {
                throw UltraError(UltraErrorType::Compiler, "Invalid stack adjustment " + c.arg3, c.line, c.column);
            }
        }

        uint8_t spimm = 0;

        using enum RVInstructionSet;

        if (std::find(c.supported_sets.begin(), c.supported_sets.end(), RV32E) != c.supported_sets.end()) {
            // stack_adj = stack_adj_base + spimm[5:4] * 16;
            // spimm[5:4] = (stack_adj - stack_adj_base) / 16
            // From RISC-V docs:
            // stack_adj_base = 16;
            // stack_adj = [16|32|48|64]
            if (imm != 16 && imm != 32 && imm != 48 && imm != 64) {
                throw UltraError(UltraErrorType::Compiler, "Invalid stack adjustment " + c.arg3, c.line, c.column);
            }
            spimm = (imm - 16) / 16;
        } else if (std::find(c.supported_sets.begin(), c.supported_sets.end(), RV32I) != c.supported_sets.end()) {
            // stack_adj = stack_adj_base + spimm[5:4] * 16;
            // spimm[5:4] = (stack_adj - stack_adj_base) / 16
            // From RISC-V docs:
            /* switch (rlist) {
                case 4.. 7: stack_adj_base = 16;
                case 8..11: stack_adj_base = 32;
                case 12..14: stack_adj_base = 48;
                case 15: stack_adj_base = 64;
                }
                Valid values:
                switch (rlist) {
                case 4.. 7: stack_adj = [16|32|48| 64];
                case 8..11: stack_adj = [32|48|64| 80];
                case 12..14: stack_adj = [48|64|80| 96];
                case 15: stack_adj = [64|80|96|112];
                } */
            if (rlist >= 4 && rlist <= 7) {
                if (imm != 16 && imm != 32 && imm != 48 && imm != 64) {
                    throw UltraError(UltraErrorType::Compiler, "Invalid stack adjustment " + c.arg3, c.line, c.column);
                }
                spimm = (imm - 16) / 16;
            } else if (rlist >= 8 && rlist <= 11) {
                if (imm != 32 && imm != 48 && imm != 64 && imm != 80) {
                    throw UltraError(UltraErrorType::Compiler, "Invalid stack adjustment " + c.arg3, c.line, c.column);
                }
                spimm = (imm - 32) / 16;
            } else if (rlist >= 12 && rlist <= 14) {
                if (imm != 48 && imm != 64 && imm != 80 && imm != 96) {
                    throw UltraError(UltraErrorType::Compiler, "Invalid stack adjustment " + c.arg3, c.line, c.column);
                }
                spimm = (imm - 48) / 16;
            } else if (rlist == 15) {
                if (imm != 64 && imm != 80 && imm != 96 && imm != 112) {
                    throw UltraError(UltraErrorType::Compiler, "Invalid stack adjustment " + c.arg3, c.line, c.column);
                }
                spimm = (imm - 64) / 16;
            } else {
                throw UltraError(UltraErrorType::Compiler, "Invalid register list " + c.arg1, c.line, c.column);
            }
        } else { // RV64I is the default case
            // stack_adj = stack_adj_base + spimm[5:4] * 16;
            // spimm[5:4] = (stack_adj - stack_adj_base) / 16
            // From RISC-V docs:
            /* switch (rlist) {
                case 4.. 5: stack_adj_base = 16;
                case 6.. 7: stack_adj_base = 32;
                case 8.. 9: stack_adj_base = 48;
                case 10..11: stack_adj_base = 64;
                case 12..13: stack_adj_base = 80;
                case 14: stack_adj_base = 96;
                case 15: stack_adj_base = 112;
                }
                Valid values:
                switch (rlist) {
                case 4.. 5: stack_adj = [ 16| 32| 48| 64];
                case 6.. 7: stack_adj = [ 32| 48| 64| 80];
                case 8.. 9: stack_adj = [ 48| 64| 80| 96];
                case 10..11: stack_adj = [ 64| 80| 96|112];
                case 12..13: stack_adj = [ 80| 96|112|128];
                case 14: stack_adj = [ 96|112|128|144];
                case 15: stack_adj = [112|128|144|160];
                }*/
            if (rlist >= 4 && rlist <= 5) {
                if (imm != 16 && imm != 32 && imm != 48 && imm != 64) {
                    throw UltraError(UltraErrorType::Compiler, "Invalid stack adjustment " + c.arg3, c.line, c.column);
                }
                spimm = (imm - 16) / 16;
            } else if (rlist >= 6 && rlist <= 7) {
                if (imm != 32 && imm != 48 && imm != 64 && imm != 80) {
                    throw UltraError(UltraErrorType::Compiler, "Invalid stack adjustment " + c.arg3, c.line, c.column);
                }
                spimm = (imm - 32) / 16;
            } else if (rlist >= 8 && rlist <= 9) {
                if (imm != 48 && imm != 64 && imm != 80 && imm != 96) {
                    throw UltraError(UltraErrorType::Compiler, "Invalid stack adjustment " + c.arg3, c.line, c.column);
                }
                spimm = (imm - 48) / 16;
            } else if (rlist >= 10 && rlist <= 11) {
                if (imm != 64 && imm != 80 && imm != 96 && imm != 112) {
                    throw UltraError(UltraErrorType::Compiler, "Invalid stack adjustment " + c.arg3, c.line, c.column);
                }
                spimm = (imm - 64) / 16;
            } else if (rlist >= 12 && rlist <= 13) {
                if (imm != 80 && imm != 96 && imm != 112 && imm != 128) {
                    throw UltraError(UltraErrorType::Compiler, "Invalid stack adjustment " + c.arg3, c.line, c.column);
                }
                spimm = (imm - 80) / 16;
            } else if (rlist == 14) {
                if (imm != 96 && imm != 112 && imm != 128 && imm != 144) {
                    throw UltraError(UltraErrorType::Compiler, "Invalid stack adjustment " + c.arg3, c.line, c.column);
                }
                spimm = (imm - 96) / 16;
            } else if (rlist == 15) {
                if (imm != 112 && imm != 128 && imm != 144 && imm != 160) {
                    throw UltraError(UltraErrorType::Compiler, "Invalid stack adjustment " + c.arg3, c.line, c.column);
                }
                spimm = (imm - 112) / 16;
            } else {
                throw UltraError(UltraErrorType::Compiler, "Invalid register list " + c.arg1, c.line, c.column);
            }
        }

        DBG(std::cout << "spimm: " << (int)spimm << std::endl;)

        inst |= (spimm & 0b11) << 2;   // Add spimm[5:4]
        inst |= (rlist & 0b1111) << 4; // Add rlist[3:0]
        inst |= funct << 8;            // Add funct8
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

                    // std::cout << "Loc for i: " << c.label_locs.at(i).loc << ", loc for j: " << c.label_locs.at(j).loc << std::endl;

                    // std::cout << "Offset for label " << c.label_locs.at(i).id << ": " << offset << std::endl;

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

ultravector<RVInstructionSet> decode_sets(const ultrastring& str) {
    // Example: For an input str that looks like "rv64ifma", this function will return a vector containing RV64I, RV64F, RV64M, and RV64A
    ultravector<RVInstructionSet> sets;
    ultrastring search_str;
    for (const char& c : str) {
        search_str.push_back(c);
        // for (const auto& name : instruction_set
    }
    return sets;
}

uint8_t decode_opcode(const ultrastring& str) {
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
        throw UltraError(UltraErrorType::Compiler, "Invalid opcode " + str);
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
                     {"zcb", Zcb},     {"zbb", Zbb},     {"zcmp", Zcmp}, {"c", C},     {"zcd", Zcd},           {"zcf", Zcf},     {"zcmt", Zcmt},   {"b", B},           {"v", V}}
            };

            auto get_arches_from_string = [&](const std::string_view& str) {
                ultravector<RVInstructionSet> arches;
                ultrastring temp;
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
        } else if (fast_eq(c.arg1, "simpleoffset")) {
            DBG(std::cout << "Setting simpleoffset option to true" << std::endl;)
            c.options.back().plain_jump_offset = true;
        } else if (fast_eq(c.arg1, "nosimpleoffset")) {
            DBG(std::cout << "Setting simpleoffset option to false" << std::endl;)
            c.options.back().plain_jump_offset = false;
        }
    } else if (fast_eq(c.inst, ".insn")) {
        DBG(std::cout << "Instruction directive" << std::endl;)
        // .insn <value> = make an instruction with content <value>
        // .insn <insn_length>, <value> = make an instruction with length <insn_length> and content <value> (verify length)
        // .insn <type> <fields> = make an instruction with type <type> and fields <fields>

        uint32_t custom_inst = 0;
        uint8_t inst_len = 0;

        using enum RVInstructionFormat;
        const std::array<std::pair<std::string_view, RVInstructionFormat>, 38> type_names = {
                {{"r", R},     {"i", I},        {"s", S},        {"b", Branch},   {"u", U},     {"j", J},       {"r4", R4},        {"cr", CR},    {"ci", CI},   {"css", CSS},
                 {"ciw", CIW}, {"cl", CL},      {"cs", CS},      {"ca", CA},      {"cb", CB},   {"cj", CJ},     {"vl", VL},        {"vls", VLS},  {"vlx", VLX}, {"vs", VS},
                 {"vss", VSS}, {"vsx", VSX},    {"vlr", VLR},    {"ivv", IVV},    {"fvv", FVV}, {"mvv", MVV},   {"ivi", IVI},      {"ivx", IVX},  {"fvf", FVF}, {"mvx", MVX},
                 {"clb", CLB}, {"csb", CSBfmt}, {"clh", CLHfmt}, {"csh", CSHfmt}, {"cu", CU},   {"cmmv", CMMV}, {"cmjt", CMJTfmt}, {"cmpp", CMPP}}
        };
        if (!c.arg1.empty() && c.arg2.empty()) {
            if (auto num = decode_imm<uint32_t>(c.arg1, c); num.has_value()) {
                custom_inst = num.value();
                inst_len = (custom_inst & 0xffff0000) ? 4 : 2;
            }
        } else if (!c.arg1.empty() && !c.arg2.empty()) {
            RVInstructionFormat this_type;
            bool is_type = false;
            for (const auto& [name, type] : type_names) {
                if (fast_eq(c.arg1, name)) {
                    is_type = true;
                    this_type = type;
                    DBG(std::cout << "Found type: " << c.inst << std::endl;)
                    break;
                }
            }
            if (is_type) {
                DBG(std::cout << "Making a custom type instruction" << std::endl;)
                auto get_extra_args = [&]() -> ultravector<ultrastring> {
                    // Parse all the extra args from c.arg_extra, which are separated by commas and whitespace
                    ultravector<ultrastring> args;
                    ultrastring temp;
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

                if (auto num = decode_imm<uint8_t>(c.arg2, c); num.has_value()) {
                    custom_inst = num.value();
                } else {
                    custom_inst = decode_opcode(c.arg2);
                }
                if (this_type == R && get_extra_args().size() == 1) {
                    uint8_t func3 = decode_imm<uint8_t>(c.arg3, c).value();
                    uint8_t func7 = decode_imm<uint8_t>(c.arg4, c).value();
                    uint8_t rd = decode_register(c.arg5).encoding;
                    uint8_t rs1 = decode_register(c.arg6).encoding;
                    uint8_t rs2 = decode_register(get_extra_args().at(0)).encoding;

                    custom_inst = custom_inst | (rd << 7) | (func3 << 12) | (rs1 << 15) | (rs2 << 20) | (func7 << 25);
                    inst_len = 4;
                } else if (this_type == R && get_extra_args().size() == 2) { // R with 4 args
                    uint8_t func3 = decode_imm<uint8_t>(c.arg3, c).value();
                    uint8_t func2 = decode_imm<uint8_t>(c.arg4, c).value();
                    uint8_t rd = decode_register(c.arg5).encoding;
                    uint8_t rs1 = decode_register(c.arg6).encoding;
                    uint8_t rs2 = decode_register(get_extra_args().at(0)).encoding;
                    uint8_t rs3 = decode_register(get_extra_args().at(1)).encoding;

                    custom_inst = custom_inst | (rd << 7) | (func3 << 12) | (rs1 << 15) | (rs2 << 20) | (func2 << 25) | (rs3 << 27);
                    inst_len = 4;
                } else if (this_type == R4) {
                    uint8_t func3 = decode_imm<uint8_t>(c.arg3, c).value();
                    uint8_t func2 = decode_imm<uint8_t>(c.arg4, c).value();
                    uint8_t rd = decode_register(c.arg5).encoding;
                    uint8_t rs1 = decode_register(c.arg6).encoding;
                    uint8_t rs2 = decode_register(get_extra_args().at(0)).encoding;
                    uint8_t rs3 = decode_register(get_extra_args().at(1)).encoding;

                    custom_inst = custom_inst | (rd << 7) | (func3 << 12) | (rs1 << 15) | (rs2 << 20) | (func2 << 25) | (rs3 << 27);
                    inst_len = 4;
                } else if (this_type == I && !c.arg6.empty()) { // I type: .insn i opcode7, func3, rd, rs1, simm12
                    uint8_t func3 = decode_imm<uint8_t>(c.arg3, c).value();
                    uint8_t rd = decode_register(c.arg4).encoding;
                    uint8_t rs1 = decode_register(c.arg5).encoding;
                    int32_t simm12 = decode_imm<int32_t>(c.arg6, c).value();

                    custom_inst = custom_inst | (rd << 7) | (func3 << 12) | (rs1 << 15) | ((simm12 & 0xFFF) << 20);
                    inst_len = 4;
                } else if (this_type == I && c.arg6.empty()) { // I type: .insn i opcode7, func3, rd, simm12(rs1)
                    uint8_t func3 = decode_imm<uint8_t>(c.arg3, c).value();
                    uint8_t rd = decode_register(c.arg4).encoding;
                    auto [simm12, temp] = decode_offset_plus_reg(c.arg5, c);
                    uint8_t rs1 = decode_register(temp).encoding;

                    custom_inst = custom_inst | (rd << 7) | (func3 << 12) | (rs1 << 15) | ((simm12 & 0xFFF) << 20);
                    inst_len = 4;
                } else if (this_type == S) { // S type: .insn s opcode7, func3, rs2, simm12(rs1)
                    uint8_t func3 = decode_imm<uint8_t>(c.arg3, c).value();
                    uint8_t rs2 = decode_register(c.arg4).encoding;
                    auto [simm12, temp] = decode_offset_plus_reg(c.arg5, c);
                    uint8_t rs1 = decode_register(temp).encoding;

                    custom_inst = custom_inst | ((simm12 & 0b11111) << 7) | (func3 << 12) | (rs1 << 15) | (rs2 << 20) | ((simm12 >> 5) << 25);
                    inst_len = 4;
                } else if (this_type == Branch) { // B type: .insn s opcode7, func3, rs1, rs2, symbol
                    uint8_t func3 = decode_imm<uint8_t>(c.arg3, c).value();
                    uint8_t rs1 = decode_register(c.arg4).encoding;
                    uint8_t rs2 = decode_register(c.arg5).encoding;
                    ultrastring symbol = c.arg6;

                    if (auto num = to_num<int32_t>(symbol); num.has_value()) {
                        custom_inst = custom_inst | ((num.value() & 0b1) << 7) | (((num.value() >> 1) & 0b1111) << 8) | (func3 << 12) | (rs1 << 15) | (rs2 << 20)
                                      | (((num.value() >> 5) & 0b111111) << 25) | ((num.value() >> 11) & 0b1) << 31;
                    } else {
                        c.label_locs.push_back(label_loc {.loc = c.machine_code.size(), .id = string_to_label(symbol, c), .is_dest = false, .format = Branch});
                        custom_inst = custom_inst | (func3 << 12) | (rs1 << 15) | (rs2 << 20);
                    }

                    inst_len = 4;
                } else if (this_type == U) { // U type: .insn u opcode7, rd, simm20
                    uint8_t rd = decode_register(c.arg3).encoding;
                    int32_t simm20 = decode_imm<int32_t>(c.arg4, c).value();

                    custom_inst = custom_inst | (rd << 7) | ((simm20 & 0xFFFFF) << 12);
                    inst_len = 4;
                } else if (this_type == J) { // J type: .insn j opcode7, rd, symbol
                    uint8_t rd = decode_register(c.arg3).encoding;
                    ultrastring symbol = c.arg4;

                    if (auto num = to_num<int32_t>(symbol); num.has_value()) {
                        custom_inst = custom_inst | (rd << 7) | (((num.value() >> 12) & 0b11111111) << 12) | (((num.value() >> 11) & 0b1) << 20) | (((num.value() >> 1) & 0b1111111111) << 21)
                                      | (((num.value() >> 20) & 0b1) << 31);
                    } else {
                        c.label_locs.push_back(label_loc {.loc = c.machine_code.size(), .id = string_to_label(symbol, c), .is_dest = false, .format = J});
                        custom_inst = custom_inst | (rd << 7);
                    }
                    inst_len = 4;
                } else if (this_type == CR) { // CR type: .insn cr opcode2, func4, rd, rs2
                    uint8_t func4 = decode_imm<uint8_t>(c.arg3, c).value();
                    uint8_t rd = decode_register(c.arg4).encoding;
                    uint8_t rs2 = decode_register(c.arg5).encoding;

                    custom_inst = custom_inst | (rs2 << 2) | (rd << 7) | (func4 << 12);
                    inst_len = 2;
                } else if (this_type == CI) { // CI type: .insn ci opcode2, func3, rd, simm6
                    uint8_t func3 = decode_imm<uint8_t>(c.arg3, c).value();
                    uint8_t rd = decode_register(c.arg4).encoding;
                    int32_t simm6 = decode_imm<int32_t>(c.arg5, c).value();

                    custom_inst = custom_inst | ((simm6 & 0b111111) << 2) | (rd << 7) | ((simm6 >> 5) << 12) | (func3 << 13);
                    inst_len = 2;
                } else if (this_type == CIW) { // CIW type: .insn ciw opcode2, func3, rd', uimm8
                    uint8_t func3 = decode_imm<uint8_t>(c.arg3, c).value();
                    uint8_t rd = decode_register(c.arg4).encoding & 0b111; // Only use the lower 3 bits
                    int32_t uimm8 = decode_imm<int32_t>(c.arg5, c).value();

                    custom_inst = custom_inst | (rd << 2) | ((uimm8 & 0xFF) << 5) | (func3 << 13);
                    inst_len = 2;
                } else if (this_type == CSS) { // CSS type: .insn css opcode2, func3, rd, uimm6
                    uint8_t func3 = decode_imm<uint8_t>(c.arg3, c).value();
                    uint8_t rd = decode_register(c.arg4).encoding;
                    int32_t uimm6 = decode_imm<int32_t>(c.arg5, c).value();

                    custom_inst = custom_inst | (rd << 2) | ((uimm6 & 0b111111) << 7) | (func3 << 13);
                    inst_len = 2;
                } else if (this_type == CL) { // CL type: .insn cl opcode2, func3, rd', uimm5(rs1')
                    uint8_t func3 = decode_imm<uint8_t>(c.arg3, c).value();
                    uint8_t rd = decode_register(c.arg4).encoding & 0b111; // Only use the lower 3 bits
                    auto [uimm5, rs1temp] = decode_offset_plus_reg(c.arg5, c);
                    uint8_t rs1 = decode_register(rs1temp).encoding;
                    rs1 = rs1 & 0b111; // Only use the lower 3 bits

                    custom_inst = custom_inst | (rd << 2) | ((uimm5 & 0b11) << 5) | (rs1 << 7) | (((uimm5 >> 2) & 0b111) << 10) | (func3 << 13);
                    inst_len = 2;
                } else if (this_type == CS) { // CS type: .insn cs opcode2, func3, rs2', uimm5(rs1')
                    uint8_t func3 = decode_imm<uint8_t>(c.arg3, c).value();
                    uint8_t rs2 = decode_register(c.arg4).encoding & 0b111; // Only use the lower 3 bits
                    auto [uimm5, rs1temp] = decode_offset_plus_reg(c.arg5, c);
                    uint8_t rs1 = decode_register(rs1temp).encoding;
                    rs1 = rs1 & 0b111; // Only use the lower 3 bits

                    custom_inst = custom_inst | (rs2 << 2) | ((uimm5 & 0b11) << 5) | (rs1 << 7) | (((uimm5 >> 2) & 0b111) << 10) | (func3 << 13);
                    inst_len = 2;
                } else if (this_type == CA) { // CA type: .insn ca opcode2, func6, func2, rd', rs2'
                    uint8_t func6 = decode_imm<uint8_t>(c.arg3, c).value();
                    uint8_t func2 = decode_imm<uint8_t>(c.arg4, c).value();
                    uint8_t rd = decode_register(c.arg5).encoding & 0b111;  // Only use the lower 3 bits
                    uint8_t rs2 = decode_register(c.arg6).encoding & 0b111; // Only use the lower 3 bits

                    custom_inst = custom_inst | (rs2 << 2) | (func2 << 5) | (rd << 7) | (func6 << 10);
                    inst_len = 2;
                } else if (this_type == CB) { // CB type: .insn cb opcode2, func3, rs1', symbol
                    uint8_t func3 = decode_imm<uint8_t>(c.arg3, c).value();
                    uint8_t rs1 = decode_register(c.arg4).encoding & 0b111; // Only use the lower 3 bits
                    ultrastring symbol = c.arg5;

                    if (auto num = to_num<int32_t>(symbol); num.has_value()) {
                        custom_inst = custom_inst | (((num.value() >> 5) & 0b1) << 2) | (((num.value() >> 1) & 0b11) << 3) | (((num.value() >> 6) & 0b11) << 5) | (rs1 << 7)
                                      | (((num.value() >> 3) & 0b11) << 10) | (((num.value() >> 8) & 0b1) << 12) | (func3 << 13);
                    } else {
                        c.label_locs.push_back(label_loc {.loc = c.machine_code.size(), .id = string_to_label(symbol, c), .is_dest = false, .format = CB});
                        custom_inst = custom_inst | (rs1 << 7) | (func3 << 13);
                    }
                    inst_len = 2;
                } else if (this_type == CJ) { // CJ type: .insn cj opcode2, func3, symbol
                    uint8_t func3 = decode_imm<uint8_t>(c.arg3, c).value();
                    ultrastring symbol = c.arg4;

                    if (auto num = to_num<int32_t>(symbol); num.has_value()) {
                        custom_inst = custom_inst | (((num.value() >> 5) & 0b1) << 2) | (((num.value() >> 1) & 0b111) << 3) | (((num.value() >> 7) & 0b1) << 6) | (((num.value() >> 6) & 0b1) << 7)
                                      | (((num.value() >> 10) & 0b1) << 8) | (((num.value() >> 8) & 0b11) << 9) | (((num.value() >> 4) & 0b1) << 11) | (((num.value() >> 11) & 0b1) << 12)
                                      | (func3 << 13);
                    } else {
                        c.label_locs.push_back(label_loc {.loc = c.machine_code.size(), .id = string_to_label(symbol, c), .is_dest = false, .format = CJ});
                        custom_inst = custom_inst | (func3 << 13);
                    }
                    inst_len = 2;
                }
            } else {
                if (auto num = decode_imm<uint32_t>(c.arg2, c); num.has_value()) {
                    custom_inst = num.value();
                    inst_len = (custom_inst & 0xffff0000) ? 4 : 2;
                }
                if (auto num = decode_imm<uint8_t>(c.arg1, c); num.has_value()) {
                    if (num.value() != inst_len) {
                        throw UltraError(UltraErrorType::Assembler, "Instruction length mismatch: expected " + to_ultrastring(num.value()) + ", got " + to_ultrastring(inst_len), c.line, c.column);
                    }
                }
            }
        }

        if (inst_len == 4) {
            c.machine_code.push_back(custom_inst & 0xFF);
            c.machine_code.push_back((custom_inst >> 8) & 0xFF);
            c.machine_code.push_back((custom_inst >> 16) & 0xFF);
            c.machine_code.push_back((custom_inst >> 24) & 0xFF);
        } else if (inst_len == 2) {
            c.machine_code.push_back(custom_inst & 0xFF);
            c.machine_code.push_back((custom_inst >> 8) & 0xFF);
        }
    } else if (fast_eq(c.inst, ".equ")) {
        DBG(std::cout << "Constant directive" << std::endl;)
        // .equ <name>, <value> = define a constant with name <name> and value <value>

        if (c.arg1.empty() || c.arg2.empty()) {
            throw UltraError(UltraErrorType::Assembler, "Invalid .equ directive", c.line, c.column);
        }

        c.constants.push_back({c.arg1, c.arg2});
    }
}

size_t parse_this_line(size_t i, const ultrastring& data, assembly_context& c) {
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

    volatile char preview;
    while (i < data.size() && not_at_end(ch()) && !is_whitespace(ch())) {
        c.inst.push_back(ch());
        i++;
        preview = ch();
    }

    DBG(std::cout << "Instruction candidate: " << c.inst << std::endl;)
    while (i < data.size() && not_at_end(ch()) && is_whitespace(ch())) {
        i++;
    }

    auto parse_arg = [&](ultrastring& arg) {
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
                            while (i < data.size() && not_at_end(ch())) {
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
    return i;
}

ultravector<uint8_t> assemble_code(const std::string_view& input, const ultravector<RVInstructionSet> supported_sets) {
    // auto then = std::chrono::high_resolution_clock::now();

    ultrastring data(input);

    assembly_context c;

    c.options.push_back(directive_options{});

    c.supported_sets = supported_sets;

    using enum RVInstructionSet;

    if (!c.supported_sets.empty()) {
        if (std::find(c.supported_sets.begin(), c.supported_sets.end(), RV32I) == c.supported_sets.end()
            && std::find(c.supported_sets.begin(), c.supported_sets.end(), RV64I) == c.supported_sets.end()) {
            throw UltraError(UltraErrorType::Assembler, "The set of supported RISC-V instruction sets must include at least RV32I or RV64I");
        }
    }

    c.inst.reserve(32); // This adds memory padding
    c.arg1.reserve(32);
    c.arg2.reserve(32);
    c.arg3.reserve(32);
    c.arg4.reserve(32);
    c.arg5.reserve(32);
    c.arg6.reserve(32);
    c.arg_extra.reserve(32);
    c.machine_code.reserve(128000);

    for (size_t i = 0; i < data.size();) {
        i = parse_this_line(i, data, c);
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
    DBG(for (const auto& c : c.machine_code) { printf("%02x ", c); })

    DBG(std::cout << "Let's compare this against the reference, gcc as" << std::endl;)

    std::ofstream out("temp.s");
    out << data;
    out.close();

    int res = std::system(
            "riscv64-linux-gnu-as "
            "-march=rv64gfdcqb_zknd_zbkb_zknh_zksh_zksed_zvkned_zvkb_zbkx_zvbb_zvbc_zvknhb_zvkg_zvksh_zvksed_zbc_zba_zicond_zacas_zcb_zcmp_zfbfmin_zvfbfmin_zvfbfwma_zabha_zicbom_"
            "zicboz_zicbop_xtheadvector_xtheadcmo_xtheadsync_xtheadba_xtheadbb_xtheadbs_xtheadcondmov_xtheadmemidx_xtheadmempair_xtheadfmemidx_xtheadmac_xtheadfmv_xtheadint_xtheadvdotv0.7.1_"
            "xtheadzvamo "
            "temp.s -o temp.o"
    );

    if (res != 0) {
        // DBG(std::cout << "error in command riscv64-linux-gnu-as temp.s -o temp.o" << std::endl;)
        // exit(1);
        throw UltraError(UltraErrorType::Assembler, "error in command riscv64-linux-gnu-as temp.s -o temp.o", 0, 0);
    }

    res = std::system("riscv64-linux-gnu-objcopy -O binary temp.o temp.bin");

    if (res != 0) {
        // DBG(std::cout << "error in command riscv64-linux-gnu-objcopy -O binary temp.o temp.bin" << std::endl;)
        // exit(1);
        throw UltraError(UltraErrorType::Assembler, "error in command riscv64-linux-gnu-objcopy -O binary temp.o temp.bin", 0, 0);
    }

    std::ifstream in("temp.bin", std::ios::binary);
    ultrastring result((std::istreambuf_iterator<char>(in)), std::istreambuf_iterator<char>());
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

} // namespace ultrassembler_internal