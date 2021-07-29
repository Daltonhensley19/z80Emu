#include "../../include/load_rom.h"
#include <fstream>


#include "../../include/fmt/core.h"

#include "../../include/memory.h"

bool util::load_rom(const char* file_path)
{
  if (file_path == nullptr)
    return false;

  std::ifstream infile(file_path, std::ios::binary | std::ios::ate);

  if (!infile.good())
  {
    fmt::print("Error! Unable to load rom: {}\n", file_path);

    return false;
  }
  else
  {
    std::streampos rom_size = infile.tellg();
    char* rom_buffer        = new char[rom_size];

    infile.seekg(0, std::ios::beg);
    infile.read(rom_buffer, rom_size);
    infile.close();

    for (int i = 0; i < rom_size; i++)
    {
      ram[i] = (Byte)rom_buffer[i];
    }

    delete[] rom_buffer;
  }

  return true;
}
