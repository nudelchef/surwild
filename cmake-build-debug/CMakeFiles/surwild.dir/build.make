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
CMAKE_COMMAND = /root/.local/share/JetBrains/Toolbox/apps/CLion/ch-0/221.5921.27/bin/cmake/linux/bin/cmake

# The command to remove a file.
RM = /root/.local/share/JetBrains/Toolbox/apps/CLion/ch-0/221.5921.27/bin/cmake/linux/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /root/CLionProjects/surwild

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /root/CLionProjects/surwild/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/surwild.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/surwild.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/surwild.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/surwild.dir/flags.make

CMakeFiles/surwild.dir/src/Camera.cpp.o: CMakeFiles/surwild.dir/flags.make
CMakeFiles/surwild.dir/src/Camera.cpp.o: ../src/Camera.cpp
CMakeFiles/surwild.dir/src/Camera.cpp.o: CMakeFiles/surwild.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/root/CLionProjects/surwild/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/surwild.dir/src/Camera.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/surwild.dir/src/Camera.cpp.o -MF CMakeFiles/surwild.dir/src/Camera.cpp.o.d -o CMakeFiles/surwild.dir/src/Camera.cpp.o -c /root/CLionProjects/surwild/src/Camera.cpp

CMakeFiles/surwild.dir/src/Camera.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/surwild.dir/src/Camera.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /root/CLionProjects/surwild/src/Camera.cpp > CMakeFiles/surwild.dir/src/Camera.cpp.i

CMakeFiles/surwild.dir/src/Camera.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/surwild.dir/src/Camera.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /root/CLionProjects/surwild/src/Camera.cpp -o CMakeFiles/surwild.dir/src/Camera.cpp.s

CMakeFiles/surwild.dir/src/Entity.cpp.o: CMakeFiles/surwild.dir/flags.make
CMakeFiles/surwild.dir/src/Entity.cpp.o: ../src/Entity.cpp
CMakeFiles/surwild.dir/src/Entity.cpp.o: CMakeFiles/surwild.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/root/CLionProjects/surwild/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/surwild.dir/src/Entity.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/surwild.dir/src/Entity.cpp.o -MF CMakeFiles/surwild.dir/src/Entity.cpp.o.d -o CMakeFiles/surwild.dir/src/Entity.cpp.o -c /root/CLionProjects/surwild/src/Entity.cpp

CMakeFiles/surwild.dir/src/Entity.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/surwild.dir/src/Entity.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /root/CLionProjects/surwild/src/Entity.cpp > CMakeFiles/surwild.dir/src/Entity.cpp.i

CMakeFiles/surwild.dir/src/Entity.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/surwild.dir/src/Entity.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /root/CLionProjects/surwild/src/Entity.cpp -o CMakeFiles/surwild.dir/src/Entity.cpp.s

CMakeFiles/surwild.dir/src/Game.cpp.o: CMakeFiles/surwild.dir/flags.make
CMakeFiles/surwild.dir/src/Game.cpp.o: ../src/Game.cpp
CMakeFiles/surwild.dir/src/Game.cpp.o: CMakeFiles/surwild.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/root/CLionProjects/surwild/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/surwild.dir/src/Game.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/surwild.dir/src/Game.cpp.o -MF CMakeFiles/surwild.dir/src/Game.cpp.o.d -o CMakeFiles/surwild.dir/src/Game.cpp.o -c /root/CLionProjects/surwild/src/Game.cpp

CMakeFiles/surwild.dir/src/Game.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/surwild.dir/src/Game.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /root/CLionProjects/surwild/src/Game.cpp > CMakeFiles/surwild.dir/src/Game.cpp.i

CMakeFiles/surwild.dir/src/Game.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/surwild.dir/src/Game.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /root/CLionProjects/surwild/src/Game.cpp -o CMakeFiles/surwild.dir/src/Game.cpp.s

CMakeFiles/surwild.dir/src/Map.cpp.o: CMakeFiles/surwild.dir/flags.make
CMakeFiles/surwild.dir/src/Map.cpp.o: ../src/Map.cpp
CMakeFiles/surwild.dir/src/Map.cpp.o: CMakeFiles/surwild.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/root/CLionProjects/surwild/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/surwild.dir/src/Map.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/surwild.dir/src/Map.cpp.o -MF CMakeFiles/surwild.dir/src/Map.cpp.o.d -o CMakeFiles/surwild.dir/src/Map.cpp.o -c /root/CLionProjects/surwild/src/Map.cpp

CMakeFiles/surwild.dir/src/Map.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/surwild.dir/src/Map.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /root/CLionProjects/surwild/src/Map.cpp > CMakeFiles/surwild.dir/src/Map.cpp.i

CMakeFiles/surwild.dir/src/Map.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/surwild.dir/src/Map.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /root/CLionProjects/surwild/src/Map.cpp -o CMakeFiles/surwild.dir/src/Map.cpp.s

