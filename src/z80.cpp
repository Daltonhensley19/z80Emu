//
// Created by dalton on 5/29/21.
//

#include <z80.h>
#include "../include/opcodes.h"

void Z80CPU::executeInstruction()
{
    while (cycles > 0)
    {
        // fetch current opcode
        currentOpcode = ram[pc] << 8 | ram[pc + 1];

        switch (this->currentOpcode)
        {
            case LD8::A_A_LD:
            {
                cycles = 4;
                ByteRegister::A_Reg_A = ByteRegister::A_Reg_A;
                cycles--;
                pc++;
            }
                break;
            case LD8::B_A_LD:
            {
                cycles = 4;
                ByteRegister::A_Reg_A = ByteRegister::B_Reg_A;
                cycles--;
                pc++;
            }
                break;

        }
    }
}

