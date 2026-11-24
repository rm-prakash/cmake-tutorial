#include <iostream>
#include "embeddedcore/sensor.hpp"
#include "embeddedcore/diagnostics.hpp"
#ifdef EMBEDDEDCORE_INTERNAL_TRACE
#error "An implementation-only definition leaked into DeviceSimulator"
#endif
int main() {
    const double t = embeddedcore::read_temperature();
    std::cout << "Embedded Device Simulator\n"
              << "Temperature: " << t << " C\n"
              << "Device status: " << embeddedcore::device_status(t) << "\n"
              << "Core configuration: " << embeddedcore::build_configuration() << "\n"
              << "Target system: " << embeddedcore::target_system() << "\n"
              << "Internal trace: " << (embeddedcore::internal_trace_enabled() ? "ON" : "OFF") << "\n";
    return embeddedcore::device_status(t)[0] == 'H' ? 0 : 1;
}
