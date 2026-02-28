cmake_minimum_required(VERSION 3.20)
project(AGE LANGUAGES CXX C)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_subdirectory(external/glfw)

add_executable(AGE
    src/main.cpp
    external/glad/src/glad.c
)

target_include_directories(AGE PRIVATE
    external/glad/include
)

target_link_libraries(AGE PRIVATE glfw)

if (WIN32)
    target_link_libraries(AGE PRIVATE opengl32)
endif()