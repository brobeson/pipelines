add_library(pipelines INTERFACE)
target_include_directories(pipelines INTERFACE "${CMAKE_CURRENT_SOURCE_DIR}")
target_compile_features(pipelines INTERFACE cxx_std_17)
add_library(pipelines::pipelines ALIAS pipelines)
