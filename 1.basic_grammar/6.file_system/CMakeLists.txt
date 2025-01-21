cmake_minimum_required(VERSION 3.11)
project(6.FILE_SYSTEM)

message(STATUS "")
message(STATUS "Started all process in ${PROJECT_NAME} CMakeLists.txt.")
message(STATUS "")

message(STATUS "Example 1: variables for file system")
message(STATUS "Example 1.1: variables for file system - CMAKE_SOURCE_DIR")
message(STATUS "CMAKE_SOURCE_DIR: ${CMAKE_SOURCE_DIR}")
message(STATUS "")

message(STATUS "Example 1.2: variables for file system - CMAKE_CURRENT_SOURCE_DIR")
message(STATUS "CMAKE_CURRENT_SOURCE_DIR: ${CMAKE_CURRENT_SOURCE_DIR}")
message(STATUS "")

message(STATUS "Example 1.3: variables for file system - CMAKE_BINARY_DIR")
message(STATUS "CMAKE_BINARY_DIR: ${CMAKE_BINARY_DIR}")
message(STATUS "")

message(STATUS "Example 1.4: variables for file system - CMAKE_CURRENT_BINARY_DIR")
message(STATUS "CMAKE_CURRENT_BINARY_DIR: ${CMAKE_CURRENT_BINARY_DIR}")
message(STATUS "")

message(STATUS "Example 1.5: variables for file system - CMAKE_CURRENT_LIST_DIR")
message(STATUS "CMAKE_CURRENT_LIST_DIR: ${CMAKE_CURRENT_LIST_DIR}")
message(STATUS "")

message(STATUS "Example 1.6: variables for file system - include()")
message(STATUS "include(cmake/example.cmake)")
include(cmake/example.cmake)

message(STATUS "Example 2: file")
message(STATUS "Example 2.1: file - write")
file(WRITE ${CMAKE_CURRENT_SOURCE_DIR}/file.txt "Hello, World!\n")
message(STATUS "")

message(STATUS "Example 2.2: file - read")
file(READ ${CMAKE_CURRENT_SOURCE_DIR}/file.txt CONTENT)
message(STATUS "CONTENT: ${CONTENT}")
message(STATUS "")

message(STATUS "Example 2.3: file - remove")
file(REMOVE ${CMAKE_CURRENT_SOURCE_DIR}/file.txt)
message(STATUS "")

message(STATUS "Example 3: symlink")
message(STATUS "Example 3.1: symlink - create")
file(WRITE ${CMAKE_CURRENT_SOURCE_DIR}/file.txt "Hello, World!\n")
file(CREATE_LINK ${CMAKE_CURRENT_SOURCE_DIR}/file.txt ${CMAKE_CURRENT_SOURCE_DIR}/symlink.txt SYMBOLIC)
message(STATUS "")

message(STATUS "Example 3.2: symlink - read")
file(READ_SYMLINK ${CMAKE_CURRENT_SOURCE_DIR}/symlink.txt CONTENT)
message(STATUS "CONTENT: ${CONTENT}")
message(STATUS "")

message(STATUS "Example 3.3: symlink - remove")
file(REMOVE ${CMAKE_CURRENT_SOURCE_DIR}/symlink.txt)
file(REMOVE ${CMAKE_CURRENT_SOURCE_DIR}/file.txt)
message(STATUS "")

message(STATUS "Example 4: directory")
message(STATUS "Example 4.1: directory - create")
file(MAKE_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/directory)
message(STATUS "")

message(STATUS "Example 4.2: directory - remove")
file(REMOVE_RECURSE ${CMAKE_CURRENT_SOURCE_DIR}/directory)
message(STATUS "")

message(STATUS "Example 5: copy")
message(STATUS "Example 5.1: copy - file")
file(WRITE ${CMAKE_CURRENT_SOURCE_DIR}/file.txt "Hello, World!\n")
file(COPY ${CMAKE_CURRENT_SOURCE_DIR}/file.txt DESTINATION ${CMAKE_CURRENT_SOURCE_DIR}/copy_dir)

message(STATUS "")

message(STATUS "Example 5.2: copy - directory")
file(MAKE_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/directory)
file(WRITE ${CMAKE_CURRENT_SOURCE_DIR}/directory/file.txt "Hello, World!\n")
file(COPY ${CMAKE_CURRENT_SOURCE_DIR}/directory DESTINATION ${CMAKE_CURRENT_SOURCE_DIR}/destination)
message(STATUS "")

message(STATUS "Example 5.3: copy - remove")
file(REMOVE ${CMAKE_CURRENT_SOURCE_DIR}/file.txt)
file(REMOVE_RECURSE ${CMAKE_CURRENT_SOURCE_DIR}/directory)
file(REMOVE_RECURSE ${CMAKE_CURRENT_SOURCE_DIR}/copy_dir)
file(REMOVE_RECURSE ${CMAKE_CURRENT_SOURCE_DIR}/destination)
message(STATUS "")

