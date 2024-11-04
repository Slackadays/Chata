#include <expected>
#include <optional>
#include <string_view>
#include <array>
#include <cstring>
#include <span>

constexpr size_t max_code_size = 1048576;

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
    InputFile(std::string_view data, std::optional<std::string_view> filename)
        : data(data), filename(filename) {}
};

class ChataProcessor {
    std::array<unsigned char, max_code_size> assembled_code;

public:
    std::optional<ChataError> compile(const std::string_view& code);

    std::optional<ChataError> compile(const InputFile& file);

    std::optional<ChataError> compile(const std::span<InputFile> files);

    std::optional<ChataError> process_data(float& in1);
};