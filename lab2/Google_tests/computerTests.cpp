#include <gtest/gtest.h>
#include <chrono>
#include <iostream>
#include "computer.h"
#include <stdexcept>
#include <string>
#include "ComputerService.h"

TEST(ComputerServiceTest, FindComputerWithCPUsMoreCores_CountCheck) {
    HardDrive hd1(1, 500);
    DiskDrive dd1(1, 2);
    RAM ram1(1, 8192);
    CPU cpu1(1, 4);

    HardDrive hd2(2, 1000);
    DiskDrive dd2(2, 1);
    RAM ram2(2, 16384);
    CPU cpu2(2, 8);

    std::vector<Computer> computers = {
        Computer(&hd1, &dd1, &ram1, &cpu1),
        Computer(&hd2, &dd2, &ram2, &cpu2)
    };

    auto result = ComputerService::findComputerWithCPUsMoreCores(computers, 4);

    EXPECT_EQ(result.size(), 1);
}

TEST(ComputerServiceTest, FindComputerWithCPUsMoreCores_ValidCoresCount) {
    HardDrive hd1(1, 500);
    DiskDrive dd1(1, 2);
    RAM ram1(1, 8192);
    CPU cpu1(1, 4);

    HardDrive hd2(2, 1000);
    DiskDrive dd2(2, 1);
    RAM ram2(2, 16384);
    CPU cpu2(2, 8);

    std::vector<Computer> computers = {
        Computer(&hd1, &dd1, &ram1, &cpu1),
        Computer(&hd2, &dd2, &ram2, &cpu2)
    };

    auto result = ComputerService::findComputerWithCPUsMoreCores(computers, 4);
    EXPECT_EQ(result[0].getCPU()->getCoresCount(), 8);
}

TEST(ComputerServiceTest, FindComputerWithCPUsMoreCores_TimeCheck) {
    HardDrive hd1(1, 500);
    DiskDrive dd1(1, 2);
    RAM ram1(1, 8192);
    CPU cpu1(1, 4);

    HardDrive hd2(2, 1000);
    DiskDrive dd2(2, 1);
    RAM ram2(2, 16384);
    CPU cpu2(2, 8);

    std::vector<Computer> computers = {
        Computer(&hd1, &dd1, &ram1, &cpu1),
        Computer(&hd2, &dd2, &ram2, &cpu2)
    };

    auto start = std::chrono::high_resolution_clock::now();
    auto result = ComputerService::findComputerWithCPUsMoreCores(computers, 4);
    auto end = std::chrono::high_resolution_clock::now();

    EXPECT_LT(std::chrono::duration_cast<std::chrono::microseconds>(end - start).count(), 1000);
}

TEST(ComputerServiceTest, FindComputerWithCPUsMoreCores_NoCoresAboveEight) {
    HardDrive hd1(1, 500);
    DiskDrive dd1(1, 2);
    RAM ram1(1, 8192);
    CPU cpu1(1, 4);

    HardDrive hd2(2, 1000);
    DiskDrive dd2(2, 1);
    RAM ram2(2, 16384);
    CPU cpu2(2, 8);

    std::vector<Computer> computers = {
        Computer(&hd1, &dd1, &ram1, &cpu1),
        Computer(&hd2, &dd2, &ram2, &cpu2)
    };

    auto result = ComputerService::findComputerWithCPUsMoreCores(computers, 8);
    EXPECT_EQ(result.size(), 0);
}

TEST(ComputerServiceTest, FindComputerWithCPUsMoreCores_TwoCoresCheck) {
    HardDrive hd1(1, 500);
    DiskDrive dd1(1, 2);
    RAM ram1(1, 8192);
    CPU cpu1(1, 4);

    HardDrive hd2(2, 1000);
    DiskDrive dd2(2, 1);
    RAM ram2(2, 16384);
    CPU cpu2(2, 8);

    std::vector<Computer> computers = {
        Computer(&hd1, &dd1, &ram1, &cpu1),
        Computer(&hd2, &dd2, &ram2, &cpu2)
    };

    auto result = ComputerService::findComputerWithCPUsMoreCores(computers, 3);
    EXPECT_EQ(result.size(), 2);
}

TEST(ComputerServiceTest, FindComputerWithHardDrivesSizeInRange_ValidRange) {
    HardDrive hd1(1, 500);
    DiskDrive dd1(1, 2);
    RAM ram1(1, 8192);
    CPU cpu1(1, 4);

    HardDrive hd2(2, 1000);
    DiskDrive dd2(2, 1);
    RAM ram2(2, 16384);
    CPU cpu2(2, 8);

    std::vector<Computer> computers = {
        Computer(&hd1, &dd1, &ram1, &cpu1),
        Computer(&hd2, &dd2, &ram2, &cpu2)
    };

    auto result = ComputerService::findComputerWithHardDrivesSizeInRange(computers, 300, 800);
    EXPECT_EQ(result.size(), 1);
}

