#include "embeddedcore/sensor.hpp"
#include <iostream>
int main() {
  const auto t = embeddedcore::read_temperature();
  std::cout << "Embedded Device Simulator\nTemperature: " << t
            << " C\nDevice status: " << (embeddedcore::is_healthy(t) ? "HEALTHY" : "WARNING") << '\n';
  return embeddedcore::is_healthy(t) ? 0 : 1;
}
