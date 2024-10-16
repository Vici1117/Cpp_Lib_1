#include "ExecutorImpl.hpp"

#include <new>
#include <algorithm>

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
            switch (sig_command)
            {
            case 'M':
                {
                    if(pose.heading=='E')
                        ++pose.x;
                    else if(pose.heading=='W')
                        --pose.x;
                    else if(pose.heading=='N')
                        ++pose.y;
                    else
                        --pose.y;
                }
            }
        };
        std::for_each(commands.begin(), commands.end(),eachMove);
    }
}
