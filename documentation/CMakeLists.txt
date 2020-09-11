find_package(Doxygen REQUIRED)
get_target_property(
  pipelines_header_directory pipelines INTERFACE_INCLUDE_DIRECTORIES
)
file(GLOB_RECURSE pipelines_headers "${pipelines_header_directory}/*.h")
add_custom_command(
  OUTPUT "${CMAKE_CURRENT_SOURCE_DIR}/xml/index.xml"
  DEPENDS ${pipelines_headers}
  COMMAND ${DOXYGEN_EXECUTABLE} doxyfile
  WORKING_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}"
  MAIN_DEPENDENCY doxyfile
  COMMENT "Generating documentation with Doxygen"
)
add_custom_target(doxygen ALL DEPENDS "${CMAKE_CURRENT_SOURCE_DIR}/xml/index.xml")

list(APPEND CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake")
find_package(Sphinx REQUIRED)
find_package(Breathe REQUIRED)
add_custom_command(
  OUTPUT "${CMAKE_CURRENT_BINARY_DIR}/documentation/sphinx/index.html"
  DEPENDS ${restructured_text_files}
  COMMAND
    ${SPHINX_EXECUTABLE}
    -b html
    -Dbreathe_projects.pipelines="${CMAKE_CURRENT_SOURCE_DIR}/xml"
    "${CMAKE_CURRENT_SOURCE_DIR}"
    "${CMAKE_CURRENT_BINARY_DIR}/documentation/sphinx"
  WORKING_DIRECTORY "${CMAKE_CURRENT_BINARY_DIR}"
  COMMENT "Generating documention with Sphinx"
)
add_custom_target(sphinx ALL DEPENDS "${CMAKE_CURRENT_BINARY_DIR}/documentation/sphinx/index.html")
