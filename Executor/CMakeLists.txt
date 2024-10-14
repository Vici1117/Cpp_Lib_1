cmake_minimum_required(VERSION 3.22)
project(Executor)

add_library(Executor SHARED Executor.cpp)
target_include_directories(Executor PUBLIC include)
