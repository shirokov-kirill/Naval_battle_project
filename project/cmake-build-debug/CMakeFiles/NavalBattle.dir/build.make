# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.15

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
CMAKE_COMMAND = /home/alexandr/Soft/Clion/clion-2019.2.5/bin/cmake/linux/bin/cmake

# The command to remove a file.
RM = /home/alexandr/Soft/Clion/clion-2019.2.5/bin/cmake/linux/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "/home/alexandr/Рабочий стол/Naval_battle_project/project"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "/home/alexandr/Рабочий стол/Naval_battle_project/project/cmake-build-debug"

# Include any dependencies generated for this target.
include CMakeFiles/NavalBattle.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/NavalBattle.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/NavalBattle.dir/flags.make

CMakeFiles/NavalBattle.dir/src/Controller.cpp.o: CMakeFiles/NavalBattle.dir/flags.make
CMakeFiles/NavalBattle.dir/src/Controller.cpp.o: ../src/Controller.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/home/alexandr/Рабочий стол/Naval_battle_project/project/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/NavalBattle.dir/src/Controller.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/NavalBattle.dir/src/Controller.cpp.o -c "/home/alexandr/Рабочий стол/Naval_battle_project/project/src/Controller.cpp"

CMakeFiles/NavalBattle.dir/src/Controller.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/NavalBattle.dir/src/Controller.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/home/alexandr/Рабочий стол/Naval_battle_project/project/src/Controller.cpp" > CMakeFiles/NavalBattle.dir/src/Controller.cpp.i

CMakeFiles/NavalBattle.dir/src/Controller.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/NavalBattle.dir/src/Controller.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/home/alexandr/Рабочий стол/Naval_battle_project/project/src/Controller.cpp" -o CMakeFiles/NavalBattle.dir/src/Controller.cpp.s

CMakeFiles/NavalBattle.dir/src/Player.cpp.o: CMakeFiles/NavalBattle.dir/flags.make
CMakeFiles/NavalBattle.dir/src/Player.cpp.o: ../src/Player.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/home/alexandr/Рабочий стол/Naval_battle_project/project/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/NavalBattle.dir/src/Player.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/NavalBattle.dir/src/Player.cpp.o -c "/home/alexandr/Рабочий стол/Naval_battle_project/project/src/Player.cpp"

CMakeFiles/NavalBattle.dir/src/Player.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/NavalBattle.dir/src/Player.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/home/alexandr/Рабочий стол/Naval_battle_project/project/src/Player.cpp" > CMakeFiles/NavalBattle.dir/src/Player.cpp.i

CMakeFiles/NavalBattle.dir/src/Player.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/NavalBattle.dir/src/Player.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/home/alexandr/Рабочий стол/Naval_battle_project/project/src/Player.cpp" -o CMakeFiles/NavalBattle.dir/src/Player.cpp.s

CMakeFiles/NavalBattle.dir/src/Interface.cpp.o: CMakeFiles/NavalBattle.dir/flags.make
CMakeFiles/NavalBattle.dir/src/Interface.cpp.o: ../src/Interface.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/home/alexandr/Рабочий стол/Naval_battle_project/project/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/NavalBattle.dir/src/Interface.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/NavalBattle.dir/src/Interface.cpp.o -c "/home/alexandr/Рабочий стол/Naval_battle_project/project/src/Interface.cpp"

CMakeFiles/NavalBattle.dir/src/Interface.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/NavalBattle.dir/src/Interface.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/home/alexandr/Рабочий стол/Naval_battle_project/project/src/Interface.cpp" > CMakeFiles/NavalBattle.dir/src/Interface.cpp.i

CMakeFiles/NavalBattle.dir/src/Interface.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/NavalBattle.dir/src/Interface.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/home/alexandr/Рабочий стол/Naval_battle_project/project/src/Interface.cpp" -o CMakeFiles/NavalBattle.dir/src/Interface.cpp.s

