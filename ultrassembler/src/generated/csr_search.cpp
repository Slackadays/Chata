// SPDX-License-Identifier: MPL-2.0
// The generate_csrister_search.py script automatically generated this code. DO NOT MODIFY!
#include "../csrs.hpp"
#include "../ultrassembler.hpp"

namespace ultrassembler_internal {

const uint16_t fast_csr_search(const ultrastring& csr) {
    if (csr.size() < 1) return csr_search_failed;
    if (csr[0] == 'c') {
        if (csr.size() < 2) return csr_search_failed;
        if (csr[1] == 'y') {
            if (csr.size() < 3) return csr_search_failed;
            if (csr[2] == 'c') {
                if (csr.size() < 4) return csr_search_failed;
                if (csr[3] == 'l') {
                    if (csr.size() < 5) return csr_search_failed;
                    if (csr[4] == 'e') {
                        if (csr.size() < 6) return 17;
                        if (csr[5] == 'h') {
                            if (csr.size() < 7) return 49;
                        }
                    }
                }
            }
        }
    }
    if (csr[0] == 'h') {
        if (csr.size() < 2) return csr_search_failed;
        if (csr[1] == 'c') {
            if (csr.size() < 3) return csr_search_failed;
            if (csr[2] == 'o') {
                if (csr.size() < 4) return csr_search_failed;
                if (csr[3] == 'n') {
                    if (csr.size() < 5) return csr_search_failed;
                    if (csr[4] == 't') {
                        if (csr.size() < 6) return csr_search_failed;
                        if (csr[5] == 'e') {
                            if (csr.size() < 7) return csr_search_failed;
                            if (csr[6] == 'x') {
                                if (csr.size() < 8) return csr_search_failed;
                                if (csr[7] == 't') {
                                    if (csr.size() < 9) return 114;
                                }
                            }
                        }
                    }
                }
                if (csr[3] == 'u') {
                    if (csr.size() < 5) return csr_search_failed;
                    if (csr[4] == 'n') {
                        if (csr.size() < 6) return csr_search_failed;
                        if (csr[5] == 't') {
                            if (csr.size() < 7) return csr_search_failed;
                            if (csr[6] == 'e') {
                                if (csr.size() < 8) return csr_search_failed;
                                if (csr[7] == 'r') {
                                    if (csr.size() < 9) return csr_search_failed;
                                    if (csr[8] == 'e') {
                                        if (csr.size() < 10) return csr_search_failed;
                                        if (csr[9] == 'n') {
                                            if (csr.size() < 11) return 103;
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
        if (csr[1] == 'e') {
            if (csr.size() < 3) return csr_search_failed;
            if (csr[2] == 'd') {
                if (csr.size() < 4) return csr_search_failed;
                if (csr[3] == 'e') {
                    if (csr.size() < 5) return csr_search_failed;
                    if (csr[4] == 'l') {
                        if (csr.size() < 6) return csr_search_failed;
                        if (csr[5] == 'e') {
                            if (csr.size() < 7) return csr_search_failed;
                            if (csr[6] == 'g') {
                                if (csr.size() < 8) return 100;
                                if (csr[7] == 'h') {
                                    if (csr.size() < 9) return 105;
                                }
                            }
                        }
                    }
                }
            }
            if (csr[2] == 'n') {
                if (csr.size() < 4) return csr_search_failed;
                if (csr[3] == 'v') {
                    if (csr.size() < 5) return csr_search_failed;
                    if (csr[4] == 'c') {
                        if (csr.size() < 6) return csr_search_failed;
                        if (csr[5] == 'f') {
                            if (csr.size() < 7) return csr_search_failed;
                            if (csr[6] == 'g') {
                                if (csr.size() < 8) return 111;
                                if (csr[7] == 'h') {
                                    if (csr.size() < 9) return 112;
                                }
                            }
                        }
                    }
                }
            }
        }
        if (csr[1] == 's') {
            if (csr.size() < 3) return csr_search_failed;
            if (csr[2] == 't') {
                if (csr.size() < 4) return csr_search_failed;
                if (csr[3] == 'a') {
                    if (csr.size() < 5) return csr_search_failed;
                    if (csr[4] == 't') {
                        if (csr.size() < 6) return csr_search_failed;
                        if (csr[5] == 'e') {
                            if (csr.size() < 7) return csr_search_failed;
                            if (csr[6] == 'e') {
                                if (csr.size() < 8) return csr_search_failed;
                                if (csr[7] == 'n') {
                                    if (csr.size() < 9) return csr_search_failed;
                                    if (csr[8] == '0') {
                                        if (csr.size() < 10) return 117;
                                        if (csr[9] == 'h') {
                                            if (csr.size() < 11) return 121;
                                        }
                                    }
                                    if (csr[8] == '1') {
                                        if (csr.size() < 10) return 118;
                                        if (csr[9] == 'h') {
                                            if (csr.size() < 11) return 122;
                                        }
                                    }
                                    if (csr[8] == '2') {
                                        if (csr.size() < 10) return 119;
                                        if (csr[9] == 'h') {
                                            if (csr.size() < 11) return 123;
                                        }
                                    }
                                    if (csr[8] == '3') {
                                        if (csr.size() < 10) return 120;
                                        if (csr[9] == 'h') {
                                            if (csr.size() < 11) return 124;
                                        }
                                    }
                                }
                            }
                        }
                        if (csr[5] == 'u') {
                            if (csr.size() < 7) return csr_search_failed;
                            if (csr[6] == 's') {
                                if (csr.size() < 8) return 99;
                            }
                        }
                    }
                }
            }
        }
        if (csr[1] == 'p') {
            if (csr.size() < 3) return csr_search_failed;
            if (csr[2] == 'm') {
                if (csr.size() < 4) return csr_search_failed;
                if (csr[3] == 'c') {
                    if (csr.size() < 5) return csr_search_failed;
                    if (csr[4] == 'o') {
                        if (csr.size() < 6) return csr_search_failed;
                        if (csr[5] == 'u') {
                            if (csr.size() < 7) return csr_search_failed;
                            if (csr[6] == 'n') {
                                if (csr.size() < 8) return csr_search_failed;
                                if (csr[7] == 't') {
                                    if (csr.size() < 9) return csr_search_failed;
                                    if (csr[8] == 'e') {
                                        if (csr.size() < 10) return csr_search_failed;
                                        if (csr[9] == 'r') {
                                            if (csr.size() < 11) return csr_search_failed;
                                            if (csr[10] == '1') {
                                                if (csr.size() < 12) return csr_search_failed;
                                                if (csr[11] == '0') {
                                                    if (csr.size() < 13) return 27;
                                                    if (csr[12] == 'h') {
                                                        if (csr.size() < 14) return 59;
                                                    }
                                                }
                                                if (csr[11] == '1') {
                                                    if (csr.size() < 13) return 28;
                                                    if (csr[12] == 'h') {
                                                        if (csr.size() < 14) return 60;
                                                    }
                                                }
                                                if (csr[11] == '2') {
                                                    if (csr.size() < 13) return 29;
                                                    if (csr[12] == 'h') {
                                                        if (csr.size() < 14) return 61;
                                                    }
                                                }
                                                if (csr[11] == '3') {
                                                    if (csr.size() < 13) return 30;
                                                    if (csr[12] == 'h') {
                                                        if (csr.size() < 14) return 62;
                                                    }
                                                }
                                                if (csr[11] == '4') {
                                                    if (csr.size() < 13) return 31;
                                                    if (csr[12] == 'h') {
                                                        if (csr.size() < 14) return 63;
                                                    }
                                                }
                                                if (csr[11] == '5') {
                                                    if (csr.size() < 13) return 32;
                                                    if (csr[12] == 'h') {
                                                        if (csr.size() < 14) return 64;
                                                    }
                                                }
                                                if (csr[11] == '6') {
                                                    if (csr.size() < 13) return 33;
                                                    if (csr[12] == 'h') {
                                                        if (csr.size() < 14) return 65;
                                                    }
                                                }
                                                if (csr[11] == '7') {
                                                    if (csr.size() < 13) return 34;
                                                    if (csr[12] == 'h') {
                                                        if (csr.size() < 14) return 66;
                                                    }
                                                }
                                                if (csr[11] == '8') {
                                                    if (csr.size() < 13) return 35;
                                                    if (csr[12] == 'h') {
                                                        if (csr.size() < 14) return 67;
                                                    }
                                                }
                                                if (csr[11] == '9') {
                                                    if (csr.size() < 13) return 36;
                                                    if (csr[12] == 'h') {
                                                        if (csr.size() < 14) return 68;
                                                    }
                                                }
                                            }
                                            if (csr[10] == '2') {
                                                if (csr.size() < 12) return csr_search_failed;
                                                if (csr[11] == '0') {
                                                    if (csr.size() < 13) return 37;
                                                    if (csr[12] == 'h') {
                                                        if (csr.size() < 14) return 69;
                                                    }
                                                }
                                                if (csr[11] == '1') {
                                                    if (csr.size() < 13) return 38;
                                                    if (csr[12] == 'h') {
                                                        if (csr.size() < 14) return 70;
                                                    }
                                                }
                                                if (csr[11] == '2') {
                                                    if (csr.size() < 13) return 39;
                                                    if (csr[12] == 'h') {
                                                        if (csr.size() < 14) return 71;
                                                    }
                                                }
                                                if (csr[11] == '3') {
                                                    if (csr.size() < 13) return 40;
                                                    if (csr[12] == 'h') {
                                                        if (csr.size() < 14) return 72;
                                                    }
                                                }
                                                if (csr[11] == '4') {
                                                    if (csr.size() < 13) return 41;
                                                    if (csr[12] == 'h') {
                                                        if (csr.size() < 14) return 73;
                                                    }
                                                }
                                                if (csr[11] == '5') {
                                                    if (csr.size() < 13) return 42;
                                                    if (csr[12] == 'h') {
                                                        if (csr.size() < 14) return 74;
                                                    }
                                                }
                                                if (csr[11] == '6') {
                                                    if (csr.size() < 13) return 43;
                                                    if (csr[12] == 'h') {
                                                        if (csr.size() < 14) return 75;
                                                    }
                                                }
                                                if (csr[11] == '7') {
                                                    if (csr.size() < 13) return 44;
                                                    if (csr[12] == 'h') {
                                                        if (csr.size() < 14) return 76;
                                                    }
                                                }
                                                if (csr[11] == '8') {
                                                    if (csr.size() < 13) return 45;
                                                    if (csr[12] == 'h') {
                                                        if (csr.size() < 14) return 77;
                                                    }
                                                }
                                                if (csr[11] == '9') {
                                                    if (csr.size() < 13) return 46;
                                                    if (csr[12] == 'h') {
                                                        if (csr.size() < 14) return 78;
                                                    }
                                                }
                                            }
                                            if (csr[10] == '3') {
                                                if (csr.size() < 12) return 20;
                                                if (csr[11] == 'h') {
                                                    if (csr.size() < 13) return 52;
                                                }
                                                if (csr[11] == '0') {
                                                    if (csr.size() < 13) return 47;
                                                    if (csr[12] == 'h') {
                                                        if (csr.size() < 14) return 79;
                                                    }
                                                }
                                                if (csr[11] == '1') {
                                                    if (csr.size() < 13) return 48;
                                                    if (csr[12] == 'h') {
                                                        if (csr.size() < 14) return 80;
                                                    }
                                                }
                                            }
                                            if (csr[10] == '4') {
                                                if (csr.size() < 12) return 21;
                                                if (csr[11] == 'h') {
                                                    if (csr.size() < 13) return 53;
                                                }
                                            }
                                            if (csr[10] == '5') {
                                                if (csr.size() < 12) return 22;
                                                if (csr[11] == 'h') {
                                                    if (csr.size() < 13) return 54;
                                                }
                                            }
                                            if (csr[10] == '6') {
                                                if (csr.size() < 12) return 23;
                                                if (csr[11] == 'h') {
                                                    if (csr.size() < 13) return 55;
                                                }
                                            }
                                            if (csr[10] == '7') {
                                                if (csr.size() < 12) return 24;
                                                if (csr[11] == 'h') {
                                                    if (csr.size() < 13) return 56;
                                                }
                                            }
                                            if (csr[10] == '8') {
                                                if (csr.size() < 12) return 25;
                                                if (csr[11] == 'h') {
                                                    if (csr.size() < 13) return 57;
                                                }
                                            }
                                            if (csr[10] == '9') {
                                                if (csr.size() < 12) return 26;
                                                if (csr[11] == 'h') {
                                                    if (csr.size() < 13) return 58;
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
        if (csr[1] == 't') {
            if (csr.size() < 3) return csr_search_failed;
            if (csr[2] == 'v') {
                if (csr.size() < 4) return csr_search_failed;
                if (csr[3] == 'a') {
                    if (csr.size() < 5) return csr_search_failed;
                    if (csr[4] == 'l') {
                        if (csr.size() < 6) return 106;
                    }
                }
            }
            if (csr[2] == 'i') {
                if (csr.size() < 4) return csr_search_failed;
                if (csr[3] == 'm') {
                    if (csr.size() < 5) return csr_search_failed;
                    if (csr[4] == 'e') {
                        if (csr.size() < 6) return csr_search_failed;
                        if (csr[5] == 'd') {
                            if (csr.size() < 7) return csr_search_failed;
                            if (csr[6] == 'e') {
                                if (csr.size() < 8) return csr_search_failed;
                                if (csr[7] == 'l') {
                                    if (csr.size() < 9) return csr_search_failed;
                                    if (csr[8] == 't') {
                                        if (csr.size() < 10) return csr_search_failed;
                                        if (csr[9] == 'a') {
                                            if (csr.size() < 11) return 115;
                                            if (csr[10] == 'h') {
                                                if (csr.size() < 12) return 116;
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
                if (csr[3] == 'n') {
                    if (csr.size() < 5) return csr_search_failed;
                    if (csr[4] == 's') {
                        if (csr.size() < 6) return csr_search_failed;
                        if (csr[5] == 't') {
                            if (csr.size() < 7) return 109;
                        }
                    }
                }
            }
        }
        if (csr[1] == 'g') {
            if (csr.size() < 3) return csr_search_failed;
            if (csr[2] == 'e') {
                if (csr.size() < 4) return csr_search_failed;
                if (csr[3] == 'i') {
                    if (csr.size() < 5) return csr_search_failed;
                    if (csr[4] == 'e') {
                        if (csr.size() < 6) return 104;
                    }
                    if (csr[4] == 'p') {
                        if (csr.size() < 6) return 110;
                    }
                }
            }
            if (csr[2] == 'a') {
                if (csr.size() < 4) return csr_search_failed;
                if (csr[3] == 't') {
                    if (csr.size() < 5) return csr_search_failed;
                    if (csr[4] == 'p') {
                        if (csr.size() < 6) return 113;
                    }
                }
            }
        }
        if (csr[1] == 'v') {
            if (csr.size() < 3) return csr_search_failed;
            if (csr[2] == 'i') {
                if (csr.size() < 4) return csr_search_failed;
                if (csr[3] == 'p') {
                    if (csr.size() < 5) return 108;
                }
            }
        }
        if (csr[1] == 'i') {
            if (csr.size() < 3) return csr_search_failed;
            if (csr[2] == 'e') {
                if (csr.size() < 4) return 102;
            }
            if (csr[2] == 'd') {
                if (csr.size() < 4) return csr_search_failed;
                if (csr[3] == 'e') {
                    if (csr.size() < 5) return csr_search_failed;
                    if (csr[4] == 'l') {
                        if (csr.size() < 6) return csr_search_failed;
                        if (csr[5] == 'e') {
                            if (csr.size() < 7) return csr_search_failed;
                            if (csr[6] == 'g') {
                                if (csr.size() < 8) return 101;
                            }
                        }
                    }
                }
            }
            if (csr[2] == 'p') {
                if (csr.size() < 4) return 107;
            }
        }
    }
    if (csr[0] == 'd') {
        if (csr.size() < 2) return csr_search_failed;
        if (csr[1] == 'c') {
            if (csr.size() < 3) return csr_search_failed;
            if (csr[2] == 's') {
                if (csr.size() < 4) return csr_search_failed;
                if (csr[3] == 'r') {
                    if (csr.size() < 5) return 377;
                }
            }
        }
        if (csr[1] == 's') {
            if (csr.size() < 3) return csr_search_failed;
            if (csr[2] == 'c') {
                if (csr.size() < 4) return csr_search_failed;
                if (csr[3] == 'r') {
                    if (csr.size() < 5) return csr_search_failed;
                    if (csr[4] == 'a') {
                        if (csr.size() < 6) return csr_search_failed;
                        if (csr[5] == 't') {
                            if (csr.size() < 7) return csr_search_failed;
                            if (csr[6] == 'c') {
                                if (csr.size() < 8) return csr_search_failed;
                                if (csr[7] == 'h') {
                                    if (csr.size() < 9) return csr_search_failed;
                                    if (csr[8] == '0') {
                                        if (csr.size() < 10) return 379;
                                    }
                                    if (csr[8] == '1') {
                                        if (csr.size() < 10) return 380;
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
        if (csr[1] == 'p') {
            if (csr.size() < 3) return csr_search_failed;
            if (csr[2] == 'c') {
                if (csr.size() < 4) return 378;
            }
        }
    }
    if (csr[0] == 's') {
        if (csr.size() < 2) return csr_search_failed;
        if (csr[1] == 'c') {
            if (csr.size() < 3) return csr_search_failed;
            if (csr[2] == 'a') {
                if (csr.size() < 4) return csr_search_failed;
                if (csr[3] == 'u') {
                    if (csr.size() < 5) return csr_search_failed;
                    if (csr[4] == 's') {
                        if (csr.size() < 6) return csr_search_failed;
                        if (csr[5] == 'e') {
                            if (csr.size() < 7) return 89;
                        }
                    }
                }
            }
            if (csr[2] == 'o') {
                if (csr.size() < 4) return csr_search_failed;
                if (csr[3] == 'n') {
                    if (csr.size() < 5) return csr_search_failed;
                    if (csr[4] == 't') {
                        if (csr.size() < 6) return csr_search_failed;
                        if (csr[5] == 'e') {
                            if (csr.size() < 7) return csr_search_failed;
                            if (csr[6] == 'x') {
                                if (csr.size() < 8) return csr_search_failed;
                                if (csr[7] == 't') {
                                    if (csr.size() < 9) return 94;
                                }
                            }
                        }
                    }
                }
                if (csr[3] == 'u') {
                    if (csr.size() < 5) return csr_search_failed;
                    if (csr[4] == 'n') {
                        if (csr.size() < 6) return csr_search_failed;
                        if (csr[5] == 't') {
                            if (csr.size() < 7) return csr_search_failed;
                            if (csr[6] == 'e') {
                                if (csr.size() < 8) return csr_search_failed;
                                if (csr[7] == 'r') {
                                    if (csr.size() < 9) return csr_search_failed;
                                    if (csr[8] == 'e') {
                                        if (csr.size() < 10) return csr_search_failed;
                                        if (csr[9] == 'n') {
                                            if (csr.size() < 11) return 84;
                                        }
                                    }
                                }
                            }
                            if (csr[6] == 'o') {
                                if (csr.size() < 8) return csr_search_failed;
                                if (csr[7] == 'v') {
                                    if (csr.size() < 9) return csr_search_failed;
                                    if (csr[8] == 'f') {
                                        if (csr.size() < 10) return 92;
                                    }
                                }
                            }
                            if (csr[6] == 'i') {
                                if (csr.size() < 8) return csr_search_failed;
                                if (csr[7] == 'n') {
                                    if (csr.size() < 9) return csr_search_failed;
                                    if (csr[8] == 'h') {
                                        if (csr.size() < 10) return csr_search_failed;
                                        if (csr[9] == 'i') {
                                            if (csr.size() < 11) return csr_search_failed;
                                            if (csr[10] == 'b') {
                                                if (csr.size() < 12) return csr_search_failed;
                                                if (csr[11] == 'i') {
                                                    if (csr.size() < 13) return csr_search_failed;
                                                    if (csr[12] == 't') {
                                                        if (csr.size() < 14) return 86;
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
        if (csr[1] == 'e') {
            if (csr.size() < 3) return csr_search_failed;
            if (csr[2] == 'p') {
                if (csr.size() < 4) return csr_search_failed;
                if (csr[3] == 'c') {
                    if (csr.size() < 5) return 88;
                }
            }
            if (csr[2] == 'n') {
                if (csr.size() < 4) return csr_search_failed;
                if (csr[3] == 'v') {
                    if (csr.size() < 5) return csr_search_failed;
                    if (csr[4] == 'c') {
                        if (csr.size() < 6) return csr_search_failed;
                        if (csr[5] == 'f') {
                            if (csr.size() < 7) return csr_search_failed;
                            if (csr[6] == 'g') {
                                if (csr.size() < 8) return 85;
                            }
                        }
                    }
                }
            }
        }
        if (csr[1] == 's') {
            if (csr.size() < 3) return csr_search_failed;
            if (csr[2] == 'c') {
                if (csr.size() < 4) return csr_search_failed;
                if (csr[3] == 'r') {
                    if (csr.size() < 5) return csr_search_failed;
                    if (csr[4] == 'a') {
                        if (csr.size() < 6) return csr_search_failed;
                        if (csr[5] == 't') {
                            if (csr.size() < 7) return csr_search_failed;
                            if (csr[6] == 'c') {
                                if (csr.size() < 8) return csr_search_failed;
                                if (csr[7] == 'h') {
                                    if (csr.size() < 9) return 87;
                                }
                            }
                        }
                    }
                }
            }
            if (csr[2] == 'p') {
                if (csr.size() < 4) return 15;
            }
            if (csr[2] == 't') {
                if (csr.size() < 4) return csr_search_failed;
                if (csr[3] == 'a') {
                    if (csr.size() < 5) return csr_search_failed;
                    if (csr[4] == 't') {
                        if (csr.size() < 6) return csr_search_failed;
                        if (csr[5] == 'e') {
                            if (csr.size() < 7) return csr_search_failed;
                            if (csr[6] == 'e') {
                                if (csr.size() < 8) return csr_search_failed;
                                if (csr[7] == 'n') {
                                    if (csr.size() < 9) return csr_search_failed;
                                    if (csr[8] == '0') {
                                        if (csr.size() < 10) return 95;
                                    }
                                    if (csr[8] == '1') {
                                        if (csr.size() < 10) return 96;
                                    }
                                    if (csr[8] == '2') {
                                        if (csr.size() < 10) return 97;
                                    }
                                    if (csr[8] == '3') {
                                        if (csr.size() < 10) return 98;
                                    }
                                }
                            }
                        }
                        if (csr[5] == 'u') {
                            if (csr.size() < 7) return csr_search_failed;
                            if (csr[6] == 's') {
                                if (csr.size() < 8) return 81;
                            }
                        }
                    }
                }
            }
        }
        if (csr[1] == 'a') {
            if (csr.size() < 3) return csr_search_failed;
            if (csr[2] == 't') {
                if (csr.size() < 4) return csr_search_failed;
                if (csr[3] == 'p') {
                    if (csr.size() < 5) return 93;
                }
            }
        }
        if (csr[1] == 't') {
            if (csr.size() < 3) return csr_search_failed;
            if (csr[2] == 'v') {
                if (csr.size() < 4) return csr_search_failed;
                if (csr[3] == 'e') {
                    if (csr.size() < 5) return csr_search_failed;
                    if (csr[4] == 'c') {
                        if (csr.size() < 6) return 83;
                    }
                }
                if (csr[3] == 'a') {
                    if (csr.size() < 5) return csr_search_failed;
                    if (csr[4] == 'l') {
                        if (csr.size() < 6) return 90;
                    }
                }
            }
        }
        if (csr[1] == 'i') {
            if (csr.size() < 3) return csr_search_failed;
            if (csr[2] == 'e') {
                if (csr.size() < 4) return 82;
            }
            if (csr[2] == 'p') {
                if (csr.size() < 4) return 91;
            }
        }
    }
    if (csr[0] == 'p') {
        if (csr.size() < 2) return csr_search_failed;
        if (csr[1] == 'm') {
            if (csr.size() < 3) return csr_search_failed;
            if (csr[2] == 'p') {
                if (csr.size() < 4) return csr_search_failed;
                if (csr[3] == 'c') {
                    if (csr.size() < 5) return csr_search_failed;
                    if (csr[4] == 'f') {
                        if (csr.size() < 6) return csr_search_failed;
                        if (csr[5] == 'g') {
                            if (csr.size() < 7) return csr_search_failed;
                            if (csr[6] == '0') {
                                if (csr.size() < 8) return 159;
                            }
                            if (csr[6] == '1') {
                                if (csr.size() < 8) return 160;
                                if (csr[7] == '0') {
                                    if (csr.size() < 9) return 169;
                                }
                                if (csr[7] == '1') {
                                    if (csr.size() < 9) return 170;
                                }
                                if (csr[7] == '2') {
                                    if (csr.size() < 9) return 171;
                                }
                                if (csr[7] == '3') {
                                    if (csr.size() < 9) return 172;
                                }
                                if (csr[7] == '4') {
                                    if (csr.size() < 9) return 173;
                                }
                                if (csr[7] == '5') {
                                    if (csr.size() < 9) return 174;
                                }
                            }
                            if (csr[6] == '2') {
                                if (csr.size() < 8) return 161;
                            }
                            if (csr[6] == '3') {
                                if (csr.size() < 8) return 162;
                            }
                            if (csr[6] == '4') {
                                if (csr.size() < 8) return 163;
                            }
                            if (csr[6] == '5') {
                                if (csr.size() < 8) return 164;
                            }
                            if (csr[6] == '6') {
                                if (csr.size() < 8) return 165;
                            }
                            if (csr[6] == '7') {
                                if (csr.size() < 8) return 166;
                            }
                            if (csr[6] == '8') {
                                if (csr.size() < 8) return 167;
                            }
                            if (csr[6] == '9') {
                                if (csr.size() < 8) return 168;
                            }
                        }
                    }
                }
                if (csr[3] == 'a') {
                    if (csr.size() < 5) return csr_search_failed;
                    if (csr[4] == 'd') {
                        if (csr.size() < 6) return csr_search_failed;
                        if (csr[5] == 'd') {
                            if (csr.size() < 7) return csr_search_failed;
                            if (csr[6] == 'r') {
                                if (csr.size() < 8) return csr_search_failed;
                                if (csr[7] == '0') {
                                    if (csr.size() < 9) return 175;
                                }
                                if (csr[7] == '1') {
                                    if (csr.size() < 9) return 176;
                                    if (csr[8] == '0') {
                                        if (csr.size() < 10) return 185;
                                    }
                                    if (csr[8] == '1') {
                                        if (csr.size() < 10) return 186;
                                    }
                                    if (csr[8] == '2') {
                                        if (csr.size() < 10) return 187;
                                    }
                                    if (csr[8] == '3') {
                                        if (csr.size() < 10) return 188;
                                    }
                                    if (csr[8] == '4') {
                                        if (csr.size() < 10) return 189;
                                    }
                                    if (csr[8] == '5') {
                                        if (csr.size() < 10) return 190;
                                    }
                                    if (csr[8] == '6') {
                                        if (csr.size() < 10) return 191;
                                    }
                                    if (csr[8] == '7') {
                                        if (csr.size() < 10) return 192;
                                    }
                                    if (csr[8] == '8') {
                                        if (csr.size() < 10) return 193;
                                    }
                                    if (csr[8] == '9') {
                                        if (csr.size() < 10) return 194;
                                    }
                                }
                                if (csr[7] == '2') {
                                    if (csr.size() < 9) return 177;
                                    if (csr[8] == '0') {
                                        if (csr.size() < 10) return 195;
                                    }
                                    if (csr[8] == '1') {
                                        if (csr.size() < 10) return 196;
                                    }
                                    if (csr[8] == '2') {
                                        if (csr.size() < 10) return 197;
                                    }
                                    if (csr[8] == '3') {
                                        if (csr.size() < 10) return 198;
                                    }
                                    if (csr[8] == '4') {
                                        if (csr.size() < 10) return 199;
                                    }
                                    if (csr[8] == '5') {
                                        if (csr.size() < 10) return 200;
                                    }
                                    if (csr[8] == '6') {
                                        if (csr.size() < 10) return 201;
                                    }
                                    if (csr[8] == '7') {
                                        if (csr.size() < 10) return 202;
                                    }
                                    if (csr[8] == '8') {
                                        if (csr.size() < 10) return 203;
                                    }
                                    if (csr[8] == '9') {
                                        if (csr.size() < 10) return 204;
                                    }
                                }
                                if (csr[7] == '3') {
                                    if (csr.size() < 9) return 178;
                                    if (csr[8] == '0') {
                                        if (csr.size() < 10) return 205;
                                    }
                                    if (csr[8] == '1') {
                                        if (csr.size() < 10) return 206;
                                    }
                                    if (csr[8] == '2') {
                                        if (csr.size() < 10) return 207;
                                    }
                                    if (csr[8] == '3') {
                                        if (csr.size() < 10) return 208;
                                    }
                                    if (csr[8] == '4') {
                                        if (csr.size() < 10) return 209;
                                    }
                                    if (csr[8] == '5') {
                                        if (csr.size() < 10) return 210;
                                    }
                                    if (csr[8] == '6') {
                                        if (csr.size() < 10) return 211;
                                    }
                                    if (csr[8] == '7') {
                                        if (csr.size() < 10) return 212;
                                    }
                                    if (csr[8] == '8') {
                                        if (csr.size() < 10) return 213;
                                    }
                                    if (csr[8] == '9') {
                                        if (csr.size() < 10) return 214;
                                    }
                                }
                                if (csr[7] == '4') {
                                    if (csr.size() < 9) return 179;
                                    if (csr[8] == '0') {
                                        if (csr.size() < 10) return 215;
                                    }
                                    if (csr[8] == '1') {
                                        if (csr.size() < 10) return 216;
                                    }
                                    if (csr[8] == '2') {
                                        if (csr.size() < 10) return 217;
                                    }
                                    if (csr[8] == '3') {
                                        if (csr.size() < 10) return 218;
                                    }
                                    if (csr[8] == '4') {
                                        if (csr.size() < 10) return 219;
                                    }
                                    if (csr[8] == '5') {
                                        if (csr.size() < 10) return 220;
                                    }
                                    if (csr[8] == '6') {
                                        if (csr.size() < 10) return 221;
                                    }
                                    if (csr[8] == '7') {
                                        if (csr.size() < 10) return 222;
                                    }
                                    if (csr[8] == '8') {
                                        if (csr.size() < 10) return 223;
                                    }
                                    if (csr[8] == '9') {
                                        if (csr.size() < 10) return 224;
                                    }
                                }
                                if (csr[7] == '5') {
                                    if (csr.size() < 9) return 180;
                                    if (csr[8] == '0') {
                                        if (csr.size() < 10) return 225;
                                    }
                                    if (csr[8] == '1') {
                                        if (csr.size() < 10) return 226;
                                    }
                                    if (csr[8] == '2') {
                                        if (csr.size() < 10) return 227;
                                    }
                                    if (csr[8] == '3') {
                                        if (csr.size() < 10) return 228;
                                    }
                                    if (csr[8] == '4') {
                                        if (csr.size() < 10) return 229;
                                    }
                                    if (csr[8] == '5') {
                                        if (csr.size() < 10) return 230;
                                    }
                                    if (csr[8] == '6') {
                                        if (csr.size() < 10) return 231;
                                    }
                                    if (csr[8] == '7') {
                                        if (csr.size() < 10) return 232;
                                    }
                                    if (csr[8] == '8') {
                                        if (csr.size() < 10) return 233;
                                    }
                                    if (csr[8] == '9') {
                                        if (csr.size() < 10) return 234;
                                    }
                                }
                                if (csr[7] == '6') {
                                    if (csr.size() < 9) return 181;
                                    if (csr[8] == '0') {
                                        if (csr.size() < 10) return 235;
                                    }
                                    if (csr[8] == '1') {
                                        if (csr.size() < 10) return 236;
                                    }
                                    if (csr[8] == '2') {
                                        if (csr.size() < 10) return 237;
                                    }
                                    if (csr[8] == '3') {
                                        if (csr.size() < 10) return 238;
                                    }
                                }
                                if (csr[7] == '7') {
                                    if (csr.size() < 9) return 182;
                                }
                                if (csr[7] == '8') {
                                    if (csr.size() < 9) return 183;
                                }
                                if (csr[7] == '9') {
                                    if (csr.size() < 9) return 184;
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    if (csr[0] == 't') {
        if (csr.size() < 2) return csr_search_failed;
        if (csr[1] == 'h') {
            if (csr.size() < 3) return csr_search_failed;
            if (csr[2] == '.') {
                if (csr.size() < 4) return csr_search_failed;
                if (csr[3] == 'v') {
                    if (csr.size() < 5) return csr_search_failed;
                    if (csr[4] == 'l') {
                        if (csr.size() < 6) return 11;
                    }
                    if (csr[4] == 's') {
                        if (csr.size() < 6) return csr_search_failed;
                        if (csr[5] == 't') {
                            if (csr.size() < 7) return csr_search_failed;
                            if (csr[6] == 'a') {
                                if (csr.size() < 8) return csr_search_failed;
                                if (csr[7] == 'r') {
                                    if (csr.size() < 9) return csr_search_failed;
                                    if (csr[8] == 't') {
                                        if (csr.size() < 10) return 4;
                                    }
                                }
                            }
                        }
                    }
                    if (csr[4] == 't') {
                        if (csr.size() < 6) return csr_search_failed;
                        if (csr[5] == 'y') {
                            if (csr.size() < 7) return csr_search_failed;
                            if (csr[6] == 'p') {
                                if (csr.size() < 8) return csr_search_failed;
                                if (csr[7] == 'e') {
                                    if (csr.size() < 9) return 13;
                                }
                            }
                        }
                    }
                    if (csr[4] == 'x') {
                        if (csr.size() < 6) return csr_search_failed;
                        if (csr[5] == 's') {
                            if (csr.size() < 7) return csr_search_failed;
                            if (csr[6] == 'a') {
                                if (csr.size() < 8) return csr_search_failed;
                                if (csr[7] == 't') {
                                    if (csr.size() < 9) return 6;
                                }
                            }
                        }
                        if (csr[5] == 'r') {
                            if (csr.size() < 7) return csr_search_failed;
                            if (csr[6] == 'm') {
                                if (csr.size() < 8) return 8;
                            }
                        }
                    }
                }
            }
        }
        if (csr[1] == 'd') {
            if (csr.size() < 3) return csr_search_failed;
            if (csr[2] == 'a') {
                if (csr.size() < 4) return csr_search_failed;
                if (csr[3] == 't') {
                    if (csr.size() < 5) return csr_search_failed;
                    if (csr[4] == 'a') {
                        if (csr.size() < 6) return csr_search_failed;
                        if (csr[5] == '1') {
                            if (csr.size() < 7) return 373;
                        }
                        if (csr[5] == '2') {
                            if (csr.size() < 7) return 374;
                        }
                        if (csr[5] == '3') {
                            if (csr.size() < 7) return 375;
                        }
                    }
                }
            }
        }
        if (csr[1] == 's') {
            if (csr.size() < 3) return csr_search_failed;
            if (csr[2] == 'e') {
                if (csr.size() < 4) return csr_search_failed;
                if (csr[3] == 'l') {
                    if (csr.size() < 5) return csr_search_failed;
                    if (csr[4] == 'e') {
                        if (csr.size() < 6) return csr_search_failed;
                        if (csr[5] == 'c') {
                            if (csr.size() < 7) return csr_search_failed;
                            if (csr[6] == 't') {
                                if (csr.size() < 8) return 372;
                            }
                        }
                    }
                }
            }
        }
        if (csr[1] == 'i') {
            if (csr.size() < 3) return csr_search_failed;
            if (csr[2] == 'm') {
                if (csr.size() < 4) return csr_search_failed;
                if (csr[3] == 'e') {
                    if (csr.size() < 5) return 18;
                    if (csr[4] == 'h') {
                        if (csr.size() < 6) return 50;
                    }
                }
            }
        }
    }
    if (csr[0] == 'f') {
        if (csr.size() < 2) return csr_search_failed;
        if (csr[1] == 'c') {
            if (csr.size() < 3) return csr_search_failed;
            if (csr[2] == 's') {
                if (csr.size() < 4) return csr_search_failed;
                if (csr[3] == 'r') {
                    if (csr.size() < 5) return 2;
                }
            }
        }
        if (csr[1] == 'r') {
            if (csr.size() < 3) return csr_search_failed;
            if (csr[2] == 'm') {
                if (csr.size() < 4) return 1;
            }
        }
        if (csr[1] == 'f') {
            if (csr.size() < 3) return csr_search_failed;
            if (csr[2] == 'l') {
                if (csr.size() < 4) return csr_search_failed;
                if (csr[3] == 'a') {
                    if (csr.size() < 5) return csr_search_failed;
                    if (csr[4] == 'g') {
                        if (csr.size() < 6) return csr_search_failed;
                        if (csr[5] == 's') {
                            if (csr.size() < 7) return 0;
                        }
                    }
                }
            }
        }
    }
    if (csr[0] == 'm') {
        if (csr.size() < 2) return csr_search_failed;
        if (csr[1] == 'c') {
            if (csr.size() < 3) return csr_search_failed;
            if (csr[2] == 'y') {
                if (csr.size() < 4) return csr_search_failed;
                if (csr[3] == 'c') {
                    if (csr.size() < 5) return csr_search_failed;
                    if (csr[4] == 'l') {
                        if (csr.size() < 6) return csr_search_failed;
                        if (csr[5] == 'e') {
                            if (csr.size() < 7) return 251;
                            if (csr[6] == 'h') {
                                if (csr.size() < 8) return 282;
                            }
                        }
                    }
                }
            }
            if (csr[2] == 'a') {
                if (csr.size() < 4) return csr_search_failed;
                if (csr[3] == 'u') {
                    if (csr.size() < 5) return csr_search_failed;
                    if (csr[4] == 's') {
                        if (csr.size() < 6) return csr_search_failed;
                        if (csr[5] == 'e') {
                            if (csr.size() < 7) return 150;
                        }
                    }
                }
            }
            if (csr[2] == 'o') {
                if (csr.size() < 4) return csr_search_failed;
                if (csr[3] == 'n') {
                    if (csr.size() < 5) return csr_search_failed;
                    if (csr[4] == 't') {
                        if (csr.size() < 6) return csr_search_failed;
                        if (csr[5] == 'e') {
                            if (csr.size() < 7) return csr_search_failed;
                            if (csr[6] == 'x') {
                                if (csr.size() < 8) return csr_search_failed;
                                if (csr[7] == 't') {
                                    if (csr.size() < 9) return 376;
                                }
                            }
                        }
                    }
                    if (csr[4] == 'f') {
                        if (csr.size() < 6) return csr_search_failed;
                        if (csr[5] == 'i') {
                            if (csr.size() < 7) return csr_search_failed;
                            if (csr[6] == 'g') {
                                if (csr.size() < 8) return csr_search_failed;
                                if (csr[7] == 'p') {
                                    if (csr.size() < 9) return csr_search_failed;
                                    if (csr[8] == 't') {
                                        if (csr.size() < 10) return csr_search_failed;
                                        if (csr[9] == 'r') {
                                            if (csr.size() < 11) return 138;
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
                if (csr[3] == 'u') {
                    if (csr.size() < 5) return csr_search_failed;
                    if (csr[4] == 'n') {
                        if (csr.size() < 6) return csr_search_failed;
                        if (csr[5] == 't') {
                            if (csr.size() < 7) return csr_search_failed;
                            if (csr[6] == 'e') {
                                if (csr.size() < 8) return csr_search_failed;
                                if (csr[7] == 'r') {
                                    if (csr.size() < 9) return csr_search_failed;
                                    if (csr[8] == 'e') {
                                        if (csr.size() < 10) return csr_search_failed;
                                        if (csr[9] == 'n') {
                                            if (csr.size() < 11) return 145;
                                        }
                                    }
                                }
                            }
                            if (csr[6] == 'i') {
                                if (csr.size() < 8) return csr_search_failed;
                                if (csr[7] == 'n') {
                                    if (csr.size() < 9) return csr_search_failed;
                                    if (csr[8] == 'h') {
                                        if (csr.size() < 10) return csr_search_failed;
                                        if (csr[9] == 'i') {
                                            if (csr.size() < 11) return csr_search_failed;
                                            if (csr[10] == 'b') {
                                                if (csr.size() < 12) return csr_search_failed;
                                                if (csr[11] == 'i') {
                                                    if (csr.size() < 13) return csr_search_failed;
                                                    if (csr[12] == 't') {
                                                        if (csr.size() < 14) return 313;
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
        if (csr[1] == 'e') {
            if (csr.size() < 3) return csr_search_failed;
            if (csr[2] == 'd') {
                if (csr.size() < 4) return csr_search_failed;
                if (csr[3] == 'e') {
                    if (csr.size() < 5) return csr_search_failed;
                    if (csr[4] == 'l') {
                        if (csr.size() < 6) return csr_search_failed;
                        if (csr[5] == 'e') {
                            if (csr.size() < 7) return csr_search_failed;
                            if (csr[6] == 'g') {
                                if (csr.size() < 8) return 141;
                                if (csr[7] == 'h') {
                                    if (csr.size() < 9) return 147;
                                }
                            }
                        }
                    }
                }
            }
            if (csr[2] == 'p') {
                if (csr.size() < 4) return csr_search_failed;
                if (csr[3] == 'c') {
                    if (csr.size() < 5) return 149;
                }
            }
            if (csr[2] == 'n') {
                if (csr.size() < 4) return csr_search_failed;
                if (csr[3] == 'v') {
                    if (csr.size() < 5) return csr_search_failed;
                    if (csr[4] == 'c') {
                        if (csr.size() < 6) return csr_search_failed;
                        if (csr[5] == 'f') {
                            if (csr.size() < 7) return csr_search_failed;
                            if (csr[6] == 'g') {
                                if (csr.size() < 8) return 155;
                                if (csr[7] == 'h') {
                                    if (csr.size() < 9) return 156;
                                }
                            }
                        }
                    }
                }
            }
        }
        if (csr[1] == 'h') {
            if (csr.size() < 3) return csr_search_failed;
            if (csr[2] == 'p') {
                if (csr.size() < 4) return csr_search_failed;
                if (csr[3] == 'm') {
                    if (csr.size() < 5) return csr_search_failed;
                    if (csr[4] == 'c') {
                        if (csr.size() < 6) return csr_search_failed;
                        if (csr[5] == 'o') {
                            if (csr.size() < 7) return csr_search_failed;
                            if (csr[6] == 'u') {
                                if (csr.size() < 8) return csr_search_failed;
                                if (csr[7] == 'n') {
                                    if (csr.size() < 9) return csr_search_failed;
                                    if (csr[8] == 't') {
                                        if (csr.size() < 10) return csr_search_failed;
                                        if (csr[9] == 'e') {
                                            if (csr.size() < 11) return csr_search_failed;
                                            if (csr[10] == 'r') {
                                                if (csr.size() < 12) return csr_search_failed;
                                                if (csr[11] == '1') {
                                                    if (csr.size() < 13) return csr_search_failed;
                                                    if (csr[12] == '0') {
                                                        if (csr.size() < 14) return 260;
                                                        if (csr[13] == 'h') {
                                                            if (csr.size() < 15) return 291;
                                                        }
                                                    }
                                                    if (csr[12] == '1') {
                                                        if (csr.size() < 14) return 261;
                                                        if (csr[13] == 'h') {
                                                            if (csr.size() < 15) return 292;
                                                        }
                                                    }
                                                    if (csr[12] == '2') {
                                                        if (csr.size() < 14) return 262;
                                                        if (csr[13] == 'h') {
                                                            if (csr.size() < 15) return 293;
                                                        }
                                                    }
                                                    if (csr[12] == '3') {
                                                        if (csr.size() < 14) return 263;
                                                        if (csr[13] == 'h') {
                                                            if (csr.size() < 15) return 294;
                                                        }
                                                    }
                                                    if (csr[12] == '4') {
                                                        if (csr.size() < 14) return 264;
                                                        if (csr[13] == 'h') {
                                                            if (csr.size() < 15) return 295;
                                                        }
                                                    }
                                                    if (csr[12] == '5') {
                                                        if (csr.size() < 14) return 265;
                                                        if (csr[13] == 'h') {
                                                            if (csr.size() < 15) return 296;
                                                        }
                                                    }
                                                    if (csr[12] == '6') {
                                                        if (csr.size() < 14) return 266;
                                                        if (csr[13] == 'h') {
                                                            if (csr.size() < 15) return 297;
                                                        }
                                                    }
                                                    if (csr[12] == '7') {
                                                        if (csr.size() < 14) return 267;
                                                        if (csr[13] == 'h') {
                                                            if (csr.size() < 15) return 298;
                                                        }
                                                    }
                                                    if (csr[12] == '8') {
                                                        if (csr.size() < 14) return 268;
                                                        if (csr[13] == 'h') {
                                                            if (csr.size() < 15) return 299;
                                                        }
                                                    }
                                                    if (csr[12] == '9') {
                                                        if (csr.size() < 14) return 269;
                                                        if (csr[13] == 'h') {
                                                            if (csr.size() < 15) return 300;
                                                        }
                                                    }
                                                }
                                                if (csr[11] == '2') {
                                                    if (csr.size() < 13) return csr_search_failed;
                                                    if (csr[12] == '0') {
                                                        if (csr.size() < 14) return 270;
                                                        if (csr[13] == 'h') {
                                                            if (csr.size() < 15) return 301;
                                                        }
                                                    }
                                                    if (csr[12] == '1') {
                                                        if (csr.size() < 14) return 271;
                                                        if (csr[13] == 'h') {
                                                            if (csr.size() < 15) return 302;
                                                        }
                                                    }
                                                    if (csr[12] == '2') {
                                                        if (csr.size() < 14) return 272;
                                                        if (csr[13] == 'h') {
                                                            if (csr.size() < 15) return 303;
                                                        }
                                                    }
                                                    if (csr[12] == '3') {
                                                        if (csr.size() < 14) return 273;
                                                        if (csr[13] == 'h') {
                                                            if (csr.size() < 15) return 304;
                                                        }
                                                    }
                                                    if (csr[12] == '4') {
                                                        if (csr.size() < 14) return 274;
                                                        if (csr[13] == 'h') {
                                                            if (csr.size() < 15) return 305;
                                                        }
                                                    }
                                                    if (csr[12] == '5') {
                                                        if (csr.size() < 14) return 275;
                                                        if (csr[13] == 'h') {
                                                            if (csr.size() < 15) return 306;
                                                        }
                                                    }
                                                    if (csr[12] == '6') {
                                                        if (csr.size() < 14) return 276;
                                                        if (csr[13] == 'h') {
                                                            if (csr.size() < 15) return 307;
                                                        }
                                                    }
                                                    if (csr[12] == '7') {
                                                        if (csr.size() < 14) return 277;
                                                        if (csr[13] == 'h') {
                                                            if (csr.size() < 15) return 308;
                                                        }
                                                    }
                                                    if (csr[12] == '8') {
                                                        if (csr.size() < 14) return 278;
                                                        if (csr[13] == 'h') {
                                                            if (csr.size() < 15) return 309;
                                                        }
                                                    }
                                                    if (csr[12] == '9') {
                                                        if (csr.size() < 14) return 279;
                                                        if (csr[13] == 'h') {
                                                            if (csr.size() < 15) return 310;
                                                        }
                                                    }
                                                }
                                                if (csr[11] == '3') {
                                                    if (csr.size() < 13) return 253;
                                                    if (csr[12] == 'h') {
                                                        if (csr.size() < 14) return 284;
                                                    }
                                                    if (csr[12] == '0') {
                                                        if (csr.size() < 14) return 280;
                                                        if (csr[13] == 'h') {
                                                            if (csr.size() < 15) return 311;
                                                        }
                                                    }
                                                    if (csr[12] == '1') {
                                                        if (csr.size() < 14) return 281;
                                                        if (csr[13] == 'h') {
                                                            if (csr.size() < 15) return 312;
                                                        }
                                                    }
                                                }
                                                if (csr[11] == '4') {
                                                    if (csr.size() < 13) return 254;
                                                    if (csr[12] == 'h') {
                                                        if (csr.size() < 14) return 285;
                                                    }
                                                }
                                                if (csr[11] == '5') {
                                                    if (csr.size() < 13) return 255;
                                                    if (csr[12] == 'h') {
                                                        if (csr.size() < 14) return 286;
                                                    }
                                                }
                                                if (csr[11] == '6') {
                                                    if (csr.size() < 13) return 256;
                                                    if (csr[12] == 'h') {
                                                        if (csr.size() < 14) return 287;
                                                    }
                                                }
                                                if (csr[11] == '7') {
                                                    if (csr.size() < 13) return 257;
                                                    if (csr[12] == 'h') {
                                                        if (csr.size() < 14) return 288;
                                                    }
                                                }
                                                if (csr[11] == '8') {
                                                    if (csr.size() < 13) return 258;
                                                    if (csr[12] == 'h') {
                                                        if (csr.size() < 14) return 289;
                                                    }
                                                }
                                                if (csr[11] == '9') {
                                                    if (csr.size() < 13) return 259;
                                                    if (csr[12] == 'h') {
                                                        if (csr.size() < 14) return 290;
                                                    }
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                    if (csr[4] == 'e') {
                        if (csr.size() < 6) return csr_search_failed;
                        if (csr[5] == 'v') {
                            if (csr.size() < 7) return csr_search_failed;
                            if (csr[6] == 'e') {
                                if (csr.size() < 8) return csr_search_failed;
                                if (csr[7] == 'n') {
                                    if (csr.size() < 9) return csr_search_failed;
                                    if (csr[8] == 't') {
                                        if (csr.size() < 10) return csr_search_failed;
                                        if (csr[9] == '1') {
                                            if (csr.size() < 11) return csr_search_failed;
                                            if (csr[10] == '0') {
                                                if (csr.size() < 12) return 321;
                                                if (csr[11] == 'h') {
                                                    if (csr.size() < 13) return 350;
                                                }
                                            }
                                            if (csr[10] == '1') {
                                                if (csr.size() < 12) return 322;
                                                if (csr[11] == 'h') {
                                                    if (csr.size() < 13) return 351;
                                                }
                                            }
                                            if (csr[10] == '2') {
                                                if (csr.size() < 12) return 323;
                                                if (csr[11] == 'h') {
                                                    if (csr.size() < 13) return 352;
                                                }
                                            }
                                            if (csr[10] == '3') {
                                                if (csr.size() < 12) return 324;
                                                if (csr[11] == 'h') {
                                                    if (csr.size() < 13) return 353;
                                                }
                                            }
                                            if (csr[10] == '4') {
                                                if (csr.size() < 12) return 325;
                                                if (csr[11] == 'h') {
                                                    if (csr.size() < 13) return 354;
                                                }
                                            }
                                            if (csr[10] == '5') {
                                                if (csr.size() < 12) return 326;
                                                if (csr[11] == 'h') {
                                                    if (csr.size() < 13) return 355;
                                                }
                                            }
                                            if (csr[10] == '6') {
                                                if (csr.size() < 12) return 327;
                                                if (csr[11] == 'h') {
                                                    if (csr.size() < 13) return 356;
                                                }
                                            }
                                            if (csr[10] == '7') {
                                                if (csr.size() < 12) return 328;
                                                if (csr[11] == 'h') {
                                                    if (csr.size() < 13) return 357;
                                                }
                                            }
                                            if (csr[10] == '8') {
                                                if (csr.size() < 12) return 329;
                                                if (csr[11] == 'h') {
                                                    if (csr.size() < 13) return 358;
                                                }
                                            }
                                            if (csr[10] == '9') {
                                                if (csr.size() < 12) return 330;
                                                if (csr[11] == 'h') {
                                                    if (csr.size() < 13) return 359;
                                                }
                                            }
                                        }
                                        if (csr[9] == '2') {
                                            if (csr.size() < 11) return csr_search_failed;
                                            if (csr[10] == '0') {
                                                if (csr.size() < 12) return 331;
                                                if (csr[11] == 'h') {
                                                    if (csr.size() < 13) return 360;
                                                }
                                            }
                                            if (csr[10] == '1') {
                                                if (csr.size() < 12) return 332;
                                                if (csr[11] == 'h') {
                                                    if (csr.size() < 13) return 361;
                                                }
                                            }
                                            if (csr[10] == '2') {
                                                if (csr.size() < 12) return 333;
                                                if (csr[11] == 'h') {
                                                    if (csr.size() < 13) return 362;
                                                }
                                            }
                                            if (csr[10] == '3') {
                                                if (csr.size() < 12) return 334;
                                                if (csr[11] == 'h') {
                                                    if (csr.size() < 13) return 363;
                                                }
                                            }
                                            if (csr[10] == '4') {
                                                if (csr.size() < 12) return 335;
                                                if (csr[11] == 'h') {
                                                    if (csr.size() < 13) return 364;
                                                }
                                            }
                                            if (csr[10] == '5') {
                                                if (csr.size() < 12) return 336;
                                                if (csr[11] == 'h') {
                                                    if (csr.size() < 13) return 365;
                                                }
                                            }
                                            if (csr[10] == '6') {
                                                if (csr.size() < 12) return 337;
                                                if (csr[11] == 'h') {
                                                    if (csr.size() < 13) return 366;
                                                }
                                            }
                                            if (csr[10] == '7') {
                                                if (csr.size() < 12) return 338;
                                                if (csr[11] == 'h') {
                                                    if (csr.size() < 13) return 367;
                                                }
                                            }
                                            if (csr[10] == '8') {
                                                if (csr.size() < 12) return 339;
                                                if (csr[11] == 'h') {
                                                    if (csr.size() < 13) return 368;
                                                }
                                            }
                                            if (csr[10] == '9') {
                                                if (csr.size() < 12) return 340;
                                                if (csr[11] == 'h') {
                                                    if (csr.size() < 13) return 369;
                                                }
                                            }
                                        }
                                        if (csr[9] == '3') {
                                            if (csr.size() < 11) return 314;
                                            if (csr[10] == 'h') {
                                                if (csr.size() < 12) return 343;
                                            }
                                            if (csr[10] == '0') {
                                                if (csr.size() < 12) return 341;
                                                if (csr[11] == 'h') {
                                                    if (csr.size() < 13) return 370;
                                                }
                                            }
                                            if (csr[10] == '1') {
                                                if (csr.size() < 12) return 342;
                                                if (csr[11] == 'h') {
                                                    if (csr.size() < 13) return 371;
                                                }
                                            }
                                        }
                                        if (csr[9] == '4') {
                                            if (csr.size() < 11) return 315;
                                            if (csr[10] == 'h') {
                                                if (csr.size() < 12) return 344;
                                            }
                                        }
                                        if (csr[9] == '5') {
                                            if (csr.size() < 11) return 316;
                                            if (csr[10] == 'h') {
                                                if (csr.size() < 12) return 345;
                                            }
                                        }
                                        if (csr[9] == '6') {
                                            if (csr.size() < 11) return 317;
                                            if (csr[10] == 'h') {
                                                if (csr.size() < 12) return 346;
                                            }
                                        }
                                        if (csr[9] == '7') {
                                            if (csr.size() < 11) return 318;
                                            if (csr[10] == 'h') {
                                                if (csr.size() < 12) return 347;
                                            }
                                        }
                                        if (csr[9] == '8') {
                                            if (csr.size() < 11) return 319;
                                            if (csr[10] == 'h') {
                                                if (csr.size() < 12) return 348;
                                            }
                                        }
                                        if (csr[9] == '9') {
                                            if (csr.size() < 11) return 320;
                                            if (csr[10] == 'h') {
                                                if (csr.size() < 12) return 349;
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
            if (csr[2] == 'a') {
                if (csr.size() < 4) return csr_search_failed;
                if (csr[3] == 'r') {
                    if (csr.size() < 5) return csr_search_failed;
                    if (csr[4] == 't') {
                        if (csr.size() < 6) return csr_search_failed;
                        if (csr[5] == 'i') {
                            if (csr.size() < 7) return csr_search_failed;
                            if (csr[6] == 'd') {
                                if (csr.size() < 8) return 137;
                            }
                        }
                    }
                }
            }
        }
        if (csr[1] == 's') {
            if (csr.size() < 3) return csr_search_failed;
            if (csr[2] == 'c') {
                if (csr.size() < 4) return csr_search_failed;
                if (csr[3] == 'r') {
                    if (csr.size() < 5) return csr_search_failed;
                    if (csr[4] == 'a') {
                        if (csr.size() < 6) return csr_search_failed;
                        if (csr[5] == 't') {
                            if (csr.size() < 7) return csr_search_failed;
                            if (csr[6] == 'c') {
                                if (csr.size() < 8) return csr_search_failed;
                                if (csr[7] == 'h') {
                                    if (csr.size() < 9) return 148;
                                }
                            }
                        }
                    }
                }
            }
            if (csr[2] == 'e') {
                if (csr.size() < 4) return csr_search_failed;
                if (csr[3] == 'c') {
                    if (csr.size() < 5) return csr_search_failed;
                    if (csr[4] == 'c') {
                        if (csr.size() < 6) return csr_search_failed;
                        if (csr[5] == 'f') {
                            if (csr.size() < 7) return csr_search_failed;
                            if (csr[6] == 'g') {
                                if (csr.size() < 8) return 157;
                                if (csr[7] == 'h') {
                                    if (csr.size() < 9) return 158;
                                }
                            }
                        }
                    }
                }
            }
            if (csr[2] == 't') {
                if (csr.size() < 4) return csr_search_failed;
                if (csr[3] == 'a') {
                    if (csr.size() < 5) return csr_search_failed;
                    if (csr[4] == 't') {
                        if (csr.size() < 6) return csr_search_failed;
                        if (csr[5] == 'e') {
                            if (csr.size() < 7) return csr_search_failed;
                            if (csr[6] == 'e') {
                                if (csr.size() < 8) return csr_search_failed;
                                if (csr[7] == 'n') {
                                    if (csr.size() < 9) return csr_search_failed;
                                    if (csr[8] == '0') {
                                        if (csr.size() < 10) return 239;
                                        if (csr[9] == 'h') {
                                            if (csr.size() < 11) return 243;
                                        }
                                    }
                                    if (csr[8] == '1') {
                                        if (csr.size() < 10) return 240;
                                        if (csr[9] == 'h') {
                                            if (csr.size() < 11) return 244;
                                        }
                                    }
                                    if (csr[8] == '2') {
                                        if (csr.size() < 10) return 241;
                                        if (csr[9] == 'h') {
                                            if (csr.size() < 11) return 245;
                                        }
                                    }
                                    if (csr[8] == '3') {
                                        if (csr.size() < 10) return 242;
                                        if (csr[9] == 'h') {
                                            if (csr.size() < 11) return 246;
                                        }
                                    }
                                }
                            }
                        }
                        if (csr[5] == 'u') {
                            if (csr.size() < 7) return csr_search_failed;
                            if (csr[6] == 's') {
                                if (csr.size() < 8) return 139;
                                if (csr[7] == 'h') {
                                    if (csr.size() < 9) return 146;
                                }
                            }
                        }
                    }
                }
            }
        }
        if (csr[1] == 'a') {
            if (csr.size() < 3) return csr_search_failed;
            if (csr[2] == 'r') {
                if (csr.size() < 4) return csr_search_failed;
                if (csr[3] == 'c') {
                    if (csr.size() < 5) return csr_search_failed;
                    if (csr[4] == 'h') {
                        if (csr.size() < 6) return csr_search_failed;
                        if (csr[5] == 'i') {
                            if (csr.size() < 7) return csr_search_failed;
                            if (csr[6] == 'd') {
                                if (csr.size() < 8) return 135;
                            }
                        }
                    }
                }
            }
        }
        if (csr[1] == 't') {
            if (csr.size() < 3) return csr_search_failed;
            if (csr[2] == 'v') {
                if (csr.size() < 4) return csr_search_failed;
                if (csr[3] == 'e') {
                    if (csr.size() < 5) return csr_search_failed;
                    if (csr[4] == 'c') {
                        if (csr.size() < 6) return 144;
                    }
                }
                if (csr[3] == 'a') {
                    if (csr.size() < 5) return csr_search_failed;
                    if (csr[4] == 'l') {
                        if (csr.size() < 6) return 151;
                        if (csr[5] == '2') {
                            if (csr.size() < 7) return 154;
                        }
                    }
                }
            }
            if (csr[2] == 'i') {
                if (csr.size() < 4) return csr_search_failed;
                if (csr[3] == 'n') {
                    if (csr.size() < 5) return csr_search_failed;
                    if (csr[4] == 's') {
                        if (csr.size() < 6) return csr_search_failed;
                        if (csr[5] == 't') {
                            if (csr.size() < 7) return 153;
                        }
                    }
                }
            }
        }
        if (csr[1] == 'n') {
            if (csr.size() < 3) return csr_search_failed;
            if (csr[2] == 'c') {
                if (csr.size() < 4) return csr_search_failed;
                if (csr[3] == 'a') {
                    if (csr.size() < 5) return csr_search_failed;
                    if (csr[4] == 'u') {
                        if (csr.size() < 6) return csr_search_failed;
                        if (csr[5] == 's') {
                            if (csr.size() < 7) return csr_search_failed;
                            if (csr[6] == 'e') {
                                if (csr.size() < 8) return 249;
                            }
                        }
                    }
                }
            }
            if (csr[2] == 'e') {
                if (csr.size() < 4) return csr_search_failed;
                if (csr[3] == 'p') {
                    if (csr.size() < 5) return csr_search_failed;
                    if (csr[4] == 'c') {
                        if (csr.size() < 6) return 248;
                    }
                }
            }
            if (csr[2] == 's') {
                if (csr.size() < 4) return csr_search_failed;
                if (csr[3] == 'c') {
                    if (csr.size() < 5) return csr_search_failed;
                    if (csr[4] == 'r') {
                        if (csr.size() < 6) return csr_search_failed;
                        if (csr[5] == 'a') {
                            if (csr.size() < 7) return csr_search_failed;
                            if (csr[6] == 't') {
                                if (csr.size() < 8) return csr_search_failed;
                                if (csr[7] == 'c') {
                                    if (csr.size() < 9) return csr_search_failed;
                                    if (csr[8] == 'h') {
                                        if (csr.size() < 10) return 247;
                                    }
                                }
                            }
                        }
                    }
                }
                if (csr[3] == 't') {
                    if (csr.size() < 5) return csr_search_failed;
                    if (csr[4] == 'a') {
                        if (csr.size() < 6) return csr_search_failed;
                        if (csr[5] == 't') {
                            if (csr.size() < 7) return csr_search_failed;
                            if (csr[6] == 'u') {
                                if (csr.size() < 8) return csr_search_failed;
                                if (csr[7] == 's') {
                                    if (csr.size() < 9) return 250;
                                }
                            }
                        }
                    }
                }
            }
        }
        if (csr[1] == 'v') {
            if (csr.size() < 3) return csr_search_failed;
            if (csr[2] == 'e') {
                if (csr.size() < 4) return csr_search_failed;
                if (csr[3] == 'n') {
                    if (csr.size() < 5) return csr_search_failed;
                    if (csr[4] == 'd') {
                        if (csr.size() < 6) return csr_search_failed;
                        if (csr[5] == 'o') {
                            if (csr.size() < 7) return csr_search_failed;
                            if (csr[6] == 'r') {
                                if (csr.size() < 8) return csr_search_failed;
                                if (csr[7] == 'i') {
                                    if (csr.size() < 9) return csr_search_failed;
                                    if (csr[8] == 'd') {
                                        if (csr.size() < 10) return 134;
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
        if (csr[1] == 'i') {
            if (csr.size() < 3) return csr_search_failed;
            if (csr[2] == 'e') {
                if (csr.size() < 4) return 143;
            }
            if (csr[2] == 'd') {
                if (csr.size() < 4) return csr_search_failed;
                if (csr[3] == 'e') {
                    if (csr.size() < 5) return csr_search_failed;
                    if (csr[4] == 'l') {
                        if (csr.size() < 6) return csr_search_failed;
                        if (csr[5] == 'e') {
                            if (csr.size() < 7) return csr_search_failed;
                            if (csr[6] == 'g') {
                                if (csr.size() < 8) return 142;
                            }
                        }
                    }
                }
            }
            if (csr[2] == 's') {
                if (csr.size() < 4) return csr_search_failed;
                if (csr[3] == 'a') {
                    if (csr.size() < 5) return 140;
                }
            }
            if (csr[2] == 'p') {
                if (csr.size() < 4) return 152;
            }
            if (csr[2] == 'm') {
                if (csr.size() < 4) return csr_search_failed;
                if (csr[3] == 'p') {
                    if (csr.size() < 5) return csr_search_failed;
                    if (csr[4] == 'i') {
                        if (csr.size() < 6) return csr_search_failed;
                        if (csr[5] == 'd') {
                            if (csr.size() < 7) return 136;
                        }
                    }
                }
            }
            if (csr[2] == 'n') {
                if (csr.size() < 4) return csr_search_failed;
                if (csr[3] == 's') {
                    if (csr.size() < 5) return csr_search_failed;
                    if (csr[4] == 't') {
                        if (csr.size() < 6) return csr_search_failed;
                        if (csr[5] == 'r') {
                            if (csr.size() < 7) return csr_search_failed;
                            if (csr[6] == 'e') {
                                if (csr.size() < 8) return csr_search_failed;
                                if (csr[7] == 't') {
                                    if (csr.size() < 9) return 252;
                                    if (csr[8] == 'h') {
                                        if (csr.size() < 10) return 283;
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    if (csr[0] == 'v') {
        if (csr.size() < 2) return csr_search_failed;
        if (csr[1] == 'c') {
            if (csr.size() < 3) return csr_search_failed;
            if (csr[2] == 's') {
                if (csr.size() < 4) return csr_search_failed;
                if (csr[3] == 'r') {
                    if (csr.size() < 5) return 9;
                }
            }
        }
        if (csr[1] == 'l') {
            if (csr.size() < 3) return 10;
            if (csr[2] == 'e') {
                if (csr.size() < 4) return csr_search_failed;
                if (csr[3] == 'n') {
                    if (csr.size() < 5) return csr_search_failed;
                    if (csr[4] == 'b') {
                        if (csr.size() < 6) return 14;
                    }
                }
            }
        }
        if (csr[1] == 's') {
            if (csr.size() < 3) return csr_search_failed;
            if (csr[2] == 'c') {
                if (csr.size() < 4) return csr_search_failed;
                if (csr[3] == 'a') {
                    if (csr.size() < 5) return csr_search_failed;
                    if (csr[4] == 'u') {
                        if (csr.size() < 6) return csr_search_failed;
                        if (csr[5] == 's') {
                            if (csr.size() < 7) return csr_search_failed;
                            if (csr[6] == 'e') {
                                if (csr.size() < 8) return 130;
                            }
                        }
                    }
                }
            }
            if (csr[2] == 'e') {
                if (csr.size() < 4) return csr_search_failed;
                if (csr[3] == 'p') {
                    if (csr.size() < 5) return csr_search_failed;
                    if (csr[4] == 'c') {
                        if (csr.size() < 6) return 129;
                    }
                }
            }
            if (csr[2] == 's') {
                if (csr.size() < 4) return csr_search_failed;
                if (csr[3] == 'c') {
                    if (csr.size() < 5) return csr_search_failed;
                    if (csr[4] == 'r') {
                        if (csr.size() < 6) return csr_search_failed;
                        if (csr[5] == 'a') {
                            if (csr.size() < 7) return csr_search_failed;
                            if (csr[6] == 't') {
                                if (csr.size() < 8) return csr_search_failed;
                                if (csr[7] == 'c') {
                                    if (csr.size() < 9) return csr_search_failed;
                                    if (csr[8] == 'h') {
                                        if (csr.size() < 10) return 128;
                                    }
                                }
                            }
                        }
                    }
                }
                if (csr[3] == 't') {
                    if (csr.size() < 5) return csr_search_failed;
                    if (csr[4] == 'a') {
                        if (csr.size() < 6) return csr_search_failed;
                        if (csr[5] == 't') {
                            if (csr.size() < 7) return csr_search_failed;
                            if (csr[6] == 'u') {
                                if (csr.size() < 8) return csr_search_failed;
                                if (csr[7] == 's') {
                                    if (csr.size() < 9) return 125;
                                }
                            }
                        }
                    }
                }
            }
            if (csr[2] == 'a') {
                if (csr.size() < 4) return csr_search_failed;
                if (csr[3] == 't') {
                    if (csr.size() < 5) return csr_search_failed;
                    if (csr[4] == 'p') {
                        if (csr.size() < 6) return 133;
                    }
                }
            }
            if (csr[2] == 't') {
                if (csr.size() < 4) return csr_search_failed;
                if (csr[3] == 'a') {
                    if (csr.size() < 5) return csr_search_failed;
                    if (csr[4] == 'r') {
                        if (csr.size() < 6) return csr_search_failed;
                        if (csr[5] == 't') {
                            if (csr.size() < 7) return 3;
                        }
                    }
                }
                if (csr[3] == 'v') {
                    if (csr.size() < 5) return csr_search_failed;
                    if (csr[4] == 'e') {
                        if (csr.size() < 6) return csr_search_failed;
                        if (csr[5] == 'c') {
                            if (csr.size() < 7) return 127;
                        }
                    }
                    if (csr[4] == 'a') {
                        if (csr.size() < 6) return csr_search_failed;
                        if (csr[5] == 'l') {
                            if (csr.size() < 7) return 131;
                        }
                    }
                }
            }
            if (csr[2] == 'i') {
                if (csr.size() < 4) return csr_search_failed;
                if (csr[3] == 'e') {
                    if (csr.size() < 5) return 126;
                }
                if (csr[3] == 'p') {
                    if (csr.size() < 5) return 132;
                }
            }
        }
        if (csr[1] == 't') {
            if (csr.size() < 3) return csr_search_failed;
            if (csr[2] == 'y') {
                if (csr.size() < 4) return csr_search_failed;
                if (csr[3] == 'p') {
                    if (csr.size() < 5) return csr_search_failed;
                    if (csr[4] == 'e') {
                        if (csr.size() < 6) return 12;
                    }
                }
            }
        }
        if (csr[1] == 'x') {
            if (csr.size() < 3) return csr_search_failed;
            if (csr[2] == 's') {
                if (csr.size() < 4) return csr_search_failed;
                if (csr[3] == 'a') {
                    if (csr.size() < 5) return csr_search_failed;
                    if (csr[4] == 't') {
                        if (csr.size() < 6) return 5;
                    }
                }
            }
            if (csr[2] == 'r') {
                if (csr.size() < 4) return csr_search_failed;
                if (csr[3] == 'm') {
                    if (csr.size() < 5) return 7;
                }
            }
        }
    }
    if (csr[0] == 'i') {
        if (csr.size() < 2) return csr_search_failed;
        if (csr[1] == 'n') {
            if (csr.size() < 3) return csr_search_failed;
            if (csr[2] == 's') {
                if (csr.size() < 4) return csr_search_failed;
                if (csr[3] == 't') {
                    if (csr.size() < 5) return csr_search_failed;
                    if (csr[4] == 'r') {
                        if (csr.size() < 6) return csr_search_failed;
                        if (csr[5] == 'e') {
                            if (csr.size() < 7) return csr_search_failed;
                            if (csr[6] == 't') {
                                if (csr.size() < 8) return 19;
                                if (csr[7] == 'h') {
                                    if (csr.size() < 9) return 51;
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    if (csr[0] == 'j') {
        if (csr.size() < 2) return csr_search_failed;
        if (csr[1] == 'v') {
            if (csr.size() < 3) return csr_search_failed;
            if (csr[2] == 't') {
                if (csr.size() < 4) return 16;
            }
        }
    }
    return csr_search_failed;
}

} // namespace ultrassembler_internal