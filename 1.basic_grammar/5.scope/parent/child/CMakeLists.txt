message(STATUS "Example 1 - Local scope variable")
message(STATUS "Local scope variable in top_level/parent/child/CMakeLists.txt")
message(STATUS "set(LOCAL_VARIABLE_NAME value)")
set(CHILD_STRING_VARIABLE "child")
message(STATUS "CHILD_STRING_VARIABLE only can read in top_level/parent/child/CMakeLists.txt")

message(STATUS "")

message(STATUS "Example 2 - Parent scope variable")
message(STATUS "Parent scope variable in top_level/parent/child/CMakeLists.txt")
message(STATUS "set(PARENT_STRING_VARIABLE value PARENT_SCOPE)")
set(PARENT_STRING_VARIABLE "parent" PARENT_SCOPE)
message(STATUS "PARENT_STRING_VARIABLE can read in top_level/parent/CMakeLists.txt")

message(STATUS "")

message(STATUS "Example 3 - Global scope variable")
message(STATUS "Global scope variable in top_level/parent/child/CMakeLists.txt")
message(STATUS "set(GLOBAL_STRING_VARIABLE value CACHE <TYPE> \"Description for the variable\")")
set(GLOBAL_STRING_VARIABLE "global" CACHE STRING "a simple description for GLOBAL_STRING_VARIABLE")
message(STATUS "CACHE: set the variable in the cache")
message(STATUS "<TYPE>: the type of the variable (BOOL, FILEPATH, PATH, STRING, INTERNAL, or UNINITIALIZED)")
message(STATUS "- BOOL: ON/OFF, TRUE/FALSE, YES/NO, 1/0")
message(STATUS "- FILEPATH: absolute path to a file")
message(STATUS "- PATH: absolute path to a directory")
message(STATUS "- STRING: any string")
message(STATUS "- INTERNAL: not shown in the CMake GUI")
message(STATUS "- UNINITIALIZED: not initialized (set)")
message(STATUS "GLOBAL_STRING_VARIABLE can read in any CMakeLists.txt")
message(STATUS "")

message(STATUS "On child:")
message(STATUS "CHILD_STRING_VARIABLE: ${CHILD_STRING_VARIABLE}")
message(STATUS "PARENT_STRING_VARIABLE: ${PARENT_STRING_VARIABLE}")
message(STATUS "GLOBAL_STRING_VARIABLE: ${GLOBAL_STRING_VARIABLE}")
message(STATUS "")
