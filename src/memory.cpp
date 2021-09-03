//
// Created by dalton on 6/8/21.
//

#include "../include/memory.h"
#include "../include/emuTypes.h"

#include <array>

// Reads a byte from internal Z80 memory.
Byte read_byte(const Word address)
{
  return ram[address];
}

// Writes a byte to a specified address. 
void write_byte(const Byte byte, Word address)
{
  ram[address] = byte;
}

// Reads a word from internal Z80 memory.
Word read_word(const Word address)
{
  return (ram[address] | ram[address + 1] << BYTE_SHIFT_ALIGNMENT);
}

// Write a word to a specified address. 
void write_word(Word word, Word address)
{
  ram[address]     = word & MAX_BYTE_SIZE;
  ram[address + 1] = (word >> BYTE_SHIFT_ALIGNMENT) & MAX_BYTE_SIZE;
}

// Zero out Z80 memory. 
void reset_mem(std::array<Byte, RAM_SIZE>& p_ram)
{

  for (auto& byte : p_ram)
  {
    byte = 0;
  }
}

// Converts two bytes (usually a high and low byte) into a word.
Word bytes_to_word(const Byte high_byte, const Byte low_byte)
{
  return high_byte << BYTE_SHIFT_ALIGNMENT | low_byte;
}
