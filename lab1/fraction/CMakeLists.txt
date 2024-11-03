project(fraction)

set(HEADER_FILES
        Fraction.h
        FractionService.h
)

set(SOURCE_FILES
        Fraction.cpp
        FractionService.cpp
)

add_library(fraction STATIC ${SOURCE_FILES} ${HEADER_FILES})