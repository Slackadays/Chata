#include "libchata.hpp"
#include <charconv>

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

chatastring to_chatastring(int num) {
    if (num == 0) {
        return "0";
    }
    chatastring str;
    while (num) {
        str.push_back('0' + num % 10);
        num /= 10;
    }
    std::reverse(str.begin(), str.end());
    return str;
}

int to_int(const chatastring& str) {
    int result = 0;
    auto res = std::from_chars(str.data(), str.data() + str.size(), result);
    if (res.ec != std::errc()) {
        throw ChataError(ErrorType::Dummy, "Error! Invalid integer", 0, 0);
    }
    return result;
}

void process_comments(chatavector<InternalFile>& files) {
    // Comment format: # begins a comment on a line, and another # ends that comment
    // Examples: # Commented out #
    // # This whole line is a comment

    for (auto& file : files) { // Modify data in-place (make whitespace)
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
}