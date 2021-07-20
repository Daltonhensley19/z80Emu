#pragma once

#include "glew.h"

#include "gl.h"

#include "../libs/imgui/imgui.h"
#include "../libs/imgui/imgui_impl_glfw.h"
#include "../libs/imgui/imgui_impl_opengl3.h"

#include "glfw3.h"






void debug_handle();

auto debug_glfw_init();

void debug_imgui_init(GLFWwindow* window);

void debug_event_loop(GLFWwindow* window);

void debug_cleanup(GLFWwindow* window);