CMakeFiles/surwild.dir/src/PacketManager.cpp.o: CMakeFiles/surwild.dir/flags.make
CMakeFiles/surwild.dir/src/PacketManager.cpp.o: ../src/PacketManager.cpp
CMakeFiles/surwild.dir/src/PacketManager.cpp.o: CMakeFiles/surwild.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/root/CLionProjects/surwild/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/surwild.dir/src/PacketManager.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/surwild.dir/src/PacketManager.cpp.o -MF CMakeFiles/surwild.dir/src/PacketManager.cpp.o.d -o CMakeFiles/surwild.dir/src/PacketManager.cpp.o -c /root/CLionProjects/surwild/src/PacketManager.cpp

CMakeFiles/surwild.dir/src/PacketManager.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/surwild.dir/src/PacketManager.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /root/CLionProjects/surwild/src/PacketManager.cpp > CMakeFiles/surwild.dir/src/PacketManager.cpp.i

CMakeFiles/surwild.dir/src/PacketManager.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/surwild.dir/src/PacketManager.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /root/CLionProjects/surwild/src/PacketManager.cpp -o CMakeFiles/surwild.dir/src/PacketManager.cpp.s

CMakeFiles/surwild.dir/src/Player.cpp.o: CMakeFiles/surwild.dir/flags.make
CMakeFiles/surwild.dir/src/Player.cpp.o: ../src/Player.cpp
CMakeFiles/surwild.dir/src/Player.cpp.o: CMakeFiles/surwild.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/root/CLionProjects/surwild/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/surwild.dir/src/Player.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/surwild.dir/src/Player.cpp.o -MF CMakeFiles/surwild.dir/src/Player.cpp.o.d -o CMakeFiles/surwild.dir/src/Player.cpp.o -c /root/CLionProjects/surwild/src/Player.cpp

CMakeFiles/surwild.dir/src/Player.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/surwild.dir/src/Player.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /root/CLionProjects/surwild/src/Player.cpp > CMakeFiles/surwild.dir/src/Player.cpp.i

CMakeFiles/surwild.dir/src/Player.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/surwild.dir/src/Player.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /root/CLionProjects/surwild/src/Player.cpp -o CMakeFiles/surwild.dir/src/Player.cpp.s

CMakeFiles/surwild.dir/src/SocketClient.cpp.o: CMakeFiles/surwild.dir/flags.make
CMakeFiles/surwild.dir/src/SocketClient.cpp.o: ../src/SocketClient.cpp
CMakeFiles/surwild.dir/src/SocketClient.cpp.o: CMakeFiles/surwild.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/root/CLionProjects/surwild/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object CMakeFiles/surwild.dir/src/SocketClient.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/surwild.dir/src/SocketClient.cpp.o -MF CMakeFiles/surwild.dir/src/SocketClient.cpp.o.d -o CMakeFiles/surwild.dir/src/SocketClient.cpp.o -c /root/CLionProjects/surwild/src/SocketClient.cpp

CMakeFiles/surwild.dir/src/SocketClient.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/surwild.dir/src/SocketClient.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /root/CLionProjects/surwild/src/SocketClient.cpp > CMakeFiles/surwild.dir/src/SocketClient.cpp.i

CMakeFiles/surwild.dir/src/SocketClient.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/surwild.dir/src/SocketClient.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /root/CLionProjects/surwild/src/SocketClient.cpp -o CMakeFiles/surwild.dir/src/SocketClient.cpp.s

CMakeFiles/surwild.dir/src/StringUtils.cpp.o: CMakeFiles/surwild.dir/flags.make
CMakeFiles/surwild.dir/src/StringUtils.cpp.o: ../src/StringUtils.cpp
CMakeFiles/surwild.dir/src/StringUtils.cpp.o: CMakeFiles/surwild.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/root/CLionProjects/surwild/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Building CXX object CMakeFiles/surwild.dir/src/StringUtils.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/surwild.dir/src/StringUtils.cpp.o -MF CMakeFiles/surwild.dir/src/StringUtils.cpp.o.d -o CMakeFiles/surwild.dir/src/StringUtils.cpp.o -c /root/CLionProjects/surwild/src/StringUtils.cpp

CMakeFiles/surwild.dir/src/StringUtils.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/surwild.dir/src/StringUtils.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /root/CLionProjects/surwild/src/StringUtils.cpp > CMakeFiles/surwild.dir/src/StringUtils.cpp.i

CMakeFiles/surwild.dir/src/StringUtils.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/surwild.dir/src/StringUtils.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /root/CLionProjects/surwild/src/StringUtils.cpp -o CMakeFiles/surwild.dir/src/StringUtils.cpp.s

