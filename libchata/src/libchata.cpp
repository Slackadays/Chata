#include "libchata.hpp"
#include <print>
#include <vector>

constexpr std::string_view libchata_version_str = PROJECT_VERSION;

std::optional<ChataError> ChataProcessor::process_data(float& in1) {
    in1 *= 0.5;
    return std::nullopt;
}

void process_comments(auto& files) {
    // Comment format: # begins a comment on a line, and another # ends that comment
    // Examples: # Commented out #
    // # This whole line is a comment

    for (auto& file : files) { // Modify data in-place (make whitespace)
        bool is_comment = false;
        for (auto& c : file.data) {
            if (c == '#') {
                is_comment = !is_comment;
                c = ' ';
            }
            if (c == '\n') {
                is_comment = false;
            }
            if (is_comment) {
                c = ' ';
            }
        }
        
    }
}


std::optional<ChataError> ChataProcessor::compile(const std::span<InputFile> input) {
    std::vector<InternalFile, AccessMemoryBank<InternalFile>> files;
    for (const auto& file : input) {
        files.push_back(InternalFile(file));
    }

    process_comments(files);

    std::println("Ok, here's the processed data: {}", files[0].data);

    exit(0);
    
    std::vector<int, AccessMemoryBank<int>> test;
    for (int i = 0; i < 10000000; i++) {
        test.push_back(i);
        std::println("{}", test.back());
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