#pragma once

#include "emuTypes.h"
#include "registers.h"
#include "memory.h"
#include "stack.h"

struct Z80CPU
{

    // Program Counter
    Word        pc;
    // Stack Pointer
   inline static Word sp;
    // Index Register
    Word        ix;
    // Index Register
    Word        iy;
    // Interrupt Page Register
    Byte        I;
    // Memory Refresh Register
    Byte        R;


/*
    During the LD A, I and LD A, R instructions, the P/V Flag is
    set with the value of the
    interrupt enable flip-flop (IFF2) for storage or testing.
*/
    bool IFF1;
    bool IFF2;

    // Bit Field for common Z80 Flags
    FlagBitField flag;


    ByteRegister byteRegister{};

    // CPU clock cycle counter
    std::size_t cycles;

    // Usually 8-bits (currentOpcode & 0xFF00 >> 8),
    // but sometimes 16-bits due to prefixes (DD, ED, FD, CB).
    Word currentOpcode;

    // Stack operations
    Stack stack;

    void executeInstruction();

    Z80CPU() : flag{0, 0, 0, 0, 0, 0, 0}
    {}
};