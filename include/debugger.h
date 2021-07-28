#pragma once

#include "glew.h"

#include "gl.h"

#include "../libs/imgui/imgui.h"
#include "../libs/imgui/imgui_impl_glfw.h"
#include "../libs/imgui/imgui_impl_opengl3.h"

#include "glfw3.h"

#include "z80.h"

namespace debug
{
bool debug_handle(GLFWwindow* glfw_win, int counter_handle, Z80CPU* cpu);

GLFWwindow* debug_glfw_init();

void debug_imgui_init(GLFWwindow* window);

bool debug_event_loop(GLFWwindow* window, int counter, Z80CPU* cpu);

void debug_cleanup(GLFWwindow* window);

}

