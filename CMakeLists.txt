cmake_minimum_required(VERSION 3.28.1)
project(Filozofowie)

set(CMAKE_CXX_STANDARD 17)

set(CMAKE_GENERATOR_PLATFORM x64) # Dla 64-bit
set(CMAKE_EXE_LINKER_FLAGS "-static -W")

add_executable(Filozofowie main.cpp
        Helper.cpp
        Helper.h
        Program.cpp
        Program.h
        Philosopher.cpp
        Philosopher.h
        main.cpp)
