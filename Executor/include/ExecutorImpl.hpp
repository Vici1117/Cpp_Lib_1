#ifndef EXECUTORIMPL_HPP
#define EXECUTORIMPL_HPP 1

#include "Executor.hpp"
#include <string>

namespace adas{
    class ExecutorImpl:public Executor{
        public:

        explicit ExecutorImpl(const Pose& Pose) noexcept;

        ~ExecutorImpl() noexcept =default;

        ExecutorImpl(const ExecutorImpl &) =delete;

        ExecutorImpl &operator=(const ExecutorImpl &)=delete;

        public:

        Pose State() const noexcept override;

        void Execute(const std::string &commands) noexcept override;

        private:

        Pose pose;

        void Move() noexcept;
    };
}

#endif