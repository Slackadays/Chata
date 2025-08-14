// SPDX-License-Identifier: MPL-2.0
#include <array>
#include <charconv>
#include <cstdint>
#include <cstring>
#include <iostream>
#include <memory>
#include <new>
#include <optional>
#include <span>
#include <string_view>
#include <unistd.h>
#include <vector>

#pragma once

#if defined(__linux__) || defined(__unix__) || defined(__APPLE__) || defined(__NetBSD__) || defined(__OpenBSD__) || defined(__DragonFly__) || defined(__HAIKU__) || defined(__FreeBSD__) \
        || defined(__posix__)
#define UNIX_OR_UNIX_LIKE
#endif

enum class RVInstructionSet : uint8_t {
    RV32E,
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
    Zfinx,
    Zdinx,
    Zhinx,
    Zhinxmin,
    Zmmul,
    Zaamo,
    Zalrsc,
    Zifencei,
    Zicsr,
    Zawrs,
    Zicond,
    Zacas,
    Zabha,
    Zicbom,
    Zicboz,
    Zicbop,
    Zce,
    Zcb,
    Zbb,
    Zcmp,
    C,
    Zcd,
    Zcf,
    Zcmt,
    Zfa,
    Zimop,
    B,
    V,
    Zvl32b,
    Zvl64b,
    Zvl128b,
    Zvl256b,
    Zvl512b,
    Zvl1024b,
    Zve32x,
    Zve32f,
    Zve64x,
    Zve64f,
    Zve64d,
    Zvfhmin,
    Zvfh,
    Zbkb,
    Zbkc,
    Zbkx,
    Zknd,
    Zkne,
    Zknh,
    Zksed,
    Zksh,
    Zkr,
    Zkn,
    Zks,
    Zk,
    Zkt,
    Zvbb,
    Zvbc,
    Zvkb,
    Zvkg,
    Zvkned,
    Zvknh,
    Zvknhab,
    Zvknhb,
    Zvksed,
    Zvkn,
    Zvknc,
    Zvkng,
    Zvks,
    Zvksc,
    Zvksg,
    Zvkt,
    Zvksh,
    XTheadCmo,
    XTheadSync,
    XTheadBa,
    XTheadBb,
    XTheadBs,
    XTheadCondMov,
    XTheadMemIdx,
    XTheadMemPair,
    XTheadFMemIdx,
    XTheadMac,
    XTheadFmv,
    XTheadVdot,
    XTheadVector,
    XTheadZvamo
};

enum class UASErrorID {
    GenericError,
    InvalidRelocationMode,
    InvalidRegisterGeneric,
    InvalidRegisterPositional,
    InvalidRegisterSpecial,
    InvalidRoundingMode,
    InvalidFence,
    InvalidCSR,
    InvalidFLI,
    InvalidOperator,
    ImmOutOfRange,
    InvalidImm,
    InvalidPrefetch,
    InvalidPrefetchReg,
    InvalidVSEW,
    InvalidVtypei,
    InvalidRelImm,
    InvalidIndex,
    InvalidStackAdj,
    InvalidRegList,
    InvalidOpcode,
    InvalidInstruction,
    InstLenMismatch,
    InvalidEqu,
    InvalidDirective,
    NotEnoughSets,
    OutOfMemory,
    InvalidInt,
    InvalidFloat,
    InvalidInstLen,
    InvalidInstArguments
};

class UASError;

namespace ultrassembler_internal {

#if defined(DEBUG)
#define DBG(x) x
#else
#define DBG(x)
#endif
} // namespace ultrassembler_internal

namespace ultrassembler_internal {

using enum UASErrorID;

constexpr size_t memory_pool_size = 33554432;

template <class T>
class MemoryBank;

typedef std::basic_string<char, std::char_traits<char>, MemoryBank<char>> ultrastring;

template <typename T>
using ultravector = std::vector<T, MemoryBank<T>>;

ultrastring to_ultrastring(const int32_t& num);

class GlobalMemoryBank {
    inline static std::array<std::byte, memory_pool_size> pool;
    inline static size_t used = 0;
    inline static long pagesize = sysconf(_SC_PAGE_SIZE);

public:
    void* grab_some_memory(size_t requested);

