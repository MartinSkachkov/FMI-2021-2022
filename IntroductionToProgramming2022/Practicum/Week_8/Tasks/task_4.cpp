#include <iostream>
using namespace std;

bool isPrime(unsigned int number) {
    if (number == 0 || number == 1) {
        return false;
    }
    for (size_t i = 2; i <= number/2; i++) {
        if (number % i == 0) {
            return false;
        }
    }
    return true;
}

int enterNumber(unsigned int n) {
    unsigned int input, counter = 0;
    for (size_t i = 0; i < n; i++) {
        cin >> input;
        if (isPrime(input)) {
           // cout << input;
            counter++;
        }
    }
    return counter;
}

int main() {
    unsigned int n;
    cout << "n: ";
    cin >> n;
    unsigned int counter = enterNumber(n);
    cout << "counter: " << counter;
    return 0;
}