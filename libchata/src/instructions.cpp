// SPDX-License-Identifier: MPL-2.0
#include "instructions.hpp"
#include <array>
#include <cstdint>
#include <initializer_list>
#include <string_view>

namespace libchata_internal {

using enum RVInstructionFormat;
using enum RVInstructionID;
using enum RVInstructionSet;
using std::nullopt;

const std::array<rvinstruction, 420> instructions = {
        {{"lui", U, LUI, 0b0110111, 0b000, RV32I, 4},
         {"auipc", U, AUIPC, 0b0010111, 0b000, RV32I, 4},
         {"jal", J, JAL, 0b1101111, 0b000, RV32I, 4},
         {"jalr", I, JALR, 0b1100111, 0b000, RV32I, 4},
         {"beq", B, BEQ, 0b1100011, 0b000, RV32I, 4},
         {"bne", B, BNE, 0b1100011, 0b001, RV32I, 4},
         {"blt", B, BLT, 0b1100011, 0b001, RV32I, 4},
         {"bge", B, BGE, 0b1100011, 0b100, RV32I, 4},
         {"bltu", B, BLTU, 0b1100011, 0b101, RV32I, 4},
         {"bgeu", B, BGEU, 0b1100011, 0b110, RV32I, 4},
         {"lb", I, LB, 0b0000011, 0b000, RV32I, 4},
         {"lh", I, LH, 0b0000011, 0b001, RV32I, 4},
         {"lw", I, LW, 0b0000011, 0b010, RV32I, 4},
         {"lbu", I, LBU, 0b0000011, 0b100, RV32I, 4},
         {"lhu", I, LHU, 0b0000011, 0b101, RV32I, 4},
         {"sb", S, SB, 0b0100011, 0b000, RV32I, 4},
         {"sh", S, SH, 0b0100011, 0b001, RV32I, 4},
         {"sw", S, SW, 0b0100011, 0b010, RV32I, 4},
         {"addi", I, ADDI, 0b0010011, 0b000, RV32I, 4},
         {"slti", I, SLTI, 0b0010011, 0b010, RV32I, 4},
         {"sltiu", I, SLTIU, 0b0010011, 0b011, RV32I, 4},
         {"xori", I, XORI, 0b0010011, 0b100, RV32I, 4},
         {"ori", I, ORI, 0b0010011, 0b110, RV32I, 4},
         {"andi", I, ANDI, 0b0010011, 0b111, RV32I, 4},
         {"slli", R, SLLI, 0b0010011, 0b0000000001, RV32I, 4, {nullopt, false, true}},
         {"srli", R, SRLI, 0b0010011, 0b0000000101, RV32I, 4, {nullopt, false, true}},
         {"srai", R, SRAI, 0b0010011, 0b0100000101, RV32I, 4, {nullopt, false, true}},
         {"add", R, ADD, 0b0110011, 0b0000000000, RV32I, 4},
         {"sub", R, SUB, 0b0110011, 0b0100000000, RV32I, 4},
         {"sll", R, SLL, 0b0110011, 0b0000000001, RV32I, 4},
         {"slt", R, SLT, 0b0110011, 0b0000000010, RV32I, 4},
         {"sltu", R, SLTU, 0b0110011, 0b0000000011, RV32I, 4},
         {"xor", R, XOR, 0b0110011, 0b0000000100, RV32I, 4},
         {"srl", R, SRL, 0b0110011, 0b0000000101, RV32I, 4},
         {"sra", R, SRA, 0b0110011, 0b0100000101, RV32I, 4},
         {"or", R, OR, 0b0110011, 0b0000000110, RV32I, 4},
         {"and", R, AND, 0b0110011, 0b0000000111, RV32I, 4},
         {"fence", I, FENCE, 0b0001111, 0b000, RV32I, 4, {nullopt, false, false, true}},
         {"fence.tso", I, FENCETSO, 0b0001111, 0b000, RV32I, 4, {nullopt, false, false, true}},
         {"pause", I, PAUSE, 0b0001111, 0b000, RV32I, 4, {nullopt, false, false, true}},
         {"ecall", I, ECALL, 0b1110011, 0b000, RV32I, 4, {nullopt, false, false, true}},
         {"ebreak", I, EBREAK, 0b1110011, 0b000, RV32I, 4, {nullopt, false, false, true}},
         {"lwu", I, LWU, 0b0000011, 0b110, RV64I, 4},
         {"ld", I, LD, 0b0000011, 0b011, RV64I, 4},
         {"sd", S, SD, 0b0100011, 0b011, RV64I, 4},
         {"addiw", I, ADDIW, 0b0011011, 0b0000000000, RV64I, 4},
         {"slliw", R, SLLIW, 0b0011011, 0b0000000001, RV64I, 4, {nullopt, false, true}},
         {"srliw", R, SRLIW, 0b0011011, 0b0000000101, RV64I, 4, {nullopt, false, true}},
         {"sraiw", R, SRAIW, 0b0011011, 0b0100000101, RV64I, 4, {nullopt, false, true}},
         {"addw", R, ADDW, 0b0111011, 0b0000000000, RV64I, 4},
         {"subw", R, SUBW, 0b0111011, 0b0100000000, RV64I, 4},
         {"sllw", R, SLLW, 0b0111011, 0b0000000001, RV64I, 4},
         {"srlw", R, SRLW, 0b0111011, 0b0000000101, RV64I, 4},
         {"sraw", R, SRAW, 0b0111011, 0b0100000101, RV64I, 4},
         {"mul", R, MUL, 0b0110011, 0b0000001000, RV32M, 4},
         {"mulh", R, MULH, 0b0110011, 0b0000001001, RV32M, 4},
         {"mulhsu", R, MULHSU, 0b0110011, 0b0000001010, RV32M, 4},
         {"mulhu", R, MULHU, 0b0110011, 0b0000001011, RV32M, 4},
         {"div", R, DIV, 0b0110011, 0b0000001100, RV32M, 4},
         {"divu", R, DIVU, 0b0110011, 0b0000001101, RV32M, 4},
         {"rem", R, REM, 0b0110011, 0b0000001110, RV32M, 4},
         {"remu", R, REMU, 0b0110011, 0b0000001111, RV32M, 4},
         {"mulw", R, MULW, 0b0111011, 0b0000001000, RV64M, 4},
         {"divw", R, DIVW, 0b0111011, 0b0000001100, RV64M, 4},
         {"divuw", R, DIVUW, 0b0111011, 0b0000001101, RV64M, 4},
         {"remw", R, REMW, 0b0111011, 0b0000001110, RV64M, 4},
         {"remuw", R, REMUW, 0b0111011, 0b0000001111, RV64M, 4},
         {"lr.w", R, LRW, 0b0101111, 0b0001000010, RV32A, 4, {0b00000}},
         {"sc.w", R, SCW, 0b0101111, 0b0001100010, RV32A, 4},
         {"lr.w.aq", R, LRWAQ, 0b0101111, 0b0001010010, RV32A, 4, {0b00000}},
         {"sc.w.aq", R, SCWAQ, 0b0101111, 0b0001110010, RV32A, 4},
         {"lr.w.rl", R, LRWRL, 0b0101111, 0b0001001010, RV32A, 4, {0b00000}},
         {"sc.w.rl", R, SCWRL, 0b0101111, 0b0001101010, RV32A, 4},
         {"lr.w.aqrl", R, LRWAQRL, 0b0101111, 0b0001011010, RV32A, 4, {0b00000}},
         {"sc.w.aqrl", R, SCWAQRL, 0b0101111, 0b0001111010, RV32A, 4},
         {"amoswap.w", R, AMOSWAPW, 0b0101111, 0b0000100010, RV32A, 4},
         {"amoadd.w", R, AMOADDW, 0b0101111, 0b0000000010, RV32A, 4},
         {"amoxor.w", R, AMOXORW, 0b0101111, 0b0010000010, RV32A, 4},
         {"amoand.w", R, AMOANDW, 0b0101111, 0b0110000010, RV32A, 4},
         {"amoor.w", R, AMOORW, 0b0101111, 0b0100000010, RV32A, 4},
         {"amomin.w", R, AMOMINW, 0b0101111, 0b1000000010, RV32A, 4},
         {"amomax.w", R, AMOMAXW, 0b0101111, 0b1010000010, RV32A, 4},
         {"amominu.w", R, AMOMINUW, 0b0101111, 0b1100000010, RV32A, 4},
         {"amomaxu.w", R, AMOMAXUW, 0b0101111, 0b1110000010, RV32A, 4},
         {"amoswap.w.aq", R, AMOSWAPWAQ, 0b0101111, 0b0000110010, RV32A, 4},
         {"amoadd.w.aq", R, AMOADDWAQ, 0b0101111, 0b0000010010, RV32A, 4},
         {"amoxor.w.aq", R, AMOXORWAQ, 0b0101111, 0b0010010010, RV32A, 4},
         {"amoand.w.aq", R, AMOANDWAQ, 0b0101111, 0b0110010010, RV32A, 4},
         {"amoor.w.aq", R, AMOORWAQ, 0b0101111, 0b0100010010, RV32A, 4},
         {"amomin.w.aq", R, AMOMINWAQ, 0b0101111, 0b1000010010, RV32A, 4},
         {"amomax.w.aq", R, AMOMAXWAQ, 0b0101111, 0b1010010010, RV32A, 4},
         {"amominu.w.aq", R, AMOMINUWAQ, 0b0101111, 0b1100010010, RV32A, 4},
         {"amomaxu.w.aq", R, AMOMAXUWAQ, 0b0101111, 0b1110010010, RV32A, 4},
         {"amoswap.w.rl", R, AMOSWAPWRL, 0b0101111, 0b0000101010, RV32A, 4},
         {"amoadd.w.rl", R, AMOADDWRL, 0b0101111, 0b0000001010, RV32A, 4},
         {"amoxor.w.rl", R, AMOXORWRL, 0b0101111, 0b0010001010, RV32A, 4},
         {"amoand.w.rl", R, AMOANDWRL, 0b0101111, 0b0110001010, RV32A, 4},
         {"amoor.w.rl", R, AMOORWRL, 0b0101111, 0b0100001010, RV32A, 4},
         {"amomin.w.rl", R, AMOMINWRL, 0b0101111, 0b1000001010, RV32A, 4},
         {"amomax.w.rl", R, AMOMAXWRL, 0b0101111, 0b1010001010, RV32A, 4},
         {"amominu.w.rl", R, AMOMINUWRL, 0b0101111, 0b1100001010, RV32A, 4},
         {"amomaxu.w.rl", R, AMOMAXUWRL, 0b0101111, 0b1110001010, RV32A, 4},
         {"amoswap.w.aqrl", R, AMOSWAPWAQRL, 0b0101111, 0b0000111010, RV32A, 4},
         {"amoadd.w.aqrl", R, AMOADDWAQRL, 0b0101111, 0b0000011010, RV32A, 4},
         {"amoxor.w.aqrl", R, AMOXORWAQRL, 0b0101111, 0b0010011010, RV32A, 4},
         {"amoand.w.aqrl", R, AMOANDWAQRL, 0b0101111, 0b0110011010, RV32A, 4},
         {"amoor.w.aqrl", R, AMOORWAQRL, 0b0101111, 0b0100011010, RV32A, 4},
         {"amomin.w.aqrl", R, AMOMINWAQRL, 0b0101111, 0b1000011010, RV32A, 4},
         {"amomax.w.aqrl", R, AMOMAXWAQRL, 0b0101111, 0b1010011010, RV32A, 4},
         {"amominu.w.aqrl", R, AMOMINUWAQRL, 0b0101111, 0b1100011010, RV32A, 4},
         {"amomaxu.w.aqrl", R, AMOMAXUWAQRL, 0b0101111, 0b1110011010, RV32A, 4},
         {"lr.d", R, LRD, 0b0101111, 0b0001000011, RV64A, 4, {0b00000}},
         {"sc.d", R, SCD, 0b0101111, 0b0001100011, RV64A, 4},
         {"lr.d.aq", R, LRDAQ, 0b0101111, 0b0001010011, RV64A, 4, {0b00000}},
         {"sc.d.aq", R, SCDAQ, 0b0101111, 0b0001110011, RV64A, 4},
         {"lr.d.rl", R, LRDRL, 0b0101111, 0b0001001011, RV64A, 4, {0b00000}},
         {"sc.d.rl", R, SCDRL, 0b0101111, 0b0001101011, RV64A, 4},
         {"lr.d.aqrl", R, LRDAQRL, 0b0101111, 0b0001011011, RV64A, 4, {0b00000}},
         {"sc.d.aqrl", R, SCDAQRL, 0b0101111, 0b0001111011, RV64A, 4},
         {"amoswap.d", R, AMOSWAPD, 0b0101111, 0b0000100011, RV64A, 4},
         {"amoadd.d", R, AMOADDD, 0b0101111, 0b0000000011, RV64A, 4},
         {"amoxor.d", R, AMOXORD, 0b0101111, 0b0010000011, RV64A, 4},
         {"amoand.d", R, AMOANDD, 0b0101111, 0b0110000011, RV64A, 4},
         {"amoor.d", R, AMOORD, 0b0101111, 0b0100000011, RV64A, 4},
         {"amomin.d", R, AMOMIND, 0b0101111, 0b1000000011, RV64A, 4},
         {"amomax.d", R, AMOMAXD, 0b0101111, 0b1010000011, RV64A, 4},
         {"amominu.d", R, AMOMINUD, 0b0101111, 0b1100000011, RV64A, 4},
         {"amomaxu.d", R, AMOMAXUD, 0b0101111, 0b1110000011, RV64A, 4},
         {"amoswap.d.aq", R, AMOSWAPDAQ, 0b0101111, 0b0000110011, RV64A, 4},
         {"amoadd.d.aq", R, AMOADDDAQ, 0b0101111, 0b0000010011, RV64A, 4},
         {"amoxor.d.aq", R, AMOXORDAQ, 0b0101111, 0b0010010011, RV64A, 4},
         {"amoand.d.aq", R, AMOANDDAQ, 0b0101111, 0b0110010011, RV64A, 4},
         {"amoor.d.aq", R, AMOORDAQ, 0b0101111, 0b0100010011, RV64A, 4},
         {"amomin.d.aq", R, AMOMINDAQ, 0b0101111, 0b1000010011, RV64A, 4},
         {"amomax.d.aq", R, AMOMAXDAQ, 0b0101111, 0b1010010011, RV64A, 4},
         {"amominu.d.aq", R, AMOMINUDAQ, 0b0101111, 0b1100010011, RV64A, 4},
         {"amomaxu.d.aq", R, AMOMAXUDAQ, 0b0101111, 0b1110010011, RV64A, 4},
         {"amoswap.d.rl", R, AMOSWAPDRL, 0b0101111, 0b0000101011, RV64A, 4},
         {"amoadd.d.rl", R, AMOADDDRL, 0b0101111, 0b0000001011, RV64A, 4},
         {"amoxor.d.rl", R, AMOXORDRL, 0b0101111, 0b0010001011, RV64A, 4},
         {"amoand.d.rl", R, AMOANDDRL, 0b0101111, 0b0110001011, RV64A, 4},
         {"amoor.d.rl", R, AMOORDRL, 0b0101111, 0b0100001011, RV64A, 4},
         {"amomin.d.rl", R, AMOMINDRL, 0b0101111, 0b1000001011, RV64A, 4},
         {"amomax.d.rl", R, AMOMAXDRL, 0b0101111, 0b1010001011, RV64A, 4},
         {"amominu.d.rl", R, AMOMINUDRL, 0b0101111, 0b1100001011, RV64A, 4},
         {"amomaxu.d.rl", R, AMOMAXUDRL, 0b0101111, 0b1110001011, RV64A, 4},
         {"amoswap.d.aqrl", R, AMOSWAPDAQRL, 0b0101111, 0b0000111011, RV64A, 4},
         {"amoadd.d.aqrl", R, AMOADDDAQRL, 0b0101111, 0b0000011011, RV64A, 4},
         {"amoxor.d.aqrl", R, AMOXORDAQRL, 0b0101111, 0b0010011011, RV64A, 4},
         {"amoand.d.aqrl", R, AMOANDDAQRL, 0b0101111, 0b0110011011, RV64A, 4},
         {"amoor.d.aqrl", R, AMOORDAQRL, 0b0101111, 0b0100011011, RV64A, 4},
         {"amomin.d.aqrl", R, AMOMINDAQRL, 0b0101111, 0b1000011011, RV64A, 4},
         {"amomax.d.aqrl", R, AMOMAXDAQRL, 0b0101111, 0b1010011011, RV64A, 4},
         {"amominu.d.aqrl", R, AMOMINUDAQRL, 0b0101111, 0b1100011011, RV64A, 4},
         {"amomaxu.d.aqrl", R, AMOMAXUDAQRL, 0b0101111, 0b1110011011, RV64A, 4},
         {"fmadd.s", R4, FMADDS, 0b1000011, 0b00, RV32F, 4, {nullopt, true}},
         {"fmsub.s", R4, FMSUBS, 0b1000111, 0b00, RV32F, 4, {nullopt, true}},
         {"fnmsub.s", R4, FNMSUBS, 0b1001011, 0b00, RV32F, 4, {nullopt, true}},
         {"fnmadd.s", R4, FNMADDS, 0b1001111, 0b00, RV32F, 4, {nullopt, true}},
         {"fadd.s", R, FADDS, 0b1010011, 0b0000000000, RV32F, 4, {nullopt, true}},
         {"fsub.s", R, FSUBS, 0b1010011, 0b0000100000, RV32F, 4, {nullopt, true}},
         {"fmul.s", R, FMULS, 0b1010011, 0b0001000000, RV32F, 4, {nullopt, true}},
         {"fdiv.s", R, FDIVS, 0b1010011, 0b0001100000, RV32F, 4, {nullopt, true}},
         {"fsqrt.s", R, FSQRTS, 0b1010011, 0b0101100000, RV32F, 4, {0b00000, true}},
         {"fsgnj.s", R, FSGNJS, 0b1010011, 0b0010000000, RV32F, 4},
         {"fsgnjn.s", R, FSGNJNS, 0b1010011, 0b0010000001, RV32F, 4},
         {"fsgnjx.s", R, FSGNJXS, 0b1010011, 0b0010000010, RV32F, 4},
         {"fmin.s", R, FMINS, 0b1010011, 0b0010100000, RV32F, 4},
         {"fmax.s", R, FMAXS, 0b1010011, 0b0010100001, RV32F, 4},
         {"fcvt.w.s", R, FCVTWS, 0b1010011, 0b1100000000, RV32F, 4, {0b00000, true}},
         {"fcvt.wu.s", R, FCVTWUS, 0b1010011, 0b1100000000, RV32F, 4, {0b00001, true}},
         {"fmv.x.w", R, FMVXW, 0b1010011, 0b1110000000, RV32F, 4, {0b00000}},
         {"feq.s", R, FEQS, 0b1010011, 0b1010000010, RV32F, 4},
         {"flt.s", R, FLTS, 0b1010011, 0b1010000001, RV32F, 4},
         {"fle.s", R, FLES, 0b1010011, 0b1010000000, RV32F, 4},
         {"fclass.s", R, FCLASSS, 0b1010011, 0b1110000001, RV32F, 4, {0b00000}},
         {"fcvt.s.w", R, FCVTSW, 0b1010011, 0b1101000000, RV32F, 4, {0b00000, true}},
         {"fcvt.s.wu", R, FCVTSWU, 0b1010011, 0b1101000000, RV32F, 4, {0b00001, true}},
         {"fmv.w.x", R, FMVWX, 0b1010011, 0b1111000000, RV32F, 4, {0b00000}},
         {"flw", I, FLW, 0b0000111, 0b010, RV32F, 4},
         {"fsw", S, FSW, 0b0100111, 0b010, RV32F, 4},
         {"fcvt.l.s", R, FCVTLS, 0b1010011, 0b1100000000, RV64F, 4, {0b00010, true}},
         {"fcvt.lu.s", R, FCVTLUS, 0b1010011, 0b1100000000, RV64F, 4, {0b00011, true}},
         {"fcvt.s.l", R, FCVTSL, 0b1010011, 0b1101000000, RV64F, 4, {0b00010, true}},
         {"fcvt.s.lu", R, FCVTSLU, 0b1010011, 0b1101000000, RV64F, 4, {0b00011, true}},
         {"fadd.d", R, FADDD, 0b1010011, 0b0000001000, RV32D, 4, {nullopt, true}},
         {"fmadd.d", R4, FMADDD, 0b1000011, 0b01000, RV32D, 4, {nullopt, true}},
         {"fmax.d", R, FMAXD, 0b1010011, 0b0010101001, RV32D, 4},
         {"fclass.d", R, FCLASSD, 0b1010011, 0b1110001001, RV32D, 4, {0b00000}},
         {"fcvt.d.s", R, FCVTDS, 0b1010011, 0b0100001000, RV32D, 4, {0b00000, true}},
         {"fcvt.d.w", R, FCVTDW, 0b1010011, 0b1101001000, RV32D, 4, {0b00000, true}},
         {"fcvt.d.wu", R, FCVTDWU, 0b1010011, 0b1101001000, RV32D, 4, {0b00001, true}},
         {"fcvt.s.d", R, FCVTSD, 0b1010011, 0b0100000000, RV32D, 4, {0b00001, true}},
         {"fcvt.w.d", R, FCVTWD, 0b1010011, 0b1100001000, RV32D, 4, {0b00000, true}},
         {"fcvt.wu.d", R, FCVTWUD, 0b1010011, 0b1100001000, RV32D, 4, {0b00001, true}},
         {"fdiv.d", R, FDIVD, 0b1010011, 0b0001101000, RV32D, 4, {nullopt, true}},
         {"feq.d", R, FEQD, 0b1010011, 0b1010001010, RV32D, 4},
         {"flt.d", R, FLTD, 0b1010011, 0b1010001001, RV32D, 4},
         {"fle.d", R, FLED, 0b1010011, 0b1010001000, RV32D, 4},
         {"fld", I, FLD, 0b0000111, 0b011, RV32D, 4},
         {"fmin.d", R, FMIND, 0b1010011, 0b0010101000, RV32D, 4},
         {"fmsub.d", R4, FMSUBD, 0b1000111, 0b01000, RV32D, 4, {nullopt, true}},
         {"fmul.d", R, FMULD, 0b1010011, 0b0001001000, RV32D, 4, {nullopt, true}},
         {"fnmadd.d", R4, FNMADDD, 0b1001111, 0b01000, RV32D, 4, {nullopt, true}},
         {"fnmsub.d", R4, FNMSUBD, 0b1001011, 0b01000, RV32D, 4, {nullopt, true}},
         {"fsd", S, FSD, 0b0100111, 0b011, RV32D, 4},
         {"fsgnj.d", R, FSGNJD, 0b1010011, 0b0010001000, RV32D, 4},
         {"fsgnjn.d", R, FSGJND, 0b1010011, 0b0010001001, RV32D, 4},
         {"fsgnjx.d", R, FSGNJXD, 0b1010011, 0b0010001010, RV32D, 4},
         {"fsqrt.d", R, FSQRTD, 0b1010011, 0b0101101000, RV32D, 4, {0b00000, true}},
         {"fsub.d", R, FSUBD, 0b1010011, 0b0000101000, RV32D, 4, {nullopt, true}},
         {"fcvt.l.d", R, FCVTLD, 0b1010011, 0b1100001000, RV64D, 4, {0b00010, true}},
         {"fcvt.lu.d", R, FCVTLUD, 0b1010011, 0b1100001000, RV64D, 4, {0b00011, true}},
         {"fmv.x.d", R, FMVXD, 0b1010011, 0b1110001000, RV64D, 4, {0b00000}},
         {"fcvt.d.l", R, FCVTDL, 0b1010011, 0b1101001000, RV64D, 4, {0b00010, true}},
         {"fcvt.d.lu", R, FCVTDLU, 0b1010011, 0b1101001000, RV64D, 4, {0b00011, true}},
         {"fmv.d.x", R, FMVDX, 0b1010011, 0b1111001000, RV64D, 4, {0b00000}},
         {"flq", I, FLQ, 0b0000111, 0b100, RV32Q, 4},
         {"fsq", S, FSQ, 0b0100111, 0b100, RV32Q, 4},
         {"fmadd.q", R4, FMADDQ, 0b1000011, 0b11000, RV32Q, 4, {nullopt, true}},
         {"fmsub.q", R4, FMSUBQ, 0b1000111, 0b11000, RV32Q, 4, {nullopt, true}},
         {"fnmsub.q", R4, FNMSUBQ, 0b1001011, 0b11000, RV32Q, 4, {nullopt, true}},
         {"fnmadd.q", R4, FNMADDQ, 0b1001111, 0b11000, RV32Q, 4, {nullopt, true}},
         {"fadd.q", R, FADDQ, 0b1010011, 0b0000011000, RV32Q, 4, {nullopt, true}},
         {"fsub.q", R, FSUBQ, 0b1010011, 0b0000111000, RV32Q, 4, {nullopt, true}},
         {"fmul.q", R, FMULQ, 0b1010011, 0b0001011000, RV32Q, 4, {nullopt, true}},
         {"fdiv.q", R, FDIVQ, 0b1010011, 0b0001111000, RV32Q, 4, {nullopt, true}},
         {"fsqrt.q", R, FSQRTQ, 0b1010011, 0b0101111000, RV32Q, 4, {0b00000, true}},
         {"fsgnj.q", R, FSGNJQ, 0b1010011, 0b0010011000, RV32Q, 4},
         {"fsgnjn.q", R, FSGNJNQ, 0b1010011, 0b0010011001, RV32Q, 4},
         {"fsgnjx.q", R, FSGNJXQ, 0b1010011, 0b0010011010, RV32Q, 4},
         {"fmin.q", R, FMINQ, 0b1010011, 0b0010111000, RV32Q, 4},
         {"fmax.q", R, FMAXQ, 0b1010011, 0b0010111001, RV32Q, 4},
         {"fcvt.s.q", R, FCVTSQ, 0b1010011, 0b0100000000, RV32Q, 4, {0b00011, true}},
         {"fcvt.q.s", R, FCVTQS, 0b1010011, 0b0100011000, RV32Q, 4, {0b00000, true}},
         {"fcvt.d.q", R, FCVTDQ, 0b1010011, 0b0100001000, RV32Q, 4, {0b00011, true}},
         {"fcvt.q.d", R, FCVTQD, 0b1010011, 0b0100011000, RV32Q, 4, {0b00001, true}},
         {"feq.q", R, FEQQ, 0b1010011, 0b1010011010, RV32Q, 4},
         {"flt.q", R, FLTQ, 0b1010011, 0b1010011001, RV32Q, 4},
         {"fle.q", R, FLEQ, 0b1010011, 0b1010011000, RV32Q, 4},
         {"fclass.q", R, FCLASSQ, 0b1010011, 0b1110011001, RV32Q, 4, {0b00000}},
         {"fcvt.w.q", R, FCVTWQ, 0b1010011, 0b1100011000, RV32Q, 4, {0b00000, true}},
         {"fcvt.wu.q", R, FCVTWUQ, 0b1010011, 0b1100011000, RV32Q, 4, {0b00001, true}},
         {"fcvt.q.w", R, FCVTQW, 0b1010011, 0b1101011000, RV32Q, 4, {0b00000, true}},
         {"fcvt.q.wu", R, FCVTQWU, 0b1010011, 0b1101011000, RV32Q, 4, {0b00001, true}},
         {"fcvt.l.q", R, FCVTLQ, 0b1010011, 0b1100011000, RV64Q, 4, {0b00010, true}},
         {"fcvt.lu.q", R, FCVTLUQ, 0b1010011, 0b1100011000, RV64Q, 4, {0b00011, true}},
         {"fcvt.q.l", R, FCVTQL, 0b1010011, 0b1101011000, RV64Q, 4, {0b00010, true}},
         {"fcvt.q.lu", R, FCVTQLU, 0b1010011, 0b1101011000, RV64Q, 4, {0b00011, true}},
         {"flh", I, FLH, 0b0000111, 0b001, RV32Zfh, 4},
         {"fsh", S, FSH, 0b0100111, 0b001, RV32Zfh, 4},
         {"fmadd.h", R4, FMADDH, 0b1000011, 0b10000, RV32Zfh, 4, {nullopt, true}},
         {"fmsub.h", R4, FMSUBH, 0b1000111, 0b10000, RV32Zfh, 4, {nullopt, true}},
         {"fnmsub.h", R4, FNMSUBH, 0b1001011, 0b10000, RV32Zfh, 4, {nullopt, true}},
         {"fnmadd.h", R4, FNMADDH, 0b1001111, 0b10000, RV32Zfh, 4, {nullopt, true}},
         {"fadd.h", R, FADDH, 0b1010011, 0b0000010000, RV32Zfh, 4, {nullopt, true}},
         {"fsub.h", R, FSUBH, 0b1010011, 0b0000110000, RV32Zfh, 4, {nullopt, true}},
         {"fmul.h", R, FMULH, 0b1010011, 0b0001010000, RV32Zfh, 4, {nullopt, true}},
         {"fdiv.h", R, FDIVH, 0b1010011, 0b0001110000, RV32Zfh, 4, {nullopt, true}},
         {"fsqrt.h", R, FSQRTH, 0b1010011, 0b0101110000, RV32Zfh, 4, {0b00000, true}},
         {"fsgnj.h", R, FSGNJH, 0b1010011, 0b0010010000, RV32Zfh, 4},
         {"fsgnjn.h", R, FSGNJNH, 0b1010011, 0b0010010001, RV32Zfh, 4},
         {"fsgnjx.h", R, FSGNJXH, 0b1010011, 0b0010010010, RV32Zfh, 4},
         {"fmin.h", R, FMINH, 0b1010011, 0b0010110000, RV32Zfh, 4},
         {"fmax.h", R, FMAXH, 0b1010011, 0b0010110001, RV32Zfh, 4},
         {"fcvt.s.h", R, FCVTSH, 0b1010011, 0b0100000000, RV32Zfh, 4, {0b00010, true}},
         {"fcvt.h.s", R, FCVTHS, 0b1010011, 0b0100010000, RV32Zfh, 4, {0b00000, true}},
         {"fcvt.d.h", R, FCVTDH, 0b1010011, 0b0100001000, RV32Zfh, 4, {0b00010, true}},
         {"fcvt.h.d", R, FCVTHD, 0b1010011, 0b0100010000, RV32Zfh, 4, {0b00001, true}},
         {"fcvt.q.h", R, FCVTQH, 0b1010011, 0b0100011000, RV32Zfh, 4, {0b00010, true}},
         {"fcvt.h.q", R, FCVTHQ, 0b1010011, 0b0100010000, RV32Zfh, 4, {0b00011, true}},
         {"feq.h", R, FEQH, 0b1010011, 0b1010010010, RV32Zfh, 4},
         {"flt.h", R, FLTH, 0b1010011, 0b1010010001, RV32Zfh, 4},
         {"fle.h", R, FLEH, 0b1010011, 0b1010010000, RV32Zfh, 4},
         {"fclass.h", R, FCLASSH, 0b1010011, 0b1110010001, RV32Zfh, 4, {0b00000}},
         {"fcvt.w.h", R, FCVTWH, 0b1010011, 0b1100010000, RV32Zfh, 4, {0b00000, true}},
         {"fcvt.wu.h", R, FCVTWUH, 0b1010011, 0b1100010000, RV32Zfh, 4, {0b00001, true}},
         {"fmv.x.h", R, FMVXH, 0b1010011, 0b1110010000, RV32Zfh, 4, {0b00000}},
         {"fcvt.h.w", R, FCVTHW, 0b1010011, 0b1101010000, RV32Zfh, 4, {0b00000, true}},
         {"fcvt.h.wu", R, FCVTHWU, 0b1010011, 0b1101010000, RV32Zfh, 4, {0b00001, true}},
         {"fmv.h.x", R, FMVXH, 0b1010011, 0b1111010000, RV32Zfh, 4, {0b00000}},
         {"fcvt.l.h", R, FCVTLH, 0b1010011, 0b1100010000, RV64Zfh, 4, {0b00010, true}},
         {"fcvt.lu.h", R, FCVTLUH, 0b1010011, 0b1100010000, RV64Zfh, 4, {0b00011, true}},
         {"fcvt.h.l", R, FCVTHL, 0b1010011, 0b1101010000, RV64Zfh, 4, {0b00010, true}},
         {"fcvt.h.lu", R, FCVTHLU, 0b1010011, 0b1101010000, RV64Zfh, 4, {0b00011, true}},
         {"fence.i", I, FENCEI, 0b0001111, 0b001, Zifencei, 4, {nullopt, false, false, true}},
         {"csrrw", I, CSRRW, 0b1110011, 0b001, Zicsr, 4, {nullopt, false, false, true}},
         {"csrrs", I, CSRRS, 0b1110011, 0b010, Zicsr, 4, {nullopt, false, false, true}},
         {"csrrc", I, CSRRC, 0b1110011, 0b011, Zicsr, 4, {nullopt, false, false, true}},
         {"csrrwi", I, CSRRWI, 0b1110011, 0b101, Zicsr, 4, {nullopt, false, false, true}},
         {"csrrsi", I, CSRRSI, 0b1110011, 0b110, Zicsr, 4, {nullopt, false, false, true}},
         {"csrrci", I, CSRRCI, 0b1110011, 0b111, Zicsr, 4, {nullopt, false, false, true}},
         {"wrs.nto", I, WRSNTO, 0b1110011, 0b000, Zawrs, 4, {nullopt, false, false, true}},
         {"wrs.sto", I, WRSSTO, 0b1110011, 0b000, Zawrs, 4, {nullopt, false, false, true}},
         {"c.lwsp", CI, CLWSP, 0b10, 0b010, C, 2},
         {"c.ldsp", CI, CLDSP, 0b10, 0b011, C, 2},
         {"c.flwsp", CI, CFLWSP, 0b10, 0b011, C, 2},
         {"c.fldsp", CI, CFLDSP, 0b10, 0b001, C, 2},
         {"c.swsp", CSS, CSWSP, 0b10, 0b110, C, 2},
         {"c.sdsp", CSS, CSDSP, 0b10, 0b111, C, 2},
         {"c.fswsp", CSS, CFSWSP, 0b10, 0b111, C, 2},
         {"c.fsdsp", CSS, CFSDSP, 0b10, 0b101, C, 2},
         {"c.lw", CL, CLW, 0b00, 0b010, C, 2},
         {"c.ld", CL, CLD, 0b00, 0b011, C, 2},
         {"c.flw", CL, CFLW, 0b00, 0b011, C, 2},
         {"c.fld", CL, CFLD, 0b00, 0b001, C, 2},
         {"c.sw", CS, CSW, 0b00, 0b110, C, 2},
         {"c.sd", CS, CSD, 0b00, 0b111, C, 2},
         {"c.fsw", CS, CFSW, 0b00, 0b111, C, 2},
         {"c.fsd", CS, CFSD, 0b00, 0b101, C, 2},
         {"c.j", CJ, CJump, 0b01, 0b101, C, 2},
         {"c.jal", CJ, CJAL, 0b01, 0b001, C, 2},
         {"c.jr", CR, CJR, 0b10, 0b1000, C, 2, {0b00000}},
         {"c.jalr", CR, CJALR, 0b10, 0b1001, C, 2, {0b00000}},
         {"c.beqz", CB, CBEQZ, 0b01, 0b110, C, 2},
         {"c.bnez", CB, CBNEZ, 0b01, 0b111, C, 2},
         {"c.li", CI, CLI, 0b01, 0b010, C, 2},
         {"c.lui", CI, CLUI, 0b01, 0b011, C, 2},
         {"c.addi", CI, CADDI, 0b01, 0b000, C, 2},
         {"c.addiw", CI, CADDIW, 0b01, 0b001, C, 2},
         {"c.addi16sp", CI, CADDI16SP, 0b01, 0b011, C, 2},
         {"c.slli", CI, CSLLI, 0b10, 0b000, C, 2},
         {"c.srli", CB, CSRLI, 0b01, 0b10000, C, 2},
         {"c.srai", CB, CSRAI, 0b01, 0b10001, C, 2},
         {"c.andi", CB, CANDI, 0b01, 0b10010, C, 2},
         {"c.mv", CR, CMV, 0b10, 0b1000, C, 2},
         {"c.add", CR, CADD, 0b10, 0b1001, C, 2},
         {"c.and", CA, CAND, 0b01, 0b10001111, C, 2},
         {"c.or", CA, COR, 0b01, 0b10001110, C, 2},
         {"c.xor", CA, CXOR, 0b01, 0b10001101, C, 2},
         {"c.sub", CA, CSUB, 0b01, 0b10001100, C, 2},
         {"c.addw", CA, CADDW, 0b01, 0b10011101, C, 2},
         {"c.subw", CA, CSUBW, 0b01, 0b10011100, C, 2},
         {"c.nop", CI, CNOP, 0b01, 0b000, C, 2, {nullopt, false, false, true}},
         {"c.ebreak", CI, CEBREAK, 0b10, 0b1001, C, 2, {nullopt, false, false, true}},
         {"czero.eqz", R, CZEROEQZ, 0b0110011, 0b0000111101, Zicond, 4},
         {"czero.nez", R, CZERONEZ, 0b0110011, 0b0000111111, Zicond, 4},
         {"amocas.w", R, AMOCASW, 0b0101111, 0b0010100010, Zacas, 4},
         {"amocas.d", R, AMOCASD, 0b0101111, 0b0010100011, Zacas, 4},
         {"amocas.q", R, AMOCASQ, 0b0101111, 0b0010100100, Zacas, 4},
         {"amocas.w.aq", R, AMOCASWAQ, 0b0101111, 0b0010110010, Zacas, 4},
         {"amocas.d.aq", R, AMOCASDAQ, 0b0101111, 0b0010110011, Zacas, 4},
         {"amocas.q.aq", R, AMOCASQAQ, 0b0101111, 0b0010110100, Zacas, 4},
         {"amocas.w.rl", R, AMOCASWRL, 0b0101111, 0b0010101010, Zacas, 4},
         {"amocas.d.rl", R, AMOCASDRL, 0b0101111, 0b0010101011, Zacas, 4},
         {"amocas.q.rl", R, AMOCASQRL, 0b0101111, 0b0010101100, Zacas, 4},
         {"amocas.w.aqrl", R, AMOCASWAQRL, 0b0101111, 0b0010111010, Zacas, 4},
         {"amocas.d.aqrl", R, AMOCASDAQRL, 0b0101111, 0b0010111011, Zacas, 4},
         {"amocas.q.aqrl", R, AMOCASQAQRL, 0b0101111, 0b0010111100, Zacas, 4},
         {"c.lbu", CLB, CLBU, 0b00, 0b100000, Zcb, 2},
         {"c.lhu", CLHfmt, CLHU, 0b00, 0b1000010, Zcb, 2},
         {"c.lh", CLHfmt, CLH, 0b00, 0b1000011, Zcb, 2},
         {"c.sb", CSHfmt, CSB, 0b00, 0b100010, Zcb, 2},
         {"c.sh", CSHfmt, CSH, 0b00, 0b1000110, Zcb, 2},
         {"c.zext.b", CU, CZEXTB, 0b01, 0b10011111000, Zcb, 2},
         {"c.sext.b", CU, CSEXTB, 0b01, 0b10011111001, Zcb, 2},
         {"c.zext.h", CU, CZEXTH, 0b01, 0b10011111010, Zcb, 2},
         {"c.sext.h", CU, CSEXTH, 0b01, 0b10011111011, Zcb, 2},
         {"c.zext.w", CU, CZEXTW, 0b01, 0b10011111100, Zcb, 2},
         {"c.not", CU, CNOT, 0b01, 0b10011111101, Zcb, 2},
         {"c.mul", CA, CMUL, 0b01, 0b10011110, Zcb, 2},
         {"cm.push", CMPP, CMPUSH, 0b10, 0b10111000, Zcmp, 2},
         {"cm.pop", CMPP, CMPOP, 0b10, 0b10111010, Zcmp, 2},
         {"cm.popretz", CMPP, CMPOPRETZ, 0b10, 0b10111100, Zcmp, 2},
         {"cm.popret", CMPP, CMPOPRET, 0b10, 0b10111110, Zcmp, 2},
         {"cm.mvsa01", CMMV, CMMVSA01, 0b10, 0b10101101, Zcmp, 2},
         {"cm.mva01s", CMMV, CMMVA01S, 0b10, 0b10101111, Zcmp, 2},
         {"cm.jt", CMJTfmt, CMJT, 0b10, 0b101000, Zcmt, 2},
         {"cm.jalt", CMJTfmt, CMJALT, 0b10, 0b101000, Zcmt, 2},
         {"add.uw", R, ADDUW, 0b0111011, 0b0000100000, Bit, 4},
         {"andn", R, ANDN, 0b0110011, 0b0100000111, Bit, 4},
         {"bclr", R, BCLR, 0b0110011, 0b0100100001, Bit, 4},
         {"bclri", R, BCLRI, 0b0010011, 0b0100100001, Bit, 4, {nullopt, false, true}}, // This one "requires" an extra bit in shamt for RV64, but in reality it's a special case where shamt is big
                                                                                       // enough to clear a 64 bit register, so we just add the extra bit to rs2 and let the extra available space
                                                                                       // handle it transparently
         {"bext", R, BEXT, 0b0110011, 0b0100100101, Bit, 4},
         {"bexti", R, BEXTI, 0b0010011, 0b0100100101, Bit, 4, {nullopt, false, true}}, // Same idea as bclri
         {"binv", R, BINV, 0b0110011, 0b0110100001, Bit, 4},
         {"binvi", R, BINVI, 0b0010011, 0b0110100001, Bit, 4, {nullopt, false, true}}, // Same idea as bclri
         {"bset", R, BSET, 0b0110011, 0b0010100001, Bit, 4},
         {"bseti", R, BSETI, 0b0010011, 0b0010100001, Bit, 4, {nullopt, false, true}}, // Same idea as bclri
         {"clmul", R, CLMUL, 0b0110011, 0b0000101001, Bit, 4},
         {"clmulh", R, CLMULH, 0b0110011, 0b0000101011, Bit, 4},
         {"clmulr", R, CLMULR, 0b0110011, 0b0000101010, Bit, 4},
         {"clz", R, CLZ, 0b0010011, 0b0110000001, Bit, 4, {0b00000}},
         {"clzw", R, CLZW, 0b0011011, 0b0110000001, Bit, 4, {0b00000}},
         {"cpop", R, CPOP, 0b0010011, 0b0110000001, Bit, 4, {0b00010}},
         {"cpopw", R, CPOPW, 0b0011011, 0b0110000001, Bit, 4, {0b00010}},
         {"ctz", R, CTZ, 0b0010011, 0b0110000001, Bit, 4, {0b00001}},
         {"ctzw", R, CTZW, 0b0011011, 0b0110000001, Bit, 4, {0b00001}},
         {"max", R, MAX, 0b0110011, 0b0000101110, Bit, 4},
         {"maxu", R, MAXU, 0b0110011, 0b0000101111, Bit, 4},
         {"min", R, MIN, 0b0110011, 0b0000101100, Bit, 4},
         {"minu", R, MINU, 0b0110011, 0b0000101101, Bit, 4},
         {"orc.b", R, ORCB, 0b0010011, 0b0010100101, Bit, 4, {0b00111}},
         {"orn", R, ORN, 0b0110011, 0b0100000110, Bit, 4},
         {"pack", R, PACK, 0b0110011, 0b0000100100, Bit, 4},
         {"packh", R, PACKH, 0b0110011, 0b0000100111, Bit, 4},
         {"packw", R, PACKW, 0b0111011, 0b0000100100, Bit, 4},
         {"rev8", R, REV8, 0b0010011, 0b0110100101, Bit, 4, {0b11000}}, // This one is similar to bclri, but it instead makes bit 25 1 on rv64 and otherwise stays the same
         {"rev.b", R, REVB, 0b0010011, 0b0110100101, Bit, 4, {0b00111}},
         {"rol", R, ROL, 0b0110011, 0b0110000001, Bit, 4},
         {"rolw", R, ROLW, 0b0111011, 0b0110000001, Bit, 4},
         {"ror", R, ROR, 0b0110011, 0b0110000101, Bit, 4},
         {"rori", R, RORI, 0b0010011, 0b0110000101, Bit, 4, {nullopt, false, true}}, // Same idea as bclri
         {"roriw", R, RORIW, 0b0011011, 0b0110000101, Bit, 4, {nullopt, false, true}},
         {"rorw", R, RORW, 0b0111011, 0b0110000101, Bit, 4},
         {"sext.b", R, SEXTB, 0b0010011, 0b0110000001, Bit, 4, {0b00100}},
         {"sext.h", R, SEXTH, 0b0010011, 0b0110000001, Bit, 4, {0b00101}},
         {"sh1add", R, SH1ADD, 0b0110011, 0b0010000010, Bit, 4},
         {"sh2add.uw", R, SH1ADDUW, 0b0111011, 0b0010000010, Bit, 4},
         {"sh2add", R, SH2ADD, 0b0110011, 0b0010000100, Bit, 4},
         {"sh2add.uw", R, SH2ADDUW, 0b0111011, 0b0010000100, Bit, 4},
         {"sh3add", R, SH3ADD, 0b0110011, 0b0010000110, Bit, 4},
         {"sh3add.uw", R, SH3ADDUW, 0b0111011, 0b0010000110, Bit, 4},
         {"slli.uw", R, SLLIUW, 0b0011011, 0b000010001, Bit, 4, {nullopt, false, true}},
         {"unzip", R, UNZIP, 0b0010011, 0b0000100101, Bit, 4, {0b11111}},
         {"xnor", R, XNOR, 0b0110011, 0b0100000100, Bit, 4},
         {"xperm.b", R, XPERMB, 0b0110011, 0b0010100100, Bit, 4},
         {"xperm.n", R, XPERMN, 0b0110011, 0b0010100010, Bit, 4},
         {"zext.h", R, ZEXTH, 0b0110011, 0b0000100100, Bit, 4, {0b00000}}, // Similar to rev8, but we make bit 4 (in the opcode) 1 instead for rv64
         {"zip", R, ZIP, 0b0010011, 0b0000100001, Bit, 4, {0b11110}}}};

} // namespace libchata_internal