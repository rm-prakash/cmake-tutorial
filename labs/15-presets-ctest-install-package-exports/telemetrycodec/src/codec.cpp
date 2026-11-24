#include "telemetrycodec/codec.hpp"
#include <sstream>
namespace telemetrycodec {
std::string encode_temperature(double t) {
  std::ostringstream out;
  out << "TELEMETRY:TEMP=" << t;
  return out.str();
}
}
