# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.13

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
CMAKE_COMMAND = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake

# The command to remove a file.
RM = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/ioanajercan/CLionProjects/uSDA1

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/ioanajercan/CLionProjects/uSDA1/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/uSDA1.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/uSDA1.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/uSDA1.dir/flags.make

CMakeFiles/uSDA1.dir/main.cpp.o: CMakeFiles/uSDA1.dir/flags.make
CMakeFiles/uSDA1.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/ioanajercan/CLionProjects/uSDA1/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/uSDA1.dir/main.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/uSDA1.dir/main.cpp.o -c /Users/ioanajercan/CLionProjects/uSDA1/main.cpp

CMakeFiles/uSDA1.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/uSDA1.dir/main.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/ioanajercan/CLionProjects/uSDA1/main.cpp > CMakeFiles/uSDA1.dir/main.cpp.i

CMakeFiles/uSDA1.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/uSDA1.dir/main.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/ioanajercan/CLionProjects/uSDA1/main.cpp -o CMakeFiles/uSDA1.dir/main.cpp.s

CMakeFiles/uSDA1.dir/Container.cpp.o: CMakeFiles/uSDA1.dir/flags.make
CMakeFiles/uSDA1.dir/Container.cpp.o: ../Container.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/ioanajercan/CLionProjects/uSDA1/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/uSDA1.dir/Container.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/uSDA1.dir/Container.cpp.o -c /Users/ioanajercan/CLionProjects/uSDA1/Container.cpp

CMakeFiles/uSDA1.dir/Container.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/uSDA1.dir/Container.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/ioanajercan/CLionProjects/uSDA1/Container.cpp > CMakeFiles/uSDA1.dir/Container.cpp.i

CMakeFiles/uSDA1.dir/Container.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/uSDA1.dir/Container.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/ioanajercan/CLionProjects/uSDA1/Container.cpp -o CMakeFiles/uSDA1.dir/Container.cpp.s

CMakeFiles/uSDA1.dir/MatrixIterator.cpp.o: CMakeFiles/uSDA1.dir/flags.make
CMakeFiles/uSDA1.dir/MatrixIterator.cpp.o: ../MatrixIterator.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/ioanajercan/CLionProjects/uSDA1/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/uSDA1.dir/MatrixIterator.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/uSDA1.dir/MatrixIterator.cpp.o -c /Users/ioanajercan/CLionProjects/uSDA1/MatrixIterator.cpp

CMakeFiles/uSDA1.dir/MatrixIterator.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/uSDA1.dir/MatrixIterator.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/ioanajercan/CLionProjects/uSDA1/MatrixIterator.cpp > CMakeFiles/uSDA1.dir/MatrixIterator.cpp.i

CMakeFiles/uSDA1.dir/MatrixIterator.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/uSDA1.dir/MatrixIterator.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/ioanajercan/CLionProjects/uSDA1/MatrixIterator.cpp -o CMakeFiles/uSDA1.dir/MatrixIterator.cpp.s

# Object files for target uSDA1
uSDA1_OBJECTS = \
"CMakeFiles/uSDA1.dir/main.cpp.o" \
"CMakeFiles/uSDA1.dir/Container.cpp.o" \
"CMakeFiles/uSDA1.dir/MatrixIterator.cpp.o"

# External object files for target uSDA1
uSDA1_EXTERNAL_OBJECTS =

uSDA1: CMakeFiles/uSDA1.dir/main.cpp.o
uSDA1: CMakeFiles/uSDA1.dir/Container.cpp.o
uSDA1: CMakeFiles/uSDA1.dir/MatrixIterator.cpp.o
uSDA1: CMakeFiles/uSDA1.dir/build.make
uSDA1: CMakeFiles/uSDA1.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/ioanajercan/CLionProjects/uSDA1/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Linking CXX executable uSDA1"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/uSDA1.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/uSDA1.dir/build: uSDA1

.PHONY : CMakeFiles/uSDA1.dir/build

CMakeFiles/uSDA1.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/uSDA1.dir/cmake_clean.cmake
.PHONY : CMakeFiles/uSDA1.dir/clean

CMakeFiles/uSDA1.dir/depend:
	cd /Users/ioanajercan/CLionProjects/uSDA1/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/ioanajercan/CLionProjects/uSDA1 /Users/ioanajercan/CLionProjects/uSDA1 /Users/ioanajercan/CLionProjects/uSDA1/cmake-build-debug /Users/ioanajercan/CLionProjects/uSDA1/cmake-build-debug /Users/ioanajercan/CLionProjects/uSDA1/cmake-build-debug/CMakeFiles/uSDA1.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/uSDA1.dir/depend
