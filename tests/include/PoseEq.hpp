#ifndef POSEEQ_HPP
#define POSEEQ_HPP 1

#include <tuple>

#include "Executor.hpp"

namespace adas
{
    bool operator==(const Pose &lhs, const Pose &rhs);
}

#endif