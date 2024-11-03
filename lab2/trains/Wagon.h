#pragma once
#include <string>

class Wagon {
protected:
    int id;
    double weight;

public:
    Wagon(int id, double weight);
    virtual ~Wagon();

    int getId() const;
    void setId(int id);

    double getWeight() const;
    void setWeight(double weight);

    virtual std::string toString() const;
};