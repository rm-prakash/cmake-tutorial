#include "telemetrycodec/codec.hpp"
#include <iomanip>
#include <sstream>
namespace telemetrycodec {
std::string encode_temperature(double celsius) {
    std::ostringstream stream;
    stream << "TEMP:" << std::fixed << std::setprecision(1) << celsius;
    return stream.str();
}
}
