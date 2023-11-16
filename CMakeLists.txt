cmake_minimum_required(VERSION 3.24)
project(SP C)

set(CMAKE_C_STANDARD 11)

include_directories(core_bits)

add_executable(SP
        hello.h
        func.c)
