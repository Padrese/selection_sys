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
CMAKE_COMMAND = /usr/local/bin/cmake

# The command to remove a file.
RM = /usr/local/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/alan/Documents/Cours/3A/C++/selection_sys

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/alan/Documents/Cours/3A/C++/selection_sys/build

# Include any dependencies generated for this target.
include src/CMakeFiles/selectivesystem.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include src/CMakeFiles/selectivesystem.dir/compiler_depend.make

# Include the progress variables for this target.
include src/CMakeFiles/selectivesystem.dir/progress.make

# Include the compile flags for this target's objects.
include src/CMakeFiles/selectivesystem.dir/flags.make

src/CMakeFiles/selectivesystem.dir/SelectiveSystem/SelectiveSystem.cpp.o: src/CMakeFiles/selectivesystem.dir/flags.make
src/CMakeFiles/selectivesystem.dir/SelectiveSystem/SelectiveSystem.cpp.o: ../src/SelectiveSystem/SelectiveSystem.cpp
src/CMakeFiles/selectivesystem.dir/SelectiveSystem/SelectiveSystem.cpp.o: src/CMakeFiles/selectivesystem.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/alan/Documents/Cours/3A/C++/selection_sys/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object src/CMakeFiles/selectivesystem.dir/SelectiveSystem/SelectiveSystem.cpp.o"
	cd /home/alan/Documents/Cours/3A/C++/selection_sys/build/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT src/CMakeFiles/selectivesystem.dir/SelectiveSystem/SelectiveSystem.cpp.o -MF CMakeFiles/selectivesystem.dir/SelectiveSystem/SelectiveSystem.cpp.o.d -o CMakeFiles/selectivesystem.dir/SelectiveSystem/SelectiveSystem.cpp.o -c /home/alan/Documents/Cours/3A/C++/selection_sys/src/SelectiveSystem/SelectiveSystem.cpp

src/CMakeFiles/selectivesystem.dir/SelectiveSystem/SelectiveSystem.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/selectivesystem.dir/SelectiveSystem/SelectiveSystem.cpp.i"
	cd /home/alan/Documents/Cours/3A/C++/selection_sys/build/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/alan/Documents/Cours/3A/C++/selection_sys/src/SelectiveSystem/SelectiveSystem.cpp > CMakeFiles/selectivesystem.dir/SelectiveSystem/SelectiveSystem.cpp.i

src/CMakeFiles/selectivesystem.dir/SelectiveSystem/SelectiveSystem.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/selectivesystem.dir/SelectiveSystem/SelectiveSystem.cpp.s"
	cd /home/alan/Documents/Cours/3A/C++/selection_sys/build/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/alan/Documents/Cours/3A/C++/selection_sys/src/SelectiveSystem/SelectiveSystem.cpp -o CMakeFiles/selectivesystem.dir/SelectiveSystem/SelectiveSystem.cpp.s

# Object files for target selectivesystem
selectivesystem_OBJECTS = \
"CMakeFiles/selectivesystem.dir/SelectiveSystem/SelectiveSystem.cpp.o"

# External object files for target selectivesystem
selectivesystem_EXTERNAL_OBJECTS =

src/libselectivesystem.a: src/CMakeFiles/selectivesystem.dir/SelectiveSystem/SelectiveSystem.cpp.o
src/libselectivesystem.a: src/CMakeFiles/selectivesystem.dir/build.make
src/libselectivesystem.a: src/CMakeFiles/selectivesystem.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/alan/Documents/Cours/3A/C++/selection_sys/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX static library libselectivesystem.a"
	cd /home/alan/Documents/Cours/3A/C++/selection_sys/build/src && $(CMAKE_COMMAND) -P CMakeFiles/selectivesystem.dir/cmake_clean_target.cmake
	cd /home/alan/Documents/Cours/3A/C++/selection_sys/build/src && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/selectivesystem.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
src/CMakeFiles/selectivesystem.dir/build: src/libselectivesystem.a
.PHONY : src/CMakeFiles/selectivesystem.dir/build

src/CMakeFiles/selectivesystem.dir/clean:
	cd /home/alan/Documents/Cours/3A/C++/selection_sys/build/src && $(CMAKE_COMMAND) -P CMakeFiles/selectivesystem.dir/cmake_clean.cmake
.PHONY : src/CMakeFiles/selectivesystem.dir/clean

src/CMakeFiles/selectivesystem.dir/depend:
	cd /home/alan/Documents/Cours/3A/C++/selection_sys/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/alan/Documents/Cours/3A/C++/selection_sys /home/alan/Documents/Cours/3A/C++/selection_sys/src /home/alan/Documents/Cours/3A/C++/selection_sys/build /home/alan/Documents/Cours/3A/C++/selection_sys/build/src /home/alan/Documents/Cours/3A/C++/selection_sys/build/src/CMakeFiles/selectivesystem.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : src/CMakeFiles/selectivesystem.dir/depend

