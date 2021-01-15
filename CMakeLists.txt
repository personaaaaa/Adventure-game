# cmake_minimum_required(VERSION <specify CMake version here>)
project(HelloWorld)

set(CMAKE_CXX_STANDARD 11)

include_directories(./include)

add_executable(HelloWorld src/main.cpp)