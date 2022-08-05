#include <iostream>
using namespace std;

int main() {
    size_t decimal;
    cout << "decimal: ";
    cin >> decimal;

    size_t binary = 0, order = 1, decimalCopy = decimal;
    while (decimalCopy != 0) {
        binary = binary + order * (decimalCopy % 2); //!!!
        decimalCopy /= 2;
        order *= 10;
    }

    cout << "binary: " << binary;

    return 0;
}