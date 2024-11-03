#pragma once
#include <vector>
#include "Circle.h"


class CircleService {
private:
    static bool areCollinear(const Circle& c1, const Circle& c2, const Circle& c3);

public:

    static std::vector<std::vector<Circle>> findCollinearGroups(const std::vector<Circle>& circles);

    static Circle findMinCircleByArea(const std::vector<Circle>& circles);
    static Circle findMaxCircleByArea(const std::vector<Circle>& circles);
    static Circle findMinCircleByPerimeter(const std::vector<Circle>& circles);
    static Circle findMaxCircleByPerimeter(const std::vector<Circle>& circles);
};