#pragma once

#include "emuTypes.h"
#include <array>
#include <limits>

const auto RAM_SIZE = std::numeric_limits<std::uint16_t>::max(); // (2^16) - 1

inline std::array<Byte, RAM_SIZE> ram;

const Byte MAX_BYTE_SIZE               = 0xff;   // 255
const Word MAX_WORD_SIZE               = 0xffff; // 65535
const std::size_t BYTE_SHIFT_ALIGNMENT = 8;

Byte read_byte(const Word address);

void write_byte(const Byte byte, Word address);

Word read_word(const Word address);

void write_word(Word word, Word address);

void reset_mem(std::array<Byte, RAM_SIZE>& p_ram);

Word bytes_to_word(const Byte high_byte, const Byte low_byte);

