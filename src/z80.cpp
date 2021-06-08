//
// Created by dalton on 5/29/21.
//

#include <z80.h>
#include "../include/opcodes.h"

void Z80CPU::executeInstruction()
{
    while (this->cycles > 0)
    {
        // fetch current opcode
        this->currentOpcode = ram[this->pc] << 8 | ram[this->pc + 1];

        switch (this->currentOpcode)
        {
            case LD8::A_A_LD:
            {
                cycles = 4;
                this->byteRegister.A_Reg_A = this->byteRegister.A_Reg_A;
                cycles--;
                pc++;
            }
                break;
            case LD8::B_A_LD:
            {
                cycles = 4;
                this->byteRegister.A_Reg_A = this->byteRegister.B_Reg_A;
                cycles--;
                pc++;
            }
                break;

        }
    }
}

