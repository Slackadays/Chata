// SPDX-License-Identifier: MPL-2.0
#include <array>
#include <chrono>
#include <cstring>
#include <fcntl.h>
#include <filesystem>
#include <fstream>
#include <iostream>
#include <libchata.hpp>
#include <optional>
#include <string>
#include <thread>
#include <ultrassembler.hpp>
#include <unistd.h>
#include <vector>

namespace fs = std::filesystem;

bool assemble_flag = false;
bool no_write_flag = false;
bool silent_flag = false;

#if defined(__linux__) || defined(__unix__) || defined(__APPLE__) || defined(__NetBSD__) || defined(__OpenBSD__) || defined(__DragonFly__) || defined(__HAIKU__) || defined(__FreeBSD__) \
        || defined(__posix__)
#define UNIX_OR_UNIX_LIKE
#endif

size_t writeToFile(const fs::path& path, const std::string& content, bool append = false) {
    std::ofstream file(path, append ? std::ios::app : std::ios::trunc | std::ios::binary);
    file << content;
    return content.size();
}

std::optional<std::string> fileContents(const fs::path& path) {
#if defined(UNIX_OR_UNIX_LIKE)
    errno = 0;
    int fd = open(path.string().data(), O_RDONLY);
    if (fd == -1) {
        if (errno == ENOENT)
            return std::nullopt;
        else
            throw std::runtime_error("Couldn't open file " + path.string() + ": " + std::strerror(errno));
    }
    std::string contents;
#if defined(__linux__) || defined(__FreeBSD__)
    std::array<char, 65536> buffer;
#elif defined(__APPLE__) || defined(__OpenBSD__) || defined(__NetBSD__) || defined(__DragonFly__)
    std::array<char, 16384> buffer;
#else
    std::array<char, PIPE_BUF> buffer;
#endif
    ssize_t bytes_read;
    errno = 0;
    while ((bytes_read = read(fd, buffer.data(), buffer.size())) > 0) {
        contents.append(buffer.data(), bytes_read);
        if (bytes_read < buffer.size() && errno == 0) break; // check if we reached EOF early and not due to an error
    }
    close(fd);
    return contents;
#else
    std::stringstream buffer;
    std::ifstream file(path, std::ios::binary);
    if (!file.is_open()) return std::nullopt;
    buffer << file.rdbuf();
    return buffer.str();
#endif
}

int main(int argc, char* argv[]) {
    std::vector<std::string> args;
    for (int i = 0; i < argc; i++) {
        args.push_back(argv[i]);
    }

    // Search args for "-a" and assign to assemble_flag
    for (size_t i = 0; i < args.size(); i++) {
        if (args.at(i) == "-a") {
            assemble_flag = true;
            args.erase(args.begin() + i);
        }
        if (args.at(i) == "--no-write") {
            no_write_flag = true;
            args.erase(args.begin() + i);
        }
        if (args.at(i) == "--silent") {
            silent_flag = true;
            args.erase(args.begin() + i);
        }
    }

    if (!silent_flag) {
        std::cout << "Welcome to ChataCLI " << PROJECT_VERSION << " (commit " << GIT_COMMIT_HASH << " on branch " << GIT_BRANCH << ")" << std::endl;
        std::cout << "libchata version: " << libchata::version() << std::endl;
    }
    if (argc < 2) {
        std::cout << "You must provide one or more files" << std::endl;
        return 1;
    }

    

    fs::path filePath = args.back();
    auto contents = fileContents(filePath);

    if (!silent_flag) {
        if (contents) {
            std::cout << "File found: " << filePath.string() << std::endl;
        } else {
            std::cout << "File not found: " << filePath.string() << std::endl;
            return 1;
        }
    }
    
    InputFile file(*contents, filePath.string());

    if (assemble_flag) {
        std::span<uint8_t> result;
        try {
            result = ultrassembler::assemble(file.data);
        } catch (ChataError& e) {
            std::cout << e.what() << std::endl;
            return 1;
        } catch (UltraError& e) {
            std::cout << "" << e.what() << std::endl;
            return 1;
        }
        if (!no_write_flag) {
            std::string filename = filePath.replace_extension(".bin").string();
            if (!silent_flag) {
                std::cout << "Writing result to " << filename << std::endl;
            }
            
            writeToFile(filename, std::string(result.begin(), result.end()));
        } else {
            if (!silent_flag) {
                std::cout << "Skipping writing the result to a file" << std::endl;
            }
        }
        return 0;
    }

    if (!silent_flag) {
        std::cout << "Processing the file " << filePath.string() << std::endl;
    }
    

    ChataProcessor processor;

    try {
        processor.compile_and_commit(file);

        double value = 2.0;

        if (!silent_flag) {
            std::cout << "Ok, let's see if we can change the value of a float. Current value: " << value << std::endl;
        }

        chata_args args;

        args.input1 = value;

        processor.process_data(args);

        if (!silent_flag) {
            std::cout << "New value: " << args.input1 << std::endl;
        }
        
    } catch (ChataError& e) {
        std::cout << "" << e.what() << std::endl;
        return 1;
    }

    if (!silent_flag) {
        std::cout << "Success!" << std::endl;
    }
    
}