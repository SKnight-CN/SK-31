# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.8

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

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "F:\mingw-w64\programming tools\CLion 2017.2.3\bin\cmake\bin\cmake.exe"

# The command to remove a file.
RM = "F:\mingw-w64\programming tools\CLion 2017.2.3\bin\cmake\bin\cmake.exe" -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = F:\programs\AI2

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = F:\programs\AI2\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/AI2.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/AI2.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/AI2.dir/flags.make

CMakeFiles/AI2.dir/main.cpp.obj: CMakeFiles/AI2.dir/flags.make
CMakeFiles/AI2.dir/main.cpp.obj: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=F:\programs\AI2\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/AI2.dir/main.cpp.obj"
	F:\GCC\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\AI2.dir\main.cpp.obj -c F:\programs\AI2\main.cpp

CMakeFiles/AI2.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/AI2.dir/main.cpp.i"
	F:\GCC\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E F:\programs\AI2\main.cpp > CMakeFiles\AI2.dir\main.cpp.i

CMakeFiles/AI2.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/AI2.dir/main.cpp.s"
	F:\GCC\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S F:\programs\AI2\main.cpp -o CMakeFiles\AI2.dir\main.cpp.s

CMakeFiles/AI2.dir/main.cpp.obj.requires:

.PHONY : CMakeFiles/AI2.dir/main.cpp.obj.requires

CMakeFiles/AI2.dir/main.cpp.obj.provides: CMakeFiles/AI2.dir/main.cpp.obj.requires
	$(MAKE) -f CMakeFiles\AI2.dir\build.make CMakeFiles/AI2.dir/main.cpp.obj.provides.build
.PHONY : CMakeFiles/AI2.dir/main.cpp.obj.provides

CMakeFiles/AI2.dir/main.cpp.obj.provides.build: CMakeFiles/AI2.dir/main.cpp.obj


# Object files for target AI2
AI2_OBJECTS = \
"CMakeFiles/AI2.dir/main.cpp.obj"

# External object files for target AI2
AI2_EXTERNAL_OBJECTS =

AI2.exe: CMakeFiles/AI2.dir/main.cpp.obj
AI2.exe: CMakeFiles/AI2.dir/build.make
AI2.exe: CMakeFiles/AI2.dir/linklibs.rsp
AI2.exe: CMakeFiles/AI2.dir/objects1.rsp
AI2.exe: CMakeFiles/AI2.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=F:\programs\AI2\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable AI2.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\AI2.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/AI2.dir/build: AI2.exe

.PHONY : CMakeFiles/AI2.dir/build

CMakeFiles/AI2.dir/requires: CMakeFiles/AI2.dir/main.cpp.obj.requires

.PHONY : CMakeFiles/AI2.dir/requires

CMakeFiles/AI2.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\AI2.dir\cmake_clean.cmake
.PHONY : CMakeFiles/AI2.dir/clean

CMakeFiles/AI2.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" F:\programs\AI2 F:\programs\AI2 F:\programs\AI2\cmake-build-debug F:\programs\AI2\cmake-build-debug F:\programs\AI2\cmake-build-debug\CMakeFiles\AI2.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/AI2.dir/depend

