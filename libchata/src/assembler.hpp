#include "libchata.hpp"

#pragma once

namespace libchata_internal {

enum class InstrImmPurpose : uint8_t {
    INSTR_IMM, // The regular case
    LABEL_DEST, // The value in imm is the label id we want to go to
    LABEL_NODE, // This instruction is the location of this label id instead
    RAW_INSTR, // This instruction is solely what's in imm, for custom instructions
    OPCODE_AND_IMM // This instruction uses custom fields but we need to store the opcode here to save space
};

/*struct instruction {
    int32_t imm = 0;
    uint16_t inst_offset = 0; // The offset from the instructions array at which our instruction is (saves memory and prevents O(n) lookups)
                                // Alternatively, the size of the raw instruction
    uint8_t rd = 0;
    uint8_t rs1 = 0;
    uint8_t rs2 = 0;
    uint8_t rs3 = 0;
    uint8_t frm = 0;
    InstrImmPurpose imm_purpose = InstrImmPurpose::INSTR_IMM;
};*/

struct directive_option {
    chatavector<RVInstructionSet> supported_sets;
};

struct label_loc {
    uint32_t loc;
    int id;
    bool is_dest;
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
    uint32_t raw_instr;
    RVInstructionFormat raw_format;
    uint32_t line = 1;
    uint32_t column = 0;
    uint16_t inst_offset = 0;
    chatavector<instruction> nodes;
    chatavector<uint8_t> machine_code;
    chatavector<RVInstructionSet> supported_sets;
    chatavector<std::pair<chatastring, int>> labels;
    chatavector<label_loc> label_locs;
    chatavector<directive_option> options;
};

instruction make_inst(assembly_context& c);

} // namespace libchata_internal