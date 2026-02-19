cmake_minimum_required(VERSION 3.10)
project(signals)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Find packages
find_package(OpenGL REQUIRED)
find_package(glfw3 REQUIRED)

# Add ImGui
add_subdirectory(external/imgui)

# Source files
set(SOURCES
    src/main.cpp
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
