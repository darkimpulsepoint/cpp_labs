project(taskB)

set(HEADER_FILES
        Wagon.h
        PassengerWagon.h
        Train.h
        TrainService.h
        Serializer.h
)

set(SOURCE_FILES
        Wagon.cpp
        PassengerWagon.cpp
        Train.cpp
        TrainService.cpp
        Serializer.cpp
)

if (NOT TARGET QuaZip::QuaZip)
    find_package(QuaZip-Qt6)
endif()

add_library(taskB STATIC ${SOURCE_FILES} ${HEADER_FILES})
target_link_libraries(taskB QuaZip::QuaZip)
