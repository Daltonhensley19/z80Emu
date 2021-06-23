//
// Created by dalton on 5/29/21.
//

#include "../include/z80.h"
#include "../include/opcodes.h"


// I must apologize for the very long switch table.
// This is the quickest (yet dirtiest) way to implement the Z80 opcodes.
void Z80CPU::executeInstruction()
{


    while (cycles > 0)
    {
        // fetch current opcode
        currentOpcode = ram[pc] << 8 | ram[pc + 1];
        Byte opcodeByte = ((currentOpcode & 0xFF00) >> BYTE_SHIFT_ALIGNMENT);
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
            case LD8::A_B_LD:
            {
                cycles                = 4;
                ByteRegister::B_Reg_A = ByteRegister::A_Reg_A;
                cycles--;
                pc += 2;
            }
                break;
            case LD8::A_C_LD:
            {
                cycles                = 4;
                ByteRegister::C_Reg_A = ByteRegister::A_Reg_A;
                cycles--;
                pc += 2;
            }
                break;
            case LD8::A_D_LD:
            {
                cycles                = 4;
                ByteRegister::D_Reg_A = ByteRegister::A_Reg_A;
                cycles--;
                pc += 2;
            }
                break;
            case LD8::A_E_LD:
            {
                cycles                = 4;
                ByteRegister::E_Reg_A = ByteRegister::A_Reg_A;
                cycles--;
                pc += 2;
            }
                break;
            case LD8::A_H_LD:
            {
                cycles                = 4;
                ByteRegister::H_Reg_A = ByteRegister::A_Reg_A;
                cycles--;
                pc += 2;
            }
                break;
            case LD8::A_L_LD:
            {
                cycles                = 4;
                ByteRegister::L_Reg_A = ByteRegister::A_Reg_A;
                cycles--;
                pc += 2;
            }
                break;
            case LD8::A_BC_LD:
            {
                cycles = 8;
                ram[BCasWord()] = ByteRegister::A_Reg_A;
                cycles--;
                pc += 2;
            }
                break;
            case LD8::A_DE_LD:
            {
                cycles = 8;
                ram[DEasWord()] = ByteRegister::A_Reg_A;
                cycles--;
                pc += 2;
            }
                break;
            case LD8::A_HL_LD:
            {
                cycles = 8;
                ram[HLasWord()] = ByteRegister::A_Reg_A;
                cycles--;
                pc += 2;
            }
                break;
            case LD8::A_nn_LD:
            {
                cycles = 8;
                writeByte(ByteRegister::A_Reg_A, bytesToWord(ram[pc + 2], ram[pc + 1]));
                cycles--;
                pc += 2;
            }
                break;
            case LD8::n_A_LD:
            {
                cycles                = 8;
                ByteRegister::A_Reg_A = ram[pc + 1]; // LD imm to register
                cycles--;
                pc += 2;
            }
                break;
            case LD8::n_B_LD:
            {
                cycles                = 8;
                ByteRegister::B_Reg_A = ram[pc + 1]; // LD imm to register
                cycles--;
                pc += 2;
            }
                break;
            case LD8::n_C_LD:
            {
                cycles                = 8;
                ByteRegister::C_Reg_A = ram[pc + 1]; // LD imm to register
                cycles--;
                pc += 2;
            }
                break;
            case LD8::n_D_LD:
            {
                cycles                = 8;
                ByteRegister::D_Reg_A = ram[pc + 1]; // LD imm to register
                cycles--;
                pc += 2;
            }
                break;
            case LD8::n_E_LD:
            {
                cycles                = 8;
                ByteRegister::E_Reg_A = ram[pc + 1]; // LD imm to register
                cycles--;
                pc += 2;
            }
                break;
            case LD8::n_H_LD:
            {
                cycles                = 8;
                ByteRegister::H_Reg_A = ram[pc + 1]; // LD imm to register
                cycles--;
                pc += 2;
            }
                break;
            case LD8::n_L_LD:
            {
                cycles                = 8;
                ByteRegister::L_Reg_A = ram[pc + 1]; // LD imm to register
                cycles--;
                pc += 2;
            }
                break;
            case LD8::BC_A_LD:
            {
                cycles                = 8;
                ByteRegister::A_Reg_A = ram[BCasWord()]; // LD indirect address to reg.
                cycles--;
                pc += 2;
            }
                break;
            case LD8::DE_A_LD:
            {
                cycles                = 8;
                ByteRegister::A_Reg_A = ram[DEasWord()]; // LD indirect address to reg.
                cycles--;
                pc += 2;
            }
                break;
            case LD8::nn_A_LD:
            {
                cycles                = 13; //TODO(Dalton): possible mistake in cycles?
                ByteRegister::A_Reg_A = readByte(bytesToWord(ram[pc + 2], ram[pc + 1]));
                cycles--;
                pc += 2;
            }
                break;
                // DD Prefixed Opcodes
            case LD8::IDX_R_LD:
            {
                Byte d = ram[pc + 2];
                switch (ram[pc + 1])
                {
                    case LD8::HL_A_LD:
                    {
                        cycles                = 19;
                        ByteRegister::A_Reg_A = ram[ix + d];
                        cycles--;
                        pc += 2;
                    }
                        break;
                    case LD8::HL_B_LD:
                    {
                        cycles                = 19;
                        ByteRegister::B_Reg_A = ram[ix + d];
                        cycles--;
                        pc += 2;
                    }
                        break;
                    case LD8::HL_C_LD:
                    {
                        cycles                = 19;
                        ByteRegister::C_Reg_A = ram[ix + d];
                        cycles--;
                        pc += 2;
                    }
                        break;
                    case LD8::HL_D_LD:
                    {
                        cycles                = 19;
                        ByteRegister::D_Reg_A = ram[ix + d];
                        cycles--;
                        pc += 2;
                    }
                        break;
                    case LD8::HL_E_LD:
                    {
                        cycles                = 19;
                        ByteRegister::E_Reg_A = ram[ix + d];
                        cycles--;
                        pc += 2;
                    }
                        break;
                    case LD8::HL_H_LD:
                    {
                        cycles                = 19;
                        ByteRegister::H_Reg_A = ram[ix + d];
                        cycles--;
                        pc += 2;
                    }
                        break;
                    case LD8::HL_L_LD:
                    {
                        cycles                = 19;
                        ByteRegister::L_Reg_A = ram[ix + d];
                        cycles--;
                        pc += 2;
                    }
                        break;
                    case LD8::A_HL_LD:
                    {
                        cycles = 19;
                        ram[ix + d] = ByteRegister::A_Reg_A;
                        cycles--;
                        pc += 2;
                    }
                        break;
                    case LD8::B_HL_LD:
                    {
                        cycles = 19;
                        ram[ix + d] = ByteRegister::B_Reg_A;
                        cycles--;
                        pc += 2;
                    }
                        break;
                    case LD8::C_HL_LD:
                    {
                        cycles = 19;
                        ram[ix + d] = ByteRegister::C_Reg_A;
                        cycles--;
                        pc += 2;
                    }
                        break;
                    case LD8::D_HL_LD:
                    {
                        cycles = 19;
                        ram[ix + d] = ByteRegister::D_Reg_A;
                        cycles--;
                        pc += 2;
                    }
                        break;
                    case LD8::E_HL_LD:
                    {
                        cycles = 19;
                        ram[ix + d] = ByteRegister::E_Reg_A;
                        cycles--;
                        pc += 2;
                    }
                        break;
                    case LD8::H_HL_LD:
                    {
                        cycles = 19;
                        ram[ix + d] = ByteRegister::H_Reg_A;
                        cycles--;
                        pc += 2;
                    }
                        break;
                    case LD8::L_HL_LD:
                    {
                        cycles = 19;
                        ram[ix + d] = ByteRegister::L_Reg_A;
                        cycles--;
                        pc += 2;
                    }
                        break;
                    case LD8::n_HL_LD:
                    {
                        cycles = 19;
                        ram[ix + d] = ram[pc + 3];
                        cycles--;
                        pc += 2;
                    }
                        break;
                    case LD16::nn_HL_LD:
                    {
                        cycles = 14;

                        ix = readWord(pc + 2);
                        cycles--;
                        pc += 2;
                    }
                        break;
                    case LD16::nn_HL_LD_EXT:
                    {
                        cycles = 20;

                        Word position = readWord(pc + 2);
                        ix = ram[position + 1] << BYTE_SHIFT_ALIGNMENT | ram[position];

                        cycles--;
                        pc += 2;
                    }
                        break;
                    case Pop::POP_HL:
                    {
                        cycles = 14;

                        ix = popWord();

                        cycles--;
                        pc += 2;

                    }
                        break;
                    case LD16::HL_SP_LD:
                    {
                        cycles = 10;

                        sp = ix;

                        cycles--;
                        pc += 2;
                    }
                        break;
                    case LD16::HL_nn_LD:
                    {
                        cycles = 20;

                        std::uint32_t location = readWord(pc + 2);

                        Byte highByte = (ix >> BYTE_SHIFT_ALIGNMENT) & MAX_BYTE_SIZE;
                        Byte lowByte  = ix & MAX_BYTE_SIZE;

                        ram[location + 1] = highByte;
                        ram[location]     = lowByte;

                        cycles--;
                        pc += 2;
                    }


                }
            }
                break;
                // FD Prefixed Opcodes
            case LD8::IDY_R_LD:
            {
                Byte d = ram[pc + 2];
                switch (ram[pc + 1])
                {
                    case LD8::HL_A_LD:
                    {
                        cycles                = 19;
                        ByteRegister::A_Reg_A = ram[iy + d];
                        cycles--;
                        pc += 2;
                    }
                        break;
                    case LD8::HL_B_LD:
                    {
                        cycles                = 19;
                        ByteRegister::B_Reg_A = ram[iy + d];
                        cycles--;
                        pc += 2;
                    }
                        break;
                    case LD8::HL_C_LD:
                    {
                        cycles                = 19;
                        ByteRegister::C_Reg_A = ram[iy + d];
                        cycles--;
                        pc += 2;
                    }
                        break;
                    case LD8::HL_D_LD:
                    {
                        cycles                = 19;
                        ByteRegister::D_Reg_A = ram[iy + d];
                        cycles--;
                        pc += 2;
                    }
                        break;
                    case LD8::HL_E_LD:
                    {
                        cycles                = 19;
                        ByteRegister::E_Reg_A = ram[iy + d];
                        cycles--;
                        pc += 2;
                    }
                        break;
                    case LD8::HL_H_LD:
                    {
                        cycles                = 19;
                        ByteRegister::H_Reg_A = ram[iy + d];
                        cycles--;
                        pc += 2;
                    }
                        break;
                    case LD8::HL_L_LD:
                    {
                        cycles                = 19;
                        ByteRegister::L_Reg_A = ram[iy + d];
                        cycles--;
                        pc += 2;
                    }
                        break;
                    case LD8::A_HL_LD:
                    {
                        cycles = 19;
                        ram[iy + d] = ByteRegister::A_Reg_A;
                        cycles--;
                        pc += 2;
                    }
                        break;
                    case LD8::B_HL_LD:
                    {
                        cycles = 19;
                        ram[iy + d] = ByteRegister::B_Reg_A;
                        cycles--;
                        pc += 2;
                    }
                        break;
                    case LD8::C_HL_LD:
                    {
                        cycles = 19;
                        ram[iy + d] = ByteRegister::C_Reg_A;
                        cycles--;
                        pc += 2;
                    }
                        break;
                    case LD8::D_HL_LD:
                    {
                        cycles = 19;
                        ram[iy + d] = ByteRegister::D_Reg_A;
                        cycles--;
                        pc += 2;
                    }
                        break;
                    case LD8::E_HL_LD:
                    {
                        cycles = 19;
                        ram[iy + d] = ByteRegister::E_Reg_A;
                        cycles--;
                        pc += 2;
                    }
                        break;
                    case LD8::H_HL_LD:
                    {
                        cycles = 19;
                        ram[iy + d] = ByteRegister::H_Reg_A;
                        cycles--;
                        pc += 2;
                    }
                        break;
                    case LD8::L_HL_LD:
                    {
                        cycles = 19;
                        ram[iy + d] = ByteRegister::L_Reg_A;
                        cycles--;
                        pc += 2;
                    }
                        break;
                    case LD16::HL_nn_LD:
                    {
                        cycles = 20;

                        std::uint32_t location = readWord(pc + 2);

                        Byte highByte = (iy >> BYTE_SHIFT_ALIGNMENT) & MAX_BYTE_SIZE;
                        Byte lowByte  = iy & MAX_BYTE_SIZE;

                        ram[location + 1] = highByte;
                        ram[location]     = lowByte;

                        cycles--;
                        pc += 2;

                    }
                        break;
                    case LD16::nn_HL_LD_EXT:
                    {
                        cycles = 20;

                        std::uint32_t location = readWord(pc + 2);

                        Byte IByte = (iy >> BYTE_SHIFT_ALIGNMENT) & MAX_BYTE_SIZE;
                        Byte YByte = iy & MAX_BYTE_SIZE;

                        IByte = ram[location + 1];
                        YByte = ram[location];

                        iy = bytesToWord(IByte, YByte);

                        cycles--;
                        pc += 2;
                    }
                        break;

                }
            }
                break;
                // ED Prefixed Opcodes
            case LD8::ED_PREFIX:
            {
                switch (ram[pc + 1])
                {
                    case LD8::I_A_LD:
                    {
                        cycles                = 9;
                        ByteRegister::A_Reg_A = I;

                        (I & 0x80) != 0 ? flag.S = 1 : flag.S = 0; // Two's complement, S
                        (I == 0) ? flag.Z = 1 : flag.Z = 0; // Z
                        flag.H = 0; // H
                        flag.P = IFF2; // P
                        flag.N = 0; // N
                        // C flag not affected
                        cycles--;
                        pc += 2;
                    }
                        break;
                    case LD8::R_A_LD:
                    {
                        cycles                = 9;
                        ByteRegister::A_Reg_A = R;

                        (R & 0x80) != 0 ? flag.S = 1 : flag.S = 0; // Two's complement, S
                        (R == 0) ? flag.Z = 1 : flag.Z = 0; // Z
                        flag.H = 0; // H
                        flag.P = IFF2; // P
                        flag.N = 0; // N
                        // C is not affected
                        cycles--;
                        pc += 2;
                    }
                        break;
                    case LD8::A_I_LD:
                    {
                        cycles = 9;
                        I      = ByteRegister::A_Reg_A;

                        cycles--;
                        pc += 2;
                    }
                        break;
                    case LD8::A_R_LD:
                    {
                        cycles = 9;
                        R      = ByteRegister::A_Reg_A;

                        cycles--;
                        pc += 2;
                    }
                        break;
                    case LD16::ED_BC_nn_LD:
                    {
                        cycles = 20;

                        std::uint32_t location = readWord(pc + 2);

                        ram[location + 1] = ByteRegister::B_Reg_A;
                        ram[location]     = ByteRegister::C_Reg_A;

                        cycles--;
                        pc += 2;
                    }
                        break;
                    case LD16::ED_DE_nn_LD:
                    {
                        cycles = 20;

                        std::uint32_t location = readWord(pc + 2);

                        ram[location + 1] = ByteRegister::D_Reg_A;
                        ram[location]     = ByteRegister::E_Reg_A;

                        cycles--;
                        pc += 2;
                    }
                        break;
                    case LD16::ED_SP_nn_LD:
                    {
                        cycles = 20;

                        std::uint32_t location = readWord(pc + 2);

                        Byte S = (sp >> BYTE_SHIFT_ALIGNMENT) & MAX_BYTE_SIZE;
                        Byte P = sp & MAX_BYTE_SIZE;

                        ram[location + 1] = S;
                        ram[location]     = P;

                        cycles--;
                        pc += 2;
                    }
                        break;
                    case LD16::ED_nn_BC_LD:
                    {
                        cycles = 20;

                        std::uint32_t location = readWord(pc + 2);

                        ByteRegister::B_Reg_A = ram[location + 1];
                        ByteRegister::C_Reg_A = ram[location];

                        cycles--;
                        pc += 2;
                    }
                        break;
                    case LD16::ED_nn_DE_LD:
                    {
                        cycles = 20;

                        std::uint32_t location = readWord(pc + 2);

                        ByteRegister::D_Reg_A = ram[location + 1];
                        ByteRegister::E_Reg_A = ram[location];

                        cycles--;
                        pc += 2;
                    }
                        break;
                    case LD16::ED_nn_SP_LD:
                    {
                        cycles = 20;

                        std::uint32_t location = readWord(pc + 2);

                        Byte S = (sp >> BYTE_SHIFT_ALIGNMENT) & MAX_BYTE_SIZE;
                        Byte P = sp & MAX_BYTE_SIZE;

                        S = ram[location + 1];
                        P = ram[location];

                        sp = bytesToWord(S, P);

                        cycles--;
                        pc += 2;
                    }
                        break;

                }
            }
                break;
            case LD16::nn_BC_LD:
            {
                cycles                = 10;
                ByteRegister::B_Reg_A = ram[pc + 2];
                ByteRegister::C_Reg_A = ram[pc + 1];

                cycles--;
                pc += 2;

            }
                break;
            case LD16::nn_DE_LD:
            {
                cycles                = 10;
                ByteRegister::D_Reg_A = ram[pc + 2];
                ByteRegister::E_Reg_A = ram[pc + 1];

                cycles--;
                pc += 2;
            }
                break;
            case LD16::nn_HL_LD:
            {
                cycles                = 10;
                ByteRegister::H_Reg_A = ram[pc + 2];
                ByteRegister::L_Reg_A = ram[pc + 1];

                cycles--;
                pc += 2;
            }
                break;
            case LD16::nn_SP_LD:
            {
                cycles = 10;
                sp     = readWord(pc + 1);

                cycles--;
                pc += 2;
            }
                break;
            case Pop::POP_BC:
            {
                cycles = 10;

                ByteRegister::C_Reg_A = ram[Z80CPU::sp++];
                ByteRegister::B_Reg_A = ram[Z80CPU::sp++];

                cycles--;
                pc += 2;
            }
                break;
            case Pop::POP_DE:
            {
                cycles = 10;

                ByteRegister::E_Reg_A = ram[Z80CPU::sp++];
                ByteRegister::D_Reg_A = ram[Z80CPU::sp++];

                cycles--;
                pc += 2;
            }
                break;
            case Pop::POP_HL:
            {
                cycles = 10;

                ByteRegister::L_Reg_A = ram[Z80CPU::sp++];
                ByteRegister::H_Reg_A = ram[Z80CPU::sp++];

                cycles--;
                pc += 2;
            }
                break;
            case Pop::POP_AF:
            {
                cycles = 10;

                ByteRegister::F_Reg_A = ram[Z80CPU::sp++];
                ByteRegister::A_Reg_A = ram[Z80CPU::sp++];

                cycles--;
                pc += 2;
            }
                break;
            case LD16::HL_SP_LD:
            {
                cycles = 6;

                sp = HLasWord();

                cycles--;
                pc += 2;
            }
                break;
            case Push::PUSH_BC:
            {
                cycles = 11;

                pushWord(BCasWord());

                cycles--;
                pc += 2;
            }
                break;
            case Push::PUSH_DE:
            {
                cycles = 11;

                pushWord(DEasWord());

                cycles--;
                pc += 2;
            }
                break;
            case Push::PUSH_HL:
            {
                cycles = 11;

                pushWord(HLasWord());

                cycles--;
                pc += 2;
            }
                break;
            case Push::PUSH_AF:
            {
                cycles = 11;

                pushWord(AFasWord());

                cycles--;
                pc += 2;
            }
                break;
            case LD16::nn_HL_LD_EXT:
            {
                cycles = 16;
                std::uint32_t location = readWord(pc + 1);

                ByteRegister::H_Reg_A = ram[location + 1];
                ByteRegister::L_Reg_A = ram[location];

                cycles--;
                pc += 2;
            }
                break;
            case LD16::HL_nn_LD:
            {
                cycles = 16;

                std::uint32_t location = readWord(pc + 1);

                ram[location + 1] = ByteRegister::H_Reg_A;
                ram[location]     = ByteRegister::L_Reg_A;

                cycles--;
                pc += 2;
            }
                break;

        }

    }
}




