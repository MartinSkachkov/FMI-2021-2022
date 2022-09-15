#include "Matrix.h"
#include <iostream>
using namespace std;

int **Matrix::allocateMatrixMem(const size_t size) const {
    int **matrix = new int *[size];
    for (size_t i = 0; i < size; i++) {
        matrix[i] = new int[size];
        for (size_t j = 0; j < size; j++) {
            matrix[i][j] = 0;
        }
    }
    return matrix;
}

void Matrix::copyVal(int **other) {
    for (size_t i = 0; i < mSize; i++) {
        for (size_t j = 0; j < mSize; j++) {
            mMatrix[i][j] = other[i][j];
        }
    }
}

void Matrix::copy(const Matrix &rhs) {
    mSize = rhs.mSize;
    mMatrix = allocateMatrixMem(mSize);
    copyVal(rhs.mMatrix);
}

void Matrix::free() {
    for (size_t i = 0; i < mSize; i++) {
        delete[] mMatrix[i];
    }
    delete[] mMatrix;
}

Matrix::Matrix() : mSize(3) {
    mMatrix = allocateMatrixMem(mSize);
}

Matrix::Matrix(size_t size, int **matrix) : mSize(size) {
    mMatrix = allocateMatrixMem(mSize);
    copyVal(matrix);
}

Matrix::Matrix(const Matrix &other) {
    copy(other);
}

Matrix &Matrix::operator=(const Matrix &other) {
    if (this == &other) {
        return *this;
    }
    free();
    copy(other);
    return *this;
}

Matrix::~Matrix() {
    free();
}

void Matrix::print() const {
    cout << "Matrix size: " << mSize << '\n';
    for (size_t i = 0; i < mSize; i++) {
        for (size_t j = 0; j < mSize; j++) {
            cout << mMatrix[i][j] << ' ';
        }
        cout << '\n';
    }
}

int Matrix::getAt(size_t i, size_t j) const {
    if ((i < 0 || i >= mSize) || (j < 0 || j >= mSize)) {
        throw "Out of bounds!";
    } else {
        // cout << "Element in position (" << i << ") (" << j << ") : " << mMatrix[i][j];
        return mMatrix[i][j];
    }
}

Matrix Matrix::add(const Matrix &B) {
    if (mSize != B.mSize) {
        throw "Incompatible sizes!";
    }

    size_t sumSize = mSize;
    int **sumMatrix = new int *[sumSize];
    for (size_t i = 0; i < sumSize; i++) {
        sumMatrix[i] = new int[sumSize];
        for (size_t j = 0; j < sumSize; j++) {
            sumMatrix[i][j] = mMatrix[i][j] + B.mMatrix[i][j];
        }
    }

    Matrix newMatrix(sumSize, sumMatrix);
    return newMatrix;
}