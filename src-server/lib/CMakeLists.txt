project(lib)
set(CMAKE_BUILD_TYPE Release)

# set includes and sources
include_directories(headers)
file(GLOB SOURCES "cpp/*.cpp")

# generate the shared library
add_library(d2ai SHARED ${SOURCES})

# set libmicrohttps dependency
find_path(MHD_INCLUDE_DIR NAMES microhttpd.h)
find_library(MHD_LIBRARY NAMES microhttpd libmicrohttpd libmicrohttpd-dll)
message(STATUS "MHD header: ${MHD_INCLUDE_DIR}")
message(STATUS "MHD lib   : ${MHD_LIBRARY}")
target_include_directories(d2ai PRIVATE ${MHD_INCLUDE_DIR})
target_link_libraries(d2ai ${MHD_LIBRARY})
