#include "libchata.hpp"
#include <charconv>
#include <algorithm>

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
        throw ChataError(ChataErrorType::Other, "Error! Invalid integer", 0, 0);
    }
    for (auto i = temp.data(); i < res.ptr; i++) {
        result.push_back(*i);
    }
    std::cout << "result: " << result << std::endl;
    return result;
}

int to_int(const chatastring& str) {
    int result = 0;
    auto res = std::from_chars(str.data(), str.data() + str.size(), result);
    if (res.ec != std::errc()) {
        throw ChataError(ChataErrorType::Other, "Error! Invalid integer", 0, 0);
    }
    return result;
}

double to_float(const chatastring& str) {
    double result = 0;
    auto res = std::from_chars(str.data(), str.data() + str.size(), result);
    if (res.ec != std::errc()) {
        throw ChataError(ChataErrorType::Other, "Error! Invalid float", 0, 0);
    }
    return result;
}

bool is_register_character(const char& c) {
    return std::islower(c) || std::isdigit(c);
}

bool is_int_register(chatastring& reg) {
    return std::find(valid_integer_registers.begin(), valid_integer_registers.end(), reg) != valid_integer_registers.end();
}

bool is_float_register(chatastring& reg) {
    return std::find(valid_floating_point_registers.begin(), valid_floating_point_registers.end(), reg) != valid_floating_point_registers.end();
}

chatastring make_base_register(const chatastring& reg) {
    if (auto it = std::find_if(x_register_aliases.begin(), x_register_aliases.end(), [&](const auto& pair) { return pair.second == reg; }); it != x_register_aliases.end()) {
        return chatastring(it->first);
    }
    if (auto it = std::find_if(f_register_aliases.begin(), f_register_aliases.end(), [&](const auto& pair) { return pair.second == reg; }); it != f_register_aliases.end()) {
        return chatastring(it->first);
    }
    return reg;
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

