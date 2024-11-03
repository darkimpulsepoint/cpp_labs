#include "CircleService.h"
#include <stdexcept>

bool CircleService::areCollinear(const Circle& c1, const Circle& c2, const Circle& c3) {
        std::pair<int, int> coords1 = c1.center();
        std::pair<int, int> coords2 = c2.center();
        std::pair<int, int> coords3 = c3.center();
        return (coords1.second - coords2.second) * (coords2.first - coords3.first) == (coords2.second - coords3.second) * (coords1.first - coords2.first);
    }

std::vector<std::vector<Circle> > CircleService::findCollinearGroups(const std::vector<Circle>& circles) {
    std::set<std::set<size_t>> uniqueGroups;
    std::vector<std::vector<Circle>> collinearGroups;

    for (size_t i = 0; i < circles.size(); ++i) {
        for (size_t j = i + 1; j < circles.size(); ++j) {
            std::set<size_t> group = {i, j};
            for (size_t k = 0; k < circles.size(); ++k) {
                if (k != i && k != j && areCollinear(circles[i], circles[j], circles[k])) {
                    group.insert(k);
                }
            }
            if (group.size() >= 2) {
                uniqueGroups.insert(group);
            }
        }
    }

    for (const auto& group : uniqueGroups) {
        std::vector<Circle> collinearGroup;
        for (auto index : group) {
            collinearGroup.push_back(circles[index]);
        }
        collinearGroups.push_back(collinearGroup);
    }

    return collinearGroups;
}

Circle CircleService::findMinCircleByArea(const std::vector<Circle>& circles) {
    if (circles.empty()) throw std::runtime_error("No circles in the vector");
    const Circle* minCircle = &circles[0];

    for (const auto& circle : circles) {
        if (circle.area() < minCircle->area()) {
            minCircle = &circle;
        }
    }

    return *minCircle;
}

Circle CircleService::findMaxCircleByArea(const std::vector<Circle>& circles) {
    if (circles.empty()) throw std::runtime_error("No circles in the vector");
    const Circle* maxCircle = &circles[0];

    for (const auto& circle : circles) {
        if (circle.area() > maxCircle->area()) {
            maxCircle = &circle;
        }
    }

    return *maxCircle;
}

Circle CircleService::findMinCircleByPerimeter(const std::vector<Circle>& circles) {
    if (circles.empty()) throw std::runtime_error("No circles in the vector");
    const Circle* minCircle = &circles[0];

    for (const auto& circle : circles) {
        if (circle.perimeter() < minCircle->perimeter()) {
            minCircle = &circle;
        }
    }

    return *minCircle;
}

Circle CircleService::findMaxCircleByPerimeter(const std::vector<Circle>& circles) {
    if (circles.empty()) throw std::runtime_error("No circles in the vector");
    const Circle* maxCircle = &circles[0];

    for (const auto& circle : circles) {
        if (circle.perimeter() > maxCircle->perimeter()) {
            maxCircle = &circle;
        }
    }

    return *maxCircle;
}