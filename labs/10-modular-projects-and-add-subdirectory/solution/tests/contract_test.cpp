#include "embeddedcore/controller/controller.hpp"
#include "embeddedcore/sensors/sensor.hpp"
int main() {
  const auto ok = embeddedcore::controller::evaluate({25.5});
  const auto hot = embeddedcore::controller::evaluate({45.0});
  return (ok.health == "HEALTHY" && hot.health == "WARNING" &&
          ok.connection == "CONNECTED (simulated)") ? 0 : 1;
}
