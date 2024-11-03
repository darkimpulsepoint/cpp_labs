cmake_minimum_required(VERSION 3.27)
project(lab2)

set(CMAKE_CXX_STANDARD 17)

add_executable(lab2 main.cpp
)

include_directories(computer)
add_subdirectory(computer)
target_link_libraries(lab2 computer)

include_directories(trains)
add_subdirectory(trains)
target_link_libraries(lab2 trains)

add_subdirectory(Google_tests)