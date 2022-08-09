#include <iostream>
using namespace std;

size_t sumDigits(int num) {
    size_t counter = 0;
    while (num != 0) {
        if ((num % 10) % 2 == 1) {
            counter++;
        }
        num /= 10;
    }
    return counter;
}

void BubbleSort(int* rows, const size_t n) {
    for (size_t i = 0; i < n - 1; i++) {
        for (size_t j = 0; j < n - 1 - i; j++) {
            // if the sum of the digits of the curr number is bigger than the
            // next then swap the real numbers
            if (sumDigits(rows[j]) > sumDigits(rows[j + 1])) {
                swap(rows[j], rows[j + 1]);
            }
        }
    }
}

void sortRows(int** matrix, const size_t n) {
    for (size_t i = 0; i < n; i++) {
        BubbleSort(matrix[i], n);
    }
}

void print(int** matrix, const size_t n) {
    for (size_t i = 0; i < n; i++) {
        for (size_t j = 0; j < n; j++) {
            cout << matrix[i][j] << ' ';
        }
        cout << '\n';
    }
}

int main() {
    size_t n;
    do {
        cout << "n: ";
        cin >> n;
    } while (n < 2 || n > 20);

    cout << "enter matrix:\n";
    int** matrix = new (nothrow) int*[n];
    if (!matrix) {
        cout << "couldn't allocate memory";
        return -1;
    }
    for (size_t i = 0; i < n; i++) {
        matrix[i] = new (nothrow) int[n];
        if (!matrix[i]) {
            cout << "couldn't allocate memory";
            return -1;
        }
        for (size_t j = 0; j < n; j++) {
            cin >> matrix[i][j];
        }
    }

    cout << "before sorting:\n";
    print(matrix, n);

    sortRows(matrix, n);

    cout << "after sorting:\n";
    print(matrix, n);

    for (size_t i = 0; i < n; i++) {
        delete[] matrix[i];
    }
    delete[] matrix;
    return 0;
}