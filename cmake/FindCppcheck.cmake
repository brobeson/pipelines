find_program(
  Cppcheck_EXECUTABLE
  NAMES cppcheck
  DOC "The path to the Cppcheck executable."
)
include(FindPackageHandleStandardArgs)
find_package_handle_standard_args(Cppcheck REQUIRED_VARS Cppcheck_EXECUTABLE)