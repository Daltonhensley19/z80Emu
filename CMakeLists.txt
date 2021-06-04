cmake_minimum_required(VERSION 3.20)
project(z80Emu)

set(CMAKE_CXX_STANDARD 20)

include_directories(include)




add_executable(z80Emu
        src/main.cpp include/emuTypes.h src/z80.cpp include/z80.h include/registers.h include/memory.h include/opcodes.h)

add_subdirectory(tests)