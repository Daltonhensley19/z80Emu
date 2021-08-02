#define FMT_HEADER_ONLY 1

#include "../include/fmt/core.h"
#include "../include/memory.h"
#include "../include/registers.h"
#include "../include/z80.h"

#include "../include/load_rom.h"
#include "../include/timer.h"

int main(int argc, char** argv)
{

  if (argc != 2)
  {
    fmt::print("Error! Invaild number of arguments.\nExpected a path to binary "
               "test rom.\n");

    // Spit error code.
    return -1;
  }
  else
  {
    util::load_rom(argv[1]);
  }

  Z80CPU cpu{};

  cpu.execute_instruction();

  return 0;
}

