cmake_minimum_required(VERSION 3.16)
project(GameEngine)

set(CMAKE_CXX_STANDARD 14)

add_executable(GameEngine main.cpp shader.cpp shader.hpp object.cpp object.hpp)

find_package(OpenGL REQUIRED)

target_link_libraries(GameEngine PUBLIC -lGL -lGLU -lglut -lGLEW -lglfw)

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -O0")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O0")