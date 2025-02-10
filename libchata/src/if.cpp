// SPDX-License-Identifier: MPL-2.0
#include "debug.hpp"
#include "libchata.hpp"

namespace libchata_internal {

chatastring condition_to_int_instruction(chatastring& condition) {
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
        throw ChataError(ChataErrorType::Compiler, "Invalid condition " + errorDetailOrUnknown(condition));
    }
}

chatastring condition_to_float_instruction(chatastring& condition, chatastring& result, chatastring& operand_one, chatastring& operand_two) {
    if (condition == "=") {
        return "feq.d " + result + ", " + operand_one + ", " + operand_two;
    } else if (condition == "!=") {
        return "feq.d " + result + ", " + operand_one + ", " + operand_two;
    } else if (condition == "<") {
        return "flt.d " + result + ", " + operand_one + ", " + operand_two;
    } else if (condition == ">") {
        return "flt.d " + result + ", " + operand_two + ", " + operand_one;
    } else if (condition == "<=") {
        return "fle.d " + result + ", " + operand_one + ", " + operand_two;
    } else if (condition == "=>") {
        return "fle.d " + result + ", " + operand_two + ", " + operand_one;
    } else {
        throw ChataError(ChataErrorType::Compiler, "Invalid condition " + errorDetailOrUnknown(condition));
    }
}

