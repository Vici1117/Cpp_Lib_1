cmake_minimum_required(VERSION 3.22)
project(test)

add_subdirectory(${WorkSpaceFolder}/gtest googletest)

add_executable(ExecutorTest ExecutorTest.cpp)
target_include_directories(ExecutorTest PUBLIC ${WorkSpaceFolder}/gtest/googletest/include)
target_include_directories(ExecutorTest PUBLIC ${WorkSpaceFolder}/Executor/include)
target_link_libraries(ExecutorTest PUBLIC gtest gtest_main Executor)

add_test(NAME ExecutorTest COMMAND ExecutorTest)