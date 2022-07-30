#include <string.h>
#include <iostream>
#define MAX_SIZE 1024
using namespace std;

// string = abcdf
// substr = bcd

bool hasSubstring(char* string, char* substring) {
    int substringLen = strlen(substring);
    int stringIterator = 0;

    while (string[stringIterator] != 0) {
        if (string[stringIterator] == substring[0]) {
            int k = 0;
            // checking for substring
            while (string[stringIterator + k] != 0 && substring[k] != 0 &&
                   string[stringIterator + k] == substring[k]) {
                k++;
            }

            // is the found substring same size as substring
            if (substringLen == k) {
                return true;
            }
        }
        stringIterator++;
    }
    return false;
}

void initArr(char* arr,
             unsigned int size) {  // pass by reference (we change, not copy)
    for (size_t i = 0; i < size; i++) {
        cin >> arr[i];
    }
    arr[size] = 0;
}

int main() {
    unsigned int stringSize, substringSize;
    char string[MAX_SIZE], substring[MAX_SIZE];

    cout << "String size: ";
    cin >> stringSize;
    cout << "Substring size: ";
    cin >> substringSize;

    cout << "String: ";
    initArr(string, stringSize);

    cout << "Substring: ";
    initArr(substring, substringSize);

    cout << "The substring is: " << boolalpha << hasSubstring(string, substring);
}