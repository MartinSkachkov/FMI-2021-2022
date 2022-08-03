#include <iostream>
using namespace std;

void copy(int* arr1, int* arr2, size_t cols) {
    for (size_t i = 0; i < cols; i++) {
        arr1[i] = arr2[i];
    }
}

void deleteRow(int** matrix, size_t k, size_t rows, size_t cols) {
    for (size_t i = k; i < rows - 1; i++) {
        copy(matrix[i], matrix[i + 1], cols);  // those are pointers;
    }
    matrix[rows - 1] = nullptr;
}

void print(int** matrix, size_t rows, size_t cols) {
    cout << "printing matrix\n";
    for (size_t i = 0; i < rows; i++) {
        for (size_t j = 0; j < cols; j++) {
            cout << matrix[i][j] << ' ';
        }
        cout << endl;  // print every row on new line
    }
    cout << endl;
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
    for (size_t i = 0; i < rows; i++) {
        matrix[i] = new int[cols];
        for (size_t j = 0; j < cols; j++) {
            cin >> matrix[i][j];
        }
    }

    size_t k;
    cout << "row to be deleted: ";
    cin >> k;

    print(matrix, rows, cols);
    deleteRow(matrix, k - 1, rows, cols);
    print(matrix, rows, cols);

    for (size_t i = 0; i < rows; i++) {
        delete[] matrix[i];
    }
    delete[] matrix;

    return 0;
}