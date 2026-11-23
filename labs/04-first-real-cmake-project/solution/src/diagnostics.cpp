#include "embeddedcore/diagnostics.hpp"
namespace embeddedcore {
    bool is_temperature_healthy(double temperature) {
        return temperature <= 40.0;
    }
}
