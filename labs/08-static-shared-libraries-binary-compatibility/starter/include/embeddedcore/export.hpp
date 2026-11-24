#pragma once

// BUILD_SHARED_LIBS decides which kind of EmbeddedCore target this build creates.
// EMBEDDEDCORE_SHARED is propagated to consumers when a DLL is being used.
#if defined(_WIN32) && defined(EMBEDDEDCORE_SHARED)
  #if defined(EMBEDDEDCORE_BUILDING_LIBRARY)
    #define EMBEDDEDCORE_API __declspec(dllexport)
  #else
    #define EMBEDDEDCORE_API __declspec(dllimport)
  #endif
#elif defined(__GNUC__) && defined(EMBEDDEDCORE_SHARED)
  #define EMBEDDEDCORE_API __attribute__((visibility("default")))
#else
  #define EMBEDDEDCORE_API
#endif
