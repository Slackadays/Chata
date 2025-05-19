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
    Zifencei,
    Zicsr,
    Zawrs,
    Zicond,
    Zacas,
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
    V
};

enum class ChataErrorType {
    Unspecified,
    Compiler,
    Assembler,
    Execution,
    Other
};

class ChataError;

namespace libchata_internal {

#if defined(DEBUG)
#define DBG(x) x
#else
#define DBG(x)
#endif

class InternalFile;
} // namespace libchata_internal

struct InputFile {
    std::string_view data;
    std::optional<std::string_view> filename;
};

namespace libchata_internal {

constexpr size_t memory_pool_size = 33554432;

template <class T>
class MemoryBank;

typedef std::basic_string<char, std::char_traits<char>, MemoryBank<char>> chatastring;

template <typename T>
using chatavector = std::vector<T, MemoryBank<T>>;

chatastring to_chatastring(const int& num);
chatastring allocate_label(struct compilation_context& c);
chatastring allocate_label(int num);
chatastring allocate_int_register(struct compilation_context& c);
chatastring allocate_int_register(int num);
chatastring allocate_float_register(struct compilation_context& c);
chatastring allocate_float_register(int num);

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

struct InternalFile {
    chatastring data;
    std::optional<std::string_view> filename;
    InternalFile(const InputFile& file) : data(file.data.begin(), file.data.end()), filename(file.filename) {}
};

struct compilation_context {
    int generated_label_num = 0;
    int placeholder_temp_integer_register_num = 0;
    int placeholder_temp_floating_point_register_num = 0;
    int line = 1;
    int column = 0;
};

chatavector<uint8_t> assemble_code(const std::string_view& data, const chatavector<RVInstructionSet> sets = {});

chatastring compile_code(chatavector<InternalFile>& files);

bool is_float(const chatastring& str);

bool is_integer(const chatastring& str);

bool is_number(const chatastring& str);

double to_float(const chatastring& str);

bool is_int_register(chatastring& reg);

bool is_float_register(chatastring& reg);

void jump_to_next_line(InternalFile& file, struct compilation_context& c, size_t& i);

chatastring read_this_line(InternalFile& file, struct compilation_context& c, size_t& i);

int decimal_representation_of_float(const float& input);

void process_ifs(InternalFile& file, struct compilation_context& c);

void process_changes(InternalFile& file, struct compilation_context& c);

bool is_register_character(const char& c);

chatastring make_base_register(const chatastring& reg);

int extract_number_from_string(const chatastring& str);

constexpr std::string_view generated_label_prefix = "generated_code_label";

constexpr std::string_view placeholder_temp_integer_register = "generated_placeholder_integer_register";

constexpr std::string_view placeholder_temp_floating_point_register = "generated_placeholder_floating_point_register";

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
std::optional<T> to_num(const chatastring& str) {
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
                throw ChataError(ChataErrorType::Compiler, "Invalid relocation mode " + str);
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
        if (relocation_mode == -1) {
            result = result & 0xFFF;
        } else if (relocation_mode == 1) {
            result = (result >> 12) & 0xFFFFF;
        }
    }

    DBG(std::cout << "result = " << result << std::endl;)

    return result;
}

} // namespace libchata_internal

class ChataError : public std::exception {
    std::string_view color_start = "\033[1;31m";
    std::string_view color_end = "\033[0m";

    void set_color() {
        if (getenv("NO_COLOR") != nullptr) {
            color_start = "";
            color_end = "";
        }
    }

public:
    std::optional<ChataErrorType> type;
    std::optional<std::string_view> details;
    std::optional<std::string_view> filename;
    std::optional<uint32_t> line = 0;
    std::optional<uint32_t> column = 0;
    std::optional<libchata_internal::chatastring> line_content;

