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
CMAKE_SOURCE_DIR = /home/local/girogiu95354/sistemaDomotico/sistemaDomotico

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/local/girogiu95354/sistemaDomotico/sistemaDomotico/build

# Include any dependencies generated for this target.
include CMakeFiles/sistemaDomotico.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/sistemaDomotico.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/sistemaDomotico.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/sistemaDomotico.dir/flags.make

CMakeFiles/sistemaDomotico.dir/src/main.cpp.o: CMakeFiles/sistemaDomotico.dir/flags.make
CMakeFiles/sistemaDomotico.dir/src/main.cpp.o: ../src/main.cpp
CMakeFiles/sistemaDomotico.dir/src/main.cpp.o: CMakeFiles/sistemaDomotico.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/local/girogiu95354/sistemaDomotico/sistemaDomotico/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/sistemaDomotico.dir/src/main.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/sistemaDomotico.dir/src/main.cpp.o -MF CMakeFiles/sistemaDomotico.dir/src/main.cpp.o.d -o CMakeFiles/sistemaDomotico.dir/src/main.cpp.o -c /home/local/girogiu95354/sistemaDomotico/sistemaDomotico/src/main.cpp

CMakeFiles/sistemaDomotico.dir/src/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/sistemaDomotico.dir/src/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/local/girogiu95354/sistemaDomotico/sistemaDomotico/src/main.cpp > CMakeFiles/sistemaDomotico.dir/src/main.cpp.i

CMakeFiles/sistemaDomotico.dir/src/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/sistemaDomotico.dir/src/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/local/girogiu95354/sistemaDomotico/sistemaDomotico/src/main.cpp -o CMakeFiles/sistemaDomotico.dir/src/main.cpp.s

CMakeFiles/sistemaDomotico.dir/src/Controller.cpp.o: CMakeFiles/sistemaDomotico.dir/flags.make
CMakeFiles/sistemaDomotico.dir/src/Controller.cpp.o: ../src/Controller.cpp
CMakeFiles/sistemaDomotico.dir/src/Controller.cpp.o: CMakeFiles/sistemaDomotico.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/local/girogiu95354/sistemaDomotico/sistemaDomotico/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/sistemaDomotico.dir/src/Controller.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/sistemaDomotico.dir/src/Controller.cpp.o -MF CMakeFiles/sistemaDomotico.dir/src/Controller.cpp.o.d -o CMakeFiles/sistemaDomotico.dir/src/Controller.cpp.o -c /home/local/girogiu95354/sistemaDomotico/sistemaDomotico/src/Controller.cpp

CMakeFiles/sistemaDomotico.dir/src/Controller.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/sistemaDomotico.dir/src/Controller.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/local/girogiu95354/sistemaDomotico/sistemaDomotico/src/Controller.cpp > CMakeFiles/sistemaDomotico.dir/src/Controller.cpp.i

CMakeFiles/sistemaDomotico.dir/src/Controller.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/sistemaDomotico.dir/src/Controller.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/local/girogiu95354/sistemaDomotico/sistemaDomotico/src/Controller.cpp -o CMakeFiles/sistemaDomotico.dir/src/Controller.cpp.s

CMakeFiles/sistemaDomotico.dir/src/Device.cpp.o: CMakeFiles/sistemaDomotico.dir/flags.make
CMakeFiles/sistemaDomotico.dir/src/Device.cpp.o: ../src/Device.cpp
CMakeFiles/sistemaDomotico.dir/src/Device.cpp.o: CMakeFiles/sistemaDomotico.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/local/girogiu95354/sistemaDomotico/sistemaDomotico/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/sistemaDomotico.dir/src/Device.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/sistemaDomotico.dir/src/Device.cpp.o -MF CMakeFiles/sistemaDomotico.dir/src/Device.cpp.o.d -o CMakeFiles/sistemaDomotico.dir/src/Device.cpp.o -c /home/local/girogiu95354/sistemaDomotico/sistemaDomotico/src/Device.cpp

