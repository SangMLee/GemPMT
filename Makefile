# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.8

# Default target executed when no arguments are given to make.
default_target: all

.PHONY : default_target

# Allow only one "make -f Makefile2" at a time, but pass parallelism.
.NOTPARALLEL:


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
CMAKE_COMMAND = /cvmfs/sft.cern.ch/lcg/releases/CMake/3.8.2-ece19/x86_64-slc6-gcc62-opt/bin/cmake

# The command to remove a file.
RM = /cvmfs/sft.cern.ch/lcg/releases/CMake/3.8.2-ece19/x86_64-slc6-gcc62-opt/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /cms/scratch/daniellee/GemPMT

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /cms/scratch/daniellee/GemPMT

#=============================================================================
# Targets provided globally by CMake.

# Special rule for the target install/strip
install/strip: preinstall
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Installing the project stripped..."
	/cvmfs/sft.cern.ch/lcg/releases/CMake/3.8.2-ece19/x86_64-slc6-gcc62-opt/bin/cmake -DCMAKE_INSTALL_DO_STRIP=1 -P cmake_install.cmake
.PHONY : install/strip

# Special rule for the target install/strip
install/strip/fast: preinstall/fast
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Installing the project stripped..."
	/cvmfs/sft.cern.ch/lcg/releases/CMake/3.8.2-ece19/x86_64-slc6-gcc62-opt/bin/cmake -DCMAKE_INSTALL_DO_STRIP=1 -P cmake_install.cmake
.PHONY : install/strip/fast

# Special rule for the target install/local
install/local: preinstall
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Installing only the local directory..."
	/cvmfs/sft.cern.ch/lcg/releases/CMake/3.8.2-ece19/x86_64-slc6-gcc62-opt/bin/cmake -DCMAKE_INSTALL_LOCAL_ONLY=1 -P cmake_install.cmake
.PHONY : install/local

# Special rule for the target install/local
install/local/fast: preinstall/fast
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Installing only the local directory..."
	/cvmfs/sft.cern.ch/lcg/releases/CMake/3.8.2-ece19/x86_64-slc6-gcc62-opt/bin/cmake -DCMAKE_INSTALL_LOCAL_ONLY=1 -P cmake_install.cmake
.PHONY : install/local/fast

# Special rule for the target install
install: preinstall
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Install the project..."
	/cvmfs/sft.cern.ch/lcg/releases/CMake/3.8.2-ece19/x86_64-slc6-gcc62-opt/bin/cmake -P cmake_install.cmake
.PHONY : install

# Special rule for the target install
install/fast: preinstall/fast
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Install the project..."
	/cvmfs/sft.cern.ch/lcg/releases/CMake/3.8.2-ece19/x86_64-slc6-gcc62-opt/bin/cmake -P cmake_install.cmake
.PHONY : install/fast

# Special rule for the target list_install_components
list_install_components:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Available install components are: \"Unspecified\""
.PHONY : list_install_components

# Special rule for the target list_install_components
list_install_components/fast: list_install_components

.PHONY : list_install_components/fast

# Special rule for the target edit_cache
edit_cache:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Running CMake cache editor..."
	/cvmfs/sft.cern.ch/lcg/releases/CMake/3.8.2-ece19/x86_64-slc6-gcc62-opt/bin/ccmake -H$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR)
.PHONY : edit_cache

# Special rule for the target edit_cache
edit_cache/fast: edit_cache

.PHONY : edit_cache/fast

# Special rule for the target rebuild_cache
rebuild_cache:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Running CMake to regenerate build system..."
	/cvmfs/sft.cern.ch/lcg/releases/CMake/3.8.2-ece19/x86_64-slc6-gcc62-opt/bin/cmake -H$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR)
.PHONY : rebuild_cache

# Special rule for the target rebuild_cache
rebuild_cache/fast: rebuild_cache

.PHONY : rebuild_cache/fast

# The main all target
all: cmake_check_build_system
	$(CMAKE_COMMAND) -E cmake_progress_start /cms/scratch/daniellee/GemPMT/CMakeFiles /cms/scratch/daniellee/GemPMT/CMakeFiles/progress.marks
	$(MAKE) -f CMakeFiles/Makefile2 all
	$(CMAKE_COMMAND) -E cmake_progress_start /cms/scratch/daniellee/GemPMT/CMakeFiles 0