    char* what() {
        set_color();
        libchata_internal::chatastring error_message;
        error_message += "| ";
        error_message += color_start;
        if (!type.has_value()) {
            error_message += "Unspecified error";
        } else if (*type == ChataErrorType::Unspecified) {
            error_message += "Unspecified error";
        } else if (*type == ChataErrorType::Compiler) {
            error_message += "Compiler error";
        } else if (*type == ChataErrorType::Assembler) {
            error_message += "Assembler error";
        } else if (*type == ChataErrorType::Execution) {
            error_message += "Execution error";
        } else if (*type == ChataErrorType::Other) {
            error_message += "Other error";
        }
        error_message += color_end;
        error_message += " at line ";
        if (line.has_value()) {
            error_message += libchata_internal::to_chatastring(*line);
        } else {
            error_message += "(unknown)";
        }
        error_message += ", column ";
        if (column.has_value()) {
            error_message += libchata_internal::to_chatastring(*column);
        } else {
            error_message += "(unknown)";
        }
        error_message += " in file ";
        if (filename.has_value()) {
            error_message += *filename;
            error_message += ":\n| ";
        } else {
            error_message += "(unknown):\n| ";
        }
        if (details.has_value()) {
            error_message += *details;
        }
        if (line_content.has_value()) {
            error_message += "\n| ";
            if (line.has_value()) {
                error_message += libchata_internal::to_chatastring(line.value());
            } else {
                error_message += "(unknown)";
            }
            error_message += ":";
            if (column.has_value()) {
                error_message += libchata_internal::to_chatastring(column.value());
            } else {
                error_message += "(unknown)";
            }
            error_message += " | ";
            error_message += line_content.value();
        }
        return error_message.data();
    }

    ChataError(ChataErrorType type, std::string_view details, uint32_t line, uint32_t column, std::string_view filename)
            : type(type)
            , details(details)
            , line(line)
            , column(column)
            , filename(filename) {}

    ChataError(ChataErrorType type, std::string_view details, uint32_t line, uint32_t column, std::string_view filename, libchata_internal::chatastring line_content)
            : type(type)
            , details(details)
            , line(line)
            , column(column)
            , filename(filename)
            , line_content(line_content) {}

    ChataError(ChataErrorType type, std::optional<std::string_view> details, uint32_t line, uint32_t column) : type(type), details(details), line(line), column(column) {}

    ChataError(ChataErrorType type, std::optional<std::string_view> details, uint32_t line, uint32_t column, libchata_internal::chatastring line_content)
            : type(type)
            , details(details)
            , line(line)
            , column(column)
            , line_content(line_content) {}

    ChataError(ChataErrorType type, std::string_view details) : type(type), details(details) {}

    ChataError(ChataErrorType type, std::string_view details, libchata_internal::chatastring line_content) : type(type), details(details), line_content(line_content) {}
};

struct chata_args {
    double input1;
    double input2;
    double input3;
    double input4;
};

class ChataProcessor {
    using chatastring = libchata_internal::chatastring;
    template <typename T>
    using AlignedMemory = libchata_internal::AlignedMemory<T>;

    std::array<std::vector<uint8_t, AlignedMemory<uint8_t>>, 2> executable_memory;
    int current_executable_memory = 0;

    size_t executable_size = 0;

    size_t executable_instruction_count = 0;

    size_t compiled_size = 0;

    size_t compiled_instruction_count = 0;

    void (*executable_function)(chata_args&) = nullptr;

    void save_to_memory(const libchata_internal::chatavector<uint8_t>& data);

public:
    void compile(const std::string_view& code);

    void compile(const InputFile& file);

    void compile(const std::span<InputFile> files);

    void compile_and_commit(const std::string_view& code);

    void compile_and_commit(const InputFile& file);

    void compile_and_commit(const std::span<InputFile> files);

    void process_data(chata_args& in1);

    void commit();

    [[nodiscard]] size_t get_executable_size() { return executable_size; }

    [[nodiscard]] size_t get_executable_instruction_count() { return executable_instruction_count; }

    [[nodiscard]] size_t get_compiled_size() { return compiled_size; }

    [[nodiscard]] size_t get_compiled_instruction_count() { return compiled_instruction_count; }

    ChataProcessor(const std::string_view& code) { compile_and_commit(code); }

    ChataProcessor(const InputFile& file) { compile_and_commit(file); }

    ChataProcessor(const std::span<InputFile> files) { compile_and_commit(files); }

    ChataProcessor() = default;
};

namespace libchata {

void reset_memory_bank();

std::string_view version();

/**
 * @brief Assemble RISC-V assembly with Chatassembler
 *
 * @param code The RISC-V assembly you want to assemble
 * @param supported_sets An array or vector of supported instruction sets to be used for bit-dependent instructions and architecture options
 * @return std::span<uint8_t>
 */
std::span<uint8_t> assemble(std::string_view code, std::span<RVInstructionSet> supported_sets = {});

} // namespace libchata