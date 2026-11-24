#include "embeddedcore/sensor.hpp"
#include "embeddedcore/telemetry.hpp"
#include <iostream>
int main() {
    std::cout << "Embedded Device Simulator\n";
    std::cout << "Temperature: " << embeddedcore::read_temperature() << " C\n";
    std::cout << "Device status: HEALTHY\n";
    std::cout << "Telemetry: " << embeddedcore::make_telemetry() << '\n';
}
