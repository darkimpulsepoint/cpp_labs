#include "ComputerService.h"

std::vector<Computer> ComputerService::findComputerWithCPUsMoreCores(const std::vector<Computer>& computers, int cores) {
    std::vector<Computer> result;
    for (const auto& computer : computers) {
        if (computer.getCPU()->getCoresCount() > cores) {
            result.push_back(computer);
        }
    }
    return result;
}

std::vector<Computer> ComputerService::findComputerWithHardDrivesSizeInRange(const std::vector<Computer>& computers, double min, double max) {
    std::vector<Computer> result;
    for (const auto& computer : computers) {
        double size = computer.getHardDrive()->getSizeInGBs();
        if (size >= min && size <= max) {
            result.push_back(computer);
        }
    }
    return result;
}

std::vector<Computer> ComputerService::findComputerWithRamSize(const std::vector<Computer>& computers, int ramSize) {
    std::vector<Computer> result;
    for (const auto& computer : computers) {
        if (computer.getRAM()->getMemorySizeInMBs() == ramSize) {
            result.push_back(computer);
        }
    }
    return result;
}