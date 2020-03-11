cmake_minimum_required(VERSION 3.7)

project(mandelbot)

# Setup Conan
include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
conan_basic_setup()
message(STATUS "Libs: ${CONAN_LIBS}")

# Add in client and server
add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/shared/)
add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/client/)
add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/server/)
