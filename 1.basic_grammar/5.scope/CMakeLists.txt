cmake_minimum_required(VERSION 3.11)
project(5.SCOPE)

message(STATUS "")
message(STATUS "Started all process in ${PROJECT_NAME} CMakeLists.txt.")
message(STATUS "")

add_subdirectory(parent)
message(STATUS "On top-level:")
message(STATUS "CHILD_STRING_VARIABLE: ${CHILD_STRING_VARIABLE}")
message(STATUS "PARENT_STRING_VARIABLE: ${PARENT_STRING_VARIABLE}")
message(STATUS "GLOBAL_STRING_VARIABLE: ${GLOBAL_STRING_VARIABLE}")
message(STATUS "")

message(STATUS "")
message(STATUS "Finished all process in ${PROJECT_NAME} CMakeLists.txt.")
message(STATUS "")
