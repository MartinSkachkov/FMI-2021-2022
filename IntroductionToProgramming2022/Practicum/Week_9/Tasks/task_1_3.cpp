#include <iostream>
using namespace std;

size_t strlen(const char* str) {
    size_t len = 0;
    while (*str != 0) {
        len++;
        str++;
    }
    return len;
}

int substringIndex(const char* str, const char* substr) {
    size_t stringIterator = 0;
    size_t substrLen = strlen(substr);
    bool hasSubstring = false;
    while (str[stringIterator] != 0) {
        hasSubstring = false;
        if (str[stringIterator] == substr[0]) {
            size_t k = 0;
            while (str[stringIterator + k] != 0 && substr[k] != 0 &&
                   str[stringIterator + k] == substr[k]) {
                k++;
            }
            if (k == substrLen) {
                hasSubstring = true;
            }
            if (hasSubstring) {
                return stringIterator;
            }
        }
        stringIterator++;
    }
    return -1;
}

int main() {
    size_t strSize, substrSize;
    do {
        cout << "string size: ";
        cin >> strSize;

        cout << "substring size: ";
        cin >> substrSize;
    } while (substrSize > strSize);
    char* str = new char[strSize + 1];
    char* substr = new char[substrSize + 1];

    cin.get();
    cout << "string: ";
    cin.getline(str, strSize + 1);
    cout << "substring: ";
    cin.getline(substr, substrSize + 1);

    cout << "the substring is met at index: "
         << substringIndex(str, substr) + 1;

    delete[] str;
    delete[] substr;
    return 0;
}