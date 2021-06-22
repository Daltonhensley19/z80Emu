#pragma once

#include "memory.h"

class Stack
{
public:
    void pushByte(Byte byte);
    void pushWord(Word word);

    Word popWord();

};

