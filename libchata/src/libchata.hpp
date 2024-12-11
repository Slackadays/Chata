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

class InputFile {
    std::string_view data;
    std::optional<std::string_view> filename;
    friend libchata_internal::InternalFile;

public:
    InputFile(std::string_view data, std::optional<std::string_view> filename) : data(data), filename(filename) {}
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

class InternalFile {
public:
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
    Unspecified,
    Compiler,
    Assembler,
    Execution,
    Other
};

class ChataError : public std::exception {
public:
    ChataErrorType type = ChataErrorType::Unspecified;
    std::optional<std::string_view> details;
    int line = 0;
    int column = 0;

    char* what() {
        libchata_internal::chatastring error_message;
        switch (type) {
        case ChataErrorType::Unspecified:
            error_message = "Unspecified error ";
            break;
        case ChataErrorType::Compiler:
            error_message = "Compiler error ";
            break;
        case ChataErrorType::Assembler:
            error_message = "Assembler error ";
            break;
        case ChataErrorType::Execution:
            error_message = "Execution error ";
            break;
        case ChataErrorType::Other:
            error_message = "Other error ";
            break;
        }
        if (details.has_value()) {
            error_message += *details;
        }
        error_message += " at line " + libchata_internal::to_chatastring(line) + ", column " + libchata_internal::to_chatastring(column);
        return error_message.data();
    }

    ChataError(ChataErrorType type, std::optional<std::string_view> details, int line, int column) : type(type), details(details), line(line), column(column) {}
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

    void (*executable_function)(chata_args&) = nullptr;

    void save_to_memory(const chatastring& data);

public:
    [[nodiscard]] chatastring compile(const std::string_view& code);

    [[nodiscard]] chatastring compile(const InputFile& file);

    [[nodiscard]] chatastring compile(const std::span<InputFile> files);

    void compile_and_commit(const std::string_view& code);

    void compile_and_commit(const InputFile& file);

    void compile_and_commit(const std::span<InputFile> files);

    void process_data(chata_args& in1);

    void commit();

    ChataProcessor(const std::string_view& code) { compile_and_commit(code); }

    ChataProcessor() = default;
};

std::string_view libchata_version();