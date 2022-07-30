#include <iostream>
#define MAX_SIZE 100
using namespace std;

void swap(int* num1, int* num2) {
    int temp = *num1;
    *num1 = *num2;
    *num2 = temp;
}

void swapAllArrElements(int* a, int* b, int size) {
    for (size_t i = 0; i < size; i++) {
        swap(a[i], b[i]);
    }
}

void swapByIndex(int* a, int* b, int size, int index) {
    swap(a[index - 1], b[index - 1]);
}

void init(int* arr, int size) {
    for (size_t i = 0; i < size; i++) {
        cin >> arr[i];
    }
    arr[size] = 0;
}

void print(int* arr, int size) {
    for (size_t i = 0; i < size; i++) {
        cout << arr[i] << ' ';
    }
    cout << endl;
}

int main() {
    int a[MAX_SIZE], b[MAX_SIZE];
    int size;

    cout << "Size: ";
    cin >> size;

    cout << "a: ";
    init(a, size);
    cout << "b: ";
    init(b, size);

    swapAllArrElements(a, b, size);

    cout << "a: ";
    print(a, size);
    cout << "b: ";
    print(b, size);

    int index;
    cout << "index: ";
    cin >> index;
    swapByIndex(a, b, size, index);
    cout << "a: ";
    print(a, size);
    cout << "b: ";
    print(b, size);

    return 0;
}