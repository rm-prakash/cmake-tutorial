#include "embeddedcore/sensor.hpp"
#include "embeddedcore/diagnostics.hpp"
#include <string_view>
int main() {
    if (embeddedcore::read_temperature_c() != 25.5) return 1;
    if (std::string_view(embeddedcore::classify_temperature(25.5)) != "HEALTHY") return 2;
    if (std::string_view(embeddedcore::classify_temperature(45.0)) != "WARNING") return 3;
    return 0;
}
