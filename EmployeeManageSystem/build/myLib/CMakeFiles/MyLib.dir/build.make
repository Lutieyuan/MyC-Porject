# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.5

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
CMAKE_SOURCE_DIR = /mnt/hgfs/ShareDir/code/Github/MyC-Porject/EmployeeManageSystem

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /mnt/hgfs/ShareDir/code/Github/MyC-Porject/EmployeeManageSystem/build

# Include any dependencies generated for this target.
include myLib/CMakeFiles/MyLib.dir/depend.make

# Include the progress variables for this target.
include myLib/CMakeFiles/MyLib.dir/progress.make

# Include the compile flags for this target's objects.
include myLib/CMakeFiles/MyLib.dir/flags.make

myLib/CMakeFiles/MyLib.dir/boss.cpp.o: myLib/CMakeFiles/MyLib.dir/flags.make
myLib/CMakeFiles/MyLib.dir/boss.cpp.o: ../myLib/boss.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/mnt/hgfs/ShareDir/code/Github/MyC-Porject/EmployeeManageSystem/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object myLib/CMakeFiles/MyLib.dir/boss.cpp.o"
	cd /mnt/hgfs/ShareDir/code/Github/MyC-Porject/EmployeeManageSystem/build/myLib && /usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/MyLib.dir/boss.cpp.o -c /mnt/hgfs/ShareDir/code/Github/MyC-Porject/EmployeeManageSystem/myLib/boss.cpp

myLib/CMakeFiles/MyLib.dir/boss.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/MyLib.dir/boss.cpp.i"
	cd /mnt/hgfs/ShareDir/code/Github/MyC-Porject/EmployeeManageSystem/build/myLib && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /mnt/hgfs/ShareDir/code/Github/MyC-Porject/EmployeeManageSystem/myLib/boss.cpp > CMakeFiles/MyLib.dir/boss.cpp.i

myLib/CMakeFiles/MyLib.dir/boss.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/MyLib.dir/boss.cpp.s"
	cd /mnt/hgfs/ShareDir/code/Github/MyC-Porject/EmployeeManageSystem/build/myLib && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /mnt/hgfs/ShareDir/code/Github/MyC-Porject/EmployeeManageSystem/myLib/boss.cpp -o CMakeFiles/MyLib.dir/boss.cpp.s

myLib/CMakeFiles/MyLib.dir/boss.cpp.o.requires:

.PHONY : myLib/CMakeFiles/MyLib.dir/boss.cpp.o.requires

myLib/CMakeFiles/MyLib.dir/boss.cpp.o.provides: myLib/CMakeFiles/MyLib.dir/boss.cpp.o.requires
	$(MAKE) -f myLib/CMakeFiles/MyLib.dir/build.make myLib/CMakeFiles/MyLib.dir/boss.cpp.o.provides.build
.PHONY : myLib/CMakeFiles/MyLib.dir/boss.cpp.o.provides

myLib/CMakeFiles/MyLib.dir/boss.cpp.o.provides.build: myLib/CMakeFiles/MyLib.dir/boss.cpp.o


myLib/CMakeFiles/MyLib.dir/employeeManager.cpp.o: myLib/CMakeFiles/MyLib.dir/flags.make
myLib/CMakeFiles/MyLib.dir/employeeManager.cpp.o: ../myLib/employeeManager.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/mnt/hgfs/ShareDir/code/Github/MyC-Porject/EmployeeManageSystem/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object myLib/CMakeFiles/MyLib.dir/employeeManager.cpp.o"
	cd /mnt/hgfs/ShareDir/code/Github/MyC-Porject/EmployeeManageSystem/build/myLib && /usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/MyLib.dir/employeeManager.cpp.o -c /mnt/hgfs/ShareDir/code/Github/MyC-Porject/EmployeeManageSystem/myLib/employeeManager.cpp

myLib/CMakeFiles/MyLib.dir/employeeManager.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/MyLib.dir/employeeManager.cpp.i"
	cd /mnt/hgfs/ShareDir/code/Github/MyC-Porject/EmployeeManageSystem/build/myLib && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /mnt/hgfs/ShareDir/code/Github/MyC-Porject/EmployeeManageSystem/myLib/employeeManager.cpp > CMakeFiles/MyLib.dir/employeeManager.cpp.i

myLib/CMakeFiles/MyLib.dir/employeeManager.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/MyLib.dir/employeeManager.cpp.s"
	cd /mnt/hgfs/ShareDir/code/Github/MyC-Porject/EmployeeManageSystem/build/myLib && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /mnt/hgfs/ShareDir/code/Github/MyC-Porject/EmployeeManageSystem/myLib/employeeManager.cpp -o CMakeFiles/MyLib.dir/employeeManager.cpp.s

