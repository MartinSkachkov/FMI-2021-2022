#include <cstring>
#include <iostream>
using namespace std;

/*  char inputBuffer1[12];          // elements initialized to 0
    static char inputBuffer2[12];   // elements initialized to 0

    void foo(void)
    {
        char inputBuffer3[12];         // elements have indeterminate value!
        static char inputBuffer4[12];  // elements initialized to 0
    }
*/

bool isPalindrome(char* arr) {
    unsigned int size = strlen(arr);  // null-terminator
    for (size_t i = 0; i < size / 2; i++) {
        if (arr[i] != arr[size - 1 - i]) {
            return false;
        }
    }
    return true;
}

int main() {
    int size;
    cout << "Size: ";
    cin >> size;
    char* arr = new char[size + 1];  // for null-terminator

    cout << "Enter string: ";
    cin.get();                   //!!!
    cin.getline(arr, size + 1);  // includes a space for null-terminator
    //(otherwise we will enter 4 chars, not 5)

    cout << "Is the string palindrome? " << boolalpha << isPalindrome(arr);

    delete[] arr;
    return 0;
}