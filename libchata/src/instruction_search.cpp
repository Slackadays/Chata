// SPDX-License-Identifier: MPL-2.0
// The generate_instruction_search.py script automatically generated this code. DO NOT MODIFY!
#include "instructions.hpp"
#include "libchata.hpp"

namespace libchata_internal {

const uint16_t fast_instr_search(const chatastring& inst) {
    if (inst.size() < 1) return instr_search_failed;
    if (inst[0] == 'a') {
        if (inst.size() < 2) return instr_search_failed;
        if (inst[1] == 'd') {
            if (inst.size() < 3) return instr_search_failed;
            if (inst[2] == 'd') {
                if (inst.size() < 4) return 27;
                if (inst[3] == '.') {
                    if (inst.size() < 5) return instr_search_failed;
                    if (inst[4] == 'u') {
                        if (inst.size() < 6) return instr_search_failed;
                        if (inst[5] == 'w') {
                            if (inst.size() < 7) return 369;
                        }
                    }
                }
                if (inst[3] == 'w') {
                    if (inst.size() < 5) return 49;
                }
                if (inst[3] == 'i') {
                    if (inst.size() < 5) return 18;
                    if (inst[4] == 'w') {
                        if (inst.size() < 6) return 45;
                    }
                }
            }
        }
        if (inst[1] == 'u') {
            if (inst.size() < 3) return instr_search_failed;
            if (inst[2] == 'i') {
                if (inst.size() < 4) return instr_search_failed;
                if (inst[3] == 'p') {
                    if (inst.size() < 5) return instr_search_failed;
                    if (inst[4] == 'c') {
                        if (inst.size() < 6) return 1;
                    }
                }
            }
        }
        if (inst[1] == 'm') {
            if (inst.size() < 3) return instr_search_failed;
            if (inst[2] == 'o') {
                if (inst.size() < 4) return instr_search_failed;
                if (inst[3] == 'a') {
                    if (inst.size() < 5) return instr_search_failed;
                    if (inst[4] == 'd') {
                        if (inst.size() < 6) return instr_search_failed;
                        if (inst[5] == 'd') {
                            if (inst.size() < 7) return instr_search_failed;
                            if (inst[6] == '.') {
                                if (inst.size() < 8) return instr_search_failed;
                                if (inst[7] == 'd') {
                                    if (inst.size() < 9) return 120;
                                    if (inst[8] == '.') {
                                        if (inst.size() < 10) return instr_search_failed;
                                        if (inst[9] == 'a') {
                                            if (inst.size() < 11) return instr_search_failed;
                                            if (inst[10] == 'q') {
                                                if (inst.size() < 12) return 129;
                                                if (inst[11] == 'r') {
                                                    if (inst.size() < 13) return instr_search_failed;
                                                    if (inst[12] == 'l') {
                                                        if (inst.size() < 14) return 147;
                                                    }
                                                }
                                            }
                                        }
                                        if (inst[9] == 'r') {
                                            if (inst.size() < 11) return instr_search_failed;
                                            if (inst[10] == 'l') {
                                                if (inst.size() < 12) return 138;
                                            }
                                        }
                                    }
                                }
                                if (inst[7] == 'w') {
                                    if (inst.size() < 9) return 76;
                                    if (inst[8] == '.') {
                                        if (inst.size() < 10) return instr_search_failed;
                                        if (inst[9] == 'a') {
                                            if (inst.size() < 11) return instr_search_failed;
                                            if (inst[10] == 'q') {
                                                if (inst.size() < 12) return 85;
                                                if (inst[11] == 'r') {
                                                    if (inst.size() < 13) return instr_search_failed;
                                                    if (inst[12] == 'l') {
                                                        if (inst.size() < 14) return 103;
                                                    }
                                                }
                                            }
                                        }
                                        if (inst[9] == 'r') {
                                            if (inst.size() < 11) return instr_search_failed;
                                            if (inst[10] == 'l') {
                                                if (inst.size() < 12) return 94;
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                    if (inst[4] == 'n') {
                        if (inst.size() < 6) return instr_search_failed;
                        if (inst[5] == 'd') {
                            if (inst.size() < 7) return instr_search_failed;
                            if (inst[6] == '.') {
                                if (inst.size() < 8) return instr_search_failed;
                                if (inst[7] == 'd') {
                                    if (inst.size() < 9) return 122;
                                    if (inst[8] == '.') {
                                        if (inst.size() < 10) return instr_search_failed;
                                        if (inst[9] == 'a') {
                                            if (inst.size() < 11) return instr_search_failed;
                                            if (inst[10] == 'q') {
                                                if (inst.size() < 12) return 131;
                                                if (inst[11] == 'r') {
                                                    if (inst.size() < 13) return instr_search_failed;
                                                    if (inst[12] == 'l') {
                                                        if (inst.size() < 14) return 149;
                                                    }
                                                }
                                            }
                                        }
                                        if (inst[9] == 'r') {
                                            if (inst.size() < 11) return instr_search_failed;
                                            if (inst[10] == 'l') {
                                                if (inst.size() < 12) return 140;
                                            }
                                        }
                                    }
                                }
                                if (inst[7] == 'w') {
                                    if (inst.size() < 9) return 78;
                                    if (inst[8] == '.') {
                                        if (inst.size() < 10) return instr_search_failed;
                                        if (inst[9] == 'a') {
                                            if (inst.size() < 11) return instr_search_failed;
                                            if (inst[10] == 'q') {
                                                if (inst.size() < 12) return 87;
                                                if (inst[11] == 'r') {
                                                    if (inst.size() < 13) return instr_search_failed;
                                                    if (inst[12] == 'l') {
                                                        if (inst.size() < 14) return 105;
                                                    }
                                                }
                                            }
                                        }
                                        if (inst[9] == 'r') {
                                            if (inst.size() < 11) return instr_search_failed;
                                            if (inst[10] == 'l') {
                                                if (inst.size() < 12) return 96;
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
                if (inst[3] == 'm') {
                    if (inst.size() < 5) return instr_search_failed;
                    if (inst[4] == 'a') {
                        if (inst.size() < 6) return instr_search_failed;
                        if (inst[5] == 'x') {
                            if (inst.size() < 7) return instr_search_failed;
                            if (inst[6] == '.') {
                                if (inst.size() < 8) return instr_search_failed;
                                if (inst[7] == 'd') {
                                    if (inst.size() < 9) return 125;
                                    if (inst[8] == '.') {
                                        if (inst.size() < 10) return instr_search_failed;
                                        if (inst[9] == 'a') {
                                            if (inst.size() < 11) return instr_search_failed;
                                            if (inst[10] == 'q') {
                                                if (inst.size() < 12) return 134;
                                                if (inst[11] == 'r') {
                                                    if (inst.size() < 13) return instr_search_failed;
                                                    if (inst[12] == 'l') {
                                                        if (inst.size() < 14) return 152;
                                                    }
                                                }
                                            }
                                        }
                                        if (inst[9] == 'r') {
                                            if (inst.size() < 11) return instr_search_failed;
                                            if (inst[10] == 'l') {
                                                if (inst.size() < 12) return 143;
                                            }
                                        }
                                    }
                                }
                                if (inst[7] == 'w') {
                                    if (inst.size() < 9) return 81;
                                    if (inst[8] == '.') {
                                        if (inst.size() < 10) return instr_search_failed;
                                        if (inst[9] == 'a') {
                                            if (inst.size() < 11) return instr_search_failed;
                                            if (inst[10] == 'q') {
                                                if (inst.size() < 12) return 90;
                                                if (inst[11] == 'r') {
                                                    if (inst.size() < 13) return instr_search_failed;
                                                    if (inst[12] == 'l') {
                                                        if (inst.size() < 14) return 108;
                                                    }
                                                }
                                            }
                                        }
                                        if (inst[9] == 'r') {
                                            if (inst.size() < 11) return instr_search_failed;
                                            if (inst[10] == 'l') {
                                                if (inst.size() < 12) return 99;
                                            }
                                        }
                                    }
                                }
                            }
                            if (inst[6] == 'u') {
                                if (inst.size() < 8) return instr_search_failed;
                                if (inst[7] == '.') {
                                    if (inst.size() < 9) return instr_search_failed;
                                    if (inst[8] == 'd') {
                                        if (inst.size() < 10) return 127;
                                        if (inst[9] == '.') {
                                            if (inst.size() < 11) return instr_search_failed;
                                            if (inst[10] == 'a') {
                                                if (inst.size() < 12) return instr_search_failed;
                                                if (inst[11] == 'q') {
                                                    if (inst.size() < 13) return 136;
                                                    if (inst[12] == 'r') {
                                                        if (inst.size() < 14) return instr_search_failed;
                                                        if (inst[13] == 'l') {
                                                            if (inst.size() < 15) return 154;
                                                        }
                                                    }
                                                }
                                            }
                                            if (inst[10] == 'r') {
                                                if (inst.size() < 12) return instr_search_failed;
                                                if (inst[11] == 'l') {
                                                    if (inst.size() < 13) return 145;
                                                }
                                            }
                                        }
                                    }
                                    if (inst[8] == 'w') {
                                        if (inst.size() < 10) return 83;
                                        if (inst[9] == '.') {
                                            if (inst.size() < 11) return instr_search_failed;
                                            if (inst[10] == 'a') {
                                                if (inst.size() < 12) return instr_search_failed;
                                                if (inst[11] == 'q') {
                                                    if (inst.size() < 13) return 92;
                                                    if (inst[12] == 'r') {
                                                        if (inst.size() < 14) return instr_search_failed;
                                                        if (inst[13] == 'l') {
                                                            if (inst.size() < 15) return 110;
                                                        }
                                                    }
                                                }
                                            }
                                            if (inst[10] == 'r') {
                                                if (inst.size() < 12) return instr_search_failed;
                                                if (inst[11] == 'l') {
                                                    if (inst.size() < 13) return 101;
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                    if (inst[4] == 'i') {
                        if (inst.size() < 6) return instr_search_failed;
                        if (inst[5] == 'n') {
                            if (inst.size() < 7) return instr_search_failed;
                            if (inst[6] == '.') {
                                if (inst.size() < 8) return instr_search_failed;
                                if (inst[7] == 'd') {
                                    if (inst.size() < 9) return 124;
                                    if (inst[8] == '.') {
                                        if (inst.size() < 10) return instr_search_failed;
                                        if (inst[9] == 'a') {
                                            if (inst.size() < 11) return instr_search_failed;
                                            if (inst[10] == 'q') {
                                                if (inst.size() < 12) return 133;
                                                if (inst[11] == 'r') {
                                                    if (inst.size() < 13) return instr_search_failed;
                                                    if (inst[12] == 'l') {
                                                        if (inst.size() < 14) return 151;
                                                    }
                                                }
                                            }
                                        }
                                        if (inst[9] == 'r') {
                                            if (inst.size() < 11) return instr_search_failed;
                                            if (inst[10] == 'l') {
                                                if (inst.size() < 12) return 142;
                                            }
                                        }
                                    }
                                }
                                if (inst[7] == 'w') {
                                    if (inst.size() < 9) return 80;
                                    if (inst[8] == '.') {
                                        if (inst.size() < 10) return instr_search_failed;
                                        if (inst[9] == 'a') {
                                            if (inst.size() < 11) return instr_search_failed;
                                            if (inst[10] == 'q') {
                                                if (inst.size() < 12) return 89;
                                                if (inst[11] == 'r') {
                                                    if (inst.size() < 13) return instr_search_failed;
                                                    if (inst[12] == 'l') {
                                                        if (inst.size() < 14) return 107;
                                                    }
                                                }
                                            }
                                        }
                                        if (inst[9] == 'r') {
                                            if (inst.size() < 11) return instr_search_failed;
                                            if (inst[10] == 'l') {
                                                if (inst.size() < 12) return 98;
                                            }
                                        }
                                    }
                                }
                            }
                            if (inst[6] == 'u') {
                                if (inst.size() < 8) return instr_search_failed;
                                if (inst[7] == '.') {
                                    if (inst.size() < 9) return instr_search_failed;
                                    if (inst[8] == 'd') {
                                        if (inst.size() < 10) return 126;
                                        if (inst[9] == '.') {
                                            if (inst.size() < 11) return instr_search_failed;
                                            if (inst[10] == 'a') {
                                                if (inst.size() < 12) return instr_search_failed;
                                                if (inst[11] == 'q') {
                                                    if (inst.size() < 13) return 135;
                                                    if (inst[12] == 'r') {
                                                        if (inst.size() < 14) return instr_search_failed;
                                                        if (inst[13] == 'l') {
                                                            if (inst.size() < 15) return 153;
                                                        }
                                                    }
                                                }
                                            }
                                            if (inst[10] == 'r') {
                                                if (inst.size() < 12) return instr_search_failed;
                                                if (inst[11] == 'l') {
                                                    if (inst.size() < 13) return 144;
                                                }
                                            }
                                        }
                                    }
                                    if (inst[8] == 'w') {
                                        if (inst.size() < 10) return 82;
                                        if (inst[9] == '.') {
                                            if (inst.size() < 11) return instr_search_failed;
                                            if (inst[10] == 'a') {
                                                if (inst.size() < 12) return instr_search_failed;
                                                if (inst[11] == 'q') {
                                                    if (inst.size() < 13) return 91;
                                                    if (inst[12] == 'r') {
                                                        if (inst.size() < 14) return instr_search_failed;
                                                        if (inst[13] == 'l') {
                                                            if (inst.size() < 15) return 109;
                                                        }
                                                    }
                                                }
                                            }
                                            if (inst[10] == 'r') {
                                                if (inst.size() < 12) return instr_search_failed;
                                                if (inst[11] == 'l') {
                                                    if (inst.size() < 13) return 100;
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
                if (inst[3] == 'o') {
                    if (inst.size() < 5) return instr_search_failed;
                    if (inst[4] == 'r') {
                        if (inst.size() < 6) return instr_search_failed;
                        if (inst[5] == '.') {
                            if (inst.size() < 7) return instr_search_failed;
                            if (inst[6] == 'd') {
                                if (inst.size() < 8) return 123;
                                if (inst[7] == '.') {
                                    if (inst.size() < 9) return instr_search_failed;
                                    if (inst[8] == 'a') {
                                        if (inst.size() < 10) return instr_search_failed;
                                        if (inst[9] == 'q') {
                                            if (inst.size() < 11) return 132;
                                            if (inst[10] == 'r') {
                                                if (inst.size() < 12) return instr_search_failed;
                                                if (inst[11] == 'l') {
                                                    if (inst.size() < 13) return 150;
                                                }
                                            }
                                        }
                                    }
                                    if (inst[8] == 'r') {
                                        if (inst.size() < 10) return instr_search_failed;
                                        if (inst[9] == 'l') {
                                            if (inst.size() < 11) return 141;
                                        }
                                    }
                                }
                            }
                            if (inst[6] == 'w') {
                                if (inst.size() < 8) return 79;
                                if (inst[7] == '.') {
                                    if (inst.size() < 9) return instr_search_failed;
                                    if (inst[8] == 'a') {
                                        if (inst.size() < 10) return instr_search_failed;
                                        if (inst[9] == 'q') {
                                            if (inst.size() < 11) return 88;
                                            if (inst[10] == 'r') {
                                                if (inst.size() < 12) return instr_search_failed;
                                                if (inst[11] == 'l') {
                                                    if (inst.size() < 13) return 106;
                                                }
                                            }
                                        }
                                    }
                                    if (inst[8] == 'r') {
                                        if (inst.size() < 10) return instr_search_failed;
                                        if (inst[9] == 'l') {
                                            if (inst.size() < 11) return 97;
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
                if (inst[3] == 'c') {
                    if (inst.size() < 5) return instr_search_failed;
                    if (inst[4] == 'a') {
                        if (inst.size() < 6) return instr_search_failed;
                        if (inst[5] == 's') {
                            if (inst.size() < 7) return instr_search_failed;
                            if (inst[6] == '.') {
                                if (inst.size() < 8) return instr_search_failed;
                                if (inst[7] == 'd') {
                                    if (inst.size() < 9) return 338;
                                    if (inst[8] == '.') {
                                        if (inst.size() < 10) return instr_search_failed;
                                        if (inst[9] == 'a') {
                                            if (inst.size() < 11) return instr_search_failed;
                                            if (inst[10] == 'q') {
                                                if (inst.size() < 12) return 341;
                                                if (inst[11] == 'r') {
                                                    if (inst.size() < 13) return instr_search_failed;
                                                    if (inst[12] == 'l') {
                                                        if (inst.size() < 14) return 347;
                                                    }
                                                }
                                            }
                                        }
                                        if (inst[9] == 'r') {
                                            if (inst.size() < 11) return instr_search_failed;
                                            if (inst[10] == 'l') {
                                                if (inst.size() < 12) return 344;
                                            }
                                        }
                                    }
                                }
                                if (inst[7] == 'w') {
                                    if (inst.size() < 9) return 337;
                                    if (inst[8] == '.') {
                                        if (inst.size() < 10) return instr_search_failed;
                                        if (inst[9] == 'a') {
                                            if (inst.size() < 11) return instr_search_failed;
                                            if (inst[10] == 'q') {
                                                if (inst.size() < 12) return 340;
                                                if (inst[11] == 'r') {
                                                    if (inst.size() < 13) return instr_search_failed;
                                                    if (inst[12] == 'l') {
                                                        if (inst.size() < 14) return 346;
                                                    }
                                                }
                                            }
                                        }
                                        if (inst[9] == 'r') {
                                            if (inst.size() < 11) return instr_search_failed;
                                            if (inst[10] == 'l') {
                                                if (inst.size() < 12) return 343;
                                            }
                                        }
                                    }
                                }
                                if (inst[7] == 'q') {
                                    if (inst.size() < 9) return 339;
                                    if (inst[8] == '.') {
                                        if (inst.size() < 10) return instr_search_failed;
                                        if (inst[9] == 'a') {
                                            if (inst.size() < 11) return instr_search_failed;
                                            if (inst[10] == 'q') {
                                                if (inst.size() < 12) return 342;
                                                if (inst[11] == 'r') {
                                                    if (inst.size() < 13) return instr_search_failed;
                                                    if (inst[12] == 'l') {
                                                        if (inst.size() < 14) return 348;
                                                    }
                                                }
                                            }
                                        }
                                        if (inst[9] == 'r') {
                                            if (inst.size() < 11) return instr_search_failed;
                                            if (inst[10] == 'l') {
                                                if (inst.size() < 12) return 345;
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
                if (inst[3] == 's') {
                    if (inst.size() < 5) return instr_search_failed;
                    if (inst[4] == 'w') {
                        if (inst.size() < 6) return instr_search_failed;
                        if (inst[5] == 'a') {
                            if (inst.size() < 7) return instr_search_failed;
                            if (inst[6] == 'p') {
                                if (inst.size() < 8) return instr_search_failed;
                                if (inst[7] == '.') {
                                    if (inst.size() < 9) return instr_search_failed;
                                    if (inst[8] == 'd') {
                                        if (inst.size() < 10) return 119;
                                        if (inst[9] == '.') {
                                            if (inst.size() < 11) return instr_search_failed;
                                            if (inst[10] == 'a') {
                                                if (inst.size() < 12) return instr_search_failed;
                                                if (inst[11] == 'q') {
                                                    if (inst.size() < 13) return 128;
                                                    if (inst[12] == 'r') {
                                                        if (inst.size() < 14) return instr_search_failed;
                                                        if (inst[13] == 'l') {
                                                            if (inst.size() < 15) return 146;
                                                        }
                                                    }
                                                }
                                            }
                                            if (inst[10] == 'r') {
                                                if (inst.size() < 12) return instr_search_failed;
                                                if (inst[11] == 'l') {
                                                    if (inst.size() < 13) return 137;
                                                }
                                            }
                                        }
                                    }
                                    if (inst[8] == 'w') {
                                        if (inst.size() < 10) return 75;
                                        if (inst[9] == '.') {
                                            if (inst.size() < 11) return instr_search_failed;
                                            if (inst[10] == 'a') {
                                                if (inst.size() < 12) return instr_search_failed;
                                                if (inst[11] == 'q') {
                                                    if (inst.size() < 13) return 84;
                                                    if (inst[12] == 'r') {
                                                        if (inst.size() < 14) return instr_search_failed;
                                                        if (inst[13] == 'l') {
                                                            if (inst.size() < 15) return 102;
                                                        }
                                                    }
                                                }
                                            }
                                            if (inst[10] == 'r') {
                                                if (inst.size() < 12) return instr_search_failed;
                                                if (inst[11] == 'l') {
                                                    if (inst.size() < 13) return 93;
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
                if (inst[3] == 'x') {
                    if (inst.size() < 5) return instr_search_failed;
                    if (inst[4] == 'o') {
                        if (inst.size() < 6) return instr_search_failed;
                        if (inst[5] == 'r') {
                            if (inst.size() < 7) return instr_search_failed;
                            if (inst[6] == '.') {
                                if (inst.size() < 8) return instr_search_failed;
                                if (inst[7] == 'd') {
                                    if (inst.size() < 9) return 121;
                                    if (inst[8] == '.') {
                                        if (inst.size() < 10) return instr_search_failed;
                                        if (inst[9] == 'a') {
                                            if (inst.size() < 11) return instr_search_failed;
                                            if (inst[10] == 'q') {
                                                if (inst.size() < 12) return 130;
                                                if (inst[11] == 'r') {
                                                    if (inst.size() < 13) return instr_search_failed;
                                                    if (inst[12] == 'l') {
                                                        if (inst.size() < 14) return 148;
                                                    }
                                                }
                                            }
                                        }
                                        if (inst[9] == 'r') {
                                            if (inst.size() < 11) return instr_search_failed;
                                            if (inst[10] == 'l') {
                                                if (inst.size() < 12) return 139;
                                            }
                                        }
                                    }
                                }
                                if (inst[7] == 'w') {
                                    if (inst.size() < 9) return 77;
                                    if (inst[8] == '.') {
                                        if (inst.size() < 10) return instr_search_failed;
                                        if (inst[9] == 'a') {
                                            if (inst.size() < 11) return instr_search_failed;
                                            if (inst[10] == 'q') {
                                                if (inst.size() < 12) return 86;
                                                if (inst[11] == 'r') {
                                                    if (inst.size() < 13) return instr_search_failed;
                                                    if (inst[12] == 'l') {
                                                        if (inst.size() < 14) return 104;
                                                    }
                                                }
                                            }
                                        }
                                        if (inst[9] == 'r') {
                                            if (inst.size() < 11) return instr_search_failed;
                                            if (inst[10] == 'l') {
                                                if (inst.size() < 12) return 95;
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
        if (inst[1] == 'n') {
            if (inst.size() < 3) return instr_search_failed;
            if (inst[2] == 'd') {
                if (inst.size() < 4) return 36;
                if (inst[3] == 'i') {
                    if (inst.size() < 5) return 23;
                }
                if (inst[3] == 'n') {
                    if (inst.size() < 5) return 370;
                }
            }
        }
    }
    if (inst[0] == 'd') {
        if (inst.size() < 2) return instr_search_failed;
        if (inst[1] == 'i') {
            if (inst.size() < 3) return instr_search_failed;
            if (inst[2] == 'v') {
                if (inst.size() < 4) return 58;
                if (inst[3] == 'u') {
                    if (inst.size() < 5) return 59;
                    if (inst[4] == 'w') {
                        if (inst.size() < 6) return 64;
                    }
                }
                if (inst[3] == 'w') {
                    if (inst.size() < 5) return 63;
                }
            }
        }
    }
    if (inst[0] == 'u') {
        if (inst.size() < 2) return instr_search_failed;
        if (inst[1] == 'n') {
            if (inst.size() < 3) return instr_search_failed;
            if (inst[2] == 'z') {
                if (inst.size() < 4) return instr_search_failed;
                if (inst[3] == 'i') {
                    if (inst.size() < 5) return instr_search_failed;
                    if (inst[4] == 'p') {
                        if (inst.size() < 6) return 414;
                    }
                }
            }
        }
    }
    if (inst[0] == 'w') {
        if (inst.size() < 2) return instr_search_failed;
        if (inst[1] == 'r') {
            if (inst.size() < 3) return instr_search_failed;
            if (inst[2] == 's') {
                if (inst.size() < 4) return instr_search_failed;
                if (inst[3] == '.') {
                    if (inst.size() < 5) return instr_search_failed;
                    if (inst[4] == 'n') {
                        if (inst.size() < 6) return instr_search_failed;
                        if (inst[5] == 't') {
                            if (inst.size() < 7) return instr_search_failed;
                            if (inst[6] == 'o') {
                                if (inst.size() < 8) return 292;
                            }
                        }
                    }
                    if (inst[4] == 's') {
                        if (inst.size() < 6) return instr_search_failed;
                        if (inst[5] == 't') {
                            if (inst.size() < 7) return instr_search_failed;
                            if (inst[6] == 'o') {
                                if (inst.size() < 8) return 293;
                            }
                        }
                    }
                }
            }
        }
    }
    if (inst[0] == 'm') {
        if (inst.size() < 2) return instr_search_failed;
        if (inst[1] == 'a') {
            if (inst.size() < 3) return instr_search_failed;
            if (inst[2] == 'x') {
                if (inst.size() < 4) return 388;
                if (inst[3] == 'u') {
                    if (inst.size() < 5) return 389;
                }
            }
        }
        if (inst[1] == 'u') {
            if (inst.size() < 3) return instr_search_failed;
            if (inst[2] == 'l') {
                if (inst.size() < 4) return 54;
                if (inst[3] == 'w') {
                    if (inst.size() < 5) return 62;
                }
                if (inst[3] == 'h') {
                    if (inst.size() < 5) return 55;
                    if (inst[4] == 'u') {
                        if (inst.size() < 6) return 57;
                    }
                    if (inst[4] == 's') {
                        if (inst.size() < 6) return instr_search_failed;
                        if (inst[5] == 'u') {
                            if (inst.size() < 7) return 56;
                        }
                    }
                }
            }
        }
        if (inst[1] == 'i') {
            if (inst.size() < 3) return instr_search_failed;
            if (inst[2] == 'n') {
                if (inst.size() < 4) return 390;
                if (inst[3] == 'u') {
                    if (inst.size() < 5) return 391;
                }
            }
        }
    }
    if (inst[0] == 'o') {
        if (inst.size() < 2) return instr_search_failed;
        if (inst[1] == 'r') {
            if (inst.size() < 3) return 35;
            if (inst[2] == 'i') {
                if (inst.size() < 4) return 22;
            }
            if (inst[2] == 'n') {
                if (inst.size() < 4) return 393;
            }
            if (inst[2] == 'c') {
                if (inst.size() < 4) return instr_search_failed;
                if (inst[3] == '.') {
                    if (inst.size() < 5) return instr_search_failed;
                    if (inst[4] == 'b') {
                        if (inst.size() < 6) return 392;
                    }
                }
            }
        }
    }
    if (inst[0] == 'r') {
        if (inst.size() < 2) return instr_search_failed;
        if (inst[1] == 'o') {
            if (inst.size() < 3) return instr_search_failed;
            if (inst[2] == 'r') {
                if (inst.size() < 4) return 401;
                if (inst[3] == 'w') {
                    if (inst.size() < 5) return 404;
                }
                if (inst[3] == 'i') {
                    if (inst.size() < 5) return 402;
                    if (inst[4] == 'w') {
                        if (inst.size() < 6) return 403;
                    }
                }
            }
            if (inst[2] == 'l') {
                if (inst.size() < 4) return 399;
                if (inst[3] == 'w') {
                    if (inst.size() < 5) return 400;
                }
            }
        }
        if (inst[1] == 'e') {
            if (inst.size() < 3) return instr_search_failed;
            if (inst[2] == 'm') {
                if (inst.size() < 4) return 60;
                if (inst[3] == 'u') {
                    if (inst.size() < 5) return 61;
                    if (inst[4] == 'w') {
                        if (inst.size() < 6) return 66;
                    }
                }
                if (inst[3] == 'w') {
                    if (inst.size() < 5) return 65;
                }
            }
            if (inst[2] == 'v') {
                if (inst.size() < 4) return instr_search_failed;
                if (inst[3] == '.') {
                    if (inst.size() < 5) return instr_search_failed;
                    if (inst[4] == 'b') {
                        if (inst.size() < 6) return 398;
                    }
                }
                if (inst[3] == '8') {
                    if (inst.size() < 5) return 397;
                }
            }
        }
    }
    if (inst[0] == 'l') {
        if (inst.size() < 2) return instr_search_failed;
        if (inst[1] == 'd') {
            if (inst.size() < 3) return 43;
        }
        if (inst[1] == 'u') {
            if (inst.size() < 3) return instr_search_failed;
            if (inst[2] == 'i') {
                if (inst.size() < 4) return 0;
            }
        }
        if (inst[1] == 'w') {
            if (inst.size() < 3) return 12;
            if (inst[2] == 'u') {
                if (inst.size() < 4) return 42;
            }
        }
        if (inst[1] == 'r') {
            if (inst.size() < 3) return instr_search_failed;
            if (inst[2] == '.') {
                if (inst.size() < 4) return instr_search_failed;
                if (inst[3] == 'd') {
                    if (inst.size() < 5) return 111;
                    if (inst[4] == '.') {
                        if (inst.size() < 6) return instr_search_failed;
                        if (inst[5] == 'a') {
                            if (inst.size() < 7) return instr_search_failed;
                            if (inst[6] == 'q') {
                                if (inst.size() < 8) return 113;
                                if (inst[7] == 'r') {
                                    if (inst.size() < 9) return instr_search_failed;
                                    if (inst[8] == 'l') {
                                        if (inst.size() < 10) return 117;
                                    }
                                }
                            }
                        }
                        if (inst[5] == 'r') {
                            if (inst.size() < 7) return instr_search_failed;
                            if (inst[6] == 'l') {
                                if (inst.size() < 8) return 115;
                            }
                        }
                    }
                }
                if (inst[3] == 'w') {
                    if (inst.size() < 5) return 67;
                    if (inst[4] == '.') {
                        if (inst.size() < 6) return instr_search_failed;
                        if (inst[5] == 'a') {
                            if (inst.size() < 7) return instr_search_failed;
                            if (inst[6] == 'q') {
                                if (inst.size() < 8) return 69;
                                if (inst[7] == 'r') {
                                    if (inst.size() < 9) return instr_search_failed;
                                    if (inst[8] == 'l') {
                                        if (inst.size() < 10) return 73;
                                    }
                                }
                            }
                        }
                        if (inst[5] == 'r') {
                            if (inst.size() < 7) return instr_search_failed;
                            if (inst[6] == 'l') {
                                if (inst.size() < 8) return 71;
                            }
                        }
                    }
                }
            }
        }
        if (inst[1] == 'b') {
            if (inst.size() < 3) return 10;
            if (inst[2] == 'u') {
                if (inst.size() < 4) return 13;
            }
        }
        if (inst[1] == 'h') {
            if (inst.size() < 3) return 11;
            if (inst[2] == 'u') {
                if (inst.size() < 4) return 14;
            }
        }
    }
    if (inst[0] == 'c') {
        if (inst.size() < 2) return instr_search_failed;
        if (inst[1] == '.') {
            if (inst.size() < 3) return instr_search_failed;
            if (inst[2] == 'a') {
                if (inst.size() < 4) return instr_search_failed;
                if (inst[3] == 'd') {
                    if (inst.size() < 5) return instr_search_failed;
                    if (inst[4] == 'd') {
                        if (inst.size() < 6) return 326;
                        if (inst[5] == 'w') {
                            if (inst.size() < 7) return 331;
                        }
                        if (inst[5] == 'i') {
                            if (inst.size() < 7) return 318;
                            if (inst[6] == 'w') {
                                if (inst.size() < 8) return 319;
                            }
                            if (inst[6] == '1') {
                                if (inst.size() < 8) return instr_search_failed;
                                if (inst[7] == '6') {
                                    if (inst.size() < 9) return instr_search_failed;
                                    if (inst[8] == 's') {
                                        if (inst.size() < 10) return instr_search_failed;
                                        if (inst[9] == 'p') {
                                            if (inst.size() < 11) return 320;
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
                if (inst[3] == 'n') {
                    if (inst.size() < 5) return instr_search_failed;
                    if (inst[4] == 'd') {
                        if (inst.size() < 6) return 327;
                        if (inst[5] == 'i') {
                            if (inst.size() < 7) return 324;
                        }
                    }
                }
            }
            if (inst[2] == 'm') {
                if (inst.size() < 4) return instr_search_failed;
                if (inst[3] == 'u') {
                    if (inst.size() < 5) return instr_search_failed;
                    if (inst[4] == 'l') {
                        if (inst.size() < 6) return 360;
                    }
                }
                if (inst[3] == 'v') {
                    if (inst.size() < 5) return 325;
                }
            }
            if (inst[2] == 'o') {
                if (inst.size() < 4) return instr_search_failed;
                if (inst[3] == 'r') {
                    if (inst.size() < 5) return 328;
                }
            }
            if (inst[2] == 'l') {
                if (inst.size() < 4) return instr_search_failed;
                if (inst[3] == 'd') {
                    if (inst.size() < 5) return 303;
                    if (inst[4] == 's') {
                        if (inst.size() < 6) return instr_search_failed;
                        if (inst[5] == 'p') {
                            if (inst.size() < 7) return 295;
                        }
                    }
                }
                if (inst[3] == 'u') {
                    if (inst.size() < 5) return instr_search_failed;
                    if (inst[4] == 'i') {
                        if (inst.size() < 6) return 317;
                    }
                }
                if (inst[3] == 'w') {
                    if (inst.size() < 5) return 302;
                    if (inst[4] == 's') {
                        if (inst.size() < 6) return instr_search_failed;
                        if (inst[5] == 'p') {
                            if (inst.size() < 7) return 294;
                        }
                    }
                }
                if (inst[3] == 'i') {
                    if (inst.size() < 5) return 316;
                }
                if (inst[3] == 'b') {
                    if (inst.size() < 5) return instr_search_failed;
                    if (inst[4] == 'u') {
                        if (inst.size() < 6) return 349;
                    }
                }
                if (inst[3] == 'h') {
                    if (inst.size() < 5) return 351;
                    if (inst[4] == 'u') {
                        if (inst.size() < 6) return 350;
                    }
                }
            }
            if (inst[2] == 'n') {
                if (inst.size() < 4) return instr_search_failed;
                if (inst[3] == 'o') {
                    if (inst.size() < 5) return instr_search_failed;
                    if (inst[4] == 'p') {
                        if (inst.size() < 6) return 333;
                    }
                    if (inst[4] == 't') {
                        if (inst.size() < 6) return 359;
                    }
                }
            }
            if (inst[2] == 's') {
                if (inst.size() < 4) return instr_search_failed;
                if (inst[3] == 'd') {
                    if (inst.size() < 5) return 307;
                    if (inst[4] == 's') {
                        if (inst.size() < 6) return instr_search_failed;
                        if (inst[5] == 'p') {
                            if (inst.size() < 7) return 299;
                        }
                    }
                }
                if (inst[3] == 'u') {
                    if (inst.size() < 5) return instr_search_failed;
                    if (inst[4] == 'b') {
                        if (inst.size() < 6) return 330;
                        if (inst[5] == 'w') {
                            if (inst.size() < 7) return 332;
                        }
                    }
                }
                if (inst[3] == 'w') {
                    if (inst.size() < 5) return 306;
                    if (inst[4] == 's') {
                        if (inst.size() < 6) return instr_search_failed;
                        if (inst[5] == 'p') {
                            if (inst.size() < 7) return 298;
                        }
                    }
                }
                if (inst[3] == 'r') {
                    if (inst.size() < 5) return instr_search_failed;
                    if (inst[4] == 'a') {
                        if (inst.size() < 6) return instr_search_failed;
                        if (inst[5] == 'i') {
                            if (inst.size() < 7) return 323;
                        }
                    }
                    if (inst[4] == 'l') {
                        if (inst.size() < 6) return instr_search_failed;
                        if (inst[5] == 'i') {
                            if (inst.size() < 7) return 322;
                        }
                    }
                }
                if (inst[3] == 'l') {
                    if (inst.size() < 5) return instr_search_failed;
                    if (inst[4] == 'l') {
                        if (inst.size() < 6) return instr_search_failed;
                        if (inst[5] == 'i') {
                            if (inst.size() < 7) return 321;
                        }
                    }
                }
                if (inst[3] == 'b') {
                    if (inst.size() < 5) return 352;
                }
                if (inst[3] == 'e') {
                    if (inst.size() < 5) return instr_search_failed;
                    if (inst[4] == 'x') {
                        if (inst.size() < 6) return instr_search_failed;
                        if (inst[5] == 't') {
                            if (inst.size() < 7) return instr_search_failed;
                            if (inst[6] == '.') {
                                if (inst.size() < 8) return instr_search_failed;
                                if (inst[7] == 'b') {
                                    if (inst.size() < 9) return 355;
                                }
                                if (inst[7] == 'h') {
                                    if (inst.size() < 9) return 357;
                                }
                            }
                        }
                    }
                }
                if (inst[3] == 'h') {
                    if (inst.size() < 5) return 353;
                }
            }
            if (inst[2] == 'x') {
                if (inst.size() < 4) return instr_search_failed;
                if (inst[3] == 'o') {
                    if (inst.size() < 5) return instr_search_failed;
                    if (inst[4] == 'r') {
                        if (inst.size() < 6) return 329;
                    }
                }
            }
            if (inst[2] == 'b') {
                if (inst.size() < 4) return instr_search_failed;
                if (inst[3] == 'n') {
                    if (inst.size() < 5) return instr_search_failed;
                    if (inst[4] == 'e') {
                        if (inst.size() < 6) return instr_search_failed;
                        if (inst[5] == 'z') {
                            if (inst.size() < 7) return 315;
                        }
                    }
                }
                if (inst[3] == 'e') {
                    if (inst.size() < 5) return instr_search_failed;
                    if (inst[4] == 'q') {
                        if (inst.size() < 6) return instr_search_failed;
                        if (inst[5] == 'z') {
                            if (inst.size() < 7) return 314;
                        }
                    }
                }
            }
            if (inst[2] == 'e') {
                if (inst.size() < 4) return instr_search_failed;
                if (inst[3] == 'b') {
                    if (inst.size() < 5) return instr_search_failed;
                    if (inst[4] == 'r') {
                        if (inst.size() < 6) return instr_search_failed;
                        if (inst[5] == 'e') {
                            if (inst.size() < 7) return instr_search_failed;
                            if (inst[6] == 'a') {
                                if (inst.size() < 8) return instr_search_failed;
                                if (inst[7] == 'k') {
                                    if (inst.size() < 9) return 334;
                                }
                            }
                        }
                    }
                }
            }
            if (inst[2] == 'z') {
                if (inst.size() < 4) return instr_search_failed;
                if (inst[3] == 'e') {
                    if (inst.size() < 5) return instr_search_failed;
                    if (inst[4] == 'x') {
                        if (inst.size() < 6) return instr_search_failed;
                        if (inst[5] == 't') {
                            if (inst.size() < 7) return instr_search_failed;
                            if (inst[6] == '.') {
                                if (inst.size() < 8) return instr_search_failed;
                                if (inst[7] == 'w') {
                                    if (inst.size() < 9) return 358;
                                }
                                if (inst[7] == 'b') {
                                    if (inst.size() < 9) return 354;
                                }
                                if (inst[7] == 'h') {
                                    if (inst.size() < 9) return 356;
                                }
                            }
                        }
                    }
                }
            }
            if (inst[2] == 'f') {
                if (inst.size() < 4) return instr_search_failed;
                if (inst[3] == 'l') {
                    if (inst.size() < 5) return instr_search_failed;
                    if (inst[4] == 'd') {
                        if (inst.size() < 6) return 305;
                        if (inst[5] == 's') {
                            if (inst.size() < 7) return instr_search_failed;
                            if (inst[6] == 'p') {
                                if (inst.size() < 8) return 297;
                            }
                        }
                    }
                    if (inst[4] == 'w') {
                        if (inst.size() < 6) return 304;
                        if (inst[5] == 's') {
                            if (inst.size() < 7) return instr_search_failed;
                            if (inst[6] == 'p') {
                                if (inst.size() < 8) return 296;
                            }
                        }
                    }
                }
                if (inst[3] == 's') {
                    if (inst.size() < 5) return instr_search_failed;
                    if (inst[4] == 'd') {
                        if (inst.size() < 6) return 309;
                        if (inst[5] == 's') {
                            if (inst.size() < 7) return instr_search_failed;
                            if (inst[6] == 'p') {
                                if (inst.size() < 8) return 301;
                            }
                        }
                    }
                    if (inst[4] == 'w') {
                        if (inst.size() < 6) return 308;
                        if (inst[5] == 's') {
                            if (inst.size() < 7) return instr_search_failed;
                            if (inst[6] == 'p') {
                                if (inst.size() < 8) return 300;
                            }
                        }
                    }
                }
            }
            if (inst[2] == 'j') {
                if (inst.size() < 4) return 310;
                if (inst[3] == 'a') {
                    if (inst.size() < 5) return instr_search_failed;
                    if (inst[4] == 'l') {
                        if (inst.size() < 6) return 311;
                        if (inst[5] == 'r') {
                            if (inst.size() < 7) return 313;
                        }
                    }
                }
                if (inst[3] == 'r') {
                    if (inst.size() < 5) return 312;
                }
            }
        }
        if (inst[1] == 'm') {
            if (inst.size() < 3) return instr_search_failed;
            if (inst[2] == '.') {
                if (inst.size() < 4) return instr_search_failed;
                if (inst[3] == 'm') {
                    if (inst.size() < 5) return instr_search_failed;
                    if (inst[4] == 'v') {
                        if (inst.size() < 6) return instr_search_failed;
                        if (inst[5] == 'a') {
                            if (inst.size() < 7) return instr_search_failed;
                            if (inst[6] == '0') {
                                if (inst.size() < 8) return instr_search_failed;
                                if (inst[7] == '1') {
                                    if (inst.size() < 9) return instr_search_failed;
                                    if (inst[8] == 's') {
                                        if (inst.size() < 10) return 366;
                                    }
                                }
                            }
                        }
                        if (inst[5] == 's') {
                            if (inst.size() < 7) return instr_search_failed;
                            if (inst[6] == 'a') {
                                if (inst.size() < 8) return instr_search_failed;
                                if (inst[7] == '0') {
                                    if (inst.size() < 9) return instr_search_failed;
                                    if (inst[8] == '1') {
                                        if (inst.size() < 10) return 365;
                                    }
                                }
                            }
                        }
                    }
                }
                if (inst[3] == 'p') {
                    if (inst.size() < 5) return instr_search_failed;
                    if (inst[4] == 'u') {
                        if (inst.size() < 6) return instr_search_failed;
                        if (inst[5] == 's') {
                            if (inst.size() < 7) return instr_search_failed;
                            if (inst[6] == 'h') {
                                if (inst.size() < 8) return 361;
                            }
                        }
                    }
                    if (inst[4] == 'o') {
                        if (inst.size() < 6) return instr_search_failed;
                        if (inst[5] == 'p') {
                            if (inst.size() < 7) return 362;
                            if (inst[6] == 'r') {
                                if (inst.size() < 8) return instr_search_failed;
                                if (inst[7] == 'e') {
                                    if (inst.size() < 9) return instr_search_failed;
                                    if (inst[8] == 't') {
                                        if (inst.size() < 10) return 364;
                                        if (inst[9] == 'z') {
                                            if (inst.size() < 11) return 363;
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
                if (inst[3] == 'j') {
                    if (inst.size() < 5) return instr_search_failed;
                    if (inst[4] == 'a') {
                        if (inst.size() < 6) return instr_search_failed;
                        if (inst[5] == 'l') {
                            if (inst.size() < 7) return instr_search_failed;
                            if (inst[6] == 't') {
                                if (inst.size() < 8) return 368;
                            }
                        }
                    }
                    if (inst[4] == 't') {
                        if (inst.size() < 6) return 367;
                    }
                }
            }
        }
        if (inst[1] == 'l') {
            if (inst.size() < 3) return instr_search_failed;
            if (inst[2] == 'm') {
                if (inst.size() < 4) return instr_search_failed;
                if (inst[3] == 'u') {
                    if (inst.size() < 5) return instr_search_failed;
                    if (inst[4] == 'l') {
                        if (inst.size() < 6) return 379;
                        if (inst[5] == 'r') {
                            if (inst.size() < 7) return 381;
                        }
                        if (inst[5] == 'h') {
                            if (inst.size() < 7) return 380;
                        }
                    }
                }
            }
            if (inst[2] == 'z') {
                if (inst.size() < 4) return 382;
                if (inst[3] == 'w') {
                    if (inst.size() < 5) return 383;
                }
            }
        }
        if (inst[1] == 's') {
            if (inst.size() < 3) return instr_search_failed;
            if (inst[2] == 'r') {
                if (inst.size() < 4) return instr_search_failed;
                if (inst[3] == 'r') {
                    if (inst.size() < 5) return instr_search_failed;
                    if (inst[4] == 'w') {
                        if (inst.size() < 6) return 286;
                        if (inst[5] == 'i') {
                            if (inst.size() < 7) return 289;
                        }
                    }
                    if (inst[4] == 'c') {
                        if (inst.size() < 6) return 288;
                        if (inst[5] == 'i') {
                            if (inst.size() < 7) return 291;
                        }
                    }
                    if (inst[4] == 's') {
                        if (inst.size() < 6) return 287;
                        if (inst[5] == 'i') {
                            if (inst.size() < 7) return 290;
                        }
                    }
                }
            }
        }
        if (inst[1] == 'p') {
            if (inst.size() < 3) return instr_search_failed;
            if (inst[2] == 'o') {
                if (inst.size() < 4) return instr_search_failed;
                if (inst[3] == 'p') {
                    if (inst.size() < 5) return 384;
                    if (inst[4] == 'w') {
                        if (inst.size() < 6) return 385;
                    }
                }
            }
        }
        if (inst[1] == 't') {
            if (inst.size() < 3) return instr_search_failed;
            if (inst[2] == 'z') {
                if (inst.size() < 4) return 386;
                if (inst[3] == 'w') {
                    if (inst.size() < 5) return 387;
                }
            }
        }
        if (inst[1] == 'z') {
            if (inst.size() < 3) return instr_search_failed;
            if (inst[2] == 'e') {
                if (inst.size() < 4) return instr_search_failed;
                if (inst[3] == 'r') {
                    if (inst.size() < 5) return instr_search_failed;
                    if (inst[4] == 'o') {
                        if (inst.size() < 6) return instr_search_failed;
                        if (inst[5] == '.') {
                            if (inst.size() < 7) return instr_search_failed;
                            if (inst[6] == 'n') {
                                if (inst.size() < 8) return instr_search_failed;
                                if (inst[7] == 'e') {
                                    if (inst.size() < 9) return instr_search_failed;
                                    if (inst[8] == 'z') {
                                        if (inst.size() < 10) return 336;
                                    }
                                }
                            }
                            if (inst[6] == 'e') {
                                if (inst.size() < 8) return instr_search_failed;
                                if (inst[7] == 'q') {
                                    if (inst.size() < 9) return instr_search_failed;
                                    if (inst[8] == 'z') {
                                        if (inst.size() < 10) return 335;
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    if (inst[0] == 's') {
        if (inst.size() < 2) return instr_search_failed;
        if (inst[1] == 'd') {
            if (inst.size() < 3) return 44;
        }
        if (inst[1] == 'u') {
            if (inst.size() < 3) return instr_search_failed;
            if (inst[2] == 'b') {
                if (inst.size() < 4) return 28;
                if (inst[3] == 'w') {
                    if (inst.size() < 5) return 50;
                }
            }
        }
        if (inst[1] == 'w') {
            if (inst.size() < 3) return 17;
        }
        if (inst[1] == 'r') {
            if (inst.size() < 3) return instr_search_failed;
            if (inst[2] == 'a') {
                if (inst.size() < 4) return 34;
                if (inst[3] == 'w') {
                    if (inst.size() < 5) return 53;
                }
                if (inst[3] == 'i') {
                    if (inst.size() < 5) return 26;
                    if (inst[4] == 'w') {
                        if (inst.size() < 6) return 48;
                    }
                }
            }
            if (inst[2] == 'l') {
                if (inst.size() < 4) return 33;
                if (inst[3] == 'w') {
                    if (inst.size() < 5) return 52;
                }
                if (inst[3] == 'i') {
                    if (inst.size() < 5) return 25;
                    if (inst[4] == 'w') {
                        if (inst.size() < 6) return 47;
                    }
                }
            }
        }
        if (inst[1] == 'l') {
            if (inst.size() < 3) return instr_search_failed;
            if (inst[2] == 'l') {
                if (inst.size() < 4) return 29;
                if (inst[3] == 'w') {
                    if (inst.size() < 5) return 51;
                }
                if (inst[3] == 'i') {
                    if (inst.size() < 5) return 24;
                    if (inst[4] == '.') {
                        if (inst.size() < 6) return instr_search_failed;
                        if (inst[5] == 'u') {
                            if (inst.size() < 7) return instr_search_failed;
                            if (inst[6] == 'w') {
                                if (inst.size() < 8) return 413;
                            }
                        }
                    }
                    if (inst[4] == 'w') {
                        if (inst.size() < 6) return 46;
                    }
                }
            }
            if (inst[2] == 't') {
                if (inst.size() < 4) return 30;
                if (inst[3] == 'u') {
                    if (inst.size() < 5) return 31;
                }
                if (inst[3] == 'i') {
                    if (inst.size() < 5) return 19;
                    if (inst[4] == 'u') {
                        if (inst.size() < 6) return 20;
                    }
                }
            }
        }
        if (inst[1] == 'c') {
            if (inst.size() < 3) return instr_search_failed;
            if (inst[2] == '.') {
                if (inst.size() < 4) return instr_search_failed;
                if (inst[3] == 'd') {
                    if (inst.size() < 5) return 112;
                    if (inst[4] == '.') {
                        if (inst.size() < 6) return instr_search_failed;
                        if (inst[5] == 'a') {
                            if (inst.size() < 7) return instr_search_failed;
                            if (inst[6] == 'q') {
                                if (inst.size() < 8) return 114;
                                if (inst[7] == 'r') {
                                    if (inst.size() < 9) return instr_search_failed;
                                    if (inst[8] == 'l') {
                                        if (inst.size() < 10) return 118;
                                    }
                                }
                            }
                        }
                        if (inst[5] == 'r') {
                            if (inst.size() < 7) return instr_search_failed;
                            if (inst[6] == 'l') {
                                if (inst.size() < 8) return 116;
                            }
                        }
                    }
                }
                if (inst[3] == 'w') {
                    if (inst.size() < 5) return 68;
                    if (inst[4] == '.') {
                        if (inst.size() < 6) return instr_search_failed;
                        if (inst[5] == 'a') {
                            if (inst.size() < 7) return instr_search_failed;
                            if (inst[6] == 'q') {
                                if (inst.size() < 8) return 70;
                                if (inst[7] == 'r') {
                                    if (inst.size() < 9) return instr_search_failed;
                                    if (inst[8] == 'l') {
                                        if (inst.size() < 10) return 74;
                                    }
                                }
                            }
                        }
                        if (inst[5] == 'r') {
                            if (inst.size() < 7) return instr_search_failed;
                            if (inst[6] == 'l') {
                                if (inst.size() < 8) return 72;
                            }
                        }
                    }
                }
            }
        }
        if (inst[1] == 'b') {
            if (inst.size() < 3) return 15;
        }
        if (inst[1] == 'e') {
            if (inst.size() < 3) return instr_search_failed;
            if (inst[2] == 'x') {
                if (inst.size() < 4) return instr_search_failed;
                if (inst[3] == 't') {
                    if (inst.size() < 5) return instr_search_failed;
                    if (inst[4] == '.') {
                        if (inst.size() < 6) return instr_search_failed;
                        if (inst[5] == 'b') {
                            if (inst.size() < 7) return 405;
                        }
                        if (inst[5] == 'h') {
                            if (inst.size() < 7) return 406;
                        }
                    }
                }
            }
        }
        if (inst[1] == 'h') {
            if (inst.size() < 3) return 16;
            if (inst[2] == '1') {
                if (inst.size() < 4) return instr_search_failed;
                if (inst[3] == 'a') {
                    if (inst.size() < 5) return instr_search_failed;
                    if (inst[4] == 'd') {
                        if (inst.size() < 6) return instr_search_failed;
                        if (inst[5] == 'd') {
                            if (inst.size() < 7) return 407;
                        }
                    }
                }
            }
            if (inst[2] == '2') {
                if (inst.size() < 4) return instr_search_failed;
                if (inst[3] == 'a') {
                    if (inst.size() < 5) return instr_search_failed;
                    if (inst[4] == 'd') {
                        if (inst.size() < 6) return instr_search_failed;
                        if (inst[5] == 'd') {
                            if (inst.size() < 7) return 409;
                            if (inst[6] == '.') {
                                if (inst.size() < 8) return instr_search_failed;
                                if (inst[7] == 'u') {
                                    if (inst.size() < 9) return instr_search_failed;
                                    if (inst[8] == 'w') {
                                        if (inst.size() < 10) return 408;
                                    }
                                }
                            }
                        }
                    }
                }
            }
            if (inst[2] == '3') {
                if (inst.size() < 4) return instr_search_failed;
                if (inst[3] == 'a') {
                    if (inst.size() < 5) return instr_search_failed;
                    if (inst[4] == 'd') {
                        if (inst.size() < 6) return instr_search_failed;
                        if (inst[5] == 'd') {
                            if (inst.size() < 7) return 411;
                            if (inst[6] == '.') {
                                if (inst.size() < 8) return instr_search_failed;
                                if (inst[7] == 'u') {
                                    if (inst.size() < 9) return instr_search_failed;
                                    if (inst[8] == 'w') {
                                        if (inst.size() < 10) return 412;
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    if (inst[0] == 'x') {
        if (inst.size() < 2) return instr_search_failed;
        if (inst[1] == 'o') {
            if (inst.size() < 3) return instr_search_failed;
            if (inst[2] == 'r') {
                if (inst.size() < 4) return 32;
                if (inst[3] == 'i') {
                    if (inst.size() < 5) return 21;
                }
            }
        }
        if (inst[1] == 'n') {
            if (inst.size() < 3) return instr_search_failed;
            if (inst[2] == 'o') {
                if (inst.size() < 4) return instr_search_failed;
                if (inst[3] == 'r') {
                    if (inst.size() < 5) return 415;
                }
            }
        }
        if (inst[1] == 'p') {
            if (inst.size() < 3) return instr_search_failed;
            if (inst[2] == 'e') {
                if (inst.size() < 4) return instr_search_failed;
                if (inst[3] == 'r') {
                    if (inst.size() < 5) return instr_search_failed;
                    if (inst[4] == 'm') {
                        if (inst.size() < 6) return instr_search_failed;
                        if (inst[5] == '.') {
                            if (inst.size() < 7) return instr_search_failed;
                            if (inst[6] == 'n') {
                                if (inst.size() < 8) return 417;
                            }
                            if (inst[6] == 'b') {
                                if (inst.size() < 8) return 416;
                            }
                        }
                    }
                }
            }
        }
    }
    if (inst[0] == 'p') {
        if (inst.size() < 2) return instr_search_failed;
        if (inst[1] == 'a') {
            if (inst.size() < 3) return instr_search_failed;
            if (inst[2] == 'u') {
                if (inst.size() < 4) return instr_search_failed;
                if (inst[3] == 's') {
                    if (inst.size() < 5) return instr_search_failed;
                    if (inst[4] == 'e') {
                        if (inst.size() < 6) return 39;
                    }
                }
            }
            if (inst[2] == 'c') {
                if (inst.size() < 4) return instr_search_failed;
                if (inst[3] == 'k') {
                    if (inst.size() < 5) return 394;
                    if (inst[4] == 'w') {
                        if (inst.size() < 6) return 396;
                    }
                    if (inst[4] == 'h') {
                        if (inst.size() < 6) return 395;
                    }
                }
            }
        }
    }
    if (inst[0] == 'b') {
        if (inst.size() < 2) return instr_search_failed;
        if (inst[1] == 'i') {
            if (inst.size() < 3) return instr_search_failed;
            if (inst[2] == 'n') {
                if (inst.size() < 4) return instr_search_failed;
                if (inst[3] == 'v') {
                    if (inst.size() < 5) return 375;
                    if (inst[4] == 'i') {
                        if (inst.size() < 6) return 376;
                    }
                }
            }
        }
        if (inst[1] == 'l') {
            if (inst.size() < 3) return instr_search_failed;
            if (inst[2] == 't') {
                if (inst.size() < 4) return 6;
                if (inst[3] == 'u') {
                    if (inst.size() < 5) return 8;
                }
            }
        }
        if (inst[1] == 'n') {
            if (inst.size() < 3) return instr_search_failed;
            if (inst[2] == 'e') {
                if (inst.size() < 4) return 5;
            }
        }
        if (inst[1] == 'c') {
            if (inst.size() < 3) return instr_search_failed;
            if (inst[2] == 'l') {
                if (inst.size() < 4) return instr_search_failed;
                if (inst[3] == 'r') {
                    if (inst.size() < 5) return 371;
                    if (inst[4] == 'i') {
                        if (inst.size() < 6) return 372;
                    }
                }
            }
        }
        if (inst[1] == 's') {
            if (inst.size() < 3) return instr_search_failed;
            if (inst[2] == 'e') {
                if (inst.size() < 4) return instr_search_failed;
                if (inst[3] == 't') {
                    if (inst.size() < 5) return 377;
                    if (inst[4] == 'i') {
                        if (inst.size() < 6) return 378;
                    }
                }
            }
        }
        if (inst[1] == 'e') {
            if (inst.size() < 3) return instr_search_failed;
            if (inst[2] == 'q') {
                if (inst.size() < 4) return 4;
            }
            if (inst[2] == 'x') {
                if (inst.size() < 4) return instr_search_failed;
                if (inst[3] == 't') {
                    if (inst.size() < 5) return 373;
                    if (inst[4] == 'i') {
                        if (inst.size() < 6) return 374;
                    }
                }
            }
        }
        if (inst[1] == 'g') {
            if (inst.size() < 3) return instr_search_failed;
            if (inst[2] == 'e') {
                if (inst.size() < 4) return 7;
                if (inst[3] == 'u') {
                    if (inst.size() < 5) return 9;
                }
            }
        }
    }
    if (inst[0] == 'e') {
        if (inst.size() < 2) return instr_search_failed;
        if (inst[1] == 'c') {
            if (inst.size() < 3) return instr_search_failed;
            if (inst[2] == 'a') {
                if (inst.size() < 4) return instr_search_failed;
                if (inst[3] == 'l') {
                    if (inst.size() < 5) return instr_search_failed;
                    if (inst[4] == 'l') {
                        if (inst.size() < 6) return 40;
                    }
                }
            }
        }
        if (inst[1] == 'b') {
            if (inst.size() < 3) return instr_search_failed;
            if (inst[2] == 'r') {
                if (inst.size() < 4) return instr_search_failed;
                if (inst[3] == 'e') {
                    if (inst.size() < 5) return instr_search_failed;
                    if (inst[4] == 'a') {
                        if (inst.size() < 6) return instr_search_failed;
                        if (inst[5] == 'k') {
                            if (inst.size() < 7) return 41;
                        }
                    }
                }
            }
        }
    }
    if (inst[0] == 'v') {
        if (inst.size() < 2) return instr_search_failed;
        if (inst[1] == 'a') {
            if (inst.size() < 3) return instr_search_failed;
            if (inst[2] == 'a') {
                if (inst.size() < 4) return instr_search_failed;
                if (inst[3] == 'd') {
                    if (inst.size() < 5) return instr_search_failed;
                    if (inst[4] == 'd') {
                        if (inst.size() < 6) return instr_search_failed;
                        if (inst[5] == '.') {
                            if (inst.size() < 7) return instr_search_failed;
                            if (inst[6] == 'v') {
                                if (inst.size() < 8) return instr_search_failed;
                                if (inst[7] == 'x') {
                                    if (inst.size() < 9) return 885;
                                }
                                if (inst[7] == 'v') {
                                    if (inst.size() < 9) return 884;
                                }
                            }
                        }
                        if (inst[5] == 'u') {
                            if (inst.size() < 7) return instr_search_failed;
                            if (inst[6] == '.') {
                                if (inst.size() < 8) return instr_search_failed;
                                if (inst[7] == 'v') {
                                    if (inst.size() < 9) return instr_search_failed;
                                    if (inst[8] == 'x') {
                                        if (inst.size() < 10) return 883;
                                    }
                                    if (inst[8] == 'v') {
                                        if (inst.size() < 10) return 882;
                                    }
                                }
                            }
                        }
                    }
                }
            }
            if (inst[2] == 'd') {
                if (inst.size() < 4) return instr_search_failed;
                if (inst[3] == 'd') {
                    if (inst.size() < 5) return instr_search_failed;
                    if (inst[4] == '.') {
                        if (inst.size() < 6) return instr_search_failed;
                        if (inst[5] == 'v') {
                            if (inst.size() < 7) return instr_search_failed;
                            if (inst[6] == 'i') {
                                if (inst.size() < 8) return 735;
                            }
                            if (inst[6] == 'x') {
                                if (inst.size() < 8) return 734;
                            }
                            if (inst[6] == 'v') {
                                if (inst.size() < 8) return 733;
                            }
                        }
                    }
                }
                if (inst[3] == 'c') {
                    if (inst.size() < 5) return instr_search_failed;
                    if (inst[4] == '.') {
                        if (inst.size() < 6) return instr_search_failed;
                        if (inst[5] == 'v') {
                            if (inst.size() < 7) return instr_search_failed;
                            if (inst[6] == 'i') {
                                if (inst.size() < 8) return instr_search_failed;
                                if (inst[7] == 'm') {
                                    if (inst.size() < 9) return 764;
                                }
                            }
                            if (inst[6] == 'x') {
                                if (inst.size() < 8) return instr_search_failed;
                                if (inst[7] == 'm') {
                                    if (inst.size() < 9) return 763;
                                }
                            }
                            if (inst[6] == 'v') {
                                if (inst.size() < 8) return instr_search_failed;
                                if (inst[7] == 'm') {
                                    if (inst.size() < 9) return 762;
                                }
                            }
                        }
                    }
                }
            }
            if (inst[2] == 'n') {
                if (inst.size() < 4) return instr_search_failed;
                if (inst[3] == 'd') {
                    if (inst.size() < 5) return instr_search_failed;
                    if (inst[4] == '.') {
                        if (inst.size() < 6) return instr_search_failed;
                        if (inst[5] == 'v') {
                            if (inst.size() < 7) return instr_search_failed;
                            if (inst[6] == 'i') {
                                if (inst.size() < 8) return 779;
                            }
                            if (inst[6] == 'x') {
                                if (inst.size() < 8) return 778;
                            }
                            if (inst[6] == 'v') {
                                if (inst.size() < 8) return 777;
                            }
                        }
                    }
                }
            }
            if (inst[2] == 's') {
                if (inst.size() < 4) return instr_search_failed;
                if (inst[3] == 'u') {
                    if (inst.size() < 5) return instr_search_failed;
                    if (inst[4] == 'b') {
                        if (inst.size() < 6) return instr_search_failed;
                        if (inst[5] == '.') {
                            if (inst.size() < 7) return instr_search_failed;
                            if (inst[6] == 'v') {
                                if (inst.size() < 8) return instr_search_failed;
                                if (inst[7] == 'x') {
                                    if (inst.size() < 9) return 889;
                                }
                                if (inst[7] == 'v') {
                                    if (inst.size() < 9) return 888;
                                }
                            }
                        }
                        if (inst[5] == 'u') {
                            if (inst.size() < 7) return instr_search_failed;
                            if (inst[6] == '.') {
                                if (inst.size() < 8) return instr_search_failed;
                                if (inst[7] == 'v') {
                                    if (inst.size() < 9) return instr_search_failed;
                                    if (inst[8] == 'x') {
                                        if (inst.size() < 10) return 887;
                                    }
                                    if (inst[8] == 'v') {
                                        if (inst.size() < 10) return 886;
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
        if (inst[1] == 'd') {
            if (inst.size() < 3) return instr_search_failed;
            if (inst[2] == 'i') {
                if (inst.size() < 4) return instr_search_failed;
                if (inst[3] == 'v') {
                    if (inst.size() < 5) return instr_search_failed;
                    if (inst[4] == '.') {
                        if (inst.size() < 6) return instr_search_failed;
                        if (inst[5] == 'v') {
                            if (inst.size() < 7) return instr_search_failed;
                            if (inst[6] == 'x') {
                                if (inst.size() < 8) return 840;
                            }
                            if (inst[6] == 'v') {
                                if (inst.size() < 8) return 839;
                            }
                        }
                    }
                    if (inst[4] == 'u') {
                        if (inst.size() < 6) return instr_search_failed;
                        if (inst[5] == '.') {
                            if (inst.size() < 7) return instr_search_failed;
                            if (inst[6] == 'v') {
                                if (inst.size() < 8) return instr_search_failed;
                                if (inst[7] == 'x') {
                                    if (inst.size() < 9) return 838;
                                }
                                if (inst[7] == 'v') {
                                    if (inst.size() < 9) return 837;
                                }
                            }
                        }
                    }
                }
            }
        }
        if (inst[1] == 'w') {
            if (inst.size() < 3) return instr_search_failed;
            if (inst[2] == 'a') {
                if (inst.size() < 4) return instr_search_failed;
                if (inst[3] == 'd') {
                    if (inst.size() < 5) return instr_search_failed;
                    if (inst[4] == 'd') {
                        if (inst.size() < 6) return instr_search_failed;
                        if (inst[5] == '.') {
                            if (inst.size() < 7) return instr_search_failed;
                            if (inst[6] == 'w') {
                                if (inst.size() < 8) return instr_search_failed;
                                if (inst[7] == 'x') {
                                    if (inst.size() < 9) return 753;
                                }
                                if (inst[7] == 'v') {
                                    if (inst.size() < 9) return 752;
                                }
                            }
                            if (inst[6] == 'v') {
                                if (inst.size() < 8) return instr_search_failed;
                                if (inst[7] == 'x') {
                                    if (inst.size() < 9) return 745;
                                }
                                if (inst[7] == 'v') {
                                    if (inst.size() < 9) return 744;
                                }
                            }
                        }
                        if (inst[5] == 'u') {
                            if (inst.size() < 7) return instr_search_failed;
                            if (inst[6] == '.') {
                                if (inst.size() < 8) return instr_search_failed;
                                if (inst[7] == 'w') {
                                    if (inst.size() < 9) return instr_search_failed;
                                    if (inst[8] == 'x') {
                                        if (inst.size() < 10) return 749;
                                    }
                                    if (inst[8] == 'v') {
                                        if (inst.size() < 10) return 748;
                                    }
                                }
                                if (inst[7] == 'v') {
                                    if (inst.size() < 9) return instr_search_failed;
                                    if (inst[8] == 'x') {
                                        if (inst.size() < 10) return 741;
                                    }
                                    if (inst[8] == 'v') {
                                        if (inst.size() < 10) return 740;
                                    }
                                }
                            }
                        }
                    }
                }
            }
            if (inst[2] == 'm') {
                if (inst.size() < 4) return instr_search_failed;
                if (inst[3] == 'a') {
                    if (inst.size() < 5) return instr_search_failed;
                    if (inst[4] == 'c') {
                        if (inst.size() < 6) return instr_search_failed;
                        if (inst[5] == 'c') {
                            if (inst.size() < 7) return instr_search_failed;
                            if (inst[6] == '.') {
                                if (inst.size() < 8) return instr_search_failed;
                                if (inst[7] == 'v') {
                                    if (inst.size() < 9) return instr_search_failed;
                                    if (inst[8] == 'x') {
                                        if (inst.size() < 10) return 862;
                                    }
                                    if (inst[8] == 'v') {
                                        if (inst.size() < 10) return 861;
                                    }
                                }
                            }
                            if (inst[6] == 'u') {
                                if (inst.size() < 8) return instr_search_failed;
                                if (inst[7] == '.') {
                                    if (inst.size() < 9) return instr_search_failed;
                                    if (inst[8] == 'v') {
                                        if (inst.size() < 10) return instr_search_failed;
                                        if (inst[9] == 'x') {
                                            if (inst.size() < 11) return 860;
                                        }
                                        if (inst[9] == 'v') {
                                            if (inst.size() < 11) return 859;
                                        }
                                    }
                                }
                                if (inst[7] == 's') {
                                    if (inst.size() < 9) return instr_search_failed;
                                    if (inst[8] == '.') {
                                        if (inst.size() < 10) return instr_search_failed;
                                        if (inst[9] == 'v') {
                                            if (inst.size() < 11) return instr_search_failed;
                                            if (inst[10] == 'x') {
                                                if (inst.size() < 12) return 865;
                                            }
                                        }
                                    }
                                }
                            }
                            if (inst[6] == 's') {
                                if (inst.size() < 8) return instr_search_failed;
                                if (inst[7] == 'u') {
                                    if (inst.size() < 9) return instr_search_failed;
                                    if (inst[8] == '.') {
                                        if (inst.size() < 10) return instr_search_failed;
                                        if (inst[9] == 'v') {
                                            if (inst.size() < 11) return instr_search_failed;
                                            if (inst[10] == 'x') {
                                                if (inst.size() < 12) return 864;
                                            }
                                            if (inst[10] == 'v') {
                                                if (inst.size() < 12) return 863;
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
                if (inst[3] == 'u') {
                    if (inst.size() < 5) return instr_search_failed;
                    if (inst[4] == 'l') {
                        if (inst.size() < 6) return instr_search_failed;
                        if (inst[5] == '.') {
                            if (inst.size() < 7) return instr_search_failed;
                            if (inst[6] == 'v') {
                                if (inst.size() < 8) return instr_search_failed;
                                if (inst[7] == 'x') {
                                    if (inst.size() < 9) return 846;
                                }
                                if (inst[7] == 'v') {
                                    if (inst.size() < 9) return 845;
                                }
                            }
                        }
                        if (inst[5] == 'u') {
                            if (inst.size() < 7) return instr_search_failed;
                            if (inst[6] == '.') {
                                if (inst.size() < 8) return instr_search_failed;
                                if (inst[7] == 'v') {
                                    if (inst.size() < 9) return instr_search_failed;
                                    if (inst[8] == 'x') {
                                        if (inst.size() < 10) return 848;
                                    }
                                    if (inst[8] == 'v') {
                                        if (inst.size() < 10) return 847;
                                    }
                                }
                            }
                        }
                        if (inst[5] == 's') {
                            if (inst.size() < 7) return instr_search_failed;
                            if (inst[6] == 'u') {
                                if (inst.size() < 8) return instr_search_failed;
                                if (inst[7] == '.') {
                                    if (inst.size() < 9) return instr_search_failed;
                                    if (inst[8] == 'v') {
                                        if (inst.size() < 10) return instr_search_failed;
                                        if (inst[9] == 'x') {
                                            if (inst.size() < 11) return 850;
                                        }
                                        if (inst[9] == 'v') {
                                            if (inst.size() < 11) return 849;
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
            if (inst[2] == 'r') {
                if (inst.size() < 4) return instr_search_failed;
                if (inst[3] == 'e') {
                    if (inst.size() < 5) return instr_search_failed;
                    if (inst[4] == 'd') {
                        if (inst.size() < 6) return instr_search_failed;
                        if (inst[5] == 's') {
                            if (inst.size() < 7) return instr_search_failed;
                            if (inst[6] == 'u') {
                                if (inst.size() < 8) return instr_search_failed;
                                if (inst[7] == 'm') {
                                    if (inst.size() < 9) return instr_search_failed;
                                    if (inst[8] == '.') {
                                        if (inst.size() < 10) return instr_search_failed;
                                        if (inst[9] == 'v') {
                                            if (inst.size() < 11) return instr_search_failed;
                                            if (inst[10] == 's') {
                                                if (inst.size() < 12) return 996;
                                            }
                                        }
                                    }
                                    if (inst[8] == 'u') {
                                        if (inst.size() < 10) return instr_search_failed;
                                        if (inst[9] == '.') {
                                            if (inst.size() < 11) return instr_search_failed;
                                            if (inst[10] == 'v') {
                                                if (inst.size() < 12) return instr_search_failed;
                                                if (inst[11] == 's') {
                                                    if (inst.size() < 13) return 995;
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
            if (inst[2] == 's') {
                if (inst.size() < 4) return instr_search_failed;
                if (inst[3] == 'u') {
                    if (inst.size() < 5) return instr_search_failed;
                    if (inst[4] == 'b') {
                        if (inst.size() < 6) return instr_search_failed;
                        if (inst[5] == '.') {
                            if (inst.size() < 7) return instr_search_failed;
                            if (inst[6] == 'w') {
                                if (inst.size() < 8) return instr_search_failed;
                                if (inst[7] == 'x') {
                                    if (inst.size() < 9) return 755;
                                }
                                if (inst[7] == 'v') {
                                    if (inst.size() < 9) return 754;
                                }
                            }
                            if (inst[6] == 'v') {
                                if (inst.size() < 8) return instr_search_failed;
                                if (inst[7] == 'x') {
                                    if (inst.size() < 9) return 747;
                                }
                                if (inst[7] == 'v') {
                                    if (inst.size() < 9) return 746;
                                }
                            }
                        }
                        if (inst[5] == 'u') {
                            if (inst.size() < 7) return instr_search_failed;
                            if (inst[6] == '.') {
                                if (inst.size() < 8) return instr_search_failed;
                                if (inst[7] == 'w') {
                                    if (inst.size() < 9) return instr_search_failed;
                                    if (inst[8] == 'x') {
                                        if (inst.size() < 10) return 751;
                                    }
                                    if (inst[8] == 'v') {
                                        if (inst.size() < 10) return 750;
                                    }
                                }
                                if (inst[7] == 'v') {
                                    if (inst.size() < 9) return instr_search_failed;
                                    if (inst[8] == 'x') {
                                        if (inst.size() < 10) return 743;
                                    }
                                    if (inst[8] == 'v') {
                                        if (inst.size() < 10) return 742;
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
        if (inst[1] == 'i') {
            if (inst.size() < 3) return instr_search_failed;
            if (inst[2] == 'd') {
                if (inst.size() < 4) return instr_search_failed;
                if (inst[3] == '.') {
                    if (inst.size() < 5) return instr_search_failed;
                    if (inst[4] == 'v') {
                        if (inst.size() < 6) return 1017;
                    }
                }
            }
            if (inst[2] == 'o') {
                if (inst.size() < 4) return instr_search_failed;
                if (inst[3] == 't') {
                    if (inst.size() < 5) return instr_search_failed;
                    if (inst[4] == 'a') {
                        if (inst.size() < 6) return instr_search_failed;
                        if (inst[5] == '.') {
                            if (inst.size() < 7) return instr_search_failed;
                            if (inst[6] == 'm') {
                                if (inst.size() < 8) return 1016;
                            }
                        }
                    }
                }
            }
        }
        if (inst[1] == 'm') {
            if (inst.size() < 3) return instr_search_failed;
            if (inst[2] == 'a') {
                if (inst.size() < 4) return instr_search_failed;
                if (inst[3] == 'd') {
                    if (inst.size() < 5) return instr_search_failed;
                    if (inst[4] == 'd') {
                        if (inst.size() < 6) return instr_search_failed;
                        if (inst[5] == '.') {
                            if (inst.size() < 7) return instr_search_failed;
                            if (inst[6] == 'v') {
                                if (inst.size() < 8) return instr_search_failed;
                                if (inst[7] == 'x') {
                                    if (inst.size() < 9) return 856;
                                }
                                if (inst[7] == 'v') {
                                    if (inst.size() < 9) return 855;
                                }
                            }
                        }
                    }
                    if (inst[4] == 'c') {
                        if (inst.size() < 6) return instr_search_failed;
                        if (inst[5] == '.') {
                            if (inst.size() < 7) return instr_search_failed;
                            if (inst[6] == 'v') {
                                if (inst.size() < 8) return instr_search_failed;
                                if (inst[7] == 'i') {
                                    if (inst.size() < 9) return 770;
                                    if (inst[8] == 'm') {
                                        if (inst.size() < 10) return 767;
                                    }
                                }
                                if (inst[7] == 'x') {
                                    if (inst.size() < 9) return 769;
                                    if (inst[8] == 'm') {
                                        if (inst.size() < 10) return 766;
                                    }
                                }
                                if (inst[7] == 'v') {
                                    if (inst.size() < 9) return 768;
                                    if (inst[8] == 'm') {
                                        if (inst.size() < 10) return 765;
                                    }
                                }
                            }
                        }
                    }
                }
                if (inst[3] == 'n') {
                    if (inst.size() < 5) return instr_search_failed;
                    if (inst[4] == 'd') {
                        if (inst.size() < 6) return instr_search_failed;
                        if (inst[5] == '.') {
                            if (inst.size() < 7) return instr_search_failed;
                            if (inst[6] == 'm') {
                                if (inst.size() < 8) return instr_search_failed;
                                if (inst[7] == 'm') {
                                    if (inst.size() < 9) return 1003;
                                }
                            }
                        }
                        if (inst[5] == 'n') {
                            if (inst.size() < 7) return instr_search_failed;
                            if (inst[6] == '.') {
                                if (inst.size() < 8) return instr_search_failed;
                                if (inst[7] == 'm') {
                                    if (inst.size() < 9) return instr_search_failed;
                                    if (inst[8] == 'm') {
                                        if (inst.size() < 10) return 1005;
                                    }
                                }
                            }
                        }
                    }
                }
                if (inst[3] == 'c') {
                    if (inst.size() < 5) return instr_search_failed;
                    if (inst[4] == 'c') {
                        if (inst.size() < 6) return instr_search_failed;
                        if (inst[5] == '.') {
                            if (inst.size() < 7) return instr_search_failed;
                            if (inst[6] == 'v') {
                                if (inst.size() < 8) return instr_search_failed;
                                if (inst[7] == 'x') {
                                    if (inst.size() < 9) return 852;
                                }
                                if (inst[7] == 'v') {
                                    if (inst.size() < 9) return 851;
                                }
                            }
                        }
                    }
                }
                if (inst[3] == 'x') {
                    if (inst.size() < 5) return instr_search_failed;
                    if (inst[4] == '.') {
                        if (inst.size() < 6) return instr_search_failed;
                        if (inst[5] == 'v') {
                            if (inst.size() < 7) return instr_search_failed;
                            if (inst[6] == 'x') {
                                if (inst.size() < 8) return 828;
                            }
                            if (inst[6] == 'v') {
                                if (inst.size() < 8) return 827;
                            }
                        }
                    }
                    if (inst[4] == 'u') {
                        if (inst.size() < 6) return instr_search_failed;
                        if (inst[5] == '.') {
                            if (inst.size() < 7) return instr_search_failed;
                            if (inst[6] == 'v') {
                                if (inst.size() < 8) return instr_search_failed;
                                if (inst[7] == 'x') {
                                    if (inst.size() < 9) return 826;
                                }
                                if (inst[7] == 'v') {
                                    if (inst.size() < 9) return 825;
                                }
                            }
                        }
                    }
                }
            }
            if (inst[2] == 'u') {
                if (inst.size() < 4) return instr_search_failed;
                if (inst[3] == 'l') {
                    if (inst.size() < 5) return instr_search_failed;
                    if (inst[4] == '.') {
                        if (inst.size() < 6) return instr_search_failed;
                        if (inst[5] == 'v') {
                            if (inst.size() < 7) return instr_search_failed;
                            if (inst[6] == 'x') {
                                if (inst.size() < 8) return 830;
                            }
                            if (inst[6] == 'v') {
                                if (inst.size() < 8) return 829;
                            }
                        }
                    }
                    if (inst[4] == 'h') {
                        if (inst.size() < 6) return instr_search_failed;
                        if (inst[5] == '.') {
                            if (inst.size() < 7) return instr_search_failed;
                            if (inst[6] == 'v') {
                                if (inst.size() < 8) return instr_search_failed;
                                if (inst[7] == 'x') {
                                    if (inst.size() < 9) return 832;
                                }
                                if (inst[7] == 'v') {
                                    if (inst.size() < 9) return 831;
                                }
                            }
                        }
                        if (inst[5] == 'u') {
                            if (inst.size() < 7) return instr_search_failed;
                            if (inst[6] == '.') {
                                if (inst.size() < 8) return instr_search_failed;
                                if (inst[7] == 'v') {
                                    if (inst.size() < 9) return instr_search_failed;
                                    if (inst[8] == 'x') {
                                        if (inst.size() < 10) return 834;
                                    }
                                    if (inst[8] == 'v') {
                                        if (inst.size() < 10) return 833;
                                    }
                                }
                            }
                        }
                        if (inst[5] == 's') {
                            if (inst.size() < 7) return instr_search_failed;
                            if (inst[6] == 'u') {
                                if (inst.size() < 8) return instr_search_failed;
                                if (inst[7] == '.') {
                                    if (inst.size() < 9) return instr_search_failed;
                                    if (inst[8] == 'v') {
                                        if (inst.size() < 10) return instr_search_failed;
                                        if (inst[9] == 'x') {
                                            if (inst.size() < 11) return 836;
                                        }
                                        if (inst[9] == 'v') {
                                            if (inst.size() < 11) return 835;
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
            if (inst[2] == 'i') {
                if (inst.size() < 4) return instr_search_failed;
                if (inst[3] == 'n') {
                    if (inst.size() < 5) return instr_search_failed;
                    if (inst[4] == '.') {
                        if (inst.size() < 6) return instr_search_failed;
                        if (inst[5] == 'v') {
                            if (inst.size() < 7) return instr_search_failed;
                            if (inst[6] == 'x') {
                                if (inst.size() < 8) return 824;
                            }
                            if (inst[6] == 'v') {
                                if (inst.size() < 8) return 823;
                            }
                        }
                    }
                    if (inst[4] == 'u') {
                        if (inst.size() < 6) return instr_search_failed;
                        if (inst[5] == '.') {
                            if (inst.size() < 7) return instr_search_failed;
                            if (inst[6] == 'v') {
                                if (inst.size() < 8) return instr_search_failed;
                                if (inst[7] == 'x') {
                                    if (inst.size() < 9) return 822;
                                }
                                if (inst[7] == 'v') {
                                    if (inst.size() < 9) return 821;
                                }
                            }
                        }
                    }
                }
            }
            if (inst[2] == 'o') {
                if (inst.size() < 4) return instr_search_failed;
                if (inst[3] == 'r') {
                    if (inst.size() < 5) return instr_search_failed;
                    if (inst[4] == '.') {
                        if (inst.size() < 6) return instr_search_failed;
                        if (inst[5] == 'm') {
                            if (inst.size() < 7) return instr_search_failed;
                            if (inst[6] == 'm') {
                                if (inst.size() < 8) return 1007;
                            }
                        }
                    }
                    if (inst[4] == 'n') {
                        if (inst.size() < 6) return instr_search_failed;
                        if (inst[5] == '.') {
                            if (inst.size() < 7) return instr_search_failed;
                            if (inst[6] == 'm') {
                                if (inst.size() < 8) return instr_search_failed;
                                if (inst[7] == 'm') {
                                    if (inst.size() < 9) return 1009;
                                }
                            }
                        }
                    }
                }
            }
            if (inst[2] == 'n') {
                if (inst.size() < 4) return instr_search_failed;
                if (inst[3] == 'a') {
                    if (inst.size() < 5) return instr_search_failed;
                    if (inst[4] == 'n') {
                        if (inst.size() < 6) return instr_search_failed;
                        if (inst[5] == 'd') {
                            if (inst.size() < 7) return instr_search_failed;
                            if (inst[6] == '.') {
                                if (inst.size() < 8) return instr_search_failed;
                                if (inst[7] == 'm') {
                                    if (inst.size() < 9) return instr_search_failed;
                                    if (inst[8] == 'm') {
                                        if (inst.size() < 10) return 1004;
                                    }
                                }
                            }
                        }
                    }
                }
                if (inst[3] == 'o') {
                    if (inst.size() < 5) return instr_search_failed;
                    if (inst[4] == 'r') {
                        if (inst.size() < 6) return instr_search_failed;
                        if (inst[5] == '.') {
                            if (inst.size() < 7) return instr_search_failed;
                            if (inst[6] == 'm') {
                                if (inst.size() < 8) return instr_search_failed;
                                if (inst[7] == 'm') {
                                    if (inst.size() < 9) return 1008;
                                }
                            }
                        }
                    }
                }
            }
            if (inst[2] == 's') {
                if (inst.size() < 4) return instr_search_failed;
                if (inst[3] == 'i') {
                    if (inst.size() < 5) return instr_search_failed;
                    if (inst[4] == 'f') {
                        if (inst.size() < 6) return instr_search_failed;
                        if (inst[5] == '.') {
                            if (inst.size() < 7) return instr_search_failed;
                            if (inst[6] == 'm') {
                                if (inst.size() < 8) return 1014;
                            }
                        }
                    }
                }
                if (inst[3] == 'o') {
                    if (inst.size() < 5) return instr_search_failed;
                    if (inst[4] == 'f') {
                        if (inst.size() < 6) return instr_search_failed;
                        if (inst[5] == '.') {
                            if (inst.size() < 7) return instr_search_failed;
                            if (inst[6] == 'm') {
                                if (inst.size() < 8) return 1015;
                            }
                        }
                    }
                }
                if (inst[3] == 'l') {
                    if (inst.size() < 5) return instr_search_failed;
                    if (inst[4] == 'e') {
                        if (inst.size() < 6) return instr_search_failed;
                        if (inst[5] == '.') {
                            if (inst.size() < 7) return instr_search_failed;
                            if (inst[6] == 'v') {
                                if (inst.size() < 8) return instr_search_failed;
                                if (inst[7] == 'i') {
                                    if (inst.size() < 9) return 816;
                                }
                                if (inst[7] == 'x') {
                                    if (inst.size() < 9) return 815;
                                }
                                if (inst[7] == 'v') {
                                    if (inst.size() < 9) return 814;
                                }
                            }
                        }
                        if (inst[5] == 'u') {
                            if (inst.size() < 7) return instr_search_failed;
                            if (inst[6] == '.') {
                                if (inst.size() < 8) return instr_search_failed;
                                if (inst[7] == 'v') {
                                    if (inst.size() < 9) return instr_search_failed;
                                    if (inst[8] == 'i') {
                                        if (inst.size() < 10) return 813;
                                    }
                                    if (inst[8] == 'x') {
                                        if (inst.size() < 10) return 812;
                                    }
                                    if (inst[8] == 'v') {
                                        if (inst.size() < 10) return 811;
                                    }
                                }
                            }
                        }
                    }
                    if (inst[4] == 't') {
                        if (inst.size() < 6) return instr_search_failed;
                        if (inst[5] == '.') {
                            if (inst.size() < 7) return instr_search_failed;
                            if (inst[6] == 'v') {
                                if (inst.size() < 8) return instr_search_failed;
                                if (inst[7] == 'x') {
                                    if (inst.size() < 9) return 810;
                                }
                                if (inst[7] == 'v') {
                                    if (inst.size() < 9) return 809;
                                }
                            }
                        }
                        if (inst[5] == 'u') {
                            if (inst.size() < 7) return instr_search_failed;
                            if (inst[6] == '.') {
                                if (inst.size() < 8) return instr_search_failed;
                                if (inst[7] == 'v') {
                                    if (inst.size() < 9) return instr_search_failed;
                                    if (inst[8] == 'x') {
                                        if (inst.size() < 10) return 808;
                                    }
                                    if (inst[8] == 'v') {
                                        if (inst.size() < 10) return 807;
                                    }
                                }
                            }
                        }
                    }
                }
                if (inst[3] == 'n') {
                    if (inst.size() < 5) return instr_search_failed;
                    if (inst[4] == 'e') {
                        if (inst.size() < 6) return instr_search_failed;
                        if (inst[5] == '.') {
                            if (inst.size() < 7) return instr_search_failed;
                            if (inst[6] == 'v') {
                                if (inst.size() < 8) return instr_search_failed;
                                if (inst[7] == 'i') {
                                    if (inst.size() < 9) return 806;
                                }
                                if (inst[7] == 'x') {
                                    if (inst.size() < 9) return 805;
                                }
                                if (inst[7] == 'v') {
                                    if (inst.size() < 9) return 804;
                                }
                            }
                        }
                    }
                }
                if (inst[3] == 'b') {
                    if (inst.size() < 5) return instr_search_failed;
                    if (inst[4] == 'c') {
                        if (inst.size() < 6) return instr_search_failed;
                        if (inst[5] == '.') {
                            if (inst.size() < 7) return instr_search_failed;
                            if (inst[6] == 'v') {
                                if (inst.size() < 8) return instr_search_failed;
                                if (inst[7] == 'x') {
                                    if (inst.size() < 9) return 776;
                                    if (inst[8] == 'm') {
                                        if (inst.size() < 10) return 774;
                                    }
                                }
                                if (inst[7] == 'v') {
                                    if (inst.size() < 9) return 775;
                                    if (inst[8] == 'm') {
                                        if (inst.size() < 10) return 773;
                                    }
                                }
                            }
                        }
                    }
                    if (inst[4] == 'f') {
                        if (inst.size() < 6) return instr_search_failed;
                        if (inst[5] == '.') {
                            if (inst.size() < 7) return instr_search_failed;
                            if (inst[6] == 'm') {
                                if (inst.size() < 8) return 1013;
                            }
                        }
                    }
                }
                if (inst[3] == 'e') {
                    if (inst.size() < 5) return instr_search_failed;
                    if (inst[4] == 'q') {
                        if (inst.size() < 6) return instr_search_failed;
                        if (inst[5] == '.') {
                            if (inst.size() < 7) return instr_search_failed;
                            if (inst[6] == 'v') {
                                if (inst.size() < 8) return instr_search_failed;
                                if (inst[7] == 'i') {
                                    if (inst.size() < 9) return 803;
                                }
                                if (inst[7] == 'x') {
                                    if (inst.size() < 9) return 802;
                                }
                                if (inst[7] == 'v') {
                                    if (inst.size() < 9) return 801;
                                }
                            }
                        }
                    }
                }
                if (inst[3] == 'g') {
                    if (inst.size() < 5) return instr_search_failed;
                    if (inst[4] == 't') {
                        if (inst.size() < 6) return instr_search_failed;
                        if (inst[5] == '.') {
                            if (inst.size() < 7) return instr_search_failed;
                            if (inst[6] == 'v') {
                                if (inst.size() < 8) return instr_search_failed;
                                if (inst[7] == 'i') {
                                    if (inst.size() < 9) return 820;
                                }
                                if (inst[7] == 'x') {
                                    if (inst.size() < 9) return 819;
                                }
                            }
                        }
                        if (inst[5] == 'u') {
                            if (inst.size() < 7) return instr_search_failed;
                            if (inst[6] == '.') {
                                if (inst.size() < 8) return instr_search_failed;
                                if (inst[7] == 'v') {
                                    if (inst.size() < 9) return instr_search_failed;
                                    if (inst[8] == 'i') {
                                        if (inst.size() < 10) return 818;
                                    }
                                    if (inst[8] == 'x') {
                                        if (inst.size() < 10) return 817;
                                    }
                                }
                            }
                        }
                    }
                }
            }
            if (inst[2] == 'x') {
                if (inst.size() < 4) return instr_search_failed;
                if (inst[3] == 'o') {
                    if (inst.size() < 5) return instr_search_failed;
                    if (inst[4] == 'r') {
                        if (inst.size() < 6) return instr_search_failed;
                        if (inst[5] == '.') {
                            if (inst.size() < 7) return instr_search_failed;
                            if (inst[6] == 'm') {
                                if (inst.size() < 8) return instr_search_failed;
                                if (inst[7] == 'm') {
                                    if (inst.size() < 9) return 1006;
                                }
                            }
                        }
                    }
                }
                if (inst[3] == 'n') {
                    if (inst.size() < 5) return instr_search_failed;
                    if (inst[4] == 'o') {
                        if (inst.size() < 6) return instr_search_failed;
                        if (inst[5] == 'r') {
                            if (inst.size() < 7) return instr_search_failed;
                            if (inst[6] == '.') {
                                if (inst.size() < 8) return instr_search_failed;
                                if (inst[7] == 'm') {
                                    if (inst.size() < 9) return instr_search_failed;
                                    if (inst[8] == 'm') {
                                        if (inst.size() < 10) return 1010;
                                    }
                                }
                            }
                        }
                    }
                }
            }
            if (inst[2] == 'e') {
                if (inst.size() < 4) return instr_search_failed;
                if (inst[3] == 'r') {
                    if (inst.size() < 5) return instr_search_failed;
                    if (inst[4] == 'g') {
                        if (inst.size() < 6) return instr_search_failed;
                        if (inst[5] == 'e') {
                            if (inst.size() < 7) return instr_search_failed;
                            if (inst[6] == '.') {
                                if (inst.size() < 8) return instr_search_failed;
                                if (inst[7] == 'v') {
                                    if (inst.size() < 9) return instr_search_failed;
                                    if (inst[8] == 'i') {
                                        if (inst.size() < 10) return instr_search_failed;
                                        if (inst[9] == 'm') {
                                            if (inst.size() < 11) return 868;
                                        }
                                    }
                                    if (inst[8] == 'x') {
                                        if (inst.size() < 10) return instr_search_failed;
                                        if (inst[9] == 'm') {
                                            if (inst.size() < 11) return 867;
                                        }
                                    }
                                    if (inst[8] == 'v') {
                                        if (inst.size() < 10) return instr_search_failed;
                                        if (inst[9] == 'm') {
                                            if (inst.size() < 11) return 866;
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
            if (inst[2] == 'v') {
                if (inst.size() < 4) return instr_search_failed;
                if (inst[3] == '.') {
                    if (inst.size() < 5) return instr_search_failed;
                    if (inst[4] == 's') {
                        if (inst.size() < 6) return instr_search_failed;
                        if (inst[5] == '.') {
                            if (inst.size() < 7) return instr_search_failed;
                            if (inst[6] == 'x') {
                                if (inst.size() < 8) return 1019;
                            }
                        }
                    }
                    if (inst[4] == 'x') {
                        if (inst.size() < 6) return instr_search_failed;
                        if (inst[5] == '.') {
                            if (inst.size() < 7) return instr_search_failed;
                            if (inst[6] == 's') {
                                if (inst.size() < 8) return 1018;
                            }
                        }
                    }
                    if (inst[4] == 'v') {
                        if (inst.size() < 6) return instr_search_failed;
                        if (inst[5] == '.') {
                            if (inst.size() < 7) return instr_search_failed;
                            if (inst[6] == 'i') {
                                if (inst.size() < 8) return 871;
                            }
                            if (inst[6] == 'x') {
                                if (inst.size() < 8) return 870;
                            }
                            if (inst[6] == 'v') {
                                if (inst.size() < 8) return 869;
                            }
                        }
                    }
                }
                if (inst[3] == '1') {
                    if (inst.size() < 5) return instr_search_failed;
                    if (inst[4] == 'r') {
                        if (inst.size() < 6) return instr_search_failed;
                        if (inst[5] == '.') {
                            if (inst.size() < 7) return instr_search_failed;
                            if (inst[6] == 'v') {
                                if (inst.size() < 8) return 1035;
                            }
                        }
                    }
                }
                if (inst[3] == '8') {
                    if (inst.size() < 5) return instr_search_failed;
                    if (inst[4] == 'r') {
                        if (inst.size() < 6) return instr_search_failed;
                        if (inst[5] == '.') {
                            if (inst.size() < 7) return instr_search_failed;
                            if (inst[6] == 'v') {
                                if (inst.size() < 8) return 1038;
                            }
                        }
                    }
                }
                if (inst[3] == '2') {
                    if (inst.size() < 5) return instr_search_failed;
                    if (inst[4] == 'r') {
                        if (inst.size() < 6) return instr_search_failed;
                        if (inst[5] == '.') {
                            if (inst.size() < 7) return instr_search_failed;
                            if (inst[6] == 'v') {
                                if (inst.size() < 8) return 1036;
                            }
                        }
                    }
                }
                if (inst[3] == '4') {
                    if (inst.size() < 5) return instr_search_failed;
                    if (inst[4] == 'r') {
                        if (inst.size() < 6) return instr_search_failed;
                        if (inst[5] == '.') {
                            if (inst.size() < 7) return instr_search_failed;
                            if (inst[6] == 'v') {
                                if (inst.size() < 8) return 1037;
                            }
                        }
                    }
                }
            }
            if (inst[2] == 'f') {
                if (inst.size() < 4) return instr_search_failed;
                if (inst[3] == 'l') {
                    if (inst.size() < 5) return instr_search_failed;
                    if (inst[4] == 'e') {
                        if (inst.size() < 6) return instr_search_failed;
                        if (inst[5] == '.') {
                            if (inst.size() < 7) return instr_search_failed;
                            if (inst[6] == 'v') {
                                if (inst.size() < 8) return instr_search_failed;
                                if (inst[7] == 'v') {
                                    if (inst.size() < 9) return 959;
                                }
                                if (inst[7] == 'f') {
                                    if (inst.size() < 9) return 960;
                                }
                            }
                        }
                    }
                    if (inst[4] == 't') {
                        if (inst.size() < 6) return instr_search_failed;
                        if (inst[5] == '.') {
                            if (inst.size() < 7) return instr_search_failed;
                            if (inst[6] == 'v') {
                                if (inst.size() < 8) return instr_search_failed;
                                if (inst[7] == 'v') {
                                    if (inst.size() < 9) return 957;
                                }
                                if (inst[7] == 'f') {
                                    if (inst.size() < 9) return 958;
                                }
                            }
                        }
                    }
                }
                if (inst[3] == 'n') {
                    if (inst.size() < 5) return instr_search_failed;
                    if (inst[4] == 'e') {
                        if (inst.size() < 6) return instr_search_failed;
                        if (inst[5] == '.') {
                            if (inst.size() < 7) return instr_search_failed;
                            if (inst[6] == 'v') {
                                if (inst.size() < 8) return instr_search_failed;
                                if (inst[7] == 'v') {
                                    if (inst.size() < 9) return 955;
                                }
                                if (inst[7] == 'f') {
                                    if (inst.size() < 9) return 956;
                                }
                            }
                        }
                    }
                }
                if (inst[3] == 'e') {
                    if (inst.size() < 5) return instr_search_failed;
                    if (inst[4] == 'q') {
                        if (inst.size() < 6) return instr_search_failed;
                        if (inst[5] == '.') {
                            if (inst.size() < 7) return instr_search_failed;
                            if (inst[6] == 'v') {
                                if (inst.size() < 8) return instr_search_failed;
                                if (inst[7] == 'v') {
                                    if (inst.size() < 9) return 953;
                                }
                                if (inst[7] == 'f') {
                                    if (inst.size() < 9) return 954;
                                }
                            }
                        }
                    }
                }
                if (inst[3] == 'g') {
                    if (inst.size() < 5) return instr_search_failed;
                    if (inst[4] == 'e') {
                        if (inst.size() < 6) return instr_search_failed;
                        if (inst[5] == '.') {
                            if (inst.size() < 7) return instr_search_failed;
                            if (inst[6] == 'v') {
                                if (inst.size() < 8) return instr_search_failed;
                                if (inst[7] == 'f') {
                                    if (inst.size() < 9) return 962;
                                }
                            }
                        }
                    }
                    if (inst[4] == 't') {
                        if (inst.size() < 6) return instr_search_failed;
                        if (inst[5] == '.') {
                            if (inst.size() < 7) return instr_search_failed;
                            if (inst[6] == 'v') {
                                if (inst.size() < 8) return instr_search_failed;
                                if (inst[7] == 'f') {
                                    if (inst.size() < 9) return 961;
                                }
                            }
                        }
                    }
                }
            }
        }
        if (inst[1] == 'o') {
            if (inst.size() < 3) return instr_search_failed;
            if (inst[2] == 'r') {
                if (inst.size() < 4) return instr_search_failed;
                if (inst[3] == '.') {
                    if (inst.size() < 5) return instr_search_failed;
                    if (inst[4] == 'v') {
                        if (inst.size() < 6) return instr_search_failed;
                        if (inst[5] == 'i') {
                            if (inst.size() < 7) return 782;
                        }
                        if (inst[5] == 'x') {
                            if (inst.size() < 7) return 781;
                        }
                        if (inst[5] == 'v') {
                            if (inst.size() < 7) return 780;
                        }
                    }
                }
            }
        }
        if (inst[1] == 'r') {
            if (inst.size() < 3) return instr_search_failed;
            if (inst[2] == 's') {
                if (inst.size() < 4) return instr_search_failed;
                if (inst[3] == 'u') {
                    if (inst.size() < 5) return instr_search_failed;
                    if (inst[4] == 'b') {
                        if (inst.size() < 6) return instr_search_failed;
                        if (inst[5] == '.') {
                            if (inst.size() < 7) return instr_search_failed;
                            if (inst[6] == 'v') {
                                if (inst.size() < 8) return instr_search_failed;
                                if (inst[7] == 'i') {
                                    if (inst.size() < 9) return 739;
                                }
                                if (inst[7] == 'x') {
                                    if (inst.size() < 9) return 738;
                                }
                            }
                        }
                    }
                }
            }
            if (inst[2] == 'e') {
                if (inst.size() < 4) return instr_search_failed;
                if (inst[3] == 'd') {
                    if (inst.size() < 5) return instr_search_failed;
                    if (inst[4] == 'a') {
                        if (inst.size() < 6) return instr_search_failed;
                        if (inst[5] == 'n') {
                            if (inst.size() < 7) return instr_search_failed;
                            if (inst[6] == 'd') {
                                if (inst.size() < 8) return instr_search_failed;
                                if (inst[7] == '.') {
                                    if (inst.size() < 9) return instr_search_failed;
                                    if (inst[8] == 'v') {
                                        if (inst.size() < 10) return instr_search_failed;
                                        if (inst[9] == 's') {
                                            if (inst.size() < 11) return 992;
                                        }
                                    }
                                }
                            }
                        }
                    }
                    if (inst[4] == 'm') {
                        if (inst.size() < 6) return instr_search_failed;
                        if (inst[5] == 'a') {
                            if (inst.size() < 7) return instr_search_failed;
                            if (inst[6] == 'x') {
                                if (inst.size() < 8) return instr_search_failed;
                                if (inst[7] == '.') {
                                    if (inst.size() < 9) return instr_search_failed;
                                    if (inst[8] == 'v') {
                                        if (inst.size() < 10) return instr_search_failed;
                                        if (inst[9] == 's') {
                                            if (inst.size() < 11) return 989;
                                        }
                                    }
                                }
                                if (inst[7] == 'u') {
                                    if (inst.size() < 9) return instr_search_failed;
                                    if (inst[8] == '.') {
                                        if (inst.size() < 10) return instr_search_failed;
                                        if (inst[9] == 'v') {
                                            if (inst.size() < 11) return instr_search_failed;
                                            if (inst[10] == 's') {
                                                if (inst.size() < 12) return 988;
                                            }
                                        }
                                    }
                                }
                            }
                        }
                        if (inst[5] == 'i') {
                            if (inst.size() < 7) return instr_search_failed;
                            if (inst[6] == 'n') {
                                if (inst.size() < 8) return instr_search_failed;
                                if (inst[7] == '.') {
                                    if (inst.size() < 9) return instr_search_failed;
                                    if (inst[8] == 'v') {
                                        if (inst.size() < 10) return instr_search_failed;
                                        if (inst[9] == 's') {
                                            if (inst.size() < 11) return 991;
                                        }
                                    }
                                }
                                if (inst[7] == 'u') {
                                    if (inst.size() < 9) return instr_search_failed;
                                    if (inst[8] == '.') {
                                        if (inst.size() < 10) return instr_search_failed;
                                        if (inst[9] == 'v') {
                                            if (inst.size() < 11) return instr_search_failed;
                                            if (inst[10] == 's') {
                                                if (inst.size() < 12) return 990;
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                    if (inst[4] == 'o') {
                        if (inst.size() < 6) return instr_search_failed;
                        if (inst[5] == 'r') {
                            if (inst.size() < 7) return instr_search_failed;
                            if (inst[6] == '.') {
                                if (inst.size() < 8) return instr_search_failed;
                                if (inst[7] == 'v') {
                                    if (inst.size() < 9) return instr_search_failed;
                                    if (inst[8] == 's') {
                                        if (inst.size() < 10) return 993;
                                    }
                                }
                            }
                        }
                    }
                    if (inst[4] == 's') {
                        if (inst.size() < 6) return instr_search_failed;
                        if (inst[5] == 'u') {
                            if (inst.size() < 7) return instr_search_failed;
                            if (inst[6] == 'm') {
                                if (inst.size() < 8) return instr_search_failed;
                                if (inst[7] == '.') {
                                    if (inst.size() < 9) return instr_search_failed;
                                    if (inst[8] == 'v') {
                                        if (inst.size() < 10) return instr_search_failed;
                                        if (inst[9] == 's') {
                                            if (inst.size() < 11) return 987;
                                        }
                                    }
                                }
                            }
                        }
                    }
                    if (inst[4] == 'x') {
                        if (inst.size() < 6) return instr_search_failed;
                        if (inst[5] == 'o') {
                            if (inst.size() < 7) return instr_search_failed;
                            if (inst[6] == 'r') {
                                if (inst.size() < 8) return instr_search_failed;
                                if (inst[7] == '.') {
                                    if (inst.size() < 9) return instr_search_failed;
                                    if (inst[8] == 'v') {
                                        if (inst.size() < 10) return instr_search_failed;
                                        if (inst[9] == 's') {
                                            if (inst.size() < 11) return 994;
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
                if (inst[3] == 'm') {
                    if (inst.size() < 5) return instr_search_failed;
                    if (inst[4] == '.') {
                        if (inst.size() < 6) return instr_search_failed;
                        if (inst[5] == 'v') {
                            if (inst.size() < 7) return instr_search_failed;
                            if (inst[6] == 'x') {
                                if (inst.size() < 8) return 844;
                            }
                            if (inst[6] == 'v') {
                                if (inst.size() < 8) return 843;
                            }
                        }
                    }
                    if (inst[4] == 'u') {
                        if (inst.size() < 6) return instr_search_failed;
                        if (inst[5] == '.') {
                            if (inst.size() < 7) return instr_search_failed;
                            if (inst[6] == 'v') {
                                if (inst.size() < 8) return instr_search_failed;
                                if (inst[7] == 'x') {
                                    if (inst.size() < 9) return 842;
                                }
                                if (inst[7] == 'v') {
                                    if (inst.size() < 9) return 841;
                                }
                            }
                        }
                    }
                }
            }
            if (inst[2] == 'g') {
                if (inst.size() < 4) return instr_search_failed;
                if (inst[3] == 'a') {
                    if (inst.size() < 5) return instr_search_failed;
                    if (inst[4] == 't') {
                        if (inst.size() < 6) return instr_search_failed;
                        if (inst[5] == 'h') {
                            if (inst.size() < 7) return instr_search_failed;
                            if (inst[6] == 'e') {
                                if (inst.size() < 8) return instr_search_failed;
                                if (inst[7] == 'r') {
                                    if (inst.size() < 9) return instr_search_failed;
                                    if (inst[8] == '.') {
                                        if (inst.size() < 10) return instr_search_failed;
                                        if (inst[9] == 'v') {
                                            if (inst.size() < 11) return instr_search_failed;
                                            if (inst[10] == 'i') {
                                                if (inst.size() < 12) return 1033;
                                            }
                                            if (inst[10] == 'x') {
                                                if (inst.size() < 12) return 1032;
                                            }
                                            if (inst[10] == 'v') {
                                                if (inst.size() < 12) return 1030;
                                            }
                                        }
                                    }
                                    if (inst[8] == 'e') {
                                        if (inst.size() < 10) return instr_search_failed;
                                        if (inst[9] == 'i') {
                                            if (inst.size() < 11) return instr_search_failed;
                                            if (inst[10] == '1') {
                                                if (inst.size() < 12) return instr_search_failed;
                                                if (inst[11] == '6') {
                                                    if (inst.size() < 13) return instr_search_failed;
                                                    if (inst[12] == '.') {
                                                        if (inst.size() < 14) return instr_search_failed;
                                                        if (inst[13] == 'v') {
                                                            if (inst.size() < 15) return instr_search_failed;
                                                            if (inst[14] == 'v') {
                                                                if (inst.size() < 16) return 1031;
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
                }
            }
        }
        if (inst[1] == 'l') {
            if (inst.size() < 3) return instr_search_failed;
            if (inst[2] == 'u') {
                if (inst.size() < 4) return instr_search_failed;
                if (inst[3] == 'x') {
                    if (inst.size() < 5) return instr_search_failed;
                    if (inst[4] == 's') {
                        if (inst.size() < 6) return instr_search_failed;
                        if (inst[5] == 'e') {
                            if (inst.size() < 7) return instr_search_failed;
                            if (inst[6] == 'g') {
                                if (inst.size() < 8) return instr_search_failed;
                                if (inst[7] == '6') {
                                    if (inst.size() < 9) return instr_search_failed;
                                    if (inst[8] == 'e') {
                                        if (inst.size() < 10) return instr_search_failed;
                                        if (inst[9] == 'i') {
                                            if (inst.size() < 11) return instr_search_failed;
                                            if (inst[10] == '1') {
                                                if (inst.size() < 12) return instr_search_failed;
                                                if (inst[11] == '6') {
                                                    if (inst.size() < 13) return instr_search_failed;
                                                    if (inst[12] == '.') {
                                                        if (inst.size() < 14) return instr_search_failed;
                                                        if (inst[13] == 'v') {
                                                            if (inst.size() < 15) return 669;
                                                        }
                                                    }
                                                }
                                            }
                                            if (inst[10] == '6') {
                                                if (inst.size() < 12) return instr_search_failed;
                                                if (inst[11] == '4') {
                                                    if (inst.size() < 13) return instr_search_failed;
                                                    if (inst[12] == '.') {
                                                        if (inst.size() < 14) return instr_search_failed;
                                                        if (inst[13] == 'v') {
                                                            if (inst.size() < 15) return 677;
                                                        }
                                                    }
                                                }
                                            }
                                            if (inst[10] == '8') {
                                                if (inst.size() < 12) return instr_search_failed;
                                                if (inst[11] == '.') {
                                                    if (inst.size() < 13) return instr_search_failed;
                                                    if (inst[12] == 'v') {
                                                        if (inst.size() < 14) return 665;
                                                    }
                                                }
                                            }
                                            if (inst[10] == '3') {
                                                if (inst.size() < 12) return instr_search_failed;
                                                if (inst[11] == '2') {
                                                    if (inst.size() < 13) return instr_search_failed;
                                                    if (inst[12] == '.') {
                                                        if (inst.size() < 14) return instr_search_failed;
                                                        if (inst[13] == 'v') {
                                                            if (inst.size() < 15) return 673;
                                                        }
                                                    }
                                                }
                                            }
                                        }
                                    }
                                }
                                if (inst[7] == '8') {
                                    if (inst.size() < 9) return instr_search_failed;
                                    if (inst[8] == 'e') {
                                        if (inst.size() < 10) return instr_search_failed;
                                        if (inst[9] == 'i') {
                                            if (inst.size() < 11) return instr_search_failed;
                                            if (inst[10] == '1') {
                                                if (inst.size() < 12) return instr_search_failed;
                                                if (inst[11] == '6') {
                                                    if (inst.size() < 13) return instr_search_failed;
                                                    if (inst[12] == '.') {
                                                        if (inst.size() < 14) return instr_search_failed;
                                                        if (inst[13] == 'v') {
                                                            if (inst.size() < 15) return 701;
                                                        }
                                                    }
                                                }
                                            }
                                            if (inst[10] == '6') {
                                                if (inst.size() < 12) return instr_search_failed;
                                                if (inst[11] == '4') {
                                                    if (inst.size() < 13) return instr_search_failed;
                                                    if (inst[12] == '.') {
                                                        if (inst.size() < 14) return instr_search_failed;
                                                        if (inst[13] == 'v') {
                                                            if (inst.size() < 15) return 709;
                                                        }
                                                    }
                                                }
                                            }
                                            if (inst[10] == '8') {
                                                if (inst.size() < 12) return instr_search_failed;
                                                if (inst[11] == '.') {
                                                    if (inst.size() < 13) return instr_search_failed;
                                                    if (inst[12] == 'v') {
                                                        if (inst.size() < 14) return 697;
                                                    }
                                                }
                                            }
                                            if (inst[10] == '3') {
                                                if (inst.size() < 12) return instr_search_failed;
                                                if (inst[11] == '2') {
                                                    if (inst.size() < 13) return instr_search_failed;
                                                    if (inst[12] == '.') {
                                                        if (inst.size() < 14) return instr_search_failed;
                                                        if (inst[13] == 'v') {
                                                            if (inst.size() < 15) return 705;
                                                        }
                                                    }
                                                }
                                            }
                                        }
                                    }
                                }
                                if (inst[7] == '2') {
                                    if (inst.size() < 9) return instr_search_failed;
                                    if (inst[8] == 'e') {
                                        if (inst.size() < 10) return instr_search_failed;
                                        if (inst[9] == 'i') {
                                            if (inst.size() < 11) return instr_search_failed;
                                            if (inst[10] == '1') {
                                                if (inst.size() < 12) return instr_search_failed;
                                                if (inst[11] == '6') {
                                                    if (inst.size() < 13) return instr_search_failed;
                                                    if (inst[12] == '.') {
                                                        if (inst.size() < 14) return instr_search_failed;
                                                        if (inst[13] == 'v') {
                                                            if (inst.size() < 15) return 605;
                                                        }
                                                    }
                                                }
                                            }
                                            if (inst[10] == '6') {
                                                if (inst.size() < 12) return instr_search_failed;
                                                if (inst[11] == '4') {
                                                    if (inst.size() < 13) return instr_search_failed;
                                                    if (inst[12] == '.') {
                                                        if (inst.size() < 14) return instr_search_failed;
                                                        if (inst[13] == 'v') {
                                                            if (inst.size() < 15) return 613;
                                                        }
                                                    }
                                                }
                                            }
                                            if (inst[10] == '8') {
                                                if (inst.size() < 12) return instr_search_failed;
                                                if (inst[11] == '.') {
                                                    if (inst.size() < 13) return instr_search_failed;
                                                    if (inst[12] == 'v') {
                                                        if (inst.size() < 14) return 601;
                                                    }
                                                }
                                            }
                                            if (inst[10] == '3') {
                                                if (inst.size() < 12) return instr_search_failed;
                                                if (inst[11] == '2') {
                                                    if (inst.size() < 13) return instr_search_failed;
                                                    if (inst[12] == '.') {
                                                        if (inst.size() < 14) return instr_search_failed;
                                                        if (inst[13] == 'v') {
                                                            if (inst.size() < 15) return 609;
                                                        }
                                                    }
                                                }
                                            }
                                        }
                                    }
                                }
                                if (inst[7] == '3') {
                                    if (inst.size() < 9) return instr_search_failed;
                                    if (inst[8] == 'e') {
                                        if (inst.size() < 10) return instr_search_failed;
                                        if (inst[9] == 'i') {
                                            if (inst.size() < 11) return instr_search_failed;
                                            if (inst[10] == '1') {
                                                if (inst.size() < 12) return instr_search_failed;
                                                if (inst[11] == '6') {
                                                    if (inst.size() < 13) return instr_search_failed;
                                                    if (inst[12] == '.') {
                                                        if (inst.size() < 14) return instr_search_failed;
                                                        if (inst[13] == 'v') {
                                                            if (inst.size() < 15) return 621;
                                                        }
                                                    }
                                                }
                                            }
                                            if (inst[10] == '6') {
                                                if (inst.size() < 12) return instr_search_failed;
                                                if (inst[11] == '4') {
                                                    if (inst.size() < 13) return instr_search_failed;
                                                    if (inst[12] == '.') {
                                                        if (inst.size() < 14) return instr_search_failed;
                                                        if (inst[13] == 'v') {
                                                            if (inst.size() < 15) return 629;
                                                        }
                                                    }
                                                }
                                            }
                                            if (inst[10] == '8') {
                                                if (inst.size() < 12) return instr_search_failed;
                                                if (inst[11] == '.') {
                                                    if (inst.size() < 13) return instr_search_failed;
                                                    if (inst[12] == 'v') {
                                                        if (inst.size() < 14) return 617;
                                                    }
                                                }
                                            }
                                            if (inst[10] == '3') {
                                                if (inst.size() < 12) return instr_search_failed;
                                                if (inst[11] == '2') {
                                                    if (inst.size() < 13) return instr_search_failed;
                                                    if (inst[12] == '.') {
                                                        if (inst.size() < 14) return instr_search_failed;
                                                        if (inst[13] == 'v') {
                                                            if (inst.size() < 15) return 625;
                                                        }
                                                    }
                                                }
                                            }
                                        }
                                    }
                                }
                                if (inst[7] == '7') {
                                    if (inst.size() < 9) return instr_search_failed;
                                    if (inst[8] == 'e') {
                                        if (inst.size() < 10) return instr_search_failed;
                                        if (inst[9] == 'i') {
                                            if (inst.size() < 11) return instr_search_failed;
                                            if (inst[10] == '1') {
                                                if (inst.size() < 12) return instr_search_failed;
                                                if (inst[11] == '6') {
                                                    if (inst.size() < 13) return instr_search_failed;
                                                    if (inst[12] == '.') {
                                                        if (inst.size() < 14) return instr_search_failed;
                                                        if (inst[13] == 'v') {
                                                            if (inst.size() < 15) return 685;
                                                        }
                                                    }
                                                }
                                            }
                                            if (inst[10] == '6') {
                                                if (inst.size() < 12) return instr_search_failed;
                                                if (inst[11] == '4') {
                                                    if (inst.size() < 13) return instr_search_failed;
                                                    if (inst[12] == '.') {
                                                        if (inst.size() < 14) return instr_search_failed;
                                                        if (inst[13] == 'v') {
                                                            if (inst.size() < 15) return 693;
                                                        }
                                                    }
                                                }
                                            }
                                            if (inst[10] == '8') {
                                                if (inst.size() < 12) return instr_search_failed;
                                                if (inst[11] == '.') {
                                                    if (inst.size() < 13) return instr_search_failed;
                                                    if (inst[12] == 'v') {
                                                        if (inst.size() < 14) return 681;
                                                    }
                                                }
                                            }
                                            if (inst[10] == '3') {
                                                if (inst.size() < 12) return instr_search_failed;
                                                if (inst[11] == '2') {
                                                    if (inst.size() < 13) return instr_search_failed;
                                                    if (inst[12] == '.') {
                                                        if (inst.size() < 14) return instr_search_failed;
                                                        if (inst[13] == 'v') {
                                                            if (inst.size() < 15) return 689;
                                                        }
                                                    }
                                                }
                                            }
                                        }
                                    }
                                }
                                if (inst[7] == '4') {
                                    if (inst.size() < 9) return instr_search_failed;
                                    if (inst[8] == 'e') {
                                        if (inst.size() < 10) return instr_search_failed;
                                        if (inst[9] == 'i') {
                                            if (inst.size() < 11) return instr_search_failed;
                                            if (inst[10] == '1') {
                                                if (inst.size() < 12) return instr_search_failed;
                                                if (inst[11] == '6') {
                                                    if (inst.size() < 13) return instr_search_failed;
                                                    if (inst[12] == '.') {
                                                        if (inst.size() < 14) return instr_search_failed;
                                                        if (inst[13] == 'v') {
                                                            if (inst.size() < 15) return 637;
                                                        }
                                                    }
                                                }
                                            }
                                            if (inst[10] == '6') {
                                                if (inst.size() < 12) return instr_search_failed;
                                                if (inst[11] == '4') {
                                                    if (inst.size() < 13) return instr_search_failed;
                                                    if (inst[12] == '.') {
                                                        if (inst.size() < 14) return instr_search_failed;
                                                        if (inst[13] == 'v') {
                                                            if (inst.size() < 15) return 645;
                                                        }
                                                    }
                                                }
                                            }
                                            if (inst[10] == '8') {
                                                if (inst.size() < 12) return instr_search_failed;
                                                if (inst[11] == '.') {
                                                    if (inst.size() < 13) return instr_search_failed;
                                                    if (inst[12] == 'v') {
                                                        if (inst.size() < 14) return 633;
                                                    }
                                                }
                                            }
                                            if (inst[10] == '3') {
                                                if (inst.size() < 12) return instr_search_failed;
                                                if (inst[11] == '2') {
                                                    if (inst.size() < 13) return instr_search_failed;
                                                    if (inst[12] == '.') {
                                                        if (inst.size() < 14) return instr_search_failed;
                                                        if (inst[13] == 'v') {
                                                            if (inst.size() < 15) return 641;
                                                        }
                                                    }
                                                }
                                            }
                                        }
                                    }
                                }
                                if (inst[7] == '5') {
                                    if (inst.size() < 9) return instr_search_failed;
                                    if (inst[8] == 'e') {
                                        if (inst.size() < 10) return instr_search_failed;
                                        if (inst[9] == 'i') {
                                            if (inst.size() < 11) return instr_search_failed;
                                            if (inst[10] == '1') {
                                                if (inst.size() < 12) return instr_search_failed;
                                                if (inst[11] == '6') {
                                                    if (inst.size() < 13) return instr_search_failed;
                                                    if (inst[12] == '.') {
                                                        if (inst.size() < 14) return instr_search_failed;
                                                        if (inst[13] == 'v') {
                                                            if (inst.size() < 15) return 653;
                                                        }
                                                    }
                                                }
                                            }
                                            if (inst[10] == '6') {
                                                if (inst.size() < 12) return instr_search_failed;
                                                if (inst[11] == '4') {
                                                    if (inst.size() < 13) return instr_search_failed;
                                                    if (inst[12] == '.') {
                                                        if (inst.size() < 14) return instr_search_failed;
                                                        if (inst[13] == 'v') {
                                                            if (inst.size() < 15) return 661;
                                                        }
                                                    }
                                                }
                                            }
                                            if (inst[10] == '8') {
                                                if (inst.size() < 12) return instr_search_failed;
                                                if (inst[11] == '.') {
                                                    if (inst.size() < 13) return instr_search_failed;
                                                    if (inst[12] == 'v') {
                                                        if (inst.size() < 14) return 649;
                                                    }
                                                }
                                            }
                                            if (inst[10] == '3') {
                                                if (inst.size() < 12) return instr_search_failed;
                                                if (inst[11] == '2') {
                                                    if (inst.size() < 13) return instr_search_failed;
                                                    if (inst[12] == '.') {
                                                        if (inst.size() < 14) return instr_search_failed;
                                                        if (inst[13] == 'v') {
                                                            if (inst.size() < 15) return 657;
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
                    if (inst[4] == 'e') {
                        if (inst.size() < 6) return instr_search_failed;
                        if (inst[5] == 'i') {
                            if (inst.size() < 7) return instr_search_failed;
                            if (inst[6] == '1') {
                                if (inst.size() < 8) return instr_search_failed;
                                if (inst[7] == '6') {
                                    if (inst.size() < 9) return instr_search_failed;
                                    if (inst[8] == '.') {
                                        if (inst.size() < 10) return instr_search_failed;
                                        if (inst[9] == 'v') {
                                            if (inst.size() < 11) return 442;
                                        }
                                    }
                                }
                            }
                            if (inst[6] == '6') {
                                if (inst.size() < 8) return instr_search_failed;
                                if (inst[7] == '4') {
                                    if (inst.size() < 9) return instr_search_failed;
                                    if (inst[8] == '.') {
                                        if (inst.size() < 10) return instr_search_failed;
                                        if (inst[9] == 'v') {
                                            if (inst.size() < 11) return 444;
                                        }
                                    }
                                }
                            }
                            if (inst[6] == '8') {
                                if (inst.size() < 8) return instr_search_failed;
                                if (inst[7] == '.') {
                                    if (inst.size() < 9) return instr_search_failed;
                                    if (inst[8] == 'v') {
                                        if (inst.size() < 10) return 441;
                                    }
                                }
                            }
                            if (inst[6] == '3') {
                                if (inst.size() < 8) return instr_search_failed;
                                if (inst[7] == '2') {
                                    if (inst.size() < 9) return instr_search_failed;
                                    if (inst[8] == '.') {
                                        if (inst.size() < 10) return instr_search_failed;
                                        if (inst[9] == 'v') {
                                            if (inst.size() < 11) return 443;
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
            if (inst[2] == 'm') {
                if (inst.size() < 4) return instr_search_failed;
                if (inst[3] == '.') {
                    if (inst.size() < 5) return instr_search_failed;
                    if (inst[4] == 'v') {
                        if (inst.size() < 6) return 431;
                    }
                }
            }
            if (inst[2] == 'o') {
                if (inst.size() < 4) return instr_search_failed;
                if (inst[3] == 'x') {
                    if (inst.size() < 5) return instr_search_failed;
                    if (inst[4] == 's') {
                        if (inst.size() < 6) return instr_search_failed;
                        if (inst[5] == 'e') {
                            if (inst.size() < 7) return instr_search_failed;
                            if (inst[6] == 'g') {
                                if (inst.size() < 8) return instr_search_failed;
                                if (inst[7] == '6') {
                                    if (inst.size() < 9) return instr_search_failed;
                                    if (inst[8] == 'e') {
                                        if (inst.size() < 10) return instr_search_failed;
                                        if (inst[9] == 'i') {
                                            if (inst.size() < 11) return instr_search_failed;
                                            if (inst[10] == '1') {
                                                if (inst.size() < 12) return instr_search_failed;
                                                if (inst[11] == '6') {
                                                    if (inst.size() < 13) return instr_search_failed;
                                                    if (inst[12] == '.') {
                                                        if (inst.size() < 14) return instr_search_failed;
                                                        if (inst[13] == 'v') {
                                                            if (inst.size() < 15) return 670;
                                                        }
                                                    }
                                                }
                                            }
                                            if (inst[10] == '6') {
                                                if (inst.size() < 12) return instr_search_failed;
                                                if (inst[11] == '4') {
                                                    if (inst.size() < 13) return instr_search_failed;
                                                    if (inst[12] == '.') {
                                                        if (inst.size() < 14) return instr_search_failed;
                                                        if (inst[13] == 'v') {
                                                            if (inst.size() < 15) return 678;
                                                        }
                                                    }
                                                }
                                            }
                                            if (inst[10] == '8') {
                                                if (inst.size() < 12) return instr_search_failed;
                                                if (inst[11] == '.') {
                                                    if (inst.size() < 13) return instr_search_failed;
                                                    if (inst[12] == 'v') {
                                                        if (inst.size() < 14) return 666;
                                                    }
                                                }
                                            }
                                            if (inst[10] == '3') {
                                                if (inst.size() < 12) return instr_search_failed;
                                                if (inst[11] == '2') {
                                                    if (inst.size() < 13) return instr_search_failed;
                                                    if (inst[12] == '.') {
                                                        if (inst.size() < 14) return instr_search_failed;
                                                        if (inst[13] == 'v') {
                                                            if (inst.size() < 15) return 674;
                                                        }
                                                    }
                                                }
                                            }
                                        }
                                    }
                                }
                                if (inst[7] == '8') {
                                    if (inst.size() < 9) return instr_search_failed;
                                    if (inst[8] == 'e') {
                                        if (inst.size() < 10) return instr_search_failed;
                                        if (inst[9] == 'i') {
                                            if (inst.size() < 11) return instr_search_failed;
                                            if (inst[10] == '1') {
                                                if (inst.size() < 12) return instr_search_failed;
                                                if (inst[11] == '6') {
                                                    if (inst.size() < 13) return instr_search_failed;
                                                    if (inst[12] == '.') {
                                                        if (inst.size() < 14) return instr_search_failed;
                                                        if (inst[13] == 'v') {
                                                            if (inst.size() < 15) return 702;
                                                        }
                                                    }
                                                }
                                            }
                                            if (inst[10] == '6') {
                                                if (inst.size() < 12) return instr_search_failed;
                                                if (inst[11] == '4') {
                                                    if (inst.size() < 13) return instr_search_failed;
                                                    if (inst[12] == '.') {
                                                        if (inst.size() < 14) return instr_search_failed;
                                                        if (inst[13] == 'v') {
                                                            if (inst.size() < 15) return 710;
                                                        }
                                                    }
                                                }
                                            }
                                            if (inst[10] == '8') {
                                                if (inst.size() < 12) return instr_search_failed;
                                                if (inst[11] == '.') {
                                                    if (inst.size() < 13) return instr_search_failed;
                                                    if (inst[12] == 'v') {
                                                        if (inst.size() < 14) return 698;
                                                    }
                                                }
                                            }
                                            if (inst[10] == '3') {
                                                if (inst.size() < 12) return instr_search_failed;
                                                if (inst[11] == '2') {
                                                    if (inst.size() < 13) return instr_search_failed;
                                                    if (inst[12] == '.') {
                                                        if (inst.size() < 14) return instr_search_failed;
                                                        if (inst[13] == 'v') {
                                                            if (inst.size() < 15) return 706;
                                                        }
                                                    }
                                                }
                                            }
                                        }
                                    }
                                }
                                if (inst[7] == '2') {
                                    if (inst.size() < 9) return instr_search_failed;
                                    if (inst[8] == 'e') {
                                        if (inst.size() < 10) return instr_search_failed;
                                        if (inst[9] == 'i') {
                                            if (inst.size() < 11) return instr_search_failed;
                                            if (inst[10] == '1') {
                                                if (inst.size() < 12) return instr_search_failed;
                                                if (inst[11] == '6') {
                                                    if (inst.size() < 13) return instr_search_failed;
                                                    if (inst[12] == '.') {
                                                        if (inst.size() < 14) return instr_search_failed;
                                                        if (inst[13] == 'v') {
                                                            if (inst.size() < 15) return 606;
                                                        }
                                                    }
                                                }
                                            }
                                            if (inst[10] == '6') {
                                                if (inst.size() < 12) return instr_search_failed;
                                                if (inst[11] == '4') {
                                                    if (inst.size() < 13) return instr_search_failed;
                                                    if (inst[12] == '.') {
                                                        if (inst.size() < 14) return instr_search_failed;
                                                        if (inst[13] == 'v') {
                                                            if (inst.size() < 15) return 614;
                                                        }
                                                    }
                                                }
                                            }
                                            if (inst[10] == '8') {
                                                if (inst.size() < 12) return instr_search_failed;
                                                if (inst[11] == '.') {
                                                    if (inst.size() < 13) return instr_search_failed;
                                                    if (inst[12] == 'v') {
                                                        if (inst.size() < 14) return 602;
                                                    }
                                                }
                                            }
                                            if (inst[10] == '3') {
                                                if (inst.size() < 12) return instr_search_failed;
                                                if (inst[11] == '2') {
                                                    if (inst.size() < 13) return instr_search_failed;
                                                    if (inst[12] == '.') {
                                                        if (inst.size() < 14) return instr_search_failed;
                                                        if (inst[13] == 'v') {
                                                            if (inst.size() < 15) return 610;
                                                        }
                                                    }
                                                }
                                            }
                                        }
                                    }
                                }
                                if (inst[7] == '3') {
                                    if (inst.size() < 9) return instr_search_failed;
                                    if (inst[8] == 'e') {
                                        if (inst.size() < 10) return instr_search_failed;
                                        if (inst[9] == 'i') {
                                            if (inst.size() < 11) return instr_search_failed;
                                            if (inst[10] == '1') {
                                                if (inst.size() < 12) return instr_search_failed;
                                                if (inst[11] == '6') {
                                                    if (inst.size() < 13) return instr_search_failed;
                                                    if (inst[12] == '.') {
                                                        if (inst.size() < 14) return instr_search_failed;
                                                        if (inst[13] == 'v') {
                                                            if (inst.size() < 15) return 622;
                                                        }
                                                    }
                                                }
                                            }
                                            if (inst[10] == '6') {
                                                if (inst.size() < 12) return instr_search_failed;
                                                if (inst[11] == '4') {
                                                    if (inst.size() < 13) return instr_search_failed;
                                                    if (inst[12] == '.') {
                                                        if (inst.size() < 14) return instr_search_failed;
                                                        if (inst[13] == 'v') {
                                                            if (inst.size() < 15) return 630;
                                                        }
                                                    }
                                                }
                                            }
                                            if (inst[10] == '8') {
                                                if (inst.size() < 12) return instr_search_failed;
                                                if (inst[11] == '.') {
                                                    if (inst.size() < 13) return instr_search_failed;
                                                    if (inst[12] == 'v') {
                                                        if (inst.size() < 14) return 618;
                                                    }
                                                }
                                            }
                                            if (inst[10] == '3') {
                                                if (inst.size() < 12) return instr_search_failed;
                                                if (inst[11] == '2') {
                                                    if (inst.size() < 13) return instr_search_failed;
                                                    if (inst[12] == '.') {
                                                        if (inst.size() < 14) return instr_search_failed;
                                                        if (inst[13] == 'v') {
                                                            if (inst.size() < 15) return 626;
                                                        }
                                                    }
                                                }
                                            }
                                        }
                                    }
                                }
                                if (inst[7] == '7') {
                                    if (inst.size() < 9) return instr_search_failed;
                                    if (inst[8] == 'e') {
                                        if (inst.size() < 10) return instr_search_failed;
                                        if (inst[9] == 'i') {
                                            if (inst.size() < 11) return instr_search_failed;
                                            if (inst[10] == '1') {
                                                if (inst.size() < 12) return instr_search_failed;
                                                if (inst[11] == '6') {
                                                    if (inst.size() < 13) return instr_search_failed;
                                                    if (inst[12] == '.') {
                                                        if (inst.size() < 14) return instr_search_failed;
                                                        if (inst[13] == 'v') {
                                                            if (inst.size() < 15) return 686;
                                                        }
                                                    }
                                                }
                                            }
                                            if (inst[10] == '6') {
                                                if (inst.size() < 12) return instr_search_failed;
                                                if (inst[11] == '4') {
                                                    if (inst.size() < 13) return instr_search_failed;
                                                    if (inst[12] == '.') {
                                                        if (inst.size() < 14) return instr_search_failed;
                                                        if (inst[13] == 'v') {
                                                            if (inst.size() < 15) return 694;
                                                        }
                                                    }
                                                }
                                            }
                                            if (inst[10] == '8') {
                                                if (inst.size() < 12) return instr_search_failed;
                                                if (inst[11] == '.') {
                                                    if (inst.size() < 13) return instr_search_failed;
                                                    if (inst[12] == 'v') {
                                                        if (inst.size() < 14) return 682;
                                                    }
                                                }
                                            }
                                            if (inst[10] == '3') {
                                                if (inst.size() < 12) return instr_search_failed;
                                                if (inst[11] == '2') {
                                                    if (inst.size() < 13) return instr_search_failed;
                                                    if (inst[12] == '.') {
                                                        if (inst.size() < 14) return instr_search_failed;
                                                        if (inst[13] == 'v') {
                                                            if (inst.size() < 15) return 690;
                                                        }
                                                    }
                                                }
                                            }
                                        }
                                    }
                                }
                                if (inst[7] == '4') {
                                    if (inst.size() < 9) return instr_search_failed;
                                    if (inst[8] == 'e') {
                                        if (inst.size() < 10) return instr_search_failed;
                                        if (inst[9] == 'i') {
                                            if (inst.size() < 11) return instr_search_failed;
                                            if (inst[10] == '1') {
                                                if (inst.size() < 12) return instr_search_failed;
                                                if (inst[11] == '6') {
                                                    if (inst.size() < 13) return instr_search_failed;
                                                    if (inst[12] == '.') {
                                                        if (inst.size() < 14) return instr_search_failed;
                                                        if (inst[13] == 'v') {
                                                            if (inst.size() < 15) return 638;
                                                        }
                                                    }
                                                }
                                            }
                                            if (inst[10] == '6') {
                                                if (inst.size() < 12) return instr_search_failed;
                                                if (inst[11] == '4') {
                                                    if (inst.size() < 13) return instr_search_failed;
                                                    if (inst[12] == '.') {
                                                        if (inst.size() < 14) return instr_search_failed;
                                                        if (inst[13] == 'v') {
                                                            if (inst.size() < 15) return 646;
                                                        }
                                                    }
                                                }
                                            }
                                            if (inst[10] == '8') {
                                                if (inst.size() < 12) return instr_search_failed;
                                                if (inst[11] == '.') {
                                                    if (inst.size() < 13) return instr_search_failed;
                                                    if (inst[12] == 'v') {
                                                        if (inst.size() < 14) return 634;
                                                    }
                                                }
                                            }
                                            if (inst[10] == '3') {
                                                if (inst.size() < 12) return instr_search_failed;
                                                if (inst[11] == '2') {
                                                    if (inst.size() < 13) return instr_search_failed;
                                                    if (inst[12] == '.') {
                                                        if (inst.size() < 14) return instr_search_failed;
                                                        if (inst[13] == 'v') {
                                                            if (inst.size() < 15) return 642;
                                                        }
                                                    }
                                                }
                                            }
                                        }
                                    }
                                }
                                if (inst[7] == '5') {
                                    if (inst.size() < 9) return instr_search_failed;
                                    if (inst[8] == 'e') {
                                        if (inst.size() < 10) return instr_search_failed;
                                        if (inst[9] == 'i') {
                                            if (inst.size() < 11) return instr_search_failed;
                                            if (inst[10] == '1') {
                                                if (inst.size() < 12) return instr_search_failed;
                                                if (inst[11] == '6') {
                                                    if (inst.size() < 13) return instr_search_failed;
                                                    if (inst[12] == '.') {
                                                        if (inst.size() < 14) return instr_search_failed;
                                                        if (inst[13] == 'v') {
                                                            if (inst.size() < 15) return 654;
                                                        }
                                                    }
                                                }
                                            }
                                            if (inst[10] == '6') {
                                                if (inst.size() < 12) return instr_search_failed;
                                                if (inst[11] == '4') {
                                                    if (inst.size() < 13) return instr_search_failed;
                                                    if (inst[12] == '.') {
                                                        if (inst.size() < 14) return instr_search_failed;
                                                        if (inst[13] == 'v') {
                                                            if (inst.size() < 15) return 662;
                                                        }
                                                    }
                                                }
                                            }
                                            if (inst[10] == '8') {
                                                if (inst.size() < 12) return instr_search_failed;
                                                if (inst[11] == '.') {
                                                    if (inst.size() < 13) return instr_search_failed;
                                                    if (inst[12] == 'v') {
                                                        if (inst.size() < 14) return 650;
                                                    }
                                                }
                                            }
                                            if (inst[10] == '3') {
                                                if (inst.size() < 12) return instr_search_failed;
                                                if (inst[11] == '2') {
                                                    if (inst.size() < 13) return instr_search_failed;
                                                    if (inst[12] == '.') {
                                                        if (inst.size() < 14) return instr_search_failed;
                                                        if (inst[13] == 'v') {
                                                            if (inst.size() < 15) return 658;
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
                    if (inst[4] == 'e') {
                        if (inst.size() < 6) return instr_search_failed;
                        if (inst[5] == 'i') {
                            if (inst.size() < 7) return instr_search_failed;
                            if (inst[6] == '1') {
                                if (inst.size() < 8) return instr_search_failed;
                                if (inst[7] == '6') {
                                    if (inst.size() < 9) return instr_search_failed;
                                    if (inst[8] == '.') {
                                        if (inst.size() < 10) return instr_search_failed;
                                        if (inst[9] == 'v') {
                                            if (inst.size() < 11) return 446;
                                        }
                                    }
                                }
                            }
                            if (inst[6] == '6') {
                                if (inst.size() < 8) return instr_search_failed;
                                if (inst[7] == '4') {
                                    if (inst.size() < 9) return instr_search_failed;
                                    if (inst[8] == '.') {
                                        if (inst.size() < 10) return instr_search_failed;
                                        if (inst[9] == 'v') {
                                            if (inst.size() < 11) return 448;
                                        }
                                    }
                                }
                            }
                            if (inst[6] == '8') {
                                if (inst.size() < 8) return instr_search_failed;
                                if (inst[7] == '.') {
                                    if (inst.size() < 9) return instr_search_failed;
                                    if (inst[8] == 'v') {
                                        if (inst.size() < 10) return 445;
                                    }
                                }
                            }
                            if (inst[6] == '3') {
                                if (inst.size() < 8) return instr_search_failed;
                                if (inst[7] == '2') {
                                    if (inst.size() < 9) return instr_search_failed;
                                    if (inst[8] == '.') {
                                        if (inst.size() < 10) return instr_search_failed;
                                        if (inst[9] == 'v') {
                                            if (inst.size() < 11) return 447;
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
            if (inst[2] == 's') {
                if (inst.size() < 4) return instr_search_failed;
                if (inst[3] == 's') {
                    if (inst.size() < 5) return instr_search_failed;
                    if (inst[4] == 'e') {
                        if (inst.size() < 6) return instr_search_failed;
                        if (inst[5] == 'g') {
                            if (inst.size() < 7) return instr_search_failed;
                            if (inst[6] == '6') {
                                if (inst.size() < 8) return instr_search_failed;
                                if (inst[7] == 'e') {
                                    if (inst.size() < 9) return instr_search_failed;
                                    if (inst[8] == '1') {
                                        if (inst.size() < 10) return instr_search_failed;
                                        if (inst[9] == '6') {
                                            if (inst.size() < 11) return instr_search_failed;
                                            if (inst[10] == '.') {
                                                if (inst.size() < 12) return instr_search_failed;
                                                if (inst[11] == 'v') {
                                                    if (inst.size() < 13) return 579;
                                                }
                                            }
                                        }
                                    }
                                    if (inst[8] == '6') {
                                        if (inst.size() < 10) return instr_search_failed;
                                        if (inst[9] == '4') {
                                            if (inst.size() < 11) return instr_search_failed;
                                            if (inst[10] == '.') {
                                                if (inst.size() < 12) return instr_search_failed;
                                                if (inst[11] == 'v') {
                                                    if (inst.size() < 13) return 583;
                                                }
                                            }
                                        }
                                    }
                                    if (inst[8] == '8') {
                                        if (inst.size() < 10) return instr_search_failed;
                                        if (inst[9] == '.') {
                                            if (inst.size() < 11) return instr_search_failed;
                                            if (inst[10] == 'v') {
                                                if (inst.size() < 12) return 577;
                                            }
                                        }
                                    }
                                    if (inst[8] == '3') {
                                        if (inst.size() < 10) return instr_search_failed;
                                        if (inst[9] == '2') {
                                            if (inst.size() < 11) return instr_search_failed;
                                            if (inst[10] == '.') {
                                                if (inst.size() < 12) return instr_search_failed;
                                                if (inst[11] == 'v') {
                                                    if (inst.size() < 13) return 581;
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                            if (inst[6] == '8') {
                                if (inst.size() < 8) return instr_search_failed;
                                if (inst[7] == 'e') {
                                    if (inst.size() < 9) return instr_search_failed;
                                    if (inst[8] == '1') {
                                        if (inst.size() < 10) return instr_search_failed;
                                        if (inst[9] == '6') {
                                            if (inst.size() < 11) return instr_search_failed;
                                            if (inst[10] == '.') {
                                                if (inst.size() < 12) return instr_search_failed;
                                                if (inst[11] == 'v') {
                                                    if (inst.size() < 13) return 595;
                                                }
                                            }
                                        }
                                    }
                                    if (inst[8] == '6') {
                                        if (inst.size() < 10) return instr_search_failed;
                                        if (inst[9] == '4') {
                                            if (inst.size() < 11) return instr_search_failed;
                                            if (inst[10] == '.') {
                                                if (inst.size() < 12) return instr_search_failed;
                                                if (inst[11] == 'v') {
                                                    if (inst.size() < 13) return 599;
                                                }
                                            }
                                        }
                                    }
                                    if (inst[8] == '8') {
                                        if (inst.size() < 10) return instr_search_failed;
                                        if (inst[9] == '.') {
                                            if (inst.size() < 11) return instr_search_failed;
                                            if (inst[10] == 'v') {
                                                if (inst.size() < 12) return 593;
                                            }
                                        }
                                    }
                                    if (inst[8] == '3') {
                                        if (inst.size() < 10) return instr_search_failed;
                                        if (inst[9] == '2') {
                                            if (inst.size() < 11) return instr_search_failed;
                                            if (inst[10] == '.') {
                                                if (inst.size() < 12) return instr_search_failed;
                                                if (inst[11] == 'v') {
                                                    if (inst.size() < 13) return 597;
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                            if (inst[6] == '2') {
                                if (inst.size() < 8) return instr_search_failed;
                                if (inst[7] == 'e') {
                                    if (inst.size() < 9) return instr_search_failed;
                                    if (inst[8] == '1') {
                                        if (inst.size() < 10) return instr_search_failed;
                                        if (inst[9] == '6') {
                                            if (inst.size() < 11) return instr_search_failed;
                                            if (inst[10] == '.') {
                                                if (inst.size() < 12) return instr_search_failed;
                                                if (inst[11] == 'v') {
                                                    if (inst.size() < 13) return 547;
                                                }
                                            }
                                        }
                                    }
                                    if (inst[8] == '6') {
                                        if (inst.size() < 10) return instr_search_failed;
                                        if (inst[9] == '4') {
                                            if (inst.size() < 11) return instr_search_failed;
                                            if (inst[10] == '.') {
                                                if (inst.size() < 12) return instr_search_failed;
                                                if (inst[11] == 'v') {
                                                    if (inst.size() < 13) return 551;
                                                }
                                            }
                                        }
                                    }
                                    if (inst[8] == '8') {
                                        if (inst.size() < 10) return instr_search_failed;
                                        if (inst[9] == '.') {
                                            if (inst.size() < 11) return instr_search_failed;
                                            if (inst[10] == 'v') {
                                                if (inst.size() < 12) return 545;
                                            }
                                        }
                                    }
                                    if (inst[8] == '3') {
                                        if (inst.size() < 10) return instr_search_failed;
                                        if (inst[9] == '2') {
                                            if (inst.size() < 11) return instr_search_failed;
                                            if (inst[10] == '.') {
                                                if (inst.size() < 12) return instr_search_failed;
                                                if (inst[11] == 'v') {
                                                    if (inst.size() < 13) return 549;
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                            if (inst[6] == '3') {
                                if (inst.size() < 8) return instr_search_failed;
                                if (inst[7] == 'e') {
                                    if (inst.size() < 9) return instr_search_failed;
                                    if (inst[8] == '1') {
                                        if (inst.size() < 10) return instr_search_failed;
                                        if (inst[9] == '6') {
                                            if (inst.size() < 11) return instr_search_failed;
                                            if (inst[10] == '.') {
                                                if (inst.size() < 12) return instr_search_failed;
                                                if (inst[11] == 'v') {
                                                    if (inst.size() < 13) return 555;
                                                }
                                            }
                                        }
                                    }
                                    if (inst[8] == '6') {
                                        if (inst.size() < 10) return instr_search_failed;
                                        if (inst[9] == '4') {
                                            if (inst.size() < 11) return instr_search_failed;
                                            if (inst[10] == '.') {
                                                if (inst.size() < 12) return instr_search_failed;
                                                if (inst[11] == 'v') {
                                                    if (inst.size() < 13) return 559;
                                                }
                                            }
                                        }
                                    }
                                    if (inst[8] == '8') {
                                        if (inst.size() < 10) return instr_search_failed;
                                        if (inst[9] == '.') {
                                            if (inst.size() < 11) return instr_search_failed;
                                            if (inst[10] == 'v') {
                                                if (inst.size() < 12) return 553;
                                            }
                                        }
                                    }
                                    if (inst[8] == '3') {
                                        if (inst.size() < 10) return instr_search_failed;
                                        if (inst[9] == '2') {
                                            if (inst.size() < 11) return instr_search_failed;
                                            if (inst[10] == '.') {
                                                if (inst.size() < 12) return instr_search_failed;
                                                if (inst[11] == 'v') {
                                                    if (inst.size() < 13) return 557;
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                            if (inst[6] == '7') {
                                if (inst.size() < 8) return instr_search_failed;
                                if (inst[7] == 'e') {
                                    if (inst.size() < 9) return instr_search_failed;
                                    if (inst[8] == '1') {
                                        if (inst.size() < 10) return instr_search_failed;
                                        if (inst[9] == '6') {
                                            if (inst.size() < 11) return instr_search_failed;
                                            if (inst[10] == '.') {
                                                if (inst.size() < 12) return instr_search_failed;
                                                if (inst[11] == 'v') {
                                                    if (inst.size() < 13) return 587;
                                                }
                                            }
                                        }
                                    }
                                    if (inst[8] == '6') {
                                        if (inst.size() < 10) return instr_search_failed;
                                        if (inst[9] == '4') {
                                            if (inst.size() < 11) return instr_search_failed;
                                            if (inst[10] == '.') {
                                                if (inst.size() < 12) return instr_search_failed;
                                                if (inst[11] == 'v') {
                                                    if (inst.size() < 13) return 591;
                                                }
                                            }
                                        }
                                    }
                                    if (inst[8] == '8') {
                                        if (inst.size() < 10) return instr_search_failed;
                                        if (inst[9] == '.') {
                                            if (inst.size() < 11) return instr_search_failed;
                                            if (inst[10] == 'v') {
                                                if (inst.size() < 12) return 585;
                                            }
                                        }
                                    }
                                    if (inst[8] == '3') {
                                        if (inst.size() < 10) return instr_search_failed;
                                        if (inst[9] == '2') {
                                            if (inst.size() < 11) return instr_search_failed;
                                            if (inst[10] == '.') {
                                                if (inst.size() < 12) return instr_search_failed;
                                                if (inst[11] == 'v') {
                                                    if (inst.size() < 13) return 589;
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                            if (inst[6] == '4') {
                                if (inst.size() < 8) return instr_search_failed;
                                if (inst[7] == 'e') {
                                    if (inst.size() < 9) return instr_search_failed;
                                    if (inst[8] == '1') {
                                        if (inst.size() < 10) return instr_search_failed;
                                        if (inst[9] == '6') {
                                            if (inst.size() < 11) return instr_search_failed;
                                            if (inst[10] == '.') {
                                                if (inst.size() < 12) return instr_search_failed;
                                                if (inst[11] == 'v') {
                                                    if (inst.size() < 13) return 563;
                                                }
                                            }
                                        }
                                    }
                                    if (inst[8] == '6') {
                                        if (inst.size() < 10) return instr_search_failed;
                                        if (inst[9] == '4') {
                                            if (inst.size() < 11) return instr_search_failed;
                                            if (inst[10] == '.') {
                                                if (inst.size() < 12) return instr_search_failed;
                                                if (inst[11] == 'v') {
                                                    if (inst.size() < 13) return 567;
                                                }
                                            }
                                        }
                                    }
                                    if (inst[8] == '8') {
                                        if (inst.size() < 10) return instr_search_failed;
                                        if (inst[9] == '.') {
                                            if (inst.size() < 11) return instr_search_failed;
                                            if (inst[10] == 'v') {
                                                if (inst.size() < 12) return 561;
                                            }
                                        }
                                    }
                                    if (inst[8] == '3') {
                                        if (inst.size() < 10) return instr_search_failed;
                                        if (inst[9] == '2') {
                                            if (inst.size() < 11) return instr_search_failed;
                                            if (inst[10] == '.') {
                                                if (inst.size() < 12) return instr_search_failed;
                                                if (inst[11] == 'v') {
                                                    if (inst.size() < 13) return 565;
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                            if (inst[6] == '5') {
                                if (inst.size() < 8) return instr_search_failed;
                                if (inst[7] == 'e') {
                                    if (inst.size() < 9) return instr_search_failed;
                                    if (inst[8] == '.') {
                                        if (inst.size() < 10) return instr_search_failed;
                                        if (inst[9] == 'v') {
                                            if (inst.size() < 11) return 571;
                                        }
                                    }
                                    if (inst[8] == '6') {
                                        if (inst.size() < 10) return instr_search_failed;
                                        if (inst[9] == '4') {
                                            if (inst.size() < 11) return instr_search_failed;
                                            if (inst[10] == '.') {
                                                if (inst.size() < 12) return instr_search_failed;
                                                if (inst[11] == 'v') {
                                                    if (inst.size() < 13) return 575;
                                                }
                                            }
                                        }
                                    }
                                    if (inst[8] == '8') {
                                        if (inst.size() < 10) return instr_search_failed;
                                        if (inst[9] == '.') {
                                            if (inst.size() < 11) return instr_search_failed;
                                            if (inst[10] == 'v') {
                                                if (inst.size() < 12) return 569;
                                            }
                                        }
                                    }
                                    if (inst[8] == '3') {
                                        if (inst.size() < 10) return instr_search_failed;
                                        if (inst[9] == '2') {
                                            if (inst.size() < 11) return instr_search_failed;
                                            if (inst[10] == '.') {
                                                if (inst.size() < 12) return instr_search_failed;
                                                if (inst[11] == 'v') {
                                                    if (inst.size() < 13) return 573;
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
                if (inst[3] == 'e') {
                    if (inst.size() < 5) return instr_search_failed;
                    if (inst[4] == 'g') {
                        if (inst.size() < 6) return instr_search_failed;
                        if (inst[5] == '6') {
                            if (inst.size() < 7) return instr_search_failed;
                            if (inst[6] == 'e') {
                                if (inst.size() < 8) return instr_search_failed;
                                if (inst[7] == '1') {
                                    if (inst.size() < 9) return instr_search_failed;
                                    if (inst[8] == '6') {
                                        if (inst.size() < 10) return instr_search_failed;
                                        if (inst[9] == '.') {
                                            if (inst.size() < 11) return instr_search_failed;
                                            if (inst[10] == 'v') {
                                                if (inst.size() < 12) return 495;
                                            }
                                        }
                                        if (inst[9] == 'f') {
                                            if (inst.size() < 11) return instr_search_failed;
                                            if (inst[10] == 'f') {
                                                if (inst.size() < 12) return instr_search_failed;
                                                if (inst[11] == '.') {
                                                    if (inst.size() < 13) return instr_search_failed;
                                                    if (inst[12] == 'v') {
                                                        if (inst.size() < 14) return 534;
                                                    }
                                                }
                                            }
                                        }
                                    }
                                }
                                if (inst[7] == '6') {
                                    if (inst.size() < 9) return instr_search_failed;
                                    if (inst[8] == '4') {
                                        if (inst.size() < 10) return instr_search_failed;
                                        if (inst[9] == '.') {
                                            if (inst.size() < 11) return instr_search_failed;
                                            if (inst[10] == 'v') {
                                                if (inst.size() < 12) return 499;
                                            }
                                        }
                                        if (inst[9] == 'f') {
                                            if (inst.size() < 11) return instr_search_failed;
                                            if (inst[10] == 'f') {
                                                if (inst.size() < 12) return instr_search_failed;
                                                if (inst[11] == '.') {
                                                    if (inst.size() < 13) return instr_search_failed;
                                                    if (inst[12] == 'v') {
                                                        if (inst.size() < 14) return 536;
                                                    }
                                                }
                                            }
                                        }
                                    }
                                }
                                if (inst[7] == '8') {
                                    if (inst.size() < 9) return instr_search_failed;
                                    if (inst[8] == '.') {
                                        if (inst.size() < 10) return instr_search_failed;
                                        if (inst[9] == 'v') {
                                            if (inst.size() < 11) return 493;
                                        }
                                    }
                                    if (inst[8] == 'f') {
                                        if (inst.size() < 10) return instr_search_failed;
                                        if (inst[9] == 'f') {
                                            if (inst.size() < 11) return instr_search_failed;
                                            if (inst[10] == '.') {
                                                if (inst.size() < 12) return instr_search_failed;
                                                if (inst[11] == 'v') {
                                                    if (inst.size() < 13) return 533;
                                                }
                                            }
                                        }
                                    }
                                }
                                if (inst[7] == '3') {
                                    if (inst.size() < 9) return instr_search_failed;
                                    if (inst[8] == '2') {
                                        if (inst.size() < 10) return instr_search_failed;
                                        if (inst[9] == '.') {
                                            if (inst.size() < 11) return instr_search_failed;
                                            if (inst[10] == 'v') {
                                                if (inst.size() < 12) return 497;
                                            }
                                        }
                                        if (inst[9] == 'f') {
                                            if (inst.size() < 11) return instr_search_failed;
                                            if (inst[10] == 'f') {
                                                if (inst.size() < 12) return instr_search_failed;
                                                if (inst[11] == '.') {
                                                    if (inst.size() < 13) return instr_search_failed;
                                                    if (inst[12] == 'v') {
                                                        if (inst.size() < 14) return 535;
                                                    }
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                        if (inst[5] == '8') {
                            if (inst.size() < 7) return instr_search_failed;
                            if (inst[6] == 'e') {
                                if (inst.size() < 8) return instr_search_failed;
                                if (inst[7] == '1') {
                                    if (inst.size() < 9) return instr_search_failed;
                                    if (inst[8] == '6') {
                                        if (inst.size() < 10) return instr_search_failed;
                                        if (inst[9] == '.') {
                                            if (inst.size() < 11) return instr_search_failed;
                                            if (inst[10] == 'v') {
                                                if (inst.size() < 12) return 511;
                                            }
                                        }
                                        if (inst[9] == 'f') {
                                            if (inst.size() < 11) return instr_search_failed;
                                            if (inst[10] == 'f') {
                                                if (inst.size() < 12) return instr_search_failed;
                                                if (inst[11] == '.') {
                                                    if (inst.size() < 13) return instr_search_failed;
                                                    if (inst[12] == 'v') {
                                                        if (inst.size() < 14) return 542;
                                                    }
                                                }
                                            }
                                        }
                                    }
                                }
                                if (inst[7] == '6') {
                                    if (inst.size() < 9) return instr_search_failed;
                                    if (inst[8] == '4') {
                                        if (inst.size() < 10) return instr_search_failed;
                                        if (inst[9] == '.') {
                                            if (inst.size() < 11) return instr_search_failed;
                                            if (inst[10] == 'v') {
                                                if (inst.size() < 12) return 515;
                                            }
                                        }
                                        if (inst[9] == 'f') {
                                            if (inst.size() < 11) return instr_search_failed;
                                            if (inst[10] == 'f') {
                                                if (inst.size() < 12) return instr_search_failed;
                                                if (inst[11] == '.') {
                                                    if (inst.size() < 13) return instr_search_failed;
                                                    if (inst[12] == 'v') {
                                                        if (inst.size() < 14) return 544;
                                                    }
                                                }
                                            }
                                        }
                                    }
                                }
                                if (inst[7] == '8') {
                                    if (inst.size() < 9) return instr_search_failed;
                                    if (inst[8] == '.') {
                                        if (inst.size() < 10) return instr_search_failed;
                                        if (inst[9] == 'v') {
                                            if (inst.size() < 11) return 509;
                                        }
                                    }
                                    if (inst[8] == 'f') {
                                        if (inst.size() < 10) return instr_search_failed;
                                        if (inst[9] == 'f') {
                                            if (inst.size() < 11) return instr_search_failed;
                                            if (inst[10] == '.') {
                                                if (inst.size() < 12) return instr_search_failed;
                                                if (inst[11] == 'v') {
                                                    if (inst.size() < 13) return 541;
                                                }
                                            }
                                        }
                                    }
                                }
                                if (inst[7] == '3') {
                                    if (inst.size() < 9) return instr_search_failed;
                                    if (inst[8] == '2') {
                                        if (inst.size() < 10) return instr_search_failed;
                                        if (inst[9] == '.') {
                                            if (inst.size() < 11) return instr_search_failed;
                                            if (inst[10] == 'v') {
                                                if (inst.size() < 12) return 513;
                                            }
                                        }
                                        if (inst[9] == 'f') {
                                            if (inst.size() < 11) return instr_search_failed;
                                            if (inst[10] == 'f') {
                                                if (inst.size() < 12) return instr_search_failed;
                                                if (inst[11] == '.') {
                                                    if (inst.size() < 13) return instr_search_failed;
                                                    if (inst[12] == 'v') {
                                                        if (inst.size() < 14) return 543;
                                                    }
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                        if (inst[5] == '2') {
                            if (inst.size() < 7) return instr_search_failed;
                            if (inst[6] == 'e') {
                                if (inst.size() < 8) return instr_search_failed;
                                if (inst[7] == '1') {
                                    if (inst.size() < 9) return instr_search_failed;
                                    if (inst[8] == '6') {
                                        if (inst.size() < 10) return instr_search_failed;
                                        if (inst[9] == '.') {
                                            if (inst.size() < 11) return instr_search_failed;
                                            if (inst[10] == 'v') {
                                                if (inst.size() < 12) return 463;
                                            }
                                        }
                                        if (inst[9] == 'f') {
                                            if (inst.size() < 11) return instr_search_failed;
                                            if (inst[10] == 'f') {
                                                if (inst.size() < 12) return instr_search_failed;
                                                if (inst[11] == '.') {
                                                    if (inst.size() < 13) return instr_search_failed;
                                                    if (inst[12] == 'v') {
                                                        if (inst.size() < 14) return 518;
                                                    }
                                                }
                                            }
                                        }
                                    }
                                }
                                if (inst[7] == '6') {
                                    if (inst.size() < 9) return instr_search_failed;
                                    if (inst[8] == '4') {
                                        if (inst.size() < 10) return instr_search_failed;
                                        if (inst[9] == '.') {
                                            if (inst.size() < 11) return instr_search_failed;
                                            if (inst[10] == 'v') {
                                                if (inst.size() < 12) return 467;
                                            }
                                        }
                                        if (inst[9] == 'f') {
                                            if (inst.size() < 11) return instr_search_failed;
                                            if (inst[10] == 'f') {
                                                if (inst.size() < 12) return instr_search_failed;
                                                if (inst[11] == '.') {
                                                    if (inst.size() < 13) return instr_search_failed;
                                                    if (inst[12] == 'v') {
                                                        if (inst.size() < 14) return 520;
                                                    }
                                                }
                                            }
                                        }
                                    }
                                }
                                if (inst[7] == '8') {
                                    if (inst.size() < 9) return instr_search_failed;
                                    if (inst[8] == '.') {
                                        if (inst.size() < 10) return instr_search_failed;
                                        if (inst[9] == 'v') {
                                            if (inst.size() < 11) return 461;
                                        }
                                    }
                                    if (inst[8] == 'f') {
                                        if (inst.size() < 10) return instr_search_failed;
                                        if (inst[9] == 'f') {
                                            if (inst.size() < 11) return instr_search_failed;
                                            if (inst[10] == '.') {
                                                if (inst.size() < 12) return instr_search_failed;
                                                if (inst[11] == 'v') {
                                                    if (inst.size() < 13) return 517;
                                                }
                                            }
                                        }
                                    }
                                }
                                if (inst[7] == '3') {
                                    if (inst.size() < 9) return instr_search_failed;
                                    if (inst[8] == '2') {
                                        if (inst.size() < 10) return instr_search_failed;
                                        if (inst[9] == '.') {
                                            if (inst.size() < 11) return instr_search_failed;
                                            if (inst[10] == 'v') {
                                                if (inst.size() < 12) return 465;
                                            }
                                        }
                                        if (inst[9] == 'f') {
                                            if (inst.size() < 11) return instr_search_failed;
                                            if (inst[10] == 'f') {
                                                if (inst.size() < 12) return instr_search_failed;
                                                if (inst[11] == '.') {
                                                    if (inst.size() < 13) return instr_search_failed;
                                                    if (inst[12] == 'v') {
                                                        if (inst.size() < 14) return 519;
                                                    }
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                        if (inst[5] == '3') {
                            if (inst.size() < 7) return instr_search_failed;
                            if (inst[6] == 'e') {
                                if (inst.size() < 8) return instr_search_failed;
                                if (inst[7] == '1') {
                                    if (inst.size() < 9) return instr_search_failed;
                                    if (inst[8] == '6') {
                                        if (inst.size() < 10) return instr_search_failed;
                                        if (inst[9] == '.') {
                                            if (inst.size() < 11) return instr_search_failed;
                                            if (inst[10] == 'v') {
                                                if (inst.size() < 12) return 471;
                                            }
                                        }
                                        if (inst[9] == 'f') {
                                            if (inst.size() < 11) return instr_search_failed;
                                            if (inst[10] == 'f') {
                                                if (inst.size() < 12) return instr_search_failed;
                                                if (inst[11] == '.') {
                                                    if (inst.size() < 13) return instr_search_failed;
                                                    if (inst[12] == 'v') {
                                                        if (inst.size() < 14) return 522;
                                                    }
                                                }
                                            }
                                        }
                                    }
                                }
                                if (inst[7] == '6') {
                                    if (inst.size() < 9) return instr_search_failed;
                                    if (inst[8] == '4') {
                                        if (inst.size() < 10) return instr_search_failed;
                                        if (inst[9] == '.') {
                                            if (inst.size() < 11) return instr_search_failed;
                                            if (inst[10] == 'v') {
                                                if (inst.size() < 12) return 475;
                                            }
                                        }
                                        if (inst[9] == 'f') {
                                            if (inst.size() < 11) return instr_search_failed;
                                            if (inst[10] == 'f') {
                                                if (inst.size() < 12) return instr_search_failed;
                                                if (inst[11] == '.') {
                                                    if (inst.size() < 13) return instr_search_failed;
                                                    if (inst[12] == 'v') {
                                                        if (inst.size() < 14) return 524;
                                                    }
                                                }
                                            }
                                        }
                                    }
                                }
                                if (inst[7] == '8') {
                                    if (inst.size() < 9) return instr_search_failed;
                                    if (inst[8] == '.') {
                                        if (inst.size() < 10) return instr_search_failed;
                                        if (inst[9] == 'v') {
                                            if (inst.size() < 11) return 469;
                                        }
                                    }
                                    if (inst[8] == 'f') {
                                        if (inst.size() < 10) return instr_search_failed;
                                        if (inst[9] == 'f') {
                                            if (inst.size() < 11) return instr_search_failed;
                                            if (inst[10] == '.') {
                                                if (inst.size() < 12) return instr_search_failed;
                                                if (inst[11] == 'v') {
                                                    if (inst.size() < 13) return 521;
                                                }
                                            }
                                        }
                                    }
                                }
                                if (inst[7] == '3') {
                                    if (inst.size() < 9) return instr_search_failed;
                                    if (inst[8] == '2') {
                                        if (inst.size() < 10) return instr_search_failed;
                                        if (inst[9] == '.') {
                                            if (inst.size() < 11) return instr_search_failed;
                                            if (inst[10] == 'v') {
                                                if (inst.size() < 12) return 473;
                                            }
                                        }
                                        if (inst[9] == 'f') {
                                            if (inst.size() < 11) return instr_search_failed;
                                            if (inst[10] == 'f') {
                                                if (inst.size() < 12) return instr_search_failed;
                                                if (inst[11] == '.') {
                                                    if (inst.size() < 13) return instr_search_failed;
                                                    if (inst[12] == 'v') {
                                                        if (inst.size() < 14) return 523;
                                                    }
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                        if (inst[5] == '7') {
                            if (inst.size() < 7) return instr_search_failed;
                            if (inst[6] == 'e') {
                                if (inst.size() < 8) return instr_search_failed;
                                if (inst[7] == '1') {
                                    if (inst.size() < 9) return instr_search_failed;
                                    if (inst[8] == '6') {
                                        if (inst.size() < 10) return instr_search_failed;
                                        if (inst[9] == '.') {
                                            if (inst.size() < 11) return instr_search_failed;
                                            if (inst[10] == 'v') {
                                                if (inst.size() < 12) return 503;
                                            }
                                        }
                                        if (inst[9] == 'f') {
                                            if (inst.size() < 11) return instr_search_failed;
                                            if (inst[10] == 'f') {
                                                if (inst.size() < 12) return instr_search_failed;
                                                if (inst[11] == '.') {
                                                    if (inst.size() < 13) return instr_search_failed;
                                                    if (inst[12] == 'v') {
                                                        if (inst.size() < 14) return 538;
                                                    }
                                                }
                                            }
                                        }
                                    }
                                }
                                if (inst[7] == '6') {
                                    if (inst.size() < 9) return instr_search_failed;
                                    if (inst[8] == '4') {
                                        if (inst.size() < 10) return instr_search_failed;
                                        if (inst[9] == '.') {
                                            if (inst.size() < 11) return instr_search_failed;
                                            if (inst[10] == 'v') {
                                                if (inst.size() < 12) return 507;
                                            }
                                        }
                                        if (inst[9] == 'f') {
                                            if (inst.size() < 11) return instr_search_failed;
                                            if (inst[10] == 'f') {
                                                if (inst.size() < 12) return instr_search_failed;
                                                if (inst[11] == '.') {
                                                    if (inst.size() < 13) return instr_search_failed;
                                                    if (inst[12] == 'v') {
                                                        if (inst.size() < 14) return 540;
                                                    }
                                                }
                                            }
                                        }
                                    }
                                }
                                if (inst[7] == '8') {
                                    if (inst.size() < 9) return instr_search_failed;
                                    if (inst[8] == '.') {
                                        if (inst.size() < 10) return instr_search_failed;
                                        if (inst[9] == 'v') {
                                            if (inst.size() < 11) return 501;
                                        }
                                    }
                                    if (inst[8] == 'f') {
                                        if (inst.size() < 10) return instr_search_failed;
                                        if (inst[9] == 'f') {
                                            if (inst.size() < 11) return instr_search_failed;
                                            if (inst[10] == '.') {
                                                if (inst.size() < 12) return instr_search_failed;
                                                if (inst[11] == 'v') {
                                                    if (inst.size() < 13) return 537;
                                                }
                                            }
                                        }
                                    }
                                }
                                if (inst[7] == '3') {
                                    if (inst.size() < 9) return instr_search_failed;
                                    if (inst[8] == '2') {
                                        if (inst.size() < 10) return instr_search_failed;
                                        if (inst[9] == '.') {
                                            if (inst.size() < 11) return instr_search_failed;
                                            if (inst[10] == 'v') {
                                                if (inst.size() < 12) return 505;
                                            }
                                        }
                                        if (inst[9] == 'f') {
                                            if (inst.size() < 11) return instr_search_failed;
                                            if (inst[10] == 'f') {
                                                if (inst.size() < 12) return instr_search_failed;
                                                if (inst[11] == '.') {
                                                    if (inst.size() < 13) return instr_search_failed;
                                                    if (inst[12] == 'v') {
                                                        if (inst.size() < 14) return 539;
                                                    }
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                        if (inst[5] == '4') {
                            if (inst.size() < 7) return instr_search_failed;
                            if (inst[6] == 'e') {
                                if (inst.size() < 8) return instr_search_failed;
                                if (inst[7] == '1') {
                                    if (inst.size() < 9) return instr_search_failed;
                                    if (inst[8] == '6') {
                                        if (inst.size() < 10) return instr_search_failed;
                                        if (inst[9] == '.') {
                                            if (inst.size() < 11) return instr_search_failed;
                                            if (inst[10] == 'v') {
                                                if (inst.size() < 12) return 479;
                                            }
                                        }
                                        if (inst[9] == 'f') {
                                            if (inst.size() < 11) return instr_search_failed;
                                            if (inst[10] == 'f') {
                                                if (inst.size() < 12) return instr_search_failed;
                                                if (inst[11] == '.') {
                                                    if (inst.size() < 13) return instr_search_failed;
                                                    if (inst[12] == 'v') {
                                                        if (inst.size() < 14) return 526;
                                                    }
                                                }
                                            }
                                        }
                                    }
                                }
                                if (inst[7] == '6') {
                                    if (inst.size() < 9) return instr_search_failed;
                                    if (inst[8] == '4') {
                                        if (inst.size() < 10) return instr_search_failed;
                                        if (inst[9] == '.') {
                                            if (inst.size() < 11) return instr_search_failed;
                                            if (inst[10] == 'v') {
                                                if (inst.size() < 12) return 483;
                                            }
                                        }
                                        if (inst[9] == 'f') {
                                            if (inst.size() < 11) return instr_search_failed;
                                            if (inst[10] == 'f') {
                                                if (inst.size() < 12) return instr_search_failed;
                                                if (inst[11] == '.') {
                                                    if (inst.size() < 13) return instr_search_failed;
                                                    if (inst[12] == 'v') {
                                                        if (inst.size() < 14) return 528;
                                                    }
                                                }
                                            }
                                        }
                                    }
                                }
                                if (inst[7] == '8') {
                                    if (inst.size() < 9) return instr_search_failed;
                                    if (inst[8] == '.') {
                                        if (inst.size() < 10) return instr_search_failed;
                                        if (inst[9] == 'v') {
                                            if (inst.size() < 11) return 477;
                                        }
                                    }
                                    if (inst[8] == 'f') {
                                        if (inst.size() < 10) return instr_search_failed;
                                        if (inst[9] == 'f') {
                                            if (inst.size() < 11) return instr_search_failed;
                                            if (inst[10] == '.') {
                                                if (inst.size() < 12) return instr_search_failed;
                                                if (inst[11] == 'v') {
                                                    if (inst.size() < 13) return 525;
                                                }
                                            }
                                        }
                                    }
                                }
                                if (inst[7] == '3') {
                                    if (inst.size() < 9) return instr_search_failed;
                                    if (inst[8] == '2') {
                                        if (inst.size() < 10) return instr_search_failed;
                                        if (inst[9] == '.') {
                                            if (inst.size() < 11) return instr_search_failed;
                                            if (inst[10] == 'v') {
                                                if (inst.size() < 12) return 481;
                                            }
                                        }
                                        if (inst[9] == 'f') {
                                            if (inst.size() < 11) return instr_search_failed;
                                            if (inst[10] == 'f') {
                                                if (inst.size() < 12) return instr_search_failed;
                                                if (inst[11] == '.') {
                                                    if (inst.size() < 13) return instr_search_failed;
                                                    if (inst[12] == 'v') {
                                                        if (inst.size() < 14) return 527;
                                                    }
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                        if (inst[5] == '5') {
                            if (inst.size() < 7) return instr_search_failed;
                            if (inst[6] == 'e') {
                                if (inst.size() < 8) return instr_search_failed;
                                if (inst[7] == '1') {
                                    if (inst.size() < 9) return instr_search_failed;
                                    if (inst[8] == '6') {
                                        if (inst.size() < 10) return instr_search_failed;
                                        if (inst[9] == '.') {
                                            if (inst.size() < 11) return instr_search_failed;
                                            if (inst[10] == 'v') {
                                                if (inst.size() < 12) return 487;
                                            }
                                        }
                                        if (inst[9] == 'f') {
                                            if (inst.size() < 11) return instr_search_failed;
                                            if (inst[10] == 'f') {
                                                if (inst.size() < 12) return instr_search_failed;
                                                if (inst[11] == '.') {
                                                    if (inst.size() < 13) return instr_search_failed;
                                                    if (inst[12] == 'v') {
                                                        if (inst.size() < 14) return 530;
                                                    }
                                                }
                                            }
                                        }
                                    }
                                }
                                if (inst[7] == '6') {
                                    if (inst.size() < 9) return instr_search_failed;
                                    if (inst[8] == '4') {
                                        if (inst.size() < 10) return instr_search_failed;
                                        if (inst[9] == '.') {
                                            if (inst.size() < 11) return instr_search_failed;
                                            if (inst[10] == 'v') {
                                                if (inst.size() < 12) return 491;
                                            }
                                        }
                                        if (inst[9] == 'f') {
                                            if (inst.size() < 11) return instr_search_failed;
                                            if (inst[10] == 'f') {
                                                if (inst.size() < 12) return instr_search_failed;
                                                if (inst[11] == '.') {
                                                    if (inst.size() < 13) return instr_search_failed;
                                                    if (inst[12] == 'v') {
                                                        if (inst.size() < 14) return 532;
                                                    }
                                                }
                                            }
                                        }
                                    }
                                }
                                if (inst[7] == '8') {
                                    if (inst.size() < 9) return instr_search_failed;
                                    if (inst[8] == '.') {
                                        if (inst.size() < 10) return instr_search_failed;
                                        if (inst[9] == 'v') {
                                            if (inst.size() < 11) return 485;
                                        }
                                    }
                                    if (inst[8] == 'f') {
                                        if (inst.size() < 10) return instr_search_failed;
                                        if (inst[9] == 'f') {
                                            if (inst.size() < 11) return instr_search_failed;
                                            if (inst[10] == '.') {
                                                if (inst.size() < 12) return instr_search_failed;
                                                if (inst[11] == 'v') {
                                                    if (inst.size() < 13) return 529;
                                                }
                                            }
                                        }
                                    }
                                }
                                if (inst[7] == '3') {
                                    if (inst.size() < 9) return instr_search_failed;
                                    if (inst[8] == '2') {
                                        if (inst.size() < 10) return instr_search_failed;
                                        if (inst[9] == '.') {
                                            if (inst.size() < 11) return instr_search_failed;
                                            if (inst[10] == 'v') {
                                                if (inst.size() < 12) return 489;
                                            }
                                        }
                                        if (inst[9] == 'f') {
                                            if (inst.size() < 11) return instr_search_failed;
                                            if (inst[10] == 'f') {
                                                if (inst.size() < 12) return instr_search_failed;
                                                if (inst[11] == '.') {
                                                    if (inst.size() < 13) return instr_search_failed;
                                                    if (inst[12] == 'v') {
                                                        if (inst.size() < 14) return 531;
                                                    }
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                    if (inst[4] == '1') {
                        if (inst.size() < 6) return instr_search_failed;
                        if (inst[5] == '6') {
                            if (inst.size() < 7) return instr_search_failed;
                            if (inst[6] == '.') {
                                if (inst.size() < 8) return instr_search_failed;
                                if (inst[7] == 'v') {
                                    if (inst.size() < 9) return 434;
                                }
                            }
                        }
                    }
                    if (inst[4] == '6') {
                        if (inst.size() < 6) return instr_search_failed;
                        if (inst[5] == '4') {
                            if (inst.size() < 7) return instr_search_failed;
                            if (inst[6] == '.') {
                                if (inst.size() < 8) return instr_search_failed;
                                if (inst[7] == 'v') {
                                    if (inst.size() < 9) return 436;
                                }
                            }
                        }
                    }
                    if (inst[4] == '8') {
                        if (inst.size() < 6) return instr_search_failed;
                        if (inst[5] == '.') {
                            if (inst.size() < 7) return instr_search_failed;
                            if (inst[6] == 'v') {
                                if (inst.size() < 8) return 433;
                            }
                        }
                    }
                    if (inst[4] == '3') {
                        if (inst.size() < 6) return instr_search_failed;
                        if (inst[5] == '2') {
                            if (inst.size() < 7) return instr_search_failed;
                            if (inst[6] == '.') {
                                if (inst.size() < 8) return instr_search_failed;
                                if (inst[7] == 'v') {
                                    if (inst.size() < 9) return 435;
                                }
                            }
                        }
                    }
                }
            }
            if (inst[2] == 'e') {
                if (inst.size() < 4) return instr_search_failed;
                if (inst[3] == '1') {
                    if (inst.size() < 5) return instr_search_failed;
                    if (inst[4] == '6') {
                        if (inst.size() < 6) return instr_search_failed;
                        if (inst[5] == '.') {
                            if (inst.size() < 7) return instr_search_failed;
                            if (inst[6] == 'v') {
                                if (inst.size() < 8) return 424;
                            }
                        }
                        if (inst[5] == 'f') {
                            if (inst.size() < 7) return instr_search_failed;
                            if (inst[6] == 'f') {
                                if (inst.size() < 8) return instr_search_failed;
                                if (inst[7] == '.') {
                                    if (inst.size() < 9) return instr_search_failed;
                                    if (inst[8] == 'v') {
                                        if (inst.size() < 10) return 458;
                                    }
                                }
                            }
                        }
                    }
                }
                if (inst[3] == '6') {
                    if (inst.size() < 5) return instr_search_failed;
                    if (inst[4] == '4') {
                        if (inst.size() < 6) return instr_search_failed;
                        if (inst[5] == '.') {
                            if (inst.size() < 7) return instr_search_failed;
                            if (inst[6] == 'v') {
                                if (inst.size() < 8) return 426;
                            }
                        }
                        if (inst[5] == 'f') {
                            if (inst.size() < 7) return instr_search_failed;
                            if (inst[6] == 'f') {
                                if (inst.size() < 8) return instr_search_failed;
                                if (inst[7] == '.') {
                                    if (inst.size() < 9) return instr_search_failed;
                                    if (inst[8] == 'v') {
                                        if (inst.size() < 10) return 460;
                                    }
                                }
                            }
                        }
                    }
                }
                if (inst[3] == '8') {
                    if (inst.size() < 5) return instr_search_failed;
                    if (inst[4] == '.') {
                        if (inst.size() < 6) return instr_search_failed;
                        if (inst[5] == 'v') {
                            if (inst.size() < 7) return 423;
                        }
                    }
                    if (inst[4] == 'f') {
                        if (inst.size() < 6) return instr_search_failed;
                        if (inst[5] == 'f') {
                            if (inst.size() < 7) return instr_search_failed;
                            if (inst[6] == '.') {
                                if (inst.size() < 8) return instr_search_failed;
                                if (inst[7] == 'v') {
                                    if (inst.size() < 9) return 457;
                                }
                            }
                        }
                    }
                }
                if (inst[3] == '3') {
                    if (inst.size() < 5) return instr_search_failed;
                    if (inst[4] == '2') {
                        if (inst.size() < 6) return instr_search_failed;
                        if (inst[5] == '.') {
                            if (inst.size() < 7) return instr_search_failed;
                            if (inst[6] == 'v') {
                                if (inst.size() < 8) return 425;
                            }
                        }
                        if (inst[5] == 'f') {
                            if (inst.size() < 7) return instr_search_failed;
                            if (inst[6] == 'f') {
                                if (inst.size() < 8) return instr_search_failed;
                                if (inst[7] == '.') {
                                    if (inst.size() < 9) return instr_search_failed;
                                    if (inst[8] == 'v') {
                                        if (inst.size() < 10) return 459;
                                    }
                                }
                            }
                        }
                    }
                }
            }
            if (inst[2] == '1') {
                if (inst.size() < 4) return instr_search_failed;
                if (inst[3] == 'r') {
                    if (inst.size() < 5) return instr_search_failed;
                    if (inst[4] == 'e') {
                        if (inst.size() < 6) return instr_search_failed;
                        if (inst[5] == '1') {
                            if (inst.size() < 7) return instr_search_failed;
                            if (inst[6] == '6') {
                                if (inst.size() < 8) return instr_search_failed;
                                if (inst[7] == '.') {
                                    if (inst.size() < 9) return instr_search_failed;
                                    if (inst[8] == 'v') {
                                        if (inst.size() < 10) return 714;
                                    }
                                }
                            }
                        }
                        if (inst[5] == '6') {
                            if (inst.size() < 7) return instr_search_failed;
                            if (inst[6] == '4') {
                                if (inst.size() < 8) return instr_search_failed;
                                if (inst[7] == '.') {
                                    if (inst.size() < 9) return instr_search_failed;
                                    if (inst[8] == 'v') {
                                        if (inst.size() < 10) return 716;
                                    }
                                }
                            }
                        }
                        if (inst[5] == '8') {
                            if (inst.size() < 7) return instr_search_failed;
                            if (inst[6] == '.') {
                                if (inst.size() < 8) return instr_search_failed;
                                if (inst[7] == 'v') {
                                    if (inst.size() < 9) return 713;
                                }
                            }
                        }
                        if (inst[5] == '3') {
                            if (inst.size() < 7) return instr_search_failed;
                            if (inst[6] == '2') {
                                if (inst.size() < 8) return instr_search_failed;
                                if (inst[7] == '.') {
                                    if (inst.size() < 9) return instr_search_failed;
                                    if (inst[8] == 'v') {
                                        if (inst.size() < 10) return 715;
                                    }
                                }
                            }
                        }
                    }
                }
            }
            if (inst[2] == '8') {
                if (inst.size() < 4) return instr_search_failed;
                if (inst[3] == 'r') {
                    if (inst.size() < 5) return instr_search_failed;
                    if (inst[4] == 'e') {
                        if (inst.size() < 6) return instr_search_failed;
                        if (inst[5] == '1') {
                            if (inst.size() < 7) return instr_search_failed;
                            if (inst[6] == '6') {
                                if (inst.size() < 8) return instr_search_failed;
                                if (inst[7] == '.') {
                                    if (inst.size() < 9) return instr_search_failed;
                                    if (inst[8] == 'v') {
                                        if (inst.size() < 10) return 726;
                                    }
                                }
                            }
                        }
                        if (inst[5] == '6') {
                            if (inst.size() < 7) return instr_search_failed;
                            if (inst[6] == '4') {
                                if (inst.size() < 8) return instr_search_failed;
                                if (inst[7] == '.') {
                                    if (inst.size() < 9) return instr_search_failed;
                                    if (inst[8] == 'v') {
                                        if (inst.size() < 10) return 728;
                                    }
                                }
                            }
                        }
                        if (inst[5] == '8') {
                            if (inst.size() < 7) return instr_search_failed;
                            if (inst[6] == '.') {
                                if (inst.size() < 8) return instr_search_failed;
                                if (inst[7] == 'v') {
                                    if (inst.size() < 9) return 725;
                                }
                            }
                        }
                        if (inst[5] == '3') {
                            if (inst.size() < 7) return instr_search_failed;
                            if (inst[6] == '2') {
                                if (inst.size() < 8) return instr_search_failed;
                                if (inst[7] == '.') {
                                    if (inst.size() < 9) return instr_search_failed;
                                    if (inst[8] == 'v') {
                                        if (inst.size() < 10) return 727;
                                    }
                                }
                            }
                        }
                    }
                }
            }
            if (inst[2] == '2') {
                if (inst.size() < 4) return instr_search_failed;
                if (inst[3] == 'r') {
                    if (inst.size() < 5) return instr_search_failed;
                    if (inst[4] == 'e') {
                        if (inst.size() < 6) return instr_search_failed;
                        if (inst[5] == '1') {
                            if (inst.size() < 7) return instr_search_failed;
                            if (inst[6] == '6') {
                                if (inst.size() < 8) return instr_search_failed;
                                if (inst[7] == '.') {
                                    if (inst.size() < 9) return instr_search_failed;
                                    if (inst[8] == 'v') {
                                        if (inst.size() < 10) return 718;
                                    }
                                }
                            }
                        }
                        if (inst[5] == '6') {
                            if (inst.size() < 7) return instr_search_failed;
                            if (inst[6] == '4') {
                                if (inst.size() < 8) return instr_search_failed;
                                if (inst[7] == '.') {
                                    if (inst.size() < 9) return instr_search_failed;
                                    if (inst[8] == 'v') {
                                        if (inst.size() < 10) return 720;
                                    }
                                }
                            }
                        }
                        if (inst[5] == '8') {
                            if (inst.size() < 7) return instr_search_failed;
                            if (inst[6] == '.') {
                                if (inst.size() < 8) return instr_search_failed;
                                if (inst[7] == 'v') {
                                    if (inst.size() < 9) return 717;
                                }
                            }
                        }
                        if (inst[5] == '3') {
                            if (inst.size() < 7) return instr_search_failed;
                            if (inst[6] == '2') {
                                if (inst.size() < 8) return instr_search_failed;
                                if (inst[7] == '.') {
                                    if (inst.size() < 9) return instr_search_failed;
                                    if (inst[8] == 'v') {
                                        if (inst.size() < 10) return 719;
                                    }
                                }
                            }
                        }
                    }
                }
            }
            if (inst[2] == '4') {
                if (inst.size() < 4) return instr_search_failed;
                if (inst[3] == 'r') {
                    if (inst.size() < 5) return instr_search_failed;
                    if (inst[4] == 'e') {
                        if (inst.size() < 6) return instr_search_failed;
                        if (inst[5] == '1') {
                            if (inst.size() < 7) return instr_search_failed;
                            if (inst[6] == '6') {
                                if (inst.size() < 8) return instr_search_failed;
                                if (inst[7] == '.') {
                                    if (inst.size() < 9) return instr_search_failed;
                                    if (inst[8] == 'v') {
                                        if (inst.size() < 10) return 722;
                                    }
                                }
                            }
                        }
                        if (inst[5] == '6') {
                            if (inst.size() < 7) return instr_search_failed;
                            if (inst[6] == '4') {
                                if (inst.size() < 8) return instr_search_failed;
                                if (inst[7] == '.') {
                                    if (inst.size() < 9) return instr_search_failed;
                                    if (inst[8] == 'v') {
                                        if (inst.size() < 10) return 724;
                                    }
                                }
                            }
                        }
                        if (inst[5] == '8') {
                            if (inst.size() < 7) return instr_search_failed;
                            if (inst[6] == '.') {
                                if (inst.size() < 8) return instr_search_failed;
                                if (inst[7] == 'v') {
                                    if (inst.size() < 9) return 721;
                                }
                            }
                        }
                        if (inst[5] == '3') {
                            if (inst.size() < 7) return instr_search_failed;
                            if (inst[6] == '2') {
                                if (inst.size() < 8) return instr_search_failed;
                                if (inst[7] == '.') {
                                    if (inst.size() < 9) return instr_search_failed;
                                    if (inst[8] == 'v') {
                                        if (inst.size() < 10) return 723;
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
        if (inst[1] == 'n') {
            if (inst.size() < 3) return instr_search_failed;
            if (inst[2] == 'm') {
                if (inst.size() < 4) return instr_search_failed;
                if (inst[3] == 's') {
                    if (inst.size() < 5) return instr_search_failed;
                    if (inst[4] == 'a') {
                        if (inst.size() < 6) return instr_search_failed;
                        if (inst[5] == 'c') {
                            if (inst.size() < 7) return instr_search_failed;
                            if (inst[6] == '.') {
                                if (inst.size() < 8) return instr_search_failed;
                                if (inst[7] == 'v') {
                                    if (inst.size() < 9) return instr_search_failed;
                                    if (inst[8] == 'x') {
                                        if (inst.size() < 10) return 854;
                                    }
                                    if (inst[8] == 'v') {
                                        if (inst.size() < 10) return 853;
                                    }
                                }
                            }
                        }
                    }
                    if (inst[4] == 'u') {
                        if (inst.size() < 6) return instr_search_failed;
                        if (inst[5] == 'b') {
                            if (inst.size() < 7) return instr_search_failed;
                            if (inst[6] == '.') {
                                if (inst.size() < 8) return instr_search_failed;
                                if (inst[7] == 'v') {
                                    if (inst.size() < 9) return instr_search_failed;
                                    if (inst[8] == 'x') {
                                        if (inst.size() < 10) return 858;
                                    }
                                    if (inst[8] == 'v') {
                                        if (inst.size() < 10) return 857;
                                    }
                                }
                            }
                        }
                    }
                }
            }
            if (inst[2] == 'c') {
                if (inst.size() < 4) return instr_search_failed;
                if (inst[3] == 'l') {
                    if (inst.size() < 5) return instr_search_failed;
                    if (inst[4] == 'i') {
                        if (inst.size() < 6) return instr_search_failed;
                        if (inst[5] == 'p') {
                            if (inst.size() < 7) return instr_search_failed;
                            if (inst[6] == '.') {
                                if (inst.size() < 8) return instr_search_failed;
                                if (inst[7] == 'w') {
                                    if (inst.size() < 9) return instr_search_failed;
                                    if (inst[8] == 'i') {
                                        if (inst.size() < 10) return 903;
                                    }
                                    if (inst[8] == 'x') {
                                        if (inst.size() < 10) return 902;
                                    }
                                    if (inst[8] == 'v') {
                                        if (inst.size() < 10) return 901;
                                    }
                                }
                            }
                            if (inst[6] == 'u') {
                                if (inst.size() < 8) return instr_search_failed;
                                if (inst[7] == '.') {
                                    if (inst.size() < 9) return instr_search_failed;
                                    if (inst[8] == 'w') {
                                        if (inst.size() < 10) return instr_search_failed;
                                        if (inst[9] == 'i') {
                                            if (inst.size() < 11) return 900;
                                        }
                                        if (inst[9] == 'x') {
                                            if (inst.size() < 11) return 899;
                                        }
                                        if (inst[9] == 'v') {
                                            if (inst.size() < 11) return 898;
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
            if (inst[2] == 's') {
                if (inst.size() < 4) return instr_search_failed;
                if (inst[3] == 'r') {
                    if (inst.size() < 5) return instr_search_failed;
                    if (inst[4] == 'a') {
                        if (inst.size() < 6) return instr_search_failed;
                        if (inst[5] == '.') {
                            if (inst.size() < 7) return instr_search_failed;
                            if (inst[6] == 'w') {
                                if (inst.size() < 8) return instr_search_failed;
                                if (inst[7] == 'i') {
                                    if (inst.size() < 9) return 800;
                                }
                                if (inst[7] == 'x') {
                                    if (inst.size() < 9) return 799;
                                }
                                if (inst[7] == 'v') {
                                    if (inst.size() < 9) return 798;
                                }
                            }
                        }
                    }
                    if (inst[4] == 'l') {
                        if (inst.size() < 6) return instr_search_failed;
                        if (inst[5] == '.') {
                            if (inst.size() < 7) return instr_search_failed;
                            if (inst[6] == 'w') {
                                if (inst.size() < 8) return instr_search_failed;
                                if (inst[7] == 'i') {
                                    if (inst.size() < 9) return 797;
                                }
                                if (inst[7] == 'x') {
                                    if (inst.size() < 9) return 796;
                                }
                                if (inst[7] == 'v') {
                                    if (inst.size() < 9) return 795;
                                }
                            }
                        }
                    }
                }
            }
        }
        if (inst[1] == 'c') {
            if (inst.size() < 3) return instr_search_failed;
            if (inst[2] == 'o') {
                if (inst.size() < 4) return instr_search_failed;
                if (inst[3] == 'm') {
                    if (inst.size() < 5) return instr_search_failed;
                    if (inst[4] == 'p') {
                        if (inst.size() < 6) return instr_search_failed;
                        if (inst[5] == 'r') {
                            if (inst.size() < 7) return instr_search_failed;
                            if (inst[6] == 'e') {
                                if (inst.size() < 8) return instr_search_failed;
                                if (inst[7] == 's') {
                                    if (inst.size() < 9) return instr_search_failed;
                                    if (inst[8] == 's') {
                                        if (inst.size() < 10) return instr_search_failed;
                                        if (inst[9] == '.') {
                                            if (inst.size() < 11) return instr_search_failed;
                                            if (inst[10] == 'v') {
                                                if (inst.size() < 12) return instr_search_failed;
                                                if (inst[11] == 'm') {
                                                    if (inst.size() < 13) return 1034;
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
            if (inst[2] == 'p') {
                if (inst.size() < 4) return instr_search_failed;
                if (inst[3] == 'o') {
                    if (inst.size() < 5) return instr_search_failed;
                    if (inst[4] == 'p') {
                        if (inst.size() < 6) return instr_search_failed;
                        if (inst[5] == '.') {
                            if (inst.size() < 7) return instr_search_failed;
                            if (inst[6] == 'm') {
                                if (inst.size() < 8) return 1011;
                            }
                        }
                    }
                }
            }
        }
        if (inst[1] == 's') {
            if (inst.size() < 3) return instr_search_failed;
            if (inst[2] == 'a') {
                if (inst.size() < 4) return instr_search_failed;
                if (inst[3] == 'd') {
                    if (inst.size() < 5) return instr_search_failed;
                    if (inst[4] == 'd') {
                        if (inst.size() < 6) return instr_search_failed;
                        if (inst[5] == '.') {
                            if (inst.size() < 7) return instr_search_failed;
                            if (inst[6] == 'v') {
                                if (inst.size() < 8) return instr_search_failed;
                                if (inst[7] == 'i') {
                                    if (inst.size() < 9) return 877;
                                }
                                if (inst[7] == 'x') {
                                    if (inst.size() < 9) return 876;
                                }
                                if (inst[7] == 'v') {
                                    if (inst.size() < 9) return 875;
                                }
                            }
                        }
                        if (inst[5] == 'u') {
                            if (inst.size() < 7) return instr_search_failed;
                            if (inst[6] == '.') {
                                if (inst.size() < 8) return instr_search_failed;
                                if (inst[7] == 'v') {
                                    if (inst.size() < 9) return instr_search_failed;
                                    if (inst[8] == 'i') {
                                        if (inst.size() < 10) return 874;
                                    }
                                    if (inst[8] == 'x') {
                                        if (inst.size() < 10) return 873;
                                    }
                                    if (inst[8] == 'v') {
                                        if (inst.size() < 10) return 872;
                                    }
                                }
                            }
                        }
                    }
                }
            }
            if (inst[2] == 'u') {
                if (inst.size() < 4) return instr_search_failed;
                if (inst[3] == 'x') {
                    if (inst.size() < 5) return instr_search_failed;
                    if (inst[4] == 's') {
                        if (inst.size() < 6) return instr_search_failed;
                        if (inst[5] == 'e') {
                            if (inst.size() < 7) return instr_search_failed;
                            if (inst[6] == 'g') {
                                if (inst.size() < 8) return instr_search_failed;
                                if (inst[7] == '6') {
                                    if (inst.size() < 9) return instr_search_failed;
                                    if (inst[8] == 'e') {
                                        if (inst.size() < 10) return instr_search_failed;
                                        if (inst[9] == 'i') {
                                            if (inst.size() < 11) return instr_search_failed;
                                            if (inst[10] == '1') {
                                                if (inst.size() < 12) return instr_search_failed;
                                                if (inst[11] == '6') {
                                                    if (inst.size() < 13) return instr_search_failed;
                                                    if (inst[12] == '.') {
                                                        if (inst.size() < 14) return instr_search_failed;
                                                        if (inst[13] == 'v') {
                                                            if (inst.size() < 15) return 671;
                                                        }
                                                    }
                                                }
                                            }
                                            if (inst[10] == '6') {
                                                if (inst.size() < 12) return instr_search_failed;
                                                if (inst[11] == '4') {
                                                    if (inst.size() < 13) return instr_search_failed;
                                                    if (inst[12] == '.') {
                                                        if (inst.size() < 14) return instr_search_failed;
                                                        if (inst[13] == 'v') {
                                                            if (inst.size() < 15) return 679;
                                                        }
                                                    }
                                                }
                                            }
                                            if (inst[10] == '8') {
                                                if (inst.size() < 12) return instr_search_failed;
                                                if (inst[11] == '.') {
                                                    if (inst.size() < 13) return instr_search_failed;
                                                    if (inst[12] == 'v') {
                                                        if (inst.size() < 14) return 667;
                                                    }
                                                }
                                            }
                                            if (inst[10] == '3') {
                                                if (inst.size() < 12) return instr_search_failed;
                                                if (inst[11] == '2') {
                                                    if (inst.size() < 13) return instr_search_failed;
                                                    if (inst[12] == '.') {
                                                        if (inst.size() < 14) return instr_search_failed;
                                                        if (inst[13] == 'v') {
                                                            if (inst.size() < 15) return 675;
                                                        }
                                                    }
                                                }
                                            }
                                        }
                                    }
                                }
                                if (inst[7] == '8') {
                                    if (inst.size() < 9) return instr_search_failed;
                                    if (inst[8] == 'e') {
                                        if (inst.size() < 10) return instr_search_failed;
                                        if (inst[9] == 'i') {
                                            if (inst.size() < 11) return instr_search_failed;
                                            if (inst[10] == '1') {
                                                if (inst.size() < 12) return instr_search_failed;
                                                if (inst[11] == '6') {
                                                    if (inst.size() < 13) return instr_search_failed;
                                                    if (inst[12] == '.') {
                                                        if (inst.size() < 14) return instr_search_failed;
                                                        if (inst[13] == 'v') {
                                                            if (inst.size() < 15) return 703;
                                                        }
                                                    }
                                                }
                                            }
                                            if (inst[10] == '6') {
                                                if (inst.size() < 12) return instr_search_failed;
                                                if (inst[11] == '4') {
                                                    if (inst.size() < 13) return instr_search_failed;
                                                    if (inst[12] == '.') {
                                                        if (inst.size() < 14) return instr_search_failed;
                                                        if (inst[13] == 'v') {
                                                            if (inst.size() < 15) return 711;
                                                        }
                                                    }
                                                }
                                            }
                                            if (inst[10] == '8') {
                                                if (inst.size() < 12) return instr_search_failed;
                                                if (inst[11] == '.') {
                                                    if (inst.size() < 13) return instr_search_failed;
                                                    if (inst[12] == 'v') {
                                                        if (inst.size() < 14) return 699;
                                                    }
                                                }
                                            }
                                            if (inst[10] == '3') {
                                                if (inst.size() < 12) return instr_search_failed;
                                                if (inst[11] == '2') {
                                                    if (inst.size() < 13) return instr_search_failed;
                                                    if (inst[12] == '.') {
                                                        if (inst.size() < 14) return instr_search_failed;
                                                        if (inst[13] == 'v') {
                                                            if (inst.size() < 15) return 707;
                                                        }
                                                    }
                                                }
                                            }
                                        }
                                    }
                                }
                                if (inst[7] == '2') {
                                    if (inst.size() < 9) return instr_search_failed;
                                    if (inst[8] == 'e') {
                                        if (inst.size() < 10) return instr_search_failed;
                                        if (inst[9] == 'i') {
                                            if (inst.size() < 11) return instr_search_failed;
                                            if (inst[10] == '1') {
                                                if (inst.size() < 12) return instr_search_failed;
                                                if (inst[11] == '6') {
                                                    if (inst.size() < 13) return instr_search_failed;
                                                    if (inst[12] == '.') {
                                                        if (inst.size() < 14) return instr_search_failed;
                                                        if (inst[13] == 'v') {
                                                            if (inst.size() < 15) return 607;
                                                        }
                                                    }
                                                }
                                            }
                                            if (inst[10] == '6') {
                                                if (inst.size() < 12) return instr_search_failed;
                                                if (inst[11] == '4') {
                                                    if (inst.size() < 13) return instr_search_failed;
                                                    if (inst[12] == '.') {
                                                        if (inst.size() < 14) return instr_search_failed;
                                                        if (inst[13] == 'v') {
                                                            if (inst.size() < 15) return 615;
                                                        }
                                                    }
                                                }
                                            }
                                            if (inst[10] == '8') {
                                                if (inst.size() < 12) return instr_search_failed;
                                                if (inst[11] == '.') {
                                                    if (inst.size() < 13) return instr_search_failed;
                                                    if (inst[12] == 'v') {
                                                        if (inst.size() < 14) return 603;
                                                    }
                                                }
                                            }
                                            if (inst[10] == '3') {
                                                if (inst.size() < 12) return instr_search_failed;
                                                if (inst[11] == '2') {
                                                    if (inst.size() < 13) return instr_search_failed;
                                                    if (inst[12] == '.') {
                                                        if (inst.size() < 14) return instr_search_failed;
                                                        if (inst[13] == 'v') {
                                                            if (inst.size() < 15) return 611;
                                                        }
                                                    }
                                                }
                                            }
                                        }
                                    }
                                }
                                if (inst[7] == '3') {
                                    if (inst.size() < 9) return instr_search_failed;
                                    if (inst[8] == 'e') {
                                        if (inst.size() < 10) return instr_search_failed;
                                        if (inst[9] == 'i') {
                                            if (inst.size() < 11) return instr_search_failed;
                                            if (inst[10] == '1') {
                                                if (inst.size() < 12) return instr_search_failed;
                                                if (inst[11] == '6') {
                                                    if (inst.size() < 13) return instr_search_failed;
                                                    if (inst[12] == '.') {
                                                        if (inst.size() < 14) return instr_search_failed;
                                                        if (inst[13] == 'v') {
                                                            if (inst.size() < 15) return 623;
                                                        }
                                                    }
                                                }
                                            }
                                            if (inst[10] == '6') {
                                                if (inst.size() < 12) return instr_search_failed;
                                                if (inst[11] == '4') {
                                                    if (inst.size() < 13) return instr_search_failed;
                                                    if (inst[12] == '.') {
                                                        if (inst.size() < 14) return instr_search_failed;
                                                        if (inst[13] == 'v') {
                                                            if (inst.size() < 15) return 631;
                                                        }
                                                    }
                                                }
                                            }
                                            if (inst[10] == '8') {
                                                if (inst.size() < 12) return instr_search_failed;
                                                if (inst[11] == '.') {
                                                    if (inst.size() < 13) return instr_search_failed;
                                                    if (inst[12] == 'v') {
                                                        if (inst.size() < 14) return 619;
                                                    }
                                                }
                                            }
                                            if (inst[10] == '3') {
                                                if (inst.size() < 12) return instr_search_failed;
                                                if (inst[11] == '2') {
                                                    if (inst.size() < 13) return instr_search_failed;
                                                    if (inst[12] == '.') {
                                                        if (inst.size() < 14) return instr_search_failed;
                                                        if (inst[13] == 'v') {
                                                            if (inst.size() < 15) return 627;
                                                        }
                                                    }
                                                }
                                            }
                                        }
                                    }
                                }
                                if (inst[7] == '7') {
                                    if (inst.size() < 9) return instr_search_failed;
                                    if (inst[8] == 'e') {
                                        if (inst.size() < 10) return instr_search_failed;
                                        if (inst[9] == 'i') {
                                            if (inst.size() < 11) return instr_search_failed;
                                            if (inst[10] == '1') {
                                                if (inst.size() < 12) return instr_search_failed;
                                                if (inst[11] == '6') {
                                                    if (inst.size() < 13) return instr_search_failed;
                                                    if (inst[12] == '.') {
                                                        if (inst.size() < 14) return instr_search_failed;
                                                        if (inst[13] == 'v') {
                                                            if (inst.size() < 15) return 687;
                                                        }
                                                    }
                                                }
                                            }
                                            if (inst[10] == '6') {
                                                if (inst.size() < 12) return instr_search_failed;
                                                if (inst[11] == '4') {
                                                    if (inst.size() < 13) return instr_search_failed;
                                                    if (inst[12] == '.') {
                                                        if (inst.size() < 14) return instr_search_failed;
                                                        if (inst[13] == 'v') {
                                                            if (inst.size() < 15) return 695;
                                                        }
                                                    }
                                                }
                                            }
                                            if (inst[10] == '8') {
                                                if (inst.size() < 12) return instr_search_failed;
                                                if (inst[11] == '.') {
                                                    if (inst.size() < 13) return instr_search_failed;
                                                    if (inst[12] == 'v') {
                                                        if (inst.size() < 14) return 683;
                                                    }
                                                }
                                            }
                                            if (inst[10] == '3') {
                                                if (inst.size() < 12) return instr_search_failed;
                                                if (inst[11] == '2') {
                                                    if (inst.size() < 13) return instr_search_failed;
                                                    if (inst[12] == '.') {
                                                        if (inst.size() < 14) return instr_search_failed;
                                                        if (inst[13] == 'v') {
                                                            if (inst.size() < 15) return 691;
                                                        }
                                                    }
                                                }
                                            }
                                        }
                                    }
                                }
                                if (inst[7] == '4') {
                                    if (inst.size() < 9) return instr_search_failed;
                                    if (inst[8] == 'e') {
                                        if (inst.size() < 10) return instr_search_failed;
                                        if (inst[9] == 'i') {
                                            if (inst.size() < 11) return instr_search_failed;
                                            if (inst[10] == '1') {
                                                if (inst.size() < 12) return instr_search_failed;
                                                if (inst[11] == '6') {
                                                    if (inst.size() < 13) return instr_search_failed;
                                                    if (inst[12] == '.') {
                                                        if (inst.size() < 14) return instr_search_failed;
                                                        if (inst[13] == 'v') {
                                                            if (inst.size() < 15) return 639;
                                                        }
                                                    }
                                                }
                                            }
                                            if (inst[10] == '6') {
                                                if (inst.size() < 12) return instr_search_failed;
                                                if (inst[11] == '4') {
                                                    if (inst.size() < 13) return instr_search_failed;
                                                    if (inst[12] == '.') {
                                                        if (inst.size() < 14) return instr_search_failed;
                                                        if (inst[13] == 'v') {
                                                            if (inst.size() < 15) return 647;
                                                        }
                                                    }
                                                }
                                            }
                                            if (inst[10] == '8') {
                                                if (inst.size() < 12) return instr_search_failed;
                                                if (inst[11] == '.') {
                                                    if (inst.size() < 13) return instr_search_failed;
                                                    if (inst[12] == 'v') {
                                                        if (inst.size() < 14) return 635;
                                                    }
                                                }
                                            }
                                            if (inst[10] == '3') {
                                                if (inst.size() < 12) return instr_search_failed;
                                                if (inst[11] == '2') {
                                                    if (inst.size() < 13) return instr_search_failed;
                                                    if (inst[12] == '.') {
                                                        if (inst.size() < 14) return instr_search_failed;
                                                        if (inst[13] == 'v') {
                                                            if (inst.size() < 15) return 643;
                                                        }
                                                    }
                                                }
                                            }
                                        }
                                    }
                                }
                                if (inst[7] == '5') {
                                    if (inst.size() < 9) return instr_search_failed;
                                    if (inst[8] == 'e') {
                                        if (inst.size() < 10) return instr_search_failed;
                                        if (inst[9] == 'i') {
                                            if (inst.size() < 11) return instr_search_failed;
                                            if (inst[10] == '1') {
                                                if (inst.size() < 12) return instr_search_failed;
                                                if (inst[11] == '6') {
                                                    if (inst.size() < 13) return instr_search_failed;
                                                    if (inst[12] == '.') {
                                                        if (inst.size() < 14) return instr_search_failed;
                                                        if (inst[13] == 'v') {
                                                            if (inst.size() < 15) return 655;
                                                        }
                                                    }
                                                }
                                            }
                                            if (inst[10] == '6') {
                                                if (inst.size() < 12) return instr_search_failed;
                                                if (inst[11] == '4') {
                                                    if (inst.size() < 13) return instr_search_failed;
                                                    if (inst[12] == '.') {
                                                        if (inst.size() < 14) return instr_search_failed;
                                                        if (inst[13] == 'v') {
                                                            if (inst.size() < 15) return 663;
                                                        }
                                                    }
                                                }
                                            }
                                            if (inst[10] == '8') {
                                                if (inst.size() < 12) return instr_search_failed;
                                                if (inst[11] == '.') {
                                                    if (inst.size() < 13) return instr_search_failed;
                                                    if (inst[12] == 'v') {
                                                        if (inst.size() < 14) return 651;
                                                    }
                                                }
                                            }
                                            if (inst[10] == '3') {
                                                if (inst.size() < 12) return instr_search_failed;
                                                if (inst[11] == '2') {
                                                    if (inst.size() < 13) return instr_search_failed;
                                                    if (inst[12] == '.') {
                                                        if (inst.size() < 14) return instr_search_failed;
                                                        if (inst[13] == 'v') {
                                                            if (inst.size() < 15) return 659;
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
                    if (inst[4] == 'e') {
                        if (inst.size() < 6) return instr_search_failed;
                        if (inst[5] == 'i') {
                            if (inst.size() < 7) return instr_search_failed;
                            if (inst[6] == '1') {
                                if (inst.size() < 8) return instr_search_failed;
                                if (inst[7] == '6') {
                                    if (inst.size() < 9) return instr_search_failed;
                                    if (inst[8] == '.') {
                                        if (inst.size() < 10) return instr_search_failed;
                                        if (inst[9] == 'v') {
                                            if (inst.size() < 11) return 450;
                                        }
                                    }
                                }
                            }
                            if (inst[6] == '6') {
                                if (inst.size() < 8) return instr_search_failed;
                                if (inst[7] == '4') {
                                    if (inst.size() < 9) return instr_search_failed;
                                    if (inst[8] == '.') {
                                        if (inst.size() < 10) return instr_search_failed;
                                        if (inst[9] == 'v') {
                                            if (inst.size() < 11) return 452;
                                        }
                                    }
                                }
                            }
                            if (inst[6] == '8') {
                                if (inst.size() < 8) return instr_search_failed;
                                if (inst[7] == '.') {
                                    if (inst.size() < 9) return instr_search_failed;
                                    if (inst[8] == 'v') {
                                        if (inst.size() < 10) return 449;
                                    }
                                }
                            }
                            if (inst[6] == '3') {
                                if (inst.size() < 8) return instr_search_failed;
                                if (inst[7] == '2') {
                                    if (inst.size() < 9) return instr_search_failed;
                                    if (inst[8] == '.') {
                                        if (inst.size() < 10) return instr_search_failed;
                                        if (inst[9] == 'v') {
                                            if (inst.size() < 11) return 451;
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
                if (inst[3] == 'b') {
                    if (inst.size() < 5) return instr_search_failed;
                    if (inst[4] == '.') {
                        if (inst.size() < 6) return instr_search_failed;
                        if (inst[5] == 'v') {
                            if (inst.size() < 7) return instr_search_failed;
                            if (inst[6] == 'x') {
                                if (inst.size() < 8) return 737;
                            }
                            if (inst[6] == 'v') {
                                if (inst.size() < 8) return 736;
                            }
                        }
                    }
                }
            }
            if (inst[2] == 'm') {
                if (inst.size() < 4) return instr_search_failed;
                if (inst[3] == '.') {
                    if (inst.size() < 5) return instr_search_failed;
                    if (inst[4] == 'v') {
                        if (inst.size() < 6) return 432;
                    }
                }
                if (inst[3] == 'u') {
                    if (inst.size() < 5) return instr_search_failed;
                    if (inst[4] == 'l') {
                        if (inst.size() < 6) return instr_search_failed;
                        if (inst[5] == '.') {
                            if (inst.size() < 7) return instr_search_failed;
                            if (inst[6] == 'v') {
                                if (inst.size() < 8) return instr_search_failed;
                                if (inst[7] == 'x') {
                                    if (inst.size() < 9) return 891;
                                }
                                if (inst[7] == 'v') {
                                    if (inst.size() < 9) return 890;
                                }
                            }
                        }
                    }
                }
            }
            if (inst[2] == 'o') {
                if (inst.size() < 4) return instr_search_failed;
                if (inst[3] == 'x') {
                    if (inst.size() < 5) return instr_search_failed;
                    if (inst[4] == 's') {
                        if (inst.size() < 6) return instr_search_failed;
                        if (inst[5] == 'e') {
                            if (inst.size() < 7) return instr_search_failed;
                            if (inst[6] == 'g') {
                                if (inst.size() < 8) return instr_search_failed;
                                if (inst[7] == '6') {
                                    if (inst.size() < 9) return instr_search_failed;
                                    if (inst[8] == 'e') {
                                        if (inst.size() < 10) return instr_search_failed;
                                        if (inst[9] == 'i') {
                                            if (inst.size() < 11) return instr_search_failed;
                                            if (inst[10] == '1') {
                                                if (inst.size() < 12) return instr_search_failed;
                                                if (inst[11] == '6') {
                                                    if (inst.size() < 13) return instr_search_failed;
                                                    if (inst[12] == '.') {
                                                        if (inst.size() < 14) return instr_search_failed;
                                                        if (inst[13] == 'v') {
                                                            if (inst.size() < 15) return 672;
                                                        }
                                                    }
                                                }
                                            }
                                            if (inst[10] == '6') {
                                                if (inst.size() < 12) return instr_search_failed;
                                                if (inst[11] == '4') {
                                                    if (inst.size() < 13) return instr_search_failed;
                                                    if (inst[12] == '.') {
                                                        if (inst.size() < 14) return instr_search_failed;
                                                        if (inst[13] == 'v') {
                                                            if (inst.size() < 15) return 680;
                                                        }
                                                    }
                                                }
                                            }
                                            if (inst[10] == '8') {
                                                if (inst.size() < 12) return instr_search_failed;
                                                if (inst[11] == '.') {
                                                    if (inst.size() < 13) return instr_search_failed;
                                                    if (inst[12] == 'v') {
                                                        if (inst.size() < 14) return 668;
                                                    }
                                                }
                                            }
                                            if (inst[10] == '3') {
                                                if (inst.size() < 12) return instr_search_failed;
                                                if (inst[11] == '2') {
                                                    if (inst.size() < 13) return instr_search_failed;
                                                    if (inst[12] == '.') {
                                                        if (inst.size() < 14) return instr_search_failed;
                                                        if (inst[13] == 'v') {
                                                            if (inst.size() < 15) return 676;
                                                        }
                                                    }
                                                }
                                            }
                                        }
                                    }
                                }
                                if (inst[7] == '8') {
                                    if (inst.size() < 9) return instr_search_failed;
                                    if (inst[8] == 'e') {
                                        if (inst.size() < 10) return instr_search_failed;
                                        if (inst[9] == 'i') {
                                            if (inst.size() < 11) return instr_search_failed;
                                            if (inst[10] == '1') {
                                                if (inst.size() < 12) return instr_search_failed;
                                                if (inst[11] == '6') {
                                                    if (inst.size() < 13) return instr_search_failed;
                                                    if (inst[12] == '.') {
                                                        if (inst.size() < 14) return instr_search_failed;
                                                        if (inst[13] == 'v') {
                                                            if (inst.size() < 15) return 704;
                                                        }
                                                    }
                                                }
                                            }
                                            if (inst[10] == '6') {
                                                if (inst.size() < 12) return instr_search_failed;
                                                if (inst[11] == '4') {
                                                    if (inst.size() < 13) return instr_search_failed;
                                                    if (inst[12] == '.') {
                                                        if (inst.size() < 14) return instr_search_failed;
                                                        if (inst[13] == 'v') {
                                                            if (inst.size() < 15) return 712;
                                                        }
                                                    }
                                                }
                                            }
                                            if (inst[10] == '8') {
                                                if (inst.size() < 12) return instr_search_failed;
                                                if (inst[11] == '.') {
                                                    if (inst.size() < 13) return instr_search_failed;
                                                    if (inst[12] == 'v') {
                                                        if (inst.size() < 14) return 700;
                                                    }
                                                }
                                            }
                                            if (inst[10] == '3') {
                                                if (inst.size() < 12) return instr_search_failed;
                                                if (inst[11] == '2') {
                                                    if (inst.size() < 13) return instr_search_failed;
                                                    if (inst[12] == '.') {
                                                        if (inst.size() < 14) return instr_search_failed;
                                                        if (inst[13] == 'v') {
                                                            if (inst.size() < 15) return 708;
                                                        }
                                                    }
                                                }
                                            }
                                        }
                                    }
                                }
                                if (inst[7] == '2') {
                                    if (inst.size() < 9) return instr_search_failed;
                                    if (inst[8] == 'e') {
                                        if (inst.size() < 10) return instr_search_failed;
                                        if (inst[9] == 'i') {
                                            if (inst.size() < 11) return instr_search_failed;
                                            if (inst[10] == '1') {
                                                if (inst.size() < 12) return instr_search_failed;
                                                if (inst[11] == '6') {
                                                    if (inst.size() < 13) return instr_search_failed;
                                                    if (inst[12] == '.') {
                                                        if (inst.size() < 14) return instr_search_failed;
                                                        if (inst[13] == 'v') {
                                                            if (inst.size() < 15) return 608;
                                                        }
                                                    }
                                                }
                                            }
                                            if (inst[10] == '6') {
                                                if (inst.size() < 12) return instr_search_failed;
                                                if (inst[11] == '4') {
                                                    if (inst.size() < 13) return instr_search_failed;
                                                    if (inst[12] == '.') {
                                                        if (inst.size() < 14) return instr_search_failed;
                                                        if (inst[13] == 'v') {
                                                            if (inst.size() < 15) return 616;
                                                        }
                                                    }
                                                }
                                            }
                                            if (inst[10] == '8') {
                                                if (inst.size() < 12) return instr_search_failed;
                                                if (inst[11] == '.') {
                                                    if (inst.size() < 13) return instr_search_failed;
                                                    if (inst[12] == 'v') {
                                                        if (inst.size() < 14) return 604;
                                                    }
                                                }
                                            }
                                            if (inst[10] == '3') {
                                                if (inst.size() < 12) return instr_search_failed;
                                                if (inst[11] == '2') {
                                                    if (inst.size() < 13) return instr_search_failed;
                                                    if (inst[12] == '.') {
                                                        if (inst.size() < 14) return instr_search_failed;
                                                        if (inst[13] == 'v') {
                                                            if (inst.size() < 15) return 612;
                                                        }
                                                    }
                                                }
                                            }
                                        }
                                    }
                                }
                                if (inst[7] == '3') {
                                    if (inst.size() < 9) return instr_search_failed;
                                    if (inst[8] == 'e') {
                                        if (inst.size() < 10) return instr_search_failed;
                                        if (inst[9] == 'i') {
                                            if (inst.size() < 11) return instr_search_failed;
                                            if (inst[10] == '1') {
                                                if (inst.size() < 12) return instr_search_failed;
                                                if (inst[11] == '6') {
                                                    if (inst.size() < 13) return instr_search_failed;
                                                    if (inst[12] == '.') {
                                                        if (inst.size() < 14) return instr_search_failed;
                                                        if (inst[13] == 'v') {
                                                            if (inst.size() < 15) return 624;
                                                        }
                                                    }
                                                }
                                            }
                                            if (inst[10] == '6') {
                                                if (inst.size() < 12) return instr_search_failed;
                                                if (inst[11] == '4') {
                                                    if (inst.size() < 13) return instr_search_failed;
                                                    if (inst[12] == '.') {
                                                        if (inst.size() < 14) return instr_search_failed;
                                                        if (inst[13] == 'v') {
                                                            if (inst.size() < 15) return 632;
                                                        }
                                                    }
                                                }
                                            }
                                            if (inst[10] == '8') {
                                                if (inst.size() < 12) return instr_search_failed;
                                                if (inst[11] == '.') {
                                                    if (inst.size() < 13) return instr_search_failed;
                                                    if (inst[12] == 'v') {
                                                        if (inst.size() < 14) return 620;
                                                    }
                                                }
                                            }
                                            if (inst[10] == '3') {
                                                if (inst.size() < 12) return instr_search_failed;
                                                if (inst[11] == '2') {
                                                    if (inst.size() < 13) return instr_search_failed;
                                                    if (inst[12] == '.') {
                                                        if (inst.size() < 14) return instr_search_failed;
                                                        if (inst[13] == 'v') {
                                                            if (inst.size() < 15) return 628;
                                                        }
                                                    }
                                                }
                                            }
                                        }
                                    }
                                }
                                if (inst[7] == '7') {
                                    if (inst.size() < 9) return instr_search_failed;
                                    if (inst[8] == 'e') {
                                        if (inst.size() < 10) return instr_search_failed;
                                        if (inst[9] == 'i') {
                                            if (inst.size() < 11) return instr_search_failed;
                                            if (inst[10] == '1') {
                                                if (inst.size() < 12) return instr_search_failed;
                                                if (inst[11] == '6') {
                                                    if (inst.size() < 13) return instr_search_failed;
                                                    if (inst[12] == '.') {
                                                        if (inst.size() < 14) return instr_search_failed;
                                                        if (inst[13] == 'v') {
                                                            if (inst.size() < 15) return 688;
                                                        }
                                                    }
                                                }
                                            }
                                            if (inst[10] == '6') {
                                                if (inst.size() < 12) return instr_search_failed;
                                                if (inst[11] == '4') {
                                                    if (inst.size() < 13) return instr_search_failed;
                                                    if (inst[12] == '.') {
                                                        if (inst.size() < 14) return instr_search_failed;
                                                        if (inst[13] == 'v') {
                                                            if (inst.size() < 15) return 696;
                                                        }
                                                    }
                                                }
                                            }
                                            if (inst[10] == '8') {
                                                if (inst.size() < 12) return instr_search_failed;
                                                if (inst[11] == '.') {
                                                    if (inst.size() < 13) return instr_search_failed;
                                                    if (inst[12] == 'v') {
                                                        if (inst.size() < 14) return 684;
                                                    }
                                                }
                                            }
                                            if (inst[10] == '3') {
                                                if (inst.size() < 12) return instr_search_failed;
                                                if (inst[11] == '2') {
                                                    if (inst.size() < 13) return instr_search_failed;
                                                    if (inst[12] == '.') {
                                                        if (inst.size() < 14) return instr_search_failed;
                                                        if (inst[13] == 'v') {
                                                            if (inst.size() < 15) return 692;
                                                        }
                                                    }
                                                }
                                            }
                                        }
                                    }
                                }
                                if (inst[7] == '4') {
                                    if (inst.size() < 9) return instr_search_failed;
                                    if (inst[8] == 'e') {
                                        if (inst.size() < 10) return instr_search_failed;
                                        if (inst[9] == 'i') {
                                            if (inst.size() < 11) return instr_search_failed;
                                            if (inst[10] == '1') {
                                                if (inst.size() < 12) return instr_search_failed;
                                                if (inst[11] == '6') {
                                                    if (inst.size() < 13) return instr_search_failed;
                                                    if (inst[12] == '.') {
                                                        if (inst.size() < 14) return instr_search_failed;
                                                        if (inst[13] == 'v') {
                                                            if (inst.size() < 15) return 640;
                                                        }
                                                    }
                                                }
                                            }
                                            if (inst[10] == '6') {
                                                if (inst.size() < 12) return instr_search_failed;
                                                if (inst[11] == '4') {
                                                    if (inst.size() < 13) return instr_search_failed;
                                                    if (inst[12] == '.') {
                                                        if (inst.size() < 14) return instr_search_failed;
                                                        if (inst[13] == 'v') {
                                                            if (inst.size() < 15) return 648;
                                                        }
                                                    }
                                                }
                                            }
                                            if (inst[10] == '8') {
                                                if (inst.size() < 12) return instr_search_failed;
                                                if (inst[11] == '.') {
                                                    if (inst.size() < 13) return instr_search_failed;
                                                    if (inst[12] == 'v') {
                                                        if (inst.size() < 14) return 636;
                                                    }
                                                }
                                            }
                                            if (inst[10] == '3') {
                                                if (inst.size() < 12) return instr_search_failed;
                                                if (inst[11] == '2') {
                                                    if (inst.size() < 13) return instr_search_failed;
                                                    if (inst[12] == '.') {
                                                        if (inst.size() < 14) return instr_search_failed;
                                                        if (inst[13] == 'v') {
                                                            if (inst.size() < 15) return 644;
                                                        }
                                                    }
                                                }
                                            }
                                        }
                                    }
                                }
                                if (inst[7] == '5') {
                                    if (inst.size() < 9) return instr_search_failed;
                                    if (inst[8] == 'e') {
                                        if (inst.size() < 10) return instr_search_failed;
                                        if (inst[9] == 'i') {
                                            if (inst.size() < 11) return instr_search_failed;
                                            if (inst[10] == '1') {
                                                if (inst.size() < 12) return instr_search_failed;
                                                if (inst[11] == '6') {
                                                    if (inst.size() < 13) return instr_search_failed;
                                                    if (inst[12] == '.') {
                                                        if (inst.size() < 14) return instr_search_failed;
                                                        if (inst[13] == 'v') {
                                                            if (inst.size() < 15) return 656;
                                                        }
                                                    }
                                                }
                                            }
                                            if (inst[10] == '6') {
                                                if (inst.size() < 12) return instr_search_failed;
                                                if (inst[11] == '4') {
                                                    if (inst.size() < 13) return instr_search_failed;
                                                    if (inst[12] == '.') {
                                                        if (inst.size() < 14) return instr_search_failed;
                                                        if (inst[13] == 'v') {
                                                            if (inst.size() < 15) return 664;
                                                        }
                                                    }
                                                }
                                            }
                                            if (inst[10] == '8') {
                                                if (inst.size() < 12) return instr_search_failed;
                                                if (inst[11] == '.') {
                                                    if (inst.size() < 13) return instr_search_failed;
                                                    if (inst[12] == 'v') {
                                                        if (inst.size() < 14) return 652;
                                                    }
                                                }
                                            }
                                            if (inst[10] == '3') {
                                                if (inst.size() < 12) return instr_search_failed;
                                                if (inst[11] == '2') {
                                                    if (inst.size() < 13) return instr_search_failed;
                                                    if (inst[12] == '.') {
                                                        if (inst.size() < 14) return instr_search_failed;
                                                        if (inst[13] == 'v') {
                                                            if (inst.size() < 15) return 660;
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
                    if (inst[4] == 'e') {
                        if (inst.size() < 6) return instr_search_failed;
                        if (inst[5] == 'i') {
                            if (inst.size() < 7) return instr_search_failed;
                            if (inst[6] == '1') {
                                if (inst.size() < 8) return instr_search_failed;
                                if (inst[7] == '6') {
                                    if (inst.size() < 9) return instr_search_failed;
                                    if (inst[8] == '.') {
                                        if (inst.size() < 10) return instr_search_failed;
                                        if (inst[9] == 'v') {
                                            if (inst.size() < 11) return 454;
                                        }
                                    }
                                }
                            }
                            if (inst[6] == '6') {
                                if (inst.size() < 8) return instr_search_failed;
                                if (inst[7] == '4') {
                                    if (inst.size() < 9) return instr_search_failed;
                                    if (inst[8] == '.') {
                                        if (inst.size() < 10) return instr_search_failed;
                                        if (inst[9] == 'v') {
                                            if (inst.size() < 11) return 456;
                                        }
                                    }
                                }
                            }
                            if (inst[6] == '8') {
                                if (inst.size() < 8) return instr_search_failed;
                                if (inst[7] == '.') {
                                    if (inst.size() < 9) return instr_search_failed;
                                    if (inst[8] == 'v') {
                                        if (inst.size() < 10) return 453;
                                    }
                                }
                            }
                            if (inst[6] == '3') {
                                if (inst.size() < 8) return instr_search_failed;
                                if (inst[7] == '2') {
                                    if (inst.size() < 9) return instr_search_failed;
                                    if (inst[8] == '.') {
                                        if (inst.size() < 10) return instr_search_failed;
                                        if (inst[9] == 'v') {
                                            if (inst.size() < 11) return 455;
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
            if (inst[2] == 'r') {
                if (inst.size() < 4) return instr_search_failed;
                if (inst[3] == 'a') {
                    if (inst.size() < 5) return instr_search_failed;
                    if (inst[4] == '.') {
                        if (inst.size() < 6) return instr_search_failed;
                        if (inst[5] == 'v') {
                            if (inst.size() < 7) return instr_search_failed;
                            if (inst[6] == 'i') {
                                if (inst.size() < 8) return 794;
                            }
                            if (inst[6] == 'x') {
                                if (inst.size() < 8) return 793;
                            }
                            if (inst[6] == 'v') {
                                if (inst.size() < 8) return 792;
                            }
                        }
                    }
                }
                if (inst[3] == 'l') {
                    if (inst.size() < 5) return instr_search_failed;
                    if (inst[4] == '.') {
                        if (inst.size() < 6) return instr_search_failed;
                        if (inst[5] == 'v') {
                            if (inst.size() < 7) return instr_search_failed;
                            if (inst[6] == 'i') {
                                if (inst.size() < 8) return 791;
                            }
                            if (inst[6] == 'x') {
                                if (inst.size() < 8) return 790;
                            }
                            if (inst[6] == 'v') {
                                if (inst.size() < 8) return 789;
                            }
                        }
                    }
                }
            }
            if (inst[2] == 'l') {
                if (inst.size() < 4) return instr_search_failed;
                if (inst[3] == 'i') {
                    if (inst.size() < 5) return instr_search_failed;
                    if (inst[4] == 'd') {
                        if (inst.size() < 6) return instr_search_failed;
                        if (inst[5] == 'e') {
                            if (inst.size() < 7) return instr_search_failed;
                            if (inst[6] == 'd') {
                                if (inst.size() < 8) return instr_search_failed;
                                if (inst[7] == 'o') {
                                    if (inst.size() < 9) return instr_search_failed;
                                    if (inst[8] == 'w') {
                                        if (inst.size() < 10) return instr_search_failed;
                                        if (inst[9] == 'n') {
                                            if (inst.size() < 11) return instr_search_failed;
                                            if (inst[10] == '.') {
                                                if (inst.size() < 12) return instr_search_failed;
                                                if (inst[11] == 'v') {
                                                    if (inst.size() < 13) return instr_search_failed;
                                                    if (inst[12] == 'i') {
                                                        if (inst.size() < 14) return 1025;
                                                    }
                                                    if (inst[12] == 'x') {
                                                        if (inst.size() < 14) return 1024;
                                                    }
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                            if (inst[6] == 'u') {
                                if (inst.size() < 8) return instr_search_failed;
                                if (inst[7] == 'p') {
                                    if (inst.size() < 9) return instr_search_failed;
                                    if (inst[8] == '.') {
                                        if (inst.size() < 10) return instr_search_failed;
                                        if (inst[9] == 'v') {
                                            if (inst.size() < 11) return instr_search_failed;
                                            if (inst[10] == 'i') {
                                                if (inst.size() < 12) return 1023;
                                            }
                                            if (inst[10] == 'x') {
                                                if (inst.size() < 12) return 1022;
                                            }
                                        }
                                    }
                                }
                            }
                            if (inst[6] == '1') {
                                if (inst.size() < 8) return instr_search_failed;
                                if (inst[7] == 'd') {
                                    if (inst.size() < 9) return instr_search_failed;
                                    if (inst[8] == 'o') {
                                        if (inst.size() < 10) return instr_search_failed;
                                        if (inst[9] == 'w') {
                                            if (inst.size() < 11) return instr_search_failed;
                                            if (inst[10] == 'n') {
                                                if (inst.size() < 12) return instr_search_failed;
                                                if (inst[11] == '.') {
                                                    if (inst.size() < 13) return instr_search_failed;
                                                    if (inst[12] == 'v') {
                                                        if (inst.size() < 14) return instr_search_failed;
                                                        if (inst[13] == 'x') {
                                                            if (inst.size() < 15) return 1028;
                                                        }
                                                    }
                                                }
                                            }
                                        }
                                    }
                                }
                                if (inst[7] == 'u') {
                                    if (inst.size() < 9) return instr_search_failed;
                                    if (inst[8] == 'p') {
                                        if (inst.size() < 10) return instr_search_failed;
                                        if (inst[9] == '.') {
                                            if (inst.size() < 11) return instr_search_failed;
                                            if (inst[10] == 'v') {
                                                if (inst.size() < 12) return instr_search_failed;
                                                if (inst[11] == 'x') {
                                                    if (inst.size() < 13) return 1026;
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
                if (inst[3] == 'l') {
                    if (inst.size() < 5) return instr_search_failed;
                    if (inst[4] == '.') {
                        if (inst.size() < 6) return instr_search_failed;
                        if (inst[5] == 'v') {
                            if (inst.size() < 7) return instr_search_failed;
                            if (inst[6] == 'i') {
                                if (inst.size() < 8) return 788;
                            }
                            if (inst[6] == 'x') {
                                if (inst.size() < 8) return 787;
                            }
                            if (inst[6] == 'v') {
                                if (inst.size() < 8) return 786;
                            }
                        }
                    }
                }
            }
            if (inst[2] == 's') {
                if (inst.size() < 4) return instr_search_failed;
                if (inst[3] == 'u') {
                    if (inst.size() < 5) return instr_search_failed;
                    if (inst[4] == 'b') {
                        if (inst.size() < 6) return instr_search_failed;
                        if (inst[5] == '.') {
                            if (inst.size() < 7) return instr_search_failed;
                            if (inst[6] == 'v') {
                                if (inst.size() < 8) return instr_search_failed;
                                if (inst[7] == 'x') {
                                    if (inst.size() < 9) return 881;
                                }
                                if (inst[7] == 'v') {
                                    if (inst.size() < 9) return 880;
                                }
                            }
                        }
                        if (inst[5] == 'u') {
                            if (inst.size() < 7) return instr_search_failed;
                            if (inst[6] == '.') {
                                if (inst.size() < 8) return instr_search_failed;
                                if (inst[7] == 'v') {
                                    if (inst.size() < 9) return instr_search_failed;
                                    if (inst[8] == 'x') {
                                        if (inst.size() < 10) return 879;
                                    }
                                    if (inst[8] == 'v') {
                                        if (inst.size() < 10) return 878;
                                    }
                                }
                            }
                        }
                    }
                }
                if (inst[3] == 'r') {
                    if (inst.size() < 5) return instr_search_failed;
                    if (inst[4] == 'a') {
                        if (inst.size() < 6) return instr_search_failed;
                        if (inst[5] == '.') {
                            if (inst.size() < 7) return instr_search_failed;
                            if (inst[6] == 'v') {
                                if (inst.size() < 8) return instr_search_failed;
                                if (inst[7] == 'i') {
                                    if (inst.size() < 9) return 897;
                                }
                                if (inst[7] == 'x') {
                                    if (inst.size() < 9) return 896;
                                }
                                if (inst[7] == 'v') {
                                    if (inst.size() < 9) return 895;
                                }
                            }
                        }
                    }
                    if (inst[4] == 'l') {
                        if (inst.size() < 6) return instr_search_failed;
                        if (inst[5] == '.') {
                            if (inst.size() < 7) return instr_search_failed;
                            if (inst[6] == 'v') {
                                if (inst.size() < 8) return instr_search_failed;
                                if (inst[7] == 'i') {
                                    if (inst.size() < 9) return 894;
                                }
                                if (inst[7] == 'x') {
                                    if (inst.size() < 9) return 893;
                                }
                                if (inst[7] == 'v') {
                                    if (inst.size() < 9) return 892;
                                }
                            }
                        }
                    }
                }
                if (inst[3] == 'e') {
                    if (inst.size() < 5) return instr_search_failed;
                    if (inst[4] == 'g') {
                        if (inst.size() < 6) return instr_search_failed;
                        if (inst[5] == '6') {
                            if (inst.size() < 7) return instr_search_failed;
                            if (inst[6] == 'e') {
                                if (inst.size() < 8) return instr_search_failed;
                                if (inst[7] == '1') {
                                    if (inst.size() < 9) return instr_search_failed;
                                    if (inst[8] == '6') {
                                        if (inst.size() < 10) return instr_search_failed;
                                        if (inst[9] == '.') {
                                            if (inst.size() < 11) return instr_search_failed;
                                            if (inst[10] == 'v') {
                                                if (inst.size() < 12) return 496;
                                            }
                                        }
                                    }
                                }
                                if (inst[7] == '6') {
                                    if (inst.size() < 9) return instr_search_failed;
                                    if (inst[8] == '4') {
                                        if (inst.size() < 10) return instr_search_failed;
                                        if (inst[9] == '.') {
                                            if (inst.size() < 11) return instr_search_failed;
                                            if (inst[10] == 'v') {
                                                if (inst.size() < 12) return 500;
                                            }
                                        }
                                    }
                                }
                                if (inst[7] == '8') {
                                    if (inst.size() < 9) return instr_search_failed;
                                    if (inst[8] == '.') {
                                        if (inst.size() < 10) return instr_search_failed;
                                        if (inst[9] == 'v') {
                                            if (inst.size() < 11) return 494;
                                        }
                                    }
                                }
                                if (inst[7] == '3') {
                                    if (inst.size() < 9) return instr_search_failed;
                                    if (inst[8] == '2') {
                                        if (inst.size() < 10) return instr_search_failed;
                                        if (inst[9] == '.') {
                                            if (inst.size() < 11) return instr_search_failed;
                                            if (inst[10] == 'v') {
                                                if (inst.size() < 12) return 498;
                                            }
                                        }
                                    }
                                }
                            }
                        }
                        if (inst[5] == '8') {
                            if (inst.size() < 7) return instr_search_failed;
                            if (inst[6] == 'e') {
                                if (inst.size() < 8) return instr_search_failed;
                                if (inst[7] == '1') {
                                    if (inst.size() < 9) return instr_search_failed;
                                    if (inst[8] == '6') {
                                        if (inst.size() < 10) return instr_search_failed;
                                        if (inst[9] == '.') {
                                            if (inst.size() < 11) return instr_search_failed;
                                            if (inst[10] == 'v') {
                                                if (inst.size() < 12) return 512;
                                            }
                                        }
                                    }
                                }
                                if (inst[7] == '6') {
                                    if (inst.size() < 9) return instr_search_failed;
                                    if (inst[8] == '4') {
                                        if (inst.size() < 10) return instr_search_failed;
                                        if (inst[9] == '.') {
                                            if (inst.size() < 11) return instr_search_failed;
                                            if (inst[10] == 'v') {
                                                if (inst.size() < 12) return 516;
                                            }
                                        }
                                    }
                                }
                                if (inst[7] == '8') {
                                    if (inst.size() < 9) return instr_search_failed;
                                    if (inst[8] == '.') {
                                        if (inst.size() < 10) return instr_search_failed;
                                        if (inst[9] == 'v') {
                                            if (inst.size() < 11) return 510;
                                        }
                                    }
                                }
                                if (inst[7] == '3') {
                                    if (inst.size() < 9) return instr_search_failed;
                                    if (inst[8] == '2') {
                                        if (inst.size() < 10) return instr_search_failed;
                                        if (inst[9] == '.') {
                                            if (inst.size() < 11) return instr_search_failed;
                                            if (inst[10] == 'v') {
                                                if (inst.size() < 12) return 514;
                                            }
                                        }
                                    }
                                }
                            }
                        }
                        if (inst[5] == '2') {
                            if (inst.size() < 7) return instr_search_failed;
                            if (inst[6] == 'e') {
                                if (inst.size() < 8) return instr_search_failed;
                                if (inst[7] == '1') {
                                    if (inst.size() < 9) return instr_search_failed;
                                    if (inst[8] == '6') {
                                        if (inst.size() < 10) return instr_search_failed;
                                        if (inst[9] == '.') {
                                            if (inst.size() < 11) return instr_search_failed;
                                            if (inst[10] == 'v') {
                                                if (inst.size() < 12) return 464;
                                            }
                                        }
                                    }
                                }
                                if (inst[7] == '6') {
                                    if (inst.size() < 9) return instr_search_failed;
                                    if (inst[8] == '4') {
                                        if (inst.size() < 10) return instr_search_failed;
                                        if (inst[9] == '.') {
                                            if (inst.size() < 11) return instr_search_failed;
                                            if (inst[10] == 'v') {
                                                if (inst.size() < 12) return 468;
                                            }
                                        }
                                    }
                                }
                                if (inst[7] == '8') {
                                    if (inst.size() < 9) return instr_search_failed;
                                    if (inst[8] == '.') {
                                        if (inst.size() < 10) return instr_search_failed;
                                        if (inst[9] == 'v') {
                                            if (inst.size() < 11) return 462;
                                        }
                                    }
                                }
                                if (inst[7] == '3') {
                                    if (inst.size() < 9) return instr_search_failed;
                                    if (inst[8] == '2') {
                                        if (inst.size() < 10) return instr_search_failed;
                                        if (inst[9] == '.') {
                                            if (inst.size() < 11) return instr_search_failed;
                                            if (inst[10] == 'v') {
                                                if (inst.size() < 12) return 466;
                                            }
                                        }
                                    }
                                }
                            }
                        }
                        if (inst[5] == '3') {
                            if (inst.size() < 7) return instr_search_failed;
                            if (inst[6] == 'e') {
                                if (inst.size() < 8) return instr_search_failed;
                                if (inst[7] == '1') {
                                    if (inst.size() < 9) return instr_search_failed;
                                    if (inst[8] == '6') {
                                        if (inst.size() < 10) return instr_search_failed;
                                        if (inst[9] == '.') {
                                            if (inst.size() < 11) return instr_search_failed;
                                            if (inst[10] == 'v') {
                                                if (inst.size() < 12) return 472;
                                            }
                                        }
                                    }
                                }
                                if (inst[7] == '6') {
                                    if (inst.size() < 9) return instr_search_failed;
                                    if (inst[8] == '4') {
                                        if (inst.size() < 10) return instr_search_failed;
                                        if (inst[9] == '.') {
                                            if (inst.size() < 11) return instr_search_failed;
                                            if (inst[10] == 'v') {
                                                if (inst.size() < 12) return 476;
                                            }
                                        }
                                    }
                                }
                                if (inst[7] == '8') {
                                    if (inst.size() < 9) return instr_search_failed;
                                    if (inst[8] == '.') {
                                        if (inst.size() < 10) return instr_search_failed;
                                        if (inst[9] == 'v') {
                                            if (inst.size() < 11) return 470;
                                        }
                                    }
                                }
                                if (inst[7] == '3') {
                                    if (inst.size() < 9) return instr_search_failed;
                                    if (inst[8] == '2') {
                                        if (inst.size() < 10) return instr_search_failed;
                                        if (inst[9] == '.') {
                                            if (inst.size() < 11) return instr_search_failed;
                                            if (inst[10] == 'v') {
                                                if (inst.size() < 12) return 474;
                                            }
                                        }
                                    }
                                }
                            }
                        }
                        if (inst[5] == '7') {
                            if (inst.size() < 7) return instr_search_failed;
                            if (inst[6] == 'e') {
                                if (inst.size() < 8) return instr_search_failed;
                                if (inst[7] == '1') {
                                    if (inst.size() < 9) return instr_search_failed;
                                    if (inst[8] == '6') {
                                        if (inst.size() < 10) return instr_search_failed;
                                        if (inst[9] == '.') {
                                            if (inst.size() < 11) return instr_search_failed;
                                            if (inst[10] == 'v') {
                                                if (inst.size() < 12) return 504;
                                            }
                                        }
                                    }
                                }
                                if (inst[7] == '6') {
                                    if (inst.size() < 9) return instr_search_failed;
                                    if (inst[8] == '4') {
                                        if (inst.size() < 10) return instr_search_failed;
                                        if (inst[9] == '.') {
                                            if (inst.size() < 11) return instr_search_failed;
                                            if (inst[10] == 'v') {
                                                if (inst.size() < 12) return 508;
                                            }
                                        }
                                    }
                                }
                                if (inst[7] == '8') {
                                    if (inst.size() < 9) return instr_search_failed;
                                    if (inst[8] == '.') {
                                        if (inst.size() < 10) return instr_search_failed;
                                        if (inst[9] == 'v') {
                                            if (inst.size() < 11) return 502;
                                        }
                                    }
                                }
                                if (inst[7] == '3') {
                                    if (inst.size() < 9) return instr_search_failed;
                                    if (inst[8] == '2') {
                                        if (inst.size() < 10) return instr_search_failed;
                                        if (inst[9] == '.') {
                                            if (inst.size() < 11) return instr_search_failed;
                                            if (inst[10] == 'v') {
                                                if (inst.size() < 12) return 506;
                                            }
                                        }
                                    }
                                }
                            }
                        }
                        if (inst[5] == '4') {
                            if (inst.size() < 7) return instr_search_failed;
                            if (inst[6] == 'e') {
                                if (inst.size() < 8) return instr_search_failed;
                                if (inst[7] == '1') {
                                    if (inst.size() < 9) return instr_search_failed;
                                    if (inst[8] == '6') {
                                        if (inst.size() < 10) return instr_search_failed;
                                        if (inst[9] == '.') {
                                            if (inst.size() < 11) return instr_search_failed;
                                            if (inst[10] == 'v') {
                                                if (inst.size() < 12) return 564;
                                            }
                                        }
                                    }
                                }
                                if (inst[7] == '6') {
                                    if (inst.size() < 9) return instr_search_failed;
                                    if (inst[8] == '4') {
                                        if (inst.size() < 10) return instr_search_failed;
                                        if (inst[9] == '.') {
                                            if (inst.size() < 11) return instr_search_failed;
                                            if (inst[10] == 'v') {
                                                if (inst.size() < 12) return 484;
                                            }
                                        }
                                    }
                                }
                                if (inst[7] == '8') {
                                    if (inst.size() < 9) return instr_search_failed;
                                    if (inst[8] == '.') {
                                        if (inst.size() < 10) return instr_search_failed;
                                        if (inst[9] == 'v') {
                                            if (inst.size() < 11) return 478;
                                        }
                                    }
                                }
                                if (inst[7] == '3') {
                                    if (inst.size() < 9) return instr_search_failed;
                                    if (inst[8] == '2') {
                                        if (inst.size() < 10) return instr_search_failed;
                                        if (inst[9] == '.') {
                                            if (inst.size() < 11) return instr_search_failed;
                                            if (inst[10] == 'v') {
                                                if (inst.size() < 12) return 566;
                                            }
                                        }
                                    }
                                }
                            }
                        }
                        if (inst[5] == '5') {
                            if (inst.size() < 7) return instr_search_failed;
                            if (inst[6] == 'e') {
                                if (inst.size() < 8) return instr_search_failed;
                                if (inst[7] == '1') {
                                    if (inst.size() < 9) return instr_search_failed;
                                    if (inst[8] == '6') {
                                        if (inst.size() < 10) return instr_search_failed;
                                        if (inst[9] == '.') {
                                            if (inst.size() < 11) return instr_search_failed;
                                            if (inst[10] == 'v') {
                                                if (inst.size() < 12) return 488;
                                            }
                                        }
                                    }
                                }
                                if (inst[7] == '6') {
                                    if (inst.size() < 9) return instr_search_failed;
                                    if (inst[8] == '4') {
                                        if (inst.size() < 10) return instr_search_failed;
                                        if (inst[9] == '.') {
                                            if (inst.size() < 11) return instr_search_failed;
                                            if (inst[10] == 'v') {
                                                if (inst.size() < 12) return 492;
                                            }
                                        }
                                    }
                                }
                                if (inst[7] == '8') {
                                    if (inst.size() < 9) return instr_search_failed;
                                    if (inst[8] == '.') {
                                        if (inst.size() < 10) return instr_search_failed;
                                        if (inst[9] == 'v') {
                                            if (inst.size() < 11) return 486;
                                        }
                                    }
                                }
                                if (inst[7] == '3') {
                                    if (inst.size() < 9) return instr_search_failed;
                                    if (inst[8] == '2') {
                                        if (inst.size() < 10) return instr_search_failed;
                                        if (inst[9] == '.') {
                                            if (inst.size() < 11) return instr_search_failed;
                                            if (inst[10] == 'v') {
                                                if (inst.size() < 12) return 490;
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                    if (inst[4] == '1') {
                        if (inst.size() < 6) return instr_search_failed;
                        if (inst[5] == '6') {
                            if (inst.size() < 7) return instr_search_failed;
                            if (inst[6] == '.') {
                                if (inst.size() < 8) return instr_search_failed;
                                if (inst[7] == 'v') {
                                    if (inst.size() < 9) return 438;
                                }
                            }
                        }
                    }
                    if (inst[4] == '6') {
                        if (inst.size() < 6) return instr_search_failed;
                        if (inst[5] == '4') {
                            if (inst.size() < 7) return instr_search_failed;
                            if (inst[6] == '.') {
                                if (inst.size() < 8) return instr_search_failed;
                                if (inst[7] == 'v') {
                                    if (inst.size() < 9) return 440;
                                }
                            }
                        }
                    }
                    if (inst[4] == '8') {
                        if (inst.size() < 6) return instr_search_failed;
                        if (inst[5] == '.') {
                            if (inst.size() < 7) return instr_search_failed;
                            if (inst[6] == 'v') {
                                if (inst.size() < 8) return 437;
                            }
                        }
                    }
                    if (inst[4] == '3') {
                        if (inst.size() < 6) return instr_search_failed;
                        if (inst[5] == '2') {
                            if (inst.size() < 7) return instr_search_failed;
                            if (inst[6] == '.') {
                                if (inst.size() < 8) return instr_search_failed;
                                if (inst[7] == 'v') {
                                    if (inst.size() < 9) return 439;
                                }
                            }
                        }
                    }
                }
            }
            if (inst[2] == 'b') {
                if (inst.size() < 4) return instr_search_failed;
                if (inst[3] == 'c') {
                    if (inst.size() < 5) return instr_search_failed;
                    if (inst[4] == '.') {
                        if (inst.size() < 6) return instr_search_failed;
                        if (inst[5] == 'v') {
                            if (inst.size() < 7) return instr_search_failed;
                            if (inst[6] == 'x') {
                                if (inst.size() < 8) return instr_search_failed;
                                if (inst[7] == 'm') {
                                    if (inst.size() < 9) return 772;
                                }
                            }
                            if (inst[6] == 'v') {
                                if (inst.size() < 8) return instr_search_failed;
                                if (inst[7] == 'm') {
                                    if (inst.size() < 9) return 771;
                                }
                            }
                        }
                    }
                }
            }
            if (inst[2] == 'e') {
                if (inst.size() < 4) return instr_search_failed;
                if (inst[3] == 'x') {
                    if (inst.size() < 5) return instr_search_failed;
                    if (inst[4] == 't') {
                        if (inst.size() < 6) return instr_search_failed;
                        if (inst[5] == '.') {
                            if (inst.size() < 7) return instr_search_failed;
                            if (inst[6] == 'v') {
                                if (inst.size() < 8) return instr_search_failed;
                                if (inst[7] == 'f') {
                                    if (inst.size() < 9) return instr_search_failed;
                                    if (inst[8] == '8') {
                                        if (inst.size() < 10) return 761;
                                    }
                                    if (inst[8] == '2') {
                                        if (inst.size() < 10) return 757;
                                    }
                                    if (inst[8] == '4') {
                                        if (inst.size() < 10) return 759;
                                    }
                                }
                            }
                        }
                    }
                }
                if (inst[3] == 't') {
                    if (inst.size() < 5) return instr_search_failed;
                    if (inst[4] == 'i') {
                        if (inst.size() < 6) return instr_search_failed;
                        if (inst[5] == 'v') {
                            if (inst.size() < 7) return instr_search_failed;
                            if (inst[6] == 'l') {
                                if (inst.size() < 8) return instr_search_failed;
                                if (inst[7] == 'i') {
                                    if (inst.size() < 9) return 421;
                                }
                            }
                        }
                    }
                    if (inst[4] == 'v') {
                        if (inst.size() < 6) return instr_search_failed;
                        if (inst[5] == 'l') {
                            if (inst.size() < 7) return 422;
                            if (inst[6] == 'i') {
                                if (inst.size() < 8) return 420;
                            }
                        }
                    }
                }
                if (inst[3] == '1') {
                    if (inst.size() < 5) return instr_search_failed;
                    if (inst[4] == '6') {
                        if (inst.size() < 6) return instr_search_failed;
                        if (inst[5] == '.') {
                            if (inst.size() < 7) return instr_search_failed;
                            if (inst[6] == 'v') {
                                if (inst.size() < 8) return 428;
                            }
                        }
                    }
                }
                if (inst[3] == '6') {
                    if (inst.size() < 5) return instr_search_failed;
                    if (inst[4] == '4') {
                        if (inst.size() < 6) return instr_search_failed;
                        if (inst[5] == '.') {
                            if (inst.size() < 7) return instr_search_failed;
                            if (inst[6] == 'v') {
                                if (inst.size() < 8) return 430;
                            }
                        }
                    }
                }
                if (inst[3] == '8') {
                    if (inst.size() < 5) return instr_search_failed;
                    if (inst[4] == '.') {
                        if (inst.size() < 6) return instr_search_failed;
                        if (inst[5] == 'v') {
                            if (inst.size() < 7) return 427;
                        }
                    }
                }
                if (inst[3] == '3') {
                    if (inst.size() < 5) return instr_search_failed;
                    if (inst[4] == '2') {
                        if (inst.size() < 6) return instr_search_failed;
                        if (inst[5] == '.') {
                            if (inst.size() < 7) return instr_search_failed;
                            if (inst[6] == 'v') {
                                if (inst.size() < 8) return 429;
                            }
                        }
                    }
                }
            }
            if (inst[2] == '1') {
                if (inst.size() < 4) return instr_search_failed;
                if (inst[3] == 'r') {
                    if (inst.size() < 5) return instr_search_failed;
                    if (inst[4] == '.') {
                        if (inst.size() < 6) return instr_search_failed;
                        if (inst[5] == 'v') {
                            if (inst.size() < 7) return 729;
                        }
                    }
                }
            }
            if (inst[2] == '8') {
                if (inst.size() < 4) return instr_search_failed;
                if (inst[3] == 'r') {
                    if (inst.size() < 5) return instr_search_failed;
                    if (inst[4] == '.') {
                        if (inst.size() < 6) return instr_search_failed;
                        if (inst[5] == 'v') {
                            if (inst.size() < 7) return 732;
                        }
                    }
                }
            }
            if (inst[2] == '2') {
                if (inst.size() < 4) return instr_search_failed;
                if (inst[3] == 'r') {
                    if (inst.size() < 5) return instr_search_failed;
                    if (inst[4] == '.') {
                        if (inst.size() < 6) return instr_search_failed;
                        if (inst[5] == 'v') {
                            if (inst.size() < 7) return 730;
                        }
                    }
                }
            }
            if (inst[2] == '4') {
                if (inst.size() < 4) return instr_search_failed;
                if (inst[3] == 'r') {
                    if (inst.size() < 5) return instr_search_failed;
                    if (inst[4] == '.') {
                        if (inst.size() < 6) return instr_search_failed;
                        if (inst[5] == 'v') {
                            if (inst.size() < 7) return 731;
                        }
                    }
                }
            }
        }
        if (inst[1] == 'x') {
            if (inst.size() < 3) return instr_search_failed;
            if (inst[2] == 'o') {
                if (inst.size() < 4) return instr_search_failed;
                if (inst[3] == 'r') {
                    if (inst.size() < 5) return instr_search_failed;
                    if (inst[4] == '.') {
                        if (inst.size() < 6) return instr_search_failed;
                        if (inst[5] == 'v') {
                            if (inst.size() < 7) return instr_search_failed;
                            if (inst[6] == 'i') {
                                if (inst.size() < 8) return 785;
                            }
                            if (inst[6] == 'x') {
                                if (inst.size() < 8) return 784;
                            }
                            if (inst[6] == 'v') {
                                if (inst.size() < 8) return 783;
                            }
                        }
                    }
                }
            }
        }
        if (inst[1] == 'z') {
            if (inst.size() < 3) return instr_search_failed;
            if (inst[2] == 'e') {
                if (inst.size() < 4) return instr_search_failed;
                if (inst[3] == 'x') {
                    if (inst.size() < 5) return instr_search_failed;
                    if (inst[4] == 't') {
                        if (inst.size() < 6) return instr_search_failed;
                        if (inst[5] == '.') {
                            if (inst.size() < 7) return instr_search_failed;
                            if (inst[6] == 'v') {
                                if (inst.size() < 8) return instr_search_failed;
                                if (inst[7] == 'f') {
                                    if (inst.size() < 9) return instr_search_failed;
                                    if (inst[8] == '8') {
                                        if (inst.size() < 10) return 760;
                                    }
                                    if (inst[8] == '2') {
                                        if (inst.size() < 10) return 756;
                                    }
                                    if (inst[8] == '4') {
                                        if (inst.size() < 10) return 758;
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
        if (inst[1] == 'f') {
            if (inst.size() < 3) return instr_search_failed;
            if (inst[2] == 'a') {
                if (inst.size() < 4) return instr_search_failed;
                if (inst[3] == 'd') {
                    if (inst.size() < 5) return instr_search_failed;
                    if (inst[4] == 'd') {
                        if (inst.size() < 6) return instr_search_failed;
                        if (inst[5] == '.') {
                            if (inst.size() < 7) return instr_search_failed;
                            if (inst[6] == 'v') {
                                if (inst.size() < 8) return instr_search_failed;
                                if (inst[7] == 'v') {
                                    if (inst.size() < 9) return 904;
                                }
                                if (inst[7] == 'f') {
                                    if (inst.size() < 9) return 905;
                                }
                            }
                        }
                    }
                }
            }
            if (inst[2] == 'd') {
                if (inst.size() < 4) return instr_search_failed;
                if (inst[3] == 'i') {
                    if (inst.size() < 5) return instr_search_failed;
                    if (inst[4] == 'v') {
                        if (inst.size() < 6) return instr_search_failed;
                        if (inst[5] == '.') {
                            if (inst.size() < 7) return instr_search_failed;
                            if (inst[6] == 'v') {
                                if (inst.size() < 8) return instr_search_failed;
                                if (inst[7] == 'v') {
                                    if (inst.size() < 9) return 919;
                                }
                                if (inst[7] == 'f') {
                                    if (inst.size() < 9) return 920;
                                }
                            }
                        }
                    }
                }
            }
            if (inst[2] == 'w') {
                if (inst.size() < 4) return instr_search_failed;
                if (inst[3] == 'a') {
                    if (inst.size() < 5) return instr_search_failed;
                    if (inst[4] == 'd') {
                        if (inst.size() < 6) return instr_search_failed;
                        if (inst[5] == 'd') {
                            if (inst.size() < 7) return instr_search_failed;
                            if (inst[6] == '.') {
                                if (inst.size() < 8) return instr_search_failed;
                                if (inst[7] == 'w') {
                                    if (inst.size() < 9) return instr_search_failed;
                                    if (inst[8] == 'v') {
                                        if (inst.size() < 10) return 913;
                                    }
                                    if (inst[8] == 'f') {
                                        if (inst.size() < 10) return 914;
                                    }
                                }
                                if (inst[7] == 'v') {
                                    if (inst.size() < 9) return instr_search_failed;
                                    if (inst[8] == 'v') {
                                        if (inst.size() < 10) return 909;
                                    }
                                    if (inst[8] == 'f') {
                                        if (inst.size() < 10) return 910;
                                    }
                                }
                            }
                        }
                    }
                }
                if (inst[3] == 'm') {
                    if (inst.size() < 5) return instr_search_failed;
                    if (inst[4] == 'u') {
                        if (inst.size() < 6) return instr_search_failed;
                        if (inst[5] == 'l') {
                            if (inst.size() < 7) return instr_search_failed;
                            if (inst[6] == '.') {
                                if (inst.size() < 8) return instr_search_failed;
                                if (inst[7] == 'v') {
                                    if (inst.size() < 9) return instr_search_failed;
                                    if (inst[8] == 'v') {
                                        if (inst.size() < 10) return 922;
                                    }
                                    if (inst[8] == 'f') {
                                        if (inst.size() < 10) return 923;
                                    }
                                }
                            }
                        }
                    }
                }
                if (inst[3] == 'r') {
                    if (inst.size() < 5) return instr_search_failed;
                    if (inst[4] == 'e') {
                        if (inst.size() < 6) return instr_search_failed;
                        if (inst[5] == 'd') {
                            if (inst.size() < 7) return instr_search_failed;
                            if (inst[6] == 'u') {
                                if (inst.size() < 8) return instr_search_failed;
                                if (inst[7] == 's') {
                                    if (inst.size() < 9) return instr_search_failed;
                                    if (inst[8] == 'u') {
                                        if (inst.size() < 10) return instr_search_failed;
                                        if (inst[9] == 'm') {
                                            if (inst.size() < 11) return instr_search_failed;
                                            if (inst[10] == '.') {
                                                if (inst.size() < 12) return instr_search_failed;
                                                if (inst[11] == 'v') {
                                                    if (inst.size() < 13) return instr_search_failed;
                                                    if (inst[12] == 's') {
                                                        if (inst.size() < 14) return 1002;
                                                    }
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                            if (inst[6] == 'o') {
                                if (inst.size() < 8) return instr_search_failed;
                                if (inst[7] == 's') {
                                    if (inst.size() < 9) return instr_search_failed;
                                    if (inst[8] == 'u') {
                                        if (inst.size() < 10) return instr_search_failed;
                                        if (inst[9] == 'm') {
                                            if (inst.size() < 11) return instr_search_failed;
                                            if (inst[10] == '.') {
                                                if (inst.size() < 12) return instr_search_failed;
                                                if (inst[11] == 'v') {
                                                    if (inst.size() < 13) return instr_search_failed;
                                                    if (inst[12] == 's') {
                                                        if (inst.size() < 14) return 1001;
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
                if (inst[3] == 'c') {
                    if (inst.size() < 5) return instr_search_failed;
                    if (inst[4] == 'v') {
                        if (inst.size() < 6) return instr_search_failed;
                        if (inst[5] == 't') {
                            if (inst.size() < 7) return instr_search_failed;
                            if (inst[6] == '.') {
                                if (inst.size() < 8) return instr_search_failed;
                                if (inst[7] == 'r') {
                                    if (inst.size() < 9) return instr_search_failed;
                                    if (inst[8] == 't') {
                                        if (inst.size() < 10) return instr_search_failed;
                                        if (inst[9] == 'z') {
                                            if (inst.size() < 11) return instr_search_failed;
                                            if (inst[10] == '.') {
                                                if (inst.size() < 12) return instr_search_failed;
                                                if (inst[11] == 'x') {
                                                    if (inst.size() < 13) return instr_search_failed;
                                                    if (inst[12] == '.') {
                                                        if (inst.size() < 14) return instr_search_failed;
                                                        if (inst[13] == 'f') {
                                                            if (inst.size() < 15) return instr_search_failed;
                                                            if (inst[14] == '.') {
                                                                if (inst.size() < 16) return instr_search_failed;
                                                                if (inst[15] == 'v') {
                                                                    if (inst.size() < 17) return 975;
                                                                }
                                                            }
                                                        }
                                                    }
                                                    if (inst[12] == 'u') {
                                                        if (inst.size() < 14) return instr_search_failed;
                                                        if (inst[13] == '.') {
                                                            if (inst.size() < 15) return instr_search_failed;
                                                            if (inst[14] == 'f') {
                                                                if (inst.size() < 16) return instr_search_failed;
                                                                if (inst[15] == '.') {
                                                                    if (inst.size() < 17) return instr_search_failed;
                                                                    if (inst[16] == 'v') {
                                                                        if (inst.size() < 18) return 974;
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
                                if (inst[7] == 'x') {
                                    if (inst.size() < 9) return instr_search_failed;
                                    if (inst[8] == '.') {
                                        if (inst.size() < 10) return instr_search_failed;
                                        if (inst[9] == 'f') {
                                            if (inst.size() < 11) return instr_search_failed;
                                            if (inst[10] == '.') {
                                                if (inst.size() < 12) return instr_search_failed;
                                                if (inst[11] == 'v') {
                                                    if (inst.size() < 13) return 973;
                                                }
                                            }
                                        }
                                    }
                                    if (inst[8] == 'u') {
                                        if (inst.size() < 10) return instr_search_failed;
                                        if (inst[9] == '.') {
                                            if (inst.size() < 11) return instr_search_failed;
                                            if (inst[10] == 'f') {
                                                if (inst.size() < 12) return instr_search_failed;
                                                if (inst[11] == '.') {
                                                    if (inst.size() < 13) return instr_search_failed;
                                                    if (inst[12] == 'v') {
                                                        if (inst.size() < 14) return 972;
                                                    }
                                                }
                                            }
                                        }
                                    }
                                }
                                if (inst[7] == 'f') {
                                    if (inst.size() < 9) return instr_search_failed;
                                    if (inst[8] == '.') {
                                        if (inst.size() < 10) return instr_search_failed;
                                        if (inst[9] == 'x') {
                                            if (inst.size() < 11) return instr_search_failed;
                                            if (inst[10] == '.') {
                                                if (inst.size() < 12) return instr_search_failed;
                                                if (inst[11] == 'v') {
                                                    if (inst.size() < 13) return 977;
                                                }
                                            }
                                            if (inst[10] == 'u') {
                                                if (inst.size() < 12) return instr_search_failed;
                                                if (inst[11] == '.') {
                                                    if (inst.size() < 13) return instr_search_failed;
                                                    if (inst[12] == 'v') {
                                                        if (inst.size() < 14) return 976;
                                                    }
                                                }
                                            }
                                        }
                                        if (inst[9] == 'f') {
                                            if (inst.size() < 11) return instr_search_failed;
                                            if (inst[10] == '.') {
                                                if (inst.size() < 12) return instr_search_failed;
                                                if (inst[11] == 'v') {
                                                    if (inst.size() < 13) return 978;
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
                if (inst[3] == 's') {
                    if (inst.size() < 5) return instr_search_failed;
                    if (inst[4] == 'u') {
                        if (inst.size() < 6) return instr_search_failed;
                        if (inst[5] == 'b') {
                            if (inst.size() < 7) return instr_search_failed;
                            if (inst[6] == '.') {
                                if (inst.size() < 8) return instr_search_failed;
                                if (inst[7] == 'w') {
                                    if (inst.size() < 9) return instr_search_failed;
                                    if (inst[8] == 'v') {
                                        if (inst.size() < 10) return 915;
                                    }
                                    if (inst[8] == 'f') {
                                        if (inst.size() < 10) return 916;
                                    }
                                }
                                if (inst[7] == 'v') {
                                    if (inst.size() < 9) return instr_search_failed;
                                    if (inst[8] == 'v') {
                                        if (inst.size() < 10) return 911;
                                    }
                                    if (inst[8] == 'f') {
                                        if (inst.size() < 10) return 912;
                                    }
                                }
                            }
                        }
                    }
                }
            }
            if (inst[2] == 'i') {
                if (inst.size() < 4) return instr_search_failed;
                if (inst[3] == 'r') {
                    if (inst.size() < 5) return instr_search_failed;
                    if (inst[4] == 's') {
                        if (inst.size() < 6) return instr_search_failed;
                        if (inst[5] == 't') {
                            if (inst.size() < 7) return instr_search_failed;
                            if (inst[6] == '.') {
                                if (inst.size() < 8) return instr_search_failed;
                                if (inst[7] == 'm') {
                                    if (inst.size() < 9) return 1012;
                                }
                            }
                        }
                    }
                }
            }
            if (inst[2] == 'm') {
                if (inst.size() < 4) return instr_search_failed;
                if (inst[3] == 'a') {
                    if (inst.size() < 5) return instr_search_failed;
                    if (inst[4] == 'd') {
                        if (inst.size() < 6) return instr_search_failed;
                        if (inst[5] == 'd') {
                            if (inst.size() < 7) return instr_search_failed;
                            if (inst[6] == '.') {
                                if (inst.size() < 8) return instr_search_failed;
                                if (inst[7] == 'v') {
                                    if (inst.size() < 9) return instr_search_failed;
                                    if (inst[8] == 'v') {
                                        if (inst.size() < 10) return 932;
                                    }
                                    if (inst[8] == 'f') {
                                        if (inst.size() < 10) return 933;
                                    }
                                }
                            }
                        }
                    }
                    if (inst[4] == 'c') {
                        if (inst.size() < 6) return instr_search_failed;
                        if (inst[5] == 'c') {
                            if (inst.size() < 7) return instr_search_failed;
                            if (inst[6] == '.') {
                                if (inst.size() < 8) return instr_search_failed;
                                if (inst[7] == 'v') {
                                    if (inst.size() < 9) return instr_search_failed;
                                    if (inst[8] == 'v') {
                                        if (inst.size() < 10) return 924;
                                    }
                                    if (inst[8] == 'f') {
                                        if (inst.size() < 10) return 925;
                                    }
                                }
                            }
                        }
                    }
                    if (inst[4] == 'x') {
                        if (inst.size() < 6) return instr_search_failed;
                        if (inst[5] == '.') {
                            if (inst.size() < 7) return instr_search_failed;
                            if (inst[6] == 'v') {
                                if (inst.size() < 8) return instr_search_failed;
                                if (inst[7] == 'v') {
                                    if (inst.size() < 9) return 945;
                                }
                                if (inst[7] == 'f') {
                                    if (inst.size() < 9) return 946;
                                }
                            }
                        }
                    }
                }
                if (inst[3] == 'u') {
                    if (inst.size() < 5) return instr_search_failed;
                    if (inst[4] == 'l') {
                        if (inst.size() < 6) return instr_search_failed;
                        if (inst[5] == '.') {
                            if (inst.size() < 7) return instr_search_failed;
                            if (inst[6] == 'v') {
                                if (inst.size() < 8) return instr_search_failed;
                                if (inst[7] == 'v') {
                                    if (inst.size() < 9) return 917;
                                }
                                if (inst[7] == 'f') {
                                    if (inst.size() < 9) return 918;
                                }
                            }
                        }
                    }
                }
                if (inst[3] == 'i') {
                    if (inst.size() < 5) return instr_search_failed;
                    if (inst[4] == 'n') {
                        if (inst.size() < 6) return instr_search_failed;
                        if (inst[5] == '.') {
                            if (inst.size() < 7) return instr_search_failed;
                            if (inst[6] == 'v') {
                                if (inst.size() < 8) return instr_search_failed;
                                if (inst[7] == 'v') {
                                    if (inst.size() < 9) return 943;
                                }
                                if (inst[7] == 'f') {
                                    if (inst.size() < 9) return 944;
                                }
                            }
                        }
                    }
                }
                if (inst[3] == 's') {
                    if (inst.size() < 5) return instr_search_failed;
                    if (inst[4] == 'a') {
                        if (inst.size() < 6) return instr_search_failed;
                        if (inst[5] == 'c') {
                            if (inst.size() < 7) return instr_search_failed;
                            if (inst[6] == '.') {
                                if (inst.size() < 8) return instr_search_failed;
                                if (inst[7] == 'v') {
                                    if (inst.size() < 9) return instr_search_failed;
                                    if (inst[8] == 'v') {
                                        if (inst.size() < 10) return 928;
                                    }
                                    if (inst[8] == 'f') {
                                        if (inst.size() < 10) return 929;
                                    }
                                }
                            }
                        }
                    }
                    if (inst[4] == 'u') {
                        if (inst.size() < 6) return instr_search_failed;
                        if (inst[5] == 'b') {
                            if (inst.size() < 7) return instr_search_failed;
                            if (inst[6] == '.') {
                                if (inst.size() < 8) return instr_search_failed;
                                if (inst[7] == 'v') {
                                    if (inst.size() < 9) return instr_search_failed;
                                    if (inst[8] == 'v') {
                                        if (inst.size() < 10) return 936;
                                    }
                                    if (inst[8] == 'f') {
                                        if (inst.size() < 10) return 937;
                                    }
                                }
                            }
                        }
                    }
                }
                if (inst[3] == 'e') {
                    if (inst.size() < 5) return instr_search_failed;
                    if (inst[4] == 'r') {
                        if (inst.size() < 6) return instr_search_failed;
                        if (inst[5] == 'g') {
                            if (inst.size() < 7) return instr_search_failed;
                            if (inst[6] == 'e') {
                                if (inst.size() < 8) return instr_search_failed;
                                if (inst[7] == '.') {
                                    if (inst.size() < 9) return instr_search_failed;
                                    if (inst[8] == 'v') {
                                        if (inst.size() < 10) return instr_search_failed;
                                        if (inst[9] == 'f') {
                                            if (inst.size() < 11) return instr_search_failed;
                                            if (inst[10] == 'm') {
                                                if (inst.size() < 12) return 964;
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
                if (inst[3] == 'v') {
                    if (inst.size() < 5) return instr_search_failed;
                    if (inst[4] == '.') {
                        if (inst.size() < 6) return instr_search_failed;
                        if (inst[5] == 's') {
                            if (inst.size() < 7) return instr_search_failed;
                            if (inst[6] == '.') {
                                if (inst.size() < 8) return instr_search_failed;
                                if (inst[7] == 'f') {
                                    if (inst.size() < 9) return 1021;
                                }
                            }
                        }
                        if (inst[5] == 'v') {
                            if (inst.size() < 7) return instr_search_failed;
                            if (inst[6] == '.') {
                                if (inst.size() < 8) return instr_search_failed;
                                if (inst[7] == 'f') {
                                    if (inst.size() < 9) return 965;
                                }
                            }
                        }
                        if (inst[5] == 'f') {
                            if (inst.size() < 7) return instr_search_failed;
                            if (inst[6] == '.') {
                                if (inst.size() < 8) return instr_search_failed;
                                if (inst[7] == 's') {
                                    if (inst.size() < 9) return 1020;
                                }
                            }
                        }
                    }
                }
            }
            if (inst[2] == 'r') {
                if (inst.size() < 4) return instr_search_failed;
                if (inst[3] == 'd') {
                    if (inst.size() < 5) return instr_search_failed;
                    if (inst[4] == 'i') {
                        if (inst.size() < 6) return instr_search_failed;
                        if (inst[5] == 'v') {
                            if (inst.size() < 7) return instr_search_failed;
                            if (inst[6] == '.') {
                                if (inst.size() < 8) return instr_search_failed;
                                if (inst[7] == 'v') {
                                    if (inst.size() < 9) return instr_search_failed;
                                    if (inst[8] == 'f') {
                                        if (inst.size() < 10) return 921;
                                    }
                                }
                            }
                        }
                    }
                }
                if (inst[3] == 's') {
                    if (inst.size() < 5) return instr_search_failed;
                    if (inst[4] == 'u') {
                        if (inst.size() < 6) return instr_search_failed;
                        if (inst[5] == 'b') {
                            if (inst.size() < 7) return instr_search_failed;
                            if (inst[6] == '.') {
                                if (inst.size() < 8) return instr_search_failed;
                                if (inst[7] == 'v') {
                                    if (inst.size() < 9) return instr_search_failed;
                                    if (inst[8] == 'f') {
                                        if (inst.size() < 10) return 908;
                                    }
                                }
                            }
                        }
                    }
                    if (inst[4] == 'q') {
                        if (inst.size() < 6) return instr_search_failed;
                        if (inst[5] == 'r') {
                            if (inst.size() < 7) return instr_search_failed;
                            if (inst[6] == 't') {
                                if (inst.size() < 8) return instr_search_failed;
                                if (inst[7] == '7') {
                                    if (inst.size() < 9) return instr_search_failed;
                                    if (inst[8] == '.') {
                                        if (inst.size() < 10) return instr_search_failed;
                                        if (inst[9] == 'v') {
                                            if (inst.size() < 11) return 941;
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
                if (inst[3] == 'e') {
                    if (inst.size() < 5) return instr_search_failed;
                    if (inst[4] == 'd') {
                        if (inst.size() < 6) return instr_search_failed;
                        if (inst[5] == 'u') {
                            if (inst.size() < 7) return instr_search_failed;
                            if (inst[6] == 's') {
                                if (inst.size() < 8) return instr_search_failed;
                                if (inst[7] == 'u') {
                                    if (inst.size() < 9) return instr_search_failed;
                                    if (inst[8] == 'm') {
                                        if (inst.size() < 10) return instr_search_failed;
                                        if (inst[9] == '.') {
                                            if (inst.size() < 11) return instr_search_failed;
                                            if (inst[10] == 'v') {
                                                if (inst.size() < 12) return instr_search_failed;
                                                if (inst[11] == 's') {
                                                    if (inst.size() < 13) return 998;
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                        if (inst[5] == 'm') {
                            if (inst.size() < 7) return instr_search_failed;
                            if (inst[6] == 'a') {
                                if (inst.size() < 8) return instr_search_failed;
                                if (inst[7] == 'x') {
                                    if (inst.size() < 9) return instr_search_failed;
                                    if (inst[8] == '.') {
                                        if (inst.size() < 10) return instr_search_failed;
                                        if (inst[9] == 'v') {
                                            if (inst.size() < 11) return instr_search_failed;
                                            if (inst[10] == 's') {
                                                if (inst.size() < 12) return 999;
                                            }
                                        }
                                    }
                                }
                            }
                            if (inst[6] == 'i') {
                                if (inst.size() < 8) return instr_search_failed;
                                if (inst[7] == 'n') {
                                    if (inst.size() < 9) return instr_search_failed;
                                    if (inst[8] == '.') {
                                        if (inst.size() < 10) return instr_search_failed;
                                        if (inst[9] == 'v') {
                                            if (inst.size() < 11) return instr_search_failed;
                                            if (inst[10] == 's') {
                                                if (inst.size() < 12) return 1000;
                                            }
                                        }
                                    }
                                }
                            }
                        }
                        if (inst[5] == 'o') {
                            if (inst.size() < 7) return instr_search_failed;
                            if (inst[6] == 's') {
                                if (inst.size() < 8) return instr_search_failed;
                                if (inst[7] == 'u') {
                                    if (inst.size() < 9) return instr_search_failed;
                                    if (inst[8] == 'm') {
                                        if (inst.size() < 10) return instr_search_failed;
                                        if (inst[9] == '.') {
                                            if (inst.size() < 11) return instr_search_failed;
                                            if (inst[10] == 'v') {
                                                if (inst.size() < 12) return instr_search_failed;
                                                if (inst[11] == 's') {
                                                    if (inst.size() < 13) return 997;
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                    if (inst[4] == 'c') {
                        if (inst.size() < 6) return instr_search_failed;
                        if (inst[5] == '7') {
                            if (inst.size() < 7) return instr_search_failed;
                            if (inst[6] == '.') {
                                if (inst.size() < 8) return instr_search_failed;
                                if (inst[7] == 'v') {
                                    if (inst.size() < 9) return 942;
                                }
                            }
                        }
                    }
                }
            }
            if (inst[2] == 'n') {
                if (inst.size() < 4) return instr_search_failed;
                if (inst[3] == 'm') {
                    if (inst.size() < 5) return instr_search_failed;
                    if (inst[4] == 'a') {
                        if (inst.size() < 6) return instr_search_failed;
                        if (inst[5] == 'd') {
                            if (inst.size() < 7) return instr_search_failed;
                            if (inst[6] == 'd') {
                                if (inst.size() < 8) return instr_search_failed;
                                if (inst[7] == '.') {
                                    if (inst.size() < 9) return instr_search_failed;
                                    if (inst[8] == 'v') {
                                        if (inst.size() < 10) return instr_search_failed;
                                        if (inst[9] == 'v') {
                                            if (inst.size() < 11) return 934;
                                        }
                                        if (inst[9] == 'f') {
                                            if (inst.size() < 11) return 935;
                                        }
                                    }
                                }
                            }
                        }
                        if (inst[5] == 'c') {
                            if (inst.size() < 7) return instr_search_failed;
                            if (inst[6] == 'c') {
                                if (inst.size() < 8) return instr_search_failed;
                                if (inst[7] == '.') {
                                    if (inst.size() < 9) return instr_search_failed;
                                    if (inst[8] == 'v') {
                                        if (inst.size() < 10) return instr_search_failed;
                                        if (inst[9] == 'v') {
                                            if (inst.size() < 11) return 926;
                                        }
                                        if (inst[9] == 'f') {
                                            if (inst.size() < 11) return 927;
                                        }
                                    }
                                }
                            }
                        }
                    }
                    if (inst[4] == 's') {
                        if (inst.size() < 6) return instr_search_failed;
                        if (inst[5] == 'a') {
                            if (inst.size() < 7) return instr_search_failed;
                            if (inst[6] == 'c') {
                                if (inst.size() < 8) return instr_search_failed;
                                if (inst[7] == '.') {
                                    if (inst.size() < 9) return instr_search_failed;
                                    if (inst[8] == 'v') {
                                        if (inst.size() < 10) return instr_search_failed;
                                        if (inst[9] == 'v') {
                                            if (inst.size() < 11) return 930;
                                        }
                                        if (inst[9] == 'f') {
                                            if (inst.size() < 11) return 931;
                                        }
                                    }
                                }
                            }
                        }
                        if (inst[5] == 'u') {
                            if (inst.size() < 7) return instr_search_failed;
                            if (inst[6] == 'b') {
                                if (inst.size() < 8) return instr_search_failed;
                                if (inst[7] == '.') {
                                    if (inst.size() < 9) return instr_search_failed;
                                    if (inst[8] == 'v') {
                                        if (inst.size() < 10) return instr_search_failed;
                                        if (inst[9] == 'v') {
                                            if (inst.size() < 11) return 938;
                                        }
                                        if (inst[9] == 'f') {
                                            if (inst.size() < 11) return 939;
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
                if (inst[3] == 'c') {
                    if (inst.size() < 5) return instr_search_failed;
                    if (inst[4] == 'v') {
                        if (inst.size() < 6) return instr_search_failed;
                        if (inst[5] == 't') {
                            if (inst.size() < 7) return instr_search_failed;
                            if (inst[6] == '.') {
                                if (inst.size() < 8) return instr_search_failed;
                                if (inst[7] == 'r') {
                                    if (inst.size() < 9) return instr_search_failed;
                                    if (inst[8] == 'o') {
                                        if (inst.size() < 10) return instr_search_failed;
                                        if (inst[9] == 'd') {
                                            if (inst.size() < 11) return instr_search_failed;
                                            if (inst[10] == '.') {
                                                if (inst.size() < 12) return instr_search_failed;
                                                if (inst[11] == 'f') {
                                                    if (inst.size() < 13) return instr_search_failed;
                                                    if (inst[12] == '.') {
                                                        if (inst.size() < 14) return instr_search_failed;
                                                        if (inst[13] == 'f') {
                                                            if (inst.size() < 15) return instr_search_failed;
                                                            if (inst[14] == '.') {
                                                                if (inst.size() < 16) return instr_search_failed;
                                                                if (inst[15] == 'w') {
                                                                    if (inst.size() < 17) return 986;
                                                                }
                                                            }
                                                        }
                                                    }
                                                }
                                            }
                                        }
                                    }
                                    if (inst[8] == 't') {
                                        if (inst.size() < 10) return instr_search_failed;
                                        if (inst[9] == 'z') {
                                            if (inst.size() < 11) return instr_search_failed;
                                            if (inst[10] == '.') {
                                                if (inst.size() < 12) return instr_search_failed;
                                                if (inst[11] == 'x') {
                                                    if (inst.size() < 13) return instr_search_failed;
                                                    if (inst[12] == '.') {
                                                        if (inst.size() < 14) return instr_search_failed;
                                                        if (inst[13] == 'f') {
                                                            if (inst.size() < 15) return instr_search_failed;
                                                            if (inst[14] == '.') {
                                                                if (inst.size() < 16) return instr_search_failed;
                                                                if (inst[15] == 'w') {
                                                                    if (inst.size() < 17) return 982;
                                                                }
                                                            }
                                                        }
                                                    }
                                                    if (inst[12] == 'u') {
                                                        if (inst.size() < 14) return instr_search_failed;
                                                        if (inst[13] == '.') {
                                                            if (inst.size() < 15) return instr_search_failed;
                                                            if (inst[14] == 'f') {
                                                                if (inst.size() < 16) return instr_search_failed;
                                                                if (inst[15] == '.') {
                                                                    if (inst.size() < 17) return instr_search_failed;
                                                                    if (inst[16] == 'w') {
                                                                        if (inst.size() < 18) return 981;
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
                                if (inst[7] == 'x') {
                                    if (inst.size() < 9) return instr_search_failed;
                                    if (inst[8] == '.') {
                                        if (inst.size() < 10) return instr_search_failed;
                                        if (inst[9] == 'f') {
                                            if (inst.size() < 11) return instr_search_failed;
                                            if (inst[10] == '.') {
                                                if (inst.size() < 12) return instr_search_failed;
                                                if (inst[11] == 'w') {
                                                    if (inst.size() < 13) return 980;
                                                }
                                            }
                                        }
                                    }
                                    if (inst[8] == 'u') {
                                        if (inst.size() < 10) return instr_search_failed;
                                        if (inst[9] == '.') {
                                            if (inst.size() < 11) return instr_search_failed;
                                            if (inst[10] == 'f') {
                                                if (inst.size() < 12) return instr_search_failed;
                                                if (inst[11] == '.') {
                                                    if (inst.size() < 13) return instr_search_failed;
                                                    if (inst[12] == 'w') {
                                                        if (inst.size() < 14) return 979;
                                                    }
                                                }
                                            }
                                        }
                                    }
                                }
                                if (inst[7] == 'f') {
                                    if (inst.size() < 9) return instr_search_failed;
                                    if (inst[8] == '.') {
                                        if (inst.size() < 10) return instr_search_failed;
                                        if (inst[9] == 'x') {
                                            if (inst.size() < 11) return instr_search_failed;
                                            if (inst[10] == '.') {
                                                if (inst.size() < 12) return instr_search_failed;
                                                if (inst[11] == 'w') {
                                                    if (inst.size() < 13) return 984;
                                                }
                                            }
                                            if (inst[10] == 'u') {
                                                if (inst.size() < 12) return instr_search_failed;
                                                if (inst[11] == '.') {
                                                    if (inst.size() < 13) return instr_search_failed;
                                                    if (inst[12] == 'w') {
                                                        if (inst.size() < 14) return 983;
                                                    }
                                                }
                                            }
                                        }
                                        if (inst[9] == 'f') {
                                            if (inst.size() < 11) return instr_search_failed;
                                            if (inst[10] == '.') {
                                                if (inst.size() < 12) return instr_search_failed;
                                                if (inst[11] == 'w') {
                                                    if (inst.size() < 13) return 985;
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
            if (inst[2] == 'c') {
                if (inst.size() < 4) return instr_search_failed;
                if (inst[3] == 'l') {
                    if (inst.size() < 5) return instr_search_failed;
                    if (inst[4] == 'a') {
                        if (inst.size() < 6) return instr_search_failed;
                        if (inst[5] == 's') {
                            if (inst.size() < 7) return instr_search_failed;
                            if (inst[6] == 's') {
                                if (inst.size() < 8) return instr_search_failed;
                                if (inst[7] == '.') {
                                    if (inst.size() < 9) return instr_search_failed;
                                    if (inst[8] == 'v') {
                                        if (inst.size() < 10) return 963;
                                    }
                                }
                            }
                        }
                    }
                }
                if (inst[3] == 'v') {
                    if (inst.size() < 5) return instr_search_failed;
                    if (inst[4] == 't') {
                        if (inst.size() < 6) return instr_search_failed;
                        if (inst[5] == '.') {
                            if (inst.size() < 7) return instr_search_failed;
                            if (inst[6] == 'r') {
                                if (inst.size() < 8) return instr_search_failed;
                                if (inst[7] == 't') {
                                    if (inst.size() < 9) return instr_search_failed;
                                    if (inst[8] == 'z') {
                                        if (inst.size() < 10) return instr_search_failed;
                                        if (inst[9] == '.') {
                                            if (inst.size() < 11) return instr_search_failed;
                                            if (inst[10] == 'x') {
                                                if (inst.size() < 12) return instr_search_failed;
                                                if (inst[11] == '.') {
                                                    if (inst.size() < 13) return instr_search_failed;
                                                    if (inst[12] == 'f') {
                                                        if (inst.size() < 14) return instr_search_failed;
                                                        if (inst[13] == '.') {
                                                            if (inst.size() < 15) return instr_search_failed;
                                                            if (inst[14] == 'v') {
                                                                if (inst.size() < 16) return 969;
                                                            }
                                                        }
                                                    }
                                                }
                                                if (inst[11] == 'u') {
                                                    if (inst.size() < 13) return instr_search_failed;
                                                    if (inst[12] == '.') {
                                                        if (inst.size() < 14) return instr_search_failed;
                                                        if (inst[13] == 'f') {
                                                            if (inst.size() < 15) return instr_search_failed;
                                                            if (inst[14] == '.') {
                                                                if (inst.size() < 16) return instr_search_failed;
                                                                if (inst[15] == 'v') {
                                                                    if (inst.size() < 17) return 968;
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
                            if (inst[6] == 'x') {
                                if (inst.size() < 8) return instr_search_failed;
                                if (inst[7] == '.') {
                                    if (inst.size() < 9) return instr_search_failed;
                                    if (inst[8] == 'f') {
                                        if (inst.size() < 10) return instr_search_failed;
                                        if (inst[9] == '.') {
                                            if (inst.size() < 11) return instr_search_failed;
                                            if (inst[10] == 'v') {
                                                if (inst.size() < 12) return 967;
                                            }
                                        }
                                    }
                                }
                                if (inst[7] == 'u') {
                                    if (inst.size() < 9) return instr_search_failed;
                                    if (inst[8] == '.') {
                                        if (inst.size() < 10) return instr_search_failed;
                                        if (inst[9] == 'f') {
                                            if (inst.size() < 11) return instr_search_failed;
                                            if (inst[10] == '.') {
                                                if (inst.size() < 12) return instr_search_failed;
                                                if (inst[11] == 'v') {
                                                    if (inst.size() < 13) return 966;
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                            if (inst[6] == 'f') {
                                if (inst.size() < 8) return instr_search_failed;
                                if (inst[7] == '.') {
                                    if (inst.size() < 9) return instr_search_failed;
                                    if (inst[8] == 'x') {
                                        if (inst.size() < 10) return instr_search_failed;
                                        if (inst[9] == '.') {
                                            if (inst.size() < 11) return instr_search_failed;
                                            if (inst[10] == 'v') {
                                                if (inst.size() < 12) return 971;
                                            }
                                        }
                                        if (inst[9] == 'u') {
                                            if (inst.size() < 11) return instr_search_failed;
                                            if (inst[10] == '.') {
                                                if (inst.size() < 12) return instr_search_failed;
                                                if (inst[11] == 'v') {
                                                    if (inst.size() < 13) return 970;
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
            if (inst[2] == 's') {
                if (inst.size() < 4) return instr_search_failed;
                if (inst[3] == 'u') {
                    if (inst.size() < 5) return instr_search_failed;
                    if (inst[4] == 'b') {
                        if (inst.size() < 6) return instr_search_failed;
                        if (inst[5] == '.') {
                            if (inst.size() < 7) return instr_search_failed;
                            if (inst[6] == 'v') {
                                if (inst.size() < 8) return instr_search_failed;
                                if (inst[7] == 'v') {
                                    if (inst.size() < 9) return 906;
                                }
                                if (inst[7] == 'f') {
                                    if (inst.size() < 9) return 907;
                                }
                            }
                        }
                    }
                }
                if (inst[3] == 'q') {
                    if (inst.size() < 5) return instr_search_failed;
                    if (inst[4] == 'r') {
                        if (inst.size() < 6) return instr_search_failed;
                        if (inst[5] == 't') {
                            if (inst.size() < 7) return instr_search_failed;
                            if (inst[6] == '.') {
                                if (inst.size() < 8) return instr_search_failed;
                                if (inst[7] == 'v') {
                                    if (inst.size() < 9) return 940;
                                }
                            }
                        }
                    }
                }
                if (inst[3] == 'l') {
                    if (inst.size() < 5) return instr_search_failed;
                    if (inst[4] == 'i') {
                        if (inst.size() < 6) return instr_search_failed;
                        if (inst[5] == 'd') {
                            if (inst.size() < 7) return instr_search_failed;
                            if (inst[6] == 'e') {
                                if (inst.size() < 8) return instr_search_failed;
                                if (inst[7] == '1') {
                                    if (inst.size() < 9) return instr_search_failed;
                                    if (inst[8] == 'd') {
                                        if (inst.size() < 10) return instr_search_failed;
                                        if (inst[9] == 'o') {
                                            if (inst.size() < 11) return instr_search_failed;
                                            if (inst[10] == 'w') {
                                                if (inst.size() < 12) return instr_search_failed;
                                                if (inst[11] == 'n') {
                                                    if (inst.size() < 13) return instr_search_failed;
                                                    if (inst[12] == '.') {
                                                        if (inst.size() < 14) return instr_search_failed;
                                                        if (inst[13] == 'v') {
                                                            if (inst.size() < 15) return instr_search_failed;
                                                            if (inst[14] == 'f') {
                                                                if (inst.size() < 16) return 1029;
                                                            }
                                                        }
                                                    }
                                                }
                                            }
                                        }
                                    }
                                    if (inst[8] == 'u') {
                                        if (inst.size() < 10) return instr_search_failed;
                                        if (inst[9] == 'p') {
                                            if (inst.size() < 11) return instr_search_failed;
                                            if (inst[10] == '.') {
                                                if (inst.size() < 12) return instr_search_failed;
                                                if (inst[11] == 'v') {
                                                    if (inst.size() < 13) return instr_search_failed;
                                                    if (inst[12] == 'f') {
                                                        if (inst.size() < 14) return 1027;
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
                if (inst[3] == 'g') {
                    if (inst.size() < 5) return instr_search_failed;
                    if (inst[4] == 'n') {
                        if (inst.size() < 6) return instr_search_failed;
                        if (inst[5] == 'j') {
                            if (inst.size() < 7) return instr_search_failed;
                            if (inst[6] == '.') {
                                if (inst.size() < 8) return instr_search_failed;
                                if (inst[7] == 'v') {
                                    if (inst.size() < 9) return instr_search_failed;
                                    if (inst[8] == 'v') {
                                        if (inst.size() < 10) return 947;
                                    }
                                    if (inst[8] == 'f') {
                                        if (inst.size() < 10) return 948;
                                    }
                                }
                            }
                            if (inst[6] == 'n') {
                                if (inst.size() < 8) return instr_search_failed;
                                if (inst[7] == '.') {
                                    if (inst.size() < 9) return instr_search_failed;
                                    if (inst[8] == 'v') {
                                        if (inst.size() < 10) return instr_search_failed;
                                        if (inst[9] == 'v') {
                                            if (inst.size() < 11) return 949;
                                        }
                                        if (inst[9] == 'f') {
                                            if (inst.size() < 11) return 950;
                                        }
                                    }
                                }
                            }
                            if (inst[6] == 'x') {
                                if (inst.size() < 8) return instr_search_failed;
                                if (inst[7] == '.') {
                                    if (inst.size() < 9) return instr_search_failed;
                                    if (inst[8] == 'v') {
                                        if (inst.size() < 10) return instr_search_failed;
                                        if (inst[9] == 'v') {
                                            if (inst.size() < 11) return 951;
                                        }
                                        if (inst[9] == 'f') {
                                            if (inst.size() < 11) return 952;
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
    if (inst[0] == 'z') {
        if (inst.size() < 2) return instr_search_failed;
        if (inst[1] == 'i') {
            if (inst.size() < 3) return instr_search_failed;
            if (inst[2] == 'p') {
                if (inst.size() < 4) return 419;
            }
        }
        if (inst[1] == 'e') {
            if (inst.size() < 3) return instr_search_failed;
            if (inst[2] == 'x') {
                if (inst.size() < 4) return instr_search_failed;
                if (inst[3] == 't') {
                    if (inst.size() < 5) return instr_search_failed;
                    if (inst[4] == '.') {
                        if (inst.size() < 6) return instr_search_failed;
                        if (inst[5] == 'h') {
                            if (inst.size() < 7) return 418;
                        }
                    }
                }
            }
        }
    }
    if (inst[0] == 'f') {
        if (inst.size() < 2) return instr_search_failed;
        if (inst[1] == 'a') {
            if (inst.size() < 3) return instr_search_failed;
            if (inst[2] == 'd') {
                if (inst.size() < 4) return instr_search_failed;
                if (inst[3] == 'd') {
                    if (inst.size() < 5) return instr_search_failed;
                    if (inst[4] == '.') {
                        if (inst.size() < 6) return instr_search_failed;
                        if (inst[5] == 'd') {
                            if (inst.size() < 7) return 185;
                        }
                        if (inst[5] == 'q') {
                            if (inst.size() < 7) return 223;
                        }
                        if (inst[5] == 's') {
                            if (inst.size() < 7) return 159;
                        }
                        if (inst[5] == 'h') {
                            if (inst.size() < 7) return 255;
                        }
                    }
                }
            }
        }
        if (inst[1] == 'd') {
            if (inst.size() < 3) return instr_search_failed;
            if (inst[2] == 'i') {
                if (inst.size() < 4) return instr_search_failed;
                if (inst[3] == 'v') {
                    if (inst.size() < 5) return instr_search_failed;
                    if (inst[4] == '.') {
                        if (inst.size() < 6) return instr_search_failed;
                        if (inst[5] == 'd') {
                            if (inst.size() < 7) return 195;
                        }
                        if (inst[5] == 'q') {
                            if (inst.size() < 7) return 226;
                        }
                        if (inst[5] == 's') {
                            if (inst.size() < 7) return 162;
                        }
                        if (inst[5] == 'h') {
                            if (inst.size() < 7) return 258;
                        }
                    }
                }
            }
        }
        if (inst[1] == 'm') {
            if (inst.size() < 3) return instr_search_failed;
            if (inst[2] == 'a') {
                if (inst.size() < 4) return instr_search_failed;
                if (inst[3] == 'd') {
                    if (inst.size() < 5) return instr_search_failed;
                    if (inst[4] == 'd') {
                        if (inst.size() < 6) return instr_search_failed;
                        if (inst[5] == '.') {
                            if (inst.size() < 7) return instr_search_failed;
                            if (inst[6] == 'd') {
                                if (inst.size() < 8) return 186;
                            }
                            if (inst[6] == 'q') {
                                if (inst.size() < 8) return 219;
                            }
                            if (inst[6] == 's') {
                                if (inst.size() < 8) return 155;
                            }
                            if (inst[6] == 'h') {
                                if (inst.size() < 8) return 251;
                            }
                        }
                    }
                }
                if (inst[3] == 'x') {
                    if (inst.size() < 5) return instr_search_failed;
                    if (inst[4] == '.') {
                        if (inst.size() < 6) return instr_search_failed;
                        if (inst[5] == 'd') {
                            if (inst.size() < 7) return 187;
                        }
                        if (inst[5] == 'q') {
                            if (inst.size() < 7) return 232;
                        }
                        if (inst[5] == 's') {
                            if (inst.size() < 7) return 168;
                        }
                        if (inst[5] == 'h') {
                            if (inst.size() < 7) return 264;
                        }
                    }
                }
            }
            if (inst[2] == 'u') {
                if (inst.size() < 4) return instr_search_failed;
                if (inst[3] == 'l') {
                    if (inst.size() < 5) return instr_search_failed;
                    if (inst[4] == '.') {
                        if (inst.size() < 6) return instr_search_failed;
                        if (inst[5] == 'd') {
                            if (inst.size() < 7) return 202;
                        }
                        if (inst[5] == 'q') {
                            if (inst.size() < 7) return 225;
                        }
                        if (inst[5] == 's') {
                            if (inst.size() < 7) return 161;
                        }
                        if (inst[5] == 'h') {
                            if (inst.size() < 7) return 257;
                        }
                    }
                }
            }
            if (inst[2] == 'i') {
                if (inst.size() < 4) return instr_search_failed;
                if (inst[3] == 'n') {
                    if (inst.size() < 5) return instr_search_failed;
                    if (inst[4] == '.') {
                        if (inst.size() < 6) return instr_search_failed;
                        if (inst[5] == 'd') {
                            if (inst.size() < 7) return 200;
                        }
                        if (inst[5] == 'q') {
                            if (inst.size() < 7) return 231;
                        }
                        if (inst[5] == 's') {
                            if (inst.size() < 7) return 167;
                        }
                        if (inst[5] == 'h') {
                            if (inst.size() < 7) return 263;
                        }
                    }
                }
            }
            if (inst[2] == 's') {
                if (inst.size() < 4) return instr_search_failed;
                if (inst[3] == 'u') {
                    if (inst.size() < 5) return instr_search_failed;
                    if (inst[4] == 'b') {
                        if (inst.size() < 6) return instr_search_failed;
                        if (inst[5] == '.') {
                            if (inst.size() < 7) return instr_search_failed;
                            if (inst[6] == 'd') {
                                if (inst.size() < 8) return 201;
                            }
                            if (inst[6] == 'q') {
                                if (inst.size() < 8) return 220;
                            }
                            if (inst[6] == 's') {
                                if (inst.size() < 8) return 156;
                            }
                            if (inst[6] == 'h') {
                                if (inst.size() < 8) return 252;
                            }
                        }
                    }
                }
            }
            if (inst[2] == 'v') {
                if (inst.size() < 4) return instr_search_failed;
                if (inst[3] == '.') {
                    if (inst.size() < 5) return instr_search_failed;
                    if (inst[4] == 'd') {
                        if (inst.size() < 6) return instr_search_failed;
                        if (inst[5] == '.') {
                            if (inst.size() < 7) return instr_search_failed;
                            if (inst[6] == 'x') {
                                if (inst.size() < 8) return 216;
                            }
                        }
                    }
                    if (inst[4] == 'w') {
                        if (inst.size() < 6) return instr_search_failed;
                        if (inst[5] == '.') {
                            if (inst.size() < 7) return instr_search_failed;
                            if (inst[6] == 'x') {
                                if (inst.size() < 8) return 178;
                            }
                        }
                    }
                    if (inst[4] == 'x') {
                        if (inst.size() < 6) return instr_search_failed;
                        if (inst[5] == '.') {
                            if (inst.size() < 7) return instr_search_failed;
                            if (inst[6] == 'd') {
                                if (inst.size() < 8) return 213;
                            }
                            if (inst[6] == 'w') {
                                if (inst.size() < 8) return 171;
                            }
                            if (inst[6] == 'h') {
                                if (inst.size() < 8) return 277;
                            }
                        }
                    }
                    if (inst[4] == 'h') {
                        if (inst.size() < 6) return instr_search_failed;
                        if (inst[5] == '.') {
                            if (inst.size() < 7) return instr_search_failed;
                            if (inst[6] == 'x') {
                                if (inst.size() < 8) return 280;
                            }
                        }
                    }
                }
            }
        }
        if (inst[1] == 'l') {
            if (inst.size() < 3) return instr_search_failed;
            if (inst[2] == 'd') {
                if (inst.size() < 4) return 199;
            }
            if (inst[2] == 'w') {
                if (inst.size() < 4) return 179;
            }
            if (inst[2] == 'q') {
                if (inst.size() < 4) return 217;
            }
            if (inst[2] == 'e') {
                if (inst.size() < 4) return instr_search_failed;
                if (inst[3] == '.') {
                    if (inst.size() < 5) return instr_search_failed;
                    if (inst[4] == 'd') {
                        if (inst.size() < 6) return 198;
                    }
                    if (inst[4] == 'q') {
                        if (inst.size() < 6) return 239;
                    }
                    if (inst[4] == 's') {
                        if (inst.size() < 6) return 174;
                    }
                    if (inst[4] == 'h') {
                        if (inst.size() < 6) return 273;
                    }
                }
            }
            if (inst[2] == 't') {
                if (inst.size() < 4) return instr_search_failed;
                if (inst[3] == '.') {
                    if (inst.size() < 5) return instr_search_failed;
                    if (inst[4] == 'd') {
                        if (inst.size() < 6) return 197;
                    }
                    if (inst[4] == 'q') {
                        if (inst.size() < 6) return 238;
                    }
                    if (inst[4] == 's') {
                        if (inst.size() < 6) return 173;
                    }
                    if (inst[4] == 'h') {
                        if (inst.size() < 6) return 272;
                    }
                }
            }
            if (inst[2] == 'h') {
                if (inst.size() < 4) return 249;
            }
        }
        if (inst[1] == 'n') {
            if (inst.size() < 3) return instr_search_failed;
            if (inst[2] == 'm') {
                if (inst.size() < 4) return instr_search_failed;
                if (inst[3] == 'a') {
                    if (inst.size() < 5) return instr_search_failed;
                    if (inst[4] == 'd') {
                        if (inst.size() < 6) return instr_search_failed;
                        if (inst[5] == 'd') {
                            if (inst.size() < 7) return instr_search_failed;
                            if (inst[6] == '.') {
                                if (inst.size() < 8) return instr_search_failed;
                                if (inst[7] == 'd') {
                                    if (inst.size() < 9) return 203;
                                }
                                if (inst[7] == 'q') {
                                    if (inst.size() < 9) return 222;
                                }
                                if (inst[7] == 's') {
                                    if (inst.size() < 9) return 158;
                                }
                                if (inst[7] == 'h') {
                                    if (inst.size() < 9) return 254;
                                }
                            }
                        }
                    }
                }
                if (inst[3] == 's') {
                    if (inst.size() < 5) return instr_search_failed;
                    if (inst[4] == 'u') {
                        if (inst.size() < 6) return instr_search_failed;
                        if (inst[5] == 'b') {
                            if (inst.size() < 7) return instr_search_failed;
                            if (inst[6] == '.') {
                                if (inst.size() < 8) return instr_search_failed;
                                if (inst[7] == 'd') {
                                    if (inst.size() < 9) return 204;
                                }
                                if (inst[7] == 'q') {
                                    if (inst.size() < 9) return 221;
                                }
                                if (inst[7] == 's') {
                                    if (inst.size() < 9) return 157;
                                }
                                if (inst[7] == 'h') {
                                    if (inst.size() < 9) return 253;
                                }
                            }
                        }
                    }
                }
            }
        }
        if (inst[1] == 'c') {
            if (inst.size() < 3) return instr_search_failed;
            if (inst[2] == 'l') {
                if (inst.size() < 4) return instr_search_failed;
                if (inst[3] == 'a') {
                    if (inst.size() < 5) return instr_search_failed;
                    if (inst[4] == 's') {
                        if (inst.size() < 6) return instr_search_failed;
                        if (inst[5] == 's') {
                            if (inst.size() < 7) return instr_search_failed;
                            if (inst[6] == '.') {
                                if (inst.size() < 8) return instr_search_failed;
                                if (inst[7] == 'd') {
                                    if (inst.size() < 9) return 188;
                                }
                                if (inst[7] == 'q') {
                                    if (inst.size() < 9) return 240;
                                }
                                if (inst[7] == 's') {
                                    if (inst.size() < 9) return 175;
                                }
                                if (inst[7] == 'h') {
                                    if (inst.size() < 9) return 274;
                                }
                            }
                        }
                    }
                }
            }
            if (inst[2] == 'v') {
                if (inst.size() < 4) return instr_search_failed;
                if (inst[3] == 't') {
                    if (inst.size() < 5) return instr_search_failed;
                    if (inst[4] == '.') {
                        if (inst.size() < 6) return instr_search_failed;
                        if (inst[5] == 'd') {
                            if (inst.size() < 7) return instr_search_failed;
                            if (inst[6] == '.') {
                                if (inst.size() < 8) return instr_search_failed;
                                if (inst[7] == 'w') {
                                    if (inst.size() < 9) return 190;
                                    if (inst[8] == 'u') {
                                        if (inst.size() < 10) return 191;
                                    }
                                }
                                if (inst[7] == 'q') {
                                    if (inst.size() < 9) return 235;
                                }
                                if (inst[7] == 'l') {
                                    if (inst.size() < 9) return 214;
                                    if (inst[8] == 'u') {
                                        if (inst.size() < 10) return 215;
                                    }
                                }
                                if (inst[7] == 's') {
                                    if (inst.size() < 9) return 189;
                                }
                                if (inst[7] == 'h') {
                                    if (inst.size() < 9) return 267;
                                }
                            }
                        }
                        if (inst[5] == 'w') {
                            if (inst.size() < 7) return instr_search_failed;
                            if (inst[6] == '.') {
                                if (inst.size() < 8) return instr_search_failed;
                                if (inst[7] == 'd') {
                                    if (inst.size() < 9) return 193;
                                }
                                if (inst[7] == 'q') {
                                    if (inst.size() < 9) return 241;
                                }
                                if (inst[7] == 's') {
                                    if (inst.size() < 9) return 169;
                                }
                                if (inst[7] == 'h') {
                                    if (inst.size() < 9) return 275;
                                }
                            }
                            if (inst[6] == 'u') {
                                if (inst.size() < 8) return instr_search_failed;
                                if (inst[7] == '.') {
                                    if (inst.size() < 9) return instr_search_failed;
                                    if (inst[8] == 'd') {
                                        if (inst.size() < 10) return 194;
                                    }
                                    if (inst[8] == 'q') {
                                        if (inst.size() < 10) return 242;
                                    }
                                    if (inst[8] == 's') {
                                        if (inst.size() < 10) return 170;
                                    }
                                    if (inst[8] == 'h') {
                                        if (inst.size() < 10) return 276;
                                    }
                                }
                            }
                        }
                        if (inst[5] == 'q') {
                            if (inst.size() < 7) return instr_search_failed;
                            if (inst[6] == '.') {
                                if (inst.size() < 8) return instr_search_failed;
                                if (inst[7] == 'd') {
                                    if (inst.size() < 9) return 236;
                                }
                                if (inst[7] == 'w') {
                                    if (inst.size() < 9) return 243;
                                    if (inst[8] == 'u') {
                                        if (inst.size() < 10) return 244;
                                    }
                                }
                                if (inst[7] == 'l') {
                                    if (inst.size() < 9) return 247;
                                    if (inst[8] == 'u') {
                                        if (inst.size() < 10) return 248;
                                    }
                                }
                                if (inst[7] == 's') {
                                    if (inst.size() < 9) return 234;
                                }
                                if (inst[7] == 'h') {
                                    if (inst.size() < 9) return 269;
                                }
                            }
                        }
                        if (inst[5] == 'l') {
                            if (inst.size() < 7) return instr_search_failed;
                            if (inst[6] == '.') {
                                if (inst.size() < 8) return instr_search_failed;
                                if (inst[7] == 'd') {
                                    if (inst.size() < 9) return 211;
                                }
                                if (inst[7] == 'q') {
                                    if (inst.size() < 9) return 245;
                                }
                                if (inst[7] == 's') {
                                    if (inst.size() < 9) return 181;
                                }
                                if (inst[7] == 'h') {
                                    if (inst.size() < 9) return 281;
                                }
                            }
                            if (inst[6] == 'u') {
                                if (inst.size() < 8) return instr_search_failed;
                                if (inst[7] == '.') {
                                    if (inst.size() < 9) return instr_search_failed;
                                    if (inst[8] == 'd') {
                                        if (inst.size() < 10) return 212;
                                    }
                                    if (inst[8] == 'q') {
                                        if (inst.size() < 10) return 246;
                                    }
                                    if (inst[8] == 's') {
                                        if (inst.size() < 10) return 182;
                                    }
                                    if (inst[8] == 'h') {
                                        if (inst.size() < 10) return 282;
                                    }
                                }
                            }
                        }
                        if (inst[5] == 's') {
                            if (inst.size() < 7) return instr_search_failed;
                            if (inst[6] == '.') {
                                if (inst.size() < 8) return instr_search_failed;
                                if (inst[7] == 'd') {
                                    if (inst.size() < 9) return 192;
                                }
                                if (inst[7] == 'w') {
                                    if (inst.size() < 9) return 176;
                                    if (inst[8] == 'u') {
                                        if (inst.size() < 10) return 177;
                                    }
                                }
                                if (inst[7] == 'q') {
                                    if (inst.size() < 9) return 233;
                                }
                                if (inst[7] == 'l') {
                                    if (inst.size() < 9) return 183;
                                    if (inst[8] == 'u') {
                                        if (inst.size() < 10) return 184;
                                    }
                                }
                                if (inst[7] == 'h') {
                                    if (inst.size() < 9) return 265;
                                }
                            }
                        }
                        if (inst[5] == 'h') {
                            if (inst.size() < 7) return instr_search_failed;
                            if (inst[6] == '.') {
                                if (inst.size() < 8) return instr_search_failed;
                                if (inst[7] == 'd') {
                                    if (inst.size() < 9) return 268;
                                }
                                if (inst[7] == 'w') {
                                    if (inst.size() < 9) return 278;
                                    if (inst[8] == 'u') {
                                        if (inst.size() < 10) return 279;
                                    }
                                }
                                if (inst[7] == 'q') {
                                    if (inst.size() < 9) return 270;
                                }
                                if (inst[7] == 'l') {
                                    if (inst.size() < 9) return 283;
                                    if (inst[8] == 'u') {
                                        if (inst.size() < 10) return 284;
                                    }
                                }
                                if (inst[7] == 's') {
                                    if (inst.size() < 9) return 266;
                                }
                            }
                        }
                    }
                }
            }
        }
        if (inst[1] == 's') {
            if (inst.size() < 3) return instr_search_failed;
            if (inst[2] == 'd') {
                if (inst.size() < 4) return 205;
            }
            if (inst[2] == 'u') {
                if (inst.size() < 4) return instr_search_failed;
                if (inst[3] == 'b') {
                    if (inst.size() < 5) return instr_search_failed;
                    if (inst[4] == '.') {
                        if (inst.size() < 6) return instr_search_failed;
                        if (inst[5] == 'd') {
                            if (inst.size() < 7) return 210;
                        }
                        if (inst[5] == 'q') {
                            if (inst.size() < 7) return 224;
                        }
                        if (inst[5] == 's') {
                            if (inst.size() < 7) return 160;
                        }
                        if (inst[5] == 'h') {
                            if (inst.size() < 7) return 256;
                        }
                    }
                }
            }
            if (inst[2] == 'w') {
                if (inst.size() < 4) return 180;
            }
            if (inst[2] == 'q') {
                if (inst.size() < 4) return 218;
                if (inst[3] == 'r') {
                    if (inst.size() < 5) return instr_search_failed;
                    if (inst[4] == 't') {
                        if (inst.size() < 6) return instr_search_failed;
                        if (inst[5] == '.') {
                            if (inst.size() < 7) return instr_search_failed;
                            if (inst[6] == 'd') {
                                if (inst.size() < 8) return 209;
                            }
                            if (inst[6] == 'q') {
                                if (inst.size() < 8) return 227;
                            }
                            if (inst[6] == 's') {
                                if (inst.size() < 8) return 163;
                            }
                            if (inst[6] == 'h') {
                                if (inst.size() < 8) return 259;
                            }
                        }
                    }
                }
            }
            if (inst[2] == 'g') {
                if (inst.size() < 4) return instr_search_failed;
                if (inst[3] == 'n') {
                    if (inst.size() < 5) return instr_search_failed;
                    if (inst[4] == 'j') {
                        if (inst.size() < 6) return instr_search_failed;
                        if (inst[5] == '.') {
                            if (inst.size() < 7) return instr_search_failed;
                            if (inst[6] == 'd') {
                                if (inst.size() < 8) return 206;
                            }
                            if (inst[6] == 'q') {
                                if (inst.size() < 8) return 228;
                            }
                            if (inst[6] == 's') {
                                if (inst.size() < 8) return 164;
                            }
                            if (inst[6] == 'h') {
                                if (inst.size() < 8) return 260;
                            }
                        }
                        if (inst[5] == 'n') {
                            if (inst.size() < 7) return instr_search_failed;
                            if (inst[6] == '.') {
                                if (inst.size() < 8) return instr_search_failed;
                                if (inst[7] == 'd') {
                                    if (inst.size() < 9) return 207;
                                }
                                if (inst[7] == 'q') {
                                    if (inst.size() < 9) return 229;
                                }
                                if (inst[7] == 's') {
                                    if (inst.size() < 9) return 165;
                                }
                                if (inst[7] == 'h') {
                                    if (inst.size() < 9) return 261;
                                }
                            }
                        }
                        if (inst[5] == 'x') {
                            if (inst.size() < 7) return instr_search_failed;
                            if (inst[6] == '.') {
                                if (inst.size() < 8) return instr_search_failed;
                                if (inst[7] == 'd') {
                                    if (inst.size() < 9) return 208;
                                }
                                if (inst[7] == 'q') {
                                    if (inst.size() < 9) return 230;
                                }
                                if (inst[7] == 's') {
                                    if (inst.size() < 9) return 166;
                                }
                                if (inst[7] == 'h') {
                                    if (inst.size() < 9) return 262;
                                }
                            }
                        }
                    }
                }
            }
            if (inst[2] == 'h') {
                if (inst.size() < 4) return 250;
            }
        }
        if (inst[1] == 'e') {
            if (inst.size() < 3) return instr_search_failed;
            if (inst[2] == 'q') {
                if (inst.size() < 4) return instr_search_failed;
                if (inst[3] == '.') {
                    if (inst.size() < 5) return instr_search_failed;
                    if (inst[4] == 'd') {
                        if (inst.size() < 6) return 196;
                    }
                    if (inst[4] == 'q') {
                        if (inst.size() < 6) return 237;
                    }
                    if (inst[4] == 's') {
                        if (inst.size() < 6) return 172;
                    }
                    if (inst[4] == 'h') {
                        if (inst.size() < 6) return 271;
                    }
                }
            }
            if (inst[2] == 'n') {
                if (inst.size() < 4) return instr_search_failed;
                if (inst[3] == 'c') {
                    if (inst.size() < 5) return instr_search_failed;
                    if (inst[4] == 'e') {
                        if (inst.size() < 6) return 37;
                        if (inst[5] == '.') {
                            if (inst.size() < 7) return instr_search_failed;
                            if (inst[6] == 'i') {
                                if (inst.size() < 8) return 285;
                            }
                            if (inst[6] == 't') {
                                if (inst.size() < 8) return instr_search_failed;
                                if (inst[7] == 's') {
                                    if (inst.size() < 9) return instr_search_failed;
                                    if (inst[8] == 'o') {
                                        if (inst.size() < 10) return 38;
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    if (inst[0] == 'j') {
        if (inst.size() < 2) return instr_search_failed;
        if (inst[1] == 'a') {
            if (inst.size() < 3) return instr_search_failed;
            if (inst[2] == 'l') {
                if (inst.size() < 4) return 2;
                if (inst[3] == 'r') {
                    if (inst.size() < 5) return 3;
                }
            }
        }
    }
    return instr_search_failed;
}

} // namespace libchata_internal