#include "Wagon.h"
#include <sstream>

Wagon::Wagon(int id, double weight)
        : id(id), weight(weight) {}

Wagon::~Wagon() {}

int Wagon::getId() const {
    return id;
}

void Wagon::setId(int id) {
    if (id <= 0) throw std::invalid_argument("ID must be > 0");
    this->id = id;
}

double Wagon::getWeight() const {
    return weight;
}

void Wagon::setWeight(double weight) {
    if (weight <= 0) throw std::invalid_argument("Weight must be > 0");
    this->weight = weight;
}

std::string Wagon::toString() const {
    return "ID: " + std::to_string(getId())
        + ", Weight: " + std::to_string(getWeight()) + " kg";
}