# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.9

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
CMAKE_COMMAND = /Applications/CLion.app/Contents/bin/cmake/bin/cmake

# The command to remove a file.
RM = /Applications/CLion.app/Contents/bin/cmake/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/filipgulan/college/bioinformatics-project

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/filipgulan/college/bioinformatics-project/build

# Include any dependencies generated for this target.
include CMakeFiles/wavelet_lib.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/wavelet_lib.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/wavelet_lib.dir/flags.make

CMakeFiles/wavelet_lib.dir/src/rrr/RRRTable.cpp.o: CMakeFiles/wavelet_lib.dir/flags.make
CMakeFiles/wavelet_lib.dir/src/rrr/RRRTable.cpp.o: ../src/rrr/RRRTable.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/filipgulan/college/bioinformatics-project/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/wavelet_lib.dir/src/rrr/RRRTable.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/wavelet_lib.dir/src/rrr/RRRTable.cpp.o -c /Users/filipgulan/college/bioinformatics-project/src/rrr/RRRTable.cpp

CMakeFiles/wavelet_lib.dir/src/rrr/RRRTable.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/wavelet_lib.dir/src/rrr/RRRTable.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/filipgulan/college/bioinformatics-project/src/rrr/RRRTable.cpp > CMakeFiles/wavelet_lib.dir/src/rrr/RRRTable.cpp.i

CMakeFiles/wavelet_lib.dir/src/rrr/RRRTable.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/wavelet_lib.dir/src/rrr/RRRTable.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/filipgulan/college/bioinformatics-project/src/rrr/RRRTable.cpp -o CMakeFiles/wavelet_lib.dir/src/rrr/RRRTable.cpp.s

CMakeFiles/wavelet_lib.dir/src/rrr/RRRTable.cpp.o.requires:

.PHONY : CMakeFiles/wavelet_lib.dir/src/rrr/RRRTable.cpp.o.requires

CMakeFiles/wavelet_lib.dir/src/rrr/RRRTable.cpp.o.provides: CMakeFiles/wavelet_lib.dir/src/rrr/RRRTable.cpp.o.requires
	$(MAKE) -f CMakeFiles/wavelet_lib.dir/build.make CMakeFiles/wavelet_lib.dir/src/rrr/RRRTable.cpp.o.provides.build
.PHONY : CMakeFiles/wavelet_lib.dir/src/rrr/RRRTable.cpp.o.provides

CMakeFiles/wavelet_lib.dir/src/rrr/RRRTable.cpp.o.provides.build: CMakeFiles/wavelet_lib.dir/src/rrr/RRRTable.cpp.o


CMakeFiles/wavelet_lib.dir/src/rrr/RRRSequence.cpp.o: CMakeFiles/wavelet_lib.dir/flags.make
CMakeFiles/wavelet_lib.dir/src/rrr/RRRSequence.cpp.o: ../src/rrr/RRRSequence.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/filipgulan/college/bioinformatics-project/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/wavelet_lib.dir/src/rrr/RRRSequence.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/wavelet_lib.dir/src/rrr/RRRSequence.cpp.o -c /Users/filipgulan/college/bioinformatics-project/src/rrr/RRRSequence.cpp

CMakeFiles/wavelet_lib.dir/src/rrr/RRRSequence.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/wavelet_lib.dir/src/rrr/RRRSequence.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/filipgulan/college/bioinformatics-project/src/rrr/RRRSequence.cpp > CMakeFiles/wavelet_lib.dir/src/rrr/RRRSequence.cpp.i

CMakeFiles/wavelet_lib.dir/src/rrr/RRRSequence.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/wavelet_lib.dir/src/rrr/RRRSequence.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/filipgulan/college/bioinformatics-project/src/rrr/RRRSequence.cpp -o CMakeFiles/wavelet_lib.dir/src/rrr/RRRSequence.cpp.s

CMakeFiles/wavelet_lib.dir/src/rrr/RRRSequence.cpp.o.requires:

.PHONY : CMakeFiles/wavelet_lib.dir/src/rrr/RRRSequence.cpp.o.requires

CMakeFiles/wavelet_lib.dir/src/rrr/RRRSequence.cpp.o.provides: CMakeFiles/wavelet_lib.dir/src/rrr/RRRSequence.cpp.o.requires
	$(MAKE) -f CMakeFiles/wavelet_lib.dir/build.make CMakeFiles/wavelet_lib.dir/src/rrr/RRRSequence.cpp.o.provides.build
.PHONY : CMakeFiles/wavelet_lib.dir/src/rrr/RRRSequence.cpp.o.provides

CMakeFiles/wavelet_lib.dir/src/rrr/RRRSequence.cpp.o.provides.build: CMakeFiles/wavelet_lib.dir/src/rrr/RRRSequence.cpp.o


