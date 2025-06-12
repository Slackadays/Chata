#include "libchata.hpp"
#include <bitset>

int passed_tests = 0;
int failed_tests = 0;

namespace libchata_internal {} // namespace libchata_internal

using namespace libchata_internal;

int main() {

    std::cout << passed_tests << " tests passed, " << failed_tests << " tests failed, " << passed_tests + failed_tests << " tests total" << std::endl;

    if (passed_tests == passed_tests + failed_tests) {
        std::cout << "Yay, all your tests passed!" << std::endl;
    }
}