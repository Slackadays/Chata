#include "libchata.hpp"
#include <algorithm>
#include <cctype>
#include <chrono>
#include <iostream>

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

void replace_temp_registers(chatastring& input) {
    // First, search for all integer registers already present and mark those as non-candidates.
    chatavector<chatastring> used_integer_registers;

    for (const auto& reg : valid_integer_registers) {
        for (auto pos = input.find(reg); pos != std::string::npos; pos = input.find(reg, pos + 1)) {
            if (pos == 0 || input.at(pos - 1) != 'f') {
                auto it = std::find_if(x_register_aliases.begin(), x_register_aliases.end(), [&](const auto& pair) { return pair.first == reg; });
                if (it != x_register_aliases.end()) {
                    used_integer_registers.emplace_back(it->second);
                } else {
                    used_integer_registers.emplace_back(reg);
                }
                break;
            }
        }
    }

    std::cout << "Used integer registers: " << std::endl;
    for (const auto& reg : used_integer_registers) {
        std::cout << reg << std::endl;
    }

    chatavector<chatastring> used_floating_point_registers;

    for (const auto& reg : valid_floating_point_registers) {
        for (auto pos = input.find(reg); pos != std::string::npos; pos = input.find(reg, pos + 1)) {
            auto it = std::find_if(f_register_aliases.begin(), f_register_aliases.end(), [&](const auto& pair) { return pair.first == reg; });
            if (it != f_register_aliases.end()) {
                used_floating_point_registers.emplace_back(it->second);
            } else {
                used_floating_point_registers.emplace_back(reg);
            }
            break;
        }
    }

    std::cout << "Used floating point registers: " << std::endl;
    for (const auto& reg : used_floating_point_registers) {
        std::cout << reg << std::endl;
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
        id = to_int(id_str);
        std::cout << "Found temp register: " << id << std::endl;

        chatastring replacement;

        // Check if we can find a suitable replacement register by looking in temp_integer_register_id_to_replacement first
        for (auto& pair : temp_integer_register_id_to_replacement) {
            if (pair.first == id) {
                replacement = pair.second;
                break;
            }
        }

        if (!replacement.empty()) {
            std::cout << "Replacement: " << replacement << std::endl;
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

        std::cout << "Replacement: " << replacement << std::endl;

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
        id = to_int(id_str);
        std::cout << "Found temp register: " << id << std::endl;

        chatastring replacement;

        // Check if we can find a suitable replacement register by looking in temp_floating_point_register_id_to_replacement first
        for (auto& pair : temp_floating_point_register_id_to_replacement) {
            if (pair.first == id) {
                replacement = pair.second;
                break;
            }
        }

        if (!replacement.empty()) {
            std::cout << "Replacement: " << replacement << std::endl;
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

        std::cout << "Replacement: " << replacement << std::endl;

        temp_floating_point_register_id_to_replacement.emplace_back(id, replacement);

        used_floating_point_registers.emplace_back(replacement);

        input.replace(pos, placeholder_temp_floating_point_register.size() + id_str.size(), replacement);
    }
}

chatastring compile_code(chatavector<InternalFile>& files) {
    auto then = std::chrono::high_resolution_clock::now();

    auto prelude = generate_prelude();

    for (auto& file : files) {
        process_comments(file);

        process_ifs(file);
    }

    auto postlude = generate_postlude();

    chatastring result;

    for (auto& file : files) {
        result += file.data;
    }

    result = prelude + result + postlude;

    // std::cout << "Result: " << result << std::endl;

    replace_temp_registers(result);

    auto now = std::chrono::high_resolution_clock::now();

    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(now - then);

    std::cout << "Compilation took " << duration.count() << " microseconds" << std::endl;

    std::cout << "Result: " << result << std::endl;

    // exit(0);

    return result;
}