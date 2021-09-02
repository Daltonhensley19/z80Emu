if (APPLE)
    cmake_minimum_required(VERSION 3.18)
endif (APPLE)

if (UNIX AND NOT APPLE)
    cmake_minimum_required(VERSION 3.20)
endif (UNIX AND NOT APPLE)


project(z80Emu)

set(CMAKE_CXX_STANDARD 20)

if (APPLE)
    set(CMAKE_CXX_FLAGS "-O0 -g -Wall -Wextra -std=c++20")
endif (APPLE)

if (UNIX AND NOT APPLE)
    set(CMAKE_CXX_FLAGS "-O0 -g -Wall -Wextra -lglfw -lGL")
endif (UNIX AND NOT APPLE)

set(SOURCES src/main.cpp
        src/z80.cpp
        src/registers.cpp
        src/memory.cpp
        src/stack.cpp
        src/debugger.cpp
        src/utility/timer.cpp
        src/utility/load_rom.cpp)


add_executable(z80Emu ${SOURCES})


add_subdirectory(tests)
add_subdirectory(libs)

# MacOS platforms
if (APPLE)
    find_library(COCOA_LIBRARY Cocoa)
    find_library(OpenGL_LIBRARY OpenGL)
    find_library(IOKIT_LIBRARY IOKit)
    find_library(COREVIDEO_LIBRARY CoreVideo)

    SET(EXTRA_LIBS
            ${COCOA_LIBRARY}
            ${OpenGL_LIBRARY}
            ${IOKIT_LIBRARY}
            ${COREVIDEO_LIBRARY})

    target_link_libraries(imgui PUBLIC glfw glew ${EXTRA_LIBS})


    target_include_directories(z80Emu PUBLIC libs/imgui/)
    target_link_libraries(z80Emu PUBLIC imgui)
endif (APPLE)

# Linux platforms
if (UNIX AND NOT APPLE)

    target_include_directories(z80Emu PUBLIC libs/imgui/)
    target_link_libraries(z80Emu PUBLIC imgui GLEW)

endif (UNIX AND NOT APPLE)
