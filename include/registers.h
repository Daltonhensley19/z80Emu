#pragma once

#include "emuTypes.h"


struct FlagBitField
{
    Byte C: 1; // Carry Flag
    Byte N: 1; // Add/Subtract Flag
    // Parity/Overflow Flag
    union
    {
        Byte P: 1;
        Byte V: 1;
    };
    Byte X: 1; // Not Used
    Byte H: 1; // Half Carry Flag
    Byte Z: 1; // Zero Flag
    Byte S: 1; // Sign Flag
};


struct ByteRegister
{
    static Byte A_Reg_A;
    static Byte B_Reg_A;
    static Byte D_Reg_A;
    static Byte H_Reg_A;

    static Byte F_Reg_A;
    static Byte C_Reg_A;
    static Byte E_Reg_A;
    static Byte L_Reg_A;

    static Byte A_Reg_B;
    static Byte B_Reg_B;
    static Byte D_Reg_B;
    static Byte H_Reg_B;

    static Byte F_Reg_B;
    static Byte C_Reg_B;
    static Byte E_Reg_B;
    static Byte L_Reg_B;
};

