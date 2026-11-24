#include <iostream>
#include "embeddedcore/controller/controller.hpp"
#include "embeddedcore/sensors/sensor.hpp"
int main() {
  // TODO 1: Replace the fixed reading with sensors::read_temperature().
  const auto reading = embeddedcore::sensors::Reading{25.5};
  const auto report = embeddedcore::controller::evaluate(reading);
  // TODO 2: Display the report's temperature and connection status.
  std::cout << "Device status: " << report.health << '\n';
  return 0;
}
