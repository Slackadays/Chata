#include "libchata.hpp"
#include <bitset>

int passed_tests = 0;
int failed_tests = 0;

namespace libchata_internal {

void as(std::string_view input, uint32_t expected_output) {
    chatavector<uint8_t> result;
    try {
        result = assemble_code(input);
    } catch (ChataError& e) {
        std::cout << e.what() << std::endl;
        std::cout << "❌ Test FAILED for " << input << ": expected " << std::hex << expected_output << std::dec << " (" << std::bitset<32>(expected_output) << "), but got an error" << std::endl;
        failed_tests++;
        return;
    }
    uint32_t result_int = 0;

    for (size_t i = 0; i < result.size(); i++) {
        result_int |= static_cast<uint32_t>(result[result.size() - i - 1]) << (i * 8); // Assign everything in reverse
    }

    if (result_int != expected_output) {
        std::cout << "❌ Test FAILED for " << input << ": expected " << std::hex << expected_output << std::dec << " (" << std::bitset<32>(expected_output) << "), but got " << std::hex << result_int
                  << std::dec << " (" << std::bitset<32>(result_int) << ")" << std::endl;
        failed_tests++;
    } else {
        std::cout << "✅ Test passed for " << input << std::endl;
        passed_tests++;
    }
}

void as(std::string_view input, std::vector<uint8_t> expected_output) {
    std::vector<uint8_t> result;
    try {
        auto temp = assemble_code(input);
        result = std::vector<uint8_t>(temp.begin(), temp.end());
    } catch (ChataError& e) {
        std::cout << e.what() << std::endl;
        std::cout << "❌ Test FAILED for " << input << ": expected ";
        for (auto& byte : expected_output) {
            std::cout << std::hex << static_cast<uint32_t>(byte) << " ";
        }
        std::cout << std::dec << " (";
        for (auto& byte : expected_output) {
            std::cout << std::bitset<8>(byte);
        }
        std::cout << "), but got an error" << std::endl;
        return;
    }

    if (result != expected_output) {
        std::cout << "❌ Test FAILED for " << input << ": expected ";
        for (auto& byte : expected_output) {
            std::cout << std::hex << static_cast<uint32_t>(byte) << " ";
        }
        std::cout << std::dec << " (";
        for (auto& byte : expected_output) {
            std::cout << std::bitset<8>(byte);
        }
        std::cout << "), but got ";
        for (auto& byte : result) {
            std::cout << std::hex << static_cast<uint32_t>(byte) << " ";
        }
        std::cout << std::dec << " (";
        for (auto& byte : result) {
            std::cout << std::bitset<8>(byte);
        }
        std::cout << ")" << std::endl;
        failed_tests++;
        return;
    }

    std::cout << "✅ Test passed for " << input << std::endl;
    passed_tests++;
}

} // namespace libchata_internal

using namespace libchata_internal;

