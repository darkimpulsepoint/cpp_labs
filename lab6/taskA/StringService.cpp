#include "StringService.h"

#include <string>
#include <qt6/QtCore/QString>

#include "FileReader.h"
#include "FileWriter.h"
#include "Zipper.h"

int StringService::maxConsecutiveDigitsInFile_WriteToFileAndZip(const std::string& filename, QString outFile) {
    std::string text = FileReader::read(filename);
    int maxCount = 0;
    int currentCount = 0;

    for (char ch : text) {
        if (std::isdigit(ch)) {
            currentCount++;
            maxCount = std::max(maxCount, currentCount);
        } else {
            currentCount = 0;
        }
    }

    FileWriter::write(outFile.toStdString(), std::to_string(maxCount));

    QFileInfoList l;
    l.append(QFileInfo(outFile));
    Zipper::zip(QString(filename.c_str()).split(".").first() + ".zip", l);

    return maxCount;
}
