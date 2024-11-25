#include "libchata.hpp"

int generated_label_num = 0;

int placeholder_temp_integer_register_num = 0;

int placeholder_temp_floating_point_register_num = 0;

bool is_one_of(auto& str, auto& vec) {
    return std::find(vec.begin(), vec.end(), str) != vec.end();
}

chatastring allocate_label() {
    return chatastring(generated_label) + to_chatastring(generated_label_num);
}

chatastring allocate_label(int num) {
    return chatastring(generated_label) + to_chatastring(num);
}

chatastring allocate_int_register() {
    auto res = chatastring(placeholder_temp_integer_register) + to_chatastring(placeholder_temp_integer_register_num);
    placeholder_temp_integer_register_num++;
    return res;
}

chatastring allocate_int_register(int num) {
    return chatastring(placeholder_temp_integer_register) + to_chatastring(num);
}

chatastring allocate_float_register() {
    auto res = chatastring(placeholder_temp_floating_point_register) + to_chatastring(placeholder_temp_floating_point_register_num);
    placeholder_temp_floating_point_register_num++;
    return res;
}

chatastring allocate_float_register(int num) {
    return chatastring(placeholder_temp_floating_point_register) + to_chatastring(num);
}

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
        throw ChataError(ErrorType::Dummy, "Error! Invalid condition", 0, 0);
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
        throw ChataError(ErrorType::Dummy, "Error! Invalid condition", 0, 0);
    }
}

void process_ifs(chatavector<InternalFile>& files) {
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
    chatavector<chatastring> branch_code, code_block;
    chatastring operand_1, operand_2, condition;
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

        if (is_one_of(operand_1, valid_integer_registers) && is_one_of(operand_2, valid_integer_registers)) { // 
            branch_code.push_back(condition_to_int_instruction(condition) + " " + operand_1 + ", " + operand_2 + ", " + allocate_label(inner_if_label_num));
        } else if ((is_number(operand_1) && is_one_of(operand_2, valid_integer_registers)) || (is_one_of(operand_1, valid_integer_registers) && is_number(operand_2))) {
            chatastring this_reg, this_num;
            if (is_number(operand_1)) {
                this_num = operand_1;
                this_reg = operand_2;
            } else {
                this_num = operand_2;
                this_reg = operand_1;
            }
            auto temp_reg_1 = allocate_int_register();
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
        } else if (is_one_of(operand_1, valid_floating_point_registers) && is_one_of(operand_2, valid_floating_point_registers)) {
            auto temp_reg_1 = allocate_int_register();
            branch_code.push_back(condition_to_float_instruction(condition, temp_reg_1, operand_1, operand_2));
            if (condition == "!=") {
                branch_code.push_back("beqz " + temp_reg_1 + ", " + allocate_label(inner_if_label_num));
            } else {
                branch_code.push_back("bnez " + temp_reg_1 + ", " + allocate_label(inner_if_label_num));
            }
        } else if ((is_one_of(operand_1, valid_floating_point_registers) && is_number(operand_2)) || (is_number(operand_1) && is_one_of(operand_2, valid_floating_point_registers))) {
            chatastring this_reg, this_num;
            if (is_number(operand_1)) {
                this_num = operand_1;
                this_reg = operand_2;
            } else {
                this_num = operand_2;
                this_reg = operand_1;
            }
            auto temp_reg_1 = allocate_int_register();
            auto temp_reg_2 = allocate_float_register();
            float temp = to_float(this_num); // Only floats are supported here for now
            std::cout << "Temp: " << temp << std::endl;
            union {
                float f;
                int i;
            } u;
            u.f = temp;
            std::cout << "u.i = " << u.i << std::endl;
            chatastring decimal_representation = to_chatastring(u.i);
            std::cout << "Decimal representation: " << decimal_representation << std::endl;
            branch_code.push_back("li " + temp_reg_1 + ", " + decimal_representation);
            branch_code.push_back("fmv.s.x " + temp_reg_2 + ", " + temp_reg_1); // Move from integer register to floating point
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
            auto num_1 = to_int(operand_1);
            auto num_2 = to_int(operand_2);
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
            throw ChataError(ErrorType::Dummy, "Error! Invalid operands", 0, 0);
        }
        generated_label_num++;

        std::cout << "Branch code: " << std::endl;
        for (auto& line : branch_code) {
            std::cout << line << std::endl;
        }
        
        // Ok, now that we have the branch instruction, we can generate the code block

        // First, add "j label" to the block to skip past it if we don't branch
        code_block.push_back(chatastring(if_indent_level, ' ') + "j " + allocate_label());

        // Then, we need to add the label to jump to for our inner if statement
        code_block.push_back(chatastring(if_indent_level, ' ') + allocate_label(inner_if_label_num) + ":");

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

        code_block.push_back(chatastring(if_indent_level, ' ') + allocate_label() + ":");
        generated_label_num++;

        // Ok, now we need to overwrite the if statement starting at i_at_if_statement_start with the generated label and the code block
        // We also need to indent the code block by some nonzero amount compared to the label
        chatastring temp;
        temp.clear();

        for (auto& line : branch_code) {
            line.append("\n");
            temp += line;
        }

        std::cout << "Temp: " << temp << std::endl;

        file.data.replace(i_at_if_statement_start, i - i_at_if_statement_start, temp);

        i = i_at_if_statement_start + temp.size();

        for (auto& line : code_block) {
            line.append("\n");
            file.data.insert(i, line);
            i += line.size();
        }

        file.data.insert(i, "\n");

        i = 0;
    }
   }
}