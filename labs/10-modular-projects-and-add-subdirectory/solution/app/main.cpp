#include <iostream>
#include "embeddedcore/controller/controller.hpp"
#include "embeddedcore/sensors/sensor.hpp"
int main() {
  const auto report = embeddedcore::controller::evaluate(
      embeddedcore::sensors::read_temperature());
  std::cout << "Embedded Device Simulator\n"
            << "Temperature: " << report.temperature_celsius << " C\n"
            << "Device status: " << report.health << "\n"
            << "Communication: " << report.connection << '\n';
  return report.health == "HEALTHY" ? 0 : 1;
}
