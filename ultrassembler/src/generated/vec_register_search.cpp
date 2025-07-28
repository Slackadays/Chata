// SPDX-License-Identifier: MPL-2.0
// The generate_register_search.py script automatically generated this code. DO NOT MODIFY!
#include "../ultrassembler.hpp"
#include "../registers.hpp"

namespace ultrassembler_internal {

const uint8_t fast_vec_reg_search(const ultrastring& reg) {
    if (reg.size() < 1) return reg_search_failed;
    if (reg[0] == 'v') {
        if (reg.size() < 2) return reg_search_failed;
        if (reg[1] == '0') {
            if (reg.size() < 3) return 0;
        }
        if (reg[1] == '1') {
            if (reg.size() < 3) return 1;
            if (reg[2] == '0') {
                if (reg.size() < 4) return 10;
            }
            if (reg[2] == '1') {
                if (reg.size() < 4) return 11;
            }
            if (reg[2] == '2') {
                if (reg.size() < 4) return 12;
            }
            if (reg[2] == '3') {
                if (reg.size() < 4) return 13;
            }
            if (reg[2] == '4') {
                if (reg.size() < 4) return 14;
            }
            if (reg[2] == '5') {
                if (reg.size() < 4) return 15;
            }
            if (reg[2] == '6') {
                if (reg.size() < 4) return 16;
            }
            if (reg[2] == '7') {
                if (reg.size() < 4) return 17;
            }
            if (reg[2] == '8') {
                if (reg.size() < 4) return 18;
            }
            if (reg[2] == '9') {
                if (reg.size() < 4) return 19;
            }
        }
        if (reg[1] == '2') {
            if (reg.size() < 3) return 2;
            if (reg[2] == '0') {
                if (reg.size() < 4) return 20;
            }
            if (reg[2] == '1') {
                if (reg.size() < 4) return 21;
            }
            if (reg[2] == '2') {
                if (reg.size() < 4) return 22;
            }
            if (reg[2] == '3') {
                if (reg.size() < 4) return 23;
            }
            if (reg[2] == '4') {
                if (reg.size() < 4) return 24;
            }
            if (reg[2] == '5') {
                if (reg.size() < 4) return 25;
            }
            if (reg[2] == '6') {
                if (reg.size() < 4) return 26;
            }
            if (reg[2] == '7') {
                if (reg.size() < 4) return 27;
            }
            if (reg[2] == '8') {
                if (reg.size() < 4) return 28;
            }
            if (reg[2] == '9') {
                if (reg.size() < 4) return 29;
            }
        }
        if (reg[1] == '3') {
            if (reg.size() < 3) return 3;
            if (reg[2] == '0') {
                if (reg.size() < 4) return 30;
            }
            if (reg[2] == '1') {
                if (reg.size() < 4) return 31;
            }
        }
        if (reg[1] == '4') {
            if (reg.size() < 3) return 4;
        }
        if (reg[1] == '5') {
            if (reg.size() < 3) return 5;
        }
        if (reg[1] == '6') {
            if (reg.size() < 3) return 6;
        }
        if (reg[1] == '7') {
            if (reg.size() < 3) return 7;
        }
        if (reg[1] == '8') {
            if (reg.size() < 3) return 8;
        }
        if (reg[1] == '9') {
            if (reg.size() < 3) return 9;
        }
    }
    return reg_search_failed;
}

} // namespace ultrassembler_internal