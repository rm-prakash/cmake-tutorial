#include "embeddedcore/diagnostics.hpp"

namespace embeddedcore {
bool is_temperature_healthy(double temperature) {
#ifdef EMBEDDEDCORE_STRICT_LIMIT
    return temperature <= 35.0;
#else
    return temperature <= 40.0;
#endif
}
}
