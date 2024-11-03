#include "FileReader.h"
#include <fstream>
#include <iostream>
#include <sstream>
#include <stdexcept>

std::string FileReader::read(const std::string& filename) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        throw std::runtime_error("Can not open file: " + filename);
    }

    char temp = 'a';
    if(!(file >> temp)) throw empty_file();

    file.clear();
    file.seekg(0, std::ios::beg);

    std::ostringstream ss;
    ss << file.rdbuf();

    if (ss.str().empty()) throw empty_file();

    file.close();
    return ss.str();
}