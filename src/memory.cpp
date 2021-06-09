//
// Created by dalton on 6/8/21.
//


#include "../include/emuTypes.h"
#include "../include/memory.h"

#include <array>

Byte readByte(const Word& address)
{
    return ram[address];
}

void writeByte(const Byte& byte, Word& address)
{
    ram[address] = byte;
}

Word readWord(const Word& address)
{
    return (ram[address] | ram[address + 1] << BYTE_SHIFT_ALIGNMENT);
}

void writeWord(Word& word, Word& address)
{
    ram[address]     = word & MAX_BYTE_SIZE;
    ram[address + 1] = (word >> BYTE_SHIFT_ALIGNMENT) & MAX_BYTE_SIZE;
}

void resetMem(std::array<Byte, RAM_SIZE>& p_ram)
{
    for (auto& byte: p_ram)
    {
        byte = 0;
    }
}

