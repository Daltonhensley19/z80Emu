#pragma once

#include "glew.h"

#include "gl.h"

#include "../libs/imgui/imgui.h"
#include "../libs/imgui/imgui_impl_glfw.h"
#include "../libs/imgui/imgui_impl_opengl3.h"

#include "glfw3.h"

#include "z80.h"






bool debug_handle(GLFWwindow* glfw_win, int counter_handle);

GLFWwindow* debug_glfw_init();

void debug_imgui_init(GLFWwindow* window);

void debug_event_loop(GLFWwindow* window, int counter);

void debug_cleanup(GLFWwindow* window);

void update_register_values();