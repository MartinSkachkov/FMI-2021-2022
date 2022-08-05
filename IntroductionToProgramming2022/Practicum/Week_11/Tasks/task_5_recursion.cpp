#include <iostream>
using namespace std;

size_t convertToBinary(size_t decimal) {  // passing a copy
    size_t binary;
    // base case
    if (decimal == 0) {
        binary = 0;
    } else {
        binary = decimal % 2 + 10 * (convertToBinary(decimal / 2));
    }
    return binary;
}

int main() {
    size_t decimal;
    cout << "decimal: ";
    cin >> decimal;

    cout << "from " << decimal << " in decimal to -> "
         << convertToBinary(decimal) << " in binary" << endl;

    return 0;
}