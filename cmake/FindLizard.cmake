find_program(
  Lizard_EXECUTABLE
  NAMES lizard
  DOC "The path to the Lizard executable."
)
include(FindPackageHandleStandardArgs)
find_package_handle_standard_args(Lizard REQUIRED_VARS Lizard_EXECUTABLE)

function(add_lizard_target)
  if(NOT Lizard_FOUND)
    message(WARNING "The Lizard target was requested, but Lizard was not found. Install Lizard first.")
    return()
  endif()
  cmake_parse_arguments(
    lizard
    "MODIFIED"
    "CCN;ARGUMENTS;LENGTH"
    ""
    ${ARGN}
  )
  set(lizard_command "${Lizard_EXECUTABLE}" "--warnings_only")
  if(CMAKE_CXX_COMPILER_ID STREQUAL "MSVC")
    list(APPEND lizard_command "--warning-msvs")
  endif()
  cmake_host_system_information(RESULT threads QUERY NUMBER_OF_LOGICAL_CORES)
  list(APPEND lizard_command "--working_threads=${threads}")
  if(lizard_MODIFIED)
    list(APPEND lizard_command "--modified")
  endif()
  message(STATUS "the lizard command is ${lizard_command}")
  if(lizard_CCN)
    list(APPEND lizard_command "--CCN=${lizard_CCN}")
  endif()
  if(lizard_ARGUMENTS)
    list(APPEND lizard_command "--arguments=${lizard_ARGUMENTS}")
  endif()
  if(lizard_LENGTH)
    list(APPEND lizard_command "--length=${lizard_LENGTH}")
  endif()
  list(APPEND lizard_command "${CMAKE_SOURCE_DIR}")
  add_custom_target(
    lizard
    ALL
    COMMAND ${lizard_command}
    COMMENT "Running Lizard complexity analysis..."
    WORKING_DIRECTORY "${CMAKE_SOURCE_DIR}"
    VERBATIM
  )
endfunction()