# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.10

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
CMAKE_COMMAND = /home/gabriel/.local/share/JetBrains/Toolbox/apps/CLion/ch-0/181.5281.33/bin/cmake/bin/cmake

# The command to remove a file.
RM = /home/gabriel/.local/share/JetBrains/Toolbox/apps/CLion/ch-0/181.5281.33/bin/cmake/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/gabriel/Projetos/ray-tracer

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/gabriel/Projetos/ray-tracer/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/ray_tracer.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/ray_tracer.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/ray_tracer.dir/flags.make

CMakeFiles/ray_tracer.dir/main.cpp.o: CMakeFiles/ray_tracer.dir/flags.make
CMakeFiles/ray_tracer.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/gabriel/Projetos/ray-tracer/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/ray_tracer.dir/main.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/ray_tracer.dir/main.cpp.o -c /home/gabriel/Projetos/ray-tracer/main.cpp

CMakeFiles/ray_tracer.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ray_tracer.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/gabriel/Projetos/ray-tracer/main.cpp > CMakeFiles/ray_tracer.dir/main.cpp.i

CMakeFiles/ray_tracer.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ray_tracer.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/gabriel/Projetos/ray-tracer/main.cpp -o CMakeFiles/ray_tracer.dir/main.cpp.s

CMakeFiles/ray_tracer.dir/main.cpp.o.requires:

.PHONY : CMakeFiles/ray_tracer.dir/main.cpp.o.requires

CMakeFiles/ray_tracer.dir/main.cpp.o.provides: CMakeFiles/ray_tracer.dir/main.cpp.o.requires
	$(MAKE) -f CMakeFiles/ray_tracer.dir/build.make CMakeFiles/ray_tracer.dir/main.cpp.o.provides.build
.PHONY : CMakeFiles/ray_tracer.dir/main.cpp.o.provides

CMakeFiles/ray_tracer.dir/main.cpp.o.provides.build: CMakeFiles/ray_tracer.dir/main.cpp.o


CMakeFiles/ray_tracer.dir/engine/Renderer.cpp.o: CMakeFiles/ray_tracer.dir/flags.make
CMakeFiles/ray_tracer.dir/engine/Renderer.cpp.o: ../engine/Renderer.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/gabriel/Projetos/ray-tracer/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/ray_tracer.dir/engine/Renderer.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/ray_tracer.dir/engine/Renderer.cpp.o -c /home/gabriel/Projetos/ray-tracer/engine/Renderer.cpp

CMakeFiles/ray_tracer.dir/engine/Renderer.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ray_tracer.dir/engine/Renderer.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/gabriel/Projetos/ray-tracer/engine/Renderer.cpp > CMakeFiles/ray_tracer.dir/engine/Renderer.cpp.i

CMakeFiles/ray_tracer.dir/engine/Renderer.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ray_tracer.dir/engine/Renderer.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/gabriel/Projetos/ray-tracer/engine/Renderer.cpp -o CMakeFiles/ray_tracer.dir/engine/Renderer.cpp.s

CMakeFiles/ray_tracer.dir/engine/Renderer.cpp.o.requires:

.PHONY : CMakeFiles/ray_tracer.dir/engine/Renderer.cpp.o.requires

CMakeFiles/ray_tracer.dir/engine/Renderer.cpp.o.provides: CMakeFiles/ray_tracer.dir/engine/Renderer.cpp.o.requires
	$(MAKE) -f CMakeFiles/ray_tracer.dir/build.make CMakeFiles/ray_tracer.dir/engine/Renderer.cpp.o.provides.build
.PHONY : CMakeFiles/ray_tracer.dir/engine/Renderer.cpp.o.provides

CMakeFiles/ray_tracer.dir/engine/Renderer.cpp.o.provides.build: CMakeFiles/ray_tracer.dir/engine/Renderer.cpp.o


