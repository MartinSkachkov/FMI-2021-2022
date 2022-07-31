#include <iostream>
using namespace std;

void initialize(double* numbers,
                const unsigned int
                    size) {  // const because we don't want to change the size
    cout << "Initialize array: ";
    for (size_t i = 0; i < size; i++) {
        cin >> numbers[i];
    }
}

double minElement(double* numbers, const unsigned int size) {
    double min = numbers[0];
    for (size_t i = 1; i < size; i++) {
        if (min > numbers[i]) {
            min = numbers[i];
        }
    }
    return min;
}

double maxElement(double* numbers, const unsigned int size) {
    double max = numbers[0];
    for (size_t i = 1; i < size; i++) {
        if (max < numbers[i]) {
            max = numbers[i];
        }
    }
    return max;
}

double average(double* numbers, const unsigned int size) {
    double sum = 0;
    for (size_t i = 0; i < size; i++) {
        sum += numbers[i];
    }
    return sum / size;
}

double sum(double* numbers, const unsigned int size) {
    return minElement(numbers, size) + maxElement(numbers, size) +
           average(numbers, size);
}

int main() {
    unsigned int size;
    cout << "size: ";
    cin >> size;
    double* numbers = new double[size];

    // way to get the size: size = sizeof(arr)/sizeof(double)
    initialize(numbers, size);
    cout << "Result: " << sum(numbers, size);

    delete[] numbers;
    return 0;
}