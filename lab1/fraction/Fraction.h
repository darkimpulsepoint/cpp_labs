#pragma once
#include <iostream>
#include <complex>
#include <vector>

class Fraction {
public:
    Fraction(const std::complex<int>& numerator, const std::complex<int>& denominator);

    std::complex<int> getNumerator() const;
    std::complex<int> getDenominator() const;

    void setNumerator(const std::complex<int>& numerator);
    void setDenominator(const std::complex<int>& denominator);

    Fraction();

    Fraction operator+(const Fraction &second) const;

    Fraction operator-(const Fraction &second) const;

    Fraction operator*(const Fraction &second) const;

    Fraction operator/(const Fraction &second) const;

    bool operator==(const Fraction &second) const;

    std::string toString() const;

private:
    std::complex<int> m;
    std::complex<int> n;

    void normalize();
    int gcd(int, int) const;
};