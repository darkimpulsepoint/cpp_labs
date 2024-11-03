#include <gtest/gtest.h>
#include <spdlog/spdlog.h>
#include <chrono>
#include "City.h"
#include "CityService.h"

TEST(CityServiceTest, FindCitiesWithAvenue_ValidCities) {
    std::vector<City> cities;
    City city1("New York", "USA");
    city1.addLocation("5th Avenue", AVENUE);
    city1.addLocation("Central Park", SQUARE);

    City city2("Paris", "France");
    city2.addLocation("Champs-Élysées", AVENUE);
    city2.addLocation("Place de la Concorde", SQUARE);

    City city3("Tokyo", "Japan");
    city3.addLocation("Harajuku Street", STREET);

    cities.push_back(city1);
    cities.push_back(city2);
    cities.push_back(city3);

    auto start = std::chrono::high_resolution_clock::now();
    auto result = CityService::findCitiesWithAvenue(cities);
    auto end = std::chrono::high_resolution_clock::now();

    std::chrono::duration<double, std::milli> elapsed = end - start;
    spdlog::info("FindCitiesWithAvenue_ValidCities took {} ms", elapsed.count());

    EXPECT_EQ(result.size(), 2);
    EXPECT_EQ(result[0].getName(), "New York");
    EXPECT_EQ(result[1].getName(), "Paris");
}

TEST(CityServiceTest, FindCitiesWithAvenue_NoAvenue) {
    std::vector<City> cities;
    City city1("Tokyo", "Japan");
    city1.addLocation("Harajuku Street", STREET);

    cities.push_back(city1);

    auto start = std::chrono::high_resolution_clock::now();
    auto result = CityService::findCitiesWithAvenue(cities);
    auto end = std::chrono::high_resolution_clock::now();

    std::chrono::duration<double, std::milli> elapsed = end - start;
    spdlog::info("FindCitiesWithAvenue_NoAvenue took {} ms", elapsed.count());

    EXPECT_TRUE(result.empty());
}

TEST(CityServiceTest, FindCitiesWithAvenue_EmptyList) {
    std::vector<City> cities;

    auto start = std::chrono::high_resolution_clock::now();
    auto result = CityService::findCitiesWithAvenue(cities);
    auto end = std::chrono::high_resolution_clock::now();

    std::chrono::duration<double, std::milli> elapsed = end - start;
    spdlog::info("FindCitiesWithAvenue_EmptyList took {} ms", elapsed.count());

    EXPECT_TRUE(result.empty());
}

TEST(CityServiceTest, FindCityWithLocation_ValidLocation) {
    std::vector<City> cities;
    City city1("New York", "USA");
    city1.addLocation("5th Avenue", AVENUE);
    city1.addLocation("Central Park", SQUARE);

    cities.push_back(city1);

    auto start = std::chrono::high_resolution_clock::now();
    City* foundCity = CityService::findCityWithLocation(cities, "5th Avenue");
    auto end = std::chrono::high_resolution_clock::now();

    std::chrono::duration<double, std::milli> elapsed = end - start;
    spdlog::info("FindCityWithLocation_ValidLocation took {} ms", elapsed.count());

    EXPECT_NE(foundCity, nullptr);
    EXPECT_EQ(foundCity->getName(), "New York");
}

TEST(CityServiceTest, FindCityWithLocation_InvalidLocation) {
    std::vector<City> cities;
    City city1("Paris", "France");
    city1.addLocation("Champs-Élysées", AVENUE);

    cities.push_back(city1);

    auto start = std::chrono::high_resolution_clock::now();
    City* foundCity = CityService::findCityWithLocation(cities, "Nonexistent Location");
    auto end = std::chrono::high_resolution_clock::now();

    std::chrono::duration<double, std::milli> elapsed = end - start;
    spdlog::info("FindCityWithLocation_InvalidLocation took {} ms", elapsed.count());

    EXPECT_EQ(foundCity, nullptr);
}

TEST(CityServiceTest, FindCityWithLocation_EmptyList) {
    std::vector<City> cities;

    auto start = std::chrono::high_resolution_clock::now();
    City* foundCity = CityService::findCityWithLocation(cities, "Any Location");
    auto end = std::chrono::high_resolution_clock::now();

    std::chrono::duration<double, std::milli> elapsed = end - start;
    spdlog::info("FindCityWithLocation_EmptyList took {} ms", elapsed.count());

    EXPECT_EQ(foundCity, nullptr);
}

TEST(CityServiceTest, FindCitiesWithAllTypes_ValidCities) {
    std::vector<City> cities;
    City city1("New York", "USA");
    city1.addLocation("5th Avenue", AVENUE);
    city1.addLocation("Central Park", SQUARE);
    city1.addLocation("Broadway", STREET);

    City city2("Paris", "France");
    city2.addLocation("Champs-Élysées", AVENUE);
    city2.addLocation("Place de la Concorde", SQUARE);
    city2.addLocation("Rue de Rivoli", STREET);

    cities.push_back(city1);
    cities.push_back(city2);

    auto start = std::chrono::high_resolution_clock::now();
    auto result = CityService::findCitiesWithAllTypes(cities);
    auto end = std::chrono::high_resolution_clock::now();

    std::chrono::duration<double, std::milli> elapsed = end - start;
    spdlog::info("FindCitiesWithAllTypes_ValidCities took {} ms", elapsed.count());

    ASSERT_EQ(result.size(), 2);
    EXPECT_EQ(result[0].getName(), "New York");
    EXPECT_EQ(result[1].getName(), "Paris");
}

TEST(CityServiceTest, FindCitiesWithAllTypes_MissingTypes) {
    std::vector<City> cities;
    City city1("Tokyo", "Japan");
    city1.addLocation("Harajuku Street", STREET);
    city1.addLocation("Shibuya Crossing", SQUARE);

    cities.push_back(city1);

    auto start = std::chrono::high_resolution_clock::now();
    auto result = CityService::findCitiesWithAllTypes(cities);
    auto end = std::chrono::high_resolution_clock::now();

    std::chrono::duration<double, std::milli> elapsed = end - start;
    spdlog::info("FindCitiesWithAllTypes_MissingTypes took {} ms", elapsed.count());

    EXPECT_TRUE(result.empty());
}

TEST(CityServiceTest, FindCitiesWithAllTypes_EmptyList) {
    std::vector<City> cities;

    auto start = std::chrono::high_resolution_clock::now();
    auto result = CityService::findCitiesWithAllTypes(cities);
    auto end = std::chrono::high_resolution_clock::now();

    std::chrono::duration<double, std::milli> elapsed = end - start;
    spdlog::info("FindCitiesWithAllTypes_EmptyList took {} ms", elapsed.count());

    EXPECT_TRUE(result.empty());
}

int main() {
    ::testing::InitGoogleTest();
    return RUN_ALL_TESTS();
}