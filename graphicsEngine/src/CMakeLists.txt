cmake_minimum_required(VERSION 3.16)

# dependencies 
find_package(CMakeshift 3.7 REQUIRED)
find_package(gsl-lite 0.36.0 REQUIRED)

find_package(glfw3 REQUIRED)
find_package(glad REQUIRED)
find_package(glm REQUIRED)
find_package(imgui REQUIRED)
find_package(spdlog REQUIRED)

add_library(graphicsEngine STATIC
    core/application.cpp
    core/layer.cpp
    core/layerstack.cpp
    core/window.cpp
    core/input.cpp
    core/log.cpp
    renderer/renderer.cpp
    renderer/rendercommand.cpp
    renderer/graphicscontext.cpp
    renderer/vertexbuffer.cpp
    renderer/indexbuffer.cpp
    renderer/vertexarray.cpp
    renderer/shader.cpp)

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
    PRIVATE
        glfw
        glad::glad
        glm
        spdlog::spdlog
        spdlog::spdlog_header_only
    PUBLIC
        gsl::gsl-lite-v1
        imgui::imgui
        )
