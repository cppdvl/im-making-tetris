cmake_minimum_required(VERSION 3.15)
project(w3d VERSION 0.1 LANGUAGES CXX C)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_VERBOSE_MAKEFILE TRUE)
set(CMAKE_BUILD_TYPE DEBUG)

add_executable(w3d src/main.cpp src/glad/gl.c src/graphics/bitmap.cpp src/graphics/bitmap.h)

target_include_directories(w3d PRIVATE inc)
target_link_directories(w3d PRIVATE lib/glfw)
target_link_libraries(w3d PRIVATE glfw3 gdi32 opengl32 )
