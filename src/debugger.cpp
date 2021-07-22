#include "../include/debugger.h"
#include "../include/registers.h"
#include "../include/z80.h"

#include <cstddef>
#include <iostream>

void update_register_values(Byte* reg_buf)
{

  const int buffer_size         = 16;
  Byte update_regs[buffer_size] = {ByteRegister::A_Reg_A,
                                   ByteRegister::B_Reg_A,
                                   ByteRegister::D_Reg_A,
                                   ByteRegister::H_Reg_A,

                                   ByteRegister::F_Reg_A,
                                   ByteRegister::C_Reg_A,
                                   ByteRegister::E_Reg_A,
                                   ByteRegister::L_Reg_A,

                                   // Alternate register set
                                   ByteRegister::A_Reg_B,
                                   ByteRegister::B_Reg_B,
                                   ByteRegister::D_Reg_B,
                                   ByteRegister::H_Reg_B,

                                   ByteRegister::F_Reg_B,
                                   ByteRegister::C_Reg_B,
                                   ByteRegister::E_Reg_B,
                                   ByteRegister::L_Reg_B};

  for (int i = 0; i < buffer_size; i++)
  {
    reg_buf[i] = update_regs[i];
  }
}

GLFWwindow* debug_glfw_init()
{
  // Start GLFW API
  glfwInit();

  // Give GLFW info about current version
  glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
  glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6);
  glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

  // Create glfw_window handle
  GLFWwindow* window =
    glfwCreateWindow(1920, 1080, "Dear ImGui GLFW+OpenGL3 example", NULL, NULL);

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

void debug_event_loop(GLFWwindow* window, int counter)
{

  int debug_counter = 0;

  Z80CPU cpu{};

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

  const std::size_t buff    = 4;
  Word auxiliary_regs[buff] = {cpu.pc, cpu.ix, cpu.iy, cpu.sp};

  const char* auxiliary_regs_names[buff] = {"pc", "ix", "iy", "sp"};

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

  bool execute_next_frame = false;

  while (!glfwWindowShouldClose(window))
  {

    update_register_values(reg);

    // Update ImGui
    ImGui_ImplOpenGL3_NewFrame();
    ImGui_ImplGlfw_NewFrame();
    ImGui::NewFrame();

    ///////// GUI action ///////////////////////

    ImGui::Begin("Debugger");

    if (ImGui::Button("Next frame"))
    {
      execute_next_frame = true;
    }

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

    if (ImGui::BeginTable("##table3", 1))
    {

      for (int row = 0; row < 4; row++)
      {
        ImGui::TableNextRow();
        ImGui::TableSetColumnIndex(0);
        ImGui::Text("%s \t\t\t\t\t    value: 0x%X",
                    auxiliary_regs_names[row],
                    (int)auxiliary_regs[row]);
      }

      ImGui::EndTable();
    }

    ImGui::Text("Current step: %d", counter);

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

    debug_counter++;

    // If flag is true, we handle another emu frame
    if (execute_next_frame)
      return;
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

bool debug_handle(GLFWwindow* glfw_win, int counter_handle)
{

  // Trigger event-loop, action happens here!
  debug_event_loop(glfw_win, counter_handle);

  // Clean up Dear ImGui and GLFW
  bool cleanup_GLFW = false;
  std::cout << "Want to turn off debugger? Type `1` for yes. \n";
  std::cin >> cleanup_GLFW;

  if (cleanup_GLFW)
  {
    debug_cleanup(glfw_win);
    exit(EXIT_SUCCESS);
  }

  else
  {
    return false;
  }
}
