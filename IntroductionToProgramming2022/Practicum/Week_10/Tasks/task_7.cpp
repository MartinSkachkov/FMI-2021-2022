#include <iostream>
using namespace std;

double mainDiagSum(double** matrix, size_t n) {
    double sum = 0;
    for (size_t i = 0; i < n; i++) {
        for (size_t j = 0; j < n; j++) {
            if (i > j) {
                sum += matrix[i][j];
            }
        }
    }
    return sum;
}

int main() {
    size_t n;
    do {
        cout << "n: ";
        cin >> n;
    } while (n < 1 || n > 100);

    double** matrix = new double*[n];
    cout << "enter matrix:\n";
    for (size_t i = 0; i < n; i++) {
        matrix[i] = new double[n];
        for (size_t j = 0; j < n; j++) {
            cin >> matrix[i][j];
        }
    }

    cout << "sum of elements from main diagonal: " << mainDiagSum(matrix, n);

    for (size_t i = 0; i < n; i++) {
        delete[] matrix[i];
    }
    delete[] matrix;

    return 0;
}