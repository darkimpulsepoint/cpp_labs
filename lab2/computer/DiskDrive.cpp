#include <stdexcept>
#include <iostream>
#include <string>
#include "DiskDrive.h"

DiskDrive::DiskDrive(int id, int slots): Component(id) {
    this->setNumberOfSlots(slots);
}

void DiskDrive::setNumberOfSlots(int slots) {
    if (slots < 0) throw std::invalid_argument("Slots count must be > 0");
    this->numberOfSlots = slots;
}

std::string DiskDrive::toString() const {
    return "DiskDrive: slots: "+ std::to_string(getNumberOfSlots());
}

int DiskDrive::getNumberOfSlots() const {
    return this->numberOfSlots;
}