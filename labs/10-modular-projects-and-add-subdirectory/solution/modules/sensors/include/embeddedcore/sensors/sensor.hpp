#pragma once
namespace embeddedcore::sensors {
struct Reading { double celsius; };
Reading read_temperature();
}
