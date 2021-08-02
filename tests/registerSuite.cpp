#include "../include/doctest.h"
#include "../include/registers.h"


TEST_CASE("Testing BCasWord function.")
{
    GIVEN("Register B and C, with dummy test values.")
    {
        ByteRegister::B_Reg_A = 0xA;
        ByteRegister::C_Reg_A = 0xB;

        WHEN("Function BCasWord is called.")
        {
            THEN("Function returns expected value.")
            {
                CHECK(bc_as_word() == 2571);
            }
        }
    }
}

TEST_CASE("Testing HLasWord function.")
{
    GIVEN("Register H and L, with dummy test values.")
    {
        ByteRegister::H_Reg_A = 0xA;
        ByteRegister::L_Reg_A = 0xB;

        WHEN("Function HLasWord is called.")
        {
            THEN("Function returns expected value.")
            {
                CHECK(hl_as_word() == 2571);
            }
        }
    }
}

TEST_CASE("Testing AFasWord function.")
{
    GIVEN("Register A and F, with dummy test values.")
    {
        ByteRegister::A_Reg_A = 0xA;
        ByteRegister::F_Reg_A = 0xB;

        WHEN("Function AFasWord is called.")
        {
            THEN("Function returns expected value.")
            {
                CHECK(af_as_word() == 2571);
            }
        }
    }
}

TEST_CASE("Testing DEasWord function.")
{
    GIVEN("Register D and E, with dummy test values.")
    {
        ByteRegister::D_Reg_A = 0xA;
        ByteRegister::E_Reg_A = 0xB;

        WHEN("Function DEasWord is called.")
        {
            THEN("Function returns expected value.")
            {
                CHECK(de_as_word() == 2571);
            }
        }
    }
}
