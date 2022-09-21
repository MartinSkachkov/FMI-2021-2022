#ifndef _COMPLEX_NUMBER_H_
#define _COMPLEX_NUMBER_H_
#include <fstream>

class ComplexNumber {
private:
    double mReal;
    double mImag;

public:
    // we don't need big 4 since we don't have dynamic mem
    ComplexNumber(double real = 0, double imaginary = 0);

    ComplexNumber &operator+=(const ComplexNumber &rhs);
    ComplexNumber &operator-=(const ComplexNumber &rhs);
    ComplexNumber &operator*=(const ComplexNumber &rhs);
    ComplexNumber &operator/=(const ComplexNumber &rhs);

    friend std::ostream &operator<<(std::ostream &out, const ComplexNumber &c);
    friend std::istream &operator>>(std::istream &in, ComplexNumber &c);
};

const ComplexNumber operator+(const ComplexNumber &lhs, const ComplexNumber &rhs);
const ComplexNumber operator-(const ComplexNumber &lhs, const ComplexNumber &rhs);
const ComplexNumber operator*(const ComplexNumber &lhs, const ComplexNumber &rhs);
const ComplexNumber operator/(const ComplexNumber &lhs, const ComplexNumber &rhs);

#endif