#pragma once
#include "Train.h"
#include <vector>

class TrainService {
public:
    static int getTotalPassengers_WriteAndZip(Train& train, const std::string filename);
    static void sortWagonsByComfort_WriteAndZip(Train& train, const std::string filename);
    static std::vector<Wagon*> findWagonsWithPassengersInRange_WriteAndZip(Train& train, int min, int max, const std::string filename);
    static void saveTrainToFileAndZip(Train& train, const std::string& filename);
};
