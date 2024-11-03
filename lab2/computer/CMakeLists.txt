project(computer)

set(HEADER_FILES
        CPU.h
        Component.h
        computer.h
        DiskDrive.h
        HardDrive.h
        RAM.h
        ComputerService.h
)

set(SOURCE_FILES
        CPU.cpp
        Component.cpp
        computer.cpp
        DiskDrive.cpp
        HardDrive.cpp
        RAM.cpp
        ComputerService.cpp
)

add_library(computer STATIC ${SOURCE_FILES} ${HEADER_FILES})