TEST(ComputerServiceTest, FindComputerWithHardDrivesSizeInRange_HardDriveSizeCheck) {
    HardDrive hd1(1, 500);
    DiskDrive dd1(1, 2);
    RAM ram1(1, 8192);
    CPU cpu1(1, 4);

    HardDrive hd2(2, 1000);
    DiskDrive dd2(2, 1);
    RAM ram2(2, 16384);
    CPU cpu2(2, 8);

    std::vector<Computer> computers = {
        Computer(&hd1, &dd1, &ram1, &cpu1),
        Computer(&hd2, &dd2, &ram2, &cpu2)
    };

    auto result = ComputerService::findComputerWithHardDrivesSizeInRange(computers, 300, 800);
    EXPECT_EQ(result[0].getHardDrive()->getSizeInGBs(), 500);
}

TEST(ComputerServiceTest, FindComputerWithHardDrivesSizeInRange_NoComputersInRange) {
    HardDrive hd1(1, 500);
    DiskDrive dd1(1, 2);
    RAM ram1(1, 8192);
    CPU cpu1(1, 4);

    HardDrive hd2(2, 1000);
    DiskDrive dd2(2, 1);
    RAM ram2(2, 16384);
    CPU cpu2(2, 8);

    std::vector<Computer> computers = {
        Computer(&hd1, &dd1, &ram1, &cpu1),
        Computer(&hd2, &dd2, &ram2, &cpu2)
    };

    auto result = ComputerService::findComputerWithHardDrivesSizeInRange(computers, 600, 700);
    EXPECT_EQ(result.size(), 0);
}

TEST(ComputerServiceTest, FindComputerWithHardDrivesSizeInRange_TwoComputersInRange) {
    HardDrive hd1(1, 500);
    DiskDrive dd1(1, 2);
    RAM ram1(1, 8192);
    CPU cpu1(1, 4);

    HardDrive hd2(2, 1000);
    DiskDrive dd2(2, 1);
    RAM ram2(2, 16384);
    CPU cpu2(2, 8);

    std::vector<Computer> computers = {
        Computer(&hd1, &dd1, &ram1, &cpu1),
        Computer(&hd2, &dd2, &ram2, &cpu2)
    };

    auto result = ComputerService::findComputerWithHardDrivesSizeInRange(computers, 0, 2000);
    EXPECT_EQ(result.size(), 2);
}

TEST(ComputerServiceTest, FindComputerWithRamSize_ValidSize) {
    HardDrive hd1(1, 500);
    DiskDrive dd1(1, 2);
    RAM ram1(1, 8192);
    CPU cpu1(1, 4);

    HardDrive hd2(2, 1000);
    DiskDrive dd2(2, 1);
    RAM ram2(2, 16384);
    CPU cpu2(2, 8);

    std::vector<Computer> computers = {
        Computer(&hd1, &dd1, &ram1, &cpu1),
        Computer(&hd2, &dd2, &ram2, &cpu2)
    };

    auto result = ComputerService::findComputerWithRamSize(computers, 8192);
    EXPECT_EQ(result.size(), 1);
}

TEST(ComputerServiceTest, FindComputerWithRamSize_RamSizeCheck) {
    HardDrive hd1(1, 500);
    DiskDrive dd1(1, 2);
    RAM ram1(1, 8192);
    CPU cpu1(1, 4);

    HardDrive hd2(2, 1000);
    DiskDrive dd2(2, 1);
    RAM ram2(2, 16384);
    CPU cpu2(2, 8);

    std::vector<Computer> computers = {
        Computer(&hd1, &dd1, &ram1, &cpu1),
        Computer(&hd2, &dd2, &ram2, &cpu2)
    };

    auto result = ComputerService::findComputerWithRamSize(computers, 8192);
    EXPECT_EQ(result[0].getRAM()->getMemorySizeInMBs(), 8192);
}

TEST(ComputerServiceTest, FindComputerWithRamSize_NoComputersWithSize) {
    HardDrive hd1(1, 500);
    DiskDrive dd1(1, 2);
    RAM ram1(1, 8192);
    CPU cpu1(1, 4);

    HardDrive hd2(2, 1000);
    DiskDrive dd2(2, 1);
    RAM ram2(2, 16384);
    CPU cpu2(2, 8);

    std::vector<Computer> computers = {
        Computer(&hd1, &dd1, &ram1, &cpu1),
        Computer(&hd2, &dd2, &ram2, &cpu2)
    };

    auto result = ComputerService::findComputerWithRamSize(computers, 4096);
    EXPECT_EQ(result.size(), 0);
}

TEST(ComputerServiceTest, FindComputerWithRamSize_NoComputersWithZeroSize) {
    HardDrive hd1(1, 500);
    DiskDrive dd1(1, 2);
    RAM ram1(1, 8192);
    CPU cpu1(1, 4);

    HardDrive hd2(2, 1000);
    DiskDrive dd2(2, 1);
    RAM ram2(2, 16384);
    CPU cpu2(2, 8);

    std::vector<Computer> computers = {
        Computer(&hd1, &dd1, &ram1, &cpu1),
        Computer(&hd2, &dd2, &ram2, &cpu2)
    };

    auto result = ComputerService::findComputerWithRamSize(computers, 0);
    EXPECT_EQ(result.size(), 0);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}