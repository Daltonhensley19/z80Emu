#define FMT_HEADER_ONLY 1

#include "../include/fmt/core.h"
#include "../include/memory.h"
#include "../include/registers.h"
#include "../include/z80.h"
#include <cassert>


#include "GLFW/glfw3.h"



#include "../libs/imgui/imgui.h"

#include "../libs/imgui/backends/imgui_impl_opengl3.h"


#include "../libs/imgui/backends/imgui_impl_glfw.h"
int main()
{ 



    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 2);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);


    GLFWwindow* window = glfwCreateWindow(1280, 720, "Dear ImGui GLFW+OpenGL3 example", NULL, NULL);
    glfwMakeContextCurrent(window);
    glfwInit();
    
    ImGui::CreateContext();

    ImGuiIO& io = ImGui::GetIO();



  return 0;
}

