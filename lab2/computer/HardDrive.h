#include "Component.h"

#include <string>

class HardDrive : public Component {
private:
    double sizeInGBs;
public:
    HardDrive(int id, double size);
    void setSizeInGBs(double GBs);
    double getSizeInGBs() const;
    std::string toString() const;
};