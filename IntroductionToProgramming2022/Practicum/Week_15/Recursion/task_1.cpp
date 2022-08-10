#include <iostream>
using namespace std;

/*void resetToZero(bool** visited, size_t n) {
    for (size_t i = 0; i < n; i++) {
        for (size_t j = 0; j < n; j++) {
            visited[i][j] = 0;
        }
    }
}*/

size_t areaSize(bool** matrix, bool** visited, size_t x, size_t y, size_t n) {
    // base case
    if (x < 0 || x > n - 1 || y < 0 || y > n - 1 || matrix[x][y] == 0 ||
        visited[x][y] == 1) {
        return 0;
    }

    visited[x][y] = 1;
    return 1 + areaSize(matrix, visited, x - 1, y - 1, n) +
           areaSize(matrix, visited, x - 1, y, n) +
           areaSize(matrix, visited, x, y - 1, n) +
           areaSize(matrix, visited, x + 1, y + 1, n) +
           areaSize(matrix, visited, x + 1, y, n) +
           areaSize(matrix, visited, x, y + 1, n) +
           areaSize(matrix, visited, x + 1, y - 1, n) +
           areaSize(matrix, visited, x - 1, y + 1, n);
}

size_t countAreas(bool** matrix, bool** visited, size_t n) {
    size_t ctr = 0;
    for (size_t i = 0; i < n; i++) {
        for (size_t j = 0; j < n; j++) {
            if (matrix[i][j] == 1 && visited[i][j] == 0) {
                ctr++;
                cout << '\n'
                     << "area " << ctr << " has size of "
                     << areaSize(matrix, visited, i, j, n);
            }
        }
    }
    return ctr;
}

void free(bool**& matrix, size_t n) {
    for (size_t i = 0; i < n; i++) {
        delete[] matrix[i];
    }
    delete[] matrix;
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

    bool** visited = new bool*[n];
    for (size_t i = 0; i < n; i++) {
        visited[i] = new bool[n];
        for (size_t j = 0; j < n; j++) {
            visited[i][j] = 0;
        }
    }

    cout << '\n'
         << "whole number of areas is: " << countAreas(matrix, visited, n);

    free(matrix, n);
    free(visited, n);
    return 0;
}