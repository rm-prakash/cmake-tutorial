#include "embeddedcore/platform_report.hpp"
#include "embeddedcore/sensor.hpp"
#include <iostream>

int main() {
    const double temperature = embeddedcore::read_temperature();
    std::cout << "Embedded Device Simulator\n"
              << "Temperature: " << temperature << " C\n"
              << "Device status: " << (embeddedcore::is_healthy(temperature) ? "HEALTHY" : "WARNING") << "\n"
              << "Target system: " << embeddedcore::target_system() << "\n"
              << "Target processor: " << embeddedcore::target_processor() << "\n"
              << "Target ABI label: " << embeddedcore::target_abi() << "\n";
    return embeddedcore::is_healthy(temperature) ? 0 : 1;
}
