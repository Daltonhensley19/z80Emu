# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.21

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:

# Disable VCS-based implicit rules.
% : %,v

# Disable VCS-based implicit rules.
% : RCS/%

# Disable VCS-based implicit rules.
% : RCS/%,v

# Disable VCS-based implicit rules.
% : SCCS/s.%

# Disable VCS-based implicit rules.
% : s.%

.SUFFIXES: .hpux_make_needs_suffix_list

# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

#Suppress display of executed commands.
$(VERBOSE).SILENT:

# A target that is always out of date.
cmake_force:
.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/dalton/desktop/z80Emu2

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/dalton/desktop/z80Emu2/build

# Include any dependencies generated for this target.
include CMakeFiles/z80Emu.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/z80Emu.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/z80Emu.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/z80Emu.dir/flags.make

CMakeFiles/z80Emu.dir/src/main.cpp.o: CMakeFiles/z80Emu.dir/flags.make
CMakeFiles/z80Emu.dir/src/main.cpp.o: ../src/main.cpp
CMakeFiles/z80Emu.dir/src/main.cpp.o: CMakeFiles/z80Emu.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/dalton/desktop/z80Emu2/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/z80Emu.dir/src/main.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/z80Emu.dir/src/main.cpp.o -MF CMakeFiles/z80Emu.dir/src/main.cpp.o.d -o CMakeFiles/z80Emu.dir/src/main.cpp.o -c /home/dalton/desktop/z80Emu2/src/main.cpp

CMakeFiles/z80Emu.dir/src/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/z80Emu.dir/src/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/dalton/desktop/z80Emu2/src/main.cpp > CMakeFiles/z80Emu.dir/src/main.cpp.i

CMakeFiles/z80Emu.dir/src/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/z80Emu.dir/src/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/dalton/desktop/z80Emu2/src/main.cpp -o CMakeFiles/z80Emu.dir/src/main.cpp.s

CMakeFiles/z80Emu.dir/src/z80.cpp.o: CMakeFiles/z80Emu.dir/flags.make
CMakeFiles/z80Emu.dir/src/z80.cpp.o: ../src/z80.cpp
CMakeFiles/z80Emu.dir/src/z80.cpp.o: CMakeFiles/z80Emu.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/dalton/desktop/z80Emu2/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/z80Emu.dir/src/z80.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/z80Emu.dir/src/z80.cpp.o -MF CMakeFiles/z80Emu.dir/src/z80.cpp.o.d -o CMakeFiles/z80Emu.dir/src/z80.cpp.o -c /home/dalton/desktop/z80Emu2/src/z80.cpp

CMakeFiles/z80Emu.dir/src/z80.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/z80Emu.dir/src/z80.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/dalton/desktop/z80Emu2/src/z80.cpp > CMakeFiles/z80Emu.dir/src/z80.cpp.i

CMakeFiles/z80Emu.dir/src/z80.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/z80Emu.dir/src/z80.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/dalton/desktop/z80Emu2/src/z80.cpp -o CMakeFiles/z80Emu.dir/src/z80.cpp.s

CMakeFiles/z80Emu.dir/src/registers.cpp.o: CMakeFiles/z80Emu.dir/flags.make
CMakeFiles/z80Emu.dir/src/registers.cpp.o: ../src/registers.cpp
CMakeFiles/z80Emu.dir/src/registers.cpp.o: CMakeFiles/z80Emu.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/dalton/desktop/z80Emu2/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/z80Emu.dir/src/registers.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/z80Emu.dir/src/registers.cpp.o -MF CMakeFiles/z80Emu.dir/src/registers.cpp.o.d -o CMakeFiles/z80Emu.dir/src/registers.cpp.o -c /home/dalton/desktop/z80Emu2/src/registers.cpp

CMakeFiles/z80Emu.dir/src/registers.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/z80Emu.dir/src/registers.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/dalton/desktop/z80Emu2/src/registers.cpp > CMakeFiles/z80Emu.dir/src/registers.cpp.i

CMakeFiles/z80Emu.dir/src/registers.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/z80Emu.dir/src/registers.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/dalton/desktop/z80Emu2/src/registers.cpp -o CMakeFiles/z80Emu.dir/src/registers.cpp.s

