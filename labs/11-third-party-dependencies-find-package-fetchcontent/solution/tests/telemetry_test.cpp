#include "embeddedcore/telemetry.hpp"
#include <iostream>
int main() {
    const auto actual = embeddedcore::make_telemetry();
    if (actual != "TEMP:25.5") {
        std::cerr << "Unexpected telemetry: " << actual << '\n';
        return 1;
    }
    return 0;
}
