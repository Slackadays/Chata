#include "libchata.hpp"
#include <cctype>
#include <iostream>
#include <algorithm>

constexpr std::string_view generated_label = "generated_code_label"; // You can generate unique labels if needed
int generated_label_num = 0;

constexpr std::string_view placeholder_temp_register = "generated_placeholder_register"; // You can generate unique labels if needed
int placeholder_temp_register_num = 0;

bool is_one_of(auto& str, auto& vec) {
    return std::find(vec.begin(), vec.end(), str) != vec.end();
}

chatastring make_label() {
    return chatastring(generated_label) + to_chatastring(generated_label_num);
}

chatastring make_label(int num) {
    return chatastring(generated_label) + to_chatastring(num);
}

chatastring make_register() {
    return chatastring(placeholder_temp_register) + to_chatastring(placeholder_temp_register_num);
}

chatastring make_register(int num) {
    return chatastring(placeholder_temp_register) + to_chatastring(num);
}

chatastring condition_to_instruction(chatastring& condition) {
    if (condition == "=") {
        return "beq";
    } else if (condition == "!=") {
        return "bne";
    } else if (condition == "<") {
        return "blt";
    } else if (condition == ">") {
        return "bgt";
    } else if (condition == "<=") {
        return "ble";
    } else if (condition == "=>") {
        return "bge";
    } else {
        throw ChataError(ErrorType::Dummy, "Error! Invalid condition", 0, 0);
    }
};

