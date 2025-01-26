#include "instructions.hpp"
#include "libchata.hpp"

#pragma once

namespace libchata_internal {

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
    chatastring arg_extra;
    chatavector<uint8_t> machine_code;
    chatavector<RVInstructionSet> supported_sets;
    chatavector<std::pair<chatastring, int>> labels;
    chatavector<label_loc> label_locs;
    chatavector<directive_option> options;
    int32_t custom_inst = 0;
    uint32_t line = 1;
    uint32_t column = 0;
    uint16_t inst_offset = 0;
    RVInstructionFormat raw_format;
};

void make_inst(assembly_context& c);

} // namespace libchata_internal