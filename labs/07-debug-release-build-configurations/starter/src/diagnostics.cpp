#include "embeddedcore/diagnostics.hpp"
namespace embeddedcore {
    const char* classify_temperature(double temperature_c) {
        return temperature_c > 40.0 ? "WARNING" : "HEALTHY";
    }
    const char* build_configuration() {
#if defined(EMBEDDEDCORE_DEBUG_BUILD)
        return "Debug";
#elif defined(EMBEDDEDCORE_RELEASE_BUILD)
        return "Release";
#else
        return "Other configuration";
#endif
    }
}
