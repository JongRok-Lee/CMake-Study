# Basic configurations
cmake_minimum_required(VERSION 3.11) # Minimum CMake version required
project(4.AUTOMATION) # Required for CMake to know what project this is

message(STATUS "")
message(STATUS "Started all process in ${PROJECT_NAME} CMakeLists.txt.")
message(STATUS "")

message(STATUS "Example: External scripts")
message(STATUS "This example shows how to use external scripts in CMake.")

message(STATUS "")
message(STATUS "execute_process(
COMMAND <command1> [args1...]
[COMMAND <command2> [args2...] ...]
[WORKING_DIRECTORY <directory>]
[RESULT_VARIABLE <variable>]
[OUTPUT_VARIABLE <variable>])")
message(STATUS "")
message(STATUS "COMMAND <command1> [args1...]: The command to execute.")
message(STATUS "WORKING_DIRECTORY <directory>: The directory in which to run the command.")
message(STATUS "RESULT_VARIABLE <variable>: If specified the variable will be set to the result code of the command.")
message(STATUS "OUTPUT_VARIABLE <variable>: If specified the variable will be set to the output of the command.")
message(STATUS "")

execute_process(
    COMMAND chmod +x external_script.sh
    COMMAND sh external_script.sh
    WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/scripts
    RESULT_VARIABLE RESULT_CODE
    OUTPUT_VARIABLE OUTPUT_RESULT
)

if(${RESULT_CODE} EQUAL 0)
    message(STATUS "Output: ${OUTPUT_RESULT}")
else()
    message(STATUS "Error code: ${RESULT_CODE}")
endif()

message(STATUS "")
message(STATUS "Finished all process in ${PROJECT_NAME} CMakeLists.txt.")
message(STATUS "")
