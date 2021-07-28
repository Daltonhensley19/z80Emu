cmake_minimum_required(VERSION 3.20)

set(IMGUILIBSOURCES imgui/imgui.cpp 
               imgui/imgui_demo.cpp
               imgui/imgui_draw.cpp
               imgui/imgui_tables.cpp
               imgui/imgui_widgets.cpp
               imgui/imgui_impl_glfw.cpp
               imgui/imgui_impl_opengl3.cpp)



add_library(imgui STATIC ${IMGUILIBSOURCES})


