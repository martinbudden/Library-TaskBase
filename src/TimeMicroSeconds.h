#pragma once

// time in milliseconds
typedef uint32_t timeMs32_t;
typedef uint64_t timeMs64_t;

// time in microseconds
typedef uint32_t timeUs32_t;
typedef uint64_t timeUs64_t;

#if defined(FRAMEWORK_RPI_PICO)

#include <pico/time.h>
inline timeUs32_t timeUs() { return time_us_32(); }
inline timeUs64_t timeUs64() { return time_us_64(); }

inline timeMs32_t timeMs() { return static_cast<timeMs32_t>(time_us_64() / 1000); }
inline timeMs64_t timeMs64() { return time_us_64() / 1000; }

#elif defined(FRAMEWORK_ESPIDF)

#include <esp_timer.h>
inline timeUs32_t timeUs() { return static_cast<timeUs32_t>(esp_timer_get_time()); }
inline timeUs64_t timeUs64() { return esp_timer_get_time(); }

inline timeUs32_t timeMs() { return static_cast<timeUs32_t>(esp_timer_get_time() / 1000); }
inline timeUs64_t timeMs64() { return esp_timer_get_time() / 1000; }

#elif defined(FRAMEWORK_TEST)

inline timeUs32_t timeUs() { return 0; }
inline timeUs64_t timeUs64() { return 0; }

inline timeMs32_t timeMs() { return 0; }
inline timeMs64_t timeMs64() { return 0; }

#else // defaults to FRAMEWORK_ARDUINO

#if defined(USE_ARDUINO_ESP32)
#include <esp_timer.h>
inline timeUs32_t timeUs() { return static_cast<timeUs32_t>(esp_timer_get_time()); }
inline timeUs64_t timeUs64() { return esp_timer_get_time(); }

inline timeUs32_t timeMs() { return static_cast<timeUs32_t>(esp_timer_get_time() / 1000); }
inline timeUs64_t timeMs64() { return esp_timer_get_time() / 1000; }
#else
#include <Arduino.h>
inline timeUs32_t timeUs() { return micros(); } // overflows after approximately 70 minutes.
inline timeMs32_t timeMs() { return millis(); } // overflows after approximately 50 days.
#endif

#endif // FRAMEWORK
