#pragma once
#ifndef EMBEDDEDCORE_API_LEVEL
#error "EmbeddedCore API version is missing from target usage requirements"
#endif
#if EMBEDDEDCORE_API_LEVEL != 2
#error "Unexpected EmbeddedCore API version"
#endif
namespace embeddedcore {
    double read_temperature();
    const char* build_configuration();
    const char* target_system();
}
