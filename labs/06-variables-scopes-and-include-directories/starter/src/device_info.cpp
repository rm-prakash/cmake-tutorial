#include "embeddedcore/device_info.hpp"
#include "embeddedcore/device_config.hpp"
namespace embeddedcore {
    const char* device_label() { return configuration::label; }
}
