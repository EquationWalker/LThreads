# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.16

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


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

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /mnt/d/liuxin/Documents/LThreads/test

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /mnt/d/liuxin/Documents/LThreads/test/build

# Include any dependencies generated for this target.
include CMakeFiles/testcond.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/testcond.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/testcond.dir/flags.make

CMakeFiles/testcond.dir/testcond.cpp.o: CMakeFiles/testcond.dir/flags.make
CMakeFiles/testcond.dir/testcond.cpp.o: ../testcond.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/mnt/d/liuxin/Documents/LThreads/test/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/testcond.dir/testcond.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/testcond.dir/testcond.cpp.o -c /mnt/d/liuxin/Documents/LThreads/test/testcond.cpp

CMakeFiles/testcond.dir/testcond.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/testcond.dir/testcond.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /mnt/d/liuxin/Documents/LThreads/test/testcond.cpp > CMakeFiles/testcond.dir/testcond.cpp.i

CMakeFiles/testcond.dir/testcond.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/testcond.dir/testcond.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /mnt/d/liuxin/Documents/LThreads/test/testcond.cpp -o CMakeFiles/testcond.dir/testcond.cpp.s

# Object files for target testcond
testcond_OBJECTS = \
"CMakeFiles/testcond.dir/testcond.cpp.o"

# External object files for target testcond
testcond_EXTERNAL_OBJECTS =

testcond: CMakeFiles/testcond.dir/testcond.cpp.o
testcond: CMakeFiles/testcond.dir/build.make
testcond: CMakeFiles/testcond.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/mnt/d/liuxin/Documents/LThreads/test/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable testcond"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/testcond.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/testcond.dir/build: testcond

.PHONY : CMakeFiles/testcond.dir/build

CMakeFiles/testcond.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/testcond.dir/cmake_clean.cmake
.PHONY : CMakeFiles/testcond.dir/clean

CMakeFiles/testcond.dir/depend:
	cd /mnt/d/liuxin/Documents/LThreads/test/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /mnt/d/liuxin/Documents/LThreads/test /mnt/d/liuxin/Documents/LThreads/test /mnt/d/liuxin/Documents/LThreads/test/build /mnt/d/liuxin/Documents/LThreads/test/build /mnt/d/liuxin/Documents/LThreads/test/build/CMakeFiles/testcond.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/testcond.dir/depend

