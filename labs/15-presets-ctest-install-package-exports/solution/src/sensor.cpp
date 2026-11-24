#include "embeddedcore/sensor.hpp"
namespace embeddedcore {
  double read_temperature() { return 25.5; }
  bool is_healthy(double temperature) { return temperature <= 40.0; }
}
