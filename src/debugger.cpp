#include "../include/debugger.h"
#include "../include/registers.h"
#include <cstddef>

auto debug_glfw_init()
{
  // Start GLFW API
  glfwInit();

  // Give GLFW info about current version
  glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
  glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6);
  glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

  // Create glfw_window handle
  GLFWwindow* window =
    glfwCreateWindow(480, 720, "Dear ImGui GLFW+OpenGL3 example", NULL, NULL);

  // Use glfw_window handle
  glfwMakeContextCurrent(window);
  glfwSwapInterval(1); // Enable v-sync

  return window;
}

void debug_imgui_init(GLFWwindow* window)
{

  // Initalize Dear ImGui
  IMGUI_CHECKVERSION();
  ImGui::CreateContext();
  ImGuiIO& io = ImGui::GetIO();
  ImGui::StyleColorsDark();

  ImGui_ImplGlfw_InitForOpenGL(window, true);
  ImGui_ImplOpenGL3_Init("#version 460");
}

void debug_event_loop(GLFWwindow* window)
{

  const std::size_t buffer_size = 16;

  Byte reg[buffer_size] = {ByteRegister::A_Reg_A,
                           ByteRegister::B_Reg_A,
                           ByteRegister::D_Reg_A,
                           ByteRegister::H_Reg_A,

                           ByteRegister::F_Reg_A,
                           ByteRegister::C_Reg_A,
                           ByteRegister::E_Reg_A,
                           ByteRegister::L_Reg_A,

                           ByteRegister::A_Reg_B,
                           ByteRegister::B_Reg_B,
                           ByteRegister::D_Reg_B,
                           ByteRegister::H_Reg_B,

                           ByteRegister::F_Reg_B,
                           ByteRegister::C_Reg_B,
                           ByteRegister::E_Reg_B,
                           ByteRegister::L_Reg_B};

  const char* reg_names[buffer_size] = {"ByteRegister::A_Reg_A",
                                        "ByteRegister::B_Reg_A",
                                        "ByteRegister::D_Reg_A",
                                        "ByteRegister::H_Reg_A",

                                        "ByteRegister::F_Reg_A",
                                        "ByteRegister::C_Reg_A",
                                        "ByteRegister::E_Reg_A",
                                        "ByteRegister::L_Reg_A",

                                        "ByteRegister::A_Reg_B",
                                        "ByteRegister::B_Reg_B",
                                        "ByteRegister::D_Reg_B",
                                        "ByteRegister::H_Reg_B",

                                        "ByteRegister::F_Reg_B",
                                        "ByteRegister::C_Reg_B",
                                        "ByteRegister::E_Reg_B",
                                        "ByteRegister::L_Reg_B"};

  while (!glfwWindowShouldClose(window))
  {
    // Update ImGui
    ImGui_ImplOpenGL3_NewFrame();
    ImGui_ImplGlfw_NewFrame();
    ImGui::NewFrame();

    ///////// GUI action ///////////////////////

    ImGui::Begin("Debugger");

    if (ImGui::BeginTable("##table1", 1))
    {
      for (int row = 0; row < 8; row++)
      {
        ImGui::TableNextRow();
        ImGui::TableSetColumnIndex(0);
        ImGui::Text("%s \t value: 0x%X", reg_names[row], (int)reg[row]);
      }

      ImGui::EndTable();
    }

    if (ImGui::BeginTable("##table2", 1))
    {

      for (int row = 8; row < 16; row++)
      {
        ImGui::TableNextRow();
        ImGui::TableSetColumnIndex(0);
        ImGui::Text("%s \t value: 0x%X", reg_names[row], (int)reg[row]);
      }

      ImGui::EndTable();
    }

    ImGui::End();

    ////////////////////////////////////////////
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
}

void debug_cleanup(GLFWwindow* window)
{

  // ImGui Cleanup
  ImGui_ImplOpenGL3_Shutdown();
  ImGui_ImplGlfw_Shutdown();
  ImGui::DestroyContext();

  // GLFW Cleanup
  glfwDestroyWindow(window);
  glfwTerminate();
}

void debug_handle()
{

  // initalize GLFW and return a window handle
  auto glfw_win = debug_glfw_init();

  // GLEW provides efficient run-time mechanisms
  // for determining which OpenGL extensions are supported
  // on the target platform.
  glewInit();

  // Initalize Dear ImGui
  debug_imgui_init(glfw_win);

  // Trigger event-loop, action happens here!
  debug_event_loop(glfw_win);

  // Clean up Dear ImGui and GLFW
  debug_cleanup(glfw_win);
}