CMakeFiles/z80Emu.dir/src/memory.cpp.o: CMakeFiles/z80Emu.dir/flags.make
CMakeFiles/z80Emu.dir/src/memory.cpp.o: ../src/memory.cpp
CMakeFiles/z80Emu.dir/src/memory.cpp.o: CMakeFiles/z80Emu.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/dalton/desktop/z80Emu2/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/z80Emu.dir/src/memory.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/z80Emu.dir/src/memory.cpp.o -MF CMakeFiles/z80Emu.dir/src/memory.cpp.o.d -o CMakeFiles/z80Emu.dir/src/memory.cpp.o -c /home/dalton/desktop/z80Emu2/src/memory.cpp

CMakeFiles/z80Emu.dir/src/memory.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/z80Emu.dir/src/memory.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/dalton/desktop/z80Emu2/src/memory.cpp > CMakeFiles/z80Emu.dir/src/memory.cpp.i

CMakeFiles/z80Emu.dir/src/memory.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/z80Emu.dir/src/memory.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/dalton/desktop/z80Emu2/src/memory.cpp -o CMakeFiles/z80Emu.dir/src/memory.cpp.s

CMakeFiles/z80Emu.dir/src/stack.cpp.o: CMakeFiles/z80Emu.dir/flags.make
CMakeFiles/z80Emu.dir/src/stack.cpp.o: ../src/stack.cpp
CMakeFiles/z80Emu.dir/src/stack.cpp.o: CMakeFiles/z80Emu.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/dalton/desktop/z80Emu2/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/z80Emu.dir/src/stack.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/z80Emu.dir/src/stack.cpp.o -MF CMakeFiles/z80Emu.dir/src/stack.cpp.o.d -o CMakeFiles/z80Emu.dir/src/stack.cpp.o -c /home/dalton/desktop/z80Emu2/src/stack.cpp

CMakeFiles/z80Emu.dir/src/stack.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/z80Emu.dir/src/stack.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/dalton/desktop/z80Emu2/src/stack.cpp > CMakeFiles/z80Emu.dir/src/stack.cpp.i

CMakeFiles/z80Emu.dir/src/stack.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/z80Emu.dir/src/stack.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/dalton/desktop/z80Emu2/src/stack.cpp -o CMakeFiles/z80Emu.dir/src/stack.cpp.s

# Object files for target z80Emu
z80Emu_OBJECTS = \
"CMakeFiles/z80Emu.dir/src/main.cpp.o" \
"CMakeFiles/z80Emu.dir/src/z80.cpp.o" \
"CMakeFiles/z80Emu.dir/src/registers.cpp.o" \
"CMakeFiles/z80Emu.dir/src/memory.cpp.o" \
"CMakeFiles/z80Emu.dir/src/stack.cpp.o"

# External object files for target z80Emu
z80Emu_EXTERNAL_OBJECTS =

z80Emu: CMakeFiles/z80Emu.dir/src/main.cpp.o
z80Emu: CMakeFiles/z80Emu.dir/src/z80.cpp.o
z80Emu: CMakeFiles/z80Emu.dir/src/registers.cpp.o
z80Emu: CMakeFiles/z80Emu.dir/src/memory.cpp.o
z80Emu: CMakeFiles/z80Emu.dir/src/stack.cpp.o
z80Emu: CMakeFiles/z80Emu.dir/build.make
z80Emu: libs/libimgui.so
z80Emu: CMakeFiles/z80Emu.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/dalton/desktop/z80Emu2/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Linking CXX executable z80Emu"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/z80Emu.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/z80Emu.dir/build: z80Emu
.PHONY : CMakeFiles/z80Emu.dir/build

CMakeFiles/z80Emu.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/z80Emu.dir/cmake_clean.cmake
.PHONY : CMakeFiles/z80Emu.dir/clean

CMakeFiles/z80Emu.dir/depend:
	cd /home/dalton/desktop/z80Emu2/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/dalton/desktop/z80Emu2 /home/dalton/desktop/z80Emu2 /home/dalton/desktop/z80Emu2/build /home/dalton/desktop/z80Emu2/build /home/dalton/desktop/z80Emu2/build/CMakeFiles/z80Emu.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/z80Emu.dir/depend

