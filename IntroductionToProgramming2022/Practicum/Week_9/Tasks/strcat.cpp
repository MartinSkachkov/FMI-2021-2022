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

void copy(char* dest, const char* source) {
    size_t len = strlen(source) + 1;  // this copies the null terminator as well
    for (size_t i = 0; i < len; i++) {
        dest[i] = source[i];
    }
}

void strcat(char* prefix, const char* suffix) {
    char* concatenated = new char[strlen(prefix) + strlen(suffix) + 1];
    copy(concatenated, prefix);
    size_t iterator = 0;

    for (size_t i = strlen(prefix); i < strlen(prefix) + strlen(suffix) + 1;
         i++) {
        concatenated[i] = suffix[iterator++];
    }

    delete[] prefix;  // delete the old memory and allocate new one
    prefix = new char[strlen(prefix) + strlen(suffix) + 1];
    copy(prefix, concatenated);
    delete[] concatenated;
}

int main() {
    size_t strLen1;
    cout << "string1 length: ";
    cin >> strLen1;
    char* str1 = new char[strLen1 + 1];

    cout << "enter string1: ";
    cin.get();
    cin.getline(str1, strLen1 + 1);

    size_t strLen2;
    cout << "string2 length: ";
    cin >> strLen2;
    char* str2 = new char[strLen2 + 1];

    cout << "enter string2: ";
    cin.get();
    cin.getline(str2, strLen2 + 1);

    strcat(str1, str2);

    cout << "result: " << str1;

    delete[] str1;
    delete[] str2;
    return 0;
}