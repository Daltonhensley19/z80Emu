cmake_minimum_required(VERSION 3.20)
project(z80EmuTests)

set(CMAKE_CXX_STANDARD 20)

include_directories(../include)




add_executable(z80EmuTests
        memorySuite.cpp)