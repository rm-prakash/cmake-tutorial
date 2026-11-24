#include "embeddedcore/telemetry.hpp"
#include "embeddedcore/sensor.hpp"
#include "telemetrycodec/codec.hpp"
namespace embeddedcore {
std::string make_telemetry() {
    return telemetrycodec::encode_temperature(read_temperature());
}
}
