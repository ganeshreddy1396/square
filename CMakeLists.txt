cmake_minimum_required(VERSION 3.10)
project(square_project)

set(CMAKE_CXX_STANDARD 11)

include_directories(include)

add_executable(square_app src/main.cpp)
