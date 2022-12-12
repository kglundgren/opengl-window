cmake_minimum_required(VERSION 3.25.0)

project(opengl_window)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_C_COMPILER gcc)
set(CMAKE_CXX_COMPILER g++)
set(CMAKE_CXX_STANDARD 20)

set(SOURCES
    src/window.cpp
    src/glad/glad.c
    src/input/input.h
    src/window/init_window.h
)

add_executable(window ${SOURCES})

target_include_directories(window PRIVATE 
	$ENV{GLFW_INCLUDE}
	$ENV{GLAD_INCLUDE}
)

target_link_libraries(window PRIVATE
    $ENV{DEV_LIB}/libglfw3.a
    opengl32.a
    shell32.a
    user32.a 
    gdi32.a
)

target_compile_options(window PRIVATE
    -Wall -Wextra -Wpedantic
)
