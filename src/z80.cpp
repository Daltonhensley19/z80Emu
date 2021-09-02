//
// Created by dalton on 5/29/21.
//

#include <memory.h>
#define FMT_HEADER_ONLY 1
#include "../include/fmt/core.h"

#include "../include/debugger.h"
#include "../include/opcodes.h"

#define ENABLE_DEBUG 1

// I must apologize for the very long switch table.
// This is the quickest (yet dirtiest) way to implement the Z80 opcodes.
// There might also be a way to breakup repeated operations into a function
// of some kind. 
void Z80CPU::execute_instruction()
{

#if ENABLE_DEBUG
  int counter = 0;
  bool pause  = true;

  // SANDBOX VALUES FOR TESTING //////
  //  cycles    = 10;
  // pc        = 0x78;
  // ram[pc]   = 0xED;
  // ram[0x79] = 0x57;
  // current_opcode = ram[pc];
  ////////////////////////////////////

  GLFWwindow* glfw_win = debug::debug_glfw_init();

  // GLEW provides efficient run-time mechanisms
  // for determining which OpenGL extensions are supported
  // on the target platform.
  glewInit();

  // Initalize Dear ImGui
  debug::debug_imgui_init(glfw_win);

  while (cycles > 0 && pause)
  {

    fmt::print("At emu start\n");
    if (counter > 0)
      counter++;

    bool glfw_is_shutdown = debug::debug_handle(glfw_win, counter, this);

    if (pause && !glfw_is_shutdown)
    {
      fmt::print("Processing emu cycle. \n");
    }
    if (glfw_is_shutdown)
      return;

#else
  while (cycles > 0)
  {
#endif

    // fetch current opcode
    current_opcode = ram[pc];
    debug_opcode   = ram[pc];
    switch (current_opcode)
    {
      case LD8::A_A_LD:
      {
        cycles += 4;
        ByteRegister::A_Reg_A = ByteRegister::A_Reg_A;
        cycles--;
        pc++;
      }
      break;
      case LD8::B_A_LD:
      {
        cycles += 4;
        ByteRegister::A_Reg_A = ByteRegister::B_Reg_A;
        cycles--;
        pc++;
      }
      break;
      case LD8::C_A_LD:
      {
        cycles += 4;
        ByteRegister::A_Reg_A = ByteRegister::C_Reg_A;
        cycles--;
        pc++;
      }
      break;
      case LD8::D_A_LD:
      {
        cycles += 4;
        ByteRegister::A_Reg_A = ByteRegister::D_Reg_A;
        cycles--;
        pc++;
      }
      break;
      case LD8::E_A_LD:
      {
        cycles += 4;
        ByteRegister::A_Reg_A = ByteRegister::E_Reg_A;
        cycles--;
        pc++;
      }
      break;
      case LD8::H_A_LD:
      {
        cycles += 4;
        ByteRegister::A_Reg_A = ByteRegister::H_Reg_A;
        cycles--;
        pc++;
      }
      break;
      case LD8::L_A_LD:
      {
        cycles += 4;
        ByteRegister::A_Reg_A = ByteRegister::L_Reg_A;
        cycles--;
        pc++;
      }
      break;
      case LD8::HL_A_LD:
      {
        cycles += 8;
        ByteRegister::A_Reg_A = ram[hl_as_word()];
        cycles--;
        pc++;
      }
      break;
      case LD8::B_B_LD:
      {
        cycles += 4;
        ByteRegister::B_Reg_A = ByteRegister::B_Reg_A;
        cycles--;
        pc++;
      }
      break;
      case LD8::C_B_LD:
      {
        cycles += 4;
        ByteRegister::B_Reg_A = ByteRegister::C_Reg_A;
        cycles--;
        pc++;
      }
      break;
      case LD8::D_B_LD:
      {
        cycles += 4;
        ByteRegister::B_Reg_A = ByteRegister::D_Reg_A;
        cycles--;
        pc++;
      }
      break;
      case LD8::E_B_LD:
      {
        cycles += 4;
        ByteRegister::B_Reg_A = ByteRegister::E_Reg_A;
        cycles--;
        pc++;
      }
      break;
      case LD8::H_B_LD:
      {
        cycles += 4;
        ByteRegister::B_Reg_A = ByteRegister::H_Reg_A;
        cycles--;
        pc++;
      }
      break;
      case LD8::L_B_LD:
      {
        cycles += 4;
        ByteRegister::B_Reg_A = ByteRegister::L_Reg_A;
        cycles--;
        pc++;
      }
      break;
      case LD8::HL_B_LD:
      {
        cycles += 8;
        ByteRegister::B_Reg_A = ram[hl_as_word()];
        cycles--;
        pc++;
      }
      break;
      case LD8::B_C_LD:
      {
        cycles += 4;
        ByteRegister::C_Reg_A = ByteRegister::B_Reg_A;
        cycles--;
        pc++;
      }
      break;
      case LD8::C_C_LD:
      {
        cycles += 4;
        ByteRegister::C_Reg_A = ByteRegister::C_Reg_A;
        cycles--;
        pc++;
      }
      break;
      case LD8::D_C_LD:
      {
        cycles += 4;
        ByteRegister::C_Reg_A = ByteRegister::D_Reg_A;
        cycles--;
        pc++;
      }
      break;
      case LD8::E_C_LD:
      {
        cycles += 4;
        ByteRegister::C_Reg_A = ByteRegister::E_Reg_A;
        cycles--;
        pc++;
      }
      break;
      case LD8::H_C_LD:
      {
        cycles += 4;
        ByteRegister::C_Reg_A = ByteRegister::H_Reg_A;
        cycles--;
        pc++;
      }
      break;
      case LD8::L_C_LD:
      {
        cycles += 4;
        ByteRegister::C_Reg_A = ByteRegister::L_Reg_A;
        cycles--;
        pc++;
      }
      break;
      case LD8::HL_C_LD:
      {
        cycles += 8;
        ByteRegister::B_Reg_A = ram[hl_as_word()];
        cycles--;
        pc++;
      }
      break;
      case LD8::B_D_LD:
      {
        cycles += 4;
        ByteRegister::D_Reg_A = ByteRegister::B_Reg_A;
        cycles--;
        pc++;
      }
      break;
      case LD8::C_D_LD:
      {
        cycles += 4;
        ByteRegister::D_Reg_A = ByteRegister::C_Reg_A;
        cycles--;
        pc++;
      }
      break;
      case LD8::D_D_LD:
      {
        cycles += 4;
        ByteRegister::D_Reg_A = ByteRegister::D_Reg_A;
        cycles--;
        pc++;
      }
      break;
      case LD8::E_D_LD:
      {
        cycles += 4;
        ByteRegister::D_Reg_A = ByteRegister::E_Reg_A;
        cycles--;
        pc++;
      }
      break;
      case LD8::H_D_LD:
      {
        cycles += 4;
        ByteRegister::D_Reg_A = ByteRegister::H_Reg_A;
        cycles--;
        pc++;
      }
      break;
      case LD8::L_D_LD:
      {
        cycles += 4;
        ByteRegister::D_Reg_A = ByteRegister::L_Reg_A;
        cycles--;
        pc++;
      }
      break;
      case LD8::HL_D_LD:
      {
        cycles += 8;
        ByteRegister::D_Reg_A = ram[hl_as_word()];
        cycles--;
        pc++;
      }
      break;
      case LD8::B_E_LD:
      {
        cycles += 4;
        ByteRegister::E_Reg_A = ByteRegister::B_Reg_A;
        cycles--;
        pc++;
      }
      break;
      case LD8::C_E_LD:
      {
        cycles += 4;
        ByteRegister::E_Reg_A = ByteRegister::C_Reg_A;
        cycles--;
        pc++;
      }
      break;
      case LD8::D_E_LD:
      {
        cycles += 4;
        ByteRegister::E_Reg_A = ByteRegister::D_Reg_A;
        cycles--;
        pc++;
      }
      break;
      case LD8::E_E_LD:
      {
        cycles += 4;
        ByteRegister::E_Reg_A = ByteRegister::E_Reg_A;
        cycles--;
        pc++;
      }
      break;
      case LD8::H_E_LD:
      {
        cycles += 4;
        ByteRegister::E_Reg_A = ByteRegister::H_Reg_A;
        cycles--;
        pc++;
      }
      break;
      case LD8::L_E_LD:
      {
        cycles += 4;
        ByteRegister::E_Reg_A = ByteRegister::L_Reg_A;
        cycles--;
        pc++;
      }
      break;
      case LD8::HL_E_LD:
      {
        cycles += 8;
        ByteRegister::E_Reg_A = ram[hl_as_word()];
        cycles--;
        pc++;
      }
      break;
      case LD8::B_H_LD:
      {
        cycles += 4;
        ByteRegister::H_Reg_A = ByteRegister::B_Reg_A;
        cycles--;
        pc++;
      }
      break;
      case LD8::C_H_LD:
      {
        cycles += 4;
        ByteRegister::H_Reg_A = ByteRegister::C_Reg_A;
        cycles--;
        pc++;
      }
      break;
      case LD8::D_H_LD:
      {
        cycles += 4;
        ByteRegister::H_Reg_A = ByteRegister::D_Reg_A;
        cycles--;
        pc++;
      }
      break;
      case LD8::E_H_LD:
      {
        cycles += 4;
        ByteRegister::H_Reg_A = ByteRegister::E_Reg_A;
        cycles--;
        pc++;
      }
      break;
      case LD8::H_H_LD:
      {
        cycles += 4;
        ByteRegister::H_Reg_A = ByteRegister::H_Reg_A;
        cycles--;
        pc++;
      }
      break;
      case LD8::L_H_LD:
      {
        cycles += 4;
        ByteRegister::H_Reg_A = ByteRegister::L_Reg_A;
        cycles--;
        pc++;
      }
      break;
      case LD8::HL_H_LD:
      {
        cycles += 8;
        ByteRegister::H_Reg_A = ram[hl_as_word()];
        cycles--;
        pc++;
      }
      break;
      case LD8::B_L_LD:
      {
        cycles += 4;
        ByteRegister::L_Reg_A = ByteRegister::B_Reg_A;
        cycles--;
        pc++;
      }
      break;
      case LD8::C_L_LD:
      {
        cycles += 4;
        ByteRegister::L_Reg_A = ByteRegister::C_Reg_A;
        cycles--;
        pc++;
      }
      break;
      case LD8::D_L_LD:
      {
        cycles += 4;
        ByteRegister::L_Reg_A = ByteRegister::D_Reg_A;
        cycles--;
        pc++;
      }
      break;
      case LD8::E_L_LD:
      {
        cycles += 4;
        ByteRegister::L_Reg_A = ByteRegister::E_Reg_A;
        cycles--;
        pc++;
      }
      break;
      case LD8::H_L_LD:
      {
        cycles += 4;
        ByteRegister::L_Reg_A = ByteRegister::H_Reg_A;
        cycles--;
        pc++;
      }
      break;
      case LD8::L_L_LD:
      {
        cycles += 4;
        ByteRegister::L_Reg_A = ByteRegister::L_Reg_A;
        cycles--;
        pc++;
      }
      break;
      case LD8::HL_L_LD:
      {
        cycles += 8;
        ByteRegister::L_Reg_A = ram[hl_as_word()];
        cycles--;
        pc++;
      }
      break;
      case LD8::B_HL_LD:
      {
        cycles += 8;
        ram[hl_as_word()] = ByteRegister::B_Reg_A;
        cycles--;
        pc++;
      }
      break;
      case LD8::C_HL_LD:
      {
        cycles += 8;
        ram[hl_as_word()] = ByteRegister::C_Reg_A;
        cycles--;
        pc++;
      }
      break;
      case LD8::D_HL_LD:
      {
        cycles += 8;
        ram[hl_as_word()] = ByteRegister::D_Reg_A;
        cycles--;
        pc++;
      }
      break;
      case LD8::E_HL_LD:
      {
        cycles += 8;
        ram[hl_as_word()] = ByteRegister::E_Reg_A;
        cycles--;
        pc++;
      }
      break;
      case LD8::H_HL_LD:
      {
        cycles += 8;
        ram[hl_as_word()] = ByteRegister::H_Reg_A;
        cycles--;
        pc++;
      }
      break;
      case LD8::L_HL_LD:
      {
        cycles += 8;
        ram[hl_as_word()] = ByteRegister::L_Reg_A;
        cycles--;
        pc++;
      }
      break;
      case LD8::n_HL_LD:
      {
        cycles += 8;
        ram[hl_as_word()] = ram[pc + 1]; // LD imm to indirect address
        cycles--;
        pc++;
      }
      break;
      case LD8::A_B_LD:
      {
        cycles += 4;
        ByteRegister::B_Reg_A = ByteRegister::A_Reg_A;
        cycles--;
        pc++;
      }
      break;
      case LD8::A_C_LD:
      {
        cycles += 4;
        ByteRegister::C_Reg_A = ByteRegister::A_Reg_A;
        cycles--;
        pc++;
      }
      break;
      case LD8::A_D_LD:
      {
        cycles += 4;
        ByteRegister::D_Reg_A = ByteRegister::A_Reg_A;
        cycles--;
        pc++;
      }
      break;
      case LD8::A_E_LD:
      {
        cycles += 4;
        ByteRegister::E_Reg_A = ByteRegister::A_Reg_A;
        cycles--;
        pc++;
      }
      break;
      case LD8::A_H_LD:
      {
        cycles += 4;
        ByteRegister::H_Reg_A = ByteRegister::A_Reg_A;
        cycles--;
        pc++;
      }
      break;
      case LD8::A_L_LD:
      {
        cycles += 4;
        ByteRegister::L_Reg_A = ByteRegister::A_Reg_A;
        cycles--;
        pc++;
      }
      break;
      case LD8::A_BC_LD:
      {
        cycles += 8;
        ram[bc_as_word()] = ByteRegister::A_Reg_A;
        cycles--;
        pc++;
      }
      break;
      case LD8::A_DE_LD:
      {
        cycles += 8;
        ram[de_as_word()] = ByteRegister::A_Reg_A;
        cycles--;
        pc++;
      }
      break;
      case LD8::A_HL_LD:
      {
        cycles += 8;
        ram[hl_as_word()] = ByteRegister::A_Reg_A;
        cycles--;
        pc++;
      }
      break;
      case LD8::A_nn_LD:
      {
        cycles += 8;
        write_byte(ByteRegister::A_Reg_A,
                   bytes_to_word(ram[pc + 2], ram[pc + 1]));
        cycles--;
        pc++;
      }
      break;
      case LD8::n_A_LD:
      {
        cycles += 8;
        ByteRegister::A_Reg_A = ram[pc + 1]; // LD imm to register
        cycles--;
        pc++;
      }
      break;
      case LD8::n_B_LD:
      {
        cycles += 8;
        ByteRegister::B_Reg_A = ram[pc + 1]; // LD imm to register
        cycles--;
        pc++;
      }
      break;
      case LD8::n_C_LD:
      {
        cycles += 8;
        ByteRegister::C_Reg_A = ram[pc + 1]; // LD imm to register
        cycles--;
        pc++;
      }
      break;
      case LD8::n_D_LD:
      {
        cycles += 8;
        ByteRegister::D_Reg_A = ram[pc + 1]; // LD imm to register
        cycles--;
        pc++;
      }
      break;
      case LD8::n_E_LD:
      {
        cycles += 8;
        ByteRegister::E_Reg_A = ram[pc + 1]; // LD imm to register
        cycles--;
        pc++;
      }
      break;
      case LD8::n_H_LD:
      {
        cycles += 8;
        ByteRegister::H_Reg_A = ram[pc + 1]; // LD imm to register
        cycles--;
        pc++;
      }
      break;
      case LD8::n_L_LD:
      {
        cycles += 8;
        ByteRegister::L_Reg_A = ram[pc + 1]; // LD imm to register
        cycles--;
        pc++;
      }
      break;
      case LD8::BC_A_LD:
      {
        cycles += 8;
        ByteRegister::A_Reg_A =
          ram[bc_as_word()]; // LD indirect address to reg.
        cycles--;
        pc++;
      }
      break;
      case LD8::DE_A_LD:
      {
        cycles += 8;
        ByteRegister::A_Reg_A =
          ram[de_as_word()]; // LD indirect address to reg.
        cycles--;
        pc++;
      }
      break;
      case LD8::nn_A_LD:
      {
        cycles += 13;
        ByteRegister::A_Reg_A =
          read_byte(bytes_to_word(ram[pc + 2], ram[pc + 1]));
        cycles--;
        pc += 3;
      }
      break;
        // DD Prefixed Opcodes
      case LD8::IDX_R_LD:
      {
#if ENABLE_DEBUG
        fmt::print("At prefix DD.\n");
        counter++;
        glfw_is_shutdown = debug::debug_handle(glfw_win, counter, this);

        if (glfw_is_shutdown)
          return;
#endif
        Byte d = ram[pc + 2];
        switch (ram[pc + 1])
        {
          case LD8::HL_A_LD:
          {
            cycles += 19;
            ByteRegister::A_Reg_A = ram[ix + d];
            cycles--;
            pc += 4;
          }
          break;
          case LD8::HL_B_LD:
          {
            cycles += 19;
            ByteRegister::B_Reg_A = ram[ix + d];
            cycles--;
            pc += 4;
          }
          break;
          case LD8::HL_C_LD:
          {
            cycles += 19;
            ByteRegister::C_Reg_A = ram[ix + d];
            cycles--;
            pc += 4;
          }
          break;
          case LD8::HL_D_LD:
          {
            cycles += 19;
            ByteRegister::D_Reg_A = ram[ix + d];
            cycles--;
            pc += 4;
          }
          break;
          case LD8::HL_E_LD:
          {
            cycles += 19;
            ByteRegister::E_Reg_A = ram[ix + d];
            cycles--;
            pc += 4;
          }
          break;
          case LD8::HL_H_LD:
          {
            cycles += 19;
            ByteRegister::H_Reg_A = ram[ix + d];
            cycles--;
            pc += 4;
          }
          break;
          case LD8::HL_L_LD:
          {
            cycles += 19;
            ByteRegister::L_Reg_A = ram[ix + d];
            cycles--;
            pc += 4;
          }
          break;
          case LD8::A_HL_LD:
          {
            cycles += 19;
            ram[ix + d] = ByteRegister::A_Reg_A;
            cycles--;
            pc += 3;
          }
          break;
          case LD8::B_HL_LD:
          {
            cycles += 19;
            ram[ix + d] = ByteRegister::B_Reg_A;
            cycles--;
            pc += 3;
          }
          break;
          case LD8::C_HL_LD:
          {
            cycles += 19;
            ram[ix + d] = ByteRegister::C_Reg_A;
            cycles--;
            pc += 3;
          }
          break;
          case LD8::D_HL_LD:
          {
            cycles += 19;
            ram[ix + d] = ByteRegister::D_Reg_A;
            cycles--;
            pc += 3;
          }
          break;
          case LD8::E_HL_LD:
          {
            cycles += 19;
            ram[ix + d] = ByteRegister::E_Reg_A;
            cycles--;
            pc += 3;
          }
          break;
          case LD8::H_HL_LD:
          {
            cycles += 19;
            ram[ix + d] = ByteRegister::H_Reg_A;
            cycles--;
            pc += 3;
          }
          break;
          case LD8::L_HL_LD:
          {
            cycles += 19;
            ram[ix + d] = ByteRegister::L_Reg_A;
            cycles--;
            pc += 3;
          }
          break;
          case LD8::n_HL_LD:
          {
            cycles += 19;
            ram[ix + d] = ram[pc + 3];
            cycles--;
            pc += 4;
          }
          break;
          case LD16::nn_HL_LD:
          {
            cycles += 14;

            ix = read_word(pc + 2);
            cycles--;
            pc += 4;
          }
          break;
          case LD16::nn_HL_LD_EXT:
          {
            cycles += 20;

            Word position = read_word(pc + 2);
            ix = ram[position + 1] << BYTE_SHIFT_ALIGNMENT | ram[position];

            cycles--;
            pc += 4;
          }
          break;
          case Pop::POP_HL:
          {
            cycles += 14;

            ix = stack.pop_word();

            cycles--;
            pc += 2;
          }
          break;
          case LD16::HL_SP_LD:
          {
            cycles += 10;

            sp = ix;

            cycles--;
            pc += 2;
          }
          break;
          case LD16::HL_nn_LD:
          {
            cycles += 20;

            std::uint32_t location = read_word(pc + 2);

            Byte highByte = (ix >> BYTE_SHIFT_ALIGNMENT) & MAX_BYTE_SIZE;
            Byte lowByte  = ix & MAX_BYTE_SIZE;

            ram[location + 1] = highByte;
            ram[location]     = lowByte;

            cycles--;
            pc += 4;
          }
          break;
          case Push::PUSH_HL:
          {
            cycles += 15;

            stack.push_word(ix);

            cycles--;
            pc += 2;
          }
          break;
          case Ex::HL_SP:
          {
            cycles += 23;

            // SP and IX Exchange
            // Store temp values
            auto tempRegI = (ix >> BYTE_SHIFT_ALIGNMENT) & MAX_BYTE_SIZE;
            auto tempRegX = ix & MAX_BYTE_SIZE;

            // Set IX to SP indirect
            auto pIndir = ram[sp];
            auto sIndir = ram[sp + 1];

            ix = (sIndir << BYTE_SHIFT_ALIGNMENT) | (pIndir & MAX_BYTE_SIZE);

            // Set SP indirect to ix using temp
            ram[sp + 1] = tempRegI;
            ram[sp]     = tempRegX;

            cycles--;
            pc++;
          }
          break;
        }
      }
      break;
        // FD Prefixed Opcodes
      case LD8::IDY_R_LD:
      {
#if ENABLE_DEBUG
        fmt::print("At prefix FD.\n");
        counter++;
        glfw_is_shutdown = debug::debug_handle(glfw_win, counter, this);

        if (glfw_is_shutdown)
          return;
#endif
        Byte d = ram[pc + 2];
        switch (ram[pc + 1])
        {
          case LD8::HL_A_LD:
          {
            cycles += 19;
            ByteRegister::A_Reg_A = ram[iy + d];
            cycles--;
            pc += 3;
          }
          break;
          case LD8::HL_B_LD:
          {
            cycles += 19;
            ByteRegister::B_Reg_A = ram[iy + d];
            cycles--;
            pc += 3;
          }
          break;
          case LD8::HL_C_LD:
          {
            cycles += 19;
            ByteRegister::C_Reg_A = ram[iy + d];
            cycles--;
            pc += 3;
          }
          break;
          case LD8::HL_D_LD:
          {
            cycles += 19;
            ByteRegister::D_Reg_A = ram[iy + d];
            cycles--;
            pc += 3;
          }
          break;
          case LD8::HL_E_LD:
          {
            cycles += 19;
            ByteRegister::E_Reg_A = ram[iy + d];
            cycles--;
            pc += 3;
          }
          break;
          case LD8::HL_H_LD:
          {
            cycles += 19;
            ByteRegister::H_Reg_A = ram[iy + d];
            cycles--;
            pc += 3;
          }
          break;
          case LD8::HL_L_LD:
          {
            cycles += 19;
            ByteRegister::L_Reg_A = ram[iy + d];
            cycles--;
            pc += 3;
          }
          break;
          case LD8::A_HL_LD:
          {
            cycles += 19;
            ram[iy + d] = ByteRegister::A_Reg_A;
            cycles--;
            pc += 3;
          }
          break;
          case LD8::B_HL_LD:
          {
            cycles += 19;
            ram[iy + d] = ByteRegister::B_Reg_A;
            cycles--;
            pc += 3;
          }
          break;
          case LD8::C_HL_LD:
          {
            cycles += 19;
            ram[iy + d] = ByteRegister::C_Reg_A;
            cycles--;
            pc += 3;
          }
          break;
          case LD8::D_HL_LD:
          {
            cycles += 19;
            ram[iy + d] = ByteRegister::D_Reg_A;
            cycles--;
            pc += 3;
          }
          break;
          case LD8::E_HL_LD:
          {
            cycles += 19;
            ram[iy + d] = ByteRegister::E_Reg_A;
            cycles--;
            pc += 3;
          }
          break;
          case LD8::H_HL_LD:
          {
            cycles += 19;
            ram[iy + d] = ByteRegister::H_Reg_A;
            cycles--;
            pc += 3;
          }
          break;
          case LD8::L_HL_LD:
          {
            cycles += 19;
            ram[iy + d] = ByteRegister::L_Reg_A;
            cycles--;
            pc += 3;
          }
          break;
          case LD8::n_HL_LD:
          {
            cycles += 19;

            ram[iy + d] = ram[pc + 3];

            cycles--;
            pc += 4;
          }
          break;
          case LD16::HL_nn_LD:
          {
            cycles += 20;

            std::uint32_t location = read_word(pc + 2);

            Byte highByte = (iy >> BYTE_SHIFT_ALIGNMENT) & MAX_BYTE_SIZE;
            Byte lowByte  = iy & MAX_BYTE_SIZE;

            ram[location + 1] = highByte;
            ram[location]     = lowByte;

            cycles--;
            pc += 4;
          }
          break;
          case LD16::nn_HL_LD_EXT:
          {
            cycles += 20;

            std::uint32_t location = read_word(pc + 2);

            Byte IByte = (iy >> BYTE_SHIFT_ALIGNMENT) & MAX_BYTE_SIZE;
            Byte YByte = iy & MAX_BYTE_SIZE;

            IByte = ram[location + 1];
            YByte = ram[location];

            iy = bytes_to_word(IByte, YByte);

            cycles--;
            pc += 4;
          }
          break;
          case LD16::nn_HL_LD:
          {
            cycles += 14;

            iy = read_word(pc + 2);

            cycles--;
            pc += 4;
          }
          break;
          case Pop::POP_HL:
          {
            cycles += 14;

            iy = stack.pop_word();

            cycles--;
            pc += 2;
          }
          break;
          case LD16::HL_SP_LD:
          {
            cycles += 10;

            sp = iy;

            cycles--;
            pc += 2;
          }
          break;
          case Push::PUSH_HL:
          {
            cycles += 15;

            stack.push_word(iy);

            cycles--;
            pc += 2;
          }
          break;
          case Ex::HL_SP:
          {
            cycles += 23;

            // SP and IY Exchange
            // Store temp values
            auto tempRegI = (iy >> BYTE_SHIFT_ALIGNMENT) & MAX_BYTE_SIZE;
            auto tempRegY = iy & MAX_BYTE_SIZE;

            // Set IY to SP indirect
            auto pIndir = ram[sp];
            auto sIndir = ram[sp + 1];

            iy = (sIndir << BYTE_SHIFT_ALIGNMENT) | (pIndir & MAX_BYTE_SIZE);

            // Set SP indirect to iy using temp
            ram[sp + 1] = tempRegI;
            ram[sp]     = tempRegY;

            cycles--;
            pc += 2;
          }
          break;
        }
      }
      break;
        // ED Prefixed Opcodes
      case LD8::ED_PREFIX:
      {
#if ENABLE_DEBUG
        fmt::print("At prefix ED.\n");
        counter++;
        glfw_is_shutdown = debug::debug_handle(glfw_win, counter, this);

        if (glfw_is_shutdown)
          return;
#endif
        switch (ram[pc + 1])
        {
          case LD8::I_A_LD:
          {

            cycles += 9;
            ByteRegister::A_Reg_A = I;

            // Two's complement, S flag
            bool condition_S = (I & 0x80) != 0;
            set_flag_reg(condition_S, flag.S);

            // Z flag
            bool condition_Z = (I == 0);
            set_flag_reg(condition_Z, flag.Z);

            flag.H = 0;    // H
            flag.P = IFF2; // P
            flag.N = 0;    // N
            // C flag not affected

            cycles--;
            pc += 2;
          }
          break;
          case LD8::R_A_LD:
          {
            cycles += 9;
            ByteRegister::A_Reg_A = R;

            // Two's complement, S flag
            bool condition_S = (R & 0x80) != 0;
            set_flag_reg(condition_S, flag.S);

            // Z flag
            bool condition_Z = (R == 0);
            set_flag_reg(condition_Z, flag.Z);

            flag.H = 0;    // H
            flag.P = IFF2; // P
            flag.N = 0;    // N
            // C is not affected
            cycles--;
            pc += 2;
          }
          break;
          case LD8::A_I_LD:
          {
            cycles += 9;
            I = ByteRegister::A_Reg_A;

            cycles--;
            pc += 2;
          }
          break;
          case LD8::A_R_LD:
          {
            cycles += 9;
            R = ByteRegister::A_Reg_A;

            cycles--;
            pc += 2;
          }
          break;
          case LD16::ED_BC_nn_LD:
          {
            cycles += 20;

            std::uint32_t location = read_word(pc + 2);

            ram[location + 1] = ByteRegister::B_Reg_A;
            ram[location]     = ByteRegister::C_Reg_A;

            cycles--;
            pc += 4;
          }
          break;
          case LD16::ED_DE_nn_LD:
          {
            cycles += 20;

            std::uint32_t location = read_word(pc + 2);

            ram[location + 1] = ByteRegister::D_Reg_A;
            ram[location]     = ByteRegister::E_Reg_A;

            cycles--;
            pc += 4;
          }
          break;
          case LD16::ED_SP_nn_LD:
          {
            cycles += 20;

            std::uint32_t location = read_word(pc + 2);

            Byte S = (sp >> BYTE_SHIFT_ALIGNMENT) & MAX_BYTE_SIZE;
            Byte P = sp & MAX_BYTE_SIZE;

            ram[location + 1] = S;
            ram[location]     = P;

            cycles--;
            pc += 4;
          }
          break;
          case LD16::ED_nn_BC_LD:
          {
            cycles += 20;

            std::uint32_t location = read_word(pc + 2);

            ByteRegister::B_Reg_A = ram[location + 1];
            ByteRegister::C_Reg_A = ram[location];

            cycles--;
            pc += 4;
          }
          break;
          case LD16::ED_nn_DE_LD:
          {
            cycles += 20;

            std::uint32_t location = read_word(pc + 2);

            ByteRegister::D_Reg_A = ram[location + 1];
            ByteRegister::E_Reg_A = ram[location];

            cycles--;
            pc += 4;
          }
          break;
          case LD16::ED_nn_SP_LD:
          {
            cycles += 20;

            std::uint32_t location = read_word(pc + 2);

            Byte S = (sp >> BYTE_SHIFT_ALIGNMENT) & MAX_BYTE_SIZE;
            Byte P = sp & MAX_BYTE_SIZE;

            S = ram[location + 1];
            P = ram[location];

            sp = bytes_to_word(S, P);

            cycles--;
            pc += 4;
          }
          break;
          case Ex::CPIR:
          {
            cycles += 21;

            // Set Z flag
            bool condition = ram[hl_as_word()] == ByteRegister::A_Reg_A;
            set_flag_reg(condition, flag.Z);

            // Decrement BC
            Word currentvalue_bc = bc_as_word();
            currentvalue_bc--;
            ByteRegister::B_Reg_A =
              (currentvalue_bc >> BYTE_SHIFT_ALIGNMENT) & MAX_BYTE_SIZE;
            ByteRegister::C_Reg_A = currentvalue_bc & MAX_BYTE_SIZE;

            // Increment HL
            Word currentvalue_hl = hl_as_word();
            currentvalue_hl--;
            ByteRegister::B_Reg_A =
              (currentvalue_hl >> BYTE_SHIFT_ALIGNMENT) & MAX_BYTE_SIZE;
            ByteRegister::C_Reg_A = currentvalue_hl & MAX_BYTE_SIZE;

            // Set P, H, N, S flags
            set_flag_reg((bc_as_word() - 1 != 0), flag.P);
            set_flag_reg(0, flag.H);
            set_flag_reg(0, flag.N);
            set_flag_reg(0, flag.S);

            if (condition && (bc_as_word() - 1 != 0))
              pc -= 2;
          }
        }
      }
      break;
      case LD16::nn_BC_LD:
      {
        cycles += 10;
        ByteRegister::B_Reg_A = ram[pc + 2];
        ByteRegister::C_Reg_A = ram[pc + 1];

        cycles--;
        pc += 3;
      }
      break;
      case LD16::nn_DE_LD:
      {
        cycles += 10;
        ByteRegister::D_Reg_A = ram[pc + 2];
        ByteRegister::E_Reg_A = ram[pc + 1];

        cycles--;
        pc += 3;
      }
      break;
      case LD16::nn_HL_LD:
      {
        cycles += 10;
        ByteRegister::H_Reg_A = ram[pc + 2];
        ByteRegister::L_Reg_A = ram[pc + 1];

        cycles--;
        pc += 3;
      }
      break;
      case LD16::nn_SP_LD:
      {
        cycles += 10;
        sp = read_word(pc + 1);

        cycles--;
        pc += 3;
      }
      break;
      case Pop::POP_BC:
      {
        cycles += 10;

        ByteRegister::C_Reg_A = ram[Z80CPU::sp++];
        ByteRegister::B_Reg_A = ram[Z80CPU::sp++];

        cycles--;
        pc++;
      }
      break;
      case Pop::POP_DE:
      {
        cycles += 10;

        ByteRegister::E_Reg_A = ram[Z80CPU::sp++];
        ByteRegister::D_Reg_A = ram[Z80CPU::sp++];

        cycles--;
        pc++;
      }
      break;
      case Pop::POP_HL:
      {
        cycles += 10;

        ByteRegister::L_Reg_A = ram[Z80CPU::sp++];
        ByteRegister::H_Reg_A = ram[Z80CPU::sp++];

        cycles--;
        pc++;
      }
      break;
      case Pop::POP_AF:
      {
        cycles += 10;

        ByteRegister::F_Reg_A = ram[Z80CPU::sp++];
        ByteRegister::A_Reg_A = ram[Z80CPU::sp++];

        cycles--;
        pc++;
      }
      break;
      case LD16::HL_SP_LD:
      {
        cycles += 6;

        sp = hl_as_word();

        cycles--;
        pc++;
      }
      break;
      case Push::PUSH_BC:
      {
        cycles += 11;

        stack.push_word(bc_as_word());

        cycles--;
        pc++;
      }
      break;
      case Push::PUSH_DE:
      {
        cycles += 11;

        stack.push_word(de_as_word());

        cycles--;
        pc++;
      }
      break;
      case Push::PUSH_HL:
      {
        cycles += 11;

        stack.push_word(hl_as_word());

        cycles--;
        pc++;
      }
      break;
      case Push::PUSH_AF:
      {
        cycles += 11;

        stack.push_word(af_as_word());

        cycles--;
        pc++;
      }
      break;
      case LD16::nn_HL_LD_EXT:
      {
        cycles += 16;
        std::uint32_t location = read_word(pc + 1);

        ByteRegister::H_Reg_A = ram[location + 1];
        ByteRegister::L_Reg_A = ram[location];

        cycles--;
        pc += 3;
      }
      break;
      case LD16::HL_nn_LD:
      {
        cycles += 16;

        std::uint32_t location = read_word(pc + 1);

        ram[location + 1] = ByteRegister::H_Reg_A;
        ram[location]     = ByteRegister::L_Reg_A;

        cycles--;
        pc += 3;
      }
      break;
      case Ex::AFPRIME_AF:
      {
        cycles += 4;

        // Store temp values
        auto tempReg1 = ByteRegister::A_Reg_A;
        auto tempReg2 = ByteRegister::F_Reg_A;

        // Set pair to prime pair
        ByteRegister::A_Reg_A = ByteRegister::A_Reg_B;
        ByteRegister::F_Reg_A = ByteRegister::F_Reg_B;

        // Set prime pair to pair using temp
        ByteRegister::A_Reg_B = tempReg1;
        ByteRegister::F_Reg_B = tempReg2;

        cycles--;
        pc++;
      }
      break;
      case Ex::PAIRPRIME_PAIR:
      {
        cycles += 4;

        // BC and BC Prime Exchange
        // Store temp values
        auto tempRegB = ByteRegister::B_Reg_A;
        auto tempRegC = ByteRegister::C_Reg_A;

        // Set pair to prime pair
        ByteRegister::B_Reg_A = ByteRegister::B_Reg_B;
        ByteRegister::C_Reg_A = ByteRegister::C_Reg_B;

        // Set prime pair to pair using temp
        ByteRegister::B_Reg_B = tempRegB;
        ByteRegister::C_Reg_B = tempRegC;

        ////////////////////////////////////////////////

        // DE and DE Prime Exchange
        // Store temp values
        auto tempRegD = ByteRegister::D_Reg_A;
        auto tempRegE = ByteRegister::E_Reg_A;

        // Set pair to prime pair
        ByteRegister::D_Reg_A = ByteRegister::D_Reg_B;
        ByteRegister::E_Reg_A = ByteRegister::E_Reg_B;

        // Set prime pair to pair using temp
        ByteRegister::D_Reg_B = tempRegD;
        ByteRegister::E_Reg_B = tempRegE;

        //////////////////////////////////////////////

        // HL and HL Prime Exchange
        // Store temp values
        auto tempRegH = ByteRegister::H_Reg_A;
        auto tempRegL = ByteRegister::L_Reg_A;

        // Set pair to prime pair
        ByteRegister::H_Reg_A = ByteRegister::H_Reg_B;
        ByteRegister::L_Reg_A = ByteRegister::L_Reg_B;

        // Set prime pair to pair using temp
        ByteRegister::H_Reg_B = tempRegH;
        ByteRegister::L_Reg_B = tempRegL;

        cycles--;
        pc++;
      }
      break;
      case Ex::HL_SP:
      {
        cycles += 19;

        // Store temp values
        auto tempRegH = ByteRegister::H_Reg_A;
        auto tempRegL = ByteRegister::L_Reg_A;

        // Set pair (HL) to stack pointer indirect

        ByteRegister::H_Reg_A = ram[sp + 1];
        ByteRegister::L_Reg_A = ram[sp];

        // Set sp to pair using temp
        ram[sp + 1] = tempRegH;
        ram[sp]     = tempRegL;

        cycles--;
        pc++;
      }
      break;
      case Ex::HL_DE:
      {
        cycles += 4;

        // Store temp values
        auto tempRegD = ByteRegister::D_Reg_A;
        auto tempRegE = ByteRegister::E_Reg_A;

        // Set pair to prime pair
        ByteRegister::D_Reg_A = ByteRegister::H_Reg_A;
        ByteRegister::E_Reg_A = ByteRegister::L_Reg_A;

        // Set prime pair to pair using temp
        ByteRegister::H_Reg_B = tempRegD;
        ByteRegister::L_Reg_B = tempRegE;

        cycles--;
        pc++;
      }
      break;
      case Call::UNCON_CALL:
      {
        cycles += 3;

        ram[sp - 1] = (pc >> BYTE_SHIFT_ALIGNMENT) & MAX_BYTE_SIZE;
        ram[sp - 2] = (pc & MAX_BYTE_SIZE);

        pc = ((ram[pc + 2] << BYTE_SHIFT_ALIGNMENT) & MAX_BYTE_SIZE) |
             (ram[pc + 1] & MAX_BYTE_SIZE);

        cycles--;
      }
      break;
      case Call::NONZERO_CALL:
      {

        /* cc   * Condition          * Flag
         *
         * 000  * Non-Zero (NZ)      * Z
         * 001  * Zero (Z)           * Z
         * 010  * Non Carry (NC)     * C
         * 011  * Carry (C)          * Z
         * 100  * Parity Odd (PO)    * P/V
         * 101  * Parity Even (PE)   * P/V
         * 110  * Sign Positive (P)  * S
         * 111  * Sign Negative (M)  * S */

        cycles += 3;

        if (!flag.Z)
        {

          ram[sp - 1] = (pc >> BYTE_SHIFT_ALIGNMENT) & MAX_BYTE_SIZE;
          ram[sp - 2] = (pc & MAX_BYTE_SIZE);

          pc = ((ram[pc + 2] << BYTE_SHIFT_ALIGNMENT) & MAX_BYTE_SIZE) |
               (ram[pc + 1] & MAX_BYTE_SIZE);
        }
        else
        {
          pc += 3;
        }
      }
      break;

      case Call::ZERO_CALL:
      {

        /* cc   * Condition          * Flag
         *
         * 000  * Non-Zero (NZ)      * Z
         * 001  * Zero (Z)           * Z
         * 010  * Non Carry (NC)     * C
         * 011  * Carry (C)          * Z
         * 100  * Parity Odd (PO)    * P/V
         * 101  * Parity Even (PE)   * P/V
         * 110  * Sign Positive (P)  * S
         * 111  * Sign Negative (M)  * S */

        cycles += 3;

        if (flag.Z)
        {

          ram[sp - 1] = (pc >> BYTE_SHIFT_ALIGNMENT) & MAX_BYTE_SIZE;
          ram[sp - 2] = (pc & MAX_BYTE_SIZE);

          pc = ((ram[pc + 2] << BYTE_SHIFT_ALIGNMENT) & MAX_BYTE_SIZE) |
               (ram[pc + 1] & MAX_BYTE_SIZE);
        }
        else
        {
          pc += 3;
        }
      }
      break;
      case Call::NONCARRY_CALL:
      {

        /* cc   * Condition          * Flag
         *
         * 000  * Non-Zero (NZ)      * Z
         * 001  * Zero (Z)           * Z
         * 010  * Non Carry (NC)     * C
         * 011  * Carry (C)          * Z
         * 100  * Parity Odd (PO)    * P/V
         * 101  * Parity Even (PE)   * P/V
         * 110  * Sign Positive (P)  * S
         * 111  * Sign Negative (M)  * S */

        cycles += 3;

        if (!flag.C)
        {

          ram[sp - 1] = (pc >> BYTE_SHIFT_ALIGNMENT) & MAX_BYTE_SIZE;
          ram[sp - 2] = (pc & MAX_BYTE_SIZE);

          pc = ((ram[pc + 2] << BYTE_SHIFT_ALIGNMENT) & MAX_BYTE_SIZE) |
               (ram[pc + 1] & MAX_BYTE_SIZE);
        }
        else
        {
          pc += 3;
        }
      }
      break;

      case Call::CARRY_CALL:
      {

        /* cc   * Condition          * Flag
         *
         * 000  * Non-Zero (NZ)      * Z
         * 001  * Zero (Z)           * Z
         * 010  * Non Carry (NC)     * C
         * 011  * Carry (C)          * Z
         * 100  * Parity Odd (PO)    * P/V
         * 101  * Parity Even (PE)   * P/V
         * 110  * Sign Positive (P)  * S
         * 111  * Sign Negative (M)  * S */

        cycles += 3;

        if (flag.C)
        {

          ram[sp - 1] = (pc >> BYTE_SHIFT_ALIGNMENT) & MAX_BYTE_SIZE;
          ram[sp - 2] = (pc & MAX_BYTE_SIZE);

          pc = ((ram[pc + 2] << BYTE_SHIFT_ALIGNMENT) & MAX_BYTE_SIZE) |
               (ram[pc + 1] & MAX_BYTE_SIZE);
        }
        else
        {
          pc += 3;
        }
      }
      break;
      case Call::ODD_CALL:
      {

        /*  cc   * Condition         * Flag
         *
         * 000  * Non-Zero (NZ)      * Z
         * 001  * Zero (Z)           * Z
         * 010  * Non Carry (NC)     * C
         * 011  * Carry (C)          * Z
         * 100  * Parity Odd (PO)    * P/V
         * 101  * Parity Even (PE)   * P/V
         * 110  * Sign Positive (P)  * S
         * 111  * Sign Negative (M)  * S */

        cycles += 3;

        if (!flag.P)
        {

          ram[sp - 1] = (pc >> BYTE_SHIFT_ALIGNMENT) & MAX_BYTE_SIZE;
          ram[sp - 2] = (pc & MAX_BYTE_SIZE);

          pc = ((ram[pc + 2] << BYTE_SHIFT_ALIGNMENT) & MAX_BYTE_SIZE) |
               (ram[pc + 1] & MAX_BYTE_SIZE);
        }
        else
        {
          pc += 3;
        }
      }
      break;
      case Call::EVEN_CALL:
      {

        /* cc   * Condition          * Flag
         *
         * 000  * Non-Zero (NZ)      * Z
         * 001  * Zero (Z)           * Z
         * 010  * Non Carry (NC)     * C
         * 011  * Carry (C)          * Z
         * 100  * Parity Odd (PO)    * P/V
         * 101  * Parity Even (PE)   * P/V
         * 110  * Sign Positive (P)  * S
         * 111  * Sign Negative (M)  * S */

        cycles += 3;

        if (flag.P)
        {

          ram[sp - 1] = (pc >> BYTE_SHIFT_ALIGNMENT) & MAX_BYTE_SIZE;
          ram[sp - 2] = (pc & MAX_BYTE_SIZE);

          pc = ((ram[pc + 2] << BYTE_SHIFT_ALIGNMENT) & MAX_BYTE_SIZE) |
               (ram[pc + 1] & MAX_BYTE_SIZE);
        }
        else
        {
          pc += 3;
        }
      }
      break;
      case Call::POS_CALL:
      {

        /* cc   * Condition          * Flag
         *
         * 000  * Non-Zero (NZ)      * Z
         * 001  * Zero (Z)           * Z
         * 010  * Non Carry (NC)     * C
         * 011  * Carry (C)          * Z
         * 100  * Parity Odd (PO)    * P/V
         * 101  * Parity Even (PE)   * P/V
         * 110  * Sign Positive (P)  * S
         * 111  * Sign Negative (M)  * S */

        cycles += 3;

        if (flag.S)
        {

          ram[sp - 1] = (pc >> BYTE_SHIFT_ALIGNMENT) & MAX_BYTE_SIZE;
          ram[sp - 2] = (pc & MAX_BYTE_SIZE);

          pc = ((ram[pc + 2] << BYTE_SHIFT_ALIGNMENT) & MAX_BYTE_SIZE) |
               (ram[pc + 1] & MAX_BYTE_SIZE);
        }
        else
        {
          pc += 3;
        }
      }
      break;
      case Call::NEG_CALL:
      {

        /* cc   * Condition          * Flag
         *
         * 000  * Non-Zero (NZ)      * Z
         * 001  * Zero (Z)           * Z
         * 010  * Non Carry (NC)     * C
         * 011  * Carry (C)          * Z
         * 100  * Parity Odd (PO)    * P/V
         * 101  * Parity Even (PE)   * P/V
         * 110  * Sign Positive (P)  * S
         * 111  * Sign Negative (M)  * S */

        cycles += 3;

        if (!flag.S)
        {

          ram[sp - 1] = (pc >> BYTE_SHIFT_ALIGNMENT) & MAX_BYTE_SIZE;
          ram[sp - 2] = (pc & MAX_BYTE_SIZE);

          pc = ((ram[pc + 2] << BYTE_SHIFT_ALIGNMENT) & MAX_BYTE_SIZE) |
               (ram[pc + 1] & MAX_BYTE_SIZE);
        }
        else
        {
          pc += 3;
        }
      }
      break;
      case Jump::UNCON_JP:
      {
        cycles += 10;

        // Load next two bytes from ram into pc.
        pc = ram[pc + 2] | ram[pc + 1];

        cycles--;
      }
      break;
      case Jump::NONZERO_JP:
      {
        cycles += 10;

        if (!flag.Z)
          pc = ram[pc + 2] | ram[pc + 1];
        else
          pc += 3;

        cycles--;
      }
      break;
      case Jump::ZERO_JP:
      {
        cycles += 10;

        if (flag.Z)
          pc = ram[pc + 2] | ram[pc + 1];
        else
          pc += 3;

        cycles--;
      }
      break;
      case Jump::NONCARRY_JP:
      {
        cycles += 10;

        if (!flag.C)
          pc = ram[pc + 2] | ram[pc + 1];
        else
          pc += 3;

        cycles--;
      }
      break;
      case Jump::CARRY_JP:
      {
        cycles += 10;

        if (flag.C)
          pc = ram[pc + 2] | ram[pc + 1];
        else
          pc += 3;

        cycles--;
      }
      break;
      case Jump::ODD_JP:
      {
        cycles += 10;

        if (!flag.P)
          pc = ram[pc + 2] | ram[pc + 1];
        else
          pc += 3;

        cycles--;
      }
      break;
      case Jump::EVEN_JP:
      {
        cycles += 10;

        if (flag.P)
          pc = ram[pc + 2] | ram[pc + 1];
        else
          pc += 3;

        cycles--;
      }
      break;
      case Jump::POS_JP:
      {
        cycles += 10;

        if (flag.S)
          pc = ram[pc + 2] | ram[pc + 1];
        else
          pc += 3;

        cycles--;
      }
      break;
      case Jump::NEG_JP:
      {
        cycles += 10;

        if (!flag.S)
          pc = ram[pc + 2] | ram[pc + 1];
        else
          pc += 3;

        cycles--;
      }
      break;
      case Jump::UNCON_JR:
      {
        cycles += 12;

        // `d` represents displacement relative to `pc`
        // and is added to `pc`
        auto d = ram[pc + 1];

        // We skip the jump if the operand is `0x00`.
        // Otherwise, jump to pc + d offset in memory.
        // Though, this might be correct behaviour?
        // TODO: Make sure this is correct!
        if (d == 0x00)
          pc += 2;
        else
          pc += d;

        cycles--;
      }
      break;
      case Jump::CARRY_JR:
      {

        cycles += 12;

        // `d` represents displacement relative to `pc`
        // and is added to `pc`
        auto d = ram[pc + 1];

        // We skip the jump if the operand is `0x00`
        // or if the carry flag is not set.
        // Otherwise, jump to pc + d offset in memory.
        if (d == 0x00 || !flag.C)
          pc += 2;
        else
          pc += d;

        cycles--;
      }
      break;
      case Jump::NONCARRY_JR:
      {
        cycles += 12;

        // `d` represents displacement relative to `pc`
        // and is added to `pc`
        auto d = ram[pc + 1];

        // We skip the jump if the operand is `0x00`
        // or if the Carry flag is set.
        // Otherwise, jump to pc + d offset in memory.
        if (d == 0x00 || flag.C)
          pc += 2;
        else
          pc += d;

        cycles--;
      }
      break;
      case Jump::ZERO_JR:
      {
        cycles += 12;

        // `d` represents displacement relative to `pc`
        // and is added to `pc`
        auto d = ram[pc + 1];

        // We skip the jump if the operand is `0x00`
        // or if the Zero flag is not set.
        // Otherwise, jump to pc + d offset in memory.
        if (d == 0x00 || !flag.Z)
          pc += 2;
        else
          pc += d;

        cycles--;
      }
      break;
      case Jump::NONZERO_JR:
      {
        cycles += 12;

        // `d` represents displacement relative to `pc`
        // and is added to `pc`
        auto d = ram[pc + 1];

        // We skip the jump if the operand is `0x00`
        // or if the Zero flag is not set.
        // Otherwise, jump to pc + d offset in memory.
        if (d == 0x00 || flag.Z)
          pc += 2;
        else
          pc += d;

        cycles--;
      }
      break;
    }

#if ENABLE_DEBUG

    if (!glfw_is_shutdown)
    {
      fmt::print("At end of opcode search.\n");
      counter++;
      debug_opcode     = ram[pc];
      glfw_is_shutdown = debug::debug_handle(glfw_win, counter, this);

      if (glfw_is_shutdown)
        return;
    }

#endif
  }
}

