// SPDX-License-Identifier: MPL-2.0
// The generate_pseudoinstruction_converter.py script automatically generated this code. DO NOT MODIFY!
#include "../pseudoinstructions.hpp"
#include "../ultrassembler.hpp"

namespace ultrassembler_internal {

bool make_inst_from_pseudoinst(assembly_context& c) {
    if (c.inst.size() < 1) return false;
    if (c.inst[0] == 'b') {
        if (c.inst.size() < 2) return false;
        if (c.inst[1] == 'e') {
            if (c.inst.size() < 3) return false;
            if (c.inst[2] == 'q') {
                if (c.inst.size() < 4) return false;
                if (c.inst[3] == 'z') {
                    if (c.inst.size() < 5) {
                        beqz_instr(c);
                        return true;
                    }
                }
            }
        }
        if (c.inst[1] == 'g') {
            if (c.inst.size() < 3) return false;
            if (c.inst[2] == 'e') {
                if (c.inst.size() < 4) return false;
                if (c.inst[3] == 'z') {
                    if (c.inst.size() < 5) {
                        bgez_instr(c);
                        return true;
                    }
                }
            }
            if (c.inst[2] == 't') {
                if (c.inst.size() < 4) {
                    bgt_instr(c);
                    return true;
                }
                if (c.inst[3] == 'z') {
                    if (c.inst.size() < 5) {
                        bgtz_instr(c);
                        return true;
                    }
                }
                if (c.inst[3] == 'u') {
                    if (c.inst.size() < 5) {
                        bgtu_instr(c);
                        return true;
                    }
                }
            }
        }
        if (c.inst[1] == 'l') {
            if (c.inst.size() < 3) return false;
            if (c.inst[2] == 'e') {
                if (c.inst.size() < 4) {
                    ble_instr(c);
                    return true;
                }
                if (c.inst[3] == 'z') {
                    if (c.inst.size() < 5) {
                        blez_instr(c);
                        return true;
                    }
                }
                if (c.inst[3] == 'u') {
                    if (c.inst.size() < 5) {
                        bleu_instr(c);
                        return true;
                    }
                }
            }
        }
        if (c.inst[1] == 'n') {
            if (c.inst.size() < 3) return false;
            if (c.inst[2] == 'e') {
                if (c.inst.size() < 4) return false;
                if (c.inst[3] == 'z') {
                    if (c.inst.size() < 5) {
                        bnez_instr(c);
                        return true;
                    }
                }
            }
        }
    }
    if (c.inst[0] == 'z') {
        if (c.inst.size() < 2) return false;
        if (c.inst[1] == 'e') {
            if (c.inst.size() < 3) return false;
            if (c.inst[2] == 'x') {
                if (c.inst.size() < 4) return false;
                if (c.inst[3] == 't') {
                    if (c.inst.size() < 5) return false;
                    if (c.inst[4] == '.') {
                        if (c.inst.size() < 6) return false;
                        if (c.inst[5] == 'b') {
                            if (c.inst.size() < 7) {
                                zext_b_instr(c);
                                return true;
                            }
                        }
                    }
                }
            }
        }
    }
    if (c.inst[0] == 't') {
        if (c.inst.size() < 2) return false;
        if (c.inst[1] == 'h') {
            if (c.inst.size() < 3) return false;
            if (c.inst[2] == '.') {
                if (c.inst.size() < 4) return false;
                if (c.inst[3] == 'v') {
                    if (c.inst.size() < 5) return false;
                    if (c.inst[4] == 'n') {
                        if (c.inst.size() < 6) return false;
                        if (c.inst[5] == 'e') {
                            if (c.inst.size() < 7) return false;
                            if (c.inst[6] == 'g') {
                                if (c.inst.size() < 8) return false;
                                if (c.inst[7] == '.') {
                                    if (c.inst.size() < 9) return false;
                                    if (c.inst[8] == 'v') {
                                        if (c.inst.size() < 10) {
                                            th_vneg_v_instr(c);
                                            return true;
                                        }
                                    }
                                }
                            }
                        }
                        if (c.inst[5] == 'c') {
                            if (c.inst.size() < 7) return false;
                            if (c.inst[6] == 'v') {
                                if (c.inst.size() < 8) return false;
                                if (c.inst[7] == 't') {
                                    if (c.inst.size() < 9) return false;
                                    if (c.inst[8] == '.') {
                                        if (c.inst.size() < 10) return false;
                                        if (c.inst[9] == 'x') {
                                            if (c.inst.size() < 11) return false;
                                            if (c.inst[10] == '.') {
                                                if (c.inst.size() < 12) return false;
                                                if (c.inst[11] == 'x') {
                                                    if (c.inst.size() < 13) return false;
                                                    if (c.inst[12] == '.') {
                                                        if (c.inst.size() < 14) return false;
                                                        if (c.inst[13] == 'v') {
                                                            if (c.inst.size() < 15) {
                                                                th_vncvt_x_x_v_instr(c);
                                                                return true;
                                                            }
                                                        }
                                                    }
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                        if (c.inst[5] == 'o') {
                            if (c.inst.size() < 7) return false;
                            if (c.inst[6] == 't') {
                                if (c.inst.size() < 8) return false;
                                if (c.inst[7] == '.') {
                                    if (c.inst.size() < 9) return false;
                                    if (c.inst[8] == 'v') {
                                        if (c.inst.size() < 10) {
                                            th_vnot_v_instr(c);
                                            return true;
                                        }
                                    }
                                }
                            }
                        }
                    }
                    if (c.inst[4] == 'w') {
                        if (c.inst.size() < 6) return false;
                        if (c.inst[5] == 'c') {
                            if (c.inst.size() < 7) return false;
                            if (c.inst[6] == 'v') {
                                if (c.inst.size() < 8) return false;
                                if (c.inst[7] == 't') {
                                    if (c.inst.size() < 9) return false;
                                    if (c.inst[8] == 'u') {
                                        if (c.inst.size() < 10) return false;
                                        if (c.inst[9] == '.') {
                                            if (c.inst.size() < 11) return false;
                                            if (c.inst[10] == 'x') {
                                                if (c.inst.size() < 12) return false;
                                                if (c.inst[11] == '.') {
                                                    if (c.inst.size() < 13) return false;
                                                    if (c.inst[12] == 'x') {
                                                        if (c.inst.size() < 14) return false;
                                                        if (c.inst[13] == '.') {
                                                            if (c.inst.size() < 15) return false;
                                                            if (c.inst[14] == 'v') {
                                                                if (c.inst.size() < 16) {
                                                                    th_vwcvtu_x_x_v_instr(c);
                                                                    return true;
                                                                }
                                                            }
                                                        }
                                                    }
                                                }
                                            }
                                        }
                                    }
                                    if (c.inst[8] == '.') {
                                        if (c.inst.size() < 10) return false;
                                        if (c.inst[9] == 'x') {
                                            if (c.inst.size() < 11) return false;
                                            if (c.inst[10] == '.') {
                                                if (c.inst.size() < 12) return false;
                                                if (c.inst[11] == 'x') {
                                                    if (c.inst.size() < 13) return false;
                                                    if (c.inst[12] == '.') {
                                                        if (c.inst.size() < 14) return false;
                                                        if (c.inst[13] == 'v') {
                                                            if (c.inst.size() < 15) {
                                                                th_vwcvt_x_x_v_instr(c);
                                                                return true;
                                                            }
                                                        }
                                                    }
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                    if (c.inst[4] == 'f') {
                        if (c.inst.size() < 6) return false;
                        if (c.inst[5] == 'n') {
                            if (c.inst.size() < 7) return false;
                            if (c.inst[6] == 'e') {
                                if (c.inst.size() < 8) return false;
                                if (c.inst[7] == 'g') {
                                    if (c.inst.size() < 9) return false;
                                    if (c.inst[8] == '.') {
                                        if (c.inst.size() < 10) return false;
                                        if (c.inst[9] == 'v') {
                                            if (c.inst.size() < 11) {
                                                th_vfneg_v_instr(c);
                                                return true;
                                            }
                                        }
                                    }
                                }
                            }
                        }
                        if (c.inst[5] == 'a') {
                            if (c.inst.size() < 7) return false;
                            if (c.inst[6] == 'b') {
                                if (c.inst.size() < 8) return false;
                                if (c.inst[7] == 's') {
                                    if (c.inst.size() < 9) return false;
                                    if (c.inst[8] == '.') {
                                        if (c.inst.size() < 10) return false;
                                        if (c.inst[9] == 'v') {
                                            if (c.inst.size() < 11) {
                                                th_vfabs_v_instr(c);
                                                return true;
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                    if (c.inst[4] == 'm') {
                        if (c.inst.size() < 6) return false;
                        if (c.inst[5] == 'n') {
                            if (c.inst.size() < 7) return false;
                            if (c.inst[6] == 'o') {
                                if (c.inst.size() < 8) return false;
                                if (c.inst[7] == 't') {
                                    if (c.inst.size() < 9) return false;
                                    if (c.inst[8] == '.') {
                                        if (c.inst.size() < 10) return false;
                                        if (c.inst[9] == 'm') {
                                            if (c.inst.size() < 11) {
                                                th_vmnot_m_instr(c);
                                                return true;
                                            }
                                        }
                                    }
                                }
                            }
                        }
                        if (c.inst[5] == 'c') {
                            if (c.inst.size() < 7) return false;
                            if (c.inst[6] == 'l') {
                                if (c.inst.size() < 8) return false;
                                if (c.inst[7] == 'r') {
                                    if (c.inst.size() < 9) return false;
                                    if (c.inst[8] == '.') {
                                        if (c.inst.size() < 10) return false;
                                        if (c.inst[9] == 'm') {
                                            if (c.inst.size() < 11) {
                                                th_vmclr_m_instr(c);
                                                return true;
                                            }
                                        }
                                    }
                                }
                            }
                            if (c.inst[6] == 'p') {
                                if (c.inst.size() < 8) return false;
                                if (c.inst[7] == 'y') {
                                    if (c.inst.size() < 9) return false;
                                    if (c.inst[8] == '.') {
                                        if (c.inst.size() < 10) return false;
                                        if (c.inst[9] == 'm') {
                                            if (c.inst.size() < 11) {
                                                th_vmcpy_m_instr(c);
                                                return true;
                                            }
                                        }
                                    }
                                }
                            }
                        }
                        if (c.inst[5] == 's') {
                            if (c.inst.size() < 7) return false;
                            if (c.inst[6] == 'e') {
                                if (c.inst.size() < 8) return false;
                                if (c.inst[7] == 't') {
                                    if (c.inst.size() < 9) return false;
                                    if (c.inst[8] == '.') {
                                        if (c.inst.size() < 10) return false;
                                        if (c.inst[9] == 'm') {
                                            if (c.inst.size() < 11) {
                                                th_vmset_m_instr(c);
                                                return true;
                                            }
                                        }
                                    }
                                }
                            }
                            if (c.inst[6] == 'g') {
                                if (c.inst.size() < 8) return false;
                                if (c.inst[7] == 'e') {
                                    if (c.inst.size() < 9) return false;
                                    if (c.inst[8] == 'u') {
                                        if (c.inst.size() < 10) return false;
                                        if (c.inst[9] == '.') {
                                            if (c.inst.size() < 11) return false;
                                            if (c.inst[10] == 'v') {
                                                if (c.inst.size() < 12) return false;
                                                if (c.inst[11] == 'i') {
                                                    if (c.inst.size() < 13) {
                                                        th_vmsgeu_vi_instr(c);
                                                        return true;
                                                    }
                                                }
                                                if (c.inst[11] == 'v') {
                                                    if (c.inst.size() < 13) {
                                                        th_vmsgeu_vv_instr(c);
                                                        return true;
                                                    }
                                                }
                                                if (c.inst[11] == 'x') {
                                                    if (c.inst.size() < 13) {
                                                        th_vmsgeu_vx_instr(c);
                                                        return true;
                                                    }
                                                }
                                            }
                                        }
                                    }
                                    if (c.inst[8] == '.') {
                                        if (c.inst.size() < 10) return false;
                                        if (c.inst[9] == 'v') {
                                            if (c.inst.size() < 11) return false;
                                            if (c.inst[10] == 'i') {
                                                if (c.inst.size() < 12) {
                                                    th_vmsge_vi_instr(c);
                                                    return true;
                                                }
                                            }
                                            if (c.inst[10] == 'v') {
                                                if (c.inst.size() < 12) {
                                                    th_vmsge_vv_instr(c);
                                                    return true;
                                                }
                                            }
                                            if (c.inst[10] == 'x') {
                                                if (c.inst.size() < 12) {
                                                    th_vmsge_vx_instr(c);
                                                    return true;
                                                }
                                            }
                                        }
                                    }
                                }
                                if (c.inst[7] == 't') {
                                    if (c.inst.size() < 9) return false;
                                    if (c.inst[8] == 'u') {
                                        if (c.inst.size() < 10) return false;
                                        if (c.inst[9] == '.') {
                                            if (c.inst.size() < 11) return false;
                                            if (c.inst[10] == 'v') {
                                                if (c.inst.size() < 12) return false;
                                                if (c.inst[11] == 'v') {
                                                    if (c.inst.size() < 13) {
                                                        th_vmsgtu_vv_instr(c);
                                                        return true;
                                                    }
                                                }
                                            }
                                        }
                                    }
                                    if (c.inst[8] == '.') {
                                        if (c.inst.size() < 10) return false;
                                        if (c.inst[9] == 'v') {
                                            if (c.inst.size() < 11) return false;
                                            if (c.inst[10] == 'v') {
                                                if (c.inst.size() < 12) {
                                                    th_vmsgt_vv_instr(c);
                                                    return true;
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                            if (c.inst[6] == 'l') {
                                if (c.inst.size() < 8) return false;
                                if (c.inst[7] == 't') {
                                    if (c.inst.size() < 9) return false;
                                    if (c.inst[8] == 'u') {
                                        if (c.inst.size() < 10) return false;
                                        if (c.inst[9] == '.') {
                                            if (c.inst.size() < 11) return false;
                                            if (c.inst[10] == 'v') {
                                                if (c.inst.size() < 12) return false;
                                                if (c.inst[11] == 'i') {
                                                    if (c.inst.size() < 13) {
                                                        th_vmsltu_vi_instr(c);
                                                        return true;
                                                    }
                                                }
                                            }
                                        }
                                    }
                                    if (c.inst[8] == '.') {
                                        if (c.inst.size() < 10) return false;
                                        if (c.inst[9] == 'v') {
                                            if (c.inst.size() < 11) return false;
                                            if (c.inst[10] == 'i') {
                                                if (c.inst.size() < 12) {
                                                    th_vmslt_vi_instr(c);
                                                    return true;
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                        if (c.inst[5] == 'f') {
                            if (c.inst.size() < 7) return false;
                            if (c.inst[6] == 'g') {
                                if (c.inst.size() < 8) return false;
                                if (c.inst[7] == 'e') {
                                    if (c.inst.size() < 9) return false;
                                    if (c.inst[8] == '.') {
                                        if (c.inst.size() < 10) return false;
                                        if (c.inst[9] == 'v') {
                                            if (c.inst.size() < 11) return false;
                                            if (c.inst[10] == 'v') {
                                                if (c.inst.size() < 12) {
                                                    th_vmfge_vv_instr(c);
                                                    return true;
                                                }
                                            }
                                        }
                                    }
                                }
                                if (c.inst[7] == 't') {
                                    if (c.inst.size() < 9) return false;
                                    if (c.inst[8] == '.') {
                                        if (c.inst.size() < 10) return false;
                                        if (c.inst[9] == 'v') {
                                            if (c.inst.size() < 11) return false;
                                            if (c.inst[10] == 'v') {
                                                if (c.inst.size() < 12) {
                                                    th_vmfgt_vv_instr(c);
                                                    return true;
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                        if (c.inst[5] == 'm') {
                            if (c.inst.size() < 7) return false;
                            if (c.inst[6] == 'v') {
                                if (c.inst.size() < 8) return false;
                                if (c.inst[7] == '.') {
                                    if (c.inst.size() < 9) return false;
                                    if (c.inst[8] == 'm') {
                                        if (c.inst.size() < 10) {
                                            th_vmmv_m_instr(c);
                                            return true;
                                        }
                                    }
                                }
                            }
                        }
                        if (c.inst[5] == 'v') {
                            if (c.inst.size() < 7) return false;
                            if (c.inst[6] == '.') {
                                if (c.inst.size() < 8) return false;
                                if (c.inst[7] == 'x') {
                                    if (c.inst.size() < 9) return false;
                                    if (c.inst[8] == '.') {
                                        if (c.inst.size() < 10) return false;
                                        if (c.inst[9] == 's') {
                                            if (c.inst.size() < 11) {
                                                th_vmv_x_s_instr(c);
                                                return true;
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    if (c.inst[0] == 'l') {
        if (c.inst.size() < 2) return false;
        if (c.inst[1] == 'a') {
            if (c.inst.size() < 3) {
                la_instr(c);
                return true;
            }
        }
        if (c.inst[1] == 'i') {
            if (c.inst.size() < 3) {
                li_instr(c);
                return true;
            }
        }
    }
    if (c.inst[0] == 'n') {
        if (c.inst.size() < 2) return false;
        if (c.inst[1] == 'e') {
            if (c.inst.size() < 3) return false;
            if (c.inst[2] == 'g') {
                if (c.inst.size() < 4) {
                    neg_instr(c);
                    return true;
                }
                if (c.inst[3] == 'w') {
                    if (c.inst.size() < 5) {
                        negw_instr(c);
                        return true;
                    }
                }
            }
        }
        if (c.inst[1] == 't') {
            if (c.inst.size() < 3) return false;
            if (c.inst[2] == 'l') {
                if (c.inst.size() < 4) return false;
                if (c.inst[3] == '.') {
                    if (c.inst.size() < 5) return false;
                    if (c.inst[4] == 'a') {
                        if (c.inst.size() < 6) return false;
                        if (c.inst[5] == 'l') {
                            if (c.inst.size() < 7) return false;
                            if (c.inst[6] == 'l') {
                                if (c.inst.size() < 8) {
                                    ntl_all_instr(c);
                                    return true;
                                }
                            }
                        }
                    }
                    if (c.inst[4] == 's') {
                        if (c.inst.size() < 6) return false;
                        if (c.inst[5] == '1') {
                            if (c.inst.size() < 7) {
                                ntl_s1_instr(c);
                                return true;
                            }
                        }
                    }
                    if (c.inst[4] == 'p') {
                        if (c.inst.size() < 6) return false;
                        if (c.inst[5] == 'a') {
                            if (c.inst.size() < 7) return false;
                            if (c.inst[6] == 'l') {
                                if (c.inst.size() < 8) return false;
                                if (c.inst[7] == 'l') {
                                    if (c.inst.size() < 9) {
                                        ntl_pall_instr(c);
                                        return true;
                                    }
                                }
                            }
                        }
                        if (c.inst[5] == '1') {
                            if (c.inst.size() < 7) {
                                ntl_p1_instr(c);
                                return true;
                            }
                        }
                    }
                }
            }
        }
        if (c.inst[1] == 'o') {
            if (c.inst.size() < 3) return false;
            if (c.inst[2] == 't') {
                if (c.inst.size() < 4) {
                    not_instr(c);
                    return true;
                }
            }
            if (c.inst[2] == 'p') {
                if (c.inst.size() < 4) {
                    nop_instr(c);
                    return true;
                }
            }
        }
    }
    if (c.inst[0] == 'c') {
        if (c.inst.size() < 2) return false;
        if (c.inst[1] == 'a') {
            if (c.inst.size() < 3) return false;
            if (c.inst[2] == 'l') {
                if (c.inst.size() < 4) return false;
                if (c.inst[3] == 'l') {
                    if (c.inst.size() < 5) {
                        call_instr(c);
                        return true;
                    }
                }
            }
        }
        if (c.inst[1] == 's') {
            if (c.inst.size() < 3) return false;
            if (c.inst[2] == 'r') {
                if (c.inst.size() < 4) return false;
                if (c.inst[3] == 'c') {
                    if (c.inst.size() < 5) {
                        csrc_instr(c);
                        return true;
                    }
                    if (c.inst[4] == 'i') {
                        if (c.inst.size() < 6) {
                            csrci_instr(c);
                            return true;
                        }
                    }
                }
                if (c.inst[3] == 's') {
                    if (c.inst.size() < 5) {
                        csrs_instr(c);
                        return true;
                    }
                    if (c.inst[4] == 'i') {
                        if (c.inst.size() < 6) {
                            csrsi_instr(c);
                            return true;
                        }
                    }
                }
                if (c.inst[3] == 'r') {
                    if (c.inst.size() < 5) {
                        csrr_instr(c);
                        return true;
                    }
                }
                if (c.inst[3] == 'w') {
                    if (c.inst.size() < 5) {
                        csrw_instr(c);
                        return true;
                    }
                    if (c.inst[4] == 'i') {
                        if (c.inst.size() < 6) {
                            csrwi_instr(c);
                            return true;
                        }
                    }
                }
            }
        }
    }
    if (c.inst[0] == 's') {
        if (c.inst.size() < 2) return false;
        if (c.inst[1] == 'e') {
            if (c.inst.size() < 3) return false;
            if (c.inst[2] == 'q') {
                if (c.inst.size() < 4) return false;
                if (c.inst[3] == 'z') {
                    if (c.inst.size() < 5) {
                        seqz_instr(c);
                        return true;
                    }
                }
            }
            if (c.inst[2] == 'x') {
                if (c.inst.size() < 4) return false;
                if (c.inst[3] == 't') {
                    if (c.inst.size() < 5) return false;
                    if (c.inst[4] == '.') {
                        if (c.inst.size() < 6) return false;
                        if (c.inst[5] == 'w') {
                            if (c.inst.size() < 7) {
                                sext_w_instr(c);
                                return true;
                            }
                        }
                    }
                }
            }
        }
        if (c.inst[1] == 'g') {
            if (c.inst.size() < 3) return false;
            if (c.inst[2] == 't') {
                if (c.inst.size() < 4) return false;
                if (c.inst[3] == 'z') {
                    if (c.inst.size() < 5) {
                        sgtz_instr(c);
                        return true;
                    }
                }
            }
        }
        if (c.inst[1] == 'l') {
            if (c.inst.size() < 3) return false;
            if (c.inst[2] == 't') {
                if (c.inst.size() < 4) return false;
                if (c.inst[3] == 'z') {
                    if (c.inst.size() < 5) {
                        sltz_instr(c);
                        return true;
                    }
                }
            }
        }
        if (c.inst[1] == 'n') {
            if (c.inst.size() < 3) return false;
            if (c.inst[2] == 'e') {
                if (c.inst.size() < 4) return false;
                if (c.inst[3] == 'z') {
                    if (c.inst.size() < 5) {
                        snez_instr(c);
                        return true;
                    }
                }
            }
        }
    }
    if (c.inst[0] == 'r') {
        if (c.inst.size() < 2) return false;
        if (c.inst[1] == 'e') {
            if (c.inst.size() < 3) return false;
            if (c.inst[2] == 't') {
                if (c.inst.size() < 4) {
                    ret_instr(c);
                    return true;
                }
            }
        }
        if (c.inst[1] == 'd') {
            if (c.inst.size() < 3) return false;
            if (c.inst[2] == 't') {
                if (c.inst.size() < 4) return false;
                if (c.inst[3] == 'i') {
                    if (c.inst.size() < 5) return false;
                    if (c.inst[4] == 'm') {
                        if (c.inst.size() < 6) return false;
                        if (c.inst[5] == 'e') {
                            if (c.inst.size() < 7) {
                                rdtime_instr(c);
                                return true;
                            }
                            if (c.inst[6] == 'h') {
                                if (c.inst.size() < 8) {
                                    rdtimeh_instr(c);
                                    return true;
                                }
                            }
                        }
                    }
                }
            }
            if (c.inst[2] == 'c') {
                if (c.inst.size() < 4) return false;
                if (c.inst[3] == 'y') {
                    if (c.inst.size() < 5) return false;
                    if (c.inst[4] == 'c') {
                        if (c.inst.size() < 6) return false;
                        if (c.inst[5] == 'l') {
                            if (c.inst.size() < 7) return false;
                            if (c.inst[6] == 'e') {
                                if (c.inst.size() < 8) {
                                    rdcycle_instr(c);
                                    return true;
                                }
                                if (c.inst[7] == 'h') {
                                    if (c.inst.size() < 9) {
                                        rdcycleh_instr(c);
                                        return true;
                                    }
                                }
                            }
                        }
                    }
                }
            }
            if (c.inst[2] == 'i') {
                if (c.inst.size() < 4) return false;
                if (c.inst[3] == 'n') {
                    if (c.inst.size() < 5) return false;
                    if (c.inst[4] == 's') {
                        if (c.inst.size() < 6) return false;
                        if (c.inst[5] == 't') {
                            if (c.inst.size() < 7) return false;
                            if (c.inst[6] == 'r') {
                                if (c.inst.size() < 8) return false;
                                if (c.inst[7] == 'e') {
                                    if (c.inst.size() < 9) return false;
                                    if (c.inst[8] == 't') {
                                        if (c.inst.size() < 10) {
                                            rdinstret_instr(c);
                                            return true;
                                        }
                                        if (c.inst[9] == 'h') {
                                            if (c.inst.size() < 11) {
                                                rdinstreth_instr(c);
                                                return true;
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    if (c.inst[0] == 'f') {
        if (c.inst.size() < 2) return false;
        if (c.inst[1] == 'n') {
            if (c.inst.size() < 3) return false;
            if (c.inst[2] == 'e') {
                if (c.inst.size() < 4) return false;
                if (c.inst[3] == 'g') {
                    if (c.inst.size() < 5) return false;
                    if (c.inst[4] == '.') {
                        if (c.inst.size() < 6) return false;
                        if (c.inst[5] == 's') {
                            if (c.inst.size() < 7) {
                                fneg_s_instr(c);
                                return true;
                            }
                        }
                        if (c.inst[5] == 'd') {
                            if (c.inst.size() < 7) {
                                fneg_d_instr(c);
                                return true;
                            }
                        }
                    }
                }
            }
        }
        if (c.inst[1] == 'a') {
            if (c.inst.size() < 3) return false;
            if (c.inst[2] == 'b') {
                if (c.inst.size() < 4) return false;
                if (c.inst[3] == 's') {
                    if (c.inst.size() < 5) return false;
                    if (c.inst[4] == '.') {
                        if (c.inst.size() < 6) return false;
                        if (c.inst[5] == 's') {
                            if (c.inst.size() < 7) {
                                fabs_s_instr(c);
                                return true;
                            }
                        }
                        if (c.inst[5] == 'd') {
                            if (c.inst.size() < 7) {
                                fabs_d_instr(c);
                                return true;
                            }
                        }
                    }
                }
            }
        }
        if (c.inst[1] == 's') {
            if (c.inst.size() < 3) return false;
            if (c.inst[2] == 'c') {
                if (c.inst.size() < 4) return false;
                if (c.inst[3] == 's') {
                    if (c.inst.size() < 5) return false;
                    if (c.inst[4] == 'r') {
                        if (c.inst.size() < 6) {
                            fscsr_instr(c);
                            return true;
                        }
                    }
                }
            }
            if (c.inst[2] == 'r') {
                if (c.inst.size() < 4) return false;
                if (c.inst[3] == 'm') {
                    if (c.inst.size() < 5) {
                        fsrm_instr(c);
                        return true;
                    }
                    if (c.inst[4] == 'i') {
                        if (c.inst.size() < 6) {
                            fsrmi_instr(c);
                            return true;
                        }
                    }
                }
            }
            if (c.inst[2] == 'f') {
                if (c.inst.size() < 4) return false;
                if (c.inst[3] == 'l') {
                    if (c.inst.size() < 5) return false;
                    if (c.inst[4] == 'a') {
                        if (c.inst.size() < 6) return false;
                        if (c.inst[5] == 'g') {
                            if (c.inst.size() < 7) return false;
                            if (c.inst[6] == 's') {
                                if (c.inst.size() < 8) {
                                    fsflags_instr(c);
                                    return true;
                                }
                                if (c.inst[7] == 'i') {
                                    if (c.inst.size() < 9) {
                                        fsflagsi_instr(c);
                                        return true;
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
        if (c.inst[1] == 'r') {
            if (c.inst.size() < 3) return false;
            if (c.inst[2] == 'c') {
                if (c.inst.size() < 4) return false;
                if (c.inst[3] == 's') {
                    if (c.inst.size() < 5) return false;
                    if (c.inst[4] == 'r') {
                        if (c.inst.size() < 6) {
                            frcsr_instr(c);
                            return true;
                        }
                    }
                }
            }
            if (c.inst[2] == 'r') {
                if (c.inst.size() < 4) return false;
                if (c.inst[3] == 'm') {
                    if (c.inst.size() < 5) {
                        frrm_instr(c);
                        return true;
                    }
                }
            }
            if (c.inst[2] == 'f') {
                if (c.inst.size() < 4) return false;
                if (c.inst[3] == 'l') {
                    if (c.inst.size() < 5) return false;
                    if (c.inst[4] == 'a') {
                        if (c.inst.size() < 6) return false;
                        if (c.inst[5] == 'g') {
                            if (c.inst.size() < 7) return false;
                            if (c.inst[6] == 's') {
                                if (c.inst.size() < 8) {
                                    frflags_instr(c);
                                    return true;
                                }
                            }
                        }
                    }
                }
            }
        }
        if (c.inst[1] == 'm') {
            if (c.inst.size() < 3) return false;
            if (c.inst[2] == 'v') {
                if (c.inst.size() < 4) return false;
                if (c.inst[3] == '.') {
                    if (c.inst.size() < 5) return false;
                    if (c.inst[4] == 's') {
                        if (c.inst.size() < 6) {
                            fmv_s_instr(c);
                            return true;
                        }
                        if (c.inst[5] == '.') {
                            if (c.inst.size() < 7) return false;
                            if (c.inst[6] == 'x') {
                                if (c.inst.size() < 8) {
                                    fmv_s_x_instr(c);
                                    return true;
                                }
                            }
                        }
                    }
                    if (c.inst[4] == 'd') {
                        if (c.inst.size() < 6) {
                            fmv_d_instr(c);
                            return true;
                        }
                    }
                    if (c.inst[4] == 'x') {
                        if (c.inst.size() < 6) return false;
                        if (c.inst[5] == '.') {
                            if (c.inst.size() < 7) return false;
                            if (c.inst[6] == 's') {
                                if (c.inst.size() < 8) {
                                    fmv_x_s_instr(c);
                                    return true;
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    if (c.inst[0] == 'm') {
        if (c.inst.size() < 2) return false;
        if (c.inst[1] == 'v') {
            if (c.inst.size() < 3) {
                mv_instr(c);
                return true;
            }
        }
    }
    if (c.inst[0] == 'v') {
        if (c.inst.size() < 2) return false;
        if (c.inst[1] == 'l') {
            if (c.inst.size() < 3) return false;
            if (c.inst[2] == '1') {
                if (c.inst.size() < 4) return false;
                if (c.inst[3] == 'r') {
                    if (c.inst.size() < 5) return false;
                    if (c.inst[4] == '.') {
                        if (c.inst.size() < 6) return false;
                        if (c.inst[5] == 'v') {
                            if (c.inst.size() < 7) {
                                vl1r_v_instr(c);
                                return true;
                            }
                        }
                    }
                }
            }
            if (c.inst[2] == '2') {
                if (c.inst.size() < 4) return false;
                if (c.inst[3] == 'r') {
                    if (c.inst.size() < 5) return false;
                    if (c.inst[4] == '.') {
                        if (c.inst.size() < 6) return false;
                        if (c.inst[5] == 'v') {
                            if (c.inst.size() < 7) {
                                vl2r_v_instr(c);
                                return true;
                            }
                        }
                    }
                }
            }
            if (c.inst[2] == '4') {
                if (c.inst.size() < 4) return false;
                if (c.inst[3] == 'r') {
                    if (c.inst.size() < 5) return false;
                    if (c.inst[4] == '.') {
                        if (c.inst.size() < 6) return false;
                        if (c.inst[5] == 'v') {
                            if (c.inst.size() < 7) {
                                vl4r_v_instr(c);
                                return true;
                            }
                        }
                    }
                }
            }
            if (c.inst[2] == '8') {
                if (c.inst.size() < 4) return false;
                if (c.inst[3] == 'r') {
                    if (c.inst.size() < 5) return false;
                    if (c.inst[4] == '.') {
                        if (c.inst.size() < 6) return false;
                        if (c.inst[5] == 'v') {
                            if (c.inst.size() < 7) {
                                vl8r_v_instr(c);
                                return true;
                            }
                        }
                    }
                }
            }
        }
        if (c.inst[1] == 'n') {
            if (c.inst.size() < 3) return false;
            if (c.inst[2] == 'e') {
                if (c.inst.size() < 4) return false;
                if (c.inst[3] == 'g') {
                    if (c.inst.size() < 5) return false;
                    if (c.inst[4] == '.') {
                        if (c.inst.size() < 6) return false;
                        if (c.inst[5] == 'v') {
                            if (c.inst.size() < 7) {
                                vneg_v_instr(c);
                                return true;
                            }
                        }
                    }
                }
            }
            if (c.inst[2] == 'c') {
                if (c.inst.size() < 4) return false;
                if (c.inst[3] == 'v') {
                    if (c.inst.size() < 5) return false;
                    if (c.inst[4] == 't') {
                        if (c.inst.size() < 6) return false;
                        if (c.inst[5] == '.') {
                            if (c.inst.size() < 7) return false;
                            if (c.inst[6] == 'x') {
                                if (c.inst.size() < 8) return false;
                                if (c.inst[7] == '.') {
                                    if (c.inst.size() < 9) return false;
                                    if (c.inst[8] == 'x') {
                                        if (c.inst.size() < 10) return false;
                                        if (c.inst[9] == '.') {
                                            if (c.inst.size() < 11) return false;
                                            if (c.inst[10] == 'w') {
                                                if (c.inst.size() < 12) {
                                                    vncvt_x_x_w_instr(c);
                                                    return true;
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
            if (c.inst[2] == 'o') {
                if (c.inst.size() < 4) return false;
                if (c.inst[3] == 't') {
                    if (c.inst.size() < 5) return false;
                    if (c.inst[4] == '.') {
                        if (c.inst.size() < 6) return false;
                        if (c.inst[5] == 'v') {
                            if (c.inst.size() < 7) {
                                vnot_v_instr(c);
                                return true;
                            }
                        }
                    }
                }
            }
        }
        if (c.inst[1] == 'w') {
            if (c.inst.size() < 3) return false;
            if (c.inst[2] == 'c') {
                if (c.inst.size() < 4) return false;
                if (c.inst[3] == 'v') {
                    if (c.inst.size() < 5) return false;
                    if (c.inst[4] == 't') {
                        if (c.inst.size() < 6) return false;
                        if (c.inst[5] == 'u') {
                            if (c.inst.size() < 7) return false;
                            if (c.inst[6] == '.') {
                                if (c.inst.size() < 8) return false;
                                if (c.inst[7] == 'x') {
                                    if (c.inst.size() < 9) return false;
                                    if (c.inst[8] == '.') {
                                        if (c.inst.size() < 10) return false;
                                        if (c.inst[9] == 'x') {
                                            if (c.inst.size() < 11) return false;
                                            if (c.inst[10] == '.') {
                                                if (c.inst.size() < 12) return false;
                                                if (c.inst[11] == 'v') {
                                                    if (c.inst.size() < 13) {
                                                        vwcvtu_x_x_v_instr(c);
                                                        return true;
                                                    }
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                        if (c.inst[5] == '.') {
                            if (c.inst.size() < 7) return false;
                            if (c.inst[6] == 'x') {
                                if (c.inst.size() < 8) return false;
                                if (c.inst[7] == '.') {
                                    if (c.inst.size() < 9) return false;
                                    if (c.inst[8] == 'x') {
                                        if (c.inst.size() < 10) return false;
                                        if (c.inst[9] == '.') {
                                            if (c.inst.size() < 11) return false;
                                            if (c.inst[10] == 'v') {
                                                if (c.inst.size() < 12) {
                                                    vwcvt_x_x_v_instr(c);
                                                    return true;
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
        if (c.inst[1] == 'f') {
            if (c.inst.size() < 3) return false;
            if (c.inst[2] == 'n') {
                if (c.inst.size() < 4) return false;
                if (c.inst[3] == 'e') {
                    if (c.inst.size() < 5) return false;
                    if (c.inst[4] == 'g') {
                        if (c.inst.size() < 6) return false;
                        if (c.inst[5] == '.') {
                            if (c.inst.size() < 7) return false;
                            if (c.inst[6] == 'v') {
                                if (c.inst.size() < 8) {
                                    vfneg_v_instr(c);
                                    return true;
                                }
                            }
                        }
                    }
                }
            }
            if (c.inst[2] == 'a') {
                if (c.inst.size() < 4) return false;
                if (c.inst[3] == 'b') {
                    if (c.inst.size() < 5) return false;
                    if (c.inst[4] == 's') {
                        if (c.inst.size() < 6) return false;
                        if (c.inst[5] == '.') {
                            if (c.inst.size() < 7) return false;
                            if (c.inst[6] == 'v') {
                                if (c.inst.size() < 8) {
                                    vfabs_v_instr(c);
                                    return true;
                                }
                            }
                        }
                    }
                }
            }
        }
        if (c.inst[1] == 'm') {
            if (c.inst.size() < 3) return false;
            if (c.inst[2] == 'n') {
                if (c.inst.size() < 4) return false;
                if (c.inst[3] == 'o') {
                    if (c.inst.size() < 5) return false;
                    if (c.inst[4] == 't') {
                        if (c.inst.size() < 6) return false;
                        if (c.inst[5] == '.') {
                            if (c.inst.size() < 7) return false;
                            if (c.inst[6] == 'm') {
                                if (c.inst.size() < 8) {
                                    vmnot_m_instr(c);
                                    return true;
                                }
                            }
                        }
                    }
                }
            }
            if (c.inst[2] == 'c') {
                if (c.inst.size() < 4) return false;
                if (c.inst[3] == 'l') {
                    if (c.inst.size() < 5) return false;
                    if (c.inst[4] == 'r') {
                        if (c.inst.size() < 6) return false;
                        if (c.inst[5] == '.') {
                            if (c.inst.size() < 7) return false;
                            if (c.inst[6] == 'm') {
                                if (c.inst.size() < 8) {
                                    vmclr_m_instr(c);
                                    return true;
                                }
                            }
                        }
                    }
                }
            }
            if (c.inst[2] == 's') {
                if (c.inst.size() < 4) return false;
                if (c.inst[3] == 'e') {
                    if (c.inst.size() < 5) return false;
                    if (c.inst[4] == 't') {
                        if (c.inst.size() < 6) return false;
                        if (c.inst[5] == '.') {
                            if (c.inst.size() < 7) return false;
                            if (c.inst[6] == 'm') {
                                if (c.inst.size() < 8) {
                                    vmset_m_instr(c);
                                    return true;
                                }
                            }
                        }
                    }
                }
                if (c.inst[3] == 'g') {
                    if (c.inst.size() < 5) return false;
                    if (c.inst[4] == 'e') {
                        if (c.inst.size() < 6) return false;
                        if (c.inst[5] == 'u') {
                            if (c.inst.size() < 7) return false;
                            if (c.inst[6] == '.') {
                                if (c.inst.size() < 8) return false;
                                if (c.inst[7] == 'v') {
                                    if (c.inst.size() < 9) return false;
                                    if (c.inst[8] == 'i') {
                                        if (c.inst.size() < 10) {
                                            vmsgeu_vi_instr(c);
                                            return true;
                                        }
                                    }
                                    if (c.inst[8] == 'v') {
                                        if (c.inst.size() < 10) {
                                            vmsgeu_vv_instr(c);
                                            return true;
                                        }
                                    }
                                }
                            }
                        }
                        if (c.inst[5] == '.') {
                            if (c.inst.size() < 7) return false;
                            if (c.inst[6] == 'v') {
                                if (c.inst.size() < 8) return false;
                                if (c.inst[7] == 'i') {
                                    if (c.inst.size() < 9) {
                                        vmsge_vi_instr(c);
                                        return true;
                                    }
                                }
                                if (c.inst[7] == 'v') {
                                    if (c.inst.size() < 9) {
                                        vmsge_vv_instr(c);
                                        return true;
                                    }
                                }
                            }
                        }
                    }
                    if (c.inst[4] == 't') {
                        if (c.inst.size() < 6) return false;
                        if (c.inst[5] == 'u') {
                            if (c.inst.size() < 7) return false;
                            if (c.inst[6] == '.') {
                                if (c.inst.size() < 8) return false;
                                if (c.inst[7] == 'v') {
                                    if (c.inst.size() < 9) return false;
                                    if (c.inst[8] == 'v') {
                                        if (c.inst.size() < 10) {
                                            vmsgtu_vv_instr(c);
                                            return true;
                                        }
                                    }
                                }
                            }
                        }
                        if (c.inst[5] == '.') {
                            if (c.inst.size() < 7) return false;
                            if (c.inst[6] == 'v') {
                                if (c.inst.size() < 8) return false;
                                if (c.inst[7] == 'v') {
                                    if (c.inst.size() < 9) {
                                        vmsgt_vv_instr(c);
                                        return true;
                                    }
                                }
                            }
                        }
                    }
                }
                if (c.inst[3] == 'l') {
                    if (c.inst.size() < 5) return false;
                    if (c.inst[4] == 't') {
                        if (c.inst.size() < 6) return false;
                        if (c.inst[5] == 'u') {
                            if (c.inst.size() < 7) return false;
                            if (c.inst[6] == '.') {
                                if (c.inst.size() < 8) return false;
                                if (c.inst[7] == 'v') {
                                    if (c.inst.size() < 9) return false;
                                    if (c.inst[8] == 'i') {
                                        if (c.inst.size() < 10) {
                                            vmsltu_vi_instr(c);
                                            return true;
                                        }
                                    }
                                }
                            }
                        }
                        if (c.inst[5] == '.') {
                            if (c.inst.size() < 7) return false;
                            if (c.inst[6] == 'v') {
                                if (c.inst.size() < 8) return false;
                                if (c.inst[7] == 'i') {
                                    if (c.inst.size() < 9) {
                                        vmslt_vi_instr(c);
                                        return true;
                                    }
                                }
                            }
                        }
                    }
                }
            }
            if (c.inst[2] == 'f') {
                if (c.inst.size() < 4) return false;
                if (c.inst[3] == 'g') {
                    if (c.inst.size() < 5) return false;
                    if (c.inst[4] == 'e') {
                        if (c.inst.size() < 6) return false;
                        if (c.inst[5] == '.') {
                            if (c.inst.size() < 7) return false;
                            if (c.inst[6] == 'v') {
                                if (c.inst.size() < 8) return false;
                                if (c.inst[7] == 'v') {
                                    if (c.inst.size() < 9) {
                                        vmfge_vv_instr(c);
                                        return true;
                                    }
                                }
                            }
                        }
                    }
                    if (c.inst[4] == 't') {
                        if (c.inst.size() < 6) return false;
                        if (c.inst[5] == '.') {
                            if (c.inst.size() < 7) return false;
                            if (c.inst[6] == 'v') {
                                if (c.inst.size() < 8) return false;
                                if (c.inst[7] == 'v') {
                                    if (c.inst.size() < 9) {
                                        vmfgt_vv_instr(c);
                                        return true;
                                    }
                                }
                            }
                        }
                    }
                }
            }
            if (c.inst[2] == 'm') {
                if (c.inst.size() < 4) return false;
                if (c.inst[3] == 'v') {
                    if (c.inst.size() < 5) return false;
                    if (c.inst[4] == '.') {
                        if (c.inst.size() < 6) return false;
                        if (c.inst[5] == 'm') {
                            if (c.inst.size() < 7) {
                                vmmv_m_instr(c);
                                return true;
                            }
                        }
                    }
                }
            }
        }
    }
    if (c.inst[0] == 'j') {
        if (c.inst.size() < 2) {
            j_instr(c);
            return true;
        }
    }
    return false;
}

} // namespace ultrassembler_internal