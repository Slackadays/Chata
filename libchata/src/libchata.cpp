#include "libchata.hpp"
#include <print>
#include <vector>
#include <sys/mman.h>


#include <fstream>
#include <filesystem>
#include <string.h>

constexpr std::string_view libchata_version_str = PROJECT_VERSION;

std::optional<ChataError> ChataProcessor::process_data(float& in1) {
    //in1 *= 0.5;
    executable_function(in1);
    return std::nullopt;
}

void ChataProcessor::commit_to_memory(const chatastring& data) {
    executable_memory.resize(data.size());
    auto res = mmap(executable_memory.data(), data.size(), PROT_READ | PROT_WRITE, MAP_PRIVATE | MAP_ANONYMOUS, -1, 0);
    if (res == MAP_FAILED) {
        std::perror("mmap");
        exit(1);
    }
    
    std::move(data.begin(), data.end(), executable_memory.begin());

    errno = 0;
    int mpres = mprotect(executable_memory.data(), executable_memory.size(), PROT_READ | PROT_EXEC);
    if (mpres == -1) {

    // show error
    std::println("mprotect failed: {}, {}", strerror(errno), errno);

    exit(1);
    }
}

std::optional<ChataError> ChataProcessor::compile(const std::span<InputFile> input) {
    chatavector<InternalFile> files;
    for (const auto& file : input) {
        files.push_back(InternalFile(file));
    }

    compile_code(files);

    std::println("Ok, here's the processed code: {}", files[0].data);
    
    auto assembled = assemble_code(files[0].data);

    std::println("Ok, here's the assembled code:");
    // Show the code in hex form
    for (auto c : assembled) {
        printf("%02x ", c);
    }

    std::println("");

    commit_to_memory(assembled);

    std::println("Ok, here's the memory:");
    for (auto c : executable_memory) {
        printf("%02x ", c);
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