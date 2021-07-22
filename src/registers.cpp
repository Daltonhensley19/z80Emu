//
// Created by dalton on 6/8/21.
//
#define FMT_HEADER_ONLY 1
#include "../include/registers.h"
#include "../include/fmt/core.h"
#include "../include/z80.h"

Word BCasWord()
{
  return ByteRegister::B_Reg_A << BYTE_SHIFT_ALIGNMENT | ByteRegister::C_Reg_A;
}

Word AFasWord()
{
  return ByteRegister::A_Reg_A << BYTE_SHIFT_ALIGNMENT | ByteRegister::F_Reg_A;
}

Word DEasWord()
{
  return ByteRegister::D_Reg_A << BYTE_SHIFT_ALIGNMENT | ByteRegister::E_Reg_A;
}

Word HLasWord()
{
  return ByteRegister::H_Reg_A << BYTE_SHIFT_ALIGNMENT | ByteRegister::L_Reg_A;
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

void debugRegisters::displayRegisterTable()
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

void debugRegisters::displaySingleRegister(char reg)
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
