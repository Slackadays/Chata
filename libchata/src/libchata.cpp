#include "libchata.hpp"



std::optional<ChataError> ChataProcessor::process_data(float& in1) {
    in1 *= 0.5;
    return std::nullopt;
}

std::optional<ChataError> ChataProcessor::compile(const std::span<InputFile> files) {
    return std::nullopt;
}

std::optional<ChataError> ChataProcessor::compile(const InputFile& file) {
    std::array<InputFile, 1> temp = {file};
    return compile(std::span(temp));
}

std::optional<ChataError> ChataProcessor::compile(const std::string_view& code) {
    return compile(InputFile(code, std::nullopt));
}

std::string_view libchata_version() {
    return libchata_version_str;
}