#include <iostream>
#define NAME_LEN 20
using namespace std;

void initList(char** list, size_t countOfPpl) {
    for (size_t i = 0; i < countOfPpl; i++) {
        cin.get();
        cin.getline(list[i], NAME_LEN, ',');
    }
}

size_t strlen(const char* str) {
    size_t len = 0;
    while (*str != 0) {
        str++;
        len++;
    }
    return len;
}

int strcmp(const char* str1, const char* str2) {
    size_t min = strlen(str1) > strlen(str2) ? strlen(str2) : strlen(str1);
    for (size_t i = 0; i < min; i++) {
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

bool hasName(char** list, char* name, size_t countOfPpl) {
    for (size_t i = 0; i < countOfPpl; i++) {
        if (strcmp(list[i], name) == 0) {
            return true;
        }
    }
    return false;
}

int main() {
    size_t countOfPpl;
    cout << "number of ppl: ";
    cin >> countOfPpl;
    char** list = new char*[countOfPpl];
    for (size_t i = 0; i < countOfPpl; i++) {
        list[i] = new char[NAME_LEN];
    }

    initList(list, countOfPpl);

    char input[NAME_LEN];
    cout << "person's name: ";
    cin.get();
    cin.getline(input, NAME_LEN);

    cout << boolalpha << hasName(list, input, countOfPpl);
    for (size_t i = 0; i < countOfPpl; i++) {
        delete[] list[i];
    }
    delete[] list;
    return 0;
}