cmake_minimum_required(VERSION 3.16)

add_executable(app "sandboxApp.cpp")

# properties
target_compile_features(app
    PRIVATE
        cxx_std_20)

# compiler settings
include(CMakeshift/TargetCompileSettings)
cmakeshift_target_compile_settings(app
    PRIVATE
        default)

target_compile_definitions(app
    PRIVATE
        gsl_CONFIG_CONTRACT_VIOLATION_THROWS # make `Expects()` throw an exception on precondition failure (so we can write unit tests for failure)
        gsl_CONFIG_CONTRACT_CHECKING_AUDIT) # enable audit-level checks

# library dependencies
target_link_libraries(app
    PRIVATE
        graphicsEngine)
