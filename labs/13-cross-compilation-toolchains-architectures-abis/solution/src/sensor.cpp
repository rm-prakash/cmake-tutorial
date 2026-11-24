#include "embeddedcore/sensor.hpp"

namespace embeddedcore {
double read_temperature() noexcept { return 25.5; }
bool is_healthy(double temperature_celsius) noexcept {
    return temperature_celsius <= 40.0;
}
}
