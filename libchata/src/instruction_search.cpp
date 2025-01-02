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