#include "Matrix.h"
#include <iostream>
using namespace std;

int main() {
    Matrix def;
    def.print();
    cout << endl;

    int **matrix_1 = new int *[3];
    int **matrix_2 = new int *[3];
    for (size_t i = 0; i < 3; i++) {
        matrix_1[i] = new int[3];
        matrix_2[i] = new int[3];
        for (size_t j = 0; j < 3; j++) {
            cin >> matrix_1[i][j];
            cin >> matrix_2[i][j];
        }
    }

    Matrix matrix1(3, matrix_1);
    Matrix matrix2(3, matrix_2);

    def = matrix1.add(matrix2);
    def.print();

    return 0;
}