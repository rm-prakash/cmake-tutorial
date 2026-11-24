#include "embeddedcore/sensor.hpp"
#include "embeddedcore/diagnostics.hpp"
#ifdef EMBEDDEDCORE_INTERNAL_TRACE
#error "Private definition leaked to a consumer"
#endif
int main() {
    if (EMBEDDEDCORE_API_LEVEL != 2) return 1;
    if (embeddedcore::read_temperature() != 25.5) return 2;
    if (embeddedcore::device_status(25.5)[0] != 'H') return 3;
    if (embeddedcore::device_status(45.0)[0] != 'W') return 4;
    return 0;
}
