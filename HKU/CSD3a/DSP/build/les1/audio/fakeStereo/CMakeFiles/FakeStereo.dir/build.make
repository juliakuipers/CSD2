# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.23

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
CMAKE_COMMAND = /usr/local/Cellar/cmake/3.23.1/bin/cmake

# The command to remove a file.
RM = /usr/local/Cellar/cmake/3.23.1/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/Julia/Documents/Atom/HKU/CSD3a/DSP

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/Julia/Documents/Atom/HKU/CSD3a/DSP/build

# Include any dependencies generated for this target.
include les1/audio/fakeStereo/CMakeFiles/FakeStereo.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include les1/audio/fakeStereo/CMakeFiles/FakeStereo.dir/compiler_depend.make

# Include the progress variables for this target.
include les1/audio/fakeStereo/CMakeFiles/FakeStereo.dir/progress.make

# Include the compile flags for this target's objects.
include les1/audio/fakeStereo/CMakeFiles/FakeStereo.dir/flags.make

les1/audio/fakeStereo/CMakeFiles/FakeStereo.dir/fakeStereo.cpp.o: les1/audio/fakeStereo/CMakeFiles/FakeStereo.dir/flags.make
les1/audio/fakeStereo/CMakeFiles/FakeStereo.dir/fakeStereo.cpp.o: ../les1/audio/fakeStereo/fakeStereo.cpp
les1/audio/fakeStereo/CMakeFiles/FakeStereo.dir/fakeStereo.cpp.o: les1/audio/fakeStereo/CMakeFiles/FakeStereo.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/Julia/Documents/Atom/HKU/CSD3a/DSP/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object les1/audio/fakeStereo/CMakeFiles/FakeStereo.dir/fakeStereo.cpp.o"
	cd /Users/Julia/Documents/Atom/HKU/CSD3a/DSP/build/les1/audio/fakeStereo && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT les1/audio/fakeStereo/CMakeFiles/FakeStereo.dir/fakeStereo.cpp.o -MF CMakeFiles/FakeStereo.dir/fakeStereo.cpp.o.d -o CMakeFiles/FakeStereo.dir/fakeStereo.cpp.o -c /Users/Julia/Documents/Atom/HKU/CSD3a/DSP/les1/audio/fakeStereo/fakeStereo.cpp

les1/audio/fakeStereo/CMakeFiles/FakeStereo.dir/fakeStereo.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/FakeStereo.dir/fakeStereo.cpp.i"
	cd /Users/Julia/Documents/Atom/HKU/CSD3a/DSP/build/les1/audio/fakeStereo && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/Julia/Documents/Atom/HKU/CSD3a/DSP/les1/audio/fakeStereo/fakeStereo.cpp > CMakeFiles/FakeStereo.dir/fakeStereo.cpp.i

les1/audio/fakeStereo/CMakeFiles/FakeStereo.dir/fakeStereo.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/FakeStereo.dir/fakeStereo.cpp.s"
	cd /Users/Julia/Documents/Atom/HKU/CSD3a/DSP/build/les1/audio/fakeStereo && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/Julia/Documents/Atom/HKU/CSD3a/DSP/les1/audio/fakeStereo/fakeStereo.cpp -o CMakeFiles/FakeStereo.dir/fakeStereo.cpp.s

# Object files for target FakeStereo
FakeStereo_OBJECTS = \
"CMakeFiles/FakeStereo.dir/fakeStereo.cpp.o"

# External object files for target FakeStereo
FakeStereo_EXTERNAL_OBJECTS =

les1/audio/fakeStereo/libFakeStereo.a: les1/audio/fakeStereo/CMakeFiles/FakeStereo.dir/fakeStereo.cpp.o
les1/audio/fakeStereo/libFakeStereo.a: les1/audio/fakeStereo/CMakeFiles/FakeStereo.dir/build.make
les1/audio/fakeStereo/libFakeStereo.a: les1/audio/fakeStereo/CMakeFiles/FakeStereo.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/Julia/Documents/Atom/HKU/CSD3a/DSP/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX static library libFakeStereo.a"
	cd /Users/Julia/Documents/Atom/HKU/CSD3a/DSP/build/les1/audio/fakeStereo && $(CMAKE_COMMAND) -P CMakeFiles/FakeStereo.dir/cmake_clean_target.cmake
	cd /Users/Julia/Documents/Atom/HKU/CSD3a/DSP/build/les1/audio/fakeStereo && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/FakeStereo.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
les1/audio/fakeStereo/CMakeFiles/FakeStereo.dir/build: les1/audio/fakeStereo/libFakeStereo.a
.PHONY : les1/audio/fakeStereo/CMakeFiles/FakeStereo.dir/build

les1/audio/fakeStereo/CMakeFiles/FakeStereo.dir/clean:
	cd /Users/Julia/Documents/Atom/HKU/CSD3a/DSP/build/les1/audio/fakeStereo && $(CMAKE_COMMAND) -P CMakeFiles/FakeStereo.dir/cmake_clean.cmake
.PHONY : les1/audio/fakeStereo/CMakeFiles/FakeStereo.dir/clean

les1/audio/fakeStereo/CMakeFiles/FakeStereo.dir/depend:
	cd /Users/Julia/Documents/Atom/HKU/CSD3a/DSP/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/Julia/Documents/Atom/HKU/CSD3a/DSP /Users/Julia/Documents/Atom/HKU/CSD3a/DSP/les1/audio/fakeStereo /Users/Julia/Documents/Atom/HKU/CSD3a/DSP/build /Users/Julia/Documents/Atom/HKU/CSD3a/DSP/build/les1/audio/fakeStereo /Users/Julia/Documents/Atom/HKU/CSD3a/DSP/build/les1/audio/fakeStereo/CMakeFiles/FakeStereo.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : les1/audio/fakeStereo/CMakeFiles/FakeStereo.dir/depend

