#include "libchata.hpp"
#include <print>
#include <vector>

#include <fstream>
#include <filesystem>

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

ChataString assemble_code(const ChataString& data) {
    // Assemble by putting everything into a .s file, then invoke as, then convert to binary with objcopy

    std::ofstream out("temp.s");
    out << data;
    out.close();

    std::system("riscv64-linux-gnu-as temp.s -o temp.o");

    std::system("riscv64-linux-gnu-objcopy -O binary temp.o temp.bin");

    std::ifstream in("temp.bin", std::ios::binary);
    ChataString result((std::istreambuf_iterator<char>(in)), std::istreambuf_iterator<char>());
    in.close();

    std::filesystem::remove("temp.s");
    std::filesystem::remove("temp.o");
    std::filesystem::remove("temp.bin");

    return result;
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