#include <iostream>
using namespace std;

int maxRow(int** matrix, size_t n) {
    int max = INT_MIN, sum = 0;
    for (size_t rows = 0; rows < n; rows++) {
        sum = 0;
        for (size_t cols = 0; cols < n; cols++) {
            sum += matrix[rows][cols];
        }
        if (sum > max) {
            max = sum;
        }
    }
    return max;
}

int maxCol(int** matrix, size_t n) {
    int max = INT_MIN, sum = 0;
    for (size_t cols = 0; cols < n; cols++) {
        sum = 0;
        for (size_t rows = 0; rows < n; rows++) {
            sum += matrix[rows][cols];
        }
        if (sum > max) {
            max = sum;
        }
    }
    return max;
}

int main() {
    size_t n;
    do {
        cout << "n: ";
        cin >> n;
    } while (n < 3 || n > 32);

    int** matrix = new int*[n];
    cout << "enter matrix:\n";
    for (size_t i = 0; i < n; i++) {
        matrix[i] = new int[n];
        for (size_t j = 0; j < n; j++) {
            cin >> matrix[i][j];
        }
    }

    cout << "max row: " << maxRow(matrix, n) << endl;
    cout << "max col: " << maxCol(matrix, n) << endl;

    for (size_t i = 0; i < n; i++) {
        delete[] matrix[i];
    }
    delete[] matrix;
    return 0;
}