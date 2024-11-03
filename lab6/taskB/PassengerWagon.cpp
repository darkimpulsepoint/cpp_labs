#include "PassengerWagon.h"
#include <sstream>

PassengerWagon::PassengerWagon(int id, double maxBaggage, double weight, int comfort, int passengers)
        : Wagon(id, weight), maxBaggageInKg(maxBaggage), currBaggageInKg(0), comfortLvl(comfort), currPassengers(passengers) {}

double PassengerWagon::getMaxBaggageInKg() const {
    return maxBaggageInKg;
}

double PassengerWagon::getCurrBaggageInKg() const {
    return currBaggageInKg;
}

void PassengerWagon::setCurrBaggageInKg(double baggage) {
    if (baggage <= maxBaggageInKg) {
        currBaggageInKg = baggage;
    } else throw std::invalid_argument("Curr baggage must be <= max baggage");

    if (baggage < 0) throw std::invalid_argument("Baggage must be positive");
}

int PassengerWagon::getComfortLvl() const {
    return comfortLvl;
}

int PassengerWagon::getCurrPassengers() const {
    return currPassengers;
}

void PassengerWagon::setComfortLvl(int comfort) {
    comfortLvl = comfort;
}

void PassengerWagon::setCurrPassengers(int passengers) {
    if (passengers < 0) throw std::invalid_argument("Passengers can't be < 0");
    currPassengers = passengers;
}

std::string PassengerWagon::toString() const {
    return Wagon::toString()
        + ", Max baggage: " + std::to_string(getMaxBaggageInKg()) + " kg"
        + ", Curr baggage: " + std::to_string(getCurrBaggageInKg()) + " kg"
        + ", Comfort lvl: " + std::to_string(getComfortLvl())
        + ", Current passengers: " + std::to_string(getCurrPassengers());
}

std::map<std::string, std::string> PassengerWagon::getFieldValues() const {
    return {
            {"objectType", "PassengerWagon"},
            {"ID", std::to_string(getId())},
            {"MaxBaggage", std::to_string(getMaxBaggageInKg())},
            {"CurrBaggage", std::to_string(getCurrBaggageInKg())},
            {"ComfortLevel", std::to_string(getComfortLvl())},
            {"CurrPassengers", std::to_string(getCurrPassengers())},
            {"Weight", std::to_string(getWeight())},
    };
}