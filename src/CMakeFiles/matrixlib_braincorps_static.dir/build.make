# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 2.8

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
CMAKE_SOURCE_DIR = /home/kushal/Documents/matrixlib_braincorps

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/kushal/Documents/matrixlib_braincorps

# Include any dependencies generated for this target.
include src/CMakeFiles/matrixlib_braincorps_static.dir/depend.make

# Include the progress variables for this target.
include src/CMakeFiles/matrixlib_braincorps_static.dir/progress.make

# Include the compile flags for this target's objects.
include src/CMakeFiles/matrixlib_braincorps_static.dir/flags.make

src/CMakeFiles/matrixlib_braincorps_static.dir/matrixlib.cpp.o: src/CMakeFiles/matrixlib_braincorps_static.dir/flags.make
src/CMakeFiles/matrixlib_braincorps_static.dir/matrixlib.cpp.o: src/matrixlib.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/kushal/Documents/matrixlib_braincorps/CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object src/CMakeFiles/matrixlib_braincorps_static.dir/matrixlib.cpp.o"
	cd /home/kushal/Documents/matrixlib_braincorps/src && /usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/matrixlib_braincorps_static.dir/matrixlib.cpp.o -c /home/kushal/Documents/matrixlib_braincorps/src/matrixlib.cpp

src/CMakeFiles/matrixlib_braincorps_static.dir/matrixlib.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/matrixlib_braincorps_static.dir/matrixlib.cpp.i"
	cd /home/kushal/Documents/matrixlib_braincorps/src && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/kushal/Documents/matrixlib_braincorps/src/matrixlib.cpp > CMakeFiles/matrixlib_braincorps_static.dir/matrixlib.cpp.i

src/CMakeFiles/matrixlib_braincorps_static.dir/matrixlib.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/matrixlib_braincorps_static.dir/matrixlib.cpp.s"
	cd /home/kushal/Documents/matrixlib_braincorps/src && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/kushal/Documents/matrixlib_braincorps/src/matrixlib.cpp -o CMakeFiles/matrixlib_braincorps_static.dir/matrixlib.cpp.s

src/CMakeFiles/matrixlib_braincorps_static.dir/matrixlib.cpp.o.requires:
.PHONY : src/CMakeFiles/matrixlib_braincorps_static.dir/matrixlib.cpp.o.requires

src/CMakeFiles/matrixlib_braincorps_static.dir/matrixlib.cpp.o.provides: src/CMakeFiles/matrixlib_braincorps_static.dir/matrixlib.cpp.o.requires
	$(MAKE) -f src/CMakeFiles/matrixlib_braincorps_static.dir/build.make src/CMakeFiles/matrixlib_braincorps_static.dir/matrixlib.cpp.o.provides.build
.PHONY : src/CMakeFiles/matrixlib_braincorps_static.dir/matrixlib.cpp.o.provides

src/CMakeFiles/matrixlib_braincorps_static.dir/matrixlib.cpp.o.provides.build: src/CMakeFiles/matrixlib_braincorps_static.dir/matrixlib.cpp.o

# Object files for target matrixlib_braincorps_static
matrixlib_braincorps_static_OBJECTS = \
"CMakeFiles/matrixlib_braincorps_static.dir/matrixlib.cpp.o"

# External object files for target matrixlib_braincorps_static
matrixlib_braincorps_static_EXTERNAL_OBJECTS =

src/libmatrixlib_braincorps.a: src/CMakeFiles/matrixlib_braincorps_static.dir/matrixlib.cpp.o
src/libmatrixlib_braincorps.a: src/CMakeFiles/matrixlib_braincorps_static.dir/build.make
src/libmatrixlib_braincorps.a: src/CMakeFiles/matrixlib_braincorps_static.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --red --bold "Linking CXX static library libmatrixlib_braincorps.a"
	cd /home/kushal/Documents/matrixlib_braincorps/src && $(CMAKE_COMMAND) -P CMakeFiles/matrixlib_braincorps_static.dir/cmake_clean_target.cmake
	cd /home/kushal/Documents/matrixlib_braincorps/src && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/matrixlib_braincorps_static.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
src/CMakeFiles/matrixlib_braincorps_static.dir/build: src/libmatrixlib_braincorps.a
.PHONY : src/CMakeFiles/matrixlib_braincorps_static.dir/build

src/CMakeFiles/matrixlib_braincorps_static.dir/requires: src/CMakeFiles/matrixlib_braincorps_static.dir/matrixlib.cpp.o.requires
.PHONY : src/CMakeFiles/matrixlib_braincorps_static.dir/requires

src/CMakeFiles/matrixlib_braincorps_static.dir/clean:
	cd /home/kushal/Documents/matrixlib_braincorps/src && $(CMAKE_COMMAND) -P CMakeFiles/matrixlib_braincorps_static.dir/cmake_clean.cmake
.PHONY : src/CMakeFiles/matrixlib_braincorps_static.dir/clean

src/CMakeFiles/matrixlib_braincorps_static.dir/depend:
	cd /home/kushal/Documents/matrixlib_braincorps && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/kushal/Documents/matrixlib_braincorps /home/kushal/Documents/matrixlib_braincorps/src /home/kushal/Documents/matrixlib_braincorps /home/kushal/Documents/matrixlib_braincorps/src /home/kushal/Documents/matrixlib_braincorps/src/CMakeFiles/matrixlib_braincorps_static.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : src/CMakeFiles/matrixlib_braincorps_static.dir/depend

