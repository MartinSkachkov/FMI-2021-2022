#include <iostream>
using namespace std;

size_t numlen(int number) {
    size_t length = 0;
    while (number != 0) {
        length++;
        number /= 10;
    }
    return length;
}

char* stringRepresentation(int number) {
    // alloc mem
    size_t strLen = numlen(number);
    char* str = new char[strLen + 1];
    str[strLen] = 0;

    while (number != 0) {
        // int to str -> '8' +'0';
        str[strLen - 1] = char(number % 10) + '0';  // saving back to start
        number /= 10;
        strLen--;
    }
    return str;
}

int main() {
    int number;
    cout << "number: ";
    cin >> number;

    char* strRepresentation = stringRepresentation(number);

    cout << strRepresentation;
    delete[] strRepresentation;
    return 0;
}