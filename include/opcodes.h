#pragma once

#include "emuTypes.h"


// 8-Bit Load Group (LD)
class LD8
{
public:
    //TODO(Dalton): Add prefixes to opcodes in 8-bit table.

    // NOTE: Format is register (source) to register (destination).
    const static Word A_A_LD = 0x7F;
    const static Word B_A_LD = 0x78;
    const static Word C_A_LD = 0x79;
    const static Word D_A_LD = 0x7A;
    const static Word E_A_LD = 0x7B;
    const static Word F_A_LD = 0x7C;
    const static Word L_A_LD = 0x7D;

    const static Word A_B_LD = 0x47;
    const static Word B_B_LD = 0x40;
    const static Word C_B_LD = 0x41;
    const static Word D_B_LD = 0x42;
    const static Word E_B_LD = 0x43;
    const static Word F_B_LD = 0x44;
    const static Word L_B_LD = 0x45;

    const static Word A_C_LD = 0x4F;
    const static Word B_C_LD = 0x48;
    const static Word C_C_LD = 0x49;
    const static Word D_C_LD = 0x4A;
    const static Word E_C_LD = 0x4B;
    const static Word F_C_LD = 0x4C;
    const static Word L_C_LD = 0x4D;

    const static Word A_D_LD = 0x57;
    const static Word B_D_LD = 0x50;
    const static Word C_D_LD = 0x51;
    const static Word D_D_LD = 0x52;
    const static Word E_D_LD = 0x53;
    const static Word F_D_LD = 0x54;
    const static Word L_D_LD = 0x55;

    const static Word A_E_LD = 0x5F;
    const static Word B_E_LD = 0x58;
    const static Word C_E_LD = 0x59;
    const static Word D_E_LD = 0x5A;
    const static Word E_E_LD = 0x5B;
    const static Word F_E_LD = 0x5C;
    const static Word L_E_LD = 0x5D;

    const static Word A_H_LD = 0x67;
    const static Word B_H_LD = 0x60;
    const static Word C_H_LD = 0x61;
    const static Word D_H_LD = 0x62;
    const static Word E_H_LD = 0x63;
    const static Word F_H_LD = 0x64;
    const static Word L_H_LD = 0x65;

    const static Word A_L_LD = 0x6F;
    const static Word B_L_LD = 0x68;
    const static Word C_L_LD = 0x69;
    const static Word D_L_LD = 0x6A;
    const static Word E_L_LD = 0x6B;
    const static Word F_L_LD = 0x6C;
    const static Word L_L_LD = 0x6D;

    // LD Immediate to register
    const static Word n_A_LD = 0x3E;
    const static Word n_B_LD = 0x06;
    const static Word n_C_LD = 0x0E;
    const static Word n_D_LD = 0x16;
    const static Word n_E_LD = 0x1E;
    const static Word n_H_LD = 0x26;
    const static Word n_L_LD = 0x2E;

    // Reg indirect to register
    const static Word HL_A_LD = 0x7E;
    const static Word HL_B_LD = 0x46;
    const static Word HL_C_LD = 0x4E;
    const static Word HL_D_LD = 0x56;
    const static Word HL_E_LD = 0x5E;
    const static Word HL_H_LD = 0x66;
    const static Word HL_L_LD = 0x6E;

    // Reg indirect to register
    const static Word BC_A_LD = 0x0A;
    const static Word DE_A_LD = 0x1A;

    // Indexed (NOTE: Indexed is source [IDX or IDY] to generic register [R], A B C D E F L,
    // which is the destination.
    const static Word IDX_R_LD = 0xDD;
    const static Word IDY_R_LD = 0xFD;

    // Extended to register
    const static Word nn_A_LD = 0x3A;

    // Implied to register
    const static Word I_A_LD = 0x57;
    const static Word R_A_LD = 0x5F;


    // Register to HL
    const static Word A_HL_LD = 0x77;
    const static Word B_HL_LD = 0x70;
    const static Word C_HL_LD = 0x71;
    const static Word D_HL_LD = 0x72;
    const static Word E_HL_LD = 0x73;
    const static Word F_HL_LD = 0x74;
    const static Word L_HL_LD = 0x75;

    // Register to register indirect (BC and DE)
    const static Word A_BC_LD = 0x02;
    const static Word A_DE_LD = 0x12;

    // Register to Ext. Addr.
    const static Word A_nn_LD = 0x32;

    // Register to implied
    const static Word A_I_LD = 0x47;
    const static Word A_R_LD = 0x4F;

    const static Word FD_nn_IY_ = 0x21; // Prefix: FD

    // Imm. to register indirect
    const static Word n_HL_LD = 0x36;


    // NOTE: remember to think about the opcode
    // prefixes (DE, CB, DD, FD)


};

class LD16
{
public:
    /* This starts the 16-bit load opcode table. */

// Imm. Extended to Register pair

    const static Word nn_BC_LD = 0x01;
    const static Word nn_DE_LD = 0x11;
    const static Word nn_HL_LD = 0x21;
    const static Word nn_SP_LD = 0x31;
    const static Word DD_nn_IX = 0x21; // Prefix: DD
    const static Word FD_nn_IY = 0x21; // Prefix: FD

// Ext. to register
    const static Word ED_nn_BC_LD  = 0x4B; // Prefix: ED
    const static Word ED_nn_DE_LD  = 0x5B; // Prefix: ED
    const static Word nn_HL_LD_EXT = 0x2A; // NOTE: this is close to nn_HL_LD above
    const static Word ED_nn_SP_LD  = 0x7B; // Prefix: ED
    const static Word DD_nn_IX_LD  = 0x2A; // Prefix: DD
    const static Word FD_nn_IY_LD  = 0x2A; // Prefix: FD

    // Register to extended
    const static Word ED_BC_nn_LD = 0x43; // Prefix: ED
    const static Word ED_DE_nn_LD = 0x53; // Prefix: ED
    const static Word HL_nn_LD    = 0x22;
    const static Word ED_SP_nn_LD = 0x73; // Prefix: ED
    const static Word DD_IX_nn_LD = 0x22; // Prefix: DD
    const static Word FD_IY_nn_LD = 0x22; // Prefix: FD

    // Register to register
    const static Word HL_SP_LD    = 0xF9;
    const static Word DD_IX_SP_LD = 0xF9; // Prefix: DD
    const static Word FD_IY_SP_LD = 0xF9; // Prefix: FD

};

class Pop
{
public:
    // Push opcodes (found in the table with 16-bit load)
    const static Word POP_AF    = 0xF1;
    const static Word POP_BC    = 0xC1;
    const static Word POP_DE    = 0xD1;
    const static Word POP_HL    = 0xE1;
    const static Word POP_DD_IX = 0xE1; // Prefix: DD
    const static Word POP_FD_IY = 0xE1; // Prefix: FD
};

class Push
{
public:
    const static Word PUSH_AF     = 0xF5;
    const static Word PUSH_BC     = 0xC5;
    const static Word PUSH_DE     = 0xD5;
    const static Word PUSH_HL     = 0xE5;
    const static Word PUSH_DD_IX  = 0xE5; //Prefix: DD
    const static Word PUSH__FD_IY = 0xE5; // Prefix: FD
};