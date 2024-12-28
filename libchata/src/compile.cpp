// SPDX-License-Identifier: MPL-2.0
#include "debug.hpp"
#include "libchata.hpp"
#include "registers.hpp"
#include <algorithm>
#include <cctype>
#include <chrono>
#include <iostream>

namespace libchata_internal {

chatastring generate_prelude() {
    return "fld fa0, 0(a0)\n"
           "fld fa1, 8(a0)\n"
           "fld fa2, 16(a0)\n"
           "fld fa3, 24(a0)\n";
}

chatastring generate_postlude() {
    return "\nfsd fa0, 0(a0)\n"
           "fsd fa1, 8(a0)\n"
           "fsd fa2, 16(a0)\n"
           "fsd fa3, 24(a0)\n"
           "ret";
}

chatastring allocate_label(struct compilation_context& c) {
    return chatastring(generated_label_prefix) + to_chatastring(c.generated_label_num);
}

chatastring allocate_label(int num) {
    return chatastring(generated_label_prefix) + to_chatastring(num);
}

chatastring allocate_int_register(struct compilation_context& c) {
    auto res = chatastring(placeholder_temp_integer_register) + to_chatastring(c.placeholder_temp_integer_register_num);
    c.placeholder_temp_integer_register_num++;
    return res;
}

chatastring allocate_int_register(int num) {
    return chatastring(placeholder_temp_integer_register) + to_chatastring(num);
}

chatastring allocate_float_register(struct compilation_context& c) {
    auto res = chatastring(placeholder_temp_floating_point_register) + to_chatastring(c.placeholder_temp_floating_point_register_num);
    c.placeholder_temp_floating_point_register_num++;
    return res;
}

chatastring allocate_float_register(int num) {
    return chatastring(placeholder_temp_floating_point_register) + to_chatastring(num);
}

void jump_to_next_line(InternalFile& file, struct compilation_context& c, size_t& i) {
    while (i < file.data.size() && file.data.at(i) != '\n') {
        i++;
    }
    while (i < file.data.size() && file.data.at(i) == '\n') {
        c.line++;
        i++;
    }
    c.column = 0;
}

chatastring read_this_line(InternalFile& file, struct compilation_context& c, size_t& i) {
    chatastring line;
    while (i < file.data.size() && file.data.at(i) != '\n') {
        line += file.data.at(i);
        DBG(std::cout << "Line: " << line << std::endl;)
        i++;
        c.column++;
    }
    return line;
}

void replace_temp_registers(chatastring& input) {
    // First, search for all integer registers already present and mark those as non-candidates.
    chatavector<chatastring> used_integer_registers;

    for (const auto& reg : valid_integer_registers) {
        for (auto pos = input.find(reg); pos != std::string::npos; pos = input.find(reg, pos + 1)) {
            if (pos == 0 || input.at(pos - 1) != 'f') {
                auto it = std::find_if(registers.begin(), registers.end(), [&](const auto& r) { return r.name == reg && r.type == RegisterType::Integer; });
                if (it != registers.end()) {
                    used_integer_registers.emplace_back(it->alias);
                } else {
                    used_integer_registers.emplace_back(reg);
                }
                break;
            }
        }
    }

    DBG(std::cout << "Used integer registers: " << std::endl;)
    for (const auto& reg : used_integer_registers) {
        DBG(std::cout << reg << std::endl;)
    }

    chatavector<chatastring> used_floating_point_registers;

    for (const auto& reg : valid_floating_point_registers) {
        for (auto pos = input.find(reg); pos != std::string::npos; pos = input.find(reg, pos + 1)) {
            auto it = std::find_if(registers.begin(), registers.end(), [&](const auto& r) { return r.name == reg && r.type == RegisterType::FloatingPoint; });
            if (it != registers.end()) {
                used_floating_point_registers.emplace_back(it->alias);
            } else {
                used_floating_point_registers.emplace_back(reg);
            }
            break;
        }
    }

    DBG(std::cout << "Used floating point registers: " << std::endl;)
    for (const auto& reg : used_floating_point_registers) {
        DBG(std::cout << reg << std::endl;)
    }

    auto integer_reg_eligible = [&](const auto& reg) {
        return std::find(used_integer_registers.begin(), used_integer_registers.end(), reg) == used_integer_registers.end();
    };

    auto floating_point_reg_eligible = [&](const auto& reg) {
        return std::find(used_floating_point_registers.begin(), used_floating_point_registers.end(), reg) == used_floating_point_registers.end();
    };

    // Search for temporary register labels

    chatavector<std::pair<int, chatastring>> temp_integer_register_id_to_replacement;

    for (auto pos = input.find(placeholder_temp_integer_register); pos != std::string::npos; pos = input.find(placeholder_temp_integer_register, pos + 1)) {
        int id = 0;
        chatastring id_str;
        for (auto i = pos + placeholder_temp_integer_register.size(); i < input.size(); i++) {
            if (std::isdigit(input.at(i))) {
                id_str.push_back(input.at(i));
            } else {
                break;
            }
        }
        if (auto num = to_int(id_str); num.has_value()) {
            id = num.value();
        } else {
            throw ChataError(ChataErrorType::Compiler, "Invalid temporary integer register ID " + id_str);
        }
        DBG(std::cout << "Found temp register: " << id << std::endl;)

        chatastring replacement;

        // Check if we can find a suitable replacement register by looking in temp_integer_register_id_to_replacement first
        for (auto& pair : temp_integer_register_id_to_replacement) {
            if (pair.first == id) {
                replacement = pair.second;
                break;
            }
        }

        if (!replacement.empty()) {
            DBG(std::cout << "Replacement: " << replacement << std::endl;)
            input.replace(pos, placeholder_temp_integer_register.size() + id_str.size(), replacement);
            used_integer_registers.emplace_back(replacement);
            continue;
        }

        // Now for each ID, we need to find a suitable replacement register
        for (const auto& reg : integer_register_replacement_priority_list) {
            if (integer_reg_eligible(reg)) {
                replacement = reg;
                break;
            }
        }

        DBG(std::cout << "Replacement: " << replacement << std::endl;)

        temp_integer_register_id_to_replacement.emplace_back(id, replacement);

        used_integer_registers.emplace_back(replacement);

        input.replace(pos, placeholder_temp_integer_register.size() + id_str.size(), replacement);
    }

    chatavector<std::pair<int, chatastring>> temp_floating_point_register_id_to_replacement;

    for (auto pos = input.find(placeholder_temp_floating_point_register); pos != std::string::npos; pos = input.find(placeholder_temp_floating_point_register, pos + 1)) {
        int id = 0;
        chatastring id_str;
        for (auto i = pos + placeholder_temp_floating_point_register.size(); i < input.size(); i++) {
            if (std::isdigit(input.at(i))) {
                id_str.push_back(input.at(i));
            } else {
                break;
            }
        }
        if (auto num = to_int(id_str); num.has_value()) {
            id = num.value();
        } else {
            throw ChataError(ChataErrorType::Compiler, "Invalid temporary floating point register ID " + id_str);
        }
        DBG(std::cout << "Found temp register: " << id << std::endl;)

        chatastring replacement;

        // Check if we can find a suitable replacement register by looking in temp_floating_point_register_id_to_replacement first
        for (auto& pair : temp_floating_point_register_id_to_replacement) {
            if (pair.first == id) {
                replacement = pair.second;
                break;
            }
        }

        if (!replacement.empty()) {
            DBG(std::cout << "Replacement: " << replacement << std::endl;)
            input.replace(pos, placeholder_temp_floating_point_register.size() + id_str.size(), replacement);
            used_floating_point_registers.emplace_back(replacement);
            continue;
        }

        // Now for each ID, we need to find a suitable replacement register
        for (const auto& reg : floating_point_register_replacement_priority_list) {
            if (floating_point_reg_eligible(reg)) {
                replacement = reg;
                break;
            }
        }

        DBG(std::cout << "Replacement: " << replacement << std::endl;)

        temp_floating_point_register_id_to_replacement.emplace_back(id, replacement);

        used_floating_point_registers.emplace_back(replacement);

        input.replace(pos, placeholder_temp_floating_point_register.size() + id_str.size(), replacement);
    }
}

void process_comments(InternalFile& file) {
    // Chata comment format: # begins a comment on a line, and another # ends that comment
    // If a line begins with a #, no subsequent # matters
    // Examples: This is not commented out, but # this is #
    // # This whole line is a comment
    // Regular RISC-V assemblers will already handle the whole line case, so we only need to think about
    // the partial line one

    bool in_comment = false;
    bool partial_comment_possible = false;
    for (size_t i = 0; i < file.data.size(); i++) {
        auto ch = [&]() {
            return file.data.at(i);
        };
        if (std::isspace(ch()) && !partial_comment_possible) {
            continue;
        }
        if (std::isprint(ch()) && ch() != '#' && !in_comment) {
            partial_comment_possible = true;
        }
        if (std::isprint(ch()) && ch() == '#' && !partial_comment_possible) {
            for (; i < file.data.size() && ch() != '\n'; i++) {
                file.data.at(i) = ' ';
            }
            continue;
        }
        if (ch() == '#' && partial_comment_possible) {
            in_comment = !in_comment;
            file.data.at(i) = ' ';
        }
        if (ch() == '\n') {
            partial_comment_possible = false;
            in_comment = false;
        }
        if (in_comment) {
            file.data.at(i) = ' ';
        }
    }
}

chatastring compile_code(chatavector<InternalFile>& files) {
    auto then = std::chrono::high_resolution_clock::now();

    compilation_context c;

    auto prelude = generate_prelude();

    for (auto& file : files) {
        process_comments(file);

        process_ifs(file, c);

        process_changes(file, c);
    }

    auto postlude = generate_postlude();

    chatastring result;

    for (auto& file : files) {
        result += file.data;
    }

    result = prelude + result + postlude;

    // DBG(std::cout << "Result: " << result << std::endl;)

    replace_temp_registers(result);

    auto now = std::chrono::high_resolution_clock::now();

    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(now - then);

    DBG(std::cout << "Compilation took " << duration.count() << " microseconds" << std::endl;)

    DBG(std::cout << "Result: " << result << std::endl;)

    // exit(0);

    return result;
}

} // namespace libchata_internal