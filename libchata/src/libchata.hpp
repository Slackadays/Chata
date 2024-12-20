// SPDX-License-Identifier: MPL-2.0
#include <array>
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

namespace libchata_internal {
class InternalFile;
}

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

chatastring to_chatastring(int num);
chatastring allocate_label(struct compilation_context& c);
chatastring allocate_label(int num);
chatastring allocate_int_register(struct compilation_context& c);
chatastring allocate_int_register(int num);
chatastring allocate_float_register(struct compilation_context& c);
chatastring allocate_float_register(int num);

static class GlobalMemoryBank {
    std::array<std::byte, memory_pool_size> pool;
    size_t used = 0;
    long pagesize = sysconf(_SC_PAGE_SIZE);

public:
    void* grab_some_memory(size_t requested);

    void* grab_aligned_memory(size_t requested);

} memory_bank;

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
    InternalFile(InputFile file) : data(file.data.begin(), file.data.end()), filename(file.filename) {}
};

struct compilation_context {
    int generated_label_num = 0;
    int placeholder_temp_integer_register_num = 0;
    int placeholder_temp_floating_point_register_num = 0;
    int line = 1;
    int column = 0;
};

chatastring assemble_code(const chatastring& data);

chatastring compile_code(chatavector<InternalFile>& files);

bool is_float(const chatastring& str);

bool is_integer(const chatastring& str);

bool is_number(const chatastring& str);

int to_int(const chatastring& str);

double to_float(const chatastring& str);

bool is_int_register(chatastring& reg);

bool is_float_register(chatastring& reg);

void jump_to_next_line(InternalFile& file, struct compilation_context& c, size_t& i);

chatastring read_this_line(InternalFile& file, struct compilation_context& c, size_t& i);

int decimal_representation_of_float(float input);

void process_ifs(InternalFile& file, struct compilation_context& c);

void process_changes(InternalFile& file, struct compilation_context& c);

bool is_register_character(const char& c);

chatastring make_base_register(const chatastring& reg);

int extract_number_from_string(const chatastring& str);

constexpr std::string_view generated_label_prefix = "generated_code_label";

constexpr std::string_view placeholder_temp_integer_register = "generated_placeholder_integer_register";

constexpr std::string_view placeholder_temp_floating_point_register = "generated_placeholder_floating_point_register";

} // namespace libchata_internal

enum class ChataErrorType {
    Compiler,
    Assembler,
    Execution,
    Other
};

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
    std::optional<int> line = 0;
    std::optional<int> column = 0;

    virtual char* what();

    ChataError(ChataErrorType type, std::string_view details, int line, int column, std::string_view filename) : type(type), details(details), line(line), column(column), filename(filename) {}

    ChataError(ChataErrorType type, std::optional<std::string_view> details, int line, int column) : type(type), details(details), line(line), column(column) {}

    ChataError(ChataErrorType type, std::string_view details) : type(type), details(details) {}
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

    std::array<std::vector<unsigned char, AlignedMemory<unsigned char>>, 2> executable_memory;
    int current_executable_memory = 0;

    size_t executable_size = 0;

    size_t executable_instruction_count = 0;

    size_t compiled_size = 0;

    size_t compiled_instruction_count = 0;

    void (*executable_function)(chata_args&) = nullptr;

    void save_to_memory(const chatastring& data);

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

std::string_view libchata_version();

std::string_view libchata_assemble(std::string_view code);