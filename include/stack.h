#pragma once

#include "memory.h"

struct Stack
{
public:
  void push_byte(Byte byte);
  void push_word(Word word);

  Word pop_word();
};

