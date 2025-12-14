#pragma once

#include <cstdint>


// time in milliseconds
typedef uint32_t timeMs32_t;
typedef uint64_t timeMs64_t;
typedef int32_t timeMsDelta_t; // 32 bits is always sufficient for time delta
inline timeMsDelta_t timeDifferenceMs(timeMs32_t a, timeMs32_t b) { return static_cast<timeMsDelta_t>(static_cast<int32_t>(a) - static_cast<int32_t>(b)); }
inline timeMsDelta_t timeDifferenceMs(timeMs64_t a, timeMs64_t b) { return static_cast<timeMsDelta_t>(static_cast<int64_t>(a) - static_cast<int64_t>(b)); }

// time in microseconds
typedef uint32_t timeUs32_t;
typedef uint64_t timeUs64_t;
typedef int32_t timeUsDelta_t; // 32 bits is always sufficient for time delta
inline timeUsDelta_t timeDifferenceUs(timeUs32_t a, timeUs32_t b) { return static_cast<timeUsDelta_t>(static_cast<int32_t>(a) - static_cast<int32_t>(b)); }
inline timeUsDelta_t timeDifferenceUs(timeUs64_t a, timeUs64_t b) { return static_cast<timeUsDelta_t>(static_cast<int64_t>(a) - static_cast<int64_t>(b)); }


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

#elif defined(FRAMEWORK_STM32_CUBE)

#if defined(FRAMEWORK_STM32_CUBE_F1)
#include <stm32f1xx_hal.h>
#elif defined(FRAMEWORK_STM32_CUBE_F3)
#include <stm32f3xx_hal.h>
#elif defined(FRAMEWORK_STM32_CUBE_F4)
#include <stm32f4xx_hal.h>
#elif defined(FRAMEWORK_STM32_CUBE_F7)
#include <stm32f7xx_hal.h>
#endif

inline timeUs32_t timeUs() { enum {msToUs = 1000}; return static_cast<timeUs32_t>(HAL_GetTick()*msToUs); }
inline timeUs64_t timeUs64() { enum {msToUs = 1000}; return static_cast<timeUs64_t>(HAL_GetTick()*msToUs); }

inline timeMs32_t timeMs() { return static_cast<timeUs32_t>(HAL_GetTick()); }
inline timeMs64_t timeMs64() { return static_cast<timeUs64_t>(HAL_GetTick()); }

#elif defined(FRAMEWORK_TEST)

inline timeUs32_t timeUs() { return 0; }
inline timeUs64_t timeUs64() { return 0; }

inline timeMs32_t timeMs() { return 0; }
inline timeMs64_t timeMs64() { return 0; }

#else // defaults to FRAMEWORK_ARDUINO

#if defined(FRAMEWORK_ARDUINO_ESP32)
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
