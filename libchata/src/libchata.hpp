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

constexpr std::array<std::string_view, 161> valid_registers = {
        "x0",   "x1",   "x2",  "x3",  "x4",  "x5",  "x6",  "x7",  "x8",  "x9",   "x10", "x11", "x12",  "x13",  "x14", "x15", "x16", "x17", "x18", "x19", "x20", "x21", "x22",
        "x23",  "x24",  "x25", "x26", "x27", "x28", "x29", "x30", "x31", "zero", "ra",  "fp",  "sp",   "gp",   "tp",  "t0",  "t1",  "t2",  "s0",  "s1",  "a0",  "a1",  "a2",
        "a3",   "a4",   "a5",  "a6",  "a7",  "s2",  "s3",  "s4",  "s5",  "s6",   "s7",  "s8",  "s9",   "s10",  "s11", "t3",  "t4",  "t5",  "t6",  "f0",  "f1",  "f2",  "f3",
        "f4",   "f5",   "f6",  "f7",  "f8",  "f9",  "f10", "f11", "f12", "f13",  "f14", "f15", "f16",  "f17",  "f18", "f19", "f20", "f21", "f22", "f23", "f24", "f25", "f26",
        "f27",  "f28",  "f29", "f30", "f31", "fa0", "fa1", "fa2", "fa3", "fa4",  "fa5", "fa6", "fa7",  "ft0",  "ft1", "ft2", "ft3", "ft4", "ft5", "ft6", "ft7", "ft8", "ft9",
        "ft10", "ft11", "fs0", "fs1", "fs2", "fs3", "fs4", "fs5", "fs6", "fs7",  "fs8", "fs9", "fs10", "fs11", "v0",  "v1",  "v2",  "v3",  "v4",  "v5",  "v6",  "v7",  "v8",
        "v9",   "v10",  "v11", "v12", "v13", "v14", "v15", "v16", "v17", "v18",  "v19", "v20", "v21",  "v22",  "v23", "v24", "v25", "v26", "v27", "v28", "v29", "v30", "v31"};

constexpr std::array<std::string_view, 54> valid_integer_registers = {"x5",  "x6",  "x7",  "x8",  "x9",  "x10", "x11", "x12", "x13", "x14", "x15", "x16", "x17", "x18", "x19", "x20", "x21", "x22",
                                                                      "x23", "x24", "x25", "x26", "x27", "x28", "x29", "x30", "x31", "t0",  "t1",  "t2",  "s0",  "s1",  "a0",  "a1",  "a2",  "a3",
                                                                      "a4",  "a5",  "a6",  "a7",  "s2",  "s3",  "s4",  "s5",  "s6",  "s7",  "s8",  "s9",  "s10", "s11", "t3",  "t4",  "t5",  "t6"};

constexpr std::array<std::string_view, 64> valid_floating_point_registers = {"f0",  "f1",  "f2",   "f3",   "f4",  "f5",  "f6",  "f7",  "f8",  "f9",  "f10", "f11", "f12", "f13", "f14",  "f15",
                                                                             "f16", "f17", "f18",  "f19",  "f20", "f21", "f22", "f23", "f24", "f25", "f26", "f27", "f28", "f29", "f30",  "f31",
                                                                             "fa0", "fa1", "fa2",  "fa3",  "fa4", "fa5", "fa6", "fa7", "ft0", "ft1", "ft2", "ft3", "ft4", "ft5", "ft6",  "ft7",
                                                                             "ft8", "ft9", "ft10", "ft11", "fs0", "fs1", "fs2", "fs3", "fs4", "fs5", "fs6", "fs7", "fs8", "fs9", "fs10", "fs11"};

constexpr std::array<std::string_view, 32> valid_vector_registers = {"v0",  "v1",  "v2",  "v3",  "v4",  "v5",  "v6",  "v7",  "v8",  "v9",  "v10", "v11", "v12", "v13", "v14", "v15",
                                                                     "v16", "v17", "v18", "v19", "v20", "v21", "v22", "v23", "v24", "v25", "v26", "v27", "v28", "v29", "v30", "v31"};

