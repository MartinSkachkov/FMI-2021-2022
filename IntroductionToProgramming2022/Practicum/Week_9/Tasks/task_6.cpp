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

void strcpy(char* destination, const char* source) {
    size_t length = strlen(source);
    for (size_t i = 0; i <= length; i++) {
        destination[i] = source[i];
    }
}

char& toLower(char& ch) { return ch += 32; }

char& toUpper(char& ch) { return ch -= 32; }

void setLower(char* str, unsigned int size) {
    for (size_t i = 0; i < size; i++) {
        if (str[i] == ' ') {
            continue;
        }
        // if the letter is upper case, make it lower
        if (65 <= str[i] && str[i] <= 90) {
            str[i] = toLower(str[i]);
        }
    }
}

void setUpper(char* str, unsigned int size) {
    for (size_t i = 0; i < size; i++) {
        if (str[i] == ' ') {
            continue;
        }
        // if the letter is lower case, make it upper
        if (97 <= str[i] && str[i] <= 122) {
            str[i] = toUpper(str[i]);
        }
    }
}

int main() {
    const unsigned int stringSize = 256;

    cout << "string: ";
    char str[stringSize];
    cin.getline(str, stringSize);

    char lower[stringSize];
    strcpy(lower, str);
    setLower(lower, stringSize);

    char upper[stringSize];
    strcpy(upper, str);
    setUpper(upper, stringSize);

    cout << str << endl;
    cout << lower << endl;
    cout << upper << endl;

    return 0;
}
