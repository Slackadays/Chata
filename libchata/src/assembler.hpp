#include "libchata.hpp"

#pragma once

namespace libchata_internal {

enum class InstrImmPurpose : uint8_t {
    INSTR_IMM,
    LABEL_DEST,
    LABEL_NODE,
    RAW_INSTR
};

struct instruction {
    int32_t imm = 0;
    uint16_t inst_offset = 0; // The offset from the instructions array at which our instruction is (saves memory and prevents O(n) lookups)
                                // Alternatively, the size of the raw instruction
    uint8_t rd = 0;
    uint8_t rs1 = 0;
    uint8_t rs2 = 0;
    uint8_t rs3 = 0;
    uint8_t frm = 0;
    InstrImmPurpose imm_purpose = InstrImmPurpose::INSTR_IMM;
};

struct directive_option {
    chatavector<RVInstructionSet> supported_sets;
};

struct assembly_context {
    chatastring inst;
    chatastring arg1;
    chatastring arg2;
    chatastring arg3;
    chatastring arg4;
    chatastring arg5;
    chatastring arg6;
    uint32_t instruction_bytes = 0;
    uint32_t line = 1;
    uint32_t column = 0;
    uint16_t inst_offset = 0;
    chatavector<instruction> nodes;
    chatavector<uint8_t> machine_code;
    chatavector<RVInstructionSet> supported_sets;
    chatavector<std::pair<chatastring, int>> labels;
    chatavector<directive_option> options;
};

instruction make_inst(assembly_context& c);

} // namespace libchata_internal