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
CMAKE_SOURCE_DIR = /workspaces/casa-vegetativa

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /workspaces/casa-vegetativa

# Include any dependencies generated for this target.
include CMakeFiles/MyExe.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/MyExe.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/MyExe.dir/flags.make

CMakeFiles/MyExe.dir/src/Greenhouse.cpp.o: CMakeFiles/MyExe.dir/flags.make
CMakeFiles/MyExe.dir/src/Greenhouse.cpp.o: src/Greenhouse.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/workspaces/casa-vegetativa/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/MyExe.dir/src/Greenhouse.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/MyExe.dir/src/Greenhouse.cpp.o -c /workspaces/casa-vegetativa/src/Greenhouse.cpp

CMakeFiles/MyExe.dir/src/Greenhouse.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/MyExe.dir/src/Greenhouse.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /workspaces/casa-vegetativa/src/Greenhouse.cpp > CMakeFiles/MyExe.dir/src/Greenhouse.cpp.i

CMakeFiles/MyExe.dir/src/Greenhouse.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/MyExe.dir/src/Greenhouse.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /workspaces/casa-vegetativa/src/Greenhouse.cpp -o CMakeFiles/MyExe.dir/src/Greenhouse.cpp.s

# Object files for target MyExe
MyExe_OBJECTS = \
"CMakeFiles/MyExe.dir/src/Greenhouse.cpp.o"

# External object files for target MyExe
MyExe_EXTERNAL_OBJECTS =

MyExe: CMakeFiles/MyExe.dir/src/Greenhouse.cpp.o
MyExe: CMakeFiles/MyExe.dir/build.make
MyExe: CMakeFiles/MyExe.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/workspaces/casa-vegetativa/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable MyExe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/MyExe.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/MyExe.dir/build: MyExe

.PHONY : CMakeFiles/MyExe.dir/build

CMakeFiles/MyExe.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/MyExe.dir/cmake_clean.cmake
.PHONY : CMakeFiles/MyExe.dir/clean

CMakeFiles/MyExe.dir/depend:
	cd /workspaces/casa-vegetativa && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /workspaces/casa-vegetativa /workspaces/casa-vegetativa /workspaces/casa-vegetativa /workspaces/casa-vegetativa /workspaces/casa-vegetativa/CMakeFiles/MyExe.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/MyExe.dir/depend

