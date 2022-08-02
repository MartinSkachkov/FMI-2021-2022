#include <cstring>
#include <iostream>
using namespace std;

bool isSmallLetter(const char ch) { return 97 <= ch && ch <= 122; }

// get all small letters from the string and save them to the result
void extractSmallLetters(const char* source, unsigned int size, char* result) {
    unsigned int iterator = 0;
    for (size_t i = 0; i < size; i++) {
        if (isSmallLetter(source[i])) {
            result[iterator++] = source[i];
        }
    }
    result[iterator] = 0;
}

bool isUpper(const char ch) { return 65 <= ch && ch <= 90; }

// if the letter is upper, save it to the result
void extractCapitalLetters(const char* source, unsigned int size,
                           char* result) {
    unsigned int iterator = 0;
    for (size_t i = 0; i < size; i++) {
        if (isUpper(source[i])) {
            result[iterator++] = source[i];
        }
    }
    result[iterator] = 0;
}

bool check(const char* str, unsigned int size) {
    char* lower = new char[strlen(str) + 1];
    extractSmallLetters(str, size, lower);  // passing size?

    char* upper = new char[strlen(str) + 1];
    extractCapitalLetters(str, size, upper);

    if (strlen(lower) != strlen(upper)) {
        return false;
    }

    unsigned int len = strlen(lower);  // they have the same length
    for (size_t i = 0; i < len; i++) {
        if (lower[i] - 32 !=
            upper[i]) {  //ако малката буква, направена голяма е различна от
            return false;  //голямата буква на upper то не са съответни
        }
    }
    return true;
}

int main() {
    const unsigned int strSize = 8;
    char str[strSize];

    cout << "string: ";
    cin.getline(str, strSize);

    if (check(str, strSize)) {
        cout << "yes";
    } else {
        cout << "no";
    }

    return 0;
}
