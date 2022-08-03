#include <iostream>
using namespace std;

void aboveTheSecondaryDia(int** matrix, size_t n) {
    for (size_t i = 0; i < n; i++) {
        for (size_t j = 0; j < n; j++) {
            if (i <= n - 1 - j) {
                cout << matrix[i][j] << ' ';
            }
        }
        cout << endl;
    }
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

    aboveTheSecondaryDia(matrix, n);

    for (size_t i = 0; i < n; i++)  // rows
    {
        delete[] matrix[i];
    }
    delete[] matrix;

    return 0;
}