#include <iostream>
using namespace std;

//ако матриците бяха nxm, тогава тази, в която ще пишем резултата щеше да е mxn
//иначе просто заменяме n с rows и cols на правилните места

void transpose(int** matrix, int** transposed, size_t n) {
    for (size_t i = 0; i < n; i++) {
        for (size_t j = 0; j < n; j++) {
            transposed[j][i] = matrix[i][j];
        }
    }
}

void print(int** matrix, size_t n) {
    for (size_t i = 0; i < n; i++) {
        for (size_t j = 0; j < n; j++) {
            cout << matrix[i][j] << ' ';
        }
        cout << endl;
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
    cout << "enter matrix:\n";
    for (size_t i = 0; i < n; i++) {
        matrix[i] = new int[n];
        for (size_t j = 0; j < n; j++) {
            cin >> matrix[i][j];
        }
    }

    int** transposed = new int*[n];
    for (size_t i = 0; i < n; i++) {
        transposed[i] = new int[n];
    }

    transpose(matrix, transposed, n);
    cout << "transposed:\n";
    print(transposed, n);

    free(matrix, n);
    free(transposed, n);
    return 0;
}
