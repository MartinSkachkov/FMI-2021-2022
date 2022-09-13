#ifndef _MATRIX_H_
#define _MATRIX_H_
#include <cstddef>

class Matrix {
private:
    int **mMatrix;
    size_t mSize;

    int **allocateMatrixMem(const size_t size) const;
    void copy(const Matrix &other);
    void copyVal(int **other);
    void free();

public:
    // Big 4
    Matrix();
    Matrix(size_t size, int **matrix);
    Matrix(const Matrix &other);
    Matrix &operator=(const Matrix &other);
    ~Matrix();

    // getters
    int **getMatrix() { return mMatrix; } // returns a copy of the pointer
    size_t getSize() { return mSize; }    // returns a copu of the size

    void print() const;
    int getAt(size_t i, size_t j) const;
    Matrix add(const Matrix& B);
};

#endif