#include "FileReverser.h"

#include <algorithm>
#include <sstream>
#include <string>

#include "FileReader.h"
#include "FileWriter.h"

void FileReverser::reverseLinesAndZip(const std::string& inputFilename, const std::string& outputFilename) {
    std::string content = FileReader::read(inputFilename);
    std::string reversedContent;
    std::string line;
    std::istringstream stream(content);

    while (std::getline(stream, line)) {
        std::reverse(line.begin(), line.end());
        reversedContent += line + '\n';
    }

    FileWriter::write(outputFilename, reversedContent);

}
