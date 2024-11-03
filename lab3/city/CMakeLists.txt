project(city)

set(HEADER_FILES
    City.h
    CityService.h
)

set(SOURCE_FILES
        City.cpp
        CityService.cpp
)

add_library(city STATIC ${SOURCE_FILES} ${HEADER_FILES})