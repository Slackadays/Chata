// SPDX-License-Identifier: MPL-2.0
// The generate_instruction_search.py script automatically generated this code. DO NOT MODIFY!
#include "../instructions.hpp"
#include "../ultrassembler.hpp"

namespace ultrassembler_internal {

const uint16_t fast_instr_search(const ultrastring& inst) {
    const auto size = inst.size();

    if (size == 2) {
        if (inst[0] == 's') {
            if (inst[1] == 'd') return 44;
            if (inst[1] == 'w') return 17;
            if (inst[1] == 'b') return 15;
            if (inst[1] == 'h') return 16;
        }
        if (inst[0] == 'o') {
            if (inst[1] == 'r') return 35;
        }
        if (inst[0] == 'l') {
            if (inst[1] == 'd') return 43;
            if (inst[1] == 'w') return 12;
            if (inst[1] == 'b') return 10;
            if (inst[1] == 'h') return 11;
        }
    }

    if (size == 3) {
        if (inst[0] == 'a') {
            if (inst[1] == 'd') {
                if (inst[2] == 'd') return 27;
            }
            if (inst[1] == 'n') {
                if (inst[2] == 'd') return 36;
            }
        }
        if (inst[0] == 'd') {
            if (inst[1] == 'i') {
                if (inst[2] == 'v') return 58;
            }
        }
        if (inst[0] == 's') {
            if (inst[1] == 'u') {
                if (inst[2] == 'b') return 28;
            }
            if (inst[1] == 'r') {
                if (inst[2] == 'a') return 34;
                if (inst[2] == 'l') return 33;
            }
            if (inst[1] == 'l') {
                if (inst[2] == 'l') return 29;
                if (inst[2] == 't') return 30;
            }
        }
        if (inst[0] == 'm') {
            if (inst[1] == 'a') {
                if (inst[2] == 'x') return 548;
            }
            if (inst[1] == 'u') {
                if (inst[2] == 'l') return 54;
            }
            if (inst[1] == 'i') {
                if (inst[2] == 'n') return 550;
            }
        }
        if (inst[0] == 'o') {
            if (inst[1] == 'r') {
                if (inst[2] == 'i') return 22;
                if (inst[2] == 'n') return 553;
            }
        }
        if (inst[0] == 'b') {
            if (inst[1] == 'e') {
                if (inst[2] == 'q') return 4;
            }
            if (inst[1] == 'l') {
                if (inst[2] == 't') return 6;
            }
            if (inst[1] == 'n') {
                if (inst[2] == 'e') return 5;
            }
            if (inst[1] == 'g') {
                if (inst[2] == 'e') return 7;
            }
        }
        if (inst[0] == 'r') {
            if (inst[1] == 'e') {
                if (inst[2] == 'm') return 60;
            }
            if (inst[1] == 'o') {
                if (inst[2] == 'r') return 560;
                if (inst[2] == 'l') return 558;
            }
        }
        if (inst[0] == 'l') {
            if (inst[1] == 'u') {
                if (inst[2] == 'i') return 0;
            }
            if (inst[1] == 'w') {
                if (inst[2] == 'u') return 42;
            }
            if (inst[1] == 'b') {
                if (inst[2] == 'u') return 13;
            }
            if (inst[1] == 'h') {
                if (inst[2] == 'u') return 14;
            }
        }
        if (inst[0] == 'c') {
            if (inst[1] == '.') {
                if (inst[2] == 'j') return 317;
            }
            if (inst[1] == 'l') {
                if (inst[2] == 'z') return 542;
            }
            if (inst[1] == 't') {
                if (inst[2] == 'z') return 546;
            }
        }
        if (inst[0] == 'x') {
            if (inst[1] == 'o') {
                if (inst[2] == 'r') return 32;
            }
        }
        if (inst[0] == 'z') {
            if (inst[1] == 'i') {
                if (inst[2] == 'p') return 578;
            }
        }
        if (inst[0] == 'f') {
            if (inst[1] == 's') {
                if (inst[2] == 'd') return 212;
                if (inst[2] == 'w') return 187;
                if (inst[2] == 'q') return 225;
                if (inst[2] == 'h') return 257;
            }
            if (inst[1] == 'l') {
                if (inst[2] == 'd') return 206;
                if (inst[2] == 'w') return 186;
                if (inst[2] == 'q') return 224;
                if (inst[2] == 'h') return 256;
            }
        }
        if (inst[0] == 'j') {
            if (inst[1] == 'a') {
                if (inst[2] == 'l') return 2;
            }
        }
    }

    if (size == 4) {
        if (inst[0] == 'a') {
            if (inst[1] == 'd') {
                if (inst[2] == 'd') {
                    if (inst[3] == 'w') return 49;
                    if (inst[3] == 'i') return 18;
                }
            }
            if (inst[1] == 'n') {
                if (inst[2] == 'd') {
                    if (inst[3] == 'i') return 23;
                    if (inst[3] == 'n') return 530;
                }
            }
        }
        if (inst[0] == 'd') {
            if (inst[1] == 'i') {
                if (inst[2] == 'v') {
                    if (inst[3] == 'u') return 59;
                    if (inst[3] == 'w') return 63;
                }
            }
        }
        if (inst[0] == 's') {
            if (inst[1] == 'u') {
                if (inst[2] == 'b') {
                    if (inst[3] == 'w') return 50;
                }
            }
            if (inst[1] == 'r') {
                if (inst[2] == 'a') {
                    if (inst[3] == 'w') return 53;
                    if (inst[3] == 'i') return 26;
                }
                if (inst[2] == 'l') {
                    if (inst[3] == 'w') return 52;
                    if (inst[3] == 'i') return 25;
                }
            }
            if (inst[1] == 'l') {
                if (inst[2] == 'l') {
                    if (inst[3] == 'w') return 51;
                    if (inst[3] == 'i') return 24;
                }
                if (inst[2] == 't') {
                    if (inst[3] == 'u') return 31;
                    if (inst[3] == 'i') return 19;
                }
            }
            if (inst[1] == 'c') {
                if (inst[2] == '.') {
                    if (inst[3] == 'd') return 112;
                    if (inst[3] == 'w') return 68;
                }
            }
        }
        if (inst[0] == 'm') {
            if (inst[1] == 'a') {
                if (inst[2] == 'x') {
                    if (inst[3] == 'u') return 549;
                }
            }
            if (inst[1] == 'u') {
                if (inst[2] == 'l') {
                    if (inst[3] == 'w') return 62;
                    if (inst[3] == 'h') return 55;
                }
            }
            if (inst[1] == 'i') {
                if (inst[2] == 'n') {
                    if (inst[3] == 'u') return 551;
                }
            }
        }
        if (inst[0] == 'b') {
            if (inst[1] == 'i') {
                if (inst[2] == 'n') {
                    if (inst[3] == 'v') return 535;
                }
            }
            if (inst[1] == 'e') {
                if (inst[2] == 'x') {
                    if (inst[3] == 't') return 533;
                }
            }
            if (inst[1] == 's') {
                if (inst[2] == 'e') {
                    if (inst[3] == 't') return 537;
                }
            }
            if (inst[1] == 'l') {
                if (inst[2] == 't') {
                    if (inst[3] == 'u') return 8;
                }
            }
            if (inst[1] == 'c') {
                if (inst[2] == 'l') {
                    if (inst[3] == 'r') return 531;
                }
            }
            if (inst[1] == 'g') {
                if (inst[2] == 'e') {
                    if (inst[3] == 'u') return 9;
                }
            }
        }
        if (inst[0] == 'r') {
            if (inst[1] == 'e') {
                if (inst[2] == 'm') {
                    if (inst[3] == 'u') return 61;
                    if (inst[3] == 'w') return 65;
                }
                if (inst[2] == 'v') {
                    if (inst[3] == '8') return 557;
                }
            }
            if (inst[1] == 'o') {
                if (inst[2] == 'r') {
                    if (inst[3] == 'w') return 563;
                    if (inst[3] == 'i') return 561;
                }
                if (inst[2] == 'l') {
                    if (inst[3] == 'w') return 559;
                }
            }
        }
        if (inst[0] == 'l') {
            if (inst[1] == 'r') {
                if (inst[2] == '.') {
                    if (inst[3] == 'd') return 111;
                    if (inst[3] == 'w') return 67;
                }
            }
        }
        if (inst[0] == 'c') {
            if (inst[1] == '.') {
                if (inst[2] == 's') {
                    if (inst[3] == 'd') return 314;
                    if (inst[3] == 'w') return 313;
                    if (inst[3] == 'b') return 439;
                    if (inst[3] == 'h') return 440;
                }
                if (inst[2] == 'm') {
                    if (inst[3] == 'v') return 332;
                }
                if (inst[2] == 'o') {
                    if (inst[3] == 'r') return 335;
                }
                if (inst[2] == 'l') {
                    if (inst[3] == 'd') return 310;
                    if (inst[3] == 'w') return 309;
                    if (inst[3] == 'i') return 323;
                    if (inst[3] == 'h') return 438;
                }
                if (inst[2] == 'j') {
                    if (inst[3] == 'r') return 319;
                }
            }
            if (inst[1] == 'l') {
                if (inst[2] == 'z') {
                    if (inst[3] == 'w') return 543;
                }
            }
            if (inst[1] == 'p') {
                if (inst[2] == 'o') {
                    if (inst[3] == 'p') return 544;
                }
            }
            if (inst[1] == 't') {
                if (inst[2] == 'z') {
                    if (inst[3] == 'w') return 547;
                }
            }
        }
        if (inst[0] == 'x') {
            if (inst[1] == 'o') {
                if (inst[2] == 'r') {
                    if (inst[3] == 'i') return 21;
                }
            }
            if (inst[1] == 'n') {
                if (inst[2] == 'o') {
                    if (inst[3] == 'r') return 574;
                }
            }
        }
        if (inst[0] == 'p') {
            if (inst[1] == 'a') {
                if (inst[2] == 'c') {
                    if (inst[3] == 'k') return 554;
                }
            }
        }
        if (inst[0] == 'j') {
            if (inst[1] == 'a') {
                if (inst[2] == 'l') {
                    if (inst[3] == 'r') return 3;
                }
            }
        }
    }

    if (size == 5) {
        if (inst[0] == 'a') {
            if (inst[1] == 'd') {
                if (inst[2] == 'd') {
                    if (inst[3] == 'i') {
                        if (inst[4] == 'w') return 45;
                    }
                }
            }
            if (inst[1] == 'u') {
                if (inst[2] == 'i') {
                    if (inst[3] == 'p') {
                        if (inst[4] == 'c') return 1;
                    }
                }
            }
        }
        if (inst[0] == 'd') {
            if (inst[1] == 'i') {
                if (inst[2] == 'v') {
                    if (inst[3] == 'u') {
                        if (inst[4] == 'w') return 64;
                    }
                }
            }
        }
        if (inst[0] == 'u') {
            if (inst[1] == 'n') {
                if (inst[2] == 'z') {
                    if (inst[3] == 'i') {
                        if (inst[4] == 'p') return 573;
                    }
                }
            }
        }
        if (inst[0] == 'e') {
            if (inst[1] == 'c') {
                if (inst[2] == 'a') {
                    if (inst[3] == 'l') {
                        if (inst[4] == 'l') return 40;
                    }
                }
            }
        }
        if (inst[0] == 's') {
            if (inst[1] == 'm') {
                if (inst[2] == '3') {
                    if (inst[3] == 'p') {
                        if (inst[4] == '1') return 1233;
                        if (inst[4] == '0') return 1232;
                    }
                }
                if (inst[2] == '4') {
                    if (inst[3] == 'e') {
                        if (inst[4] == 'd') return 1234;
                    }
                    if (inst[3] == 'k') {
                        if (inst[4] == 's') return 1235;
                    }
                }
            }
            if (inst[1] == 'r') {
                if (inst[2] == 'a') {
                    if (inst[3] == 'i') {
                        if (inst[4] == 'w') return 48;
                    }
                }
                if (inst[2] == 'l') {
                    if (inst[3] == 'i') {
                        if (inst[4] == 'w') return 47;
                    }
                }
            }
            if (inst[1] == 'l') {
                if (inst[2] == 'l') {
                    if (inst[3] == 'i') {
                        if (inst[4] == 'w') return 46;
                    }
                }
                if (inst[2] == 't') {
                    if (inst[3] == 'i') {
                        if (inst[4] == 'u') return 20;
                    }
                }
            }
        }
        if (inst[0] == 'm') {
            if (inst[1] == 'u') {
                if (inst[2] == 'l') {
                    if (inst[3] == 'h') {
                        if (inst[4] == 'u') return 57;
                    }
                }
            }
        }
        if (inst[0] == 'o') {
            if (inst[1] == 'r') {
                if (inst[2] == 'c') {
                    if (inst[3] == '.') {
                        if (inst[4] == 'b') return 552;
                    }
                }
            }
        }
        if (inst[0] == 'b') {
            if (inst[1] == 'i') {
                if (inst[2] == 'n') {
                    if (inst[3] == 'v') {
                        if (inst[4] == 'i') return 536;
                    }
                }
            }
            if (inst[1] == 'e') {
                if (inst[2] == 'x') {
                    if (inst[3] == 't') {
                        if (inst[4] == 'i') return 534;
                    }
                }
            }
            if (inst[1] == 's') {
                if (inst[2] == 'e') {
                    if (inst[3] == 't') {
                        if (inst[4] == 'i') return 538;
                    }
                }
            }
            if (inst[1] == 'r') {
                if (inst[2] == 'e') {
                    if (inst[3] == 'v') {
                        if (inst[4] == '8') return 1217;
                    }
                }
            }
            if (inst[1] == 'c') {
                if (inst[2] == 'l') {
                    if (inst[3] == 'r') {
                        if (inst[4] == 'i') return 532;
                    }
                }
            }
        }
        if (inst[0] == 'r') {
            if (inst[1] == 'e') {
                if (inst[2] == 'm') {
                    if (inst[3] == 'u') {
                        if (inst[4] == 'w') return 66;
                    }
                }
            }
            if (inst[1] == 'o') {
                if (inst[2] == 'r') {
                    if (inst[3] == 'i') {
                        if (inst[4] == 'w') return 562;
                    }
                }
            }
        }
        if (inst[0] == 'c') {
            if (inst[1] == '.') {
                if (inst[2] == 'a') {
                    if (inst[3] == 'd') {
                        if (inst[4] == 'd') return 333;
                    }
                    if (inst[3] == 'n') {
                        if (inst[4] == 'd') return 334;
                    }
                }
                if (inst[2] == 's') {
                    if (inst[3] == 'u') {
                        if (inst[4] == 'b') return 337;
                    }
                }
                if (inst[2] == 'm') {
                    if (inst[3] == 'u') {
                        if (inst[4] == 'l') return 447;
                    }
                }
                if (inst[2] == 'l') {
                    if (inst[3] == 'u') {
                        if (inst[4] == 'i') return 324;
                    }
                    if (inst[3] == 'b') {
                        if (inst[4] == 'u') return 436;
                    }
                    if (inst[3] == 'h') {
                        if (inst[4] == 'u') return 437;
                    }
                }
                if (inst[2] == 'n') {
                    if (inst[3] == 'o') {
                        if (inst[4] == 'p') return 340;
                        if (inst[4] == 't') return 446;
                    }
                }
                if (inst[2] == 'x') {
                    if (inst[3] == 'o') {
                        if (inst[4] == 'r') return 336;
                    }
                }
                if (inst[2] == 'f') {
                    if (inst[3] == 's') {
                        if (inst[4] == 'd') return 316;
                        if (inst[4] == 'w') return 315;
                    }
                    if (inst[3] == 'l') {
                        if (inst[4] == 'd') return 312;
                        if (inst[4] == 'w') return 311;
                    }
                }
                if (inst[2] == 'j') {
                    if (inst[3] == 'a') {
                        if (inst[4] == 'l') return 318;
                    }
                }
            }
            if (inst[1] == 's') {
                if (inst[2] == 'r') {
                    if (inst[3] == 'r') {
                        if (inst[4] == 'w') return 293;
                        if (inst[4] == 's') return 294;
                        if (inst[4] == 'c') return 295;
                    }
                }
            }
            if (inst[1] == 'm') {
                if (inst[2] == '.') {
                    if (inst[3] == 'j') {
                        if (inst[4] == 't') return 454;
                    }
                }
            }
            if (inst[1] == 'l') {
                if (inst[2] == 'm') {
                    if (inst[3] == 'u') {
                        if (inst[4] == 'l') return 539;
                    }
                }
            }
            if (inst[1] == 'p') {
                if (inst[2] == 'o') {
                    if (inst[3] == 'p') {
                        if (inst[4] == 'w') return 545;
                    }
                }
            }
        }
        if (inst[0] == 'p') {
            if (inst[1] == 'a') {
                if (inst[2] == 'u') {
                    if (inst[3] == 's') {
                        if (inst[4] == 'e') return 39;
                    }
                }
                if (inst[2] == 'c') {
                    if (inst[3] == 'k') {
                        if (inst[4] == 'w') return 556;
                        if (inst[4] == 'h') return 555;
                    }
                }
            }
        }
        if (inst[0] == 'v') {
            if (inst[1] == 'i') {
                if (inst[2] == 'd') {
                    if (inst[3] == '.') {
                        if (inst[4] == 'v') return 1184;
                    }
                }
            }
            if (inst[1] == 's') {
                if (inst[2] == 'm') {
                    if (inst[3] == '.') {
                        if (inst[4] == 'v') return 591;
                    }
                }
            }
            if (inst[1] == 'l') {
                if (inst[2] == 'm') {
                    if (inst[3] == '.') {
                        if (inst[4] == 'v') return 590;
                    }
                }
            }
        }
        if (inst[0] == 'f') {
            if (inst[1] == 'e') {
                if (inst[2] == 'q') {
                    if (inst[3] == '.') {
                        if (inst[4] == 'd') return 203;
                        if (inst[4] == 's') return 179;
                        if (inst[4] == 'q') return 244;
                        if (inst[4] == 'h') return 278;
                    }
                }
                if (inst[2] == 'n') {
                    if (inst[3] == 'c') {
                        if (inst[4] == 'e') return 37;
                    }
                }
            }
            if (inst[1] == 'l') {
                if (inst[2] == 'i') {
                    if (inst[3] == '.') {
                        if (inst[4] == 'd') return 457;
                        if (inst[4] == 's') return 456;
                        if (inst[4] == 'q') return 458;
                        if (inst[4] == 'h') return 459;
                    }
                }
                if (inst[2] == 'e') {
                    if (inst[3] == '.') {
                        if (inst[4] == 'd') return 205;
                        if (inst[4] == 's') return 181;
                        if (inst[4] == 'q') return 246;
                        if (inst[4] == 'h') return 280;
                    }
                }
                if (inst[2] == 't') {
                    if (inst[3] == '.') {
                        if (inst[4] == 'd') return 204;
                        if (inst[4] == 's') return 180;
                        if (inst[4] == 'q') return 245;
                        if (inst[4] == 'h') return 279;
                    }
                }
            }
        }
    }

    if (size == 6) {
        if (inst[0] == 'a') {
            if (inst[1] == 'd') {
                if (inst[2] == 'd') {
                    if (inst[3] == '.') {
                        if (inst[4] == 'u') {
                            if (inst[5] == 'w') return 529;
                        }
                    }
                }
            }
        }
        if (inst[0] == 'e') {
            if (inst[1] == 'b') {
                if (inst[2] == 'r') {
                    if (inst[3] == 'e') {
                        if (inst[4] == 'a') {
                            if (inst[5] == 'k') return 41;
                        }
                    }
                }
            }
        }
        if (inst[0] == 's') {
            if (inst[1] == 'e') {
                if (inst[2] == 'x') {
                    if (inst[3] == 't') {
                        if (inst[4] == '.') {
                            if (inst[5] == 'b') return 564;
                            if (inst[5] == 'h') return 565;
                        }
                    }
                }
            }
            if (inst[1] == 'h') {
                if (inst[2] == '3') {
                    if (inst[3] == 'a') {
                        if (inst[4] == 'd') {
                            if (inst[5] == 'd') return 570;
                        }
                    }
                }
                if (inst[2] == '2') {
                    if (inst[3] == 'a') {
                        if (inst[4] == 'd') {
                            if (inst[5] == 'd') return 568;
                        }
                    }
                }
                if (inst[2] == '1') {
                    if (inst[3] == 'a') {
                        if (inst[4] == 'd') {
                            if (inst[5] == 'd') return 566;
                        }
                    }
                }
            }
        }
        if (inst[0] == 'm') {
            if (inst[1] == 'u') {
                if (inst[2] == 'l') {
                    if (inst[3] == 'h') {
                        if (inst[4] == 's') {
                            if (inst[5] == 'u') return 56;
                        }
                    }
                }
            }
        }
        if (inst[0] == 'c') {
            if (inst[1] == '.') {
                if (inst[2] == 'a') {
                    if (inst[3] == 'd') {
                        if (inst[4] == 'd') {
                            if (inst[5] == 'w') return 338;
                            if (inst[5] == 'i') return 325;
                        }
                    }
                    if (inst[3] == 'n') {
                        if (inst[4] == 'd') {
                            if (inst[5] == 'i') return 331;
                        }
                    }
                }
                if (inst[2] == 's') {
                    if (inst[3] == 'd') {
                        if (inst[4] == 's') {
                            if (inst[5] == 'p') return 306;
                        }
                    }
                    if (inst[3] == 'u') {
                        if (inst[4] == 'b') {
                            if (inst[5] == 'w') return 339;
                        }
                    }
                    if (inst[3] == 'w') {
                        if (inst[4] == 's') {
                            if (inst[5] == 'p') return 305;
                        }
                    }
                    if (inst[3] == 'r') {
                        if (inst[4] == 'a') {
                            if (inst[5] == 'i') return 330;
                        }
                        if (inst[4] == 'l') {
                            if (inst[5] == 'i') return 329;
                        }
                    }
                    if (inst[3] == 'l') {
                        if (inst[4] == 'l') {
                            if (inst[5] == 'i') return 328;
                        }
                    }
                }
                if (inst[2] == 'b') {
                    if (inst[3] == 'e') {
                        if (inst[4] == 'q') {
                            if (inst[5] == 'z') return 321;
                        }
                    }
                    if (inst[3] == 'n') {
                        if (inst[4] == 'e') {
                            if (inst[5] == 'z') return 322;
                        }
                    }
                }
                if (inst[2] == 'l') {
                    if (inst[3] == 'd') {
                        if (inst[4] == 's') {
                            if (inst[5] == 'p') return 302;
                        }
                    }
                    if (inst[3] == 'w') {
                        if (inst[4] == 's') {
                            if (inst[5] == 'p') return 301;
                        }
                    }
                }
                if (inst[2] == 'j') {
                    if (inst[3] == 'a') {
                        if (inst[4] == 'l') {
                            if (inst[5] == 'r') return 320;
                        }
                    }
                }
            }
            if (inst[1] == 's') {
                if (inst[2] == 'r') {
                    if (inst[3] == 'r') {
                        if (inst[4] == 'w') {
                            if (inst[5] == 'i') return 296;
                        }
                        if (inst[4] == 's') {
                            if (inst[5] == 'i') return 297;
                        }
                        if (inst[4] == 'c') {
                            if (inst[5] == 'i') return 298;
                        }
                    }
                }
            }
            if (inst[1] == 'm') {
                if (inst[2] == '.') {
                    if (inst[3] == 'p') {
                        if (inst[4] == 'o') {
                            if (inst[5] == 'p') return 449;
                        }
                    }
                }
            }
            if (inst[1] == 'l') {
                if (inst[2] == 'm') {
                    if (inst[3] == 'u') {
                        if (inst[4] == 'l') {
                            if (inst[5] == 'r') return 541;
                            if (inst[5] == 'h') return 540;
                        }
                    }
                }
            }
        }
        if (inst[0] == 'x') {
            if (inst[1] == 'p') {
                if (inst[2] == 'e') {
                    if (inst[3] == 'r') {
                        if (inst[4] == 'm') {
                            if (inst[5] == '4') return 1237;
                            if (inst[5] == '8') return 1236;
                        }
                    }
                }
            }
        }
        if (inst[0] == 't') {
            if (inst[1] == 'h') {
                if (inst[2] == '.') {
                    if (inst[3] == 'e') {
                        if (inst[4] == 'x') {
                            if (inst[5] == 't') return 1313;
                        }
                    }
                    if (inst[3] == 's') {
                        if (inst[4] == 'd') {
                            if (inst[5] == 'd') return 1370;
                        }
                        if (inst[4] == 'w') {
                            if (inst[5] == 'd') return 1371;
                        }
                        if (inst[4] == 'r') {
                            if (inst[5] == 'd') return 1355;
                            if (inst[5] == 'w') return 1354;
                            if (inst[5] == 'b') return 1352;
                            if (inst[5] == 'h') return 1353;
                        }
                    }
                    if (inst[3] == 'r') {
                        if (inst[4] == 'e') {
                            if (inst[5] == 'v') return 1317;
                        }
                    }
                    if (inst[3] == 'l') {
                        if (inst[4] == 'd') {
                            if (inst[5] == 'd') return 1367;
                        }
                        if (inst[4] == 'w') {
                            if (inst[5] == 'd') return 1368;
                        }
                        if (inst[4] == 'r') {
                            if (inst[5] == 'd') return 1351;
                            if (inst[5] == 'w') return 1349;
                            if (inst[5] == 'b') return 1345;
                            if (inst[5] == 'h') return 1347;
                        }
                    }
                    if (inst[3] == 't') {
                        if (inst[4] == 's') {
                            if (inst[5] == 't') return 1320;
                        }
                    }
                    if (inst[3] == 'f') {
                        if (inst[4] == 'f') {
                            if (inst[5] == '1') return 1316;
                            if (inst[5] == '0') return 1315;
                        }
                    }
                }
            }
        }
        if (inst[0] == 'v') {
            if (inst[1] == 's') {
                if (inst[2] == 'e') {
                    if (inst[3] == 't') {
                        if (inst[4] == 'v') {
                            if (inst[5] == 'l') return 581;
                        }
                    }
                    if (inst[3] == '8') {
                        if (inst[4] == '.') {
                            if (inst[5] == 'v') return 586;
                        }
                    }
                }
                if (inst[2] == '2') {
                    if (inst[3] == 'r') {
                        if (inst[4] == '.') {
                            if (inst[5] == 'v') return 889;
                        }
                    }
                }
                if (inst[2] == '4') {
                    if (inst[3] == 'r') {
                        if (inst[4] == '.') {
                            if (inst[5] == 'v') return 890;
                        }
                    }
                }
                if (inst[2] == '1') {
                    if (inst[3] == 'r') {
                        if (inst[4] == '.') {
                            if (inst[5] == 'v') return 888;
                        }
                    }
                }
                if (inst[2] == '8') {
                    if (inst[3] == 'r') {
                        if (inst[4] == '.') {
                            if (inst[5] == 'v') return 891;
                        }
                    }
                }
            }
            if (inst[1] == 'o') {
                if (inst[2] == 'r') {
                    if (inst[3] == '.') {
                        if (inst[4] == 'v') {
                            if (inst[5] == 'i') return 941;
                            if (inst[5] == 'x') return 940;
                            if (inst[5] == 'v') return 939;
                        }
                    }
                }
            }
            if (inst[1] == 'l') {
                if (inst[2] == 'e') {
                    if (inst[3] == '8') {
                        if (inst[4] == '.') {
                            if (inst[5] == 'v') return 582;
                        }
                    }
                }
            }
            if (inst[1] == 'c') {
                if (inst[2] == 'l') {
                    if (inst[3] == 'z') {
                        if (inst[4] == '.') {
                            if (inst[5] == 'v') return 1257;
                        }
                    }
                }
                if (inst[2] == 't') {
                    if (inst[3] == 'z') {
                        if (inst[4] == '.') {
                            if (inst[5] == 'v') return 1258;
                        }
                    }
                }
            }
        }
        if (inst[0] == 'z') {
            if (inst[1] == 'e') {
                if (inst[2] == 'x') {
                    if (inst[3] == 't') {
                        if (inst[4] == '.') {
                            if (inst[5] == 'h') return 577;
                        }
                    }
                }
            }
        }
        if (inst[0] == 'f') {
            if (inst[1] == 'a') {
                if (inst[2] == 'd') {
                    if (inst[3] == 'd') {
                        if (inst[4] == '.') {
                            if (inst[5] == 'd') return 192;
                            if (inst[5] == 's') return 166;
                            if (inst[5] == 'q') return 230;
                            if (inst[5] == 'h') return 262;
                        }
                    }
                }
            }
            if (inst[1] == 'd') {
                if (inst[2] == 'i') {
                    if (inst[3] == 'v') {
                        if (inst[4] == '.') {
                            if (inst[5] == 'd') return 202;
                            if (inst[5] == 's') return 169;
                            if (inst[5] == 'q') return 233;
                            if (inst[5] == 'h') return 265;
                        }
                    }
                }
            }
            if (inst[1] == 's') {
                if (inst[2] == 'u') {
                    if (inst[3] == 'b') {
                        if (inst[4] == '.') {
                            if (inst[5] == 'd') return 217;
                            if (inst[5] == 's') return 167;
                            if (inst[5] == 'q') return 231;
                            if (inst[5] == 'h') return 263;
                        }
                    }
                }
            }
            if (inst[1] == 'm') {
                if (inst[2] == 'a') {
                    if (inst[3] == 'x') {
                        if (inst[4] == '.') {
                            if (inst[5] == 'd') return 194;
                            if (inst[5] == 's') return 175;
                            if (inst[5] == 'q') return 239;
                            if (inst[5] == 'h') return 271;
                        }
                    }
                }
                if (inst[2] == 'u') {
                    if (inst[3] == 'l') {
                        if (inst[4] == '.') {
                            if (inst[5] == 'd') return 209;
                            if (inst[5] == 's') return 168;
                            if (inst[5] == 'q') return 232;
                            if (inst[5] == 'h') return 264;
                        }
                    }
                }
                if (inst[2] == 'i') {
                    if (inst[3] == 'n') {
                        if (inst[4] == '.') {
                            if (inst[5] == 'd') return 207;
                            if (inst[5] == 's') return 174;
                            if (inst[5] == 'q') return 238;
                            if (inst[5] == 'h') return 270;
                        }
                    }
                }
            }
            if (inst[1] == 'l') {
                if (inst[2] == 'e') {
                    if (inst[3] == 'q') {
                        if (inst[4] == '.') {
                            if (inst[5] == 'd') return 483;
                            if (inst[5] == 's') return 481;
                            if (inst[5] == 'q') return 487;
                            if (inst[5] == 'h') return 485;
                        }
                    }
                }
                if (inst[2] == 't') {
                    if (inst[3] == 'q') {
                        if (inst[4] == '.') {
                            if (inst[5] == 'd') return 484;
                            if (inst[5] == 's') return 482;
                            if (inst[5] == 'q') return 488;
                            if (inst[5] == 'h') return 486;
                        }
                    }
                }
            }
        }
    }

    if (size == 7) {
        if (inst[0] == 'a') {
            if (inst[1] == 'e') {
                if (inst[2] == 's') {
                    if (inst[3] == '6') {
                        if (inst[4] == '4') {
                            if (inst[5] == 'd') {
                                if (inst[6] == 's') return 1210;
                            }
                            if (inst[5] == 'i') {
                                if (inst[6] == 'm') return 1214;
                            }
                            if (inst[5] == 'e') {
                                if (inst[6] == 's') return 1212;
                            }
                        }
                    }
                }
            }
            if (inst[1] == 'm') {
                if (inst[2] == 'o') {
                    if (inst[3] == 'o') {
                        if (inst[4] == 'r') {
                            if (inst[5] == '.') {
                                if (inst[6] == 'd') return 123;
                                if (inst[6] == 'w') return 79;
                                if (inst[6] == 'b') return 362;
                                if (inst[6] == 'h') return 363;
                            }
                        }
                    }
                }
            }
        }
        if (inst[0] == 'w') {
            if (inst[1] == 'r') {
                if (inst[2] == 's') {
                    if (inst[3] == '.') {
                        if (inst[4] == 's') {
                            if (inst[5] == 't') {
                                if (inst[6] == 'o') return 300;
                            }
                        }
                        if (inst[4] == 'n') {
                            if (inst[5] == 't') {
                                if (inst[6] == 'o') return 299;
                            }
                        }
                    }
                }
            }
        }
        if (inst[0] == 's') {
            if (inst[1] == 'l') {
                if (inst[2] == 'l') {
                    if (inst[3] == 'i') {
                        if (inst[4] == '.') {
                            if (inst[5] == 'u') {
                                if (inst[6] == 'w') return 572;
                            }
                        }
                    }
                }
            }
            if (inst[1] == 'c') {
                if (inst[2] == '.') {
                    if (inst[3] == 'd') {
                        if (inst[4] == '.') {
                            if (inst[5] == 'a') {
                                if (inst[6] == 'q') return 114;
                            }
                            if (inst[5] == 'r') {
                                if (inst[6] == 'l') return 116;
                            }
                        }
                    }
                    if (inst[3] == 'w') {
                        if (inst[4] == '.') {
                            if (inst[5] == 'a') {
                                if (inst[6] == 'q') return 70;
                            }
                            if (inst[5] == 'r') {
                                if (inst[6] == 'l') return 72;
                            }
                        }
                    }
                }
            }
        }
        if (inst[0] == 'm') {
            if (inst[1] == 'o') {
                if (inst[2] == 'p') {
                    if (inst[3] == '.') {
                        if (inst[4] == 'r') {
                            if (inst[5] == '.') {
                                if (inst[6] == '3') return 492;
                                if (inst[6] == '2') return 491;
                                if (inst[6] == '6') return 495;
                                if (inst[6] == '4') return 493;
                                if (inst[6] == '1') return 490;
                                if (inst[6] == '8') return 497;
                                if (inst[6] == '0') return 489;
                                if (inst[6] == '5') return 494;
                                if (inst[6] == '7') return 496;
                                if (inst[6] == '9') return 498;
                            }
                        }
                    }
                }
            }
        }
        if (inst[0] == 'l') {
            if (inst[1] == 'r') {
                if (inst[2] == '.') {
                    if (inst[3] == 'd') {
                        if (inst[4] == '.') {
                            if (inst[5] == 'a') {
                                if (inst[6] == 'q') return 113;
                            }
                            if (inst[5] == 'r') {
                                if (inst[6] == 'l') return 115;
                            }
                        }
                    }
                    if (inst[3] == 'w') {
                        if (inst[4] == '.') {
                            if (inst[5] == 'a') {
                                if (inst[6] == 'q') return 69;
                            }
                            if (inst[5] == 'r') {
                                if (inst[6] == 'l') return 71;
                            }
                        }
                    }
                }
            }
        }
        if (inst[0] == 'c') {
            if (inst[1] == '.') {
                if (inst[2] == 'a') {
                    if (inst[3] == 'd') {
                        if (inst[4] == 'd') {
                            if (inst[5] == 'i') {
                                if (inst[6] == 'w') return 326;
                            }
                        }
                    }
                }
                if (inst[2] == 'f') {
                    if (inst[3] == 's') {
                        if (inst[4] == 'd') {
                            if (inst[5] == 's') {
                                if (inst[6] == 'p') return 308;
                            }
                        }
                        if (inst[4] == 'w') {
                            if (inst[5] == 's') {
                                if (inst[6] == 'p') return 307;
                            }
                        }
                    }
                    if (inst[3] == 'l') {
                        if (inst[4] == 'd') {
                            if (inst[5] == 's') {
                                if (inst[6] == 'p') return 304;
                            }
                        }
                        if (inst[4] == 'w') {
                            if (inst[5] == 's') {
                                if (inst[6] == 'p') return 303;
                            }
                        }
                    }
                }
            }
            if (inst[1] == 'm') {
                if (inst[2] == '.') {
                    if (inst[3] == 'p') {
                        if (inst[4] == 'u') {
                            if (inst[5] == 's') {
                                if (inst[6] == 'h') return 448;
                            }
                        }
                    }
                    if (inst[3] == 'j') {
                        if (inst[4] == 'a') {
                            if (inst[5] == 'l') {
                                if (inst[6] == 't') return 455;
                            }
                        }
                    }
                }
            }
        }
        if (inst[0] == 'x') {
            if (inst[1] == 'p') {
                if (inst[2] == 'e') {
                    if (inst[3] == 'r') {
                        if (inst[4] == 'm') {
                            if (inst[5] == '.') {
                                if (inst[6] == 'b') return 575;
                                if (inst[6] == 'n') return 576;
                            }
                        }
                    }
                }
            }
        }
        if (inst[0] == 't') {
            if (inst[1] == 'h') {
                if (inst[2] == '.') {
                    if (inst[3] == 'i') {
                        if (inst[4] == 'p') {
                            if (inst[5] == 'o') {
                                if (inst[6] == 'p') return 1389;
                            }
                        }
                    }
                    if (inst[3] == 'e') {
                        if (inst[4] == 'x') {
                            if (inst[5] == 't') {
                                if (inst[6] == 'u') return 1314;
                            }
                        }
                    }
                    if (inst[3] == 's') {
                        if (inst[4] == 'd') {
                            if (inst[5] == 'i') {
                                if (inst[6] == 'a') return 1343;
                                if (inst[6] == 'b') return 1344;
                            }
                        }
                        if (inst[4] == 'u') {
                            if (inst[5] == 'r') {
                                if (inst[6] == 'd') return 1366;
                                if (inst[6] == 'w') return 1365;
                                if (inst[6] == 'b') return 1363;
                                if (inst[6] == 'h') return 1364;
                            }
                        }
                        if (inst[4] == 'w') {
                            if (inst[5] == 'i') {
                                if (inst[6] == 'a') return 1341;
                                if (inst[6] == 'b') return 1342;
                            }
                        }
                        if (inst[4] == 'b') {
                            if (inst[5] == 'i') {
                                if (inst[6] == 'a') return 1337;
                                if (inst[6] == 'b') return 1338;
                            }
                        }
                        if (inst[4] == 'r') {
                            if (inst[5] == 'r') {
                                if (inst[6] == 'i') return 1311;
                            }
                        }
                        if (inst[4] == 'h') {
                            if (inst[5] == 'i') {
                                if (inst[6] == 'a') return 1339;
                                if (inst[6] == 'b') return 1340;
                            }
                        }
                        if (inst[4] == 'y') {
                            if (inst[5] == 'n') {
                                if (inst[6] == 'c') return 1306;
                            }
                        }
                    }
                    if (inst[3] == 'm') {
                        if (inst[4] == 'u') {
                            if (inst[5] == 'l') {
                                if (inst[6] == 'a') return 1380;
                                if (inst[6] == 's') return 1383;
                            }
                        }
                    }
                    if (inst[3] == 'r') {
                        if (inst[4] == 'e') {
                            if (inst[5] == 'v') {
                                if (inst[6] == 'w') return 1318;
                            }
                        }
                    }
                    if (inst[3] == 'l') {
                        if (inst[4] == 'd') {
                            if (inst[5] == 'i') {
                                if (inst[6] == 'a') return 1335;
                                if (inst[6] == 'b') return 1336;
                            }
                        }
                        if (inst[4] == 'u') {
                            if (inst[5] == 'r') {
                                if (inst[6] == 'd') return 1362;
                                if (inst[6] == 'w') return 1360;
                                if (inst[6] == 'b') return 1356;
                                if (inst[6] == 'h') return 1358;
                            }
                        }
                        if (inst[4] == 'w') {
                            if (inst[5] == 'u') {
                                if (inst[6] == 'd') return 1369;
                            }
                            if (inst[5] == 'i') {
                                if (inst[6] == 'a') return 1331;
                                if (inst[6] == 'b') return 1332;
                            }
                        }
                        if (inst[4] == 'b') {
                            if (inst[5] == 'i') {
                                if (inst[6] == 'a') return 1323;
                                if (inst[6] == 'b') return 1324;
                            }
                        }
                        if (inst[4] == 'r') {
                            if (inst[5] == 'w') {
                                if (inst[6] == 'u') return 1350;
                            }
                            if (inst[5] == 'b') {
                                if (inst[6] == 'u') return 1346;
                            }
                            if (inst[5] == 'h') {
                                if (inst[6] == 'u') return 1348;
                            }
                        }
                        if (inst[4] == 'h') {
                            if (inst[5] == 'i') {
                                if (inst[6] == 'a') return 1327;
                                if (inst[6] == 'b') return 1328;
                            }
                        }
                    }
                    if (inst[3] == 'f') {
                        if (inst[4] == 's') {
                            if (inst[5] == 'r') {
                                if (inst[6] == 'd') return 1376;
                                if (inst[6] == 'w') return 1377;
                            }
                        }
                        if (inst[4] == 'l') {
                            if (inst[5] == 'r') {
                                if (inst[6] == 'd') return 1372;
                                if (inst[6] == 'w') return 1373;
                            }
                        }
                    }
                }
            }
        }
        if (inst[0] == 'v') {
            if (inst[1] == 'a') {
                if (inst[2] == 'd') {
                    if (inst[3] == 'd') {
                        if (inst[4] == '.') {
                            if (inst[5] == 'v') {
                                if (inst[6] == 'i') return 894;
                                if (inst[6] == 'x') return 893;
                                if (inst[6] == 'v') return 892;
                            }
                        }
                    }
                }
                if (inst[2] == 'n') {
                    if (inst[3] == 'd') {
                        if (inst[4] == '.') {
                            if (inst[5] == 'v') {
                                if (inst[6] == 'i') return 938;
                                if (inst[6] == 'x') return 937;
                                if (inst[6] == 'v') return 936;
                            }
                        }
                    }
                }
            }
            if (inst[1] == 'd') {
                if (inst[2] == 'i') {
                    if (inst[3] == 'v') {
                        if (inst[4] == '.') {
                            if (inst[5] == 'v') {
                                if (inst[6] == 'x') return 999;
                                if (inst[6] == 'v') return 998;
                            }
                        }
                    }
                }
            }
            if (inst[1] == 'i') {
                if (inst[2] == 'o') {
                    if (inst[3] == 't') {
                        if (inst[4] == 'a') {
                            if (inst[5] == '.') {
                                if (inst[6] == 'm') return 1183;
                            }
                        }
                    }
                }
            }
            if (inst[1] == 's') {
                if (inst[2] == 'u') {
                    if (inst[3] == 'b') {
                        if (inst[4] == '.') {
                            if (inst[5] == 'v') {
                                if (inst[6] == 'x') return 896;
                                if (inst[6] == 'v') return 895;
                            }
                        }
                    }
                }
                if (inst[2] == 'e') {
                    if (inst[3] == '3') {
                        if (inst[4] == '2') {
                            if (inst[5] == '.') {
                                if (inst[6] == 'v') return 588;
                            }
                        }
                    }
                    if (inst[3] == '6') {
                        if (inst[4] == '4') {
                            if (inst[5] == '.') {
                                if (inst[6] == 'v') return 589;
                            }
                        }
                    }
                    if (inst[3] == '1') {
                        if (inst[4] == '6') {
                            if (inst[5] == '.') {
                                if (inst[6] == 'v') return 587;
                            }
                        }
                    }
                    if (inst[3] == 't') {
                        if (inst[4] == 'v') {
                            if (inst[5] == 'l') {
                                if (inst[6] == 'i') return 579;
                            }
                        }
                    }
                }
                if (inst[2] == 's') {
                    if (inst[3] == 'e') {
                        if (inst[4] == '8') {
                            if (inst[5] == '.') {
                                if (inst[6] == 'v') return 596;
                            }
                        }
                    }
                }
                if (inst[2] == 'r') {
                    if (inst[3] == 'a') {
                        if (inst[4] == '.') {
                            if (inst[5] == 'v') {
                                if (inst[6] == 'i') return 953;
                                if (inst[6] == 'x') return 952;
                                if (inst[6] == 'v') return 951;
                            }
                        }
                    }
                    if (inst[3] == 'l') {
                        if (inst[4] == '.') {
                            if (inst[5] == 'v') {
                                if (inst[6] == 'i') return 950;
                                if (inst[6] == 'x') return 949;
                                if (inst[6] == 'v') return 948;
                            }
                        }
                    }
                }
                if (inst[2] == 'l') {
                    if (inst[3] == 'l') {
                        if (inst[4] == '.') {
                            if (inst[5] == 'v') {
                                if (inst[6] == 'i') return 947;
                                if (inst[6] == 'x') return 946;
                                if (inst[6] == 'v') return 945;
                            }
                        }
                    }
                }
            }
            if (inst[1] == 'm') {
                if (inst[2] == 'a') {
                    if (inst[3] == 'x') {
                        if (inst[4] == '.') {
                            if (inst[5] == 'v') {
                                if (inst[6] == 'x') return 987;
                                if (inst[6] == 'v') return 986;
                            }
                        }
                    }
                }
                if (inst[2] == 'u') {
                    if (inst[3] == 'l') {
                        if (inst[4] == '.') {
                            if (inst[5] == 'v') {
                                if (inst[6] == 'x') return 989;
                                if (inst[6] == 'v') return 988;
                            }
                        }
                    }
                }
                if (inst[2] == 'i') {
                    if (inst[3] == 'n') {
                        if (inst[4] == '.') {
                            if (inst[5] == 'v') {
                                if (inst[6] == 'x') return 983;
                                if (inst[6] == 'v') return 982;
                            }
                        }
                    }
                }
                if (inst[2] == 's') {
                    if (inst[3] == 'i') {
                        if (inst[4] == 'f') {
                            if (inst[5] == '.') {
                                if (inst[6] == 'm') return 1181;
                            }
                        }
                    }
                    if (inst[3] == 'o') {
                        if (inst[4] == 'f') {
                            if (inst[5] == '.') {
                                if (inst[6] == 'm') return 1182;
                            }
                        }
                    }
                    if (inst[3] == 'b') {
                        if (inst[4] == 'f') {
                            if (inst[5] == '.') {
                                if (inst[6] == 'm') return 1180;
                            }
                        }
                    }
                }
                if (inst[2] == 'o') {
                    if (inst[3] == 'r') {
                        if (inst[4] == '.') {
                            if (inst[5] == 'm') {
                                if (inst[6] == 'm') return 1174;
                            }
                        }
                    }
                }
                if (inst[2] == 'v') {
                    if (inst[3] == '.') {
                        if (inst[4] == 's') {
                            if (inst[5] == '.') {
                                if (inst[6] == 'x') return 1186;
                            }
                        }
                        if (inst[4] == 'x') {
                            if (inst[5] == '.') {
                                if (inst[6] == 's') return 1185;
                            }
                        }
                        if (inst[4] == 'v') {
                            if (inst[5] == '.') {
                                if (inst[6] == 'i') return 1030;
                                if (inst[6] == 'x') return 1029;
                                if (inst[6] == 'v') return 1028;
                            }
                        }
                    }
                    if (inst[3] == '2') {
                        if (inst[4] == 'r') {
                            if (inst[5] == '.') {
                                if (inst[6] == 'v') return 1203;
                            }
                        }
                    }
                    if (inst[3] == '4') {
                        if (inst[4] == 'r') {
                            if (inst[5] == '.') {
                                if (inst[6] == 'v') return 1204;
                            }
                        }
                    }
                    if (inst[3] == '1') {
                        if (inst[4] == 'r') {
                            if (inst[5] == '.') {
                                if (inst[6] == 'v') return 1202;
                            }
                        }
                    }
                    if (inst[3] == '8') {
                        if (inst[4] == 'r') {
                            if (inst[5] == '.') {
                                if (inst[6] == 'v') return 1205;
                            }
                        }
                    }
                }
            }
            if (inst[1] == 'b') {
                if (inst[2] == 'r') {
                    if (inst[3] == 'e') {
                        if (inst[4] == 'v') {
                            if (inst[5] == '.') {
                                if (inst[6] == 'v') return 1251;
                            }
                        }
                    }
                }
            }
            if (inst[1] == 'r') {
                if (inst[2] == 'e') {
                    if (inst[3] == 'm') {
                        if (inst[4] == '.') {
                            if (inst[5] == 'v') {
                                if (inst[6] == 'x') return 1003;
                                if (inst[6] == 'v') return 1002;
                            }
                        }
                    }
                    if (inst[3] == 'v') {
                        if (inst[4] == '8') {
                            if (inst[5] == '.') {
                                if (inst[6] == 'v') return 1261;
                            }
                        }
                    }
                }
                if (inst[2] == 'o') {
                    if (inst[3] == 'r') {
                        if (inst[4] == '.') {
                            if (inst[5] == 'v') {
                                if (inst[6] == 'i') return 1266;
                                if (inst[6] == 'x') return 1265;
                                if (inst[6] == 'v') return 1264;
                            }
                        }
                    }
                    if (inst[3] == 'l') {
                        if (inst[4] == '.') {
                            if (inst[5] == 'v') {
                                if (inst[6] == 'x') return 1263;
                                if (inst[6] == 'v') return 1262;
                            }
                        }
                    }
                }
            }
            if (inst[1] == 'l') {
                if (inst[2] == 'e') {
                    if (inst[3] == '3') {
                        if (inst[4] == '2') {
                            if (inst[5] == '.') {
                                if (inst[6] == 'v') return 584;
                            }
                        }
                    }
                    if (inst[3] == '6') {
                        if (inst[4] == '4') {
                            if (inst[5] == '.') {
                                if (inst[6] == 'v') return 585;
                            }
                        }
                    }
                    if (inst[3] == '1') {
                        if (inst[4] == '6') {
                            if (inst[5] == '.') {
                                if (inst[6] == 'v') return 583;
                            }
                        }
                    }
                }
                if (inst[2] == 's') {
                    if (inst[3] == 'e') {
                        if (inst[4] == '8') {
                            if (inst[5] == '.') {
                                if (inst[6] == 'v') return 592;
                            }
                        }
                    }
                }
            }
            if (inst[1] == 'c') {
                if (inst[2] == 'p') {
                    if (inst[3] == 'o') {
                        if (inst[4] == 'p') {
                            if (inst[5] == '.') {
                                if (inst[6] == 'm') return 1178;
                            }
                        }
                    }
                }
            }
            if (inst[1] == 'x') {
                if (inst[2] == 'o') {
                    if (inst[3] == 'r') {
                        if (inst[4] == '.') {
                            if (inst[5] == 'v') {
                                if (inst[6] == 'i') return 944;
                                if (inst[6] == 'x') return 943;
                                if (inst[6] == 'v') return 942;
                            }
                        }
                    }
                }
            }
        }
        if (inst[0] == 'f') {
            if (inst[1] == 'e') {
                if (inst[2] == 'n') {
                    if (inst[3] == 'c') {
                        if (inst[4] == 'e') {
                            if (inst[5] == '.') {
                                if (inst[6] == 'i') return 292;
                            }
                        }
                    }
                }
            }
            if (inst[1] == 's') {
                if (inst[2] == 'q') {
                    if (inst[3] == 'r') {
                        if (inst[4] == 't') {
                            if (inst[5] == '.') {
                                if (inst[6] == 'd') return 216;
                                if (inst[6] == 's') return 170;
                                if (inst[6] == 'q') return 234;
                                if (inst[6] == 'h') return 266;
                            }
                        }
                    }
                }
                if (inst[2] == 'g') {
                    if (inst[3] == 'n') {
                        if (inst[4] == 'j') {
                            if (inst[5] == '.') {
                                if (inst[6] == 'd') return 213;
                                if (inst[6] == 's') return 171;
                                if (inst[6] == 'q') return 235;
                                if (inst[6] == 'h') return 267;
                            }
                        }
                    }
                }
            }
            if (inst[1] == 'm') {
                if (inst[2] == 'a') {
                    if (inst[3] == 'd') {
                        if (inst[4] == 'd') {
                            if (inst[5] == '.') {
                                if (inst[6] == 'd') return 193;
                                if (inst[6] == 's') return 162;
                                if (inst[6] == 'q') return 226;
                                if (inst[6] == 'h') return 258;
                            }
                        }
                    }
                    if (inst[3] == 'x') {
                        if (inst[4] == 'm') {
                            if (inst[5] == '.') {
                                if (inst[6] == 'd') return 463;
                                if (inst[6] == 's') return 461;
                                if (inst[6] == 'q') return 465;
                                if (inst[6] == 'h') return 467;
                            }
                        }
                    }
                }
                if (inst[2] == 'i') {
                    if (inst[3] == 'n') {
                        if (inst[4] == 'm') {
                            if (inst[5] == '.') {
                                if (inst[6] == 'd') return 462;
                                if (inst[6] == 's') return 460;
                                if (inst[6] == 'q') return 464;
                                if (inst[6] == 'h') return 466;
                            }
                        }
                    }
                }
                if (inst[2] == 's') {
                    if (inst[3] == 'u') {
                        if (inst[4] == 'b') {
                            if (inst[5] == '.') {
                                if (inst[6] == 'd') return 208;
                                if (inst[6] == 's') return 163;
                                if (inst[6] == 'q') return 227;
                                if (inst[6] == 'h') return 259;
                            }
                        }
                    }
                }
                if (inst[2] == 'v') {
                    if (inst[3] == '.') {
                        if (inst[4] == 'd') {
                            if (inst[5] == '.') {
                                if (inst[6] == 'x') return 223;
                            }
                        }
                        if (inst[4] == 'w') {
                            if (inst[5] == '.') {
                                if (inst[6] == 'x') return 185;
                            }
                        }
                        if (inst[4] == 'h') {
                            if (inst[5] == '.') {
                                if (inst[6] == 'x') return 287;
                            }
                        }
                        if (inst[4] == 'x') {
                            if (inst[5] == '.') {
                                if (inst[6] == 'd') return 220;
                                if (inst[6] == 'w') return 178;
                                if (inst[6] == 'h') return 284;
                            }
                        }
                    }
                }
            }
        }
    }

    if (size == 8) {
        if (inst[0] == 'a') {
            if (inst[1] == 'e') {
                if (inst[2] == 's') {
                    if (inst[3] == '3') {
                        if (inst[4] == '2') {
                            if (inst[5] == 'd') {
                                if (inst[6] == 's') {
                                    if (inst[7] == 'i') return 1206;
                                }
                            }
                            if (inst[5] == 'e') {
                                if (inst[6] == 's') {
                                    if (inst[7] == 'i') return 1208;
                                }
                            }
                        }
                    }
                    if (inst[3] == '6') {
                        if (inst[4] == '4') {
                            if (inst[5] == 'd') {
                                if (inst[6] == 's') {
                                    if (inst[7] == 'm') return 1211;
                                }
                            }
                            if (inst[5] == 'e') {
                                if (inst[6] == 's') {
                                    if (inst[7] == 'm') return 1213;
                                }
                            }
                            if (inst[5] == 'k') {
                                if (inst[6] == 's') {
                                    if (inst[7] == '2') return 1216;
                                }
                            }
                        }
                    }
                }
            }
            if (inst[1] == 'm') {
                if (inst[2] == 'o') {
                    if (inst[3] == 'a') {
                        if (inst[4] == 'd') {
                            if (inst[5] == 'd') {
                                if (inst[6] == '.') {
                                    if (inst[7] == 'd') return 120;
                                    if (inst[7] == 'w') return 76;
                                    if (inst[7] == 'b') return 358;
                                    if (inst[7] == 'h') return 359;
                                }
                            }
                        }
                        if (inst[4] == 'n') {
                            if (inst[5] == 'd') {
                                if (inst[6] == '.') {
                                    if (inst[7] == 'd') return 122;
                                    if (inst[7] == 'w') return 78;
                                    if (inst[7] == 'b') return 360;
                                    if (inst[7] == 'h') return 361;
                                }
                            }
                        }
                    }
                    if (inst[3] == 'm') {
                        if (inst[4] == 'a') {
                            if (inst[5] == 'x') {
                                if (inst[6] == '.') {
                                    if (inst[7] == 'd') return 125;
                                    if (inst[7] == 'w') return 81;
                                    if (inst[7] == 'b') return 366;
                                    if (inst[7] == 'h') return 367;
                                }
                            }
                        }
                        if (inst[4] == 'i') {
                            if (inst[5] == 'n') {
                                if (inst[6] == '.') {
                                    if (inst[7] == 'd') return 124;
                                    if (inst[7] == 'w') return 80;
                                    if (inst[7] == 'b') return 370;
                                    if (inst[7] == 'h') return 371;
                                }
                            }
                        }
                    }
                    if (inst[3] == 'c') {
                        if (inst[4] == 'a') {
                            if (inst[5] == 's') {
                                if (inst[6] == '.') {
                                    if (inst[7] == 'd') return 345;
                                    if (inst[7] == 'w') return 344;
                                    if (inst[7] == 'b') return 374;
                                    if (inst[7] == 'q') return 346;
                                    if (inst[7] == 'h') return 375;
                                }
                            }
                        }
                    }
                    if (inst[3] == 'x') {
                        if (inst[4] == 'o') {
                            if (inst[5] == 'r') {
                                if (inst[6] == '.') {
                                    if (inst[7] == 'd') return 121;
                                    if (inst[7] == 'w') return 77;
                                    if (inst[7] == 'b') return 364;
                                    if (inst[7] == 'h') return 365;
                                }
                            }
                        }
                    }
                }
            }
        }
        if (inst[0] == 'm') {
            if (inst[1] == 'o') {
                if (inst[2] == 'p') {
                    if (inst[3] == '.') {
                        if (inst[4] == 'r') {
                            if (inst[5] == '.') {
                                if (inst[6] == '3') {
                                    if (inst[7] == '1') return 520;
                                    if (inst[7] == '0') return 519;
                                }
                                if (inst[6] == '2') {
                                    if (inst[7] == '3') return 512;
                                    if (inst[7] == '2') return 511;
                                    if (inst[7] == '6') return 515;
                                    if (inst[7] == '4') return 513;
                                    if (inst[7] == '1') return 510;
                                    if (inst[7] == '8') return 517;
                                    if (inst[7] == '0') return 509;
                                    if (inst[7] == '5') return 514;
                                    if (inst[7] == '7') return 516;
                                    if (inst[7] == '9') return 518;
                                }
                                if (inst[6] == '1') {
                                    if (inst[7] == '3') return 502;
                                    if (inst[7] == '2') return 501;
                                    if (inst[7] == '6') return 505;
                                    if (inst[7] == '4') return 503;
                                    if (inst[7] == '1') return 500;
                                    if (inst[7] == '8') return 507;
                                    if (inst[7] == '0') return 499;
                                    if (inst[7] == '5') return 504;
                                    if (inst[7] == '7') return 506;
                                    if (inst[7] == '9') return 508;
                                }
                            }
                            if (inst[5] == 'r') {
                                if (inst[6] == '.') {
                                    if (inst[7] == '3') return 524;
                                    if (inst[7] == '2') return 523;
                                    if (inst[7] == '6') return 527;
                                    if (inst[7] == '4') return 525;
                                    if (inst[7] == '1') return 522;
                                    if (inst[7] == '0') return 521;
                                    if (inst[7] == '5') return 526;
                                    if (inst[7] == '7') return 528;
                                }
                            }
                        }
                    }
                }
            }
        }
        if (inst[0] == 'c') {
            if (inst[1] == '.') {
                if (inst[2] == 'e') {
                    if (inst[3] == 'b') {
                        if (inst[4] == 'r') {
                            if (inst[5] == 'e') {
                                if (inst[6] == 'a') {
                                    if (inst[7] == 'k') return 341;
                                }
                            }
                        }
                    }
                }
                if (inst[2] == 's') {
                    if (inst[3] == 'e') {
                        if (inst[4] == 'x') {
                            if (inst[5] == 't') {
                                if (inst[6] == '.') {
                                    if (inst[7] == 'b') return 442;
                                    if (inst[7] == 'h') return 444;
                                }
                            }
                        }
                    }
                }
                if (inst[2] == 'z') {
                    if (inst[3] == 'e') {
                        if (inst[4] == 'x') {
                            if (inst[5] == 't') {
                                if (inst[6] == '.') {
                                    if (inst[7] == 'w') return 445;
                                    if (inst[7] == 'b') return 441;
                                    if (inst[7] == 'h') return 443;
                                }
                            }
                        }
                    }
                }
            }
            if (inst[1] == 'b') {
                if (inst[2] == 'o') {
                    if (inst[3] == '.') {
                        if (inst[4] == 'z') {
                            if (inst[5] == 'e') {
                                if (inst[6] == 'r') {
                                    if (inst[7] == 'o') return 158;
                                }
                            }
                        }
                    }
                }
            }
        }
        if (inst[0] == 't') {
            if (inst[1] == 'h') {
                if (inst[2] == '.') {
                    if (inst[3] == 'a') {
                        if (inst[4] == 'd') {
                            if (inst[5] == 'd') {
                                if (inst[6] == 's') {
                                    if (inst[7] == 'l') return 1310;
                                }
                            }
                        }
                    }
                    if (inst[3] == 'i') {
                        if (inst[4] == 'p') {
                            if (inst[5] == 'u') {
                                if (inst[6] == 's') {
                                    if (inst[7] == 'h') return 1388;
                                }
                            }
                        }
                    }
                    if (inst[3] == 's') {
                        if (inst[4] == 'r') {
                            if (inst[5] == 'r') {
                                if (inst[6] == 'i') {
                                    if (inst[7] == 'w') return 1312;
                                }
                            }
                        }
                    }
                    if (inst[3] == 'm') {
                        if (inst[4] == 'u') {
                            if (inst[5] == 'l') {
                                if (inst[6] == 'a') {
                                    if (inst[7] == 'w') return 1382;
                                    if (inst[7] == 'h') return 1381;
                                }
                                if (inst[6] == 's') {
                                    if (inst[7] == 'w') return 1385;
                                    if (inst[7] == 'h') return 1384;
                                }
                            }
                        }
                        if (inst[4] == 'v') {
                            if (inst[5] == 'e') {
                                if (inst[6] == 'q') {
                                    if (inst[7] == 'z') return 1321;
                                }
                            }
                            if (inst[5] == 'n') {
                                if (inst[6] == 'e') {
                                    if (inst[7] == 'z') return 1322;
                                }
                            }
                        }
                    }
                    if (inst[3] == 'l') {
                        if (inst[4] == 'u') {
                            if (inst[5] == 'r') {
                                if (inst[6] == 'w') {
                                    if (inst[7] == 'u') return 1361;
                                }
                                if (inst[6] == 'b') {
                                    if (inst[7] == 'u') return 1357;
                                }
                                if (inst[6] == 'h') {
                                    if (inst[7] == 'u') return 1359;
                                }
                            }
                        }
                        if (inst[4] == 'w') {
                            if (inst[5] == 'u') {
                                if (inst[6] == 'i') {
                                    if (inst[7] == 'a') return 1333;
                                    if (inst[7] == 'b') return 1334;
                                }
                            }
                        }
                        if (inst[4] == 'b') {
                            if (inst[5] == 'u') {
                                if (inst[6] == 'i') {
                                    if (inst[7] == 'a') return 1325;
                                    if (inst[7] == 'b') return 1326;
                                }
                            }
                        }
                        if (inst[4] == 'h') {
                            if (inst[5] == 'u') {
                                if (inst[6] == 'i') {
                                    if (inst[7] == 'a') return 1329;
                                    if (inst[7] == 'b') return 1330;
                                }
                            }
                        }
                    }
                    if (inst[3] == 'v') {
                        if (inst[4] == 'i') {
                            if (inst[5] == 'd') {
                                if (inst[6] == '.') {
                                    if (inst[7] == 'v') return 2019;
                                }
                            }
                        }
                        if (inst[4] == 's') {
                            if (inst[5] == 'w') {
                                if (inst[6] == '.') {
                                    if (inst[7] == 'v') return 1408;
                                }
                            }
                            if (inst[5] == 'e') {
                                if (inst[6] == '.') {
                                    if (inst[7] == 'v') return 1409;
                                }
                            }
                            if (inst[5] == 'b') {
                                if (inst[6] == '.') {
                                    if (inst[7] == 'v') return 1406;
                                }
                            }
                            if (inst[5] == 'h') {
                                if (inst[6] == '.') {
                                    if (inst[7] == 'v') return 1407;
                                }
                            }
                        }
                        if (inst[4] == 'l') {
                            if (inst[5] == 'w') {
                                if (inst[6] == '.') {
                                    if (inst[7] == 'v') return 1401;
                                }
                            }
                            if (inst[5] == 'e') {
                                if (inst[6] == '.') {
                                    if (inst[7] == 'v') return 1405;
                                }
                            }
                            if (inst[5] == 'b') {
                                if (inst[6] == '.') {
                                    if (inst[7] == 'v') return 1399;
                                }
                            }
                            if (inst[5] == 'h') {
                                if (inst[6] == '.') {
                                    if (inst[7] == 'v') return 1400;
                                }
                            }
                        }
                    }
                    if (inst[3] == 'f') {
                        if (inst[4] == 's') {
                            if (inst[5] == 'u') {
                                if (inst[6] == 'r') {
                                    if (inst[7] == 'd') return 1378;
                                    if (inst[7] == 'w') return 1379;
                                }
                            }
                        }
                        if (inst[4] == 'l') {
                            if (inst[5] == 'u') {
                                if (inst[6] == 'r') {
                                    if (inst[7] == 'd') return 1374;
                                    if (inst[7] == 'w') return 1375;
                                }
                            }
                        }
                    }
                }
            }
        }
        if (inst[0] == 'v') {
            if (inst[1] == 'a') {
                if (inst[2] == 'a') {
                    if (inst[3] == 'd') {
                        if (inst[4] == 'd') {
                            if (inst[5] == '.') {
                                if (inst[6] == 'v') {
                                    if (inst[7] == 'x') return 1044;
                                    if (inst[7] == 'v') return 1043;
                                }
                            }
                        }
                    }
                }
                if (inst[2] == 'd') {
                    if (inst[3] == 'c') {
                        if (inst[4] == '.') {
                            if (inst[5] == 'v') {
                                if (inst[6] == 'i') {
                                    if (inst[7] == 'm') return 923;
                                }
                                if (inst[6] == 'x') {
                                    if (inst[7] == 'm') return 922;
                                }
                                if (inst[6] == 'v') {
                                    if (inst[7] == 'm') return 921;
                                }
                            }
                        }
                    }
                }
                if (inst[2] == 'e') {
                    if (inst[3] == 's') {
                        if (inst[4] == 'z') {
                            if (inst[5] == '.') {
                                if (inst[6] == 'v') {
                                    if (inst[7] == 's') return 1248;
                                }
                            }
                        }
                    }
                }
                if (inst[2] == 's') {
                    if (inst[3] == 'u') {
                        if (inst[4] == 'b') {
                            if (inst[5] == '.') {
                                if (inst[6] == 'v') {
                                    if (inst[7] == 'x') return 1048;
                                    if (inst[7] == 'v') return 1047;
                                }
                            }
                        }
                    }
                }
                if (inst[2] == 'n') {
                    if (inst[3] == 'd') {
                        if (inst[4] == 'n') {
                            if (inst[5] == '.') {
                                if (inst[6] == 'v') {
                                    if (inst[7] == 'x') return 1250;
                                    if (inst[7] == 'v') return 1249;
                                }
                            }
                        }
                    }
                }
            }
            if (inst[1] == 'd') {
                if (inst[2] == 'i') {
                    if (inst[3] == 'v') {
                        if (inst[4] == 'u') {
                            if (inst[5] == '.') {
                                if (inst[6] == 'v') {
                                    if (inst[7] == 'x') return 997;
                                    if (inst[7] == 'v') return 996;
                                }
                            }
                        }
                    }
                }
            }
            if (inst[1] == 'w') {
                if (inst[2] == 'a') {
                    if (inst[3] == 'd') {
                        if (inst[4] == 'd') {
                            if (inst[5] == '.') {
                                if (inst[6] == 'w') {
                                    if (inst[7] == 'x') return 912;
                                    if (inst[7] == 'v') return 911;
                                }
                                if (inst[6] == 'v') {
                                    if (inst[7] == 'x') return 904;
                                    if (inst[7] == 'v') return 903;
                                }
                            }
                        }
                    }
                }
                if (inst[2] == 's') {
                    if (inst[3] == 'u') {
                        if (inst[4] == 'b') {
                            if (inst[5] == '.') {
                                if (inst[6] == 'w') {
                                    if (inst[7] == 'x') return 914;
                                    if (inst[7] == 'v') return 913;
                                }
                                if (inst[6] == 'v') {
                                    if (inst[7] == 'x') return 906;
                                    if (inst[7] == 'v') return 905;
                                }
                            }
                        }
                    }
                    if (inst[3] == 'l') {
                        if (inst[4] == 'l') {
                            if (inst[5] == '.') {
                                if (inst[6] == 'v') {
                                    if (inst[7] == 'i') return 1277;
                                    if (inst[7] == 'x') return 1276;
                                    if (inst[7] == 'v') return 1275;
                                }
                            }
                        }
                    }
                }
                if (inst[2] == 'm') {
                    if (inst[3] == 'u') {
                        if (inst[4] == 'l') {
                            if (inst[5] == '.') {
                                if (inst[6] == 'v') {
                                    if (inst[7] == 'x') return 1005;
                                    if (inst[7] == 'v') return 1004;
                                }
                            }
                        }
                    }
                }
            }
            if (inst[1] == 's') {
                if (inst[2] == 'a') {
                    if (inst[3] == 'd') {
                        if (inst[4] == 'd') {
                            if (inst[5] == '.') {
                                if (inst[6] == 'v') {
                                    if (inst[7] == 'i') return 1036;
                                    if (inst[7] == 'x') return 1035;
                                    if (inst[7] == 'v') return 1034;
                                }
                            }
                        }
                    }
                }
                if (inst[2] == 'e') {
                    if (inst[3] == 't') {
                        if (inst[4] == 'i') {
                            if (inst[5] == 'v') {
                                if (inst[6] == 'l') {
                                    if (inst[7] == 'i') return 580;
                                }
                            }
                        }
                    }
                }
                if (inst[2] == 's') {
                    if (inst[3] == 'u') {
                        if (inst[4] == 'b') {
                            if (inst[5] == '.') {
                                if (inst[6] == 'v') {
                                    if (inst[7] == 'x') return 1040;
                                    if (inst[7] == 'v') return 1039;
                                }
                            }
                        }
                    }
                    if (inst[3] == 'e') {
                        if (inst[4] == '3') {
                            if (inst[5] == '2') {
                                if (inst[6] == '.') {
                                    if (inst[7] == 'v') return 598;
                                }
                            }
                        }
                        if (inst[4] == '6') {
                            if (inst[5] == '4') {
                                if (inst[6] == '.') {
                                    if (inst[7] == 'v') return 599;
                                }
                            }
                        }
                        if (inst[4] == '1') {
                            if (inst[5] == '6') {
                                if (inst[6] == '.') {
                                    if (inst[7] == 'v') return 597;
                                }
                            }
                        }
                    }
                    if (inst[3] == 'r') {
                        if (inst[4] == 'a') {
                            if (inst[5] == '.') {
                                if (inst[6] == 'v') {
                                    if (inst[7] == 'i') return 1056;
                                    if (inst[7] == 'x') return 1055;
                                    if (inst[7] == 'v') return 1054;
                                }
                            }
                        }
                        if (inst[4] == 'l') {
                            if (inst[5] == '.') {
                                if (inst[6] == 'v') {
                                    if (inst[7] == 'i') return 1053;
                                    if (inst[7] == 'x') return 1052;
                                    if (inst[7] == 'v') return 1051;
                                }
                            }
                        }
                    }
                }
                if (inst[2] == 'm') {
                    if (inst[3] == 'u') {
                        if (inst[4] == 'l') {
                            if (inst[5] == '.') {
                                if (inst[6] == 'v') {
                                    if (inst[7] == 'x') return 1050;
                                    if (inst[7] == 'v') return 1049;
                                }
                            }
                        }
                    }
                    if (inst[3] == '3') {
                        if (inst[4] == 'c') {
                            if (inst[5] == '.') {
                                if (inst[6] == 'v') {
                                    if (inst[7] == 'i') return 1270;
                                }
                            }
                        }
                    }
                    if (inst[3] == '4') {
                        if (inst[4] == 'k') {
                            if (inst[5] == '.') {
                                if (inst[6] == 'v') {
                                    if (inst[7] == 'i') return 1272;
                                }
                            }
                        }
                        if (inst[4] == 'r') {
                            if (inst[5] == '.') {
                                if (inst[6] == 'v') {
                                    if (inst[7] == 's') return 1274;
                                    if (inst[7] == 'v') return 1273;
                                }
                            }
                        }
                    }
                }
                if (inst[2] == 'b') {
                    if (inst[3] == 'c') {
                        if (inst[4] == '.') {
                            if (inst[5] == 'v') {
                                if (inst[6] == 'x') {
                                    if (inst[7] == 'm') return 931;
                                }
                                if (inst[6] == 'v') {
                                    if (inst[7] == 'm') return 930;
                                }
                            }
                        }
                    }
                }
            }
            if (inst[1] == 'm') {
                if (inst[2] == 'a') {
                    if (inst[3] == 'd') {
                        if (inst[4] == 'd') {
                            if (inst[5] == '.') {
                                if (inst[6] == 'v') {
                                    if (inst[7] == 'x') return 1015;
                                    if (inst[7] == 'v') return 1014;
                                }
                            }
                        }
                        if (inst[4] == 'c') {
                            if (inst[5] == '.') {
                                if (inst[6] == 'v') {
                                    if (inst[7] == 'i') return 929;
                                    if (inst[7] == 'x') return 928;
                                    if (inst[7] == 'v') return 927;
                                }
                            }
                        }
                    }
                    if (inst[3] == 'n') {
                        if (inst[4] == 'd') {
                            if (inst[5] == '.') {
                                if (inst[6] == 'm') {
                                    if (inst[7] == 'm') return 1170;
                                }
                            }
                        }
                    }
                    if (inst[3] == 'c') {
                        if (inst[4] == 'c') {
                            if (inst[5] == '.') {
                                if (inst[6] == 'v') {
                                    if (inst[7] == 'x') return 1011;
                                    if (inst[7] == 'v') return 1010;
                                }
                            }
                        }
                    }
                    if (inst[3] == 'x') {
                        if (inst[4] == 'u') {
                            if (inst[5] == '.') {
                                if (inst[6] == 'v') {
                                    if (inst[7] == 'x') return 985;
                                    if (inst[7] == 'v') return 984;
                                }
                            }
                        }
                    }
                }
                if (inst[2] == 'u') {
                    if (inst[3] == 'l') {
                        if (inst[4] == 'h') {
                            if (inst[5] == '.') {
                                if (inst[6] == 'v') {
                                    if (inst[7] == 'x') return 991;
                                    if (inst[7] == 'v') return 990;
                                }
                            }
                        }
                    }
                }
                if (inst[2] == 'i') {
                    if (inst[3] == 'n') {
                        if (inst[4] == 'u') {
                            if (inst[5] == '.') {
                                if (inst[6] == 'v') {
                                    if (inst[7] == 'x') return 981;
                                    if (inst[7] == 'v') return 980;
                                }
                            }
                        }
                    }
                }
                if (inst[2] == 's') {
                    if (inst[3] == 'e') {
                        if (inst[4] == 'q') {
                            if (inst[5] == '.') {
                                if (inst[6] == 'v') {
                                    if (inst[7] == 'i') return 962;
                                    if (inst[7] == 'x') return 961;
                                    if (inst[7] == 'v') return 960;
                                }
                            }
                        }
                    }
                    if (inst[3] == 'b') {
                        if (inst[4] == 'c') {
                            if (inst[5] == '.') {
                                if (inst[6] == 'v') {
                                    if (inst[7] == 'x') return 935;
                                    if (inst[7] == 'v') return 934;
                                }
                            }
                        }
                    }
                    if (inst[3] == 'l') {
                        if (inst[4] == 'e') {
                            if (inst[5] == '.') {
                                if (inst[6] == 'v') {
                                    if (inst[7] == 'i') return 975;
                                    if (inst[7] == 'x') return 974;
                                    if (inst[7] == 'v') return 973;
                                }
                            }
                        }
                        if (inst[4] == 't') {
                            if (inst[5] == '.') {
                                if (inst[6] == 'v') {
                                    if (inst[7] == 'x') return 969;
                                    if (inst[7] == 'v') return 968;
                                }
                            }
                        }
                    }
                    if (inst[3] == 'n') {
                        if (inst[4] == 'e') {
                            if (inst[5] == '.') {
                                if (inst[6] == 'v') {
                                    if (inst[7] == 'i') return 965;
                                    if (inst[7] == 'x') return 964;
                                    if (inst[7] == 'v') return 963;
                                }
                            }
                        }
                    }
                    if (inst[3] == 'g') {
                        if (inst[4] == 't') {
                            if (inst[5] == '.') {
                                if (inst[6] == 'v') {
                                    if (inst[7] == 'i') return 979;
                                    if (inst[7] == 'x') return 978;
                                }
                            }
                        }
                    }
                }
                if (inst[2] == 'o') {
                    if (inst[3] == 'r') {
                        if (inst[4] == 'n') {
                            if (inst[5] == '.') {
                                if (inst[6] == 'm') {
                                    if (inst[7] == 'm') return 1176;
                                }
                            }
                        }
                    }
                }
                if (inst[2] == 'n') {
                    if (inst[3] == 'o') {
                        if (inst[4] == 'r') {
                            if (inst[5] == '.') {
                                if (inst[6] == 'm') {
                                    if (inst[7] == 'm') return 1175;
                                }
                            }
                        }
                    }
                }
                if (inst[2] == 'x') {
                    if (inst[3] == 'o') {
                        if (inst[4] == 'r') {
                            if (inst[5] == '.') {
                                if (inst[6] == 'm') {
                                    if (inst[7] == 'm') return 1173;
                                }
                            }
                        }
                    }
                }
                if (inst[2] == 'f') {
                    if (inst[3] == 'e') {
                        if (inst[4] == 'q') {
                            if (inst[5] == '.') {
                                if (inst[6] == 'v') {
                                    if (inst[7] == 'v') return 1120;
                                    if (inst[7] == 'f') return 1121;
                                }
                            }
                        }
                    }
                    if (inst[3] == 'l') {
                        if (inst[4] == 'e') {
                            if (inst[5] == '.') {
                                if (inst[6] == 'v') {
                                    if (inst[7] == 'v') return 1126;
                                    if (inst[7] == 'f') return 1127;
                                }
                            }
                        }
                        if (inst[4] == 't') {
                            if (inst[5] == '.') {
                                if (inst[6] == 'v') {
                                    if (inst[7] == 'v') return 1124;
                                    if (inst[7] == 'f') return 1125;
                                }
                            }
                        }
                    }
                    if (inst[3] == 'n') {
                        if (inst[4] == 'e') {
                            if (inst[5] == '.') {
                                if (inst[6] == 'v') {
                                    if (inst[7] == 'v') return 1122;
                                    if (inst[7] == 'f') return 1123;
                                }
                            }
                        }
                    }
                    if (inst[3] == 'g') {
                        if (inst[4] == 'e') {
                            if (inst[5] == '.') {
                                if (inst[6] == 'v') {
                                    if (inst[7] == 'f') return 1129;
                                }
                            }
                        }
                        if (inst[4] == 't') {
                            if (inst[5] == '.') {
                                if (inst[6] == 'v') {
                                    if (inst[7] == 'f') return 1128;
                                }
                            }
                        }
                    }
                }
            }
            if (inst[1] == 'b') {
                if (inst[2] == 'r') {
                    if (inst[3] == 'e') {
                        if (inst[4] == 'v') {
                            if (inst[5] == '8') {
                                if (inst[6] == '.') {
                                    if (inst[7] == 'v') return 1252;
                                }
                            }
                        }
                    }
                }
            }
            if (inst[1] == 'r') {
                if (inst[2] == 'e') {
                    if (inst[3] == 'm') {
                        if (inst[4] == 'u') {
                            if (inst[5] == '.') {
                                if (inst[6] == 'v') {
                                    if (inst[7] == 'x') return 1001;
                                    if (inst[7] == 'v') return 1000;
                                }
                            }
                        }
                    }
                }
                if (inst[2] == 's') {
                    if (inst[3] == 'u') {
                        if (inst[4] == 'b') {
                            if (inst[5] == '.') {
                                if (inst[6] == 'v') {
                                    if (inst[7] == 'i') return 898;
                                    if (inst[7] == 'x') return 897;
                                }
                            }
                        }
                    }
                }
            }
            if (inst[1] == 'l') {
                if (inst[2] == 'e') {
                    if (inst[3] == '8') {
                        if (inst[4] == 'f') {
                            if (inst[5] == 'f') {
                                if (inst[6] == '.') {
                                    if (inst[7] == 'v') return 616;
                                }
                            }
                        }
                    }
                }
                if (inst[2] == 's') {
                    if (inst[3] == 'e') {
                        if (inst[4] == '3') {
                            if (inst[5] == '2') {
                                if (inst[6] == '.') {
                                    if (inst[7] == 'v') return 594;
                                }
                            }
                        }
                        if (inst[4] == '6') {
                            if (inst[5] == '4') {
                                if (inst[6] == '.') {
                                    if (inst[7] == 'v') return 595;
                                }
                            }
                        }
                        if (inst[4] == '1') {
                            if (inst[5] == '6') {
                                if (inst[6] == '.') {
                                    if (inst[7] == 'v') return 593;
                                }
                            }
                        }
                    }
                }
                if (inst[2] == '2') {
                    if (inst[3] == 'r') {
                        if (inst[4] == 'e') {
                            if (inst[5] == '8') {
                                if (inst[6] == '.') {
                                    if (inst[7] == 'v') return 876;
                                }
                            }
                        }
                    }
                }
                if (inst[2] == '4') {
                    if (inst[3] == 'r') {
                        if (inst[4] == 'e') {
                            if (inst[5] == '8') {
                                if (inst[6] == '.') {
                                    if (inst[7] == 'v') return 880;
                                }
                            }
                        }
                    }
                }
                if (inst[2] == '1') {
                    if (inst[3] == 'r') {
                        if (inst[4] == 'e') {
                            if (inst[5] == '8') {
                                if (inst[6] == '.') {
                                    if (inst[7] == 'v') return 872;
                                }
                            }
                        }
                    }
                }
                if (inst[2] == '8') {
                    if (inst[3] == 'r') {
                        if (inst[4] == 'e') {
                            if (inst[5] == '8') {
                                if (inst[6] == '.') {
                                    if (inst[7] == 'v') return 884;
                                }
                            }
                        }
                    }
                }
            }
            if (inst[1] == 'n') {
                if (inst[2] == 's') {
                    if (inst[3] == 'r') {
                        if (inst[4] == 'a') {
                            if (inst[5] == '.') {
                                if (inst[6] == 'w') {
                                    if (inst[7] == 'i') return 959;
                                    if (inst[7] == 'x') return 958;
                                    if (inst[7] == 'v') return 957;
                                }
                            }
                        }
                        if (inst[4] == 'l') {
                            if (inst[5] == '.') {
                                if (inst[6] == 'w') {
                                    if (inst[7] == 'i') return 956;
                                    if (inst[7] == 'x') return 955;
                                    if (inst[7] == 'v') return 954;
                                }
                            }
                        }
                    }
                }
            }
            if (inst[1] == 'g') {
                if (inst[2] == 'm') {
                    if (inst[3] == 'u') {
                        if (inst[4] == 'l') {
                            if (inst[5] == '.') {
                                if (inst[6] == 'v') {
                                    if (inst[7] == 'v') return 1260;
                                }
                            }
                        }
                    }
                }
                if (inst[2] == 'h') {
                    if (inst[3] == 's') {
                        if (inst[4] == 'h') {
                            if (inst[5] == '.') {
                                if (inst[6] == 'v') {
                                    if (inst[7] == 'v') return 1259;
                                }
                            }
                        }
                    }
                }
            }
            if (inst[1] == 'f') {
                if (inst[2] == 'a') {
                    if (inst[3] == 'd') {
                        if (inst[4] == 'd') {
                            if (inst[5] == '.') {
                                if (inst[6] == 'v') {
                                    if (inst[7] == 'v') return 1063;
                                    if (inst[7] == 'f') return 1064;
                                }
                            }
                        }
                    }
                }
                if (inst[2] == 'd') {
                    if (inst[3] == 'i') {
                        if (inst[4] == 'v') {
                            if (inst[5] == '.') {
                                if (inst[6] == 'v') {
                                    if (inst[7] == 'v') return 1078;
                                    if (inst[7] == 'f') return 1079;
                                }
                            }
                        }
                    }
                }
                if (inst[2] == 'i') {
                    if (inst[3] == 'r') {
                        if (inst[4] == 's') {
                            if (inst[5] == 't') {
                                if (inst[6] == '.') {
                                    if (inst[7] == 'm') return 1179;
                                }
                            }
                        }
                    }
                }
                if (inst[2] == 's') {
                    if (inst[3] == 'u') {
                        if (inst[4] == 'b') {
                            if (inst[5] == '.') {
                                if (inst[6] == 'v') {
                                    if (inst[7] == 'v') return 1065;
                                    if (inst[7] == 'f') return 1066;
                                }
                            }
                        }
                    }
                    if (inst[3] == 'q') {
                        if (inst[4] == 'r') {
                            if (inst[5] == 't') {
                                if (inst[6] == '.') {
                                    if (inst[7] == 'v') return 1107;
                                }
                            }
                        }
                    }
                }
                if (inst[2] == 'm') {
                    if (inst[3] == 'a') {
                        if (inst[4] == 'x') {
                            if (inst[5] == '.') {
                                if (inst[6] == 'v') {
                                    if (inst[7] == 'v') return 1112;
                                    if (inst[7] == 'f') return 1113;
                                }
                            }
                        }
                    }
                    if (inst[3] == 'u') {
                        if (inst[4] == 'l') {
                            if (inst[5] == '.') {
                                if (inst[6] == 'v') {
                                    if (inst[7] == 'v') return 1076;
                                    if (inst[7] == 'f') return 1077;
                                }
                            }
                        }
                    }
                    if (inst[3] == 'i') {
                        if (inst[4] == 'n') {
                            if (inst[5] == '.') {
                                if (inst[6] == 'v') {
                                    if (inst[7] == 'v') return 1110;
                                    if (inst[7] == 'f') return 1111;
                                }
                            }
                        }
                    }
                    if (inst[3] == 'v') {
                        if (inst[4] == '.') {
                            if (inst[5] == 's') {
                                if (inst[6] == '.') {
                                    if (inst[7] == 'f') return 1188;
                                }
                            }
                            if (inst[5] == 'v') {
                                if (inst[6] == '.') {
                                    if (inst[7] == 'f') return 1132;
                                }
                            }
                            if (inst[5] == 'f') {
                                if (inst[6] == '.') {
                                    if (inst[7] == 's') return 1187;
                                }
                            }
                        }
                    }
                }
                if (inst[2] == 'r') {
                    if (inst[3] == 'e') {
                        if (inst[4] == 'c') {
                            if (inst[5] == '7') {
                                if (inst[6] == '.') {
                                    if (inst[7] == 'v') return 1109;
                                }
                            }
                        }
                    }
                }
            }
        }
        if (inst[0] == 'f') {
            if (inst[1] == 's') {
                if (inst[2] == 'g') {
                    if (inst[3] == 'n') {
                        if (inst[4] == 'j') {
                            if (inst[5] == 'n') {
                                if (inst[6] == '.') {
                                    if (inst[7] == 'd') return 214;
                                    if (inst[7] == 's') return 172;
                                    if (inst[7] == 'q') return 236;
                                    if (inst[7] == 'h') return 268;
                                }
                            }
                            if (inst[5] == 'x') {
                                if (inst[6] == '.') {
                                    if (inst[7] == 'd') return 215;
                                    if (inst[7] == 's') return 173;
                                    if (inst[7] == 'q') return 237;
                                    if (inst[7] == 'h') return 269;
                                }
                            }
                        }
                    }
                }
            }
            if (inst[1] == 'm') {
                if (inst[2] == 'v') {
                    if (inst[3] == 'h') {
                        if (inst[4] == '.') {
                            if (inst[5] == 'x') {
                                if (inst[6] == '.') {
                                    if (inst[7] == 'd') return 477;
                                    if (inst[7] == 'q') return 479;
                                }
                            }
                        }
                    }
                    if (inst[3] == 'p') {
                        if (inst[4] == '.') {
                            if (inst[5] == 'd') {
                                if (inst[6] == '.') {
                                    if (inst[7] == 'x') return 478;
                                }
                            }
                            if (inst[5] == 'q') {
                                if (inst[6] == '.') {
                                    if (inst[7] == 'x') return 480;
                                }
                            }
                        }
                    }
                }
            }
            if (inst[1] == 'r') {
                if (inst[2] == 'o') {
                    if (inst[3] == 'u') {
                        if (inst[4] == 'n') {
                            if (inst[5] == 'd') {
                                if (inst[6] == '.') {
                                    if (inst[7] == 'd') return 470;
                                    if (inst[7] == 's') return 468;
                                    if (inst[7] == 'q') return 474;
                                    if (inst[7] == 'h') return 472;
                                }
                            }
                        }
                    }
                }
            }
            if (inst[1] == 'n') {
                if (inst[2] == 'm') {
                    if (inst[3] == 'a') {
                        if (inst[4] == 'd') {
                            if (inst[5] == 'd') {
                                if (inst[6] == '.') {
                                    if (inst[7] == 'd') return 210;
                                    if (inst[7] == 's') return 165;
                                    if (inst[7] == 'q') return 229;
                                    if (inst[7] == 'h') return 261;
                                }
                            }
                        }
                    }
                    if (inst[3] == 's') {
                        if (inst[4] == 'u') {
                            if (inst[5] == 'b') {
                                if (inst[6] == '.') {
                                    if (inst[7] == 'd') return 211;
                                    if (inst[7] == 's') return 164;
                                    if (inst[7] == 'q') return 228;
                                    if (inst[7] == 'h') return 260;
                                }
                            }
                        }
                    }
                }
            }
            if (inst[1] == 'c') {
                if (inst[2] == 'l') {
                    if (inst[3] == 'a') {
                        if (inst[4] == 's') {
                            if (inst[5] == 's') {
                                if (inst[6] == '.') {
                                    if (inst[7] == 'd') return 195;
                                    if (inst[7] == 's') return 182;
                                    if (inst[7] == 'q') return 247;
                                    if (inst[7] == 'h') return 281;
                                }
                            }
                        }
                    }
                }
                if (inst[2] == 'v') {
                    if (inst[3] == 't') {
                        if (inst[4] == '.') {
                            if (inst[5] == 'd') {
                                if (inst[6] == '.') {
                                    if (inst[7] == 'w') return 197;
                                    if (inst[7] == 's') return 196;
                                    if (inst[7] == 'q') return 242;
                                    if (inst[7] == 'l') return 221;
                                    if (inst[7] == 'h') return 274;
                                }
                            }
                            if (inst[5] == 'w') {
                                if (inst[6] == '.') {
                                    if (inst[7] == 'd') return 200;
                                    if (inst[7] == 's') return 176;
                                    if (inst[7] == 'q') return 248;
                                    if (inst[7] == 'h') return 282;
                                }
                            }
                            if (inst[5] == 's') {
                                if (inst[6] == '.') {
                                    if (inst[7] == 'd') return 199;
                                    if (inst[7] == 'w') return 183;
                                    if (inst[7] == 'q') return 240;
                                    if (inst[7] == 'l') return 190;
                                    if (inst[7] == 'h') return 272;
                                }
                            }
                            if (inst[5] == 'q') {
                                if (inst[6] == '.') {
                                    if (inst[7] == 'd') return 243;
                                    if (inst[7] == 'w') return 250;
                                    if (inst[7] == 's') return 241;
                                    if (inst[7] == 'l') return 254;
                                    if (inst[7] == 'h') return 276;
                                }
                            }
                            if (inst[5] == 'l') {
                                if (inst[6] == '.') {
                                    if (inst[7] == 'd') return 218;
                                    if (inst[7] == 's') return 188;
                                    if (inst[7] == 'q') return 252;
                                    if (inst[7] == 'h') return 288;
                                }
                            }
                            if (inst[5] == 'h') {
                                if (inst[6] == '.') {
                                    if (inst[7] == 'd') return 275;
                                    if (inst[7] == 'w') return 285;
                                    if (inst[7] == 's') return 273;
                                    if (inst[7] == 'q') return 277;
                                    if (inst[7] == 'l') return 290;
                                }
                            }
                        }
                    }
                }
            }
        }
    }

    if (size == 9) {
        if (inst[0] == 'a') {
            if (inst[1] == 'e') {
                if (inst[2] == 's') {
                    if (inst[3] == '3') {
                        if (inst[4] == '2') {
                            if (inst[5] == 'd') {
                                if (inst[6] == 's') {
                                    if (inst[7] == 'm') {
                                        if (inst[8] == 'i') return 1207;
                                    }
                                }
                            }
                            if (inst[5] == 'e') {
                                if (inst[6] == 's') {
                                    if (inst[7] == 'm') {
                                        if (inst[8] == 'i') return 1209;
                                    }
                                }
                            }
                        }
                    }
                    if (inst[3] == '6') {
                        if (inst[4] == '4') {
                            if (inst[5] == 'k') {
                                if (inst[6] == 's') {
                                    if (inst[7] == '1') {
                                        if (inst[8] == 'i') return 1215;
                                    }
                                }
                            }
                        }
                    }
                }
            }
            if (inst[1] == 'm') {
                if (inst[2] == 'o') {
                    if (inst[3] == 's') {
                        if (inst[4] == 'w') {
                            if (inst[5] == 'a') {
                                if (inst[6] == 'p') {
                                    if (inst[7] == '.') {
                                        if (inst[8] == 'd') return 119;
                                        if (inst[8] == 'w') return 75;
                                        if (inst[8] == 'b') return 356;
                                        if (inst[8] == 'h') return 357;
                                    }
                                }
                            }
                        }
                    }
                    if (inst[3] == 'm') {
                        if (inst[4] == 'a') {
                            if (inst[5] == 'x') {
                                if (inst[6] == 'u') {
                                    if (inst[7] == '.') {
                                        if (inst[8] == 'd') return 127;
                                        if (inst[8] == 'w') return 83;
                                        if (inst[8] == 'b') return 368;
                                        if (inst[8] == 'h') return 369;
                                    }
                                }
                            }
                        }
                        if (inst[4] == 'i') {
                            if (inst[5] == 'n') {
                                if (inst[6] == 'u') {
                                    if (inst[7] == '.') {
                                        if (inst[8] == 'd') return 126;
                                        if (inst[8] == 'w') return 82;
                                        if (inst[8] == 'b') return 372;
                                        if (inst[8] == 'h') return 373;
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
        if (inst[0] == 's') {
            if (inst[1] == 'h') {
                if (inst[2] == '3') {
                    if (inst[3] == 'a') {
                        if (inst[4] == 'd') {
                            if (inst[5] == 'd') {
                                if (inst[6] == '.') {
                                    if (inst[7] == 'u') {
                                        if (inst[8] == 'w') return 571;
                                    }
                                }
                            }
                        }
                    }
                }
                if (inst[2] == '2') {
                    if (inst[3] == 'a') {
                        if (inst[4] == 'd') {
                            if (inst[5] == 'd') {
                                if (inst[6] == '.') {
                                    if (inst[7] == 'u') {
                                        if (inst[8] == 'w') return 569;
                                    }
                                }
                            }
                        }
                    }
                }
                if (inst[2] == '1') {
                    if (inst[3] == 'a') {
                        if (inst[4] == 'd') {
                            if (inst[5] == 'd') {
                                if (inst[6] == '.') {
                                    if (inst[7] == 'u') {
                                        if (inst[8] == 'w') return 567;
                                    }
                                }
                            }
                        }
                    }
                }
            }
            if (inst[1] == 'c') {
                if (inst[2] == '.') {
                    if (inst[3] == 'd') {
                        if (inst[4] == '.') {
                            if (inst[5] == 'a') {
                                if (inst[6] == 'q') {
                                    if (inst[7] == 'r') {
                                        if (inst[8] == 'l') return 118;
                                    }
                                }
                            }
                        }
                    }
                    if (inst[3] == 'w') {
                        if (inst[4] == '.') {
                            if (inst[5] == 'a') {
                                if (inst[6] == 'q') {
                                    if (inst[7] == 'r') {
                                        if (inst[8] == 'l') return 74;
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
        if (inst[0] == 'l') {
            if (inst[1] == 'r') {
                if (inst[2] == '.') {
                    if (inst[3] == 'd') {
                        if (inst[4] == '.') {
                            if (inst[5] == 'a') {
                                if (inst[6] == 'q') {
                                    if (inst[7] == 'r') {
                                        if (inst[8] == 'l') return 117;
                                    }
                                }
                            }
                        }
                    }
                    if (inst[3] == 'w') {
                        if (inst[4] == '.') {
                            if (inst[5] == 'a') {
                                if (inst[6] == 'q') {
                                    if (inst[7] == 'r') {
                                        if (inst[8] == 'l') return 73;
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
        if (inst[0] == 'c') {
            if (inst[1] == 'm') {
                if (inst[2] == '.') {
                    if (inst[3] == 'm') {
                        if (inst[4] == 'v') {
                            if (inst[5] == 'a') {
                                if (inst[6] == '0') {
                                    if (inst[7] == '1') {
                                        if (inst[8] == 's') return 453;
                                    }
                                }
                            }
                            if (inst[5] == 's') {
                                if (inst[6] == 'a') {
                                    if (inst[7] == '0') {
                                        if (inst[8] == '1') return 452;
                                    }
                                }
                            }
                        }
                    }
                    if (inst[3] == 'p') {
                        if (inst[4] == 'o') {
                            if (inst[5] == 'p') {
                                if (inst[6] == 'r') {
                                    if (inst[7] == 'e') {
                                        if (inst[8] == 't') return 451;
                                    }
                                }
                            }
                        }
                    }
                }
            }
            if (inst[1] == 'b') {
                if (inst[2] == 'o') {
                    if (inst[3] == '.') {
                        if (inst[4] == 'i') {
                            if (inst[5] == 'n') {
                                if (inst[6] == 'v') {
                                    if (inst[7] == 'a') {
                                        if (inst[8] == 'l') return 157;
                                    }
                                }
                            }
                        }
                        if (inst[4] == 'c') {
                            if (inst[5] == 'l') {
                                if (inst[6] == 'e') {
                                    if (inst[7] == 'a') {
                                        if (inst[8] == 'n') return 155;
                                    }
                                }
                            }
                        }
                        if (inst[4] == 'f') {
                            if (inst[5] == 'l') {
                                if (inst[6] == 'u') {
                                    if (inst[7] == 's') {
                                        if (inst[8] == 'h') return 156;
                                    }
                                }
                            }
                        }
                    }
                }
            }
            if (inst[1] == 'z') {
                if (inst[2] == 'e') {
                    if (inst[3] == 'r') {
                        if (inst[4] == 'o') {
                            if (inst[5] == '.') {
                                if (inst[6] == 'e') {
                                    if (inst[7] == 'q') {
                                        if (inst[8] == 'z') return 342;
                                    }
                                }
                                if (inst[6] == 'n') {
                                    if (inst[7] == 'e') {
                                        if (inst[8] == 'z') return 343;
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
        if (inst[0] == 't') {
            if (inst[1] == 'h') {
                if (inst[2] == '.') {
                    if (inst[3] == 's') {
                        if (inst[4] == 'y') {
                            if (inst[5] == 'n') {
                                if (inst[6] == 'c') {
                                    if (inst[7] == '.') {
                                        if (inst[8] == 'i') return 1308;
                                        if (inst[8] == 's') return 1307;
                                    }
                                }
                            }
                        }
                    }
                    if (inst[3] == 't') {
                        if (inst[4] == 's') {
                            if (inst[5] == 't') {
                                if (inst[6] == 'n') {
                                    if (inst[7] == 'b') {
                                        if (inst[8] == 'z') return 1319;
                                    }
                                }
                            }
                        }
                    }
                    if (inst[3] == 'v') {
                        if (inst[4] == 's') {
                            if (inst[5] == 'e') {
                                if (inst[6] == 't') {
                                    if (inst[7] == 'v') {
                                        if (inst[8] == 'l') return 1398;
                                    }
                                }
                            }
                            if (inst[5] == 's') {
                                if (inst[6] == 'w') {
                                    if (inst[7] == '.') {
                                        if (inst[8] == 'v') return 1419;
                                    }
                                }
                                if (inst[6] == 'e') {
                                    if (inst[7] == '.') {
                                        if (inst[8] == 'v') return 1420;
                                    }
                                }
                                if (inst[6] == 'b') {
                                    if (inst[7] == '.') {
                                        if (inst[8] == 'v') return 1417;
                                    }
                                }
                                if (inst[6] == 'h') {
                                    if (inst[7] == '.') {
                                        if (inst[8] == 'v') return 1418;
                                    }
                                }
                            }
                            if (inst[5] == 'x') {
                                if (inst[6] == 'w') {
                                    if (inst[7] == '.') {
                                        if (inst[8] == 'v') return 1430;
                                    }
                                }
                                if (inst[6] == 'e') {
                                    if (inst[7] == '.') {
                                        if (inst[8] == 'v') return 1431;
                                    }
                                }
                                if (inst[6] == 'b') {
                                    if (inst[7] == '.') {
                                        if (inst[8] == 'v') return 1428;
                                    }
                                }
                                if (inst[6] == 'h') {
                                    if (inst[7] == '.') {
                                        if (inst[8] == 'v') return 1429;
                                    }
                                }
                            }
                        }
                        if (inst[4] == 'o') {
                            if (inst[5] == 'r') {
                                if (inst[6] == '.') {
                                    if (inst[7] == 'v') {
                                        if (inst[8] == 'i') return 1779;
                                        if (inst[8] == 'x') return 1778;
                                        if (inst[8] == 'v') return 1777;
                                    }
                                }
                            }
                        }
                        if (inst[4] == 'l') {
                            if (inst[5] == 'w') {
                                if (inst[6] == 'u') {
                                    if (inst[7] == '.') {
                                        if (inst[8] == 'v') return 1404;
                                    }
                                }
                            }
                            if (inst[5] == 's') {
                                if (inst[6] == 'w') {
                                    if (inst[7] == '.') {
                                        if (inst[8] == 'v') return 1412;
                                    }
                                }
                                if (inst[6] == 'e') {
                                    if (inst[7] == '.') {
                                        if (inst[8] == 'v') return 1416;
                                    }
                                }
                                if (inst[6] == 'b') {
                                    if (inst[7] == '.') {
                                        if (inst[8] == 'v') return 1410;
                                    }
                                }
                                if (inst[6] == 'h') {
                                    if (inst[7] == '.') {
                                        if (inst[8] == 'v') return 1411;
                                    }
                                }
                            }
                            if (inst[5] == 'b') {
                                if (inst[6] == 'u') {
                                    if (inst[7] == '.') {
                                        if (inst[8] == 'v') return 1402;
                                    }
                                }
                            }
                            if (inst[5] == 'h') {
                                if (inst[6] == 'u') {
                                    if (inst[7] == '.') {
                                        if (inst[8] == 'v') return 1403;
                                    }
                                }
                            }
                            if (inst[5] == 'x') {
                                if (inst[6] == 'w') {
                                    if (inst[7] == '.') {
                                        if (inst[8] == 'v') return 1423;
                                    }
                                }
                                if (inst[6] == 'e') {
                                    if (inst[7] == '.') {
                                        if (inst[8] == 'v') return 1427;
                                    }
                                }
                                if (inst[6] == 'b') {
                                    if (inst[7] == '.') {
                                        if (inst[8] == 'v') return 1421;
                                    }
                                }
                                if (inst[6] == 'h') {
                                    if (inst[7] == '.') {
                                        if (inst[8] == 'v') return 1422;
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
        if (inst[0] == 'v') {
            if (inst[1] == 'a') {
                if (inst[2] == 'a') {
                    if (inst[3] == 'd') {
                        if (inst[4] == 'd') {
                            if (inst[5] == 'u') {
                                if (inst[6] == '.') {
                                    if (inst[7] == 'v') {
                                        if (inst[8] == 'x') return 1042;
                                        if (inst[8] == 'v') return 1041;
                                    }
                                }
                            }
                        }
                    }
                }
                if (inst[2] == 'e') {
                    if (inst[3] == 's') {
                        if (inst[4] == 'd') {
                            if (inst[5] == 'm') {
                                if (inst[6] == '.') {
                                    if (inst[7] == 'v') {
                                        if (inst[8] == 's') return 1241;
                                        if (inst[8] == 'v') return 1240;
                                    }
                                }
                            }
                            if (inst[5] == 'f') {
                                if (inst[6] == '.') {
                                    if (inst[7] == 'v') {
                                        if (inst[8] == 's') return 1239;
                                        if (inst[8] == 'v') return 1238;
                                    }
                                }
                            }
                        }
                        if (inst[4] == 'e') {
                            if (inst[5] == 'm') {
                                if (inst[6] == '.') {
                                    if (inst[7] == 'v') {
                                        if (inst[8] == 's') return 1245;
                                        if (inst[8] == 'v') return 1244;
                                    }
                                }
                            }
                            if (inst[5] == 'f') {
                                if (inst[6] == '.') {
                                    if (inst[7] == 'v') {
                                        if (inst[8] == 's') return 1243;
                                        if (inst[8] == 'v') return 1242;
                                    }
                                }
                            }
                        }
                    }
                }
                if (inst[2] == 's') {
                    if (inst[3] == 'u') {
                        if (inst[4] == 'b') {
                            if (inst[5] == 'u') {
                                if (inst[6] == '.') {
                                    if (inst[7] == 'v') {
                                        if (inst[8] == 'x') return 1046;
                                        if (inst[8] == 'v') return 1045;
                                    }
                                }
                            }
                        }
                    }
                }
            }
            if (inst[1] == 'w') {
                if (inst[2] == 'a') {
                    if (inst[3] == 'd') {
                        if (inst[4] == 'd') {
                            if (inst[5] == 'u') {
                                if (inst[6] == '.') {
                                    if (inst[7] == 'w') {
                                        if (inst[8] == 'x') return 908;
                                        if (inst[8] == 'v') return 907;
                                    }
                                    if (inst[7] == 'v') {
                                        if (inst[8] == 'x') return 900;
                                        if (inst[8] == 'v') return 899;
                                    }
                                }
                            }
                        }
                    }
                }
                if (inst[2] == 's') {
                    if (inst[3] == 'u') {
                        if (inst[4] == 'b') {
                            if (inst[5] == 'u') {
                                if (inst[6] == '.') {
                                    if (inst[7] == 'w') {
                                        if (inst[8] == 'x') return 910;
                                        if (inst[8] == 'v') return 909;
                                    }
                                    if (inst[7] == 'v') {
                                        if (inst[8] == 'x') return 902;
                                        if (inst[8] == 'v') return 901;
                                    }
                                }
                            }
                        }
                    }
                }
                if (inst[2] == 'm') {
                    if (inst[3] == 'a') {
                        if (inst[4] == 'c') {
                            if (inst[5] == 'c') {
                                if (inst[6] == '.') {
                                    if (inst[7] == 'v') {
                                        if (inst[8] == 'x') return 1021;
                                        if (inst[8] == 'v') return 1020;
                                    }
                                }
                            }
                        }
                    }
                    if (inst[3] == 'u') {
                        if (inst[4] == 'l') {
                            if (inst[5] == 'u') {
                                if (inst[6] == '.') {
                                    if (inst[7] == 'v') {
                                        if (inst[8] == 'x') return 1007;
                                        if (inst[8] == 'v') return 1006;
                                    }
                                }
                            }
                        }
                    }
                }
            }
            if (inst[1] == 's') {
                if (inst[2] == 'a') {
                    if (inst[3] == 'd') {
                        if (inst[4] == 'd') {
                            if (inst[5] == 'u') {
                                if (inst[6] == '.') {
                                    if (inst[7] == 'v') {
                                        if (inst[8] == 'i') return 1033;
                                        if (inst[8] == 'x') return 1032;
                                        if (inst[8] == 'v') return 1031;
                                    }
                                }
                            }
                        }
                    }
                }
                if (inst[2] == 'u') {
                    if (inst[3] == 'x') {
                        if (inst[4] == 'e') {
                            if (inst[5] == 'i') {
                                if (inst[6] == '8') {
                                    if (inst[7] == '.') {
                                        if (inst[8] == 'v') return 608;
                                    }
                                }
                            }
                        }
                    }
                }
                if (inst[2] == 'e') {
                    if (inst[3] == 'x') {
                        if (inst[4] == 't') {
                            if (inst[5] == '.') {
                                if (inst[6] == 'v') {
                                    if (inst[7] == 'f') {
                                        if (inst[8] == '2') return 916;
                                        if (inst[8] == '4') return 918;
                                        if (inst[8] == '8') return 920;
                                    }
                                }
                            }
                        }
                    }
                }
                if (inst[2] == 's') {
                    if (inst[3] == 'u') {
                        if (inst[4] == 'b') {
                            if (inst[5] == 'u') {
                                if (inst[6] == '.') {
                                    if (inst[7] == 'v') {
                                        if (inst[8] == 'x') return 1038;
                                        if (inst[8] == 'v') return 1037;
                                    }
                                }
                            }
                        }
                    }
                }
                if (inst[2] == 'm') {
                    if (inst[3] == '3') {
                        if (inst[4] == 'm') {
                            if (inst[5] == 'e') {
                                if (inst[6] == '.') {
                                    if (inst[7] == 'v') {
                                        if (inst[8] == 'v') return 1271;
                                    }
                                }
                            }
                        }
                    }
                }
                if (inst[2] == 'o') {
                    if (inst[3] == 'x') {
                        if (inst[4] == 'e') {
                            if (inst[5] == 'i') {
                                if (inst[6] == '8') {
                                    if (inst[7] == '.') {
                                        if (inst[8] == 'v') return 612;
                                    }
                                }
                            }
                        }
                    }
                }
            }
            if (inst[1] == 'm') {
                if (inst[2] == 'a') {
                    if (inst[3] == 'd') {
                        if (inst[4] == 'c') {
                            if (inst[5] == '.') {
                                if (inst[6] == 'v') {
                                    if (inst[7] == 'i') {
                                        if (inst[8] == 'm') return 926;
                                    }
                                    if (inst[7] == 'x') {
                                        if (inst[8] == 'm') return 925;
                                    }
                                    if (inst[7] == 'v') {
                                        if (inst[8] == 'm') return 924;
                                    }
                                }
                            }
                        }
                    }
                    if (inst[3] == 'n') {
                        if (inst[4] == 'd') {
                            if (inst[5] == 'n') {
                                if (inst[6] == '.') {
                                    if (inst[7] == 'm') {
                                        if (inst[8] == 'm') return 1172;
                                    }
                                }
                            }
                        }
                    }
                }
                if (inst[2] == 'u') {
                    if (inst[3] == 'l') {
                        if (inst[4] == 'h') {
                            if (inst[5] == 'u') {
                                if (inst[6] == '.') {
                                    if (inst[7] == 'v') {
                                        if (inst[8] == 'x') return 993;
                                        if (inst[8] == 'v') return 992;
                                    }
                                }
                            }
                        }
                    }
                }
                if (inst[2] == 's') {
                    if (inst[3] == 'b') {
                        if (inst[4] == 'c') {
                            if (inst[5] == '.') {
                                if (inst[6] == 'v') {
                                    if (inst[7] == 'x') {
                                        if (inst[8] == 'm') return 933;
                                    }
                                    if (inst[7] == 'v') {
                                        if (inst[8] == 'm') return 932;
                                    }
                                }
                            }
                        }
                    }
                    if (inst[3] == 'l') {
                        if (inst[4] == 'e') {
                            if (inst[5] == 'u') {
                                if (inst[6] == '.') {
                                    if (inst[7] == 'v') {
                                        if (inst[8] == 'i') return 972;
                                        if (inst[8] == 'x') return 971;
                                        if (inst[8] == 'v') return 970;
                                    }
                                }
                            }
                        }
                        if (inst[4] == 't') {
                            if (inst[5] == 'u') {
                                if (inst[6] == '.') {
                                    if (inst[7] == 'v') {
                                        if (inst[8] == 'x') return 967;
                                        if (inst[8] == 'v') return 966;
                                    }
                                }
                            }
                        }
                    }
                    if (inst[3] == 'g') {
                        if (inst[4] == 't') {
                            if (inst[5] == 'u') {
                                if (inst[6] == '.') {
                                    if (inst[7] == 'v') {
                                        if (inst[8] == 'i') return 977;
                                        if (inst[8] == 'x') return 976;
                                    }
                                }
                            }
                        }
                    }
                }
                if (inst[2] == 'n') {
                    if (inst[3] == 'a') {
                        if (inst[4] == 'n') {
                            if (inst[5] == 'd') {
                                if (inst[6] == '.') {
                                    if (inst[7] == 'm') {
                                        if (inst[8] == 'm') return 1171;
                                    }
                                }
                            }
                        }
                    }
                }
                if (inst[2] == 'x') {
                    if (inst[3] == 'n') {
                        if (inst[4] == 'o') {
                            if (inst[5] == 'r') {
                                if (inst[6] == '.') {
                                    if (inst[7] == 'm') {
                                        if (inst[8] == 'm') return 1177;
                                    }
                                }
                            }
                        }
                    }
                }
            }
            if (inst[1] == 'r') {
                if (inst[2] == 'e') {
                    if (inst[3] == 'd') {
                        if (inst[4] == 'o') {
                            if (inst[5] == 'r') {
                                if (inst[6] == '.') {
                                    if (inst[7] == 'v') {
                                        if (inst[8] == 's') return 1160;
                                    }
                                }
                            }
                        }
                    }
                }
            }
            if (inst[1] == 'l') {
                if (inst[2] == 'u') {
                    if (inst[3] == 'x') {
                        if (inst[4] == 'e') {
                            if (inst[5] == 'i') {
                                if (inst[6] == '8') {
                                    if (inst[7] == '.') {
                                        if (inst[8] == 'v') return 600;
                                    }
                                }
                            }
                        }
                    }
                }
                if (inst[2] == 'e') {
                    if (inst[3] == '3') {
                        if (inst[4] == '2') {
                            if (inst[5] == 'f') {
                                if (inst[6] == 'f') {
                                    if (inst[7] == '.') {
                                        if (inst[8] == 'v') return 618;
                                    }
                                }
                            }
                        }
                    }
                    if (inst[3] == '6') {
                        if (inst[4] == '4') {
                            if (inst[5] == 'f') {
                                if (inst[6] == 'f') {
                                    if (inst[7] == '.') {
                                        if (inst[8] == 'v') return 619;
                                    }
                                }
                            }
                        }
                    }
                    if (inst[3] == '1') {
                        if (inst[4] == '6') {
                            if (inst[5] == 'f') {
                                if (inst[6] == 'f') {
                                    if (inst[7] == '.') {
                                        if (inst[8] == 'v') return 617;
                                    }
                                }
                            }
                        }
                    }
                }
                if (inst[2] == '2') {
                    if (inst[3] == 'r') {
                        if (inst[4] == 'e') {
                            if (inst[5] == '3') {
                                if (inst[6] == '2') {
                                    if (inst[7] == '.') {
                                        if (inst[8] == 'v') return 878;
                                    }
                                }
                            }
                            if (inst[5] == '6') {
                                if (inst[6] == '4') {
                                    if (inst[7] == '.') {
                                        if (inst[8] == 'v') return 879;
                                    }
                                }
                            }
                            if (inst[5] == '1') {
                                if (inst[6] == '6') {
                                    if (inst[7] == '.') {
                                        if (inst[8] == 'v') return 877;
                                    }
                                }
                            }
                        }
                    }
                }
                if (inst[2] == '4') {
                    if (inst[3] == 'r') {
                        if (inst[4] == 'e') {
                            if (inst[5] == '3') {
                                if (inst[6] == '2') {
                                    if (inst[7] == '.') {
                                        if (inst[8] == 'v') return 882;
                                    }
                                }
                            }
                            if (inst[5] == '6') {
                                if (inst[6] == '4') {
                                    if (inst[7] == '.') {
                                        if (inst[8] == 'v') return 883;
                                    }
                                }
                            }
                            if (inst[5] == '1') {
                                if (inst[6] == '6') {
                                    if (inst[7] == '.') {
                                        if (inst[8] == 'v') return 881;
                                    }
                                }
                            }
                        }
                    }
                }
                if (inst[2] == '1') {
                    if (inst[3] == 'r') {
                        if (inst[4] == 'e') {
                            if (inst[5] == '3') {
                                if (inst[6] == '2') {
                                    if (inst[7] == '.') {
                                        if (inst[8] == 'v') return 874;
                                    }
                                }
                            }
                            if (inst[5] == '6') {
                                if (inst[6] == '4') {
                                    if (inst[7] == '.') {
                                        if (inst[8] == 'v') return 875;
                                    }
                                }
                            }
                            if (inst[5] == '1') {
                                if (inst[6] == '6') {
                                    if (inst[7] == '.') {
                                        if (inst[8] == 'v') return 873;
                                    }
                                }
                            }
                        }
                    }
                }
                if (inst[2] == 'o') {
                    if (inst[3] == 'x') {
                        if (inst[4] == 'e') {
                            if (inst[5] == 'i') {
                                if (inst[6] == '8') {
                                    if (inst[7] == '.') {
                                        if (inst[8] == 'v') return 604;
                                    }
                                }
                            }
                        }
                    }
                }
                if (inst[2] == '8') {
                    if (inst[3] == 'r') {
                        if (inst[4] == 'e') {
                            if (inst[5] == '3') {
                                if (inst[6] == '2') {
                                    if (inst[7] == '.') {
                                        if (inst[8] == 'v') return 886;
                                    }
                                }
                            }
                            if (inst[5] == '6') {
                                if (inst[6] == '4') {
                                    if (inst[7] == '.') {
                                        if (inst[8] == 'v') return 887;
                                    }
                                }
                            }
                            if (inst[5] == '1') {
                                if (inst[6] == '6') {
                                    if (inst[7] == '.') {
                                        if (inst[8] == 'v') return 885;
                                    }
                                }
                            }
                        }
                    }
                }
            }
            if (inst[1] == 'n') {
                if (inst[2] == 'm') {
                    if (inst[3] == 's') {
                        if (inst[4] == 'a') {
                            if (inst[5] == 'c') {
                                if (inst[6] == '.') {
                                    if (inst[7] == 'v') {
                                        if (inst[8] == 'x') return 1013;
                                        if (inst[8] == 'v') return 1012;
                                    }
                                }
                            }
                        }
                        if (inst[4] == 'u') {
                            if (inst[5] == 'b') {
                                if (inst[6] == '.') {
                                    if (inst[7] == 'v') {
                                        if (inst[8] == 'x') return 1017;
                                        if (inst[8] == 'v') return 1016;
                                    }
                                }
                            }
                        }
                    }
                }
                if (inst[2] == 'c') {
                    if (inst[3] == 'l') {
                        if (inst[4] == 'i') {
                            if (inst[5] == 'p') {
                                if (inst[6] == '.') {
                                    if (inst[7] == 'w') {
                                        if (inst[8] == 'i') return 1062;
                                        if (inst[8] == 'x') return 1061;
                                        if (inst[8] == 'v') return 1060;
                                    }
                                }
                            }
                        }
                    }
                }
            }
            if (inst[1] == 'c') {
                if (inst[2] == 'l') {
                    if (inst[3] == 'm') {
                        if (inst[4] == 'u') {
                            if (inst[5] == 'l') {
                                if (inst[6] == '.') {
                                    if (inst[7] == 'v') {
                                        if (inst[8] == 'x') return 1254;
                                        if (inst[8] == 'v') return 1253;
                                    }
                                }
                            }
                        }
                    }
                }
            }
            if (inst[1] == 'z') {
                if (inst[2] == 'e') {
                    if (inst[3] == 'x') {
                        if (inst[4] == 't') {
                            if (inst[5] == '.') {
                                if (inst[6] == 'v') {
                                    if (inst[7] == 'f') {
                                        if (inst[8] == '2') return 915;
                                        if (inst[8] == '4') return 917;
                                        if (inst[8] == '8') return 919;
                                    }
                                }
                            }
                        }
                    }
                }
            }
            if (inst[1] == 'f') {
                if (inst[2] == 'w') {
                    if (inst[3] == 'a') {
                        if (inst[4] == 'd') {
                            if (inst[5] == 'd') {
                                if (inst[6] == '.') {
                                    if (inst[7] == 'w') {
                                        if (inst[8] == 'v') return 1072;
                                        if (inst[8] == 'f') return 1073;
                                    }
                                    if (inst[7] == 'v') {
                                        if (inst[8] == 'v') return 1068;
                                        if (inst[8] == 'f') return 1069;
                                    }
                                }
                            }
                        }
                    }
                    if (inst[3] == 's') {
                        if (inst[4] == 'u') {
                            if (inst[5] == 'b') {
                                if (inst[6] == '.') {
                                    if (inst[7] == 'w') {
                                        if (inst[8] == 'v') return 1074;
                                        if (inst[8] == 'f') return 1075;
                                    }
                                    if (inst[7] == 'v') {
                                        if (inst[8] == 'v') return 1070;
                                        if (inst[8] == 'f') return 1071;
                                    }
                                }
                            }
                        }
                    }
                    if (inst[3] == 'm') {
                        if (inst[4] == 'u') {
                            if (inst[5] == 'l') {
                                if (inst[6] == '.') {
                                    if (inst[7] == 'v') {
                                        if (inst[8] == 'v') return 1081;
                                        if (inst[8] == 'f') return 1082;
                                    }
                                }
                            }
                        }
                    }
                }
                if (inst[2] == 's') {
                    if (inst[3] == 'g') {
                        if (inst[4] == 'n') {
                            if (inst[5] == 'j') {
                                if (inst[6] == '.') {
                                    if (inst[7] == 'v') {
                                        if (inst[8] == 'v') return 1114;
                                        if (inst[8] == 'f') return 1115;
                                    }
                                }
                            }
                        }
                    }
                }
                if (inst[2] == 'm') {
                    if (inst[3] == 'a') {
                        if (inst[4] == 'd') {
                            if (inst[5] == 'd') {
                                if (inst[6] == '.') {
                                    if (inst[7] == 'v') {
                                        if (inst[8] == 'v') return 1091;
                                        if (inst[8] == 'f') return 1092;
                                    }
                                }
                            }
                        }
                        if (inst[4] == 'c') {
                            if (inst[5] == 'c') {
                                if (inst[6] == '.') {
                                    if (inst[7] == 'v') {
                                        if (inst[8] == 'v') return 1083;
                                        if (inst[8] == 'f') return 1084;
                                    }
                                }
                            }
                        }
                    }
                    if (inst[3] == 's') {
                        if (inst[4] == 'a') {
                            if (inst[5] == 'c') {
                                if (inst[6] == '.') {
                                    if (inst[7] == 'v') {
                                        if (inst[8] == 'v') return 1087;
                                        if (inst[8] == 'f') return 1088;
                                    }
                                }
                            }
                        }
                        if (inst[4] == 'u') {
                            if (inst[5] == 'b') {
                                if (inst[6] == '.') {
                                    if (inst[7] == 'v') {
                                        if (inst[8] == 'v') return 1095;
                                        if (inst[8] == 'f') return 1096;
                                    }
                                }
                            }
                        }
                    }
                }
                if (inst[2] == 'r') {
                    if (inst[3] == 'd') {
                        if (inst[4] == 'i') {
                            if (inst[5] == 'v') {
                                if (inst[6] == '.') {
                                    if (inst[7] == 'v') {
                                        if (inst[8] == 'f') return 1080;
                                    }
                                }
                            }
                        }
                    }
                    if (inst[3] == 's') {
                        if (inst[4] == 'u') {
                            if (inst[5] == 'b') {
                                if (inst[6] == '.') {
                                    if (inst[7] == 'v') {
                                        if (inst[8] == 'f') return 1067;
                                    }
                                }
                            }
                        }
                    }
                }
                if (inst[2] == 'c') {
                    if (inst[3] == 'l') {
                        if (inst[4] == 'a') {
                            if (inst[5] == 's') {
                                if (inst[6] == 's') {
                                    if (inst[7] == '.') {
                                        if (inst[8] == 'v') return 1130;
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
        if (inst[0] == 'f') {
            if (inst[1] == 'e') {
                if (inst[2] == 'n') {
                    if (inst[3] == 'c') {
                        if (inst[4] == 'e') {
                            if (inst[5] == '.') {
                                if (inst[6] == 't') {
                                    if (inst[7] == 's') {
                                        if (inst[8] == 'o') return 38;
                                    }
                                }
                            }
                        }
                    }
                }
            }
            if (inst[1] == 'c') {
                if (inst[2] == 'v') {
                    if (inst[3] == 't') {
                        if (inst[4] == '.') {
                            if (inst[5] == 'd') {
                                if (inst[6] == '.') {
                                    if (inst[7] == 'w') {
                                        if (inst[8] == 'u') return 198;
                                    }
                                    if (inst[7] == 'l') {
                                        if (inst[8] == 'u') return 222;
                                    }
                                }
                            }
                            if (inst[5] == 'w') {
                                if (inst[6] == 'u') {
                                    if (inst[7] == '.') {
                                        if (inst[8] == 'd') return 201;
                                        if (inst[8] == 's') return 177;
                                        if (inst[8] == 'q') return 249;
                                        if (inst[8] == 'h') return 283;
                                    }
                                }
                            }
                            if (inst[5] == 's') {
                                if (inst[6] == '.') {
                                    if (inst[7] == 'w') {
                                        if (inst[8] == 'u') return 184;
                                    }
                                    if (inst[7] == 'l') {
                                        if (inst[8] == 'u') return 191;
                                    }
                                }
                            }
                            if (inst[5] == 'q') {
                                if (inst[6] == '.') {
                                    if (inst[7] == 'w') {
                                        if (inst[8] == 'u') return 251;
                                    }
                                    if (inst[7] == 'l') {
                                        if (inst[8] == 'u') return 255;
                                    }
                                }
                            }
                            if (inst[5] == 'l') {
                                if (inst[6] == 'u') {
                                    if (inst[7] == '.') {
                                        if (inst[8] == 'd') return 219;
                                        if (inst[8] == 's') return 189;
                                        if (inst[8] == 'q') return 253;
                                        if (inst[8] == 'h') return 289;
                                    }
                                }
                            }
                            if (inst[5] == 'h') {
                                if (inst[6] == '.') {
                                    if (inst[7] == 'w') {
                                        if (inst[8] == 'u') return 286;
                                    }
                                    if (inst[7] == 'l') {
                                        if (inst[8] == 'u') return 291;
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }

    if (size == 10) {
        if (inst[0] == 'a') {
            if (inst[1] == 'm') {
                if (inst[2] == 'o') {
                    if (inst[3] == 'o') {
                        if (inst[4] == 'r') {
                            if (inst[5] == '.') {
                                if (inst[6] == 'd') {
                                    if (inst[7] == '.') {
                                        if (inst[8] == 'a') {
                                            if (inst[9] == 'q') return 132;
                                        }
                                        if (inst[8] == 'r') {
                                            if (inst[9] == 'l') return 141;
                                        }
                                    }
                                }
                                if (inst[6] == 'w') {
                                    if (inst[7] == '.') {
                                        if (inst[8] == 'a') {
                                            if (inst[9] == 'q') return 88;
                                        }
                                        if (inst[8] == 'r') {
                                            if (inst[9] == 'l') return 97;
                                        }
                                    }
                                }
                                if (inst[6] == 'b') {
                                    if (inst[7] == '.') {
                                        if (inst[8] == 'a') {
                                            if (inst[9] == 'q') return 382;
                                        }
                                        if (inst[8] == 'r') {
                                            if (inst[9] == 'l') return 402;
                                        }
                                    }
                                }
                                if (inst[6] == 'h') {
                                    if (inst[7] == '.') {
                                        if (inst[8] == 'a') {
                                            if (inst[9] == 'q') return 383;
                                        }
                                        if (inst[8] == 'r') {
                                            if (inst[9] == 'l') return 403;
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
            if (inst[1] == 'h') {
                if (inst[2] == 'a') {
                    if (inst[3] == '2') {
                        if (inst[4] == '5') {
                            if (inst[5] == '6') {
                                if (inst[6] == 's') {
                                    if (inst[7] == 'u') {
                                        if (inst[8] == 'm') {
                                            if (inst[9] == '1') return 1221;
                                            if (inst[9] == '0') return 1220;
                                        }
                                    }
                                    if (inst[7] == 'i') {
                                        if (inst[8] == 'g') {
                                            if (inst[9] == '1') return 1219;
                                            if (inst[9] == '0') return 1218;
                                        }
                                    }
                                }
                            }
                        }
                    }
                    if (inst[3] == '5') {
                        if (inst[4] == '1') {
                            if (inst[5] == '2') {
                                if (inst[6] == 's') {
                                    if (inst[7] == 'u') {
                                        if (inst[8] == 'm') {
                                            if (inst[9] == '1') return 1231;
                                            if (inst[9] == '0') return 1230;
                                        }
                                    }
                                    if (inst[7] == 'i') {
                                        if (inst[8] == 'g') {
                                            if (inst[9] == '1') return 1229;
                                            if (inst[9] == '0') return 1228;
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
        if (inst[0] == 'c') {
            if (inst[1] == '.') {
                if (inst[2] == 'a') {
                    if (inst[3] == 'd') {
                        if (inst[4] == 'd') {
                            if (inst[5] == 'i') {
                                if (inst[6] == '1') {
                                    if (inst[7] == '6') {
                                        if (inst[8] == 's') {
                                            if (inst[9] == 'p') return 327;
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
            if (inst[1] == 'm') {
                if (inst[2] == '.') {
                    if (inst[3] == 'p') {
                        if (inst[4] == 'o') {
                            if (inst[5] == 'p') {
                                if (inst[6] == 'r') {
                                    if (inst[7] == 'e') {
                                        if (inst[8] == 't') {
                                            if (inst[9] == 'z') return 450;
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
        if (inst[0] == 'p') {
            if (inst[1] == 'r') {
                if (inst[2] == 'e') {
                    if (inst[3] == 'f') {
                        if (inst[4] == 'e') {
                            if (inst[5] == 't') {
                                if (inst[6] == 'c') {
                                    if (inst[7] == 'h') {
                                        if (inst[8] == '.') {
                                            if (inst[9] == 'w') return 161;
                                            if (inst[9] == 'i') return 159;
                                            if (inst[9] == 'r') return 160;
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
        if (inst[0] == 't') {
            if (inst[1] == 'h') {
                if (inst[2] == '.') {
                    if (inst[3] == 's') {
                        if (inst[4] == 'y') {
                            if (inst[5] == 'n') {
                                if (inst[6] == 'c') {
                                    if (inst[7] == '.') {
                                        if (inst[8] == 'i') {
                                            if (inst[9] == 's') return 1309;
                                        }
                                    }
                                }
                            }
                        }
                    }
                    if (inst[3] == 'v') {
                        if (inst[4] == 'a') {
                            if (inst[5] == 'd') {
                                if (inst[6] == 'd') {
                                    if (inst[7] == '.') {
                                        if (inst[8] == 'v') {
                                            if (inst[9] == 'i') return 1743;
                                            if (inst[9] == 'x') return 1742;
                                            if (inst[9] == 'v') return 1741;
                                        }
                                    }
                                }
                            }
                            if (inst[5] == 'n') {
                                if (inst[6] == 'd') {
                                    if (inst[7] == '.') {
                                        if (inst[8] == 'v') {
                                            if (inst[9] == 'i') return 1776;
                                            if (inst[9] == 'x') return 1775;
                                            if (inst[9] == 'v') return 1774;
                                        }
                                    }
                                }
                            }
                        }
                        if (inst[4] == 'd') {
                            if (inst[5] == 'i') {
                                if (inst[6] == 'v') {
                                    if (inst[7] == '.') {
                                        if (inst[8] == 'v') {
                                            if (inst[9] == 'x') return 1837;
                                            if (inst[9] == 'v') return 1836;
                                        }
                                    }
                                }
                            }
                        }
                        if (inst[4] == 'i') {
                            if (inst[5] == 'o') {
                                if (inst[6] == 't') {
                                    if (inst[7] == 'a') {
                                        if (inst[8] == '.') {
                                            if (inst[9] == 'm') return 2018;
                                        }
                                    }
                                }
                            }
                        }
                        if (inst[4] == 's') {
                            if (inst[5] == 'u') {
                                if (inst[6] == 'b') {
                                    if (inst[7] == '.') {
                                        if (inst[8] == 'v') {
                                            if (inst[9] == 'x') return 1745;
                                            if (inst[9] == 'v') return 1744;
                                        }
                                    }
                                }
                                if (inst[6] == 'x') {
                                    if (inst[7] == 'w') {
                                        if (inst[8] == '.') {
                                            if (inst[9] == 'v') return 1434;
                                        }
                                    }
                                    if (inst[7] == 'e') {
                                        if (inst[8] == '.') {
                                            if (inst[9] == 'v') return 1435;
                                        }
                                    }
                                    if (inst[7] == 'b') {
                                        if (inst[8] == '.') {
                                            if (inst[9] == 'v') return 1432;
                                        }
                                    }
                                    if (inst[7] == 'h') {
                                        if (inst[8] == '.') {
                                            if (inst[9] == 'v') return 1433;
                                        }
                                    }
                                }
                            }
                            if (inst[5] == 'e') {
                                if (inst[6] == 't') {
                                    if (inst[7] == 'v') {
                                        if (inst[8] == 'l') {
                                            if (inst[9] == 'i') return 1397;
                                        }
                                    }
                                }
                            }
                            if (inst[5] == 'r') {
                                if (inst[6] == 'a') {
                                    if (inst[7] == '.') {
                                        if (inst[8] == 'v') {
                                            if (inst[9] == 'i') return 1791;
                                            if (inst[9] == 'x') return 1790;
                                            if (inst[9] == 'v') return 1789;
                                        }
                                    }
                                }
                                if (inst[6] == 'l') {
                                    if (inst[7] == '.') {
                                        if (inst[8] == 'v') {
                                            if (inst[9] == 'i') return 1788;
                                            if (inst[9] == 'x') return 1787;
                                            if (inst[9] == 'v') return 1786;
                                        }
                                    }
                                }
                            }
                            if (inst[5] == 'l') {
                                if (inst[6] == 'l') {
                                    if (inst[7] == '.') {
                                        if (inst[8] == 'v') {
                                            if (inst[9] == 'i') return 1785;
                                            if (inst[9] == 'x') return 1784;
                                            if (inst[9] == 'v') return 1783;
                                        }
                                    }
                                }
                            }
                        }
                        if (inst[4] == 'm') {
                            if (inst[5] == 'a') {
                                if (inst[6] == 'x') {
                                    if (inst[7] == '.') {
                                        if (inst[8] == 'v') {
                                            if (inst[9] == 'x') return 1825;
                                            if (inst[9] == 'v') return 1824;
                                        }
                                    }
                                }
                            }
                            if (inst[5] == 'u') {
                                if (inst[6] == 'l') {
                                    if (inst[7] == '.') {
                                        if (inst[8] == 'v') {
                                            if (inst[9] == 'x') return 1827;
                                            if (inst[9] == 'v') return 1826;
                                        }
                                    }
                                }
                            }
                            if (inst[5] == 'i') {
                                if (inst[6] == 'n') {
                                    if (inst[7] == '.') {
                                        if (inst[8] == 'v') {
                                            if (inst[9] == 'x') return 1821;
                                            if (inst[9] == 'v') return 1820;
                                        }
                                    }
                                }
                            }
                            if (inst[5] == 's') {
                                if (inst[6] == 'i') {
                                    if (inst[7] == 'f') {
                                        if (inst[8] == '.') {
                                            if (inst[9] == 'm') return 2016;
                                        }
                                    }
                                }
                                if (inst[6] == 'o') {
                                    if (inst[7] == 'f') {
                                        if (inst[8] == '.') {
                                            if (inst[9] == 'm') return 2017;
                                        }
                                    }
                                }
                                if (inst[6] == 'b') {
                                    if (inst[7] == 'f') {
                                        if (inst[8] == '.') {
                                            if (inst[9] == 'm') return 2015;
                                        }
                                    }
                                }
                            }
                            if (inst[5] == 'o') {
                                if (inst[6] == 'r') {
                                    if (inst[7] == '.') {
                                        if (inst[8] == 'm') {
                                            if (inst[9] == 'm') return 2009;
                                        }
                                    }
                                }
                            }
                            if (inst[5] == 'v') {
                                if (inst[6] == '.') {
                                    if (inst[7] == 's') {
                                        if (inst[8] == '.') {
                                            if (inst[9] == 'x') return 2020;
                                        }
                                    }
                                    if (inst[7] == 'v') {
                                        if (inst[8] == '.') {
                                            if (inst[9] == 'i') return 1868;
                                            if (inst[9] == 'x') return 1867;
                                            if (inst[9] == 'v') return 1866;
                                        }
                                    }
                                }
                            }
                        }
                        if (inst[4] == 'r') {
                            if (inst[5] == 'e') {
                                if (inst[6] == 'm') {
                                    if (inst[7] == '.') {
                                        if (inst[8] == 'v') {
                                            if (inst[9] == 'x') return 1841;
                                            if (inst[9] == 'v') return 1840;
                                        }
                                    }
                                }
                            }
                        }
                        if (inst[4] == 'l') {
                            if (inst[5] == 'w') {
                                if (inst[6] == 'f') {
                                    if (inst[7] == 'f') {
                                        if (inst[8] == '.') {
                                            if (inst[9] == 'v') return 1438;
                                        }
                                    }
                                }
                            }
                            if (inst[5] == 'e') {
                                if (inst[6] == 'f') {
                                    if (inst[7] == 'f') {
                                        if (inst[8] == '.') {
                                            if (inst[9] == 'v') return 1442;
                                        }
                                    }
                                }
                            }
                            if (inst[5] == 's') {
                                if (inst[6] == 'w') {
                                    if (inst[7] == 'u') {
                                        if (inst[8] == '.') {
                                            if (inst[9] == 'v') return 1415;
                                        }
                                    }
                                }
                                if (inst[6] == 'b') {
                                    if (inst[7] == 'u') {
                                        if (inst[8] == '.') {
                                            if (inst[9] == 'v') return 1413;
                                        }
                                    }
                                }
                                if (inst[6] == 'h') {
                                    if (inst[7] == 'u') {
                                        if (inst[8] == '.') {
                                            if (inst[9] == 'v') return 1414;
                                        }
                                    }
                                }
                            }
                            if (inst[5] == 'b') {
                                if (inst[6] == 'f') {
                                    if (inst[7] == 'f') {
                                        if (inst[8] == '.') {
                                            if (inst[9] == 'v') return 1436;
                                        }
                                    }
                                }
                            }
                            if (inst[5] == 'h') {
                                if (inst[6] == 'f') {
                                    if (inst[7] == 'f') {
                                        if (inst[8] == '.') {
                                            if (inst[9] == 'v') return 1437;
                                        }
                                    }
                                }
                            }
                            if (inst[5] == 'x') {
                                if (inst[6] == 'w') {
                                    if (inst[7] == 'u') {
                                        if (inst[8] == '.') {
                                            if (inst[9] == 'v') return 1426;
                                        }
                                    }
                                }
                                if (inst[6] == 'b') {
                                    if (inst[7] == 'u') {
                                        if (inst[8] == '.') {
                                            if (inst[9] == 'v') return 1424;
                                        }
                                    }
                                }
                                if (inst[6] == 'h') {
                                    if (inst[7] == 'u') {
                                        if (inst[8] == '.') {
                                            if (inst[9] == 'v') return 1425;
                                        }
                                    }
                                }
                            }
                        }
                        if (inst[4] == 'x') {
                            if (inst[5] == 'o') {
                                if (inst[6] == 'r') {
                                    if (inst[7] == '.') {
                                        if (inst[8] == 'v') {
                                            if (inst[9] == 'i') return 1782;
                                            if (inst[9] == 'x') return 1781;
                                            if (inst[9] == 'v') return 1780;
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
        if (inst[0] == 'v') {
            if (inst[1] == 'a') {
                if (inst[2] == 'e') {
                    if (inst[3] == 's') {
                        if (inst[4] == 'k') {
                            if (inst[5] == 'f') {
                                if (inst[6] == '2') {
                                    if (inst[7] == '.') {
                                        if (inst[8] == 'v') {
                                            if (inst[9] == 'i') return 1247;
                                        }
                                    }
                                }
                                if (inst[6] == '1') {
                                    if (inst[7] == '.') {
                                        if (inst[8] == 'v') {
                                            if (inst[9] == 'i') return 1246;
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
            if (inst[1] == 'w') {
                if (inst[2] == 'm') {
                    if (inst[3] == 'a') {
                        if (inst[4] == 'c') {
                            if (inst[5] == 'c') {
                                if (inst[6] == 'u') {
                                    if (inst[7] == '.') {
                                        if (inst[8] == 'v') {
                                            if (inst[9] == 'x') return 1019;
                                            if (inst[9] == 'v') return 1018;
                                        }
                                    }
                                }
                            }
                        }
                    }
                    if (inst[3] == 'u') {
                        if (inst[4] == 'l') {
                            if (inst[5] == 's') {
                                if (inst[6] == 'u') {
                                    if (inst[7] == '.') {
                                        if (inst[8] == 'v') {
                                            if (inst[9] == 'x') return 1009;
                                            if (inst[9] == 'v') return 1008;
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
            if (inst[1] == 's') {
                if (inst[2] == 'u') {
                    if (inst[3] == 'x') {
                        if (inst[4] == 'e') {
                            if (inst[5] == 'i') {
                                if (inst[6] == '3') {
                                    if (inst[7] == '2') {
                                        if (inst[8] == '.') {
                                            if (inst[9] == 'v') return 610;
                                        }
                                    }
                                }
                                if (inst[6] == '6') {
                                    if (inst[7] == '4') {
                                        if (inst[8] == '.') {
                                            if (inst[9] == 'v') return 611;
                                        }
                                    }
                                }
                                if (inst[6] == '1') {
                                    if (inst[7] == '6') {
                                        if (inst[8] == '.') {
                                            if (inst[9] == 'v') return 609;
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
                if (inst[2] == 's') {
                    if (inst[3] == 'e') {
                        if (inst[4] == 'g') {
                            if (inst[5] == '3') {
                                if (inst[6] == 'e') {
                                    if (inst[7] == '8') {
                                        if (inst[8] == '.') {
                                            if (inst[9] == 'v') return 629;
                                        }
                                    }
                                }
                            }
                            if (inst[5] == '2') {
                                if (inst[6] == 'e') {
                                    if (inst[7] == '8') {
                                        if (inst[8] == '.') {
                                            if (inst[9] == 'v') return 621;
                                        }
                                    }
                                }
                            }
                            if (inst[5] == '6') {
                                if (inst[6] == 'e') {
                                    if (inst[7] == '8') {
                                        if (inst[8] == '.') {
                                            if (inst[9] == 'v') return 653;
                                        }
                                    }
                                }
                            }
                            if (inst[5] == '4') {
                                if (inst[6] == 'e') {
                                    if (inst[7] == '8') {
                                        if (inst[8] == '.') {
                                            if (inst[9] == 'v') return 637;
                                        }
                                    }
                                }
                            }
                            if (inst[5] == '8') {
                                if (inst[6] == 'e') {
                                    if (inst[7] == '8') {
                                        if (inst[8] == '.') {
                                            if (inst[9] == 'v') return 669;
                                        }
                                    }
                                }
                            }
                            if (inst[5] == '5') {
                                if (inst[6] == 'e') {
                                    if (inst[7] == '8') {
                                        if (inst[8] == '.') {
                                            if (inst[9] == 'v') return 645;
                                        }
                                    }
                                }
                            }
                            if (inst[5] == '7') {
                                if (inst[6] == 'e') {
                                    if (inst[7] == '8') {
                                        if (inst[8] == '.') {
                                            if (inst[9] == 'v') return 661;
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
                if (inst[2] == 'o') {
                    if (inst[3] == 'x') {
                        if (inst[4] == 'e') {
                            if (inst[5] == 'i') {
                                if (inst[6] == '3') {
                                    if (inst[7] == '2') {
                                        if (inst[8] == '.') {
                                            if (inst[9] == 'v') return 614;
                                        }
                                    }
                                }
                                if (inst[6] == '6') {
                                    if (inst[7] == '4') {
                                        if (inst[8] == '.') {
                                            if (inst[9] == 'v') return 615;
                                        }
                                    }
                                }
                                if (inst[6] == '1') {
                                    if (inst[7] == '6') {
                                        if (inst[8] == '.') {
                                            if (inst[9] == 'v') return 613;
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
                if (inst[2] == 'h') {
                    if (inst[3] == 'a') {
                        if (inst[4] == '2') {
                            if (inst[5] == 'm') {
                                if (inst[6] == 's') {
                                    if (inst[7] == '.') {
                                        if (inst[8] == 'v') {
                                            if (inst[9] == 'v') return 1269;
                                        }
                                    }
                                }
                            }
                            if (inst[5] == 'c') {
                                if (inst[6] == 'l') {
                                    if (inst[7] == '.') {
                                        if (inst[8] == 'v') {
                                            if (inst[9] == 'v') return 1268;
                                        }
                                    }
                                }
                                if (inst[6] == 'h') {
                                    if (inst[7] == '.') {
                                        if (inst[8] == 'v') {
                                            if (inst[9] == 'v') return 1267;
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
            if (inst[1] == 'm') {
                if (inst[2] == 'u') {
                    if (inst[3] == 'l') {
                        if (inst[4] == 'h') {
                            if (inst[5] == 's') {
                                if (inst[6] == 'u') {
                                    if (inst[7] == '.') {
                                        if (inst[8] == 'v') {
                                            if (inst[9] == 'x') return 995;
                                            if (inst[9] == 'v') return 994;
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
                if (inst[2] == 'e') {
                    if (inst[3] == 'r') {
                        if (inst[4] == 'g') {
                            if (inst[5] == 'e') {
                                if (inst[6] == '.') {
                                    if (inst[7] == 'v') {
                                        if (inst[8] == 'i') {
                                            if (inst[9] == 'm') return 1027;
                                        }
                                        if (inst[8] == 'x') {
                                            if (inst[9] == 'm') return 1026;
                                        }
                                        if (inst[8] == 'v') {
                                            if (inst[9] == 'm') return 1025;
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
            if (inst[1] == 'r') {
                if (inst[2] == 'e') {
                    if (inst[3] == 'd') {
                        if (inst[4] == 'a') {
                            if (inst[5] == 'n') {
                                if (inst[6] == 'd') {
                                    if (inst[7] == '.') {
                                        if (inst[8] == 'v') {
                                            if (inst[9] == 's') return 1159;
                                        }
                                    }
                                }
                            }
                        }
                        if (inst[4] == 's') {
                            if (inst[5] == 'u') {
                                if (inst[6] == 'm') {
                                    if (inst[7] == '.') {
                                        if (inst[8] == 'v') {
                                            if (inst[9] == 's') return 1154;
                                        }
                                    }
                                }
                            }
                        }
                        if (inst[4] == 'm') {
                            if (inst[5] == 'a') {
                                if (inst[6] == 'x') {
                                    if (inst[7] == '.') {
                                        if (inst[8] == 'v') {
                                            if (inst[9] == 's') return 1156;
                                        }
                                    }
                                }
                            }
                            if (inst[5] == 'i') {
                                if (inst[6] == 'n') {
                                    if (inst[7] == '.') {
                                        if (inst[8] == 'v') {
                                            if (inst[9] == 's') return 1158;
                                        }
                                    }
                                }
                            }
                        }
                        if (inst[4] == 'x') {
                            if (inst[5] == 'o') {
                                if (inst[6] == 'r') {
                                    if (inst[7] == '.') {
                                        if (inst[8] == 'v') {
                                            if (inst[9] == 's') return 1161;
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
            if (inst[1] == 'l') {
                if (inst[2] == 'u') {
                    if (inst[3] == 'x') {
                        if (inst[4] == 'e') {
                            if (inst[5] == 'i') {
                                if (inst[6] == '3') {
                                    if (inst[7] == '2') {
                                        if (inst[8] == '.') {
                                            if (inst[9] == 'v') return 602;
                                        }
                                    }
                                }
                                if (inst[6] == '6') {
                                    if (inst[7] == '4') {
                                        if (inst[8] == '.') {
                                            if (inst[9] == 'v') return 603;
                                        }
                                    }
                                }
                                if (inst[6] == '1') {
                                    if (inst[7] == '6') {
                                        if (inst[8] == '.') {
                                            if (inst[9] == 'v') return 601;
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
                if (inst[2] == 's') {
                    if (inst[3] == 'e') {
                        if (inst[4] == 'g') {
                            if (inst[5] == '3') {
                                if (inst[6] == 'e') {
                                    if (inst[7] == '8') {
                                        if (inst[8] == '.') {
                                            if (inst[9] == 'v') return 628;
                                        }
                                    }
                                }
                            }
                            if (inst[5] == '2') {
                                if (inst[6] == 'e') {
                                    if (inst[7] == '8') {
                                        if (inst[8] == '.') {
                                            if (inst[9] == 'v') return 620;
                                        }
                                    }
                                }
                            }
                            if (inst[5] == '6') {
                                if (inst[6] == 'e') {
                                    if (inst[7] == '8') {
                                        if (inst[8] == '.') {
                                            if (inst[9] == 'v') return 652;
                                        }
                                    }
                                }
                            }
                            if (inst[5] == '4') {
                                if (inst[6] == 'e') {
                                    if (inst[7] == '8') {
                                        if (inst[8] == '.') {
                                            if (inst[9] == 'v') return 636;
                                        }
                                    }
                                }
                            }
                            if (inst[5] == '8') {
                                if (inst[6] == 'e') {
                                    if (inst[7] == '8') {
                                        if (inst[8] == '.') {
                                            if (inst[9] == 'v') return 668;
                                        }
                                    }
                                }
                            }
                            if (inst[5] == '5') {
                                if (inst[6] == 'e') {
                                    if (inst[7] == '8') {
                                        if (inst[8] == '.') {
                                            if (inst[9] == 'v') return 644;
                                        }
                                    }
                                }
                            }
                            if (inst[5] == '7') {
                                if (inst[6] == 'e') {
                                    if (inst[7] == '8') {
                                        if (inst[8] == '.') {
                                            if (inst[9] == 'v') return 660;
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
                if (inst[2] == 'o') {
                    if (inst[3] == 'x') {
                        if (inst[4] == 'e') {
                            if (inst[5] == 'i') {
                                if (inst[6] == '3') {
                                    if (inst[7] == '2') {
                                        if (inst[8] == '.') {
                                            if (inst[9] == 'v') return 606;
                                        }
                                    }
                                }
                                if (inst[6] == '6') {
                                    if (inst[7] == '4') {
                                        if (inst[8] == '.') {
                                            if (inst[9] == 'v') return 607;
                                        }
                                    }
                                }
                                if (inst[6] == '1') {
                                    if (inst[7] == '6') {
                                        if (inst[8] == '.') {
                                            if (inst[9] == 'v') return 605;
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
            if (inst[1] == 'n') {
                if (inst[2] == 'c') {
                    if (inst[3] == 'l') {
                        if (inst[4] == 'i') {
                            if (inst[5] == 'p') {
                                if (inst[6] == 'u') {
                                    if (inst[7] == '.') {
                                        if (inst[8] == 'w') {
                                            if (inst[9] == 'i') return 1059;
                                            if (inst[9] == 'x') return 1058;
                                            if (inst[9] == 'v') return 1057;
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
            if (inst[1] == 'c') {
                if (inst[2] == 'l') {
                    if (inst[3] == 'm') {
                        if (inst[4] == 'u') {
                            if (inst[5] == 'l') {
                                if (inst[6] == 'h') {
                                    if (inst[7] == '.') {
                                        if (inst[8] == 'v') {
                                            if (inst[9] == 'x') return 1256;
                                            if (inst[9] == 'v') return 1255;
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
            if (inst[1] == 'f') {
                if (inst[2] == 'w') {
                    if (inst[3] == 'm') {
                        if (inst[4] == 'a') {
                            if (inst[5] == 'c') {
                                if (inst[6] == 'c') {
                                    if (inst[7] == '.') {
                                        if (inst[8] == 'v') {
                                            if (inst[9] == 'v') return 1099;
                                            if (inst[9] == 'f') return 1100;
                                        }
                                    }
                                }
                            }
                        }
                        if (inst[4] == 's') {
                            if (inst[5] == 'a') {
                                if (inst[6] == 'c') {
                                    if (inst[7] == '.') {
                                        if (inst[8] == 'v') {
                                            if (inst[9] == 'v') return 1103;
                                            if (inst[9] == 'f') return 1104;
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
                if (inst[2] == 's') {
                    if (inst[3] == 'g') {
                        if (inst[4] == 'n') {
                            if (inst[5] == 'j') {
                                if (inst[6] == 'n') {
                                    if (inst[7] == '.') {
                                        if (inst[8] == 'v') {
                                            if (inst[9] == 'v') return 1116;
                                            if (inst[9] == 'f') return 1117;
                                        }
                                    }
                                }
                                if (inst[6] == 'x') {
                                    if (inst[7] == '.') {
                                        if (inst[8] == 'v') {
                                            if (inst[9] == 'v') return 1118;
                                            if (inst[9] == 'f') return 1119;
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
                if (inst[2] == 'r') {
                    if (inst[3] == 's') {
                        if (inst[4] == 'q') {
                            if (inst[5] == 'r') {
                                if (inst[6] == 't') {
                                    if (inst[7] == '7') {
                                        if (inst[8] == '.') {
                                            if (inst[9] == 'v') return 1108;
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
                if (inst[2] == 'n') {
                    if (inst[3] == 'm') {
                        if (inst[4] == 'a') {
                            if (inst[5] == 'd') {
                                if (inst[6] == 'd') {
                                    if (inst[7] == '.') {
                                        if (inst[8] == 'v') {
                                            if (inst[9] == 'v') return 1093;
                                            if (inst[9] == 'f') return 1094;
                                        }
                                    }
                                }
                            }
                            if (inst[5] == 'c') {
                                if (inst[6] == 'c') {
                                    if (inst[7] == '.') {
                                        if (inst[8] == 'v') {
                                            if (inst[9] == 'v') return 1085;
                                            if (inst[9] == 'f') return 1086;
                                        }
                                    }
                                }
                            }
                        }
                        if (inst[4] == 's') {
                            if (inst[5] == 'a') {
                                if (inst[6] == 'c') {
                                    if (inst[7] == '.') {
                                        if (inst[8] == 'v') {
                                            if (inst[9] == 'v') return 1089;
                                            if (inst[9] == 'f') return 1090;
                                        }
                                    }
                                }
                            }
                            if (inst[5] == 'u') {
                                if (inst[6] == 'b') {
                                    if (inst[7] == '.') {
                                        if (inst[8] == 'v') {
                                            if (inst[9] == 'v') return 1097;
                                            if (inst[9] == 'f') return 1098;
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
        if (inst[0] == 'f') {
            if (inst[1] == 'r') {
                if (inst[2] == 'o') {
                    if (inst[3] == 'u') {
                        if (inst[4] == 'n') {
                            if (inst[5] == 'd') {
                                if (inst[6] == 'n') {
                                    if (inst[7] == 'x') {
                                        if (inst[8] == '.') {
                                            if (inst[9] == 'd') return 471;
                                            if (inst[9] == 's') return 469;
                                            if (inst[9] == 'q') return 475;
                                            if (inst[9] == 'h') return 473;
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

    if (size == 11) {
        if (inst[0] == 'a') {
            if (inst[1] == 'm') {
                if (inst[2] == 'o') {
                    if (inst[3] == 'a') {
                        if (inst[4] == 'd') {
                            if (inst[5] == 'd') {
                                if (inst[6] == '.') {
                                    if (inst[7] == 'd') {
                                        if (inst[8] == '.') {
                                            if (inst[9] == 'a') {
                                                if (inst[10] == 'q') return 129;
                                            }
                                            if (inst[9] == 'r') {
                                                if (inst[10] == 'l') return 138;
                                            }
                                        }
                                    }
                                    if (inst[7] == 'w') {
                                        if (inst[8] == '.') {
                                            if (inst[9] == 'a') {
                                                if (inst[10] == 'q') return 85;
                                            }
                                            if (inst[9] == 'r') {
                                                if (inst[10] == 'l') return 94;
                                            }
                                        }
                                    }
                                    if (inst[7] == 'b') {
                                        if (inst[8] == '.') {
                                            if (inst[9] == 'a') {
                                                if (inst[10] == 'q') return 378;
                                            }
                                            if (inst[9] == 'r') {
                                                if (inst[10] == 'l') return 398;
                                            }
                                        }
                                    }
                                    if (inst[7] == 'h') {
                                        if (inst[8] == '.') {
                                            if (inst[9] == 'a') {
                                                if (inst[10] == 'q') return 379;
                                            }
                                            if (inst[9] == 'r') {
                                                if (inst[10] == 'l') return 399;
                                            }
                                        }
                                    }
                                }
                            }
                        }
                        if (inst[4] == 'n') {
                            if (inst[5] == 'd') {
                                if (inst[6] == '.') {
                                    if (inst[7] == 'd') {
                                        if (inst[8] == '.') {
                                            if (inst[9] == 'a') {
                                                if (inst[10] == 'q') return 131;
                                            }
                                            if (inst[9] == 'r') {
                                                if (inst[10] == 'l') return 140;
                                            }
                                        }
                                    }
                                    if (inst[7] == 'w') {
                                        if (inst[8] == '.') {
                                            if (inst[9] == 'a') {
                                                if (inst[10] == 'q') return 87;
                                            }
                                            if (inst[9] == 'r') {
                                                if (inst[10] == 'l') return 96;
                                            }
                                        }
                                    }
                                    if (inst[7] == 'b') {
                                        if (inst[8] == '.') {
                                            if (inst[9] == 'a') {
                                                if (inst[10] == 'q') return 380;
                                            }
                                            if (inst[9] == 'r') {
                                                if (inst[10] == 'l') return 400;
                                            }
                                        }
                                    }
                                    if (inst[7] == 'h') {
                                        if (inst[8] == '.') {
                                            if (inst[9] == 'a') {
                                                if (inst[10] == 'q') return 381;
                                            }
                                            if (inst[9] == 'r') {
                                                if (inst[10] == 'l') return 401;
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                    if (inst[3] == 'm') {
                        if (inst[4] == 'a') {
                            if (inst[5] == 'x') {
                                if (inst[6] == '.') {
                                    if (inst[7] == 'd') {
                                        if (inst[8] == '.') {
                                            if (inst[9] == 'a') {
                                                if (inst[10] == 'q') return 134;
                                            }
                                            if (inst[9] == 'r') {
                                                if (inst[10] == 'l') return 143;
                                            }
                                        }
                                    }
                                    if (inst[7] == 'w') {
                                        if (inst[8] == '.') {
                                            if (inst[9] == 'a') {
                                                if (inst[10] == 'q') return 90;
                                            }
                                            if (inst[9] == 'r') {
                                                if (inst[10] == 'l') return 99;
                                            }
                                        }
                                    }
                                    if (inst[7] == 'b') {
                                        if (inst[8] == '.') {
                                            if (inst[9] == 'a') {
                                                if (inst[10] == 'q') return 386;
                                            }
                                            if (inst[9] == 'r') {
                                                if (inst[10] == 'l') return 406;
                                            }
                                        }
                                    }
                                    if (inst[7] == 'h') {
                                        if (inst[8] == '.') {
                                            if (inst[9] == 'a') {
                                                if (inst[10] == 'q') return 387;
                                            }
                                            if (inst[9] == 'r') {
                                                if (inst[10] == 'l') return 407;
                                            }
                                        }
                                    }
                                }
                            }
                        }
                        if (inst[4] == 'i') {
                            if (inst[5] == 'n') {
                                if (inst[6] == '.') {
                                    if (inst[7] == 'd') {
                                        if (inst[8] == '.') {
                                            if (inst[9] == 'a') {
                                                if (inst[10] == 'q') return 133;
                                            }
                                            if (inst[9] == 'r') {
                                                if (inst[10] == 'l') return 142;
                                            }
                                        }
                                    }
                                    if (inst[7] == 'w') {
                                        if (inst[8] == '.') {
                                            if (inst[9] == 'a') {
                                                if (inst[10] == 'q') return 89;
                                            }
                                            if (inst[9] == 'r') {
                                                if (inst[10] == 'l') return 98;
                                            }
                                        }
                                    }
                                    if (inst[7] == 'b') {
                                        if (inst[8] == '.') {
                                            if (inst[9] == 'a') {
                                                if (inst[10] == 'q') return 390;
                                            }
                                            if (inst[9] == 'r') {
                                                if (inst[10] == 'l') return 410;
                                            }
                                        }
                                    }
                                    if (inst[7] == 'h') {
                                        if (inst[8] == '.') {
                                            if (inst[9] == 'a') {
                                                if (inst[10] == 'q') return 391;
                                            }
                                            if (inst[9] == 'r') {
                                                if (inst[10] == 'l') return 411;
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                    if (inst[3] == 'c') {
                        if (inst[4] == 'a') {
                            if (inst[5] == 's') {
                                if (inst[6] == '.') {
                                    if (inst[7] == 'd') {
                                        if (inst[8] == '.') {
                                            if (inst[9] == 'a') {
                                                if (inst[10] == 'q') return 348;
                                            }
                                            if (inst[9] == 'r') {
                                                if (inst[10] == 'l') return 351;
                                            }
                                        }
                                    }
                                    if (inst[7] == 'w') {
                                        if (inst[8] == '.') {
                                            if (inst[9] == 'a') {
                                                if (inst[10] == 'q') return 347;
                                            }
                                            if (inst[9] == 'r') {
                                                if (inst[10] == 'l') return 350;
                                            }
                                        }
                                    }
                                    if (inst[7] == 'b') {
                                        if (inst[8] == '.') {
                                            if (inst[9] == 'a') {
                                                if (inst[10] == 'q') return 394;
                                            }
                                            if (inst[9] == 'r') {
                                                if (inst[10] == 'l') return 414;
                                            }
                                        }
                                    }
                                    if (inst[7] == 'q') {
                                        if (inst[8] == '.') {
                                            if (inst[9] == 'a') {
                                                if (inst[10] == 'q') return 349;
                                            }
                                            if (inst[9] == 'r') {
                                                if (inst[10] == 'l') return 352;
                                            }
                                        }
                                    }
                                    if (inst[7] == 'h') {
                                        if (inst[8] == '.') {
                                            if (inst[9] == 'a') {
                                                if (inst[10] == 'q') return 395;
                                            }
                                            if (inst[9] == 'r') {
                                                if (inst[10] == 'l') return 415;
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                    if (inst[3] == 'x') {
                        if (inst[4] == 'o') {
                            if (inst[5] == 'r') {
                                if (inst[6] == '.') {
                                    if (inst[7] == 'd') {
                                        if (inst[8] == '.') {
                                            if (inst[9] == 'a') {
                                                if (inst[10] == 'q') return 130;
                                            }
                                            if (inst[9] == 'r') {
                                                if (inst[10] == 'l') return 139;
                                            }
                                        }
                                    }
                                    if (inst[7] == 'w') {
                                        if (inst[8] == '.') {
                                            if (inst[9] == 'a') {
                                                if (inst[10] == 'q') return 86;
                                            }
                                            if (inst[9] == 'r') {
                                                if (inst[10] == 'l') return 95;
                                            }
                                        }
                                    }
                                    if (inst[7] == 'b') {
                                        if (inst[8] == '.') {
                                            if (inst[9] == 'a') {
                                                if (inst[10] == 'q') return 384;
                                            }
                                            if (inst[9] == 'r') {
                                                if (inst[10] == 'l') return 404;
                                            }
                                        }
                                    }
                                    if (inst[7] == 'h') {
                                        if (inst[8] == '.') {
                                            if (inst[9] == 'a') {
                                                if (inst[10] == 'q') return 385;
                                            }
                                            if (inst[9] == 'r') {
                                                if (inst[10] == 'l') return 405;
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
        if (inst[0] == 's') {
            if (inst[1] == 'h') {
                if (inst[2] == 'a') {
                    if (inst[3] == '5') {
                        if (inst[4] == '1') {
                            if (inst[5] == '2') {
                                if (inst[6] == 's') {
                                    if (inst[7] == 'u') {
                                        if (inst[8] == 'm') {
                                            if (inst[9] == '1') {
                                                if (inst[10] == 'r') return 1227;
                                            }
                                            if (inst[9] == '0') {
                                                if (inst[10] == 'r') return 1226;
                                            }
                                        }
                                    }
                                    if (inst[7] == 'i') {
                                        if (inst[8] == 'g') {
                                            if (inst[9] == '1') {
                                                if (inst[10] == 'l') return 1225;
                                                if (inst[10] == 'h') return 1224;
                                            }
                                            if (inst[9] == '0') {
                                                if (inst[10] == 'l') return 1223;
                                                if (inst[10] == 'h') return 1222;
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
        if (inst[0] == 't') {
            if (inst[1] == 'h') {
                if (inst[2] == '.') {
                    if (inst[3] == 'v') {
                        if (inst[4] == 'a') {
                            if (inst[5] == 'a') {
                                if (inst[6] == 'd') {
                                    if (inst[7] == 'd') {
                                        if (inst[8] == '.') {
                                            if (inst[9] == 'v') {
                                                if (inst[10] == 'i') return 1881;
                                                if (inst[10] == 'x') return 1880;
                                                if (inst[10] == 'v') return 1879;
                                            }
                                        }
                                    }
                                }
                            }
                            if (inst[5] == 'd') {
                                if (inst[6] == 'c') {
                                    if (inst[7] == '.') {
                                        if (inst[8] == 'v') {
                                            if (inst[9] == 'i') {
                                                if (inst[10] == 'm') return 1766;
                                            }
                                            if (inst[9] == 'x') {
                                                if (inst[10] == 'm') return 1765;
                                            }
                                            if (inst[9] == 'v') {
                                                if (inst[10] == 'm') return 1764;
                                            }
                                        }
                                    }
                                }
                            }
                            if (inst[5] == 's') {
                                if (inst[6] == 'u') {
                                    if (inst[7] == 'b') {
                                        if (inst[8] == '.') {
                                            if (inst[9] == 'v') {
                                                if (inst[10] == 'x') return 1883;
                                                if (inst[10] == 'v') return 1882;
                                            }
                                        }
                                    }
                                }
                            }
                        }
                        if (inst[4] == 'd') {
                            if (inst[5] == 'i') {
                                if (inst[6] == 'v') {
                                    if (inst[7] == 'u') {
                                        if (inst[8] == '.') {
                                            if (inst[9] == 'v') {
                                                if (inst[10] == 'x') return 1835;
                                                if (inst[10] == 'v') return 1834;
                                            }
                                        }
                                    }
                                }
                            }
                        }
                        if (inst[4] == 'w') {
                            if (inst[5] == 'a') {
                                if (inst[6] == 'd') {
                                    if (inst[7] == 'd') {
                                        if (inst[8] == '.') {
                                            if (inst[9] == 'w') {
                                                if (inst[10] == 'x') return 1761;
                                                if (inst[10] == 'v') return 1760;
                                            }
                                            if (inst[9] == 'v') {
                                                if (inst[10] == 'x') return 1753;
                                                if (inst[10] == 'v') return 1752;
                                            }
                                        }
                                    }
                                }
                            }
                            if (inst[5] == 's') {
                                if (inst[6] == 'u') {
                                    if (inst[7] == 'b') {
                                        if (inst[8] == '.') {
                                            if (inst[9] == 'w') {
                                                if (inst[10] == 'x') return 1763;
                                                if (inst[10] == 'v') return 1762;
                                            }
                                            if (inst[9] == 'v') {
                                                if (inst[10] == 'x') return 1755;
                                                if (inst[10] == 'v') return 1754;
                                            }
                                        }
                                    }
                                }
                            }
                            if (inst[5] == 'm') {
                                if (inst[6] == 'u') {
                                    if (inst[7] == 'l') {
                                        if (inst[8] == '.') {
                                            if (inst[9] == 'v') {
                                                if (inst[10] == 'x') return 1843;
                                                if (inst[10] == 'v') return 1842;
                                            }
                                        }
                                    }
                                }
                            }
                        }
                        if (inst[4] == 'e') {
                            if (inst[5] == 'x') {
                                if (inst[6] == 't') {
                                    if (inst[7] == '.') {
                                        if (inst[8] == 'x') {
                                            if (inst[9] == '.') {
                                                if (inst[10] == 'v') return 2021;
                                            }
                                        }
                                    }
                                }
                            }
                        }
                        if (inst[4] == 's') {
                            if (inst[5] == 'a') {
                                if (inst[6] == 'd') {
                                    if (inst[7] == 'd') {
                                        if (inst[8] == '.') {
                                            if (inst[9] == 'v') {
                                                if (inst[10] == 'i') return 1874;
                                                if (inst[10] == 'x') return 1873;
                                                if (inst[10] == 'v') return 1872;
                                            }
                                        }
                                    }
                                }
                            }
                            if (inst[5] == 's') {
                                if (inst[6] == 'u') {
                                    if (inst[7] == 'b') {
                                        if (inst[8] == '.') {
                                            if (inst[9] == 'v') {
                                                if (inst[10] == 'x') return 1878;
                                                if (inst[10] == 'v') return 1877;
                                            }
                                        }
                                    }
                                }
                                if (inst[6] == 'r') {
                                    if (inst[7] == 'a') {
                                        if (inst[8] == '.') {
                                            if (inst[9] == 'v') {
                                                if (inst[10] == 'i') return 1898;
                                                if (inst[10] == 'x') return 1897;
                                                if (inst[10] == 'v') return 1896;
                                            }
                                        }
                                    }
                                    if (inst[7] == 'l') {
                                        if (inst[8] == '.') {
                                            if (inst[9] == 'v') {
                                                if (inst[10] == 'i') return 1895;
                                                if (inst[10] == 'x') return 1894;
                                                if (inst[10] == 'v') return 1893;
                                            }
                                        }
                                    }
                                }
                            }
                            if (inst[5] == 'm') {
                                if (inst[6] == 'u') {
                                    if (inst[7] == 'l') {
                                        if (inst[8] == '.') {
                                            if (inst[9] == 'v') {
                                                if (inst[10] == 'x') return 1885;
                                                if (inst[10] == 'v') return 1884;
                                            }
                                        }
                                    }
                                }
                            }
                            if (inst[5] == 'b') {
                                if (inst[6] == 'c') {
                                    if (inst[7] == '.') {
                                        if (inst[8] == 'v') {
                                            if (inst[9] == 'x') {
                                                if (inst[10] == 'm') return 1771;
                                            }
                                            if (inst[9] == 'v') {
                                                if (inst[10] == 'm') return 1770;
                                            }
                                        }
                                    }
                                }
                            }
                        }
                        if (inst[4] == 'm') {
                            if (inst[5] == 'a') {
                                if (inst[6] == 'd') {
                                    if (inst[7] == 'd') {
                                        if (inst[8] == '.') {
                                            if (inst[9] == 'v') {
                                                if (inst[10] == 'x') return 1853;
                                                if (inst[10] == 'v') return 1852;
                                            }
                                        }
                                    }
                                }
                                if (inst[6] == 'q') {
                                    if (inst[7] == 'a') {
                                        if (inst[8] == '.') {
                                            if (inst[9] == 'v') {
                                                if (inst[10] == 'x') return 1391;
                                                if (inst[10] == 'v') return 1390;
                                            }
                                        }
                                    }
                                }
                                if (inst[6] == 'n') {
                                    if (inst[7] == 'd') {
                                        if (inst[8] == '.') {
                                            if (inst[9] == 'm') {
                                                if (inst[10] == 'm') return 2005;
                                            }
                                        }
                                    }
                                }
                                if (inst[6] == 'c') {
                                    if (inst[7] == 'c') {
                                        if (inst[8] == '.') {
                                            if (inst[9] == 'v') {
                                                if (inst[10] == 'x') return 1849;
                                                if (inst[10] == 'v') return 1848;
                                            }
                                        }
                                    }
                                }
                                if (inst[6] == 'x') {
                                    if (inst[7] == 'u') {
                                        if (inst[8] == '.') {
                                            if (inst[9] == 'v') {
                                                if (inst[10] == 'x') return 1823;
                                                if (inst[10] == 'v') return 1822;
                                            }
                                        }
                                    }
                                }
                            }
                            if (inst[5] == 'u') {
                                if (inst[6] == 'l') {
                                    if (inst[7] == 'h') {
                                        if (inst[8] == '.') {
                                            if (inst[9] == 'v') {
                                                if (inst[10] == 'x') return 1829;
                                                if (inst[10] == 'v') return 1828;
                                            }
                                        }
                                    }
                                }
                            }
                            if (inst[5] == 'i') {
                                if (inst[6] == 'n') {
                                    if (inst[7] == 'u') {
                                        if (inst[8] == '.') {
                                            if (inst[9] == 'v') {
                                                if (inst[10] == 'x') return 1819;
                                                if (inst[10] == 'v') return 1818;
                                            }
                                        }
                                    }
                                }
                            }
                            if (inst[5] == 's') {
                                if (inst[6] == 'e') {
                                    if (inst[7] == 'q') {
                                        if (inst[8] == '.') {
                                            if (inst[9] == 'v') {
                                                if (inst[10] == 'i') return 1800;
                                                if (inst[10] == 'x') return 1799;
                                                if (inst[10] == 'v') return 1798;
                                            }
                                        }
                                    }
                                }
                                if (inst[6] == 'l') {
                                    if (inst[7] == 'e') {
                                        if (inst[8] == '.') {
                                            if (inst[9] == 'v') {
                                                if (inst[10] == 'i') return 1813;
                                                if (inst[10] == 'x') return 1812;
                                                if (inst[10] == 'v') return 1811;
                                            }
                                        }
                                    }
                                    if (inst[7] == 't') {
                                        if (inst[8] == '.') {
                                            if (inst[9] == 'v') {
                                                if (inst[10] == 'x') return 1807;
                                                if (inst[10] == 'v') return 1806;
                                            }
                                        }
                                    }
                                }
                                if (inst[6] == 'n') {
                                    if (inst[7] == 'e') {
                                        if (inst[8] == '.') {
                                            if (inst[9] == 'v') {
                                                if (inst[10] == 'i') return 1803;
                                                if (inst[10] == 'x') return 1802;
                                                if (inst[10] == 'v') return 1801;
                                            }
                                        }
                                    }
                                }
                                if (inst[6] == 'g') {
                                    if (inst[7] == 't') {
                                        if (inst[8] == '.') {
                                            if (inst[9] == 'v') {
                                                if (inst[10] == 'i') return 1817;
                                                if (inst[10] == 'x') return 1816;
                                            }
                                        }
                                    }
                                }
                            }
                            if (inst[5] == 'n') {
                                if (inst[6] == 'o') {
                                    if (inst[7] == 'r') {
                                        if (inst[8] == '.') {
                                            if (inst[9] == 'm') {
                                                if (inst[10] == 'm') return 2010;
                                            }
                                        }
                                    }
                                }
                            }
                            if (inst[5] == 'x') {
                                if (inst[6] == 'o') {
                                    if (inst[7] == 'r') {
                                        if (inst[8] == '.') {
                                            if (inst[9] == 'm') {
                                                if (inst[10] == 'm') return 2008;
                                            }
                                        }
                                    }
                                }
                            }
                            if (inst[5] == 'p') {
                                if (inst[6] == 'o') {
                                    if (inst[7] == 'p') {
                                        if (inst[8] == 'c') {
                                            if (inst[9] == '.') {
                                                if (inst[10] == 'm') return 2013;
                                            }
                                        }
                                    }
                                }
                            }
                            if (inst[5] == 'f') {
                                if (inst[6] == 'e') {
                                    if (inst[7] == 'q') {
                                        if (inst[8] == '.') {
                                            if (inst[9] == 'v') {
                                                if (inst[10] == 'v') return 1960;
                                                if (inst[10] == 'f') return 1961;
                                            }
                                        }
                                    }
                                }
                                if (inst[6] == 'l') {
                                    if (inst[7] == 'e') {
                                        if (inst[8] == '.') {
                                            if (inst[9] == 'v') {
                                                if (inst[10] == 'v') return 1966;
                                                if (inst[10] == 'f') return 1967;
                                            }
                                        }
                                    }
                                    if (inst[7] == 't') {
                                        if (inst[8] == '.') {
                                            if (inst[9] == 'v') {
                                                if (inst[10] == 'v') return 1964;
                                                if (inst[10] == 'f') return 1965;
                                            }
                                        }
                                    }
                                }
                                if (inst[6] == 'n') {
                                    if (inst[7] == 'e') {
                                        if (inst[8] == '.') {
                                            if (inst[9] == 'v') {
                                                if (inst[10] == 'v') return 1962;
                                                if (inst[10] == 'f') return 1963;
                                            }
                                        }
                                    }
                                }
                                if (inst[6] == 'g') {
                                    if (inst[7] == 'e') {
                                        if (inst[8] == '.') {
                                            if (inst[9] == 'v') {
                                                if (inst[10] == 'f') return 1969;
                                            }
                                        }
                                    }
                                    if (inst[7] == 't') {
                                        if (inst[8] == '.') {
                                            if (inst[9] == 'v') {
                                                if (inst[10] == 'f') return 1968;
                                            }
                                        }
                                    }
                                }
                            }
                        }
                        if (inst[4] == 'r') {
                            if (inst[5] == 'e') {
                                if (inst[6] == 'm') {
                                    if (inst[7] == 'u') {
                                        if (inst[8] == '.') {
                                            if (inst[9] == 'v') {
                                                if (inst[10] == 'x') return 1839;
                                                if (inst[10] == 'v') return 1838;
                                            }
                                        }
                                    }
                                }
                            }
                            if (inst[5] == 's') {
                                if (inst[6] == 'u') {
                                    if (inst[7] == 'b') {
                                        if (inst[8] == '.') {
                                            if (inst[9] == 'v') {
                                                if (inst[10] == 'i') return 1747;
                                                if (inst[10] == 'x') return 1746;
                                            }
                                        }
                                    }
                                }
                            }
                        }
                        if (inst[4] == 'l') {
                            if (inst[5] == 'w') {
                                if (inst[6] == 'u') {
                                    if (inst[7] == 'f') {
                                        if (inst[8] == 'f') {
                                            if (inst[9] == '.') {
                                                if (inst[10] == 'v') return 1441;
                                            }
                                        }
                                    }
                                }
                            }
                            if (inst[5] == 'b') {
                                if (inst[6] == 'u') {
                                    if (inst[7] == 'f') {
                                        if (inst[8] == 'f') {
                                            if (inst[9] == '.') {
                                                if (inst[10] == 'v') return 1439;
                                            }
                                        }
                                    }
                                }
                            }
                            if (inst[5] == 'h') {
                                if (inst[6] == 'u') {
                                    if (inst[7] == 'f') {
                                        if (inst[8] == 'f') {
                                            if (inst[9] == '.') {
                                                if (inst[10] == 'v') return 1440;
                                            }
                                        }
                                    }
                                }
                            }
                        }
                        if (inst[4] == 'n') {
                            if (inst[5] == 's') {
                                if (inst[6] == 'r') {
                                    if (inst[7] == 'a') {
                                        if (inst[8] == '.') {
                                            if (inst[9] == 'v') {
                                                if (inst[10] == 'i') return 1797;
                                                if (inst[10] == 'x') return 1796;
                                                if (inst[10] == 'v') return 1795;
                                            }
                                        }
                                    }
                                    if (inst[7] == 'l') {
                                        if (inst[8] == '.') {
                                            if (inst[9] == 'v') {
                                                if (inst[10] == 'i') return 1794;
                                                if (inst[10] == 'x') return 1793;
                                                if (inst[10] == 'v') return 1792;
                                            }
                                        }
                                    }
                                }
                            }
                        }
                        if (inst[4] == 'f') {
                            if (inst[5] == 'a') {
                                if (inst[6] == 'd') {
                                    if (inst[7] == 'd') {
                                        if (inst[8] == '.') {
                                            if (inst[9] == 'v') {
                                                if (inst[10] == 'v') return 1905;
                                                if (inst[10] == 'f') return 1906;
                                            }
                                        }
                                    }
                                }
                            }
                            if (inst[5] == 'd') {
                                if (inst[6] == 'i') {
                                    if (inst[7] == 'v') {
                                        if (inst[8] == '.') {
                                            if (inst[9] == 'v') {
                                                if (inst[10] == 'v') return 1920;
                                                if (inst[10] == 'f') return 1921;
                                            }
                                        }
                                    }
                                }
                            }
                            if (inst[5] == 's') {
                                if (inst[6] == 'u') {
                                    if (inst[7] == 'b') {
                                        if (inst[8] == '.') {
                                            if (inst[9] == 'v') {
                                                if (inst[10] == 'v') return 1907;
                                                if (inst[10] == 'f') return 1908;
                                            }
                                        }
                                    }
                                }
                                if (inst[6] == 'q') {
                                    if (inst[7] == 'r') {
                                        if (inst[8] == 't') {
                                            if (inst[9] == '.') {
                                                if (inst[10] == 'v') return 1949;
                                            }
                                        }
                                    }
                                }
                            }
                            if (inst[5] == 'm') {
                                if (inst[6] == 'a') {
                                    if (inst[7] == 'x') {
                                        if (inst[8] == '.') {
                                            if (inst[9] == 'v') {
                                                if (inst[10] == 'v') return 1952;
                                                if (inst[10] == 'f') return 1953;
                                            }
                                        }
                                    }
                                }
                                if (inst[6] == 'u') {
                                    if (inst[7] == 'l') {
                                        if (inst[8] == '.') {
                                            if (inst[9] == 'v') {
                                                if (inst[10] == 'v') return 1918;
                                                if (inst[10] == 'f') return 1919;
                                            }
                                        }
                                    }
                                }
                                if (inst[6] == 'i') {
                                    if (inst[7] == 'n') {
                                        if (inst[8] == '.') {
                                            if (inst[9] == 'v') {
                                                if (inst[10] == 'v') return 1950;
                                                if (inst[10] == 'f') return 1951;
                                            }
                                        }
                                    }
                                }
                                if (inst[6] == 'v') {
                                    if (inst[7] == '.') {
                                        if (inst[8] == 's') {
                                            if (inst[9] == '.') {
                                                if (inst[10] == 'f') return 2023;
                                            }
                                        }
                                        if (inst[8] == 'v') {
                                            if (inst[9] == '.') {
                                                if (inst[10] == 'f') return 1974;
                                            }
                                        }
                                        if (inst[8] == 'f') {
                                            if (inst[9] == '.') {
                                                if (inst[10] == 's') return 2022;
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                    if (inst[3] == 'f') {
                        if (inst[4] == 'm') {
                            if (inst[5] == 'v') {
                                if (inst[6] == '.') {
                                    if (inst[7] == 'h') {
                                        if (inst[8] == 'w') {
                                            if (inst[9] == '.') {
                                                if (inst[10] == 'x') return 1387;
                                            }
                                        }
                                    }
                                    if (inst[7] == 'x') {
                                        if (inst[8] == '.') {
                                            if (inst[9] == 'h') {
                                                if (inst[10] == 'w') return 1386;
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
        if (inst[0] == 'v') {
            if (inst[1] == 'w') {
                if (inst[2] == 'm') {
                    if (inst[3] == 'a') {
                        if (inst[4] == 'c') {
                            if (inst[5] == 'c') {
                                if (inst[6] == 'u') {
                                    if (inst[7] == 's') {
                                        if (inst[8] == '.') {
                                            if (inst[9] == 'v') {
                                                if (inst[10] == 'x') return 1024;
                                            }
                                        }
                                    }
                                }
                                if (inst[6] == 's') {
                                    if (inst[7] == 'u') {
                                        if (inst[8] == '.') {
                                            if (inst[9] == 'v') {
                                                if (inst[10] == 'x') return 1023;
                                                if (inst[10] == 'v') return 1022;
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
                if (inst[2] == 'r') {
                    if (inst[3] == 'e') {
                        if (inst[4] == 'd') {
                            if (inst[5] == 's') {
                                if (inst[6] == 'u') {
                                    if (inst[7] == 'm') {
                                        if (inst[8] == '.') {
                                            if (inst[9] == 'v') {
                                                if (inst[10] == 's') return 1163;
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
            if (inst[1] == 's') {
                if (inst[2] == 's') {
                    if (inst[3] == 'e') {
                        if (inst[4] == 'g') {
                            if (inst[5] == '3') {
                                if (inst[6] == 'e') {
                                    if (inst[7] == '3') {
                                        if (inst[8] == '2') {
                                            if (inst[9] == '.') {
                                                if (inst[10] == 'v') return 633;
                                            }
                                        }
                                    }
                                    if (inst[7] == '6') {
                                        if (inst[8] == '4') {
                                            if (inst[9] == '.') {
                                                if (inst[10] == 'v') return 635;
                                            }
                                        }
                                    }
                                    if (inst[7] == '1') {
                                        if (inst[8] == '6') {
                                            if (inst[9] == '.') {
                                                if (inst[10] == 'v') return 631;
                                            }
                                        }
                                    }
                                }
                            }
                            if (inst[5] == '2') {
                                if (inst[6] == 'e') {
                                    if (inst[7] == '3') {
                                        if (inst[8] == '2') {
                                            if (inst[9] == '.') {
                                                if (inst[10] == 'v') return 625;
                                            }
                                        }
                                    }
                                    if (inst[7] == '6') {
                                        if (inst[8] == '4') {
                                            if (inst[9] == '.') {
                                                if (inst[10] == 'v') return 627;
                                            }
                                        }
                                    }
                                    if (inst[7] == '1') {
                                        if (inst[8] == '6') {
                                            if (inst[9] == '.') {
                                                if (inst[10] == 'v') return 623;
                                            }
                                        }
                                    }
                                }
                            }
                            if (inst[5] == '6') {
                                if (inst[6] == 'e') {
                                    if (inst[7] == '3') {
                                        if (inst[8] == '2') {
                                            if (inst[9] == '.') {
                                                if (inst[10] == 'v') return 657;
                                            }
                                        }
                                    }
                                    if (inst[7] == '6') {
                                        if (inst[8] == '4') {
                                            if (inst[9] == '.') {
                                                if (inst[10] == 'v') return 659;
                                            }
                                        }
                                    }
                                    if (inst[7] == '1') {
                                        if (inst[8] == '6') {
                                            if (inst[9] == '.') {
                                                if (inst[10] == 'v') return 655;
                                            }
                                        }
                                    }
                                }
                            }
                            if (inst[5] == '4') {
                                if (inst[6] == 'e') {
                                    if (inst[7] == '3') {
                                        if (inst[8] == '2') {
                                            if (inst[9] == '.') {
                                                if (inst[10] == 'v') return 641;
                                            }
                                        }
                                    }
                                    if (inst[7] == '6') {
                                        if (inst[8] == '4') {
                                            if (inst[9] == '.') {
                                                if (inst[10] == 'v') return 643;
                                            }
                                        }
                                    }
                                    if (inst[7] == '1') {
                                        if (inst[8] == '6') {
                                            if (inst[9] == '.') {
                                                if (inst[10] == 'v') return 639;
                                            }
                                        }
                                    }
                                }
                            }
                            if (inst[5] == '8') {
                                if (inst[6] == 'e') {
                                    if (inst[7] == '3') {
                                        if (inst[8] == '2') {
                                            if (inst[9] == '.') {
                                                if (inst[10] == 'v') return 673;
                                            }
                                        }
                                    }
                                    if (inst[7] == '6') {
                                        if (inst[8] == '4') {
                                            if (inst[9] == '.') {
                                                if (inst[10] == 'v') return 675;
                                            }
                                        }
                                    }
                                    if (inst[7] == '1') {
                                        if (inst[8] == '6') {
                                            if (inst[9] == '.') {
                                                if (inst[10] == 'v') return 671;
                                            }
                                        }
                                    }
                                }
                            }
                            if (inst[5] == '5') {
                                if (inst[6] == 'e') {
                                    if (inst[7] == '3') {
                                        if (inst[8] == '2') {
                                            if (inst[9] == '.') {
                                                if (inst[10] == 'v') return 649;
                                            }
                                        }
                                    }
                                    if (inst[7] == '6') {
                                        if (inst[8] == '4') {
                                            if (inst[9] == '.') {
                                                if (inst[10] == 'v') return 651;
                                            }
                                        }
                                    }
                                    if (inst[7] == '1') {
                                        if (inst[8] == '6') {
                                            if (inst[9] == '.') {
                                                if (inst[10] == 'v') return 647;
                                            }
                                        }
                                    }
                                }
                            }
                            if (inst[5] == '7') {
                                if (inst[6] == 'e') {
                                    if (inst[7] == '3') {
                                        if (inst[8] == '2') {
                                            if (inst[9] == '.') {
                                                if (inst[10] == 'v') return 665;
                                            }
                                        }
                                    }
                                    if (inst[7] == '6') {
                                        if (inst[8] == '4') {
                                            if (inst[9] == '.') {
                                                if (inst[10] == 'v') return 667;
                                            }
                                        }
                                    }
                                    if (inst[7] == '1') {
                                        if (inst[8] == '6') {
                                            if (inst[9] == '.') {
                                                if (inst[10] == 'v') return 663;
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                    if (inst[3] == 's') {
                        if (inst[4] == 'e') {
                            if (inst[5] == 'g') {
                                if (inst[6] == '3') {
                                    if (inst[7] == 'e') {
                                        if (inst[8] == '8') {
                                            if (inst[9] == '.') {
                                                if (inst[10] == 'v') return 713;
                                            }
                                        }
                                    }
                                }
                                if (inst[6] == '2') {
                                    if (inst[7] == 'e') {
                                        if (inst[8] == '8') {
                                            if (inst[9] == '.') {
                                                if (inst[10] == 'v') return 705;
                                            }
                                        }
                                    }
                                }
                                if (inst[6] == '6') {
                                    if (inst[7] == 'e') {
                                        if (inst[8] == '8') {
                                            if (inst[9] == '.') {
                                                if (inst[10] == 'v') return 737;
                                            }
                                        }
                                    }
                                }
                                if (inst[6] == '4') {
                                    if (inst[7] == 'e') {
                                        if (inst[8] == '8') {
                                            if (inst[9] == '.') {
                                                if (inst[10] == 'v') return 721;
                                            }
                                        }
                                    }
                                }
                                if (inst[6] == '8') {
                                    if (inst[7] == 'e') {
                                        if (inst[8] == '8') {
                                            if (inst[9] == '.') {
                                                if (inst[10] == 'v') return 753;
                                            }
                                        }
                                    }
                                }
                                if (inst[6] == '5') {
                                    if (inst[7] == 'e') {
                                        if (inst[8] == '8') {
                                            if (inst[9] == '.') {
                                                if (inst[10] == 'v') return 729;
                                            }
                                        }
                                    }
                                }
                                if (inst[6] == '7') {
                                    if (inst[7] == 'e') {
                                        if (inst[8] == '8') {
                                            if (inst[9] == '.') {
                                                if (inst[10] == 'v') return 745;
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
                if (inst[2] == 'l') {
                    if (inst[3] == 'i') {
                        if (inst[4] == 'd') {
                            if (inst[5] == 'e') {
                                if (inst[6] == 'u') {
                                    if (inst[7] == 'p') {
                                        if (inst[8] == '.') {
                                            if (inst[9] == 'v') {
                                                if (inst[10] == 'i') return 1190;
                                                if (inst[10] == 'x') return 1189;
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
            if (inst[1] == 'r') {
                if (inst[2] == 'e') {
                    if (inst[3] == 'd') {
                        if (inst[4] == 'm') {
                            if (inst[5] == 'a') {
                                if (inst[6] == 'x') {
                                    if (inst[7] == 'u') {
                                        if (inst[8] == '.') {
                                            if (inst[9] == 'v') {
                                                if (inst[10] == 's') return 1155;
                                            }
                                        }
                                    }
                                }
                            }
                            if (inst[5] == 'i') {
                                if (inst[6] == 'n') {
                                    if (inst[7] == 'u') {
                                        if (inst[8] == '.') {
                                            if (inst[9] == 'v') {
                                                if (inst[10] == 's') return 1157;
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
                if (inst[2] == 'g') {
                    if (inst[3] == 'a') {
                        if (inst[4] == 't') {
                            if (inst[5] == 'h') {
                                if (inst[6] == 'e') {
                                    if (inst[7] == 'r') {
                                        if (inst[8] == '.') {
                                            if (inst[9] == 'v') {
                                                if (inst[10] == 'i') return 1200;
                                                if (inst[10] == 'x') return 1199;
                                                if (inst[10] == 'v') return 1197;
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
                if (inst[2] == 's') {
                    if (inst[3] == 'e') {
                        if (inst[4] == 'g') {
                            if (inst[5] == '3') {
                                if (inst[6] == 'e') {
                                    if (inst[7] == '3') {
                                        if (inst[8] == '2') {
                                            if (inst[9] == '.') {
                                                if (inst[10] == 'v') return 632;
                                            }
                                        }
                                    }
                                    if (inst[7] == '6') {
                                        if (inst[8] == '4') {
                                            if (inst[9] == '.') {
                                                if (inst[10] == 'v') return 634;
                                            }
                                        }
                                    }
                                    if (inst[7] == '1') {
                                        if (inst[8] == '6') {
                                            if (inst[9] == '.') {
                                                if (inst[10] == 'v') return 630;
                                            }
                                        }
                                    }
                                }
                            }
                            if (inst[5] == '2') {
                                if (inst[6] == 'e') {
                                    if (inst[7] == '3') {
                                        if (inst[8] == '2') {
                                            if (inst[9] == '.') {
                                                if (inst[10] == 'v') return 624;
                                            }
                                        }
                                    }
                                    if (inst[7] == '6') {
                                        if (inst[8] == '4') {
                                            if (inst[9] == '.') {
                                                if (inst[10] == 'v') return 626;
                                            }
                                        }
                                    }
                                    if (inst[7] == '1') {
                                        if (inst[8] == '6') {
                                            if (inst[9] == '.') {
                                                if (inst[10] == 'v') return 622;
                                            }
                                        }
                                    }
                                }
                            }
                            if (inst[5] == '6') {
                                if (inst[6] == 'e') {
                                    if (inst[7] == '3') {
                                        if (inst[8] == '2') {
                                            if (inst[9] == '.') {
                                                if (inst[10] == 'v') return 656;
                                            }
                                        }
                                    }
                                    if (inst[7] == '6') {
                                        if (inst[8] == '4') {
                                            if (inst[9] == '.') {
                                                if (inst[10] == 'v') return 658;
                                            }
                                        }
                                    }
                                    if (inst[7] == '1') {
                                        if (inst[8] == '6') {
                                            if (inst[9] == '.') {
                                                if (inst[10] == 'v') return 654;
                                            }
                                        }
                                    }
                                }
                            }
                            if (inst[5] == '4') {
                                if (inst[6] == 'e') {
                                    if (inst[7] == '3') {
                                        if (inst[8] == '2') {
                                            if (inst[9] == '.') {
                                                if (inst[10] == 'v') return 640;
                                            }
                                        }
                                    }
                                    if (inst[7] == '6') {
                                        if (inst[8] == '4') {
                                            if (inst[9] == '.') {
                                                if (inst[10] == 'v') return 642;
                                            }
                                        }
                                    }
                                    if (inst[7] == '1') {
                                        if (inst[8] == '6') {
                                            if (inst[9] == '.') {
                                                if (inst[10] == 'v') return 638;
                                            }
                                        }
                                    }
                                }
                            }
                            if (inst[5] == '8') {
                                if (inst[6] == 'e') {
                                    if (inst[7] == '3') {
                                        if (inst[8] == '2') {
                                            if (inst[9] == '.') {
                                                if (inst[10] == 'v') return 672;
                                            }
                                        }
                                    }
                                    if (inst[7] == '6') {
                                        if (inst[8] == '4') {
                                            if (inst[9] == '.') {
                                                if (inst[10] == 'v') return 674;
                                            }
                                        }
                                    }
                                    if (inst[7] == '1') {
                                        if (inst[8] == '6') {
                                            if (inst[9] == '.') {
                                                if (inst[10] == 'v') return 670;
                                            }
                                        }
                                    }
                                }
                            }
                            if (inst[5] == '5') {
                                if (inst[6] == 'e') {
                                    if (inst[7] == '3') {
                                        if (inst[8] == '2') {
                                            if (inst[9] == '.') {
                                                if (inst[10] == 'v') return 648;
                                            }
                                        }
                                    }
                                    if (inst[7] == '6') {
                                        if (inst[8] == '4') {
                                            if (inst[9] == '.') {
                                                if (inst[10] == 'v') return 650;
                                            }
                                        }
                                    }
                                    if (inst[7] == '1') {
                                        if (inst[8] == '6') {
                                            if (inst[9] == '.') {
                                                if (inst[10] == 'v') return 646;
                                            }
                                        }
                                    }
                                }
                            }
                            if (inst[5] == '7') {
                                if (inst[6] == 'e') {
                                    if (inst[7] == '3') {
                                        if (inst[8] == '2') {
                                            if (inst[9] == '.') {
                                                if (inst[10] == 'v') return 664;
                                            }
                                        }
                                    }
                                    if (inst[7] == '6') {
                                        if (inst[8] == '4') {
                                            if (inst[9] == '.') {
                                                if (inst[10] == 'v') return 666;
                                            }
                                        }
                                    }
                                    if (inst[7] == '1') {
                                        if (inst[8] == '6') {
                                            if (inst[9] == '.') {
                                                if (inst[10] == 'v') return 662;
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                    if (inst[3] == 's') {
                        if (inst[4] == 'e') {
                            if (inst[5] == 'g') {
                                if (inst[6] == '3') {
                                    if (inst[7] == 'e') {
                                        if (inst[8] == '8') {
                                            if (inst[9] == '.') {
                                                if (inst[10] == 'v') return 712;
                                            }
                                        }
                                    }
                                }
                                if (inst[6] == '2') {
                                    if (inst[7] == 'e') {
                                        if (inst[8] == '8') {
                                            if (inst[9] == '.') {
                                                if (inst[10] == 'v') return 704;
                                            }
                                        }
                                    }
                                }
                                if (inst[6] == '6') {
                                    if (inst[7] == 'e') {
                                        if (inst[8] == '8') {
                                            if (inst[9] == '.') {
                                                if (inst[10] == 'v') return 736;
                                            }
                                        }
                                    }
                                }
                                if (inst[6] == '4') {
                                    if (inst[7] == 'e') {
                                        if (inst[8] == '8') {
                                            if (inst[9] == '.') {
                                                if (inst[10] == 'v') return 720;
                                            }
                                        }
                                    }
                                }
                                if (inst[6] == '8') {
                                    if (inst[7] == 'e') {
                                        if (inst[8] == '8') {
                                            if (inst[9] == '.') {
                                                if (inst[10] == 'v') return 752;
                                            }
                                        }
                                    }
                                }
                                if (inst[6] == '5') {
                                    if (inst[7] == 'e') {
                                        if (inst[8] == '8') {
                                            if (inst[9] == '.') {
                                                if (inst[10] == 'v') return 728;
                                            }
                                        }
                                    }
                                }
                                if (inst[6] == '7') {
                                    if (inst[7] == 'e') {
                                        if (inst[8] == '8') {
                                            if (inst[9] == '.') {
                                                if (inst[10] == 'v') return 744;
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
            if (inst[1] == 'f') {
                if (inst[2] == 'w') {
                    if (inst[3] == 'n') {
                        if (inst[4] == 'm') {
                            if (inst[5] == 'a') {
                                if (inst[6] == 'c') {
                                    if (inst[7] == 'c') {
                                        if (inst[8] == '.') {
                                            if (inst[9] == 'v') {
                                                if (inst[10] == 'v') return 1101;
                                                if (inst[10] == 'f') return 1102;
                                            }
                                        }
                                    }
                                }
                            }
                            if (inst[5] == 's') {
                                if (inst[6] == 'a') {
                                    if (inst[7] == 'c') {
                                        if (inst[8] == '.') {
                                            if (inst[9] == 'v') {
                                                if (inst[10] == 'v') return 1105;
                                                if (inst[10] == 'f') return 1106;
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
                if (inst[2] == 'm') {
                    if (inst[3] == 'e') {
                        if (inst[4] == 'r') {
                            if (inst[5] == 'g') {
                                if (inst[6] == 'e') {
                                    if (inst[7] == '.') {
                                        if (inst[8] == 'v') {
                                            if (inst[9] == 'f') {
                                                if (inst[10] == 'm') return 1131;
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
                if (inst[2] == 'r') {
                    if (inst[3] == 'e') {
                        if (inst[4] == 'd') {
                            if (inst[5] == 'm') {
                                if (inst[6] == 'a') {
                                    if (inst[7] == 'x') {
                                        if (inst[8] == '.') {
                                            if (inst[9] == 'v') {
                                                if (inst[10] == 's') return 1166;
                                            }
                                        }
                                    }
                                }
                                if (inst[6] == 'i') {
                                    if (inst[7] == 'n') {
                                        if (inst[8] == '.') {
                                            if (inst[9] == 'v') {
                                                if (inst[10] == 's') return 1167;
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
                if (inst[2] == 'c') {
                    if (inst[3] == 'v') {
                        if (inst[4] == 't') {
                            if (inst[5] == '.') {
                                if (inst[6] == 'x') {
                                    if (inst[7] == '.') {
                                        if (inst[8] == 'f') {
                                            if (inst[9] == '.') {
                                                if (inst[10] == 'v') return 1134;
                                            }
                                        }
                                    }
                                }
                                if (inst[6] == 'f') {
                                    if (inst[7] == '.') {
                                        if (inst[8] == 'x') {
                                            if (inst[9] == '.') {
                                                if (inst[10] == 'v') return 1138;
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
        if (inst[0] == 'f') {
            if (inst[1] == 'c') {
                if (inst[2] == 'v') {
                    if (inst[3] == 't') {
                        if (inst[4] == '.') {
                            if (inst[5] == 's') {
                                if (inst[6] == '.') {
                                    if (inst[7] == 'b') {
                                        if (inst[8] == 'f') {
                                            if (inst[9] == '1') {
                                                if (inst[10] == '6') return 1279;
                                            }
                                        }
                                    }
                                }
                            }
                            if (inst[5] == 'b') {
                                if (inst[6] == 'f') {
                                    if (inst[7] == '1') {
                                        if (inst[8] == '6') {
                                            if (inst[9] == '.') {
                                                if (inst[10] == 's') return 1278;
                                            }
                                        }
                                    }
                                }
                            }
                        }
                        if (inst[4] == 'm') {
                            if (inst[5] == 'o') {
                                if (inst[6] == 'd') {
                                    if (inst[7] == '.') {
                                        if (inst[8] == 'w') {
                                            if (inst[9] == '.') {
                                                if (inst[10] == 'd') return 476;
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

    if (size == 12) {
        if (inst[0] == 'a') {
            if (inst[1] == 'm') {
                if (inst[2] == 'o') {
                    if (inst[3] == 's') {
                        if (inst[4] == 'w') {
                            if (inst[5] == 'a') {
                                if (inst[6] == 'p') {
                                    if (inst[7] == '.') {
                                        if (inst[8] == 'd') {
                                            if (inst[9] == '.') {
                                                if (inst[10] == 'a') {
                                                    if (inst[11] == 'q') return 128;
                                                }
                                                if (inst[10] == 'r') {
                                                    if (inst[11] == 'l') return 137;
                                                }
                                            }
                                        }
                                        if (inst[8] == 'w') {
                                            if (inst[9] == '.') {
                                                if (inst[10] == 'a') {
                                                    if (inst[11] == 'q') return 84;
                                                }
                                                if (inst[10] == 'r') {
                                                    if (inst[11] == 'l') return 93;
                                                }
                                            }
                                        }
                                        if (inst[8] == 'b') {
                                            if (inst[9] == '.') {
                                                if (inst[10] == 'a') {
                                                    if (inst[11] == 'q') return 376;
                                                }
                                                if (inst[10] == 'r') {
                                                    if (inst[11] == 'l') return 396;
                                                }
                                            }
                                        }
                                        if (inst[8] == 'h') {
                                            if (inst[9] == '.') {
                                                if (inst[10] == 'a') {
                                                    if (inst[11] == 'q') return 377;
                                                }
                                                if (inst[10] == 'r') {
                                                    if (inst[11] == 'l') return 397;
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                    if (inst[3] == 'm') {
                        if (inst[4] == 'a') {
                            if (inst[5] == 'x') {
                                if (inst[6] == 'u') {
                                    if (inst[7] == '.') {
                                        if (inst[8] == 'd') {
                                            if (inst[9] == '.') {
                                                if (inst[10] == 'a') {
                                                    if (inst[11] == 'q') return 136;
                                                }
                                                if (inst[10] == 'r') {
                                                    if (inst[11] == 'l') return 145;
                                                }
                                            }
                                        }
                                        if (inst[8] == 'w') {
                                            if (inst[9] == '.') {
                                                if (inst[10] == 'a') {
                                                    if (inst[11] == 'q') return 92;
                                                }
                                                if (inst[10] == 'r') {
                                                    if (inst[11] == 'l') return 101;
                                                }
                                            }
                                        }
                                        if (inst[8] == 'b') {
                                            if (inst[9] == '.') {
                                                if (inst[10] == 'a') {
                                                    if (inst[11] == 'q') return 388;
                                                }
                                                if (inst[10] == 'r') {
                                                    if (inst[11] == 'l') return 408;
                                                }
                                            }
                                        }
                                        if (inst[8] == 'h') {
                                            if (inst[9] == '.') {
                                                if (inst[10] == 'a') {
                                                    if (inst[11] == 'q') return 389;
                                                }
                                                if (inst[10] == 'r') {
                                                    if (inst[11] == 'l') return 409;
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                        if (inst[4] == 'i') {
                            if (inst[5] == 'n') {
                                if (inst[6] == 'u') {
                                    if (inst[7] == '.') {
                                        if (inst[8] == 'd') {
                                            if (inst[9] == '.') {
                                                if (inst[10] == 'a') {
                                                    if (inst[11] == 'q') return 135;
                                                }
                                                if (inst[10] == 'r') {
                                                    if (inst[11] == 'l') return 144;
                                                }
                                            }
                                        }
                                        if (inst[8] == 'w') {
                                            if (inst[9] == '.') {
                                                if (inst[10] == 'a') {
                                                    if (inst[11] == 'q') return 91;
                                                }
                                                if (inst[10] == 'r') {
                                                    if (inst[11] == 'l') return 100;
                                                }
                                            }
                                        }
                                        if (inst[8] == 'b') {
                                            if (inst[9] == '.') {
                                                if (inst[10] == 'a') {
                                                    if (inst[11] == 'q') return 392;
                                                }
                                                if (inst[10] == 'r') {
                                                    if (inst[11] == 'l') return 412;
                                                }
                                            }
                                        }
                                        if (inst[8] == 'h') {
                                            if (inst[9] == '.') {
                                                if (inst[10] == 'a') {
                                                    if (inst[11] == 'q') return 393;
                                                }
                                                if (inst[10] == 'r') {
                                                    if (inst[11] == 'l') return 413;
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                    if (inst[3] == 'o') {
                        if (inst[4] == 'r') {
                            if (inst[5] == '.') {
                                if (inst[6] == 'd') {
                                    if (inst[7] == '.') {
                                        if (inst[8] == 'a') {
                                            if (inst[9] == 'q') {
                                                if (inst[10] == 'r') {
                                                    if (inst[11] == 'l') return 150;
                                                }
                                            }
                                        }
                                    }
                                }
                                if (inst[6] == 'w') {
                                    if (inst[7] == '.') {
                                        if (inst[8] == 'a') {
                                            if (inst[9] == 'q') {
                                                if (inst[10] == 'r') {
                                                    if (inst[11] == 'l') return 106;
                                                }
                                            }
                                        }
                                    }
                                }
                                if (inst[6] == 'b') {
                                    if (inst[7] == '.') {
                                        if (inst[8] == 'a') {
                                            if (inst[9] == 'q') {
                                                if (inst[10] == 'r') {
                                                    if (inst[11] == 'l') return 422;
                                                }
                                            }
                                        }
                                    }
                                }
                                if (inst[6] == 'h') {
                                    if (inst[7] == '.') {
                                        if (inst[8] == 'a') {
                                            if (inst[9] == 'q') {
                                                if (inst[10] == 'r') {
                                                    if (inst[11] == 'l') return 423;
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
        if (inst[0] == 't') {
            if (inst[1] == 'h') {
                if (inst[2] == '.') {
                    if (inst[3] == 'v') {
                        if (inst[4] == 'a') {
                            if (inst[5] == 'm') {
                                if (inst[6] == 'o') {
                                    if (inst[7] == 'o') {
                                        if (inst[8] == 'r') {
                                            if (inst[9] == 'd') {
                                                if (inst[10] == '.') {
                                                    if (inst[11] == 'v') return 1732;
                                                }
                                            }
                                            if (inst[9] == 'w') {
                                                if (inst[10] == '.') {
                                                    if (inst[11] == 'v') return 1731;
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                        if (inst[4] == 'w') {
                            if (inst[5] == 'a') {
                                if (inst[6] == 'd') {
                                    if (inst[7] == 'd') {
                                        if (inst[8] == 'u') {
                                            if (inst[9] == '.') {
                                                if (inst[10] == 'w') {
                                                    if (inst[11] == 'x') return 1757;
                                                    if (inst[11] == 'v') return 1756;
                                                }
                                                if (inst[10] == 'v') {
                                                    if (inst[11] == 'x') return 1749;
                                                    if (inst[11] == 'v') return 1748;
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                            if (inst[5] == 's') {
                                if (inst[6] == 'u') {
                                    if (inst[7] == 'b') {
                                        if (inst[8] == 'u') {
                                            if (inst[9] == '.') {
                                                if (inst[10] == 'w') {
                                                    if (inst[11] == 'x') return 1759;
                                                    if (inst[11] == 'v') return 1758;
                                                }
                                                if (inst[10] == 'v') {
                                                    if (inst[11] == 'x') return 1751;
                                                    if (inst[11] == 'v') return 1750;
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                            if (inst[5] == 'm') {
                                if (inst[6] == 'a') {
                                    if (inst[7] == 'c') {
                                        if (inst[8] == 'c') {
                                            if (inst[9] == '.') {
                                                if (inst[10] == 'v') {
                                                    if (inst[11] == 'x') return 1859;
                                                    if (inst[11] == 'v') return 1858;
                                                }
                                            }
                                        }
                                    }
                                }
                                if (inst[6] == 'u') {
                                    if (inst[7] == 'l') {
                                        if (inst[8] == 'u') {
                                            if (inst[9] == '.') {
                                                if (inst[10] == 'v') {
                                                    if (inst[11] == 'x') return 1845;
                                                    if (inst[11] == 'v') return 1844;
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                        if (inst[4] == 's') {
                            if (inst[5] == 'a') {
                                if (inst[6] == 'd') {
                                    if (inst[7] == 'd') {
                                        if (inst[8] == 'u') {
                                            if (inst[9] == '.') {
                                                if (inst[10] == 'v') {
                                                    if (inst[11] == 'i') return 1871;
                                                    if (inst[11] == 'x') return 1870;
                                                    if (inst[11] == 'v') return 1869;
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                            if (inst[5] == 's') {
                                if (inst[6] == 'u') {
                                    if (inst[7] == 'b') {
                                        if (inst[8] == 'u') {
                                            if (inst[9] == '.') {
                                                if (inst[10] == 'v') {
                                                    if (inst[11] == 'x') return 1876;
                                                    if (inst[11] == 'v') return 1875;
                                                }
                                            }
                                        }
                                    }
                                }
                                if (inst[6] == 'e') {
                                    if (inst[7] == 'g') {
                                        if (inst[8] == '3') {
                                            if (inst[9] == 'w') {
                                                if (inst[10] == '.') {
                                                    if (inst[11] == 'v') return 1498;
                                                }
                                            }
                                            if (inst[9] == 'e') {
                                                if (inst[10] == '.') {
                                                    if (inst[11] == 'v') return 1499;
                                                }
                                            }
                                            if (inst[9] == 'b') {
                                                if (inst[10] == '.') {
                                                    if (inst[11] == 'v') return 1496;
                                                }
                                            }
                                            if (inst[9] == 'h') {
                                                if (inst[10] == '.') {
                                                    if (inst[11] == 'v') return 1497;
                                                }
                                            }
                                        }
                                        if (inst[8] == '2') {
                                            if (inst[9] == 'w') {
                                                if (inst[10] == '.') {
                                                    if (inst[11] == 'v') return 1494;
                                                }
                                            }
                                            if (inst[9] == 'e') {
                                                if (inst[10] == '.') {
                                                    if (inst[11] == 'v') return 1495;
                                                }
                                            }
                                            if (inst[9] == 'b') {
                                                if (inst[10] == '.') {
                                                    if (inst[11] == 'v') return 1492;
                                                }
                                            }
                                            if (inst[9] == 'h') {
                                                if (inst[10] == '.') {
                                                    if (inst[11] == 'v') return 1493;
                                                }
                                            }
                                        }
                                        if (inst[8] == '6') {
                                            if (inst[9] == 'w') {
                                                if (inst[10] == '.') {
                                                    if (inst[11] == 'v') return 1510;
                                                }
                                            }
                                            if (inst[9] == 'e') {
                                                if (inst[10] == '.') {
                                                    if (inst[11] == 'v') return 1511;
                                                }
                                            }
                                            if (inst[9] == 'b') {
                                                if (inst[10] == '.') {
                                                    if (inst[11] == 'v') return 1508;
                                                }
                                            }
                                            if (inst[9] == 'h') {
                                                if (inst[10] == '.') {
                                                    if (inst[11] == 'v') return 1509;
                                                }
                                            }
                                        }
                                        if (inst[8] == '4') {
                                            if (inst[9] == 'w') {
                                                if (inst[10] == '.') {
                                                    if (inst[11] == 'v') return 1502;
                                                }
                                            }
                                            if (inst[9] == 'e') {
                                                if (inst[10] == '.') {
                                                    if (inst[11] == 'v') return 1503;
                                                }
                                            }
                                            if (inst[9] == 'b') {
                                                if (inst[10] == '.') {
                                                    if (inst[11] == 'v') return 1500;
                                                }
                                            }
                                            if (inst[9] == 'h') {
                                                if (inst[10] == '.') {
                                                    if (inst[11] == 'v') return 1501;
                                                }
                                            }
                                        }
                                        if (inst[8] == '8') {
                                            if (inst[9] == 'w') {
                                                if (inst[10] == '.') {
                                                    if (inst[11] == 'v') return 1518;
                                                }
                                            }
                                            if (inst[9] == 'e') {
                                                if (inst[10] == '.') {
                                                    if (inst[11] == 'v') return 1519;
                                                }
                                            }
                                            if (inst[9] == 'b') {
                                                if (inst[10] == '.') {
                                                    if (inst[11] == 'v') return 1516;
                                                }
                                            }
                                            if (inst[9] == 'h') {
                                                if (inst[10] == '.') {
                                                    if (inst[11] == 'v') return 1517;
                                                }
                                            }
                                        }
                                        if (inst[8] == '5') {
                                            if (inst[9] == 'w') {
                                                if (inst[10] == '.') {
                                                    if (inst[11] == 'v') return 1506;
                                                }
                                            }
                                            if (inst[9] == 'e') {
                                                if (inst[10] == '.') {
                                                    if (inst[11] == 'v') return 1507;
                                                }
                                            }
                                            if (inst[9] == 'b') {
                                                if (inst[10] == '.') {
                                                    if (inst[11] == 'v') return 1504;
                                                }
                                            }
                                            if (inst[9] == 'h') {
                                                if (inst[10] == '.') {
                                                    if (inst[11] == 'v') return 1505;
                                                }
                                            }
                                        }
                                        if (inst[8] == '7') {
                                            if (inst[9] == 'w') {
                                                if (inst[10] == '.') {
                                                    if (inst[11] == 'v') return 1514;
                                                }
                                            }
                                            if (inst[9] == 'e') {
                                                if (inst[10] == '.') {
                                                    if (inst[11] == 'v') return 1515;
                                                }
                                            }
                                            if (inst[9] == 'b') {
                                                if (inst[10] == '.') {
                                                    if (inst[11] == 'v') return 1512;
                                                }
                                            }
                                            if (inst[9] == 'h') {
                                                if (inst[10] == '.') {
                                                    if (inst[11] == 'v') return 1513;
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                        if (inst[4] == 'm') {
                            if (inst[5] == 'a') {
                                if (inst[6] == 'd') {
                                    if (inst[7] == 'c') {
                                        if (inst[8] == '.') {
                                            if (inst[9] == 'v') {
                                                if (inst[10] == 'i') {
                                                    if (inst[11] == 'm') return 1769;
                                                }
                                                if (inst[10] == 'x') {
                                                    if (inst[11] == 'm') return 1768;
                                                }
                                                if (inst[10] == 'v') {
                                                    if (inst[11] == 'm') return 1767;
                                                }
                                            }
                                        }
                                    }
                                }
                                if (inst[6] == 'q') {
                                    if (inst[7] == 'a') {
                                        if (inst[8] == 'u') {
                                            if (inst[9] == '.') {
                                                if (inst[10] == 'v') {
                                                    if (inst[11] == 'x') return 1393;
                                                    if (inst[11] == 'v') return 1392;
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                            if (inst[5] == 'u') {
                                if (inst[6] == 'l') {
                                    if (inst[7] == 'h') {
                                        if (inst[8] == 'u') {
                                            if (inst[9] == '.') {
                                                if (inst[10] == 'v') {
                                                    if (inst[11] == 'x') return 1831;
                                                    if (inst[11] == 'v') return 1830;
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                            if (inst[5] == 's') {
                                if (inst[6] == 'b') {
                                    if (inst[7] == 'c') {
                                        if (inst[8] == '.') {
                                            if (inst[9] == 'v') {
                                                if (inst[10] == 'x') {
                                                    if (inst[11] == 'm') return 1773;
                                                }
                                                if (inst[10] == 'v') {
                                                    if (inst[11] == 'm') return 1772;
                                                }
                                            }
                                        }
                                    }
                                }
                                if (inst[6] == 'l') {
                                    if (inst[7] == 'e') {
                                        if (inst[8] == 'u') {
                                            if (inst[9] == '.') {
                                                if (inst[10] == 'v') {
                                                    if (inst[11] == 'i') return 1810;
                                                    if (inst[11] == 'x') return 1809;
                                                    if (inst[11] == 'v') return 1808;
                                                }
                                            }
                                        }
                                    }
                                    if (inst[7] == 't') {
                                        if (inst[8] == 'u') {
                                            if (inst[9] == '.') {
                                                if (inst[10] == 'v') {
                                                    if (inst[11] == 'x') return 1805;
                                                    if (inst[11] == 'v') return 1804;
                                                }
                                            }
                                        }
                                    }
                                }
                                if (inst[6] == 'g') {
                                    if (inst[7] == 't') {
                                        if (inst[8] == 'u') {
                                            if (inst[9] == '.') {
                                                if (inst[10] == 'v') {
                                                    if (inst[11] == 'i') return 1815;
                                                    if (inst[11] == 'x') return 1814;
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                            if (inst[5] == 'n') {
                                if (inst[6] == 'a') {
                                    if (inst[7] == 'n') {
                                        if (inst[8] == 'd') {
                                            if (inst[9] == '.') {
                                                if (inst[10] == 'm') {
                                                    if (inst[11] == 'm') return 2006;
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                            if (inst[5] == 'x') {
                                if (inst[6] == 'n') {
                                    if (inst[7] == 'o') {
                                        if (inst[8] == 'r') {
                                            if (inst[9] == '.') {
                                                if (inst[10] == 'm') {
                                                    if (inst[11] == 'm') return 2012;
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                            if (inst[5] == 'f') {
                                if (inst[6] == 'i') {
                                    if (inst[7] == 'r') {
                                        if (inst[8] == 's') {
                                            if (inst[9] == 't') {
                                                if (inst[10] == '.') {
                                                    if (inst[11] == 'm') return 2014;
                                                }
                                            }
                                        }
                                    }
                                }
                                if (inst[6] == 'o') {
                                    if (inst[7] == 'r') {
                                        if (inst[8] == 'd') {
                                            if (inst[9] == '.') {
                                                if (inst[10] == 'v') {
                                                    if (inst[11] == 'v') return 1970;
                                                    if (inst[11] == 'f') return 1971;
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                        if (inst[4] == 'r') {
                            if (inst[5] == 'e') {
                                if (inst[6] == 'd') {
                                    if (inst[7] == 'o') {
                                        if (inst[8] == 'r') {
                                            if (inst[9] == '.') {
                                                if (inst[10] == 'v') {
                                                    if (inst[11] == 's') return 1995;
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                        if (inst[4] == 'l') {
                            if (inst[5] == 's') {
                                if (inst[6] == 'e') {
                                    if (inst[7] == 'g') {
                                        if (inst[8] == '3') {
                                            if (inst[9] == 'w') {
                                                if (inst[10] == '.') {
                                                    if (inst[11] == 'v') return 1448;
                                                }
                                            }
                                            if (inst[9] == 'e') {
                                                if (inst[10] == '.') {
                                                    if (inst[11] == 'v') return 1465;
                                                }
                                            }
                                            if (inst[9] == 'b') {
                                                if (inst[10] == '.') {
                                                    if (inst[11] == 'v') return 1446;
                                                }
                                            }
                                            if (inst[9] == 'h') {
                                                if (inst[10] == '.') {
                                                    if (inst[11] == 'v') return 1447;
                                                }
                                            }
                                        }
                                        if (inst[8] == '2') {
                                            if (inst[9] == 'w') {
                                                if (inst[10] == '.') {
                                                    if (inst[11] == 'v') return 1445;
                                                }
                                            }
                                            if (inst[9] == 'e') {
                                                if (inst[10] == '.') {
                                                    if (inst[11] == 'v') return 1464;
                                                }
                                            }
                                            if (inst[9] == 'b') {
                                                if (inst[10] == '.') {
                                                    if (inst[11] == 'v') return 1443;
                                                }
                                            }
                                            if (inst[9] == 'h') {
                                                if (inst[10] == '.') {
                                                    if (inst[11] == 'v') return 1444;
                                                }
                                            }
                                        }
                                        if (inst[8] == '6') {
                                            if (inst[9] == 'w') {
                                                if (inst[10] == '.') {
                                                    if (inst[11] == 'v') return 1457;
                                                }
                                            }
                                            if (inst[9] == 'e') {
                                                if (inst[10] == '.') {
                                                    if (inst[11] == 'v') return 1468;
                                                }
                                            }
                                            if (inst[9] == 'b') {
                                                if (inst[10] == '.') {
                                                    if (inst[11] == 'v') return 1455;
                                                }
                                            }
                                            if (inst[9] == 'h') {
                                                if (inst[10] == '.') {
                                                    if (inst[11] == 'v') return 1456;
                                                }
                                            }
                                        }
                                        if (inst[8] == '4') {
                                            if (inst[9] == 'w') {
                                                if (inst[10] == '.') {
                                                    if (inst[11] == 'v') return 1451;
                                                }
                                            }
                                            if (inst[9] == 'e') {
                                                if (inst[10] == '.') {
                                                    if (inst[11] == 'v') return 1466;
                                                }
                                            }
                                            if (inst[9] == 'b') {
                                                if (inst[10] == '.') {
                                                    if (inst[11] == 'v') return 1449;
                                                }
                                            }
                                            if (inst[9] == 'h') {
                                                if (inst[10] == '.') {
                                                    if (inst[11] == 'v') return 1450;
                                                }
                                            }
                                        }
                                        if (inst[8] == '8') {
                                            if (inst[9] == 'w') {
                                                if (inst[10] == '.') {
                                                    if (inst[11] == 'v') return 1463;
                                                }
                                            }
                                            if (inst[9] == 'e') {
                                                if (inst[10] == '.') {
                                                    if (inst[11] == 'v') return 1470;
                                                }
                                            }
                                            if (inst[9] == 'b') {
                                                if (inst[10] == '.') {
                                                    if (inst[11] == 'v') return 1461;
                                                }
                                            }
                                            if (inst[9] == 'h') {
                                                if (inst[10] == '.') {
                                                    if (inst[11] == 'v') return 1462;
                                                }
                                            }
                                        }
                                        if (inst[8] == '5') {
                                            if (inst[9] == 'w') {
                                                if (inst[10] == '.') {
                                                    if (inst[11] == 'v') return 1454;
                                                }
                                            }
                                            if (inst[9] == 'e') {
                                                if (inst[10] == '.') {
                                                    if (inst[11] == 'v') return 1467;
                                                }
                                            }
                                            if (inst[9] == 'b') {
                                                if (inst[10] == '.') {
                                                    if (inst[11] == 'v') return 1452;
                                                }
                                            }
                                            if (inst[9] == 'h') {
                                                if (inst[10] == '.') {
                                                    if (inst[11] == 'v') return 1453;
                                                }
                                            }
                                        }
                                        if (inst[8] == '7') {
                                            if (inst[9] == 'w') {
                                                if (inst[10] == '.') {
                                                    if (inst[11] == 'v') return 1460;
                                                }
                                            }
                                            if (inst[9] == 'e') {
                                                if (inst[10] == '.') {
                                                    if (inst[11] == 'v') return 1469;
                                                }
                                            }
                                            if (inst[9] == 'b') {
                                                if (inst[10] == '.') {
                                                    if (inst[11] == 'v') return 1458;
                                                }
                                            }
                                            if (inst[9] == 'h') {
                                                if (inst[10] == '.') {
                                                    if (inst[11] == 'v') return 1459;
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                        if (inst[4] == 'n') {
                            if (inst[5] == 'm') {
                                if (inst[6] == 's') {
                                    if (inst[7] == 'a') {
                                        if (inst[8] == 'c') {
                                            if (inst[9] == '.') {
                                                if (inst[10] == 'v') {
                                                    if (inst[11] == 'x') return 1851;
                                                    if (inst[11] == 'v') return 1850;
                                                }
                                            }
                                        }
                                    }
                                    if (inst[7] == 'u') {
                                        if (inst[8] == 'b') {
                                            if (inst[9] == '.') {
                                                if (inst[10] == 'v') {
                                                    if (inst[11] == 'x') return 1855;
                                                    if (inst[11] == 'v') return 1854;
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                            if (inst[5] == 'c') {
                                if (inst[6] == 'l') {
                                    if (inst[7] == 'i') {
                                        if (inst[8] == 'p') {
                                            if (inst[9] == '.') {
                                                if (inst[10] == 'v') {
                                                    if (inst[11] == 'i') return 1904;
                                                    if (inst[11] == 'x') return 1903;
                                                    if (inst[11] == 'v') return 1902;
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                        if (inst[4] == 'f') {
                            if (inst[5] == 'w') {
                                if (inst[6] == 'a') {
                                    if (inst[7] == 'd') {
                                        if (inst[8] == 'd') {
                                            if (inst[9] == '.') {
                                                if (inst[10] == 'w') {
                                                    if (inst[11] == 'v') return 1914;
                                                    if (inst[11] == 'f') return 1915;
                                                }
                                                if (inst[10] == 'v') {
                                                    if (inst[11] == 'v') return 1910;
                                                    if (inst[11] == 'f') return 1911;
                                                }
                                            }
                                        }
                                    }
                                }
                                if (inst[6] == 's') {
                                    if (inst[7] == 'u') {
                                        if (inst[8] == 'b') {
                                            if (inst[9] == '.') {
                                                if (inst[10] == 'w') {
                                                    if (inst[11] == 'v') return 1916;
                                                    if (inst[11] == 'f') return 1917;
                                                }
                                                if (inst[10] == 'v') {
                                                    if (inst[11] == 'v') return 1912;
                                                    if (inst[11] == 'f') return 1913;
                                                }
                                            }
                                        }
                                    }
                                }
                                if (inst[6] == 'm') {
                                    if (inst[7] == 'u') {
                                        if (inst[8] == 'l') {
                                            if (inst[9] == '.') {
                                                if (inst[10] == 'v') {
                                                    if (inst[11] == 'v') return 1923;
                                                    if (inst[11] == 'f') return 1924;
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                            if (inst[5] == 's') {
                                if (inst[6] == 'g') {
                                    if (inst[7] == 'n') {
                                        if (inst[8] == 'j') {
                                            if (inst[9] == '.') {
                                                if (inst[10] == 'v') {
                                                    if (inst[11] == 'v') return 1954;
                                                    if (inst[11] == 'f') return 1955;
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                            if (inst[5] == 'm') {
                                if (inst[6] == 'a') {
                                    if (inst[7] == 'd') {
                                        if (inst[8] == 'd') {
                                            if (inst[9] == '.') {
                                                if (inst[10] == 'v') {
                                                    if (inst[11] == 'v') return 1933;
                                                    if (inst[11] == 'f') return 1934;
                                                }
                                            }
                                        }
                                    }
                                    if (inst[7] == 'c') {
                                        if (inst[8] == 'c') {
                                            if (inst[9] == '.') {
                                                if (inst[10] == 'v') {
                                                    if (inst[11] == 'v') return 1925;
                                                    if (inst[11] == 'f') return 1926;
                                                }
                                            }
                                        }
                                    }
                                }
                                if (inst[6] == 's') {
                                    if (inst[7] == 'a') {
                                        if (inst[8] == 'c') {
                                            if (inst[9] == '.') {
                                                if (inst[10] == 'v') {
                                                    if (inst[11] == 'v') return 1929;
                                                    if (inst[11] == 'f') return 1930;
                                                }
                                            }
                                        }
                                    }
                                    if (inst[7] == 'u') {
                                        if (inst[8] == 'b') {
                                            if (inst[9] == '.') {
                                                if (inst[10] == 'v') {
                                                    if (inst[11] == 'v') return 1937;
                                                    if (inst[11] == 'f') return 1938;
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                            if (inst[5] == 'r') {
                                if (inst[6] == 'd') {
                                    if (inst[7] == 'i') {
                                        if (inst[8] == 'v') {
                                            if (inst[9] == '.') {
                                                if (inst[10] == 'v') {
                                                    if (inst[11] == 'f') return 1922;
                                                }
                                            }
                                        }
                                    }
                                }
                                if (inst[6] == 's') {
                                    if (inst[7] == 'u') {
                                        if (inst[8] == 'b') {
                                            if (inst[9] == '.') {
                                                if (inst[10] == 'v') {
                                                    if (inst[11] == 'f') return 1909;
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                            if (inst[5] == 'c') {
                                if (inst[6] == 'l') {
                                    if (inst[7] == 'a') {
                                        if (inst[8] == 's') {
                                            if (inst[9] == 's') {
                                                if (inst[10] == '.') {
                                                    if (inst[11] == 'v') return 1972;
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
        if (inst[0] == 'v') {
            if (inst[1] == 'w') {
                if (inst[2] == 'r') {
                    if (inst[3] == 'e') {
                        if (inst[4] == 'd') {
                            if (inst[5] == 's') {
                                if (inst[6] == 'u') {
                                    if (inst[7] == 'm') {
                                        if (inst[8] == 'u') {
                                            if (inst[9] == '.') {
                                                if (inst[10] == 'v') {
                                                    if (inst[11] == 's') return 1162;
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
            if (inst[1] == 's') {
                if (inst[2] == 's') {
                    if (inst[3] == 's') {
                        if (inst[4] == 'e') {
                            if (inst[5] == 'g') {
                                if (inst[6] == '3') {
                                    if (inst[7] == 'e') {
                                        if (inst[8] == '3') {
                                            if (inst[9] == '2') {
                                                if (inst[10] == '.') {
                                                    if (inst[11] == 'v') return 717;
                                                }
                                            }
                                        }
                                        if (inst[8] == '6') {
                                            if (inst[9] == '4') {
                                                if (inst[10] == '.') {
                                                    if (inst[11] == 'v') return 719;
                                                }
                                            }
                                        }
                                        if (inst[8] == '1') {
                                            if (inst[9] == '6') {
                                                if (inst[10] == '.') {
                                                    if (inst[11] == 'v') return 715;
                                                }
                                            }
                                        }
                                    }
                                }
                                if (inst[6] == '2') {
                                    if (inst[7] == 'e') {
                                        if (inst[8] == '3') {
                                            if (inst[9] == '2') {
                                                if (inst[10] == '.') {
                                                    if (inst[11] == 'v') return 709;
                                                }
                                            }
                                        }
                                        if (inst[8] == '6') {
                                            if (inst[9] == '4') {
                                                if (inst[10] == '.') {
                                                    if (inst[11] == 'v') return 711;
                                                }
                                            }
                                        }
                                        if (inst[8] == '1') {
                                            if (inst[9] == '6') {
                                                if (inst[10] == '.') {
                                                    if (inst[11] == 'v') return 707;
                                                }
                                            }
                                        }
                                    }
                                }
                                if (inst[6] == '6') {
                                    if (inst[7] == 'e') {
                                        if (inst[8] == '3') {
                                            if (inst[9] == '2') {
                                                if (inst[10] == '.') {
                                                    if (inst[11] == 'v') return 741;
                                                }
                                            }
                                        }
                                        if (inst[8] == '6') {
                                            if (inst[9] == '4') {
                                                if (inst[10] == '.') {
                                                    if (inst[11] == 'v') return 743;
                                                }
                                            }
                                        }
                                        if (inst[8] == '1') {
                                            if (inst[9] == '6') {
                                                if (inst[10] == '.') {
                                                    if (inst[11] == 'v') return 739;
                                                }
                                            }
                                        }
                                    }
                                }
                                if (inst[6] == '4') {
                                    if (inst[7] == 'e') {
                                        if (inst[8] == '3') {
                                            if (inst[9] == '2') {
                                                if (inst[10] == '.') {
                                                    if (inst[11] == 'v') return 725;
                                                }
                                            }
                                        }
                                        if (inst[8] == '6') {
                                            if (inst[9] == '4') {
                                                if (inst[10] == '.') {
                                                    if (inst[11] == 'v') return 727;
                                                }
                                            }
                                        }
                                        if (inst[8] == '1') {
                                            if (inst[9] == '6') {
                                                if (inst[10] == '.') {
                                                    if (inst[11] == 'v') return 723;
                                                }
                                            }
                                        }
                                    }
                                }
                                if (inst[6] == '8') {
                                    if (inst[7] == 'e') {
                                        if (inst[8] == '3') {
                                            if (inst[9] == '2') {
                                                if (inst[10] == '.') {
                                                    if (inst[11] == 'v') return 757;
                                                }
                                            }
                                        }
                                        if (inst[8] == '6') {
                                            if (inst[9] == '4') {
                                                if (inst[10] == '.') {
                                                    if (inst[11] == 'v') return 759;
                                                }
                                            }
                                        }
                                        if (inst[8] == '1') {
                                            if (inst[9] == '6') {
                                                if (inst[10] == '.') {
                                                    if (inst[11] == 'v') return 755;
                                                }
                                            }
                                        }
                                    }
                                }
                                if (inst[6] == '5') {
                                    if (inst[7] == 'e') {
                                        if (inst[8] == '3') {
                                            if (inst[9] == '2') {
                                                if (inst[10] == '.') {
                                                    if (inst[11] == 'v') return 733;
                                                }
                                            }
                                        }
                                        if (inst[8] == '6') {
                                            if (inst[9] == '4') {
                                                if (inst[10] == '.') {
                                                    if (inst[11] == 'v') return 735;
                                                }
                                            }
                                        }
                                        if (inst[8] == '1') {
                                            if (inst[9] == '6') {
                                                if (inst[10] == '.') {
                                                    if (inst[11] == 'v') return 731;
                                                }
                                            }
                                        }
                                    }
                                }
                                if (inst[6] == '7') {
                                    if (inst[7] == 'e') {
                                        if (inst[8] == '3') {
                                            if (inst[9] == '2') {
                                                if (inst[10] == '.') {
                                                    if (inst[11] == 'v') return 749;
                                                }
                                            }
                                        }
                                        if (inst[8] == '6') {
                                            if (inst[9] == '4') {
                                                if (inst[10] == '.') {
                                                    if (inst[11] == 'v') return 751;
                                                }
                                            }
                                        }
                                        if (inst[8] == '1') {
                                            if (inst[9] == '6') {
                                                if (inst[10] == '.') {
                                                    if (inst[11] == 'v') return 747;
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
                if (inst[2] == 'l') {
                    if (inst[3] == 'i') {
                        if (inst[4] == 'd') {
                            if (inst[5] == 'e') {
                                if (inst[6] == '1') {
                                    if (inst[7] == 'u') {
                                        if (inst[8] == 'p') {
                                            if (inst[9] == '.') {
                                                if (inst[10] == 'v') {
                                                    if (inst[11] == 'x') return 1193;
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
                if (inst[2] == 's') {
                    if (inst[3] == 'e') {
                        if (inst[4] == 'g') {
                            if (inst[5] == '3') {
                                if (inst[6] == 'e') {
                                    if (inst[7] == '8') {
                                        if (inst[8] == 'f') {
                                            if (inst[9] == 'f') {
                                                if (inst[10] == '.') {
                                                    if (inst[11] == 'v') return 680;
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                            if (inst[5] == '2') {
                                if (inst[6] == 'e') {
                                    if (inst[7] == '8') {
                                        if (inst[8] == 'f') {
                                            if (inst[9] == 'f') {
                                                if (inst[10] == '.') {
                                                    if (inst[11] == 'v') return 676;
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                            if (inst[5] == '6') {
                                if (inst[6] == 'e') {
                                    if (inst[7] == '8') {
                                        if (inst[8] == 'f') {
                                            if (inst[9] == 'f') {
                                                if (inst[10] == '.') {
                                                    if (inst[11] == 'v') return 692;
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                            if (inst[5] == '4') {
                                if (inst[6] == 'e') {
                                    if (inst[7] == '8') {
                                        if (inst[8] == 'f') {
                                            if (inst[9] == 'f') {
                                                if (inst[10] == '.') {
                                                    if (inst[11] == 'v') return 684;
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                            if (inst[5] == '8') {
                                if (inst[6] == 'e') {
                                    if (inst[7] == '8') {
                                        if (inst[8] == 'f') {
                                            if (inst[9] == 'f') {
                                                if (inst[10] == '.') {
                                                    if (inst[11] == 'v') return 700;
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                            if (inst[5] == '5') {
                                if (inst[6] == 'e') {
                                    if (inst[7] == '8') {
                                        if (inst[8] == 'f') {
                                            if (inst[9] == 'f') {
                                                if (inst[10] == '.') {
                                                    if (inst[11] == 'v') return 688;
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                            if (inst[5] == '7') {
                                if (inst[6] == 'e') {
                                    if (inst[7] == '8') {
                                        if (inst[8] == 'f') {
                                            if (inst[9] == 'f') {
                                                if (inst[10] == '.') {
                                                    if (inst[11] == 'v') return 696;
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                    if (inst[3] == 's') {
                        if (inst[4] == 'e') {
                            if (inst[5] == 'g') {
                                if (inst[6] == '3') {
                                    if (inst[7] == 'e') {
                                        if (inst[8] == '3') {
                                            if (inst[9] == '2') {
                                                if (inst[10] == '.') {
                                                    if (inst[11] == 'v') return 716;
                                                }
                                            }
                                        }
                                        if (inst[8] == '6') {
                                            if (inst[9] == '4') {
                                                if (inst[10] == '.') {
                                                    if (inst[11] == 'v') return 718;
                                                }
                                            }
                                        }
                                        if (inst[8] == '1') {
                                            if (inst[9] == '6') {
                                                if (inst[10] == '.') {
                                                    if (inst[11] == 'v') return 714;
                                                }
                                            }
                                        }
                                    }
                                }
                                if (inst[6] == '2') {
                                    if (inst[7] == 'e') {
                                        if (inst[8] == '3') {
                                            if (inst[9] == '2') {
                                                if (inst[10] == '.') {
                                                    if (inst[11] == 'v') return 708;
                                                }
                                            }
                                        }
                                        if (inst[8] == '6') {
                                            if (inst[9] == '4') {
                                                if (inst[10] == '.') {
                                                    if (inst[11] == 'v') return 710;
                                                }
                                            }
                                        }
                                        if (inst[8] == '1') {
                                            if (inst[9] == '6') {
                                                if (inst[10] == '.') {
                                                    if (inst[11] == 'v') return 706;
                                                }
                                            }
                                        }
                                    }
                                }
                                if (inst[6] == '6') {
                                    if (inst[7] == 'e') {
                                        if (inst[8] == '3') {
                                            if (inst[9] == '2') {
                                                if (inst[10] == '.') {
                                                    if (inst[11] == 'v') return 740;
                                                }
                                            }
                                        }
                                        if (inst[8] == '6') {
                                            if (inst[9] == '4') {
                                                if (inst[10] == '.') {
                                                    if (inst[11] == 'v') return 742;
                                                }
                                            }
                                        }
                                        if (inst[8] == '1') {
                                            if (inst[9] == '6') {
                                                if (inst[10] == '.') {
                                                    if (inst[11] == 'v') return 738;
                                                }
                                            }
                                        }
                                    }
                                }
                                if (inst[6] == '4') {
                                    if (inst[7] == 'e') {
                                        if (inst[8] == '3') {
                                            if (inst[9] == '2') {
                                                if (inst[10] == '.') {
                                                    if (inst[11] == 'v') return 724;
                                                }
                                            }
                                        }
                                        if (inst[8] == '6') {
                                            if (inst[9] == '4') {
                                                if (inst[10] == '.') {
                                                    if (inst[11] == 'v') return 726;
                                                }
                                            }
                                        }
                                        if (inst[8] == '1') {
                                            if (inst[9] == '6') {
                                                if (inst[10] == '.') {
                                                    if (inst[11] == 'v') return 722;
                                                }
                                            }
                                        }
                                    }
                                }
                                if (inst[6] == '8') {
                                    if (inst[7] == 'e') {
                                        if (inst[8] == '3') {
                                            if (inst[9] == '2') {
                                                if (inst[10] == '.') {
                                                    if (inst[11] == 'v') return 756;
                                                }
                                            }
                                        }
                                        if (inst[8] == '6') {
                                            if (inst[9] == '4') {
                                                if (inst[10] == '.') {
                                                    if (inst[11] == 'v') return 758;
                                                }
                                            }
                                        }
                                        if (inst[8] == '1') {
                                            if (inst[9] == '6') {
                                                if (inst[10] == '.') {
                                                    if (inst[11] == 'v') return 754;
                                                }
                                            }
                                        }
                                    }
                                }
                                if (inst[6] == '5') {
                                    if (inst[7] == 'e') {
                                        if (inst[8] == '3') {
                                            if (inst[9] == '2') {
                                                if (inst[10] == '.') {
                                                    if (inst[11] == 'v') return 732;
                                                }
                                            }
                                        }
                                        if (inst[8] == '6') {
                                            if (inst[9] == '4') {
                                                if (inst[10] == '.') {
                                                    if (inst[11] == 'v') return 734;
                                                }
                                            }
                                        }
                                        if (inst[8] == '1') {
                                            if (inst[9] == '6') {
                                                if (inst[10] == '.') {
                                                    if (inst[11] == 'v') return 730;
                                                }
                                            }
                                        }
                                    }
                                }
                                if (inst[6] == '7') {
                                    if (inst[7] == 'e') {
                                        if (inst[8] == '3') {
                                            if (inst[9] == '2') {
                                                if (inst[10] == '.') {
                                                    if (inst[11] == 'v') return 748;
                                                }
                                            }
                                        }
                                        if (inst[8] == '6') {
                                            if (inst[9] == '4') {
                                                if (inst[10] == '.') {
                                                    if (inst[11] == 'v') return 750;
                                                }
                                            }
                                        }
                                        if (inst[8] == '1') {
                                            if (inst[9] == '6') {
                                                if (inst[10] == '.') {
                                                    if (inst[11] == 'v') return 746;
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
            if (inst[1] == 'c') {
                if (inst[2] == 'o') {
                    if (inst[3] == 'm') {
                        if (inst[4] == 'p') {
                            if (inst[5] == 'r') {
                                if (inst[6] == 'e') {
                                    if (inst[7] == 's') {
                                        if (inst[8] == 's') {
                                            if (inst[9] == '.') {
                                                if (inst[10] == 'v') {
                                                    if (inst[11] == 'm') return 1201;
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
            if (inst[1] == 'f') {
                if (inst[2] == 'w') {
                    if (inst[3] == 'c') {
                        if (inst[4] == 'v') {
                            if (inst[5] == 't') {
                                if (inst[6] == '.') {
                                    if (inst[7] == 'x') {
                                        if (inst[8] == '.') {
                                            if (inst[9] == 'f') {
                                                if (inst[10] == '.') {
                                                    if (inst[11] == 'v') return 1140;
                                                }
                                            }
                                        }
                                    }
                                    if (inst[7] == 'f') {
                                        if (inst[8] == '.') {
                                            if (inst[9] == 'x') {
                                                if (inst[10] == '.') {
                                                    if (inst[11] == 'v') return 1144;
                                                }
                                            }
                                            if (inst[9] == 'f') {
                                                if (inst[10] == '.') {
                                                    if (inst[11] == 'v') return 1145;
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
                if (inst[2] == 'r') {
                    if (inst[3] == 'e') {
                        if (inst[4] == 'd') {
                            if (inst[5] == 'u') {
                                if (inst[6] == 's') {
                                    if (inst[7] == 'u') {
                                        if (inst[8] == 'm') {
                                            if (inst[9] == '.') {
                                                if (inst[10] == 'v') {
                                                    if (inst[11] == 's') return 1165;
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                            if (inst[5] == 'o') {
                                if (inst[6] == 's') {
                                    if (inst[7] == 'u') {
                                        if (inst[8] == 'm') {
                                            if (inst[9] == '.') {
                                                if (inst[10] == 'v') {
                                                    if (inst[11] == 's') return 1164;
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
                if (inst[2] == 'n') {
                    if (inst[3] == 'c') {
                        if (inst[4] == 'v') {
                            if (inst[5] == 't') {
                                if (inst[6] == '.') {
                                    if (inst[7] == 'x') {
                                        if (inst[8] == '.') {
                                            if (inst[9] == 'f') {
                                                if (inst[10] == '.') {
                                                    if (inst[11] == 'w') return 1147;
                                                }
                                            }
                                        }
                                    }
                                    if (inst[7] == 'f') {
                                        if (inst[8] == '.') {
                                            if (inst[9] == 'x') {
                                                if (inst[10] == '.') {
                                                    if (inst[11] == 'w') return 1151;
                                                }
                                            }
                                            if (inst[9] == 'f') {
                                                if (inst[10] == '.') {
                                                    if (inst[11] == 'w') return 1152;
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
                    if (inst[3] == 'v') {
                        if (inst[4] == 't') {
                            if (inst[5] == '.') {
                                if (inst[6] == 'x') {
                                    if (inst[7] == 'u') {
                                        if (inst[8] == '.') {
                                            if (inst[9] == 'f') {
                                                if (inst[10] == '.') {
                                                    if (inst[11] == 'v') return 1133;
                                                }
                                            }
                                        }
                                    }
                                }
                                if (inst[6] == 'f') {
                                    if (inst[7] == '.') {
                                        if (inst[8] == 'x') {
                                            if (inst[9] == 'u') {
                                                if (inst[10] == '.') {
                                                    if (inst[11] == 'v') return 1137;
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

    if (size == 13) {
        if (inst[0] == 'a') {
            if (inst[1] == 'm') {
                if (inst[2] == 'o') {
                    if (inst[3] == 'a') {
                        if (inst[4] == 'd') {
                            if (inst[5] == 'd') {
                                if (inst[6] == '.') {
                                    if (inst[7] == 'd') {
                                        if (inst[8] == '.') {
                                            if (inst[9] == 'a') {
                                                if (inst[10] == 'q') {
                                                    if (inst[11] == 'r') {
                                                        if (inst[12] == 'l') return 147;
                                                    }
                                                }
                                            }
                                        }
                                    }
                                    if (inst[7] == 'w') {
                                        if (inst[8] == '.') {
                                            if (inst[9] == 'a') {
                                                if (inst[10] == 'q') {
                                                    if (inst[11] == 'r') {
                                                        if (inst[12] == 'l') return 103;
                                                    }
                                                }
                                            }
                                        }
                                    }
                                    if (inst[7] == 'b') {
                                        if (inst[8] == '.') {
                                            if (inst[9] == 'a') {
                                                if (inst[10] == 'q') {
                                                    if (inst[11] == 'r') {
                                                        if (inst[12] == 'l') return 418;
                                                    }
                                                }
                                            }
                                        }
                                    }
                                    if (inst[7] == 'h') {
                                        if (inst[8] == '.') {
                                            if (inst[9] == 'a') {
                                                if (inst[10] == 'q') {
                                                    if (inst[11] == 'r') {
                                                        if (inst[12] == 'l') return 419;
                                                    }
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                        if (inst[4] == 'n') {
                            if (inst[5] == 'd') {
                                if (inst[6] == '.') {
                                    if (inst[7] == 'd') {
                                        if (inst[8] == '.') {
                                            if (inst[9] == 'a') {
                                                if (inst[10] == 'q') {
                                                    if (inst[11] == 'r') {
                                                        if (inst[12] == 'l') return 149;
                                                    }
                                                }
                                            }
                                        }
                                    }
                                    if (inst[7] == 'w') {
                                        if (inst[8] == '.') {
                                            if (inst[9] == 'a') {
                                                if (inst[10] == 'q') {
                                                    if (inst[11] == 'r') {
                                                        if (inst[12] == 'l') return 105;
                                                    }
                                                }
                                            }
                                        }
                                    }
                                    if (inst[7] == 'b') {
                                        if (inst[8] == '.') {
                                            if (inst[9] == 'a') {
                                                if (inst[10] == 'q') {
                                                    if (inst[11] == 'r') {
                                                        if (inst[12] == 'l') return 420;
                                                    }
                                                }
                                            }
                                        }
                                    }
                                    if (inst[7] == 'h') {
                                        if (inst[8] == '.') {
                                            if (inst[9] == 'a') {
                                                if (inst[10] == 'q') {
                                                    if (inst[11] == 'r') {
                                                        if (inst[12] == 'l') return 421;
                                                    }
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                    if (inst[3] == 'm') {
                        if (inst[4] == 'a') {
                            if (inst[5] == 'x') {
                                if (inst[6] == '.') {
                                    if (inst[7] == 'd') {
                                        if (inst[8] == '.') {
                                            if (inst[9] == 'a') {
                                                if (inst[10] == 'q') {
                                                    if (inst[11] == 'r') {
                                                        if (inst[12] == 'l') return 152;
                                                    }
                                                }
                                            }
                                        }
                                    }
                                    if (inst[7] == 'w') {
                                        if (inst[8] == '.') {
                                            if (inst[9] == 'a') {
                                                if (inst[10] == 'q') {
                                                    if (inst[11] == 'r') {
                                                        if (inst[12] == 'l') return 108;
                                                    }
                                                }
                                            }
                                        }
                                    }
                                    if (inst[7] == 'b') {
                                        if (inst[8] == '.') {
                                            if (inst[9] == 'a') {
                                                if (inst[10] == 'q') {
                                                    if (inst[11] == 'r') {
                                                        if (inst[12] == 'l') return 426;
                                                    }
                                                }
                                            }
                                        }
                                    }
                                    if (inst[7] == 'h') {
                                        if (inst[8] == '.') {
                                            if (inst[9] == 'a') {
                                                if (inst[10] == 'q') {
                                                    if (inst[11] == 'r') {
                                                        if (inst[12] == 'l') return 427;
                                                    }
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                        if (inst[4] == 'i') {
                            if (inst[5] == 'n') {
                                if (inst[6] == '.') {
                                    if (inst[7] == 'd') {
                                        if (inst[8] == '.') {
                                            if (inst[9] == 'a') {
                                                if (inst[10] == 'q') {
                                                    if (inst[11] == 'r') {
                                                        if (inst[12] == 'l') return 151;
                                                    }
                                                }
                                            }
                                        }
                                    }
                                    if (inst[7] == 'w') {
                                        if (inst[8] == '.') {
                                            if (inst[9] == 'a') {
                                                if (inst[10] == 'q') {
                                                    if (inst[11] == 'r') {
                                                        if (inst[12] == 'l') return 107;
                                                    }
                                                }
                                            }
                                        }
                                    }
                                    if (inst[7] == 'b') {
                                        if (inst[8] == '.') {
                                            if (inst[9] == 'a') {
                                                if (inst[10] == 'q') {
                                                    if (inst[11] == 'r') {
                                                        if (inst[12] == 'l') return 430;
                                                    }
                                                }
                                            }
                                        }
                                    }
                                    if (inst[7] == 'h') {
                                        if (inst[8] == '.') {
                                            if (inst[9] == 'a') {
                                                if (inst[10] == 'q') {
                                                    if (inst[11] == 'r') {
                                                        if (inst[12] == 'l') return 431;
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
                        if (inst[4] == 'a') {
                            if (inst[5] == 's') {
                                if (inst[6] == '.') {
                                    if (inst[7] == 'd') {
                                        if (inst[8] == '.') {
                                            if (inst[9] == 'a') {
                                                if (inst[10] == 'q') {
                                                    if (inst[11] == 'r') {
                                                        if (inst[12] == 'l') return 354;
                                                    }
                                                }
                                            }
                                        }
                                    }
                                    if (inst[7] == 'w') {
                                        if (inst[8] == '.') {
                                            if (inst[9] == 'a') {
                                                if (inst[10] == 'q') {
                                                    if (inst[11] == 'r') {
                                                        if (inst[12] == 'l') return 353;
                                                    }
                                                }
                                            }
                                        }
                                    }
                                    if (inst[7] == 'b') {
                                        if (inst[8] == '.') {
                                            if (inst[9] == 'a') {
                                                if (inst[10] == 'q') {
                                                    if (inst[11] == 'r') {
                                                        if (inst[12] == 'l') return 434;
                                                    }
                                                }
                                            }
                                        }
                                    }
                                    if (inst[7] == 'q') {
                                        if (inst[8] == '.') {
                                            if (inst[9] == 'a') {
                                                if (inst[10] == 'q') {
                                                    if (inst[11] == 'r') {
                                                        if (inst[12] == 'l') return 355;
                                                    }
                                                }
                                            }
                                        }
                                    }
                                    if (inst[7] == 'h') {
                                        if (inst[8] == '.') {
                                            if (inst[9] == 'a') {
                                                if (inst[10] == 'q') {
                                                    if (inst[11] == 'r') {
                                                        if (inst[12] == 'l') return 435;
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
                        if (inst[4] == 'o') {
                            if (inst[5] == 'r') {
                                if (inst[6] == '.') {
                                    if (inst[7] == 'd') {
                                        if (inst[8] == '.') {
                                            if (inst[9] == 'a') {
                                                if (inst[10] == 'q') {
                                                    if (inst[11] == 'r') {
                                                        if (inst[12] == 'l') return 148;
                                                    }
                                                }
                                            }
                                        }
                                    }
                                    if (inst[7] == 'w') {
                                        if (inst[8] == '.') {
                                            if (inst[9] == 'a') {
                                                if (inst[10] == 'q') {
                                                    if (inst[11] == 'r') {
                                                        if (inst[12] == 'l') return 104;
                                                    }
                                                }
                                            }
                                        }
                                    }
                                    if (inst[7] == 'b') {
                                        if (inst[8] == '.') {
                                            if (inst[9] == 'a') {
                                                if (inst[10] == 'q') {
                                                    if (inst[11] == 'r') {
                                                        if (inst[12] == 'l') return 424;
                                                    }
                                                }
                                            }
                                        }
                                    }
                                    if (inst[7] == 'h') {
                                        if (inst[8] == '.') {
                                            if (inst[9] == 'a') {
                                                if (inst[10] == 'q') {
                                                    if (inst[11] == 'r') {
                                                        if (inst[12] == 'l') return 425;
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
        if (inst[0] == 't') {
            if (inst[1] == 'h') {
                if (inst[2] == '.') {
                    if (inst[3] == 'd') {
                        if (inst[4] == 'c') {
                            if (inst[5] == 'a') {
                                if (inst[6] == 'c') {
                                    if (inst[7] == 'h') {
                                        if (inst[8] == 'e') {
                                            if (inst[9] == '.') {
                                                if (inst[10] == 'i') {
                                                    if (inst[11] == 's') {
                                                        if (inst[12] == 'w') return 1295;
                                                    }
                                                    if (inst[11] == 'p') {
                                                        if (inst[12] == 'a') return 1289;
                                                    }
                                                    if (inst[11] == 'v') {
                                                        if (inst[12] == 'a') return 1292;
                                                    }
                                                }
                                                if (inst[10] == 'c') {
                                                    if (inst[11] == 's') {
                                                        if (inst[12] == 'w') return 1293;
                                                    }
                                                    if (inst[11] == 'p') {
                                                        if (inst[12] == 'a') return 1287;
                                                    }
                                                    if (inst[11] == 'v') {
                                                        if (inst[12] == 'a') return 1290;
                                                    }
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                    if (inst[3] == 'i') {
                        if (inst[4] == 'c') {
                            if (inst[5] == 'a') {
                                if (inst[6] == 'c') {
                                    if (inst[7] == 'h') {
                                        if (inst[8] == 'e') {
                                            if (inst[9] == '.') {
                                                if (inst[10] == 'i') {
                                                    if (inst[11] == 'p') {
                                                        if (inst[12] == 'a') return 1300;
                                                    }
                                                    if (inst[11] == 'v') {
                                                        if (inst[12] == 'a') return 1301;
                                                    }
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                    if (inst[3] == 'v') {
                        if (inst[4] == 'a') {
                            if (inst[5] == 'm') {
                                if (inst[6] == 'o') {
                                    if (inst[7] == 'a') {
                                        if (inst[8] == 'd') {
                                            if (inst[9] == 'd') {
                                                if (inst[10] == 'd') {
                                                    if (inst[11] == '.') {
                                                        if (inst[12] == 'v') return 1726;
                                                    }
                                                }
                                                if (inst[10] == 'w') {
                                                    if (inst[11] == '.') {
                                                        if (inst[12] == 'v') return 1725;
                                                    }
                                                }
                                            }
                                        }
                                        if (inst[8] == 'n') {
                                            if (inst[9] == 'd') {
                                                if (inst[10] == 'd') {
                                                    if (inst[11] == '.') {
                                                        if (inst[12] == 'v') return 1730;
                                                    }
                                                }
                                                if (inst[10] == 'w') {
                                                    if (inst[11] == '.') {
                                                        if (inst[12] == 'v') return 1729;
                                                    }
                                                }
                                            }
                                        }
                                    }
                                    if (inst[7] == 'm') {
                                        if (inst[8] == 'a') {
                                            if (inst[9] == 'x') {
                                                if (inst[10] == 'd') {
                                                    if (inst[11] == '.') {
                                                        if (inst[12] == 'v') return 1736;
                                                    }
                                                }
                                                if (inst[10] == 'w') {
                                                    if (inst[11] == '.') {
                                                        if (inst[12] == 'v') return 1735;
                                                    }
                                                }
                                            }
                                        }
                                        if (inst[8] == 'i') {
                                            if (inst[9] == 'n') {
                                                if (inst[10] == 'd') {
                                                    if (inst[11] == '.') {
                                                        if (inst[12] == 'v') return 1734;
                                                    }
                                                }
                                                if (inst[10] == 'w') {
                                                    if (inst[11] == '.') {
                                                        if (inst[12] == 'v') return 1733;
                                                    }
                                                }
                                            }
                                        }
                                    }
                                    if (inst[7] == 'x') {
                                        if (inst[8] == 'o') {
                                            if (inst[9] == 'r') {
                                                if (inst[10] == 'd') {
                                                    if (inst[11] == '.') {
                                                        if (inst[12] == 'v') return 1728;
                                                    }
                                                }
                                                if (inst[10] == 'w') {
                                                    if (inst[11] == '.') {
                                                        if (inst[12] == 'v') return 1727;
                                                    }
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                        if (inst[4] == 'w') {
                            if (inst[5] == 's') {
                                if (inst[6] == 'm') {
                                    if (inst[7] == 'a') {
                                        if (inst[8] == 'c') {
                                            if (inst[9] == 'c') {
                                                if (inst[10] == '.') {
                                                    if (inst[11] == 'v') {
                                                        if (inst[12] == 'x') return 1889;
                                                        if (inst[12] == 'v') return 1888;
                                                    }
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                            if (inst[5] == 'm') {
                                if (inst[6] == 'a') {
                                    if (inst[7] == 'c') {
                                        if (inst[8] == 'c') {
                                            if (inst[9] == 'u') {
                                                if (inst[10] == '.') {
                                                    if (inst[11] == 'v') {
                                                        if (inst[12] == 'x') return 1857;
                                                        if (inst[12] == 'v') return 1856;
                                                    }
                                                }
                                            }
                                        }
                                    }
                                }
                                if (inst[6] == 'u') {
                                    if (inst[7] == 'l') {
                                        if (inst[8] == 's') {
                                            if (inst[9] == 'u') {
                                                if (inst[10] == '.') {
                                                    if (inst[11] == 'v') {
                                                        if (inst[12] == 'x') return 1847;
                                                        if (inst[12] == 'v') return 1846;
                                                    }
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                        if (inst[4] == 's') {
                            if (inst[5] == 's') {
                                if (inst[6] == 's') {
                                    if (inst[7] == 'e') {
                                        if (inst[8] == 'g') {
                                            if (inst[9] == '3') {
                                                if (inst[10] == 'w') {
                                                    if (inst[11] == '.') {
                                                        if (inst[12] == 'v') return 1624;
                                                    }
                                                }
                                                if (inst[10] == 'e') {
                                                    if (inst[11] == '.') {
                                                        if (inst[12] == 'v') return 1625;
                                                    }
                                                }
                                                if (inst[10] == 'b') {
                                                    if (inst[11] == '.') {
                                                        if (inst[12] == 'v') return 1622;
                                                    }
                                                }
                                                if (inst[10] == 'h') {
                                                    if (inst[11] == '.') {
                                                        if (inst[12] == 'v') return 1623;
                                                    }
                                                }
                                            }
                                            if (inst[9] == '2') {
                                                if (inst[10] == 'w') {
                                                    if (inst[11] == '.') {
                                                        if (inst[12] == 'v') return 1620;
                                                    }
                                                }
                                                if (inst[10] == 'e') {
                                                    if (inst[11] == '.') {
                                                        if (inst[12] == 'v') return 1621;
                                                    }
                                                }
                                                if (inst[10] == 'b') {
                                                    if (inst[11] == '.') {
                                                        if (inst[12] == 'v') return 1618;
                                                    }
                                                }
                                                if (inst[10] == 'h') {
                                                    if (inst[11] == '.') {
                                                        if (inst[12] == 'v') return 1619;
                                                    }
                                                }
                                            }
                                            if (inst[9] == '6') {
                                                if (inst[10] == 'w') {
                                                    if (inst[11] == '.') {
                                                        if (inst[12] == 'v') return 1636;
                                                    }
                                                }
                                                if (inst[10] == 'e') {
                                                    if (inst[11] == '.') {
                                                        if (inst[12] == 'v') return 1637;
                                                    }
                                                }
                                                if (inst[10] == 'b') {
                                                    if (inst[11] == '.') {
                                                        if (inst[12] == 'v') return 1634;
                                                    }
                                                }
                                                if (inst[10] == 'h') {
                                                    if (inst[11] == '.') {
                                                        if (inst[12] == 'v') return 1635;
                                                    }
                                                }
                                            }
                                            if (inst[9] == '4') {
                                                if (inst[10] == 'w') {
                                                    if (inst[11] == '.') {
                                                        if (inst[12] == 'v') return 1628;
                                                    }
                                                }
                                                if (inst[10] == 'e') {
                                                    if (inst[11] == '.') {
                                                        if (inst[12] == 'v') return 1629;
                                                    }
                                                }
                                                if (inst[10] == 'b') {
                                                    if (inst[11] == '.') {
                                                        if (inst[12] == 'v') return 1626;
                                                    }
                                                }
                                                if (inst[10] == 'h') {
                                                    if (inst[11] == '.') {
                                                        if (inst[12] == 'v') return 1627;
                                                    }
                                                }
                                            }
                                            if (inst[9] == '8') {
                                                if (inst[10] == 'w') {
                                                    if (inst[11] == '.') {
                                                        if (inst[12] == 'v') return 1644;
                                                    }
                                                }
                                                if (inst[10] == 'e') {
                                                    if (inst[11] == '.') {
                                                        if (inst[12] == 'v') return 1645;
                                                    }
                                                }
                                                if (inst[10] == 'b') {
                                                    if (inst[11] == '.') {
                                                        if (inst[12] == 'v') return 1642;
                                                    }
                                                }
                                                if (inst[10] == 'h') {
                                                    if (inst[11] == '.') {
                                                        if (inst[12] == 'v') return 1643;
                                                    }
                                                }
                                            }
                                            if (inst[9] == '5') {
                                                if (inst[10] == 'w') {
                                                    if (inst[11] == '.') {
                                                        if (inst[12] == 'v') return 1632;
                                                    }
                                                }
                                                if (inst[10] == 'e') {
                                                    if (inst[11] == '.') {
                                                        if (inst[12] == 'v') return 1633;
                                                    }
                                                }
                                                if (inst[10] == 'b') {
                                                    if (inst[11] == '.') {
                                                        if (inst[12] == 'v') return 1630;
                                                    }
                                                }
                                                if (inst[10] == 'h') {
                                                    if (inst[11] == '.') {
                                                        if (inst[12] == 'v') return 1631;
                                                    }
                                                }
                                            }
                                            if (inst[9] == '7') {
                                                if (inst[10] == 'w') {
                                                    if (inst[11] == '.') {
                                                        if (inst[12] == 'v') return 1640;
                                                    }
                                                }
                                                if (inst[10] == 'e') {
                                                    if (inst[11] == '.') {
                                                        if (inst[12] == 'v') return 1641;
                                                    }
                                                }
                                                if (inst[10] == 'b') {
                                                    if (inst[11] == '.') {
                                                        if (inst[12] == 'v') return 1638;
                                                    }
                                                }
                                                if (inst[10] == 'h') {
                                                    if (inst[11] == '.') {
                                                        if (inst[12] == 'v') return 1639;
                                                    }
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                            if (inst[5] == 'x') {
                                if (inst[6] == 's') {
                                    if (inst[7] == 'e') {
                                        if (inst[8] == 'g') {
                                            if (inst[9] == '3') {
                                                if (inst[10] == 'w') {
                                                    if (inst[11] == '.') {
                                                        if (inst[12] == 'v') return 1701;
                                                    }
                                                }
                                                if (inst[10] == 'e') {
                                                    if (inst[11] == '.') {
                                                        if (inst[12] == 'v') return 1702;
                                                    }
                                                }
                                                if (inst[10] == 'b') {
                                                    if (inst[11] == '.') {
                                                        if (inst[12] == 'v') return 1699;
                                                    }
                                                }
                                                if (inst[10] == 'h') {
                                                    if (inst[11] == '.') {
                                                        if (inst[12] == 'v') return 1700;
                                                    }
                                                }
                                            }
                                            if (inst[9] == '2') {
                                                if (inst[10] == 'w') {
                                                    if (inst[11] == '.') {
                                                        if (inst[12] == 'v') return 1697;
                                                    }
                                                }
                                                if (inst[10] == 'e') {
                                                    if (inst[11] == '.') {
                                                        if (inst[12] == 'v') return 1698;
                                                    }
                                                }
                                                if (inst[10] == 'b') {
                                                    if (inst[11] == '.') {
                                                        if (inst[12] == 'v') return 1695;
                                                    }
                                                }
                                                if (inst[10] == 'h') {
                                                    if (inst[11] == '.') {
                                                        if (inst[12] == 'v') return 1696;
                                                    }
                                                }
                                            }
                                            if (inst[9] == '6') {
                                                if (inst[10] == 'w') {
                                                    if (inst[11] == '.') {
                                                        if (inst[12] == 'v') return 1713;
                                                    }
                                                }
                                                if (inst[10] == 'e') {
                                                    if (inst[11] == '.') {
                                                        if (inst[12] == 'v') return 1714;
                                                    }
                                                }
                                                if (inst[10] == 'b') {
                                                    if (inst[11] == '.') {
                                                        if (inst[12] == 'v') return 1711;
                                                    }
                                                }
                                                if (inst[10] == 'h') {
                                                    if (inst[11] == '.') {
                                                        if (inst[12] == 'v') return 1712;
                                                    }
                                                }
                                            }
                                            if (inst[9] == '4') {
                                                if (inst[10] == 'w') {
                                                    if (inst[11] == '.') {
                                                        if (inst[12] == 'v') return 1705;
                                                    }
                                                }
                                                if (inst[10] == 'e') {
                                                    if (inst[11] == '.') {
                                                        if (inst[12] == 'v') return 1706;
                                                    }
                                                }
                                                if (inst[10] == 'b') {
                                                    if (inst[11] == '.') {
                                                        if (inst[12] == 'v') return 1703;
                                                    }
                                                }
                                                if (inst[10] == 'h') {
                                                    if (inst[11] == '.') {
                                                        if (inst[12] == 'v') return 1704;
                                                    }
                                                }
                                            }
                                            if (inst[9] == '8') {
                                                if (inst[10] == 'w') {
                                                    if (inst[11] == '.') {
                                                        if (inst[12] == 'v') return 1721;
                                                    }
                                                }
                                                if (inst[10] == 'e') {
                                                    if (inst[11] == '.') {
                                                        if (inst[12] == 'v') return 1722;
                                                    }
                                                }
                                                if (inst[10] == 'b') {
                                                    if (inst[11] == '.') {
                                                        if (inst[12] == 'v') return 1719;
                                                    }
                                                }
                                                if (inst[10] == 'h') {
                                                    if (inst[11] == '.') {
                                                        if (inst[12] == 'v') return 1720;
                                                    }
                                                }
                                            }
                                            if (inst[9] == '5') {
                                                if (inst[10] == 'w') {
                                                    if (inst[11] == '.') {
                                                        if (inst[12] == 'v') return 1709;
                                                    }
                                                }
                                                if (inst[10] == 'e') {
                                                    if (inst[11] == '.') {
                                                        if (inst[12] == 'v') return 1710;
                                                    }
                                                }
                                                if (inst[10] == 'b') {
                                                    if (inst[11] == '.') {
                                                        if (inst[12] == 'v') return 1707;
                                                    }
                                                }
                                                if (inst[10] == 'h') {
                                                    if (inst[11] == '.') {
                                                        if (inst[12] == 'v') return 1708;
                                                    }
                                                }
                                            }
                                            if (inst[9] == '7') {
                                                if (inst[10] == 'w') {
                                                    if (inst[11] == '.') {
                                                        if (inst[12] == 'v') return 1717;
                                                    }
                                                }
                                                if (inst[10] == 'e') {
                                                    if (inst[11] == '.') {
                                                        if (inst[12] == 'v') return 1718;
                                                    }
                                                }
                                                if (inst[10] == 'b') {
                                                    if (inst[11] == '.') {
                                                        if (inst[12] == 'v') return 1715;
                                                    }
                                                }
                                                if (inst[10] == 'h') {
                                                    if (inst[11] == '.') {
                                                        if (inst[12] == 'v') return 1716;
                                                    }
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                        if (inst[4] == 'm') {
                            if (inst[5] == 'a') {
                                if (inst[6] == 'q') {
                                    if (inst[7] == 'a') {
                                        if (inst[8] == 'u') {
                                            if (inst[9] == 's') {
                                                if (inst[10] == '.') {
                                                    if (inst[11] == 'v') {
                                                        if (inst[12] == 'x') return 1396;
                                                    }
                                                }
                                            }
                                        }
                                        if (inst[8] == 's') {
                                            if (inst[9] == 'u') {
                                                if (inst[10] == '.') {
                                                    if (inst[11] == 'v') {
                                                        if (inst[12] == 'x') return 1395;
                                                        if (inst[12] == 'v') return 1394;
                                                    }
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                            if (inst[5] == 'u') {
                                if (inst[6] == 'l') {
                                    if (inst[7] == 'h') {
                                        if (inst[8] == 's') {
                                            if (inst[9] == 'u') {
                                                if (inst[10] == '.') {
                                                    if (inst[11] == 'v') {
                                                        if (inst[12] == 'x') return 1833;
                                                        if (inst[12] == 'v') return 1832;
                                                    }
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                            if (inst[5] == 'e') {
                                if (inst[6] == 'r') {
                                    if (inst[7] == 'g') {
                                        if (inst[8] == 'e') {
                                            if (inst[9] == '.') {
                                                if (inst[10] == 'v') {
                                                    if (inst[11] == 'i') {
                                                        if (inst[12] == 'm') return 1865;
                                                    }
                                                    if (inst[11] == 'x') {
                                                        if (inst[12] == 'm') return 1864;
                                                    }
                                                    if (inst[11] == 'v') {
                                                        if (inst[12] == 'm') return 1863;
                                                    }
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                            if (inst[5] == 'o') {
                                if (inst[6] == 'r') {
                                    if (inst[7] == 'n') {
                                        if (inst[8] == 'o') {
                                            if (inst[9] == 't') {
                                                if (inst[10] == '.') {
                                                    if (inst[11] == 'm') {
                                                        if (inst[12] == 'm') return 2011;
                                                    }
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                        if (inst[4] == 'r') {
                            if (inst[5] == 'e') {
                                if (inst[6] == 'd') {
                                    if (inst[7] == 'a') {
                                        if (inst[8] == 'n') {
                                            if (inst[9] == 'd') {
                                                if (inst[10] == '.') {
                                                    if (inst[11] == 'v') {
                                                        if (inst[12] == 's') return 1994;
                                                    }
                                                }
                                            }
                                        }
                                    }
                                    if (inst[7] == 's') {
                                        if (inst[8] == 'u') {
                                            if (inst[9] == 'm') {
                                                if (inst[10] == '.') {
                                                    if (inst[11] == 'v') {
                                                        if (inst[12] == 's') return 1989;
                                                    }
                                                }
                                            }
                                        }
                                    }
                                    if (inst[7] == 'm') {
                                        if (inst[8] == 'a') {
                                            if (inst[9] == 'x') {
                                                if (inst[10] == '.') {
                                                    if (inst[11] == 'v') {
                                                        if (inst[12] == 's') return 1991;
                                                    }
                                                }
                                            }
                                        }
                                        if (inst[8] == 'i') {
                                            if (inst[9] == 'n') {
                                                if (inst[10] == '.') {
                                                    if (inst[11] == 'v') {
                                                        if (inst[12] == 's') return 1993;
                                                    }
                                                }
                                            }
                                        }
                                    }
                                    if (inst[7] == 'x') {
                                        if (inst[8] == 'o') {
                                            if (inst[9] == 'r') {
                                                if (inst[10] == '.') {
                                                    if (inst[11] == 'v') {
                                                        if (inst[12] == 's') return 1996;
                                                    }
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                        if (inst[4] == 'l') {
                            if (inst[5] == 's') {
                                if (inst[6] == 'e') {
                                    if (inst[7] == 'g') {
                                        if (inst[8] == '3') {
                                            if (inst[9] == 'w') {
                                                if (inst[10] == 'u') {
                                                    if (inst[11] == '.') {
                                                        if (inst[12] == 'v') return 1476;
                                                    }
                                                }
                                            }
                                            if (inst[9] == 'b') {
                                                if (inst[10] == 'u') {
                                                    if (inst[11] == '.') {
                                                        if (inst[12] == 'v') return 1474;
                                                    }
                                                }
                                            }
                                            if (inst[9] == 'h') {
                                                if (inst[10] == 'u') {
                                                    if (inst[11] == '.') {
                                                        if (inst[12] == 'v') return 1475;
                                                    }
                                                }
                                            }
                                        }
                                        if (inst[8] == '2') {
                                            if (inst[9] == 'w') {
                                                if (inst[10] == 'u') {
                                                    if (inst[11] == '.') {
                                                        if (inst[12] == 'v') return 1473;
                                                    }
                                                }
                                            }
                                            if (inst[9] == 'b') {
                                                if (inst[10] == 'u') {
                                                    if (inst[11] == '.') {
                                                        if (inst[12] == 'v') return 1471;
                                                    }
                                                }
                                            }
                                            if (inst[9] == 'h') {
                                                if (inst[10] == 'u') {
                                                    if (inst[11] == '.') {
                                                        if (inst[12] == 'v') return 1472;
                                                    }
                                                }
                                            }
                                        }
                                        if (inst[8] == '6') {
                                            if (inst[9] == 'w') {
                                                if (inst[10] == 'u') {
                                                    if (inst[11] == '.') {
                                                        if (inst[12] == 'v') return 1485;
                                                    }
                                                }
                                            }
                                            if (inst[9] == 'b') {
                                                if (inst[10] == 'u') {
                                                    if (inst[11] == '.') {
                                                        if (inst[12] == 'v') return 1483;
                                                    }
                                                }
                                            }
                                            if (inst[9] == 'h') {
                                                if (inst[10] == 'u') {
                                                    if (inst[11] == '.') {
                                                        if (inst[12] == 'v') return 1484;
                                                    }
                                                }
                                            }
                                        }
                                        if (inst[8] == '4') {
                                            if (inst[9] == 'w') {
                                                if (inst[10] == 'u') {
                                                    if (inst[11] == '.') {
                                                        if (inst[12] == 'v') return 1479;
                                                    }
                                                }
                                            }
                                            if (inst[9] == 'b') {
                                                if (inst[10] == 'u') {
                                                    if (inst[11] == '.') {
                                                        if (inst[12] == 'v') return 1477;
                                                    }
                                                }
                                            }
                                            if (inst[9] == 'h') {
                                                if (inst[10] == 'u') {
                                                    if (inst[11] == '.') {
                                                        if (inst[12] == 'v') return 1478;
                                                    }
                                                }
                                            }
                                        }
                                        if (inst[8] == '8') {
                                            if (inst[9] == 'w') {
                                                if (inst[10] == 'u') {
                                                    if (inst[11] == '.') {
                                                        if (inst[12] == 'v') return 1491;
                                                    }
                                                }
                                            }
                                            if (inst[9] == 'b') {
                                                if (inst[10] == 'u') {
                                                    if (inst[11] == '.') {
                                                        if (inst[12] == 'v') return 1489;
                                                    }
                                                }
                                            }
                                            if (inst[9] == 'h') {
                                                if (inst[10] == 'u') {
                                                    if (inst[11] == '.') {
                                                        if (inst[12] == 'v') return 1490;
                                                    }
                                                }
                                            }
                                        }
                                        if (inst[8] == '5') {
                                            if (inst[9] == 'w') {
                                                if (inst[10] == 'u') {
                                                    if (inst[11] == '.') {
                                                        if (inst[12] == 'v') return 1482;
                                                    }
                                                }
                                            }
                                            if (inst[9] == 'b') {
                                                if (inst[10] == 'u') {
                                                    if (inst[11] == '.') {
                                                        if (inst[12] == 'v') return 1480;
                                                    }
                                                }
                                            }
                                            if (inst[9] == 'h') {
                                                if (inst[10] == 'u') {
                                                    if (inst[11] == '.') {
                                                        if (inst[12] == 'v') return 1481;
                                                    }
                                                }
                                            }
                                        }
                                        if (inst[8] == '7') {
                                            if (inst[9] == 'w') {
                                                if (inst[10] == 'u') {
                                                    if (inst[11] == '.') {
                                                        if (inst[12] == 'v') return 1488;
                                                    }
                                                }
                                            }
                                            if (inst[9] == 'b') {
                                                if (inst[10] == 'u') {
                                                    if (inst[11] == '.') {
                                                        if (inst[12] == 'v') return 1486;
                                                    }
                                                }
                                            }
                                            if (inst[9] == 'h') {
                                                if (inst[10] == 'u') {
                                                    if (inst[11] == '.') {
                                                        if (inst[12] == 'v') return 1487;
                                                    }
                                                }
                                            }
                                        }
                                    }
                                }
                                if (inst[6] == 's') {
                                    if (inst[7] == 'e') {
                                        if (inst[8] == 'g') {
                                            if (inst[9] == '3') {
                                                if (inst[10] == 'w') {
                                                    if (inst[11] == '.') {
                                                        if (inst[12] == 'v') return 1574;
                                                    }
                                                }
                                                if (inst[10] == 'e') {
                                                    if (inst[11] == '.') {
                                                        if (inst[12] == 'v') return 1591;
                                                    }
                                                }
                                                if (inst[10] == 'b') {
                                                    if (inst[11] == '.') {
                                                        if (inst[12] == 'v') return 1572;
                                                    }
                                                }
                                                if (inst[10] == 'h') {
                                                    if (inst[11] == '.') {
                                                        if (inst[12] == 'v') return 1573;
                                                    }
                                                }
                                            }
                                            if (inst[9] == '2') {
                                                if (inst[10] == 'w') {
                                                    if (inst[11] == '.') {
                                                        if (inst[12] == 'v') return 1571;
                                                    }
                                                }
                                                if (inst[10] == 'e') {
                                                    if (inst[11] == '.') {
                                                        if (inst[12] == 'v') return 1590;
                                                    }
                                                }
                                                if (inst[10] == 'b') {
                                                    if (inst[11] == '.') {
                                                        if (inst[12] == 'v') return 1569;
                                                    }
                                                }
                                                if (inst[10] == 'h') {
                                                    if (inst[11] == '.') {
                                                        if (inst[12] == 'v') return 1570;
                                                    }
                                                }
                                            }
                                            if (inst[9] == '6') {
                                                if (inst[10] == 'w') {
                                                    if (inst[11] == '.') {
                                                        if (inst[12] == 'v') return 1583;
                                                    }
                                                }
                                                if (inst[10] == 'e') {
                                                    if (inst[11] == '.') {
                                                        if (inst[12] == 'v') return 1594;
                                                    }
                                                }
                                                if (inst[10] == 'b') {
                                                    if (inst[11] == '.') {
                                                        if (inst[12] == 'v') return 1581;
                                                    }
                                                }
                                                if (inst[10] == 'h') {
                                                    if (inst[11] == '.') {
                                                        if (inst[12] == 'v') return 1582;
                                                    }
                                                }
                                            }
                                            if (inst[9] == '4') {
                                                if (inst[10] == 'w') {
                                                    if (inst[11] == '.') {
                                                        if (inst[12] == 'v') return 1577;
                                                    }
                                                }
                                                if (inst[10] == 'e') {
                                                    if (inst[11] == '.') {
                                                        if (inst[12] == 'v') return 1592;
                                                    }
                                                }
                                                if (inst[10] == 'b') {
                                                    if (inst[11] == '.') {
                                                        if (inst[12] == 'v') return 1575;
                                                    }
                                                }
                                                if (inst[10] == 'h') {
                                                    if (inst[11] == '.') {
                                                        if (inst[12] == 'v') return 1576;
                                                    }
                                                }
                                            }
                                            if (inst[9] == '8') {
                                                if (inst[10] == 'w') {
                                                    if (inst[11] == '.') {
                                                        if (inst[12] == 'v') return 1589;
                                                    }
                                                }
                                                if (inst[10] == 'e') {
                                                    if (inst[11] == '.') {
                                                        if (inst[12] == 'v') return 1596;
                                                    }
                                                }
                                                if (inst[10] == 'b') {
                                                    if (inst[11] == '.') {
                                                        if (inst[12] == 'v') return 1587;
                                                    }
                                                }
                                                if (inst[10] == 'h') {
                                                    if (inst[11] == '.') {
                                                        if (inst[12] == 'v') return 1588;
                                                    }
                                                }
                                            }
                                            if (inst[9] == '5') {
                                                if (inst[10] == 'w') {
                                                    if (inst[11] == '.') {
                                                        if (inst[12] == 'v') return 1580;
                                                    }
                                                }
                                                if (inst[10] == 'e') {
                                                    if (inst[11] == '.') {
                                                        if (inst[12] == 'v') return 1593;
                                                    }
                                                }
                                                if (inst[10] == 'b') {
                                                    if (inst[11] == '.') {
                                                        if (inst[12] == 'v') return 1578;
                                                    }
                                                }
                                                if (inst[10] == 'h') {
                                                    if (inst[11] == '.') {
                                                        if (inst[12] == 'v') return 1579;
                                                    }
                                                }
                                            }
                                            if (inst[9] == '7') {
                                                if (inst[10] == 'w') {
                                                    if (inst[11] == '.') {
                                                        if (inst[12] == 'v') return 1586;
                                                    }
                                                }
                                                if (inst[10] == 'e') {
                                                    if (inst[11] == '.') {
                                                        if (inst[12] == 'v') return 1595;
                                                    }
                                                }
                                                if (inst[10] == 'b') {
                                                    if (inst[11] == '.') {
                                                        if (inst[12] == 'v') return 1584;
                                                    }
                                                }
                                                if (inst[10] == 'h') {
                                                    if (inst[11] == '.') {
                                                        if (inst[12] == 'v') return 1585;
                                                    }
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                            if (inst[5] == 'x') {
                                if (inst[6] == 's') {
                                    if (inst[7] == 'e') {
                                        if (inst[8] == 'g') {
                                            if (inst[9] == '3') {
                                                if (inst[10] == 'w') {
                                                    if (inst[11] == '.') {
                                                        if (inst[12] == 'v') return 1651;
                                                    }
                                                }
                                                if (inst[10] == 'e') {
                                                    if (inst[11] == '.') {
                                                        if (inst[12] == 'v') return 1668;
                                                    }
                                                }
                                                if (inst[10] == 'b') {
                                                    if (inst[11] == '.') {
                                                        if (inst[12] == 'v') return 1649;
                                                    }
                                                }
                                                if (inst[10] == 'h') {
                                                    if (inst[11] == '.') {
                                                        if (inst[12] == 'v') return 1650;
                                                    }
                                                }
                                            }
                                            if (inst[9] == '2') {
                                                if (inst[10] == 'w') {
                                                    if (inst[11] == '.') {
                                                        if (inst[12] == 'v') return 1648;
                                                    }
                                                }
                                                if (inst[10] == 'e') {
                                                    if (inst[11] == '.') {
                                                        if (inst[12] == 'v') return 1667;
                                                    }
                                                }
                                                if (inst[10] == 'b') {
                                                    if (inst[11] == '.') {
                                                        if (inst[12] == 'v') return 1646;
                                                    }
                                                }
                                                if (inst[10] == 'h') {
                                                    if (inst[11] == '.') {
                                                        if (inst[12] == 'v') return 1647;
                                                    }
                                                }
                                            }
                                            if (inst[9] == '6') {
                                                if (inst[10] == 'w') {
                                                    if (inst[11] == '.') {
                                                        if (inst[12] == 'v') return 1660;
                                                    }
                                                }
                                                if (inst[10] == 'e') {
                                                    if (inst[11] == '.') {
                                                        if (inst[12] == 'v') return 1671;
                                                    }
                                                }
                                                if (inst[10] == 'b') {
                                                    if (inst[11] == '.') {
                                                        if (inst[12] == 'v') return 1658;
                                                    }
                                                }
                                                if (inst[10] == 'h') {
                                                    if (inst[11] == '.') {
                                                        if (inst[12] == 'v') return 1659;
                                                    }
                                                }
                                            }
                                            if (inst[9] == '4') {
                                                if (inst[10] == 'w') {
                                                    if (inst[11] == '.') {
                                                        if (inst[12] == 'v') return 1654;
                                                    }
                                                }
                                                if (inst[10] == 'e') {
                                                    if (inst[11] == '.') {
                                                        if (inst[12] == 'v') return 1669;
                                                    }
                                                }
                                                if (inst[10] == 'b') {
                                                    if (inst[11] == '.') {
                                                        if (inst[12] == 'v') return 1652;
                                                    }
                                                }
                                                if (inst[10] == 'h') {
                                                    if (inst[11] == '.') {
                                                        if (inst[12] == 'v') return 1653;
                                                    }
                                                }
                                            }
                                            if (inst[9] == '8') {
                                                if (inst[10] == 'w') {
                                                    if (inst[11] == '.') {
                                                        if (inst[12] == 'v') return 1666;
                                                    }
                                                }
                                                if (inst[10] == 'e') {
                                                    if (inst[11] == '.') {
                                                        if (inst[12] == 'v') return 1673;
                                                    }
                                                }
                                                if (inst[10] == 'b') {
                                                    if (inst[11] == '.') {
                                                        if (inst[12] == 'v') return 1664;
                                                    }
                                                }
                                                if (inst[10] == 'h') {
                                                    if (inst[11] == '.') {
                                                        if (inst[12] == 'v') return 1665;
                                                    }
                                                }
                                            }
                                            if (inst[9] == '5') {
                                                if (inst[10] == 'w') {
                                                    if (inst[11] == '.') {
                                                        if (inst[12] == 'v') return 1657;
                                                    }
                                                }
                                                if (inst[10] == 'e') {
                                                    if (inst[11] == '.') {
                                                        if (inst[12] == 'v') return 1670;
                                                    }
                                                }
                                                if (inst[10] == 'b') {
                                                    if (inst[11] == '.') {
                                                        if (inst[12] == 'v') return 1655;
                                                    }
                                                }
                                                if (inst[10] == 'h') {
                                                    if (inst[11] == '.') {
                                                        if (inst[12] == 'v') return 1656;
                                                    }
                                                }
                                            }
                                            if (inst[9] == '7') {
                                                if (inst[10] == 'w') {
                                                    if (inst[11] == '.') {
                                                        if (inst[12] == 'v') return 1663;
                                                    }
                                                }
                                                if (inst[10] == 'e') {
                                                    if (inst[11] == '.') {
                                                        if (inst[12] == 'v') return 1672;
                                                    }
                                                }
                                                if (inst[10] == 'b') {
                                                    if (inst[11] == '.') {
                                                        if (inst[12] == 'v') return 1661;
                                                    }
                                                }
                                                if (inst[10] == 'h') {
                                                    if (inst[11] == '.') {
                                                        if (inst[12] == 'v') return 1662;
                                                    }
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                        if (inst[4] == 'n') {
                            if (inst[5] == 'c') {
                                if (inst[6] == 'l') {
                                    if (inst[7] == 'i') {
                                        if (inst[8] == 'p') {
                                            if (inst[9] == 'u') {
                                                if (inst[10] == '.') {
                                                    if (inst[11] == 'v') {
                                                        if (inst[12] == 'i') return 1901;
                                                        if (inst[12] == 'x') return 1900;
                                                        if (inst[12] == 'v') return 1899;
                                                    }
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                        if (inst[4] == 'f') {
                            if (inst[5] == 'w') {
                                if (inst[6] == 'm') {
                                    if (inst[7] == 'a') {
                                        if (inst[8] == 'c') {
                                            if (inst[9] == 'c') {
                                                if (inst[10] == '.') {
                                                    if (inst[11] == 'v') {
                                                        if (inst[12] == 'v') return 1941;
                                                        if (inst[12] == 'f') return 1942;
                                                    }
                                                }
                                            }
                                        }
                                    }
                                    if (inst[7] == 's') {
                                        if (inst[8] == 'a') {
                                            if (inst[9] == 'c') {
                                                if (inst[10] == '.') {
                                                    if (inst[11] == 'v') {
                                                        if (inst[12] == 'v') return 1945;
                                                        if (inst[12] == 'f') return 1946;
                                                    }
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                            if (inst[5] == 's') {
                                if (inst[6] == 'g') {
                                    if (inst[7] == 'n') {
                                        if (inst[8] == 'j') {
                                            if (inst[9] == 'n') {
                                                if (inst[10] == '.') {
                                                    if (inst[11] == 'v') {
                                                        if (inst[12] == 'v') return 1956;
                                                        if (inst[12] == 'f') return 1957;
                                                    }
                                                }
                                            }
                                            if (inst[9] == 'x') {
                                                if (inst[10] == '.') {
                                                    if (inst[11] == 'v') {
                                                        if (inst[12] == 'v') return 1958;
                                                        if (inst[12] == 'f') return 1959;
                                                    }
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                            if (inst[5] == 'n') {
                                if (inst[6] == 'm') {
                                    if (inst[7] == 'a') {
                                        if (inst[8] == 'd') {
                                            if (inst[9] == 'd') {
                                                if (inst[10] == '.') {
                                                    if (inst[11] == 'v') {
                                                        if (inst[12] == 'v') return 1935;
                                                        if (inst[12] == 'f') return 1936;
                                                    }
                                                }
                                            }
                                        }
                                        if (inst[8] == 'c') {
                                            if (inst[9] == 'c') {
                                                if (inst[10] == '.') {
                                                    if (inst[11] == 'v') {
                                                        if (inst[12] == 'v') return 1927;
                                                        if (inst[12] == 'f') return 1928;
                                                    }
                                                }
                                            }
                                        }
                                    }
                                    if (inst[7] == 's') {
                                        if (inst[8] == 'a') {
                                            if (inst[9] == 'c') {
                                                if (inst[10] == '.') {
                                                    if (inst[11] == 'v') {
                                                        if (inst[12] == 'v') return 1931;
                                                        if (inst[12] == 'f') return 1932;
                                                    }
                                                }
                                            }
                                        }
                                        if (inst[8] == 'u') {
                                            if (inst[9] == 'b') {
                                                if (inst[10] == '.') {
                                                    if (inst[11] == 'v') {
                                                        if (inst[12] == 'v') return 1939;
                                                        if (inst[12] == 'f') return 1940;
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
        if (inst[0] == 'v') {
            if (inst[1] == 's') {
                if (inst[2] == 'u') {
                    if (inst[3] == 'x') {
                        if (inst[4] == 's') {
                            if (inst[5] == 'e') {
                                if (inst[6] == 'g') {
                                    if (inst[7] == '3') {
                                        if (inst[8] == 'e') {
                                            if (inst[9] == 'i') {
                                                if (inst[10] == '8') {
                                                    if (inst[11] == '.') {
                                                        if (inst[12] == 'v') return 778;
                                                    }
                                                }
                                            }
                                        }
                                    }
                                    if (inst[7] == '2') {
                                        if (inst[8] == 'e') {
                                            if (inst[9] == 'i') {
                                                if (inst[10] == '8') {
                                                    if (inst[11] == '.') {
                                                        if (inst[12] == 'v') return 762;
                                                    }
                                                }
                                            }
                                        }
                                    }
                                    if (inst[7] == '6') {
                                        if (inst[8] == 'e') {
                                            if (inst[9] == 'i') {
                                                if (inst[10] == '8') {
                                                    if (inst[11] == '.') {
                                                        if (inst[12] == 'v') return 826;
                                                    }
                                                }
                                            }
                                        }
                                    }
                                    if (inst[7] == '4') {
                                        if (inst[8] == 'e') {
                                            if (inst[9] == 'i') {
                                                if (inst[10] == '8') {
                                                    if (inst[11] == '.') {
                                                        if (inst[12] == 'v') return 794;
                                                    }
                                                }
                                            }
                                        }
                                    }
                                    if (inst[7] == '8') {
                                        if (inst[8] == 'e') {
                                            if (inst[9] == 'i') {
                                                if (inst[10] == '8') {
                                                    if (inst[11] == '.') {
                                                        if (inst[12] == 'v') return 858;
                                                    }
                                                }
                                            }
                                        }
                                    }
                                    if (inst[7] == '5') {
                                        if (inst[8] == 'e') {
                                            if (inst[9] == 'i') {
                                                if (inst[10] == '8') {
                                                    if (inst[11] == '.') {
                                                        if (inst[12] == 'v') return 810;
                                                    }
                                                }
                                            }
                                        }
                                    }
                                    if (inst[7] == '7') {
                                        if (inst[8] == 'e') {
                                            if (inst[9] == 'i') {
                                                if (inst[10] == '8') {
                                                    if (inst[11] == '.') {
                                                        if (inst[12] == 'v') return 842;
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
                if (inst[2] == 'o') {
                    if (inst[3] == 'x') {
                        if (inst[4] == 's') {
                            if (inst[5] == 'e') {
                                if (inst[6] == 'g') {
                                    if (inst[7] == '3') {
                                        if (inst[8] == 'e') {
                                            if (inst[9] == 'i') {
                                                if (inst[10] == '8') {
                                                    if (inst[11] == '.') {
                                                        if (inst[12] == 'v') return 779;
                                                    }
                                                }
                                            }
                                        }
                                    }
                                    if (inst[7] == '2') {
                                        if (inst[8] == 'e') {
                                            if (inst[9] == 'i') {
                                                if (inst[10] == '8') {
                                                    if (inst[11] == '.') {
                                                        if (inst[12] == 'v') return 763;
                                                    }
                                                }
                                            }
                                        }
                                    }
                                    if (inst[7] == '6') {
                                        if (inst[8] == 'e') {
                                            if (inst[9] == 'i') {
                                                if (inst[10] == '8') {
                                                    if (inst[11] == '.') {
                                                        if (inst[12] == 'v') return 827;
                                                    }
                                                }
                                            }
                                        }
                                    }
                                    if (inst[7] == '4') {
                                        if (inst[8] == 'e') {
                                            if (inst[9] == 'i') {
                                                if (inst[10] == '8') {
                                                    if (inst[11] == '.') {
                                                        if (inst[12] == 'v') return 795;
                                                    }
                                                }
                                            }
                                        }
                                    }
                                    if (inst[7] == '8') {
                                        if (inst[8] == 'e') {
                                            if (inst[9] == 'i') {
                                                if (inst[10] == '8') {
                                                    if (inst[11] == '.') {
                                                        if (inst[12] == 'v') return 859;
                                                    }
                                                }
                                            }
                                        }
                                    }
                                    if (inst[7] == '5') {
                                        if (inst[8] == 'e') {
                                            if (inst[9] == 'i') {
                                                if (inst[10] == '8') {
                                                    if (inst[11] == '.') {
                                                        if (inst[12] == 'v') return 811;
                                                    }
                                                }
                                            }
                                        }
                                    }
                                    if (inst[7] == '7') {
                                        if (inst[8] == 'e') {
                                            if (inst[9] == 'i') {
                                                if (inst[10] == '8') {
                                                    if (inst[11] == '.') {
                                                        if (inst[12] == 'v') return 843;
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
                if (inst[2] == 'l') {
                    if (inst[3] == 'i') {
                        if (inst[4] == 'd') {
                            if (inst[5] == 'e') {
                                if (inst[6] == 'd') {
                                    if (inst[7] == 'o') {
                                        if (inst[8] == 'w') {
                                            if (inst[9] == 'n') {
                                                if (inst[10] == '.') {
                                                    if (inst[11] == 'v') {
                                                        if (inst[12] == 'i') return 1192;
                                                        if (inst[12] == 'x') return 1191;
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
                if (inst[2] == 'u') {
                    if (inst[3] == 'x') {
                        if (inst[4] == 's') {
                            if (inst[5] == 'e') {
                                if (inst[6] == 'g') {
                                    if (inst[7] == '3') {
                                        if (inst[8] == 'e') {
                                            if (inst[9] == 'i') {
                                                if (inst[10] == '8') {
                                                    if (inst[11] == '.') {
                                                        if (inst[12] == 'v') return 776;
                                                    }
                                                }
                                            }
                                        }
                                    }
                                    if (inst[7] == '2') {
                                        if (inst[8] == 'e') {
                                            if (inst[9] == 'i') {
                                                if (inst[10] == '8') {
                                                    if (inst[11] == '.') {
                                                        if (inst[12] == 'v') return 760;
                                                    }
                                                }
                                            }
                                        }
                                    }
                                    if (inst[7] == '6') {
                                        if (inst[8] == 'e') {
                                            if (inst[9] == 'i') {
                                                if (inst[10] == '8') {
                                                    if (inst[11] == '.') {
                                                        if (inst[12] == 'v') return 824;
                                                    }
                                                }
                                            }
                                        }
                                    }
                                    if (inst[7] == '4') {
                                        if (inst[8] == 'e') {
                                            if (inst[9] == 'i') {
                                                if (inst[10] == '8') {
                                                    if (inst[11] == '.') {
                                                        if (inst[12] == 'v') return 792;
                                                    }
                                                }
                                            }
                                        }
                                    }
                                    if (inst[7] == '8') {
                                        if (inst[8] == 'e') {
                                            if (inst[9] == 'i') {
                                                if (inst[10] == '8') {
                                                    if (inst[11] == '.') {
                                                        if (inst[12] == 'v') return 856;
                                                    }
                                                }
                                            }
                                        }
                                    }
                                    if (inst[7] == '5') {
                                        if (inst[8] == 'e') {
                                            if (inst[9] == 'i') {
                                                if (inst[10] == '8') {
                                                    if (inst[11] == '.') {
                                                        if (inst[12] == 'v') return 808;
                                                    }
                                                }
                                            }
                                        }
                                    }
                                    if (inst[7] == '7') {
                                        if (inst[8] == 'e') {
                                            if (inst[9] == 'i') {
                                                if (inst[10] == '8') {
                                                    if (inst[11] == '.') {
                                                        if (inst[12] == 'v') return 840;
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
                    if (inst[3] == 'e') {
                        if (inst[4] == 'g') {
                            if (inst[5] == '3') {
                                if (inst[6] == 'e') {
                                    if (inst[7] == '3') {
                                        if (inst[8] == '2') {
                                            if (inst[9] == 'f') {
                                                if (inst[10] == 'f') {
                                                    if (inst[11] == '.') {
                                                        if (inst[12] == 'v') return 682;
                                                    }
                                                }
                                            }
                                        }
                                    }
                                    if (inst[7] == '6') {
                                        if (inst[8] == '4') {
                                            if (inst[9] == 'f') {
                                                if (inst[10] == 'f') {
                                                    if (inst[11] == '.') {
                                                        if (inst[12] == 'v') return 683;
                                                    }
                                                }
                                            }
                                        }
                                    }
                                    if (inst[7] == '1') {
                                        if (inst[8] == '6') {
                                            if (inst[9] == 'f') {
                                                if (inst[10] == 'f') {
                                                    if (inst[11] == '.') {
                                                        if (inst[12] == 'v') return 681;
                                                    }
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                            if (inst[5] == '2') {
                                if (inst[6] == 'e') {
                                    if (inst[7] == '3') {
                                        if (inst[8] == '2') {
                                            if (inst[9] == 'f') {
                                                if (inst[10] == 'f') {
                                                    if (inst[11] == '.') {
                                                        if (inst[12] == 'v') return 678;
                                                    }
                                                }
                                            }
                                        }
                                    }
                                    if (inst[7] == '6') {
                                        if (inst[8] == '4') {
                                            if (inst[9] == 'f') {
                                                if (inst[10] == 'f') {
                                                    if (inst[11] == '.') {
                                                        if (inst[12] == 'v') return 679;
                                                    }
                                                }
                                            }
                                        }
                                    }
                                    if (inst[7] == '1') {
                                        if (inst[8] == '6') {
                                            if (inst[9] == 'f') {
                                                if (inst[10] == 'f') {
                                                    if (inst[11] == '.') {
                                                        if (inst[12] == 'v') return 677;
                                                    }
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                            if (inst[5] == '6') {
                                if (inst[6] == 'e') {
                                    if (inst[7] == '3') {
                                        if (inst[8] == '2') {
                                            if (inst[9] == 'f') {
                                                if (inst[10] == 'f') {
                                                    if (inst[11] == '.') {
                                                        if (inst[12] == 'v') return 694;
                                                    }
                                                }
                                            }
                                        }
                                    }
                                    if (inst[7] == '6') {
                                        if (inst[8] == '4') {
                                            if (inst[9] == 'f') {
                                                if (inst[10] == 'f') {
                                                    if (inst[11] == '.') {
                                                        if (inst[12] == 'v') return 695;
                                                    }
                                                }
                                            }
                                        }
                                    }
                                    if (inst[7] == '1') {
                                        if (inst[8] == '6') {
                                            if (inst[9] == 'f') {
                                                if (inst[10] == 'f') {
                                                    if (inst[11] == '.') {
                                                        if (inst[12] == 'v') return 693;
                                                    }
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                            if (inst[5] == '4') {
                                if (inst[6] == 'e') {
                                    if (inst[7] == '3') {
                                        if (inst[8] == '2') {
                                            if (inst[9] == 'f') {
                                                if (inst[10] == 'f') {
                                                    if (inst[11] == '.') {
                                                        if (inst[12] == 'v') return 686;
                                                    }
                                                }
                                            }
                                        }
                                    }
                                    if (inst[7] == '6') {
                                        if (inst[8] == '4') {
                                            if (inst[9] == 'f') {
                                                if (inst[10] == 'f') {
                                                    if (inst[11] == '.') {
                                                        if (inst[12] == 'v') return 687;
                                                    }
                                                }
                                            }
                                        }
                                    }
                                    if (inst[7] == '1') {
                                        if (inst[8] == '6') {
                                            if (inst[9] == 'f') {
                                                if (inst[10] == 'f') {
                                                    if (inst[11] == '.') {
                                                        if (inst[12] == 'v') return 685;
                                                    }
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                            if (inst[5] == '8') {
                                if (inst[6] == 'e') {
                                    if (inst[7] == '3') {
                                        if (inst[8] == '2') {
                                            if (inst[9] == 'f') {
                                                if (inst[10] == 'f') {
                                                    if (inst[11] == '.') {
                                                        if (inst[12] == 'v') return 702;
                                                    }
                                                }
                                            }
                                        }
                                    }
                                    if (inst[7] == '6') {
                                        if (inst[8] == '4') {
                                            if (inst[9] == 'f') {
                                                if (inst[10] == 'f') {
                                                    if (inst[11] == '.') {
                                                        if (inst[12] == 'v') return 703;
                                                    }
                                                }
                                            }
                                        }
                                    }
                                    if (inst[7] == '1') {
                                        if (inst[8] == '6') {
                                            if (inst[9] == 'f') {
                                                if (inst[10] == 'f') {
                                                    if (inst[11] == '.') {
                                                        if (inst[12] == 'v') return 701;
                                                    }
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                            if (inst[5] == '5') {
                                if (inst[6] == 'e') {
                                    if (inst[7] == '3') {
                                        if (inst[8] == '2') {
                                            if (inst[9] == 'f') {
                                                if (inst[10] == 'f') {
                                                    if (inst[11] == '.') {
                                                        if (inst[12] == 'v') return 690;
                                                    }
                                                }
                                            }
                                        }
                                    }
                                    if (inst[7] == '6') {
                                        if (inst[8] == '4') {
                                            if (inst[9] == 'f') {
                                                if (inst[10] == 'f') {
                                                    if (inst[11] == '.') {
                                                        if (inst[12] == 'v') return 691;
                                                    }
                                                }
                                            }
                                        }
                                    }
                                    if (inst[7] == '1') {
                                        if (inst[8] == '6') {
                                            if (inst[9] == 'f') {
                                                if (inst[10] == 'f') {
                                                    if (inst[11] == '.') {
                                                        if (inst[12] == 'v') return 689;
                                                    }
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                            if (inst[5] == '7') {
                                if (inst[6] == 'e') {
                                    if (inst[7] == '3') {
                                        if (inst[8] == '2') {
                                            if (inst[9] == 'f') {
                                                if (inst[10] == 'f') {
                                                    if (inst[11] == '.') {
                                                        if (inst[12] == 'v') return 698;
                                                    }
                                                }
                                            }
                                        }
                                    }
                                    if (inst[7] == '6') {
                                        if (inst[8] == '4') {
                                            if (inst[9] == 'f') {
                                                if (inst[10] == 'f') {
                                                    if (inst[11] == '.') {
                                                        if (inst[12] == 'v') return 699;
                                                    }
                                                }
                                            }
                                        }
                                    }
                                    if (inst[7] == '1') {
                                        if (inst[8] == '6') {
                                            if (inst[9] == 'f') {
                                                if (inst[10] == 'f') {
                                                    if (inst[11] == '.') {
                                                        if (inst[12] == 'v') return 697;
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
                if (inst[2] == 'o') {
                    if (inst[3] == 'x') {
                        if (inst[4] == 's') {
                            if (inst[5] == 'e') {
                                if (inst[6] == 'g') {
                                    if (inst[7] == '3') {
                                        if (inst[8] == 'e') {
                                            if (inst[9] == 'i') {
                                                if (inst[10] == '8') {
                                                    if (inst[11] == '.') {
                                                        if (inst[12] == 'v') return 777;
                                                    }
                                                }
                                            }
                                        }
                                    }
                                    if (inst[7] == '2') {
                                        if (inst[8] == 'e') {
                                            if (inst[9] == 'i') {
                                                if (inst[10] == '8') {
                                                    if (inst[11] == '.') {
                                                        if (inst[12] == 'v') return 761;
                                                    }
                                                }
                                            }
                                        }
                                    }
                                    if (inst[7] == '6') {
                                        if (inst[8] == 'e') {
                                            if (inst[9] == 'i') {
                                                if (inst[10] == '8') {
                                                    if (inst[11] == '.') {
                                                        if (inst[12] == 'v') return 825;
                                                    }
                                                }
                                            }
                                        }
                                    }
                                    if (inst[7] == '4') {
                                        if (inst[8] == 'e') {
                                            if (inst[9] == 'i') {
                                                if (inst[10] == '8') {
                                                    if (inst[11] == '.') {
                                                        if (inst[12] == 'v') return 793;
                                                    }
                                                }
                                            }
                                        }
                                    }
                                    if (inst[7] == '8') {
                                        if (inst[8] == 'e') {
                                            if (inst[9] == 'i') {
                                                if (inst[10] == '8') {
                                                    if (inst[11] == '.') {
                                                        if (inst[12] == 'v') return 857;
                                                    }
                                                }
                                            }
                                        }
                                    }
                                    if (inst[7] == '5') {
                                        if (inst[8] == 'e') {
                                            if (inst[9] == 'i') {
                                                if (inst[10] == '8') {
                                                    if (inst[11] == '.') {
                                                        if (inst[12] == 'v') return 809;
                                                    }
                                                }
                                            }
                                        }
                                    }
                                    if (inst[7] == '7') {
                                        if (inst[8] == 'e') {
                                            if (inst[9] == 'i') {
                                                if (inst[10] == '8') {
                                                    if (inst[11] == '.') {
                                                        if (inst[12] == 'v') return 841;
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
            if (inst[1] == 'f') {
                if (inst[2] == 'w') {
                    if (inst[3] == 'r') {
                        if (inst[4] == 'e') {
                            if (inst[5] == 'd') {
                                if (inst[6] == 'u') {
                                    if (inst[7] == 's') {
                                        if (inst[8] == 'u') {
                                            if (inst[9] == 'm') {
                                                if (inst[10] == '.') {
                                                    if (inst[11] == 'v') {
                                                        if (inst[12] == 's') return 1169;
                                                    }
                                                }
                                            }
                                        }
                                    }
                                }
                                if (inst[6] == 'o') {
                                    if (inst[7] == 's') {
                                        if (inst[8] == 'u') {
                                            if (inst[9] == 'm') {
                                                if (inst[10] == '.') {
                                                    if (inst[11] == 'v') {
                                                        if (inst[12] == 's') return 1168;
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
                        if (inst[4] == 'v') {
                            if (inst[5] == 't') {
                                if (inst[6] == '.') {
                                    if (inst[7] == 'x') {
                                        if (inst[8] == 'u') {
                                            if (inst[9] == '.') {
                                                if (inst[10] == 'f') {
                                                    if (inst[11] == '.') {
                                                        if (inst[12] == 'v') return 1139;
                                                    }
                                                }
                                            }
                                        }
                                    }
                                    if (inst[7] == 'f') {
                                        if (inst[8] == '.') {
                                            if (inst[9] == 'x') {
                                                if (inst[10] == 'u') {
                                                    if (inst[11] == '.') {
                                                        if (inst[12] == 'v') return 1143;
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
                    if (inst[3] == 'l') {
                        if (inst[4] == 'i') {
                            if (inst[5] == 'd') {
                                if (inst[6] == 'e') {
                                    if (inst[7] == '1') {
                                        if (inst[8] == 'u') {
                                            if (inst[9] == 'p') {
                                                if (inst[10] == '.') {
                                                    if (inst[11] == 'v') {
                                                        if (inst[12] == 'f') return 1194;
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
                if (inst[2] == 'n') {
                    if (inst[3] == 'c') {
                        if (inst[4] == 'v') {
                            if (inst[5] == 't') {
                                if (inst[6] == '.') {
                                    if (inst[7] == 'x') {
                                        if (inst[8] == 'u') {
                                            if (inst[9] == '.') {
                                                if (inst[10] == 'f') {
                                                    if (inst[11] == '.') {
                                                        if (inst[12] == 'w') return 1146;
                                                    }
                                                }
                                            }
                                        }
                                    }
                                    if (inst[7] == 'f') {
                                        if (inst[8] == '.') {
                                            if (inst[9] == 'x') {
                                                if (inst[10] == 'u') {
                                                    if (inst[11] == '.') {
                                                        if (inst[12] == 'w') return 1150;
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

    if (size == 14) {
        if (inst[0] == 'a') {
            if (inst[1] == 'm') {
                if (inst[2] == 'o') {
                    if (inst[3] == 's') {
                        if (inst[4] == 'w') {
                            if (inst[5] == 'a') {
                                if (inst[6] == 'p') {
                                    if (inst[7] == '.') {
                                        if (inst[8] == 'd') {
                                            if (inst[9] == '.') {
                                                if (inst[10] == 'a') {
                                                    if (inst[11] == 'q') {
                                                        if (inst[12] == 'r') {
                                                            if (inst[13] == 'l') return 146;
                                                        }
                                                    }
                                                }
                                            }
                                        }
                                        if (inst[8] == 'w') {
                                            if (inst[9] == '.') {
                                                if (inst[10] == 'a') {
                                                    if (inst[11] == 'q') {
                                                        if (inst[12] == 'r') {
                                                            if (inst[13] == 'l') return 102;
                                                        }
                                                    }
                                                }
                                            }
                                        }
                                        if (inst[8] == 'b') {
                                            if (inst[9] == '.') {
                                                if (inst[10] == 'a') {
                                                    if (inst[11] == 'q') {
                                                        if (inst[12] == 'r') {
                                                            if (inst[13] == 'l') return 416;
                                                        }
                                                    }
                                                }
                                            }
                                        }
                                        if (inst[8] == 'h') {
                                            if (inst[9] == '.') {
                                                if (inst[10] == 'a') {
                                                    if (inst[11] == 'q') {
                                                        if (inst[12] == 'r') {
                                                            if (inst[13] == 'l') return 417;
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
                    if (inst[3] == 'm') {
                        if (inst[4] == 'a') {
                            if (inst[5] == 'x') {
                                if (inst[6] == 'u') {
                                    if (inst[7] == '.') {
                                        if (inst[8] == 'd') {
                                            if (inst[9] == '.') {
                                                if (inst[10] == 'a') {
                                                    if (inst[11] == 'q') {
                                                        if (inst[12] == 'r') {
                                                            if (inst[13] == 'l') return 154;
                                                        }
                                                    }
                                                }
                                            }
                                        }
                                        if (inst[8] == 'w') {
                                            if (inst[9] == '.') {
                                                if (inst[10] == 'a') {
                                                    if (inst[11] == 'q') {
                                                        if (inst[12] == 'r') {
                                                            if (inst[13] == 'l') return 110;
                                                        }
                                                    }
                                                }
                                            }
                                        }
                                        if (inst[8] == 'b') {
                                            if (inst[9] == '.') {
                                                if (inst[10] == 'a') {
                                                    if (inst[11] == 'q') {
                                                        if (inst[12] == 'r') {
                                                            if (inst[13] == 'l') return 428;
                                                        }
                                                    }
                                                }
                                            }
                                        }
                                        if (inst[8] == 'h') {
                                            if (inst[9] == '.') {
                                                if (inst[10] == 'a') {
                                                    if (inst[11] == 'q') {
                                                        if (inst[12] == 'r') {
                                                            if (inst[13] == 'l') return 429;
                                                        }
                                                    }
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                        if (inst[4] == 'i') {
                            if (inst[5] == 'n') {
                                if (inst[6] == 'u') {
                                    if (inst[7] == '.') {
                                        if (inst[8] == 'd') {
                                            if (inst[9] == '.') {
                                                if (inst[10] == 'a') {
                                                    if (inst[11] == 'q') {
                                                        if (inst[12] == 'r') {
                                                            if (inst[13] == 'l') return 153;
                                                        }
                                                    }
                                                }
                                            }
                                        }
                                        if (inst[8] == 'w') {
                                            if (inst[9] == '.') {
                                                if (inst[10] == 'a') {
                                                    if (inst[11] == 'q') {
                                                        if (inst[12] == 'r') {
                                                            if (inst[13] == 'l') return 109;
                                                        }
                                                    }
                                                }
                                            }
                                        }
                                        if (inst[8] == 'b') {
                                            if (inst[9] == '.') {
                                                if (inst[10] == 'a') {
                                                    if (inst[11] == 'q') {
                                                        if (inst[12] == 'r') {
                                                            if (inst[13] == 'l') return 432;
                                                        }
                                                    }
                                                }
                                            }
                                        }
                                        if (inst[8] == 'h') {
                                            if (inst[9] == '.') {
                                                if (inst[10] == 'a') {
                                                    if (inst[11] == 'q') {
                                                        if (inst[12] == 'r') {
                                                            if (inst[13] == 'l') return 433;
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
        if (inst[0] == 't') {
            if (inst[1] == 'h') {
                if (inst[2] == '.') {
                    if (inst[3] == 'd') {
                        if (inst[4] == 'c') {
                            if (inst[5] == 'a') {
                                if (inst[6] == 'c') {
                                    if (inst[7] == 'h') {
                                        if (inst[8] == 'e') {
                                            if (inst[9] == '.') {
                                                if (inst[10] == 'i') {
                                                    if (inst[11] == 'a') {
                                                        if (inst[12] == 'l') {
                                                            if (inst[13] == 'l') return 1286;
                                                        }
                                                    }
                                                }
                                                if (inst[10] == 'c') {
                                                    if (inst[11] == 'a') {
                                                        if (inst[12] == 'l') {
                                                            if (inst[13] == 'l') return 1284;
                                                        }
                                                    }
                                                    if (inst[11] == 'i') {
                                                        if (inst[12] == 's') {
                                                            if (inst[13] == 'w') return 1294;
                                                        }
                                                        if (inst[12] == 'p') {
                                                            if (inst[13] == 'a') return 1288;
                                                        }
                                                        if (inst[12] == 'v') {
                                                            if (inst[13] == 'a') return 1291;
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
                    if (inst[3] == 'i') {
                        if (inst[4] == 'c') {
                            if (inst[5] == 'a') {
                                if (inst[6] == 'c') {
                                    if (inst[7] == 'h') {
                                        if (inst[8] == 'e') {
                                            if (inst[9] == '.') {
                                                if (inst[10] == 'i') {
                                                    if (inst[11] == 'a') {
                                                        if (inst[12] == 'l') {
                                                            if (inst[13] == 'l') return 1298;
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
                    if (inst[3] == 's') {
                        if (inst[4] == 'f') {
                            if (inst[5] == 'e') {
                                if (inst[6] == 'n') {
                                    if (inst[7] == 'c') {
                                        if (inst[8] == 'e') {
                                            if (inst[9] == '.') {
                                                if (inst[10] == 'v') {
                                                    if (inst[11] == 'm') {
                                                        if (inst[12] == 'a') {
                                                            if (inst[13] == 's') return 1305;
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
                    if (inst[3] == 'v') {
                        if (inst[4] == 'a') {
                            if (inst[5] == 'm') {
                                if (inst[6] == 'o') {
                                    if (inst[7] == 's') {
                                        if (inst[8] == 'w') {
                                            if (inst[9] == 'a') {
                                                if (inst[10] == 'p') {
                                                    if (inst[11] == 'd') {
                                                        if (inst[12] == '.') {
                                                            if (inst[13] == 'v') return 1724;
                                                        }
                                                    }
                                                    if (inst[11] == 'w') {
                                                        if (inst[12] == '.') {
                                                            if (inst[13] == 'v') return 1723;
                                                        }
                                                    }
                                                }
                                            }
                                        }
                                    }
                                    if (inst[7] == 'm') {
                                        if (inst[8] == 'a') {
                                            if (inst[9] == 'x') {
                                                if (inst[10] == 'u') {
                                                    if (inst[11] == 'd') {
                                                        if (inst[12] == '.') {
                                                            if (inst[13] == 'v') return 1740;
                                                        }
                                                    }
                                                    if (inst[11] == 'w') {
                                                        if (inst[12] == '.') {
                                                            if (inst[13] == 'v') return 1739;
                                                        }
                                                    }
                                                }
                                            }
                                        }
                                        if (inst[8] == 'i') {
                                            if (inst[9] == 'n') {
                                                if (inst[10] == 'u') {
                                                    if (inst[11] == 'd') {
                                                        if (inst[12] == '.') {
                                                            if (inst[13] == 'v') return 1738;
                                                        }
                                                    }
                                                    if (inst[11] == 'w') {
                                                        if (inst[12] == '.') {
                                                            if (inst[13] == 'v') return 1737;
                                                        }
                                                    }
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                        if (inst[4] == 'w') {
                            if (inst[5] == 's') {
                                if (inst[6] == 'm') {
                                    if (inst[7] == 'a') {
                                        if (inst[8] == 'c') {
                                            if (inst[9] == 'c') {
                                                if (inst[10] == 'u') {
                                                    if (inst[11] == '.') {
                                                        if (inst[12] == 'v') {
                                                            if (inst[13] == 'x') return 1887;
                                                            if (inst[13] == 'v') return 1886;
                                                        }
                                                    }
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                            if (inst[5] == 'm') {
                                if (inst[6] == 'a') {
                                    if (inst[7] == 'c') {
                                        if (inst[8] == 'c') {
                                            if (inst[9] == 'u') {
                                                if (inst[10] == 's') {
                                                    if (inst[11] == '.') {
                                                        if (inst[12] == 'v') {
                                                            if (inst[13] == 'x') return 1862;
                                                        }
                                                    }
                                                }
                                            }
                                            if (inst[9] == 's') {
                                                if (inst[10] == 'u') {
                                                    if (inst[11] == '.') {
                                                        if (inst[12] == 'v') {
                                                            if (inst[13] == 'x') return 1861;
                                                            if (inst[13] == 'v') return 1860;
                                                        }
                                                    }
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                            if (inst[5] == 'r') {
                                if (inst[6] == 'e') {
                                    if (inst[7] == 'd') {
                                        if (inst[8] == 's') {
                                            if (inst[9] == 'u') {
                                                if (inst[10] == 'm') {
                                                    if (inst[11] == '.') {
                                                        if (inst[12] == 'v') {
                                                            if (inst[13] == 's') return 1998;
                                                        }
                                                    }
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                        if (inst[4] == 's') {
                            if (inst[5] == 'l') {
                                if (inst[6] == 'i') {
                                    if (inst[7] == 'd') {
                                        if (inst[8] == 'e') {
                                            if (inst[9] == 'u') {
                                                if (inst[10] == 'p') {
                                                    if (inst[11] == '.') {
                                                        if (inst[12] == 'v') {
                                                            if (inst[13] == 'i') return 2025;
                                                            if (inst[13] == 'x') return 2024;
                                                        }
                                                    }
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                        if (inst[4] == 'm') {
                            if (inst[5] == 'a') {
                                if (inst[6] == 'n') {
                                    if (inst[7] == 'd') {
                                        if (inst[8] == 'n') {
                                            if (inst[9] == 'o') {
                                                if (inst[10] == 't') {
                                                    if (inst[11] == '.') {
                                                        if (inst[12] == 'm') {
                                                            if (inst[13] == 'm') return 2007;
                                                        }
                                                    }
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                        if (inst[4] == 'r') {
                            if (inst[5] == 'e') {
                                if (inst[6] == 'd') {
                                    if (inst[7] == 'm') {
                                        if (inst[8] == 'a') {
                                            if (inst[9] == 'x') {
                                                if (inst[10] == 'u') {
                                                    if (inst[11] == '.') {
                                                        if (inst[12] == 'v') {
                                                            if (inst[13] == 's') return 1990;
                                                        }
                                                    }
                                                }
                                            }
                                        }
                                        if (inst[8] == 'i') {
                                            if (inst[9] == 'n') {
                                                if (inst[10] == 'u') {
                                                    if (inst[11] == '.') {
                                                        if (inst[12] == 'v') {
                                                            if (inst[13] == 's') return 1992;
                                                        }
                                                    }
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                            if (inst[5] == 'g') {
                                if (inst[6] == 'a') {
                                    if (inst[7] == 't') {
                                        if (inst[8] == 'h') {
                                            if (inst[9] == 'e') {
                                                if (inst[10] == 'r') {
                                                    if (inst[11] == '.') {
                                                        if (inst[12] == 'v') {
                                                            if (inst[13] == 'i') return 2032;
                                                            if (inst[13] == 'x') return 2031;
                                                            if (inst[13] == 'v') return 2030;
                                                        }
                                                    }
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                        if (inst[4] == 'l') {
                            if (inst[5] == 's') {
                                if (inst[6] == 'e') {
                                    if (inst[7] == 'g') {
                                        if (inst[8] == '3') {
                                            if (inst[9] == 'w') {
                                                if (inst[10] == 'f') {
                                                    if (inst[11] == 'f') {
                                                        if (inst[12] == '.') {
                                                            if (inst[13] == 'v') return 1525;
                                                        }
                                                    }
                                                }
                                            }
                                            if (inst[9] == 'e') {
                                                if (inst[10] == 'f') {
                                                    if (inst[11] == 'f') {
                                                        if (inst[12] == '.') {
                                                            if (inst[13] == 'v') return 1542;
                                                        }
                                                    }
                                                }
                                            }
                                            if (inst[9] == 'b') {
                                                if (inst[10] == 'f') {
                                                    if (inst[11] == 'f') {
                                                        if (inst[12] == '.') {
                                                            if (inst[13] == 'v') return 1523;
                                                        }
                                                    }
                                                }
                                            }
                                            if (inst[9] == 'h') {
                                                if (inst[10] == 'f') {
                                                    if (inst[11] == 'f') {
                                                        if (inst[12] == '.') {
                                                            if (inst[13] == 'v') return 1524;
                                                        }
                                                    }
                                                }
                                            }
                                        }
                                        if (inst[8] == '2') {
                                            if (inst[9] == 'w') {
                                                if (inst[10] == 'f') {
                                                    if (inst[11] == 'f') {
                                                        if (inst[12] == '.') {
                                                            if (inst[13] == 'v') return 1522;
                                                        }
                                                    }
                                                }
                                            }
                                            if (inst[9] == 'e') {
                                                if (inst[10] == 'f') {
                                                    if (inst[11] == 'f') {
                                                        if (inst[12] == '.') {
                                                            if (inst[13] == 'v') return 1541;
                                                        }
                                                    }
                                                }
                                            }
                                            if (inst[9] == 'b') {
                                                if (inst[10] == 'f') {
                                                    if (inst[11] == 'f') {
                                                        if (inst[12] == '.') {
                                                            if (inst[13] == 'v') return 1520;
                                                        }
                                                    }
                                                }
                                            }
                                            if (inst[9] == 'h') {
                                                if (inst[10] == 'f') {
                                                    if (inst[11] == 'f') {
                                                        if (inst[12] == '.') {
                                                            if (inst[13] == 'v') return 1521;
                                                        }
                                                    }
                                                }
                                            }
                                        }
                                        if (inst[8] == '6') {
                                            if (inst[9] == 'w') {
                                                if (inst[10] == 'f') {
                                                    if (inst[11] == 'f') {
                                                        if (inst[12] == '.') {
                                                            if (inst[13] == 'v') return 1534;
                                                        }
                                                    }
                                                }
                                            }
                                            if (inst[9] == 'e') {
                                                if (inst[10] == 'f') {
                                                    if (inst[11] == 'f') {
                                                        if (inst[12] == '.') {
                                                            if (inst[13] == 'v') return 1545;
                                                        }
                                                    }
                                                }
                                            }
                                            if (inst[9] == 'b') {
                                                if (inst[10] == 'f') {
                                                    if (inst[11] == 'f') {
                                                        if (inst[12] == '.') {
                                                            if (inst[13] == 'v') return 1532;
                                                        }
                                                    }
                                                }
                                            }
                                            if (inst[9] == 'h') {
                                                if (inst[10] == 'f') {
                                                    if (inst[11] == 'f') {
                                                        if (inst[12] == '.') {
                                                            if (inst[13] == 'v') return 1533;
                                                        }
                                                    }
                                                }
                                            }
                                        }
                                        if (inst[8] == '4') {
                                            if (inst[9] == 'w') {
                                                if (inst[10] == 'f') {
                                                    if (inst[11] == 'f') {
                                                        if (inst[12] == '.') {
                                                            if (inst[13] == 'v') return 1528;
                                                        }
                                                    }
                                                }
                                            }
                                            if (inst[9] == 'e') {
                                                if (inst[10] == 'f') {
                                                    if (inst[11] == 'f') {
                                                        if (inst[12] == '.') {
                                                            if (inst[13] == 'v') return 1543;
                                                        }
                                                    }
                                                }
                                            }
                                            if (inst[9] == 'b') {
                                                if (inst[10] == 'f') {
                                                    if (inst[11] == 'f') {
                                                        if (inst[12] == '.') {
                                                            if (inst[13] == 'v') return 1526;
                                                        }
                                                    }
                                                }
                                            }
                                            if (inst[9] == 'h') {
                                                if (inst[10] == 'f') {
                                                    if (inst[11] == 'f') {
                                                        if (inst[12] == '.') {
                                                            if (inst[13] == 'v') return 1527;
                                                        }
                                                    }
                                                }
                                            }
                                        }
                                        if (inst[8] == '8') {
                                            if (inst[9] == 'w') {
                                                if (inst[10] == 'f') {
                                                    if (inst[11] == 'f') {
                                                        if (inst[12] == '.') {
                                                            if (inst[13] == 'v') return 1540;
                                                        }
                                                    }
                                                }
                                            }
                                            if (inst[9] == 'e') {
                                                if (inst[10] == 'f') {
                                                    if (inst[11] == 'f') {
                                                        if (inst[12] == '.') {
                                                            if (inst[13] == 'v') return 1547;
                                                        }
                                                    }
                                                }
                                            }
                                            if (inst[9] == 'b') {
                                                if (inst[10] == 'f') {
                                                    if (inst[11] == 'f') {
                                                        if (inst[12] == '.') {
                                                            if (inst[13] == 'v') return 1538;
                                                        }
                                                    }
                                                }
                                            }
                                            if (inst[9] == 'h') {
                                                if (inst[10] == 'f') {
                                                    if (inst[11] == 'f') {
                                                        if (inst[12] == '.') {
                                                            if (inst[13] == 'v') return 1539;
                                                        }
                                                    }
                                                }
                                            }
                                        }
                                        if (inst[8] == '5') {
                                            if (inst[9] == 'w') {
                                                if (inst[10] == 'f') {
                                                    if (inst[11] == 'f') {
                                                        if (inst[12] == '.') {
                                                            if (inst[13] == 'v') return 1531;
                                                        }
                                                    }
                                                }
                                            }
                                            if (inst[9] == 'e') {
                                                if (inst[10] == 'f') {
                                                    if (inst[11] == 'f') {
                                                        if (inst[12] == '.') {
                                                            if (inst[13] == 'v') return 1544;
                                                        }
                                                    }
                                                }
                                            }
                                            if (inst[9] == 'b') {
                                                if (inst[10] == 'f') {
                                                    if (inst[11] == 'f') {
                                                        if (inst[12] == '.') {
                                                            if (inst[13] == 'v') return 1529;
                                                        }
                                                    }
                                                }
                                            }
                                            if (inst[9] == 'h') {
                                                if (inst[10] == 'f') {
                                                    if (inst[11] == 'f') {
                                                        if (inst[12] == '.') {
                                                            if (inst[13] == 'v') return 1530;
                                                        }
                                                    }
                                                }
                                            }
                                        }
                                        if (inst[8] == '7') {
                                            if (inst[9] == 'w') {
                                                if (inst[10] == 'f') {
                                                    if (inst[11] == 'f') {
                                                        if (inst[12] == '.') {
                                                            if (inst[13] == 'v') return 1537;
                                                        }
                                                    }
                                                }
                                            }
                                            if (inst[9] == 'e') {
                                                if (inst[10] == 'f') {
                                                    if (inst[11] == 'f') {
                                                        if (inst[12] == '.') {
                                                            if (inst[13] == 'v') return 1546;
                                                        }
                                                    }
                                                }
                                            }
                                            if (inst[9] == 'b') {
                                                if (inst[10] == 'f') {
                                                    if (inst[11] == 'f') {
                                                        if (inst[12] == '.') {
                                                            if (inst[13] == 'v') return 1535;
                                                        }
                                                    }
                                                }
                                            }
                                            if (inst[9] == 'h') {
                                                if (inst[10] == 'f') {
                                                    if (inst[11] == 'f') {
                                                        if (inst[12] == '.') {
                                                            if (inst[13] == 'v') return 1536;
                                                        }
                                                    }
                                                }
                                            }
                                        }
                                    }
                                }
                                if (inst[6] == 's') {
                                    if (inst[7] == 'e') {
                                        if (inst[8] == 'g') {
                                            if (inst[9] == '3') {
                                                if (inst[10] == 'w') {
                                                    if (inst[11] == 'u') {
                                                        if (inst[12] == '.') {
                                                            if (inst[13] == 'v') return 1602;
                                                        }
                                                    }
                                                }
                                                if (inst[10] == 'b') {
                                                    if (inst[11] == 'u') {
                                                        if (inst[12] == '.') {
                                                            if (inst[13] == 'v') return 1600;
                                                        }
                                                    }
                                                }
                                                if (inst[10] == 'h') {
                                                    if (inst[11] == 'u') {
                                                        if (inst[12] == '.') {
                                                            if (inst[13] == 'v') return 1601;
                                                        }
                                                    }
                                                }
                                            }
                                            if (inst[9] == '2') {
                                                if (inst[10] == 'w') {
                                                    if (inst[11] == 'u') {
                                                        if (inst[12] == '.') {
                                                            if (inst[13] == 'v') return 1599;
                                                        }
                                                    }
                                                }
                                                if (inst[10] == 'b') {
                                                    if (inst[11] == 'u') {
                                                        if (inst[12] == '.') {
                                                            if (inst[13] == 'v') return 1597;
                                                        }
                                                    }
                                                }
                                                if (inst[10] == 'h') {
                                                    if (inst[11] == 'u') {
                                                        if (inst[12] == '.') {
                                                            if (inst[13] == 'v') return 1598;
                                                        }
                                                    }
                                                }
                                            }
                                            if (inst[9] == '6') {
                                                if (inst[10] == 'w') {
                                                    if (inst[11] == 'u') {
                                                        if (inst[12] == '.') {
                                                            if (inst[13] == 'v') return 1611;
                                                        }
                                                    }
                                                }
                                                if (inst[10] == 'b') {
                                                    if (inst[11] == 'u') {
                                                        if (inst[12] == '.') {
                                                            if (inst[13] == 'v') return 1609;
                                                        }
                                                    }
                                                }
                                                if (inst[10] == 'h') {
                                                    if (inst[11] == 'u') {
                                                        if (inst[12] == '.') {
                                                            if (inst[13] == 'v') return 1610;
                                                        }
                                                    }
                                                }
                                            }
                                            if (inst[9] == '4') {
                                                if (inst[10] == 'w') {
                                                    if (inst[11] == 'u') {
                                                        if (inst[12] == '.') {
                                                            if (inst[13] == 'v') return 1605;
                                                        }
                                                    }
                                                }
                                                if (inst[10] == 'b') {
                                                    if (inst[11] == 'u') {
                                                        if (inst[12] == '.') {
                                                            if (inst[13] == 'v') return 1603;
                                                        }
                                                    }
                                                }
                                                if (inst[10] == 'h') {
                                                    if (inst[11] == 'u') {
                                                        if (inst[12] == '.') {
                                                            if (inst[13] == 'v') return 1604;
                                                        }
                                                    }
                                                }
                                            }
                                            if (inst[9] == '8') {
                                                if (inst[10] == 'w') {
                                                    if (inst[11] == 'u') {
                                                        if (inst[12] == '.') {
                                                            if (inst[13] == 'v') return 1617;
                                                        }
                                                    }
                                                }
                                                if (inst[10] == 'b') {
                                                    if (inst[11] == 'u') {
                                                        if (inst[12] == '.') {
                                                            if (inst[13] == 'v') return 1615;
                                                        }
                                                    }
                                                }
                                                if (inst[10] == 'h') {
                                                    if (inst[11] == 'u') {
                                                        if (inst[12] == '.') {
                                                            if (inst[13] == 'v') return 1616;
                                                        }
                                                    }
                                                }
                                            }
                                            if (inst[9] == '5') {
                                                if (inst[10] == 'w') {
                                                    if (inst[11] == 'u') {
                                                        if (inst[12] == '.') {
                                                            if (inst[13] == 'v') return 1608;
                                                        }
                                                    }
                                                }
                                                if (inst[10] == 'b') {
                                                    if (inst[11] == 'u') {
                                                        if (inst[12] == '.') {
                                                            if (inst[13] == 'v') return 1606;
                                                        }
                                                    }
                                                }
                                                if (inst[10] == 'h') {
                                                    if (inst[11] == 'u') {
                                                        if (inst[12] == '.') {
                                                            if (inst[13] == 'v') return 1607;
                                                        }
                                                    }
                                                }
                                            }
                                            if (inst[9] == '7') {
                                                if (inst[10] == 'w') {
                                                    if (inst[11] == 'u') {
                                                        if (inst[12] == '.') {
                                                            if (inst[13] == 'v') return 1614;
                                                        }
                                                    }
                                                }
                                                if (inst[10] == 'b') {
                                                    if (inst[11] == 'u') {
                                                        if (inst[12] == '.') {
                                                            if (inst[13] == 'v') return 1612;
                                                        }
                                                    }
                                                }
                                                if (inst[10] == 'h') {
                                                    if (inst[11] == 'u') {
                                                        if (inst[12] == '.') {
                                                            if (inst[13] == 'v') return 1613;
                                                        }
                                                    }
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                            if (inst[5] == 'x') {
                                if (inst[6] == 's') {
                                    if (inst[7] == 'e') {
                                        if (inst[8] == 'g') {
                                            if (inst[9] == '3') {
                                                if (inst[10] == 'w') {
                                                    if (inst[11] == 'u') {
                                                        if (inst[12] == '.') {
                                                            if (inst[13] == 'v') return 1679;
                                                        }
                                                    }
                                                }
                                                if (inst[10] == 'b') {
                                                    if (inst[11] == 'u') {
                                                        if (inst[12] == '.') {
                                                            if (inst[13] == 'v') return 1677;
                                                        }
                                                    }
                                                }
                                                if (inst[10] == 'h') {
                                                    if (inst[11] == 'u') {
                                                        if (inst[12] == '.') {
                                                            if (inst[13] == 'v') return 1678;
                                                        }
                                                    }
                                                }
                                            }
                                            if (inst[9] == '2') {
                                                if (inst[10] == 'w') {
                                                    if (inst[11] == 'u') {
                                                        if (inst[12] == '.') {
                                                            if (inst[13] == 'v') return 1676;
                                                        }
                                                    }
                                                }
                                                if (inst[10] == 'b') {
                                                    if (inst[11] == 'u') {
                                                        if (inst[12] == '.') {
                                                            if (inst[13] == 'v') return 1674;
                                                        }
                                                    }
                                                }
                                                if (inst[10] == 'h') {
                                                    if (inst[11] == 'u') {
                                                        if (inst[12] == '.') {
                                                            if (inst[13] == 'v') return 1675;
                                                        }
                                                    }
                                                }
                                            }
                                            if (inst[9] == '6') {
                                                if (inst[10] == 'w') {
                                                    if (inst[11] == 'u') {
                                                        if (inst[12] == '.') {
                                                            if (inst[13] == 'v') return 1688;
                                                        }
                                                    }
                                                }
                                                if (inst[10] == 'b') {
                                                    if (inst[11] == 'u') {
                                                        if (inst[12] == '.') {
                                                            if (inst[13] == 'v') return 1686;
                                                        }
                                                    }
                                                }
                                                if (inst[10] == 'h') {
                                                    if (inst[11] == 'u') {
                                                        if (inst[12] == '.') {
                                                            if (inst[13] == 'v') return 1687;
                                                        }
                                                    }
                                                }
                                            }
                                            if (inst[9] == '4') {
                                                if (inst[10] == 'w') {
                                                    if (inst[11] == 'u') {
                                                        if (inst[12] == '.') {
                                                            if (inst[13] == 'v') return 1682;
                                                        }
                                                    }
                                                }
                                                if (inst[10] == 'b') {
                                                    if (inst[11] == 'u') {
                                                        if (inst[12] == '.') {
                                                            if (inst[13] == 'v') return 1680;
                                                        }
                                                    }
                                                }
                                                if (inst[10] == 'h') {
                                                    if (inst[11] == 'u') {
                                                        if (inst[12] == '.') {
                                                            if (inst[13] == 'v') return 1681;
                                                        }
                                                    }
                                                }
                                            }
                                            if (inst[9] == '8') {
                                                if (inst[10] == 'w') {
                                                    if (inst[11] == 'u') {
                                                        if (inst[12] == '.') {
                                                            if (inst[13] == 'v') return 1694;
                                                        }
                                                    }
                                                }
                                                if (inst[10] == 'b') {
                                                    if (inst[11] == 'u') {
                                                        if (inst[12] == '.') {
                                                            if (inst[13] == 'v') return 1692;
                                                        }
                                                    }
                                                }
                                                if (inst[10] == 'h') {
                                                    if (inst[11] == 'u') {
                                                        if (inst[12] == '.') {
                                                            if (inst[13] == 'v') return 1693;
                                                        }
                                                    }
                                                }
                                            }
                                            if (inst[9] == '5') {
                                                if (inst[10] == 'w') {
                                                    if (inst[11] == 'u') {
                                                        if (inst[12] == '.') {
                                                            if (inst[13] == 'v') return 1685;
                                                        }
                                                    }
                                                }
                                                if (inst[10] == 'b') {
                                                    if (inst[11] == 'u') {
                                                        if (inst[12] == '.') {
                                                            if (inst[13] == 'v') return 1683;
                                                        }
                                                    }
                                                }
                                                if (inst[10] == 'h') {
                                                    if (inst[11] == 'u') {
                                                        if (inst[12] == '.') {
                                                            if (inst[13] == 'v') return 1684;
                                                        }
                                                    }
                                                }
                                            }
                                            if (inst[9] == '7') {
                                                if (inst[10] == 'w') {
                                                    if (inst[11] == 'u') {
                                                        if (inst[12] == '.') {
                                                            if (inst[13] == 'v') return 1691;
                                                        }
                                                    }
                                                }
                                                if (inst[10] == 'b') {
                                                    if (inst[11] == 'u') {
                                                        if (inst[12] == '.') {
                                                            if (inst[13] == 'v') return 1689;
                                                        }
                                                    }
                                                }
                                                if (inst[10] == 'h') {
                                                    if (inst[11] == 'u') {
                                                        if (inst[12] == '.') {
                                                            if (inst[13] == 'v') return 1690;
                                                        }
                                                    }
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                        if (inst[4] == 'f') {
                            if (inst[5] == 'w') {
                                if (inst[6] == 'n') {
                                    if (inst[7] == 'm') {
                                        if (inst[8] == 'a') {
                                            if (inst[9] == 'c') {
                                                if (inst[10] == 'c') {
                                                    if (inst[11] == '.') {
                                                        if (inst[12] == 'v') {
                                                            if (inst[13] == 'v') return 1943;
                                                            if (inst[13] == 'f') return 1944;
                                                        }
                                                    }
                                                }
                                            }
                                        }
                                        if (inst[8] == 's') {
                                            if (inst[9] == 'a') {
                                                if (inst[10] == 'c') {
                                                    if (inst[11] == '.') {
                                                        if (inst[12] == 'v') {
                                                            if (inst[13] == 'v') return 1947;
                                                            if (inst[13] == 'f') return 1948;
                                                        }
                                                    }
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                            if (inst[5] == 'm') {
                                if (inst[6] == 'e') {
                                    if (inst[7] == 'r') {
                                        if (inst[8] == 'g') {
                                            if (inst[9] == 'e') {
                                                if (inst[10] == '.') {
                                                    if (inst[11] == 'v') {
                                                        if (inst[12] == 'f') {
                                                            if (inst[13] == 'm') return 1973;
                                                        }
                                                    }
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                            if (inst[5] == 'r') {
                                if (inst[6] == 'e') {
                                    if (inst[7] == 'd') {
                                        if (inst[8] == 's') {
                                            if (inst[9] == 'u') {
                                                if (inst[10] == 'm') {
                                                    if (inst[11] == '.') {
                                                        if (inst[12] == 'v') {
                                                            if (inst[13] == 's') return 2000;
                                                        }
                                                    }
                                                }
                                            }
                                        }
                                        if (inst[8] == 'm') {
                                            if (inst[9] == 'a') {
                                                if (inst[10] == 'x') {
                                                    if (inst[11] == '.') {
                                                        if (inst[12] == 'v') {
                                                            if (inst[13] == 's') return 2001;
                                                        }
                                                    }
                                                }
                                            }
                                            if (inst[9] == 'i') {
                                                if (inst[10] == 'n') {
                                                    if (inst[11] == '.') {
                                                        if (inst[12] == 'v') {
                                                            if (inst[13] == 's') return 2002;
                                                        }
                                                    }
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                            if (inst[5] == 'c') {
                                if (inst[6] == 'v') {
                                    if (inst[7] == 't') {
                                        if (inst[8] == '.') {
                                            if (inst[9] == 'x') {
                                                if (inst[10] == '.') {
                                                    if (inst[11] == 'f') {
                                                        if (inst[12] == '.') {
                                                            if (inst[13] == 'v') return 1976;
                                                        }
                                                    }
                                                }
                                            }
                                            if (inst[9] == 'f') {
                                                if (inst[10] == '.') {
                                                    if (inst[11] == 'x') {
                                                        if (inst[12] == '.') {
                                                            if (inst[13] == 'v') return 1978;
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
        if (inst[0] == 'v') {
            if (inst[1] == 's') {
                if (inst[2] == 'u') {
                    if (inst[3] == 'x') {
                        if (inst[4] == 's') {
                            if (inst[5] == 'e') {
                                if (inst[6] == 'g') {
                                    if (inst[7] == '3') {
                                        if (inst[8] == 'e') {
                                            if (inst[9] == 'i') {
                                                if (inst[10] == '3') {
                                                    if (inst[11] == '2') {
                                                        if (inst[12] == '.') {
                                                            if (inst[13] == 'v') return 786;
                                                        }
                                                    }
                                                }
                                                if (inst[10] == '6') {
                                                    if (inst[11] == '4') {
                                                        if (inst[12] == '.') {
                                                            if (inst[13] == 'v') return 790;
                                                        }
                                                    }
                                                }
                                                if (inst[10] == '1') {
                                                    if (inst[11] == '6') {
                                                        if (inst[12] == '.') {
                                                            if (inst[13] == 'v') return 782;
                                                        }
                                                    }
                                                }
                                            }
                                        }
                                    }
                                    if (inst[7] == '2') {
                                        if (inst[8] == 'e') {
                                            if (inst[9] == 'i') {
                                                if (inst[10] == '3') {
                                                    if (inst[11] == '2') {
                                                        if (inst[12] == '.') {
                                                            if (inst[13] == 'v') return 770;
                                                        }
                                                    }
                                                }
                                                if (inst[10] == '6') {
                                                    if (inst[11] == '4') {
                                                        if (inst[12] == '.') {
                                                            if (inst[13] == 'v') return 774;
                                                        }
                                                    }
                                                }
                                                if (inst[10] == '1') {
                                                    if (inst[11] == '6') {
                                                        if (inst[12] == '.') {
                                                            if (inst[13] == 'v') return 766;
                                                        }
                                                    }
                                                }
                                            }
                                        }
                                    }
                                    if (inst[7] == '6') {
                                        if (inst[8] == 'e') {
                                            if (inst[9] == 'i') {
                                                if (inst[10] == '3') {
                                                    if (inst[11] == '2') {
                                                        if (inst[12] == '.') {
                                                            if (inst[13] == 'v') return 834;
                                                        }
                                                    }
                                                }
                                                if (inst[10] == '6') {
                                                    if (inst[11] == '4') {
                                                        if (inst[12] == '.') {
                                                            if (inst[13] == 'v') return 838;
                                                        }
                                                    }
                                                }
                                                if (inst[10] == '1') {
                                                    if (inst[11] == '6') {
                                                        if (inst[12] == '.') {
                                                            if (inst[13] == 'v') return 830;
                                                        }
                                                    }
                                                }
                                            }
                                        }
                                    }
                                    if (inst[7] == '4') {
                                        if (inst[8] == 'e') {
                                            if (inst[9] == 'i') {
                                                if (inst[10] == '3') {
                                                    if (inst[11] == '2') {
                                                        if (inst[12] == '.') {
                                                            if (inst[13] == 'v') return 802;
                                                        }
                                                    }
                                                }
                                                if (inst[10] == '6') {
                                                    if (inst[11] == '4') {
                                                        if (inst[12] == '.') {
                                                            if (inst[13] == 'v') return 806;
                                                        }
                                                    }
                                                }
                                                if (inst[10] == '1') {
                                                    if (inst[11] == '6') {
                                                        if (inst[12] == '.') {
                                                            if (inst[13] == 'v') return 798;
                                                        }
                                                    }
                                                }
                                            }
                                        }
                                    }
                                    if (inst[7] == '8') {
                                        if (inst[8] == 'e') {
                                            if (inst[9] == 'i') {
                                                if (inst[10] == '3') {
                                                    if (inst[11] == '2') {
                                                        if (inst[12] == '.') {
                                                            if (inst[13] == 'v') return 866;
                                                        }
                                                    }
                                                }
                                                if (inst[10] == '6') {
                                                    if (inst[11] == '4') {
                                                        if (inst[12] == '.') {
                                                            if (inst[13] == 'v') return 870;
                                                        }
                                                    }
                                                }
                                                if (inst[10] == '1') {
                                                    if (inst[11] == '6') {
                                                        if (inst[12] == '.') {
                                                            if (inst[13] == 'v') return 862;
                                                        }
                                                    }
                                                }
                                            }
                                        }
                                    }
                                    if (inst[7] == '5') {
                                        if (inst[8] == 'e') {
                                            if (inst[9] == 'i') {
                                                if (inst[10] == '3') {
                                                    if (inst[11] == '2') {
                                                        if (inst[12] == '.') {
                                                            if (inst[13] == 'v') return 818;
                                                        }
                                                    }
                                                }
                                                if (inst[10] == '6') {
                                                    if (inst[11] == '4') {
                                                        if (inst[12] == '.') {
                                                            if (inst[13] == 'v') return 822;
                                                        }
                                                    }
                                                }
                                                if (inst[10] == '1') {
                                                    if (inst[11] == '6') {
                                                        if (inst[12] == '.') {
                                                            if (inst[13] == 'v') return 814;
                                                        }
                                                    }
                                                }
                                            }
                                        }
                                    }
                                    if (inst[7] == '7') {
                                        if (inst[8] == 'e') {
                                            if (inst[9] == 'i') {
                                                if (inst[10] == '3') {
                                                    if (inst[11] == '2') {
                                                        if (inst[12] == '.') {
                                                            if (inst[13] == 'v') return 850;
                                                        }
                                                    }
                                                }
                                                if (inst[10] == '6') {
                                                    if (inst[11] == '4') {
                                                        if (inst[12] == '.') {
                                                            if (inst[13] == 'v') return 854;
                                                        }
                                                    }
                                                }
                                                if (inst[10] == '1') {
                                                    if (inst[11] == '6') {
                                                        if (inst[12] == '.') {
                                                            if (inst[13] == 'v') return 846;
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
                if (inst[2] == 'o') {
                    if (inst[3] == 'x') {
                        if (inst[4] == 's') {
                            if (inst[5] == 'e') {
                                if (inst[6] == 'g') {
                                    if (inst[7] == '3') {
                                        if (inst[8] == 'e') {
                                            if (inst[9] == 'i') {
                                                if (inst[10] == '3') {
                                                    if (inst[11] == '2') {
                                                        if (inst[12] == '.') {
                                                            if (inst[13] == 'v') return 787;
                                                        }
                                                    }
                                                }
                                                if (inst[10] == '6') {
                                                    if (inst[11] == '4') {
                                                        if (inst[12] == '.') {
                                                            if (inst[13] == 'v') return 791;
                                                        }
                                                    }
                                                }
                                                if (inst[10] == '1') {
                                                    if (inst[11] == '6') {
                                                        if (inst[12] == '.') {
                                                            if (inst[13] == 'v') return 783;
                                                        }
                                                    }
                                                }
                                            }
                                        }
                                    }
                                    if (inst[7] == '2') {
                                        if (inst[8] == 'e') {
                                            if (inst[9] == 'i') {
                                                if (inst[10] == '3') {
                                                    if (inst[11] == '2') {
                                                        if (inst[12] == '.') {
                                                            if (inst[13] == 'v') return 771;
                                                        }
                                                    }
                                                }
                                                if (inst[10] == '6') {
                                                    if (inst[11] == '4') {
                                                        if (inst[12] == '.') {
                                                            if (inst[13] == 'v') return 775;
                                                        }
                                                    }
                                                }
                                                if (inst[10] == '1') {
                                                    if (inst[11] == '6') {
                                                        if (inst[12] == '.') {
                                                            if (inst[13] == 'v') return 767;
                                                        }
                                                    }
                                                }
                                            }
                                        }
                                    }
                                    if (inst[7] == '6') {
                                        if (inst[8] == 'e') {
                                            if (inst[9] == 'i') {
                                                if (inst[10] == '3') {
                                                    if (inst[11] == '2') {
                                                        if (inst[12] == '.') {
                                                            if (inst[13] == 'v') return 835;
                                                        }
                                                    }
                                                }
                                                if (inst[10] == '6') {
                                                    if (inst[11] == '4') {
                                                        if (inst[12] == '.') {
                                                            if (inst[13] == 'v') return 839;
                                                        }
                                                    }
                                                }
                                                if (inst[10] == '1') {
                                                    if (inst[11] == '6') {
                                                        if (inst[12] == '.') {
                                                            if (inst[13] == 'v') return 831;
                                                        }
                                                    }
                                                }
                                            }
                                        }
                                    }
                                    if (inst[7] == '4') {
                                        if (inst[8] == 'e') {
                                            if (inst[9] == 'i') {
                                                if (inst[10] == '3') {
                                                    if (inst[11] == '2') {
                                                        if (inst[12] == '.') {
                                                            if (inst[13] == 'v') return 803;
                                                        }
                                                    }
                                                }
                                                if (inst[10] == '6') {
                                                    if (inst[11] == '4') {
                                                        if (inst[12] == '.') {
                                                            if (inst[13] == 'v') return 807;
                                                        }
                                                    }
                                                }
                                                if (inst[10] == '1') {
                                                    if (inst[11] == '6') {
                                                        if (inst[12] == '.') {
                                                            if (inst[13] == 'v') return 799;
                                                        }
                                                    }
                                                }
                                            }
                                        }
                                    }
                                    if (inst[7] == '8') {
                                        if (inst[8] == 'e') {
                                            if (inst[9] == 'i') {
                                                if (inst[10] == '3') {
                                                    if (inst[11] == '2') {
                                                        if (inst[12] == '.') {
                                                            if (inst[13] == 'v') return 867;
                                                        }
                                                    }
                                                }
                                                if (inst[10] == '6') {
                                                    if (inst[11] == '4') {
                                                        if (inst[12] == '.') {
                                                            if (inst[13] == 'v') return 871;
                                                        }
                                                    }
                                                }
                                                if (inst[10] == '1') {
                                                    if (inst[11] == '6') {
                                                        if (inst[12] == '.') {
                                                            if (inst[13] == 'v') return 863;
                                                        }
                                                    }
                                                }
                                            }
                                        }
                                    }
                                    if (inst[7] == '5') {
                                        if (inst[8] == 'e') {
                                            if (inst[9] == 'i') {
                                                if (inst[10] == '3') {
                                                    if (inst[11] == '2') {
                                                        if (inst[12] == '.') {
                                                            if (inst[13] == 'v') return 819;
                                                        }
                                                    }
                                                }
                                                if (inst[10] == '6') {
                                                    if (inst[11] == '4') {
                                                        if (inst[12] == '.') {
                                                            if (inst[13] == 'v') return 823;
                                                        }
                                                    }
                                                }
                                                if (inst[10] == '1') {
                                                    if (inst[11] == '6') {
                                                        if (inst[12] == '.') {
                                                            if (inst[13] == 'v') return 815;
                                                        }
                                                    }
                                                }
                                            }
                                        }
                                    }
                                    if (inst[7] == '7') {
                                        if (inst[8] == 'e') {
                                            if (inst[9] == 'i') {
                                                if (inst[10] == '3') {
                                                    if (inst[11] == '2') {
                                                        if (inst[12] == '.') {
                                                            if (inst[13] == 'v') return 851;
                                                        }
                                                    }
                                                }
                                                if (inst[10] == '6') {
                                                    if (inst[11] == '4') {
                                                        if (inst[12] == '.') {
                                                            if (inst[13] == 'v') return 855;
                                                        }
                                                    }
                                                }
                                                if (inst[10] == '1') {
                                                    if (inst[11] == '6') {
                                                        if (inst[12] == '.') {
                                                            if (inst[13] == 'v') return 847;
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
                if (inst[2] == 'l') {
                    if (inst[3] == 'i') {
                        if (inst[4] == 'd') {
                            if (inst[5] == 'e') {
                                if (inst[6] == '1') {
                                    if (inst[7] == 'd') {
                                        if (inst[8] == 'o') {
                                            if (inst[9] == 'w') {
                                                if (inst[10] == 'n') {
                                                    if (inst[11] == '.') {
                                                        if (inst[12] == 'v') {
                                                            if (inst[13] == 'x') return 1195;
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
                if (inst[2] == 'u') {
                    if (inst[3] == 'x') {
                        if (inst[4] == 's') {
                            if (inst[5] == 'e') {
                                if (inst[6] == 'g') {
                                    if (inst[7] == '3') {
                                        if (inst[8] == 'e') {
                                            if (inst[9] == 'i') {
                                                if (inst[10] == '3') {
                                                    if (inst[11] == '2') {
                                                        if (inst[12] == '.') {
                                                            if (inst[13] == 'v') return 784;
                                                        }
                                                    }
                                                }
                                                if (inst[10] == '6') {
                                                    if (inst[11] == '4') {
                                                        if (inst[12] == '.') {
                                                            if (inst[13] == 'v') return 788;
                                                        }
                                                    }
                                                }
                                                if (inst[10] == '1') {
                                                    if (inst[11] == '6') {
                                                        if (inst[12] == '.') {
                                                            if (inst[13] == 'v') return 780;
                                                        }
                                                    }
                                                }
                                            }
                                        }
                                    }
                                    if (inst[7] == '2') {
                                        if (inst[8] == 'e') {
                                            if (inst[9] == 'i') {
                                                if (inst[10] == '3') {
                                                    if (inst[11] == '2') {
                                                        if (inst[12] == '.') {
                                                            if (inst[13] == 'v') return 768;
                                                        }
                                                    }
                                                }
                                                if (inst[10] == '6') {
                                                    if (inst[11] == '4') {
                                                        if (inst[12] == '.') {
                                                            if (inst[13] == 'v') return 772;
                                                        }
                                                    }
                                                }
                                                if (inst[10] == '1') {
                                                    if (inst[11] == '6') {
                                                        if (inst[12] == '.') {
                                                            if (inst[13] == 'v') return 764;
                                                        }
                                                    }
                                                }
                                            }
                                        }
                                    }
                                    if (inst[7] == '6') {
                                        if (inst[8] == 'e') {
                                            if (inst[9] == 'i') {
                                                if (inst[10] == '3') {
                                                    if (inst[11] == '2') {
                                                        if (inst[12] == '.') {
                                                            if (inst[13] == 'v') return 832;
                                                        }
                                                    }
                                                }
                                                if (inst[10] == '6') {
                                                    if (inst[11] == '4') {
                                                        if (inst[12] == '.') {
                                                            if (inst[13] == 'v') return 836;
                                                        }
                                                    }
                                                }
                                                if (inst[10] == '1') {
                                                    if (inst[11] == '6') {
                                                        if (inst[12] == '.') {
                                                            if (inst[13] == 'v') return 828;
                                                        }
                                                    }
                                                }
                                            }
                                        }
                                    }
                                    if (inst[7] == '4') {
                                        if (inst[8] == 'e') {
                                            if (inst[9] == 'i') {
                                                if (inst[10] == '3') {
                                                    if (inst[11] == '2') {
                                                        if (inst[12] == '.') {
                                                            if (inst[13] == 'v') return 800;
                                                        }
                                                    }
                                                }
                                                if (inst[10] == '6') {
                                                    if (inst[11] == '4') {
                                                        if (inst[12] == '.') {
                                                            if (inst[13] == 'v') return 804;
                                                        }
                                                    }
                                                }
                                                if (inst[10] == '1') {
                                                    if (inst[11] == '6') {
                                                        if (inst[12] == '.') {
                                                            if (inst[13] == 'v') return 796;
                                                        }
                                                    }
                                                }
                                            }
                                        }
                                    }
                                    if (inst[7] == '8') {
                                        if (inst[8] == 'e') {
                                            if (inst[9] == 'i') {
                                                if (inst[10] == '3') {
                                                    if (inst[11] == '2') {
                                                        if (inst[12] == '.') {
                                                            if (inst[13] == 'v') return 864;
                                                        }
                                                    }
                                                }
                                                if (inst[10] == '6') {
                                                    if (inst[11] == '4') {
                                                        if (inst[12] == '.') {
                                                            if (inst[13] == 'v') return 868;
                                                        }
                                                    }
                                                }
                                                if (inst[10] == '1') {
                                                    if (inst[11] == '6') {
                                                        if (inst[12] == '.') {
                                                            if (inst[13] == 'v') return 860;
                                                        }
                                                    }
                                                }
                                            }
                                        }
                                    }
                                    if (inst[7] == '5') {
                                        if (inst[8] == 'e') {
                                            if (inst[9] == 'i') {
                                                if (inst[10] == '3') {
                                                    if (inst[11] == '2') {
                                                        if (inst[12] == '.') {
                                                            if (inst[13] == 'v') return 816;
                                                        }
                                                    }
                                                }
                                                if (inst[10] == '6') {
                                                    if (inst[11] == '4') {
                                                        if (inst[12] == '.') {
                                                            if (inst[13] == 'v') return 820;
                                                        }
                                                    }
                                                }
                                                if (inst[10] == '1') {
                                                    if (inst[11] == '6') {
                                                        if (inst[12] == '.') {
                                                            if (inst[13] == 'v') return 812;
                                                        }
                                                    }
                                                }
                                            }
                                        }
                                    }
                                    if (inst[7] == '7') {
                                        if (inst[8] == 'e') {
                                            if (inst[9] == 'i') {
                                                if (inst[10] == '3') {
                                                    if (inst[11] == '2') {
                                                        if (inst[12] == '.') {
                                                            if (inst[13] == 'v') return 848;
                                                        }
                                                    }
                                                }
                                                if (inst[10] == '6') {
                                                    if (inst[11] == '4') {
                                                        if (inst[12] == '.') {
                                                            if (inst[13] == 'v') return 852;
                                                        }
                                                    }
                                                }
                                                if (inst[10] == '1') {
                                                    if (inst[11] == '6') {
                                                        if (inst[12] == '.') {
                                                            if (inst[13] == 'v') return 844;
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
                if (inst[2] == 'o') {
                    if (inst[3] == 'x') {
                        if (inst[4] == 's') {
                            if (inst[5] == 'e') {
                                if (inst[6] == 'g') {
                                    if (inst[7] == '3') {
                                        if (inst[8] == 'e') {
                                            if (inst[9] == 'i') {
                                                if (inst[10] == '3') {
                                                    if (inst[11] == '2') {
                                                        if (inst[12] == '.') {
                                                            if (inst[13] == 'v') return 785;
                                                        }
                                                    }
                                                }
                                                if (inst[10] == '6') {
                                                    if (inst[11] == '4') {
                                                        if (inst[12] == '.') {
                                                            if (inst[13] == 'v') return 789;
                                                        }
                                                    }
                                                }
                                                if (inst[10] == '1') {
                                                    if (inst[11] == '6') {
                                                        if (inst[12] == '.') {
                                                            if (inst[13] == 'v') return 781;
                                                        }
                                                    }
                                                }
                                            }
                                        }
                                    }
                                    if (inst[7] == '2') {
                                        if (inst[8] == 'e') {
                                            if (inst[9] == 'i') {
                                                if (inst[10] == '3') {
                                                    if (inst[11] == '2') {
                                                        if (inst[12] == '.') {
                                                            if (inst[13] == 'v') return 769;
                                                        }
                                                    }
                                                }
                                                if (inst[10] == '6') {
                                                    if (inst[11] == '4') {
                                                        if (inst[12] == '.') {
                                                            if (inst[13] == 'v') return 773;
                                                        }
                                                    }
                                                }
                                                if (inst[10] == '1') {
                                                    if (inst[11] == '6') {
                                                        if (inst[12] == '.') {
                                                            if (inst[13] == 'v') return 765;
                                                        }
                                                    }
                                                }
                                            }
                                        }
                                    }
                                    if (inst[7] == '6') {
                                        if (inst[8] == 'e') {
                                            if (inst[9] == 'i') {
                                                if (inst[10] == '3') {
                                                    if (inst[11] == '2') {
                                                        if (inst[12] == '.') {
                                                            if (inst[13] == 'v') return 833;
                                                        }
                                                    }
                                                }
                                                if (inst[10] == '6') {
                                                    if (inst[11] == '4') {
                                                        if (inst[12] == '.') {
                                                            if (inst[13] == 'v') return 837;
                                                        }
                                                    }
                                                }
                                                if (inst[10] == '1') {
                                                    if (inst[11] == '6') {
                                                        if (inst[12] == '.') {
                                                            if (inst[13] == 'v') return 829;
                                                        }
                                                    }
                                                }
                                            }
                                        }
                                    }
                                    if (inst[7] == '4') {
                                        if (inst[8] == 'e') {
                                            if (inst[9] == 'i') {
                                                if (inst[10] == '3') {
                                                    if (inst[11] == '2') {
                                                        if (inst[12] == '.') {
                                                            if (inst[13] == 'v') return 801;
                                                        }
                                                    }
                                                }
                                                if (inst[10] == '6') {
                                                    if (inst[11] == '4') {
                                                        if (inst[12] == '.') {
                                                            if (inst[13] == 'v') return 805;
                                                        }
                                                    }
                                                }
                                                if (inst[10] == '1') {
                                                    if (inst[11] == '6') {
                                                        if (inst[12] == '.') {
                                                            if (inst[13] == 'v') return 797;
                                                        }
                                                    }
                                                }
                                            }
                                        }
                                    }
                                    if (inst[7] == '8') {
                                        if (inst[8] == 'e') {
                                            if (inst[9] == 'i') {
                                                if (inst[10] == '3') {
                                                    if (inst[11] == '2') {
                                                        if (inst[12] == '.') {
                                                            if (inst[13] == 'v') return 865;
                                                        }
                                                    }
                                                }
                                                if (inst[10] == '6') {
                                                    if (inst[11] == '4') {
                                                        if (inst[12] == '.') {
                                                            if (inst[13] == 'v') return 869;
                                                        }
                                                    }
                                                }
                                                if (inst[10] == '1') {
                                                    if (inst[11] == '6') {
                                                        if (inst[12] == '.') {
                                                            if (inst[13] == 'v') return 861;
                                                        }
                                                    }
                                                }
                                            }
                                        }
                                    }
                                    if (inst[7] == '5') {
                                        if (inst[8] == 'e') {
                                            if (inst[9] == 'i') {
                                                if (inst[10] == '3') {
                                                    if (inst[11] == '2') {
                                                        if (inst[12] == '.') {
                                                            if (inst[13] == 'v') return 817;
                                                        }
                                                    }
                                                }
                                                if (inst[10] == '6') {
                                                    if (inst[11] == '4') {
                                                        if (inst[12] == '.') {
                                                            if (inst[13] == 'v') return 821;
                                                        }
                                                    }
                                                }
                                                if (inst[10] == '1') {
                                                    if (inst[11] == '6') {
                                                        if (inst[12] == '.') {
                                                            if (inst[13] == 'v') return 813;
                                                        }
                                                    }
                                                }
                                            }
                                        }
                                    }
                                    if (inst[7] == '7') {
                                        if (inst[8] == 'e') {
                                            if (inst[9] == 'i') {
                                                if (inst[10] == '3') {
                                                    if (inst[11] == '2') {
                                                        if (inst[12] == '.') {
                                                            if (inst[13] == 'v') return 849;
                                                        }
                                                    }
                                                }
                                                if (inst[10] == '6') {
                                                    if (inst[11] == '4') {
                                                        if (inst[12] == '.') {
                                                            if (inst[13] == 'v') return 853;
                                                        }
                                                    }
                                                }
                                                if (inst[10] == '1') {
                                                    if (inst[11] == '6') {
                                                        if (inst[12] == '.') {
                                                            if (inst[13] == 'v') return 845;
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
            if (inst[1] == 'f') {
                if (inst[2] == 'w') {
                    if (inst[3] == 'm') {
                        if (inst[4] == 'a') {
                            if (inst[5] == 'c') {
                                if (inst[6] == 'c') {
                                    if (inst[7] == 'b') {
                                        if (inst[8] == 'f') {
                                            if (inst[9] == '1') {
                                                if (inst[10] == '6') {
                                                    if (inst[11] == '.') {
                                                        if (inst[12] == 'v') {
                                                            if (inst[13] == 'v') return 1282;
                                                            if (inst[13] == 'f') return 1283;
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

    if (size == 15) {
        if (inst[0] == 't') {
            if (inst[1] == 'h') {
                if (inst[2] == '.') {
                    if (inst[3] == 'd') {
                        if (inst[4] == 'c') {
                            if (inst[5] == 'a') {
                                if (inst[6] == 'c') {
                                    if (inst[7] == 'h') {
                                        if (inst[8] == 'e') {
                                            if (inst[9] == '.') {
                                                if (inst[10] == 'c') {
                                                    if (inst[11] == 'i') {
                                                        if (inst[12] == 'a') {
                                                            if (inst[13] == 'l') {
                                                                if (inst[14] == 'l') return 1285;
                                                            }
                                                        }
                                                    }
                                                    if (inst[11] == 'p') {
                                                        if (inst[12] == 'a') {
                                                            if (inst[13] == 'l') {
                                                                if (inst[14] == '1') return 1296;
                                                            }
                                                        }
                                                    }
                                                    if (inst[11] == 'v') {
                                                        if (inst[12] == 'a') {
                                                            if (inst[13] == 'l') {
                                                                if (inst[14] == '1') return 1297;
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
                    if (inst[3] == 'i') {
                        if (inst[4] == 'c') {
                            if (inst[5] == 'a') {
                                if (inst[6] == 'c') {
                                    if (inst[7] == 'h') {
                                        if (inst[8] == 'e') {
                                            if (inst[9] == '.') {
                                                if (inst[10] == 'i') {
                                                    if (inst[11] == 'a') {
                                                        if (inst[12] == 'l') {
                                                            if (inst[13] == 'l') {
                                                                if (inst[14] == 's') return 1299;
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
                    if (inst[3] == 'l') {
                        if (inst[4] == '2') {
                            if (inst[5] == 'c') {
                                if (inst[6] == 'a') {
                                    if (inst[7] == 'c') {
                                        if (inst[8] == 'h') {
                                            if (inst[9] == 'e') {
                                                if (inst[10] == '.') {
                                                    if (inst[11] == 'i') {
                                                        if (inst[12] == 'a') {
                                                            if (inst[13] == 'l') {
                                                                if (inst[14] == 'l') return 1304;
                                                            }
                                                        }
                                                    }
                                                    if (inst[11] == 'c') {
                                                        if (inst[12] == 'a') {
                                                            if (inst[13] == 'l') {
                                                                if (inst[14] == 'l') return 1302;
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
                    if (inst[3] == 'v') {
                        if (inst[4] == 'w') {
                            if (inst[5] == 's') {
                                if (inst[6] == 'm') {
                                    if (inst[7] == 'a') {
                                        if (inst[8] == 'c') {
                                            if (inst[9] == 'c') {
                                                if (inst[10] == 'u') {
                                                    if (inst[11] == 's') {
                                                        if (inst[12] == '.') {
                                                            if (inst[13] == 'v') {
                                                                if (inst[14] == 'x') return 1892;
                                                            }
                                                        }
                                                    }
                                                }
                                                if (inst[10] == 's') {
                                                    if (inst[11] == 'u') {
                                                        if (inst[12] == '.') {
                                                            if (inst[13] == 'v') {
                                                                if (inst[14] == 'x') return 1891;
                                                                if (inst[14] == 'v') return 1890;
                                                            }
                                                        }
                                                    }
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                            if (inst[5] == 'r') {
                                if (inst[6] == 'e') {
                                    if (inst[7] == 'd') {
                                        if (inst[8] == 's') {
                                            if (inst[9] == 'u') {
                                                if (inst[10] == 'm') {
                                                    if (inst[11] == 'u') {
                                                        if (inst[12] == '.') {
                                                            if (inst[13] == 'v') {
                                                                if (inst[14] == 's') return 1997;
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
                        if (inst[4] == 's') {
                            if (inst[5] == 'l') {
                                if (inst[6] == 'i') {
                                    if (inst[7] == 'd') {
                                        if (inst[8] == 'e') {
                                            if (inst[9] == '1') {
                                                if (inst[10] == 'u') {
                                                    if (inst[11] == 'p') {
                                                        if (inst[12] == '.') {
                                                            if (inst[13] == 'v') {
                                                                if (inst[14] == 'x') return 2028;
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
                        if (inst[4] == 'l') {
                            if (inst[5] == 's') {
                                if (inst[6] == 'e') {
                                    if (inst[7] == 'g') {
                                        if (inst[8] == '3') {
                                            if (inst[9] == 'w') {
                                                if (inst[10] == 'u') {
                                                    if (inst[11] == 'f') {
                                                        if (inst[12] == 'f') {
                                                            if (inst[13] == '.') {
                                                                if (inst[14] == 'v') return 1553;
                                                            }
                                                        }
                                                    }
                                                }
                                            }
                                            if (inst[9] == 'b') {
                                                if (inst[10] == 'u') {
                                                    if (inst[11] == 'f') {
                                                        if (inst[12] == 'f') {
                                                            if (inst[13] == '.') {
                                                                if (inst[14] == 'v') return 1551;
                                                            }
                                                        }
                                                    }
                                                }
                                            }
                                            if (inst[9] == 'h') {
                                                if (inst[10] == 'u') {
                                                    if (inst[11] == 'f') {
                                                        if (inst[12] == 'f') {
                                                            if (inst[13] == '.') {
                                                                if (inst[14] == 'v') return 1552;
                                                            }
                                                        }
                                                    }
                                                }
                                            }
                                        }
                                        if (inst[8] == '2') {
                                            if (inst[9] == 'w') {
                                                if (inst[10] == 'u') {
                                                    if (inst[11] == 'f') {
                                                        if (inst[12] == 'f') {
                                                            if (inst[13] == '.') {
                                                                if (inst[14] == 'v') return 1550;
                                                            }
                                                        }
                                                    }
                                                }
                                            }
                                            if (inst[9] == 'b') {
                                                if (inst[10] == 'u') {
                                                    if (inst[11] == 'f') {
                                                        if (inst[12] == 'f') {
                                                            if (inst[13] == '.') {
                                                                if (inst[14] == 'v') return 1548;
                                                            }
                                                        }
                                                    }
                                                }
                                            }
                                            if (inst[9] == 'h') {
                                                if (inst[10] == 'u') {
                                                    if (inst[11] == 'f') {
                                                        if (inst[12] == 'f') {
                                                            if (inst[13] == '.') {
                                                                if (inst[14] == 'v') return 1549;
                                                            }
                                                        }
                                                    }
                                                }
                                            }
                                        }
                                        if (inst[8] == '6') {
                                            if (inst[9] == 'w') {
                                                if (inst[10] == 'u') {
                                                    if (inst[11] == 'f') {
                                                        if (inst[12] == 'f') {
                                                            if (inst[13] == '.') {
                                                                if (inst[14] == 'v') return 1562;
                                                            }
                                                        }
                                                    }
                                                }
                                            }
                                            if (inst[9] == 'b') {
                                                if (inst[10] == 'u') {
                                                    if (inst[11] == 'f') {
                                                        if (inst[12] == 'f') {
                                                            if (inst[13] == '.') {
                                                                if (inst[14] == 'v') return 1560;
                                                            }
                                                        }
                                                    }
                                                }
                                            }
                                            if (inst[9] == 'h') {
                                                if (inst[10] == 'u') {
                                                    if (inst[11] == 'f') {
                                                        if (inst[12] == 'f') {
                                                            if (inst[13] == '.') {
                                                                if (inst[14] == 'v') return 1561;
                                                            }
                                                        }
                                                    }
                                                }
                                            }
                                        }
                                        if (inst[8] == '4') {
                                            if (inst[9] == 'w') {
                                                if (inst[10] == 'u') {
                                                    if (inst[11] == 'f') {
                                                        if (inst[12] == 'f') {
                                                            if (inst[13] == '.') {
                                                                if (inst[14] == 'v') return 1556;
                                                            }
                                                        }
                                                    }
                                                }
                                            }
                                            if (inst[9] == 'b') {
                                                if (inst[10] == 'u') {
                                                    if (inst[11] == 'f') {
                                                        if (inst[12] == 'f') {
                                                            if (inst[13] == '.') {
                                                                if (inst[14] == 'v') return 1554;
                                                            }
                                                        }
                                                    }
                                                }
                                            }
                                            if (inst[9] == 'h') {
                                                if (inst[10] == 'u') {
                                                    if (inst[11] == 'f') {
                                                        if (inst[12] == 'f') {
                                                            if (inst[13] == '.') {
                                                                if (inst[14] == 'v') return 1555;
                                                            }
                                                        }
                                                    }
                                                }
                                            }
                                        }
                                        if (inst[8] == '8') {
                                            if (inst[9] == 'w') {
                                                if (inst[10] == 'u') {
                                                    if (inst[11] == 'f') {
                                                        if (inst[12] == 'f') {
                                                            if (inst[13] == '.') {
                                                                if (inst[14] == 'v') return 1568;
                                                            }
                                                        }
                                                    }
                                                }
                                            }
                                            if (inst[9] == 'b') {
                                                if (inst[10] == 'u') {
                                                    if (inst[11] == 'f') {
                                                        if (inst[12] == 'f') {
                                                            if (inst[13] == '.') {
                                                                if (inst[14] == 'v') return 1566;
                                                            }
                                                        }
                                                    }
                                                }
                                            }
                                            if (inst[9] == 'h') {
                                                if (inst[10] == 'u') {
                                                    if (inst[11] == 'f') {
                                                        if (inst[12] == 'f') {
                                                            if (inst[13] == '.') {
                                                                if (inst[14] == 'v') return 1567;
                                                            }
                                                        }
                                                    }
                                                }
                                            }
                                        }
                                        if (inst[8] == '5') {
                                            if (inst[9] == 'w') {
                                                if (inst[10] == 'u') {
                                                    if (inst[11] == 'f') {
                                                        if (inst[12] == 'f') {
                                                            if (inst[13] == '.') {
                                                                if (inst[14] == 'v') return 1559;
                                                            }
                                                        }
                                                    }
                                                }
                                            }
                                            if (inst[9] == 'b') {
                                                if (inst[10] == 'u') {
                                                    if (inst[11] == 'f') {
                                                        if (inst[12] == 'f') {
                                                            if (inst[13] == '.') {
                                                                if (inst[14] == 'v') return 1557;
                                                            }
                                                        }
                                                    }
                                                }
                                            }
                                            if (inst[9] == 'h') {
                                                if (inst[10] == 'u') {
                                                    if (inst[11] == 'f') {
                                                        if (inst[12] == 'f') {
                                                            if (inst[13] == '.') {
                                                                if (inst[14] == 'v') return 1558;
                                                            }
                                                        }
                                                    }
                                                }
                                            }
                                        }
                                        if (inst[8] == '7') {
                                            if (inst[9] == 'w') {
                                                if (inst[10] == 'u') {
                                                    if (inst[11] == 'f') {
                                                        if (inst[12] == 'f') {
                                                            if (inst[13] == '.') {
                                                                if (inst[14] == 'v') return 1565;
                                                            }
                                                        }
                                                    }
                                                }
                                            }
                                            if (inst[9] == 'b') {
                                                if (inst[10] == 'u') {
                                                    if (inst[11] == 'f') {
                                                        if (inst[12] == 'f') {
                                                            if (inst[13] == '.') {
                                                                if (inst[14] == 'v') return 1563;
                                                            }
                                                        }
                                                    }
                                                }
                                            }
                                            if (inst[9] == 'h') {
                                                if (inst[10] == 'u') {
                                                    if (inst[11] == 'f') {
                                                        if (inst[12] == 'f') {
                                                            if (inst[13] == '.') {
                                                                if (inst[14] == 'v') return 1564;
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
                        if (inst[4] == 'c') {
                            if (inst[5] == 'o') {
                                if (inst[6] == 'm') {
                                    if (inst[7] == 'p') {
                                        if (inst[8] == 'r') {
                                            if (inst[9] == 'e') {
                                                if (inst[10] == 's') {
                                                    if (inst[11] == 's') {
                                                        if (inst[12] == '.') {
                                                            if (inst[13] == 'v') {
                                                                if (inst[14] == 'm') return 2033;
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
                        if (inst[4] == 'f') {
                            if (inst[5] == 'w') {
                                if (inst[6] == 'r') {
                                    if (inst[7] == 'e') {
                                        if (inst[8] == 'd') {
                                            if (inst[9] == 's') {
                                                if (inst[10] == 'u') {
                                                    if (inst[11] == 'm') {
                                                        if (inst[12] == '.') {
                                                            if (inst[13] == 'v') {
                                                                if (inst[14] == 's') return 2004;
                                                            }
                                                        }
                                                    }
                                                }
                                            }
                                        }
                                    }
                                }
                                if (inst[6] == 'c') {
                                    if (inst[7] == 'v') {
                                        if (inst[8] == 't') {
                                            if (inst[9] == '.') {
                                                if (inst[10] == 'x') {
                                                    if (inst[11] == '.') {
                                                        if (inst[12] == 'f') {
                                                            if (inst[13] == '.') {
                                                                if (inst[14] == 'v') return 1980;
                                                            }
                                                        }
                                                    }
                                                }
                                                if (inst[10] == 'f') {
                                                    if (inst[11] == '.') {
                                                        if (inst[12] == 'x') {
                                                            if (inst[13] == '.') {
                                                                if (inst[14] == 'v') return 1982;
                                                            }
                                                        }
                                                        if (inst[12] == 'f') {
                                                            if (inst[13] == '.') {
                                                                if (inst[14] == 'v') return 1983;
                                                            }
                                                        }
                                                    }
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                            if (inst[5] == 'r') {
                                if (inst[6] == 'e') {
                                    if (inst[7] == 'd') {
                                        if (inst[8] == 'o') {
                                            if (inst[9] == 's') {
                                                if (inst[10] == 'u') {
                                                    if (inst[11] == 'm') {
                                                        if (inst[12] == '.') {
                                                            if (inst[13] == 'v') {
                                                                if (inst[14] == 's') return 1999;
                                                            }
                                                        }
                                                    }
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                            if (inst[5] == 'n') {
                                if (inst[6] == 'c') {
                                    if (inst[7] == 'v') {
                                        if (inst[8] == 't') {
                                            if (inst[9] == '.') {
                                                if (inst[10] == 'x') {
                                                    if (inst[11] == '.') {
                                                        if (inst[12] == 'f') {
                                                            if (inst[13] == '.') {
                                                                if (inst[14] == 'v') return 1985;
                                                            }
                                                        }
                                                    }
                                                }
                                                if (inst[10] == 'f') {
                                                    if (inst[11] == '.') {
                                                        if (inst[12] == 'x') {
                                                            if (inst[13] == '.') {
                                                                if (inst[14] == 'v') return 1987;
                                                            }
                                                        }
                                                        if (inst[12] == 'f') {
                                                            if (inst[13] == '.') {
                                                                if (inst[14] == 'v') return 1988;
                                                            }
                                                        }
                                                    }
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                            if (inst[5] == 'c') {
                                if (inst[6] == 'v') {
                                    if (inst[7] == 't') {
                                        if (inst[8] == '.') {
                                            if (inst[9] == 'x') {
                                                if (inst[10] == 'u') {
                                                    if (inst[11] == '.') {
                                                        if (inst[12] == 'f') {
                                                            if (inst[13] == '.') {
                                                                if (inst[14] == 'v') return 1975;
                                                            }
                                                        }
                                                    }
                                                }
                                            }
                                            if (inst[9] == 'f') {
                                                if (inst[10] == '.') {
                                                    if (inst[11] == 'x') {
                                                        if (inst[12] == 'u') {
                                                            if (inst[13] == '.') {
                                                                if (inst[14] == 'v') return 1977;
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
        if (inst[0] == 'v') {
            if (inst[1] == 'r') {
                if (inst[2] == 'g') {
                    if (inst[3] == 'a') {
                        if (inst[4] == 't') {
                            if (inst[5] == 'h') {
                                if (inst[6] == 'e') {
                                    if (inst[7] == 'r') {
                                        if (inst[8] == 'e') {
                                            if (inst[9] == 'i') {
                                                if (inst[10] == '1') {
                                                    if (inst[11] == '6') {
                                                        if (inst[12] == '.') {
                                                            if (inst[13] == 'v') {
                                                                if (inst[14] == 'v') return 1198;
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
            if (inst[1] == 'f') {
                if (inst[2] == 's') {
                    if (inst[3] == 'l') {
                        if (inst[4] == 'i') {
                            if (inst[5] == 'd') {
                                if (inst[6] == 'e') {
                                    if (inst[7] == '1') {
                                        if (inst[8] == 'd') {
                                            if (inst[9] == 'o') {
                                                if (inst[10] == 'w') {
                                                    if (inst[11] == 'n') {
                                                        if (inst[12] == '.') {
                                                            if (inst[13] == 'v') {
                                                                if (inst[14] == 'f') return 1196;
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
                if (inst[2] == 'c') {
                    if (inst[3] == 'v') {
                        if (inst[4] == 't') {
                            if (inst[5] == '.') {
                                if (inst[6] == 'r') {
                                    if (inst[7] == 't') {
                                        if (inst[8] == 'z') {
                                            if (inst[9] == '.') {
                                                if (inst[10] == 'x') {
                                                    if (inst[11] == '.') {
                                                        if (inst[12] == 'f') {
                                                            if (inst[13] == '.') {
                                                                if (inst[14] == 'v') return 1136;
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
    }

    if (size == 16) {
        if (inst[0] == 't') {
            if (inst[1] == 'h') {
                if (inst[2] == '.') {
                    if (inst[3] == 'l') {
                        if (inst[4] == '2') {
                            if (inst[5] == 'c') {
                                if (inst[6] == 'a') {
                                    if (inst[7] == 'c') {
                                        if (inst[8] == 'h') {
                                            if (inst[9] == 'e') {
                                                if (inst[10] == '.') {
                                                    if (inst[11] == 'c') {
                                                        if (inst[12] == 'i') {
                                                            if (inst[13] == 'a') {
                                                                if (inst[14] == 'l') {
                                                                    if (inst[15] == 'l') return 1303;
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
                    if (inst[3] == 'v') {
                        if (inst[4] == 's') {
                            if (inst[5] == 'l') {
                                if (inst[6] == 'i') {
                                    if (inst[7] == 'd') {
                                        if (inst[8] == 'e') {
                                            if (inst[9] == 'd') {
                                                if (inst[10] == 'o') {
                                                    if (inst[11] == 'w') {
                                                        if (inst[12] == 'n') {
                                                            if (inst[13] == '.') {
                                                                if (inst[14] == 'v') {
                                                                    if (inst[15] == 'i') return 2027;
                                                                    if (inst[15] == 'x') return 2026;
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
                        if (inst[4] == 'f') {
                            if (inst[5] == 'w') {
                                if (inst[6] == 'r') {
                                    if (inst[7] == 'e') {
                                        if (inst[8] == 'd') {
                                            if (inst[9] == 'o') {
                                                if (inst[10] == 's') {
                                                    if (inst[11] == 'u') {
                                                        if (inst[12] == 'm') {
                                                            if (inst[13] == '.') {
                                                                if (inst[14] == 'v') {
                                                                    if (inst[15] == 's') return 2003;
                                                                }
                                                            }
                                                        }
                                                    }
                                                }
                                            }
                                        }
                                    }
                                }
                                if (inst[6] == 'c') {
                                    if (inst[7] == 'v') {
                                        if (inst[8] == 't') {
                                            if (inst[9] == '.') {
                                                if (inst[10] == 'x') {
                                                    if (inst[11] == 'u') {
                                                        if (inst[12] == '.') {
                                                            if (inst[13] == 'f') {
                                                                if (inst[14] == '.') {
                                                                    if (inst[15] == 'v') return 1979;
                                                                }
                                                            }
                                                        }
                                                    }
                                                }
                                                if (inst[10] == 'f') {
                                                    if (inst[11] == '.') {
                                                        if (inst[12] == 'x') {
                                                            if (inst[13] == 'u') {
                                                                if (inst[14] == '.') {
                                                                    if (inst[15] == 'v') return 1981;
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
                            if (inst[5] == 'n') {
                                if (inst[6] == 'c') {
                                    if (inst[7] == 'v') {
                                        if (inst[8] == 't') {
                                            if (inst[9] == '.') {
                                                if (inst[10] == 'x') {
                                                    if (inst[11] == 'u') {
                                                        if (inst[12] == '.') {
                                                            if (inst[13] == 'f') {
                                                                if (inst[14] == '.') {
                                                                    if (inst[15] == 'v') return 1984;
                                                                }
                                                            }
                                                        }
                                                    }
                                                }
                                                if (inst[10] == 'f') {
                                                    if (inst[11] == '.') {
                                                        if (inst[12] == 'x') {
                                                            if (inst[13] == 'u') {
                                                                if (inst[14] == '.') {
                                                                    if (inst[15] == 'v') return 1986;
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
        }
        if (inst[0] == 'v') {
            if (inst[1] == 'f') {
                if (inst[2] == 'w') {
                    if (inst[3] == 'c') {
                        if (inst[4] == 'v') {
                            if (inst[5] == 't') {
                                if (inst[6] == '.') {
                                    if (inst[7] == 'r') {
                                        if (inst[8] == 't') {
                                            if (inst[9] == 'z') {
                                                if (inst[10] == '.') {
                                                    if (inst[11] == 'x') {
                                                        if (inst[12] == '.') {
                                                            if (inst[13] == 'f') {
                                                                if (inst[14] == '.') {
                                                                    if (inst[15] == 'v') return 1142;
                                                                }
                                                            }
                                                        }
                                                    }
                                                }
                                            }
                                        }
                                    }
                                }
                                if (inst[6] == 'b') {
                                    if (inst[7] == 'f') {
                                        if (inst[8] == '1') {
                                            if (inst[9] == '6') {
                                                if (inst[10] == '.') {
                                                    if (inst[11] == 'f') {
                                                        if (inst[12] == '.') {
                                                            if (inst[13] == 'f') {
                                                                if (inst[14] == '.') {
                                                                    if (inst[15] == 'v') return 1281;
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
                if (inst[2] == 'n') {
                    if (inst[3] == 'c') {
                        if (inst[4] == 'v') {
                            if (inst[5] == 't') {
                                if (inst[6] == '.') {
                                    if (inst[7] == 'r') {
                                        if (inst[8] == 'o') {
                                            if (inst[9] == 'd') {
                                                if (inst[10] == '.') {
                                                    if (inst[11] == 'f') {
                                                        if (inst[12] == '.') {
                                                            if (inst[13] == 'f') {
                                                                if (inst[14] == '.') {
                                                                    if (inst[15] == 'w') return 1153;
                                                                }
                                                            }
                                                        }
                                                    }
                                                }
                                            }
                                        }
                                        if (inst[8] == 't') {
                                            if (inst[9] == 'z') {
                                                if (inst[10] == '.') {
                                                    if (inst[11] == 'x') {
                                                        if (inst[12] == '.') {
                                                            if (inst[13] == 'f') {
                                                                if (inst[14] == '.') {
                                                                    if (inst[15] == 'w') return 1149;
                                                                }
                                                            }
                                                        }
                                                    }
                                                }
                                            }
                                        }
                                    }
                                }
                                if (inst[6] == 'b') {
                                    if (inst[7] == 'f') {
                                        if (inst[8] == '1') {
                                            if (inst[9] == '6') {
                                                if (inst[10] == '.') {
                                                    if (inst[11] == 'f') {
                                                        if (inst[12] == '.') {
                                                            if (inst[13] == 'f') {
                                                                if (inst[14] == '.') {
                                                                    if (inst[15] == 'w') return 1280;
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
                if (inst[2] == 'c') {
                    if (inst[3] == 'v') {
                        if (inst[4] == 't') {
                            if (inst[5] == '.') {
                                if (inst[6] == 'r') {
                                    if (inst[7] == 't') {
                                        if (inst[8] == 'z') {
                                            if (inst[9] == '.') {
                                                if (inst[10] == 'x') {
                                                    if (inst[11] == 'u') {
                                                        if (inst[12] == '.') {
                                                            if (inst[13] == 'f') {
                                                                if (inst[14] == '.') {
                                                                    if (inst[15] == 'v') return 1135;
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
        }
    }

    if (size == 17) {
        if (inst[0] == 't') {
            if (inst[1] == 'h') {
                if (inst[2] == '.') {
                    if (inst[3] == 'v') {
                        if (inst[4] == 's') {
                            if (inst[5] == 'l') {
                                if (inst[6] == 'i') {
                                    if (inst[7] == 'd') {
                                        if (inst[8] == 'e') {
                                            if (inst[9] == '1') {
                                                if (inst[10] == 'd') {
                                                    if (inst[11] == 'o') {
                                                        if (inst[12] == 'w') {
                                                            if (inst[13] == 'n') {
                                                                if (inst[14] == '.') {
                                                                    if (inst[15] == 'v') {
                                                                        if (inst[16] == 'x') return 2029;
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
            }
        }
        if (inst[0] == 'v') {
            if (inst[1] == 'f') {
                if (inst[2] == 'w') {
                    if (inst[3] == 'c') {
                        if (inst[4] == 'v') {
                            if (inst[5] == 't') {
                                if (inst[6] == '.') {
                                    if (inst[7] == 'r') {
                                        if (inst[8] == 't') {
                                            if (inst[9] == 'z') {
                                                if (inst[10] == '.') {
                                                    if (inst[11] == 'x') {
                                                        if (inst[12] == 'u') {
                                                            if (inst[13] == '.') {
                                                                if (inst[14] == 'f') {
                                                                    if (inst[15] == '.') {
                                                                        if (inst[16] == 'v') return 1141;
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
                if (inst[2] == 'n') {
                    if (inst[3] == 'c') {
                        if (inst[4] == 'v') {
                            if (inst[5] == 't') {
                                if (inst[6] == '.') {
                                    if (inst[7] == 'r') {
                                        if (inst[8] == 't') {
                                            if (inst[9] == 'z') {
                                                if (inst[10] == '.') {
                                                    if (inst[11] == 'x') {
                                                        if (inst[12] == 'u') {
                                                            if (inst[13] == '.') {
                                                                if (inst[14] == 'f') {
                                                                    if (inst[15] == '.') {
                                                                        if (inst[16] == 'w') return 1148;
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
            }
        }
    }

    return instr_search_failed;
}

} // namespace ultrassembler_internal