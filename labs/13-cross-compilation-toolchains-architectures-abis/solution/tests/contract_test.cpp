#include "embeddedcore/platform_report.hpp"
#include "embeddedcore/sensor.hpp"
#include <cassert>

int main() {
    assert(embeddedcore::read_temperature() == 25.5);
    assert(embeddedcore::is_healthy(40.0));
    assert(!embeddedcore::is_healthy(40.1));
    assert(!embeddedcore::target_system().empty());
    assert(!embeddedcore::target_abi().empty());
}
