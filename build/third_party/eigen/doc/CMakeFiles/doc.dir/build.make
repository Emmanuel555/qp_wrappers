# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.16

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
CMAKE_COMMAND = /usr/local/Cellar/cmake/3.16.4/bin/cmake

# The command to remove a file.
RM = /usr/local/Cellar/cmake/3.16.4/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/vikramansathiyanarayanan/Desktop/qp_wrappers

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/vikramansathiyanarayanan/Desktop/qp_wrappers/build

# Utility rule file for doc.

# Include the progress variables for this target.
include third_party/eigen/doc/CMakeFiles/doc.dir/progress.make

third_party/eigen/doc/CMakeFiles/doc:
	cd /Users/vikramansathiyanarayanan/Desktop/qp_wrappers/build/third_party/eigen/doc && doxygen
	cd /Users/vikramansathiyanarayanan/Desktop/qp_wrappers/build/third_party/eigen/doc && doxygen Doxyfile-unsupported
	cd /Users/vikramansathiyanarayanan/Desktop/qp_wrappers/build/third_party/eigen/doc && /usr/local/Cellar/cmake/3.16.4/bin/cmake -E copy /Users/vikramansathiyanarayanan/Desktop/qp_wrappers/build/third_party/eigen/doc/html/group__TopicUnalignedArrayAssert.html /Users/vikramansathiyanarayanan/Desktop/qp_wrappers/build/third_party/eigen/doc/html/TopicUnalignedArrayAssert.html
	cd /Users/vikramansathiyanarayanan/Desktop/qp_wrappers/build/third_party/eigen/doc && /usr/local/Cellar/cmake/3.16.4/bin/cmake -E rename html eigen-doc
	cd /Users/vikramansathiyanarayanan/Desktop/qp_wrappers/build/third_party/eigen/doc && /usr/local/Cellar/cmake/3.16.4/bin/cmake -E remove eigen-doc/eigen-doc.tgz eigen-doc/unsupported/_formulas.log eigen-doc/_formulas.log
	cd /Users/vikramansathiyanarayanan/Desktop/qp_wrappers/build/third_party/eigen/doc && /usr/local/Cellar/cmake/3.16.4/bin/cmake -E tar cfz eigen-doc.tgz eigen-doc
	cd /Users/vikramansathiyanarayanan/Desktop/qp_wrappers/build/third_party/eigen/doc && /usr/local/Cellar/cmake/3.16.4/bin/cmake -E rename eigen-doc.tgz eigen-doc/eigen-doc.tgz
	cd /Users/vikramansathiyanarayanan/Desktop/qp_wrappers/build/third_party/eigen/doc && /usr/local/Cellar/cmake/3.16.4/bin/cmake -E rename eigen-doc html

doc: third_party/eigen/doc/CMakeFiles/doc
doc: third_party/eigen/doc/CMakeFiles/doc.dir/build.make

.PHONY : doc

# Rule to build all files generated by this target.
third_party/eigen/doc/CMakeFiles/doc.dir/build: doc

.PHONY : third_party/eigen/doc/CMakeFiles/doc.dir/build

third_party/eigen/doc/CMakeFiles/doc.dir/clean:
	cd /Users/vikramansathiyanarayanan/Desktop/qp_wrappers/build/third_party/eigen/doc && $(CMAKE_COMMAND) -P CMakeFiles/doc.dir/cmake_clean.cmake
.PHONY : third_party/eigen/doc/CMakeFiles/doc.dir/clean

third_party/eigen/doc/CMakeFiles/doc.dir/depend:
	cd /Users/vikramansathiyanarayanan/Desktop/qp_wrappers/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/vikramansathiyanarayanan/Desktop/qp_wrappers /Users/vikramansathiyanarayanan/Desktop/qp_wrappers/third_party/eigen/doc /Users/vikramansathiyanarayanan/Desktop/qp_wrappers/build /Users/vikramansathiyanarayanan/Desktop/qp_wrappers/build/third_party/eigen/doc /Users/vikramansathiyanarayanan/Desktop/qp_wrappers/build/third_party/eigen/doc/CMakeFiles/doc.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : third_party/eigen/doc/CMakeFiles/doc.dir/depend

