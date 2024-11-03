project(Google_tests)

add_subdirectory(lib)
include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})


add_executable(Google_Tests_run
        trainTests.cpp
        computerTests.cpp
)

target_link_libraries(Google_Tests_run trains)
target_link_libraries(Google_Tests_run computer)
target_link_libraries(Google_Tests_run gtest gtest_main)
