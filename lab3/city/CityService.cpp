#include "CityService.h"

std::vector<City> CityService::findCitiesWithAvenue(std::vector<City> cities) {
    std::vector<City> result;
    for (const auto& city : cities) {
        for (const auto& location : city.getLocations()) {
            if (location.toString().find("Avenue") != std::string::npos) {
                result.push_back(city);
                break;
            }
        }
    }
    return result;
}

City* CityService::findCityWithLocation(std::vector<City> cities, const std::string& locationName) {
    for (auto& city : cities) {
        for (const auto& location : city.getLocations()) {
            if (location.toString().find(locationName) != std::string::npos) {
                return &city;
            }
        }
    }
    return nullptr;
}

std::vector<City> CityService::findCitiesWithAllTypes(std::vector<City> cities) {
    std::vector<City> result;
    for (const auto& city : cities) {
        bool hasStreet = false;
        bool hasAvenue = false;
        bool hasSquare = false;

        for (const auto& location : city.getLocations()) {
            if (location.toString().find("Street") != std::string::npos) {
                hasStreet = true;
            }
            if (location.toString().find("Avenue") != std::string::npos) {
                hasAvenue = true;
            }
            if (location.toString().find("Square") != std::string::npos) {
                hasSquare = true;
            }
        }

        if (hasStreet && hasAvenue && hasSquare) {
            result.push_back(city);
        }
    }
    return result;
}