    void* grab_aligned_memory(size_t requested);

    void reset();
};

extern GlobalMemoryBank memory_bank;

template <class T>
class MemoryBank {
public:
    using value_type = T;

    MemoryBank() = default;

    [[nodiscard]] T* allocate(size_t requested) {
        std::size_t bytes = requested * sizeof(T);
        return reinterpret_cast<T*>(memory_bank.grab_some_memory(bytes));
    }

    void deallocate(T* ptr, size_t requested) { return; }

    bool operator==(const MemoryBank&) const { return true; }
};

template <class T>
class AlignedMemory {
public:
    using value_type = T;

    AlignedMemory() = default;

    [[nodiscard]] T* allocate(size_t requested) {
        std::size_t bytes = requested * sizeof(T);
        return reinterpret_cast<T*>(memory_bank.grab_aligned_memory(bytes));
    }

    void deallocate(T* ptr, size_t requested) { return; }
};

ultravector<uint8_t> assemble_code(const std::string_view& data, const ultravector<RVInstructionSet> sets = {});

bool fast_eq(const auto& first, const std::string_view& second) {
    if (first.size() != second.size()) { // First make sure the sizes are equal because no two strings can ever be the same if they have different sizes. Also, this lets us save on future bound checks
                                         // because we're already checking it here.
        return false;
    }
    for (size_t i = 0; i < first.size(); i++) {
        if (first[i] != second[i]) {
            [[likely]] return false;
        } else {
            [[unlikely]] continue;
        }
    }
    return true;
}

template <typename T>
std::optional<T> to_num(const ultrastring& str) {
    T result = 0;
    std::from_chars_result res;
    int relocation_mode = 0; // 0 = normal, -1 = %lo(symbol), 1 = %hi(symbol)
    size_t relocation_offset = 0;
    // Check if we follow the format %lo(symbol) or %hi(symbol)
    if (str.size() > 5) {
        DBG(std::cout << "Checking for relocation mode" << std::endl;)
        if (str[0] == '%') {
            if (str[1] == 'l' && str[2] == 'o' && str[3] == '(' && str[str.size() - 1] == ')') {
                DBG(std::cout << "Found %lo relocation mode" << std::endl;)
                relocation_mode = -1;
                relocation_offset = 4;
            } else if (str[1] == 'h' && str[2] == 'i' && str[3] == '(' && str[str.size() - 1] == ')') {
                DBG(std::cout << "Found %hi relocation mode" << std::endl;)
                relocation_mode = 1;
                relocation_offset = 4;
            } else {
                throw UASError(InvalidRelocationMode, "Invalid relocation mode " + str);
            }
        }
    }

    if (str.size() > 2) {
        if constexpr (std::is_same<T, float>::value) {
            res = std::from_chars(str.data() + relocation_offset, str.data() + str.size(), result);
        } else {
            if (str[0 + relocation_offset] == '0') {
                if (str[1 + relocation_offset] == 'x' || str[1 + relocation_offset] == 'X') {
                    res = std::from_chars(str.data() + 2 + relocation_offset, str.data() + str.size(), result, 16);
                } else if (str[1 + relocation_offset] == 'b' || str[1 + relocation_offset] == 'B') {
                    res = std::from_chars(str.data() + 2 + relocation_offset, str.data() + str.size(), result, 2);
                } else {
                    res = std::from_chars(str.data() + relocation_offset, str.data() + str.size(), result);
                }
            } else if (str[0 + relocation_offset] == '-' && str[1 + relocation_offset] == '0') {
                if (str.size() > 3) {
                    if (str[2 + relocation_offset] == 'x' || str[2 + relocation_offset] == 'X') {
                        res = std::from_chars(str.data() + 3 + relocation_offset, str.data() + str.size(), result, 16);
                        result = -result;
                    } else if (str[2 + relocation_offset] == 'b' || str[2 + relocation_offset] == 'B') {
                        res = std::from_chars(str.data() + 3 + relocation_offset, str.data() + str.size(), result, 2);
                        result = -result;
                    } else {
                        res = std::from_chars(str.data() + relocation_offset, str.data() + str.size(), result);
                    }
                } else {
                    res = std::from_chars(str.data() + relocation_offset, str.data() + str.size(), result);
                }
            } else {
                res = std::from_chars(str.data() + relocation_offset, str.data() + str.size(), result);
            }
        }

    } else {
        res = std::from_chars(str.data() + relocation_offset, str.data() + str.size(), result);
    }

    if (relocation_offset != 0) {
        relocation_offset = -1;
    }

    if (res.ec != std::errc() || res.ptr != str.data() + str.size() + relocation_offset) {
        DBG(std::cout << "Conversion failed" << std::endl;)
        return std::nullopt;
    }

    if constexpr (!std::is_same<T, float>::value) {
        if (relocation_mode == -1) {       // %lo()
            result = (result << 20) >> 20; // This preserves the sign bit
        } else if (relocation_mode == 1) { // %hi()
            result = (result >> 12) & 0xFFFFF;
        }
    }

    DBG(std::cout << "result = " << result << std::endl;)

    return result;
}

} // namespace ultrassembler_internal

