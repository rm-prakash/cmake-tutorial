#include "embeddedcore/diagnostics.hpp"
#include <string_view>
int main() {
    const std::string_view actual = embeddedcore::build_configuration();
#if defined(EMBEDDEDCORE_DEBUG_BUILD)
    return actual == "Debug" ? 0 : 1;
#elif defined(EMBEDDEDCORE_RELEASE_BUILD)
    return actual == "Release" ? 0 : 2;
#else
    return actual == "Other configuration" ? 0 : 3;
#endif
}
