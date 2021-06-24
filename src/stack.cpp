#include "../include/stack.h"
#include "../include/z80.h"


void Stack::pushByte(Byte byte)
{
    ram[--Z80CPU::sp] = byte;

}

void Stack::pushWord(Word word)
{
    Byte highByte = (word >> BYTE_SHIFT_ALIGNMENT) & MAX_BYTE_SIZE;
    Byte lowByte  = word & MAX_BYTE_SIZE;

    ram[--Z80CPU::sp] = highByte;
    ram[--Z80CPU::sp] = lowByte;
}

Word Stack::popWord()
{
    Byte lowByte  = ram[Z80CPU::sp++];
    Byte highByte = ram[Z80CPU::sp++];

    return (highByte << BYTE_SHIFT_ALIGNMENT) | lowByte;

}