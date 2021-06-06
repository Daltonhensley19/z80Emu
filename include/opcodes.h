#pragma once

#include "emuTypes.h"


// 8-Bit Load Group (LD)
enum LD8
{
    //TODO(Dalton): Add prefixes to opcodes in 8-bit table.

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
    L_C_LD = 0x4D

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

    // LD Immediate to register
    n_A_LD = 0x3E;
    n_B_LD = 0x06;
    n_C_LD = 0x0E;
    n_D_LD = 0x16;
    n_E_LD = 0x1E;
    n_H_LD = 0x26;
    n_L_LD = 0x2E;

    // Reg indirect to register
    HL_A_LD = 0x7E;
    HL_B_LD = 0x46;
    HL_C_LD = 0x4E;
    HL_D_LD = 0x56;
    HL_E_LD = 0x5E;
    HL_H_LD = 0x66;
    HL_L_LD = 0x6E;

    // Reg indirect to register
    BC_A_LD = 0x0A;
    DE_A_LD = 0x1A;

    // Indexed (NOTE: Indexed is source [IDX or IDY] to generic register [R], A B C D E F L,
    // which is the destination.
    IDX_R_LD = 0xDD;
    IDY_R_LD = 0xFD;

    // Extended to register
    nn_A_LD = 0x3A;

    // Implied to register
    I_A_LD = 0x57;
    R_A_LD = 0x5F;


    // Register to HL
    A_HL_LD = 0x77;
    B_HL_LD = 0x70;
    C_HL_LD = 0x71;
    D_HL_LD = 0x72;
    E_HL_LD = 0x73;
    F_HL_LD = 0x74;
    L_HL_LD = 0x75;

    // Register to register indirect (BC and DE)
    A_BC_LD = 0x02;
    A_DE_LD = 0x12;

    // Register to Ext. Addr.
    A_nn_LD = 0x32;

    // Register to implied
    A_I_LD = 0x47;
    A_R_LD = 0x4F;


    // Imm. to register indirect
    n_HL_LD = 0x36;


    // NOTE: remember to think about the opcode
    // prefixes (DE, CB, DD, FD)


};

enum LD16
{
    /* This starts the 16-bit load opcode table. */

// Imm. Extended to Register pair

    nn_BC_LD = 0x01;
    nn_DE_LD = 0x11;
    nn_HL_LD = 0x21;
    nn_SP_LD = 0x31;
    DD_nn_IX = 0x21; // Prefix: DD
    FD_nn_IY_ = 0x21; // Prefix: FD

// Ext. to register
    ED_nn_BC_LD = 0x4B; // Prefix: ED
    ED_nn_DE_LD = 0x5B; // Prefix: ED
    nn_HL_LD = 0x2A;
    ED_nn_SP_LD = 0x7B; // Prefix: ED
    DD_nn_IX_LD = 0x2A; // Prefix: DD
    FD_nn_IY_LD = 0x2A; // Prefix: FD

    // Register to extended
    ED_BC_nn_LD = 0x43; // Prefix: ED
    ED_DE_nn_LD = 0x53; // Prefix: ED
    HL_nn_LD = 0x22;
    ED_SP_nn_LD = 0x73; // Prefix: ED
    DD_IX_nn_LD = 0x22; // Prefix: DD
    FD_IY_nn_LD = 0x22; // Prefix: FD

    // Register to register
    HL_SP_LD = 0xF9;
    DD_IX_SP_LD = 0xF9; // Prefix: DD
    FD_IY_SP_LD = 0xF9; // Prefix: FD

};

enum Pop
{
    // Push opcodes (found in the table with 16-bit load)
    POP_AF = 0xF1;
    POP_BC = 0xC1;
    POP_DE = 0xD1;
    POP_HL = 0xE1;
    POP_DD_IX = 0xE1; // Prefix: DD
    POP_FD_IY = 0xE1; // Prefix: FD
};
enum Push
{
    PUSH_AF = 0xF5;
    PUSH_BC = 0xC5;
    PUSH_DE = 0xD5;
    PUSH_HL = 0xE5;
    PUSH_DD_IX = 0xE5; //Prefix: DD
    PUSH__FD_IY = 0xE5; // Prefix: FD
};