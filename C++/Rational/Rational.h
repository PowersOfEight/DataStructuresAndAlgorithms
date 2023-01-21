#ifndef RATIONAL_H
#define RATIONAL_H
class Rational {
    long long m_numerator;// <-- this number should hold the sign information as well
    long long m_denominator;

public:
    Rational(long long numerator, 
        long long denominator) : 
            m_numerator(numerator),
            m_denominator(denominator) {

    }

    void reduce() {

    }

    static long long euclidGCD(long long a, long long b) {
        //  a mod b = n
        //  b mod n = m
        //  ...
        //  if m == 0 return b
        if ( b == 0 ) return a;
        return euclidGCD(b, a % b);
    }
};
#endif