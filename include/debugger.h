#pragma once

#if defined(__linux__)
#include "glew.h"
#include "gl.h"
#include "../libs/imgui/imgui.h"
#include "../libs/imgui/imgui_impl_glfw.h"
#include "../libs/imgui/imgui_impl_opengl3.h"
#include "glfw3.h"
#include "z80.h"

#elif defined(__APPLE__)
#include "/usr/local/Cellar/glew/2.2.0_1/include/GL/glew.h"
#include <OpenGL/gl.h>
#include "../libs/imgui/imgui.h"
#include "../libs/imgui/imgui_impl_glfw.h"
#include "../libs/imgui/imgui_impl_opengl3.h"
#include "/usr/local/Cellar/glfw/3.3.4/include/GLFW/glfw3.h"
#include "z80.h"
#endif


namespace debug {
    bool debug_handle(GLFWwindow *glfw_win, int counter_handle, Z80CPU *cpu);

    GLFWwindow *debug_glfw_init();

    void debug_imgui_init(GLFWwindow *window);

    bool debug_event_loop(GLFWwindow *window, int counter, Z80CPU *cpu);

    void debug_cleanup(GLFWwindow *window);

}

