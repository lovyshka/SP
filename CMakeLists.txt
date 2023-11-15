cmake_minimum_required(VERSION 3.24)
project(SP C)

set(CMAKE_C_STANDARD 11)

include_directories(src)

add_executable(SP
        src/hello.h
        src/func.c)
