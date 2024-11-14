#include "libchata.hpp"
#include <fstream>
#include <filesystem>

chatastring assemble_code(const chatastring& data) {
    // Assemble by putting everything into a .s file, then invoke as, then convert to binary with objcopy

    std::ofstream out("temp.s");
    out << data;
    out.close();

    int res = std::system("riscv64-linux-gnu-as temp.s -o temp.o");

    if (res != 0) {
        std::println("error in command riscv64-linux-gnu-as temp.s -o temp.o");
        exit(1);
    }

    res = std::system("riscv64-linux-gnu-objcopy -O binary temp.o temp.bin");

    if (res != 0) {
        std::println("error in command riscv64-linux-gnu-objcopy -O binary temp.o temp.bin");
        exit(1);
    }

    std::ifstream in("temp.bin", std::ios::binary);
    chatastring result((std::istreambuf_iterator<char>(in)), std::istreambuf_iterator<char>());
    in.close();

    std::filesystem::remove("temp.s");
    std::filesystem::remove("temp.o");
    std::filesystem::remove("temp.bin");

    return result;
}