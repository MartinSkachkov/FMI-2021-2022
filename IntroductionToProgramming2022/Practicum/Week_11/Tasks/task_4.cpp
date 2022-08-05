#include <iostream>
using namespace std;

bool isMagicalMatrix(int** matrix, size_t n) {
    size_t sumMainD = 0, sumSecondD = 0;
    for (size_t i = 0; i < n; i++) {
        sumMainD += matrix[i][i];
        sumSecondD += matrix[i][n - 1 - i];
    }

    if (sumMainD != sumSecondD) {
        return false;
    }

    size_t sumRow = 0, sumCol = 0;
    for (size_t i = 0; i < n; i++) {
        sumRow = 0, sumCol = 0;
        for (size_t j = 0; j < n; j++) {
            sumRow += matrix[i][j];
            sumCol += matrix[j][i];
        }
        if (sumRow != sumCol || sumCol != sumMainD) {
            return false;
        }
    }
    return true;
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

    cout << "Is magical matrix? " << boolalpha << isMagicalMatrix(matrix, n)
         << endl;

    for (size_t i = 0; i < n; i++) {
        delete[] matrix[i];
    }
    delete[] matrix;

    return 0;
}