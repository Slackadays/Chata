#include "libchata.hpp"
#include <vector>
#include <sys/mman.h>
#include <fstream>
#include <filesystem>
#include <string.h>
#include <iostream>

constexpr std::string_view libchata_version_str = PROJECT_VERSION;

std::optional<ChataError> ChataProcessor::process_data(chata_args& input) {
    executable_function(input);
    return std::nullopt;
}

void ChataProcessor::commit_to_memory(const chatastring& data) {
    executable_memory.resize(data.size());
    
    std::copy(data.begin(), data.end(), executable_memory.begin());

    executable_memory.insert(executable_memory.end(), {0x67, 0x80, 0x00, 0x00}); // add ret

    errno = 0;
    int mpres = mprotect(executable_memory.data(), executable_memory.size(), PROT_READ | PROT_EXEC);
    if (mpres != 0) {
        std::cout << "mprotect failed: " << strerror(errno) << ", " << errno << std::endl;
        exit(1);
    }

    std::cout << "Executable memory first address: " << reinterpret_cast<long int>(executable_memory.data()) << std::endl;

    executable_function = reinterpret_cast<void (*)(chata_args&)>(executable_memory.data());
}

std::optional<ChataError> ChataProcessor::compile(const std::span<InputFile> input) {
    chatavector<InternalFile> files;
    for (const auto& file : input) {
        files.push_back(InternalFile(file));
    }

    compile_code(files);

    std::cout << "Ok, here's the processed code: " << files[0].data << std::endl;
    
    auto assembled = assemble_code(files[0].data);

    std::cout << "Ok, here's the assembled code:" << std::endl;
    // Show the code in hex form
    for (auto c : assembled) {
        printf("%02x ", c);
    }

    std::cout << std::endl;

    commit_to_memory(assembled);

    std::cout << "Ok, here's the memory:" << std::endl;
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
