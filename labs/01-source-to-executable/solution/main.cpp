#include <iostream>
#include <string>

int main() {
    const std::string deviceId = "SIM-001";
    const std::string firmwareVersion = "1.0.0";
    const double temperature = 36.0;
    const double pressure = 101.3;

    std::cout << "Embedded Device Simulator\n";
    std::cout << "-------------------------\n";
    std::cout << "Device ID: " << deviceId << "\n";
    std::cout << "Firmware: " << firmwareVersion << "\n";
    std::cout << "Temperature: " << temperature << " C\n";
    std::cout << "Pressure: " << pressure << " kPa\n";

    if (temperature > 45.0) {
        std::cout << "Device status: CRITICAL\n";
    } else if (temperature > 35.0) {
        std::cout << "Device status: WARNING\n";
    } else {
        std::cout << "Device status: NORMAL\n";
    }

    return 0;
}
