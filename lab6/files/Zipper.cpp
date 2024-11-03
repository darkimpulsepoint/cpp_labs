#include "quazip/quazip.h"
#include "quazip/quazipfile.h"
#include <quazip/JlCompress.h>

#include "Zipper.h"

#include <iostream>
#include <fmt/format.h>


bool Zipper::zip(const QString filePath, const QFileInfoList files) {
    QuaZip archive(filePath);
    archive.setFileNameCodec("IBM866");


    if (!archive.open(QuaZip::mdCreate)) {
        return false;
    }

    QFile inFile;

    QuaZipFile outFile(&archive);

    char c;
    foreach(QFileInfo fileInfo, files) {

        if (!fileInfo.isFile())
            continue;

        QString fileNameWithRelativePath = fileInfo.filePath();

        inFile.setFileName(fileInfo.filePath());

        if (!inFile.open(QIODevice::ReadOnly)) {
            return false;
        }

        if (!outFile.open(QIODevice::WriteOnly, QuaZipNewInfo(fileInfo.fileName(), fileInfo.fileName()))) {
            return false;
        }


        while (inFile.getChar(&c) && outFile.putChar(c));

        if (outFile.getZipError() != UNZ_OK) {
            return false;
        }

        outFile.close();

        if (outFile.getZipError() != UNZ_OK) {
            return false;
        }

        inFile.close();
    }


    archive.close();

    if (archive.getZipError() != 0) {
        return false;
    }

    return true;
}
