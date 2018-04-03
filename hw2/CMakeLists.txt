cmake_minimum_required(VERSION 3.9)
project(hw2)

set(CMAKE_CXX_STANDARD 17)

add_executable(hw2 tests/nestedexception.cpp utils.h Objects.h Exceptions.h Objects.cpp Exceptions.cpp)