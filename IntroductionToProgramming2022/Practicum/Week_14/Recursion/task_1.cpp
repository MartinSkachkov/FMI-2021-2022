#include <iostream>
#define capacity 8
using namespace std;

void arrcpy(int* destination, int* source, size_t size) {
    for (size_t i = 0; i < size; i++) {
        destination[i] = source[i];
    }
}

bool BubbleSort(int* arr, size_t size) {
    for (size_t i = 0; i < size - 1; i++) {
        for (size_t j = 0; j < size - 1 - i; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
    return true;
}

void resize(int* arr, size_t size) {
    int* temp = arr;              // copy arr mem adress
    arr = new int[capacity * 2];  // alloc new memory and return new address
    arrcpy(arr, temp, size);      // copy old info to the new memory location
    delete[] temp;                // delete old memory
}

void addElement(int* arr, size_t size, int x) {
    // if we are at the begining place it first
    if (size == 0) {
        arr[0] = x;
        size++;
        return;
    }
    // room for improvement with the resize func
    if (size + 1 >= capacity) {
        resize(arr, capacity);
    }
    if (arr[size - 1] > x) {
        arr[size] = arr[size - 1];  // shift them by one position
        addElement(arr, size - 1, x);
    } else {
        arr[size] = x;
        size++;
        return;
    }
}

int main() {
    size_t size;
    cout << "size: ";
    cin >> size;

    int* arr = new int[capacity];
    cout << "enter array: ";
    for (size_t i = 0; i < size; i++) {
        cin >> arr[i];
    }
    BubbleSort(arr, size);

    int x;
    cout << "add x: ";
    cin >> x;

    addElement(arr, size, x);
    size++;

    cout << "result:\n";
    for (size_t i = 0; i < size; i++) {
        cout << arr[i] << ' ';
    }
    cout << endl << size;
    delete[] arr;
    return 0;
}