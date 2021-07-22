#define FMT_HEADER_ONLY 1

#include "../include/fmt/core.h"
#include "../include/memory.h"
#include "../include/registers.h"
#include "../include/z80.h"

#include "../include/debugger.h" 


int main()
{

    Z80CPU cpu{};

    cpu.executeInstruction();
  


  return 0;
}

