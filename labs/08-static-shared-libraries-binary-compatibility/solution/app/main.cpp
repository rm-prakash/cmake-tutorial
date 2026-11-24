#include <iostream>
#include "embeddedcore/sensor.hpp"
int main() {
    const double t = embeddedcore::read_temperature();
    std::cout << "Embedded Device Simulator\n"
              << "Temperature: " << t << " C\n"
              << "Device status: " << embeddedcore::status_label(embeddedcore::is_healthy(t)) << '\n';
}
