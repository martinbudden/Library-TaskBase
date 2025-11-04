#pragma once

#include <cstdint>


class MessageQueueBase {
public:
    virtual ~MessageQueueBase() = default;
    virtual int32_t WAIT(uint32_t& timeMicroseconds) = 0;
};
