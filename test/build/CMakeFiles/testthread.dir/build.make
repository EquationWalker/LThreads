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
include CMakeFiles/testthread.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/testthread.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/testthread.dir/flags.make

CMakeFiles/testthread.dir/testthread.cpp.o: CMakeFiles/testthread.dir/flags.make
CMakeFiles/testthread.dir/testthread.cpp.o: ../testthread.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/mnt/d/liuxin/Documents/LThreads/test/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/testthread.dir/testthread.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/testthread.dir/testthread.cpp.o -c /mnt/d/liuxin/Documents/LThreads/test/testthread.cpp

CMakeFiles/testthread.dir/testthread.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/testthread.dir/testthread.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /mnt/d/liuxin/Documents/LThreads/test/testthread.cpp > CMakeFiles/testthread.dir/testthread.cpp.i

CMakeFiles/testthread.dir/testthread.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/testthread.dir/testthread.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /mnt/d/liuxin/Documents/LThreads/test/testthread.cpp -o CMakeFiles/testthread.dir/testthread.cpp.s

# Object files for target testthread
testthread_OBJECTS = \
"CMakeFiles/testthread.dir/testthread.cpp.o"

# External object files for target testthread
testthread_EXTERNAL_OBJECTS =

../bin/testthread: CMakeFiles/testthread.dir/testthread.cpp.o
../bin/testthread: CMakeFiles/testthread.dir/build.make
../bin/testthread: CMakeFiles/testthread.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/mnt/d/liuxin/Documents/LThreads/test/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable ../bin/testthread"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/testthread.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/testthread.dir/build: ../bin/testthread

.PHONY : CMakeFiles/testthread.dir/build

CMakeFiles/testthread.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/testthread.dir/cmake_clean.cmake
.PHONY : CMakeFiles/testthread.dir/clean

CMakeFiles/testthread.dir/depend:
	cd /mnt/d/liuxin/Documents/LThreads/test/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /mnt/d/liuxin/Documents/LThreads/test /mnt/d/liuxin/Documents/LThreads/test /mnt/d/liuxin/Documents/LThreads/test/build /mnt/d/liuxin/Documents/LThreads/test/build /mnt/d/liuxin/Documents/LThreads/test/build/CMakeFiles/testthread.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/testthread.dir/depend
