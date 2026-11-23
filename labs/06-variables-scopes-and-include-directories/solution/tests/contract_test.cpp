#include <cstring>
#include "embeddedcore/sensor.hpp"
#include "embeddedcore/diagnostics.hpp"
#include "embeddedcore/device_info.hpp"
int main() {
    if (embeddedcore::read_temperature() != 25.5) return 1;
    if (!embeddedcore::is_temperature_healthy(25.5)) return 2;
    if (embeddedcore::is_temperature_healthy(45.0)) return 3;
    if (std::strlen(embeddedcore::device_label()) == 0) return 4;
    return 0;
}
