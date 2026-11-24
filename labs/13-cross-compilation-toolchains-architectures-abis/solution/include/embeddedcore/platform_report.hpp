#pragma once

#include <string_view>

namespace embeddedcore {
std::string_view target_system() noexcept;
std::string_view target_processor() noexcept;
std::string_view target_abi() noexcept;
}
