#include "City.h"

#include <string>
#include <vector>

std::string locationTypeToString(LocationType locType) {
    switch (locType) {
        case LocationType::AVENUE: return "Avenue";
        case LocationType::SQUARE: return "Square";
        case LocationType::STREET: return "Street";
    }
}

City::City(std::string name, std::string country) {
    this->setName(name);
    this->setCountry(country);
}

City::Location::Location(const std::string& name, LocationType type)
            : name(name), type(type) {}

std::string City::Location::toString() const {
    return  "Name: " + name + ", Type: " + locationTypeToString(type);
}

void City::addLocation(const std::string& name, const LocationType type) {
        locations.push_back(Location(name, type));
    }

std::string City::toString() const {
    std::string str = "";
    str += "City name: " + name + "\n";
    for (const auto &location : locations)
    {
        str += location.toString() + "\n";
        return str;
    }
}

std::string City::getName() const {
    return name;
}

std::string City::getCountry() const {
    return country;
}

void City::setCountry(std::string country) {
    this->country = country;
}

void City::setName(std::string name) {
    this->name = name;
}

std::vector<City::Location> City::getLocations() const {
    return locations;
}




