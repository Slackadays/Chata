#include "libchata.hpp"
#include <filesystem>
#include <fstream>
#include <iostream>
#include <string.h>
#include <sys/mman.h>
#include <vector>

constexpr std::string_view libchata_version_str = PROJECT_VERSION;

void ChataProcessor::process_data(chata_args& input) {
    executable_function(input);
}

void ChataProcessor::save_to_memory(const chatastring& data) {
    int mpres = mprotect(executable_memory.at(!current_executable_memory).data(), executable_memory.at(!current_executable_memory).size(), PROT_READ | PROT_WRITE);
    if (mpres != 0) {
        std::cout << "mprotect failed: " << strerror(errno) << ", " << errno << std::endl;
        exit(1);
    }

    executable_memory.at(!current_executable_memory).resize(data.size());

    std::copy(data.begin(), data.end(), executable_memory.at(!current_executable_memory).begin());

    errno = 0;
    mpres = mprotect(executable_memory.at(!current_executable_memory).data(), executable_memory.at(!current_executable_memory).size(), PROT_READ | PROT_EXEC);
    if (mpres != 0) {
        std::cout << "mprotect failed: " << strerror(errno) << ", " << errno << std::endl;
        exit(1);
    }

    std::cout << "Executable memory first address: " << reinterpret_cast<long int>(executable_memory.at(!current_executable_memory).data()) << std::endl;
}

void ChataProcessor::commit() {
    executable_function = reinterpret_cast<void (*)(chata_args&)>(executable_memory.at(!current_executable_memory).data());

    current_executable_memory = !current_executable_memory;
}

[[nodiscard]] chatastring ChataProcessor::compile(const std::span<InputFile> input) {
    chatavector<InternalFile> files;
    for (const auto& file : input) {
        files.push_back(InternalFile(file));
    }

    auto compiled = compile_code(files);

    std::cout << "Ok, here's the processed code: " << compiled << std::endl;

    auto assembled = assemble_code(compiled);

    std::cout << "Ok, here's the assembled code:" << std::endl;
    // Show the code in hex form
    for (auto c : assembled) {
        printf("%02x ", c);
    }

    std::cout << std::endl;

    // exit(0);

    return assembled;
}

[[nodiscard]] chatastring ChataProcessor::compile(const InputFile& file) {
    std::array<InputFile, 1> temp = {file};
    return compile(std::span(temp));
}

[[nodiscard]] chatastring ChataProcessor::compile(const std::string_view& code) {
    return compile(InputFile(code, std::nullopt));
}

void ChataProcessor::compile_and_commit(const std::span<InputFile> input) {
    auto assembled = compile(input);

    save_to_memory(assembled);

    commit();

    std::cout << "Ok, here's the memory:" << std::endl;
    for (auto c : executable_memory.at(current_executable_memory)) {
        printf("%02x ", c);
    }
}

void ChataProcessor::compile_and_commit(const InputFile& file) {
    std::array<InputFile, 1> temp = {file};
    compile_and_commit(std::span(temp));
}

void ChataProcessor::compile_and_commit(const std::string_view& code) {
    compile_and_commit(InputFile(code, std::nullopt));
}

std::string_view libchata_version() {
    return libchata_version_str;
}
