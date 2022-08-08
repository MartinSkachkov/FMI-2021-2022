#include <iostream>
using namespace std;

int strcmpRecursion(char* str1, char* str2) {
    if (*str1 > *str2) {
        return 1;
    }
    if (*str1 < *str2) {
        return -1;
    }
    if (*str1 == 0) {
        return 0;
    }
    return strcmpRecursion(str1 + 1, str2 + 1);
}

int main() {
    size_t size1, size2;
    cout << "size1: ";
    cin >> size1;

    cout << "str1:\n";
    char* str1 = new char[size1 + 1];
    cin.get();
    cin.getline(str1, size1 + 1);

    cout << "size2: ";
    cin >> size2;

    cout << "str2:\n";
    char* str2 = new char[size2 + 1];
    cin.get();
    cin.getline(str2, size2 + 1);

    cout << "comparing " << str1 << ' ' << str2 << "\n"
         << "result: " << strcmpRecursion(str1, str2);

    delete[] str1;
    delete[] str2;
    return 0;
}