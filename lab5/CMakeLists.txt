cmake_minimum_required(VERSION 3.29)
project(lab5)

set(CMAKE_CXX_STANDARD 17)

include_directories(strings)
add_subdirectory(strings)

add_executable(lab5 main.cpp)

add_subdirectory(Google_tests)