CMakeFiles/ray_tracer.dir/world/LightSource.cpp.o: CMakeFiles/ray_tracer.dir/flags.make
CMakeFiles/ray_tracer.dir/world/LightSource.cpp.o: ../world/LightSource.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/gabriel/Projetos/ray-tracer/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/ray_tracer.dir/world/LightSource.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/ray_tracer.dir/world/LightSource.cpp.o -c /home/gabriel/Projetos/ray-tracer/world/LightSource.cpp

CMakeFiles/ray_tracer.dir/world/LightSource.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ray_tracer.dir/world/LightSource.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/gabriel/Projetos/ray-tracer/world/LightSource.cpp > CMakeFiles/ray_tracer.dir/world/LightSource.cpp.i

CMakeFiles/ray_tracer.dir/world/LightSource.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ray_tracer.dir/world/LightSource.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/gabriel/Projetos/ray-tracer/world/LightSource.cpp -o CMakeFiles/ray_tracer.dir/world/LightSource.cpp.s

CMakeFiles/ray_tracer.dir/world/LightSource.cpp.o.requires:

.PHONY : CMakeFiles/ray_tracer.dir/world/LightSource.cpp.o.requires

CMakeFiles/ray_tracer.dir/world/LightSource.cpp.o.provides: CMakeFiles/ray_tracer.dir/world/LightSource.cpp.o.requires
	$(MAKE) -f CMakeFiles/ray_tracer.dir/build.make CMakeFiles/ray_tracer.dir/world/LightSource.cpp.o.provides.build
.PHONY : CMakeFiles/ray_tracer.dir/world/LightSource.cpp.o.provides

CMakeFiles/ray_tracer.dir/world/LightSource.cpp.o.provides.build: CMakeFiles/ray_tracer.dir/world/LightSource.cpp.o


CMakeFiles/ray_tracer.dir/things/Sphere.cpp.o: CMakeFiles/ray_tracer.dir/flags.make
CMakeFiles/ray_tracer.dir/things/Sphere.cpp.o: ../things/Sphere.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/gabriel/Projetos/ray-tracer/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/ray_tracer.dir/things/Sphere.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/ray_tracer.dir/things/Sphere.cpp.o -c /home/gabriel/Projetos/ray-tracer/things/Sphere.cpp

CMakeFiles/ray_tracer.dir/things/Sphere.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ray_tracer.dir/things/Sphere.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/gabriel/Projetos/ray-tracer/things/Sphere.cpp > CMakeFiles/ray_tracer.dir/things/Sphere.cpp.i

CMakeFiles/ray_tracer.dir/things/Sphere.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ray_tracer.dir/things/Sphere.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/gabriel/Projetos/ray-tracer/things/Sphere.cpp -o CMakeFiles/ray_tracer.dir/things/Sphere.cpp.s

CMakeFiles/ray_tracer.dir/things/Sphere.cpp.o.requires:

.PHONY : CMakeFiles/ray_tracer.dir/things/Sphere.cpp.o.requires

CMakeFiles/ray_tracer.dir/things/Sphere.cpp.o.provides: CMakeFiles/ray_tracer.dir/things/Sphere.cpp.o.requires
	$(MAKE) -f CMakeFiles/ray_tracer.dir/build.make CMakeFiles/ray_tracer.dir/things/Sphere.cpp.o.provides.build
.PHONY : CMakeFiles/ray_tracer.dir/things/Sphere.cpp.o.provides

CMakeFiles/ray_tracer.dir/things/Sphere.cpp.o.provides.build: CMakeFiles/ray_tracer.dir/things/Sphere.cpp.o


CMakeFiles/ray_tracer.dir/things/Triangle.cpp.o: CMakeFiles/ray_tracer.dir/flags.make
CMakeFiles/ray_tracer.dir/things/Triangle.cpp.o: ../things/Triangle.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/gabriel/Projetos/ray-tracer/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/ray_tracer.dir/things/Triangle.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/ray_tracer.dir/things/Triangle.cpp.o -c /home/gabriel/Projetos/ray-tracer/things/Triangle.cpp

