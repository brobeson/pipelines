execute_process(
  COMMAND pip3 show breathe
  RESULT_VARIABLE exit_code
  OUTPUT_QUIET
  ERROR_QUIET
)
if(exit_code EQUAL 0)
  set(BREATHE_FOUND true)
else()
  set(BREATHE_FOUND false)
endif()
include(FindPackageHandleStandardArgs)
find_package_handle_standard_args(
  Breathe
  "Failed to find Breathe. Install it from PyPI."
  BREATHE_FOUND
)