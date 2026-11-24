#include "embeddedcore/sensor.hpp"
#include "support/status_format.hpp"
namespace embeddedcore {
double read_temperature() { return 25.5; }
bool is_healthy(double temperature) { return temperature <= 40.0; }
const char* status_label(bool healthy) { return support::format_status(healthy); }
}