CMakeFiles/ray_tracer.dir/things/Triangle.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ray_tracer.dir/things/Triangle.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/gabriel/Projetos/ray-tracer/things/Triangle.cpp > CMakeFiles/ray_tracer.dir/things/Triangle.cpp.i

CMakeFiles/ray_tracer.dir/things/Triangle.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ray_tracer.dir/things/Triangle.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/gabriel/Projetos/ray-tracer/things/Triangle.cpp -o CMakeFiles/ray_tracer.dir/things/Triangle.cpp.s

CMakeFiles/ray_tracer.dir/things/Triangle.cpp.o.requires:

.PHONY : CMakeFiles/ray_tracer.dir/things/Triangle.cpp.o.requires

CMakeFiles/ray_tracer.dir/things/Triangle.cpp.o.provides: CMakeFiles/ray_tracer.dir/things/Triangle.cpp.o.requires
	$(MAKE) -f CMakeFiles/ray_tracer.dir/build.make CMakeFiles/ray_tracer.dir/things/Triangle.cpp.o.provides.build
.PHONY : CMakeFiles/ray_tracer.dir/things/Triangle.cpp.o.provides

CMakeFiles/ray_tracer.dir/things/Triangle.cpp.o.provides.build: CMakeFiles/ray_tracer.dir/things/Triangle.cpp.o


CMakeFiles/ray_tracer.dir/things/Plane.cpp.o: CMakeFiles/ray_tracer.dir/flags.make
CMakeFiles/ray_tracer.dir/things/Plane.cpp.o: ../things/Plane.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/gabriel/Projetos/ray-tracer/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/ray_tracer.dir/things/Plane.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/ray_tracer.dir/things/Plane.cpp.o -c /home/gabriel/Projetos/ray-tracer/things/Plane.cpp

CMakeFiles/ray_tracer.dir/things/Plane.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ray_tracer.dir/things/Plane.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/gabriel/Projetos/ray-tracer/things/Plane.cpp > CMakeFiles/ray_tracer.dir/things/Plane.cpp.i

CMakeFiles/ray_tracer.dir/things/Plane.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ray_tracer.dir/things/Plane.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/gabriel/Projetos/ray-tracer/things/Plane.cpp -o CMakeFiles/ray_tracer.dir/things/Plane.cpp.s

CMakeFiles/ray_tracer.dir/things/Plane.cpp.o.requires:

.PHONY : CMakeFiles/ray_tracer.dir/things/Plane.cpp.o.requires

CMakeFiles/ray_tracer.dir/things/Plane.cpp.o.provides: CMakeFiles/ray_tracer.dir/things/Plane.cpp.o.requires
	$(MAKE) -f CMakeFiles/ray_tracer.dir/build.make CMakeFiles/ray_tracer.dir/things/Plane.cpp.o.provides.build
.PHONY : CMakeFiles/ray_tracer.dir/things/Plane.cpp.o.provides

CMakeFiles/ray_tracer.dir/things/Plane.cpp.o.provides.build: CMakeFiles/ray_tracer.dir/things/Plane.cpp.o


CMakeFiles/ray_tracer.dir/parser/RTParser.cpp.o: CMakeFiles/ray_tracer.dir/flags.make
CMakeFiles/ray_tracer.dir/parser/RTParser.cpp.o: ../parser/RTParser.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/gabriel/Projetos/ray-tracer/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object CMakeFiles/ray_tracer.dir/parser/RTParser.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/ray_tracer.dir/parser/RTParser.cpp.o -c /home/gabriel/Projetos/ray-tracer/parser/RTParser.cpp

CMakeFiles/ray_tracer.dir/parser/RTParser.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ray_tracer.dir/parser/RTParser.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/gabriel/Projetos/ray-tracer/parser/RTParser.cpp > CMakeFiles/ray_tracer.dir/parser/RTParser.cpp.i

