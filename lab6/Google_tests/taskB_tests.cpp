#include <gtest/gtest.h>
#include <spdlog/spdlog.h>
#include <fstream>
#include <string>
#include <vector>
#include <chrono>
#include "TrainService.h"
#include "Train.h"
#include "PassengerWagon.h"
#include "Zipper.h"

class TrainServiceTest : public ::testing::Test {
protected:
    void SetUp() override {
        spdlog::info("Setting up test files for TrainService...");

        train.addWagon(new PassengerWagon(1, 500.0, 15000.0, 5, 200));
        train.addWagon(new PassengerWagon(2, 300.0, 16000.0, 3, 100));
        train.addWagon(new PassengerWagon(3, 400.0, 17000.0, 4, 150));
        train.addWagon(new PassengerWagon(4, 400.0, 17000.0, 5, 250)); // Additional wagon for variety
    }

    Train train;
};

TEST_F(TrainServiceTest, GetTotalPassengers_WriteAndZip) {
    spdlog::info("Running GetTotalPassengers_WriteAndZip test...");

    auto start = std::chrono::high_resolution_clock::now();
    int total = TrainService::getTotalPassengers_WriteAndZip(train, "total_passengers_test.txt");
    auto end = std::chrono::high_resolution_clock::now();

    EXPECT_EQ(total, 700);

    std::ifstream file("total_passengers_test.txt");
    ASSERT_TRUE(file.is_open());
    std::string content;
    std::getline(file, content);
    file.close();

    EXPECT_EQ(content, "700");
    EXPECT_TRUE(std::ifstream("total_passengers_test.zip").good());

    spdlog::info("GetTotalPassengers_WriteAndZip executed in {} ms",
                  std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count());

    if (std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count() > 100) {
        GTEST_FAIL() << "GetTotalPassengers_WriteAndZip exceeded timeout of 100 ms";
    }
}

TEST_F(TrainServiceTest, GetTotalPassengers_EmptyTrain) {
    spdlog::info("Running GetTotalPassengers_EmptyTrain test...");

    Train emptyTrain;

    auto start = std::chrono::high_resolution_clock::now();
    int total = TrainService::getTotalPassengers_WriteAndZip(emptyTrain, "total_passengers_empty_test.txt");
    auto end = std::chrono::high_resolution_clock::now();

    EXPECT_EQ(total, 0);

    std::ifstream file("total_passengers_empty_test.txt");
    ASSERT_TRUE(file.is_open());
    std::string content;
    std::getline(file, content);
    file.close();

    EXPECT_EQ(content, "0");
    EXPECT_TRUE(std::ifstream("total_passengers_empty_test.zip").good());

    spdlog::info("GetTotalPassengers_EmptyTrain executed in {} ms",
                  std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count());

    if (std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count() > 100) {
        GTEST_FAIL() << "GetTotalPassengers_EmptyTrain exceeded timeout of 100 ms";
    }
}

TEST_F(TrainServiceTest, SortWagonsByComfort_WriteAndZip) {
    spdlog::info("Running SortWagonsByComfort_WriteAndZip test...");

    auto start = std::chrono::high_resolution_clock::now();
    TrainService::sortWagonsByComfort_WriteAndZip(train, "sorted_train_test.xml");
    auto end = std::chrono::high_resolution_clock::now();

    std::ifstream file("sorted_train_test.xml");
    ASSERT_TRUE(file.is_open());
    std::string content((std::istreambuf_iterator<char>(file)), std::istreambuf_iterator<char>());
    file.close();

    EXPECT_NE(content.find("<PassengerWagon>"), std::string::npos);
    EXPECT_NE(content.find("<ID>1</ID>"), std::string::npos);
    EXPECT_TRUE(std::ifstream("sorted_train_test.zip").good());

    spdlog::info("SortWagonsByComfort_WriteAndZip executed in {} ms",
                  std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count());

    if (std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count() > 100) {
        GTEST_FAIL() << "SortWagonsByComfort_WriteAndZip exceeded timeout of 100 ms";
    }
}

TEST_F(TrainServiceTest, SortWagonsByComfort_NoWagons) {
    spdlog::info("Running SortWagonsByComfort_NoWagons test...");

    Train emptyTrain;

    auto start = std::chrono::high_resolution_clock::now();
    TrainService::sortWagonsByComfort_WriteAndZip(emptyTrain, "sorted_empty_train_test.xml");
    auto end = std::chrono::high_resolution_clock::now();

    std::ifstream file("sorted_empty_train_test.xml");
    ASSERT_TRUE(file.is_open());
    std::string content((std::istreambuf_iterator<char>(file)), std::istreambuf_iterator<char>());
    file.close();

    EXPECT_EQ(content, "<Train>\n</Train>\n");
    EXPECT_TRUE(std::ifstream("sorted_empty_train_test.zip").good());

    spdlog::info("SortWagonsByComfort_NoWagons executed in {} ms",
                  std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count());

    if (std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count() > 100) {
        GTEST_FAIL() << "SortWagonsByComfort_NoWagons exceeded timeout of 100 ms";
    }
}

