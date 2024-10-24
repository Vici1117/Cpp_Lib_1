#include "gtest/gtest.h"
#include "PoseEq.hpp"

#include <memory>

namespace adas
{
    TEST(ExecutorTest, should_return_init_pose_when_without_command)
    {
        // given
        std::unique_ptr<Executor> executorP(Executor::newExecutor({0, 0, 'E'}));
        // when

        // then
        const Pose target({0, 0, 'E'});
        ASSERT_EQ(target, executorP->State());
    }

    TEST(ExecutorTest, should_return_default_pose_when_without_init_and_command)
    {
        // given
        std::unique_ptr<Executor> executor(Executor::newExecutor());
        // when

        // then
        const Pose target({0, 0, 'N'});
        ASSERT_EQ(target, executor->State());
    }

    TEST(MoveTest, should_return_x_plus_1_given_command_is_M_and_facing_is_E)
    {
        // given
        std::unique_ptr<Executor> executor(Executor::newExecutor({0, 0, 'E'}));
        // when
        executor->Execute("M");
        // then
        const Pose target({1, 0, 'E'});
        ASSERT_EQ(target, executor->State());
    }

    TEST(MoveTest, should_return_x_minus_1_given_command_is_M_and_facing_is_W)
    {
        // given
        std::unique_ptr<Executor> executor(Executor::newExecutor({0, 0, 'W'}));
        // when
        executor->Execute("M");
        // then
        const Pose target({-1, 0, 'W'});
        ASSERT_EQ(target, executor->State());
    }

    TEST(MoveTest, should_return_y_plus_1_given_command_is_M_and_facing_is_N)
    {
        // given
        std::unique_ptr<Executor> executor(Executor::newExecutor({0, 0, 'N'}));
        // when
        executor->Execute("M");
        // then
        const Pose target({0, 1, 'N'});
        ASSERT_EQ(target, executor->State());
    }

    TEST(MoveTest, should_return_y_minus_1_given_command_is_M_and_facing_is_S)
    {
        // given
        std::unique_ptr<Executor> executor(Executor::newExecutor({0, 0, 'S'}));
        // when
        executor->Execute("M");
        // then
        const Pose target({0, -1, 'S'});
        ASSERT_EQ(target, executor->State());
    }

    TEST(TurnLeftTest, should_return_N_given_command_is_L_and_facing_is_E)
    {
        // given
        std::unique_ptr<Executor> executor(Executor::newExecutor({0, 0, 'E'}));
        // when
        executor->Execute("L");
        // then
        const Pose target({0, 0, 'N'});
        ASSERT_EQ(target, executor->State());
    }

    TEST(TurnLeftTest, should_return_S_given_command_is_L_and_facing_is_W)
    {
        // given
        std::unique_ptr<Executor> executor(Executor::newExecutor({0, 0, 'W'}));
        // when
        executor->Execute("L");
        // then
        const Pose target({0, 0, 'S'});
        ASSERT_EQ(target, executor->State());
    }

    TEST(TurnLeftTest, should_return_W_given_command_is_L_and_facing_is_N)
    {
        // given
        std::unique_ptr<Executor> executor(Executor::newExecutor({0, 0, 'N'}));
        // when
        executor->Execute("L");
        // then
        const Pose target({0, 0, 'W'});
        ASSERT_EQ(target, executor->State());
    }

    TEST(TurnLeftTest, should_return_E_given_command_is_L_and_facing_is_S)
    {
        // given
        std::unique_ptr<Executor> executor(Executor::newExecutor({0, 0, 'S'}));
        // when
        executor->Execute("L");
        // then
        const Pose target({0, 0, 'E'});
        ASSERT_EQ(target, executor->State());
    }

    TEST(TurnRightTest, should_return_S_given_command_is_R_and_facing_is_E)
    {
        // given
        std::unique_ptr<Executor> executor(Executor::newExecutor({0, 0, 'E'}));
        // when
        executor->Execute("R");
        // then
        const Pose target({0, 0, 'S'});
        ASSERT_EQ(target, executor->State());
    }

    TEST(TurnRightTest, should_return_N_given_command_is_R_and_facing_is_W)
    {
        // given
        std::unique_ptr<Executor> executor(Executor::newExecutor({0, 0, 'W'}));
        // when
        executor->Execute("R");
        // then
        const Pose target({0, 0, 'N'});
        ASSERT_EQ(target, executor->State());
    }

    TEST(TurnRightTest, should_return_E_given_command_is_R_and_facing_is_N)
    {
        // given
        std::unique_ptr<Executor> executor(Executor::newExecutor({0, 0, 'N'}));
        // when
        executor->Execute("R");
        // then
        const Pose target({0, 0, 'E'});
        ASSERT_EQ(target, executor->State());
    }

    TEST(TurnRightTest, should_return_W_given_command_is_R_and_facing_is_S)
    {
        // given
        std::unique_ptr<Executor> executor(Executor::newExecutor({0, 0, 'S'}));
        // when
        executor->Execute("R");
        // then
        const Pose target({0, 0, 'W'});
        ASSERT_EQ(target, executor->State());
    }

    TEST(MultiMoveTest,N00_RMMR_S20){
        // given
        std::unique_ptr<Executor> executor(Executor::newExecutor({0, 0, 'N'}));
        // when
        executor->Execute("RMMR");
        // then
        const Pose target({2, 0, 'S'});
        ASSERT_EQ(target, executor->State());
    }

    TEST(MultiMoveTest,E00_RRLLMMM_30E){
        // given
        std::unique_ptr<Executor> executor(Executor::newExecutor({0, 0, 'E'}));
        // when
        executor->Execute("RRLLMMM");
        // then
        const Pose target({3, 0, 'E'});
        ASSERT_EQ(target, executor->State());
    }
}