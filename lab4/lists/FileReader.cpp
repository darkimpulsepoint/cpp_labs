#include "FileReader.h"
#include <fstream>
#include <sstream>
#include <stdexcept>

std::string FileReader::read(const std::string& filename) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        throw std::runtime_error("Не удалось открыть файл: " + filename);
    }

    std::ostringstream ss;
    ss << file.rdbuf();

    file.close();
    return ss.str();
}