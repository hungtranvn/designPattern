# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.14

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
CMAKE_SOURCE_DIR = /home/hungtran/Workspace/cpp/designPattern/Architecture/threadPool/examples/pool20

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/hungtran/Workspace/cpp/designPattern/Architecture/threadPool/examples/pool20/build

# Include any dependencies generated for this target.
include test/CMakeFiles/ThreadPoolTests.dir/depend.make

# Include the progress variables for this target.
include test/CMakeFiles/ThreadPoolTests.dir/progress.make

# Include the compile flags for this target's objects.
include test/CMakeFiles/ThreadPoolTests.dir/flags.make

test/CMakeFiles/ThreadPoolTests.dir/source/main.cpp.o: test/CMakeFiles/ThreadPoolTests.dir/flags.make
test/CMakeFiles/ThreadPoolTests.dir/source/main.cpp.o: ../test/source/main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/hungtran/Workspace/cpp/designPattern/Architecture/threadPool/examples/pool20/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object test/CMakeFiles/ThreadPoolTests.dir/source/main.cpp.o"
	cd /home/hungtran/Workspace/cpp/designPattern/Architecture/threadPool/examples/pool20/build/test && /usr/lib64/ccache/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/ThreadPoolTests.dir/source/main.cpp.o -c /home/hungtran/Workspace/cpp/designPattern/Architecture/threadPool/examples/pool20/test/source/main.cpp

test/CMakeFiles/ThreadPoolTests.dir/source/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ThreadPoolTests.dir/source/main.cpp.i"
	cd /home/hungtran/Workspace/cpp/designPattern/Architecture/threadPool/examples/pool20/build/test && /usr/lib64/ccache/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/hungtran/Workspace/cpp/designPattern/Architecture/threadPool/examples/pool20/test/source/main.cpp > CMakeFiles/ThreadPoolTests.dir/source/main.cpp.i

test/CMakeFiles/ThreadPoolTests.dir/source/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ThreadPoolTests.dir/source/main.cpp.s"
	cd /home/hungtran/Workspace/cpp/designPattern/Architecture/threadPool/examples/pool20/build/test && /usr/lib64/ccache/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/hungtran/Workspace/cpp/designPattern/Architecture/threadPool/examples/pool20/test/source/main.cpp -o CMakeFiles/ThreadPoolTests.dir/source/main.cpp.s

test/CMakeFiles/ThreadPoolTests.dir/source/thread_pool.cpp.o: test/CMakeFiles/ThreadPoolTests.dir/flags.make
test/CMakeFiles/ThreadPoolTests.dir/source/thread_pool.cpp.o: ../test/source/thread_pool.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/hungtran/Workspace/cpp/designPattern/Architecture/threadPool/examples/pool20/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object test/CMakeFiles/ThreadPoolTests.dir/source/thread_pool.cpp.o"
	cd /home/hungtran/Workspace/cpp/designPattern/Architecture/threadPool/examples/pool20/build/test && /usr/lib64/ccache/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/ThreadPoolTests.dir/source/thread_pool.cpp.o -c /home/hungtran/Workspace/cpp/designPattern/Architecture/threadPool/examples/pool20/test/source/thread_pool.cpp

test/CMakeFiles/ThreadPoolTests.dir/source/thread_pool.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ThreadPoolTests.dir/source/thread_pool.cpp.i"
	cd /home/hungtran/Workspace/cpp/designPattern/Architecture/threadPool/examples/pool20/build/test && /usr/lib64/ccache/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/hungtran/Workspace/cpp/designPattern/Architecture/threadPool/examples/pool20/test/source/thread_pool.cpp > CMakeFiles/ThreadPoolTests.dir/source/thread_pool.cpp.i

test/CMakeFiles/ThreadPoolTests.dir/source/thread_pool.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ThreadPoolTests.dir/source/thread_pool.cpp.s"
	cd /home/hungtran/Workspace/cpp/designPattern/Architecture/threadPool/examples/pool20/build/test && /usr/lib64/ccache/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/hungtran/Workspace/cpp/designPattern/Architecture/threadPool/examples/pool20/test/source/thread_pool.cpp -o CMakeFiles/ThreadPoolTests.dir/source/thread_pool.cpp.s

test/CMakeFiles/ThreadPoolTests.dir/source/thread_safe_queue.cpp.o: test/CMakeFiles/ThreadPoolTests.dir/flags.make
test/CMakeFiles/ThreadPoolTests.dir/source/thread_safe_queue.cpp.o: ../test/source/thread_safe_queue.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/hungtran/Workspace/cpp/designPattern/Architecture/threadPool/examples/pool20/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object test/CMakeFiles/ThreadPoolTests.dir/source/thread_safe_queue.cpp.o"
	cd /home/hungtran/Workspace/cpp/designPattern/Architecture/threadPool/examples/pool20/build/test && /usr/lib64/ccache/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/ThreadPoolTests.dir/source/thread_safe_queue.cpp.o -c /home/hungtran/Workspace/cpp/designPattern/Architecture/threadPool/examples/pool20/test/source/thread_safe_queue.cpp

