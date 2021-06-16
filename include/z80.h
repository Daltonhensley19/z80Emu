#pragma once

#include "emuTypes.h"
#include "registers.h"
#include "memory.h"

class Z80CPU
{
private:
     Word pc;
    // Program Counter
     Word sp;
    // Stack Pointer
     Word ix;
    // Index Register
     Word iy;
    // Index Register
     Byte I;
    // Interrupt Page Register
     Byte R;

    // Memory Refresh Register


/*
    During the LD A, I and LD A, R instructions, the P/V Flag is
    set with the value of the
    interrupt enable flip-flop (IFF2) for storage or testing.
*/
    bool IFF1;
    bool IFF2;

    FlagBitField flag;
    // Bit Field for common Z80 Flags
    ByteRegister byteRegister;

    std::size_t cycles;
    // CPU clock cycle counter

    Word currentOpcode;
    // Usually 8-bits (currentOpcode & 0xFF00 >> 8),
    // but sometimes 16-bits due to prefixes (DD, ED, FD, CB).

public:
    void executeInstruction();

    Z80CPU() : flag{0, 0, 0, 0, 0, 0, 0}
    {}
};