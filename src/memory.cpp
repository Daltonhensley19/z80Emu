//
// Created by dalton on 6/8/21.
//

#include "../include/memory.h"
#include "../include/emuTypes.h"

#include <array>

Byte read_byte(const Word address)
{
  return ram[address];
}

void write_byte(const Byte byte, Word address)
{
  ram[address] = byte;
}

Word read_word(const Word address)
{
  return (ram[address] | ram[address + 1] << BYTE_SHIFT_ALIGNMENT);
}

void write_word(Word word, Word address)
{
  ram[address]     = word & MAX_BYTE_SIZE;
  ram[address + 1] = (word >> BYTE_SHIFT_ALIGNMENT) & MAX_BYTE_SIZE;
}

void reset_mem(std::array<Byte, RAM_SIZE>& p_ram)
{

  for (auto& byte : p_ram)
  {
    byte = 0;
  }
}

Word bytes_to_word(const Byte high_byte, const Byte low_byte)
{
  return high_byte << BYTE_SHIFT_ALIGNMENT | low_byte;
}
