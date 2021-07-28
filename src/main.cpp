#define FMT_HEADER_ONLY 1

#include "../include/fmt/core.h"
#include "../include/memory.h"
#include "../include/registers.h"
#include "../include/z80.h"

#include "../include/debugger.h"

#include "../include/timer.h"

int main()
{

  // Z80CPU cpu{};

  //  cpu.executeInstruction();
  Timer stop_watch{};

  stop_watch.start();

  for (int i = 0; i < 10000000; i++)
  {
    fmt::print("{}\n", i);
  }
  stop_watch.stop();
  stop_watch.timer_duration();

  return 0;
}

