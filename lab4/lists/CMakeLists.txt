project(lists)

set(HEADER_FILES
        ListService.h
        ObjectInfo.h
        FileReader.h
)

set(SOURCE_FILES
        FileReader.cpp
        ObjectInfo.cpp
)

add_library(lists STATIC ${SOURCE_FILES} ${HEADER_FILES})