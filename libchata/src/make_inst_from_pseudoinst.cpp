// SPDX-License-Identifier: MPL-2.0
// The generate_pseudoinstruction_converter.py script automatically generated this code. DO NOT MODIFY!
#include "pseudoinstructions.hpp"
#include "libchata.hpp"

namespace libchata_internal {

chatavector<instruction> make_inst_from_pseudoinst(assembly_context& c) {
    if (c.inst.size() < 1) return {};
    if (c.inst[0] == 'b') {
        if (c.inst.size() < 2) return {};
        if (c.inst[1] == 'e') {
            if (c.inst.size() < 3) return {};
            if (c.inst[2] == 'q') {
                if (c.inst.size() < 4) return {};
                if (c.inst[3] == 'z') {
                    if (c.inst.size() < 5) return beqz_instr(c);
                }
            }
        }
        if (c.inst[1] == 'g') {
            if (c.inst.size() < 3) return {};
            if (c.inst[2] == 'e') {
                if (c.inst.size() < 4) return {};
                if (c.inst[3] == 'z') {
                    if (c.inst.size() < 5) return bgez_instr(c);
                }
            }
            if (c.inst[2] == 't') {
                if (c.inst.size() < 4) return bgt_instr(c);
                if (c.inst[3] == 'z') {
                    if (c.inst.size() < 5) return bgtz_instr(c);
                }
                if (c.inst[3] == 'u') {
                    if (c.inst.size() < 5) return bgtu_instr(c);
                }
            }
        }
        if (c.inst[1] == 'l') {
            if (c.inst.size() < 3) return {};
            if (c.inst[2] == 'e') {
                if (c.inst.size() < 4) return ble_instr(c);
                if (c.inst[3] == 'z') {
                    if (c.inst.size() < 5) return blez_instr(c);
                }
                if (c.inst[3] == 'u') {
                    if (c.inst.size() < 5) return bleu_instr(c);
                }
            }
        }
        if (c.inst[1] == 'n') {
            if (c.inst.size() < 3) return {};
            if (c.inst[2] == 'e') {
                if (c.inst.size() < 4) return {};
                if (c.inst[3] == 'z') {
                    if (c.inst.size() < 5) return bnez_instr(c);
                }
            }
        }
    }
    if (c.inst[0] == 'z') {
        if (c.inst.size() < 2) return {};
        if (c.inst[1] == 'e') {
            if (c.inst.size() < 3) return {};
            if (c.inst[2] == 'x') {
                if (c.inst.size() < 4) return {};
                if (c.inst[3] == 't') {
                    if (c.inst.size() < 5) return {};
                    if (c.inst[4] == '.') {
                        if (c.inst.size() < 6) return {};
                        if (c.inst[5] == 'b') {
                            if (c.inst.size() < 7) return zext_b_instr(c);
                        }
                    }
                }
            }
        }
    }
    if (c.inst[0] == 'l') {
        if (c.inst.size() < 2) return {};
        if (c.inst[1] == 'a') {
            if (c.inst.size() < 3) return la_instr(c);
        }
        if (c.inst[1] == 'i') {
            if (c.inst.size() < 3) return li_instr(c);
        }
    }
    if (c.inst[0] == 'n') {
        if (c.inst.size() < 2) return {};
        if (c.inst[1] == 'e') {
            if (c.inst.size() < 3) return {};
            if (c.inst[2] == 'g') {
                if (c.inst.size() < 4) return neg_instr(c);
                if (c.inst[3] == 'w') {
                    if (c.inst.size() < 5) return negw_instr(c);
                }
            }
        }
        if (c.inst[1] == 'o') {
            if (c.inst.size() < 3) return {};
            if (c.inst[2] == 't') {
                if (c.inst.size() < 4) return not_instr(c);
            }
            if (c.inst[2] == 'p') {
                if (c.inst.size() < 4) return nop_instr(c);
            }
        }
    }
    if (c.inst[0] == 'c') {
        if (c.inst.size() < 2) return {};
        if (c.inst[1] == 'a') {
            if (c.inst.size() < 3) return {};
            if (c.inst[2] == 'l') {
                if (c.inst.size() < 4) return {};
                if (c.inst[3] == 'l') {
                    if (c.inst.size() < 5) return call_instr(c);
                }
            }
        }
        if (c.inst[1] == 's') {
            if (c.inst.size() < 3) return {};
            if (c.inst[2] == 'r') {
                if (c.inst.size() < 4) return {};
                if (c.inst[3] == 'c') {
                    if (c.inst.size() < 5) return csrc_instr(c);
                    if (c.inst[4] == 'i') {
                        if (c.inst.size() < 6) return csrci_instr(c);
                    }
                }
                if (c.inst[3] == 's') {
                    if (c.inst.size() < 5) return csrs_instr(c);
                    if (c.inst[4] == 'i') {
                        if (c.inst.size() < 6) return csrsi_instr(c);
                    }
                }
                if (c.inst[3] == 'r') {
                    if (c.inst.size() < 5) return csrr_instr(c);
                }
                if (c.inst[3] == 'w') {
                    if (c.inst.size() < 5) return csrw_instr(c);
                    if (c.inst[4] == 'i') {
                        if (c.inst.size() < 6) return csrwi_instr(c);
                    }
                }
            }
        }
    }
    if (c.inst[0] == 's') {
        if (c.inst.size() < 2) return {};
        if (c.inst[1] == 'e') {
            if (c.inst.size() < 3) return {};
            if (c.inst[2] == 'q') {
                if (c.inst.size() < 4) return {};
                if (c.inst[3] == 'z') {
                    if (c.inst.size() < 5) return seqz_instr(c);
                }
            }
            if (c.inst[2] == 'x') {
                if (c.inst.size() < 4) return {};
                if (c.inst[3] == 't') {
                    if (c.inst.size() < 5) return {};
                    if (c.inst[4] == '.') {
                        if (c.inst.size() < 6) return {};
                        if (c.inst[5] == 'w') {
                            if (c.inst.size() < 7) return sext_w_instr(c);
                        }
                    }
                }
            }
        }
        if (c.inst[1] == 'g') {
            if (c.inst.size() < 3) return {};
            if (c.inst[2] == 't') {
                if (c.inst.size() < 4) return {};
                if (c.inst[3] == 'z') {
                    if (c.inst.size() < 5) return sgtz_instr(c);
                }
            }
        }
        if (c.inst[1] == 'l') {
            if (c.inst.size() < 3) return {};
            if (c.inst[2] == 't') {
                if (c.inst.size() < 4) return {};
                if (c.inst[3] == 'z') {
                    if (c.inst.size() < 5) return sltz_instr(c);
                }
            }
        }
        if (c.inst[1] == 'n') {
            if (c.inst.size() < 3) return {};
            if (c.inst[2] == 'e') {
                if (c.inst.size() < 4) return {};
                if (c.inst[3] == 'z') {
                    if (c.inst.size() < 5) return snez_instr(c);
                }
            }
        }
    }
    if (c.inst[0] == 'r') {
        if (c.inst.size() < 2) return {};
        if (c.inst[1] == 'e') {
            if (c.inst.size() < 3) return {};
            if (c.inst[2] == 't') {
                if (c.inst.size() < 4) return ret_instr(c);
            }
        }
        if (c.inst[1] == 'd') {
            if (c.inst.size() < 3) return {};
            if (c.inst[2] == 't') {
                if (c.inst.size() < 4) return {};
                if (c.inst[3] == 'i') {
                    if (c.inst.size() < 5) return {};
                    if (c.inst[4] == 'm') {
                        if (c.inst.size() < 6) return {};
                        if (c.inst[5] == 'e') {
                            if (c.inst.size() < 7) return rdtime_instr(c);
                            if (c.inst[6] == 'h') {
                                if (c.inst.size() < 8) return rdtimeh_instr(c);
                            }
                        }
                    }
                }
            }
            if (c.inst[2] == 'c') {
                if (c.inst.size() < 4) return {};
                if (c.inst[3] == 'y') {
                    if (c.inst.size() < 5) return {};
                    if (c.inst[4] == 'c') {
                        if (c.inst.size() < 6) return {};
                        if (c.inst[5] == 'l') {
                            if (c.inst.size() < 7) return {};
                            if (c.inst[6] == 'e') {
                                if (c.inst.size() < 8) return rdcycle_instr(c);
                                if (c.inst[7] == 'h') {
                                    if (c.inst.size() < 9) return rdcycleh_instr(c);
                                }
                            }
                        }
                    }
                }
            }
            if (c.inst[2] == 'i') {
                if (c.inst.size() < 4) return {};
                if (c.inst[3] == 'n') {
                    if (c.inst.size() < 5) return {};
                    if (c.inst[4] == 's') {
                        if (c.inst.size() < 6) return {};
                        if (c.inst[5] == 't') {
                            if (c.inst.size() < 7) return {};
                            if (c.inst[6] == 'r') {
                                if (c.inst.size() < 8) return {};
                                if (c.inst[7] == 'e') {
                                    if (c.inst.size() < 9) return {};
                                    if (c.inst[8] == 't') {
                                        if (c.inst.size() < 10) return rdinstret_instr(c);
                                        if (c.inst[9] == 'h') {
                                            if (c.inst.size() < 11) return rdinstreth_instr(c);
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
        if (c.inst.size() < 2) return {};
        if (c.inst[1] == 'n') {
            if (c.inst.size() < 3) return {};
            if (c.inst[2] == 'e') {
                if (c.inst.size() < 4) return {};
                if (c.inst[3] == 'g') {
                    if (c.inst.size() < 5) return {};
                    if (c.inst[4] == '.') {
                        if (c.inst.size() < 6) return {};
                        if (c.inst[5] == 's') {
                            if (c.inst.size() < 7) return fneg_s_instr(c);
                        }
                        if (c.inst[5] == 'd') {
                            if (c.inst.size() < 7) return fneg_d_instr(c);
                        }
                    }
                }
            }
        }
        if (c.inst[1] == 'a') {
            if (c.inst.size() < 3) return {};
            if (c.inst[2] == 'b') {
                if (c.inst.size() < 4) return {};
                if (c.inst[3] == 's') {
                    if (c.inst.size() < 5) return {};
                    if (c.inst[4] == '.') {
                        if (c.inst.size() < 6) return {};
                        if (c.inst[5] == 's') {
                            if (c.inst.size() < 7) return fabs_s_instr(c);
                        }
                        if (c.inst[5] == 'd') {
                            if (c.inst.size() < 7) return fabs_d_instr(c);
                        }
                    }
                }
            }
        }
        if (c.inst[1] == 's') {
            if (c.inst.size() < 3) return {};
            if (c.inst[2] == 'c') {
                if (c.inst.size() < 4) return {};
                if (c.inst[3] == 's') {
                    if (c.inst.size() < 5) return {};
                    if (c.inst[4] == 'r') {
                        if (c.inst.size() < 6) return fscsr_instr(c);
                    }
                }
            }
            if (c.inst[2] == 'r') {
                if (c.inst.size() < 4) return {};
                if (c.inst[3] == 'm') {
                    if (c.inst.size() < 5) return fsrm_instr(c);
                    if (c.inst[4] == 'i') {
                        if (c.inst.size() < 6) return fsrmi_instr(c);
                    }
                }
            }
            if (c.inst[2] == 'f') {
                if (c.inst.size() < 4) return {};
                if (c.inst[3] == 'l') {
                    if (c.inst.size() < 5) return {};
                    if (c.inst[4] == 'a') {
                        if (c.inst.size() < 6) return {};
                        if (c.inst[5] == 'g') {
                            if (c.inst.size() < 7) return {};
                            if (c.inst[6] == 's') {
                                if (c.inst.size() < 8) return fsflags_instr(c);
                                if (c.inst[7] == 'i') {
                                    if (c.inst.size() < 9) return fsflagsi_instr(c);
                                }
                            }
                        }
                    }
                }
            }
        }
        if (c.inst[1] == 'r') {
            if (c.inst.size() < 3) return {};
            if (c.inst[2] == 'c') {
                if (c.inst.size() < 4) return {};
                if (c.inst[3] == 's') {
                    if (c.inst.size() < 5) return {};
                    if (c.inst[4] == 'r') {
                        if (c.inst.size() < 6) return frcsr_instr(c);
                    }
                }
            }
            if (c.inst[2] == 'r') {
                if (c.inst.size() < 4) return {};
                if (c.inst[3] == 'm') {
                    if (c.inst.size() < 5) return frrm_instr(c);
                }
            }
            if (c.inst[2] == 'f') {
                if (c.inst.size() < 4) return {};
                if (c.inst[3] == 'l') {
                    if (c.inst.size() < 5) return {};
                    if (c.inst[4] == 'a') {
                        if (c.inst.size() < 6) return {};
                        if (c.inst[5] == 'g') {
                            if (c.inst.size() < 7) return {};
                            if (c.inst[6] == 's') {
                                if (c.inst.size() < 8) return frflags_instr(c);
                            }
                        }
                    }
                }
            }
        }
        if (c.inst[1] == 'm') {
            if (c.inst.size() < 3) return {};
            if (c.inst[2] == 'v') {
                if (c.inst.size() < 4) return {};
                if (c.inst[3] == 's') {
                    if (c.inst.size() < 5) return {};
                    if (c.inst[4] == 'x') {
                        if (c.inst.size() < 6) return fmvsx_instr(c);
                    }
                }
                if (c.inst[3] == '.') {
                    if (c.inst.size() < 5) return {};
                    if (c.inst[4] == 's') {
                        if (c.inst.size() < 6) return fmv_s_instr(c);
                    }
                    if (c.inst[4] == 'd') {
                        if (c.inst.size() < 6) return fmv_d_instr(c);
                    }
                }
                if (c.inst[3] == 'x') {
                    if (c.inst.size() < 5) return {};
                    if (c.inst[4] == 's') {
                        if (c.inst.size() < 6) return fmvxs_instr(c);
                    }
                }
            }
        }
    }
    if (c.inst[0] == 'm') {
        if (c.inst.size() < 2) return {};
        if (c.inst[1] == 'v') {
            if (c.inst.size() < 3) return mv_instr(c);
        }
    }
    if (c.inst[0] == 'v') {
        if (c.inst.size() < 2) return {};
        if (c.inst[1] == 'l') {
            if (c.inst.size() < 3) return {};
            if (c.inst[2] == '1') {
                if (c.inst.size() < 4) return {};
                if (c.inst[3] == 'r') {
                    if (c.inst.size() < 5) return {};
                    if (c.inst[4] == '.') {
                        if (c.inst.size() < 6) return {};
                        if (c.inst[5] == 'v') {
                            if (c.inst.size() < 7) return vl1r_v_instr(c);
                        }
                    }
                }
            }
            if (c.inst[2] == '2') {
                if (c.inst.size() < 4) return {};
                if (c.inst[3] == 'r') {
                    if (c.inst.size() < 5) return {};
                    if (c.inst[4] == '.') {
                        if (c.inst.size() < 6) return {};
                        if (c.inst[5] == 'v') {
                            if (c.inst.size() < 7) return vl2r_v_instr(c);
                        }
                    }
                }
            }
            if (c.inst[2] == '4') {
                if (c.inst.size() < 4) return {};
                if (c.inst[3] == 'r') {
                    if (c.inst.size() < 5) return {};
                    if (c.inst[4] == '.') {
                        if (c.inst.size() < 6) return {};
                        if (c.inst[5] == 'v') {
                            if (c.inst.size() < 7) return vl4r_v_instr(c);
                        }
                    }
                }
            }
            if (c.inst[2] == '8') {
                if (c.inst.size() < 4) return {};
                if (c.inst[3] == 'r') {
                    if (c.inst.size() < 5) return {};
                    if (c.inst[4] == '.') {
                        if (c.inst.size() < 6) return {};
                        if (c.inst[5] == 'v') {
                            if (c.inst.size() < 7) return vl8r_v_instr(c);
                        }
                    }
                }
            }
        }
        if (c.inst[1] == 'n') {
            if (c.inst.size() < 3) return {};
            if (c.inst[2] == 'e') {
                if (c.inst.size() < 4) return {};
                if (c.inst[3] == 'g') {
                    if (c.inst.size() < 5) return {};
                    if (c.inst[4] == '.') {
                        if (c.inst.size() < 6) return {};
                        if (c.inst[5] == 'v') {
                            if (c.inst.size() < 7) return vneg_v_instr(c);
                        }
                    }
                }
            }
            if (c.inst[2] == 'c') {
                if (c.inst.size() < 4) return {};
                if (c.inst[3] == 'v') {
                    if (c.inst.size() < 5) return {};
                    if (c.inst[4] == 't') {
                        if (c.inst.size() < 6) return {};
                        if (c.inst[5] == '.') {
                            if (c.inst.size() < 7) return {};
                            if (c.inst[6] == 'x') {
                                if (c.inst.size() < 8) return {};
                                if (c.inst[7] == '.') {
                                    if (c.inst.size() < 9) return {};
                                    if (c.inst[8] == 'x') {
                                        if (c.inst.size() < 10) return {};
                                        if (c.inst[9] == '.') {
                                            if (c.inst.size() < 11) return {};
                                            if (c.inst[10] == 'w') {
                                                if (c.inst.size() < 12) return vncvt_x_x_w_instr(c);
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
                if (c.inst.size() < 4) return {};
                if (c.inst[3] == 't') {
                    if (c.inst.size() < 5) return {};
                    if (c.inst[4] == '.') {
                        if (c.inst.size() < 6) return {};
                        if (c.inst[5] == 'v') {
                            if (c.inst.size() < 7) return vnot_v_instr(c);
                        }
                    }
                }
            }
        }
        if (c.inst[1] == 'w') {
            if (c.inst.size() < 3) return {};
            if (c.inst[2] == 'c') {
                if (c.inst.size() < 4) return {};
                if (c.inst[3] == 'v') {
                    if (c.inst.size() < 5) return {};
                    if (c.inst[4] == 't') {
                        if (c.inst.size() < 6) return {};
                        if (c.inst[5] == 'u') {
                            if (c.inst.size() < 7) return {};
                            if (c.inst[6] == '.') {
                                if (c.inst.size() < 8) return {};
                                if (c.inst[7] == 'x') {
                                    if (c.inst.size() < 9) return {};
                                    if (c.inst[8] == '.') {
                                        if (c.inst.size() < 10) return {};
                                        if (c.inst[9] == 'x') {
                                            if (c.inst.size() < 11) return {};
                                            if (c.inst[10] == '.') {
                                                if (c.inst.size() < 12) return {};
                                                if (c.inst[11] == 'v') {
                                                    if (c.inst.size() < 13) return vwcvtu_x_x_v_instr(c);
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                        if (c.inst[5] == '.') {
                            if (c.inst.size() < 7) return {};
                            if (c.inst[6] == 'x') {
                                if (c.inst.size() < 8) return {};
                                if (c.inst[7] == '.') {
                                    if (c.inst.size() < 9) return {};
                                    if (c.inst[8] == 'x') {
                                        if (c.inst.size() < 10) return {};
                                        if (c.inst[9] == '.') {
                                            if (c.inst.size() < 11) return {};
                                            if (c.inst[10] == 'v') {
                                                if (c.inst.size() < 12) return vwcvt_x_x_v_instr(c);
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
            if (c.inst.size() < 3) return {};
            if (c.inst[2] == 'n') {
                if (c.inst.size() < 4) return {};
                if (c.inst[3] == 'e') {
                    if (c.inst.size() < 5) return {};
                    if (c.inst[4] == 'g') {
                        if (c.inst.size() < 6) return {};
                        if (c.inst[5] == '.') {
                            if (c.inst.size() < 7) return {};
                            if (c.inst[6] == 'v') {
                                if (c.inst.size() < 8) return vfneg_v_instr(c);
                            }
                        }
                    }
                }
            }
            if (c.inst[2] == 'a') {
                if (c.inst.size() < 4) return {};
                if (c.inst[3] == 'b') {
                    if (c.inst.size() < 5) return {};
                    if (c.inst[4] == 's') {
                        if (c.inst.size() < 6) return {};
                        if (c.inst[5] == '.') {
                            if (c.inst.size() < 7) return {};
                            if (c.inst[6] == 'v') {
                                if (c.inst.size() < 8) return vfabs_v_instr(c);
                            }
                        }
                    }
                }
            }
        }
        if (c.inst[1] == 'm') {
            if (c.inst.size() < 3) return {};
            if (c.inst[2] == 'n') {
                if (c.inst.size() < 4) return {};
                if (c.inst[3] == 'o') {
                    if (c.inst.size() < 5) return {};
                    if (c.inst[4] == 't') {
                        if (c.inst.size() < 6) return {};
                        if (c.inst[5] == '.') {
                            if (c.inst.size() < 7) return {};
                            if (c.inst[6] == 'm') {
                                if (c.inst.size() < 8) return vmnot_m_instr(c);
                            }
                        }
                    }
                }
            }
            if (c.inst[2] == 'c') {
                if (c.inst.size() < 4) return {};
                if (c.inst[3] == 'l') {
                    if (c.inst.size() < 5) return {};
                    if (c.inst[4] == 'r') {
                        if (c.inst.size() < 6) return {};
                        if (c.inst[5] == '.') {
                            if (c.inst.size() < 7) return {};
                            if (c.inst[6] == 'm') {
                                if (c.inst.size() < 8) return vmclr_m_instr(c);
                            }
                        }
                    }
                }
            }
            if (c.inst[2] == 's') {
                if (c.inst.size() < 4) return {};
                if (c.inst[3] == 'e') {
                    if (c.inst.size() < 5) return {};
                    if (c.inst[4] == 't') {
                        if (c.inst.size() < 6) return {};
                        if (c.inst[5] == '.') {
                            if (c.inst.size() < 7) return {};
                            if (c.inst[6] == 'm') {
                                if (c.inst.size() < 8) return vmset_m_instr(c);
                            }
                        }
                    }
                }
                if (c.inst[3] == 'g') {
                    if (c.inst.size() < 5) return {};
                    if (c.inst[4] == 'e') {
                        if (c.inst.size() < 6) return {};
                        if (c.inst[5] == 'u') {
                            if (c.inst.size() < 7) return {};
                            if (c.inst[6] == '.') {
                                if (c.inst.size() < 8) return {};
                                if (c.inst[7] == 'v') {
                                    if (c.inst.size() < 9) return {};
                                    if (c.inst[8] == 'i') {
                                        if (c.inst.size() < 10) return vmsgeu_vi_instr(c);
                                    }
                                    if (c.inst[8] == 'v') {
                                        if (c.inst.size() < 10) return vmsgeu_vv_instr(c);
                                    }
                                }
                            }
                        }
                        if (c.inst[5] == '.') {
                            if (c.inst.size() < 7) return {};
                            if (c.inst[6] == 'v') {
                                if (c.inst.size() < 8) return {};
                                if (c.inst[7] == 'i') {
                                    if (c.inst.size() < 9) return vmsge_vi_instr(c);
                                }
                                if (c.inst[7] == 'v') {
                                    if (c.inst.size() < 9) return vmsge_vv_instr(c);
                                }
                            }
                        }
                    }
                    if (c.inst[4] == 't') {
                        if (c.inst.size() < 6) return {};
                        if (c.inst[5] == 'u') {
                            if (c.inst.size() < 7) return {};
                            if (c.inst[6] == '.') {
                                if (c.inst.size() < 8) return {};
                                if (c.inst[7] == 'v') {
                                    if (c.inst.size() < 9) return {};
                                    if (c.inst[8] == 'v') {
                                        if (c.inst.size() < 10) return vmsgtu_vv_instr(c);
                                    }
                                }
                            }
                        }
                        if (c.inst[5] == '.') {
                            if (c.inst.size() < 7) return {};
                            if (c.inst[6] == 'v') {
                                if (c.inst.size() < 8) return {};
                                if (c.inst[7] == 'v') {
                                    if (c.inst.size() < 9) return vmsgt_vv_instr(c);
                                }
                            }
                        }
                    }
                }
                if (c.inst[3] == 'l') {
                    if (c.inst.size() < 5) return {};
                    if (c.inst[4] == 't') {
                        if (c.inst.size() < 6) return {};
                        if (c.inst[5] == 'u') {
                            if (c.inst.size() < 7) return {};
                            if (c.inst[6] == '.') {
                                if (c.inst.size() < 8) return {};
                                if (c.inst[7] == 'v') {
                                    if (c.inst.size() < 9) return {};
                                    if (c.inst[8] == 'i') {
                                        if (c.inst.size() < 10) return vmsltu_vi_instr(c);
                                    }
                                }
                            }
                        }
                        if (c.inst[5] == '.') {
                            if (c.inst.size() < 7) return {};
                            if (c.inst[6] == 'v') {
                                if (c.inst.size() < 8) return {};
                                if (c.inst[7] == 'i') {
                                    if (c.inst.size() < 9) return vmslt_vi_instr(c);
                                }
                            }
                        }
                    }
                }
            }
            if (c.inst[2] == 'f') {
                if (c.inst.size() < 4) return {};
                if (c.inst[3] == 'g') {
                    if (c.inst.size() < 5) return {};
                    if (c.inst[4] == 'e') {
                        if (c.inst.size() < 6) return {};
                        if (c.inst[5] == '.') {
                            if (c.inst.size() < 7) return {};
                            if (c.inst[6] == 'v') {
                                if (c.inst.size() < 8) return {};
                                if (c.inst[7] == 'v') {
                                    if (c.inst.size() < 9) return vmfge_vv_instr(c);
                                }
                            }
                        }
                    }
                    if (c.inst[4] == 't') {
                        if (c.inst.size() < 6) return {};
                        if (c.inst[5] == '.') {
                            if (c.inst.size() < 7) return {};
                            if (c.inst[6] == 'v') {
                                if (c.inst.size() < 8) return {};
                                if (c.inst[7] == 'v') {
                                    if (c.inst.size() < 9) return vmfgt_vv_instr(c);
                                }
                            }
                        }
                    }
                }
            }
            if (c.inst[2] == 'm') {
                if (c.inst.size() < 4) return {};
                if (c.inst[3] == 'v') {
                    if (c.inst.size() < 5) return {};
                    if (c.inst[4] == '.') {
                        if (c.inst.size() < 6) return {};
                        if (c.inst[5] == 'm') {
                            if (c.inst.size() < 7) return vmmv_m_instr(c);
                        }
                    }
                }
            }
        }
    }
    if (c.inst[0] == 'j') {
        if (c.inst.size() < 2) return j_instr(c);
    }
    return {};
}

} // namespace libchata_internal