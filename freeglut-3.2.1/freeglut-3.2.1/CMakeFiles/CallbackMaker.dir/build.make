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
include CMakeFiles/CallbackMaker.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/CallbackMaker.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/CallbackMaker.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/CallbackMaker.dir/flags.make

CMakeFiles/CallbackMaker.dir/progs/demos/CallbackMaker/CallbackMaker.c.obj: CMakeFiles/CallbackMaker.dir/flags.make
CMakeFiles/CallbackMaker.dir/progs/demos/CallbackMaker/CallbackMaker.c.obj: CMakeFiles/CallbackMaker.dir/includes_C.rsp
CMakeFiles/CallbackMaker.dir/progs/demos/CallbackMaker/CallbackMaker.c.obj: progs/demos/CallbackMaker/CallbackMaker.c
CMakeFiles/CallbackMaker.dir/progs/demos/CallbackMaker/CallbackMaker.c.obj: CMakeFiles/CallbackMaker.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="C:\Users\Akshay Kumar U\Downloads\freeglut-3.2.1\freeglut-3.2.1\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/CallbackMaker.dir/progs/demos/CallbackMaker/CallbackMaker.c.obj"
	C:\PROGRA~1\mingw-w64\x86_64-8.1.0-posix-seh-rt_v6-rev0\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/CallbackMaker.dir/progs/demos/CallbackMaker/CallbackMaker.c.obj -MF CMakeFiles\CallbackMaker.dir\progs\demos\CallbackMaker\CallbackMaker.c.obj.d -o CMakeFiles\CallbackMaker.dir\progs\demos\CallbackMaker\CallbackMaker.c.obj -c "C:\Users\Akshay Kumar U\Downloads\freeglut-3.2.1\freeglut-3.2.1\progs\demos\CallbackMaker\CallbackMaker.c"

CMakeFiles/CallbackMaker.dir/progs/demos/CallbackMaker/CallbackMaker.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/CallbackMaker.dir/progs/demos/CallbackMaker/CallbackMaker.c.i"
	C:\PROGRA~1\mingw-w64\x86_64-8.1.0-posix-seh-rt_v6-rev0\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E "C:\Users\Akshay Kumar U\Downloads\freeglut-3.2.1\freeglut-3.2.1\progs\demos\CallbackMaker\CallbackMaker.c" > CMakeFiles\CallbackMaker.dir\progs\demos\CallbackMaker\CallbackMaker.c.i

CMakeFiles/CallbackMaker.dir/progs/demos/CallbackMaker/CallbackMaker.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/CallbackMaker.dir/progs/demos/CallbackMaker/CallbackMaker.c.s"
	C:\PROGRA~1\mingw-w64\x86_64-8.1.0-posix-seh-rt_v6-rev0\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S "C:\Users\Akshay Kumar U\Downloads\freeglut-3.2.1\freeglut-3.2.1\progs\demos\CallbackMaker\CallbackMaker.c" -o CMakeFiles\CallbackMaker.dir\progs\demos\CallbackMaker\CallbackMaker.c.s

# Object files for target CallbackMaker
CallbackMaker_OBJECTS = \
"CMakeFiles/CallbackMaker.dir/progs/demos/CallbackMaker/CallbackMaker.c.obj"

# External object files for target CallbackMaker
CallbackMaker_EXTERNAL_OBJECTS =

bin/CallbackMaker.exe: CMakeFiles/CallbackMaker.dir/progs/demos/CallbackMaker/CallbackMaker.c.obj
bin/CallbackMaker.exe: CMakeFiles/CallbackMaker.dir/build.make
bin/CallbackMaker.exe: lib/libfreeglut.dll.a
bin/CallbackMaker.exe: CMakeFiles/CallbackMaker.dir/linklibs.rsp
bin/CallbackMaker.exe: CMakeFiles/CallbackMaker.dir/objects1.rsp
bin/CallbackMaker.exe: CMakeFiles/CallbackMaker.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="C:\Users\Akshay Kumar U\Downloads\freeglut-3.2.1\freeglut-3.2.1\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable bin\CallbackMaker.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\CallbackMaker.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/CallbackMaker.dir/build: bin/CallbackMaker.exe
.PHONY : CMakeFiles/CallbackMaker.dir/build

CMakeFiles/CallbackMaker.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\CallbackMaker.dir\cmake_clean.cmake
.PHONY : CMakeFiles/CallbackMaker.dir/clean

CMakeFiles/CallbackMaker.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" "C:\Users\Akshay Kumar U\Downloads\freeglut-3.2.1\freeglut-3.2.1" "C:\Users\Akshay Kumar U\Downloads\freeglut-3.2.1\freeglut-3.2.1" "C:\Users\Akshay Kumar U\Downloads\freeglut-3.2.1\freeglut-3.2.1" "C:\Users\Akshay Kumar U\Downloads\freeglut-3.2.1\freeglut-3.2.1" "C:\Users\Akshay Kumar U\Downloads\freeglut-3.2.1\freeglut-3.2.1\CMakeFiles\CallbackMaker.dir\DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/CallbackMaker.dir/depend

