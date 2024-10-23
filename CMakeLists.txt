cmake_minimum_required(VERSION 3.30)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_C_COMPILER "gcc")
set(CMAKE_CXX_COMPILER "icpx")
set (CMAKE_CXX_STANDARD 26)

project(Project)

add_subdirectory(src)
add_subdirectory(tests)

include(FetchContent)

FetchContent_Declare(
    cli11_proj
    QUIET
    GIT_REPOSITORY https://github.com/CLIUtils/CLI11.git
    GIT_TAG v2.3.2
)

FetchContent_Declare(
    googletest
    QUIET
    GIT_REPOSITORY https://github.com/google/googletest.git
    GIT_TAG v1.15.2
)

FetchContent_Declare(
    json
    QUIET
    GIT_REPOSITORY https://github.com/nlohmann/json.git
    GIT_TAG v3.11.3
)

FetchContent_Declare(
    fmt
    QUIET
    GIT_REPOSITORY https://github.com/fmtlib/fmt.git
    GIT_TAG 11.0.2
)

FetchContent_Declare(
    jsontoolkit
    QUIET
    GIT_REPOSITORY https://github.com/sourcemeta/jsontoolkit.git
    GIT_TAG v2.0.0
)

# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)

FetchContent_MakeAvailable(googletest)
FetchContent_MakeAvailable(cli11_proj)
FetchContent_MakeAvailable(json)
FetchContent_MakeAvailable(jsontoolkit)
FetchContent_MakeAvailable(fmt)
