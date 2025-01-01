// SPDX-License-Identifier: MPL-2.0
#include "debug.hpp"
#include "libchata.hpp"
#include "registers.hpp"
#include <algorithm>
#include <charconv>

namespace libchata_internal {

bool is_integer(const chatastring& str) {
    for (auto c : str) {
        if (!std::isdigit(c)) {
            return false;
        }
    }
    return true;
}

bool is_float(const chatastring& str) {
    bool has_dot = false;
    for (auto c : str) {
        if (!std::isdigit(c) && c != '.') {
            return false;
        }
        if (c == '.') {
            if (has_dot) {
                return false;
            }
            has_dot = true;
        }
    }
    return true;
}

bool is_number(const chatastring& str) {
    return is_integer(str) || is_float(str);
}

chatastring to_chatastring(int num) {
    chatastring result;
    std::array<char, 16> temp;
    auto res = std::to_chars(temp.data(), temp.data() + temp.size(), num);
    if (res.ec != std::errc()) {
        throw ChataError(ChataErrorType::Other, "Invalid integer");
    }
    for (auto i = temp.data(); i < res.ptr; i++) {
        result.push_back(*i);
    }
    DBG(std::cout << "result: " << result << std::endl;)
    return result;
}

std::optional<int> to_int(const chatastring& str) {
    int result = 0;
    std::from_chars_result res;
    if (str.size() > 2) {
        if (str[0] == '0') {
            if (str[1] == 'x' || str[1] == 'X') {
                res = std::from_chars(str.data() + 2, str.data() + str.size(), result, 16);
            } else if (str[1] == 'b' || str[1] == 'B') {
                res = std::from_chars(str.data() + 2, str.data() + str.size(), result, 2);
            } else {
                res = std::from_chars(str.data(), str.data() + str.size(), result);
            }
        } else if (str[0] == '-' && str[1] == '0') {
            if (str.size() > 3) {
                if (str[2] == 'x' || str[2] == 'X') {
                    res = std::from_chars(str.data() + 3, str.data() + str.size(), result, 16);
                    result = -result;
                } else if (str[2] == 'b' || str[2] == 'B') {
                    res = std::from_chars(str.data() + 3, str.data() + str.size(), result, 2);
                    result = -result;
                } else {
                    res = std::from_chars(str.data(), str.data() + str.size(), result);
                }
            } else {
                res = std::from_chars(str.data(), str.data() + str.size(), result);
            }
        } else {
            res = std::from_chars(str.data(), str.data() + str.size(), result);
        }
    } else {
        res = std::from_chars(str.data(), str.data() + str.size(), result);
    }
    if (res.ec != std::errc() || res.ptr != str.data() + str.size()) {
        return std::nullopt;
    }
    return result;
}

double to_float(const chatastring& str) {
    double result = 0;
    auto res = std::from_chars(str.data(), str.data() + str.size(), result);
    if (res.ec != std::errc()) {
        throw ChataError(ChataErrorType::Other, "Invalid float " + str);
    }
    return result;
}

bool is_register_character(const char& c) {
    return std::islower(c) || std::isdigit(c);
}

bool is_int_register(chatastring& reg) {
    return std::find_if(registers.begin(), registers.end(), [&](const auto& r) { return (r.name == reg || r.alias == reg) && r.type == RegisterType::Integer; }) != registers.end();
}

bool is_float_register(chatastring& reg) {
    return std::find_if(registers.begin(), registers.end(), [&](const auto& r) { return (r.name == reg || r.alias == reg) && r.type == RegisterType::FloatingPoint; }) != registers.end();
}

chatastring make_base_register(const chatastring& reg) {
    auto reg_it = std::find_if(registers.begin(), registers.end(), [&](const auto& r) { return r.alias == reg; });
    if (reg_it == registers.end()) {
        return reg;
    }
    return chatastring(reg_it->name);
}

int extract_number_from_string(const chatastring& str) {
    int result = 0;
    for (auto c : str) {
        if (std::isdigit(c)) {
            result = result * 10 + (c - '0');
        }
    }
    return result;
}

int decimal_representation_of_float(float input) {
    union {
        float f;
        int i;
    } u;
    u.f = input;
    return u.i;
}

} // namespace libchata_internal