CMakeFiles/wavelet_lib.dir/src/wavelet/WaveletNode.cpp.o: CMakeFiles/wavelet_lib.dir/flags.make
CMakeFiles/wavelet_lib.dir/src/wavelet/WaveletNode.cpp.o: ../src/wavelet/WaveletNode.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/filipgulan/college/bioinformatics-project/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/wavelet_lib.dir/src/wavelet/WaveletNode.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/wavelet_lib.dir/src/wavelet/WaveletNode.cpp.o -c /Users/filipgulan/college/bioinformatics-project/src/wavelet/WaveletNode.cpp

CMakeFiles/wavelet_lib.dir/src/wavelet/WaveletNode.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/wavelet_lib.dir/src/wavelet/WaveletNode.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/filipgulan/college/bioinformatics-project/src/wavelet/WaveletNode.cpp > CMakeFiles/wavelet_lib.dir/src/wavelet/WaveletNode.cpp.i

CMakeFiles/wavelet_lib.dir/src/wavelet/WaveletNode.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/wavelet_lib.dir/src/wavelet/WaveletNode.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/filipgulan/college/bioinformatics-project/src/wavelet/WaveletNode.cpp -o CMakeFiles/wavelet_lib.dir/src/wavelet/WaveletNode.cpp.s

CMakeFiles/wavelet_lib.dir/src/wavelet/WaveletNode.cpp.o.requires:

.PHONY : CMakeFiles/wavelet_lib.dir/src/wavelet/WaveletNode.cpp.o.requires

CMakeFiles/wavelet_lib.dir/src/wavelet/WaveletNode.cpp.o.provides: CMakeFiles/wavelet_lib.dir/src/wavelet/WaveletNode.cpp.o.requires
	$(MAKE) -f CMakeFiles/wavelet_lib.dir/build.make CMakeFiles/wavelet_lib.dir/src/wavelet/WaveletNode.cpp.o.provides.build
.PHONY : CMakeFiles/wavelet_lib.dir/src/wavelet/WaveletNode.cpp.o.provides

CMakeFiles/wavelet_lib.dir/src/wavelet/WaveletNode.cpp.o.provides.build: CMakeFiles/wavelet_lib.dir/src/wavelet/WaveletNode.cpp.o


CMakeFiles/wavelet_lib.dir/src/wavelet/WaveletTree.cpp.o: CMakeFiles/wavelet_lib.dir/flags.make
CMakeFiles/wavelet_lib.dir/src/wavelet/WaveletTree.cpp.o: ../src/wavelet/WaveletTree.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/filipgulan/college/bioinformatics-project/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/wavelet_lib.dir/src/wavelet/WaveletTree.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/wavelet_lib.dir/src/wavelet/WaveletTree.cpp.o -c /Users/filipgulan/college/bioinformatics-project/src/wavelet/WaveletTree.cpp

CMakeFiles/wavelet_lib.dir/src/wavelet/WaveletTree.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/wavelet_lib.dir/src/wavelet/WaveletTree.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/filipgulan/college/bioinformatics-project/src/wavelet/WaveletTree.cpp > CMakeFiles/wavelet_lib.dir/src/wavelet/WaveletTree.cpp.i

CMakeFiles/wavelet_lib.dir/src/wavelet/WaveletTree.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/wavelet_lib.dir/src/wavelet/WaveletTree.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/filipgulan/college/bioinformatics-project/src/wavelet/WaveletTree.cpp -o CMakeFiles/wavelet_lib.dir/src/wavelet/WaveletTree.cpp.s

CMakeFiles/wavelet_lib.dir/src/wavelet/WaveletTree.cpp.o.requires:

.PHONY : CMakeFiles/wavelet_lib.dir/src/wavelet/WaveletTree.cpp.o.requires

CMakeFiles/wavelet_lib.dir/src/wavelet/WaveletTree.cpp.o.provides: CMakeFiles/wavelet_lib.dir/src/wavelet/WaveletTree.cpp.o.requires
	$(MAKE) -f CMakeFiles/wavelet_lib.dir/build.make CMakeFiles/wavelet_lib.dir/src/wavelet/WaveletTree.cpp.o.provides.build
.PHONY : CMakeFiles/wavelet_lib.dir/src/wavelet/WaveletTree.cpp.o.provides

CMakeFiles/wavelet_lib.dir/src/wavelet/WaveletTree.cpp.o.provides.build: CMakeFiles/wavelet_lib.dir/src/wavelet/WaveletTree.cpp.o


CMakeFiles/wavelet_lib.dir/src/utility/bioinf_utility.cpp.o: CMakeFiles/wavelet_lib.dir/flags.make
CMakeFiles/wavelet_lib.dir/src/utility/bioinf_utility.cpp.o: ../src/utility/bioinf_utility.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/filipgulan/college/bioinformatics-project/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/wavelet_lib.dir/src/utility/bioinf_utility.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/wavelet_lib.dir/src/utility/bioinf_utility.cpp.o -c /Users/filipgulan/college/bioinformatics-project/src/utility/bioinf_utility.cpp

