cmake_minimum_required(VERSION 3.22)

project(
    leetcode
    LANGUAGES CXX
)

# use C++20 and make sure that compiler supports it
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_compile_options(
    -Werror
    -Wall 
    -Wextra 
    -pedantic 
    -Wshadow
    -Wnon-virtual-dtor
    -Wold-style-cast
    -Wcast-align
    -Wunused
    -Woverloaded-virtual
    -Wpedantic
    -Wconversion
    -Wsign-conversion
    -Wmisleading-indentation
    -Wnull-dereference
    -Wdouble-promotion
    -Wformat=2
    -Wimplicit-fallthrough
    # -fno-vectorize
    # -march=core2
    # -g
    # -march=znver3
)

add_executable(matrix main.cpp obfuscate.cpp)
