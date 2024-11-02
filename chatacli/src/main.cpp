#include <iostream>
#include <vector>
#include <optional>
#include <string>
#include <filesystem>
#include <fcntl.h>
#include <unistd.h>
#include <cstring>

namespace fs = std::filesystem;

#if defined(__linux__) || defined(__unix__) || defined(__APPLE__) || defined(__NetBSD__) || defined(__OpenBSD__) || defined(__DragonFly__) || defined(__HAIKU__) || defined(__FreeBSD__) \
        || defined(__posix__)
#define UNIX_OR_UNIX_LIKE
#endif

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


int main(int argc, char *argv[]) {
    std::cout << "Welcome to Chata!" << std::endl;
    if (argc < 2) {
        std::cout << "You must provide a file" << std::endl;
        return 1;
    }

    fs::path filePath = argv[1];
    auto contents = fileContents(filePath);

    if (contents) {
        std::cout << "File contents:\n" << *contents << std::endl;
    } else {
        std::cout << "Failed to read " << filePath << std::endl;
    }
}