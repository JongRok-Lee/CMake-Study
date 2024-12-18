cmake_minimum_required(VERSION 3.11)
project(4.FUNCTION)

message(STATUS "")
message(STATUS "Started all process in ${PROJECT_NAME} CMakeLists.txt.")
message(STATUS "")

message(STATUS "Example 1: Declare a function.")
function(my_function)
    message(STATUS "This is my function.")
endfunction(my_function)
my_function()
message("")

message(STATUS "Example 2: Declare a function with arguments.")
function(my_function_with_args arg1 arg2)
    message(STATUS "This is my function with arguments: ${arg1} ${arg2}.")
endfunction(my_function_with_args)
my_function_with_args("Hello" "World")
message("")

message(STATUS "")
message(STATUS "Finished all process in ${PROJECT_NAME} CMakeLists.txt.")
message(STATUS "")
