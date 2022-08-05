#include <iostream>
using namespace std;

bool isUpperTriangular(int** matrix, size_t n) {
    for (size_t i = 0; i < n; i++) {
        for (size_t j = 0; j < n; j++) {
            if ((i < j && matrix[i][j] != 0)) {
                return false;
            }
        }
    }
    return true;
}

bool isLowerTriangular(int** matrix, size_t n) {
    for (size_t i = 0; i < n; i++) {
        for (size_t j = 0; j < n; j++) {
            if ((i > j && matrix[i][j] != 0)) {
                return false;
            }
        }
    }
    return true;
}

// another way
/* for (int i = 1; i < N; i++)
        for (int j = 0; j < i; j++)
            if (mat[i][j] != 0)
                return false;
    return true;*/

bool isTriangular(int** matrix, size_t n) {
    for (size_t i = 0; i < n; i++) {
        for (size_t j = 0; j < n; j++) {
            if (isLowerTriangular(matrix, n) || isUpperTriangular(matrix, n)) {
                return true;
            }
        }
    }
    return false;
}

int main() {
    size_t n;
    do {
        cout << "n: ";
        cin >> n;
    } while (n < 1 || n > 20);

    int** matrix = new int*[n];
    cout << "matrix:\n";
    for (size_t i = 0; i < n; i++) {
        matrix[i] = new int[n];
        for (size_t j = 0; j < n; j++) {
            cin >> matrix[i][j];
        }
    }

    cout << "Is triangular? " << boolalpha << isTriangular(matrix, n);

    for (size_t i = 0; i < n; i++) {
        delete[] matrix[i];
    }
    delete[] matrix;

    return 0;
}