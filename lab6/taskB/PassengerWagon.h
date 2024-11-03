#pragma once

#include "Wagon.h"

class PassengerWagon : public Wagon {
private:
    double maxBaggageInKg;
    double currBaggageInKg;
    int comfortLvl;
    int currPassengers;

public:
    PassengerWagon(int id, double maxBaggage, double weight, int comfort, int passengers);

    double getMaxBaggageInKg() const;
    double getCurrBaggageInKg() const;
    void setCurrBaggageInKg(double baggage);

    int getComfortLvl() const;
    int getCurrPassengers() const;
    void setComfortLvl(int comfort);
    void setCurrPassengers(int passengers);

    std::string toString() const override;
    std::map<std::string, std::string> getFieldValues() const override;
};