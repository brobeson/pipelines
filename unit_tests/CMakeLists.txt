find_package(Cppcheck REQUIRED)
if(Cppcheck_FOUND)
  set(
    cppcheck_command
    ${Cppcheck_EXECUTABLE}
    --enable=all
    --error-exitcode=1
    --project=${CMAKE_BINARY_DIR}/compile_commands.json
    --suppress=missingIncludeSystem
    --suppress=unmatchedSuppression
  )
endif()

find_package(ClangTidy REQUIRED)
if(ClangTidy_FOUND)
  set(
    clangtidy_command
    ${ClangTidy_EXECUTABLE}
    -p ${CMAKE_BINARY_DIR}/compile_commands.json
    --extra-arg=-Wno-unknown-warning-option
  )
endif()

find_package(Catch2 REQUIRED)
include(Catch)
include(PipelinesCompilerSupport)

set(tests pipe_test)
foreach(test IN LISTS tests)
  add_executable(${test} ${test}.cpp)
  target_link_libraries(${test} PRIVATE pipelines::pipelines Catch2::Catch2)
  target_compile_options(${test} PRIVATE ${pipelines_compiler_options})
  set_target_properties(
    ${test}
    PROPERTIES
      CXX_CLANG_TIDY "${clangtidy_command}"
      CXX_CPPCHECK "${cppcheck_command}"
    )
  catch_discover_tests(${test})
endforeach()
