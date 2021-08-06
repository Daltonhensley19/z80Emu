#pragma once

#include "emuTypes.h"

// 8-Bit Load Group (LD)
struct LD8
{

  // NOTE: Format is register (source) to register (destination).
  const static Word A_A_LD = 0x7F;
  const static Word B_A_LD = 0x78;
  const static Word C_A_LD = 0x79;
  const static Word D_A_LD = 0x7A;
  const static Word E_A_LD = 0x7B;
  const static Word H_A_LD = 0x7C;
  const static Word L_A_LD = 0x7D;

  const static Word A_B_LD = 0x47;
  const static Word B_B_LD = 0x40;
  const static Word C_B_LD = 0x41;
  const static Word D_B_LD = 0x42;
  const static Word E_B_LD = 0x43;
  const static Word H_B_LD = 0x44;
  const static Word L_B_LD = 0x45;

  const static Word A_C_LD = 0x4F;
  const static Word B_C_LD = 0x48;
  const static Word C_C_LD = 0x49;
  const static Word D_C_LD = 0x4A;
  const static Word E_C_LD = 0x4B;
  const static Word H_C_LD = 0x4C;
  const static Word L_C_LD = 0x4D;

  const static Word A_D_LD = 0x57;
  const static Word B_D_LD = 0x50;
  const static Word C_D_LD = 0x51;
  const static Word D_D_LD = 0x52;
  const static Word E_D_LD = 0x53;
  const static Word H_D_LD = 0x54;
  const static Word L_D_LD = 0x55;

  const static Word A_E_LD = 0x5F;
  const static Word B_E_LD = 0x58;
  const static Word C_E_LD = 0x59;
  const static Word D_E_LD = 0x5A;
  const static Word E_E_LD = 0x5B;
  const static Word H_E_LD = 0x5C;
  const static Word L_E_LD = 0x5D;

  const static Word A_H_LD = 0x67;
  const static Word B_H_LD = 0x60;
  const static Word C_H_LD = 0x61;
  const static Word D_H_LD = 0x62;
  const static Word E_H_LD = 0x63;
  const static Word H_H_LD = 0x64;
  const static Word L_H_LD = 0x65;

  const static Word A_L_LD = 0x6F;
  const static Word B_L_LD = 0x68;
  const static Word C_L_LD = 0x69;
  const static Word D_L_LD = 0x6A;
  const static Word E_L_LD = 0x6B;
  const static Word H_L_LD = 0x6C;
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

  // Indexed (NOTE: Indexed is source [IDX or IDY] to generic register [R], A B
  // C D E F L, which is the destination.
  const static Word IDX_R_LD = 0xDD;
  const static Word IDY_R_LD = 0xFD;

  // Extended to register
  const static Word nn_A_LD = 0x3A;

  // Implied to register
  const static Word I_A_LD = 0x57; // Prefixed with ED
  const static Word R_A_LD = 0x5F; // Prefixed with ED

  const static Word ED_PREFIX = 0xED;

  // Register to HL
  const static Word A_HL_LD = 0x77;
  const static Word B_HL_LD = 0x70;
  const static Word C_HL_LD = 0x71;
  const static Word D_HL_LD = 0x72;
  const static Word E_HL_LD = 0x73;
  const static Word H_HL_LD = 0x74;
  const static Word L_HL_LD = 0x75;

  // Register to register indirect (BC and DE)
  const static Word A_BC_LD = 0x02;
  const static Word A_DE_LD = 0x12;

  // Register to Ext. Addr.
  const static Word A_nn_LD = 0x32;

  // Register to implied
  const static Word A_I_LD = 0x47; // Prefixed with ED
  const static Word A_R_LD = 0x4F; // Prefixed with ED

  // Imm. to register indirect
  const static Word n_HL_LD = 0x36;

  // NOTE: remember to think about the opcode
  // prefixes (DE, CB, DD, FD)
};

struct LD16
{
  /* This starts the 16-bit load opcode table. */

  // Imm. Extended to Register pair

