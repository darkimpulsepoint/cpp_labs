#pragma once

#include "HardDrive.h"
#include "DiskDrive.h"
#include "RAM.h"
#include "CPU.h"

class Computer{
private:
    HardDrive *hardDrive;
    DiskDrive *diskDrive;
    RAM *ram;
    CPU *cpu;
    bool isTurned;

public:
    Computer(HardDrive *hd, DiskDrive *dd, RAM *r, CPU *c);

    void turnOn();

    void turnOff();

    bool isTurnedOn();

    HardDrive* getHardDrive() const;
    DiskDrive* getDiskDrive() const;
    RAM* getRAM() const;
    CPU* getCPU() const;

    virtual bool checkIsVirused();

    void displayHardDriveInfo() const;
};