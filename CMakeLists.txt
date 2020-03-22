cmake_minimum_required(VERSION 3.16)

project(GraphicsEngine
    LANGUAGES CXX)

# Allow setting the target architecture.
find_package(CMakeshift 3.7 REQUIRED)
include(CMakeshift/TargetArchitecture)

# Targets
add_subdirectory("graphicsEngine")
add_subdirectory("application")