CMakeFiles/surwild.dir/src/TextureManager.cpp.o: CMakeFiles/surwild.dir/flags.make
CMakeFiles/surwild.dir/src/TextureManager.cpp.o: ../src/TextureManager.cpp
CMakeFiles/surwild.dir/src/TextureManager.cpp.o: CMakeFiles/surwild.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/root/CLionProjects/surwild/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_9) "Building CXX object CMakeFiles/surwild.dir/src/TextureManager.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/surwild.dir/src/TextureManager.cpp.o -MF CMakeFiles/surwild.dir/src/TextureManager.cpp.o.d -o CMakeFiles/surwild.dir/src/TextureManager.cpp.o -c /root/CLionProjects/surwild/src/TextureManager.cpp

CMakeFiles/surwild.dir/src/TextureManager.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/surwild.dir/src/TextureManager.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /root/CLionProjects/surwild/src/TextureManager.cpp > CMakeFiles/surwild.dir/src/TextureManager.cpp.i

CMakeFiles/surwild.dir/src/TextureManager.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/surwild.dir/src/TextureManager.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /root/CLionProjects/surwild/src/TextureManager.cpp -o CMakeFiles/surwild.dir/src/TextureManager.cpp.s

CMakeFiles/surwild.dir/src/main.cpp.o: CMakeFiles/surwild.dir/flags.make
CMakeFiles/surwild.dir/src/main.cpp.o: ../src/main.cpp
CMakeFiles/surwild.dir/src/main.cpp.o: CMakeFiles/surwild.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/root/CLionProjects/surwild/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_10) "Building CXX object CMakeFiles/surwild.dir/src/main.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/surwild.dir/src/main.cpp.o -MF CMakeFiles/surwild.dir/src/main.cpp.o.d -o CMakeFiles/surwild.dir/src/main.cpp.o -c /root/CLionProjects/surwild/src/main.cpp

CMakeFiles/surwild.dir/src/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/surwild.dir/src/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /root/CLionProjects/surwild/src/main.cpp > CMakeFiles/surwild.dir/src/main.cpp.i

CMakeFiles/surwild.dir/src/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/surwild.dir/src/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /root/CLionProjects/surwild/src/main.cpp -o CMakeFiles/surwild.dir/src/main.cpp.s

# Object files for target surwild
surwild_OBJECTS = \
"CMakeFiles/surwild.dir/src/Camera.cpp.o" \
"CMakeFiles/surwild.dir/src/Entity.cpp.o" \
"CMakeFiles/surwild.dir/src/Game.cpp.o" \
"CMakeFiles/surwild.dir/src/Map.cpp.o" \
"CMakeFiles/surwild.dir/src/PacketManager.cpp.o" \
"CMakeFiles/surwild.dir/src/Player.cpp.o" \
"CMakeFiles/surwild.dir/src/SocketClient.cpp.o" \
"CMakeFiles/surwild.dir/src/StringUtils.cpp.o" \
"CMakeFiles/surwild.dir/src/TextureManager.cpp.o" \
"CMakeFiles/surwild.dir/src/main.cpp.o"

# External object files for target surwild
surwild_EXTERNAL_OBJECTS =

surwild: CMakeFiles/surwild.dir/src/Camera.cpp.o
surwild: CMakeFiles/surwild.dir/src/Entity.cpp.o
surwild: CMakeFiles/surwild.dir/src/Game.cpp.o
surwild: CMakeFiles/surwild.dir/src/Map.cpp.o
surwild: CMakeFiles/surwild.dir/src/PacketManager.cpp.o
surwild: CMakeFiles/surwild.dir/src/Player.cpp.o
surwild: CMakeFiles/surwild.dir/src/SocketClient.cpp.o
surwild: CMakeFiles/surwild.dir/src/StringUtils.cpp.o
surwild: CMakeFiles/surwild.dir/src/TextureManager.cpp.o
surwild: CMakeFiles/surwild.dir/src/main.cpp.o
surwild: CMakeFiles/surwild.dir/build.make
surwild: /usr/lib/x86_64-linux-gnu/libSDL2_image.so
surwild: CMakeFiles/surwild.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/root/CLionProjects/surwild/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_11) "Linking CXX executable surwild"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/surwild.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/surwild.dir/build: surwild
.PHONY : CMakeFiles/surwild.dir/build

CMakeFiles/surwild.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/surwild.dir/cmake_clean.cmake
.PHONY : CMakeFiles/surwild.dir/clean

CMakeFiles/surwild.dir/depend:
	cd /root/CLionProjects/surwild/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /root/CLionProjects/surwild /root/CLionProjects/surwild /root/CLionProjects/surwild/cmake-build-debug /root/CLionProjects/surwild/cmake-build-debug /root/CLionProjects/surwild/cmake-build-debug/CMakeFiles/surwild.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/surwild.dir/depend

