#include <expected>
#include <optional>
#include <string_view>
#include <array>
#include <cstring>

constexpr size_t max_code_size = 1048576;

enum class ChataError {
    Foo,
    Bar
};

class ChataProcessor {
    std::array<unsigned char, max_code_size> assembled_code;

public:
    std::optional<ChataError> compile(const std::string_view& code);

    std::optional<ChataError> process_data(float& in1);
};