#include "embeddedcore/diagnostics/diagnostics.hpp"
namespace embeddedcore::diagnostics {
std::string status(bool warning) { return warning ? "WARNING" : "HEALTHY"; }
}
