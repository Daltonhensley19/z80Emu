//
// Created by dalton on 6/8/21.
//
#define FMT_HEADER_ONLY 1
#include "../include/registers.h"
#include "../include/fmt/core.h"
#include "../include/z80.h"

// Returns 8-bit registers B and C as a word.
Word bc_as_word()
{
  return ByteRegister::B_Reg_A << BYTE_SHIFT_ALIGNMENT | ByteRegister::C_Reg_A;
}

// Returns 8-bit registers A and F as a word.
Word af_as_word()
{
  return ByteRegister::A_Reg_A << BYTE_SHIFT_ALIGNMENT | ByteRegister::F_Reg_A;
}

// Returns 8-bit registers D and E as a word.
Word de_as_word()
{
  return ByteRegister::D_Reg_A << BYTE_SHIFT_ALIGNMENT | ByteRegister::E_Reg_A;
}

// Returns 8-bit registers H and L as a word.
Word hl_as_word()
{
  return ByteRegister::H_Reg_A << BYTE_SHIFT_ALIGNMENT | ByteRegister::L_Reg_A;
}

// A given flag is set if the given condition evaluates to true.
void set_flag_reg(bool condition, Byte flag_reg)
{

  if (condition)
    flag_reg = 1;
  else
    flag_reg = 0;
}

// Main register set
Byte ByteRegister::A_Reg_A = 10;
Byte ByteRegister::B_Reg_A = 200;
Byte ByteRegister::D_Reg_A = 0;
Byte ByteRegister::H_Reg_A = 20;

Byte ByteRegister::F_Reg_A = 0;
Byte ByteRegister::C_Reg_A = 0;
Byte ByteRegister::E_Reg_A = 0;
Byte ByteRegister::L_Reg_A = 0;

// Alternate register set
Byte ByteRegister::A_Reg_B = 0;
Byte ByteRegister::B_Reg_B = 0;
Byte ByteRegister::D_Reg_B = 0;
Byte ByteRegister::H_Reg_B = 0;

Byte ByteRegister::F_Reg_B = 0;
Byte ByteRegister::C_Reg_B = 0;
Byte ByteRegister::E_Reg_B = 20;
Byte ByteRegister::L_Reg_B = 0;

// Displays the 8-bit registers.
void debug::display_register_table()
{
  fmt::print("\n A_Reg_A: {0:#X}\n "
             "B_Reg_A: {1:#X}\n "
             "C_Reg_A: {2:#X}\n "
             "D_Reg_A: {3:#X}\n "
             "E_Reg_A: {4:#X}\n "
             "F_Reg_A: {5:#X}\n "
             "H_Reg_A: {6:#X}\n "
             "L_Reg_A: {7:#X}\n ",
             ByteRegister::A_Reg_A,
             ByteRegister::B_Reg_A,
             ByteRegister::C_Reg_A,
             ByteRegister::D_Reg_A,
             ByteRegister::E_Reg_A,
             ByteRegister::F_Reg_A,
             ByteRegister::H_Reg_A,
             ByteRegister::L_Reg_A);
}

// Displays a given 8-bit register.
void debug::display_single_register(char reg)
{
  switch (reg)
  {
    case 'A':
      fmt::print("\n A_Reg_A: {0:#X}\n", ByteRegister::A_Reg_A);
      break;
    case 'B':
      fmt::print("\n B_Reg_A: {0:#X}\n", ByteRegister::B_Reg_A);
      break;
    case 'C':
      fmt::print("\n C_Reg_A: {0:#X}\n", ByteRegister::C_Reg_A);
      break;
    case 'D':
      fmt::print("\n D_Reg_A: {0:#X}\n", ByteRegister::D_Reg_A);
      break;
    case 'E':
      fmt::print("\n E_Reg_A: {0:#X}\n", ByteRegister::E_Reg_A);
      break;
    case 'F':
      fmt::print("\n F_Reg_A: {0:#X}\n", ByteRegister::F_Reg_A);
      break;
    case 'H':
      fmt::print("\n H_Reg_A: {0:#X}\n", ByteRegister::H_Reg_A);
      break;
    case 'L':
      fmt::print("\n L_Reg_A: {0:#X}\n", ByteRegister::L_Reg_A);
      break;
    default:
      fmt::print("\nError, invalid register: {}\n", reg);
  }
}
