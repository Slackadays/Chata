// SPDX-License-Identifier: MPL-2.0
#include <array>
#include <cstdint>
#include <string_view>
#include "instructions.hpp"

using enum RVInstructionFormat;
using enum RVInstruction;
using enum RVInstructionSet;

const std::array<rvinstruction, 170> instructions = {
        {{"lui", U, LUI, 0b0110111, 0b000, RV32I},
         {"auipc", U, AUIPC, 0b0010111, 0b000, RV32I},
         {"jal", J, JAL, 0b1101111, 0b000, RV32I},
         {"jalr", I, JALR, 0b1100111, 0b000, RV32I},
         {"beq", B, BEQ, 0b1100011, 0b000, RV32I},
         {"bne", B, BNE, 0b1100011, 0b001, RV32I},
         {"blt", B, BLT, 0b1100011, 0b001, RV32I},
         {"bge", B, BGE, 0b1100011, 0b100, RV32I},
         {"bltu", B, BLTU, 0b1100011, 0b101, RV32I},
         {"bgeu", B, BGEU, 0b1100011, 0b110, RV32I},
         {"lb", I, LB, 0b0000011, 0b111, RV32I},
         {"lh", I, LH, 0b0000011, 0b000, RV32I},
         {"lw", I, LW, 0b0000011, 0b010, RV32I},
         {"lbu", I, LBU, 0b0000011, 0b100, RV32I},
         {"lhu", I, LHU, 0b0000011, 0b101, RV32I},
         {"sb", S, SB, 0b0100011, 0b000, RV32I},
         {"sh", S, SH, 0b0100011, 0b001, RV32I},
         {"sw", S, SW, 0b0100011, 0b010, RV32I},
         {"addi", I, ADDI, 0b0010011, 0b000, RV32I},
         {"slti", I, SLTI, 0b0010011, 0b010, RV32I},
         {"sltiu", I, SLTIU, 0b0010011, 0b011, RV32I},
         {"xori", I, XORI, 0b0010011, 0b100, RV32I},
         {"ori", I, ORI, 0b0010011, 0b110, RV32I},
         {"andi", I, ANDI, 0b0010011, 0b111, RV32I},
         {"slli", I, SLLI, 0b0010011, 0b0000000001, RV32I},
         {"srli", I, SRLI, 0b0010011, 0b0000000101, RV32I},
         {"srai", I, SRAI, 0b0010011, 0b0100000101, RV32I},
         {"add", R, ADD, 0b0110011, 0b0000000000, RV32I},
         {"sub", R, SUB, 0b0110011, 0b0100000000, RV32I},
         {"sll", R, SLL, 0b0110011, 0b0000000001, RV32I},
         {"slt", R, SLT, 0b0110011, 0b0000000010, RV32I},
         {"sltu", R, SLTU, 0b0110011, 0b0000000011, RV32I},
         {"xor", R, XOR, 0b0110011, 0b0000000100, RV32I},
         {"srl", R, SRL, 0b0110011, 0b0000000101, RV32I},
         {"sra", R, SRA, 0b0110011, 0b0100000101, RV32I},
         {"or", R, OR, 0b0110011, 0b0000000110, RV32I},
         {"and", R, AND, 0b0110011, 0b0000000111, RV32I},
         {"fence", I, FENCE, 0b0001111, 0b000, RV32I},
         {"fence.tso", I, FENCETSO, 0b0001111, 0b000, RV32I},
         {"pause", I, PAUSE, 0b0001111, 0b000, RV32I},
         {"ecall", I, ECALL, 0b1110011, 0b000, RV32I},
         {"ebreak", I, EBREAK, 0b1110011, 0b000, RV32I},
         {"lwu", I, LWU, 0b0000011, 0b110, RV64I},
         {"ld", I, LD, 0b0000011, 0b011, RV64I},
         {"sd", S, SD, 0b0100011, 0b011, RV64I},
         {"addiw", I, ADDIW, 0b0011011, 0b0000000001, RV64I},
         {"slliw", I, SLLIW, 0b0011011, 0b0000000001, RV64I},
         {"srliw", I, SRLIW, 0b0011011, 0b0000000101, RV64I},
         {"sraiw", I, SRAIW, 0b0011011, 0b0100000101, RV64I},
         {"addw", R, ADDW, 0b0111011, 0b0000000000, RV64I},
         {"subw", R, SUBW, 0b0111011, 0b0100000000, RV64I},
         {"sllw", R, SLLW, 0b0111011, 0b0000000001, RV64I},
         {"srlw", R, SRLW, 0b0111011, 0b0000000101, RV64I},
         {"sraw", R, SRAW, 0b0111011, 0b0100000101, RV64I},
         {"fmadd.s", R4, FMADDS, 0b1000011, 0b00, RV32F},
         {"fmsub.s", R4, FMSUBS, 0b1000011, 0b00, RV32F},
         {"fnmsub.s", R4, FNMSUBS, 0b1000011, 0b00, RV32F},
         {"fnmadd.s", R4, FNMADDS, 0b1000011, 0b00, RV32F},
         {"fadd.s", R, FADDS, 0b1010011, 0b0000000, RV32F},
         {"fsub.s", R, FSUBS, 0b1010011, 0b0000100, RV32F},
         {"fmul.s", R, FMULS, 0b1010011, 0b0001000, RV32F},
         {"fdiv.s", R, FDIVS, 0b1010011, 0b0001100, RV32F},
         {"fsqrt.s", R, FSQRTS, 0b1010011, 0b0101100, RV32F, {0b00000}},
         {"fsgnj.s", R, FSGNJS, 0b1010011, 0b0010000000, RV32F},
         {"fsgnjn.s", R, FSGNJNS, 0b1010011, 0b0010000001, RV32F},
         {"fsgnjx.s", R, FSGNJXS, 0b1010011, 0b0010000010, RV32F},
         {"fmin.s", R, FMINS, 0b1010011, 0b0010100000, RV32F},
         {"fmax.s", R, FMAXS, 0b1010011, 0b0010100001, RV32F},
         {"fcvt.w.s", R, FCVTWS, 0b1010011, 0b110000000000, RV32F, {0b00000}},
         {"fcvt.wu.s", R, FCVTWUS, 0b1010011, 0b110000000001, RV32F, {0b00001}},
         {"fmv.x.w", R, FMVXW, 0b1010011, 0b111000000000, RV32F, {0b00000}},
         {"feq.s", R, FEQS, 0b1010011, 0b1010000010, RV32F},
         {"flt.s", R, FLTS, 0b1010011, 0b1010000001, RV32F},
         {"fle.s", R, FLES, 0b1010011, 0b1010000000, RV32F},
         {"fclass.s", R, FCLASSS, 0b1010011, 0b111000000000, RV32F, {0b00000}},
         {"fcvt.s.w", R, FCVTSW, 0b1010011, 0b110100000000, RV32F, {0b00000}},
         {"fcvt.s.wu", R, FCVTSWU, 0b1010011, 0b110100000001, RV32F, {0b00001}},
         {"fmv.w.x", R, FMVWX, 0b1010011, 0b111100000000, RV32F, {0b00000}},
         {"flw", I, FLW, 0b0000111, 0b010, RV32F},
         {"fsw", S, FSW, 0b0100111, 0b010, RV32F},
         {"fcvt.l.s", R, FCVTLS, 0b1010011, 0b110000000010, RV64F, {0b00010}},
         {"fcvt.lu.s", R, FCVTLUS, 0b1010011, 0b110000000011, RV64F, {0b00011}},
         {"fcvt.s.l", R, FCVTSL, 0b1010011, 0b110100000010, RV64F, {0b00010}},
         {"fcvt.s.lu", R, FCVTSLU, 0b1010011, 0b110100000011, RV64F, {0b00011}},
         {"fadd.d", R, FADDD, 0b1000011, 0b0000001, RV32D},
         {"fmadd.d", R4, FMADDD, 0b1000011, 0b01, RV32D},
         {"fclass.d", R, FCLASSD, 0b1010011, 0b111000100000, RV32D, {0b00000}},
         {"fcvt.d.h", R, FCVTDH, 0b1010011, 0b010000100010, RV32D, {0b00010}},
         {"fcvt.d.s", R, FCVTDS, 0b1010011, 0b010000100000, RV32D, {0b00000}},
         {"fcvt.d.w", R, FCVTDW, 0b1010011, 0b110100100000, RV32D, {0b00000}},
         {"fcvt.d.wu", R, FCVTDWU, 0b1010011, 0b110100100001, RV32D, {0b00001}},
         {"fcvt.h.d", R, FCVTHD, 0b1010011, 0b010001000001, RV32D, {0b00001}},
         {"fcvt.s.d", R, FCVTSD, 0b1010011, 0b010000000001, RV32D, {0b00001}},
         {"fcvt.w.d", R, FCVTWD, 0b1010011, 0b110000100000, RV32D, {0b00000}},
         {"fcvt.wu.d", R, FCVTWUD, 0b1010011, 0b110000100001, RV32D, {0b00001}},
         {"fdiv.d", R, FDIVD, 0b1010011, 0b0001110, RV32D},
         {"feq.d", R, FEQD, 0b1010011, 0b1010001010, RV32D},
         {"fld", I, FLD, 0b0000111, 0b011, RV32D},
         {"fle.d", R, FLED, 0b1010011, 0b1010001000, RV32D},
         {"fmin.d", R, FMIND, 0b1010011, 0b0010101000, RV32D},
         {"fmsub.d", R4, FMSUBD, 0b1000011, 0b01, RV32D},
         {"fmul.d", R, FMULD, 0b1010011, 0b00010001, RV32D},
         {"fnmadd.d", R4, FNMADDD, 0b1000011, 0b01, RV32D},
         {"fnmsub.d", R4, FNMSUBD, 0b1000011, 0b01, RV32D},
         {"fsd", S, FSD, 0b0100111, 0b011, RV32D},
         {"fsgnj.d", R, FSGNJD, 0b1010011, 0b0010001000, RV32D},
         {"fsgnjn.d", R, FSGJND, 0b1010011, 0b0010001, RV32D},
         {"fsgnjx.d", R, FSGNJXD, 0b1010011, 0b0010001010, RV32D},
         {"fsqrt.d", R, FSQRTD, 0b1010011, 0b010110100000, RV32D, {0b00000}},
         {"fsub.d", R, FSUBD, 0b1010011, 0b0000101, RV32D},
         {"fcvt.l.d", R, FCVTLD, 0b1010011, 0b110000100010, RV64D, {0b00010}},
         {"fcvt.lu.d", R, FCVTLUD, 0b1010011, 0b110000100011, RV64D, {0b00011}},
         {"fmv.x.d", R, FMVXD, 0b1010011, 0b111000100000, RV64D, {0b00000}},
         {"fcvt.d.l", R, FCVTDL, 0b1010011, 0b110100100010, RV64D, {0b00010}},
         {"fcvt.d.lu", R, FCVTDLU, 0b1010011, 0b110100100011, RV64D, {0b00011}},
         {"fmv.d.x", R, FMVDX, 0b1010011, 0b111100100000, RV64D, {0b00000}},
         {"fence.i", I, FENCE, 0b0001111, 0b001, Zifencei},
         {"csrrw", I, CSRRW, 0b1110011, 0b001, Zicsr},
         {"csrrs", I, CSRRS, 0b1110011, 0b010, Zicsr},
         {"csrrc", I, CSRRC, 0b1110011, 0b011, Zicsr},
         {"csrrwi", I, CSRRWI, 0b1110011, 0b101, Zicsr},
         {"csrrsi", I, CSRRSI, 0b1110011, 0b110, Zicsr},
         {"csrrci", I, CSRRCI, 0b1110011, 0b111, Zicsr},
         {"wrs.nto", I, WRSNTO, 0b1110011, 0b100, Zawrs},
         {"wrs.sto", I, WRSSTO, 0b1110011, 0b101, Zawrs},
         {"c.lwsp", CIW, CLWSP, 0b10, 0b010, C},
         {"c.ldsp", CIW, CLDSP, 0b10, 0b011, C},
         {"c.lqsp", CIW, CLQSP, 0b10, 0b001, C},
         {"c.flwsp", CIW, CFLWSP, 0b10, 0b011, C},
         {"c.fldsp", CIW, CFLDSP, 0b10, 0b001, C},
         {"c.swsp", CIW, CSWSP, 0b10, 0b110, C},
         {"c.sdsp", CIW, CSDSP, 0b10, 0b111, C},
         {"c.sqsp", CIW, CSQSP, 0b10, 0b101, C},
         {"c.fswsp", CIW, CFSWSP, 0b10, 0b111, C},
         {"c.fsdsp", CIW, CFSDSP, 0b10, 0b101, C},
         {"c.lw", CI, CLW, 0b00, 0b010, C},
         {"c.ld", CI, CLD, 0b00, 0b011, C},
         {"c.lq", CI, CLQ, 0b00, 0b001, C},
         {"c.flw", CI, CFLW, 0b00, 0b011, C},
         {"c.fld", CI, CFLD, 0b00, 0b001, C},
         {"c.sw", CI, CSW, 0b00, 0b110, C},
         {"c.sd", CI, CSD, 0b00, 0b111, C},
         {"c.sq", CI, CSQ, 0b00, 0b101, C},
         {"c.fsw", CI, CFSW, 0b00, 0b111, C},
         {"c.fsd", CI, CFSD, 0b00, 0b101, C},
         {"c.j", CJ, CJump, 0b01, 0b101, C},
         {"c.jal", CJ, CJAL, 0b01, 0b001, C},
         {"c.jr", CR, CJR, 0b10, 0b100, C},
         {"c.jalr", CR, CJALR, 0b10, 0b100, C},
         {"c.beqz", CB, CBEQZ, 0b01, 0b110, C},
         {"c.bnez", CB, CBNEZ, 0b01, 0b111, C},
         {"c.li", CI, CLI, 0b01, 0b010, C},
         {"c.lui", CI, CLUI, 0b01, 0b011, C},
         {"c.addi", CI, CADDI, 0b01, 0b000, C},
         {"c.addiw", CI, CADDIW, 0b01, 0b001, C},
         {"c.addi16sp", CI, CADDI16SP, 0b01, 0b011, C},
         {"c.slli", CI, CSLLI, 0b10, 0b000, C},
         {"c.srli", CI, CSRLI, 0b01, 0b100, C},
         {"c.srai", CI, CSRAI, 0b01, 0b100, C},
         {"c.andi", CI, CANDI, 0b01, 0b100, C},
         {"c.mv", CR, CMV, 0b10, 0b100, C},
         {"c.add", CR, CADD, 0b10, 0b100, C},
         {"c.and", CR, CAND, 0b01, 0b100, C},
         {"c.or", CR, COR, 0b01, 0b100, C},
         {"c.xor", CR, CXOR, 0b01, 0b100, C},
         {"c.sub", CR, CSUB, 0b01, 0b100, C},
         {"c.addw", CR, CADDW, 0b01, 0b100, C},
         {"c.subw", CR, CSUBW, 0b01, 0b100, C},
         {"c.nop", CR, CNOP, 0b01, 0b000, C},
         {"c.ebreak", CR, CEBREAK, 0b10, 0b100, C}}};