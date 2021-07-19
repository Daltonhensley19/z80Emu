cmake_minimum_required(VERSION 3.20)
project(z80Emu)

set(CMAKE_CXX_STANDARD 20)

set(CMAKE_CXX_FLAGS "-Wall -Wextra -pthread -lGLEW -lglfw -lGL")





add_executable(z80Emu
        src/main.cpp src/z80.cpp src/registers.cpp src/memory.cpp 
        src/stack.cpp)


find_package(Threads REQUIRED)





add_subdirectory(tests)
add_subdirectory(libs)





target_include_directories(z80Emu PUBLIC libs/imgui/)
target_link_libraries(z80Emu PUBLIC ${CMAKE_THREAD_LIBS_INIT} imgui)