CMakeFiles/wavelet_lib.dir/src/utility/bioinf_utility.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/wavelet_lib.dir/src/utility/bioinf_utility.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/filipgulan/college/bioinformatics-project/src/utility/bioinf_utility.cpp > CMakeFiles/wavelet_lib.dir/src/utility/bioinf_utility.cpp.i

CMakeFiles/wavelet_lib.dir/src/utility/bioinf_utility.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/wavelet_lib.dir/src/utility/bioinf_utility.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/filipgulan/college/bioinformatics-project/src/utility/bioinf_utility.cpp -o CMakeFiles/wavelet_lib.dir/src/utility/bioinf_utility.cpp.s

CMakeFiles/wavelet_lib.dir/src/utility/bioinf_utility.cpp.o.requires:

.PHONY : CMakeFiles/wavelet_lib.dir/src/utility/bioinf_utility.cpp.o.requires

CMakeFiles/wavelet_lib.dir/src/utility/bioinf_utility.cpp.o.provides: CMakeFiles/wavelet_lib.dir/src/utility/bioinf_utility.cpp.o.requires
	$(MAKE) -f CMakeFiles/wavelet_lib.dir/build.make CMakeFiles/wavelet_lib.dir/src/utility/bioinf_utility.cpp.o.provides.build
.PHONY : CMakeFiles/wavelet_lib.dir/src/utility/bioinf_utility.cpp.o.provides

CMakeFiles/wavelet_lib.dir/src/utility/bioinf_utility.cpp.o.provides.build: CMakeFiles/wavelet_lib.dir/src/utility/bioinf_utility.cpp.o


# Object files for target wavelet_lib
wavelet_lib_OBJECTS = \
"CMakeFiles/wavelet_lib.dir/src/rrr/RRRTable.cpp.o" \
"CMakeFiles/wavelet_lib.dir/src/rrr/RRRSequence.cpp.o" \
"CMakeFiles/wavelet_lib.dir/src/wavelet/WaveletNode.cpp.o" \
"CMakeFiles/wavelet_lib.dir/src/wavelet/WaveletTree.cpp.o" \
"CMakeFiles/wavelet_lib.dir/src/utility/bioinf_utility.cpp.o"

# External object files for target wavelet_lib
wavelet_lib_EXTERNAL_OBJECTS =

libwavelet_lib.a: CMakeFiles/wavelet_lib.dir/src/rrr/RRRTable.cpp.o
libwavelet_lib.a: CMakeFiles/wavelet_lib.dir/src/rrr/RRRSequence.cpp.o
libwavelet_lib.a: CMakeFiles/wavelet_lib.dir/src/wavelet/WaveletNode.cpp.o
libwavelet_lib.a: CMakeFiles/wavelet_lib.dir/src/wavelet/WaveletTree.cpp.o
libwavelet_lib.a: CMakeFiles/wavelet_lib.dir/src/utility/bioinf_utility.cpp.o
libwavelet_lib.a: CMakeFiles/wavelet_lib.dir/build.make
libwavelet_lib.a: CMakeFiles/wavelet_lib.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/filipgulan/college/bioinformatics-project/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Linking CXX static library libwavelet_lib.a"
	$(CMAKE_COMMAND) -P CMakeFiles/wavelet_lib.dir/cmake_clean_target.cmake
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/wavelet_lib.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/wavelet_lib.dir/build: libwavelet_lib.a

.PHONY : CMakeFiles/wavelet_lib.dir/build

CMakeFiles/wavelet_lib.dir/requires: CMakeFiles/wavelet_lib.dir/src/rrr/RRRTable.cpp.o.requires
CMakeFiles/wavelet_lib.dir/requires: CMakeFiles/wavelet_lib.dir/src/rrr/RRRSequence.cpp.o.requires
CMakeFiles/wavelet_lib.dir/requires: CMakeFiles/wavelet_lib.dir/src/wavelet/WaveletNode.cpp.o.requires
CMakeFiles/wavelet_lib.dir/requires: CMakeFiles/wavelet_lib.dir/src/wavelet/WaveletTree.cpp.o.requires
CMakeFiles/wavelet_lib.dir/requires: CMakeFiles/wavelet_lib.dir/src/utility/bioinf_utility.cpp.o.requires

.PHONY : CMakeFiles/wavelet_lib.dir/requires

CMakeFiles/wavelet_lib.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/wavelet_lib.dir/cmake_clean.cmake
.PHONY : CMakeFiles/wavelet_lib.dir/clean

CMakeFiles/wavelet_lib.dir/depend:
	cd /Users/filipgulan/college/bioinformatics-project/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/filipgulan/college/bioinformatics-project /Users/filipgulan/college/bioinformatics-project /Users/filipgulan/college/bioinformatics-project/build /Users/filipgulan/college/bioinformatics-project/build /Users/filipgulan/college/bioinformatics-project/build/CMakeFiles/wavelet_lib.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/wavelet_lib.dir/depend
