# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.17

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

# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "D:\program\CLion 2020.2.4\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "D:\program\CLion 2020.2.4\bin\cmake\win\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = D:\leetcode\59

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = D:\leetcode\59\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/59.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/59.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/59.dir/flags.make

CMakeFiles/59.dir/main.cpp.obj: CMakeFiles/59.dir/flags.make
CMakeFiles/59.dir/main.cpp.obj: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=D:\leetcode\59\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/59.dir/main.cpp.obj"
	D:\Mingw\x86_64-8.1.0-release-posix-sjlj-rt_v6-rev0\mingw64\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\59.dir\main.cpp.obj -c D:\leetcode\59\main.cpp

CMakeFiles/59.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/59.dir/main.cpp.i"
	D:\Mingw\x86_64-8.1.0-release-posix-sjlj-rt_v6-rev0\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E D:\leetcode\59\main.cpp > CMakeFiles\59.dir\main.cpp.i

CMakeFiles/59.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/59.dir/main.cpp.s"
	D:\Mingw\x86_64-8.1.0-release-posix-sjlj-rt_v6-rev0\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S D:\leetcode\59\main.cpp -o CMakeFiles\59.dir\main.cpp.s

# Object files for target 59
59_OBJECTS = \
"CMakeFiles/59.dir/main.cpp.obj"

# External object files for target 59
59_EXTERNAL_OBJECTS =

59.exe: CMakeFiles/59.dir/main.cpp.obj
59.exe: CMakeFiles/59.dir/build.make
59.exe: CMakeFiles/59.dir/linklibs.rsp
59.exe: CMakeFiles/59.dir/objects1.rsp
59.exe: CMakeFiles/59.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=D:\leetcode\59\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable 59.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\59.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/59.dir/build: 59.exe

.PHONY : CMakeFiles/59.dir/build

CMakeFiles/59.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\59.dir\cmake_clean.cmake
.PHONY : CMakeFiles/59.dir/clean

CMakeFiles/59.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" D:\leetcode\59 D:\leetcode\59 D:\leetcode\59\cmake-build-debug D:\leetcode\59\cmake-build-debug D:\leetcode\59\cmake-build-debug\CMakeFiles\59.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/59.dir/depend

