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
    //as("fence.i
    //as("csrrw
    //as("csrrs
    //as("csrrc
    //as("csrrwi
    //as("csrrsi
    //as("csrrci
    //as("wrs.nto
    //as("wrs.sto

    std::cout << passed_tests << " tests passed, " << failed_tests << " tests failed, " << passed_tests + failed_tests << " tests total" << std::endl;

    if (passed_tests == passed_tests + failed_tests) {
        std::cout << "Yay, all your tests passed!" << std::endl;
    }
}