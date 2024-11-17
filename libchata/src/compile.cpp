#include "libchata.hpp"
#include <cctype>
#include <iostream>
#include <algorithm>

int label_num = 0;
constexpr std::string_view generated_label = "generated_label"; // You can generate unique labels if needed
int generated_label_num = 0;
constexpr std::string_view placeholder_temp_register = "internal_placeholder_register_do_not_use"; // You can generate unique labels if needed
int needed_temp_registers = 0;

void process_comments(auto& files) {
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

bool is_one_of(auto& str, auto& vec) {
    return std::find(vec.begin(), vec.end(), str) != vec.end();
}

chatastring to_chatastring(int& num) {
    chatastring str;
    while (num) {
        str.push_back('0' + num % 10);
        num /= 10;
    }
    std::reverse(str.begin(), str.end());
    return str;
}

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
    chatastring branch_instruction;
    chatastring operand_1;
    chatastring operand_2;
    chatastring condition;
    chatastring code_block;
   for (auto& file : files) {
    for (size_t i = 0; i < file.data.size(); i++) {
        auto c = [&](){ return file.data.at(i); };

        // Count indentation and check for "if" statement
        if (c() == '\n') {
            if_indent_level = 0;
            continue;
        } else if (std::isspace(c())) {
            if_indent_level++;
            continue;
        } else if (c() == 'i' && file.data.substr(i, 2) == "if") {
            i_at_if_statement_start = i;
            i += 2;
        } else {
            continue;
        }

        // Save the condition and code block
        branch_instruction.clear();
        operand_1.clear();
        operand_2.clear();
        condition.clear();
        code_block.clear();

        // Analyze the condition and generate the correct branch instruction
        // First, check if both operands are registers
            while (std::isspace(c())) {
                i++;
            }
            while (std::isalnum(c())) {
                operand_1.push_back(c());
                i++;
            }
            while (std::isspace(c())) {
                i++;
            }
            while (c() == '=' || c() == '!' || c() == '<' || c() == '>') {
                condition.push_back(c());
                i++;
            }
            while (std::isspace(c())) {
                i++;
            }
            while (std::isalnum(c())) {
                operand_2.push_back(c());
                i++;
            }
        std::cout << "Operand 1: " << operand_1 << std::endl;
        std::cout << "Operand 2: " << operand_2 << std::endl;
        std::cout << "Condition: " << condition << std::endl;

        if (is_one_of(operand_1, valid_register_names) && is_one_of(operand_2, valid_register_names)) {
            if (condition == "=") {
                branch_instruction = "beq";
            } else if (condition == "!=") {
                branch_instruction = "bne";
            } else if (condition == "<") {
                branch_instruction = "blt";
            } else if (condition == ">") {
                branch_instruction = "bgt";
            } else if (condition == "<=") {
                branch_instruction = "ble";
            } else if (condition == ">=") {
                branch_instruction = "bge";
            }
            branch_instruction += " " + operand_1 + ", " + operand_2 + ", " + chatastring(generated_label) + to_chatastring(generated_label_num);
            generated_label_num++;
        }
        std::cout << "Branch instruction: " << branch_instruction << std::endl;

        // Ok, now that we have the branch instruction, we can generate the code block

        // Find the code block
        // Procedure: use the previously found indentation level and look for the next lines that have a higher indentation level
        // Stop when the indentation level is the same or lower than the original indentation level

        int first_line_indent_level = 0;

    
        while (true) {
            while (i < file.data.size() && c() != '\n') {
            i++;
        }
        i++;
            // First get to the start of the next line
            
        if (i >= file.data.size()) {
            break;
        }

        // Now we are at the start of the next line
        int this_indent_level = 0;
        if (first_line_indent_level == 0) {
            while (std::isspace(c())) {
                first_line_indent_level++;
                i++;
            }
            if (first_line_indent_level <= if_indent_level) {
                std::cout << "Error! Code block must be indented more than the if statement" << std::endl;
                exit(1);
            }
            this_indent_level = first_line_indent_level;
            
        } else {
            while (std::isspace(c())) {
                this_indent_level++;
                i++;
            }
        }
        
        std::cout << "This indent level: " << this_indent_level << std::endl;
        std::cout << "First line indent level: " << first_line_indent_level << std::endl;
        if (this_indent_level >= first_line_indent_level) {
            // This is the start of the code block
            while (i < file.data.size() && c() != '\n') {
                std::cout << "Adding character to code block: " << c() << std::endl;
                code_block.push_back(c());
                i++;
            }
            code_block.push_back('\n');
        } else {
            // This is the end of the code block
            break;
        }
        }
        std::cout << "Code block: " << code_block << std::endl;

        // Now add an idnentation of 4 spaces to each line of the code block
        code_block.insert(0, "    ");
        for (size_t i = 0; i < code_block.size(); i++) {
            if (code_block.at(i) == '\n') {
                code_block.insert(i + 1, "    ");
            }
        }
        code_block.append("ret\n");

        // Ok, now we need to overwrite the if statement starting at i_at_if_statement_start with the generated label and the code block
        // We also need to indent the code block by some nonzero amount compared to the label
        // We also need to add a ret instruction at the end of the code block
        file.data.replace(i_at_if_statement_start, i - i_at_if_statement_start, chatastring(generated_label) + ":\n" + code_block + branch_instruction + "\n");

        i += branch_instruction.size() + 1;

    }
   }
}

void compile_code(chatavector<InternalFile>& files) {
    process_comments(files);


    process_ifs(files);
}