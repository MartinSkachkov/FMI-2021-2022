#ifndef _NVECTOR_H_
#define _NVECTOR_H_
#include <cstdlib>
#include <fstream>

class Nvector {
private:
    int *mVectorData;
    size_t mVectorLen;

    void free();
    void copy(const Nvector &other);

public:
    Nvector(size_t len = 1);
    Nvector(const Nvector &other);
    Nvector &operator=(const Nvector &other);
    ~Nvector();

    // member funcs
    Nvector &operator+=(const Nvector &other);
    Nvector &operator-=(const Nvector &other);
    Nvector &operator*=(const int scalar);
    int operator[](const size_t index) const; // we return a copy (read-only) of mVectorData[i] (by value)
    int &operator[](const size_t index);      // we return a ref (read-n-write) so that we can change the value of mVectorData[i]
    size_t operator~() const;                 // getter of the length (unary)

    friend std::ostream &operator<<(std::ostream &out, const Nvector &v);
    friend std::istream &operator>>(std::istream &in, Nvector &v);
};

// global funcs - we don't have the this ptr
const Nvector operator+(const Nvector &lhs, const Nvector &rhs);
const Nvector operator-(const Nvector &lhs, const Nvector &rhs);
const Nvector operator*(const Nvector &lhs, const int scalar);
const Nvector operator*(const int scalar, const Nvector &rhs);

int operator%(const Nvector &lhs, const Nvector &rhs); // scalar product
bool operator|=(const Nvector &lhs, const Nvector &rhs);
bool operator||(const Nvector &lhs, const Nvector &rhs);
#endif