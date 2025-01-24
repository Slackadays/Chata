#include "libchata.hpp"
#include "instructions.hpp"

#pragma once

namespace libchata_internal {

enum class InstrImmPurpose : uint8_t {
    INSTR_IMM, // The regular case
    LABEL_DEST, // The value in imm is the label id we want to go to
    LABEL_NODE, // This instruction is the location of this label id instead
    RAW_INSTR, // This instruction is solely what's in imm, for custom instructions
    OPCODE_AND_IMM // This instruction uses custom fields but we need to store the opcode here to save space
};

struct directive_option {
    chatavector<RVInstructionSet> supported_sets;
};

struct label_loc {
    size_t loc = 0;
    int id = 0;
    uint8_t i_bytes = 0;
    bool is_dest;
    RVInstructionFormat format;
};

struct assembly_context {
    chatastring inst;
    chatastring arg1;
    chatastring arg2;
    chatastring arg3;
    chatastring arg4;
    chatastring arg5;
    chatastring arg6;
    chatastring arg7;
    chatavector<uint8_t> machine_code;
    chatavector<RVInstructionSet> supported_sets;
    chatavector<std::pair<chatastring, int>> labels;
    chatavector<label_loc> label_locs;
    chatavector<directive_option> options;
    int32_t custom_inst = 0;
    uint32_t line = 1;
    uint32_t column = 0;
    uint16_t inst_offset = 0;
    InstrImmPurpose imm_purpose = InstrImmPurpose::INSTR_IMM;
    RVInstructionFormat raw_format;
};

void make_inst(assembly_context& c);

} // namespace libchata_internal