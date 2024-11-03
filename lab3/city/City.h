#pragma once

#include <string>
#include <vector>

enum LocationType {
    STREET,
    AVENUE,
    SQUARE
};

class City {
public:
    class Location {
    public:
        Location(const std::string& name, LocationType type);

        std::string toString() const;

    private:
        std::string name;
        LocationType type;
    };

    City(std::string name, std::string country);

    void addLocation(const std::string& name, const LocationType type);

    void setName(std::string name);

    void setCountry(std::string country);

    std::string getName() const;

    std::string toString() const;

    std::string getCountry() const;

    std::vector<City::Location> getLocations() const;


private:
    std::vector<Location> locations;
    std::string name;
    std::string country;
};