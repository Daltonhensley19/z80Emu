#pragma once

#include "emuTypes.h"
#include "registers.h"
#include "memory.h"

class Z80CPU
{
private:
    Word pc; // Program Counter
    Word sp; // Stack Pointer
    Word ix; // Index Register
    Word iy; // Index Register
    Byte I; // Interrupt Page Register
    Byte R; // Memory Refresh Register

    FlagBitField flag; // Bit Field for common Z80 Flags
    ByteRegister byteRegister;

    std::size_t cycles; // CPU clock cycle counter

    Word currentOpcode;

public:
    void executeInstruction();
};