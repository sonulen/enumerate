cmake_minimum_required(VERSION 3.1...3.19)

project(enumerate
    VERSION "1.0"
    LANGUAGES CXX
)

# Establish the project options
option(ENUMERATE_BUILD_EXAMPLES "Set to ON to build examples" ON)
option(ENUMERATE_BUILD_TESTS "Set to ON to build tests" ON)


# Build examples when requested by the user
if (ENUMERATE_BUILD_EXAMPLES)
    add_subdirectory(src)
endif()

add_library(cxxopts INTERFACE)
add_subdirectory(include)

