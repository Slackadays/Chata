#include <array>
#include <string_view>

namespace libchata_internal {

constexpr std::array<std::string_view, 15> integer_register_replacement_priority_list = {"t0", "t1", "t2", "t3", "t4", "t5", "t6", "a0", "a1", "a2", "a3", "a4", "a5", "a6", "a7"};

constexpr std::array<std::string_view, 20> floating_point_register_replacement_priority_list = {"ft0",  "ft1",  "ft2", "ft3", "ft4", "ft5", "ft6", "ft7", "ft8", "ft9",
                                                                                                "ft10", "ft11", "fa0", "fa1", "fa2", "fa3", "fa4", "fa5", "fa6", "fa7"};

constexpr std::array<std::string_view, 56> valid_integer_registers = {
        "x0",   "x5", "x6", "x7", "x8", "x9", "x10", "x11", "x12", "x13", "x14", "x15", "x16", "x17", "x18", "x19", "x20", "x21", "x22", "x23", "x24", "x25", "x26", "x27", "x28", "x29", "x30", "x31",
        "zero", "t0", "t1", "t2", "s0", "s1", "a0",  "a1",  "a2",  "a3",  "a4",  "a5",  "a6",  "a7",  "s2",  "s3",  "s4",  "s5",  "s6",  "s7",  "s8",  "s9",  "s10", "s11", "t3",  "t4",  "t5",  "t6"};

constexpr std::array<std::string_view, 64> valid_floating_point_registers = {"f0",  "f1",  "f2",   "f3",   "f4",  "f5",  "f6",  "f7",  "f8",  "f9",  "f10", "f11", "f12", "f13", "f14",  "f15",
                                                                             "f16", "f17", "f18",  "f19",  "f20", "f21", "f22", "f23", "f24", "f25", "f26", "f27", "f28", "f29", "f30",  "f31",
                                                                             "fa0", "fa1", "fa2",  "fa3",  "fa4", "fa5", "fa6", "fa7", "ft0", "ft1", "ft2", "ft3", "ft4", "ft5", "ft6",  "ft7",
                                                                             "ft8", "ft9", "ft10", "ft11", "fs0", "fs1", "fs2", "fs3", "fs4", "fs5", "fs6", "fs7", "fs8", "fs9", "fs10", "fs11"};

constexpr std::array<std::string_view, 32> valid_vector_registers = {"v0",  "v1",  "v2",  "v3",  "v4",  "v5",  "v6",  "v7",  "v8",  "v9",  "v10", "v11", "v12", "v13", "v14", "v15",
                                                                     "v16", "v17", "v18", "v19", "v20", "v21", "v22", "v23", "v24", "v25", "v26", "v27", "v28", "v29", "v30", "v31"};

enum class RegisterType {
    Integer,
    FloatingPoint,
    Vector
};

enum class RegisterID {
    x0,
    x1,
    x2,
    x3,
    x4,
    x5,
    x6,
    x7,
    x8,
    x9,
    x10,
    x11,
    x12,
    x13,
    x14,
    x15,
    x16,
    x17,
    x18,
    x19,
    x20,
    x21,
    x22,
    x23,
    x24,
    x25,
    x26,
    x27,
    x28,
    x29,
    x30,
    x31,
    f0,
    f1,
    f2,
    f3,
    f4,
    f5,
    f6,
    f7,
    f8,
    f9,
    f10,
    f11,
    f12,
    f13,
    f14,
    f15,
    f16,
    f17,
    f18,
    f19,
    f20,
    f21,
    f22,
    f23,
    f24,
    f25,
    f26,
    f27,
    f28,
    f29,
    f30,
    f31,
    v0,
    v1,
    v2,
    v3,
    v4,
    v5,
    v6,
    v7,
    v8,
    v9,
    v10,
    v11,
    v12,
    v13,
    v14,
    v15,
    v16,
    v17,
    v18,
    v19,
    v20,
    v21,
    v22,
    v23,
    v24,
    v25,
    v26,
    v27,
    v28,
    v29,
    v30,
    v31
};

struct rvregister {
    std::string_view name;
    std::string_view alias;
    RegisterType type;
    RegisterID id;
    uint8_t encoding;
};

constexpr std::array<rvregister, 96> registers = {
        {{"x0", "zero", RegisterType::Integer, RegisterID::x0, 0},
         {"x1", "ra", RegisterType::Integer, RegisterID::x1, 1},
         {"x2", "fp", RegisterType::Integer, RegisterID::x2, 2},
         {"x3", "sp", RegisterType::Integer, RegisterID::x3, 3},
         {"x4", "gp", RegisterType::Integer, RegisterID::x4, 4},
         {"x5", "t0", RegisterType::Integer, RegisterID::x5, 5},
         {"x6", "t1", RegisterType::Integer, RegisterID::x6, 6},
         {"x7", "t2", RegisterType::Integer, RegisterID::x7, 7},
         {"x8", "s0", RegisterType::Integer, RegisterID::x8, 8},
         {"x9", "s1", RegisterType::Integer, RegisterID::x9, 9},
         {"x10", "a0", RegisterType::Integer, RegisterID::x10, 10},
         {"x11", "a1", RegisterType::Integer, RegisterID::x11, 11},
         {"x12", "a2", RegisterType::Integer, RegisterID::x12, 12},
         {"x13", "a3", RegisterType::Integer, RegisterID::x13, 13},
         {"x14", "a4", RegisterType::Integer, RegisterID::x14, 14},
         {"x15", "a5", RegisterType::Integer, RegisterID::x15, 15},
         {"x16", "a6", RegisterType::Integer, RegisterID::x16, 16},
         {"x17", "a7", RegisterType::Integer, RegisterID::x17, 17},
         {"x18", "s2", RegisterType::Integer, RegisterID::x18, 18},
         {"x19", "s3", RegisterType::Integer, RegisterID::x19, 19},
         {"x20", "s4", RegisterType::Integer, RegisterID::x20, 20},
         {"x21", "s5", RegisterType::Integer, RegisterID::x21, 21},
         {"x22", "s6", RegisterType::Integer, RegisterID::x22, 22},
         {"x23", "s7", RegisterType::Integer, RegisterID::x23, 23},
         {"x24", "s8", RegisterType::Integer, RegisterID::x24, 24},
         {"x25", "s9", RegisterType::Integer, RegisterID::x25, 25},
         {"x26", "s10", RegisterType::Integer, RegisterID::x26, 26},
         {"x27", "s11", RegisterType::Integer, RegisterID::x27, 27},
         {"x28", "t3", RegisterType::Integer, RegisterID::x28, 28},
         {"x29", "t4", RegisterType::Integer, RegisterID::x29, 29},
         {"x30", "t5", RegisterType::Integer, RegisterID::x30, 30},
         {"x31", "t6", RegisterType::Integer, RegisterID::x31, 31},
         {"f0", "fa0", RegisterType::FloatingPoint, RegisterID::f0, 0},
         {"f1", "fa1", RegisterType::FloatingPoint, RegisterID::f1, 1},
         {"f2", "fa2", RegisterType::FloatingPoint, RegisterID::f2, 2},
         {"f3", "fa3", RegisterType::FloatingPoint, RegisterID::f3, 3},
         {"f4", "fa4", RegisterType::FloatingPoint, RegisterID::f4, 4},
         {"f5", "fa5", RegisterType::FloatingPoint, RegisterID::f5, 5},
         {"f6", "fa6", RegisterType::FloatingPoint, RegisterID::f6, 6},
         {"f7", "fa7", RegisterType::FloatingPoint, RegisterID::f7, 7},
         {"f8", "ft0", RegisterType::FloatingPoint, RegisterID::f8, 8},
         {"f9", "ft1", RegisterType::FloatingPoint, RegisterID::f9, 9},
         {"f10", "ft2", RegisterType::FloatingPoint, RegisterID::f10, 10},
         {"f11", "ft3", RegisterType::FloatingPoint, RegisterID::f11, 11},
         {"f12", "ft4", RegisterType::FloatingPoint, RegisterID::f12, 12},
         {"f13", "ft5", RegisterType::FloatingPoint, RegisterID::f13, 13},
         {"f14", "ft6", RegisterType::FloatingPoint, RegisterID::f14, 14},
         {"f15", "ft7", RegisterType::FloatingPoint, RegisterID::f15, 15},
         {"f16", "ft8", RegisterType::FloatingPoint, RegisterID::f16, 16},
         {"f17", "ft9", RegisterType::FloatingPoint, RegisterID::f17, 17},
         {"f18", "ft10", RegisterType::FloatingPoint, RegisterID::f18, 18},
         {"f19", "ft11", RegisterType::FloatingPoint, RegisterID::f19, 19},
         {"f20", "fs0", RegisterType::FloatingPoint, RegisterID::f20, 20},
         {"f21", "fs1", RegisterType::FloatingPoint, RegisterID::f21, 21},
         {"f22", "fs2", RegisterType::FloatingPoint, RegisterID::f22, 22},
         {"f23", "fs3", RegisterType::FloatingPoint, RegisterID::f23, 23},
         {"f24", "fs4", RegisterType::FloatingPoint, RegisterID::f24, 24},
         {"f25", "fs5", RegisterType::FloatingPoint, RegisterID::f25, 25},
         {"f26", "fs6", RegisterType::FloatingPoint, RegisterID::f26, 26},
         {"f27", "fs7", RegisterType::FloatingPoint, RegisterID::f27, 27},
         {"f28", "fs8", RegisterType::FloatingPoint, RegisterID::f28, 28},
         {"f29", "fs9", RegisterType::FloatingPoint, RegisterID::f29, 29},
         {"f30", "fs10", RegisterType::FloatingPoint, RegisterID::f30, 30},
         {"f31", "fs11", RegisterType::FloatingPoint, RegisterID::f31, 31},
         {"v0", "v0", RegisterType::Vector, RegisterID::v0, 0},
         {"v1", "v1", RegisterType::Vector, RegisterID::v1, 1},
         {"v2", "v2", RegisterType::Vector, RegisterID::v2, 2},
         {"v3", "v3", RegisterType::Vector, RegisterID::v3, 3},
         {"v4", "v4", RegisterType::Vector, RegisterID::v4, 4},
         {"v5", "v5", RegisterType::Vector, RegisterID::v5, 5},
         {"v6", "v6", RegisterType::Vector, RegisterID::v6, 6},
         {"v7", "v7", RegisterType::Vector, RegisterID::v7, 7},
         {"v8", "v8", RegisterType::Vector, RegisterID::v8, 8},
         {"v9", "v9", RegisterType::Vector, RegisterID::v9, 9},
         {"v10", "v10", RegisterType::Vector, RegisterID::v10, 10},
         {"v11", "v11", RegisterType::Vector, RegisterID::v11, 11},
         {"v12", "v12", RegisterType::Vector, RegisterID::v12, 12},
         {"v13", "v13", RegisterType::Vector, RegisterID::v13, 13},
         {"v14", "v14", RegisterType::Vector, RegisterID::v14, 14},
         {"v15", "v15", RegisterType::Vector, RegisterID::v15, 15},
         {"v16", "v16", RegisterType::Vector, RegisterID::v16, 16},
         {"v17", "v17", RegisterType::Vector, RegisterID::v17, 17},
         {"v18", "v18", RegisterType::Vector, RegisterID::v18, 18},
         {"v19", "v19", RegisterType::Vector, RegisterID::v19, 19},
         {"v20", "v20", RegisterType::Vector, RegisterID::v20, 20},
         {"v21", "v21", RegisterType::Vector, RegisterID::v21, 21},
         {"v22", "v22", RegisterType::Vector, RegisterID::v22, 22},
         {"v23", "v23", RegisterType::Vector, RegisterID::v23, 23},
         {"v24", "v24", RegisterType::Vector, RegisterID::v24, 24},
         {"v25", "v25", RegisterType::Vector, RegisterID::v25, 25},
         {"v26", "v26", RegisterType::Vector, RegisterID::v26, 26},
         {"v27", "v27", RegisterType::Vector, RegisterID::v27, 27},
         {"v28", "v28", RegisterType::Vector, RegisterID::v28, 28},
         {"v29", "v29", RegisterType::Vector, RegisterID::v29, 29},
         {"v30", "v30", RegisterType::Vector, RegisterID::v30, 30},
         {"v31", "v31", RegisterType::Vector, RegisterID::v31, 31}}};

} // namespace libchata_internal