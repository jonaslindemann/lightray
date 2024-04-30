cmake_minimum_required(VERSION 3.20)
project(lightray)

# Set the C++ standard to C++11
set(CMAKE_CXX_STANDARD 20)

set( LIBRARY_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/lib )
set( EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin )

include_directories( ${PROJECT_SOURCE_DIR}/include )

find_package(raylib CONFIG REQUIRED)

add_subdirectory(src)
