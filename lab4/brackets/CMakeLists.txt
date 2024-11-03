project(brackets)


set(HEADER_FILES
        BracketsService.h
)


add_library(brackets STATIC ${HEADER_FILES})
set_target_properties(brackets PROPERTIES LINKER_LANGUAGE CXX)