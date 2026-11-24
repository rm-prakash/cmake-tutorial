#include "embeddedcore/diagnostics.hpp"
#ifdef EMBEDDEDCORE_WITH_TELEMETRY
#include "telemetrycodec/codec.hpp"
#else
#include <string>
#endif
namespace embeddedcore {
  std::string format_telemetry(double value) {
#ifdef EMBEDDEDCORE_WITH_TELEMETRY
    return telemetrycodec::encode_temperature(value);
#else
    return "TEMP:" + std::to_string(value);
#endif
  }
}
