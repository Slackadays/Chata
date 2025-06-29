// SPDX-License-Identifier: MPL-2.0
#include "assembler.hpp"
#include "instructions.hpp"
#include "ultrassembler.hpp"

namespace ultrassembler_internal {

void li_instr(assembly_context& c) { // li rd, imm -> lui rd, imm[31:12]; addi rd, rd, imm[11:0]
                                     // Case 1: imm is a 12-bit signed integer
    int imm;
    if (auto num = to_num<int>(c.arg2); num.has_value()) {
        imm = num.value();
    } else {
        throw UltraError(UltraErrorType::Compiler, "Invalid immediate " + c.arg2, c.line, c.column);
    }
    if (imm >= -2048 && imm <= 2047) {
        c.inst_offset = fast_instr_search("addi");
        c.arg2 = "zero";
        c.arg3 = to_ultrastring(imm);
        make_inst(c);
        return;
    }
    // Case 2: imm is anything else, split into two instructions, the first assigning the upper 20 bits and the second the lower 12 bits
    c.inst_offset = fast_instr_search("lui");
    c.arg2 = to_ultrastring(imm >> 12);
    make_inst(c);
    c.inst_offset = fast_instr_search("addi");
    c.arg2 = c.arg1;
    c.arg3 = to_ultrastring(imm & 0xFFF);
    make_inst(c);
}

void la_instr(assembly_context& c) { // la rd, imm -> auipc rd, imm[31:12]; addi rd, rd, imm[11:0]
                                     // Case 1: imm is a 12-bit signed integer
    int imm;
    if (auto num = to_num<int>(c.arg2); num.has_value()) {
        imm = num.value();
    } else {
        throw UltraError(UltraErrorType::Compiler, "Invalid immediate " + c.arg2, c.line, c.column);
    }
    if (imm >= -2048 && imm <= 2047) {
        c.inst_offset = fast_instr_search("addi");
        c.arg2 = "zero";
        c.arg3 = to_ultrastring(imm);
        make_inst(c);
        return;
    }
    // Case 2: imm is anything else, split into two instructions, the first assigning the upper 20 bits and the second the lower 12 bits
    c.inst_offset = fast_instr_search("auipc");
    c.arg2 = to_ultrastring(imm >> 12);
    make_inst(c);
    c.inst_offset = fast_instr_search("addi");
    c.arg2 = c.arg1;
    c.arg3 = to_ultrastring(imm & 0xFFF);
    make_inst(c);
}

void mv_instr(assembly_context& c) { // mv rd, rs -> addi rd, rs, 0
    c.inst_offset = fast_instr_search("addi");
    c.arg3 = "0";
    make_inst(c);
}

void not_instr(assembly_context& c) { // not rd, rs -> xori rd, rs, -1
    c.inst_offset = fast_instr_search("xori");
    c.arg3 = "-1";
    make_inst(c);
}

void neg_instr(assembly_context& c) { // neg rd, rs -> sub rd, zero, rs
    c.inst_offset = fast_instr_search("sub");
    c.arg3 = c.arg2;
    c.arg2 = "zero";
    make_inst(c);
}

void negw_instr(assembly_context& c) { // negw rd, rs -> subw rd, zero, rs
    c.inst_offset = fast_instr_search("subw");
    c.arg3 = c.arg2;
    c.arg2 = "zero";
    make_inst(c);
}

void sext_w_instr(assembly_context& c) { // sext.w rd, rs -> addiw rd, rs, 0
    c.inst_offset = fast_instr_search("addiw");
    c.arg3 = "0";
    make_inst(c);
}

void zext_b_instr(assembly_context& c) { // zext.b rd, rs -> andi rd, rs, 255
    c.inst_offset = fast_instr_search("andi");
    c.arg3 = "255";
    make_inst(c);
}

void seqz_instr(assembly_context& c) { // seqz rd, rs -> sltiu rd, rs, 1
    c.inst_offset = fast_instr_search("sltiu");
    c.arg3 = "1";
    make_inst(c);
}

void snez_instr(assembly_context& c) { // snez rd, rs -> sltu rd, zero, rs
    c.inst_offset = fast_instr_search("sltu");
    c.arg3 = c.arg2;
    c.arg2 = "zero";
    make_inst(c);
}

void sltz_instr(assembly_context& c) { // sltz rd, rs -> slt rd, rs, zero
    c.inst_offset = fast_instr_search("slt");
    c.arg3 = "zero";
    make_inst(c);
}

void sgtz_instr(assembly_context& c) { // sgtz rd, rs -> slt rd, zero, rs
    c.inst_offset = fast_instr_search("slt");
    c.arg3 = c.arg2;
    c.arg2 = "zero";
    make_inst(c);
}

void fmv_s_instr(assembly_context& c) { // fmv.s rd, rs -> fsgnj.s rd, rs, rs
    c.inst_offset = fast_instr_search("fsgnj.s");
    c.arg3 = c.arg2;
    make_inst(c);
}

void fabs_s_instr(assembly_context& c) { // fabs.s rd, rs -> fsgnjx.s rd, rs, rs
    c.inst_offset = fast_instr_search("fsgnjx.s");
    c.arg3 = c.arg2;
    make_inst(c);
}

void fneg_s_instr(assembly_context& c) { // fneg.s rd, rs -> fsgnjn.s rd, rs, rs
    c.inst_offset = fast_instr_search("fsgnjn.s");
    c.arg3 = c.arg2;
    make_inst(c);
}

void fmv_d_instr(assembly_context& c) { // fmv.d rd, rs -> fsgnj.d rd, rs, rs
    c.inst_offset = fast_instr_search("fsgnj.d");
    c.arg3 = c.arg2;
    make_inst(c);
}

void fabs_d_instr(assembly_context& c) { // fabs.d rd, rs -> fsgnjx.d rd, rs, rs
    c.inst_offset = fast_instr_search("fsgnjx.d");
    c.arg3 = c.arg2;
    make_inst(c);
}

void fneg_d_instr(assembly_context& c) { // fneg.d rd, rs -> fsgnjn.d rd, rs, rs
    c.inst_offset = fast_instr_search("fsgnjn.d");
    c.arg3 = c.arg2;
    make_inst(c);
}

void bgt_instr(assembly_context& c) { // bgt rs1, rs2, label|imm -> blt rs2, rs1, label|imm
    c.inst_offset = fast_instr_search("blt");
    std::swap(c.arg1, c.arg2);
    make_inst(c);
}

void ble_instr(assembly_context& c) { // ble rs1, rs2, label|imm -> bge rs2, rs1, label|imm
    c.inst_offset = fast_instr_search("bge");
    std::swap(c.arg1, c.arg2);
    make_inst(c);
}

void bgtu_instr(assembly_context& c) { // bgtu rs1, rs2, label|imm -> bltu rs2, rs1, label|imm
    c.inst_offset = fast_instr_search("bltu");
    std::swap(c.arg1, c.arg2);
    make_inst(c);
}

void bleu_instr(assembly_context& c) { // bleu rs1, rs2, label|imm -> bgeu rs2, rs1, label|imm
    c.inst_offset = fast_instr_search("bgeu");
    std::swap(c.arg1, c.arg2);
    make_inst(c);
}

void beqz_instr(assembly_context& c) { // beqz rs, label|imm -> beq rs, zero, label|imm
    c.inst_offset = fast_instr_search("beq");
    c.arg3 = c.arg2;
    c.arg2 = "zero";
    make_inst(c);
}

void bnez_instr(assembly_context& c) { // bnez rs, label|imm -> bne rs, zero, label|imm
    c.inst_offset = fast_instr_search("bne");
    c.arg3 = c.arg2;
    c.arg2 = "zero";
    make_inst(c);
}

void bgez_instr(assembly_context& c) { // bgez rs, label|imm -> bge rs, zero, label|imm
    c.inst_offset = fast_instr_search("bge");
    c.arg3 = c.arg2;
    c.arg2 = "zero";
    make_inst(c);
}

void blez_instr(assembly_context& c) { // blez rs, label|imm -> bge zero, rs, label|imm
    c.inst_offset = fast_instr_search("bge");
    c.arg3 = c.arg2;
    c.arg2 = c.arg1;
    c.arg1 = "zero";
    make_inst(c);
}

void bgtz_instr(assembly_context& c) { // bgtz rs, label|imm -> blt zero, rs, label|imm
    c.inst_offset = fast_instr_search("blt");
    c.arg3 = c.arg2;
    c.arg2 = c.arg1;
    c.arg1 = "zero";
    make_inst(c);
}

void j_instr(assembly_context& c) {
    c.inst_offset = fast_instr_search("jal");
    c.arg2 = c.arg1;
    c.arg1 = "zero";
    make_inst(c);
}

void call_instr(assembly_context& c) {
    // Case 1: imm is a 12-bit signed integer
    int imm;
    if (auto num = to_num<int>(c.arg1); num.has_value()) {
        imm = num.value();
    } else {
        throw UltraError(UltraErrorType::Compiler, "Invalid immediate " + c.arg1, c.line, c.column);
    }
    if (imm >= -2048 && imm <= 2047) {
        c.inst_offset = fast_instr_search("jalr");
        c.arg3 = c.arg1;
        c.arg2 = "ra";
        c.arg1 = "ra";
        make_inst(c);
        return;
    }
    // Case 2: imm is anything else, split into two instructions, the first assigning the upper 20 bits and the second the lower 12 bits
    throw UltraError(UltraErrorType::Assembler, "Not implemented yet");
}

void ret_instr(assembly_context& c) {
    c.inst_offset = fast_instr_search("jalr");
    c.arg1 = "zero";
    c.arg2 = "ra";
    c.arg3 = "0";
    make_inst(c);
}

void nop_instr(assembly_context& c) {
    c.inst_offset = fast_instr_search("addi");
    c.arg1 = "zero";
    c.arg2 = "zero";
    c.arg3 = "0";
    make_inst(c);
}

void vfneg_v_instr(assembly_context& c) { // vfneg.v vd, vs -> vfsgnjn.vv vd, vs, vs
    c.inst_offset = fast_instr_search("vfsgnjn.vv");
    c.arg3 = c.arg2;
    make_inst(c);
}

void th_vfneg_v_instr(assembly_context& c) { // th.vfneg.v vd, vs -> th.vfsgnjn.vv vd, vs, vs
    c.inst_offset = fast_instr_search("th.vfsgnjn.vv");
    c.arg3 = c.arg2;
    make_inst(c);
}

void vfabs_v_instr(assembly_context& c) { // vfabs.v vd, vs -> vfsgnjx.vv vd, vs, vs
    c.inst_offset = fast_instr_search("vfsgnjx.vv");
    c.arg3 = c.arg2;
    make_inst(c);
}

void th_vfabs_v_instr(assembly_context& c) { // th.vfabs.v vd, vs -> th.vfsgnjx.vv vd, vs, vs
    c.inst_offset = fast_instr_search("th.vfsgnjx.vv");
    c.arg3 = c.arg2;
    make_inst(c);
}

void vmclr_m_instr(assembly_context& c) { // vmclr.m vd -> vmxor.mm vd, vd, vd
    c.inst_offset = fast_instr_search("vmxor.mm");
    c.arg2 = c.arg1;
    c.arg3 = c.arg2;
    make_inst(c);
}

void th_vmclr_m_instr(assembly_context& c) { // th.vmclr.m vd -> th.vmxor.mm vd, vd, vd
    c.inst_offset = fast_instr_search("th.vmxor.mm");
    c.arg2 = c.arg1;
    c.arg3 = c.arg2;
    make_inst(c);
}

void vmfge_vv_instr(assembly_context& c) { // vmfge.vv vd, va, vb, vm -> vmfle.vv vd, vb, va, vm
    c.inst_offset = fast_instr_search("vmfle.vv");
    std::swap(c.arg2, c.arg3);
    make_inst(c);
}

void th_vmfge_vv_instr(assembly_context& c) { // th.vmfge.vv vd, va, vb, vm -> th.vmfle.vv vd, vb, va, vm
    c.inst_offset = fast_instr_search("th.vmfle.vv");
    std::swap(c.arg2, c.arg3);
    make_inst(c);
}

void vmfgt_vv_instr(assembly_context& c) { // vmfgt.vv vd, va, vb, vm -> vmflt.vv vd, vb, va, vm
    c.inst_offset = fast_instr_search("vmflt.vv");
    std::swap(c.arg2, c.arg3);
    make_inst(c);
}

void th_vmfgt_vv_instr(assembly_context& c) { // th.vmfgt.vv vd, va, vb, vm -> th.vmflt.vv vd, vb, va, vm
    c.inst_offset = fast_instr_search("th.vmflt.vv");
    std::swap(c.arg2, c.arg3);
    make_inst(c);
}

void vmmv_m_instr(assembly_context& c) { // vmmv.m vd, vs -> vmand.mm vd, vs, vs
    c.inst_offset = fast_instr_search("vmand.mm");
    c.arg3 = c.arg2;
    make_inst(c);
}

void th_vmcpy_m_instr(assembly_context& c) { // th.vmcpy.m vd, vs -> th.vmand.mm vd, vs, vs
    c.inst_offset = fast_instr_search("th.vmand.mm");
    c.arg3 = c.arg2;
    make_inst(c);
}

void th_vmmv_m_instr(assembly_context& c) { // th.vmmv.m vd, vs -> th.vmand.mm vd, vs, vs
    c.inst_offset = fast_instr_search("th.vmand.mm");
    c.arg3 = c.arg2;
    make_inst(c);
}

void vmnot_m_instr(assembly_context& c) { // vmnot.m vd, vs -> vmnand.mm vd, vs, vs
    c.inst_offset = fast_instr_search("vmnand.mm");
    c.arg3 = c.arg2;
    make_inst(c);
}

void th_vmnot_m_instr(assembly_context& c) { // th.vmnot.m vd, vs -> th.vmnand.mm vd, vs, vs
    c.inst_offset = fast_instr_search("th.vmnand.mm");
    c.arg3 = c.arg2;
    make_inst(c);
}

void vmset_m_instr(assembly_context& c) { // vmset.m vd -> vmxnor.mm vd, vd, vd
    c.inst_offset = fast_instr_search("vmxnor.mm");
    c.arg2 = c.arg1;
    c.arg3 = c.arg2;
    make_inst(c);
}

void th_vmset_m_instr(assembly_context& c) { // th.vmset.m vd -> th.vmxnor.mm vd, vd, vd
    c.inst_offset = fast_instr_search("th.vmxnor.mm");
    c.arg2 = c.arg1;
    c.arg3 = c.arg2;
    make_inst(c);
}

void vmsge_vi_instr(assembly_context& c) { // vmsge.vi vd, va, i, vm -> vmsgt.vi vd, va, i-1, vm
    c.inst_offset = fast_instr_search("vmsgt.vi");
    c.arg3 = to_ultrastring(to_num<int>(c.arg3).value() - 1);
    make_inst(c);
}

void th_vmsge_vi_instr(assembly_context& c) { // th.vmsge.vi vd, va, i, vm -> th.vmsgt.vi vd, va, i-1, vm
    c.inst_offset = fast_instr_search("th.vmsgt.vi");
    c.arg3 = to_ultrastring(to_num<int>(c.arg3).value() - 1);
    make_inst(c);
}

void vmsgeu_vi_instr(assembly_context& c) { // vmsgeu.vi vd, va, i, vm -> vmsgtu.vi vd, va, i-1, vm
    c.inst_offset = fast_instr_search("vmsgtu.vi");
    c.arg3 = to_ultrastring(to_num<int>(c.arg3).value() - 1);
    make_inst(c);
}

void th_vmsgeu_vi_instr(assembly_context& c) { // th.vmsgeu.vi vd, va, i, vm -> th.vmsgtu.vi vd, va, i-1, vm
    c.inst_offset = fast_instr_search("th.vmsgtu.vi");
    c.arg3 = to_ultrastring(to_num<int>(c.arg3).value() - 1);
    make_inst(c);
}

void vmsge_vv_instr(assembly_context& c) { // vmsge.vv vd, va, vb, vm -> vmsle.vv vd, vb, va, vm
    c.inst_offset = fast_instr_search("vmsle.vv");
    std::swap(c.arg2, c.arg3);
    make_inst(c);
}

void th_vmsge_vv_instr(assembly_context& c) { // th.vmsge.vv vd, va, vb, vm -> th.vmsle.vv vd, vb, va, vm
    c.inst_offset = fast_instr_search("th.vmsle.vv");
    std::swap(c.arg2, c.arg3);
    make_inst(c);
}

void vmsgeu_vv_instr(assembly_context& c) { // vmsgeu.vv vd, va, vb, vm -> vmsleu.vv vd, vb, va, vm
    c.inst_offset = fast_instr_search("vmsleu.vv");
    std::swap(c.arg2, c.arg3);
    make_inst(c);
}

void th_vmsgeu_vv_instr(assembly_context& c) { // th.vmsgeu.vv vd, va, vb, vm -> th.vmsleu.vv vd, vb, va, vm
    c.inst_offset = fast_instr_search("th.vmsleu.vv");
    std::swap(c.arg2, c.arg3);
    make_inst(c);
}

void vmsgt_vv_instr(assembly_context& c) { // vmsgt.vv vd, va, vb, vm -> vmslt.vv vd, vb, va, vm
    c.inst_offset = fast_instr_search("vmslt.vv");
    std::swap(c.arg2, c.arg3);
    make_inst(c);
}

void th_vmsgt_vv_instr(assembly_context& c) { // th.vmsgt.vv vd, va, vb, vm -> th.vmslt.vv vd, vb, va, vm
    c.inst_offset = fast_instr_search("th.vmslt.vv");
    std::swap(c.arg2, c.arg3);
    make_inst(c);
}

void vmsgtu_vv_instr(assembly_context& c) { // vmsgtu.vv vd, va, vb, vm -> vmsltu.vv vd, vb, va, vm
    c.inst_offset = fast_instr_search("vmsltu.vv");
    std::swap(c.arg2, c.arg3);
    make_inst(c);
}

void th_vmsgtu_vv_instr(assembly_context& c) { // th.vmsgtu.vv vd, va, vb, vm -> th.vmsltu.vv vd, vb, va, vm
    c.inst_offset = fast_instr_search("th.vmsltu.vv");
    std::swap(c.arg2, c.arg3);
    make_inst(c);
}

void vmslt_vi_instr(assembly_context& c) { // vmslt.vi vd, va, i, vm -> vmsle.vi vd, va, i-1, vm
    c.inst_offset = fast_instr_search("vmsle.vi");
    c.arg3 = to_ultrastring(to_num<int>(c.arg3).value() - 1);
    make_inst(c);
}

void th_vmslt_vi_instr(assembly_context& c) { // th.vmslt.vi vd, va, i, vm -> th.vmsle.vi vd, va, i-1, vm
    c.inst_offset = fast_instr_search("th.vmsle.vi");
    c.arg3 = to_ultrastring(to_num<int>(c.arg3).value() - 1);
    make_inst(c);
}

void vmsltu_vi_instr(assembly_context& c) { // vmsltu.vi vd, va, i, vm -> vmsleu.vi vd, va, i-1, vm
    c.inst_offset = fast_instr_search("vmsleu.vi");
    c.arg3 = to_ultrastring(to_num<int>(c.arg3).value() - 1);
    make_inst(c);
}

void th_vmsltu_vi_instr(assembly_context& c) { // th.vmsltu.vi vd, va, i, vm -> th.vmsleu.vi vd, va, i-1, vm
    c.inst_offset = fast_instr_search("th.vmsleu.vi");
    c.arg3 = to_ultrastring(to_num<int>(c.arg3).value() - 1);
    make_inst(c);
}

void vneg_v_instr(assembly_context& c) { // vneg.v vd, vs -> vrsub.vx vd, vs, zero
    c.inst_offset = fast_instr_search("vrsub.vx");
    c.arg3 = "zero";
    make_inst(c);
}

void th_vneg_v_instr(assembly_context& c) { // th.vneg.v vd, vs -> th.vrsub.vx vd, vs, zero
    c.inst_offset = fast_instr_search("th.vrsub.vx");
    c.arg3 = "zero";
    make_inst(c);
}

void vnot_v_instr(assembly_context& c) { // vnot.v vd, vs, vm -> vxor.vi vd, vs, -1, vm
    c.inst_offset = fast_instr_search("vxor.vi");
    c.arg4 = c.arg3;
    c.arg3 = "-1";
    make_inst(c);
}

void th_vnot_v_instr(assembly_context& c) { // th.vnot.v vd, vs, vm -> th.vxor.vi vd, vs, -1, vm
    c.inst_offset = fast_instr_search("th.vxor.vi");
    c.arg4 = c.arg3;
    c.arg3 = "-1";
    make_inst(c);
}

void vncvt_x_x_w_instr(assembly_context& c) { // vncvt.x.x.w vd, vs, vm -> vnsrl.wx vd, vs, zero, vm
    c.inst_offset = fast_instr_search("vnsrl.wx");
    c.arg4 = c.arg3;
    c.arg3 = "zero";
    make_inst(c);
}

void th_vncvt_x_x_v_instr(assembly_context& c) { // th.vncvt.x.x.v vd, vs, vm -> th.vnsrl.vx vd, vs, zero, vm
    c.inst_offset = fast_instr_search("th.vnsrl.vx");
    c.arg4 = c.arg3;
    c.arg3 = "zero";
    make_inst(c);
}

void vwcvt_x_x_v_instr(assembly_context& c) { // vwcvt.x.x.v vd, vs, vm -> vwadd.vx vd, vs, zero, vm
    c.inst_offset = fast_instr_search("vwadd.vx");
    c.arg4 = c.arg3;
    c.arg3 = "zero";
    make_inst(c);
}

void th_vwcvt_x_x_v_instr(assembly_context& c) { // th.vwcvt.x.x.v vd, vs, vm -> th.vwadd.vx vd, vs, zero, vm
    c.inst_offset = fast_instr_search("th.vwadd.vx");
    c.arg4 = c.arg3;
    c.arg3 = "zero";
    make_inst(c);
}

void vwcvtu_x_x_v_instr(assembly_context& c) { // vwcvtu.x.x.v vd, vs, vm -> vwaddu.vx vd, vs, zero, vm
    c.inst_offset = fast_instr_search("vwaddu.vx");
    c.arg4 = c.arg3;
    c.arg3 = "zero";
    make_inst(c);
}

void th_vwcvtu_x_x_v_instr(assembly_context& c) { // th.vwcvtu.x.x.v vd, vs, vm -> th.vwaddu.vx vd, vs, zero, vm
    c.inst_offset = fast_instr_search("th.vwaddu.vx");
    c.arg4 = c.arg3;
    c.arg3 = "zero";
    make_inst(c);
}

void th_vmsge_vx_instr(assembly_context& c) { // th.vmsge.vx vd, va, vb, vm -> th.vmsle.vv vd, vb, va, vm
    c.inst_offset = fast_instr_search("th.vmsle.vv");
    std::swap(c.arg2, c.arg3);
    make_inst(c);
}

void th_vmsgeu_vx_instr(assembly_context& c) { // th.vmsgeu.vx vd, va, vb, vm -> th.vmsleu.vv vd, vb, va, vm
    c.inst_offset = fast_instr_search("th.vmsleu.vv");
    std::swap(c.arg2, c.arg3);
    make_inst(c);
}

void th_vmv_x_s_instr(assembly_context& c) { // th.vmv.x.s rd, vs2 -> th.vext.x.v rd, vs2, zero
    c.inst_offset = fast_instr_search("th.vext.x.v");
    c.arg3 = "zero";
    make_inst(c);
}

void vl1r_v_instr(assembly_context& c) { // vl1r.v v3, zero -> vl1re8.v v3, zero
    c.inst_offset = fast_instr_search("vl1re8.v");
    make_inst(c);
}

void vl2r_v_instr(assembly_context& c) { // vl2r.v v2, zero -> vl2re8.v v2, zero
    c.inst_offset = fast_instr_search("vl2re8.v");
    make_inst(c);
}

void vl4r_v_instr(assembly_context& c) { // vl4r.v v4, zero -> vl4re8.v v4, zero
    c.inst_offset = fast_instr_search("vl4re8.v");
    make_inst(c);
}

void vl8r_v_instr(assembly_context& c) { // vl8r.v v8, zero -> vl8re8.v v8, zero
    c.inst_offset = fast_instr_search("vl8re8.v");
    make_inst(c);
}

void fmv_s_x_instr(assembly_context& c) {
    c.inst_offset = fast_instr_search("fmv.w.x");
    make_inst(c);
}

void fmv_x_s_instr(assembly_context& c) {
    c.inst_offset = fast_instr_search("fmv.x.w");
    make_inst(c);
}

void rdinstret_instr(assembly_context& c) { // rdinstret rd -> csrrs rd, instret, zero
    c.inst_offset = fast_instr_search("csrrs");
    c.arg2 = "instret";
    c.arg3 = "zero";
    make_inst(c);
}

void rdinstreth_instr(assembly_context& c) { // rdinstreth rd -> csrrs rd, instreth, zero
    c.inst_offset = fast_instr_search("csrrs");
    c.arg2 = "instreth";
    c.arg3 = "zero";
    make_inst(c);
}

void rdcycle_instr(assembly_context& c) { // rdcycle rd -> csrrs rd, cycle, zero
    c.inst_offset = fast_instr_search("csrrs");
    c.arg2 = "cycle";
    c.arg3 = "zero";
    make_inst(c);
}

void rdcycleh_instr(assembly_context& c) { // rdcycleh rd -> csrrs rd, cycleh, zero
    c.inst_offset = fast_instr_search("csrrs");
    c.arg2 = "cycleh";
    c.arg3 = "zero";
    make_inst(c);
}

void rdtime_instr(assembly_context& c) { // rdtime rd -> csrrs rd, time, zero
    c.inst_offset = fast_instr_search("csrrs");
    c.arg2 = "time";
    c.arg3 = "zero";
    make_inst(c);
}

void rdtimeh_instr(assembly_context& c) { // rdtimeh rd -> csrrs rd, timeh, zero
    c.inst_offset = fast_instr_search("csrrs");
    c.arg2 = "timeh";
    c.arg3 = "zero";
    make_inst(c);
}

void csrr_instr(assembly_context& c) { // csrr rd, csr -> csrrs rd, csr, zero
    c.inst_offset = fast_instr_search("csrrs");
    c.arg3 = "zero";
    make_inst(c);
}

void csrw_instr(assembly_context& c) { // csrw csr, rs -> csrrw zero, csr, rs
    c.inst_offset = fast_instr_search("csrrw");
    c.arg3 = c.arg2;
    c.arg2 = c.arg1;
    c.arg1 = "zero";
    make_inst(c);
}

void csrs_instr(assembly_context& c) { // csrs csr, rs -> csrrs zero, csr, rs
    c.inst_offset = fast_instr_search("csrrs");
    c.arg3 = c.arg2;
    c.arg2 = c.arg1;
    c.arg1 = "zero";
    make_inst(c);
}

void csrc_instr(assembly_context& c) { // csrc csr, rs -> csrrc zero, csr, rs
    c.inst_offset = fast_instr_search("csrrc");
    c.arg3 = c.arg2;
    c.arg2 = c.arg1;
    c.arg1 = "zero";
    make_inst(c);
}

void csrwi_instr(assembly_context& c) { // csrwi csr, imm -> csrrwi zero, csr, imm
    c.inst_offset = fast_instr_search("csrrwi");
    c.arg3 = c.arg2;
    c.arg2 = c.arg1;
    c.arg1 = "zero";
    make_inst(c);
}

void csrsi_instr(assembly_context& c) { // csrsi csr, imm -> csrrsi zero, csr, imm
    c.inst_offset = fast_instr_search("csrrsi");
    c.arg3 = c.arg2;
    c.arg2 = c.arg1;
    c.arg1 = "zero";
    make_inst(c);
}

void csrci_instr(assembly_context& c) { // csrci csr, imm -> csrrci zero, csr, imm
    c.inst_offset = fast_instr_search("csrrci");
    c.arg3 = c.arg2;
    c.arg2 = c.arg1;
    c.arg1 = "zero";
    make_inst(c);
}

void frcsr_instr(assembly_context& c) { // frcsr rd -> csrrs rd, fcsr, zero
    c.inst_offset = fast_instr_search("csrrs");
    c.arg2 = "fcsr";
    c.arg3 = "zero";
    make_inst(c);
}

void fscsr_instr(assembly_context& c) { // fscsr rd, rs -> csrrw rd, fcsr, rs or fscsr rs -> csrrw zero, fcsr, rs
    c.inst_offset = fast_instr_search("csrrw");
    if (!c.arg2.empty()) {
        c.arg3 = c.arg2;
        c.arg2 = "fcsr";
    } else {
        c.arg3 = c.arg1;
        c.arg2 = "fcsr";
        c.arg1 = "zero";
    }
    make_inst(c);
}

void frrm_instr(assembly_context& c) { // frrm rd -> csrrs rd, frm, zero
    c.inst_offset = fast_instr_search("csrrs");
    c.arg2 = "frm";
    c.arg3 = "zero";
    make_inst(c);
}

void fsrm_instr(assembly_context& c) { // fsrm rd, rs -> csrrw rd, frm, rs or fsrm rs -> csrrw zero, frm, rs
    c.inst_offset = fast_instr_search("csrrw");
    if (!c.arg2.empty()) {
        c.arg3 = c.arg2;
        c.arg2 = "frm";
    } else {
        c.arg3 = c.arg1;
        c.arg2 = "frm";
        c.arg1 = "zero";
    }
    make_inst(c);
}

void fsrmi_instr(assembly_context& c) { // fsrmi imm -> csrrwi zero, frm, imm or fsrmi rd, imm -> csrrwi rd, frm, imm
    c.inst_offset = fast_instr_search("csrrwi");
    if (!c.arg2.empty()) {
        c.arg3 = c.arg2;
        c.arg2 = "frm";
    } else {
        c.arg3 = c.arg1;
        c.arg2 = "frm";
        c.arg1 = "zero";
    }
    make_inst(c);
}

void frflags_instr(assembly_context& c) { // frflags rd -> csrrs rd, fflags, zero
    c.inst_offset = fast_instr_search("csrrs");
    c.arg2 = "fflags";
    c.arg3 = "zero";
    make_inst(c);
}

void fsflags_instr(assembly_context& c) { // fsflags rd, rs -> csrrw rd, fflags, rs or fsflags rs -> csrrw zero, fflags, rs
    c.inst_offset = fast_instr_search("csrrw");
    if (!c.arg2.empty()) {
        c.arg3 = c.arg2;
        c.arg2 = "fflags";
    } else {
        c.arg3 = c.arg1;
        c.arg2 = "fflags";
        c.arg1 = "zero";
    }
    make_inst(c);
}

void fsflagsi_instr(assembly_context& c) { // fsflagsi imm -> csrrwi zero, fflags, imm or fsflagsi rd, imm -> csrrwi rd, fflags, imm
    c.inst_offset = fast_instr_search("csrrwi");
    if (!c.arg2.empty()) {
        c.arg3 = c.arg2;
        c.arg2 = "fflags";
    } else {
        c.arg3 = c.arg1;
        c.arg2 = "fflags";
        c.arg1 = "zero";
    }
    make_inst(c);
}

void ntl_p1_instr(assembly_context& c) { // ntl.p1 -> add x0, x0, x2
    c.inst_offset = fast_instr_search("add");
    c.arg1 = "zero";
    c.arg2 = "zero";
    c.arg3 = "x2";
    make_inst(c);
}

void ntl_pall_instr(assembly_context& c) { // ntl.pall -> add x0, x0, x3
    c.inst_offset = fast_instr_search("add");
    c.arg1 = "zero";
    c.arg2 = "zero";
    c.arg3 = "x3";
    make_inst(c);
}

void ntl_s1_instr(assembly_context& c) { // ntl.s1 -> add x0, x0, x4
    c.inst_offset = fast_instr_search("add");
    c.arg1 = "zero";
    c.arg2 = "zero";
    c.arg3 = "x4";
    make_inst(c);
}

void ntl_all_instr(assembly_context& c) { // ntl.all -> add x0, x0, x5
    c.inst_offset = fast_instr_search("add");
    c.arg1 = "zero";
    c.arg2 = "zero";
    c.arg3 = "x5";
    make_inst(c);
}

} // namespace ultrassembler_internal