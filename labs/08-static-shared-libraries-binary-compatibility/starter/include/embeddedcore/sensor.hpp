#pragma once
#include "embeddedcore/export.hpp"
namespace embeddedcore {
EMBEDDEDCORE_API double read_temperature();
EMBEDDEDCORE_API bool is_healthy(double temperature);
EMBEDDEDCORE_API const char* status_label(bool healthy);
}
