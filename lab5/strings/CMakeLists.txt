project(strings)

set(HEADER_FILES
        FileReader.h
        StringService.h
)

set(SOURCE_FILES
        FileReader.cpp
        StringService.cpp
)

add_library(strings STATIC ${SOURCE_FILES} ${HEADER_FILES})