#include <iostream>
using namespace std;

void initialize(double** matrix, size_t n) {
    for (size_t i = 0; i < n; i++) {
        matrix[i] = new double[n];
        for (size_t j = 0; j < n; j++) {
            cin >> matrix[i][j];
        }
    }
    cout << endl;
}

void multiplication(double** A, double** B, double** result, size_t n) {
    double sum = 0;
    for (size_t i = 0; i < n; i++) {
        for (size_t j = 0; j < n; j++) {
            sum = 0;
            for (size_t k = 0; k < n; k++) {
                sum += A[i][k] * B[k][j];
            }
            result[i][j] = sum;
        }
    }
}

void print(double** matrix, size_t n) {
    for (size_t i = 0; i < n; i++) {
        for (size_t j = 0; j < n; j++) {
            cout << matrix[i][j] << ' ';
        }
        cout << endl;
    }
    cout << endl;
}

void free(double** matrix, size_t n) {
    for (size_t i = 0; i < n; i++) {
        delete[] matrix[i];
    }
    delete[] matrix;
}

int main() {
    size_t n;
    do {
        cout << "n: ";
        cin >> n;
    } while (n <= 0 || n >= 100);

    double** A = new double*[n];
    cout << "Matrix A:\n";
    initialize(A, n);
    print(A, n);

    double** B = new double*[n];
    cout << "Matrix B:\n";
    initialize(B, n);
    print(B, n);

    double** result = new double*[n];
    for (size_t i = 0; i < n; i++) {
        result[i] = new double[n];
    }

    multiplication(A, B, result, n);
    print(result, n);

    free(A, n);
    free(B, n);
    free(result, n);
    return 0;
}