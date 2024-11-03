project(book)

set(HEADER_FILES
        book.h
        BookLibrary.h
)

set(SOURCE_FILES
        book.cpp
        BookLibrary.cpp
)

add_library(book STATIC ${SOURCE_FILES} ${HEADER_FILES})