#include <iostream>
using namespace std;

void initialize(int** matrix, size_t n) {
    cout << "matrix initialization: " << n << 'x' << n << endl;
    for (size_t rows = 0; rows < n; rows++) {
        matrix[rows] = new int[n];
        for (size_t cols = 0; cols < n; cols++) {
            cin >> matrix[rows][cols];
        }
    }
}

bool isEven(const int element) {
    if (element % 2 == 0) {
        return true;
    }
    return false;
}

/*bool even(int n) {
        return !(n % 2); cooler way :)
}
*/

int sumOfEvenElements(int** matrix, size_t n) {
    size_t sum = 0;
    for (size_t i = 0; i < n; i++) {
        for (size_t j = 0; j < n; j++) {
            if (isEven(matrix[i][j])) {
                sum += matrix[i][j];
            }
        }
    }
    return sum;
}

void free(int** matrix, size_t n) {
    for (size_t i = 0; i < n; i++) {
        delete[] matrix[i]; //deleting the inner arrays
    }
    delete[] matrix; //deleting the whole array of pointers
}

int main() {
    // NxN
    size_t n;
    cout << "n: ";
    cin >> n;
    int** matrix = new int*[n];

    initialize(matrix, n);
    cout << "result: " << sumOfEvenElements(matrix, n);
    free(matrix, n);
    return 0;
}