message(STATUS "Example 6: glob")
message(STATUS "Example 6.1: glob - file")
file(WRITE ${CMAKE_CURRENT_SOURCE_DIR}/file1.txt "Hello, World!\n")
file(WRITE ${CMAKE_CURRENT_SOURCE_DIR}/file2.txt "Hello, World!\n")
file(WRITE ${CMAKE_CURRENT_SOURCE_DIR}/file3.txt "Hello, World!\n")
file(GLOB FILES ${CMAKE_CURRENT_SOURCE_DIR}/*.txt)
message(STATUS "FILES: ${FILES}")
message(STATUS "")

message(STATUS "Example 6.2: glob - directory")
file(MAKE_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/directory)
file(MAKE_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/directory/directory1)
file(MAKE_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/directory/directory2)
file(MAKE_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/directory/directory3)
file(GLOB DIRECTORIES ${CMAKE_CURRENT_SOURCE_DIR}/directory/*)
message(STATUS "DIRECTORIES: ${DIRECTORIES}")
message(STATUS "")

message(STATUS "Example 6.3: glob - remove")
file(REMOVE ${CMAKE_CURRENT_SOURCE_DIR}/file1.txt)
file(REMOVE ${CMAKE_CURRENT_SOURCE_DIR}/file2.txt)
file(REMOVE ${CMAKE_CURRENT_SOURCE_DIR}/file3.txt)
file(REMOVE_RECURSE ${CMAKE_CURRENT_SOURCE_DIR}/directory)
message(STATUS "")

message(STATUS "Example 7: rename")
message(STATUS "Example 7.1: rename - file")
file(WRITE ${CMAKE_CURRENT_SOURCE_DIR}/file.txt "Hello, World!\n")
file(RENAME ${CMAKE_CURRENT_SOURCE_DIR}/file.txt ${CMAKE_CURRENT_SOURCE_DIR}/rename.txt)
file(READ ${CMAKE_CURRENT_SOURCE_DIR}/rename.txt CONTENT)
message(STATUS "CONTENT: ${CONTENT}")
file(REMOVE ${CMAKE_CURRENT_SOURCE_DIR}/rename.txt)
message(STATUS "")

message(STATUS "Example 7.2: rename - directory")
file(MAKE_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/directory)
file(RENAME ${CMAKE_CURRENT_SOURCE_DIR}/directory ${CMAKE_CURRENT_SOURCE_DIR}/rename)
file(REMOVE_RECURSE ${CMAKE_CURRENT_SOURCE_DIR}/rename)
message(STATUS "")

message(STATUS "Example 8: type check")
file(WRITE ${CMAKE_CURRENT_SOURCE_DIR}/1.txt "Hello, World!\n")
file(WRITE ${CMAKE_CURRENT_SOURCE_DIR}/2.txt "Hello, World!\n")
file(MAKE_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/directory)
file(CREATE_LINK ${CMAKE_CURRENT_SOURCE_DIR}/2.txt ${CMAKE_CURRENT_SOURCE_DIR}/2_symlink.txt SYMBOLIC)
file(WRITE ${CMAKE_CURRENT_SOURCE_DIR}/3.txt "Hello, World!\n")
set(DATA_LIST
    ${CMAKE_CURRENT_SOURCE_DIR}/2.txt
    ${CMAKE_CURRENT_SOURCE_DIR}/directory
    ${CMAKE_CURRENT_SOURCE_DIR}/2_symlink.txt
    2.txt
    directory
    2_symlink.txt
)

message(STATUS "Example 8.1: type check - directory")
foreach(DATA ${DATA_LIST})
    if(IS_DIRECTORY ${DATA})
        message(STATUS "${DATA} is directory.")
    else()
        message(STATUS "${DATA} is not directory.")
    endif()
endforeach()
message(STATUS "")

message(STATUS "Example 8.2: type check - symlink")
foreach(DATA ${DATA_LIST})
    if(IS_SYMLINK ${DATA})
        message(STATUS "${DATA} is symbolic link.")
    else()
        message(STATUS "${DATA} is not symbolic link.")
    endif()
endforeach()
message(STATUS "")

message(STATUS "Example 8.3: type check - absolute path")
foreach(DATA ${DATA_LIST})
    if(IS_ABSOLUTE ${DATA})
        message(STATUS "${DATA} is absolute path.")
    else()
        message(STATUS "${DATA} is not absolute path.")
    endif()
endforeach()
message(STATUS "")

message(STATUS "Example 8.4: type check - remove")
file(REMOVE ${CMAKE_CURRENT_SOURCE_DIR}/1.txt)
file(REMOVE ${CMAKE_CURRENT_SOURCE_DIR}/2.txt)
file(REMOVE ${CMAKE_CURRENT_SOURCE_DIR}/3.txt)
file(REMOVE_RECURSE ${CMAKE_CURRENT_SOURCE_DIR}/directory)
file(REMOVE ${CMAKE_CURRENT_SOURCE_DIR}/2_symlink.txt)
message(STATUS "")

message(STATUS "")
message(STATUS "Finished all process in ${PROJECT_NAME} CMakeLists.txt.")
message(STATUS "")