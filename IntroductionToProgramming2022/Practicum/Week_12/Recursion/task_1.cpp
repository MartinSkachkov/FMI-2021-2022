#include <iostream>
using namespace std;

size_t toBinary(int decimal) {
    return decimal == 0 ? 0 : decimal % 2 + 10 * toBinary(decimal / 2);
}

int main() {
    size_t decimal;
    cout << "decimal: ";
    cin >> decimal;

    cout << decimal << " converted to binary is " << toBinary(decimal);
    return 0;
}