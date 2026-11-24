#include "telemetrycodec/codec.hpp"
#include <iomanip>
#include <sstream>
namespace telemetrycodec {
std::string encode(double temperature) {
  std::ostringstream stream;
  stream << "TEMP:" << std::fixed << std::setprecision(1) << temperature;
  return stream.str();
}
}
