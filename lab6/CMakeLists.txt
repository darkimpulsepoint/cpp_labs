cmake_minimum_required(VERSION 3.29)
project(lab6)

set(CMAKE_CXX_STANDARD 17)

add_executable(lab6 main.cpp)

include_directories(files)
add_subdirectory(files)
target_link_libraries(lab6 fileService)

include_directories(taskA)
add_subdirectory(taskA)
target_link_libraries(lab6 taskA)

include_directories(taskB)
add_subdirectory(taskB)
target_link_libraries(lab6 taskB)

include_directories(taskC)
add_subdirectory(taskC)
target_link_libraries(lab6 taskC)

include_directories(Google_tests)
add_subdirectory(Google_tests)
#target_link_libraries(lab6 taskC)