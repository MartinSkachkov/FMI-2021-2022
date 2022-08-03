#include <iostream>
using namespace std;

bool isPrime(const int& num) {
    if (num <= 1) {
        return false;
    }
    for (size_t i = 2; i <= (size_t)num / 2; i++) {
        if (num % i == 0) {
            return false;
        }
    }
    return true;
}

// bad name xD
size_t numberOfPrimeElAboveSecondaryDiag(int** matrix, size_t n) {
    size_t counter = 0;
    cout << "prime elements:\n";
    for (size_t i = 0; i < n; i++) {
        for (size_t j = 0; j < n; j++) {
            if ((i <= n - 1 - j) && isPrime(matrix[i][j])) {
                counter++;
                cout << matrix[i][j] << ' ';
            }
        }
    }
    cout << endl << "number of prime elements above the secondary diagonal:\n";
    return counter;
}

int main() {
    size_t n;
    do {
        cout << "n: ";
        cin >> n;

    } while (n < 1 || n > 100);

    int** matrix = new int*[n];
    cout << "enter matrix:\n";
    for (size_t i = 0; i < n; i++) {
        matrix[i] = new int[n];
        for (size_t j = 0; j < n; j++) {
            cin >> matrix[i][j];
        }
    }

    cout << numberOfPrimeElAboveSecondaryDiag(matrix, n);

    for (size_t i = 0; i < n; i++) {
        delete[] matrix[i];
    }
    delete[] matrix;

    return 0;
}