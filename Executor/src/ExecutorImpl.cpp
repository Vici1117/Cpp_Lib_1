#include "ExecutorImpl.hpp"

#include <new>

namespace adas{
    ExecutorImpl::ExecutorImpl(const Pose &pose) noexcept:pose(pose){};

    Pose ExecutorImpl::State(void) const noexcept{
        return pose;
    }

    Executor *Executor::newExecutor(const Pose &pose) noexcept{
        return new(std::nothrow) ExecutorImpl(pose);
    }
}
