project(Google_tests)

add_subdirectory(lib)
include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})


if(NOT TARGET spdlog)
    find_package(spdlog REQUIRED)
endif()

add_executable(Google_tests_run listsTests.cpp bracketsTests.cpp)

target_link_libraries(
        Google_tests_run
        PUBLIC lists gtest gtest_main
        PRIVATE spdlog::spdlog $<$<BOOL:${MINGW}>:ws2_32>
)
