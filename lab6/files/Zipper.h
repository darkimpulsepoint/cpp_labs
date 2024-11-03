#pragma once
#include <quazip/quazip.h>

class Zipper {
public:
    static bool zip(const QString filepath, const QFileInfoList files);
};

