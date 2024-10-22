#include "ExecutorImpl.hpp"

#include <new>
#include <algorithm>
#include <memory>

namespace adas
{
    ExecutorImpl::ExecutorImpl(const Pose &pose) noexcept : pose(pose) {};

    Pose ExecutorImpl::State(void) const noexcept
    {
        return pose;
    }

    Executor *Executor::newExecutor(const Pose &pose) noexcept
    {
        return new (std::nothrow) ExecutorImpl(pose);
    }

    void ExecutorImpl::Execute(const std::string &commands) noexcept
    {
        auto eachMove = [this](const char &sig_command) -> void
        {
            std::unique_ptr<ICommand> cmder;
            switch (sig_command)
            {
            case 'M':
                cmder = std::make_unique<MoveCommand>();
                break;
            case 'L':
                cmder = std::make_unique<TurnLeftCommand>();
                break;
            case 'R':
                cmder = std::make_unique<TurnRightCommand>();
                break;
            case 'F':
                cmder =std::make_unique<FastCommand>();
                break;
            }
            if (cmder)
                cmder->DoOperate(*this);
        };
        std::for_each(commands.begin(), commands.end(), eachMove);
    }

    void ExecutorImpl::Move() noexcept
    {
        if (pose.heading == 'E')
            ++pose.x;
        else if (pose.heading == 'W')
            --pose.x;
        else if (pose.heading == 'N')
            ++pose.y;
        else
            --pose.y;
    }

    void ExecutorImpl::TurnLeft() noexcept
    {
        if (pose.heading == 'E')
            pose.heading = 'N';
        else if (pose.heading == 'W')
            pose.heading = 'S';
        else if (pose.heading == 'N')
            pose.heading = 'W';
        else
            pose.heading = 'E';
    }

    void ExecutorImpl::TurnRight() noexcept
    {
        if (pose.heading == 'E')
            pose.heading = 'S';
        else if (pose.heading == 'W')
            pose.heading = 'N';
        else if (pose.heading == 'N')
            pose.heading = 'E';
        else
            pose.heading = 'W';
    }

    void ExecutorImpl::Fast() noexcept
    {
        fast = (fast ? 0 : 1);
    }

    bool ExecutorImpl::IsFast() const noexcept
    {
        return fast;
    }
}
