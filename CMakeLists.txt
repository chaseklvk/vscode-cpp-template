cmake_minimum_required(VERSION 2.8.9)
project(main)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -Wall -Wextra")
set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} -Wall")

# make will print commands before running
# set(CMAKE_VERBOSE_MAKEFILE on)

# Bring the headers, such as utilities.hpp into the project
include_directories(include)

# However, the file(GLOB...) allows for wildcard additions:
file(GLOB SOURCES "src/*.cpp")

add_executable(main ${SOURCES})