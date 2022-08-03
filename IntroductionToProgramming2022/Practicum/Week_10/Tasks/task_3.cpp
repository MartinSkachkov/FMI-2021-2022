#include <iostream>
using namespace std;

bool hasDigitOne(int number) {  // passing a copy
    size_t rem = 0;             // rev = 0;
    while (number != 0) {
        rem = number % 10;
        if (rem == 1) {
            return true;
        }
        // rev = rev*10+rem;
        number /= 10;
    }
    return false;
}

int product(int** matrix, size_t n) {
    int product = 1;
    for (size_t i = 0; i < n; i++) {
        for (size_t j = 0; j < n; j++) {
            if (hasDigitOne(matrix[i][j]) && i > j) {
                product *= matrix[i][j];
            }
        }
    }
    return product;
}

void print(int** matrix, size_t n) {
    for (size_t i = 0; i < n; i++) {
        for (size_t j = 0; j < n; j++) {
            cout << matrix[i][j] << ' ';
        }
        cout << endl;  // print every row on new line
    }
    cout << endl;
}

int main() {
    size_t n;
    do {
        cout << "n: ";
        cin >> n;
    } while (n < 3 || n > 32);

    int** matrix = new int*[n];
    cout << "initialize matrix:\n";
    for (size_t rows = 0; rows < n; rows++) {
        matrix[rows] = new int[n];
        for (size_t cols = 0; cols < n; cols++) {
            cin >> matrix[rows][cols];
        }
    }

    cout << "product: " << product(matrix, n) << endl;
    print(matrix, n);

    for (size_t i = 0; i < n; i++) {
        delete[] matrix[i];
    }
    delete[] matrix;
    return 0;
}