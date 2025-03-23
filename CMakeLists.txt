cmake_minimum_required(VERSION 3.10)
project(testsql)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Define the executable
add_executable(testsql testsql.cpp)

# Include directory (sqlite3.h is in "ext/")
target_include_directories(testsql PRIVATE ${CMAKE_SOURCE_DIR}/ext)

# Link SQLite3 dynamically (sqlite3.dll is in "ext/")
target_link_libraries(testsql PRIVATE ${CMAKE_SOURCE_DIR}/ext/sqlite3.dll)

# Copy sqlite3.dll to the build directory after building
add_custom_command(
    TARGET testsql POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_if_different
        ${CMAKE_SOURCE_DIR}/ext/sqlite3.dll
        ${CMAKE_BINARY_DIR}/sqlite3.dll
)