CMakeFiles/ray_tracer.dir/parser/RTParser.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ray_tracer.dir/parser/RTParser.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/gabriel/Projetos/ray-tracer/parser/RTParser.cpp -o CMakeFiles/ray_tracer.dir/parser/RTParser.cpp.s

CMakeFiles/ray_tracer.dir/parser/RTParser.cpp.o.requires:

.PHONY : CMakeFiles/ray_tracer.dir/parser/RTParser.cpp.o.requires

CMakeFiles/ray_tracer.dir/parser/RTParser.cpp.o.provides: CMakeFiles/ray_tracer.dir/parser/RTParser.cpp.o.requires
	$(MAKE) -f CMakeFiles/ray_tracer.dir/build.make CMakeFiles/ray_tracer.dir/parser/RTParser.cpp.o.provides.build
.PHONY : CMakeFiles/ray_tracer.dir/parser/RTParser.cpp.o.provides

CMakeFiles/ray_tracer.dir/parser/RTParser.cpp.o.provides.build: CMakeFiles/ray_tracer.dir/parser/RTParser.cpp.o


CMakeFiles/ray_tracer.dir/parser/Element.cpp.o: CMakeFiles/ray_tracer.dir/flags.make
CMakeFiles/ray_tracer.dir/parser/Element.cpp.o: ../parser/Element.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/gabriel/Projetos/ray-tracer/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Building CXX object CMakeFiles/ray_tracer.dir/parser/Element.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/ray_tracer.dir/parser/Element.cpp.o -c /home/gabriel/Projetos/ray-tracer/parser/Element.cpp

CMakeFiles/ray_tracer.dir/parser/Element.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ray_tracer.dir/parser/Element.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/gabriel/Projetos/ray-tracer/parser/Element.cpp > CMakeFiles/ray_tracer.dir/parser/Element.cpp.i

CMakeFiles/ray_tracer.dir/parser/Element.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ray_tracer.dir/parser/Element.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/gabriel/Projetos/ray-tracer/parser/Element.cpp -o CMakeFiles/ray_tracer.dir/parser/Element.cpp.s

CMakeFiles/ray_tracer.dir/parser/Element.cpp.o.requires:

.PHONY : CMakeFiles/ray_tracer.dir/parser/Element.cpp.o.requires

CMakeFiles/ray_tracer.dir/parser/Element.cpp.o.provides: CMakeFiles/ray_tracer.dir/parser/Element.cpp.o.requires
	$(MAKE) -f CMakeFiles/ray_tracer.dir/build.make CMakeFiles/ray_tracer.dir/parser/Element.cpp.o.provides.build
.PHONY : CMakeFiles/ray_tracer.dir/parser/Element.cpp.o.provides

CMakeFiles/ray_tracer.dir/parser/Element.cpp.o.provides.build: CMakeFiles/ray_tracer.dir/parser/Element.cpp.o


CMakeFiles/ray_tracer.dir/parser/ObjParser.cpp.o: CMakeFiles/ray_tracer.dir/flags.make
CMakeFiles/ray_tracer.dir/parser/ObjParser.cpp.o: ../parser/ObjParser.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/gabriel/Projetos/ray-tracer/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_9) "Building CXX object CMakeFiles/ray_tracer.dir/parser/ObjParser.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/ray_tracer.dir/parser/ObjParser.cpp.o -c /home/gabriel/Projetos/ray-tracer/parser/ObjParser.cpp

CMakeFiles/ray_tracer.dir/parser/ObjParser.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ray_tracer.dir/parser/ObjParser.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/gabriel/Projetos/ray-tracer/parser/ObjParser.cpp > CMakeFiles/ray_tracer.dir/parser/ObjParser.cpp.i