test/CMakeFiles/ThreadPoolTests.dir/source/thread_safe_queue.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ThreadPoolTests.dir/source/thread_safe_queue.cpp.i"
	cd /home/hungtran/Workspace/cpp/designPattern/Architecture/threadPool/examples/pool20/build/test && /usr/lib64/ccache/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/hungtran/Workspace/cpp/designPattern/Architecture/threadPool/examples/pool20/test/source/thread_safe_queue.cpp > CMakeFiles/ThreadPoolTests.dir/source/thread_safe_queue.cpp.i

test/CMakeFiles/ThreadPoolTests.dir/source/thread_safe_queue.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ThreadPoolTests.dir/source/thread_safe_queue.cpp.s"
	cd /home/hungtran/Workspace/cpp/designPattern/Architecture/threadPool/examples/pool20/build/test && /usr/lib64/ccache/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/hungtran/Workspace/cpp/designPattern/Architecture/threadPool/examples/pool20/test/source/thread_safe_queue.cpp -o CMakeFiles/ThreadPoolTests.dir/source/thread_safe_queue.cpp.s

# Object files for target ThreadPoolTests
ThreadPoolTests_OBJECTS = \
"CMakeFiles/ThreadPoolTests.dir/source/main.cpp.o" \
"CMakeFiles/ThreadPoolTests.dir/source/thread_pool.cpp.o" \
"CMakeFiles/ThreadPoolTests.dir/source/thread_safe_queue.cpp.o"

# External object files for target ThreadPoolTests
ThreadPoolTests_EXTERNAL_OBJECTS =

test/ThreadPoolTests: test/CMakeFiles/ThreadPoolTests.dir/source/main.cpp.o
test/ThreadPoolTests: test/CMakeFiles/ThreadPoolTests.dir/source/thread_pool.cpp.o
test/ThreadPoolTests: test/CMakeFiles/ThreadPoolTests.dir/source/thread_safe_queue.cpp.o
test/ThreadPoolTests: test/CMakeFiles/ThreadPoolTests.dir/build.make
test/ThreadPoolTests: test/CMakeFiles/ThreadPoolTests.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/hungtran/Workspace/cpp/designPattern/Architecture/threadPool/examples/pool20/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Linking CXX executable ThreadPoolTests"
	cd /home/hungtran/Workspace/cpp/designPattern/Architecture/threadPool/examples/pool20/build/test && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/ThreadPoolTests.dir/link.txt --verbose=$(VERBOSE)
	cd /home/hungtran/Workspace/cpp/designPattern/Architecture/threadPool/examples/pool20/build/test && /usr/bin/cmake -D TEST_TARGET=ThreadPoolTests -D TEST_EXECUTABLE=/home/hungtran/Workspace/cpp/designPattern/Architecture/threadPool/examples/pool20/build/test/ThreadPoolTests -D TEST_EXECUTOR= -D TEST_WORKING_DIR=/home/hungtran/Workspace/cpp/designPattern/Architecture/threadPool/examples/pool20/build/test -D TEST_SPEC= -D TEST_EXTRA_ARGS= -D TEST_PROPERTIES= -D TEST_PREFIX= -D TEST_SUFFIX= -D TEST_LIST=ThreadPoolTests_TESTS -D TEST_JUNIT_OUTPUT_DIR= -D CTEST_FILE=/home/hungtran/Workspace/cpp/designPattern/Architecture/threadPool/examples/pool20/build/test/ThreadPoolTests_tests-b858cb2.cmake -P /home/hungtran/Workspace/cpp/designPattern/Architecture/threadPool/examples/pool20/build/_deps/doctest-src/scripts/cmake/doctestAddTests.cmake

# Rule to build all files generated by this target.
test/CMakeFiles/ThreadPoolTests.dir/build: test/ThreadPoolTests

.PHONY : test/CMakeFiles/ThreadPoolTests.dir/build

test/CMakeFiles/ThreadPoolTests.dir/clean:
	cd /home/hungtran/Workspace/cpp/designPattern/Architecture/threadPool/examples/pool20/build/test && $(CMAKE_COMMAND) -P CMakeFiles/ThreadPoolTests.dir/cmake_clean.cmake
.PHONY : test/CMakeFiles/ThreadPoolTests.dir/clean

test/CMakeFiles/ThreadPoolTests.dir/depend:
	cd /home/hungtran/Workspace/cpp/designPattern/Architecture/threadPool/examples/pool20/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/hungtran/Workspace/cpp/designPattern/Architecture/threadPool/examples/pool20 /home/hungtran/Workspace/cpp/designPattern/Architecture/threadPool/examples/pool20/test /home/hungtran/Workspace/cpp/designPattern/Architecture/threadPool/examples/pool20/build /home/hungtran/Workspace/cpp/designPattern/Architecture/threadPool/examples/pool20/build/test /home/hungtran/Workspace/cpp/designPattern/Architecture/threadPool/examples/pool20/build/test/CMakeFiles/ThreadPoolTests.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : test/CMakeFiles/ThreadPoolTests.dir/depend

