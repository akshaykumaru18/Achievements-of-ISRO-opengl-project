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
include CMakeFiles/One_static.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/One_static.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/One_static.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/One_static.dir/flags.make

CMakeFiles/One_static.dir/progs/demos/One/one.c.obj: CMakeFiles/One_static.dir/flags.make
CMakeFiles/One_static.dir/progs/demos/One/one.c.obj: CMakeFiles/One_static.dir/includes_C.rsp
CMakeFiles/One_static.dir/progs/demos/One/one.c.obj: progs/demos/One/one.c
CMakeFiles/One_static.dir/progs/demos/One/one.c.obj: CMakeFiles/One_static.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="C:\Users\Akshay Kumar U\Downloads\freeglut-3.2.1\freeglut-3.2.1\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/One_static.dir/progs/demos/One/one.c.obj"
	C:\PROGRA~1\mingw-w64\x86_64-8.1.0-posix-seh-rt_v6-rev0\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/One_static.dir/progs/demos/One/one.c.obj -MF CMakeFiles\One_static.dir\progs\demos\One\one.c.obj.d -o CMakeFiles\One_static.dir\progs\demos\One\one.c.obj -c "C:\Users\Akshay Kumar U\Downloads\freeglut-3.2.1\freeglut-3.2.1\progs\demos\One\one.c"

CMakeFiles/One_static.dir/progs/demos/One/one.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/One_static.dir/progs/demos/One/one.c.i"
	C:\PROGRA~1\mingw-w64\x86_64-8.1.0-posix-seh-rt_v6-rev0\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E "C:\Users\Akshay Kumar U\Downloads\freeglut-3.2.1\freeglut-3.2.1\progs\demos\One\one.c" > CMakeFiles\One_static.dir\progs\demos\One\one.c.i

CMakeFiles/One_static.dir/progs/demos/One/one.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/One_static.dir/progs/demos/One/one.c.s"
	C:\PROGRA~1\mingw-w64\x86_64-8.1.0-posix-seh-rt_v6-rev0\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S "C:\Users\Akshay Kumar U\Downloads\freeglut-3.2.1\freeglut-3.2.1\progs\demos\One\one.c" -o CMakeFiles\One_static.dir\progs\demos\One\one.c.s

CMakeFiles/One_static.dir/progs/demos/One/one.rc.obj: CMakeFiles/One_static.dir/flags.make
CMakeFiles/One_static.dir/progs/demos/One/one.rc.obj: progs/demos/One/one.rc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="C:\Users\Akshay Kumar U\Downloads\freeglut-3.2.1\freeglut-3.2.1\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Building RC object CMakeFiles/One_static.dir/progs/demos/One/one.rc.obj"
	C:\PROGRA~1\mingw-w64\x86_64-8.1.0-posix-seh-rt_v6-rev0\mingw64\bin\windres.exe -O coff $(RC_DEFINES) $(RC_INCLUDES) $(RC_FLAGS) "C:\Users\Akshay Kumar U\Downloads\freeglut-3.2.1\freeglut-3.2.1\progs\demos\One\one.rc" CMakeFiles\One_static.dir\progs\demos\One\one.rc.obj

# Object files for target One_static
One_static_OBJECTS = \
"CMakeFiles/One_static.dir/progs/demos/One/one.c.obj" \
"CMakeFiles/One_static.dir/progs/demos/One/one.rc.obj"

# External object files for target One_static
One_static_EXTERNAL_OBJECTS =

bin/One_static.exe: CMakeFiles/One_static.dir/progs/demos/One/one.c.obj
bin/One_static.exe: CMakeFiles/One_static.dir/progs/demos/One/one.rc.obj
bin/One_static.exe: CMakeFiles/One_static.dir/build.make
bin/One_static.exe: lib/libfreeglut_static.a
bin/One_static.exe: CMakeFiles/One_static.dir/linklibs.rsp
bin/One_static.exe: CMakeFiles/One_static.dir/objects1.rsp
bin/One_static.exe: CMakeFiles/One_static.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="C:\Users\Akshay Kumar U\Downloads\freeglut-3.2.1\freeglut-3.2.1\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_3) "Linking C executable bin\One_static.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\One_static.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/One_static.dir/build: bin/One_static.exe
.PHONY : CMakeFiles/One_static.dir/build

CMakeFiles/One_static.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\One_static.dir\cmake_clean.cmake
.PHONY : CMakeFiles/One_static.dir/clean

CMakeFiles/One_static.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" "C:\Users\Akshay Kumar U\Downloads\freeglut-3.2.1\freeglut-3.2.1" "C:\Users\Akshay Kumar U\Downloads\freeglut-3.2.1\freeglut-3.2.1" "C:\Users\Akshay Kumar U\Downloads\freeglut-3.2.1\freeglut-3.2.1" "C:\Users\Akshay Kumar U\Downloads\freeglut-3.2.1\freeglut-3.2.1" "C:\Users\Akshay Kumar U\Downloads\freeglut-3.2.1\freeglut-3.2.1\CMakeFiles\One_static.dir\DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/One_static.dir/depend