CMakeFiles/ray_tracer.dir/parser/ObjParser.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ray_tracer.dir/parser/ObjParser.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/gabriel/Projetos/ray-tracer/parser/ObjParser.cpp -o CMakeFiles/ray_tracer.dir/parser/ObjParser.cpp.s

CMakeFiles/ray_tracer.dir/parser/ObjParser.cpp.o.requires:

.PHONY : CMakeFiles/ray_tracer.dir/parser/ObjParser.cpp.o.requires

CMakeFiles/ray_tracer.dir/parser/ObjParser.cpp.o.provides: CMakeFiles/ray_tracer.dir/parser/ObjParser.cpp.o.requires
	$(MAKE) -f CMakeFiles/ray_tracer.dir/build.make CMakeFiles/ray_tracer.dir/parser/ObjParser.cpp.o.provides.build
.PHONY : CMakeFiles/ray_tracer.dir/parser/ObjParser.cpp.o.provides

CMakeFiles/ray_tracer.dir/parser/ObjParser.cpp.o.provides.build: CMakeFiles/ray_tracer.dir/parser/ObjParser.cpp.o


CMakeFiles/ray_tracer.dir/parser/Parser.cpp.o: CMakeFiles/ray_tracer.dir/flags.make
CMakeFiles/ray_tracer.dir/parser/Parser.cpp.o: ../parser/Parser.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/gabriel/Projetos/ray-tracer/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_10) "Building CXX object CMakeFiles/ray_tracer.dir/parser/Parser.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/ray_tracer.dir/parser/Parser.cpp.o -c /home/gabriel/Projetos/ray-tracer/parser/Parser.cpp

CMakeFiles/ray_tracer.dir/parser/Parser.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ray_tracer.dir/parser/Parser.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/gabriel/Projetos/ray-tracer/parser/Parser.cpp > CMakeFiles/ray_tracer.dir/parser/Parser.cpp.i

CMakeFiles/ray_tracer.dir/parser/Parser.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ray_tracer.dir/parser/Parser.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/gabriel/Projetos/ray-tracer/parser/Parser.cpp -o CMakeFiles/ray_tracer.dir/parser/Parser.cpp.s

CMakeFiles/ray_tracer.dir/parser/Parser.cpp.o.requires:

.PHONY : CMakeFiles/ray_tracer.dir/parser/Parser.cpp.o.requires

CMakeFiles/ray_tracer.dir/parser/Parser.cpp.o.provides: CMakeFiles/ray_tracer.dir/parser/Parser.cpp.o.requires
	$(MAKE) -f CMakeFiles/ray_tracer.dir/build.make CMakeFiles/ray_tracer.dir/parser/Parser.cpp.o.provides.build
.PHONY : CMakeFiles/ray_tracer.dir/parser/Parser.cpp.o.provides

CMakeFiles/ray_tracer.dir/parser/Parser.cpp.o.provides.build: CMakeFiles/ray_tracer.dir/parser/Parser.cpp.o


CMakeFiles/ray_tracer.dir/box/AABB.cpp.o: CMakeFiles/ray_tracer.dir/flags.make
CMakeFiles/ray_tracer.dir/box/AABB.cpp.o: ../box/AABB.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/gabriel/Projetos/ray-tracer/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_11) "Building CXX object CMakeFiles/ray_tracer.dir/box/AABB.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/ray_tracer.dir/box/AABB.cpp.o -c /home/gabriel/Projetos/ray-tracer/box/AABB.cpp

CMakeFiles/ray_tracer.dir/box/AABB.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ray_tracer.dir/box/AABB.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/gabriel/Projetos/ray-tracer/box/AABB.cpp > CMakeFiles/ray_tracer.dir/box/AABB.cpp.i

CMakeFiles/ray_tracer.dir/box/AABB.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ray_tracer.dir/box/AABB.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/gabriel/Projetos/ray-tracer/box/AABB.cpp -o CMakeFiles/ray_tracer.dir/box/AABB.cpp.s

