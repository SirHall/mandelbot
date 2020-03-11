cmake_minimum_required(VERSION 3.7)

# Find all source files
file(GLOB_RECURSE CLIENT_SRCS
    "src/*.cpp"
    "src/*.c"
    RELATIVE_PATH
)

set(OpenGL_GL_PREFERENCE GLVND)

find_package (Threads)

add_executable(client ${CLIENT_SRCS})
target_include_directories(client PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include/)
target_link_libraries(client ${CMAKE_THREAD_LIBS_INIT})
target_link_libraries(client ${CONAN_LIBS})
target_link_libraries(client shared)
set_property(TARGET client PROPERTY CXX_STANDARD 20)

# Flags
if(MSVC)
    target_compile_options(client PRIVATE /W4 /WX)
else()
    set(CLIENT_WARNING_FLAGS "-Wall -Wextra -pedantic -Werror -Wno-unknown-pragmas -Wno-unused-parameter")
    if(DEFINED CMAKE_BUILD_TYPE AND CMAKE_BUILD_TYPE EQUAL "Debug")
        target_compile_options(client PRIVATE "${CLIENT_WARNING_FLAGS} -g -fprofile-arcs -ftest-coverage")
    endif()
    if(DEFINED CMAKE_BUILD_TYPE AND CMAKE_BUILD_TYPE EQUAL "Release")
        target_compile_options(client PRIVATE "${CLIENT_WARNING_FLAGS} -flto -O3")
    endif()
endif()