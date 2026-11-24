#pragma once
#if defined(_WIN32)
  #if defined(EMBEDDEDCORE_BUILDING)
    #define EMBEDDEDCORE_API __declspec(dllexport)
  #else
    #define EMBEDDEDCORE_API __declspec(dllimport)
  #endif
#else
  #define EMBEDDEDCORE_API __attribute__((visibility("default")))
#endif
namespace embeddedcore {
EMBEDDEDCORE_API double temperature_celsius();
EMBEDDEDCORE_API const char* health_status();
EMBEDDEDCORE_API const char* communication_status();
}
