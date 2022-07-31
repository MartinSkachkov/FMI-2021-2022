#include <iostream>
using namespace std;

void SelectionSort(int* array, const size_t size) {
    for (size_t i = 0; i < size - 1; i++) {
        for (size_t j = i + 1; j < size; j++) {
            if (array[i] > array[j])  //за намаляващ array[i] < array[j]
            {
                int tmp = array[i];
                array[i] = array[j];
                array[j] = tmp;
            }
        }
    }
}

int main() {
    size_t size;
    cin >> size;
    int* array = new int[size];

    for (size_t i = 0; i < size; i++) {
        cin >> array[i];
    }

    SelectionSort(array, size);
    cout << "Sorted\n";
    for (size_t i = 0; i < size; i++) {
        cout << array[i];
    }

    delete[] array;
    return 0;
}