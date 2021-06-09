#pragma once

#include "emuTypes.h"
#include <array>

const std::uint16_t               RAM_SIZE = sizeof(std::uint16_t) - 1; // (2^16) - 1
inline std::array<Byte, RAM_SIZE> ram;

const Byte        MAX_BYTE_SIZE        = 0xff; // 255
const Word        MAX_WORD_SIZE        = 0xffff; // 65535
const std::size_t BYTE_SHIFT_ALIGNMENT = 8;

Byte readByte(const Word& address);


void writeByte(const Byte& byte, Word& address);


Word readWord(const Word& address);


void writeWord(Word& word, Word& address);


void resetMem(std::array<Byte, RAM_SIZE>& p_ram);


