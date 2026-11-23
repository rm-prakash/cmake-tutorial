#include <iostream>
#include "embeddedcore/sensor.hpp"
#include "embeddedcore/diagnostics.hpp"
#include "embeddedcore/device_info.hpp"
int main() {
    const double temperature = embeddedcore::read_temperature();
    std::cout << "Embedded Device Simulator\n";
    std::cout << "Device: " << embeddedcore::device_label() << '\n';
    std::cout << "Temperature: " << temperature << " C\n";
    std::cout << "Device status: "
              << (embeddedcore::is_temperature_healthy(temperature) ? "HEALTHY" : "WARNING")
              << '\n';
    return 0;
}
