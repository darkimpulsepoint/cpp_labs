#include "Circle.h"

Circle::Circle(double x, double y, double radius)
    : x(x), y(y), radius(radius) {}

double Circle::area() const {
    return M_PI * radius * radius;
}


double Circle::perimeter() const {
    return 2 * M_PI * radius;
}

std::pair<double, double> Circle::center() const {
    return std::make_pair(x, y);
}

double Circle::getX() const {
    return x;
}

double Circle::getY() const {
    return y;
}

double Circle::getRadius() const {
    return radius;
}

void Circle::setX(double x) {
    this->x = x;
}

void Circle::setY(double y) {
    this->y = y;
}

void Circle::setRadius(double radius) {
    this->radius = radius;
}