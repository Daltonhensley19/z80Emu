#include "../include/debugger.h"
#include "../include/registers.h"
#include "../include/z80.h"

#include <cstddef>
#include <iostream>
#include <map>
#include <string>

GLFWwindow* debug::debug_glfw_init()
{
  // Start GLFW API
  glfwInit();

  // Give GLFW info about current version
#if defined(__linux__)
  glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
  glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6);
  glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
#elif defined(__APPLE__)
  glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
  glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
  glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE)
  glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
#endif

  // Create glfw_window handle
  GLFWwindow* window =
    glfwCreateWindow(1920, 1080, "Dear ImGui GLFW+OpenGL3 example", NULL, NULL);

  // Use glfw_window handle
  glfwMakeContextCurrent(window);
  glfwSwapInterval(1); // Enable v-sync

  return window;
}

void debug::debug_imgui_init(GLFWwindow* window)
{

  // Initalize Dear ImGui
  IMGUI_CHECKVERSION();
  ImGui::CreateContext();
  ImGuiIO& io = ImGui::GetIO();
  ImGui::StyleColorsDark();

  ImGui_ImplGlfw_InitForOpenGL(window, true);
  ImGui_ImplOpenGL3_Init("#version 460");
}

bool debug::debug_event_loop(GLFWwindow* window, int counter, Z80CPU* cpu)
{

  int debug_counter = 0;

  // Info from the Z80 that is sent to the debugger /////
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
  Word auxiliary_regs[buff] = {cpu->pc, cpu->ix, cpu->iy, Z80CPU::sp};

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

  std::map<std::string, Byte> instr = {
    {"Unknown", 0x00},
    {"A_A_LD", 0x7F},
    {"B_A_LD", 0x78},
    {"C_A_LD", 0x79},
    {"D_A_LD", 0x7A},
    {"E_A_LD", 0x7B},
    {"H_A_LD", 0x7C},
    {"L_A_LD", 0x7D},

    {"A_B_LD", 0x47},
    {"B_B_LD", 0x40},
    {"C_B_LD", 0x41},
    {"D_B_LD", 0x42},
    {"E_B_LD", 0x43},
    {"H_B_LD", 0x44},
    {"L_B_LD", 0x45},

    {"A_C_LD", 0x4F},
    {"B_C_LD", 0x48},
    {"C_C_LD", 0x49},
    {"D_C_LD", 0x4A},
    {"E_C_LD", 0x4B},
    {"H_C_LD", 0x4C},
    {"L_C_LD", 0x4D},

    {"A_D_LD", 0x57},
    {"B_D_LD", 0x50},
    {"C_D_LD", 0x51},
    {"D_D_LD", 0x52},
    {"E_D_LD", 0x53},
    {"H_D_LD", 0x54},
    {"L_D_LD", 0x55},

    {"A_E_LD", 0x5F},
    {"B_E_LD", 0x58},
    {"C_E_LD", 0x59},
    {"D_E_LD", 0x5A},
    {"E_E_LD", 0x5B},
    {"H_E_LD", 0x5C},
    {"L_E_LD", 0x5D},

    {"A_H_LD", 0x67},
    {"B_H_LD", 0x60},
    {"C_H_LD", 0x61},
    {"D_H_LD", 0x62},
    {"E_H_LD", 0x63},
    {"H_H_LD", 0x64},
    {"L_H_LD", 0x65},

    {"A_L_LD", 0x6F},
    {"B_L_LD", 0x68},
    {"C_L_LD", 0x69},
    {"D_L_LD", 0x6A},
    {"E_L_LD", 0x6B},
    {"H_L_LD", 0x6C},
    {"L_L_LD", 0x6D},

    // LD Immediate to register
    {"n_A_LD", 0x3E},
    {"n_B_LD", 0x06},
    {"n_C_LD", 0x0E},
    {"n_D_LD", 0x16},
    {"n_E_LD", 0x1E},
    {"n_H_LD", 0x26},
    {"n_L_LD", 0x2E},

    // Reg indirect to register
    {"HL_A_LD", 0x7E},
    {"HL_B_LD", 0x46},
    {"HL_C_LD", 0x4E},
    {"HL_D_LD", 0x56},
    {"HL_E_LD", 0x5E},
    {"HL_H_LD", 0x66},
    {"HL_L_LD", 0x6E},

    // Reg indirect to register
    {"BC_A_LD", 0x0A},
    {"DE_A_LD", 0x1A},

    // Indexed (NOTE: Indexed is source [IDX or IDY] to generic register [R], A
    // B C D E F L, which is the destination.
    {"IDX_R_LD", 0xDD},
    {"IDY_R_LD", 0xFD},

    // Extended to register
    {"nn_A_LD", 0x3A},

    // Implied to register
    {"I_A_LD", 0x57},
    {"R_A_LD", 0x5F},

    {"ED_PREFIX", 0xED},

    // Register to HL
    {"A_HL_LD", 0x77},
    {"B_HL_LD", 0x70},
    {"C_HL_LD", 0x71},
    {"D_HL_LD", 0x72},
    {"E_HL_LD", 0x73},
    {"H_HL_LD", 0x74},
    {"L_HL_LD", 0x75},

    // Register to register indirect (BC and DE)
    {"A_BC_LD", 0x02},
    {"A_DE_LD", 0x12},

    // Register to Ext. Addr.
    {"A_nn_LD", 0x32},

    // Register to implied
    {"A_I_LD", 0x47},
    {"A_R_LD", 0x4F},

    // Imm. to register indirect
    {"n_HL_LD", 0x36},

    /* This starts the 16-bit load opcode table. */
    // Imm. Extended to Register pair

    {"nn_BC_LD", 0x01},
    {"nn_DE_LD", 0x11},
    {"nn_HL_LD", 0x21},
    {"nn_SP_LD", 0x31},

    // Ext. to register
    {"ED_nn_BC_LD", 0x4B},
    {"ED_nn_DE_LD", 0x5B},
    {"nn_HL_LD_EXT", 0x2A},
    {"ED_nn_SP_LD", 0x7B},

    // Register to extended
    {"ED_BC_nn_LD", 0x43},
    {"ED_DE_nn_LD", 0x53},
    {"HL_nn_LD", 0x22},
    {"ED_SP_nn_LD", 0x73},

    // Register to register
    {"HL_SP_LD", 0xF9}};

  const std::size_t flag_buffer            = 9;
  const char* flag_regs_names[flag_buffer] = {"flag_C",
                                              "flag_N",
                                              "flag_P",
                                              "flag_V",
                                              "flag_X1",
                                              "flag_H",
                                              "flag_Z",
                                              "flag_S",
                                              "flag_X2"};

  Byte flag_regs[flag_buffer] = {cpu->flag.C,
                                 cpu->flag.N,
                                 cpu->flag.P,
                                 cpu->flag.V,
                                 cpu->flag.X1,
                                 cpu->flag.H,
                                 cpu->flag.Z,
                                 cpu->flag.S,
                                 cpu->flag.X2};

  //////////////////////////////////////////////////////////////

  bool execute_next_frame = false;

  while (!glfwWindowShouldClose(window))
  {

    // Update ImGui
    ImGui_ImplOpenGL3_NewFrame();
    ImGui_ImplGlfw_NewFrame();
    ImGui::NewFrame();

    ///////// GUI action ///////////////////////

    ImGui::Begin("Debugger");

    // Next frame button
    if (ImGui::Button("Next frame"))
    {
      execute_next_frame = true;
    }

    // Shutdown program button
    if (ImGui::Button("Shutdown Program"))
    {
      bool shutting_down = true;

      return shutting_down;
    }

    // Table of main registers
    if (ImGui::BeginTable("##table1", 1))
    {

      ImGui::PushStyleColor(ImGuiCol_Text, IM_COL32(0, 131, 129, 255));

      for (std::size_t row = 0; row < buffer_size / 2; row++)
      {
        ImGui::TableNextRow();
        ImGui::TableSetColumnIndex(0);
        ImGui::Text("%s \t value: 0x%X", reg_names[row], (int)reg[row]);
      }

      ImGui::PopStyleColor();
      ImGui::EndTable();
    }

    // Table of secondary registers
    if (ImGui::BeginTable("##table2", 1))
    {

      ImGui::PushStyleColor(ImGuiCol_Text, IM_COL32(0, 255, 155, 119));

      for (std::size_t row = 8; row < buffer_size; row++)
      {
        ImGui::TableNextRow();
        ImGui::TableSetColumnIndex(0);
        ImGui::Text("%s \t value: 0x%X", reg_names[row], (int)reg[row]);
      }

      ImGui::PopStyleColor();
      ImGui::EndTable();
    }

    // Table of special registers
    if (ImGui::BeginTable("##table3", 1))
    {

      ImGui::PushStyleColor(ImGuiCol_Text, IM_COL32(0, 255, 110, 233));

      for (std::size_t row = 0; row < buff; row++)
      {
        ImGui::TableNextRow();
        ImGui::TableSetColumnIndex(0);
        ImGui::Text("%s \t\t\t\t\t    value: 0x%X",
                    auxiliary_regs_names[row],
                    (int)auxiliary_regs[row]);
      }

      ImGui::PopStyleColor();
      ImGui::EndTable();
    }

    // Table of flag registers
    if (ImGui::BeginTable("##table4", 1))
    {

      ImGui::PushStyleColor(ImGuiCol_Text, IM_COL32(0, 255, 0, 255));

      for (std::size_t row = 0; row < flag_buffer; row++)
      {
        ImGui::TableNextRow();
        ImGui::TableSetColumnIndex(0);
        ImGui::Text("%s \t\t\t\t    value: 0x%X",
                    flag_regs_names[row],
                    (int)flag_regs[row]);
      }

      ImGui::PopStyleColor();
      ImGui::EndTable();
    }

    // Display the current instruction.
    for (auto& [key, value] : instr)
    {

      if (value == (Byte)cpu->debugOpcode)
      {
        ImGui::Text("Current Possible Instruction: %s", key.c_str());
      }
    }

    ImGui::Text("Current opcode: 0x%X", cpu->debugOpcode);
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
      return false;
  }
  return false;
}

void debug::debug_cleanup(GLFWwindow* window)
{

  // ImGui Cleanup
  ImGui_ImplOpenGL3_Shutdown();
  ImGui_ImplGlfw_Shutdown();
  ImGui::DestroyContext();

  // GLFW Cleanup
  glfwDestroyWindow(window);
  glfwTerminate();
}

bool debug::debug_handle(GLFWwindow* glfw_win, int counter_handle, Z80CPU* cpu)
{

  // Trigger event-loop, action happens here!
  bool shutdown_handle = debug::debug_event_loop(glfw_win, counter_handle, cpu);

  if (shutdown_handle)
  {
    // Clean up Dear ImGui and GLFW
    std::cout << "Shuting off. \n";

    debug::debug_cleanup(glfw_win);
    exit(EXIT_SUCCESS);
  }

  else
  {
    return false;
  }
}
