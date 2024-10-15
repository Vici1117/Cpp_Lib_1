#include "Executor.hpp"
#include "gtest/gtest.h"

#include <tuple>
#include <memory>

namespace adas
{
    bool operator==(const Pose &lhs, const Pose &rhs)
    {
        return std::tie(lhs.x, lhs.y, lhs.heading) == std::tie(rhs.x, rhs.y, rhs.heading);
    }

    TEST(ExecutorTest, should_return_init_pose_when_without_command)
    {
        // given
        std::unique_ptr<Executor> executorP(Executor::newExecutor({0, 0, 'E'}));
        // when

        // then
        const Pose target({0, 0, 'e'});
        ASSERT_EQ(target, executorP->State());
    }

    TEST(ExecutorTest, should_return_default_pose_when_without_init_and_command)
    {
        // given
        std::unique_ptr<Executor> executor(Executor::newExecutor()); 
        //when

        // then
        const Pose target({0, 0, 'N'});
        ASSERT_EQ(target, executor->State());
    }
}