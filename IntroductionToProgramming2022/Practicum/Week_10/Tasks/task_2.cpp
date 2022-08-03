#include <iostream>
using namespace std;

bool isPrime(const int number) {
    if (number <= 1) {
        return false;
    }
    for (int i = 2; i <= number / 2; i++) {
        if (number % i == 0) {
            return false;
        }
    }
    return true;
}

size_t counter(int** matrix, size_t n) {
    size_t counter = 0;
    cout << "primes in matrix:\n";
    for (size_t i = 0; i < n; i++) {
        for (size_t j = 0; j < n; j++) {
            if (isPrime(matrix[i][j]) && i <= j) {
                cout << matrix[i][j] << ' ';
                counter++;
            }
        }
    }
    cout << endl << "counter: ";
    return counter;
}

void initialize(int** matrix, size_t n) {
    cout << "initialize matrix:\n";
    for (size_t rows = 0; rows < n; rows++) {
        for (size_t cols = 0; cols < n; cols++) {
            cin >> matrix[rows][cols];
        }
    }
    cout << endl;
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

void free(int** matrix, size_t n) {
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
    } while (n < 3 || n > 32);

    int** matrix = new int*[n];
    for (size_t i = 0; i < n; i++) {
        matrix[i] = new int[n];
    }

    initialize(matrix, n);
    print(matrix, n);
    cout << "number of prime elements above the main diagonal(including it):\n"
         << counter(matrix, n);
    free(matrix, n);
    return 0;
}