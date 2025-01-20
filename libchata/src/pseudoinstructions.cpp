// SPDX-License-Identifier: MPL-2.0
#include "assembler.hpp"
#include "instructions.hpp"
#include "libchata.hpp"

namespace libchata_internal {

chatavector<instruction> li_instr(assembly_context& c) { // li rd, imm -> lui rd, imm[31:12]; addi rd, rd, imm[11:0]
                                                         // Case 1: imm is a 12-bit signed integer
    int imm;
    if (auto num = to_num<int>(c.arg2); num.has_value()) {
        imm = num.value();
    } else {
        throw ChataError(ChataErrorType::Compiler, "Invalid immediate " + c.arg2, c.line, c.column);
    }
    if (imm >= -2048 && imm <= 2047) {
        c.inst_offset = fast_instr_search("addi");
        c.arg2 = "zero";
        c.arg3 = to_chatastring(imm);
        return {make_inst(c)};
    }
    // Case 2: imm is anything else, split into two instructions, the first assigning the upper 20 bits and the second the lower 12 bits
    c.inst_offset = fast_instr_search("lui");
    c.arg2 = to_chatastring(imm >> 12);
    instruction i1 = make_inst(c);
    c.inst_offset = fast_instr_search("addi");
    c.arg2 = c.arg1;
    c.arg3 = to_chatastring(imm & 0xFFF);
    instruction i2 = make_inst(c);
    return {i1, i2};
}

chatavector<instruction> la_instr(assembly_context& c) { // la rd, imm -> auipc rd, imm[31:12]; addi rd, rd, imm[11:0]
                                                         // Case 1: imm is a 12-bit signed integer
    int imm;
    if (auto num = to_num<int>(c.arg2); num.has_value()) {
        imm = num.value();
    } else {
        throw ChataError(ChataErrorType::Compiler, "Invalid immediate " + c.arg2, c.line, c.column);
    }
    if (imm >= -2048 && imm <= 2047) {
        c.inst_offset = fast_instr_search("addi");
        c.arg2 = "zero";
        c.arg3 = to_chatastring(imm);
        return {make_inst(c)};
    }
    // Case 2: imm is anything else, split into two instructions, the first assigning the upper 20 bits and the second the lower 12 bits
    c.inst_offset = fast_instr_search("auipc");
    c.arg2 = to_chatastring(imm >> 12);
    instruction i1 = make_inst(c);
    c.inst_offset = fast_instr_search("addi");
    c.arg2 = c.arg1;
    c.arg3 = to_chatastring(imm & 0xFFF);
    instruction i2 = make_inst(c);
    return {i1, i2};
}

chatavector<instruction> mv_instr(assembly_context& c) { // mv rd, rs -> addi rd, rs, 0
    c.inst_offset = fast_instr_search("addi");
    c.arg3 = "0";
    return {make_inst(c)};
}

chatavector<instruction> not_instr(assembly_context& c) { // not rd, rs -> xori rd, rs, -1
    c.inst_offset = fast_instr_search("xori");
    c.arg3 = "-1";
    return {make_inst(c)};
}

chatavector<instruction> neg_instr(assembly_context& c) { // neg rd, rs -> sub rd, zero, rs
    c.inst_offset = fast_instr_search("sub");
    c.arg3 = c.arg2;
    c.arg2 = "zero";
    return {make_inst(c)};
}

chatavector<instruction> negw_instr(assembly_context& c) { // negw rd, rs -> subw rd, zero, rs
    c.inst_offset = fast_instr_search("subw");
    c.arg3 = c.arg2;
    c.arg2 = "zero";
    return {make_inst(c)};
}

chatavector<instruction> seqz_instr(assembly_context& c) { // seqz rd, rs -> sltiu rd, rs, 1
    c.inst_offset = fast_instr_search("sltiu");
    c.arg3 = "1";
    return {make_inst(c)};
}

chatavector<instruction> snez_instr(assembly_context& c) { // snez rd, rs -> sltu rd, zero, rs
    c.inst_offset = fast_instr_search("sltu");
    c.arg2 = "zero";
    return {make_inst(c)};
}

chatavector<instruction> sltz_instr(assembly_context& c) { // sltz rd, rs -> slt rd, rs, zero
    c.inst_offset = fast_instr_search("slt");
    c.arg3 = "zero";
    return {make_inst(c)};
}

chatavector<instruction> sgtz_instr(assembly_context& c) { // sgtz rd, rs -> slt rd, zero, rs
    c.inst_offset = fast_instr_search("slt");
    c.arg3 = c.arg2;
    c.arg2 = "zero";
    return {make_inst(c)};
}

chatavector<instruction> bgt_instr(assembly_context& c) { // bgt rs1, rs2, label|imm -> blt rs2, rs1, label|imm
    c.inst_offset = fast_instr_search("blt");
    std::swap(c.arg1, c.arg2);
    return {make_inst(c)};
}

chatavector<instruction> ble_instr(assembly_context& c) { // ble rs1, rs2, label|imm -> bge rs2, rs1, label|imm
    c.inst_offset = fast_instr_search("bge");
    std::swap(c.arg1, c.arg2);
    return {make_inst(c)};
}

chatavector<instruction> bgtu_instr(assembly_context& c) { // bgtu rs1, rs2, label|imm -> bltu rs2, rs1, label|imm
    c.inst_offset = fast_instr_search("bltu");
    std::swap(c.arg1, c.arg2);
    return {make_inst(c)};
}

chatavector<instruction> bleu_instr(assembly_context& c) { // bleu rs1, rs2, label|imm -> bgeu rs2, rs1, label|imm
    c.inst_offset = fast_instr_search("bgeu");
    std::swap(c.arg1, c.arg2);
    return {make_inst(c)};
}

chatavector<instruction> beqz_instr(assembly_context& c) { // beqz rs, label|imm -> beq rs, zero, label|imm
    c.inst_offset = fast_instr_search("beq");
    c.arg3 = c.arg2;
    c.arg2 = "zero";
    return {make_inst(c)};
}

chatavector<instruction> bnez_instr(assembly_context& c) { // bnez rs, label|imm -> bne rs, zero, label|imm
    c.inst_offset = fast_instr_search("bne");
    c.arg3 = c.arg2;
    c.arg2 = "zero";
    return {make_inst(c)};
}

chatavector<instruction> bgez_instr(assembly_context& c) { // bgez rs, label|imm -> bge rs, zero, label|imm
    c.inst_offset = fast_instr_search("bge");
    c.arg3 = c.arg2;
    c.arg2 = "zero";
    return {make_inst(c)};
}

chatavector<instruction> blez_instr(assembly_context& c) { // blez rs, label|imm -> bge zero, rs, label|imm
    c.inst_offset = fast_instr_search("bge");
    c.arg3 = c.arg2;
    c.arg2 = c.arg1;
    c.arg1 = "zero";
    return {make_inst(c)};
}

chatavector<instruction> bgtz_instr(assembly_context& c) { // bgtz rs, label|imm -> blt zero, rs, label|imm
    c.inst_offset = fast_instr_search("blt");
    c.arg3 = c.arg2;
    c.arg2 = c.arg1;
    c.arg1 = "zero";
    return {make_inst(c)};
}

chatavector<instruction> j_instr(assembly_context& c) {
    c.inst_offset = fast_instr_search("jal");
    c.arg2 = c.arg1;
    c.arg1 = "zero";
    return {make_inst(c)};
}

chatavector<instruction> call_instr(assembly_context& c) {
    // Case 1: imm is a 12-bit signed integer
    int imm;
    if (auto num = to_num<int>(c.arg1); num.has_value()) {
        imm = num.value();
    } else {
        throw ChataError(ChataErrorType::Compiler, "Invalid immediate " + c.arg1, c.line, c.column);
    }
    if (imm >= -2048 && imm <= 2047) {
        c.inst_offset = fast_instr_search("jalr");
        c.arg3 = c.arg1;
        c.arg2 = "ra";
        c.arg1 = "ra";
        return {make_inst(c)};
    }
    // Case 2: imm is anything else, split into two instructions, the first assigning the upper 20 bits and the second the lower 12 bits
    throw ChataError(ChataErrorType::Assembler, "Not implemented yet");
}

chatavector<instruction> ret_instr(assembly_context& c) {
    c.inst_offset = fast_instr_search("jalr");
    c.arg1 = "zero";
    c.arg2 = "ra";
    c.arg3 = "0";
    return {make_inst(c)};
}

chatavector<instruction> nop_instr(assembly_context& c) {
    c.inst_offset = fast_instr_search("addi");
    c.arg1 = "zero";
    c.arg2 = "zero";
    c.arg3 = "0";
    return {make_inst(c)};
}

chatavector<instruction> fmvsx_instr(assembly_context& c) {
    c.inst_offset = fast_instr_search("fmv.w.x");
    return {make_inst(c)};
}

chatavector<instruction> fmvxs_instr(assembly_context& c) {
    c.inst_offset = fast_instr_search("fmv.x.w");
    return {make_inst(c)};
}

chatavector<instruction> rdinstret_instr(assembly_context& c) {
    c.inst_offset = fast_instr_search("csrrs");
    c.arg2 = "instret";
    c.arg3 = "zero";
    return {make_inst(c)};
}

chatavector<instruction> rdinstreth_instr(assembly_context& c) {
    c.inst_offset = fast_instr_search("csrrs");
    c.arg2 = "instreth";
    c.arg3 = "zero";
    return {make_inst(c)};
}

chatavector<instruction> rdcycle_instr(assembly_context& c) {
    c.inst_offset = fast_instr_search("csrrs");
    c.arg2 = "cycle";
    c.arg3 = "zero";
    return {make_inst(c)};
}

chatavector<instruction> rdcycleh_instr(assembly_context& c) {
    c.inst_offset = fast_instr_search("csrrs");
    c.arg2 = "cycleh";
    c.arg3 = "zero";
    return {make_inst(c)};
}

chatavector<instruction> rdtime_instr(assembly_context& c) {
    c.inst_offset = fast_instr_search("csrrs");
    c.arg2 = "time";
    c.arg3 = "zero";
    return {make_inst(c)};
}

chatavector<instruction> rdtimeh_instr(assembly_context& c) {
    c.inst_offset = fast_instr_search("csrrs");
    c.arg2 = "timeh";
    c.arg3 = "zero";
    return {make_inst(c)};
}

chatavector<instruction> csrr_instr(assembly_context& c) {
    c.inst_offset = fast_instr_search("csrrs");
    c.arg3 = "zero";
    return {make_inst(c)};
}

chatavector<instruction> csrw_instr(assembly_context& c) {
    c.inst_offset = fast_instr_search("csrrw");
    c.arg3 = c.arg2;
    c.arg2 = c.arg1;
    c.arg1 = "zero";
    return {make_inst(c)};
}

chatavector<instruction> csrs_instr(assembly_context& c) {
    c.inst_offset = fast_instr_search("csrrs");
    c.arg3 = c.arg2;
    c.arg2 = c.arg1;
    c.arg1 = "zero";
    return {make_inst(c)};
}

chatavector<instruction> csrc_instr(assembly_context& c) {
    c.inst_offset = fast_instr_search("csrrc");
    c.arg3 = c.arg2;
    c.arg2 = c.arg1;
    c.arg1 = "zero";
    return {make_inst(c)};
}

chatavector<instruction> csrwi_instr(assembly_context& c) {
    c.inst_offset = fast_instr_search("csrrwi");
    c.arg3 = c.arg2;
    c.arg2 = c.arg1;
    c.arg1 = "zero";
    return {make_inst(c)};
}

chatavector<instruction> csrsi_instr(assembly_context& c) {
    c.inst_offset = fast_instr_search("csrrsi");
    c.arg3 = c.arg2;
    c.arg2 = c.arg1;
    c.arg1 = "zero";
    return {make_inst(c)};
}

chatavector<instruction> csrci_instr(assembly_context& c) {
    c.inst_offset = fast_instr_search("csrrci");
    c.arg3 = c.arg2;
    c.arg2 = c.arg1;
    c.arg1 = "zero";
    return {make_inst(c)};
}

chatavector<instruction> frcsr_instr(assembly_context& c) {
    c.inst_offset = fast_instr_search("csrrs");
    c.arg2 = "fcsr";
    c.arg3 = "zero";
    return {make_inst(c)};
}

chatavector<instruction> fscsr_instr(assembly_context& c) {
    c.inst_offset = fast_instr_search("csrrw");
    if (!c.arg2.empty()) {
        c.arg3 = c.arg2;
        c.arg2 = "fcsr";
    } else {
        c.arg3 = c.arg1;
        c.arg2 = "fcsr";
        c.arg1 = "zero";
    }
    return {make_inst(c)};
}

chatavector<instruction> frrm_instr(assembly_context& c) {
    c.inst_offset = fast_instr_search("csrrs");
    c.arg2 = "frm";
    c.arg3 = "zero";
    return {make_inst(c)};
}

chatavector<instruction> fsrm_instr(assembly_context& c) {
    c.inst_offset = fast_instr_search("csrrw");
    if (!c.arg2.empty()) {
        c.arg3 = c.arg2;
        c.arg2 = "frm";
    } else {
        c.arg3 = c.arg1;
        c.arg2 = "frm";
        c.arg1 = "zero";
    }
    return {make_inst(c)};
}

chatavector<instruction> fsrmi_instr(assembly_context& c) {
    c.inst_offset = fast_instr_search("csrrwi");
    if (!c.arg2.empty()) {
        c.arg3 = c.arg2;
        c.arg2 = "frm";
    } else {
        c.arg3 = c.arg1;
        c.arg2 = "frm";
        c.arg1 = "zero";
    }
    return {make_inst(c)};
}

chatavector<instruction> frflags_instr(assembly_context& c) {
    c.inst_offset = fast_instr_search("csrrs");
    c.arg2 = "fflags";
    c.arg3 = "zero";
    return {make_inst(c)};
}

chatavector<instruction> fsflags_instr(assembly_context& c) {
    c.inst_offset = fast_instr_search("csrrw");
    if (!c.arg2.empty()) {
        c.arg3 = c.arg2;
        c.arg2 = "fflags";
    } else {
        c.arg3 = c.arg1;
        c.arg2 = "fflags";
        c.arg1 = "zero";
    }
    return {make_inst(c)};
}

chatavector<instruction> fsflagsi_instr(assembly_context& c) {
    c.inst_offset = fast_instr_search("csrrwi");
    if (!c.arg2.empty()) {
        c.arg3 = c.arg2;
        c.arg2 = "fflags";
    } else {
        c.arg3 = c.arg1;
        c.arg2 = "fflags";
        c.arg1 = "zero";
    }
    return {make_inst(c)};
}

} // namespace libchata_internal