CMakeFiles/ray_tracer.dir/box/AABB.cpp.o.requires:

.PHONY : CMakeFiles/ray_tracer.dir/box/AABB.cpp.o.requires

CMakeFiles/ray_tracer.dir/box/AABB.cpp.o.provides: CMakeFiles/ray_tracer.dir/box/AABB.cpp.o.requires
	$(MAKE) -f CMakeFiles/ray_tracer.dir/build.make CMakeFiles/ray_tracer.dir/box/AABB.cpp.o.provides.build
.PHONY : CMakeFiles/ray_tracer.dir/box/AABB.cpp.o.provides

CMakeFiles/ray_tracer.dir/box/AABB.cpp.o.provides.build: CMakeFiles/ray_tracer.dir/box/AABB.cpp.o


CMakeFiles/ray_tracer.dir/tree/KDTree.cpp.o: CMakeFiles/ray_tracer.dir/flags.make
CMakeFiles/ray_tracer.dir/tree/KDTree.cpp.o: ../tree/KDTree.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/gabriel/Projetos/ray-tracer/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_12) "Building CXX object CMakeFiles/ray_tracer.dir/tree/KDTree.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/ray_tracer.dir/tree/KDTree.cpp.o -c /home/gabriel/Projetos/ray-tracer/tree/KDTree.cpp

CMakeFiles/ray_tracer.dir/tree/KDTree.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ray_tracer.dir/tree/KDTree.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/gabriel/Projetos/ray-tracer/tree/KDTree.cpp > CMakeFiles/ray_tracer.dir/tree/KDTree.cpp.i

CMakeFiles/ray_tracer.dir/tree/KDTree.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ray_tracer.dir/tree/KDTree.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/gabriel/Projetos/ray-tracer/tree/KDTree.cpp -o CMakeFiles/ray_tracer.dir/tree/KDTree.cpp.s

CMakeFiles/ray_tracer.dir/tree/KDTree.cpp.o.requires:

.PHONY : CMakeFiles/ray_tracer.dir/tree/KDTree.cpp.o.requires

CMakeFiles/ray_tracer.dir/tree/KDTree.cpp.o.provides: CMakeFiles/ray_tracer.dir/tree/KDTree.cpp.o.requires
	$(MAKE) -f CMakeFiles/ray_tracer.dir/build.make CMakeFiles/ray_tracer.dir/tree/KDTree.cpp.o.provides.build
.PHONY : CMakeFiles/ray_tracer.dir/tree/KDTree.cpp.o.provides

CMakeFiles/ray_tracer.dir/tree/KDTree.cpp.o.provides.build: CMakeFiles/ray_tracer.dir/tree/KDTree.cpp.o


# Object files for target ray_tracer
ray_tracer_OBJECTS = \
"CMakeFiles/ray_tracer.dir/main.cpp.o" \
"CMakeFiles/ray_tracer.dir/engine/Renderer.cpp.o" \
"CMakeFiles/ray_tracer.dir/world/LightSource.cpp.o" \
"CMakeFiles/ray_tracer.dir/things/Sphere.cpp.o" \
"CMakeFiles/ray_tracer.dir/things/Triangle.cpp.o" \
"CMakeFiles/ray_tracer.dir/things/Plane.cpp.o" \
"CMakeFiles/ray_tracer.dir/parser/RTParser.cpp.o" \
"CMakeFiles/ray_tracer.dir/parser/Element.cpp.o" \
"CMakeFiles/ray_tracer.dir/parser/ObjParser.cpp.o" \
"CMakeFiles/ray_tracer.dir/parser/Parser.cpp.o" \
"CMakeFiles/ray_tracer.dir/box/AABB.cpp.o" \
"CMakeFiles/ray_tracer.dir/tree/KDTree.cpp.o"

# External object files for target ray_tracer
ray_tracer_EXTERNAL_OBJECTS =

