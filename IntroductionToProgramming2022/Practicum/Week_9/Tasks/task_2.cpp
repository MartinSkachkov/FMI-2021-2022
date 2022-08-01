#include <iostream>
#define MAX_SIZE 21
using namespace std;

// ascii 97-112
bool isLowerCase(const char ch) { return 97 <= ch && ch <= 122; }

size_t strlen(const char* str) {
    size_t len = 0;
    while (*str != 0) {
        str++;
        len++;
    }
    return len;
}

char& toUpper(char& ch) { return ch -= 32; }

char& toLower(char& ch) { return ch += 32; }

void changeChars(char* str) {
    size_t len = strlen(str);
    for (size_t i = 0; i < len; i++) {
        if(str[i] == ' '){
            continue;
        }
        if (isLowerCase(str[i])) {
            str[i] = toUpper(str[i]);
        } else {
            str[i] = toLower(str[i]);
        }
    }
}

int main() {
    char str[MAX_SIZE];
    cout << "string: ";
    cin.getline(str, MAX_SIZE);

    changeChars(str);
    cout << str;
    return 0;
}