add_library(mission
        STATIC dive.cpp
        lift.cpp
        move.cpp
        return.cpp
        )

target_include_directories(mission PUBLIC ${CMAKE_SOURCE_DIR}/missions)