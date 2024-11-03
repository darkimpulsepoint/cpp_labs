cmake_minimum_required(VERSION 3.11)
project(lab3 CXX)

if(NOT TARGET spdlog)
    # Stand-alone build
    find_package(spdlog REQUIRED)
endif()

# ---------------------------------------------------------------------------------------
# Example of using pre-compiled library
# ---------------------------------------------------------------------------------------
add_executable(lab3 main.cpp)

include_directories(city)
add_subdirectory(city)
target_link_libraries(lab3 PUBLIC city PRIVATE spdlog::spdlog $<$<BOOL:${MINGW}>:ws2_32>)

# ---------------------------------------------------------------------------------------
# Example of using header-only library
# ---------------------------------------------------------------------------------------
if(SPDLOG_BUILD_EXAMPLE_HO)
    add_executable(example_header_only main.cpp)
    target_link_libraries(example_header_only PRIVATE spdlog::spdlog_header_only)
endif()


#target_link_librar(lab3 city)

add_subdirectory(Google_tests)
#target_link_libraries(lab3 city)