constexpr std::array<std::pair<std::string_view, std::string_view>, 32> x_register_aliases = {{
        {"x0", "zero"}, {"x1", "ra"},  {"x2", "fp"},  {"x3", "sp"},   {"x4", "gp"}, // Check for tp too later
        {"x5", "t0"},   {"x6", "t1"},  {"x7", "t2"},  {"x8", "s0"},   {"x9", "s1"},   {"x10", "a0"}, {"x11", "a1"}, {"x12", "a2"}, {"x13", "a3"},
        {"x14", "a4"},  {"x15", "a5"}, {"x16", "a6"}, {"x17", "a7"},  {"x18", "s2"},  {"x19", "s3"}, {"x20", "s4"}, {"x21", "s5"}, {"x22", "s6"},
        {"x23", "s7"},  {"x24", "s8"}, {"x25", "s9"}, {"x26", "s10"}, {"x27", "s11"}, {"x28", "t3"}, {"x29", "t4"}, {"x30", "t5"}, {"x31", "t6"},
}};

constexpr std::array<std::pair<std::string_view, std::string_view>, 32> f_register_aliases = {{
        {"f0", "fa0"},  {"f1", "fa1"},  {"f2", "fa2"},  {"f3", "fa3"},  {"f4", "fa4"},  {"f5", "fa5"},  {"f6", "fa6"},  {"f7", "fa7"},   {"f8", "ft0"},   {"f9", "ft1"},   {"f10", "ft2"},
        {"f11", "ft3"}, {"f12", "ft4"}, {"f13", "ft5"}, {"f14", "ft6"}, {"f15", "ft7"}, {"f16", "ft8"}, {"f17", "ft9"}, {"f18", "ft10"}, {"f19", "ft11"}, {"f20", "fs0"},  {"f21", "fs1"},
        {"f22", "fs2"}, {"f23", "fs3"}, {"f24", "fs4"}, {"f25", "fs5"}, {"f26", "fs6"}, {"f27", "fs7"}, {"f28", "fs8"}, {"f29", "fs9"},  {"f30", "fs10"}, {"f31", "fs11"},
}};

constexpr std::array<std::string_view, 15> integer_register_replacement_priority_list = {"t0", "t1", "t2", "t3", "t4", "t5", "t6", "a0", "a1", "a2", "a3", "a4", "a5", "a6", "a7"};

constexpr std::array<std::string_view, 20> floating_point_register_replacement_priority_list = {"ft0",  "ft1",  "ft2", "ft3", "ft4", "ft5", "ft6", "ft7", "ft8", "ft9",
                                                                                                "ft10", "ft11", "fa0", "fa1", "fa2", "fa3", "fa4", "fa5", "fa6", "fa7"};

chatastring to_chatastring(int num);
chatastring allocate_label(struct temp_resource_context& c);
chatastring allocate_label(int num);
chatastring allocate_int_register(struct temp_resource_context& c);
chatastring allocate_int_register(int num);
chatastring allocate_float_register(struct temp_resource_context& c);
chatastring allocate_float_register(int num);

static class GlobalMemoryBank {
    std::array<std::byte, memory_pool_size> pool;
    size_t used = 0;
    long pagesize = sysconf(_SC_PAGE_SIZE);

public:
    void* grab_some_memory(size_t requested) {
        std::cout << "Allocating " << requested << " bytes, " << used << " used" << std::endl;
        if (requested + used > pool.size()) {
            return nullptr;
        }
        void* ptr = reinterpret_cast<void*>(pool.data() + used);
        used += requested;
        return ptr;
    }

    void* grab_aligned_memory(size_t requested) {
        std::cout << "Allocating " << requested << " aligned bytes" << std::endl;
        size_t current_offset = reinterpret_cast<size_t>(pool.data() + used);
        size_t aligned_offset = (current_offset + pagesize - 1) & ~(pagesize - 1);
        size_t padding = aligned_offset - current_offset;

        // std::cout << "current_offset: " << current_offset << ", aligned_offset: " << aligned_offset << ", padding: " << padding << std::endl;

        if (padding + requested + used > pool.size()) {
            return nullptr;
        }

        used += padding;
        void* ptr = reinterpret_cast<void*>(pool.data() + used);
        used += requested;
        return ptr;
    }

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

struct temp_resource_context {
    int generated_label_num = 0;
    int placeholder_temp_integer_register_num = 0;
    int placeholder_temp_floating_point_register_num = 0;
};

chatastring assemble_code(const chatastring& data);

chatastring compile_code(chatavector<InternalFile>& files);

void process_comments(InternalFile& files);

bool is_float(const chatastring& str);

bool is_integer(const chatastring& str);

bool is_number(const chatastring& str);

int to_int(const chatastring& str);

double to_float(const chatastring& str);

void process_ifs(InternalFile& file, struct temp_resource_context& c);

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