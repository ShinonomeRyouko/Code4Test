cmake_minimum_required(VERSION 3.14 FATAL_ERROR)
project(Code4Test)

# GoogleTest requires at least C++14
set(CMAKE_CXX_STANDARD 14)

set (COMMON_HEADER_TXT "CommonHeader.txt")
set (SOLUTION_NAME_TXT "SolutionNames.txt")

# The common header file names.
file (STRINGS ${COMMON_HEADER_TXT} COMMON_HEADER_STR)
# Not too many header files, so it's okay to link them to every test file.
string(REPLACE " " ";" HEADER_NAMES ${COMMON_HEADER_STR})

# The file name prefix(class name) should be same 
# in all three folder(include, src, test).
# Modify SolutionNames.txt to add more solutions.
file (STRINGS ${SOLUTION_NAME_TXT} SOLUTION_NAME_STR)
string(REPLACE " " ";" SOLUTION_NAMES ${SOLUTION_NAME_STR})

# Split it to get string list.
string(REPLACE " " ";" CLASS_NAMES "${COMMON_HEADER_STR} ${SOLUTION_NAME_STR}")

find_package(Python3 REQUIRED COMPONENTS Interpreter)
execute_process(COMMAND ${Python3_EXECUTABLE} ${PROJECT_SOURCE_DIR}/gen.py 
                ${COMMON_HEADER_TXT} ${SOLUTION_NAME_TXT} ${PROJECT_SOURCE_DIR})

include_directories(include)
add_subdirectory(src)
add_subdirectory(test)