.PHONY : all

# The main clean target
clean:
	$(MAKE) -f CMakeFiles/Makefile2 clean
.PHONY : clean

# The main clean target
clean/fast: clean

.PHONY : clean/fast

# Prepare targets for installation.
preinstall: all
	$(MAKE) -f CMakeFiles/Makefile2 preinstall
.PHONY : preinstall

# Prepare targets for installation.
preinstall/fast:
	$(MAKE) -f CMakeFiles/Makefile2 preinstall
.PHONY : preinstall/fast

# clear depends
depend:
	$(CMAKE_COMMAND) -H$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR) --check-build-system CMakeFiles/Makefile.cmake 1
.PHONY : depend

#=============================================================================
# Target rules for targets named GemPMT

# Build rule for target.
GemPMT: cmake_check_build_system
	$(MAKE) -f CMakeFiles/Makefile2 GemPMT
.PHONY : GemPMT

# fast build rule for target.
GemPMT/fast:
	$(MAKE) -f CMakeFiles/GemPMT.dir/build.make CMakeFiles/GemPMT.dir/build
.PHONY : GemPMT/fast

#=============================================================================
# Target rules for targets named YC

# Build rule for target.
YC: cmake_check_build_system
	$(MAKE) -f CMakeFiles/Makefile2 YC
.PHONY : YC

# fast build rule for target.
YC/fast:
	$(MAKE) -f CMakeFiles/YC.dir/build.make CMakeFiles/YC.dir/build
.PHONY : YC/fast

GemPMT.o: GemPMT.cc.o

.PHONY : GemPMT.o

# target to build an object file
GemPMT.cc.o:
	$(MAKE) -f CMakeFiles/GemPMT.dir/build.make CMakeFiles/GemPMT.dir/GemPMT.cc.o
.PHONY : GemPMT.cc.o

GemPMT.i: GemPMT.cc.i

.PHONY : GemPMT.i

# target to preprocess a source file
GemPMT.cc.i:
	$(MAKE) -f CMakeFiles/GemPMT.dir/build.make CMakeFiles/GemPMT.dir/GemPMT.cc.i
.PHONY : GemPMT.cc.i

GemPMT.s: GemPMT.cc.s

.PHONY : GemPMT.s

# target to generate assembly for a file
GemPMT.cc.s:
	$(MAKE) -f CMakeFiles/GemPMT.dir/build.make CMakeFiles/GemPMT.dir/GemPMT.cc.s
.PHONY : GemPMT.cc.s

src/ActionInitialization.o: src/ActionInitialization.cc.o

.PHONY : src/ActionInitialization.o

# target to build an object file
src/ActionInitialization.cc.o:
	$(MAKE) -f CMakeFiles/GemPMT.dir/build.make CMakeFiles/GemPMT.dir/src/ActionInitialization.cc.o
.PHONY : src/ActionInitialization.cc.o

src/ActionInitialization.i: src/ActionInitialization.cc.i

.PHONY : src/ActionInitialization.i

# target to preprocess a source file
src/ActionInitialization.cc.i:
	$(MAKE) -f CMakeFiles/GemPMT.dir/build.make CMakeFiles/GemPMT.dir/src/ActionInitialization.cc.i
.PHONY : src/ActionInitialization.cc.i

src/ActionInitialization.s: src/ActionInitialization.cc.s

.PHONY : src/ActionInitialization.s

# target to generate assembly for a file
src/ActionInitialization.cc.s:
	$(MAKE) -f CMakeFiles/GemPMT.dir/build.make CMakeFiles/GemPMT.dir/src/ActionInitialization.cc.s
.PHONY : src/ActionInitialization.cc.s

src/DetectorConstruction.o: src/DetectorConstruction.cc.o

.PHONY : src/DetectorConstruction.o

# target to build an object file
src/DetectorConstruction.cc.o:
	$(MAKE) -f CMakeFiles/GemPMT.dir/build.make CMakeFiles/GemPMT.dir/src/DetectorConstruction.cc.o
.PHONY : src/DetectorConstruction.cc.o

src/DetectorConstruction.i: src/DetectorConstruction.cc.i

