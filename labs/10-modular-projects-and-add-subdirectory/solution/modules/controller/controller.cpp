#include "embeddedcore/controller/controller.hpp"
#include "embeddedcore/diagnostics/diagnostics.hpp"
#include "embeddedcore/transport/transport.hpp"
namespace embeddedcore::controller {
Report evaluate(sensors::Reading reading) {
  const bool warning = reading.celsius > 40.0;
  return {reading.celsius,
          diagnostics::status(warning),
          transport::connection_status()};
}
}
