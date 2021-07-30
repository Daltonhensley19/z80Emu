#include "../../include/load_rom.h"
#include <fstream>

#include "../../include/fmt/core.h"

#include "../../include/memory.h"

// load_rom() will allow us to load a test ROM
// into z80 RAM.
bool util::load_rom(const char* file_path)
{
  // Check if file_path is given.
  if (file_path == nullptr)
    return false;

  // Open a input file in binary mode, starting at the end of file.
  std::ifstream infile(file_path, std::ios::binary | std::ios::ate);

  // Check to see if infile is created correctly.
  // Abort if invalid file path id given.
  if (!infile.good())
  {
    fmt::print("Error! Unable to load rom: {}\n", file_path);

    return false;
  }
  else
  {

    // Get size of test ROM, read position
    // is located at end of file initally.
    // We then allocate space dynamically on the heap
    // using `rom_size.`
    std::streampos rom_size = infile.tellg();
    char* rom_buffer        = new char[rom_size];

    // We then move the file's read position
    // to the beginning. Then, we store the infile data
    // into the `rom_buffer,` closing `infile.`
    infile.seekg(0, std::ios::beg);
    infile.read(rom_buffer, rom_size);
    infile.close();

    // Load the test ROM into z80 RAM.
    for (int i = 0; i < rom_size; i++)
    {
      ram[i] = (Byte)rom_buffer[i];
    }

    // Free allocated space.
    delete[] rom_buffer;
  }

  return true;
}
