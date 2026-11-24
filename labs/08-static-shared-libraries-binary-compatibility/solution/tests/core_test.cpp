#include <cassert>
#include <cstring>
#include "embeddedcore/sensor.hpp"
int main() {
    assert(embeddedcore::read_temperature() == 25.5);
    assert(embeddedcore::is_healthy(40.0));
    assert(!embeddedcore::is_healthy(40.1));
    assert(std::strcmp(embeddedcore::status_label(true), "HEALTHY") == 0);
    assert(std::strcmp(embeddedcore::status_label(false), "WARNING") == 0);
}
