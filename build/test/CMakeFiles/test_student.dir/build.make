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
include test/CMakeFiles/test_student.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include test/CMakeFiles/test_student.dir/compiler_depend.make

# Include the progress variables for this target.
include test/CMakeFiles/test_student.dir/progress.make

# Include the compile flags for this target's objects.
include test/CMakeFiles/test_student.dir/flags.make

test/CMakeFiles/test_student.dir/test_student.cpp.o: test/CMakeFiles/test_student.dir/flags.make
test/CMakeFiles/test_student.dir/test_student.cpp.o: ../test/test_student.cpp
test/CMakeFiles/test_student.dir/test_student.cpp.o: test/CMakeFiles/test_student.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/alan/Documents/Cours/3A/C++/selection_sys/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object test/CMakeFiles/test_student.dir/test_student.cpp.o"
	cd /home/alan/Documents/Cours/3A/C++/selection_sys/build/test && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT test/CMakeFiles/test_student.dir/test_student.cpp.o -MF CMakeFiles/test_student.dir/test_student.cpp.o.d -o CMakeFiles/test_student.dir/test_student.cpp.o -c /home/alan/Documents/Cours/3A/C++/selection_sys/test/test_student.cpp

test/CMakeFiles/test_student.dir/test_student.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/test_student.dir/test_student.cpp.i"
	cd /home/alan/Documents/Cours/3A/C++/selection_sys/build/test && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/alan/Documents/Cours/3A/C++/selection_sys/test/test_student.cpp > CMakeFiles/test_student.dir/test_student.cpp.i

test/CMakeFiles/test_student.dir/test_student.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/test_student.dir/test_student.cpp.s"
	cd /home/alan/Documents/Cours/3A/C++/selection_sys/build/test && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/alan/Documents/Cours/3A/C++/selection_sys/test/test_student.cpp -o CMakeFiles/test_student.dir/test_student.cpp.s

# Object files for target test_student
test_student_OBJECTS = \
"CMakeFiles/test_student.dir/test_student.cpp.o"

# External object files for target test_student
test_student_EXTERNAL_OBJECTS =

test/test_student: test/CMakeFiles/test_student.dir/test_student.cpp.o
test/test_student: test/CMakeFiles/test_student.dir/build.make
test/test_student: src/libstudent.a
test/test_student: /usr/lib/x86_64-linux-gnu/libgtest_main.a
test/test_student: /usr/lib/x86_64-linux-gnu/libgtest.a
test/test_student: test/CMakeFiles/test_student.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/alan/Documents/Cours/3A/C++/selection_sys/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable test_student"
	cd /home/alan/Documents/Cours/3A/C++/selection_sys/build/test && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/test_student.dir/link.txt --verbose=$(VERBOSE)
	cd /home/alan/Documents/Cours/3A/C++/selection_sys/build/test && /usr/local/bin/cmake -D TEST_TARGET=test_student -D TEST_EXECUTABLE=/home/alan/Documents/Cours/3A/C++/selection_sys/build/test/test_student -D TEST_EXECUTOR= -D TEST_WORKING_DIR=/home/alan/Documents/Cours/3A/C++/selection_sys/build/test -D TEST_EXTRA_ARGS= -D TEST_PROPERTIES= -D TEST_PREFIX= -D TEST_SUFFIX= -D NO_PRETTY_TYPES=FALSE -D NO_PRETTY_VALUES=FALSE -D TEST_LIST=test_student_TESTS -D CTEST_FILE=/home/alan/Documents/Cours/3A/C++/selection_sys/build/test/test_student[1]_tests.cmake -D TEST_DISCOVERY_TIMEOUT=5 -D TEST_XML_OUTPUT_DIR= -P /usr/local/share/cmake-3.21/Modules/GoogleTestAddTests.cmake

# Rule to build all files generated by this target.
test/CMakeFiles/test_student.dir/build: test/test_student
.PHONY : test/CMakeFiles/test_student.dir/build

test/CMakeFiles/test_student.dir/clean:
	cd /home/alan/Documents/Cours/3A/C++/selection_sys/build/test && $(CMAKE_COMMAND) -P CMakeFiles/test_student.dir/cmake_clean.cmake
.PHONY : test/CMakeFiles/test_student.dir/clean

test/CMakeFiles/test_student.dir/depend:
	cd /home/alan/Documents/Cours/3A/C++/selection_sys/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/alan/Documents/Cours/3A/C++/selection_sys /home/alan/Documents/Cours/3A/C++/selection_sys/test /home/alan/Documents/Cours/3A/C++/selection_sys/build /home/alan/Documents/Cours/3A/C++/selection_sys/build/test /home/alan/Documents/Cours/3A/C++/selection_sys/build/test/CMakeFiles/test_student.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : test/CMakeFiles/test_student.dir/depend

