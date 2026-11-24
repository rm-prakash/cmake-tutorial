#include "embeddedcore/sensor.hpp"
#include <cmath>
int main() {
  if (std::fabs(embeddedcore::read_temperature() - 25.5) > 0.001) return 1;
  if (!embeddedcore::is_healthy(25.5)) return 2;
  if (embeddedcore::is_healthy(45.0)) return 3;
  return 0;
}
