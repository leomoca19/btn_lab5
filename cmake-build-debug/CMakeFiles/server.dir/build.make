# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.30

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

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = C:\Users\leomo\AppData\Local\Programs\CLion\bin\cmake\win\x64\bin\cmake.exe

# The command to remove a file.
RM = C:\Users\leomo\AppData\Local\Programs\CLion\bin\cmake\win\x64\bin\cmake.exe -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\source\btn_lab5

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\source\btn_lab5\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/server.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/server.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/server.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/server.dir/flags.make

CMakeFiles/server.dir/MenuDisplayServer.cpp.obj: CMakeFiles/server.dir/flags.make
CMakeFiles/server.dir/MenuDisplayServer.cpp.obj: C:/source/btn_lab5/MenuDisplayServer.cpp
CMakeFiles/server.dir/MenuDisplayServer.cpp.obj: CMakeFiles/server.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=C:\source\btn_lab5\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/server.dir/MenuDisplayServer.cpp.obj"
	C:\Users\leomo\AppData\Local\Programs\CLion\bin\mingw\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/server.dir/MenuDisplayServer.cpp.obj -MF CMakeFiles\server.dir\MenuDisplayServer.cpp.obj.d -o CMakeFiles\server.dir\MenuDisplayServer.cpp.obj -c C:\source\btn_lab5\MenuDisplayServer.cpp

CMakeFiles/server.dir/MenuDisplayServer.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/server.dir/MenuDisplayServer.cpp.i"
	C:\Users\leomo\AppData\Local\Programs\CLion\bin\mingw\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\source\btn_lab5\MenuDisplayServer.cpp > CMakeFiles\server.dir\MenuDisplayServer.cpp.i

CMakeFiles/server.dir/MenuDisplayServer.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/server.dir/MenuDisplayServer.cpp.s"
	C:\Users\leomo\AppData\Local\Programs\CLion\bin\mingw\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\source\btn_lab5\MenuDisplayServer.cpp -o CMakeFiles\server.dir\MenuDisplayServer.cpp.s

CMakeFiles/server.dir/Inventory.cpp.obj: CMakeFiles/server.dir/flags.make
CMakeFiles/server.dir/Inventory.cpp.obj: C:/source/btn_lab5/Inventory.cpp
CMakeFiles/server.dir/Inventory.cpp.obj: CMakeFiles/server.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=C:\source\btn_lab5\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/server.dir/Inventory.cpp.obj"
	C:\Users\leomo\AppData\Local\Programs\CLion\bin\mingw\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/server.dir/Inventory.cpp.obj -MF CMakeFiles\server.dir\Inventory.cpp.obj.d -o CMakeFiles\server.dir\Inventory.cpp.obj -c C:\source\btn_lab5\Inventory.cpp

CMakeFiles/server.dir/Inventory.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/server.dir/Inventory.cpp.i"
	C:\Users\leomo\AppData\Local\Programs\CLion\bin\mingw\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\source\btn_lab5\Inventory.cpp > CMakeFiles\server.dir\Inventory.cpp.i

CMakeFiles/server.dir/Inventory.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/server.dir/Inventory.cpp.s"
	C:\Users\leomo\AppData\Local\Programs\CLion\bin\mingw\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\source\btn_lab5\Inventory.cpp -o CMakeFiles\server.dir\Inventory.cpp.s

# Object files for target server
server_OBJECTS = \
"CMakeFiles/server.dir/MenuDisplayServer.cpp.obj" \
"CMakeFiles/server.dir/Inventory.cpp.obj"

# External object files for target server
server_EXTERNAL_OBJECTS =

server.exe: CMakeFiles/server.dir/MenuDisplayServer.cpp.obj
server.exe: CMakeFiles/server.dir/Inventory.cpp.obj
server.exe: CMakeFiles/server.dir/build.make
server.exe: CMakeFiles/server.dir/linkLibs.rsp
server.exe: CMakeFiles/server.dir/objects1.rsp
server.exe: CMakeFiles/server.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=C:\source\btn_lab5\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable server.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\server.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/server.dir/build: server.exe
.PHONY : CMakeFiles/server.dir/build

CMakeFiles/server.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\server.dir\cmake_clean.cmake
.PHONY : CMakeFiles/server.dir/clean

CMakeFiles/server.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\source\btn_lab5 C:\source\btn_lab5 C:\source\btn_lab5\cmake-build-debug C:\source\btn_lab5\cmake-build-debug C:\source\btn_lab5\cmake-build-debug\CMakeFiles\server.dir\DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/server.dir/depend

