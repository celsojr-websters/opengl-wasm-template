cmake_minimum_required(VERSION 3.0)
project(OpenGLProject)

add_definitions(-std=c++17)
set(CMAKE_CXX_STANDARD 17)
file(GLOB PROJECT_SOURCE src/*.cpp)

add_subdirectory(third_party/glm)
include_directories(third_party/glm)

message(STATUS "WebAssembly build enabled")
message(STATUS "CMAKE_TOOLCHAIN_FILE='${CMAKE_TOOLCHAIN_FILE}'")
if(DEFINED ENV{EMSCRIPTEN})
    message(STATUS "emscripten environment is loaded")
else()
    # Add GLFW for the native build only
    add_subdirectory(third_party/glfw)
endif()

add_executable(wasm ${PROJECT_SOURCE})
set_target_properties(wasm 
    PROPERTIES
    OUTPUT_NAME "index"
    SUFFIX ".html"
    LINK_FLAGS "-Os -s USE_WEBGL2=1 -s FULL_ES3=1 -s USE_GLFW=3 -s WASM=1")
em_link_js_library(wasm ${libraryJsFiles})
