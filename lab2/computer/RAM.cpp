#include <stdexcept>
#include <iostream>
#include <string>
#include "RAM.h"

RAM::RAM(int id, double sizeInMBs): Component(id) {
    this->setMemorySizeInMBs(sizeInMBs);
}

void RAM::setMemorySizeInMBs(double MBs) {
    if (MBs <= 0) throw std::invalid_argument("Size count must be > 0");
    this->memorySizeInMBs = MBs;
}


std::string RAM::toString() const {
    return "RAM: size: "+ std::to_string(getMemorySizeInMBs()) + " MBs";
}

double RAM::getMemorySizeInMBs() const {
    return this->memorySizeInMBs;
}