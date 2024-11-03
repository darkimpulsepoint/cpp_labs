#pragma once
#include <utility>
#include <vector>

class Circle {
public:
    Circle(double x, double y, double radius);

    double area() const;
    double perimeter() const;
    std::pair<double, double> center() const;

    double getX() const;
    double getY() const;
    double getRadius() const;

    void setX(double x);
    void setY(double y);
    void setRadius(double radius);

private:
    double x;
    double y;
    double radius;
};