project(Google_tests)

add_subdirectory(lib)
include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})


if(NOT TARGET spdlog)
    # Stand-alone build
    find_package(spdlog REQUIRED)
endif()

# ---------------------------------------------------------------------------------------
# Example of using pre-compiled library
# ---------------------------------------------------------------------------------------
add_executable(Google_tests_run stringServiceTests.cpp)

#target_link_libraries(Google_tests_run PRIVATE spdlog::spdlog $<$<BOOL:${MINGW}>:ws2_32>)

# ---------------------------------------------------------------------------------------
# Example of using header-only library
# ---------------------------------------------------------------------------------------

#include_directories(city)
#target_link_libraries(Google_Tests_run city)
target_link_libraries(
        Google_tests_run
        PUBLIC strings gtest gtest_main
        PRIVATE spdlog::spdlog $<$<BOOL:${MINGW}>:ws2_32>
)
