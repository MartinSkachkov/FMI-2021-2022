#include <iostream>
using namespace std;

int productBelowSecondaryDia(int** matrix, size_t rows, size_t cols) {
    int product = 1;
    for (size_t i = 0; i < rows; i++) {
        for (size_t j = 0; j < cols; j++) {
            if ((i >= cols - 1 - j) && ((i + j) % 2 == 0)) {
                product *= matrix[i][j];
            }
        }
    }
    return product;
}

int main() {
    size_t rows, cols;
    do {
        cout << "rows: ";
        cin >> rows;
        cout << "cols: ";
        cin >> cols;
    } while ((rows <= 1 || rows > 16) && (cols <= 1 || cols > 32));

    int** matrix = new int*[rows];
    cout << "enter matrix:\n";
    for (size_t i = 0; i < rows; i++) {
        matrix[i] = new int[cols];
        for (size_t j = 0; j < cols; j++) {
            cin >> matrix[i][j];
        }
    }

    cout << "result: " << productBelowSecondaryDia(matrix, rows, cols);

    for (size_t i = 0; i < rows; i++) {
        delete[] matrix[i];
    }
    delete[] matrix;
    return 0;
}