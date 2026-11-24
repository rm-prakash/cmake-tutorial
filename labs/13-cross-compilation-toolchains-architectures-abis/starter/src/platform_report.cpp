#include "embeddedcore/platform_report.hpp"
#include "embeddedcore/target_config.hpp"

namespace embeddedcore {
std::string_view target_system() noexcept { return EMBEDDEDCORE_TARGET_SYSTEM; }
std::string_view target_processor() noexcept { return EMBEDDEDCORE_TARGET_PROCESSOR; }
std::string_view target_abi() noexcept { return EMBEDDEDCORE_TARGET_ABI; }
}
