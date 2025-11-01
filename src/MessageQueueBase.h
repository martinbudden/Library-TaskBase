#pragma once

#include <cstdint>


class MessageQueueBase {
public:
    virtual ~MessageQueueBase() = default;
    virtual int32_t WAIT_IF_EMPTY(uint32_t& timeMicroseconds) const = 0;
};
