#pragma once

namespace libchata_internal {

enum class InstrImmPurpose : uint8_t {
    INSTR_IMM,
    LABEL_DEST,
    LABEL_NODE
};

struct instruction {
    uint16_t inst_offset = 0; // The offset from the instructions array at which our instruction is (saves memory and prevents O(n) lookups)
    uint8_t rd = 0;
    uint8_t rs1 = 0;
    uint8_t rs2 = 0;
    uint8_t rs3 = 0;
    uint8_t frm = 0;
    int32_t imm = 0;
    InstrImmPurpose imm_purpose = InstrImmPurpose::INSTR_IMM;
};

struct directive_option {
    chatavector<RVInstructionSet> supported_sets; 
};

struct assembly_context {
    chatavector<instruction> nodes;
    size_t instruction_bytes = 0;
    chatavector<RVInstructionSet> supported_sets;
    chatavector<std::pair<chatastring, int>> labels;
    chatavector<directive_option> options;
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

instruction make_inst(assembly_context& c);

} // namespace libchata_internal