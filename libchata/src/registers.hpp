// SPDX-License-Identifier: MPL-2.0
#include <array>
#include <string_view>
#include <cstdint>

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

enum class RegisterType : uint8_t {
    Integer,
    FloatingPoint,
    Vector
};

enum class RegisterID : uint8_t {
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

extern const std::array<rvregister, 96> registers;