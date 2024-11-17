#include "libchata.hpp"
#include <vector>
#include <sys/mman.h>
#include <fstream>
#include <filesystem>
#include <string.h>
#include <iostream>

constexpr std::string_view libchata_version_str = PROJECT_VERSION;

std::optional<ChataError> ChataProcessor::process_data(float& in1) {
    //in1 *= 0.5;
    executable_function(in1);
    std::cout << "Ok, here's the result: " << in1 << std::endl;
    return std::nullopt;
}

void ChataProcessor::commit_to_memory(const chatastring& data) {
    executable_memory.resize(data.size());
    /*auto res = mmap(executable_memory.data(), executable_memory.size(), PROT_READ | PROT_WRITE, MAP_PRIVATE | MAP_ANONYMOUS, -1, 0);
    if (res == MAP_FAILED) {
        std::perror("mmap");
        exit(1);
    }*/
    
    for (size_t i = 0; i < data.size(); i += 4) {
        if (i + 3 < data.size()) {
            executable_memory[i] = data[i + 3];
            executable_memory[i + 1] = data[i + 2];
            executable_memory[i + 2] = data[i + 1];
            executable_memory[i + 3] = data[i];
        } else {
            // Handle the remaining bytes if data.size() is not a multiple of 4
            for (size_t j = 0; j < data.size() - i; ++j) {
                executable_memory[i + j] = data[i + data.size() - i - 1 - j];
            }
        }
    }

    executable_memory = {0xf3, 0x0f, 0x10, 0x07, 0xf3, 0x0f, 0x58, 0xc0, 0xf3, 0x0f, 0x11, 0x07, 0xc3};

    errno = 0;
    int mpres = mprotect(executable_memory.data(), executable_memory.size(), PROT_READ | PROT_EXEC);
    if (mpres == -1) {
        std::cout << "mprotect failed: " << strerror(errno) << ", " << errno << std::endl;
        exit(1);
    }

    std::cout << "Executable memory first address: " << reinterpret_cast<long int>(executable_memory.data()) << std::endl;

    executable_function = reinterpret_cast<void (*)(float&)>(executable_memory.data());
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
