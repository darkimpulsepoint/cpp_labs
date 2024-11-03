project(trains)

set(HEADER_FILES
        Wagon.h
        PassengerWagon.h
        Train.h
        TrainService.h
)

set(SOURCE_FILES
        Wagon.cpp
        PassengerWagon.cpp
        Train.cpp
        TrainService.cpp
)

add_library(trains STATIC ${SOURCE_FILES} ${HEADER_FILES})