#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN 1

#include "doctest.h"
#include "../include/memory.h"


TEST_CASE("testing the readByte function")
{
    GIVEN("A byte to read from RAM...")
    {

        Word location = 0xA;
        ram[location] = 0xB;
        Byte fetchedByte;
        WHEN("User chooses a location in memory to read...")
        {
            fetchedByte = readByte(location);
            THEN("Fetch Byte is correct!")
            {
                CHECK(fetchedByte == 0xB);
            }
        }

    }

}

TEST_CASE("testing the writeByte function")
{
    GIVEN("A byte to write to RAM...")
    {

        Word location = 0xA;
        Byte byteToWrite = 0xC;
        WHEN("User chooses a location of memory to write to...")
        {
            writeByte(byteToWrite, location);
            THEN("Byte is written to in a correct manner!")
            {
                CHECK(ram[location] == 0xC);
            }
        }

    }

}

TEST_CASE("testing the readWord function")
{
    GIVEN("A word to read from RAM...")
    {

        Word location = 0xA;
        Word fetchedWord;
        ram[location] = 0xC;
        WHEN("User chooses a location of memory to read word...")
        {
            fetchedWord = readWord(location);
            THEN("Fetch Word is correct!")
            {
                CHECK(fetchedWord == 0xC);
            }
        }

    }

}

TEST_CASE("testing the writeWord function")
{
    GIVEN("A word to write to RAM...")
    {

        Word location = 0xA;
        Word wordToWrite = 300;

        WHEN("User chooses a location of memory to write word...")
        {
            writeWord(wordToWrite, location);
            THEN("Word data was written correctly!")
            {
                // NOTE: Current Implementation is Little Endian!
                // 300 = 0b00000001 00101100
                CHECK(ram[location] == 44); //0b00101100 = 44
                CHECK(ram[location + 1] == 1); // 0b00000001 = 1
            }
        }

    }

}

TEST_CASE("testing the restMem function")
{
    GIVEN("A set of RAM")
    {

        Word location = 0xA;
        Word wordToWrite = 300;

        WHEN("writing data to RAM then testing reset mechanism..")
        {
            writeWord(wordToWrite, location);
            THEN("Word data was written correctly!")
            {
                // NOTE: Current Implementation is Little Endian!
                // 300 = 0b00000001 00101100
                CHECK(ram[location] == 44); //0b00101100 = 44
                CHECK(ram[location + 1] == 1); // 0b00000001 = 1
            }

            resetMem(ram);
            bool isCleared = true;

            // Note: we check here to see if RAM is clear
            // if any byte in RAM is nonzero, we set `isCleared` flag to false
            for (auto byte: ram)
            {
                if (byte != 0)
                {
                    isCleared = false;
                }
            }

            THEN("RAM cleared")
            {
                CHECK(isCleared == true);
            }
        }

    }

}


