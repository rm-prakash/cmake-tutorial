#include <iostream>

int main() {
    double temperature = 25.5;

    std::cout << "Embedded Device Simulator\n";
    std::cout << "-------------------------\n";
    std::cout << "Temperature: " << temperature << " C\n";

    if (temperature > 40.0) {
        std::cout << "Device status: WARNING\n";
    } else {
        std::cout << "Device status: HEALTHY\n";
    }

    return 0;
}
