#include <iostream>
using namespace std;

int replace(int num) {
    if (num == 0) {
        return 0;
    }
    int lasDigit = num % 10;
    if (lasDigit == 5) {
        lasDigit = 8;
    }
    return replace(num / 10) * 10 + lasDigit;
}

int main() {
    int num;
    cout << "num: ";
    cin >> num;

    cout << "replaced number: " << replace(num);

    return 0;
}