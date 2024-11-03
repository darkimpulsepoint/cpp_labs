#include <stdexcept>
#include <iostream>
#include <string>
#include "HardDrive.h"

HardDrive::HardDrive(int id, double size): Component(id) {
    this->setSizeInGBs(size);
}

void HardDrive::setSizeInGBs(double GBs) {
    if (GBs <= 0) throw std::invalid_argument("Size count must be > 0");
    this->sizeInGBs = GBs;
}

std::string HardDrive::toString() const {
    return "HardDrive: size: "+ std::to_string(getSizeInGBs()) + " GBs";
}

double HardDrive::getSizeInGBs() const {
    return this->sizeInGBs;
}