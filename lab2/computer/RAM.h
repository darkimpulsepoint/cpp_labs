#include "Component.h"
#include <string>

class RAM : public Component {
private:
    int memorySizeInMBs;
public:
    RAM(int id, double memory);
    void setMemorySizeInMBs(double MBs);
    double getMemorySizeInMBs() const;
    std::string toString() const;
};