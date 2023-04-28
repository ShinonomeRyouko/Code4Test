cmake_minimum_required(VERSION 3.14 FATAL_ERROR)
project(Code4Test LANGUAGES CXX)

# GoogleTest requires at least C++14
set(CMAKE_CXX_STANDARD 14)
# Require (at least) it
set(CMAKE_CXX_STANDARD_REQUIRED ON)
# Don't use e.g. GNU extension (like -std=gnu++11) for portability
set(CMAKE_CXX_EXTENSIONS OFF)

option(SANITIZER_CHECK "Enable sanitizer check" OFF)

option(CODE_COVERAGE "Enable coverage report" OFF)

if ("${CMAKE_CXX_COMPILER_ID}" STREQUAL "GNU")
    SET(CMAKE_CXX_FLAGS  "${CMAKE_CXX_FLAGS} -Wall -Wextra -pedantic \
    -Wnon-virtual-dtor -Wshadow=local \
    -Wno-unused-variable -Wno-sign-compare \
    -Werror=return-type -Werror=uninitialized")
    if (SANITIZER_CHECK)
        SET(CMAKE_CXX_FLAGS  "${CMAKE_CXX_FLAGS} -fsanitize=address \
        -fno-omit-frame-pointer -fsanitize=leak -O0")
    endif()
    if (CODE_COVERAGE)
        # -g generate debug info.
        SET(CMAKE_CXX_FLAGS  "${CMAKE_CXX_FLAGS} -g --coverage")
        include(CheckCXXCompilerFlag)
        check_cxx_compiler_flag(-fprofile-abs-path HAVE_fprofile_abs_path)
        if(HAVE_fprofile_abs_path)
            set(CMAKE_CXX_FLAGS  "${CMAKE_CXX_FLAGS} -fprofile-abs-path")
        endif()
        check_cxx_compiler_flag(-fprofile-exclude-files HAVE_fprofile_exclude_files)
        if(HAVE_fprofile_exclude_files)
            set(CMAKE_CXX_FLAGS  "${CMAKE_CXX_FLAGS} --fprofile-exclude-files=test/*;/usr/*")
        endif()
    endif()
endif()

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