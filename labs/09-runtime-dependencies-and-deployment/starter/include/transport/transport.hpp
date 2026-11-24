#pragma once
#if defined(_WIN32)
  #if defined(DEVICE_TRANSPORT_BUILDING)
    #define DEVICE_TRANSPORT_API __declspec(dllexport)
  #else
    #define DEVICE_TRANSPORT_API __declspec(dllimport)
  #endif
#else
  #define DEVICE_TRANSPORT_API __attribute__((visibility("default")))
#endif
namespace transport {
DEVICE_TRANSPORT_API const char* connection_status();
}
