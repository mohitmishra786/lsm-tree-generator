cmake_minimum_required(VERSION 3.10)
project(LSMTree)

set(CMAKE_C_STANDARD 11)

# Include directories
include_directories(${PROJECT_SOURCE_DIR}/include)

# Source files for main executable
file(GLOB SOURCES "src/*.c" "main.c")

# Main executable
add_executable(lsm_tree ${SOURCES})

# Testing
if(CMAKE_PROJECT_NAME STREQUAL PROJECT_NAME AND BUILD_TESTING)
    enable_testing()
    add_subdirectory(tests)
endif()