#pragma once
#include "emuTypes.h"


// 8-Bit Load Group (LD)
enum LD8
{
    // NOTE: Format is register (source) to register (destination).
    A_A_LD = 0x7F;
    B_A_LD = 0x78;
    C_A_LD = 0x79;
    D_A_LD = 0x7A;
    E_A_LD = 0x7B;
    F_A_LD = 0x7C;
    L_A_LD = 0x7D;

    A_B_LD = 0x47;
    B_B_LD = 0x40;
    C_B_LD = 0x41;
    D_B_LD = 0x42;
    E_B_LD = 0x43;
    F_B_LD = 0x44;
    L_B_LD = 0x45;

    A_C_LD = 0x4F;
    B_C_LD = 0x48;
    C_C_LD = 0x49;
    D_C_LD = 0x4A;
    E_C_LD = 0x4B;
    F_C_LD = 0x4C;
    L_C_LD = 0x4D;


    A_D_LD = 0x57;
    B_D_LD = 0x50;
    C_D_LD = 0x51;
    D_D_LD = 0x52;
    E_D_LD = 0x53;
    F_D_LD = 0x54;
    L_D_LD = 0x55;

    A_E_LD = 0x5F;
    B_E_LD = 0x58;
    C_E_LD = 0x59;
    D_E_LD = 0x5A;
    E_E_LD = 0x5B;
    F_E_LD = 0x5C;
    L_E_LD = 0x5D;

    A_H_LD = 0x67;
    B_H_LD = 0x60;
    C_H_LD = 0x61;
    D_H_LD = 0x62;
    E_H_LD = 0x63;
    F_H_LD = 0x64;
    L_H_LD = 0x65;

    A_L_LD = 0x6F;
    B_L_LD = 0x68;
    C_L_LD = 0x69;
    D_L_LD = 0x6A;
    E_L_LD = 0x6B;
    F_L_LD = 0x6C;
    L_L_LD = 0x6D;


};