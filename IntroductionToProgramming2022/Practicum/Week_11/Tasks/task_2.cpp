#include <iostream>
using namespace std;

void initialize(int** matrix, size_t rows, size_t cols) {
    for (size_t i = 0; i < rows; i++) {
        matrix[i] = new int[cols];
        for (size_t j = 0; j < cols; j++) {
            cin >> matrix[i][j];
        }
    }
}

void multiplication(int** A, size_t n, size_t m, int** B, size_t k,
                    int** result) {
    for (size_t i = 0; i < n; i++) {
        for (size_t j = 0; j < k; j++) {
            for (size_t f = 0; f < m; f++) {
                result[i][j] += A[i][f] * B[f][j];
            }
        }
    }
}

void print(int** matrix, size_t rows, size_t cols) {
    cout << "matrix:\n";
    for (size_t i = 0; i < rows; i++) {
        for (size_t j = 0; j < cols; j++) {
            cout << matrix[i][j] << ' ';
        }
        cout << endl;
    }
    cout << endl;
}

void free(int** matrix, size_t rows, size_t cols) {
    for (size_t i = 0; i < rows; i++) {
        delete[] matrix[i];
    }
    delete[] matrix;
}

int main() {
    size_t m, n, k;
    do {
        cout << "n: ";
        cin >> n;
        cout << "m: ";
        cin >> m;
        cout << "k: ";
        cin >> k;
    } while ((n < 1 || n > 20) || (m < 1 || m > 30) || (k < 1 || m > 40));

    // Anxm и Bmxk
    int** A = new int*[n];
    cout << "matrix A:\n";
    initialize(A, n, m);

    int** B = new int*[m];
    cout << "matrix B:\n";
    initialize(B, m, k);

    int** result = new int*[n];
    for (size_t i = 0; i < n; i++) {
        result[i] = new int[k];
        for (size_t j = 0; j < k; j++) {
            result[i][j] = 0;
        }
    }

    multiplication(A, n, m, B, k, result);
    print(result, n, k);

    free(A, n, m);
    free(B, m, k);
    free(result, n, k);
    return 0;
}