#include "ComplexNumber.h"
#include <iostream>
using namespace std;

ComplexNumber::ComplexNumber(double real, double imaginary) : mReal(real), mImag(imaginary) {}

ComplexNumber &ComplexNumber::operator+=(const ComplexNumber &rhs) {
    mReal += rhs.mReal;
    mImag += rhs.mImag;
    return *this;
}

ComplexNumber &ComplexNumber::operator-=(const ComplexNumber &rhs) {
    mReal -= rhs.mReal;
    mImag -= rhs.mImag;
    return *this;
}

ComplexNumber &ComplexNumber::operator*=(const ComplexNumber &rhs) {
    double oldReal = mReal;
    mReal = mReal * rhs.mReal - mImag * rhs.mImag;
    mImag = oldReal * rhs.mImag + mImag * rhs.mReal;
    return *this;
}

ComplexNumber &ComplexNumber::operator/=(const ComplexNumber &rhs) {
    ComplexNumber result;
    result.mReal = (mReal * rhs.mReal + mImag * rhs.mImag) / ((rhs.mReal * rhs.mReal) + (mImag * mImag));
    result.mImag = (mImag * rhs.mReal - mReal * rhs.mImag) / ((rhs.mReal * rhs.mReal) + (mImag * mImag));
    return *this;
}

std::ostream &operator<<(std::ostream &out, const ComplexNumber &c) {
    out << c.mReal << ' ' << c.mImag << "i\n";
    return out;
}

std::istream &operator>>(std::istream &in, ComplexNumber &c) {
    in >> c.mReal >> c.mImag;
    return in;
}

const ComplexNumber operator+(const ComplexNumber &lhs, const ComplexNumber &rhs) {
    ComplexNumber result(lhs); // default copy constructor
    result += rhs;
    return result;
}

const ComplexNumber operator-(const ComplexNumber &lhs, const ComplexNumber &rhs) {
    ComplexNumber result(lhs);
    result -= rhs;
    return result;
}

const ComplexNumber operator*(const ComplexNumber &lhs, const ComplexNumber &rhs) {
    ComplexNumber result(lhs);
    result *= rhs;
    return result;
}

const ComplexNumber operator/(const ComplexNumber &lhs, const ComplexNumber &rhs) {
    ComplexNumber result(lhs);
    result /= rhs;
    return result;
}