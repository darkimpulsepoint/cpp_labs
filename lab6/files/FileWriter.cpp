#include "FileWriter.h"

#include <fstream>

void FileWriter::write(const std::string& filename, const std::string& content) {
    std::ofstream file(filename);
    if (!file.is_open()) {
        throw std::runtime_error("Cannot open file: " + filename);
    }

    file << content;

    file.close();
}