cmake_minimum_required(VERSION 3.0)
project(OpenGLProject)

set(CMAKE_CXX_STANDARD 17)
file(GLOB PROJECT_SOURCE ../src/*.cpp)

message(STATUS "Source files: ${PROJECT_SOURCE}")

message(STATUS ${CMAKE_SOURCE_DIR})

message(STATUS "Native build enabled")

# Set OpenGL preference to GLVND (modern OpenGL)
# set(OpenGL_GL_PREFERENCE GLVND)
# cmake_policy(SET CMP0072 NEW)

find_package(OpenGL REQUIRED)
include_directories(${OPENGL_INCLUDE_DIR})

add_executable(native ${PROJECT_SOURCE})
target_link_libraries(native ${OPENGL_gl_LIBRARY} glfw)
