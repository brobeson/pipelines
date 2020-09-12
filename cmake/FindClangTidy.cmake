find_program(
  ClangTidy_EXECUTABLE
  NAMES clang-tidy
  DOC "The path to the clang-tidy executable."
)
include(FindPackageHandleStandardArgs)
find_package_handle_standard_args(ClangTidy REQUIRED_VARS ClangTidy_EXECUTABLE)
