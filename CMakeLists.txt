cmake_minimum_required(VERSION 3.20)
project(FilmTech)

# Use C++20 as specified in the VS Code settings
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Define the executable name and its source files
add_executable(filmtech
    src/main.cpp
    src/Location.cpp
    src/Role.cpp
    src/Line.cpp
    src/Scene.cpp
)

target_include_directories(filmtech PRIVATE include)
