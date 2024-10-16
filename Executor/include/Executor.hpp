#ifndef EXCUTOR_HPP
#define EXCUTOR_HPP 1

#include <string>

namespace adas
{

    using Direct = char;
    struct Pose
    {
        int x;
        int y;
        Direct heading;
    };

    class Executor
    {
    public:
        static Executor *newExecutor(const Pose &pose = {0, 0, 'N'}) noexcept;

    public:
        Executor() = default;

        virtual ~Executor() = default;

        Executor(const Executor &) = delete;

        Executor &operator=(const Executor &) = delete;

    public:
        virtual Pose State() const noexcept = 0;

        virtual void Execute(const std::string &command) noexcept =0;
    };
}

#endif