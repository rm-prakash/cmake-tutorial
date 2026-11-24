#include "support/status_format.hpp"
namespace support {
const char* format_status(bool healthy) {
    return healthy ? "HEALTHY" : "WARNING";
}
}
