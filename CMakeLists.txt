cmake_minimum_required(VERSION 3.28.1)
project(Filozofowie)

set(CMAKE_CXX_STANDARD 17)

add_executable(Filozofowie main.cpp
        Philosopher.cpp
        Philosopher.h
        Helper.cpp
        Helper.h
        Program.cpp
        Program.h
        Semaphore.cpp
        Semaphore.h
        main.cpp)
