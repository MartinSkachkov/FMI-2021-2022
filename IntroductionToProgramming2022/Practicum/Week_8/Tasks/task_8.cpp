#include <cstring>
#include <iostream>
using namespace std;

// this solution is inefficient
// it is just done to train the dynamic memory allocation
char* reverseArr(char* arr, size_t size) {
    char* reverse = new char[size + 1];
    unsigned int sizeCopy = size - 1;
    for (size_t i = 0; i < size; i++) {
        reverse[i] = arr[sizeCopy--];
    }
    reverse[size] = arr[size];
    return reverse;
}

bool isPalindrome(char* arr, size_t size) {
    char* reversed = reverseArr(arr, size);
    if (strcmp(reversed, arr) == 0) {
        delete[] reversed;
        return true;
    }
    delete[] reversed;
    return false;
}

void initialize(char* arr, size_t size) {
    for (size_t i = 0; i < size; i++) {
        cin >> arr[i];
    }
    arr[size] = 0;
}

void print(const char* arr, size_t size) {
    for (size_t i = 0; i < size; i++) {
        cout << arr[i] << ' ';
    }
    cout << endl;
}

int main() {
    unsigned int size;
    cout << "arr size: ";
    cin >> size;

    char* arr = new char[size + 1];  //+1 for terminating zero
    if (arr == nullptr) {
        throw "not allocated memory";
    }

    initialize(arr, size);
    cout << "Original arr:\n";
    // cout << arr;
    print(arr, size);

    char* reversed = reverseArr(arr, size);
    cout << "Reverse arr:\n";
    print(reversed, size);

    cout << endl << "result: " << boolalpha << isPalindrome(arr, size);
    delete[] reversed;
    delete[] arr;
    return 0;
}