CMakeFiles/sistemaDomotico.dir/src/Device.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/sistemaDomotico.dir/src/Device.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/local/girogiu95354/sistemaDomotico/sistemaDomotico/src/Device.cpp > CMakeFiles/sistemaDomotico.dir/src/Device.cpp.i

CMakeFiles/sistemaDomotico.dir/src/Device.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/sistemaDomotico.dir/src/Device.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/local/girogiu95354/sistemaDomotico/sistemaDomotico/src/Device.cpp -o CMakeFiles/sistemaDomotico.dir/src/Device.cpp.s

CMakeFiles/sistemaDomotico.dir/src/DeviceCP.cpp.o: CMakeFiles/sistemaDomotico.dir/flags.make
CMakeFiles/sistemaDomotico.dir/src/DeviceCP.cpp.o: ../src/DeviceCP.cpp
CMakeFiles/sistemaDomotico.dir/src/DeviceCP.cpp.o: CMakeFiles/sistemaDomotico.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/local/girogiu95354/sistemaDomotico/sistemaDomotico/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/sistemaDomotico.dir/src/DeviceCP.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/sistemaDomotico.dir/src/DeviceCP.cpp.o -MF CMakeFiles/sistemaDomotico.dir/src/DeviceCP.cpp.o.d -o CMakeFiles/sistemaDomotico.dir/src/DeviceCP.cpp.o -c /home/local/girogiu95354/sistemaDomotico/sistemaDomotico/src/DeviceCP.cpp

CMakeFiles/sistemaDomotico.dir/src/DeviceCP.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/sistemaDomotico.dir/src/DeviceCP.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/local/girogiu95354/sistemaDomotico/sistemaDomotico/src/DeviceCP.cpp > CMakeFiles/sistemaDomotico.dir/src/DeviceCP.cpp.i

CMakeFiles/sistemaDomotico.dir/src/DeviceCP.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/sistemaDomotico.dir/src/DeviceCP.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/local/girogiu95354/sistemaDomotico/sistemaDomotico/src/DeviceCP.cpp -o CMakeFiles/sistemaDomotico.dir/src/DeviceCP.cpp.s

CMakeFiles/sistemaDomotico.dir/src/DeviceM.cpp.o: CMakeFiles/sistemaDomotico.dir/flags.make
CMakeFiles/sistemaDomotico.dir/src/DeviceM.cpp.o: ../src/DeviceM.cpp
CMakeFiles/sistemaDomotico.dir/src/DeviceM.cpp.o: CMakeFiles/sistemaDomotico.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/local/girogiu95354/sistemaDomotico/sistemaDomotico/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/sistemaDomotico.dir/src/DeviceM.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/sistemaDomotico.dir/src/DeviceM.cpp.o -MF CMakeFiles/sistemaDomotico.dir/src/DeviceM.cpp.o.d -o CMakeFiles/sistemaDomotico.dir/src/DeviceM.cpp.o -c /home/local/girogiu95354/sistemaDomotico/sistemaDomotico/src/DeviceM.cpp

CMakeFiles/sistemaDomotico.dir/src/DeviceM.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/sistemaDomotico.dir/src/DeviceM.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/local/girogiu95354/sistemaDomotico/sistemaDomotico/src/DeviceM.cpp > CMakeFiles/sistemaDomotico.dir/src/DeviceM.cpp.i

CMakeFiles/sistemaDomotico.dir/src/DeviceM.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/sistemaDomotico.dir/src/DeviceM.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/local/girogiu95354/sistemaDomotico/sistemaDomotico/src/DeviceM.cpp -o CMakeFiles/sistemaDomotico.dir/src/DeviceM.cpp.s