  const static Word nn_BC_LD = 0x01;
  const static Word nn_DE_LD = 0x11;
  const static Word nn_HL_LD = 0x21;
  const static Word nn_SP_LD = 0x31;

  // Ext. to register
  const static Word ED_nn_BC_LD = 0x4B; // Prefix: ED
  const static Word ED_nn_DE_LD = 0x5B; // Prefix: ED
  const static Word nn_HL_LD_EXT =
    0x2A;                               // NOTE: this is close to nn_HL_LD above
  const static Word ED_nn_SP_LD = 0x7B; // Prefix: ED

  // Register to extended
  const static Word ED_BC_nn_LD = 0x43; // Prefix: ED
  const static Word ED_DE_nn_LD = 0x53; // Prefix: ED
  const static Word HL_nn_LD    = 0x22;
  const static Word ED_SP_nn_LD = 0x73; // Prefix: ED

  // Register to register
  const static Word HL_SP_LD = 0xF9;
};

// Pop opcodes (found in the table with 16-bit load)
struct Pop
{
  const static Word POP_AF = 0xF1;
  const static Word POP_BC = 0xC1;
  const static Word POP_DE = 0xD1;
  const static Word POP_HL = 0xE1;
};

// Push opcodes (found in the table with 16-bit load)
struct Push
{
  const static Word PUSH_AF = 0xF5;
  const static Word PUSH_BC = 0xC5;
  const static Word PUSH_DE = 0xD5;
  const static Word PUSH_HL = 0xE5;
};

// Exchange opcode group
struct Ex
{

  const static Word AFPRIME_AF     = 0x08;
  const static Word PAIRPRIME_PAIR = 0xD9;
  const static Word HL_SP          = 0xE3;
  const static Word HL_DE          = 0xEB;
};

// Call opcode group
/*         cc     * Condition          * Flag
 * *
 *         * 000  * Non-Zero (NZ)      * Z
 *         * 001  * Zero (Z)           * Z
 *         * 010  * Non Carry (NC)     * C
 *         * 011  * Carry (C)          * Z
 *         * 100  * Parity Odd (PO)    * P/V
 *         * 101  * Parity Even (PE)   * P/V
 *         * 110  * Sign Positive (P)  * S
 *         * 111  * Sign Negative (M)  * S */
struct Call
{
  const static Word UNCON_CALL    = 0xCD;
  const static Word CARRY_CALL    = 0xDC;
  const static Word NONCARRY_CALL = 0xD4;
  const static Word ZERO_CALL     = 0xCC;
  const static Word NONZERO_CALL  = 0xC4;
  const static Word EVEN_CALL     = 0xEC;
  const static Word ODD_CALL      = 0xE4;
  const static Word NEG_CALL      = 0xFC;
  const static Word POS_CALL      = 0xF4;
};

// Call opcode group
/*         cc     * Condition          * Flag
 * *
 *         * 000  * Non-Zero (NZ)      * Z
 *         * 001  * Zero (Z)           * Z
 *         * 010  * Non Carry (NC)     * C
 *         * 011  * Carry (C)          * Z
 *         * 100  * Parity Odd (PO)    * P/V
 *         * 101  * Parity Even (PE)   * P/V
 *         * 110  * Sign Positive (P)  * S
 *         * 111  * Sign Negative (M)  * S */
// Jump opcode group.
struct Jump
{
  const static Word UNCON_JP    = 0xC3;
  const static Word CARRY_JP    = 0xD8;
  const static Word NONCARRY_JP = 0xD2;
  const static Word ZERO_JP     = 0xCA;
  const static Word NONZERO_JP  = 0xC2;
  const static Word EVEN_JP     = 0xEA;
  const static Word ODD_JP      = 0xE2;
  const static Word NEG_JP      = 0xFA;
  const static Word POS_JP      = 0xF2;

  const static Word UNCON_JR    = 0x18;
  const static Word CARRY_JR    = 0x38;
  const static Word NONCARRY_JR = 0x30;
  const static Word ZERO_JR     = 0x28;
  const static Word NONZERO_JR  = 0x20;
};