.PHONY : src/DetectorConstruction.i

# target to preprocess a source file
src/DetectorConstruction.cc.i:
	$(MAKE) -f CMakeFiles/GemPMT.dir/build.make CMakeFiles/GemPMT.dir/src/DetectorConstruction.cc.i
.PHONY : src/DetectorConstruction.cc.i

src/DetectorConstruction.s: src/DetectorConstruction.cc.s

.PHONY : src/DetectorConstruction.s

# target to generate assembly for a file
src/DetectorConstruction.cc.s:
	$(MAKE) -f CMakeFiles/GemPMT.dir/build.make CMakeFiles/GemPMT.dir/src/DetectorConstruction.cc.s
.PHONY : src/DetectorConstruction.cc.s

src/EventAction.o: src/EventAction.cc.o

.PHONY : src/EventAction.o

# target to build an object file
src/EventAction.cc.o:
	$(MAKE) -f CMakeFiles/GemPMT.dir/build.make CMakeFiles/GemPMT.dir/src/EventAction.cc.o
.PHONY : src/EventAction.cc.o

src/EventAction.i: src/EventAction.cc.i

.PHONY : src/EventAction.i

# target to preprocess a source file
src/EventAction.cc.i:
	$(MAKE) -f CMakeFiles/GemPMT.dir/build.make CMakeFiles/GemPMT.dir/src/EventAction.cc.i
.PHONY : src/EventAction.cc.i

src/EventAction.s: src/EventAction.cc.s

.PHONY : src/EventAction.s

# target to generate assembly for a file
src/EventAction.cc.s:
	$(MAKE) -f CMakeFiles/GemPMT.dir/build.make CMakeFiles/GemPMT.dir/src/EventAction.cc.s
.PHONY : src/EventAction.cc.s

src/GPMAnalysis.o: src/GPMAnalysis.cc.o

.PHONY : src/GPMAnalysis.o

# target to build an object file
src/GPMAnalysis.cc.o:
	$(MAKE) -f CMakeFiles/GemPMT.dir/build.make CMakeFiles/GemPMT.dir/src/GPMAnalysis.cc.o
.PHONY : src/GPMAnalysis.cc.o

src/GPMAnalysis.i: src/GPMAnalysis.cc.i

.PHONY : src/GPMAnalysis.i

# target to preprocess a source file
src/GPMAnalysis.cc.i:
	$(MAKE) -f CMakeFiles/GemPMT.dir/build.make CMakeFiles/GemPMT.dir/src/GPMAnalysis.cc.i
.PHONY : src/GPMAnalysis.cc.i

src/GPMAnalysis.s: src/GPMAnalysis.cc.s

.PHONY : src/GPMAnalysis.s

# target to generate assembly for a file
src/GPMAnalysis.cc.s:
	$(MAKE) -f CMakeFiles/GemPMT.dir/build.make CMakeFiles/GemPMT.dir/src/GPMAnalysis.cc.s
.PHONY : src/GPMAnalysis.cc.s

src/PrimaryGeneratorAction.o: src/PrimaryGeneratorAction.cc.o

.PHONY : src/PrimaryGeneratorAction.o

# target to build an object file
src/PrimaryGeneratorAction.cc.o:
	$(MAKE) -f CMakeFiles/GemPMT.dir/build.make CMakeFiles/GemPMT.dir/src/PrimaryGeneratorAction.cc.o
.PHONY : src/PrimaryGeneratorAction.cc.o

src/PrimaryGeneratorAction.i: src/PrimaryGeneratorAction.cc.i

.PHONY : src/PrimaryGeneratorAction.i

# target to preprocess a source file
src/PrimaryGeneratorAction.cc.i:
	$(MAKE) -f CMakeFiles/GemPMT.dir/build.make CMakeFiles/GemPMT.dir/src/PrimaryGeneratorAction.cc.i
.PHONY : src/PrimaryGeneratorAction.cc.i

src/PrimaryGeneratorAction.s: src/PrimaryGeneratorAction.cc.s

.PHONY : src/PrimaryGeneratorAction.s

# target to generate assembly for a file
src/PrimaryGeneratorAction.cc.s:
	$(MAKE) -f CMakeFiles/GemPMT.dir/build.make CMakeFiles/GemPMT.dir/src/PrimaryGeneratorAction.cc.s
