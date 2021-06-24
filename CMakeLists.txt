cmake_minimum_required(VERSION 3.20)
project(z80Emu)

set(CMAKE_CXX_STANDARD 20)

set(CMAKE_CXX_FLAGS "-Wall -Wextra")



include_directories(z80Emu include/*)
add_executable(z80Emu
        src/main.cpp src/z80.cpp src/registers.cpp src/memory.cpp src/stack.cpp)

add_subdirectory(tests)