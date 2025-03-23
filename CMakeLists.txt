cmake_minimum_required(VERSION 3.10)
project(testsql)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Define the executable
add_executable(testsql testsql.cpp)

# Link SQLite3 dynamically
target_link_libraries(testsql PRIVATE ${CMAKE_SOURCE_DIR}/sqlite3.dll)

# Include directories (if sqlite3.h is in the same folder)
target_include_directories(testsql PRIVATE ${CMAKE_SOURCE_DIR})

# Copy sqlite3.dll to the build directory after building
add_custom_command(
    TARGET testsql POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_if_different
        ${CMAKE_SOURCE_DIR}/sqlite3.dll
        ${CMAKE_BINARY_DIR}/sqlite3.dll
)
