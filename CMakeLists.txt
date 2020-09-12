cmake_minimum_required(VERSION 3.16)
project(pipelines LANGUAGES CXX)

list(APPEND CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake")
include(PipelinesCompilerSupport)
add_subdirectory(pipelines)

include(CTest)
if(BUILD_TESTING)
  add_subdirectory(unit_tests)
endif()

add_subdirectory(documentation)

# TODO - Add a license, and credit the Catch2 library for unit tests.
# TODO - Add CMake code to generate installation packages.
# TODO - Add Cppcheck to the build process.
# TODO - Add clang-tidy to the build process.
# TODO - Add include-what-you-use to the build process.
# TODO - Add Travis CI.
# TODO - Add address sanitizer to the unit tests.
# TODO - Add Valgrind to the unit tests.
# TODO - Add test coverage to the build process.
# TODO - Configure the Doxygen configuration file using CMake variables.
# TODO - Consider using an installation of Catch2, instead of the single header.
# TODO - Consider adding a target to build PDF documentation with Sphinx.
# TODO - Update the Doxygen, Sphinx, and Breathe configurations. This may allow cleaning up the .gitignore file.
# TODO - Clean up documentation/CMakeLists.txt.
# TODO - Add INTERFACE properties to the library.
# TODO - Add support for Visual Studio.