myLib/CMakeFiles/MyLib.dir/employeeManager.cpp.o.requires:

.PHONY : myLib/CMakeFiles/MyLib.dir/employeeManager.cpp.o.requires

myLib/CMakeFiles/MyLib.dir/employeeManager.cpp.o.provides: myLib/CMakeFiles/MyLib.dir/employeeManager.cpp.o.requires
	$(MAKE) -f myLib/CMakeFiles/MyLib.dir/build.make myLib/CMakeFiles/MyLib.dir/employeeManager.cpp.o.provides.build
.PHONY : myLib/CMakeFiles/MyLib.dir/employeeManager.cpp.o.provides

myLib/CMakeFiles/MyLib.dir/employeeManager.cpp.o.provides.build: myLib/CMakeFiles/MyLib.dir/employeeManager.cpp.o


myLib/CMakeFiles/MyLib.dir/manager.cpp.o: myLib/CMakeFiles/MyLib.dir/flags.make
myLib/CMakeFiles/MyLib.dir/manager.cpp.o: ../myLib/manager.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/mnt/hgfs/ShareDir/code/Github/MyC-Porject/EmployeeManageSystem/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object myLib/CMakeFiles/MyLib.dir/manager.cpp.o"
	cd /mnt/hgfs/ShareDir/code/Github/MyC-Porject/EmployeeManageSystem/build/myLib && /usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/MyLib.dir/manager.cpp.o -c /mnt/hgfs/ShareDir/code/Github/MyC-Porject/EmployeeManageSystem/myLib/manager.cpp

myLib/CMakeFiles/MyLib.dir/manager.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/MyLib.dir/manager.cpp.i"
	cd /mnt/hgfs/ShareDir/code/Github/MyC-Porject/EmployeeManageSystem/build/myLib && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /mnt/hgfs/ShareDir/code/Github/MyC-Porject/EmployeeManageSystem/myLib/manager.cpp > CMakeFiles/MyLib.dir/manager.cpp.i

myLib/CMakeFiles/MyLib.dir/manager.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/MyLib.dir/manager.cpp.s"
	cd /mnt/hgfs/ShareDir/code/Github/MyC-Porject/EmployeeManageSystem/build/myLib && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /mnt/hgfs/ShareDir/code/Github/MyC-Porject/EmployeeManageSystem/myLib/manager.cpp -o CMakeFiles/MyLib.dir/manager.cpp.s

myLib/CMakeFiles/MyLib.dir/manager.cpp.o.requires:

.PHONY : myLib/CMakeFiles/MyLib.dir/manager.cpp.o.requires

myLib/CMakeFiles/MyLib.dir/manager.cpp.o.provides: myLib/CMakeFiles/MyLib.dir/manager.cpp.o.requires
	$(MAKE) -f myLib/CMakeFiles/MyLib.dir/build.make myLib/CMakeFiles/MyLib.dir/manager.cpp.o.provides.build
.PHONY : myLib/CMakeFiles/MyLib.dir/manager.cpp.o.provides

myLib/CMakeFiles/MyLib.dir/manager.cpp.o.provides.build: myLib/CMakeFiles/MyLib.dir/manager.cpp.o


myLib/CMakeFiles/MyLib.dir/worker.cpp.o: myLib/CMakeFiles/MyLib.dir/flags.make
myLib/CMakeFiles/MyLib.dir/worker.cpp.o: ../myLib/worker.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/mnt/hgfs/ShareDir/code/Github/MyC-Porject/EmployeeManageSystem/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object myLib/CMakeFiles/MyLib.dir/worker.cpp.o"
	cd /mnt/hgfs/ShareDir/code/Github/MyC-Porject/EmployeeManageSystem/build/myLib && /usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/MyLib.dir/worker.cpp.o -c /mnt/hgfs/ShareDir/code/Github/MyC-Porject/EmployeeManageSystem/myLib/worker.cpp

myLib/CMakeFiles/MyLib.dir/worker.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/MyLib.dir/worker.cpp.i"
	cd /mnt/hgfs/ShareDir/code/Github/MyC-Porject/EmployeeManageSystem/build/myLib && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /mnt/hgfs/ShareDir/code/Github/MyC-Porject/EmployeeManageSystem/myLib/worker.cpp > CMakeFiles/MyLib.dir/worker.cpp.i

