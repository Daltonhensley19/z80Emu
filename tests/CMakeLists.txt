cmake_minimum_required(VERSION 3.20)
project(z80EmuTests)

set(CMAKE_CXX_STANDARD 20)





add_executable(z80EmuTests
        ../src/registers.cpp ../src/memory.cpp memorySuite.cpp registerSuite.cpp)
include_directories(../include/*)
