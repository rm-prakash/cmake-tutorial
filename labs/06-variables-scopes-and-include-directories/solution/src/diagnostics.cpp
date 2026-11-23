#include "embeddedcore/diagnostics.hpp"
#include "embeddedcore/device_config.hpp"
namespace embeddedcore {
    bool is_temperature_healthy(double temperature) {
        return temperature <= configuration::warning_threshold_c;
    }
}
