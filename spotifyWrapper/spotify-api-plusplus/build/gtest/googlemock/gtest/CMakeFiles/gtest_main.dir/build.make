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
include gtest/googlemock/gtest/CMakeFiles/gtest_main.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include gtest/googlemock/gtest/CMakeFiles/gtest_main.dir/compiler_depend.make

# Include the progress variables for this target.
include gtest/googlemock/gtest/CMakeFiles/gtest_main.dir/progress.make

# Include the compile flags for this target's objects.
include gtest/googlemock/gtest/CMakeFiles/gtest_main.dir/flags.make

gtest/googlemock/gtest/CMakeFiles/gtest_main.dir/src/gtest_main.cc.o: gtest/googlemock/gtest/CMakeFiles/gtest_main.dir/flags.make
gtest/googlemock/gtest/CMakeFiles/gtest_main.dir/src/gtest_main.cc.o: /cygdrive/c/Users/Eli\ Calabrese/Downloads/School/musicELo/spotifyWrapper/spotify-api-plusplus/gtest/googletest/src/gtest_main.cc
gtest/googlemock/gtest/CMakeFiles/gtest_main.dir/src/gtest_main.cc.o: gtest/googlemock/gtest/CMakeFiles/gtest_main.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/cygdrive/c/Users/Eli Calabrese/Downloads/School/musicELo/spotifyWrapper/spotify-api-plusplus/build/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object gtest/googlemock/gtest/CMakeFiles/gtest_main.dir/src/gtest_main.cc.o"
	cd "/cygdrive/c/Users/Eli Calabrese/Downloads/School/musicELo/spotifyWrapper/spotify-api-plusplus/build/gtest/googlemock/gtest" && /usr/bin/c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT gtest/googlemock/gtest/CMakeFiles/gtest_main.dir/src/gtest_main.cc.o -MF CMakeFiles/gtest_main.dir/src/gtest_main.cc.o.d -o CMakeFiles/gtest_main.dir/src/gtest_main.cc.o -c "/cygdrive/c/Users/Eli Calabrese/Downloads/School/musicELo/spotifyWrapper/spotify-api-plusplus/gtest/googletest/src/gtest_main.cc"

gtest/googlemock/gtest/CMakeFiles/gtest_main.dir/src/gtest_main.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/gtest_main.dir/src/gtest_main.cc.i"
	cd "/cygdrive/c/Users/Eli Calabrese/Downloads/School/musicELo/spotifyWrapper/spotify-api-plusplus/build/gtest/googlemock/gtest" && /usr/bin/c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/cygdrive/c/Users/Eli Calabrese/Downloads/School/musicELo/spotifyWrapper/spotify-api-plusplus/gtest/googletest/src/gtest_main.cc" > CMakeFiles/gtest_main.dir/src/gtest_main.cc.i

gtest/googlemock/gtest/CMakeFiles/gtest_main.dir/src/gtest_main.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/gtest_main.dir/src/gtest_main.cc.s"
	cd "/cygdrive/c/Users/Eli Calabrese/Downloads/School/musicELo/spotifyWrapper/spotify-api-plusplus/build/gtest/googlemock/gtest" && /usr/bin/c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/cygdrive/c/Users/Eli Calabrese/Downloads/School/musicELo/spotifyWrapper/spotify-api-plusplus/gtest/googletest/src/gtest_main.cc" -o CMakeFiles/gtest_main.dir/src/gtest_main.cc.s

# Object files for target gtest_main
gtest_main_OBJECTS = \
"CMakeFiles/gtest_main.dir/src/gtest_main.cc.o"

# External object files for target gtest_main
gtest_main_EXTERNAL_OBJECTS =

gtest/googlemock/gtest/libgtest_main.a: gtest/googlemock/gtest/CMakeFiles/gtest_main.dir/src/gtest_main.cc.o
gtest/googlemock/gtest/libgtest_main.a: gtest/googlemock/gtest/CMakeFiles/gtest_main.dir/build.make
gtest/googlemock/gtest/libgtest_main.a: gtest/googlemock/gtest/CMakeFiles/gtest_main.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="/cygdrive/c/Users/Eli Calabrese/Downloads/School/musicELo/spotifyWrapper/spotify-api-plusplus/build/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX static library libgtest_main.a"
	cd "/cygdrive/c/Users/Eli Calabrese/Downloads/School/musicELo/spotifyWrapper/spotify-api-plusplus/build/gtest/googlemock/gtest" && $(CMAKE_COMMAND) -P CMakeFiles/gtest_main.dir/cmake_clean_target.cmake
	cd "/cygdrive/c/Users/Eli Calabrese/Downloads/School/musicELo/spotifyWrapper/spotify-api-plusplus/build/gtest/googlemock/gtest" && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/gtest_main.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
gtest/googlemock/gtest/CMakeFiles/gtest_main.dir/build: gtest/googlemock/gtest/libgtest_main.a
.PHONY : gtest/googlemock/gtest/CMakeFiles/gtest_main.dir/build

gtest/googlemock/gtest/CMakeFiles/gtest_main.dir/clean:
	cd "/cygdrive/c/Users/Eli Calabrese/Downloads/School/musicELo/spotifyWrapper/spotify-api-plusplus/build/gtest/googlemock/gtest" && $(CMAKE_COMMAND) -P CMakeFiles/gtest_main.dir/cmake_clean.cmake
.PHONY : gtest/googlemock/gtest/CMakeFiles/gtest_main.dir/clean

gtest/googlemock/gtest/CMakeFiles/gtest_main.dir/depend:
	cd "/cygdrive/c/Users/Eli Calabrese/Downloads/School/musicELo/spotifyWrapper/spotify-api-plusplus/build" && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" "/cygdrive/c/Users/Eli Calabrese/Downloads/School/musicELo/spotifyWrapper/spotify-api-plusplus" "/cygdrive/c/Users/Eli Calabrese/Downloads/School/musicELo/spotifyWrapper/spotify-api-plusplus/gtest/googletest" "/cygdrive/c/Users/Eli Calabrese/Downloads/School/musicELo/spotifyWrapper/spotify-api-plusplus/build" "/cygdrive/c/Users/Eli Calabrese/Downloads/School/musicELo/spotifyWrapper/spotify-api-plusplus/build/gtest/googlemock/gtest" "/cygdrive/c/Users/Eli Calabrese/Downloads/School/musicELo/spotifyWrapper/spotify-api-plusplus/build/gtest/googlemock/gtest/CMakeFiles/gtest_main.dir/DependInfo.cmake" --color=$(COLOR)
.PHONY : gtest/googlemock/gtest/CMakeFiles/gtest_main.dir/depend