void process_ifs(InternalFile& file, struct compilation_context& c) {
    /*Format:
    if register1|immediate1 condition register2|immediate2:
        code

    This becomes

    beq|beqz|bne|bnez|blt|bltu|bltz|bgt|bgtz|ble|blez|bge|bgez register, register|immediate, generated_label1
    j generated_label2
    generated_label1:
        code
    generated_label2:

    And "condition" can be =|!=|<|>|<=|=>
    */
    int if_indent_level = 0;
    int i_at_if_statement_start = 0;

    c.line = 1;
    c.column = 0;
    for (size_t i = 0; i < file.data.size(); i++) {
        auto ch = [&]() {
            return file.data.at(i);
        };

        // Count indentation and check for "if" statement
        if (ch() == '\n') {
            if_indent_level = 0;
            c.line++;
            c.column = 0;
            continue;
        } else if (std::isblank(ch())) {
            if_indent_level++;
            c.column++;
            continue;
        } else if (ch() == 'i' && file.data.substr(i, 2) == "if") {
            i_at_if_statement_start = i;
            i += 2;
            c.column += 2;
        } else {
            c.column++;
            continue;
        }

        DBG(std::cout << "if indent level: " << if_indent_level << std::endl;)

        // Save the condition and code block
        chatavector<chatastring> branch_code, code_block;
        chatastring operand_1, operand_2, condition;

        // Analyze the condition and generate the correct branch instruction
        // First, check if both operands are registers
        while (std::isblank(ch())) {
            i++;
            c.column++;
        }
        while (std::isalnum(ch()) || ch() == '.') {
            operand_1.push_back(ch());
            i++;
            c.column++;
        }
        while (std::isblank(ch())) {
            i++;
            c.column++;
        }
        while (ch() == '=' || ch() == '!' || ch() == '<' || ch() == '>') {
            condition.push_back(ch());
            i++;
            c.column++;
        }
        while (std::isblank(ch())) {
            i++;
            c.column++;
        }
        while (std::isalnum(ch()) || ch() == '.') {
            operand_2.push_back(ch());
            i++;
            c.column++;
        }
        i++;
        c.column = 0;
        c.line++;

        int inner_if_label_num = c.generated_label_num;

        DBG(std::cout << "Operand 1: " << operand_1 << std::endl;)
        DBG(std::cout << "Operand 2: " << operand_2 << std::endl;)
        DBG(std::cout << "Condition: " << condition << std::endl;)

        if (is_int_register(operand_1) && is_int_register(operand_2)) { //
            branch_code.push_back(condition_to_int_instruction(condition) + " " + operand_1 + ", " + operand_2 + ", " + allocate_label(inner_if_label_num));
        } else if ((is_number(operand_1) && is_int_register(operand_2)) || (is_int_register(operand_1) && is_number(operand_2))) {
            chatastring this_reg, this_num;
            if (is_number(operand_1)) {
                this_num = operand_1;
                this_reg = operand_2;
            } else {
                this_num = operand_2;
                this_reg = operand_1;
            }
            auto temp_reg_1 = allocate_int_register(c);
            if (is_float(this_num)) {
                this_num = this_num.substr(0, this_num.find('.'));
            }
            branch_code.push_back("li " + temp_reg_1 + ", " + this_num);
            chatastring comp_reg_one, comp_reg_two;
            if (is_number(operand_1)) {
                comp_reg_one = temp_reg_1;
                comp_reg_two = this_reg;
            } else {
                comp_reg_one = this_reg;
                comp_reg_two = temp_reg_1;
            }
            branch_code.push_back(condition_to_int_instruction(condition) + " " + comp_reg_one + ", " + comp_reg_two + ", " + allocate_label(inner_if_label_num));
        } else if (is_float_register(operand_1) && is_float_register(operand_2)) {
            auto temp_reg_1 = allocate_int_register(c);
            branch_code.push_back(condition_to_float_instruction(condition, temp_reg_1, operand_1, operand_2));
            if (condition == "!=") {
                branch_code.push_back("beqz " + temp_reg_1 + ", " + allocate_label(inner_if_label_num));
            } else {
                branch_code.push_back("bnez " + temp_reg_1 + ", " + allocate_label(inner_if_label_num));
            }
        } else if ((is_float_register(operand_1) && is_number(operand_2)) || (is_number(operand_1) && is_float_register(operand_2))) {
            chatastring this_reg, this_num;
            if (is_number(operand_1)) {
                this_num = operand_1;
                this_reg = operand_2;
            } else {
                this_num = operand_2;
                this_reg = operand_1;
            }
            auto temp_reg_1 = allocate_int_register(c);
            auto temp_reg_2 = allocate_float_register(c);
            branch_code.push_back("li " + temp_reg_1 + ", " + to_chatastring(decimal_representation_of_float(to_float(this_num))));
            branch_code.push_back("fmv.w.x " + temp_reg_2 + ", " + temp_reg_1);  // Move from integer register to floating point
            branch_code.push_back("fcvt.d.s " + temp_reg_2 + ", " + temp_reg_2); // Convert from single to double
            chatastring comp_reg_one, comp_reg_two;
            if (is_number(operand_1)) {
                comp_reg_one = temp_reg_2;
                comp_reg_two = this_reg;
            } else {
                comp_reg_one = this_reg;
                comp_reg_two = temp_reg_2;
            }
            branch_code.push_back(condition_to_float_instruction(condition, temp_reg_1, comp_reg_one, comp_reg_two));
            if (condition == "!=") {
                branch_code.push_back("beqz " + temp_reg_1 + ", " + allocate_label(inner_if_label_num));
            } else {
                branch_code.push_back("bnez " + temp_reg_1 + ", " + allocate_label(inner_if_label_num));
            }
        } else if (is_number(operand_1) && is_number(operand_2)) {
            // We don't actually need to write any runtime checks, so do a quick check here and then insert a dummy branch instruction
            auto num_1 = to_num<int>(operand_1).value();
            auto num_2 = to_num<int>(operand_2).value();
            if (condition == "=") {
                if (num_1 == num_2) {
                    branch_code.push_back("beq zero, zero, " + allocate_label(inner_if_label_num));
                } else {
                    branch_code.push_back("bne zero, zero, " + allocate_label(inner_if_label_num));
                }
            } else if (condition == "!=") {
                if (num_1 != num_2) {
                    branch_code.push_back("beq zero, zero, " + allocate_label(inner_if_label_num));
                } else {
                    branch_code.push_back("bne zero, zero, " + allocate_label(inner_if_label_num));
                }
            } else if (condition == "<") {
                if (num_1 < num_2) {
                    branch_code.push_back("beq zero, zero, " + allocate_label(inner_if_label_num));
                } else {
                    branch_code.push_back("bne zero, zero, " + allocate_label(inner_if_label_num));
                }
            } else if (condition == ">") {
                if (num_1 > num_2) {
                    branch_code.push_back("beq zero, zero, " + allocate_label(inner_if_label_num));
                } else {
                    branch_code.push_back("bne zero, zero, " + allocate_label(inner_if_label_num));
                }
            } else if (condition == "<=") {
                if (num_1 <= num_2) {
                    branch_code.push_back("beq zero, zero, " + allocate_label(inner_if_label_num));
                } else {
                    branch_code.push_back("bne zero, zero, " + allocate_label(inner_if_label_num));
                }
            } else if (condition == "=>") {
                if (num_1 >= num_2) {
                    branch_code.push_back("beq zero, zero, " + allocate_label(inner_if_label_num));
                } else {
                    branch_code.push_back("bne zero, zero, " + allocate_label(inner_if_label_num));
                }
            }
        } else {
            throw ChataError(ChataErrorType::Compiler, "Invalid operands");
        }
        c.generated_label_num++;

        DBG(std::cout << "Branch code: " << std::endl;)
        for (auto& line : branch_code) {
            DBG(std::cout << line << std::endl;)
        }

        // Ok, now that we have the branch instruction, we can generate the code block

        // First, add "j label" to the block to skip past it if we don't branch
        code_block.push_back(chatastring(if_indent_level, ' ') + "j " + allocate_label(c));

        // Then, we need to add the label to jump to for our inner if statement
        code_block.push_back(chatastring(if_indent_level, ' ') + allocate_label(inner_if_label_num) + ":");

        // Find the code block
        // Procedure: use the previously found indentation level and look for the next lines that have a higher indentation level
        // Stop when the indentation level is the same or lower than the original indentation level

        chatastring line;

        int first_line_indent_level = 0;

        while (i < file.data.size() && ch() != '\n') {
            i++;
            c.column++;
        }

        i++;
        c.column = 0;
        c.line++;

        for (; i < file.data.size() && std::isblank(ch()); i++) {
            first_line_indent_level++;
            c.column++;
            DBG(std::cout << "First line indent level: " << first_line_indent_level << std::endl;)
        }

        for (; i < file.data.size() && ch() != '\n'; i++) {
            line.push_back(ch());
            c.column++;
        }

        if (line.size() > 0) {
            code_block.push_back(chatastring(if_indent_level, ' ') + line);
        }

        while (i < file.data.size() && ch() == '\n') {
            i++;
            c.column = 0;
            c.line++;
        }

        DBG(std::cout << "First line: " << line << std::endl;)
        DBG(std::cout << "First line indent level: " << first_line_indent_level << std::endl;)

        if (first_line_indent_level == if_indent_level) {
            throw ChataError(ChataErrorType::Compiler, "Code block must be indented", 0, 0);
        }

        int this_indent_level = 0;

        while (true) {
            this_indent_level = 0;
            for (; i < file.data.size() && std::isblank(ch()); i++) {
                this_indent_level++;
                c.column++;
            }
            DBG(std::cout << "This indent level: " << this_indent_level << std::endl;)
            if (this_indent_level > if_indent_level && this_indent_level < first_line_indent_level) {
                throw ChataError(ChataErrorType::Compiler, "Code block must be indented the same as the first line", 0, 0);
            }
            if (this_indent_level <= if_indent_level) {
                break;
            }
            line.clear();
            for (; i < file.data.size() && ch() != '\n'; i++) {
                line.push_back(ch());
                c.column++;
            }
            code_block.push_back(chatastring(this_indent_level, ' ') + line);
            while (i < file.data.size() && ch() == '\n') {
                i++;
                c.column = 0;
                c.line++;
            }
        }

        code_block.push_back(chatastring(if_indent_level, ' ') + allocate_label(c) + ":");
        c.generated_label_num++;

        // Ok, now we need to overwrite the if statement starting at i_at_if_statement_start with the generated label and the code block
        // We also need to indent the code block by some nonzero amount compared to the label
        chatastring temp;

        for (auto& line : branch_code) {
            line.append("\n");
            temp += line;
        }

        DBG(std::cout << "Temp: " << temp << std::endl;)

        file.data.replace(i_at_if_statement_start, i - i_at_if_statement_start, temp);

        i = i_at_if_statement_start + temp.size();

        for (auto& line : code_block) {
            line.append("\n");
            file.data.insert(i, line);
            i += line.size();
        }

        file.data.insert(i, "\n");

        i = 0;
        c.line = 0;
        c.column = 0;
    }
}

} // namespace libchata_internal