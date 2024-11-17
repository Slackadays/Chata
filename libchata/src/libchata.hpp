#include <iostream>
#include <expected>
#include <optional>
#include <string_view>
#include <array>
#include <cstdint>
#include <span>
#include <memory>
#include <vector>
#include <unistd.h>
#include <new>
#include <cstring>

constexpr size_t libchata_memory_pool_size = 33554432;

template <class T>
class MemoryBank;

typedef std::basic_string<char, std::char_traits<char>, MemoryBank<char>> chatastring;

template <typename T>
using chatavector = std::vector<T, MemoryBank<T>>;

constexpr std::array<std::string_view, 128> valid_register_names = {"x0", "x1", "x2", 
"x3", "x4", "x5", "x6", "x7", "x8", "x9", "x10", "x11", "x12", "x13", "x14", "x15", "x16", "x17", "x18", "x19", "x20", "x21", "x22", "x23", "x24", "x25", "x26", "x27", "x28", "x29", "x30", "x31", "zero", "ra", "sp", "gp", "tp", "t0", "t1", "t2", "s0", "s1", "a0", "a1", "a2", "a3", "a4", "a5", "a6", "a7", "s2", "s3", "s4", "s5", "s6", "s7", "s8", "s9", "s10", "s11", "t3", "t4", "t5", "t6", "f0", "f1", "f2", "f3", "f4", "f5", "f6", "f7", "f8", "f9", "f10", "f11", "f12", "f13", "f14", "f15", "f16", "f17", "f18", "f19", "f20", "f21", "f22", "f23", "f24", "f25", "f26", "f27", "f28", "f29", "f30", "f31", "fa0", "fa1", "fa2", "fa3", "fa4", "fa5", "fa6", "fa7", "ft0", "ft1", "ft2", "ft3", "ft4", "ft5", "ft6", "ft7", "ft8", "ft9", "ft10", "ft11", 
"fs0", "fs1", "fs2", "fs3", "fs4", "fs5", "fs6", "fs7", "fs8", "fs9", "fs10", "fs11"};

static class GlobalMemoryBank {
    std::array<std::byte, libchata_memory_pool_size> pool;
    size_t used = 0;
    long pagesize = sysconf(_SC_PAGE_SIZE);

public:
    void* grab_some_memory(size_t requested) {
        std::cout << "Allocating " << requested << " bytes" << std::endl;
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
        
        //std::cout << "current_offset: " << current_offset << ", aligned_offset: " << aligned_offset << ", padding: " << padding << std::endl;

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

    void deallocate(T* ptr, size_t requested) {
        return;
    }
};

template<class T>
class AlignedMemory {
public:
    using value_type = T;

    AlignedMemory() = default;

    [[nodiscard]] T* allocate(size_t requested) {
        std::size_t bytes = requested * sizeof(T);
        return reinterpret_cast<T*>(memory_bank.grab_aligned_memory(bytes));
    }

    void deallocate(T* ptr, size_t requested) {
        return;
    }
};


enum class ErrorType {
    Nada,
    Dummy
};

class ChataError {
public:
    ErrorType what = ErrorType::Nada;
    std::optional<std::string_view> details;
    int line = 0;
    int column = 0;
};

class InternalFile;

class InputFile {
    std::string_view data;
    std::optional<std::string_view> filename;
    friend InternalFile;

public:
    InputFile(std::string_view data, std::optional<std::string_view> filename) : data(data), filename(filename) {}
};

class InternalFile {
public:
    chatastring data;
    std::optional<std::string_view> filename;
    InternalFile(InputFile file) : data(file.data.begin(), file.data.end()), filename(file.filename) {}
};

class ChataProcessor {
    std::vector<unsigned char, AlignedMemory<unsigned char>> executable_memory;

    void (*executable_function)(float&) = nullptr;

    void commit_to_memory(const chatastring& data);

public:
    std::optional<ChataError> compile(const std::string_view& code);

    std::optional<ChataError> compile(const InputFile& file);

    std::optional<ChataError> compile(const std::span<InputFile> files);

    std::optional<ChataError> process_data(float& in1);
};

std::string_view libchata_version();

chatastring assemble_code(const chatastring& data);

void compile_code(chatavector<InternalFile>& files);