#pragma once
#include <string>
#include <map>

class Serializer {
public:
    static std::string serialize(const std::map<std::string, std::string>& data);
};
