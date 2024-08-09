cmake_minimum_required(VERSION 3.10)

# Project Name
project(RPG)

# C++ Standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Find SFML
find_package(SFML 2.5 COMPONENTS system window graphics network audio REQUIRED)

# Include directories
include_directories(${SFML_INCLUDE_DIRS})

# Source files
file(GLOB SOURCES "*.cpp")

# Executable
add_executable(${PROJECT_NAME} ${SOURCES})

# Link SFML libraries
target_link_libraries(${PROJECT_NAME} sfml-system sfml-window sfml-graphics sfml-network sfml-audio)

