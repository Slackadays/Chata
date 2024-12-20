// SPDX-License-Identifier: MPL-2.0
#include <array>
#include <cstdint>
#include <string_view>
#include <optional>
#include <initializer_list>

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
    FCVTDH,
    FCVTDS,
    FCVTDW,
    FCVTDWU,
    FCVTHD,
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
    FMAXMD,
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
    CLQSP,
    CFLWSP,
    CFLDSP,
    CSWSP,
    CSDSP,
    CSQSP,
    CFSWSP,
    CFSDSP,
    CLW,
    CLD,
    CLQ,
    CFLW,
    CFLD,
    CSW,
    CSD,
    CSQ,
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
    CJ
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
    C
};

struct special_snowflake_args {
    std::optional<uint8_t> rs2;
    std::optional<bool> use_rm_for_funct3;
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

extern const std::array<rvinstruction, 171> instructions;
