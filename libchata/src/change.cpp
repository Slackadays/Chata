#include "libchata.hpp"

namespace libchata_internal {

void process_changes(InternalFile& file, struct compilation_context& c) {
    /*Format:
    register1 operand register2

    This becomes

    li|addi|add|sub|mul|div register1, register2

    And "operand" can be =, +=, -=, *=, or /=
    Temporary regosters might be allocated too
    */

    c.line = 1;
    c.column = 0;

    for (size_t i = 0; i < file.data.size(); i++) {
        auto ch = [&]() {
            return file.data.at(i);
        };

        chatastring operand_1, operand_2, operation;

        // First, get the current line

        jump_to_next_line(file, c, i);

        auto this_line = read_this_line(file, c, i);

        std::cout << "This line: " << this_line << std::endl;

        // Strategy: Assume the line is in the format "register1 operand register2" and then check if it fits the template

        int j = 0;

        auto jch = [&]() {
            return this_line.at(j);
        };

        for (; j < this_line.size() && std::isblank(this_line.at(j)); j++) {}

        for (; j < this_line.size() && std::isalnum(this_line.at(j)); j++) {
            operand_1.push_back(this_line.at(j));
            c.column++;
        }

        for (; j < this_line.size() && std::isblank(this_line.at(j)); j++) {}

        for (; j < this_line.size() && (this_line.at(j) == '=' || this_line.at(j) == '+' || this_line.at(j) == '-' || this_line.at(j) == '*' || this_line.at(j) == '/'); j++) {
            operation.push_back(this_line.at(j));
            c.column++;
        }

        for (; j < this_line.size() && std::isblank(this_line.at(j)); j++) {}

        for (; j < this_line.size() && std::isalnum(this_line.at(j)); j++) {
            operand_2.push_back(this_line.at(j));
            c.column++;
        }

        std::cout << "Operand 1: " << operand_1 << std::endl;
        std::cout << "Operand 2: " << operand_2 << std::endl;
        std::cout << "Operation: " << operation << std::endl;

        // Now check if this line fits the template

        if (operand_1.empty() || operand_2.empty() || operation.empty() || j < this_line.size()) {
            std::cout << "This line doesn't fit the template" << std::endl;
            continue;
        }

        std::cout << "Found a change operation: " << operand_1 << " " << operation << " " << operand_2 << std::endl;

        // Now, generate the correct instruction

        chatavector<chatastring> lines;

        if (is_one_of(operand_1, valid_integer_registers) && is_one_of(operand_2, valid_integer_registers)) {
            if (operation == "=") {
            lines.push_back("mv " + operand_1 + ", " + operand_2);
            } else if (operation == "+=") {
            lines.push_back("add " + operand_1 + ", " + operand_1 + ", " + operand_2);
            } else if (operation == "-=") {
            lines.push_back("sub " + operand_1 + ", " + operand_1 + ", " + operand_2);
            } else if (operation == "*=") {
            lines.push_back("mul " + operand_1 + ", " + operand_1 + ", " + operand_2);
            } else if (operation == "/=") {
            lines.push_back("div " + operand_1 + ", " + operand_1 + ", " + operand_2);
            }
        } else if ((is_number(operand_1) && is_one_of(operand_2, valid_integer_registers)) || (is_one_of(operand_1, valid_integer_registers) && is_number(operand_2))) {
            chatastring this_reg, this_num;
            if (is_number(operand_1)) {
                this_num = operand_1;
                this_reg = operand_2;
            } else {
                this_num = operand_2;
                this_reg = operand_1;
            }
            if (is_float(this_num)) {
                this_num = to_chatastring(static_cast<int>(to_float(this_num)));
            }
            if (operation == "=") {
                lines.push_back("li " + this_reg + ", " + this_num);
            } else if (operation == "+=") {
                auto temp_reg_1 = allocate_int_register(c);
                lines.push_back("li " + temp_reg_1 + ", " + this_num);
                lines.push_back("add " + this_reg + ", " + this_reg + ", " + temp_reg_1);
            } else if (operation == "-=") {
                auto temp_reg_1 = allocate_int_register(c);
                lines.push_back("li " + temp_reg_1 + ", " + this_num);
                lines.push_back("sub " + this_reg + ", " + this_reg + ", " + temp_reg_1);
            } else if (operation == "*=") {
                auto temp_reg_1 = allocate_int_register(c);
                lines.push_back("li " + temp_reg_1 + ", " + this_num);
                lines.push_back("mul " + this_reg + ", " + this_reg + ", " + temp_reg_1);
            } else if (operation == "/=") {
                auto temp_reg_1 = allocate_int_register(c);
                lines.push_back("li " + temp_reg_1 + ", " + this_num);
                lines.push_back("div " + this_reg + ", " + this_reg + ", " + temp_reg_1);
            }
        } else if (is_one_of(operand_1, valid_floating_point_registers) && is_one_of(operand_2, valid_floating_point_registers)) {
            if (operation == "=") {
                lines.push_back("fmv.d " + operand_1 + ", " + operand_2);
            } else if (operation == "+=") {
                lines.push_back("fadd.d " + operand_1 + ", " + operand_1 + ", " + operand_2);
            } else if (operation == "-=") {
                lines.push_back("fsub.d " + operand_1 + ", " + operand_1 + ", " + operand_2);
            } else if (operation == "*=") {
                lines.push_back("fmul.d " + operand_1 + ", " + operand_1 + ", " + operand_2);
            } else if (operation == "/=") {
                lines.push_back("fdiv.d " + operand_1 + ", " + operand_1 + ", " + operand_2);
            }
        } else if (is_one_of(operand_1, valid_floating_point_registers) && is_number(operand_2)) {
            auto temp_reg_1 = allocate_int_register(c);
            auto temp_reg_2 = allocate_float_register(c);
            lines.push_back("li " + temp_reg_1 + ", " + to_chatastring(decimal_representation_of_float(to_float(operand_2))));
            if (operation == "=") {
                lines.push_back("fmv.s.x " + operand_1 + ", " + temp_reg_1);
                lines.push_back("fcvt.d.s " + operand_1 + ", " + operand_1);
            } else if (operation == "+=") {
                lines.push_back("fmv.s.x " + temp_reg_2 + ", " + temp_reg_1);
                lines.push_back("fcvt.d.s " + temp_reg_2 + ", " + temp_reg_2);
                lines.push_back("fadd.d " + operand_1 + ", " + operand_1 + ", " + temp_reg_2);
            } else if (operation == "-=") {
                lines.push_back("fmv.s.x " + temp_reg_2 + ", " + temp_reg_1);
                lines.push_back("fcvt.d.s " + temp_reg_2 + ", " + temp_reg_2);
                lines.push_back("fsub.d " + operand_1 + ", " + operand_1 + ", " + temp_reg_2);
            } else if (operation == "*=") {
                lines.push_back("fmv.s.x " + temp_reg_2 + ", " + temp_reg_1);
                lines.push_back("fcvt.d.s " + temp_reg_2 + ", " + temp_reg_2);
                lines.push_back("fmul.d " + operand_1 + ", " + operand_1 + ", " + temp_reg_2);
            } else if (operation == "/=") {
                lines.push_back("fmv.s.x " + temp_reg_2 + ", " + temp_reg_1);
                lines.push_back("fcvt.d.s " + temp_reg_2 + ", " + temp_reg_2);
                lines.push_back("fdiv.d " + operand_1 + ", " + operand_1 + ", " + temp_reg_2);
            }
        } else {
            std::cout << "Not supported yet" << std::endl;
        }

        // Replace the original line with the generated instructions

        chatastring temp;

        for (auto& line : lines) {
            line.append("\n");
            temp += line;
        }

        file.data.replace(i - this_line.size(), this_line.size(), temp);

    }
}

} // namespace libchata_internal