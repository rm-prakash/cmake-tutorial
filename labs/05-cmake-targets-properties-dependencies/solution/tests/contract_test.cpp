#include "embeddedcore/diagnostics.hpp"
#include "embeddedcore/sensor.hpp"

int main() {
    const double sample = embeddedcore::read_temperature();
    if (sample != 25.5) return 1;
    if (!embeddedcore::is_temperature_healthy(sample)) return 2;
    if (embeddedcore::is_temperature_healthy(45.0)) return 3;
    return 0;
}
