#pragma once
#include <map>
#include <string>

class Wagon {
protected:
    int id;
    double weight; // Weight field

public:
    Wagon(int id, double weight);
    virtual ~Wagon();

    int getId() const;
    void setId(int id);

    double getWeight() const;
    void setWeight(double weight);

    virtual std::string toString() const;
    virtual std::map<std::string, std::string> getFieldValues() const = 0;
};