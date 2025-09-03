// SPDX-License-Identifier: MPL-2.0
// The generate_register_search.py script automatically generated this code. DO NOT MODIFY!
#include "../registers.hpp"
#include "../ultrassembler.hpp"

namespace ultrassembler_internal {

const uint8_t fast_reg_search(const ultrastring& reg) {
    const auto size = reg.size();

    if (size == 2) {
        if (reg[0] == 'a') {
            if (reg[1] == '0') return 10;
            if (reg[1] == '1') return 11;
            if (reg[1] == '2') return 12;
            if (reg[1] == '3') return 13;
            if (reg[1] == '4') return 14;
            if (reg[1] == '5') return 15;
            if (reg[1] == '6') return 16;
            if (reg[1] == '7') return 17;
        }
        if (reg[0] == 'f') {
            if (reg[1] == '0') return 32;
            if (reg[1] == '1') return 33;
            if (reg[1] == '2') return 34;
            if (reg[1] == '3') return 35;
            if (reg[1] == '4') return 36;
            if (reg[1] == '5') return 37;
            if (reg[1] == '6') return 38;
            if (reg[1] == '7') return 39;
            if (reg[1] == '8') return 40;
            if (reg[1] == '9') return 41;
        }
        if (reg[0] == 's') {
            if (reg[1] == '0') return 8;
            if (reg[1] == '1') return 9;
            if (reg[1] == '2') return 18;
            if (reg[1] == '3') return 19;
            if (reg[1] == '4') return 20;
            if (reg[1] == '5') return 21;
            if (reg[1] == '6') return 22;
            if (reg[1] == '7') return 23;
            if (reg[1] == '8') return 24;
            if (reg[1] == '9') return 25;
            if (reg[1] == 'p') return 2;
        }
        if (reg[0] == 't') {
            if (reg[1] == '0') return 5;
            if (reg[1] == '1') return 6;
            if (reg[1] == '2') return 7;
            if (reg[1] == '3') return 28;
            if (reg[1] == '4') return 29;
            if (reg[1] == '5') return 30;
            if (reg[1] == '6') return 31;
            if (reg[1] == 'p') return 4;
        }
        if (reg[0] == 'g') {
            if (reg[1] == 'p') return 3;
        }
        if (reg[0] == 'r') {
            if (reg[1] == 'a') return 1;
        }
        if (reg[0] == 'v') {
            if (reg[1] == '0') return 64;
            if (reg[1] == '1') return 65;
            if (reg[1] == '2') return 66;
            if (reg[1] == '3') return 67;
            if (reg[1] == '4') return 68;
            if (reg[1] == '5') return 69;
            if (reg[1] == '6') return 70;
            if (reg[1] == '7') return 71;
            if (reg[1] == '8') return 72;
            if (reg[1] == '9') return 73;
        }
        if (reg[0] == 'x') {
            if (reg[1] == '0') return 0;
            if (reg[1] == '1') return 1;
            if (reg[1] == '2') return 2;
            if (reg[1] == '3') return 3;
            if (reg[1] == '4') return 4;
            if (reg[1] == '5') return 5;
            if (reg[1] == '6') return 6;
            if (reg[1] == '7') return 7;
            if (reg[1] == '8') return 8;
            if (reg[1] == '9') return 9;
        }
    }

    if (size == 3) {
        if (reg[0] == 'f') {
            if (reg[1] == 'a') {
                if (reg[2] == '0') return 42;
                if (reg[2] == '1') return 43;
                if (reg[2] == '2') return 44;
                if (reg[2] == '3') return 45;
                if (reg[2] == '4') return 46;
                if (reg[2] == '5') return 47;
                if (reg[2] == '6') return 48;
                if (reg[2] == '7') return 49;
            }
            if (reg[1] == '1') {
                if (reg[2] == '0') return 42;
                if (reg[2] == '1') return 43;
                if (reg[2] == '2') return 44;
                if (reg[2] == '3') return 45;
                if (reg[2] == '4') return 46;
                if (reg[2] == '5') return 47;
                if (reg[2] == '6') return 48;
                if (reg[2] == '7') return 49;
                if (reg[2] == '8') return 50;
                if (reg[2] == '9') return 51;
            }
            if (reg[1] == '2') {
                if (reg[2] == '0') return 52;
                if (reg[2] == '1') return 53;
                if (reg[2] == '2') return 54;
                if (reg[2] == '3') return 55;
                if (reg[2] == '4') return 56;
                if (reg[2] == '5') return 57;
                if (reg[2] == '6') return 58;
                if (reg[2] == '7') return 59;
                if (reg[2] == '8') return 60;
                if (reg[2] == '9') return 61;
            }
            if (reg[1] == '3') {
                if (reg[2] == '0') return 62;
                if (reg[2] == '1') return 63;
            }
            if (reg[1] == 's') {
                if (reg[2] == '0') return 40;
                if (reg[2] == '1') return 41;
                if (reg[2] == '2') return 50;
                if (reg[2] == '3') return 51;
                if (reg[2] == '4') return 52;
                if (reg[2] == '5') return 53;
                if (reg[2] == '6') return 54;
                if (reg[2] == '7') return 55;
                if (reg[2] == '8') return 56;
                if (reg[2] == '9') return 57;
            }
            if (reg[1] == 't') {
                if (reg[2] == '0') return 32;
                if (reg[2] == '1') return 33;
                if (reg[2] == '2') return 34;
                if (reg[2] == '3') return 35;
                if (reg[2] == '4') return 36;
                if (reg[2] == '5') return 37;
                if (reg[2] == '6') return 38;
                if (reg[2] == '7') return 39;
                if (reg[2] == '8') return 60;
                if (reg[2] == '9') return 61;
            }
        }
        if (reg[0] == 's') {
            if (reg[1] == '1') {
                if (reg[2] == '0') return 26;
                if (reg[2] == '1') return 27;
            }
        }
        if (reg[0] == 'v') {
            if (reg[1] == '1') {
                if (reg[2] == '0') return 74;
                if (reg[2] == '1') return 75;
                if (reg[2] == '2') return 76;
                if (reg[2] == '3') return 77;
                if (reg[2] == '4') return 78;
                if (reg[2] == '5') return 79;
                if (reg[2] == '6') return 80;
                if (reg[2] == '7') return 81;
                if (reg[2] == '8') return 82;
                if (reg[2] == '9') return 83;
            }
            if (reg[1] == '2') {
                if (reg[2] == '0') return 84;
                if (reg[2] == '1') return 85;
                if (reg[2] == '2') return 86;
                if (reg[2] == '3') return 87;
                if (reg[2] == '4') return 88;
                if (reg[2] == '5') return 89;
                if (reg[2] == '6') return 90;
                if (reg[2] == '7') return 91;
                if (reg[2] == '8') return 92;
                if (reg[2] == '9') return 93;
            }
            if (reg[1] == '3') {
                if (reg[2] == '0') return 94;
                if (reg[2] == '1') return 95;
            }
        }
        if (reg[0] == 'x') {
            if (reg[1] == '1') {
                if (reg[2] == '0') return 10;
                if (reg[2] == '1') return 11;
                if (reg[2] == '2') return 12;
                if (reg[2] == '3') return 13;
                if (reg[2] == '4') return 14;
                if (reg[2] == '5') return 15;
                if (reg[2] == '6') return 16;
                if (reg[2] == '7') return 17;
                if (reg[2] == '8') return 18;
                if (reg[2] == '9') return 19;
            }
            if (reg[1] == '2') {
                if (reg[2] == '0') return 20;
                if (reg[2] == '1') return 21;
                if (reg[2] == '2') return 22;
                if (reg[2] == '3') return 23;
                if (reg[2] == '4') return 24;
                if (reg[2] == '5') return 25;
                if (reg[2] == '6') return 26;
                if (reg[2] == '7') return 27;
                if (reg[2] == '8') return 28;
                if (reg[2] == '9') return 29;
            }
            if (reg[1] == '3') {
                if (reg[2] == '0') return 30;
                if (reg[2] == '1') return 31;
            }
        }
    }

    if (size == 4) {
        if (reg[0] == 'f') {
            if (reg[1] == 's') {
                if (reg[2] == '1') {
                    if (reg[3] == '0') return 58;
                    if (reg[3] == '1') return 59;
                }
            }
            if (reg[1] == 't') {
                if (reg[2] == '1') {
                    if (reg[3] == '0') return 62;
                    if (reg[3] == '1') return 63;
                }
            }
        }
        if (reg[0] == 'z') {
            if (reg[1] == 'e') {
                if (reg[2] == 'r') {
                    if (reg[3] == 'o') return 0;
                }
            }
        }
    }

    return reg_search_failed;
}

} // namespace ultrassembler_internal