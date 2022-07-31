#include <iostream>
using namespace std;

void BubbleSort(int* array, const size_t size) {
    for (size_t i = 0; i < size - 1; i++) {
        for (size_t j = 0; j < size - 1 - i; j++) {
            if (array[j] > array[j + 1]) {
                int temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
            }
        }
    }
}

int main() {
    size_t size;
    cin >> size;
    int* arr = new int[size];

    for (size_t i = 0; i < size; i++) {
        cin >> arr[i];
    }

    BubbleSort(arr, size);
    cout << "Sorted\n";
    for (size_t i = 0; i < size; i++) {
        cout << arr[i];
    }

    delete[] arr;
    return 0;
}