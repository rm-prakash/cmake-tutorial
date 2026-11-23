#include "embeddedcore/sensor.hpp"
#include "embeddedcore/diagnostics.hpp"
#include <iostream>
int main() {
    const double temperature = embeddedcore::read_temperature_c();
    std::cout << "Embedded Device Simulator\n";
    std::cout << "Temperature: " << temperature << " C\n";
    std::cout << "Device status: " << embeddedcore::classify_temperature(temperature) << '\n';
    std::cout << "Build configuration: " << embeddedcore::build_configuration() << '\n';
    return 0;
}
