#include "libchata.hpp"
#include <bitset>

int passed_tests = 0;
int failed_tests = 0;

namespace libchata_internal {

void as(std::string_view input, uint32_t expected_output) {
    chatastring result;
    try {
     result = assemble_code(chatastring(input));
    } catch (ChataError& e) {
        std::cout << e.what() << std::endl;
        failed_tests++;
        return;
    }
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

    as("lui a0, 12345", 0x37950303);
    as("auipc t0, 100", 0x97420600);
    as("jal zero, 4", 0x6f004000);
    as("jalr zero, 4(a0)", 0x67004500);
    as("beq s1, t6, 40", 0x6384f403);
    as("bne s0, a2, 36", 0x6312c402);
    as("blt t4, t5, 16", 0x6398ee01);
    as("bge t3, t2, 12", 0x63467e00);
    as("bltu t1, t0, 8", 0x63545300);
    as("bgeu s2, s3, 4", 0x63623901);
    as("lb a0, 0(a1)", 0x03850500);
    as("lh a1, 0(a2)", 0x83150600);
    as("lw a2, 0(a3)", 0x03a60600);
    as("lbu a3, 0(a4)", 0x83460700);
    as("lhu a4, 0(a5)", 0x03d70700);
    as("sb a5, 0(a6)", 0x2300f800);
    as("sh a6, 0(a7)", 0x23900801);
    as("sw a7, 0(s0)", 0x23201401);
    as("addi a0, a1, 10", 0x1385a500);
    as("addi a0, a1, -10", 0x138565ff);
    as("slti a0, a1, 10", 0x13a5a500);
    as("sltiu a4, a4, 10", 0x1337a700);
    as("srli a2, a2, 8", 0x13568600);
    as("srai a3, a3, 16", 0x93d60641);
    as("add a0, a1, a2", 0x3385c500);
    as("sub a1, a2, a3", 0xb305d640);
    as("sll a2, a3, a4", 0x3396e600);
    as("slt a3, a4, a5", 0xb326f700);
    as("sltu a4, a5, a6", 0x33b70701);
    as("xor a5, a6, a7", 0xb3471801);
    as("srl a6, a7, t0", 0x33d85800);
    as("sra a7, t0, t1", 0xb3d86240);
    as("or t0, t1, t2", 0xb3627300);
    as("and t1, t2, t3", 0x33f3c301);
    as("fence rw, rw", 0x0f003003);
    as("fence.tso", 0x0f003083);
    as("pause", 0x0f000001);
    as("ecall", 0x73000000);
    
    as("lwu a0, 0(a1)", 0x03e50500);
    as("ld s0, 0(s1)", 0x03b40400);
    as("sd s1, 0(s2)", 0x23309900);
    as("addiw s2, s3, 10", 0x1b89a900);
    as("slliw s3, s4, 8", 0x9b198a00);
    as("srliw s4, s5, 16", 0x1bda0a01);
    as("sraiw s5, s6, 24", 0x9b5a8b41);

    std::cout << passed_tests << " tests passed, " << failed_tests << " tests failed, " << passed_tests + failed_tests << " tests total" << std::endl;

    if (passed_tests == passed_tests + failed_tests) {
        std::cout << "Yay, all your tests passed!" << std::endl;
    }
}