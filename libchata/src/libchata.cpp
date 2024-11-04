#include "libchata.hpp"
#include <print>
#include <vector>

constexpr std::string_view libchata_version_str = PROJECT_VERSION;

std::optional<ChataError> ChataProcessor::process_data(float& in1) {
    in1 *= 0.5;
    return std::nullopt;
}

/*std::array<char> process_injections(const std::span<InputFile> files) {
    std::array<char> injections;
    for (const auto& file : files) {
        for (const auto& c : file.data) {
            injections.push_back(c);
        }
    }
    return injections;
}*/


std::optional<ChataError> ChataProcessor::compile(const std::span<InputFile> files) {
    std::vector<int, MemoryPool<int>> test;
    test.push_back(1);
    test.push_back(2);
    test.push_back(3);
    for (const auto& i : test) {
        std::println("{}", i);
    } 
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