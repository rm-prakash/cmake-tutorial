#include "embeddedcore/sensor.hpp"
namespace embeddedcore {
  double read_temperature() noexcept { return 25.5; }
  bool is_healthy(double t) noexcept { return t <= 40.0; }
}