TEST_F(TrainServiceTest, FindWagonsWithPassengersInRange_WriteAndZip) {
    spdlog::info("Running FindWagonsWithPassengersInRange_WriteAndZip test...");

    auto start = std::chrono::high_resolution_clock::now();
    auto wagons = TrainService::findWagonsWithPassengersInRange_WriteAndZip(train, 100, 200, "wagons_in_range_test.txt");
    auto end = std::chrono::high_resolution_clock::now();

    EXPECT_EQ(wagons.size(), 3);

    std::ifstream file("wagons_in_range_test.txt");
    ASSERT_TRUE(file.is_open());
    std::string content((std::istreambuf_iterator<char>(file)), std::istreambuf_iterator<char>());
    file.close();

    EXPECT_NE(content.find("<PassengerWagon>"), std::string::npos);
    EXPECT_TRUE(std::ifstream("wagons_in_range_test.zip").good());

    spdlog::info("FindWagonsWithPassengersInRange_WriteAndZip executed in {} ms",
                  std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count());

    if (std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count() > 100) {
        GTEST_FAIL() << "FindWagonsWithPassengersInRange_WriteAndZip exceeded timeout of 100 ms";
    }
}

TEST_F(TrainServiceTest, FindWagonsWithPassengersInRange_NoWagonsInRange) {
    spdlog::info("Running FindWagonsWithPassengersInRange_NoWagonsInRange test...");

    auto start = std::chrono::high_resolution_clock::now();
    auto wagons = TrainService::findWagonsWithPassengersInRange_WriteAndZip(train, 300, 400, "wagons_no_in_range_test.txt");
    auto end = std::chrono::high_resolution_clock::now();

    EXPECT_EQ(wagons.size(), 0);

    std::ifstream file("wagons_no_in_range_test.txt");
    ASSERT_TRUE(file.is_open());
    std::string content((std::istreambuf_iterator<char>(file)), std::istreambuf_iterator<char>());
    file.close();

    EXPECT_EQ(content, "");
    EXPECT_TRUE(std::ifstream("wagons_no_in_range_test.zip").good());

    spdlog::info("FindWagonsWithPassengersInRange_NoWagonsInRange executed in {} ms",
                  std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count());

    if (std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count() > 100) {
        GTEST_FAIL() << "FindWagonsWithPassengersInRange_NoWagonsInRange exceeded timeout of 100 ms";
    }
}

TEST_F(TrainServiceTest, SaveTrainToFileAndZip) {
    spdlog::info("Running SaveTrainToFileAndZip test...");

    auto start = std::chrono::high_resolution_clock::now();
    TrainService::saveTrainToFileAndZip(train, "train_serialized_test.xml");
    auto end = std::chrono::high_resolution_clock::now();

    std::ifstream file("train_serialized_test.xml");
    ASSERT_TRUE(file.is_open());
    std::string content((std::istreambuf_iterator<char>(file)), std::istreambuf_iterator<char>());
    file.close();

    EXPECT_NE(content.find("<Train>"), std::string::npos);
    EXPECT_NE(content.find("</Train>"), std::string::npos);
    EXPECT_TRUE(std::ifstream("train_serialized_test.zip").good());

    spdlog::info("SaveTrainToFileAndZip executed in {} ms",
                  std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count());

    if (std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count() > 100) {
        GTEST_FAIL() << "SaveTrainToFileAndZip exceeded timeout of 100 ms";
    }
}

TEST_F(TrainServiceTest, SaveEmptyTrainToFileAndZip) {
    spdlog::info("Running SaveEmptyTrainToFileAndZip test...");

    Train emptyTrain;

    auto start = std::chrono::high_resolution_clock::now();
    TrainService::saveTrainToFileAndZip(emptyTrain, "empty_train_serialized_test.xml");
    auto end = std::chrono::high_resolution_clock::now();

    std::ifstream file("empty_train_serialized_test.xml");
    ASSERT_TRUE(file.is_open());
    std::string content((std::istreambuf_iterator<char>(file)), std::istreambuf_iterator<char>());
    file.close();

    EXPECT_EQ(content, "<Train>\n</Train>\n");
    EXPECT_TRUE(std::ifstream("empty_train_serialized_test.zip").good());

    spdlog::info("SaveEmptyTrainToFileAndZip executed in {} ms",
                  std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count());

    if (std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count() > 100) {
        GTEST_FAIL() << "SaveEmptyTrainToFileAndZip exceeded timeout of 100 ms";
    }
}
