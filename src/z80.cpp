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
                pc += 2;
            }
                break;
            case LD8::B_A_LD:
            {
                cycles                = 4;
                ByteRegister::A_Reg_A = ByteRegister::B_Reg_A;
                cycles--;
                pc += 2;
            }
                break;
            case LD8::C_A_LD:
            {
                cycles                = 4;
                ByteRegister::A_Reg_A = ByteRegister::C_Reg_A;
                cycles--;
                pc += 2;
            }
                break;
            case LD8::D_A_LD:
            {
                cycles                = 4;
                ByteRegister::A_Reg_A = ByteRegister::D_Reg_A;
                cycles--;
                pc += 2;
            }
                break;
            case LD8::E_A_LD:
            {
                cycles                = 4;
                ByteRegister::A_Reg_A = ByteRegister::E_Reg_A;
                cycles--;
                pc += 2;
            }
                break;
            case LD8::H_A_LD:
            {
                cycles                = 4;
                ByteRegister::A_Reg_A = ByteRegister::H_Reg_A;
                cycles--;
                pc += 2;
            }
                break;
            case LD8::L_A_LD:
            {
                cycles                = 4;
                ByteRegister::A_Reg_A = ByteRegister::L_Reg_A;
                cycles--;
                pc += 2;
            }
                break;
            case LD8::HL_A_LD:
            {
                cycles                = 8;
                ByteRegister::A_Reg_A = ram[HLasWord()];
                cycles--;
                pc += 2;
            }
                break;
            case LD8::B_B_LD:
            {
                cycles                = 4;
                ByteRegister::B_Reg_A = ByteRegister::B_Reg_A;
                cycles--;
                pc += 2;
            }
                break;
            case LD8::C_B_LD:
            {
                cycles                = 4;
                ByteRegister::B_Reg_A = ByteRegister::C_Reg_A;
                cycles--;
                pc += 2;
            }
                break;
            case LD8::D_B_LD:
            {
                cycles                = 4;
                ByteRegister::B_Reg_A = ByteRegister::D_Reg_A;
                cycles--;
                pc += 2;
            }
                break;
            case LD8::E_B_LD:
            {
                cycles                = 4;
                ByteRegister::B_Reg_A = ByteRegister::E_Reg_A;
                cycles--;
                pc += 2;
            }
                break;
            case LD8::H_B_LD:
            {
                cycles                = 4;
                ByteRegister::B_Reg_A = ByteRegister::H_Reg_A;
                cycles--;
                pc += 2;
            }
                break;
            case LD8::L_B_LD:
            {
                cycles                = 4;
                ByteRegister::B_Reg_A = ByteRegister::L_Reg_A;
                cycles--;
                pc += 2;
            }
                break;
            case LD8::HL_B_LD:
            {
                cycles                = 8;
                ByteRegister::B_Reg_A = ram[HLasWord()];
                cycles--;
                pc += 2;
            }
                break;
            case LD8::B_C_LD:
            {
                cycles                = 4;
                ByteRegister::C_Reg_A = ByteRegister::B_Reg_A;
                cycles--;
                pc += 2;
            }
                break;
            case LD8::C_C_LD:
            {
                cycles                = 4;
                ByteRegister::C_Reg_A = ByteRegister::C_Reg_A;
                cycles--;
                pc += 2;
            }
                break;
            case LD8::D_C_LD:
            {
                cycles                = 4;
                ByteRegister::C_Reg_A = ByteRegister::D_Reg_A;
                cycles--;
                pc += 2;
            }
                break;
            case LD8::E_C_LD:
            {
                cycles                = 4;
                ByteRegister::C_Reg_A = ByteRegister::E_Reg_A;
                cycles--;
                pc += 2;
            }
                break;
            case LD8::H_C_LD:
            {
                cycles                = 4;
                ByteRegister::C_Reg_A = ByteRegister::H_Reg_A;
                cycles--;
                pc += 2;
            }
                break;
            case LD8::L_C_LD:
            {
                cycles                = 4;
                ByteRegister::C_Reg_A = ByteRegister::L_Reg_A;
                cycles--;
                pc += 2;
            }
                break;
            case LD8::HL_C_LD:
            {
                cycles                = 8;
                ByteRegister::B_Reg_A = ram[HLasWord()];
                cycles--;
                pc += 2;
            }
                break;
            case LD8::B_D_LD:
            {
                cycles                = 4;
                ByteRegister::D_Reg_A = ByteRegister::B_Reg_A;
                cycles--;
                pc += 2;
            }
                break;
            case LD8::C_D_LD:
            {
                cycles                = 4;
                ByteRegister::D_Reg_A = ByteRegister::C_Reg_A;
                cycles--;
                pc += 2;
            }
                break;
            case LD8::D_D_LD:
            {
                cycles                = 4;
                ByteRegister::D_Reg_A = ByteRegister::D_Reg_A;
                cycles--;
                pc += 2;
            }
                break;
            case LD8::E_D_LD:
            {
                cycles                = 4;
                ByteRegister::D_Reg_A = ByteRegister::E_Reg_A;
                cycles--;
                pc += 2;
            }
                break;
            case LD8::H_D_LD:
            {
                cycles                = 4;
                ByteRegister::D_Reg_A = ByteRegister::H_Reg_A;
                cycles--;
                pc += 2;
            }
                break;
            case LD8::L_D_LD:
            {
                cycles                = 4;
                ByteRegister::D_Reg_A = ByteRegister::L_Reg_A;
                cycles--;
                pc += 2;
            }
                break;
            case LD8::HL_D_LD:
            {
                cycles                = 8;
                ByteRegister::D_Reg_A = ram[HLasWord()];
                cycles--;
                pc += 2;
            }
                break;
            case LD8::B_E_LD:
            {
                cycles                = 4;
                ByteRegister::E_Reg_A = ByteRegister::B_Reg_A;
                cycles--;
                pc += 2;
            }
                break;
            case LD8::C_E_LD:
            {
                cycles                = 4;
                ByteRegister::E_Reg_A = ByteRegister::C_Reg_A;
                cycles--;
                pc += 2;
            }
                break;
            case LD8::D_E_LD:
            {
                cycles                = 4;
                ByteRegister::E_Reg_A = ByteRegister::D_Reg_A;
                cycles--;
                pc += 2;
            }
                break;
            case LD8::E_E_LD:
            {
                cycles                = 4;
                ByteRegister::E_Reg_A = ByteRegister::E_Reg_A;
                cycles--;
                pc += 2;
            }
                break;
            case LD8::H_E_LD:
            {
                cycles                = 4;
                ByteRegister::E_Reg_A = ByteRegister::H_Reg_A;
                cycles--;
                pc += 2;
            }
                break;
            case LD8::L_E_LD:
            {
                cycles                = 4;
                ByteRegister::E_Reg_A = ByteRegister::L_Reg_A;
                cycles--;
                pc += 2;
            }
                break;
            case LD8::HL_E_LD:
            {
                cycles                = 8;
                ByteRegister::E_Reg_A = ram[HLasWord()];
                cycles--;
                pc += 2;
            }
                break;
            case LD8::B_H_LD:
            {
                cycles                = 4;
                ByteRegister::H_Reg_A = ByteRegister::B_Reg_A;
                cycles--;
                pc += 2;
            }
                break;
            case LD8::C_H_LD:
            {
                cycles                = 4;
                ByteRegister::H_Reg_A = ByteRegister::C_Reg_A;
                cycles--;
                pc += 2;
            }
                break;
            case LD8::D_H_LD:
            {
                cycles                = 4;
                ByteRegister::H_Reg_A = ByteRegister::D_Reg_A;
                cycles--;
                pc += 2;
            }
                break;
            case LD8::E_H_LD:
            {
                cycles                = 4;
                ByteRegister::H_Reg_A = ByteRegister::E_Reg_A;
                cycles--;
                pc += 2;
            }
                break;
            case LD8::H_H_LD:
            {
                cycles                = 4;
                ByteRegister::H_Reg_A = ByteRegister::H_Reg_A;
                cycles--;
                pc += 2;
            }
                break;
            case LD8::L_H_LD:
            {
                cycles                = 4;
                ByteRegister::H_Reg_A = ByteRegister::L_Reg_A;
                cycles--;
                pc += 2;
            }
                break;
            case LD8::HL_H_LD:
            {
                cycles                = 8;
                ByteRegister::H_Reg_A = ram[HLasWord()];
                cycles--;
                pc += 2;
            }
                break;
            case LD8::B_L_LD:
            {
                cycles                = 4;
                ByteRegister::L_Reg_A = ByteRegister::B_Reg_A;
                cycles--;
                pc += 2;
            }
                break;
            case LD8::C_L_LD:
            {
                cycles                = 4;
                ByteRegister::L_Reg_A = ByteRegister::C_Reg_A;
                cycles--;
                pc += 2;
            }
                break;
            case LD8::D_L_LD:
            {
                cycles                = 4;
                ByteRegister::L_Reg_A = ByteRegister::D_Reg_A;
                cycles--;
                pc += 2;
            }
                break;
            case LD8::E_L_LD:
            {
                cycles                = 4;
                ByteRegister::L_Reg_A = ByteRegister::E_Reg_A;
                cycles--;
                pc += 2;
            }
                break;
            case LD8::H_L_LD:
            {
                cycles                = 4;
                ByteRegister::L_Reg_A = ByteRegister::H_Reg_A;
                cycles--;
                pc += 2;
            }
                break;
            case LD8::L_L_LD:
            {
                cycles                = 4;
                ByteRegister::L_Reg_A = ByteRegister::L_Reg_A;
                cycles--;
                pc += 2;
            }
                break;
            case LD8::HL_L_LD:
            {
                cycles                = 8;
                ByteRegister::L_Reg_A = ram[HLasWord()];
                cycles--;
                pc += 2;
            }
                break;
            case LD8::B_HL_LD:
            {
                cycles = 8;
                ram[HLasWord()] = ByteRegister::B_Reg_A;
                cycles--;
                pc += 2;
            }
                break;
            case LD8::C_HL_LD:
            {
                cycles = 8;
                ram[HLasWord()] = ByteRegister::C_Reg_A;
                cycles--;
                pc += 2;
            }
                break;
            case LD8::D_HL_LD:
            {
                cycles = 8;
                ram[HLasWord()] = ByteRegister::D_Reg_A;
                cycles--;
                pc += 2;
            }
                break;
            case LD8::E_HL_LD:
            {
                cycles = 8;
                ram[HLasWord()] = ByteRegister::E_Reg_A;
                cycles--;
                pc += 2;
            }
                break;
            case LD8::H_HL_LD:
            {
                cycles = 8;
                ram[HLasWord()] = ByteRegister::H_Reg_A;
                cycles--;
                pc += 2;
            }
                break;
            case LD8::L_HL_LD:
            {
                cycles = 8;
                ram[HLasWord()] = ByteRegister::L_Reg_A;
                cycles--;
                pc += 2;
            }
                break;
            case LD8::n_HL_LD:
            {
                cycles = 8;
                ram[HLasWord()] = ram[pc + 1]; // LD imm to indirect address
                cycles--;
                pc += 2;
            }
                break;


        }
    }
}


