#include <iostream>
using namespace std;

size_t strlen(const char* str) {
    size_t len = 0;
    while (*str != 0) {
        str++;
        len++;
    }
    return len;
}

int strcmp(const char* str1, const char* str2) {
    size_t min = strlen(str1) < strlen(str2) ? strlen(str1) : strlen(str2);
    for (size_t i = 0; i <= min; i++) {
        if (str1[i] == str2[i]) {
            continue;
        }
        if (str1[i] < str2[i]) {
            return -1;
        }
        if (str1[i] > str2[i]) {
            return 1;
        }
    }
    return 0;
}

int main() {
    size_t size1, size2;
    cout << "size1: ";
    cin >> size1;
    cout << "size2: ";
    cin >> size2;

    char* str1 = new char[size1 + 1];
    char* str2 = new char[size2 + 1];

    cin.get();
    cout << "str1: ";
    cin.getline(str1, size1 + 1);
    cout << "str2: ";
    cin.getline(str2, size2 + 1);

    cout << strcmp(str1, str2);

    delete[] str1;
    delete[] str2;
    return 0;
}