void process_ifs(auto& files) {
    /*Format: 
    if register condition register|immediate:
        code

    This becomes

    generated_label:
        code
        ret

    beq|beqz|bne|bnez|blt|bltu|bltz|bgt|bgtz|ble|blez|bge|bgez register, register|immediate, generated_label

    And "condition" can be =|!=|<|>|<=|=>
    */
   int if_indent_level = 0;
    int i_at_if_statement_start = 0;
    chatavector<chatastring> branch_code;
    chatastring operand_1;
    chatastring operand_2;
    chatastring condition;
    chatavector<chatastring> code_block;
    bool no_ifs_found = true;
   for (auto& file : files) {
    for (size_t i = 0; i < file.data.size(); i++) {
        auto c = [&](){ return file.data.at(i); };

        // Count indentation and check for "if" statement
        if (c() == '\n') {
            if_indent_level = 0;
            continue;
        } else if (std::isblank(c())) {
            if_indent_level++;
            continue;
        } else if (c() == 'i' && file.data.substr(i, 2) == "if") {
            i_at_if_statement_start = i;
            no_ifs_found = false;
            i += 2;
        } else {
            continue;
        }

        std::cout << "if indent level: " << if_indent_level << std::endl;

        // Save the condition and code block
        branch_code.clear();
        operand_1.clear();
        operand_2.clear();
        condition.clear();
        code_block.clear();

        // Analyze the condition and generate the correct branch instruction
        // First, check if both operands are registers
            while (std::isblank(c())) {
                i++;
            }
            while (std::isalnum(c()) || c() == '.') {
                operand_1.push_back(c());
                i++;
            }
            while (std::isblank(c())) {
                i++;
            }
            while (c() == '=' || c() == '!' || c() == '<' || c() == '>') {
                condition.push_back(c());
                i++;
            }
            while (std::isblank(c())) {
                i++;
            }
            while (std::isalnum(c()) || c() == '.') {
                operand_2.push_back(c());
                i++;
            }
        i++;

        int inner_if_label_num = generated_label_num;

        std::cout << "Operand 1: " << operand_1 << std::endl;
        std::cout << "Operand 2: " << operand_2 << std::endl;
        std::cout << "Condition: " << condition << std::endl;

        if (is_one_of(operand_1, valid_integer_register_names) && is_one_of(operand_2, valid_integer_register_names)) { // 
            branch_code.push_back(condition_to_instruction(condition) + " " + operand_1 + ", " + operand_2 + ", " + make_label(inner_if_label_num));
            
        } else if (is_one_of(operand_1, valid_integer_register_names) && is_integer(operand_2)) {
            branch_code.push_back("addi " + make_register() + ", zero, " + operand_2);
            branch_code.push_back(condition_to_instruction(condition) + " " + operand_1 + ", " + make_register() + ", " + make_label(inner_if_label_num));
            placeholder_temp_register_num++;
        } else if (is_integer(operand_1) && is_one_of(operand_2, valid_integer_register_names)) {
            branch_code.push_back("addi " + make_register() + ", zero, " + operand_1);
            branch_code.push_back(condition_to_instruction(condition) + " " + make_register() + ", " + operand_2 + ", " + make_label(inner_if_label_num));
            placeholder_temp_register_num++;
        } else if (is_integer(operand_1) && is_integer(operand_2)) { // Allocate two temp registers for this one
            branch_code.push_back("addi " + make_register() + ", zero, " + operand_1);
            auto temp = make_register();
            placeholder_temp_register_num++;
            branch_code.push_back("addi " + make_register() + ", zero, " + operand_2);
            placeholder_temp_register_num++;
            branch_code.push_back(condition_to_instruction(condition) + " " + temp + ", " + make_register() + ", " + make_label(inner_if_label_num));
        } else {
            throw ChataError(ErrorType::Dummy, "Error! Invalid operands", 0, 0);
        }
        generated_label_num++;

        std::cout << "Branch code: " << std::endl;
        for (auto& line : branch_code) {
            std::cout << line << std::endl;
        }
        
        // Ok, now that we have the branch instruction, we can generate the code block

        // First, add "j label" to the block to skip past it if we don't branch
        code_block.push_back(chatastring(if_indent_level, ' ') + "j " + make_label());

        // Then, we need to add the label to jump to for our inner if statement
        code_block.push_back(chatastring(if_indent_level, ' ') + make_label(inner_if_label_num) + ":");

        // Find the code block
        // Procedure: use the previously found indentation level and look for the next lines that have a higher indentation level
        // Stop when the indentation level is the same or lower than the original indentation level

        chatastring line;

        int first_line_indent_level = 0;

        while (i < file.data.size() && c() != '\n') {
            i++;
        }

        i++;
    
        for (;i < file.data.size() && std::isblank(c()); i++) {
            first_line_indent_level++;
            std::cout << "First line indent level: " << first_line_indent_level << std::endl;
        }
        
        for (;i < file.data.size() && c() != '\n'; i++) {
            line.push_back(c());
        }

        if (line.size() > 0) {
            code_block.push_back(chatastring(if_indent_level, ' ') + line);
        }

        while (i < file.data.size() && c() == '\n') {
            i++;
        }

        std::cout << "First line: " << line << std::endl;
        std::cout << "First line indent level: " << first_line_indent_level << std::endl;

        if (first_line_indent_level == if_indent_level) {
            throw ChataError(ErrorType::Dummy, "Error! Code block must be indented", 0, 0);
        }

        int this_indent_level = 0;

        while(true) {
            this_indent_level = 0;
            for (;i < file.data.size() && std::isblank(c()); i++) {
                this_indent_level++;
            }
            std::cout << "This indent level: " << this_indent_level << std::endl;
            if (this_indent_level > if_indent_level && this_indent_level < first_line_indent_level) {
                throw ChataError(ErrorType::Dummy, "Error! Code block must be indented the same as the first line", 0, 0);
            }
            if (this_indent_level <= if_indent_level) {
                break;
            }
            line.clear();
            for (;i < file.data.size() && c() != '\n'; i++) {
                line.push_back(c());
            }
            code_block.push_back(chatastring(this_indent_level, ' ') + line);
            while (i < file.data.size() && c() == '\n') {
                i++;
            }
        }

        code_block.push_back(chatastring(if_indent_level, ' ') + make_label() + ":");
        generated_label_num++;

        // Ok, now we need to overwrite the if statement starting at i_at_if_statement_start with the generated label and the code block
        // We also need to indent the code block by some nonzero amount compared to the label
        chatastring temp;
        temp.clear();

        for (auto& line : branch_code) {
            //line.insert(0, chatastring(if_indent_level, ' '));
            line.append("\n");
            temp += line;
        }

        std::cout << "Temp: " << temp << std::endl;

        file.data.replace(i_at_if_statement_start, i - i_at_if_statement_start, temp);

        i = i_at_if_statement_start + temp.size();

        for (auto& line : code_block) {
            //line.insert(0, chatastring(if_indent_level, ' '));
            line.append("\n");
            file.data.insert(i, line);
            i += line.size();
        }

        file.data.insert(i, "\n");

        if (no_ifs_found) {
            std::cout << "No more ifs found" << std::endl;
        } else {
            std::cout << "Code after processing an if: " << file.data << std::endl;
            i = 0;
        }
    }
   }
}

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

    for (const auto& reg : valid_integer_register_names) {
        if (auto pos = input.find(reg); pos != std::string::npos) {
            if (input.at(pos) != 'f') {
                if (auto search = x_register_aliases.find(reg); search != x_register_aliases.end()) {
                    used_integer_registers.emplace_back(x_register_aliases[reg]);
                } else {
                    used_integer_registers.emplace_back(reg);
                }
            }
        }
    }

    std::cout << "Used integer registers: " << std::endl;
    for (const auto& reg : used_integer_registers) {
        std::cout << reg << std::endl;
    }

    chatavector<chatastring> used_floating_point_registers;

    for (const auto& reg : valid_floating_point_register_names) {
        if (auto pos = input.find(reg); pos != std::string::npos) {
            if (input.at(pos) != 'f') {
                if (auto search = f_register_aliases.find(reg); search != f_register_aliases.end()) {
                    used_floating_point_registers.emplace_back(f_register_aliases[reg]);
                } else {
                    used_floating_point_registers.emplace_back(reg);
                }
            }
        }
    }

    std::cout << "Used floating point registers: " << std::endl;
    for (const auto& reg : used_floating_point_registers) {
        std::cout << reg << std::endl;
    }
    exit(0);

    std::string temp_register_prefix = std::string(placeholder_temp_register);
    size_t pos = 0;
    while ((pos = input.find(temp_register_prefix, pos)) != std::string::npos) {
        size_t end_pos = pos + temp_register_prefix.size();
        while (end_pos < input.size() && std::isdigit(input[end_pos])) {
            end_pos++;
        }
        input.replace(pos, end_pos - pos, "t0");
        pos += 2; // Move past the replaced "t0"
    }
}

chatastring compile_code(chatavector<InternalFile>& files) {
    auto prelude = generate_prelude();

    process_comments(files);

    process_ifs(files);

    auto postlude = generate_postlude();

    chatastring result;

    for (auto& file : files) {
        result += file.data;
    }

    replace_temp_registers(result);

    return prelude + result + postlude;
}