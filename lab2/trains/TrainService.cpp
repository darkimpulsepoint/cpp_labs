#include "TrainService.h"
#include <algorithm>
#include <iostream>
#include "PassengerWagon.h"

int TrainService::getTotalPassengers(Train& train) {
    int total = 0;
    for (auto& wagon : train.getWagons()) {
        if (PassengerWagon* passengerWagon = dynamic_cast<PassengerWagon*>(wagon)) {
            total += passengerWagon->getCurrPassengers();
        }
    }
    return total;
}

void TrainService::sortWagonsByComfort(Train& train) {
    std::sort(train.getWagons().begin(), train.getWagons().end(), [](Wagon* a, Wagon* b) {
        if (PassengerWagon* passengerA = dynamic_cast<PassengerWagon*>(a)) {
            if (PassengerWagon* passengerB = dynamic_cast<PassengerWagon*>(b)) {
                return passengerA->getComfortLvl() < passengerB->getComfortLvl();
            }
        }
        return false;
    });
}

std::vector<Wagon*> TrainService::findWagonsWithPassengersInRange(Train& train, int min, int max) {
    std::vector<Wagon*> result;
    for (auto& wagon : train.getWagons()) {
        if (PassengerWagon* passengerWagon = dynamic_cast<PassengerWagon*>(wagon)) {
            int capacity = passengerWagon->getCurrPassengers();
            if (capacity >= min && capacity <= max) {
                result.push_back(wagon);
            }
        }
    }
    return result;
}