#include <TaskBase.h>
#include <TimeMicroseconds.h>

#include <array>
#include <unity.h>

void setUp()
{
}

void tearDown()
{
}

// NOLINTBEGIN(cppcoreguidelines-avoid-magic-numbers,cppcoreguidelines-pro-bounds-pointer-arithmetic,misc-const-correctness,readability-magic-numbers)
void test_task_base()
{
    enum { TASK_INTERVAL_MICROSECONDS = 5000 };
    const TaskBase task(TASK_INTERVAL_MICROSECONDS);

    TEST_ASSERT_EQUAL(TASK_INTERVAL_MICROSECONDS, task.getTaskIntervalMicroseconds());
    TEST_ASSERT_EQUAL(0, task.getTickCountDelta());
    TEST_ASSERT_EQUAL(0, task.getTimeMicroSecondDelta());

    TEST_ASSERT_EQUAL(0, timeMs());
    TEST_ASSERT_EQUAL(0, timeUs());
    TEST_ASSERT_EQUAL(0, timeMs64());
    TEST_ASSERT_EQUAL(0, timeUs64());
}

void test_time_microseconds()
{
    timeMs32_t tms32a = 2;
    timeMs32_t tms32b = 5;
    timeMsDelta_t tmsDelta32 = timeDifferenceMs(tms32a, tms32b);
    TEST_ASSERT_EQUAL(-3, tmsDelta32);

    timeMs64_t tms64a = 7;
    timeMs64_t tms64b = 11;
    timeMsDelta_t tmsDelta64 = timeDifferenceMs(tms64a, tms64b);
    TEST_ASSERT_EQUAL(-4, tmsDelta64);

    timeUs32_t tus32a = 13;
    timeUs32_t tus32b = 23;
    timeUsDelta_t tusDelta32 = timeDifferenceUs(tus32a, tus32b);
    TEST_ASSERT_EQUAL(-10, tusDelta32);

    timeUs64_t tus64a = 29;
    timeUs64_t tus64b = 31;
    timeUsDelta_t tusDelta64 = timeDifferenceUs(tus64a, tus64b);
    TEST_ASSERT_EQUAL(-2, tusDelta64);
}

// NOLINTEND(cppcoreguidelines-avoid-magic-numbers,cppcoreguidelines-pro-bounds-pointer-arithmetic,misc-const-correctness,readability-magic-numbers)

int main([[maybe_unused]] int argc, [[maybe_unused]] char **argv)
{
    UNITY_BEGIN();

    RUN_TEST(test_task_base);
    RUN_TEST(test_time_microseconds);

    UNITY_END();
}
