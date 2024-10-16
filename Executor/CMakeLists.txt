cmake_minimum_required(VERSION 3.22)
project(Executor)

SET(EXECUTOR_SRC ./src/Executor.cpp;./src/ExecutorImpl.cpp)

add_library(Executor SHARED ${EXECUTOR_SRC})
target_include_directories(Executor PUBLIC include)
