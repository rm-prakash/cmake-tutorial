#include "embeddedcore/core.hpp"
#include <string>
int main() {
  const auto healthy = embeddedcore::report(25.5);
  const auto warning = embeddedcore::report(45.0);
  if (healthy.find("HEALTHY") == std::string::npos) return 1;
  if (warning.find("WARNING") == std::string::npos) return 2;
  if (healthy.find("Provider:") == std::string::npos) return 3;
  return 0;
}
