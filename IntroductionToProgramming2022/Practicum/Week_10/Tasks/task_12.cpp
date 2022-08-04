#include <iostream>
using namespace std;

// this task can be made with one variable instead of rows and cols but i was
// training sth...
// http://teknicalprog.blogspot.com/2014/06/c-program-to-find-nth-power-of-matrix.html

void copy(int** matrix, int** matrix2, size_t rows, size_t cols) {
    for (size_t i = 0; i < rows; i++) {
        for (size_t j = 0; j < rows; j++) {
            matrix2[i][j] = matrix[i][j];
        }
    }
}

void power(int** matrix, int** matrix2, int** result, size_t rows,
           size_t cols) {  // passing a copy

    for (size_t i = 0; i < rows; i++) {
        for (size_t j = 0; j < rows; j++) {
            for (size_t k = 0; k < rows; k++) {
                result[i][j] += matrix2[i][k] * matrix[k][j];
            }
        }
    }
}

void print(int** matrix, size_t rows, size_t cols) {
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

    int** matrix2 = new int*[rows];
    for (size_t i = 0; i < rows; i++) {
        matrix2[i] = new int[cols];
    }
    copy(matrix, matrix2, rows, cols);

    size_t pow;
    cout << "pow: ";
    cin >> pow;

    int** result = new int*[rows];
    for (size_t i = 0; i < rows; i++) {
        result[i] = new int[cols];
        for (size_t j = 0; j < cols; j++) {
            result[i][j] = 0;
        }
    }
    if (pow == 0) {
        cout << "identitet" << endl;
    } else if (pow == 1) {
        print(matrix, rows, cols);
    } else {
        for (size_t i = 0; i < pow - 1; i++) {
            power(matrix, matrix2, result, rows, cols);
            copy(result, matrix2, rows, cols);
        }
    }

    cout << "result\n";
    print(result, rows, cols);

    free(matrix, rows, cols);
    free(result, rows, cols);
    free(matrix2, rows, cols);
    return 0;
}