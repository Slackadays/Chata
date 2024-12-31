// SPDX-License-Identifier: MPL-2.0
#include <array>
#include <cstdint>
#include <initializer_list>
#include <optional>
#include <string_view>
#include "libchata.hpp"

namespace libchata_internal {

constexpr uint16_t instr_search_failed = (uint16_t)-1;
const uint16_t fast_instr_search(const chatastring& inst);

enum class RVInstructionID : uint16_t {
    LUI, // RV32I
    AUIPC,
    JAL,
    JALR,
    BEQ,
    BNE,
    BLT,
    BGE,
    BLTU,
    BGEU,
    LB,
    LH,
    LW,
    LBU,
    LHU,
    SB,
    SH,
    SW,
    ADDI,
    SLTI,
    SLTIU,
    XORI,
    ORI,
    ANDI,
    SLLI,
    SRLI,
    SRAI,
    ADD,
    SUB,
    SLL,
    SLT,
    SLTU,
    XOR,
    SRL,
    SRA,
    OR,
    AND,
    FENCE,
    FENCETSO,
    PAUSE,
    ECALL,
    EBREAK,
    LWU, // RV64I
    LD,
    SD,
    ADDIW,
    SLLIW,
    SRLIW,
    SRAIW,
    ADDW,
    SUBW,
    SLLW,
    SRLW,
    SRAW,
    MUL, // RV32M
    MULH,
    MULHSU,
    MULHU,
    DIV,
    DIVU,
    REM,
    REMU,
    MULW, // RV64M
    DIVW,
    DIVUW,
    REMW,
    REMUW,
    LRW, // RV32A
    SCW,
    LRWAQ, // RV32A (aq)
    SCWAQ,
    LRWRL, // RV32A (rl)
    SCWRL,
    LRWAQRL, // RV32A (aqrl)
    SCWAQRL,
    AMOSWAPW,
    AMOADDW,
    AMOXORW,
    AMOANDW,
    AMOORW,
    AMOMINW,
    AMOMAXW,
    AMOMINUW,
    AMOMAXUW,
    AMOSWAPWAQ,
    AMOADDWAQ,
    AMOXORWAQ,
    AMOANDWAQ,
    AMOORWAQ,
    AMOMINWAQ,
    AMOMAXWAQ,
    AMOMINUWAQ,
    AMOMAXUWAQ,
    AMOSWAPWRL,
    AMOADDWRL,
    AMOXORWRL,
    AMOANDWRL,
    AMOORWRL,
    AMOMINWRL,
    AMOMAXWRL,
    AMOMINUWRL,
    AMOMAXUWRL,
    AMOSWAPWAQRL,
    AMOADDWAQRL,
    AMOXORWAQRL,
    AMOANDWAQRL,
    AMOORWAQRL,
    AMOMINWAQRL,
    AMOMAXWAQRL,
    AMOMINUWAQRL,
    AMOMAXUWAQRL,
    LRD, // RV64A
    SCD,
    LRDAQ, // RV64A (aq)
    SCDAQ,
    LRDRL, // RV64A (rl)
    SCDRL,
    LRDAQRL, // RV64A (aqrl)
    SCDAQRL,
    AMOSWAPD,
    AMOADDD,
    AMOXORD,
    AMOANDD,
    AMOORD,
    AMOMIND,
    AMOMAXD,
    AMOMINUD,
    AMOMAXUD,
    AMOSWAPDAQ,
    AMOADDDAQ,
    AMOXORDAQ,
    AMOANDDAQ,
    AMOORDAQ,
    AMOMINDAQ,
    AMOMAXDAQ,
    AMOMINUDAQ,
    AMOMAXUDAQ,
    AMOSWAPDRL,
    AMOADDDRL,
    AMOXORDRL,
    AMOANDDRL,
    AMOORDRL,
    AMOMINDRL,
    AMOMAXDRL,
    AMOMINUDRL,
    AMOMAXUDRL,
    AMOSWAPDAQRL,
    AMOADDDAQRL,
    AMOXORDAQRL,
    AMOANDDAQRL,
    AMOORDAQRL,
    AMOMINDAQRL,
    AMOMAXDAQRL,
    AMOMINUDAQRL,
    AMOMAXUDAQRL,
    FMADDS, // RV32F
    FMSUBS,
    FNMSUBS,
    FNMADDS,
    FADDS,
    FSUBS,
    FMULS,
    FDIVS,
    FSQRTS,
    FSGNJS,
    FSGNJNS,
    FSGNJXS,
    FMINS,
    FMAXS,
    FCVTWS,
    FCVTWUS,
    FMVXW,
    FEQS,
    FLTS,
    FLES,
    FCLASSS,
    FCVTSW,
    FCVTSWU,
    FMVWX,
    FLW,
    FSW,
    FCVTLS, // RV64F
    FCVTLUS,
    FCVTSL,
    FCVTSLU,
    FADDD, // RV32D
    FCLASSD,
    FCVTDS,
    FCVTDW,
    FCVTDWU,
    FCVTSD,
    FCVTWD,
    FCVTWUD,
    FDIVD,
    FEQD,
    FLD,
    FLED,
    FLTD,
    FMADDD,
    FMAXD,
    FMIND,
    FMSUBD,
    FMULD,
    FNMADDD,
    FNMSUBD,
    FSD,
    FSGNJD,
    FSGJND,
    FSGNJXD,
    FSQRTD,
    FSUBD,
    FCVTLD, // RV64D
    FCVTLUD,
    FMVXD,
    FCVTDL,
    FCVTDLU,
    FMVDX,
    FLQ, // RV32Q
    FSQ,
    FMADDQ,
    FMSUBQ,
    FNMSUBQ,
    FNMADDQ,
    FADDQ,
    FSUBQ,
    FMULQ,
    FDIVQ,
    FSQRTQ,
    FSGNJQ,
    FSGNJNQ,
    FSGNJXQ,
    FMINQ,
    FMAXQ,
    FCVTSQ,
    FCVTQS,
    FCVTDQ,
    FCVTQD,
    FEQQ,
    FLTQ,
    FLEQ,
    FCLASSQ,
    FCVTWQ,
    FCVTWUQ,
    FCVTQW,
    FCVTQWU,
    FCVTLQ, // RV64Q
    FCVTLUQ,
    FCVTQL,
    FCVTQLU,
    FLH, // RV32Zfh
    FSH,
    FMADDH,
    FMSUBH,
    FNMSUBH,
    FNMADDH,
    FADDH,
    FSUBH,
    FMULH,
    FDIVH,
    FSQRTH,
    FSGNJH,
    FSGNJNH,
    FSGNJXH,
    FMINH,
    FMAXH,
    FCVTSH,
    FCVTHS,
    FCVTDH,
    FCVTHD,
    FCVTQH,
    FCVTHQ,
    FEQH,
    FLTH,
    FLEH,
    FCLASSH,
    FCVTWH,
    FCVTWUH,
    FMVXH,
    FCVTHW,
    FCVTHWU,
    FMVHX,
    FCVTLH, // RV64Zfh
    FCVTLUH,
    FCVTHL,
    FCVTHLU,
    FENCEI, // Zifencei
    CSRRW,  // Zicsr
    CSRRS,
    CSRRC,
    CSRRWI,
    CSRRSI,
    CSRRCI,
    WRSNTO, // Zawrs
    WRSSTO,
    CLWSP, // C
    CLDSP,
    CFLWSP,
    CFLDSP,
    CSWSP,
    CSDSP,
    CFSWSP,
    CFSDSP,
    CLW,
    CLD,
    CFLW,
    CFLD,
    CSW,
    CSD,
    CFSW,
    CFSD,
    CJump,
    CJAL,
    CJR,
    CJALR,
    CBEQZ,
    CBNEZ,
    CLI,
    CLUI,
    CADDI,
    CADDIW,
    CADDI16SP,
    CSLLI,
    CSRLI,
    CSRAI,
    CANDI,
    CMV,
    CADD,
    CAND,
    COR,
    CXOR,
    CSUB,
    CADDW,
    CSUBW,
    CNOP,
    CEBREAK,
    VSETVLI, // V
    VSETIVLI,
    VSETVL,
    VLE8V,
    VLE16V,
    VLE32V,
    VLE64V,
    VSE8V,
    VSE16V,
    VSE32V,
    VSE64V,
    VLMV,
    VSMV,
    VLSE8V,
    VLSE16V,
    VLSE32V,
    VLSE64V,
    VSSE8V,
    VSSE16V,
    VSSE32V,
    VSSE64V,
    VLUXEI8V,
    VLUXEI16V,
    VLUXEI32V,
    VLUXEI64V,
    VLOXEI8V,
    VLOXEI16V,
    VLOXEI32V,
    VLOXEI64V,
    VSUXEI8V,
    VSUXEI16V,
    VSUXEI32V,
    VSUXEI64V,
    VSOXEI8V,
    VSOXEI16V,
    VSOXEI32V,
    VSOXEI64V,
    VLE8FFV,
    VLE16FFV,
    VLE32FFV,
    VLE64FFV,
    VLSEG2E8V,
    VSSEG2E8V,
    VLSEG2E16V,
    VSSEG2E16V,
    VLSEG2E32V,
    VSSEG2E32V,
    VLSEG2E64V,
    VSSEG2E64V,
    VLSEG3E8V,
    VSSEG3E8V,
    VLSEG3E16V,
    VSSEG3E16V,
    VLSEG3E32V,
    VSSEG3E32V,
    VLSEG3E64V,
    VSSEG3E64V,
    VLSEG4E8V,
    VSSEG4E8V,
    VLSEG4E16V,
    VSSEG4E16V,
    VLSEG4E32V,
    VSSEG4E32V,
    VLSEG4E64V,
    VSSEG4E64V,
    VLSEG5E8V,
    VSSEG5E8V,
    VLSEG5E16V,
    VSSEG5E16V,
    VLSEG5E32V,
    VSSEG5E32V,
    VLSEG5E64V,
    VSSEG5E64V,
    VLSEG6E8V,
    VSSEG6E8V,
    VLSEG6E16V,
    VSSEG6E16V,
    VLSEG6E32V,
    VSSEG6E32V,
    VLSEG6E64V,
    VSSEG6E64V,
    VLSEG7E8V,
    VSSEG7E8V,
    VLSEG7E16V,
    VSSEG7E16V,
    VLSEG7E32V,
    VSSEG7E32V,
    VLSEG7E64V,
    VSSEG7E64V,
    VLSEG8E8V,
    VSSEG8E8V,
    VLSEG8E16V,
    VSSEG8E16V,
    VLSEG8E32V,
    VSSEG8E32V,
    VLSEG8E64V,
    VSSEG8E64V,
    VLSEG2E8FFV,
    VLSEG2E16FFV,
    VLSEG2E32FFV,
    VLSEG2E64FFV,
    VLSEG3E8FFV,
    VLSEG3E16FFV,
    VLSEG3E32FFV,
    VLSEG3E64FFV,
    VLSEG4E8FFV,
    VLSEG4E16FFV,
    VLSEG4E32FFV,
    VLSEG4E64FFV,
    VLSEG5E8FFV,
    VLSEG5E16FFV,
    VLSEG5E32FFV,
    VLSEG5E64FFV,
    VLSEG6E8FFV,
    VLSEG6E16FFV,
    VLSEG6E32FFV,
    VLSEG6E64FFV,
    VLSEG7E8FFV,
    VLSEG7E16FFV,
    VLSEG7E32FFV,
    VLSEG7E64FFV,
    VLSEG8E8FFV,
    VLSEG8E16FFV,
    VLSEG8E32FFV,
    VLSEG8E64FFV,
    VLSSEG2E8V,
    VSSSEG2E8V,
    VLSSEG2E16V,
    VSSSEG2E16V,
    VLSSEG2E32V,
    VSSSEG2E32V,
    VLSSEG2E64V,
    VSSSEG2E64V,
    VLSSEG3E8V,
    VSSSEG3E8V,
    VLSSEG3E16V,
    VSSSEG3E16V,
    VLSSEG3E32V,
    VSSSEG3E32V,
    VLSSEG3E64V,
    VSSSEG3E64V,
    VLSSEG4E8V,
    VSSSEG4E8V,
    VLSSEG4E16V,
    VSSSEG4E16V,
    VLSSEG4E32V,
    VSSSEG4E32V,
    VLSSEG4E64V,
    VSSSEG4E64V,
    VLSSEG5E8V,
    VSSSEG5E8V,
    VLSSEG5E16V,
    VSSSEG5E16V,
    VLSSEG5E32V,
    VSSSEG5E32V,
    VLSSEG5E64V,
    VSSSEG5E64V,
    VLSSEG6E8V,
    VSSSEG6E8V,
    VLSSEG6E16V,
    VSSSEG6E16V,
    VLSSEG6E32V,
    VSSSEG6E32V,
    VLSSEG6E64V,
    VSSSEG6E64V,
    VLSSEG7E8V,
    VSSSEG7E8V,
    VLSSEG7E16V,
    VSSSEG7E16V,
    VLSSEG7E32V,
    VSSSEG7E32V,
    VLSSEG7E64V,
    VSSSEG7E64V,
    VLSSEG8E8V,
    VSSSEG8E8V,
    VLSSEG8E16V,
    VSSSEG8E16V,
    VLSSEG8E32V,
    VSSSEG8E32V,
    VLSSEG8E64V,
    VSSSEG8E64V,
    VLUXSEG2EI8V,
    VLOXSEG2EI8V,
    VSUXSEG2EI8V,
    VSOXSEG2EI8V,
    VLUXSEG2EI16V,
    VLOXSEG2EI16V,
    VSUXSEG2EI16V,
    VSOXSEG2EI16V,
    VLUXSEG2EI32V,
    VLOXSEG2EI32V,
    VSUXSEG2EI32V,
    VSOXSEG2EI32V,
    VLUXSEG2EI64V,
    VLOXSEG2EI64V,
    VSUXSEG2EI64V,
    VSOXSEG2EI64V,
    VLUXSEG3EI8V,
    VLOXSEG3EI8V,
    VSUXSEG3EI8V,
    VSOXSEG3EI8V,
    VLUXSEG3EI16V,
    VLOXSEG3EI16V,
    VSUXSEG3EI16V,
    VSOXSEG3EI16V,
    VLUXSEG3EI32V,
    VLOXSEG3EI32V,
    VSUXSEG3EI32V,
    VSOXSEG3EI32V,
    VLUXSEG3EI64V,
    VLOXSEG3EI64V,
    VSUXSEG3EI64V,
    VSOXSEG3EI64V,
    VLUXSEG4EI8V,
    VLOXSEG4EI8V,
    VSUXSEG4EI8V,
    VSOXSEG4EI8V,
    VLUXSEG4EI16V,
    VLOXSEG4EI16V,
    VSUXSEG4EI16V,
    VSOXSEG4EI16V,
    VLUXSEG4EI32V,
    VLOXSEG4EI32V,
    VSUXSEG4EI32V,
    VSOXSEG4EI32V,
    VLUXSEG4EI64V,
    VLOXSEG4EI64V,
    VSUXSEG4EI64V,
    VSOXSEG4EI64V,
    VLUXSEG5EI8V,
    VLOXSEG5EI8V,
    VSUXSEG5EI8V,
    VSOXSEG5EI8V,
    VLUXSEG5EI16V,
    VLOXSEG5EI16V,
    VSUXSEG5EI16V,
    VSOXSEG5EI16V,
    VLUXSEG5EI32V,
    VLOXSEG5EI32V,
    VSUXSEG5EI32V,
    VSOXSEG5EI32V,
    VLUXSEG5EI64V,
    VLOXSEG5EI64V,
    VSUXSEG5EI64V,
    VSOXSEG5EI64V,
    VLUXSEG6EI8V,
    VLOXSEG6EI8V,
    VSUXSEG6EI8V,
    VSOXSEG6EI8V,
    VLUXSEG6EI16V,
    VLOXSEG6EI16V,
    VSUXSEG6EI16V,
    VSOXSEG6EI16V,
    VLUXSEG6EI32V,
    VLOXSEG6EI32V,
    VSUXSEG6EI32V,
    VSOXSEG6EI32V,
    VLUXSEG6EI64V,
    VLOXSEG6EI64V,
    VSUXSEG6EI64V,
    VSOXSEG6EI64V,
    VLUXSEG7EI8V,
    VLOXSEG7EI8V,
    VSUXSEG7EI8V,
    VSOXSEG7EI8V,
    VLUXSEG7EI16V,
    VLOXSEG7EI16V,
    VSUXSEG7EI16V,
    VSOXSEG7EI16V,
    VLUXSEG7EI32V,
    VLOXSEG7EI32V,
    VSUXSEG7EI32V,
    VSOXSEG7EI32V,
    VLUXSEG7EI64V,
    VLOXSEG7EI64V,
    VSUXSEG7EI64V,
    VSOXSEG7EI64V,
    VLUXSEG8EI8V,
    VLOXSEG8EI8V,
    VSUXSEG8EI8V,
    VSOXSEG8EI8V,
    VLUXSEG8EI16V,
    VLOXSEG8EI16V,
    VSUXSEG8EI16V,
    VSOXSEG8EI16V,
    VLUXSEG8EI32V,
    VLOXSEG8EI32V,
    VSUXSEG8EI32V,
    VSOXSEG8EI32V,
    VLUXSEG8EI64V,
    VLOXSEG8EI64V,
    VSUXSEG8EI64V,
    VSOXSEG8EI64V,
    VL1RE8V,
    VL1RE16V,
    VL1RE32V,
    VL1RE64V,
    VL2RE8V,
    VL2RE16V,
    VL2RE32V,
    VL2RE64V,
    VL4RE8V,
    VL4RE16V,
    VL4RE32V,
    VL4RE64V,
    VL8RE8V,
    VL8RE16V,
    VL8RE32V,
    VL8RE64V,
    VS1RV,
    VS2RV,
    VS4RV,
    VS8RV,
    VADDVV,
    VADDVX,
    VADDVI,
    VSUBVV,
    VSUBVX,
    VRSUBVX,
    VRSUBVI,
    VWADDUVV,
    VWADDUVX,
    VWSUBUVV,
    VWSUBUVX,
    VWADDVV,
    VWADDVX,
    VWSUBVV,
    VWSUBVX,
    VWADDUWV,
    VWADDUWX,
    VWSUBUWV,
    VWSUBUWX,
    VWADDWV,
    VWADDWX,
    VWSUBWV,
    VWSUBWX,
    VZEXTVF2,
    VSEXTVF2,
    VZEXTVF4,
    VSEXTVF4,
    VZEXTVF8,
    VSEXTVF8,
    VADCVVM,
    VADCVXM,
    VADCVIM,
    VMADCVVM,
    VMADCVXM,
    VMADCVIM,
    VMADCVV,
    VMADCVX,
    VMADCVI,
    VSBCVVM,
    VSBCVXM,
    VMSBCVVM,
    VMSBCVXM,
    VMSBCVV,
    VMSBCVX,
    VANDVV,
    VANDVX,
    VANDVI,
    VORVV,
    VORVX,
    VORVI,
    VXORVV,
    VXORVX,
    VXORVI,
    VSLLVV,
    VSLLVX,
    VSLLVI,
    VSRLVV,
    VSRLVX,
    VSRLVI,
    VSRAVV,
    VSRAVX,
    VSRAVI,
    VNSRLWV,
    VNSRLWX,
    VNSRLWI,
    VNSRAWV,
    VNSRAWX,
    VNSRAWI,
    VMSEQVV,
    VMSEQVX,
    VMSEQVI,
    VMSNEVV,
    VMSNEVX,
    VMSNEVI,
    VMSLTUVV,
    VMSLTUVX,
    VMSLTVV,
    VMSLTVX,
    VMSLEUVV,
    VMSLEUVX,
    VMSLEUVI,
    VMSLEVV,
    VMSLEVX,
    VMSLEVI,
    VMSGTUVX,
    VMSGTUVI,
    VMSGTVX,
    VMSGTVI,
    VMINUVV,
    VMINUVX,
    VMINVV,
    VMINVX,
    VMAXUVV,
    VMAXUVX,
    VMAXVV,
    VMAXVX,
    VMULVV,
    VMULVX,
    VMULHVV,
    VMULHVX,
    VMULHUVV,
    VMULHUVX,
    VMULHSUVV,
    VMULHSUVX,
    VDIVUVV,
    VDIVUVX,
    VDIVVV,
    VDIVVX,
    VREMUVV,
    VREMUVX,
    VREMVV,
    VREMVX,
    VWMULVV,
    VWMULVX,
    VWMULUVV,
    VWMULUVX,
    VWMULSUVV,
    VWMULSUVX,
    VMACCVV,
    VMACCVX,
    VNMSACVV,
    VNMSACVX,
    VMADDVV,
    VMADDVX,
    VNMSUBVV,
    VNMSUBVX,
    VMWACCUVV,
    VMWACCUVX,
    VWMACCVV,
    VWMACCVX,
    VWMACCSUVV,
    VWMACCSUVX,
    VWMACCUSVX,
    VMERGEVVM,
    VMERGEVXM,
    VMERGEVIM,
    VMVVV,
    VMVVX,
    VMVVI,
    VSADDUVV,
    VSADDUVX,
    VSADDUVI,
    VSADDVV,
    VSADDVX,
    VSADDVI,
    VSSUBUVV,
    VSSUBUVX,
    VSSUBVV,
    VSSUBVX,
    VAADDUVV,
    VAADDUVX,
    VAADDVV,
    VAADDVX,
    VASUBUVV,
    VASUBUVX,
    VASUBVV,
    VASUBVX,
    VSMULVV,
    VSMULVX,
    VSSRLVV,
    VSSRLVX,
    VSSRLVI,
    VSSRAVV,
    VSSRAVX,
    VSSRAVI,
    VNCLIPUWV,
    VNCLIPUWX,
    VNCLIPUWI,
    VNCLIPWV,
    VNCLIPWX,
    VNCLIPWI,
    VFADDVV,
    VFADDVF,
    VFSUBVV,
    VFSUBVF,
    VFRSUBVF,
    VFWADDVV,
    VFWADDVF,
    VFWSUBVV,
    VFWSUBVF,
    VFWADDWV,
    VFWADDWF,
    VFWSUBWV,
    VFWSUBWF,
    VFMULVV,
    VFMULVF,
    VFDIVVV,
    VFDIVVF,
    VFRDIVVF,
    VFWMULVV,
    VFWMULVF,
    VFMACCVV,
    VFMACCVF,
    VFNMACCVV,
    VFNMACCVF,
    VFMSACVV,
    VFMSACVF,
    VFNMSACVV,
    VFNMSACVF,
    VFMADDVV,
    VFMADDVF,
    VFNMADDVV,
    VFNMADDVF,
    VFMSUBVV,
    VFMSUBVF,
    VFNMSUBVV,
    VFNMSUBVF,
    VFWMACCVV,
    VFWMACCVF,
    VFWNMACCVV,
    VFWNMACCVF,
    VFWMSACVV,
    VFWMSACVF,
    VFWNMSACVV,
    VFWNMSACVF,
    VFSQRTV,
    VFRSQRT7V,
    VFREC7V,
    VFMINVV,
    VFMINVF,
    VFMAXVV,
    VFMAXVF,
    VFSGNJVV,
    VFSGNJVF,
    VFSGNJNVV,
    VFSGNJNVF,
    VFSGNJXVV,
    VFSGNJXVF,
    VMFEQVV,
    VMFEQVF,
    VMFNEVV,
    VMFNEVF,
    VMFLTVV,
    VMFLTVF,
    VMFLEVV,
    VMFLEVF,
    VMFGTVF,
    VMFGEVF,
    VFCLASSV,
    VFMERGEVFM,
    VFMVVF,
    VFCVTXUFV,
    VFCVTXFV,
    VFCVTRTZXUFV,
    VFCVTRTZXFV,
    VFCVTFXUV,
    VFCVTFXV,
    VFWCVTXUFV,
    VFWCVTXFV,
    VFWCVTRTZXUFV,
    VFWCVTRTZXFV,
    VFWCVTFXUV,
    VFWCVTFXV,
    VFWCVTFFV,
    VFNCVTXUFW,
    VFNCVTXFW,
    VFNCVTRTZXUFW,
    VFNCVTRTZXFW,
    VFNCVTFXUW,
    VFNCVTFXW,
    VFNCVTFFW,
    VFNCVTRODFFW,
    VREDSUMVS,
    VREDMAXUVS,
    VREDMAXVS,
    VREDMINUVS,
    VREDMINVS,
    VREDANDVS,
    VREDORVS,
    VREDXORVS,
    VWREDSUMUVS,
    VWREDSUMVS,
    VFREDOSUMVS,
    VFREDUSUMVS,
    VFREDMAXVS,
    VFREDMINVS,
    VFWREDOSUMVS,
    VFWREDUSUMVS,
    VMANDMM,
    VMNANDMM,
    VMANDNMM,
    VMXORMM,
    VMORMM,
    VMNORMM,
    VMORNMM,
    VMXNORMM,
    VMMVM,
    VMCLRM,
    VMSETM,
    VMNOTM,
    VCPOPM,
    VCPOPM,
    VFIRSTM,
    VMSBFM,
    VMSIFM,
    VMSOFM,
    VIOTAM,
    VIDV,
    VMVXS,
    VMVSX,
    VFMVFS,
    VFMVSF,
    VSLIDEUPVX,
    VSLIDEUPVI,
    VSLIDEDOWNVX,
    VSLIDEDOWNVI,
    VSLIDE1UPVX,
    VFSLIDE1UPVF,
    VSLIDE1DOWNVX,
    VFSLIDE1DOWNVF,
    VRGATHERVV,
    VRGATHEREI16VV,
    VRGATHERVX,
    VRGATHERVI,
    VCOMPRESSVM,
    VMV1RV,
    VMV2RV,
    VMV4RV,
    VMV8RV,
};

enum class RVInstructionFormat : uint8_t {
    R,
    I,
    S,
    B,
    U,
    J,
    R4,
    CR,
    CI,
    CSS,
    CIW,
    CL,
    CS,
    CA,
    CB,
    CJ,
    VL,
    VLS,
    VLX,
    VS,
    VSS,
    VSX,
};

enum class RVInstructionSet : uint8_t {
    RV32I,
    RV64I,
    RV32M,
    RV64M,
    RV32A,
    RV64A,
    RV32F,
    RV64F,
    RV32D,
    RV64D,
    RV32Q,
    RV64Q,
    RV32Zfh,
    RV64Zfh,
    Zifencei,
    Zicsr,
    Zawrs,
    C,
    V
};

struct special_snowflake_args {
    std::optional<uint8_t> rs2;
    bool use_rm_for_funct3 = false;
    bool use_imm_for_rs2 = false;
    bool super_special_snowflake = false;
};

struct rvinstruction {
    std::string_view name;
    RVInstructionFormat type;
    RVInstructionID id;
    uint8_t opcode;
    uint16_t funct;
    RVInstructionSet set;
    special_snowflake_args ssargs = {};
};

extern const std::array<rvinstruction, 335> instructions;

} // namespace libchata_internal