#pragma once

#include <vector>
#include "Wagon.h"

class Train {
private:
    std::vector<Wagon*> wagons;

public:
    ~Train();
    void addWagon(Wagon* wagon);
    std::vector<Wagon*>& getWagons();
};