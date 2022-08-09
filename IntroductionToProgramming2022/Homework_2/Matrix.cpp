#include <iostream>
using namespace std;

void free(int**, size_t);

void initialize(int** matrix, size_t rows, size_t cols) {
    for (size_t i = 0; i < rows; i++) {
        matrix[i] = new (nothrow) int[cols];
        if (!matrix[i]) {
            cout << "Couldn't allocate memory";
            return;
        }
        for (size_t j = 0; j < cols; j++) {
            cin >> matrix[i][j];
        }
    }
}

// we don't want to create a copy of the int** since we will make the copy to
// point to the newly allocated memory
void shiftRow(int**& A, size_t n1, size_t m1, size_t oldRowSize) {
    // creating a new matrix, where we copy the old elements with the new size
    int** newMatrix = new (nothrow) int*[n1];
    if (!newMatrix) {
        cout << "Couldn't allocate memory";
        return;
    }
    for (size_t i = 0; i < n1; i++) {
        newMatrix[i] = new (nothrow) int[m1];
        if (!newMatrix[i]) {
            cout << "Couldn't allocate memory";
            return;
        }
        for (size_t j = 0; j < m1; j++) {
            newMatrix[i][j] = A[i][j];
        }
    }
    // deleting the memory
    free(A, oldRowSize);
    // setting A to point to the new memory location
    A = newMatrix;
}

void shiftCol(int**& A, const size_t n1, const size_t m1) {
    int** newMatrix = new (nothrow) int*[n1];
    if (!newMatrix) {
        cout << "Couldn't allocate memory";
        return;
    }
    for (size_t i = 0; i < n1; i++) {
        newMatrix[i] = new (nothrow) int[m1];
        if (!newMatrix[i]) {
            cout << "Couldn't allocate memory";
            return;
        }
        for (size_t j = 0; j < m1; j++) {
            newMatrix[i][j] = A[i][j];
        }
    }
    free(A, n1);
    A = newMatrix;
}

// passing the matrix by refference since we want to make changes
void transformMatrix(int**& A, int** B, size_t& n1, size_t& m1, const size_t n2,
                     const size_t m2) {
    size_t oldRowSize = n1;
    // size_t oldColSize = m1;
    //  ако N2 < N1, то броят на редовете ѝ N1 се намалява на N2;
    if (n2 < n1) {
        n1 = n2;
        shiftRow(A, n1, m1, oldRowSize);
    }
    // ако M2 < M1, то броят на колоните ѝ M1 се намалява на M2;
    if (m2 < m1) {
        m1 = m2;
        shiftCol(A, n1, m1);
    }

    for (size_t i = 0; i < n1; i++) {
        for (size_t j = 0; j < m1; j++) {
            //ако A[i][j] = B[i][j], то A[i][j] не се променя;
            if (A[i][j] == B[i][j]) {
                continue;
            }
            //ако A[i][j] < B[i][j], то A[i][j] приема стойността на B[i][j];
            if (A[i][j] < B[i][j]) {
                A[i][j] = B[i][j];
            }
            //ако A[i][j] > B[i][j], то A[i][j] си сменя знака;
            if (A[i][j] > B[i][j]) {
                A[i][j] = -A[i][j];
            }
        }
    }
}

void print(int** matrix, size_t rows, size_t cols) {
    for (size_t i = 0; i < rows; i++) {
        for (size_t j = 0; j < cols; j++) {
            cout << matrix[i][j] << ' ';
        }
        cout << '\n';
    }
}

void free(int** matrix, size_t rows) {
    for (size_t i = 0; i < rows; i++) {
        delete[] matrix[i];
    }
    delete[] matrix;
}

int main() {
    size_t n1, m1, n2, m2;

    cout << "n1: ";
    cin >> n1;
    cout << "m1: ";
    cin >> m1;

    cout << "A:\n";
    int** A = new int*[n1];
    if (!A) {
        cout << "Couldn't allocate memory";
        return -1;
    }
    initialize(A, n1, m1);

    cout << "n2: ";
    cin >> n2;
    cout << "m2: ";
    cin >> m2;

    cout << "B:\n";
    int** B = new int*[n2];
    if (!B) {
        cout << "Couldn't allocate memory";
        return -1;
    }
    initialize(B, n2, m2);

    transformMatrix(A, B, n1, m1, n2, m2);

    cout << "result:\n";
    print(A, n1, m1);
    // print(B, n2, m2);

    free(A, n1);
    free(B, n2);
    return 0;
}