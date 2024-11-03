cmake_minimum_required(VERSION 3.29)
project(task1)

set(CMAKE_CXX_STANDARD 17)

set(SOURCE_FILES main.cpp)

add_executable(task1_run ${SOURCE_FILES})

include_directories(book)
add_subdirectory(book)
target_link_libraries(task1_run book)

include_directories(circle)
add_subdirectory(circle)
target_link_libraries(task1_run circle)

include_directories(fraction)
add_subdirectory(fraction)
target_link_libraries(task1_run fraction)

add_subdirectory(Google_tests)
add_subdirectory(Boost_tests)
add_subdirectory(Doctests)
