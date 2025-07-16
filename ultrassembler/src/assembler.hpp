#include "instructions.hpp"
#include "ultrassembler.hpp"

#pragma once

namespace ultrassembler_internal {

struct directive_options {
    ultravector<RVInstructionSet> supported_sets;
    bool plain_jump_offset = false;
};

struct label_loc {
    size_t loc = 0;
    int id = 0;
    uint8_t i_bytes = 0;
    bool is_dest;
    RVInstructionFormat format;
};

struct assembly_context {
    ultrastring inst;
    ultrastring arg1;
    ultrastring arg2;
    ultrastring arg3;
    ultrastring arg4;
    ultrastring arg5;
    ultrastring arg6;
    ultrastring arg_extra;
    ultravector<uint8_t> machine_code;
    ultravector<RVInstructionSet> supported_sets;
    ultravector<std::pair<ultrastring, int>> labels;
    ultravector<label_loc> label_locs;
    ultravector<std::pair<ultrastring, ultrastring>> constants;
    ultravector<directive_options> options;
    int32_t custom_inst = 0;
    uint32_t line = 1;
    uint32_t column = 0;
    uint16_t inst_offset = 0;
    RVInstructionFormat raw_format;
};

void make_inst(assembly_context& c);

} // namespace ultrassembler_internal