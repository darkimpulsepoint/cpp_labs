#define BOOST_TEST_MODULE CircleTest
#include <boost/test/included/unit_test.hpp>
#include "Circle.h"
#include "CircleService.h"

BOOST_AUTO_TEST_SUITE(CircleTestSuite)

    BOOST_AUTO_TEST_CASE(test_area) {
    Circle circle1(0, 0, 5);
    Circle circle2(1, 1, 2);

    BOOST_CHECK_CLOSE(circle1.area(), 999.5398, 0.001);
    BOOST_CHECK_CLOSE(circle2.area(), 12.5664, 0.001);
}

BOOST_AUTO_TEST_CASE(test_perimeter) {
    Circle circle1(0, 0, 5);
    Circle circle2(1, 1, 2);

    BOOST_CHECK_CLOSE(circle1.perimeter(), 31.4159, 0.001);
    BOOST_CHECK_CLOSE(circle2.perimeter(), 12.5664, 0.001);
}

BOOST_AUTO_TEST_CASE(test_center) {
    Circle circle(3, 4, 5);
    auto center = circle.center();

    BOOST_CHECK_EQUAL(center.first, 3);
    BOOST_CHECK_EQUAL(center.second, 4);
}

BOOST_AUTO_TEST_CASE(test_min_circle_by_area) {
    std::vector<Circle> circles = {
        Circle(0, 0, 5),
        Circle(1, 1, 2),
        Circle(2, 2, 3)
    };

    Circle minCircle = CircleService::findMinCircleByArea(circles);
    BOOST_CHECK_EQUAL(minCircle.getRadius(), 2);
}

BOOST_AUTO_TEST_CASE(test_max_circle_by_area) {
    std::vector<Circle> circles = {
        Circle(0, 0, 5),
        Circle(1, 1, 2),
        Circle(2, 2, 3)
    };

    Circle maxCircle = CircleService::findMaxCircleByArea(circles);
    BOOST_CHECK_EQUAL(maxCircle.getRadius(), 5);
}

BOOST_AUTO_TEST_CASE(test_min_circle_by_perimeter) {
    std::vector<Circle> circles = {
        Circle(0, 0, 5),
        Circle(1, 1, 1),
        Circle(2, 2, 3)
    };

    Circle minCircle = CircleService::findMinCircleByPerimeter(circles);
    BOOST_CHECK_EQUAL(minCircle.getRadius(), 1);
}

BOOST_AUTO_TEST_CASE(test_max_circle_by_perimeter) {
    std::vector<Circle> circles = {
        Circle(0, 0, 5),
        Circle(1, 1, 1),
        Circle(2, 2, 3)
    };

    Circle maxCircle = CircleService::findMaxCircleByPerimeter(circles);
    BOOST_CHECK_EQUAL(maxCircle.getRadius(), 5);
}

BOOST_AUTO_TEST_CASE(test_empty_circle_vector) {
    std::vector<Circle> circles;

    BOOST_CHECK_THROW(CircleService::findMinCircleByArea(circles), std::runtime_error);
    BOOST_CHECK_THROW(CircleService::findMaxCircleByArea(circles), std::runtime_error);
    BOOST_CHECK_THROW(CircleService::findMinCircleByPerimeter(circles), std::runtime_error);
    BOOST_CHECK_THROW(CircleService::findMaxCircleByPerimeter(circles), std::runtime_error);
}

BOOST_AUTO_TEST_SUITE_END()