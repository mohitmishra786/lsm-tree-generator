# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.22

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

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/chessman/Desktop/Projects/Github/lsm-tree-generator

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/chessman/Desktop/Projects/Github/lsm-tree-generator/build

# Include any dependencies generated for this target.
include CMakeFiles/lsm_tree.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/lsm_tree.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/lsm_tree.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/lsm_tree.dir/flags.make

CMakeFiles/lsm_tree.dir/main.c.o: CMakeFiles/lsm_tree.dir/flags.make
CMakeFiles/lsm_tree.dir/main.c.o: ../main.c
CMakeFiles/lsm_tree.dir/main.c.o: CMakeFiles/lsm_tree.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/chessman/Desktop/Projects/Github/lsm-tree-generator/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/lsm_tree.dir/main.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/lsm_tree.dir/main.c.o -MF CMakeFiles/lsm_tree.dir/main.c.o.d -o CMakeFiles/lsm_tree.dir/main.c.o -c /home/chessman/Desktop/Projects/Github/lsm-tree-generator/main.c

CMakeFiles/lsm_tree.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/lsm_tree.dir/main.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/chessman/Desktop/Projects/Github/lsm-tree-generator/main.c > CMakeFiles/lsm_tree.dir/main.c.i

CMakeFiles/lsm_tree.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/lsm_tree.dir/main.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/chessman/Desktop/Projects/Github/lsm-tree-generator/main.c -o CMakeFiles/lsm_tree.dir/main.c.s

CMakeFiles/lsm_tree.dir/src/cli.c.o: CMakeFiles/lsm_tree.dir/flags.make
CMakeFiles/lsm_tree.dir/src/cli.c.o: ../src/cli.c
CMakeFiles/lsm_tree.dir/src/cli.c.o: CMakeFiles/lsm_tree.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/chessman/Desktop/Projects/Github/lsm-tree-generator/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/lsm_tree.dir/src/cli.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/lsm_tree.dir/src/cli.c.o -MF CMakeFiles/lsm_tree.dir/src/cli.c.o.d -o CMakeFiles/lsm_tree.dir/src/cli.c.o -c /home/chessman/Desktop/Projects/Github/lsm-tree-generator/src/cli.c

CMakeFiles/lsm_tree.dir/src/cli.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/lsm_tree.dir/src/cli.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/chessman/Desktop/Projects/Github/lsm-tree-generator/src/cli.c > CMakeFiles/lsm_tree.dir/src/cli.c.i

CMakeFiles/lsm_tree.dir/src/cli.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/lsm_tree.dir/src/cli.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/chessman/Desktop/Projects/Github/lsm-tree-generator/src/cli.c -o CMakeFiles/lsm_tree.dir/src/cli.c.s

CMakeFiles/lsm_tree.dir/src/lsm_tree.c.o: CMakeFiles/lsm_tree.dir/flags.make
CMakeFiles/lsm_tree.dir/src/lsm_tree.c.o: ../src/lsm_tree.c
CMakeFiles/lsm_tree.dir/src/lsm_tree.c.o: CMakeFiles/lsm_tree.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/chessman/Desktop/Projects/Github/lsm-tree-generator/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building C object CMakeFiles/lsm_tree.dir/src/lsm_tree.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/lsm_tree.dir/src/lsm_tree.c.o -MF CMakeFiles/lsm_tree.dir/src/lsm_tree.c.o.d -o CMakeFiles/lsm_tree.dir/src/lsm_tree.c.o -c /home/chessman/Desktop/Projects/Github/lsm-tree-generator/src/lsm_tree.c

CMakeFiles/lsm_tree.dir/src/lsm_tree.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/lsm_tree.dir/src/lsm_tree.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/chessman/Desktop/Projects/Github/lsm-tree-generator/src/lsm_tree.c > CMakeFiles/lsm_tree.dir/src/lsm_tree.c.i

CMakeFiles/lsm_tree.dir/src/lsm_tree.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/lsm_tree.dir/src/lsm_tree.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/chessman/Desktop/Projects/Github/lsm-tree-generator/src/lsm_tree.c -o CMakeFiles/lsm_tree.dir/src/lsm_tree.c.s

