cmake_minimum_required(VERSION 3.28.1)
project(Filozofowie)

set(CMAKE_CXX_STANDARD 17)

add_executable(Filozofowie main.cpp
        Helper.cpp
        Helper.h
        Program.cpp
        Program.h
        Philosopher.cpp
        Philosopher.h
        main.cpp)
