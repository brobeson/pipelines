cmake_minimum_required(VERSION 3.16)

# The pipelines library
project(pipelines LANGUAGES CXX)
add_subdirectory(pipelines)

# Unit testing
include(CTest)
if(BUILD_TESTING)
  list(APPEND CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake")
  add_subdirectory(unit_tests)
endif()

# Generating documentation
add_subdirectory(documentation)

# Documentation Tasks
# TODO - Configure the Doxygen configuration file using CMake variables.
# TODO - Consider adding a target to build PDF documentation with Sphinx.
# TODO - Update the Doxygen, Sphinx, and Breathe configurations. This may allow cleaning up the .gitignore file.
# TODO - Clean up documentation/CMakeLists.txt.
# TODO - Move the build instructions to a .rst file and include it in the built documenation. The readme file can link to it.
# TODO - Add an option to disable building the documentation.
# TODO - Add a PyPI requirements file to install Sphinx and breathe.

# Quality Tasks
# TODO - Add clang-tidy to the build process.
# TODO - Add include-what-you-use to the build process.
# TODO - Add Travis CI.
# TODO - Add address sanitizer to the unit tests.
# TODO - Add Valgrind to the unit tests.
# TODO - Add test coverage to the build process.
# TODO - Add support for Visual Studio.
# TODO - Add Lizard to the build process.
# TODO - Add thread sanitizer to the unit tests.

# Miscellaneous Tasks
# TODO - Add a license, and credit the Catch2 library for unit tests.
# TODO - Add CMake code to generate installation packages.
# TODO - Add INTERFACE properties to the library.