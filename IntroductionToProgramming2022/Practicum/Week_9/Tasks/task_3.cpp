#include <cstring>
#include <iostream>
using namespace std;

void copy(char* str, const char* helper) {
    size_t length = strlen(helper);
    for (size_t i = 0; i <= length; i++) {
        str[i] = helper[i];
    }
}

void removeDuplicateIntervals(char* str, size_t size) {
    char* helper = new char[size + 1];
    size_t iterator = 0;
    for (size_t i = 0; i < size; i++) {
        if (str[i] == ' ' && str[i + 1] == ' ') {
            continue;
        } else {
            helper[iterator++] = str[i];
        }
    }
    helper[iterator] = 0;
    copy(str, helper);
    delete[] helper;
}

int main() {
    size_t size;
    cout << "size: ";
    cin >> size;
    char* str = new char[size + 1];

    cout << "string: ";
    cin.get();
    cin.getline(str, size + 1);

    removeDuplicateIntervals(str, size);
    cout << "result: " << str;

    delete[] str;
    return 0;
}