CMakeFiles/sistemaDomotico.dir/src/Logger.cpp.o: CMakeFiles/sistemaDomotico.dir/flags.make
CMakeFiles/sistemaDomotico.dir/src/Logger.cpp.o: ../src/Logger.cpp
CMakeFiles/sistemaDomotico.dir/src/Logger.cpp.o: CMakeFiles/sistemaDomotico.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/local/girogiu95354/sistemaDomotico/sistemaDomotico/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/sistemaDomotico.dir/src/Logger.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/sistemaDomotico.dir/src/Logger.cpp.o -MF CMakeFiles/sistemaDomotico.dir/src/Logger.cpp.o.d -o CMakeFiles/sistemaDomotico.dir/src/Logger.cpp.o -c /home/local/girogiu95354/sistemaDomotico/sistemaDomotico/src/Logger.cpp

CMakeFiles/sistemaDomotico.dir/src/Logger.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/sistemaDomotico.dir/src/Logger.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/local/girogiu95354/sistemaDomotico/sistemaDomotico/src/Logger.cpp > CMakeFiles/sistemaDomotico.dir/src/Logger.cpp.i

CMakeFiles/sistemaDomotico.dir/src/Logger.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/sistemaDomotico.dir/src/Logger.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/local/girogiu95354/sistemaDomotico/sistemaDomotico/src/Logger.cpp -o CMakeFiles/sistemaDomotico.dir/src/Logger.cpp.s

# Object files for target sistemaDomotico
sistemaDomotico_OBJECTS = \
"CMakeFiles/sistemaDomotico.dir/src/main.cpp.o" \
"CMakeFiles/sistemaDomotico.dir/src/Controller.cpp.o" \
"CMakeFiles/sistemaDomotico.dir/src/Device.cpp.o" \
"CMakeFiles/sistemaDomotico.dir/src/DeviceCP.cpp.o" \
"CMakeFiles/sistemaDomotico.dir/src/DeviceM.cpp.o" \
"CMakeFiles/sistemaDomotico.dir/src/Logger.cpp.o"

# External object files for target sistemaDomotico
sistemaDomotico_EXTERNAL_OBJECTS =

bin/sistemaDomotico: CMakeFiles/sistemaDomotico.dir/src/main.cpp.o
bin/sistemaDomotico: CMakeFiles/sistemaDomotico.dir/src/Controller.cpp.o
bin/sistemaDomotico: CMakeFiles/sistemaDomotico.dir/src/Device.cpp.o
bin/sistemaDomotico: CMakeFiles/sistemaDomotico.dir/src/DeviceCP.cpp.o
bin/sistemaDomotico: CMakeFiles/sistemaDomotico.dir/src/DeviceM.cpp.o
bin/sistemaDomotico: CMakeFiles/sistemaDomotico.dir/src/Logger.cpp.o
bin/sistemaDomotico: CMakeFiles/sistemaDomotico.dir/build.make
bin/sistemaDomotico: CMakeFiles/sistemaDomotico.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/local/girogiu95354/sistemaDomotico/sistemaDomotico/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Linking CXX executable bin/sistemaDomotico"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/sistemaDomotico.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/sistemaDomotico.dir/build: bin/sistemaDomotico
.PHONY : CMakeFiles/sistemaDomotico.dir/build

CMakeFiles/sistemaDomotico.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/sistemaDomotico.dir/cmake_clean.cmake
.PHONY : CMakeFiles/sistemaDomotico.dir/clean

CMakeFiles/sistemaDomotico.dir/depend:
	cd /home/local/girogiu95354/sistemaDomotico/sistemaDomotico/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/local/girogiu95354/sistemaDomotico/sistemaDomotico /home/local/girogiu95354/sistemaDomotico/sistemaDomotico /home/local/girogiu95354/sistemaDomotico/sistemaDomotico/build /home/local/girogiu95354/sistemaDomotico/sistemaDomotico/build /home/local/girogiu95354/sistemaDomotico/sistemaDomotico/build/CMakeFiles/sistemaDomotico.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/sistemaDomotico.dir/depend

