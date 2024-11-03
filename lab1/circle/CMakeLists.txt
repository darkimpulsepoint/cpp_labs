project(circle)

set(HEADER_FILES
        Circle.h
        CircleService.h
)

set(SOURCE_FILES
        Circle.cpp
        CircleService.cpp
)

add_library(circle STATIC ${SOURCE_FILES} ${HEADER_FILES})