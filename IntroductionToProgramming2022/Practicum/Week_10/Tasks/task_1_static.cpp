#include <iostream>
using namespace std;

bool isEven(const int num) {
    if (num % 2 == 0) {
        return true;
    }
    return false;
}

int sumOfEvenElements(int matrix[3][3]) {
    size_t sum = 0;
    for (size_t rows = 0; rows < 3; rows++) {
        for (size_t cols = 0; cols < 3; cols++) {
            if (isEven(matrix[rows][cols])) {
                sum += matrix[rows][cols];
            }
        }
    }
    return sum;
}

int main() {
    int matrix[3][3];  // statically allocated
    cout << "enter matrix elements:\n";
    for (size_t rows = 0; rows < 3; rows++) {
        for (size_t cols = 0; cols < 3; cols++) {
            cin >> matrix[rows][cols];
        }
    }
    cout << "sum of even elements in the matrix is: "
         << sumOfEvenElements(matrix);
    return 0;
}