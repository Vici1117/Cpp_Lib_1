#ifndef EXECUTORIMPL_HPP
#define EXECUTORIMPL_HPP 1

#include "Executor.hpp"
#include <string>

namespace adas{
    class ExecutorImpl final:public Executor{
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
        
        class MoveCommand final{
            public:
            void DoOperate(ExecutorImpl& executor)const noexcept{
                executor.Move();
            }
        };

        class TurnLeftCommand final{
            public:
            void DoOperate(ExecutorImpl& executor)const noexcept{
                executor.TurnLeft();
            }
        };

        class TurnRightCommand final{
            public:
            void DoOperate(ExecutorImpl& executor)const noexcept{
                executor.TurnRight();
            }
        };

        void Move() noexcept;

        void TurnLeft() noexcept;

        void TurnRight() noexcept;

    };
}

#endif