#pragma once

#include "memory.h"

struct Stack
{
public:
    void pushByte(Byte byte);
    void pushWord(Word word);

    Word popWord();


};

