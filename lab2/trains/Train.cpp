#include "Train.h"

Train::~Train() {
    for (auto wagon : wagons) {
        delete wagon;
    }
}

void Train::addWagon(Wagon* wagon) {
    wagons.push_back(wagon);
}

std::vector<Wagon*>& Train::getWagons() {
    return wagons;
}