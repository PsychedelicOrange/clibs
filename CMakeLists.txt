cmake_minimum_required(VERSION 3.10)

# Set project name
project(clib)

# generate compile_commands.json for clangd
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Define directories
set(INCLUDE_DIR ${CMAKE_SOURCE_DIR}/include)
set(SRC_DIR ${CMAKE_SOURCE_DIR}/src)
set(LIBS_OUTPUT_DIR ${CMAKE_BINARY_DIR}/libs)

# Set output directories for libraries
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${LIBS_OUTPUT_DIR})
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${LIBS_OUTPUT_DIR})

# Include directories
include_directories(${INCLUDE_DIR})

# Collect source files
file(GLOB_RECURSE SOURCES ${SRC_DIR}/*.c)

# Create static library
add_library(clib STATIC ${SOURCES})
set_target_properties(clib PROPERTIES OUTPUT_NAME "clib")

# Install targets
install(TARGETS clib
        ARCHIVE DESTINATION /usr/lib/clib/
        RUNTIME DESTINATION bin)

# Install include files
install(DIRECTORY ${INCLUDE_DIR}/ DESTINATION /usr/include/clib/ FILES_MATCHING PATTERN "*.h")
