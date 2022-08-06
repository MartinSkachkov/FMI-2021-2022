#include <iostream>
using namespace std;

void BubbleSort(int* arr, size_t length) {
    for (size_t i = 0; i < length - 1; i++) {
        for (size_t j = 0; j < length - 1 - i; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}

// iterative
size_t BinarySearchIter(int* arr, size_t length, int x) {
    // we work with indexes
    size_t left = 0;
    size_t right = length - 1;

    while (left <= right) {
        size_t mid = left + (right - left) / 2;
        if (arr[mid] == x) {
            return mid;
        }
        if (arr[mid] > x) {
            right = mid - 1;
        }
        if (arr[mid] < x) {
            left = mid + 1;
        }
    }
}

// recursive
size_t BinarySearchRec(int* arr, size_t left, size_t right, int x) {
    if (left > right) {
        return -1;
    }
    size_t mid = left + (right - left) / 2;
    if (arr[mid] == x) {
        return mid;
    }
    if (arr[mid] > x) {
        BinarySearchRec(arr, left, right - 1, x);
    }
    if (arr[mid] < x) {
        BinarySearchRec(arr, mid + 1, right, x);
    }
}

int main() {
    size_t length;
    cout << "array length: ";
    cin >> length;
    int* arr = new int[length];

    cout << "enter array:\n";
    for (size_t i = 0; i < length; i++) {
        cin >> arr[i];
    }

    BubbleSort(arr, length);
    cout << "sorted:\n";
    for (size_t i = 0; i < length; i++) {
        cout << arr[i];
    }

    int x;
    cout << "x: ";
    cin >> x;

    // we want the left index and right index
    cout << "recursive(found at index): "
         << BinarySearchRec(arr, 0, length - 1, x) << endl;

    cout << "iterative(found at index): " << BinarySearchIter(arr, length, x)
         << endl;

    delete[] arr;
    return 0;
}