project(taskA)

if (NOT TARGET QuaZip::QuaZip)
    find_package(QuaZip-Qt6)
endif ()

set(HEADER_FILES
        StringService.h
)

set(SOURCE_FILES
        StringService.cpp
)

add_library(taskA STATIC ${SOURCE_FILES} ${HEADER_FILES})

target_link_libraries(
        taskA
        PUBLIC QuaZip::QuaZip
)