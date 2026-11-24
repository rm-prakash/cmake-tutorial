#include "embeddedcore/sensor.hpp"
#include "embeddedcore/build_info.hpp"
namespace embeddedcore {
double read_temperature() { return 25.5; }
const char* build_configuration() {
#if defined(EMBEDDEDCORE_DEBUG_BUILD)
    return "Debug";
#elif defined(EMBEDDEDCORE_RELEASE_BUILD)
    return "Release";
#else
    return "Other";
#endif
}
const char* target_system() { return EMBEDDEDCORE_TARGET_SYSTEM; }
}