CMakeFiles/NavalBattle.dir/src/Board.cpp.o: CMakeFiles/NavalBattle.dir/flags.make
CMakeFiles/NavalBattle.dir/src/Board.cpp.o: ../src/Board.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/home/alexandr/Рабочий стол/Naval_battle_project/project/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/NavalBattle.dir/src/Board.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/NavalBattle.dir/src/Board.cpp.o -c "/home/alexandr/Рабочий стол/Naval_battle_project/project/src/Board.cpp"

CMakeFiles/NavalBattle.dir/src/Board.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/NavalBattle.dir/src/Board.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/home/alexandr/Рабочий стол/Naval_battle_project/project/src/Board.cpp" > CMakeFiles/NavalBattle.dir/src/Board.cpp.i

CMakeFiles/NavalBattle.dir/src/Board.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/NavalBattle.dir/src/Board.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/home/alexandr/Рабочий стол/Naval_battle_project/project/src/Board.cpp" -o CMakeFiles/NavalBattle.dir/src/Board.cpp.s

CMakeFiles/NavalBattle.dir/src/main.cpp.o: CMakeFiles/NavalBattle.dir/flags.make
CMakeFiles/NavalBattle.dir/src/main.cpp.o: ../src/main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/home/alexandr/Рабочий стол/Naval_battle_project/project/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/NavalBattle.dir/src/main.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/NavalBattle.dir/src/main.cpp.o -c "/home/alexandr/Рабочий стол/Naval_battle_project/project/src/main.cpp"

CMakeFiles/NavalBattle.dir/src/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/NavalBattle.dir/src/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/home/alexandr/Рабочий стол/Naval_battle_project/project/src/main.cpp" > CMakeFiles/NavalBattle.dir/src/main.cpp.i

CMakeFiles/NavalBattle.dir/src/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/NavalBattle.dir/src/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/home/alexandr/Рабочий стол/Naval_battle_project/project/src/main.cpp" -o CMakeFiles/NavalBattle.dir/src/main.cpp.s

# Object files for target NavalBattle
NavalBattle_OBJECTS = \
"CMakeFiles/NavalBattle.dir/src/Controller.cpp.o" \
"CMakeFiles/NavalBattle.dir/src/Player.cpp.o" \
"CMakeFiles/NavalBattle.dir/src/Interface.cpp.o" \
"CMakeFiles/NavalBattle.dir/src/Board.cpp.o" \
"CMakeFiles/NavalBattle.dir/src/main.cpp.o"

# External object files for target NavalBattle
NavalBattle_EXTERNAL_OBJECTS =

NavalBattle: CMakeFiles/NavalBattle.dir/src/Controller.cpp.o
NavalBattle: CMakeFiles/NavalBattle.dir/src/Player.cpp.o
NavalBattle: CMakeFiles/NavalBattle.dir/src/Interface.cpp.o
NavalBattle: CMakeFiles/NavalBattle.dir/src/Board.cpp.o
NavalBattle: CMakeFiles/NavalBattle.dir/src/main.cpp.o
NavalBattle: CMakeFiles/NavalBattle.dir/build.make
NavalBattle: CMakeFiles/NavalBattle.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="/home/alexandr/Рабочий стол/Naval_battle_project/project/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_6) "Linking CXX executable NavalBattle"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/NavalBattle.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/NavalBattle.dir/build: NavalBattle

.PHONY : CMakeFiles/NavalBattle.dir/build

CMakeFiles/NavalBattle.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/NavalBattle.dir/cmake_clean.cmake
.PHONY : CMakeFiles/NavalBattle.dir/clean

CMakeFiles/NavalBattle.dir/depend:
	cd "/home/alexandr/Рабочий стол/Naval_battle_project/project/cmake-build-debug" && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" "/home/alexandr/Рабочий стол/Naval_battle_project/project" "/home/alexandr/Рабочий стол/Naval_battle_project/project" "/home/alexandr/Рабочий стол/Naval_battle_project/project/cmake-build-debug" "/home/alexandr/Рабочий стол/Naval_battle_project/project/cmake-build-debug" "/home/alexandr/Рабочий стол/Naval_battle_project/project/cmake-build-debug/CMakeFiles/NavalBattle.dir/DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/NavalBattle.dir/depend
