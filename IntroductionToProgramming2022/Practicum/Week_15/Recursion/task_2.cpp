#include <iostream>
using namespace std;

bool hasPath(bool** matrix, size_t i, size_t j, size_t n, size_t p) {
    if (p == 1) {
        return matrix[i][j] == 1;
    }

    int k = -1;
    bool foundPath = false;
    do {
        k++;
        if (matrix[i][k] == 1) {
            matrix[i][k] = matrix[k][i] = 0;
            foundPath = hasPath(matrix, k, j, n, p - 1);
            matrix[i][k] = matrix[k][i] = 1;
        }
    } while (!foundPath && k <= n - 2);
    return foundPath;
}

int main() {
    size_t n;
    cout << "n: ";
    cin >> n;

    cout << "matrix:\n";
    bool** matrix = new bool*[n];
    for (size_t i = 0; i < n; i++) {
        matrix[i] = new bool[n];
        for (size_t j = 0; j < n; j++) {
            cin >> matrix[i][j];
        }
    }

    size_t i, j, p;
    cout << "i: ";
    cin >> i;
    cout << "j: ";
    cin >> j;
    cout << "p: ";
    cin >> p;

    cout << "Has a path from " << i << " to " << j << boolalpha << ' '
         << hasPath(matrix, i, j, n, p);

    for (size_t i = 0; i < n; i++) {
        delete[] matrix[i];
    }
    delete[] matrix;
    return 0;
}