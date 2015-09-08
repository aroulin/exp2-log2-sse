cmake_minimum_required(VERSION 3.3)
project(exp2_log2_sse)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp rdtsc.h)
add_executable(exp2_log2_sse ${SOURCE_FILES})