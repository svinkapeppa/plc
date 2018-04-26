cmake_minimum_required(VERSION 3.9)
project(hw4)

set(CMAKE_CXX_STANDARD 17)

add_executable(
        hw4
        main.cpp
        utils.h
        RTTI.h RTTI.cpp
        src/Person.cpp src/Person.h
        src/Programmer.cpp src/Programmer.h
        src/Mathematician.cpp src/Mathematician.h
        src/Analyst.cpp src/Analyst.h
)