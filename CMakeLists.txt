cmake_minimum_required(VERSION 3.12)
project(raylib-test)

# Set the C++ standard to C++11
set(CMAKE_CXX_STANDARD 20)

find_package(raylib CONFIG REQUIRED)

# Add your source files
set(SOURCES
    src/main.cpp
    src/raylib_application.h
    src/raylib_application.cpp
    src/raylib_window.h
    src/raylib_window.cpp
)

# Create the executable
add_executable(raylib-test ${SOURCES})

# Link against the raylib library
target_link_libraries(raylib-test PRIVATE raylib)
