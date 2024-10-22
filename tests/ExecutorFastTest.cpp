#include "gtest/gtest.h"
#include "PoseEq.hpp"

#include <memory>

namespace adas
{
    TEST(ExecutorFastMove, should_return_x_plus_2_given_status_is_fast_command_is_M_and_facing_is_E)
    {
        // given
        std::unique_ptr<Executor> executorP(Executor::newExecutor({0, 0, 'E'}));
        // when
        executorP->Execute("FM");
        // then
        const Pose target({2, 0, 'E'});
        ASSERT_EQ(target, executorP->State());
    }

    TEST(ExecutorFastMove, should_return_y_plus_1_given_command_is_FFM_and_facing_is_N)
    {
        // given
        std::unique_ptr<Executor> executorP(Executor::newExecutor());
        // when
        executorP->Execute("FFM");
        // then
        const Pose target({0, 1, 'N'});
        ASSERT_EQ(target, executorP->State());
    }

    TEST(ExecutorFastTurnLeft, should_return_N_and_x_plus_1_given_status_is_fast_command_is_L_and_facing_is_E)
    {
        // given
        std::unique_ptr<Executor> executorP(Executor::newExecutor({0, 0, 'E'}));
        // when
        executorP->Execute("FL");
        // then
        const Pose target({1, 0, 'N'});
        ASSERT_EQ(target, executorP->State());
    }

    TEST(ExecutorFastTurnRight, should_return_S_and_x_plus_1_given_status_is_fast_command_is_R_and_facing_is_E)
    {
        // given
        std::unique_ptr<Executor> executorP(Executor::newExecutor({0, 0, 'E'}));
        // when
        executorP->Execute("FR");
        // then
        const Pose target({1, 0, 'S'});
        ASSERT_EQ(target, executorP->State());
    }
}