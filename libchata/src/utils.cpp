#include "libchata.hpp"
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
        throw ChataError(ErrorType::Dummy, "Error! Invalid integer", 0, 0);
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
        throw ChataError(ErrorType::Dummy, "Error! Invalid integer", 0, 0);
    }
    return result;
}

double to_float(const chatastring& str) {
    double result = 0;
    auto res = std::from_chars(str.data(), str.data() + str.size(), result);
    if (res.ec != std::errc()) {
        throw ChataError(ErrorType::Dummy, "Error! Invalid float", 0, 0);
    }
    return result;
}

void process_comments(InternalFile& file) {
    // Comment format: # begins a comment on a line, and another # ends that comment
    // Examples: # Commented out #
    // # This whole line is a comment

    bool is_comment = false;
    for (auto& c : file.data) {
        if (c == '#') {
            is_comment = !is_comment;
            c = ' ';
        }
        if (c == '\n') {
            is_comment = false;
        }
        if (is_comment) {
            c = ' ';
        }
    }
}

} // namespace libchata_internal

