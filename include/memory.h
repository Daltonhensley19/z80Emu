#pragma once

#include "emuTypes.h"
#include <array>

const std::uint16_t RAM_SIZE = sizeof(std::uint16_t) - 1; // (2^16) - 1
std::array<Byte, RAM_SIZE> ram;

const Byte MAX_BYTE_SIZE = 0xff; // 255
const Word MAX_WORD_SIZE = 0xffff; // 65535

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
    return (ram[address]) | (ram[address + 1] << 8);
}

void writeWord(Word& word, Word& address)
{
    ram[address] = word & MAX_BYTE_SIZE; // We AND here to make sure we only
    // store the first byte.
    ram[address + 1] = (word >> 8) & MAX_BYTE_SIZE;
}

void resetMem(std::array<Byte, RAM_SIZE>& ram)
{
    for (auto& byte: ram)
        byte = 0;
}
