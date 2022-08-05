#include <iostream>
#define NUM_ARR 1024
using namespace std;

size_t strlen(const char* str) {
    size_t len = 0;
    while (*str != 0) {
        str++;
        len++;
    }
    return len;
}

size_t extrcatNums(const char* str, int* numbers) {
    size_t strLength = strlen(str);
    size_t extractedNum = 0, digit = 0, flag = 0, iterator = 0;
    for (size_t i = 0; i <= strLength; i++) {
        // if it's a letter then continue to loop
        if (str[i] < '0' || str[i] > '9') {
            if (flag != 0) {
                // the thing before the letter was number
                numbers[iterator++] = extractedNum;  // save the number
                extractedNum = 0;  // set the number extractor to 0
                flag = 0;          // start searching for new numbers
            }
            continue;
        }
        if ('0' <= str[i] && str[i] <= '9') {  // if it's a digit save it
            digit = str[i] - '0';              // digit is in int now
            extractedNum = extractedNum * 10 + digit;  // concatenatrs the
                                                       // digits
            flag = 1;  // found a number but don't know if it's a single or has
                       // more digits
        }
    }

    return iterator;
}

int main() {
    size_t len;
    cout << "len: ";
    cin >> len;

    cout << "string: ";
    char* str = new char[len + 1];  // for the null-terminator
    cin.get();
    cin.getline(str, len + 1);

    int numbers[NUM_ARR];  // here we will save the numbers

    size_t count;
    try {
        count = extrcatNums(str, numbers);
        if (count == 0) {
            throw "No numbers were found";
        }

    } catch (const char* err) {
        delete[] str;
        cout << "len: ";
        cin >> len;

        cout << "string: ";
        char* str = new char[len + 1];  // for the null-terminator
        cin.get();
        cin.getline(str, len + 1);
        count = extrcatNums(str, numbers);
    }

    cout << "extracted numbers:\n";
    for (size_t i = 0; i < count; i++) {
        cout << numbers[i] << ' ';
    }

    delete[] str;
    return 0;
}