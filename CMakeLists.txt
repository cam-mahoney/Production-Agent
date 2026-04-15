cmake_minimum_required(VERSION 3.20)
project(FilmTech)

# Use C++20 as specified in the VS Code settings
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Define the executable name and its source file
add_executable(filmtech src/main.cpp)
