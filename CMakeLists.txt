cmake_minimum_required(VERSION 3.22)
project(TEMPLATE_FILE)

enable_testing()
SET(WorkSpaceFolder ${CMAKE_CURRENT_SOURCE_DIR})

add_subdirectory(Executor)

add_executable(output main.cpp)
target_include_directories(output PUBLIC Executor)
target_link_libraries(output PUBLIC Executor)

add_subdirectory(tests)
