#pragma once
#include <iostream>

class ObjectInfo {
private:
    std::string name;
    int code;

public:
    ObjectInfo();
    ObjectInfo(const std::string& name, int code);

    std::string getName() const;
    int getCode() const;

    void setName(const std::string& name);
    void setCode(int code);
};