class UASError : public std::exception {
    std::string_view color_start = "\033[1;31m";
    std::string_view color_end = "\033[0m";

    void set_color() {
        if (getenv("NO_COLOR") != nullptr) {
            color_start = "";
            color_end = "";
        }
    }

public:
    UASErrorID type;
    std::optional<std::string_view> details;
    std::optional<uint32_t> line = 0;
    std::optional<uint32_t> column = 0;
    std::optional<ultrassembler_internal::ultrastring> line_content;

    char* what() {
        set_color();
        ultrassembler_internal::ultrastring error_message;
        error_message += "| ";
        error_message += color_start;
        error_message += "Ultrassembler error";
        error_message += color_end;
        error_message += " at line ";
        if (line.has_value()) {
            error_message += ultrassembler_internal::to_ultrastring(*line);
        } else {
            error_message += "(unknown)";
        }
        error_message += ", column ";
        if (column.has_value()) {
            error_message += ultrassembler_internal::to_ultrastring(*column);
        } else {
            error_message += "(unknown)";
        }
        error_message += ":\n| ";

        if (line_content.has_value()) {
            error_message += "\n| ";
            if (line.has_value()) {
                error_message += ultrassembler_internal::to_ultrastring(line.value());
            } else {
                error_message += "(unknown)";
            }
            error_message += ":";
            if (column.has_value()) {
                error_message += ultrassembler_internal::to_ultrastring(column.value());
            } else {
                error_message += "(unknown)";
            }
            error_message += " | ";
            error_message += line_content.value();
        }
        return error_message.data();
    }

    UASError(UASErrorID type, std::string_view details, uint32_t line, uint32_t column)
            : type(type)
            , details(details)
            , line(line)
            , column(column) {}

    UASError(UASErrorID type, std::string_view details, uint32_t line, uint32_t column, ultrassembler_internal::ultrastring line_content)
            : type(type)
            , details(details)
            , line(line)
            , column(column)
            , line_content(line_content) {}

    UASError(UASErrorID type, std::string_view details) : type(type), details(details) {}

    UASError(UASErrorID type, std::string_view details, ultrassembler_internal::ultrastring line_content) : type(type), details(details), line_content(line_content) {}
};

namespace ultrassembler {

void reset_memory_bank();

std::string_view version();

/**
 * @brief Assemble RISC-V assembly with Ultrassembler
 *
 * @param code The RISC-V assembly you want to assemble
 * @param supported_sets An array or vector of supported instruction sets to be used for bit-dependent instructions and architecture options
 * @return std::span<uint8_t>
 */
std::span<uint8_t> assemble(std::string_view code, std::span<RVInstructionSet> supported_sets = {});

} // namespace ultrassembler