CMakeFiles/lsm_tree.dir/src/memtable.c.o: CMakeFiles/lsm_tree.dir/flags.make
CMakeFiles/lsm_tree.dir/src/memtable.c.o: ../src/memtable.c
CMakeFiles/lsm_tree.dir/src/memtable.c.o: CMakeFiles/lsm_tree.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/chessman/Desktop/Projects/Github/lsm-tree-generator/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building C object CMakeFiles/lsm_tree.dir/src/memtable.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/lsm_tree.dir/src/memtable.c.o -MF CMakeFiles/lsm_tree.dir/src/memtable.c.o.d -o CMakeFiles/lsm_tree.dir/src/memtable.c.o -c /home/chessman/Desktop/Projects/Github/lsm-tree-generator/src/memtable.c

CMakeFiles/lsm_tree.dir/src/memtable.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/lsm_tree.dir/src/memtable.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/chessman/Desktop/Projects/Github/lsm-tree-generator/src/memtable.c > CMakeFiles/lsm_tree.dir/src/memtable.c.i

CMakeFiles/lsm_tree.dir/src/memtable.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/lsm_tree.dir/src/memtable.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/chessman/Desktop/Projects/Github/lsm-tree-generator/src/memtable.c -o CMakeFiles/lsm_tree.dir/src/memtable.c.s

CMakeFiles/lsm_tree.dir/src/sstable.c.o: CMakeFiles/lsm_tree.dir/flags.make
CMakeFiles/lsm_tree.dir/src/sstable.c.o: ../src/sstable.c
CMakeFiles/lsm_tree.dir/src/sstable.c.o: CMakeFiles/lsm_tree.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/chessman/Desktop/Projects/Github/lsm-tree-generator/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building C object CMakeFiles/lsm_tree.dir/src/sstable.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/lsm_tree.dir/src/sstable.c.o -MF CMakeFiles/lsm_tree.dir/src/sstable.c.o.d -o CMakeFiles/lsm_tree.dir/src/sstable.c.o -c /home/chessman/Desktop/Projects/Github/lsm-tree-generator/src/sstable.c

CMakeFiles/lsm_tree.dir/src/sstable.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/lsm_tree.dir/src/sstable.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/chessman/Desktop/Projects/Github/lsm-tree-generator/src/sstable.c > CMakeFiles/lsm_tree.dir/src/sstable.c.i

CMakeFiles/lsm_tree.dir/src/sstable.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/lsm_tree.dir/src/sstable.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/chessman/Desktop/Projects/Github/lsm-tree-generator/src/sstable.c -o CMakeFiles/lsm_tree.dir/src/sstable.c.s

# Object files for target lsm_tree
lsm_tree_OBJECTS = \
"CMakeFiles/lsm_tree.dir/main.c.o" \
"CMakeFiles/lsm_tree.dir/src/cli.c.o" \
"CMakeFiles/lsm_tree.dir/src/lsm_tree.c.o" \
"CMakeFiles/lsm_tree.dir/src/memtable.c.o" \
"CMakeFiles/lsm_tree.dir/src/sstable.c.o"

# External object files for target lsm_tree
lsm_tree_EXTERNAL_OBJECTS =

lsm_tree: CMakeFiles/lsm_tree.dir/main.c.o
lsm_tree: CMakeFiles/lsm_tree.dir/src/cli.c.o
lsm_tree: CMakeFiles/lsm_tree.dir/src/lsm_tree.c.o
lsm_tree: CMakeFiles/lsm_tree.dir/src/memtable.c.o
lsm_tree: CMakeFiles/lsm_tree.dir/src/sstable.c.o
lsm_tree: CMakeFiles/lsm_tree.dir/build.make
lsm_tree: CMakeFiles/lsm_tree.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/chessman/Desktop/Projects/Github/lsm-tree-generator/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Linking C executable lsm_tree"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/lsm_tree.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/lsm_tree.dir/build: lsm_tree
.PHONY : CMakeFiles/lsm_tree.dir/build

CMakeFiles/lsm_tree.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/lsm_tree.dir/cmake_clean.cmake
.PHONY : CMakeFiles/lsm_tree.dir/clean

CMakeFiles/lsm_tree.dir/depend:
	cd /home/chessman/Desktop/Projects/Github/lsm-tree-generator/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/chessman/Desktop/Projects/Github/lsm-tree-generator /home/chessman/Desktop/Projects/Github/lsm-tree-generator /home/chessman/Desktop/Projects/Github/lsm-tree-generator/build /home/chessman/Desktop/Projects/Github/lsm-tree-generator/build /home/chessman/Desktop/Projects/Github/lsm-tree-generator/build/CMakeFiles/lsm_tree.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/lsm_tree.dir/depend
