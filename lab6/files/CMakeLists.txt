project(fileService)

find_package(spdlog REQUIRED)

set(HEADER_FILES
        FileReader.h
        FileWriter.h
        Zipper.h
)

set(SOURCE_FILES
        FileReader.cpp
        FileWriter.cpp
        Zipper.cpp
)

add_library(fileService STATIC ${SOURCE_FILES} ${HEADER_FILES})

find_package(QuaZip-Qt6)

target_link_libraries(
        fileService
        PUBLIC QuaZip::QuaZip
        PRIVATE spdlog::spdlog $<$<BOOL:${MINGW}>:ws2_32>
)