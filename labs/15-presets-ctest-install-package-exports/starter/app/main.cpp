#include "embeddedcore/sensor.hpp"
#include "embeddedcore/diagnostics.hpp"
#include <iostream>
int main() {
  const double value=embeddedcore::read_temperature();
  std::cout << "Embedded Device Simulator\n";
  std::cout << "Temperature: " << value << " C\n";
  std::cout << "Device status: " << (embeddedcore::is_healthy(value) ? "HEALTHY" : "WARNING") << "\n";
  std::cout << "Telemetry: " << embeddedcore::format_telemetry(value) << "\n";
  return embeddedcore::is_healthy(value) ? 0 : 1;
}
