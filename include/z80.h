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

    FlagBitField flag;
    // Bit Field for common Z80 Flags
    ByteRegister byteRegister;

    std::size_t cycles;
    // CPU clock cycle counter

    Word currentOpcode;
    // Usually 8-bits (currentOpcode & 0xFF00),
    // but sometimes 16-bits due to prefixes (DD, ED, FD, CB).

public:
    void executeInstruction();

    Z80CPU() : pc(0), sp(0), ix(0), iy(0), I(0), R(0), flag{0, 0, 0, 0, 0, 0, 0}
    {}
};