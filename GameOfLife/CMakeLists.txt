cmake_minimum_required(VERSION 3.13 FATAL_ERROR)
project(GameOfLife)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

set(GAME_OF_LIFE_ROOT ${CMAKE_CURRENT_SOURCE_DIR})
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -pedantic -Wall -Wextra -Wshadow")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fno-rtti -fno-exceptions")

find_package(SFML 2.5 COMPONENTS system window graphics audio network REQUIRED)

add_executable(game-of-life game_of_life.cpp app.cpp)
target_link_libraries(game-of-life graph-lib)

add_subdirectory(grlib)
