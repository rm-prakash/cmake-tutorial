#include "embeddedcore/core.hpp"
#include <iomanip>
#include <sstream>
#ifdef EMBEDDEDCORE_USE_FIXTURE
#include "telemetrycodec/codec.hpp"
#elif defined(EMBEDDEDCORE_USE_OPENSSL)
#include <openssl/sha.h>
#endif
namespace embeddedcore {
std::string report(double temperature) {
  std::ostringstream out;
  out << "Temperature: " << std::fixed << std::setprecision(1) << temperature << " C\n";
  out << "Device status: " << (temperature > 40.0 ? "WARNING" : "HEALTHY") << "\n";
#ifdef EMBEDDEDCORE_USE_FIXTURE
  out << "Provider: fixture\n" << "Telemetry: " << telemetrycodec::encode(temperature);
#else
  // SHA-256 is merely a demonstrator for real OpenSSL symbol linkage.
  // This is not a security protocol, FIPS assertion, or password hashing example.
  const std::string value = "device-demo";
  unsigned char digest[SHA256_DIGEST_LENGTH];
  SHA256(reinterpret_cast<const unsigned char*>(value.data()), value.size(), digest);
  out << "Provider: openssl\n" << "Demo SHA256 prefix: ";
  out << std::hex << std::setfill('0');
  for (int i = 0; i < 4; ++i) out << std::setw(2) << static_cast<unsigned>(digest[i]);
#endif
  return out.str();
}
}
