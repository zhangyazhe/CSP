# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.13

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
CMAKE_COMMAND = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake

# The command to remove a file.
RM = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/zhangyazhe/MyFiles/C:C++Projects/csp/201812_2

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/zhangyazhe/MyFiles/C:C++Projects/csp/201812_2/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/201812_2.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/201812_2.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/201812_2.dir/flags.make

CMakeFiles/201812_2.dir/main.cpp.o: CMakeFiles/201812_2.dir/flags.make
CMakeFiles/201812_2.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/zhangyazhe/MyFiles/C:C++Projects/csp/201812_2/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/201812_2.dir/main.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/201812_2.dir/main.cpp.o -c /Users/zhangyazhe/MyFiles/C:C++Projects/csp/201812_2/main.cpp

CMakeFiles/201812_2.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/201812_2.dir/main.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/zhangyazhe/MyFiles/C:C++Projects/csp/201812_2/main.cpp > CMakeFiles/201812_2.dir/main.cpp.i

CMakeFiles/201812_2.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/201812_2.dir/main.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/zhangyazhe/MyFiles/C:C++Projects/csp/201812_2/main.cpp -o CMakeFiles/201812_2.dir/main.cpp.s

# Object files for target 201812_2
201812_2_OBJECTS = \
"CMakeFiles/201812_2.dir/main.cpp.o"

# External object files for target 201812_2
201812_2_EXTERNAL_OBJECTS =

201812_2: CMakeFiles/201812_2.dir/main.cpp.o
201812_2: CMakeFiles/201812_2.dir/build.make
201812_2: CMakeFiles/201812_2.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/zhangyazhe/MyFiles/C:C++Projects/csp/201812_2/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable 201812_2"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/201812_2.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/201812_2.dir/build: 201812_2

.PHONY : CMakeFiles/201812_2.dir/build

CMakeFiles/201812_2.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/201812_2.dir/cmake_clean.cmake
.PHONY : CMakeFiles/201812_2.dir/clean

CMakeFiles/201812_2.dir/depend:
	cd /Users/zhangyazhe/MyFiles/C:C++Projects/csp/201812_2/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/zhangyazhe/MyFiles/C:C++Projects/csp/201812_2 /Users/zhangyazhe/MyFiles/C:C++Projects/csp/201812_2 /Users/zhangyazhe/MyFiles/C:C++Projects/csp/201812_2/cmake-build-debug /Users/zhangyazhe/MyFiles/C:C++Projects/csp/201812_2/cmake-build-debug /Users/zhangyazhe/MyFiles/C:C++Projects/csp/201812_2/cmake-build-debug/CMakeFiles/201812_2.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/201812_2.dir/depend
