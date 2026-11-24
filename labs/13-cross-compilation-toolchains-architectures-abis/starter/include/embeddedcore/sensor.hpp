#pragma once

namespace embeddedcore {
double read_temperature() noexcept;
bool is_healthy(double temperature_celsius) noexcept;
}
