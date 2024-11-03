#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "Fraction.h"
#include "FractionService.h"

TEST_CASE("test1_modifyVector") {
    std::vector<Fraction> v = std::vector<Fraction>();
    Fraction a{std::complex<int>(6), std::complex<int>(3,6)};
    Fraction b{std::complex<int>(4), std::complex<int>(2, 4)};

    v.push_back(a);
    v.push_back(b);

    std::vector<Fraction> exp = std::vector<Fraction>();
    exp.push_back(a + b);
    exp.push_back(b);

    FractionService::modifyFractions(v);

    CHECK(v == exp);
}

TEST_CASE("test2_modifyVector") {
    std::vector<Fraction> fractions = {
        Fraction(std::complex<int>(1, 2), std::complex<int>(3, 4)),
        Fraction(std::complex<int>(5), std::complex<int>(6)),
        Fraction(std::complex<int>(3), std::complex<int>(4)),
        Fraction(std::complex<int>(2), std::complex<int>(5)),
    };

    FractionService::modifyFractions(fractions);

    CHECK(fractions[0] == Fraction(std::complex<int>(22, 24), std::complex<int>(15, 20)));
    CHECK(fractions[2] == Fraction(std::complex<int>(23, 20), std::complex<int>(10, 25)));
}

TEST_CASE("test_modifyEmptyVector") {
    std::vector<Fraction> fractions = std::vector<Fraction>();

    FractionService::modifyFractions(fractions);

    CHECK(fractions == std::vector<Fraction>());
}


    TEST_CASE("Default constructor") {
    Fraction f_default;
    CHECK(f_default.getNumerator() == std::complex<int>(0, 0));
    CHECK(f_default.getDenominator() == std::complex<int>(1, 0));
}

    TEST_CASE("Constructor with two integers") {
    Fraction f_two(3, 4);
    CHECK(f_two.getNumerator() == std::complex<int>(3, 0));
    CHECK(f_two.getDenominator() == std::complex<int>(4, 0));
}

    TEST_CASE("Constructor with complex numerator and denominator") {
        Fraction f_complex(std::complex<int>(1, 2), std::complex<int>(3, 4));
        CHECK(f_complex.getNumerator() == std::complex<int>(1, 2));
        CHECK(f_complex.getDenominator() == std::complex<int>(3, 4));
    }

    TEST_CASE("Addition operator") {
        Fraction f1(std::complex<int>(1, 2), std::complex<int>(3, 4));
        Fraction f2(5, 6);
        Fraction sum = f1 + f2;
        CHECK(sum == Fraction(std::complex<int>(22, 24),std::complex<int>(15, 20)));
    }

    TEST_CASE("Subtraction operator") {
        Fraction f1(std::complex<int>(1, 2), std::complex<int>(3, 4));
        Fraction f2(5, 6);
        Fraction difference = f1 - f2;
        CHECK(difference== Fraction(std::complex<int>(-8, -24),std::complex<int>(15, 20)));
    }

    TEST_CASE("Multiplication operator") {
        Fraction f1(std::complex<int>(1, 2), std::complex<int>(3, 4));
        Fraction f2(5, 6);
        Fraction product = f1 * f2;
        CHECK(product == Fraction(std::complex<int>(5 , 10), std::complex<int>(18, 0)));
    }


    TEST_CASE("Equality operator") {
        Fraction f3(std::complex<int>(2, 4), std::complex<int>(3, 1));
        Fraction f4(std::complex<int>(4, 8), std::complex<int>(6, 2));
        CHECK(f3 == f4);
    }

