// SPDX-License-Identifier: MPL-2.0
#include "../libchata.hpp"
#include "assembler.hpp"

namespace libchata_internal {

extern bool make_inst_from_pseudoinst(assembly_context& c);

void li_instr(assembly_context& c);
void la_instr(assembly_context& c);
void mv_instr(assembly_context& c);
void not_instr(assembly_context& c);
void neg_instr(assembly_context& c);
void negw_instr(assembly_context& c);
void sext_w_instr(assembly_context& c);
void zext_b_instr(assembly_context& c);
void seqz_instr(assembly_context& c);
void snez_instr(assembly_context& c);
void sltz_instr(assembly_context& c);
void sgtz_instr(assembly_context& c);
void fmv_s_instr(assembly_context& c);
void fabs_s_instr(assembly_context& c);
void fneg_s_instr(assembly_context& c);
void fmv_d_instr(assembly_context& c);
void fabs_d_instr(assembly_context& c);
void fneg_d_instr(assembly_context& c);
void bgt_instr(assembly_context& c);
void ble_instr(assembly_context& c);
void bgtu_instr(assembly_context& c);
void bleu_instr(assembly_context& c);
void beqz_instr(assembly_context& c);
void bnez_instr(assembly_context& c);
void bgez_instr(assembly_context& c);
void blez_instr(assembly_context& c);
void bgtz_instr(assembly_context& c);
void j_instr(assembly_context& c);
void call_instr(assembly_context& c);
void ret_instr(assembly_context& c);
void nop_instr(assembly_context& c);
void vfneg_v_instr(assembly_context& c);
void vfabs_v_instr(assembly_context& c);
void vmclr_m_instr(assembly_context& c);
void vmfge_vv_instr(assembly_context& c);
void vmfgt_vv_instr(assembly_context& c);
void vmmv_m_instr(assembly_context& c);
void vmnot_m_instr(assembly_context& c);
void vmset_m_instr(assembly_context& c);
void vmsge_vi_instr(assembly_context& c);
void vmsgeu_vi_instr(assembly_context& c);
void vmsge_vv_instr(assembly_context& c);
void vmsgeu_vv_instr(assembly_context& c);
void vmsgt_vv_instr(assembly_context& c);
void vmsgtu_vv_instr(assembly_context& c);
void vmslt_vi_instr(assembly_context& c);
void vmsltu_vi_instr(assembly_context& c);
void vneg_v_instr(assembly_context& c);
void vnot_v_instr(assembly_context& c);
void vncvt_x_x_w_instr(assembly_context& c);
void vwcvt_x_x_v_instr(assembly_context& c);
void vwcvtu_x_x_v_instr(assembly_context& c);
void vl1r_v_instr(assembly_context& c);
void vl2r_v_instr(assembly_context& c);
void vl4r_v_instr(assembly_context& c);
void vl8r_v_instr(assembly_context& c);
void fmvsx_instr(assembly_context& c);
void fmvxs_instr(assembly_context& c);
void rdinstret_instr(assembly_context& c);
void rdinstreth_instr(assembly_context& c);
void rdcycle_instr(assembly_context& c);
void rdcycleh_instr(assembly_context& c);
void rdtime_instr(assembly_context& c);
void rdtimeh_instr(assembly_context& c);
void csrr_instr(assembly_context& c);
void csrw_instr(assembly_context& c);
void csrs_instr(assembly_context& c);
void csrc_instr(assembly_context& c);
void csrwi_instr(assembly_context& c);
void csrsi_instr(assembly_context& c);
void csrci_instr(assembly_context& c);
void frcsr_instr(assembly_context& c);
void fscsr_instr(assembly_context& c);
void frrm_instr(assembly_context& c);
void fsrm_instr(assembly_context& c);
void fsrmi_instr(assembly_context& c);
void frflags_instr(assembly_context& c);
void fsflags_instr(assembly_context& c);
void fsflagsi_instr(assembly_context& c);
void ntl_p1_instr(assembly_context& c);
void ntl_pall_instr(assembly_context& c);
void ntl_s1_instr(assembly_context& c);
void ntl_all_instr(assembly_context& c);

} // namespace libchata_internal