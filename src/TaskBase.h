#pragma once

#include <cstdint>

class TaskBase {
public:
    struct parameters_t {
        TaskBase* task;
    };
    struct task_info_t {
        void* taskHandle;
        const char* name;
        uint32_t stackDepthBytes;
        uint8_t* stackBuffer;
        uint32_t priority;
        uint32_t core;
        uint32_t taskIntervalMicroseconds;
    };
public:
    explicit TaskBase(uint32_t taskIntervalMicroseconds) : _taskIntervalMicroseconds(taskIntervalMicroseconds) {}
    TaskBase() : TaskBase(0) {}
public:
    inline void setTaskIntervalMicroseconds(uint32_t taskIntervalMicroseconds) { _taskIntervalMicroseconds = taskIntervalMicroseconds; }
    inline uint32_t getTaskIntervalMicroseconds() const { return _taskIntervalMicroseconds; }
    inline uint32_t getTickCountDelta() const { return _tickCountDelta; }
    inline uint32_t getTimeMicroSecondDelta() const { return _timeMicrosecondsDelta; }
protected:
    uint32_t _taskIntervalMicroseconds {0};
    uint32_t _previousWakeTimeTicks {0};
    uint32_t _tickCountDelta {0};
    uint32_t _tickCountPrevious {0};
    uint32_t _timeMicrosecondsDelta {0};
    uint32_t _timeMicrosecondsPrevious {0};
};
