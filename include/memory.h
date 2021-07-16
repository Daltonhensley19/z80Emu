#pragma once

#include "emuTypes.h"
#include <array>
#include <limits>

const auto RAM_SIZE = std::numeric_limits<std::uint16_t>::max(); // (2^16) - 1

inline std::array<Byte, RAM_SIZE> ram;

const Byte MAX_BYTE_SIZE               = 0xff;   // 255
const Word MAX_WORD_SIZE               = 0xffff; // 65535
const std::size_t BYTE_SHIFT_ALIGNMENT = 8;

Byte readByte(const Word address);

void writeByte(const Byte byte, Word address);

Word readWord(const Word address);

void writeWord(Word word, Word address);

void resetMem(std::array<Byte, RAM_SIZE>& p_ram);

Word bytesToWord(const Byte highByte, const Byte lowByte);

