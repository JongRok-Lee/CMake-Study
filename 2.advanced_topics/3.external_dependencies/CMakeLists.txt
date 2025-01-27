# Basic configurations
cmake_minimum_required(VERSION 3.11) # Minimum CMake version required
project(3.EXTERNAL_DEPENDENCIES) # Required for CMake to know what project this is

message(STATUS "")
message(STATUS "Started all process in ${PROJECT_NAME} CMakeLists.txt.")
message(STATUS "")

message(STATUS "Example 1: ExternalProject_Add")
message(STATUS "ExternalProject_Add is a CMake module that allows you to download and build as an external project.")
message(STATUS "Download and build in building phase")
message(STATUS "Include ExternalProject module")
include(ExternalProject)
message(STATUS "Add GTEST as an external project")
ExternalProject_Add(
GTEST
GIT_REPOSITORY "https://github.com/google/googletest.git"
GIT_TAG "release-1.12.1"
PREFIX ${CMAKE_BINARY_DIR}/GTEST-prefix
CMAKE_ARGS -DCMAKE_INSTALL_PREFIX=${CMAKE_SOURCE_DIR}/thirdparty/install/GTEST/${CMAKE_BUILD_TYPE} -DCMAKE_BUILD_TYPE=${CMAKE_BUILD_TYPE}
)
message(STATUS "")

message(STATUS "Example 2: find_package")
message(STATUS "find_package(<PackageName> [version] [EXACT] [QUIET] or [REQUIRED] [HINTS] PATH)")
message(STATUS "[version] : Specify the version of the package to find. If not specified, the version is not checked.")
message(STATUS "[EXACT] : If specified, the version of the package must match exactly the version specified in the find_package command.")
message(STATUS "[QUIET] : If specified, the find_package command will fail quietly if the package is not found.")
message(STATUS "[REQUIRED] : If specified, the find_package command will fail if the package is not found.")
message(STATUS "[HINTS] PATH : Specify the path in which to search for the package.")

message(STATUS "Find GTEST")
find_package(GTest REQUIRED HINTS ${CMAKE_BINARY_DIR}/thirdparty/install/GTEST/${CMAKE_BUILD_TYPE})
message(STATUS "GTEST found: ${GTest_FOUND}")

if(${GTest_FOUND})
    if(NOT GTEST_INCLUDE_DIRS)
        set(GTEST_INCLUDE_DIRS ${CMAKE_BINARY_DIR}/thirdparty/install/GTEST/${CMAKE_BUILD_TYPE}/include)
    endif()

    message(STATUS "GTEST include dir: ${GTEST_INCLUDE_DIRS}")

    if(NOT GTEST_LIBRARIES)
        set(GTEST_LIBRARIES GTest::gtest GTest::gtest_main)
    endif()

    message(STATUS "GTEST libraries: ${GTEST_LIBRARIES}")

    add_executable(ADD_TESTING src/add_testing.cpp)
    target_include_directories(ADD_TESTING
        PUBLIC
        ${GTEST_INCLUDE_DIRS}
    )
    target_link_libraries(ADD_TESTING
        PRIVATE
        ${GTEST_LIBRARIES}
    )
endif()
message(STATUS "")
message(STATUS "Finished all process in ${PROJECT_NAME} CMakeLists.txt.")
message(STATUS "")
