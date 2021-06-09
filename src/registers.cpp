//
// Created by dalton on 6/8/21.
//
#include "../include/registers.h"
#include "../include/memory.h"

Word BCasWord()
{
    return ByteRegister::B_Reg_A << BYTE_SHIFT_ALIGNMENT | ByteRegister::C_Reg_A;
}

Word AFasWord()
{
    return ByteRegister::A_Reg_A << BYTE_SHIFT_ALIGNMENT | ByteRegister::F_Reg_A;
}

Word DEasWord()
{
    return ByteRegister::D_Reg_A << BYTE_SHIFT_ALIGNMENT | ByteRegister::E_Reg_A;
}

Word HLasWord()
{
    return ByteRegister::H_Reg_A << BYTE_SHIFT_ALIGNMENT | ByteRegister::L_Reg_A;
}

