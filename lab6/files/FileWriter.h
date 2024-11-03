#pragma once
#include <string>

class FileWriter {
public:
    static void write(const std::string& filename, const std::string& content);
};
