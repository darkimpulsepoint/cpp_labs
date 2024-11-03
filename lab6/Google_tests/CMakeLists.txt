project(Google_tests)

find_package(spdlog REQUIRED)
#find_package(QuaZip-Qt6)

add_subdirectory(lib)
include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})


add_executable(Google_Tests_run
        taskC_tests.cpp
        taskA_tests.cpp
        taskB_tests.cpp
        file_tests.cpp
)

#target_link_libraries(Google_Tests_run fileService)
#target_link_libraries(Google_Tests_run taskA)
#target_link_libraries(Google_Tests_run taskB)
#target_link_libraries(Google_Tests_run taskC)
#target_link_libraries(Google_Tests_run gtest gtest_main)
target_link_libraries(
        Google_Tests_run
        PUBLIC gtest gtest_main taskA taskB taskC fileService
        PRIVATE spdlog::spdlog $<$<BOOL:${MINGW}>:ws2_32>
)

