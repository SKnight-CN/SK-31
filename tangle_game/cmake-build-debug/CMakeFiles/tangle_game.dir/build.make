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
CMAKE_SOURCE_DIR = "F:\programming tools\tangle game"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "F:\programming tools\tangle game\cmake-build-debug"

# Include any dependencies generated for this target.
include CMakeFiles/tangle_game.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/tangle_game.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/tangle_game.dir/flags.make

CMakeFiles/tangle_game.dir/main.cpp.obj: CMakeFiles/tangle_game.dir/flags.make
CMakeFiles/tangle_game.dir/main.cpp.obj: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="F:\programming tools\tangle game\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/tangle_game.dir/main.cpp.obj"
	F:\GCC\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\tangle_game.dir\main.cpp.obj -c "F:\programming tools\tangle game\main.cpp"

CMakeFiles/tangle_game.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/tangle_game.dir/main.cpp.i"
	F:\GCC\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "F:\programming tools\tangle game\main.cpp" > CMakeFiles\tangle_game.dir\main.cpp.i

CMakeFiles/tangle_game.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/tangle_game.dir/main.cpp.s"
	F:\GCC\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "F:\programming tools\tangle game\main.cpp" -o CMakeFiles\tangle_game.dir\main.cpp.s

CMakeFiles/tangle_game.dir/main.cpp.obj.requires:

.PHONY : CMakeFiles/tangle_game.dir/main.cpp.obj.requires

CMakeFiles/tangle_game.dir/main.cpp.obj.provides: CMakeFiles/tangle_game.dir/main.cpp.obj.requires
	$(MAKE) -f CMakeFiles\tangle_game.dir\build.make CMakeFiles/tangle_game.dir/main.cpp.obj.provides.build
.PHONY : CMakeFiles/tangle_game.dir/main.cpp.obj.provides

CMakeFiles/tangle_game.dir/main.cpp.obj.provides.build: CMakeFiles/tangle_game.dir/main.cpp.obj


# Object files for target tangle_game
tangle_game_OBJECTS = \
"CMakeFiles/tangle_game.dir/main.cpp.obj"

# External object files for target tangle_game
tangle_game_EXTERNAL_OBJECTS =

tangle_game.exe: CMakeFiles/tangle_game.dir/main.cpp.obj
tangle_game.exe: CMakeFiles/tangle_game.dir/build.make
tangle_game.exe: CMakeFiles/tangle_game.dir/linklibs.rsp
tangle_game.exe: CMakeFiles/tangle_game.dir/objects1.rsp
tangle_game.exe: CMakeFiles/tangle_game.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="F:\programming tools\tangle game\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable tangle_game.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\tangle_game.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/tangle_game.dir/build: tangle_game.exe

.PHONY : CMakeFiles/tangle_game.dir/build

CMakeFiles/tangle_game.dir/requires: CMakeFiles/tangle_game.dir/main.cpp.obj.requires

.PHONY : CMakeFiles/tangle_game.dir/requires

CMakeFiles/tangle_game.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\tangle_game.dir\cmake_clean.cmake
.PHONY : CMakeFiles/tangle_game.dir/clean

CMakeFiles/tangle_game.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" "F:\programming tools\tangle game" "F:\programming tools\tangle game" "F:\programming tools\tangle game\cmake-build-debug" "F:\programming tools\tangle game\cmake-build-debug" "F:\programming tools\tangle game\cmake-build-debug\CMakeFiles\tangle_game.dir\DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/tangle_game.dir/depend

