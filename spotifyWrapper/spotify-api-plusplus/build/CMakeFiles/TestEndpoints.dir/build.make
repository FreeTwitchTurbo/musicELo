# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.24

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
CMAKE_COMMAND = /usr/local/bin/cmake.exe

# The command to remove a file.
RM = /usr/local/bin/cmake.exe -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "/cygdrive/c/Users/Eli Calabrese/Downloads/School/musicELo/spotifyWrapper/spotify-api-plusplus"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "/cygdrive/c/Users/Eli Calabrese/Downloads/School/musicELo/spotifyWrapper/spotify-api-plusplus/build"

# Include any dependencies generated for this target.
include CMakeFiles/TestEndpoints.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/TestEndpoints.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/TestEndpoints.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/TestEndpoints.dir/flags.make

CMakeFiles/TestEndpoints.dir/tests/TestEndpoints.cpp.o: CMakeFiles/TestEndpoints.dir/flags.make
CMakeFiles/TestEndpoints.dir/tests/TestEndpoints.cpp.o: /cygdrive/c/Users/Eli\ Calabrese/Downloads/School/musicELo/spotifyWrapper/spotify-api-plusplus/tests/TestEndpoints.cpp
CMakeFiles/TestEndpoints.dir/tests/TestEndpoints.cpp.o: CMakeFiles/TestEndpoints.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/cygdrive/c/Users/Eli Calabrese/Downloads/School/musicELo/spotifyWrapper/spotify-api-plusplus/build/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/TestEndpoints.dir/tests/TestEndpoints.cpp.o"
	/usr/bin/c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/TestEndpoints.dir/tests/TestEndpoints.cpp.o -MF CMakeFiles/TestEndpoints.dir/tests/TestEndpoints.cpp.o.d -o CMakeFiles/TestEndpoints.dir/tests/TestEndpoints.cpp.o -c "/cygdrive/c/Users/Eli Calabrese/Downloads/School/musicELo/spotifyWrapper/spotify-api-plusplus/tests/TestEndpoints.cpp"

CMakeFiles/TestEndpoints.dir/tests/TestEndpoints.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/TestEndpoints.dir/tests/TestEndpoints.cpp.i"
	/usr/bin/c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/cygdrive/c/Users/Eli Calabrese/Downloads/School/musicELo/spotifyWrapper/spotify-api-plusplus/tests/TestEndpoints.cpp" > CMakeFiles/TestEndpoints.dir/tests/TestEndpoints.cpp.i

CMakeFiles/TestEndpoints.dir/tests/TestEndpoints.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/TestEndpoints.dir/tests/TestEndpoints.cpp.s"
	/usr/bin/c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/cygdrive/c/Users/Eli Calabrese/Downloads/School/musicELo/spotifyWrapper/spotify-api-plusplus/tests/TestEndpoints.cpp" -o CMakeFiles/TestEndpoints.dir/tests/TestEndpoints.cpp.s

# Object files for target TestEndpoints
TestEndpoints_OBJECTS = \
"CMakeFiles/TestEndpoints.dir/tests/TestEndpoints.cpp.o"

# External object files for target TestEndpoints
TestEndpoints_EXTERNAL_OBJECTS =

TestEndpoints.exe: CMakeFiles/TestEndpoints.dir/tests/TestEndpoints.cpp.o
TestEndpoints.exe: CMakeFiles/TestEndpoints.dir/build.make
TestEndpoints.exe: gtest/googlemock/gtest/libgtest.a
TestEndpoints.exe: gtest/googlemock/gtest/libgtest_main.a
TestEndpoints.exe: src/libspotify-api-plusplus.dll.a
TestEndpoints.exe: gtest/googlemock/gtest/libgtest.a
TestEndpoints.exe: CMakeFiles/TestEndpoints.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="/cygdrive/c/Users/Eli Calabrese/Downloads/School/musicELo/spotifyWrapper/spotify-api-plusplus/build/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable TestEndpoints.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/TestEndpoints.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/TestEndpoints.dir/build: TestEndpoints.exe
.PHONY : CMakeFiles/TestEndpoints.dir/build

CMakeFiles/TestEndpoints.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/TestEndpoints.dir/cmake_clean.cmake
.PHONY : CMakeFiles/TestEndpoints.dir/clean

CMakeFiles/TestEndpoints.dir/depend:
	cd "/cygdrive/c/Users/Eli Calabrese/Downloads/School/musicELo/spotifyWrapper/spotify-api-plusplus/build" && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" "/cygdrive/c/Users/Eli Calabrese/Downloads/School/musicELo/spotifyWrapper/spotify-api-plusplus" "/cygdrive/c/Users/Eli Calabrese/Downloads/School/musicELo/spotifyWrapper/spotify-api-plusplus" "/cygdrive/c/Users/Eli Calabrese/Downloads/School/musicELo/spotifyWrapper/spotify-api-plusplus/build" "/cygdrive/c/Users/Eli Calabrese/Downloads/School/musicELo/spotifyWrapper/spotify-api-plusplus/build" "/cygdrive/c/Users/Eli Calabrese/Downloads/School/musicELo/spotifyWrapper/spotify-api-plusplus/build/CMakeFiles/TestEndpoints.dir/DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/TestEndpoints.dir/depend

