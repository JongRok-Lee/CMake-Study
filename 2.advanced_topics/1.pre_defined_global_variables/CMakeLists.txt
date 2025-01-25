# Basic configurations
cmake_minimum_required(VERSION 3.11) # Minimum CMake version required
project(1.PRE_DEFINDED_GLOBAL_VARIABLES) # Required for CMake to know what project this is

message(STATUS "")
message(STATUS "Started all process in ${PROJECT_NAME} CMakeLists.txt.")
message(STATUS "")

message(STATUS "Example 1: Global variables for platform")
message(STATUS "")

message(STATUS "CMake variables for target system, that is, the system on which the generated build system will run.")
message(STATUS "")

message(STATUS "CMAKE_SYSTEM_NAME : {OS_MAME} - Darwin(MacOS), Linux, Windows")
message(STATUS "CMAKE_SYSTEM_NAME: ${CMAKE_SYSTEM_NAME}")
message(STATUS "")

message(STATUS "CMAKE_SYSTEM_VERSION : {OS_VERSION}")
message(STATUS "CMAKE_SYSTEM_VERSION: ${CMAKE_SYSTEM_VERSION}")
message(STATUS "")

message(STATUS "CMAKE_SYSTEM : {OS_MAME}-{OS_VERSION}")
message(STATUS "CMAKE_SYSTEM: ${CMAKE_SYSTEM}")
message(STATUS "")

message(STATUS "CMAKE_SYSTEM_PROCESSOR : {CPU_ARCHITECTURE} - x86_64, x86, arm64, etc...")
message(STATUS "CMAKE_SYSTEM_PROCESSOR: ${CMAKE_SYSTEM_PROCESSOR}")
message(STATUS "")

message(STATUS "CMake variables for host system, that is, the system on which CMake is being run.")
message(STATUS "")

message(STATUS "CMAKE_HOST_SYSTEM_NAME : {OS_MAME} - Darwin(MacOS), Linux, Windows")
message(STATUS "CMAKE_HOST_SYSTEM_NAME: ${CMAKE_HOST_SYSTEM_NAME}")
message(STATUS "")

message(STATUS "CMAKE_HOST_SYSTEM_VERSION : {OS_VERSION}")
message(STATUS "CMAKE_HOST_SYSTEM_VERSION: ${CMAKE_HOST_SYSTEM_VERSION}")
message(STATUS "")

message(STATUS "CMAKE_HOST_SYSTEM : {OS_MAME}-{OS_VERSION}")
message(STATUS "CMAKE_HOST_SYSTEM: ${CMAKE_HOST_SYSTEM}")
message(STATUS "")

message(STATUS "CMAKE_HOST_SYSTEM_PROCESSOR : {CPU_ARCHITECTURE} - x86_64, x86, arm64, etc...")
message(STATUS "CMAKE_HOST_SYSTEM_PROCESSOR: ${CMAKE_HOST_SYSTEM_PROCESSOR}")
message(STATUS "")

message(STATUS "Example 2: Global variables for compiler")
message(STATUS "")

message(STATUS "CMAKE_C_COMPILER : {ABSOLUTE_PATH_TO_C_COMPILER}")
message(STATUS "CMAKE_C_COMPILER_ID : {C_COMPILER_ID} - AppleClang, Clang, GNU, MSVC, etc...")
message(STATUS "CMAKE_C_COMPILER_VERSION : {C_COMPILER_VERSION}")
message(STATUS "CMAKE_C_COMPILER: ${CMAKE_C_COMPILER}")
message(STATUS "CMAKE_C_COMPILER_ID: ${CMAKE_C_COMPILER_ID}")
message(STATUS "CMAKE_C_COMPILER_VERSION: ${CMAKE_C_COMPILER_VERSION}")
message(STATUS "")

