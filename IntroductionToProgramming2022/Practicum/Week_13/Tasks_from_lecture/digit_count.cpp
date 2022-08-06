#include <iostream>
using namespace std;

size_t numberOfDigits(size_t number, size_t numberSystem) {
    if (number < numberSystem) {
        return 1;
    }

    return 1 + numberOfDigits(number / numberSystem, numberSystem);
}

int main() {
    size_t num;
    cout << "num: ";
    cin >> num;

    size_t numberSystem;
    cout << "number system: ";
    cin >> numberSystem;

    cout << "number of digits: " << numberOfDigits(num, numberSystem);

    return 0;
}