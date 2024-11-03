#pragma once
#include "computer.h"
#include <vector>

class ComputerService {
public:
    static std::vector<Computer> findComputerWithCPUsMoreCores(const std::vector<Computer>& computers, int cores);

    static std::vector<Computer> findComputerWithHardDrivesSizeInRange(const std::vector<Computer>& computers, double min, double max);

    static std::vector<Computer> findComputerWithRamSize(const std::vector<Computer>& computers, int ramSize);

};
