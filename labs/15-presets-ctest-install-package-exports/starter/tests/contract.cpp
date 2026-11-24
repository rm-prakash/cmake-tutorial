#include "embeddedcore/sensor.hpp"
#include "embeddedcore/diagnostics.hpp"
#include <string>
int main() {
  if (!embeddedcore::is_healthy(25.5)) return 1;
  if (embeddedcore::is_healthy(45.0)) return 2;
  if (embeddedcore::format_telemetry(25.5).empty()) return 3;
  return 0;
}
