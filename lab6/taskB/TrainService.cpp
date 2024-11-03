#include "TrainService.h"
#include <algorithm>
#include <iostream>
#include <qfileinfo.h>

#include "Serializer.h"
#include "FileWriter.h"
#include "PassengerWagon.h"
#include "Zipper.h"

int TrainService::getTotalPassengers_WriteAndZip(Train& train, const std::string filename) {
    int total = 0;
    for (auto& wagon : train.getWagons()) {
        if (PassengerWagon* passengerWagon = dynamic_cast<PassengerWagon*>(wagon)) {
            total += passengerWagon->getCurrPassengers();
        }
    }

    FileWriter::write(filename, std::to_string(total));
    QFileInfoList l;
    l.append(QFileInfo(filename.c_str()));
    Zipper::zip(QString(filename.c_str()).split(".").first() + ".zip", l);

    return total;
}

void TrainService::sortWagonsByComfort_WriteAndZip(Train& train, const std::string filename) {
    std::sort(train.getWagons().begin(), train.getWagons().end(), [](Wagon* a, Wagon* b) {
        if (PassengerWagon* passengerA = dynamic_cast<PassengerWagon*>(a)) {
            if (PassengerWagon* passengerB = dynamic_cast<PassengerWagon*>(b)) {
                return passengerA->getComfortLvl() < passengerB->getComfortLvl();
            }
        }
        return false;
    });

    saveTrainToFileAndZip(train, filename);
}

std::vector<Wagon*> TrainService::findWagonsWithPassengersInRange_WriteAndZip(Train& train, int min, int max, const std::string filename) {
    std::vector<Wagon*> result;
    std::string serialized = "";
    for (auto& wagon : train.getWagons()) {
        if (PassengerWagon* passengerWagon = dynamic_cast<PassengerWagon*>(wagon)) {
            int capacity = passengerWagon->getCurrPassengers();
            if (capacity >= min && capacity <= max) {
                result.push_back(wagon);
                serialized += Serializer::serialize(wagon->getFieldValues());
            }
        }
    }
    FileWriter::write(filename, serialized);
    QFileInfoList l;
    l.append(QFileInfo(filename.c_str()));
    Zipper::zip(QString(filename.c_str()).split(".").first() + ".zip", l);
    return result;
}

void TrainService::saveTrainToFileAndZip(Train& train, const std::string& filename) {
    std::string content = "<Train>\n";
    for (const auto& wagon : train.getWagons()) {
        content += Serializer::serialize(wagon->getFieldValues());
    }
    content += "</Train>\n";

    FileWriter::write(filename, content);

    QFileInfoList l;
    l.append(QFileInfo(filename.c_str()));
    Zipper::zip(QString(filename.c_str()).split(".").first() + ".zip", l);
}