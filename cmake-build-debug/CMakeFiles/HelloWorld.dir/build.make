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
CMAKE_COMMAND = "C:\Program Files\JetBrains\CLion 2020.3\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\JetBrains\CLion 2020.3\bin\cmake\win\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "C:\Users\Li Wenshu\CLionProjects\Workspace\Adventure-game"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "C:\Users\Li Wenshu\CLionProjects\Workspace\Adventure-game\cmake-build-debug"

# Include any dependencies generated for this target.
include CMakeFiles/HelloWorld.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/HelloWorld.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/HelloWorld.dir/flags.make

CMakeFiles/HelloWorld.dir/main.cpp.obj: CMakeFiles/HelloWorld.dir/flags.make
CMakeFiles/HelloWorld.dir/main.cpp.obj: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="C:\Users\Li Wenshu\CLionProjects\Workspace\Adventure-game\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/HelloWorld.dir/main.cpp.obj"
	C:\MinGW\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\HelloWorld.dir\main.cpp.obj -c "C:\Users\Li Wenshu\CLionProjects\Workspace\Adventure-game\main.cpp"

CMakeFiles/HelloWorld.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/HelloWorld.dir/main.cpp.i"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "C:\Users\Li Wenshu\CLionProjects\Workspace\Adventure-game\main.cpp" > CMakeFiles\HelloWorld.dir\main.cpp.i

CMakeFiles/HelloWorld.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/HelloWorld.dir/main.cpp.s"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "C:\Users\Li Wenshu\CLionProjects\Workspace\Adventure-game\main.cpp" -o CMakeFiles\HelloWorld.dir\main.cpp.s

# Object files for target HelloWorld
HelloWorld_OBJECTS = \
"CMakeFiles/HelloWorld.dir/main.cpp.obj"

# External object files for target HelloWorld
HelloWorld_EXTERNAL_OBJECTS =

HelloWorld.exe: CMakeFiles/HelloWorld.dir/main.cpp.obj
HelloWorld.exe: CMakeFiles/HelloWorld.dir/build.make
HelloWorld.exe: CMakeFiles/HelloWorld.dir/linklibs.rsp
HelloWorld.exe: CMakeFiles/HelloWorld.dir/objects1.rsp
HelloWorld.exe: CMakeFiles/HelloWorld.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="C:\Users\Li Wenshu\CLionProjects\Workspace\Adventure-game\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable HelloWorld.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\HelloWorld.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/HelloWorld.dir/build: HelloWorld.exe

.PHONY : CMakeFiles/HelloWorld.dir/build

CMakeFiles/HelloWorld.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\HelloWorld.dir\cmake_clean.cmake
.PHONY : CMakeFiles/HelloWorld.dir/clean

CMakeFiles/HelloWorld.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" "C:\Users\Li Wenshu\CLionProjects\Workspace\Adventure-game" "C:\Users\Li Wenshu\CLionProjects\Workspace\Adventure-game" "C:\Users\Li Wenshu\CLionProjects\Workspace\Adventure-game\cmake-build-debug" "C:\Users\Li Wenshu\CLionProjects\Workspace\Adventure-game\cmake-build-debug" "C:\Users\Li Wenshu\CLionProjects\Workspace\Adventure-game\cmake-build-debug\CMakeFiles\HelloWorld.dir\DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/HelloWorld.dir/depend

