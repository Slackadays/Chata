#include "libchata.hpp"
#include <bitset>

int passed_tests = 0;
int failed_tests = 0;

namespace libchata_internal {

void comp_as(std::string_view input, uint32_t expected_output) {
    auto result = assemble_code(chatastring(input));
    uint32_t result_int = 0;
    
    for (size_t i = 0; i < result.size(); i++) {
        result_int |= static_cast<uint32_t>(result[result.size() - i - 1]) << (i * 8);
    }

    if (result_int != expected_output) {
        std::cout << "❌ Test FAILED for " << input << ": expected " << std::hex << expected_output << std::dec 
        <<  " (" << std::bitset<32>(expected_output) << "), but got " << std::hex << result_int << std::dec 
        << " (" << std::bitset<32>(result_int) << ")" << std::endl;
        failed_tests++;
    } else {
        std::cout << "✅ Test passed for " << input << std::endl;
        passed_tests++;
    }
}

} // namespace libchata_internal

using namespace libchata_internal;

int main() {
    std::cout << "Running your tests..." << std::endl;

    comp_as("addi a0, a1, 10", 0x1385a500);
    comp_as("addi a0, a1, -10", 0x138565ff);
    
    std::cout << passed_tests << " tests passed, " << failed_tests << " tests failed, " << passed_tests + failed_tests << " tests total" << std::endl;
}