#pragma once
#include "Train.h"

class TrainService {
public:
    static int getTotalPassengers(Train& train);
    static void sortWagonsByComfort(Train& train);
    static std::vector<Wagon*> findWagonsWithPassengersInRange(Train& train, int min, int max);
};