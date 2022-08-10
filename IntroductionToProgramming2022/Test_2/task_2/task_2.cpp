#include <iostream>
using namespace std;

bool hasDuplicateDigits(int num) {
    int repeating[10] = {0};
    while (num != 0) {
        if (repeating[num % 10] == 1) {
            return true;
        } else {
            repeating[num % 10] = 1;
        }
        num /= 10;
    }
    return false;
}

void countOfDuplicateDigitsNums(int** matrix, size_t n, size_t& size) {
    for (size_t i = 0; i < n; i++) {
        for (size_t j = 0; j < n; j++) {
            if (hasDuplicateDigits(matrix[i][j])) {
                size++;
            }
        }
    }
}

int* collect(int** matrix, size_t n, size_t& size) {
    size_t iterator = 0;
    // this function will update the size
    countOfDuplicateDigitsNums(matrix, n, size);
    int* result = new (nothrow) int[size];
    if (!result) {
        throw runtime_error("Couldn't allocate memory!");
    }

    for (size_t i = n - 1; i > 0; i--) {
        for (size_t j = 0, x = i; x <= n - 1; x++, j++) {
            if (hasDuplicateDigits(matrix[x][j])) {
                result[iterator++] = matrix[x][j];
            }
        }
    }

    for (size_t i = 0; i <= n - 1; i++) {
        for (size_t j = 0, x = i; x <= n - 1; j++, x++) {
            if (hasDuplicateDigits(matrix[j][x])) {
                result[iterator++] = matrix[j][x];
            }
        }
    }
    return result;
}

int main() {
    size_t n;
    do {
        cout << "n: ";
        cin >> n;
    } while (n < 1 || n > 30);

    // allocate memory and initialize the matrix
    cout << "matrix:\n";
    int** matrix = new (nothrow) int*[n];
    if (!matrix) {
        cout << "Couldn't allocate memory!";
        return -1;
    }
    for (size_t i = 0; i < n; i++) {
        matrix[i] = new (nothrow) int[n];
        if (!matrix[i]) {
            cout << "Couldn't allocate memory!";
            return -1;
        }
        for (size_t j = 0; j < n; j++) {
            cin >> matrix[i][j];
        }
    }

    size_t size = 0;  // this variable will keep track of the added elements
    int* result = collect(matrix, n, size);

    // printing the result
    cout << "extracted numbers with duplicating digits in the matrix:\n";
    for (size_t i = 0; i < size; i++) {
        cout << result[i] << ' ';
    }

    // freeing memory
    for (size_t i = 0; i < n; i++) {
        delete[] matrix[i];
    }
    delete[] matrix;
    delete[] result;
    return 0;
}