#include "embeddedcore/core.hpp"
#include <iostream>
int main() {
  std::cout << "Embedded Device Simulator\n";
  std::cout << "Temperature: " << embeddedcore::temperature_celsius() << " C\n";
  std::cout << "Device status: " << embeddedcore::health_status() << '\n';
  std::cout << "Communication: " << embeddedcore::communication_status() << '\n';
}
