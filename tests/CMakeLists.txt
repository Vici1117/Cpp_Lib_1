cmake_minimum_required(VERSION 3.22)
project(test)

add_subdirectory(${WorkSpaceFolder}/gtest googletest)

#测试依赖库
add_library(TestLib STATIC src/PoseEq.cpp)
target_include_directories(TestLib PUBLIC ${WorkSpaceFolder}/Executor/include)
target_include_directories(TestLib PUBLIC include)
target_link_libraries(TestLib PUBLIC Executor)

#生成ExecutorTest
add_executable(ExecutorTest ExecutorTest.cpp)
target_include_directories(ExecutorTest PUBLIC ${WorkSpaceFolder}/gtest/googletest/include)
target_include_directories(ExecutorTest PUBLIC ${WorkSpaceFolder}/Executor/include)
target_include_directories(ExecutorTest PUBLIC include)
target_link_libraries(ExecutorTest PUBLIC gtest gtest_main Executor TestLib)
add_test(NAME ExecutorTest COMMAND ExecutorTest)

#生成ExecutorFastTest
add_executable(ExecutorFastTest ExecutorFastTest.cpp)
target_include_directories(ExecutorFastTest PUBLIC ${WorkSpaceFolder}/gtest/googletest/include)
target_include_directories(ExecutorFastTest PUBLIC ${WorkSpaceFolder}/Executor/include)
target_include_directories(ExecutorFastTest PUBLIC include)
target_link_libraries(ExecutorFastTest PUBLIC gtest gtest_main Executor TestLib)
add_test(NAME ExecutorFastTest COMMAND ExecutorFastTest)