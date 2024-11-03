#pragma once
#include <string>
#include <quazip/quazip.h>

class StringService {
public:
    static int maxConsecutiveDigitsInFile_WriteToFileAndZip(const std::string& filename, QString outFile);
};
