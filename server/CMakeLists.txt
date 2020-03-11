cmake_minimum_required(VERSION 3.7)

# Find all source files
file(GLOB_RECURSE SERVER_SRCS
    "src/*.cpp"
    "src/*.c"
    RELATIVE_PATH
)

set(OpenGL_GL_PREFERENCE GLVND)

find_package (Threads)

add_executable(server ${SERVER_SRCS})
target_include_directories(server PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include/)
target_link_libraries(server ${CMAKE_THREAD_LIBS_INIT})
target_link_libraries(server ${CONAN_LIBS})
set_property(TARGET server PROPERTY CXX_STANDARD 20)

# Flags
if(MSVC)
    target_compile_options(server PRIVATE /W4 /WX)
else()
    set(SERVER_WARNING_FLAGS "-Wall -Wextra -pedantic -Werror -Wno-unknown-pragmas -Wno-unused-parameter")
    if(DEFINED CMAKE_BUILD_TYPE AND CMAKE_BUILD_TYPE EQUAL "Debug")
        target_compile_options(server PRIVATE "${SERVER_WARNING_FLAGS} -g -fprofile-arcs -ftest-coverage")
    endif()
    if(DEFINED CMAKE_BUILD_TYPE AND CMAKE_BUILD_TYPE EQUAL "Release")
        target_compile_options(server PRIVATE "${SERVER_WARNING_FLAGS} -flto -O3")
    endif()
endif()