#pragma once
#include <string>
#include "embeddedcore/sensors/sensor.hpp"
namespace embeddedcore::controller {
struct Report {
  double temperature_celsius;
  std::string health;
  std::string connection;
};
Report evaluate(sensors::Reading reading);
}
