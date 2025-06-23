#include <TaskBase.h>
#include <array>
#include <unity.h>

void setUp()
{
}

void tearDown()
{
}

// NOLINTBEGIN(cppcoreguidelines-avoid-magic-numbers,cppcoreguidelines-pro-bounds-pointer-arithmetic,readability-magic-numbers)
void test_task_base()
{
    enum { TASK_INTERVAL_MICROSECONDS = 5000 };
    const TaskBase task(TASK_INTERVAL_MICROSECONDS);

    TEST_ASSERT_EQUAL(TASK_INTERVAL_MICROSECONDS, task.getTaskIntervalMicroSeconds());
    TEST_ASSERT_EQUAL(0, task.getTickCountDelta());
    TEST_ASSERT_EQUAL(0, task.getTimeMicroSecondDelta());
}

// NOLINTEND(cppcoreguidelines-avoid-magic-numbers,cppcoreguidelines-pro-bounds-pointer-arithmetic,readability-magic-numbers)

int main([[maybe_unused]] int argc, [[maybe_unused]] char **argv)
{
    UNITY_BEGIN();

    RUN_TEST(test_task_base);

    UNITY_END();
}
