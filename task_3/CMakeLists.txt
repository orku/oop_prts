cmake_minimum_required(VERSION 3.20)
project(task_3)

set(CMAKE_CXX_STANDARD 17)

add_subdirectory(missions)
add_subdirectory(application)

add_executable(task_3 main.cpp)

target_link_libraries(task_3 PRIVATE mission application)