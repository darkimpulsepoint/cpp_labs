cmake_minimum_required(VERSION 3.29)
project(lab4)

set(CMAKE_CXX_STANDARD 17)

add_subdirectory(brackets)
include_directories(brackets)

add_subdirectory(lists)
include_directories(lists)

add_executable(lab4 main.cpp)
target_link_libraries(lab4 lists)

add_subdirectory(Google_tests)
