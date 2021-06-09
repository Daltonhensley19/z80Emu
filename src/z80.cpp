//
// Created by dalton on 5/29/21.
//

#include "../include/z80.h"
#include "../include/opcodes.h"


#define opcodeByte  ((currentOpcode & 0xFF00) >> BYTE_SHIFT_ALIGNMENT)
#define opcodePair currentOpcode


void Z80CPU::executeInstruction()
{
    while (cycles > 0)
    {
        // fetch current opcode
        currentOpcode = ram[pc] << 8 | ram[pc + 1];
        switch (opcodeByte)
        {
            case LD8::A_A_LD:
            {
                cycles                = 4;
                ByteRegister::A_Reg_A = ByteRegister::A_Reg_A;
                cycles--;
                pc++;
            }
                break;
            case LD8::B_A_LD:
            {
                cycles                = 4;
                ByteRegister::A_Reg_A = ByteRegister::B_Reg_A;
                cycles--;
                pc++;
            }
                break;
            case LD8::C_A_LD:
            {
                cycles                = 4;
                ByteRegister::A_Reg_A = ByteRegister::C_Reg_A;
                cycles--;
                pc++;
            }
                break;
            case LD8::D_A_LD:
            {
                cycles                = 4;
                ByteRegister::A_Reg_A = ByteRegister::D_Reg_A;
                cycles--;
                pc++;
            }
                break;
            case LD8::E_A_LD:
            {
                cycles                = 4;
                ByteRegister::A_Reg_A = ByteRegister::E_Reg_A;
                cycles--;
                pc++;
            }
                break;
            case LD8::H_A_LD:
            {
                cycles                = 4;
                ByteRegister::A_Reg_A = ByteRegister::H_Reg_A;
                cycles--;
                pc++;
            }
                break;
            case LD8::L_A_LD:
            {
                cycles                = 4;
                ByteRegister::A_Reg_A = ByteRegister::L_Reg_A;
                cycles--;
                pc++;
            }
                break;
            case LD8::HL_A_LD:
            {
                cycles                = 8;
                ByteRegister::A_Reg_A = ram[HLasWord()];
                cycles--;
                pc++;
            }
                break;
            case LD8::B_B_LD:
            {
                cycles                = 4;
                ByteRegister::B_Reg_A = ByteRegister::B_Reg_A;
                cycles--;
                pc++;
            }
                break;
            case LD8::C_B_LD:
            {
                cycles                = 4;
                ByteRegister::B_Reg_A = ByteRegister::C_Reg_A;
                cycles--;
                pc++;
            }
                break;
            case LD8::D_B_LD:
            {
                cycles                = 4;
                ByteRegister::B_Reg_A = ByteRegister::D_Reg_A;
                cycles--;
                pc++;
            }
                break;
            case LD8::E_B_LD:
            {
                cycles                = 4;
                ByteRegister::B_Reg_A = ByteRegister::E_Reg_A;
                cycles--;
                pc++;
            }
                break;
            case LD8::H_B_LD:
            {
                cycles                = 4;
                ByteRegister::B_Reg_A = ByteRegister::H_Reg_A;
                cycles--;
                pc++;
            }
                break;
            case LD8::L_B_LD:
            {
                cycles = 4;
                ByteRegister::B_Reg_A = ByteRegister::L_Reg_A;
                cycles--;
                pc++;
            } break;


        }
    }
}


