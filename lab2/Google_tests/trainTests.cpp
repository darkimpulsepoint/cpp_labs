#include <gtest/gtest.h>
#include <chrono>
#include "Train.h"
#include "TrainService.h"
#include "PassengerWagon.h"
#include "Wagon.h"

TEST(TrainTest, AddWagon) {
    Train train;
    train.addWagon(new PassengerWagon(1, 30.0, 100.0, 3, 50));
    train.addWagon(new PassengerWagon(2, 20.0, 150.0, 5, 30));

    EXPECT_EQ(train.getWagons().size(), 2);
}

TEST(TrainServiceTest, GetTotalPassengers) {
    Train train;
    train.addWagon(new PassengerWagon(1, 30.0, 100.0, 3, 50));
    train.addWagon(new PassengerWagon(2, 20.0, 150.0, 5, 30));

    EXPECT_EQ(TrainService::getTotalPassengers(train), 80);
}

TEST(TrainServiceTest, SortWagonsByComfort) {
    Train train;
    train.addWagon(new PassengerWagon(1, 30.0, 100.0, 3, 50));
    train.addWagon(new PassengerWagon(2, 20.0, 150.0, 5, 30));
    train.addWagon(new PassengerWagon(3, 10.0, 200.0, 4, 70));

    auto start = std::chrono::high_resolution_clock::now();
    TrainService::sortWagonsByComfort(train);
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsed = end - start;

    EXPECT_LT(elapsed.count(), 1.0);

    EXPECT_EQ(static_cast<PassengerWagon*>(train.getWagons()[0])->getComfortLvl(), 3);
    EXPECT_EQ(static_cast<PassengerWagon*>(train.getWagons()[1])->getComfortLvl(), 4);
    EXPECT_EQ(static_cast<PassengerWagon*>(train.getWagons()[2])->getComfortLvl(), 5);
}

TEST(TrainServiceTest, FindWagonsInRange) {
    Train train;
    train.addWagon(new PassengerWagon(1, 30.0, 100.0, 3, 50));
    train.addWagon(new PassengerWagon(2, 20.0, 150.0, 5, 30));
    train.addWagon(new PassengerWagon(3, 10.0, 200.0, 4, 70));

    auto start = std::chrono::high_resolution_clock::now();
    std::vector<Wagon*> foundWagons = TrainService::findWagonsWithPassengersInRange(train, 15, 50);
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsed = end - start;

    EXPECT_LT(elapsed.count(), 1.0);

    EXPECT_EQ(foundWagons.size(), 2);
    EXPECT_EQ(foundWagons[0]->getId(), 1);
    EXPECT_EQ(foundWagons[1]->getId(), 2);
}

TEST(TrainServiceTest, FindWagonsInRangeLargeDataset) {
    Train train;
    for (int i = 1; i <= 1000; ++i) {
        train.addWagon(new PassengerWagon(i, i * 10.0, 100.0, i % 10 + 1, 50+10*i));
    }

    auto start = std::chrono::high_resolution_clock::now();
    std::vector<Wagon*> foundWagons = TrainService::findWagonsWithPassengersInRange(train, 100, 500);
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsed = end - start;

    EXPECT_LT(elapsed.count(), 1.0);
    EXPECT_GT(foundWagons.size(), 0);
}

TEST(TrainServiceTest, FindWagonsInRangeWithNoResults) {
    Train train;
    train.addWagon(new PassengerWagon(1, 10.0, 100.0, 3, 5));
    train.addWagon(new PassengerWagon(2, 20.0, 150.0, 5, 10));

    auto start = std::chrono::high_resolution_clock::now();
    std::vector<Wagon*> foundWagons = TrainService::findWagonsWithPassengersInRange(train, 15, 18);
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsed = end - start;

    EXPECT_LT(elapsed.count(), 1.0);
    EXPECT_EQ(foundWagons.size(), 0);
}

TEST(TrainServiceTest, FindWagonsInRangePerformanceTest) {
    Train train;
    for (int i = 1; i <= 10000; ++i) {
        train.addWagon(new PassengerWagon(i, i * 10.0, 100.0, i % 10 + 1, 5001-i));
    }

    auto start = std::chrono::high_resolution_clock::now();
    std::vector<Wagon*> foundWagons = TrainService::findWagonsWithPassengersInRange(train, 5000, 10000);
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsed = end - start;

    EXPECT_LT(elapsed.count(), 1.0);
    EXPECT_GT(foundWagons.size(), 0);
}

TEST(TrainServiceTest, FindWagonsInRangeEdgeCaseTest) {
    Train train;
    for (int i = 1; i <= 1000; ++i) {
        train.addWagon(new PassengerWagon(i, 0.0, 100.0, 3, 0));
    }

    auto start = std::chrono::high_resolution_clock::now();
    std::vector<Wagon*> foundWagons = TrainService::findWagonsWithPassengersInRange(train, 1, 10);
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsed = end - start;

    EXPECT_LT(elapsed.count(), 1.0);
    EXPECT_EQ(foundWagons.size(), 0);
}