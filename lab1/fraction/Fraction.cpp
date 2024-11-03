#include "Fraction.h"
#include <boost/exception/to_string.hpp>

Fraction::Fraction(const std::complex<int>& numerator, const std::complex<int>& denominator)
    : m(numerator), n(denominator) {normalize();}

std::complex<int> Fraction::getNumerator() const {
    return m;
}

std::complex<int> Fraction::getDenominator() const {
    return n;
}

void Fraction::setNumerator(const std::complex<int>& numerator) {
    m = numerator;
}

void Fraction::setDenominator(const std::complex<int>& denominator) {
    n = denominator;
}

Fraction::Fraction() {
    this->setNumerator(0);
    this->setDenominator(1);
}

int Fraction::gcd(int x, int y) const
{
    if (!(x == 0 && y == 0)) {
        if (!x) return y;
        if (!y) return x;
    }

    while (y != 0)
    {
        int c = x % y;
        x = y;
        y = c;
    }
    return x;
}

void Fraction::normalize()
{
    int reducer = gcd(gcd(m.real(), m.imag()), gcd(n.real(), n.imag()));

    this->m = m / reducer;
    this->n = n / reducer;

}

Fraction Fraction::operator+(const Fraction &second) const
{
    return Fraction(this->m * second.n + this->n * second.m, this->n * second.n);
}

Fraction Fraction::operator/(const Fraction &second) const
{
    return Fraction(this->m * second.n, this->n * second.m);
}

Fraction Fraction::operator-(const Fraction &second) const
{
    return Fraction(this->m * second.n - this->n * second.m, this->n * second.n);
}

Fraction Fraction::operator*(const Fraction &second) const
{
    return Fraction(this->m * second.m, this->n * second.n);
}

bool Fraction::operator==(const Fraction &second) const
{
    return (m/n == second.m/second.n);
}

std::string Fraction::toString() const{
    if (this->n != std::complex<int>(1,0))
    {
        return "("
        + std::to_string(this->m.real())
        + "+"
        +std::to_string(this->m.imag())
        +"i)"
        + "/" + "("
        + std::to_string(this->n.real())
        + "+"
        +std::to_string(this->n.imag())
        +"i)";
    }
    else
    {
        return "("
        + std::to_string(this->m.real())
        + "+"
        +std::to_string(this->m.imag())
        +"i)";
    }
}
