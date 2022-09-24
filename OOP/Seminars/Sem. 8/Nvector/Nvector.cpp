#include "Nvector.h"
#include <iostream>
#define EPS 0.001
using namespace std;

void Nvector::free() {
    delete[] mVectorData;
}

void Nvector::copy(const Nvector &other) {
    mVectorLen = other.mVectorLen;
    mVectorData = new int[mVectorLen];
    for (size_t i = 0; i < mVectorLen; i++) {
        mVectorData[i] = other.mVectorData[i];
    }
}

Nvector::Nvector(size_t len) : mVectorLen(len) {
    mVectorData = new int[len];
    for (size_t i = 0; i < len; i++) {
        mVectorData[i] = 0;
    }
}

Nvector::Nvector(const Nvector &other) {
    copy(other);
}

Nvector &Nvector::operator=(const Nvector &other) {
    if (this == &other) {
        return *this;
    }
    free();
    copy(other);
    return *this;
}

Nvector::~Nvector() {
    free();
}

// v += v1;
Nvector &Nvector::operator+=(const Nvector &other) {
    if (mVectorLen != other.mVectorLen) {
        throw "Different vector lengths!\n";
    }
    for (size_t i = 0; i < mVectorLen; i++) {
        mVectorData[i] += other.mVectorData[i];
    }
    return *this;
}

Nvector &Nvector::operator-=(const Nvector &other) {
    if (mVectorLen != other.mVectorLen) {
        throw "Different vector lengths!\n";
    }
    for (size_t i = 0; i < mVectorLen; i++) {
        mVectorData[i] -= other.mVectorData[i];
    }
    return *this;
}

Nvector &Nvector::operator*=(const int scalar) {
    for (size_t i = 0; i < mVectorLen; i++) {
        mVectorData[i] *= scalar;
    }
    return *this;
}

int Nvector::operator[](const size_t index) const {
    if (index > mVectorLen) {
        throw "Out of the vector bounds!\n";
    }
    return mVectorData[index]; // returns a copy of the currElements
}

int &Nvector::operator[](const size_t index) {
    if (index > mVectorLen) {
        throw "Out of the vector bounds!\n";
    }
    return mVectorData[index]; // now we can do v[i] = 6; because we reterned a ref to that place
}

size_t Nvector::operator~() const {
    return mVectorLen;
}

std::ostream &operator<<(std::ostream &out, const Nvector &v) {
    out << "Vector length: " << v.mVectorLen << '\n';
    out << "[ ";
    for (size_t i = 0; i < v.mVectorLen; i++) {
        out << v[i] << ' ';
    }
    out << "]";
    return out;
}

std::istream &operator>>(std::istream &in, Nvector &v) {
    // cout << "Vector lenght: ";
    // in >> v.mVectorLen;

    cout << "Vector initialization: ";
    for (size_t i = 0; i < v.mVectorLen; i++) {
        in >> v[i];
    }
    return in;
}

const Nvector operator+(const Nvector &lhs, const Nvector &rhs) {
    Nvector lhsCopy(lhs); // copy constructor
    lhsCopy += rhs;       // lhsCopy.operator+=(rhs);
    return lhsCopy;
}

const Nvector operator-(const Nvector &lhs, const Nvector &rhs) {
    Nvector lhsCopy(lhs); // copy constructor
    lhsCopy -= rhs;       // lhsCopy.operator-=(rhs);
    return lhsCopy;
}

const Nvector operator*(const Nvector &lhs, const int scalar) {
    Nvector lhsCopy(lhs);
    lhsCopy *= scalar; // lhsCopy.operator*=(scalar);
    return lhsCopy;
}

const Nvector operator*(const int scalar, const Nvector &rhs) {
    return rhs * scalar; // operator*(rhs, scalar);
}

int operator%(const Nvector &lhs, const Nvector &rhs) {
    int scalarProduct = 0;
    if (~lhs != ~rhs) {
        throw "Different lengths!\n";
    }
    for (size_t i = 0; i < ~lhs; i++) {
        scalarProduct += (lhs[i] * rhs[i]);
    }
    return scalarProduct;
}

bool operator|=(const Nvector &lhs, const Nvector &rhs) {
    return lhs % rhs == 0;
}

bool operator||(const Nvector &lhs, const Nvector &rhs) {
    if (~lhs != ~rhs) {
        throw "Different lengths!\n";
    }

    double coeff = (double)lhs[0] / rhs[0];
    for (size_t i = 1; i < ~lhs; i++) {
        double currCoeff = (double)lhs[i] / rhs[i];
        if (abs(coeff - currCoeff) > EPS) {
            return false; // not parallel
        }
    }
    return true;
}