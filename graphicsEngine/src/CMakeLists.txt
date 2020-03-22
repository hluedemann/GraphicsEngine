cmake_minimum_required(VERSION 3.16)

# dependencies 
find_package(CMakeshift 3.7 REQUIRED)
find_package(gsl-lite 0.36.0 REQUIRED)


add_library(graphicsEngine STATIC
    core/application.cpp)

# properties
target_compile_features(graphicsEngine
    PUBLIC
        cxx_std_20)

target_include_directories(graphicsEngine
    PUBLIC
        "$<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}/src>")

target_include_directories(graphicsEngine
    PUBLIC
        "$<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}>/graphicsEngine/include")

include(CMakeshift/TargetCompileSettings)
    cmakeshift_target_compile_settings(graphicsEngine
        PRIVATE
            default)

# library dependencies
target_link_libraries(graphicsEngine
    PUBLIC
        gsl::gsl-lite-v1)
