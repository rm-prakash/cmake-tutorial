#include "embeddedcore/core.hpp"
#include <iostream>
int main() {
  std::cout << "Embedded Device Simulator\n" << embeddedcore::report(25.5) << '\n';
}
