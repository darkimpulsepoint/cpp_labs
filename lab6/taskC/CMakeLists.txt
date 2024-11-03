project(taskC)

set(HEADER_FILES
        FileReverser.h
)

set(SOURCE_FILES
        FileReverser.cpp
)


if (NOT TARGET QuaZip::QuaZip)
    find_package(QuaZip-Qt6)
endif()

add_library(taskC STATIC ${SOURCE_FILES} ${HEADER_FILES})
target_link_libraries(taskC QuaZip::QuaZip)