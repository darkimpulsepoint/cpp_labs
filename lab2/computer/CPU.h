#include "Component.h"
#include <string>

class CPU : public Component {
private:
    int coresCount;
public:
    CPU(int id, int coresCount);
    void setCoresCount(int coresCount);
    int getCoresCount() const;
    std::string toString() const;
};