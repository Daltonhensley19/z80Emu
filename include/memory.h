#pragma once

#include "emuTypes.h"
#include <array>

const std::uint16_t               RAM_SIZE = sizeof(std::uint16_t) - 1; // (2^16) - 1
inline std::array<Byte, RAM_SIZE> ram;

const Byte        MAX_BYTE_SIZE        = 0xff; // 255
const Word        MAX_WORD_SIZE        = 0xffff; // 65535
const std::size_t BYTE_SHIFT_ALIGNMENT = 8;

inline Byte readByte(const Word& address)
{
    return ram[address];
}

inline void writeByte(const Byte& byte, Word& address)
{
    ram[address] = byte;
}

inline Word readWord(const Word& address)
{
    return (ram[address] | ram[address + 1] << BYTE_SHIFT_ALIGNMENT);
}

inline void writeWord(Word& word, Word& address)
{
    ram[address]     = word & MAX_BYTE_SIZE;
    ram[address + 1] = (word >> BYTE_SHIFT_ALIGNMENT) & MAX_BYTE_SIZE;
}

inline void resetMem(std::array<Byte, RAM_SIZE>& p_ram)
{

    for (auto& byte: p_ram)
    {
        byte = 0;
    }
}

