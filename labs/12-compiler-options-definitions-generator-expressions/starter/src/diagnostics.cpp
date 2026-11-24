#include "embeddedcore/diagnostics.hpp"
namespace embeddedcore {
const char* device_status(double t) { return t > 40.0 ? "WARNING" : "HEALTHY"; }
bool internal_trace_enabled() {
#if defined(EMBEDDEDCORE_INTERNAL_TRACE)
    return true;
#else
    return false;
#endif
}
}
