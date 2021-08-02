#pragma once

#include "emuTypes.h"
#include "memory.h"
#include "registers.h"
#include "stack.h"

struct Z80CPU
{

  // Program Counter
  Word pc = 0;
  // Stack Pointer
  inline static Word sp = 0;
  // Index Register
  Word ix = 0;
  // Index Register
  Word iy = 0;
  // Interrupt Page Register
  Byte I = 0;
  // Memory Refresh Register
  Byte R = 0;

  /*
      During the LD A, I and LD A, R instructions, the P/V Flag is
      set with the value of the
      interrupt enable flip-flop (IFF2) for storage or testing.
  */
  bool IFF1 = false;
  bool IFF2 = false;

  // Bit Field for common Z80 Flags
  FlagBitField flag;

  ByteRegister byte_register;

  // CPU clock cycle counter
  std::size_t cycles;

  // Usually 8-bits (currentOpcode & 0xFF00 >> 8),
  // but sometimes 16-bits due to prefixes (DD, ED, FD, CB).
  Word current_opcode = 0x0000;
  Word debug_opcode   = 0x0000;

  // Stack operations
  Stack stack;

  void execute_instruction();

  Z80CPU()
    : flag{0, 0, {0}, 0, 0, 0, 0, 0}
  {
  }
};
