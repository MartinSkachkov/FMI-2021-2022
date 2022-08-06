#include <iostream>
using namespace std;

size_t factoriel(size_t n) {
    if (n == 1) {
        return 1;
    }
    return n * factoriel(n - 1);
}

int strlen(const char* str) {
    if (str[0] == 0) {
        return 0;
    }
    return 1 + strlen(str + 1);
}

bool arpr(int* arr, int n, int i) {
    if (i > n) {  // i >= n-1
        return true;
    }
    return *(arr + i) <= *(arr + i + 1) && arpr(arr, n, i + 1);
}

size_t digitSumInStr(const char* str) {
    if (str[0] == 0) {
        return 0;
    }
    if (str[0] >= '0' && str[0] <= '9') {
        return str[0] - '0' + digitSumInStr(str + 1);
    }
    return digitSumInStr(str + 1);  // if it is a char than just move the
                                    // pointer
}

int count(char** matrix, int n, int i, int m, int j) {
    if (i >= n || j >= m) {  // i == 4, j == 4
        return 0;
    }

    if (matrix[i][j] == 'S') {
        // 1 + 1 + 0 -> 2
        return 1 + count(matrix, n, i + 1, m, j + 1);
    }

    return count(matrix, n, i + 1, m, j + 1);
}

int countS(char** matrix, int n, int m) { return count(matrix, n, 0, m, 0); }

int main() {
    size_t n;
    cout << "n: ";
    cin >> n;
    cout << "factorial: " << factoriel(n) << endl;

    const char* arr = "hello";
    cout << "string length: " << strlen(arr) << endl;

    int arr1[5] = {3, 2, 3, 4, 5};
    cout << boolalpha << arpr(arr1, 5, 0) << endl;      // F
    cout << boolalpha << arpr(arr1 + 1, 4, 0) << endl;  // T
    cout << boolalpha << arpr(arr1, 5, 1) << endl;      // T

    cout << digitSumInStr("12a63") << endl;

    char** matrix = new char*[4];
    for (size_t i = 0; i < 4; i++) {
        matrix[i] = new char[4];
        cin >> matrix[i];
    }

    // abcd
    // eS1e
    // ghij
    // lmnS
    cout << countS(matrix, 4, 4) << endl;

    for (size_t i = 0; i < 4; i++) {
        delete[] matrix[i];
    }
    delete[] matrix;
    return 0;
}