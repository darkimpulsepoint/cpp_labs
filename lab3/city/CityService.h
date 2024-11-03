#pragma once

#include "City.h"

class CityService {
public:
    static std::vector<City> findCitiesWithAvenue(std::vector<City> cities);
    static City* findCityWithLocation(std::vector<City> cities, const std::string& locationName);
    static std::vector<City> findCitiesWithAllTypes(std::vector<City> cities);
};