# Basic configurations
cmake_minimum_required(VERSION 3.11) # Minimum CMake version required
project(2.SETTING_CPP_PROJECT) # Required for CMake to know what project this is

message(STATUS "")
message(STATUS "Started all process in ${PROJECT_NAME} CMakeLists.txt.")
message(STATUS "")

message(STATUS "Example 1: project() command")

project(2.SETTING_CPP_PROJECT
    LANGUAGES CXX
    VERSION 1.3.2.9
    DESCRIPTION "CMake Tutorial 6: Functions for Project"
    HOMEPAGE_URL "studio.holyground.com"
)

message(STATUS "")
message(STATUS "PROJECT_NAME: ${PROJECT_NAME}")
message(STATUS "PROJECT_IS_TOP_LEVEL: ${PROJECT_IS_TOP_LEVEL}")
message(STATUS "PROJECT_VERSION: ${PROJECT_VERSION}")
message(STATUS "PROJECT_VERSION_MAJOR: ${PROJECT_VERSION_MAJOR}")
message(STATUS "PROJECT_VERSION_MINOR: ${PROJECT_VERSION_MINOR}")
message(STATUS "PROJECT_VERSION_PATCH: ${PROJECT_VERSION_PATCH}")
message(STATUS "PROJECT_VERSION_TWEAK: ${PROJECT_VERSION_TWEAK}")
message(STATUS "PROJECT_DESCRIPTION: ${PROJECT_DESCRIPTION}")
message(STATUS "PROJECT_HOMEPAGE_URL: ${PROJECT_HOMEPAGE_URL}")
message(STATUS "")

message(STATUS "PROJECT_SOURCE_DIR: ${PROJECT_SOURCE_DIR}")
message(STATUS "PROJECT_BINARY_DIR: ${PROJECT_BINARY_DIR}")
message(STATUS "PROJECT_IS_TOP_LEVEL: ${PROJECT_IS_TOP_LEVEL}")
message(STATUS "")

message(STATUS "Example 2: setting CMAKE_CXX_SOMETHING variables")
message(STATUS "CMAKE_CXX_STANDARD is the variable for setting C++ standard")
message(STATUS "If CMAKE_CXX_STANDARD is not set, CMAKE_CXX_STANDARD will be set to comfiler default")
set(CMAKE_CXX_STANDARD 17)
message(STATUS "CMAKE_CXX_STANDARD is ${CMAKE_CXX_STANDARD}")
message(STATUS "")

message(STATUS "CMAKE_CXX_STANDARD_REQUIRED is the variable for setting C++ standard required")
message(STATUS "IF CMAKE_CXX_STANDARD_REQUIRED is set to ON, in case of C++ standard is not supported, CMake will throw an error")
message(STATUS "If CMAKE_CXX_STANDARD_REQUIRED is not set, CMAKE_CXX_STANDARD_REQUIRED will be set to OFF")
set(CMAKE_CXX_STANDARD_REQUIRED ON)
message(STATUS "CMAKE_CXX_STANDARD_REQUIRED is ${CMAKE_CXX_STANDARD_REQUIRED}")
message(STATUS "")

message(STATUS "CMAKE_CXX_EXTENSIONS is the variable for setting C++ standard extensions")
message(STATUS "If CMAKE_CXX_EXTENSIONS is set to ON, CMake will enable compiler extensions")
set(CMAKE_CXX_EXTENSIONS OFF)
message(STATUS "CMAKE_CXX_EXTENSIONS is ${CMAKE_CXX_EXTENSIONS}")
message(STATUS "")

message(STATUS "Example 3: add_library() command")

message(STATUS "add_library() command is used to create a library target")
message(STATUS "add_library() command has 2 types: STATIC, SHARED")
message(STATUS "STATIC: static library")
message(STATUS "SHARED: shared library")
add_library(UTILS SHARED
    src/utils.cpp
)
message(STATUS "")

message(STATUS "Example 4: target_include_directories() command")
message(STATUS "target_include_directories() command is used to add include directories to a target")
message(STATUS "target_include_directories() command has 2 types: PUBLIC, PRIVATE, INTERFACE")
message(STATUS "PUBLIC: include directories will be added to both target and targets that depend on this target")
message(STATUS "PRIVATE: include directories will be added to only target")
message(STATUS "INTERFACE: include directories will be added to only targets that depend on this target")
target_include_directories(UTILS PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/include
)
message(STATUS "")

message(STATUS "Example 5: add_executable() command")

message(STATUS "add_executable() command is used to create an executable target")

add_executable(PRINTING_MESSAGE
    src/printing_message.cpp
)
message(STATUS "")

message(STATUS "Example 6: target_link_libraries() command")

message(STATUS "target_link_libraries() command is used to link libraries to a target")
message(STATUS "target_link_libraries() command has 3 types: PUBLIC, PRIVATE, INTERFACE")
message(STATUS "PUBLIC: libraries will be linked to both target and targets that depend on this target")
message(STATUS "PRIVATE: libraries will be linked to only target")
message(STATUS "INTERFACE: libraries will be linked to only targets that depend on this target")

target_link_libraries(PRINTING_MESSAGE PRIVATE
    UTILS
)
message(STATUS "")

message(STATUS "Example 7: target_compile_options() command")

message(STATUS "target_compile_options() command is used to add compile options to a target")
message(STATUS "target_compile_options() command has 3 types: PUBLIC, PRIVATE, INTERFACE")
message(STATUS "PUBLIC: compile options will be added to both target and targets that depend on this target")
message(STATUS "PRIVATE: compile options will be added to only target")
message(STATUS "INTERFACE: compile options will be added to only targets that depend on this target")

target_compile_options(UTILS PRIVATE
    -Wall
    -Wextra
    -Werror
)
target_compile_options(PRINTING_MESSAGE PRIVATE
    -Wall
    -Wextra
    -Werror
)
message(STATUS "")

message(STATUS "Example 8: add_dependencies() command")

message(STATUS "add_dependencies() command is used to add dependencies to a target")
message(STATUS "This command ensures that the specified target is built before other targets")
add_dependencies(PRINTING_MESSAGE
    UTILS
)
message(STATUS "")

message(STATUS "")
message(STATUS "Finished all process in ${PROJECT_NAME} CMakeLists.txt.")
message(STATUS "")