int main() {
    std::cout << "Running assembler tests..." << std::endl;
    as(".insn 640", 0x8002);
    as(".insn 5928400", 0xd0755a00);
    as(".insn 0x5780", 0x8057);
    as(".insn 0x40506070", 0x70605040);
    as(".insn 0b1010101010101010", 0xaaaa);
    as(".insn 0b10101010101010101010101010101010", 0xaaaaaaaa);
    as(".insn 2, 400", 0x9001);
    as(".insn 2, 0x4000", 0x0040);
    as(".insn 2, 0b1000000000000000", 0x0080);
    as(".insn 4, 1398101", 0x55551500);
    as(".insn 4, 0x155555", 0x55551500);
    as(".insn 4, 0b10101010101010101010101010101010", 0xaaaaaaaa);

    as("lui a0, 12345", 0x37950303);
    as("lui a0, 0x12345", 0x37553412);
    as("lui a0, 0b100", 0x37450000);
    as("auipc t0, 0b100", 0x97420000);
    as("auipc t0, 100", 0x97420600);
    as("auipc t0, 0x100", 0x97021000);
    as("jal zero, 4", 0x6f004000);
    as("jalr zero, 4(a0)", 0x67004500);
    as("jalr x0, a0, 4", 0x67004500);
    as("jalr x0, -800(a0)", 0x670005ce);
    as("jalr x0, a0, -800", 0x670005ce);
    as("beq s1, t6, 40", 0x6384f403);
    as("beq s1, t6, -40", 0xe38cf4fd);
    as("bne s0, a2, 36", 0x6312c402);
    as("blt t4, t5, 16", 0x6398ee01);
    as("bge t3, t2, 12", 0x63467e00);
    as("bltu t1, t0, 8", 0x63545300);
    as("bgeu s2, s3, 4", 0x63623901);
    as("lb a0, a1, 0", 0x03850500);
    as("lb a0, 0(a1)", 0x03850500);
    as("lh a1, a2, 0", 0x83150600);
    as("#foo\nlh a1, a2, 0", 0x83150600);
    as("lh a1, 0(a2)", 0x83150600);
    as("lw a2, a3, 0", 0x03a60600);
    as("lw a2, 0(a3)", 0x03a60600);
    as("lbu a3, a4, 0", 0x83460700);
    as("lbu a3, 0(a4)", 0x83460700);
    as("lhu a4, a5, 0", 0x03d70700);
    as("lhu a4, 0(a5)", 0x03d70700);
    as("sb a5, a6, 0", 0x2300f800);
    as("sb a5, 0(a6)", 0x2300f800);
    as("sh a6, a7, 0", 0x23900801);
    as("sh a6, 0(a7)", 0x23900801);
    as("sw a7, s0, 0", 0x23201401);
    as("sw a7, 0(s0)", 0x23201401);
    as("addi a0, a1, 10", 0x1385a500);
    as("addi a0, a1, 10 # This should be the same", 0x1385a500);
    as("addi a0, a1, -10", 0x138565ff);
    as("addi t0, a0, 0x30", 0x93020503);
    as("addi t0, a0, -0x30", 0x930205fd);
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
    as("ebreak", 0x73001000);
    as("lwu a0, 0(a1)", 0x03e50500);
    as("ld s0, 0(s1)", 0x03b40400);
    as("sd s1, 0(s2)", 0x23309900);
    as("addiw s2, s3, 10", 0x1b89a900);
    as("slliw s3, s4, 8", 0x9b198a00);
    as("srliw s4, s5, 16", 0x1bda0a01);
    as("sraiw s5, s6, 24", 0x9b5a8b41);
    as("addw s6, s7, s0", 0x3b8b8b00);
    as("subw s7, t0, t1", 0xbb8b6240);
    as("sllw t0, t1, t2", 0xbb127300);
    as("srlw t1, t2, t3", 0x3bd3c301);
    as("sraw t2, t3, t4", 0xbb53de41);
    as("mul t3, t4, t5", 0x338eee03);
    as("mulh t4, t5, t6", 0xb31eff03);
    as("mulhsu t5, t6, t6", 0x33afff03);
    as("mulhu x0, x1, x2", 0x33b02002);
    as("div x3, x4, x5", 0xb3415202);
    as("divu x4, x5, x6", 0x33d26202);
    as("rem x5, x6, x7", 0xb3627302);
    as("remu x6, x7, x8", 0x33f38302);
    as("mulw x7, x8, x9", 0xbb039402);
    as("divw x8, x9, x10", 0x3bc4a402);
    as("divuw x9, x10, x11", 0xbb54b502);
    as("remw x10, x11, x12", 0x3be5c502);
    as("remuw x11, x12, x13", 0xbb75d602);
    as("lr.w a0, a1", 0x2fa50510);
    as("lr.w a0, (a1)", 0x2fa50510);
    as("lr.w a0, 0(a1)", 0x2fa50510);
    as("sc.w a2, a3, a4", 0x2f26d718);
    as("sc.w a2, a3, (a4)", 0x2f26d718);
    as("sc.w a2, a3, 0(a4)", 0x2f26d718);
    as("lr.w.aq a5, a6", 0xaf270814);
    as("lr.w.aq a5, (a6)", 0xaf270814);
    as("lr.w.aq a5, 0(a6)", 0xaf270814);
    as("sc.w.aq a7, s0, s1", 0xafa8841c);
    as("sc.w.aq a7, s0, (s1)", 0xafa8841c);
    as("sc.w.aq a7, s0, 0(s1)", 0xafa8841c);
    as("lr.w.rl s2, s3", 0x2fa90912);
    as("lr.w.rl s2, (s3)", 0x2fa90912);
    as("lr.w.rl s2, 0(s3)", 0x2fa90912);
    as("sc.w.rl s4, s5, s6", 0x2f2a5b1b);
    as("sc.w.rl s4, s5, (s6)", 0x2f2a5b1b);
    as("sc.w.rl s4, s5, 0(s6)", 0x2f2a5b1b);
    as("lr.w.aqrl s7, s0", 0xaf2b0416);
    as("lr.w.aqrl s7, (s0)", 0xaf2b0416);
    as("lr.w.aqrl s7, 0(s0)", 0xaf2b0416);
    as("sc.w.aqrl s1, s2, s3", 0xafa4291f);
    as("sc.w.aqrl s1, s2, (s3)", 0xafa4291f);
    as("sc.w.aqrl s1, s2, 0(s3)", 0xafa4291f);
    as("amoswap.w s4, s5, s6", 0x2f2a5b09);
    as("amoswap.w s4, s5, (s6)", 0x2f2a5b09);
    as("amoswap.w s4, s5, 0(s6)", 0x2f2a5b09);
    as("amoadd.w s7, s0, s1", 0xafab8400);
    as("amoadd.w s7, s0, (s1)", 0xafab8400);
    as("amoadd.w s7, s0, 0(s1)", 0xafab8400);
    as("amoxor.w s2, s3, s4", 0x2f293a21);
    as("amoxor.w s2, s3, (s4)", 0x2f293a21);
    as("amoxor.w s2, s3, 0(s4)", 0x2f293a21);
    as("amoand.w s5, s6, s7", 0xafaa6b61);
    as("amoand.w s5, s6, (s7)", 0xafaa6b61);
    as("amoand.w s5, s6, 0(s7)", 0xafaa6b61);
    as("amoor.w x0, x1, x2", 0x2f201140);
    as("amoor.w x0, x1, (x2)", 0x2f201140);
    as("amoor.w x0, x1, 0(x2)", 0x2f201140);
    as("amomin.w x3, x4, x5", 0xafa14280);
    as("amomin.w x3, x4, (x5)", 0xafa14280);
    as("amomin.w x3, x4, 0(x5)", 0xafa14280);
    as("amomax.w x6, x7, x8", 0x2f2374a0);
    as("amomax.w x6, x7, (x8)", 0x2f2374a0);
    as("amomax.w x6, x7, 0(x8)", 0x2f2374a0);
    as("amominu.w x9, x10, x11", 0xafa4a5c0);
    as("amominu.w x9, x10, (x11)", 0xafa4a5c0);
    as("amominu.w x9, x10, 0(x11)", 0xafa4a5c0);
    as("amomaxu.w x12, x13, x14", 0x2f26d7e0);
    as("amomaxu.w x12, x13, (x14)", 0x2f26d7e0);
    as("amomaxu.w x12, x13, 0(x14)", 0x2f26d7e0);
    as("amoswap.w.aq x15, x16, x17", 0xafa7080d);
    as("amoswap.w.aq x15, x16, (x17)", 0xafa7080d);
    as("amoswap.w.aq x15, x16, 0(x17)", 0xafa7080d);
    as("amoadd.w.aq x18, x19, x20", 0x2f293a05);
    as("amoadd.w.aq x18, x19, (x20)", 0x2f293a05);
    as("amoadd.w.aq x18, x19, 0(x20)", 0x2f293a05);
    as("amoxor.w.aq x21, x22, x23", 0xafaa6b25);
    as("amoxor.w.aq x21, x22, (x23)", 0xafaa6b25);
    as("amoxor.w.aq x21, x22, 0(x23)", 0xafaa6b25);
    as("amoand.w.aq x24, x25, x26", 0x2f2c9d65);
    as("amoand.w.aq x24, x25, (x26)", 0x2f2c9d65);
    as("amoand.w.aq x24, x25, 0(x26)", 0x2f2c9d65);
    as("amoor.w.aq x27, x28, x29", 0xafadce45);
    as("amoor.w.aq x27, x28, (x29)", 0xafadce45);
    as("amoor.w.aq x27, x28, 0(x29)", 0xafadce45);
    as("amomin.w.aq x30, x31, x0", 0x2f2ff085);
    as("amomin.w.aq x30, x31, (x0)", 0x2f2ff085);
    as("amomin.w.aq x30, x31, 0(x0)", 0x2f2ff085);
    as("amomax.w.aq x1, x2, x3", 0xafa021a4);
    as("amomax.w.aq x1, x2, (x3)", 0xafa021a4);
    as("amomax.w.aq x1, x2, 0(x3)", 0xafa021a4);
    as("amominu.w.aq x4, x5, x6", 0x2f2253c4);
    as("amominu.w.aq x4, x5, (x6)", 0x2f2253c4);
    as("amominu.w.aq x4, x5, 0(x6)", 0x2f2253c4);
    as("amomaxu.w.aq x7, x8, x9", 0xafa384e4);
    as("amomaxu.w.aq x7, x8, (x9)", 0xafa384e4);
    as("amomaxu.w.aq x7, x8, 0(x9)", 0xafa384e4);
    as("amoswap.w.rl x10, x11, x12", 0x2f25b60a);
    as("amoswap.w.rl x10, x11, (x12)", 0x2f25b60a);
    as("amoswap.w.rl x10, x11, 0(x12)", 0x2f25b60a);
    as("amoadd.w.rl x13, x14, x15", 0xafa6e702);
    as("amoadd.w.rl x13, x14, (x15)", 0xafa6e702);
    as("amoadd.w.rl x13, x14, 0(x15)", 0xafa6e702);
    as("amoxor.w.rl x16, x17, x18", 0x2f281923);
    as("amoxor.w.rl x16, x17, (x18)", 0x2f281923);
    as("amoxor.w.rl x16, x17, 0(x18)", 0x2f281923);
    as("amoand.w.rl x19, x20, x21", 0xafa94a63);
    as("amoand.w.rl x19, x20, (x21)", 0xafa94a63);
    as("amoand.w.rl x19, x20, 0(x21)", 0xafa94a63);
    as("amoor.w.rl x22, x23, x24", 0x2f2b7c43);
    as("amoor.w.rl x22, x23, (x24)", 0x2f2b7c43);
    as("amoor.w.rl x22, x23, 0(x24)", 0x2f2b7c43);
    as("amomin.w.rl x25, x26, x27", 0xafacad83);
    as("amomin.w.rl x25, x26, (x27)", 0xafacad83);
    as("amomin.w.rl x25, x26, 0(x27)", 0xafacad83);
    as("amomax.w.rl x28, x29, x30", 0x2f2edfa3);
    as("amomax.w.rl x28, x29, (x30)", 0x2f2edfa3);
    as("amomax.w.rl x28, x29, 0(x30)", 0x2f2edfa3);
    as("amominu.w.rl x31, x0, x1", 0xafaf00c2);
    as("amominu.w.rl x31, x0, (x1)", 0xafaf00c2);
    as("amominu.w.rl x31, x0, 0(x1)", 0xafaf00c2);
    as("amomaxu.w.rl x2, x3, x4", 0x2f2132e2);
    as("amomaxu.w.rl x2, x3, (x4)", 0x2f2132e2);
    as("amomaxu.w.rl x2, x3, 0(x4)", 0x2f2132e2);
    as("amoswap.w.aqrl x5, x6, x7", 0xafa2630e);
    as("amoswap.w.aqrl x5, x6, (x7)", 0xafa2630e);
    as("amoswap.w.aqrl x5, x6, 0(x7)", 0xafa2630e);
    as("amoadd.w.aqrl x8, x9, x10", 0x2f249506);
    as("amoadd.w.aqrl x8, x9, (x10)", 0x2f249506);
    as("amoadd.w.aqrl x8, x9, 0(x10)", 0x2f249506);
    as("amoxor.w.aqrl x11, x12, x13", 0xafa5c626);
    as("amoxor.w.aqrl x11, x12, (x13)", 0xafa5c626);
    as("amoxor.w.aqrl x11, x12, 0(x13)", 0xafa5c626);
    as("amoand.w.aqrl x14, x15, x16", 0x2f27f866);
    as("amoand.w.aqrl x14, x15, (x16)", 0x2f27f866);
    as("amoand.w.aqrl x14, x15, 0(x16)", 0x2f27f866);
    as("amoor.w.aqrl x17, x18, x19", 0xafa82947);
    as("amoor.w.aqrl x17, x18, (x19)", 0xafa82947);
    as("amoor.w.aqrl x17, x18, 0(x19)", 0xafa82947);
    as("amomin.w.aqrl x20, x21, x22", 0x2f2a5b87);
    as("amomin.w.aqrl x20, x21, (x22)", 0x2f2a5b87);
    as("amomin.w.aqrl x20, x21, 0(x22)", 0x2f2a5b87);
    as("amomax.w.aqrl x23, x24, x25", 0xafab8ca7);
    as("amomax.w.aqrl x23, x24, (x25)", 0xafab8ca7);
    as("amomax.w.aqrl x23, x24, 0(x25)", 0xafab8ca7);
    as("amominu.w.aqrl x26, x27, x28", 0x2f2dbec7);
    as("amominu.w.aqrl x26, x27, (x28)", 0x2f2dbec7);
    as("amominu.w.aqrl x26, x27, 0(x28)", 0x2f2dbec7);
    as("amomaxu.w.aqrl x29, x30, x31", 0xafaeefe7);
    as("amomaxu.w.aqrl x29, x30, (x31)", 0xafaeefe7);
    as("amomaxu.w.aqrl x29, x30, 0(x31)", 0xafaeefe7);
    as("lr.d a0, a1", 0x2fb50510);
    as("lr.d a0, (a1)", 0x2fb50510);
    as("lr.d a0, 0(a1)", 0x2fb50510);
    as("sc.d a2, a3, a4", 0x2f36d718);
    as("sc.d a2, a3, (a4)", 0x2f36d718);
    as("sc.d a2, a3, 0(a4)", 0x2f36d718);
    as("lr.d.aq a5, a6", 0xaf370814);
    as("lr.d.aq a5, (a6)", 0xaf370814);
    as("lr.d.aq a5, 0(a6)", 0xaf370814);
    as("sc.d.aq a7, s0, s1", 0xafb8841c);
    as("sc.d.aq a7, s0, (s1)", 0xafb8841c);
    as("sc.d.aq a7, s0, 0(s1)", 0xafb8841c);
    as("lr.d.rl s2, s3", 0x2fb90912);
    as("lr.d.rl s2, (s3)", 0x2fb90912);
    as("lr.d.rl s2, 0(s3)", 0x2fb90912);
    as("sc.d.rl s4, s5, s6", 0x2f3a5b1b);
    as("sc.d.rl s4, s5, (s6)", 0x2f3a5b1b);
    as("sc.d.rl s4, s5, 0(s6)", 0x2f3a5b1b);
    as("lr.d.aqrl s7, s0", 0xaf3b0416);
    as("lr.d.aqrl s7, (s0)", 0xaf3b0416);
    as("lr.d.aqrl s7, 0(s0)", 0xaf3b0416);
    as("sc.d.aqrl s1, s2, s3", 0xafb4291f);
    as("sc.d.aqrl s1, s2, (s3)", 0xafb4291f);
    as("sc.d.aqrl s1, s2, 0(s3)", 0xafb4291f);
    as("amoswap.d s4, s5, s6", 0x2f3a5b09);
    as("amoswap.d s4, s5, (s6)", 0x2f3a5b09);
    as("amoswap.d s4, s5, 0(s6)", 0x2f3a5b09);
    as("amoadd.d s7, s0, s1", 0xafbb8400);
    as("amoadd.d s7, s0, (s1)", 0xafbb8400);
    as("amoadd.d s7, s0, 0(s1)", 0xafbb8400);
    as("amoxor.d s2, s3, s4", 0x2f393a21);
    as("amoxor.d s2, s3, (s4)", 0x2f393a21);
    as("amoxor.d s2, s3, 0(s4)", 0x2f393a21);
    as("amoand.d s5, s6, s7", 0xafba6b61);
    as("amoand.d s5, s6, (s7)", 0xafba6b61);
    as("amoand.d s5, s6, 0(s7)", 0xafba6b61);
    as("amoor.d x0, x1, x2", 0x2f301140);
    as("amoor.d x0, x1, (x2)", 0x2f301140);
    as("amoor.d x0, x1, 0(x2)", 0x2f301140);
    as("amomin.d x3, x4, x5", 0xafb14280);
    as("amomin.d x3, x4, (x5)", 0xafb14280);
    as("amomin.d x3, x4, 0(x5)", 0xafb14280);
    as("amomax.d x6, x7, x8", 0x2f3374a0);
    as("amomax.d x6, x7, (x8)", 0x2f3374a0);
    as("amomax.d x6, x7, 0(x8)", 0x2f3374a0);
    as("amominu.d x9, x10, x11", 0xafb4a5c0);
    as("amominu.d x9, x10, (x11)", 0xafb4a5c0);
    as("amominu.d x9, x10, 0(x11)", 0xafb4a5c0);
    as("amomaxu.d x12, x13, x14", 0x2f36d7e0);
    as("amomaxu.d x12, x13, (x14)", 0x2f36d7e0);
    as("amomaxu.d x12, x13, 0(x14)", 0x2f36d7e0);
    as("amoswap.d.aq x15, x16, x17", 0xafb7080d);
    as("amoswap.d.aq x15, x16, (x17)", 0xafb7080d);
    as("amoswap.d.aq x15, x16, 0(x17)", 0xafb7080d);
    as("amoadd.d.aq x18, x19, x20", 0x2f393a05);
    as("amoadd.d.aq x18, x19, (x20)", 0x2f393a05);
    as("amoadd.d.aq x18, x19, 0(x20)", 0x2f393a05);
    as("amoxor.d.aq x21, x22, x23", 0xafba6b25);
    as("amoxor.d.aq x21, x22, (x23)", 0xafba6b25);
    as("amoxor.d.aq x21, x22, 0(x23)", 0xafba6b25);
    as("amoand.d.aq x24, x25, x26", 0x2f3c9d65);
    as("amoand.d.aq x24, x25, (x26)", 0x2f3c9d65);
    as("amoand.d.aq x24, x25, 0(x26)", 0x2f3c9d65);
    as("amoor.d.aq x27, x28, x29", 0xafbdce45);
    as("amoor.d.aq x27, x28, (x29)", 0xafbdce45);
    as("amoor.d.aq x27, x28, 0(x29)", 0xafbdce45);
    as("amomin.d.aq x30, x31, x0", 0x2f3ff085);
    as("amomin.d.aq x30, x31, (x0)", 0x2f3ff085);
    as("amomin.d.aq x30, x31, 0(x0)", 0x2f3ff085);
    as("amomax.d.aq x1, x2, x3", 0xafb021a4);
    as("amomax.d.aq x1, x2, (x3)", 0xafb021a4);
    as("amomax.d.aq x1, x2, 0(x3)", 0xafb021a4);
    as("amominu.d.aq x4, x5, x6", 0x2f3253c4);
    as("amominu.d.aq x4, x5, (x6)", 0x2f3253c4);
    as("amominu.d.aq x4, x5, 0(x6)", 0x2f3253c4);
    as("amomaxu.d.aq x7, x8, x9", 0xafb384e4);
    as("amomaxu.d.aq x7, x8, (x9)", 0xafb384e4);
    as("amomaxu.d.aq x7, x8, 0(x9)", 0xafb384e4);
    as("amoswap.d.rl x10, x11, x12", 0x2f35b60a);
    as("amoswap.d.rl x10, x11, (x12)", 0x2f35b60a);
    as("amoswap.d.rl x10, x11, 0(x12)", 0x2f35b60a);
    as("amoadd.d.rl x13, x14, x15", 0xafb6e702);
    as("amoadd.d.rl x13, x14, (x15)", 0xafb6e702);
    as("amoadd.d.rl x13, x14, 0(x15)", 0xafb6e702);
    as("amoxor.d.rl x16, x17, x18", 0x2f381923);
    as("amoxor.d.rl x16, x17, (x18)", 0x2f381923);
    as("amoxor.d.rl x16, x17, 0(x18)", 0x2f381923);
    as("amoand.d.rl x19, x20, x21", 0xafb94a63);
    as("amoand.d.rl x19, x20, (x21)", 0xafb94a63);
    as("amoand.d.rl x19, x20, 0(x21)", 0xafb94a63);
    as("amoor.d.rl x22, x23, x24", 0x2f3b7c43);
    as("amoor.d.rl x22, x23, (x24)", 0x2f3b7c43);
    as("amoor.d.rl x22, x23, 0(x24)", 0x2f3b7c43);
    as("amomin.d.rl x25, x26, x27", 0xafbcad83);
    as("amomin.d.rl x25, x26, (x27)", 0xafbcad83);
    as("amomin.d.rl x25, x26, 0(x27)", 0xafbcad83);
    as("amomax.d.rl x28, x29, x30", 0x2f3edfa3);
    as("amomax.d.rl x28, x29, (x30)", 0x2f3edfa3);
    as("amomax.d.rl x28, x29, 0(x30)", 0x2f3edfa3);
    as("amominu.d.rl t0, a0, s0", 0xaf32a4c2);
    as("amominu.d.rl t0, a0, (s0)", 0xaf32a4c2);
    as("amominu.d.rl t0, a0, 0(s0)", 0xaf32a4c2);
    as("amomaxu.d.rl t1, a1, s1", 0x2fb3b4e2);
    as("amomaxu.d.rl t1, a1, (s1)", 0x2fb3b4e2);
    as("amomaxu.d.rl t1, a1, 0(s1)", 0x2fb3b4e2);
    as("amoswap.d.aqrl t2, a2, s2", 0xaf33c90e);
    as("amoswap.d.aqrl t2, a2, (s2)", 0xaf33c90e);
    as("amoswap.d.aqrl t2, a2, 0(s2)", 0xaf33c90e);
    as("amoadd.d.aqrl t3, a3, s3", 0x2fbed906);
    as("amoadd.d.aqrl t3, a3, (s3)", 0x2fbed906);
    as("amoadd.d.aqrl t3, a3, 0(s3)", 0x2fbed906);
    as("amoxor.d.aqrl t4, a4, s4", 0xaf3eea26);
    as("amoxor.d.aqrl t4, a4, (s4)", 0xaf3eea26);
    as("amoxor.d.aqrl t4, a4, 0(s4)", 0xaf3eea26);
    as("amoand.d.aqrl t5, a5, s5", 0x2fbffa66);
    as("amoand.d.aqrl t5, a5, (s5)", 0x2fbffa66);
    as("amoand.d.aqrl t5, a5, 0(s5)", 0x2fbffa66);
    as("amoor.d.aqrl t6, a6, s6", 0xaf3f0b47);
    as("amoor.d.aqrl t6, a6, (s6)", 0xaf3f0b47);
    as("amoor.d.aqrl t6, a6, 0(s6)", 0xaf3f0b47);
    as("amomin.d.aqrl a0, t0, s0", 0x2f355486);
    as("amomin.d.aqrl a0, t0, (s0)", 0x2f355486);
    as("amomin.d.aqrl a0, t0, 0(s0)", 0x2f355486);
    as("amomax.d.aqrl a1, t1, s1", 0xafb564a6);
    as("amomax.d.aqrl a1, t1, (s1)", 0xafb564a6);
    as("amomax.d.aqrl a1, t1, 0(s1)", 0xafb564a6);
    as("amominu.d.aqrl a2, t2, s2", 0x2f3679c6);
    as("amominu.d.aqrl a2, t2, (s2)", 0x2f3679c6);
    as("amominu.d.aqrl a2, t2, 0(s2)", 0x2f3679c6);
    as("amomaxu.d.aqrl a3, t3, s3", 0xafb6c9e7);
    as("amomaxu.d.aqrl a3, t3, (s3)", 0xafb6c9e7);
    as("amomaxu.d.aqrl a3, t3, 0(s3)", 0xafb6c9e7);
    as("fmadd.s f0, f1, f2, f3", 0x43f02018);
    as("fmsub.s f4, f5, f6, f7", 0x47f26238);
    as("fnmsub.s f8, f9, f10, f11", 0x4bf4a458);
    as("fnmadd.s f12, f13, f14, f15", 0x4ff6e678);
    as("fadd.s f16, f17, f18", 0x53f82801);
    as("fsub.s f19, f20, f21", 0xd3795a09);
    as("fmul.s f22, f23, f24", 0x53fb8b11);
    as("fdiv.s f25, f26, f27", 0xd37cbd19);
    as("fsqrt.s f28, f29", 0x53fe0e58);
    as("fsgnj.s f30, f31, f0", 0x538f0f20);
    as("fsgnjn.s f1, f2, f3", 0xd3103120);
    as("fsgnjx.s f4, f5, f6", 0x53a26220);
    as("fmin.s f7, f8, f9", 0xd3039428);
    as("fmax.s f10, f11, f12", 0x5395c528);
    as("fcvt.w.s a0, f0", 0x537500c0);
    as("fcvt.wu.s a1, f1", 0xd3f510c0);
    as("fmv.x.w a2, f2", 0x530601e0);
    as("feq.s a3, f3, f4", 0xd3a641a0);
    as("flt.s a4, f4, f5", 0x531752a0);
    as("fle.s a5, f5, f6", 0xd38762a0);
    as("fclass.s a6, f6", 0x531803e0);
    as("fcvt.s.w f7, a7", 0xd3f308d0);
    as("fcvt.s.wu f8, s0", 0x537414d0);
    as("fmv.w.x f9, s1", 0xd38404f0);
    as("flw f10, 0(a0)", 0x07250500);
    as("fsw f11, 0(a1)", 0x27a0b500);
    as("fcvt.l.s a2, f12", 0x537626c0);
    as("fcvt.lu.s a3, f13", 0xd3f636c0);
    as("fcvt.s.l f14, a4", 0x537727d0);
    as("fcvt.s.lu f15, a5", 0xd3f737d0);
    as("fadd.d f16, f17, f18", 0x53f82803);
    as("fmadd.d f19, f20, f21, f22", 0xc3795ab3);
    as("fmax.d f23, f24, f25", 0xd31b9c2b);
    as("fclass.d a0, f23", 0x53950be2);
    as("fcvt.d.s fa0, fa1", 0x53f50542);
    as("fcvt.d.w fa2, a1", 0x53f605d2);
    as("fcvt.d.wu fa3, a2", 0xd37616d2);
    as("fcvt.s.d f24, f25", 0x53fc1c40);
    as("fcvt.w.d a4, f26", 0x53770dc2);
    as("fcvt.wu.d a5, f27", 0xd3f71dc2);
    as("fdiv.d f28, f29, f30", 0x53feee1b);
    as("feq.d t3, f0, f1", 0x532e10a2);
    as("flt.d t4, f2, f3", 0xd31e31a2);
    as("fle.d t5, f4, f5", 0x530f52a2);
    as("fld f6, 4(a6)", 0x07334800);
    as("fmin.d f7, f8, f9", 0xd303942a);
    as("fmsub.d f10, f11, f12, f13", 0x47f5c56a);
    as("fmul.d f14, f15, f16", 0x53f70713);
    as("fnmadd.d f17, f18, f19, f20", 0xcf7839a3);
    as("fnmsub.d f21, f22, f23, f24", 0xcb7a7bc3);
    as("fsd f25, 8(a7)", 0x27b49801);
    as("fsgnj.d f26, f27, f28", 0x538dcd23);
    as("fsgnjn.d f29, f30, f31", 0xd31eff23);
    as("fsgnjx.d f0, f1, f2", 0x53a02022);
    as("fsqrt.d f3, f4", 0xd371025a);
    as("fsub.d f5, f6, f7", 0xd372730a);
    as("fcvt.l.d a0, f8", 0x537524c2);
    as("fcvt.lu.d a1, f9", 0xd3f534c2);
    as("fmv.x.d a2, f10", 0x530605e2);
    as("fcvt.d.l f11, a3", 0xd3f526d2);
    as("fcvt.d.lu f12, a4", 0x537637d2);
    as("fmv.d.x f13, a5", 0xd38607f2);
    as("flq f14, 0(a6)", 0x07470800);
    as("fsq f15, 8(a7)", 0x27c4f800);
    as("fmadd.q f16, f17, f18, f19", 0x43f8289f);
    as("fmsub.q f20, f21, f22, f23", 0x47fa6abf);
    as("fnmsub.q f24, f25, f26, f27", 0x4bfcacdf);
    as("fnmadd.q f28, f29, f30, f31", 0x4ffeeeff);
    as("fadd.q f0, f1, f2", 0x53f02006);
    as("fsub.q f3, f4, f5", 0xd371520e);
    as("fmul.q f6, f7, f8", 0x53f38316);
    as("fdiv.q f9, f10, f11", 0xd374b51e);
    as("fsqrt.q f12, f13", 0x53f6065e);
    as("fsgnj.q f14, f15, f16", 0x53870727);
    as("fsgnjn.q f17, f18, f19", 0xd3183927);
    as("fsgnjx.q f20, f21, f22", 0x53aa6a27);
    as("fmin.q f23, f24, f25", 0xd30b9c2f);
    as("fmax.q f26, f27, f28", 0x539dcd2f);
    as("fcvt.s.q f29, f30", 0xd37e3f40);
    as("fcvt.q.s f31, f0", 0xd37f0046);
    as("fcvt.d.q f1, f2", 0xd3703142);
    as("fcvt.q.d f3, f4", 0xd3711246);
    as("feq.q a0, f5, f6", 0x53a562a6);
    as("flt.q a1, f7, f8", 0xd39583a6);
    as("fle.q a2, f9, f10", 0x5386a4a6);
    as("fclass.q a3, f11", 0xd39605e6);
    as("fcvt.w.q a4, f12", 0x537706c6);
    as("fcvt.wu.q a5, f13", 0xd3f716c6);
    as("fcvt.q.w f14, a6", 0x537708d6);
    as("fcvt.q.wu f15, a7", 0xd3f718d6);
    as("fcvt.l.q a6, f16", 0x537828c6);
    as("fcvt.lu.q a7, f17", 0xd3f838c6);
    as("fcvt.q.l f18, a0", 0x537925d6);
    as("fcvt.q.lu f19, a1", 0xd3f935d6);
    as("flh f20, 2(a2)", 0x071a2600);
    as("fsh f21, 4(a3)", 0x27925601);
    as("fmadd.h f22, f23, f24, f25", 0x43fb8bcd);
    as("fmsub.h f26, f27, f28, f29", 0x47fdcded);
    as("fnmsub.h f30, f31, f0, f1", 0x4bff0f0c);
    as("fnmadd.h f2, f3, f4, f5", 0x4ff1412c);
    as("fadd.h f6, f7, f8", 0x53f38304);
    as("fsub.h f9, f10, f11", 0xd374b50c);
    as("fmul.h f12, f13, f14", 0x53f6e614);
    as("fdiv.h f15, f16, f17", 0xd377181d);
    as("fsqrt.h f18, f19", 0x53f9095c);
    as("fsgnj.h f20, f21, f22", 0x538a6a25);
    as("fsgnjn.h f23, f24, f25", 0xd31b9c25);
    as("fsgnjx.h f26, f27, f28", 0x53adcd25);
    as("fmin.h f29, f30, f31", 0xd30eff2d);
    as("fmax.h f0, f1, f2", 0x5390202c);
    as("fcvt.s.h f3, f4", 0xd3712240);
    as("fcvt.h.s f5, f6", 0xd3720344);
    as("fcvt.d.h f7, f8", 0xd3732442);
    as("fcvt.h.d f9, f10", 0xd3741544);
    as("fcvt.q.h f11, f12", 0xd3752646);
    as("fcvt.h.q f13, f14", 0xd3763744);
    as("feq.h a0, f15, f16", 0x53a507a5);
    as("flt.h a1, f17, f18", 0xd39528a5);
    as("fle.h a2, f19, f20", 0x538649a5);
    as("fclass.h a3, f21", 0xd3960ae4);
    as("fcvt.w.h a4, f22", 0x53770bc4);
    as("fcvt.wu.h a5, f23", 0xd3f71bc4);
    as("fmv.x.h a6, f24", 0x53080ce4);
    as("fcvt.h.w f25, a7", 0xd3fc08d4);
    as("fcvt.h.wu f26, s0", 0x537d14d4);
    as("fmv.h.x f27, s1", 0xd38d04f4);
    as("fcvt.l.h a0, f28", 0x53752ec4);
    as("fcvt.lu.h a1, f29", 0xd3f53ec4);
    as("fcvt.h.l f30, a2", 0x537f26d4);
    as("fcvt.h.lu f31, a3", 0xd3ff36d4);
    as("fence.i", 0x0f100000);
    as("csrrw a0, mvendorid, a1", 0x739515f1);
    as("csrrs a2, mvendorid, a3", 0x73a616f1);
    as("csrrc a4, marchid, a5", 0x73b727f1);
    as("csrrwi a6, mimpid, 6", 0x735833f1);
    as("csrrsi a7, mhartid, 7", 0xf3e843f1);
    as("csrrci t0, mstatus, 8", 0xf3720430);
    as("wrs.nto", 0x7300d000);
    as("wrs.sto", 0x7300d001);
    as("c.lwsp a0, 0", 0x0245);
    as("c.lwsp a0, 0(sp)", 0x0245);
    as("c.ldsp a1, 8", 0xa265);
    as("c.ldsp a1, 8(sp)", 0xa265);
    as("c.flwsp f0, 0", 0x0260);
    as("c.flwsp f0, 0(sp)", 0x0260);
    as("c.fldsp f1, 8", 0xa220);
    as("c.fldsp f1, 8(sp)", 0xa220);
    as("c.swsp a2, 0", 0x32c0);
    as("c.swsp a2, 0(sp)", 0x32c0);
    as("c.sdsp a3, 8", 0x36e4);
    as("c.sdsp a3, 8(sp)", 0x36e4);
    as("c.fswsp f4, 0", 0x12e0);
    as("c.fswsp f4, 0(sp)", 0x12e0);
    as("c.fsdsp f5, 8", 0x16a4);
    as("c.fsdsp f5, 8(sp)", 0x16a4);
    as("c.lw x8, x9, 0", 0x8040);
    as("c.lw x8, (x9)", 0x8040);
    as("c.lw x8, 0(x9)", 0x8040);
    as("c.ld x10, x11, 8", 0x8865);
    as("c.ld x10, 8(x11)", 0x8865);
    as("c.flw f12, x13, 0", 0x9062);
    as("c.flw f12, (x13)", 0x9062);
    as("c.flw f12, 0(x13)", 0x9062);
    as("c.fld f14, x15, 8", 0x9827);
    as("c.fld f14, 8(x15)", 0x9827);
    as("c.sw x8, x15, 0", 0x80c3);
    as("c.sw x8, (x15)", 0x80c3);
    as("c.sw x8, 0(x15)", 0x80c3);
    as("c.sd x9, x14, 8", 0x04e7);
    as("c.sd x9, 8(x14)", 0x04e7);
    as("c.fsw f10, x13, 0", 0x88e2);
    as("c.fsw f10, (x13)", 0x88e2);
    as("c.fsw f10, 0(x13)", 0x88e2);
    as("c.fsd f11, x12, 8", 0x0ca6);
    as("c.fsd f11, 8(x12)", 0x0ca6);
    as("c.j 64", 0x81a0);
    as("c.jal 32", 0x0520);
    as("c.jr x1", 0x8280);
    as("c.jalr x2", 0x0291);
    as("c.beqz x8, 16", 0x01c8);
    as("c.bnez x9, 8", 0x81e4);
    as("c.li x10, 31", 0x7d45);
    as("c.lui x11, 16", 0x8165);
    as("c.lui x12, 31", 0x0166);
    as("c.addi x12, 8", 0x2106);
    as("c.addiw x13, 16", 0xc126);
    as("c.addi16sp sp, 16", 0x4161);
    as("c.slli x14, 1", 0x0607);
    as("c.srli x15, 1", 0x8583);
    as("c.srai x15, 1", 0x8587);
    as("c.andi x15, 1", 0x858b);
    as("c.mv x16, x17", 0x4688);
    as("c.add x18, x19", 0x4e99);
    as("c.and x8, x9", 0x658c);
    as("c.or x10, x11", 0x4d8d);
    as("c.xor x12, x13", 0x358e);
    as("c.sub x14, x15", 0x1d8f);
    as("c.nop", 0x0100);
    as("c.ebreak", 0x0290);

    as("beq t0, t1, foolabel\n#blahblah comment\nadd a0, a5, a6\nfoolabel:", {0x63, 0x84, 0x62, 0x00, 0x33, 0x85, 0x07, 0x01});
    as("foolabel:\nadd a0, a5, a6\nbne t0, t1, foolabel\n#ignore this", {0x33, 0x85, 0x07, 0x01, 0xe3, 0x9e, 0x62, 0xfe});
    as("beq t0, t1, foolabel\nc.li a5, 26 # foobar\n\n\n#irrelevant comment\n\n#another comment\n\nfoolabel: # also ignore this comment", {0x63, 0x83, 0x62, 0x00, 0xe9, 0x47});
    as("foolabel:\nc.li a5, 26\nbeq t0, t1, foolabel", {0xe9, 0x47, 0xe3, 0x8f, 0x62, 0xfe});
    as("foolabel:\nc.li a5, 26\nadd s0, s1, s2\nbeq t0, t1, foolabel", {0xe9, 0x47, 0x33, 0x84, 0x24, 0x01, 0xe3, 0x8d, 0x62, 0xfe});
    as("dummylabel:\nc.li a5, 26\n#another comment for good measure\nbeq t0, t1, foolabel\nxor a0, a1, a2\nbarlabel:\nfoolabel:\nadd s0, s1, s2\nj dummylabel",
       {0xe9, 0x47, 0x63, 0x84, 0x62, 0x00, 0x33, 0xc5, 0xc5, 0x00, 0x33, 0x84, 0x24, 0x01, 0x6f, 0xf0, 0x3f, 0xff});
    as("foolabel:\njal zero, foolabel\nc.j foolabel\nbazlabel:\njal zero, barlabel\nc.j barlabel\n.dotlabel:\nbarlabel:", {0x6f, 0x00, 0x00, 0x00, 0xf5, 0xbf, 0x6f, 0x00, 0x60, 0x00, 0x09, 0xa0});
    as(".dotfoolabel:\njal zero, .dotfoolabel\nc.j .dotfoolabel\nbazlabel:\njal zero, .dotbarlabel\nc.j .dotbarlabel\n.dotlabel:\n.dotbarlabel:",
       {0x6f, 0x00, 0x00, 0x00, 0xf5, 0xbf, 0x6f, 0x00, 0x60, 0x00, 0x09, 0xa0});

    std::cout << passed_tests << " tests passed, " << failed_tests << " tests failed, " << passed_tests + failed_tests << " tests total" << std::endl;

    if (passed_tests == passed_tests + failed_tests) {
        std::cout << "Yay, all your tests passed!" << std::endl;
    }
}