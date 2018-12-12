cmake_minimum_required(VERSION 3.1)

project(d2ai)
set(CMAKE_CXX_STANDARD 11)

# build d2ai lib
add_subdirectory(lib)

# set includes and sources
include_directories(lib/headers passive/headers)
file(GLOB SOURCES "passive/cpp/*.cpp")

# generate and link executable
add_executable(d2ai-passive ${SOURCES})
target_link_libraries(d2ai-passive d2ai)