ray_tracer: CMakeFiles/ray_tracer.dir/main.cpp.o
ray_tracer: CMakeFiles/ray_tracer.dir/engine/Renderer.cpp.o
ray_tracer: CMakeFiles/ray_tracer.dir/world/LightSource.cpp.o
ray_tracer: CMakeFiles/ray_tracer.dir/things/Sphere.cpp.o
ray_tracer: CMakeFiles/ray_tracer.dir/things/Triangle.cpp.o
ray_tracer: CMakeFiles/ray_tracer.dir/things/Plane.cpp.o
ray_tracer: CMakeFiles/ray_tracer.dir/parser/RTParser.cpp.o
ray_tracer: CMakeFiles/ray_tracer.dir/parser/Element.cpp.o
ray_tracer: CMakeFiles/ray_tracer.dir/parser/ObjParser.cpp.o
ray_tracer: CMakeFiles/ray_tracer.dir/parser/Parser.cpp.o
ray_tracer: CMakeFiles/ray_tracer.dir/box/AABB.cpp.o
ray_tracer: CMakeFiles/ray_tracer.dir/tree/KDTree.cpp.o
ray_tracer: CMakeFiles/ray_tracer.dir/build.make
ray_tracer: /usr/lib/libarmadillo.so
ray_tracer: CMakeFiles/ray_tracer.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/gabriel/Projetos/ray-tracer/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_13) "Linking CXX executable ray_tracer"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/ray_tracer.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/ray_tracer.dir/build: ray_tracer

.PHONY : CMakeFiles/ray_tracer.dir/build

CMakeFiles/ray_tracer.dir/requires: CMakeFiles/ray_tracer.dir/main.cpp.o.requires
CMakeFiles/ray_tracer.dir/requires: CMakeFiles/ray_tracer.dir/engine/Renderer.cpp.o.requires
CMakeFiles/ray_tracer.dir/requires: CMakeFiles/ray_tracer.dir/world/LightSource.cpp.o.requires
CMakeFiles/ray_tracer.dir/requires: CMakeFiles/ray_tracer.dir/things/Sphere.cpp.o.requires
CMakeFiles/ray_tracer.dir/requires: CMakeFiles/ray_tracer.dir/things/Triangle.cpp.o.requires
CMakeFiles/ray_tracer.dir/requires: CMakeFiles/ray_tracer.dir/things/Plane.cpp.o.requires
CMakeFiles/ray_tracer.dir/requires: CMakeFiles/ray_tracer.dir/parser/RTParser.cpp.o.requires
CMakeFiles/ray_tracer.dir/requires: CMakeFiles/ray_tracer.dir/parser/Element.cpp.o.requires
CMakeFiles/ray_tracer.dir/requires: CMakeFiles/ray_tracer.dir/parser/ObjParser.cpp.o.requires
CMakeFiles/ray_tracer.dir/requires: CMakeFiles/ray_tracer.dir/parser/Parser.cpp.o.requires
CMakeFiles/ray_tracer.dir/requires: CMakeFiles/ray_tracer.dir/box/AABB.cpp.o.requires
CMakeFiles/ray_tracer.dir/requires: CMakeFiles/ray_tracer.dir/tree/KDTree.cpp.o.requires

.PHONY : CMakeFiles/ray_tracer.dir/requires

CMakeFiles/ray_tracer.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/ray_tracer.dir/cmake_clean.cmake
.PHONY : CMakeFiles/ray_tracer.dir/clean

CMakeFiles/ray_tracer.dir/depend:
	cd /home/gabriel/Projetos/ray-tracer/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/gabriel/Projetos/ray-tracer /home/gabriel/Projetos/ray-tracer /home/gabriel/Projetos/ray-tracer/cmake-build-debug /home/gabriel/Projetos/ray-tracer/cmake-build-debug /home/gabriel/Projetos/ray-tracer/cmake-build-debug/CMakeFiles/ray_tracer.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/ray_tracer.dir/depend

