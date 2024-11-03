#include "Component.h"
#include <string>

class DiskDrive : public Component {
private:
    int numberOfSlots;
public:
    DiskDrive(int id, int slots);
    void setNumberOfSlots(int slots);
    int getNumberOfSlots() const;
    std::string toString() const;
};