// SPDX-License-Identifier: MPL-2.0
#include "debug.hpp"
#include "registers.hpp"
#include "ultrassembler.hpp"
#include <algorithm>
#include <charconv>

constexpr std::string_view ultrassembler_version_str = PROJECT_VERSION;

using namespace ultrassembler_internal;

GlobalMemoryBank ultrassembler_internal::memory_bank;

void* GlobalMemoryBank::grab_some_memory(size_t requested) {
    // DBG(std::cout << "Allocating " << requested << " bytes, " << used << " used" << std::endl;)
    if (requested + used > pool.size()) {
        throw UltraError(UltraErrorType::Other, "Out of memory!");
    }
    void* ptr = reinterpret_cast<void*>(pool.data() + used);
    used += requested;
    return ptr;
}

void* GlobalMemoryBank::grab_aligned_memory(size_t requested) {
    // DBG(std::cout << "Allocating " << requested << " aligned bytes" << std::endl;)
    size_t current_offset = reinterpret_cast<size_t>(pool.data() + used);
    size_t aligned_offset = (current_offset + pagesize - 1) & ~(pagesize - 1);
    size_t padding = aligned_offset - current_offset;

    // DBG(std::cout << "current_offset: " << current_offset << ", aligned_offset: " << aligned_offset << ", padding: " << padding << std::endl;)

    if (padding + requested + used > pool.size()) {
        throw UltraError(UltraErrorType::Other, "Out of memory!");
    }

    used += padding;
    void* ptr = reinterpret_cast<void*>(pool.data() + used);
    used += requested;
    return ptr;
}

void GlobalMemoryBank::reset() {
    DBG(std::cout << "Resetting memory bank, used " << used << " bytes" << std::endl;)
    used = 0;
}

namespace ultrassembler_internal {

ultrastring to_ultrastring(const int32_t& num) {
    ultrastring result;
    result.reserve(32);
    std::array<char, 16> temp;
    auto res = std::to_chars(temp.data(), temp.data() + temp.size(), num);
    if (res.ec != std::errc()) {
        throw UltraError(UltraErrorType::Other, "Invalid integer");
    }
    for (auto i = temp.data(); i < res.ptr; i++) {
        result.push_back(*i);
    }
    // DBG(std::cout << "result: " << result << std::endl;)
    return result;
}

double to_float(const ultrastring& str) {
    double result = 0;
    auto res = std::from_chars(str.data(), str.data() + str.size(), result);
    if (res.ec != std::errc()) {
        throw UltraError(UltraErrorType::Other, "Invalid float " + str);
    }
    return result;
}

} // namespace ultrassembler_internal

namespace ultrassembler {

void reset_memory_bank() {
    ultrassembler_internal::memory_bank.reset();
}

std::string_view version() {
    return ultrassembler_version_str;
}

std::span<uint8_t> assemble(std::string_view code, std::span<RVInstructionSet> supported_sets) {
    auto assembled = assemble_code(code, ultravector<RVInstructionSet>(supported_sets.begin(), supported_sets.end()));
    return std::span<uint8_t>(assembled.data(), assembled.size());
}

} // namespace ultrassembler