myLib/CMakeFiles/MyLib.dir/worker.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/MyLib.dir/worker.cpp.s"
	cd /mnt/hgfs/ShareDir/code/Github/MyC-Porject/EmployeeManageSystem/build/myLib && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /mnt/hgfs/ShareDir/code/Github/MyC-Porject/EmployeeManageSystem/myLib/worker.cpp -o CMakeFiles/MyLib.dir/worker.cpp.s

myLib/CMakeFiles/MyLib.dir/worker.cpp.o.requires:

.PHONY : myLib/CMakeFiles/MyLib.dir/worker.cpp.o.requires

myLib/CMakeFiles/MyLib.dir/worker.cpp.o.provides: myLib/CMakeFiles/MyLib.dir/worker.cpp.o.requires
	$(MAKE) -f myLib/CMakeFiles/MyLib.dir/build.make myLib/CMakeFiles/MyLib.dir/worker.cpp.o.provides.build
.PHONY : myLib/CMakeFiles/MyLib.dir/worker.cpp.o.provides

myLib/CMakeFiles/MyLib.dir/worker.cpp.o.provides.build: myLib/CMakeFiles/MyLib.dir/worker.cpp.o


# Object files for target MyLib
MyLib_OBJECTS = \
"CMakeFiles/MyLib.dir/boss.cpp.o" \
"CMakeFiles/MyLib.dir/employeeManager.cpp.o" \
"CMakeFiles/MyLib.dir/manager.cpp.o" \
"CMakeFiles/MyLib.dir/worker.cpp.o"

# External object files for target MyLib
MyLib_EXTERNAL_OBJECTS =

myLib/libMyLib.a: myLib/CMakeFiles/MyLib.dir/boss.cpp.o
myLib/libMyLib.a: myLib/CMakeFiles/MyLib.dir/employeeManager.cpp.o
myLib/libMyLib.a: myLib/CMakeFiles/MyLib.dir/manager.cpp.o
myLib/libMyLib.a: myLib/CMakeFiles/MyLib.dir/worker.cpp.o
myLib/libMyLib.a: myLib/CMakeFiles/MyLib.dir/build.make
myLib/libMyLib.a: myLib/CMakeFiles/MyLib.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/mnt/hgfs/ShareDir/code/Github/MyC-Porject/EmployeeManageSystem/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Linking CXX static library libMyLib.a"
	cd /mnt/hgfs/ShareDir/code/Github/MyC-Porject/EmployeeManageSystem/build/myLib && $(CMAKE_COMMAND) -P CMakeFiles/MyLib.dir/cmake_clean_target.cmake
	cd /mnt/hgfs/ShareDir/code/Github/MyC-Porject/EmployeeManageSystem/build/myLib && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/MyLib.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
myLib/CMakeFiles/MyLib.dir/build: myLib/libMyLib.a

.PHONY : myLib/CMakeFiles/MyLib.dir/build

myLib/CMakeFiles/MyLib.dir/requires: myLib/CMakeFiles/MyLib.dir/boss.cpp.o.requires
myLib/CMakeFiles/MyLib.dir/requires: myLib/CMakeFiles/MyLib.dir/employeeManager.cpp.o.requires
myLib/CMakeFiles/MyLib.dir/requires: myLib/CMakeFiles/MyLib.dir/manager.cpp.o.requires
myLib/CMakeFiles/MyLib.dir/requires: myLib/CMakeFiles/MyLib.dir/worker.cpp.o.requires

.PHONY : myLib/CMakeFiles/MyLib.dir/requires

myLib/CMakeFiles/MyLib.dir/clean:
	cd /mnt/hgfs/ShareDir/code/Github/MyC-Porject/EmployeeManageSystem/build/myLib && $(CMAKE_COMMAND) -P CMakeFiles/MyLib.dir/cmake_clean.cmake
.PHONY : myLib/CMakeFiles/MyLib.dir/clean

myLib/CMakeFiles/MyLib.dir/depend:
	cd /mnt/hgfs/ShareDir/code/Github/MyC-Porject/EmployeeManageSystem/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /mnt/hgfs/ShareDir/code/Github/MyC-Porject/EmployeeManageSystem /mnt/hgfs/ShareDir/code/Github/MyC-Porject/EmployeeManageSystem/myLib /mnt/hgfs/ShareDir/code/Github/MyC-Porject/EmployeeManageSystem/build /mnt/hgfs/ShareDir/code/Github/MyC-Porject/EmployeeManageSystem/build/myLib /mnt/hgfs/ShareDir/code/Github/MyC-Porject/EmployeeManageSystem/build/myLib/CMakeFiles/MyLib.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : myLib/CMakeFiles/MyLib.dir/depend

