#include <iostream>
#include <string>
#include <string_view>
#include <immintrin.h>

bool fast_eq(const auto& first, const std::string_view& second) {
    /*if (first.size() != second.size()) { // First make sure the sizes are equal because no two strings can ever be the same if they have different sizes. Also, this lets us save on future bound checks
                                         // because we're already checking it here.
        return false;
    }
    for (size_t i = 0; i < first.size(); i++) {
        if (first[i] != second[i]) {
            [[likely]] return false;
        } else {
            [[unlikely]] continue;
        }
    }
    return true;*/
    __m128i mask = _mm_cmpestrm(_mm_loadu_si128((__m128i*)first.data()), first.size(), _mm_loadu_si128((__m128i*)second.data()), second.size(), _SIDD_CMP_EQUAL_EACH);
    return _mm_test_all_ones(mask);
}

int main() {
    std::cout << "Starting test of fast_eq" << std::endl;
    size_t loops = 333333;
    for (volatile size_t i = 0; i < loops; i++) {
        fast_eq(std::string("test1"), "test2");
        fast_eq(std::string("test2"), "test3");
        fast_eq(std::string("test3"), "test4");
    }
    //std::cout << "Finished test of fast_eq" << std::endl;
}