add_library(pipelines INTERFACE)
target_include_directories(pipelines INTERFACE "${CMAKE_CURRENT_SOURCE_DIR}")
add_library(pipelines::pipelines ALIAS pipelines)
