# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 2.8

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:

# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list

# Suppress display of executed commands.
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
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The program to use to edit the cache.
CMAKE_EDIT_COMMAND = /cvmfs/sft.cern.ch/lcg/releases/CMake/3.8.2-ece19/x86_64-slc6-gcc62-opt/bin/ccmake

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/daniellee1004/Geant

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/daniellee1004/Geant

# Utility rule file for YC.

# Include the progress variables for this target.
include CMakeFiles/YC.dir/progress.make

CMakeFiles/YC: GemPMT

YC: CMakeFiles/YC
YC: CMakeFiles/YC.dir/build.make
.PHONY : YC

# Rule to build all files generated by this target.
CMakeFiles/YC.dir/build: YC
.PHONY : CMakeFiles/YC.dir/build

CMakeFiles/YC.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/YC.dir/cmake_clean.cmake
.PHONY : CMakeFiles/YC.dir/clean

CMakeFiles/YC.dir/depend:
	cd /home/daniellee1004/Geant && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/daniellee1004/Geant /home/daniellee1004/Geant /home/daniellee1004/Geant /home/daniellee1004/Geant /home/daniellee1004/Geant/CMakeFiles/YC.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/YC.dir/depend
