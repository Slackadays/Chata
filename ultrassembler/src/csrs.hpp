#include "ultrassembler.hpp"
#include <array>
#include <cstdint>
#include <string_view>

namespace ultrassembler_internal {

constexpr uint16_t csr_search_failed = (uint16_t)-1;
const uint16_t fast_csr_search(const ultrastring& csr);

extern const std::array<std::pair<std::string_view, uint16_t>, 381> csrs;

} // namespace ultrassembler_internal