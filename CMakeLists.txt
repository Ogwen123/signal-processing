cmake_minimum_required(VERSION 3.10)
project(signals)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(OpenGL REQUIRED)
find_package(glfw3 REQUIRED)

add_subdirectory(external/imgui)

set(SOURCES
    src/main.cpp
    src/denoise.cpp
    src/ppm.cpp
)

# Create executable
add_executable(${PROJECT_NAME} ${SOURCES})

# Link libraries
target_link_libraries(${PROJECT_NAME} 
    ImGui
    OpenGL::OpenGL
    glfw
)

# Include directories
target_include_directories(${PROJECT_NAME} PRIVATE
    external/imgui
    external/imgui/backends
)
