#ifndef EXECUTORIMPL_HPP
#define EXECUTORIMPL_HPP 1

#include "Executor.hpp"
#include <string>

namespace adas
{
    class ExecutorImpl final : public Executor
    {
    public:
        explicit ExecutorImpl(const Pose &Pose) noexcept;

        ~ExecutorImpl() noexcept = default;

        ExecutorImpl(const ExecutorImpl &) = delete;

        ExecutorImpl &operator=(const ExecutorImpl &) = delete;

    public:
        Pose State() const noexcept override;

        void Execute(const std::string &commands) noexcept override;

    private:
        Pose pose;

        bool fast = false;

        class ICommand
        {
        public:
            virtual ~ICommand() = default;

            virtual void DoOperate(ExecutorImpl &executor) const noexcept = 0;
        };

        class MoveCommand final : public ICommand
        {
        public:
            void DoOperate(ExecutorImpl &executor) const noexcept override
            {
                if (executor.IsFast())
                    executor.Move();
                executor.Move();
            }
        };

        class TurnLeftCommand final : public ICommand
        {
        public:
            void DoOperate(ExecutorImpl &executor) const noexcept override
            {
                if (executor.IsFast())
                    executor.Move();
                executor.TurnLeft();
            }
        };

        class TurnRightCommand final : public ICommand
        {
        public:
            void DoOperate(ExecutorImpl &executor) const noexcept override
            {
                if (executor.IsFast())
                    executor.Move();
                executor.TurnRight();
            }
        };

        class FastCommand final : public ICommand
        {
        public:
            void DoOperate(ExecutorImpl &executor) const noexcept override
            {
                executor.Fast();
            }
        };

        void Move() noexcept;

        void TurnLeft() noexcept;

        void TurnRight() noexcept;

        void Fast() noexcept;

        bool IsFast() const noexcept;
    };
}

#endif