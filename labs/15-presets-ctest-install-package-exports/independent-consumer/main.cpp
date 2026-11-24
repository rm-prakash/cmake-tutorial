#include <embeddedcore/sensor.hpp>
#include <embeddedcore/diagnostics.hpp>
#include <iostream>
int main() {
 auto value=embeddedcore::read_temperature();
 if (!embeddedcore::is_healthy(value)) return 1;
 std::cout << "Independent consumer OK: " << embeddedcore::format_telemetry(value) << "\n";
 return 0;
}
