#define FMT_HEADER_ONLY 1

#include "../include/fmt/core.h"
#include "../include/memory.h"
#include "../include/registers.h"
#include "../include/z80.h"

#include "GL/glew.h"

#include "GL/gl.h"

#include "../libs/imgui/imgui.h"
#include "../libs/imgui/imgui_impl_glfw.h"
#include "../libs/imgui/imgui_impl_opengl3.h"

#include "GLFW/glfw3.h"


int main()
{




#define ENABLE_GUI 1
#if (ENABLE_GUI == 1)

  // Start GLFW API
  glfwInit();

  // Give GLFW info about current version
  glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
  glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6);
  glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

  // Create window handle
  GLFWwindow* window =
    glfwCreateWindow(480, 720, "Dear ImGui GLFW+OpenGL3 example", NULL, NULL);

  // Use window handle
  glfwMakeContextCurrent(window);
  glfwSwapInterval(1); // Enable v-sync

  // GLEW provides efficient run-time mechanisms
  // for determining which OpenGL extensions are supported
  // on the target platform.
  glewInit();


  // Initalize Dear ImGui
  IMGUI_CHECKVERSION();
  ImGui::CreateContext();
  ImGuiIO& io = ImGui::GetIO();
  ImGui::StyleColorsDark();

  ImGui_ImplGlfw_InitForOpenGL(window, true);
  ImGui_ImplOpenGL3_Init("#version 460");

  while (!glfwWindowShouldClose(window))
  {
    // Update ImGui 
    ImGui_ImplOpenGL3_NewFrame();
    ImGui_ImplGlfw_NewFrame();
    ImGui::NewFrame();

    // GUI action
    ImGui::Begin("Test");
    ImGui::Text("Hello, Derek!");
    ImGui::End();

    // Render GUI to opengl  
    ImGui::Render();

    int display_x, display_y;

    glfwGetFramebufferSize(window, &display_x, &display_y);
    glViewport(0, 0, display_x, display_y);
    glClear(GL_COLOR_BUFFER_BIT);

    ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());

    glfwSwapBuffers(window);

    glfwPollEvents();
  }

  // ImGui Cleanup
  ImGui_ImplOpenGL3_Shutdown();
  ImGui_ImplGlfw_Shutdown();
  ImGui::DestroyContext();

  // GLFW Cleanup
  glfwDestroyWindow(window);
  glfwTerminate();
#endif
  return 0;
}

