cmake_minimum_required(VERSION 3.16)
project(pipelines LANGUAGES CXX)
add_subdirectory(pipelines)

include(CTest)
if(BUILD_TESTING)
  add_subdirectory(unit_tests)
endif()

# list(APPEND CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake")
# add_subdirectory(documentation)