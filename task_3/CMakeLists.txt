cmake_minimum_required(VERSION 3.20)
project(task_3)

set(CMAKE_CXX_STANDARD 17)

add_subdirectory(missions)
add_executable(task_3 main.cpp)

#target_sources(task_3
#        PRIVATE
#        missions/mission.h
#        missions/dive.h
#        missions/dive.cpp
#        missions/lift.h
#        missions/lift.cpp
#        missions/move.h
#        missions/move.cpp
#        missions/return.h
#        missions/return.cpp
#        )