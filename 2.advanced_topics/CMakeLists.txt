# Basic configurations
cmake_minimum_required(VERSION 3.11) # Minimum CMake version required
project(2.ADVANCED_TOPICS
    VERSION 1.2.3.4
    LANGUAGES C CXX CUDA
    DESCRIPTION "This is a project for advanced topics in CMake."
    HOMEPAGE_URL "https://github.com/JongRok-Lee/CMake-Study"
) # Required for CMake to know what project this is

message(STATUS "")
message(STATUS "Started all process in ${PROJECT_NAME} CMakeLists.txt.")

# add_subdirectory(1.pre_defined_global_variables)
# add_subdirectory(2.setting_cpp_project)
# add_subdirectory(3.external_dependencies)
# add_subdirectory(4.automation)
message(STATUS "Finished all process in ${PROJECT_NAME} CMakeLists.txt.")
message(STATUS "")
