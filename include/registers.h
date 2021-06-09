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

    // Main register set
    inline static Byte A_Reg_A;
    inline static Byte B_Reg_A;
    inline static Byte D_Reg_A;
    inline static Byte H_Reg_A;

    inline static Byte F_Reg_A;
    inline static Byte C_Reg_A;
    inline static Byte E_Reg_A;
    inline static Byte L_Reg_A;

    // Alternate register set
    inline static Byte A_Reg_B;
    inline static Byte B_Reg_B;
    inline static Byte D_Reg_B;
    inline static Byte H_Reg_B;

    inline static Byte F_Reg_B;
    inline static Byte C_Reg_B;
    inline static Byte E_Reg_B;
    inline static Byte L_Reg_B;
};

Word BCasWord();


Word AFasWord();


Word DEasWord();


Word HLasWord();

