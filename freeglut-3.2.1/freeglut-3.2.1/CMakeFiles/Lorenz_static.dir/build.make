# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.20

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
CMAKE_COMMAND = "C:\Program Files\CMake\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\CMake\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "C:\Users\Akshay Kumar U\Downloads\freeglut-3.2.1\freeglut-3.2.1"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "C:\Users\Akshay Kumar U\Downloads\freeglut-3.2.1\freeglut-3.2.1"

# Include any dependencies generated for this target.
include CMakeFiles/Lorenz_static.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/Lorenz_static.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/Lorenz_static.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Lorenz_static.dir/flags.make

CMakeFiles/Lorenz_static.dir/progs/demos/Lorenz/lorenz.c.obj: CMakeFiles/Lorenz_static.dir/flags.make
CMakeFiles/Lorenz_static.dir/progs/demos/Lorenz/lorenz.c.obj: CMakeFiles/Lorenz_static.dir/includes_C.rsp
CMakeFiles/Lorenz_static.dir/progs/demos/Lorenz/lorenz.c.obj: progs/demos/Lorenz/lorenz.c
CMakeFiles/Lorenz_static.dir/progs/demos/Lorenz/lorenz.c.obj: CMakeFiles/Lorenz_static.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="C:\Users\Akshay Kumar U\Downloads\freeglut-3.2.1\freeglut-3.2.1\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/Lorenz_static.dir/progs/demos/Lorenz/lorenz.c.obj"
	C:\PROGRA~1\mingw-w64\x86_64-8.1.0-posix-seh-rt_v6-rev0\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/Lorenz_static.dir/progs/demos/Lorenz/lorenz.c.obj -MF CMakeFiles\Lorenz_static.dir\progs\demos\Lorenz\lorenz.c.obj.d -o CMakeFiles\Lorenz_static.dir\progs\demos\Lorenz\lorenz.c.obj -c "C:\Users\Akshay Kumar U\Downloads\freeglut-3.2.1\freeglut-3.2.1\progs\demos\Lorenz\lorenz.c"

CMakeFiles/Lorenz_static.dir/progs/demos/Lorenz/lorenz.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/Lorenz_static.dir/progs/demos/Lorenz/lorenz.c.i"
	C:\PROGRA~1\mingw-w64\x86_64-8.1.0-posix-seh-rt_v6-rev0\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E "C:\Users\Akshay Kumar U\Downloads\freeglut-3.2.1\freeglut-3.2.1\progs\demos\Lorenz\lorenz.c" > CMakeFiles\Lorenz_static.dir\progs\demos\Lorenz\lorenz.c.i

CMakeFiles/Lorenz_static.dir/progs/demos/Lorenz/lorenz.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/Lorenz_static.dir/progs/demos/Lorenz/lorenz.c.s"
	C:\PROGRA~1\mingw-w64\x86_64-8.1.0-posix-seh-rt_v6-rev0\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S "C:\Users\Akshay Kumar U\Downloads\freeglut-3.2.1\freeglut-3.2.1\progs\demos\Lorenz\lorenz.c" -o CMakeFiles\Lorenz_static.dir\progs\demos\Lorenz\lorenz.c.s

# Object files for target Lorenz_static
Lorenz_static_OBJECTS = \
"CMakeFiles/Lorenz_static.dir/progs/demos/Lorenz/lorenz.c.obj"

# External object files for target Lorenz_static
Lorenz_static_EXTERNAL_OBJECTS =

bin/Lorenz_static.exe: CMakeFiles/Lorenz_static.dir/progs/demos/Lorenz/lorenz.c.obj
bin/Lorenz_static.exe: CMakeFiles/Lorenz_static.dir/build.make
bin/Lorenz_static.exe: lib/libfreeglut_static.a
bin/Lorenz_static.exe: CMakeFiles/Lorenz_static.dir/linklibs.rsp
bin/Lorenz_static.exe: CMakeFiles/Lorenz_static.dir/objects1.rsp
bin/Lorenz_static.exe: CMakeFiles/Lorenz_static.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="C:\Users\Akshay Kumar U\Downloads\freeglut-3.2.1\freeglut-3.2.1\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable bin\Lorenz_static.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\Lorenz_static.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Lorenz_static.dir/build: bin/Lorenz_static.exe
.PHONY : CMakeFiles/Lorenz_static.dir/build

CMakeFiles/Lorenz_static.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\Lorenz_static.dir\cmake_clean.cmake
.PHONY : CMakeFiles/Lorenz_static.dir/clean

CMakeFiles/Lorenz_static.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" "C:\Users\Akshay Kumar U\Downloads\freeglut-3.2.1\freeglut-3.2.1" "C:\Users\Akshay Kumar U\Downloads\freeglut-3.2.1\freeglut-3.2.1" "C:\Users\Akshay Kumar U\Downloads\freeglut-3.2.1\freeglut-3.2.1" "C:\Users\Akshay Kumar U\Downloads\freeglut-3.2.1\freeglut-3.2.1" "C:\Users\Akshay Kumar U\Downloads\freeglut-3.2.1\freeglut-3.2.1\CMakeFiles\Lorenz_static.dir\DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/Lorenz_static.dir/depend

