#include <iostream>
using namespace std;

int smallestDigit(int num, int digit) {
    if (num == 0) {
        return digit;
    }
    if (digit > num % 10) {
        digit = num % 10;
    }
    smallestDigit(num / 10, digit);
}

int main() {
    int num;
    cout << "num: ";
    cin >> num;
    int digit = INT_MAX;
    cout << "smallest digit: " << smallestDigit(num, digit);

    return 0;
}
