#include <iostream>
using namespace std;

//        cols   
// rows  1 2 3
//       4 5 6
//       7 8 9

void belowTheDiagonal(int** matrix, size_t n) {
    cout << "printing above the diagonal:\n";
    for (size_t rows = 0; rows < n; rows++) {
        for (size_t cols = 0; cols < n; cols++) {
            if (rows >= cols) {  // including the diagonal(if we want ot exclude
                cout << matrix[rows][cols] << ' ';  // it remove the '=')
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

    belowTheDiagonal(matrix, n);

    for (size_t i = 0; i < n; i++) {
        delete[] matrix[i];
    }
    delete[] matrix;

    return 0;
}