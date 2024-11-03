#include <stdexcept>
#include <iostream>
#include <string>
#include "CPU.h"

CPU::CPU(int id, int coresCount): Component(id) {
    this->setCoresCount(coresCount);
}

void CPU::setCoresCount(int coresCount) {
    if (coresCount < 0) throw std::invalid_argument("Cores count must be > 0");
    this->coresCount = coresCount;
}


std::string CPU::toString() const {
    return "CPU: cores: "+ std::to_string(getCoresCount());
}

int CPU::getCoresCount() const {
    return this->coresCount;
}