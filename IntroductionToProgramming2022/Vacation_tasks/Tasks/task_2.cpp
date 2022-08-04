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

bool isUpper(const char* str) {
    size_t len = strlen(str);
    bool isUpLetter = true;
    for (size_t i = 0; i < len; i++) {
        if (str[i] >= 'A' && str[i] <= 'Z') {
            isUpLetter = true;
        } else {
            return false;
        }
    }
    return isUpLetter;
}

void toLower(char* str) {
    size_t len = strlen(str);
    for (size_t i = 0; i < len; i++) {
        str[i] = str[i] + 32;
    }
}

int strcmp(const char* str1, const char* str2) {
    size_t min = strlen(str1) > strlen(str2) ? strlen(str2) : strlen(str1);
    for (size_t i = 0; i <= min; i++) {
        if (str1[i] == str2[i]) {
            continue;
        }
        if (str1[i] > str2[i]) {
            return 1;
        }
        if (str1[i] < str2[i]) {
            return -1;
        }
    }
    return 0;
}

void pow(int& num, int pow = 7) {
    int result = 1;
    for (size_t i = 0; i < 7; i++) {
        result *= num;
    }
    num = result;
}

int main() {
    const int MAX_SIZE = 5;
    int num;
    cout << "enter num: ";
    cin >> num;

    cout << "Is the child good? " << endl;
    char answer[MAX_SIZE];
    cin.get();
    cin.getline(answer, MAX_SIZE);

    if (isUpper(answer)) {
        toLower(answer);
    }

    if ((strcmp(answer, "yes") == 0)) {
        pow(num);
        cout << num;
    } else {
        cout << "Naughty kid!!!";
    }

    return 0;
}