message(STATUS "CMAKE_CXX_COMPILER : {ABSOLUTE_PATH_TO_CPP_COMPILER}")
message(STATUS "CMAKE_CXX_COMPILER_ID : {CPP_COMPILER_ID} - AppleClang, Clang, GNU, MSVC, etc...")
message(STATUS "CMAKE_CXX_COMPILER_VERSION : {CPP_COMPILER_VERSION}")
message(STATUS "CMAKE_CXX_COMPILER: ${CMAKE_CXX_COMPILER}")
message(STATUS "CMAKE_CXX_COMPILER_ID: ${CMAKE_CXX_COMPILER_ID}")
message(STATUS "CMAKE_CXX_COMPILER_VERSION: ${CMAKE_CXX_COMPILER_VERSION}")
message(STATUS "")

find_package(CUDAToolkit QUIET)
if (CUDAToolkit_FOUND)
    message(STATUS "CMAKE_CUDA_COMPILER : {ABSOLUTE_PATH_TO_CUDA_COMPILER}")
    message(STATUS "CUDAToolkit_VERSION : {CUDA_VERSION}")
    message(STATUS "CMAKE_CUDA_COMPILER: ${CMAKE_CUDA_COMPILER}")
    message(STATUS "CUDAToolkit_VERSION: ${CUDAToolkit_VERSION}")
    message(STATUS "")
endif()

message(STATUS "Example 3: Global variables for build")
message(STATUS "")

message(STATUS "CMAKE_BUILD_TYPE : {BUILD_TYPE} - Debug, Release, RelWithDebInfo, MinSizeRel")
message(STATUS "CMAKE_BUILD_TYPE: ${CMAKE_BUILD_TYPE}")
message(STATUS "")

message(STATUS "CMAKE_CXX_COMPILE_FEATURES : {COMPILE_FEATURES} - cxx_std_11, cxx_std_14, cxx_std_17, cxx_std_20, cxx_std_23")
message(STATUS "CMAKE_CXX_COMPILE_FEATURES: ${CMAKE_CXX_COMPILE_FEATURES}")
message(STATUS "")

message(STATUS "Example 4: Global variables for project")
message(STATUS "CMAKE_PROJECT_NAME : {PROJECT_NAME}")
message(STATUS "CMAKE_PROJECT_NAME: ${CMAKE_PROJECT_NAME}")
message(STATUS "")

message(STATUS "CMAKE_PROJECT_VERSION : {PROJECT_VERSION}")
message(STATUS "CMAKE_PROJECT_VERSION: ${CMAKE_PROJECT_VERSION}")
message(STATUS "")

message(STATUS "CMAKE_PROJECT_VERSION_MAJOR : {PROJECT_VERSION_MAJOR}")
message(STATUS "CMAKE_PROJECT_VERSION_MAJOR: ${CMAKE_PROJECT_VERSION_MAJOR}")
message(STATUS "CMAKE_PROJECT_VERSION_MINOR : {PROJECT_VERSION_MINOR}")
message(STATUS "CMAKE_PROJECT_VERSION_MINOR: ${CMAKE_PROJECT_VERSION_MINOR}")
message(STATUS "CMAKE_PROJECT_VERSION_PATCH : {PROJECT_VERSION_PATCH}")
message(STATUS "CMAKE_PROJECT_VERSION_PATCH: ${CMAKE_PROJECT_VERSION_PATCH}")
message(STATUS "CMAKE_PROJECT_VERSION_TWEAK : {PROJECT_VERSION_TWEAK}")
message(STATUS "CMAKE_PROJECT_VERSION_TWEAK: ${CMAKE_PROJECT_VERSION_TWEAK}")
message(STATUS "")

message(STATUS "CMAKE_PROJECT_DESCRIPTION : {PROJECT_DESCRIPTION}")
message(STATUS "CMAKE_PROJECT_DESCRIPTION: ${CMAKE_PROJECT_DESCRIPTION}")
message(STATUS "")


message(STATUS "CMAKE_PROJECT_HOMEPAGE_URL : {PROJECT_HOMEPAGE_URL}")
message(STATUS "CMAKE_PROJECT_HOMEPAGE_URL: ${CMAKE_PROJECT_HOMEPAGE_URL}")
message(STATUS "")

message(STATUS "")
message(STATUS "Finished all process in ${PROJECT_NAME} CMakeLists.txt.")
message(STATUS "")
