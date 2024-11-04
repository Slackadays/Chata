#include <expected>
#include <optional>
#include <string_view>
#include <array>
#include <cstdint>
#include <span>
#include <memory>

constexpr size_t libchata_memory_pool_size = 4194304;

template <class T>
class MemoryPool {
    std::array<std::byte, libchata_memory_pool_size> pool;
    size_t used = 0;

public:
    using value_type = T;

    MemoryPool() = default;

    [[nodiscard]] T* allocate(size_t requested) {
        std::size_t bytes = requested * sizeof(T);
        if (bytes + used > pool.size()) {
            return nullptr;
        }
        T* ptr = reinterpret_cast<T*>(pool.data() + used);
        used += bytes;
        return ptr;
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

class InputFile {
    std::string_view data;
    std::optional<std::string_view> filename;

public:
    InputFile(std::string_view data, std::optional<std::string_view> filename) : data(data), filename(filename) {}
};

class ChataProcessor {
    //std::array<char, libchata_code_memory_size> code_memory;
    //std::array<std::byte, libchata_executable_memory_size> executable_memory;

public:
    std::optional<ChataError> compile(const std::string_view& code);

    std::optional<ChataError> compile(const InputFile& file);

    std::optional<ChataError> compile(const std::span<InputFile> files);

    std::optional<ChataError> process_data(float& in1);
};

std::string_view libchata_version();