.PHONY : src/PrimaryGeneratorAction.cc.s

src/RunAction.o: src/RunAction.cc.o

.PHONY : src/RunAction.o

# target to build an object file
src/RunAction.cc.o:
	$(MAKE) -f CMakeFiles/GemPMT.dir/build.make CMakeFiles/GemPMT.dir/src/RunAction.cc.o
.PHONY : src/RunAction.cc.o

src/RunAction.i: src/RunAction.cc.i

.PHONY : src/RunAction.i

# target to preprocess a source file
src/RunAction.cc.i:
	$(MAKE) -f CMakeFiles/GemPMT.dir/build.make CMakeFiles/GemPMT.dir/src/RunAction.cc.i
.PHONY : src/RunAction.cc.i

src/RunAction.s: src/RunAction.cc.s

.PHONY : src/RunAction.s

# target to generate assembly for a file
src/RunAction.cc.s:
	$(MAKE) -f CMakeFiles/GemPMT.dir/build.make CMakeFiles/GemPMT.dir/src/RunAction.cc.s
.PHONY : src/RunAction.cc.s

src/SteppingAction.o: src/SteppingAction.cc.o

.PHONY : src/SteppingAction.o

# target to build an object file
src/SteppingAction.cc.o:
	$(MAKE) -f CMakeFiles/GemPMT.dir/build.make CMakeFiles/GemPMT.dir/src/SteppingAction.cc.o
.PHONY : src/SteppingAction.cc.o

src/SteppingAction.i: src/SteppingAction.cc.i

.PHONY : src/SteppingAction.i

# target to preprocess a source file
src/SteppingAction.cc.i:
	$(MAKE) -f CMakeFiles/GemPMT.dir/build.make CMakeFiles/GemPMT.dir/src/SteppingAction.cc.i
.PHONY : src/SteppingAction.cc.i

src/SteppingAction.s: src/SteppingAction.cc.s

.PHONY : src/SteppingAction.s

# target to generate assembly for a file
src/SteppingAction.cc.s:
	$(MAKE) -f CMakeFiles/GemPMT.dir/build.make CMakeFiles/GemPMT.dir/src/SteppingAction.cc.s
.PHONY : src/SteppingAction.cc.s

# Help Target
help:
	@echo "The following are some of the valid targets for this Makefile:"
	@echo "... all (the default if no target is provided)"
	@echo "... clean"
	@echo "... depend"
	@echo "... install/strip"
	@echo "... install/local"
	@echo "... install"
	@echo "... list_install_components"
	@echo "... GemPMT"
	@echo "... YC"
	@echo "... edit_cache"
	@echo "... rebuild_cache"
	@echo "... GemPMT.o"
	@echo "... GemPMT.i"
	@echo "... GemPMT.s"
	@echo "... src/ActionInitialization.o"
	@echo "... src/ActionInitialization.i"
	@echo "... src/ActionInitialization.s"
	@echo "... src/DetectorConstruction.o"
	@echo "... src/DetectorConstruction.i"
	@echo "... src/DetectorConstruction.s"
	@echo "... src/EventAction.o"
	@echo "... src/EventAction.i"
	@echo "... src/EventAction.s"
	@echo "... src/GPMAnalysis.o"
	@echo "... src/GPMAnalysis.i"
	@echo "... src/GPMAnalysis.s"
	@echo "... src/PrimaryGeneratorAction.o"
	@echo "... src/PrimaryGeneratorAction.i"
	@echo "... src/PrimaryGeneratorAction.s"
	@echo "... src/RunAction.o"
	@echo "... src/RunAction.i"
	@echo "... src/RunAction.s"
	@echo "... src/SteppingAction.o"
	@echo "... src/SteppingAction.i"
	@echo "... src/SteppingAction.s"
.PHONY : help



#=============================================================================
# Special targets to cleanup operation of make.

# Special rule to run CMake to check the build system integrity.
# No rule that depends on this can have commands that come from listfiles
# because they might be regenerated.
cmake_check_build_system:
	$(CMAKE_COMMAND) -H$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR) --check-build-system CMakeFiles/Makefile.cmake 0
.PHONY : cmake_check_build_system

