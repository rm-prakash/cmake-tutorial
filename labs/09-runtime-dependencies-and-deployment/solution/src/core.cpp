#include "embeddedcore/core.hpp"
#include "transport/transport.hpp"
namespace embeddedcore {
double temperature_celsius() { return 25.5; }
const char* health_status() { return temperature_celsius() > 40.0 ? "WARNING" : "HEALTHY"; }
const char* communication_status() { return transport::connection_status(); }
}
