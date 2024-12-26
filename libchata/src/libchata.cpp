// SPDX-License-Identifier: MPL-2.0
#include "libchata.hpp"
#include "debug.hpp"
#include <filesystem>
#include <fstream>
#include <iostream>
#include <string.h>
#include <sys/mman.h>
#include <vector>

using namespace libchata_internal;

constexpr std::string_view libchata_version_str = PROJECT_VERSION;

void* GlobalMemoryBank::grab_some_memory(size_t requested) {
    DBG(std::cout << "Allocating " << requested << " bytes, " << used << " used" << std::endl;)
    if (requested + used > pool.size()) {
        return nullptr;
    }
    void* ptr = reinterpret_cast<void*>(pool.data() + used);
    used += requested;
    return ptr;
}

void* GlobalMemoryBank::grab_aligned_memory(size_t requested) {
    DBG(std::cout << "Allocating " << requested << " aligned bytes" << std::endl;)
    size_t current_offset = reinterpret_cast<size_t>(pool.data() + used);
    size_t aligned_offset = (current_offset + pagesize - 1) & ~(pagesize - 1);
    size_t padding = aligned_offset - current_offset;

    // DBG(std::cout << "current_offset: " << current_offset << ", aligned_offset: " << aligned_offset << ", padding: " << padding << std::endl;)

    if (padding + requested + used > pool.size()) {
        return nullptr;
    }

    used += padding;
    void* ptr = reinterpret_cast<void*>(pool.data() + used);
    used += requested;
    return ptr;
}

void ChataProcessor::process_data(chata_args& input) {
    executable_function(input);
}

void ChataProcessor::save_to_memory(const chatavector<uint8_t>& data) {
    int mpres = mprotect(executable_memory.at(!current_executable_memory).data(), executable_memory.at(!current_executable_memory).size(), PROT_READ | PROT_WRITE);
    if (mpres != 0) {
        DBG(std::cout << "mprotect failed: " << strerror(errno) << ", " << errno << std::endl;)
        exit(1);
    }

    executable_memory.at(!current_executable_memory).resize(data.size());

    std::copy(data.begin(), data.end(), executable_memory.at(!current_executable_memory).begin());

    errno = 0;
    mpres = mprotect(executable_memory.at(!current_executable_memory).data(), executable_memory.at(!current_executable_memory).size(), PROT_READ | PROT_EXEC);
    if (mpres != 0) {
        DBG(std::cout << "mprotect failed: " << strerror(errno) << ", " << errno << std::endl;)
        exit(1);
    }

    DBG(std::cout << "Executable memory first address: " << reinterpret_cast<long int>(executable_memory.at(!current_executable_memory).data()) << std::endl;)
}

void ChataProcessor::commit() {
    executable_function = reinterpret_cast<void (*)(chata_args&)>(executable_memory.at(!current_executable_memory).data());

    current_executable_memory = !current_executable_memory;
}

void ChataProcessor::compile(const std::span<InputFile> input) {
    chatavector<InternalFile> files;
    for (const auto& file : input) {
        files.push_back(InternalFile(file));
    }

    auto compiled = compile_code(files);

    DBG(std::cout << "Ok, here's the processed code: " << compiled << std::endl;)

    auto assembled = assemble_code(compiled);

    DBG(std::cout << "Ok, here's the assembled code:" << std::endl;)
    // Show the code in hex form
    for (auto c : assembled) {
        printf("%02x ", c);
    }

    DBG(std::cout << std::endl;)

    // exit(0);

    save_to_memory(assembled);
}

void ChataProcessor::compile(const InputFile& file) {
    std::array<InputFile, 1> temp = {file};
    compile(std::span(temp));
}

void ChataProcessor::compile(const std::string_view& code) {
    compile(InputFile(code, std::nullopt));
}

void ChataProcessor::compile_and_commit(const std::span<InputFile> input) {
    compile(input);

    commit();

    DBG(std::cout << "Ok, here's the memory:" << std::endl;)
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

std::span<uint8_t> libchata_assemble(std::string_view code) {
    auto assembled = assemble_code(chatastring(code));
    return std::span<uint8_t>(assembled.data(), assembled.size());
}