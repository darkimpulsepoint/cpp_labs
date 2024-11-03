#include "computer.h"
#include <iostream>

Computer::Computer(HardDrive *hd, DiskDrive *dd, RAM *r, CPU *c)
        : hardDrive{hd}, diskDrive{dd}, ram{r}, cpu{c} {}

void Computer::turnOn() {
    this->isTurned = true;
}

void Computer::turnOff() {
    this->isTurned = false;
}

bool Computer::isTurnedOn() {
    return this->isTurned;
}

bool Computer::checkIsVirused() {
    return false;
}

void Computer::displayHardDriveInfo() const {
    std::cout << hardDrive->toString() << std::endl;
}

HardDrive* Computer::getHardDrive() const {
    return hardDrive;
}

DiskDrive* Computer::getDiskDrive() const {
    return diskDrive;
}

RAM* Computer::getRAM() const {
    return ram;
}

CPU* Computer::getCPU() const {
    return cpu;
}
