#ifndef RATIONAL_H
#define RATIONAL_H
#include <cmath>
class Rational {
    long long m_numerator;// <-- this number should hold the sign information as well
    long long m_denominator;

public:
    Rational(long long numerator, long long denominator) : 
            m_numerator(numerator),
            m_denominator(denominator) { reduce(); }

    void reduce() {
        long long gcd;
        if(m_denominator < 0) {
            m_denominator *= -1;
            m_numerator *= -1;
        }
        gcd = euclidGCD(std::abs(m_numerator), std::abs(m_denominator));
        m_numerator /= gcd;
        m_denominator /= gcd;
    }

    Rational operator+(Rational other) {
        return Rational(
            m_numerator * other.denominator() + other.numerator() * m_denominator,
            m_denominator * other.denominator());
    }

    long long denominator() const { return m_denominator;}
    long long numerator() const { return m_numerator; }
    static long long euclidGCD(long long a, long long b) {
        //  a mod b = n
        //  b mod n = m
        //  ...
        //  if m == 0 return b
        if ( b == 0 ) return a;
        return euclidGCD(b, a % b);
    }
};

std::ostream& operator<<(std::ostream& os, const Rational& rational) {
    os << rational.numerator() << "/" << rational.denominator();
    return os;
}
#endif