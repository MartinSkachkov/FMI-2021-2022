#include <iostream>
using namespace std;

bool pred(int number) { return (number % 2 == 0) && (number < 6); }

size_t countElements(int* numbers, size_t size) {
    size_t counter = 0;
    for (size_t i = 0; i < size; i++) {
        if (pred(numbers[i])) {
            counter++;
        }
    }
    return counter;
}

size_t getMax(int** matrix, size_t row) {
    size_t maxRowIndex = 0;
    int maxCountOfElem = INT16_MIN;
    for (size_t i = 0; i < row; i++) {
        int countOfElements = countElements(matrix[i], row);
        if (countOfElements > maxCountOfElem) {
            maxCountOfElem = countOfElements;
            maxRowIndex = i;
        }
    }
    return maxRowIndex;
}

int** transposeMatrix(int** matrix, size_t m, size_t n) {
    int** transposed = new int*[m];
    for (size_t i = 0; i < m; i++) {
        transposed[i] = new int[n];
        for (size_t j = 0; j < n; j++) {
            transposed[i][j] = matrix[j][i];
        }
    }
    return transposed;
}

int getSum(int** matrix, size_t n, size_t m) {
    size_t maxRowIndex = getMax(matrix, n);
    int** transposed = transposeMatrix(matrix, m, n);
    size_t maxColIndex = getMax(transposed, m);

    for (size_t i = 0; i < m; i++) {
        delete[] transposed[i];
    }
    delete[] transposed;

    int sum = 0;
    for (size_t i = 0; i < m; i++) {
        sum += matrix[maxRowIndex][m];
    }
    for (size_t i = 0; i < n; i++) {
        sum += matrix[i][maxColIndex];
    }
    return sum;
}

int main() {
    size_t rows, cols;
    cout << "rows: ";
    cin >> rows;
    cout << "cols: ";
    cin >> cols;

    cout << "matrix;\n";
    int** matrix = new int*[rows];
    for (size_t i = 0; i < rows; i++) {
        matrix[i] = new int[cols];
        for (size_t j = 0; j < cols; j++) {
            cin >> matrix[i][j];
        }
    }

    cout << "sum: " << getSum(matrix, rows, cols);

    for (size_t i = 0; i < rows; i++) {
        delete[] matrix[i];
    }
    delete[] matrix;

    return 0;
}