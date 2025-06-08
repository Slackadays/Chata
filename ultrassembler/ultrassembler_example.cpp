/*
An example C++ program for Ultrassembler. 
Here, you can see the different ways you can assemble RISC-V code, and you can copy this code for your own use.
*/

#include <ultrassembler.hpp>
#include <string_view>
#include <vector>

int main() {
    using enum RVInstructionSet;

    std::vector<RVInstructionSet> my_enums = {RV32I, C};

    std::string_view my_code = 
    "addi a0, a0, 10\n"
    "sub a0, a0, a1\n"
    "ret";

    auto machine_code1 = ultrassembler::assemble(my_code);

    std::span<uint8_t> machine_code2 = ultrassembler::assemble(my_code, my_enums);

    try {
        auto caught_code = ultrassembler::assemble(my_code);
    } catch (UltraError& e) {
        // Handle your error!
    }
}