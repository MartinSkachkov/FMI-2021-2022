#include <iostream>
using namespace std;

int factorial(unsigned int num) {
    unsigned int result = 1;
    for (size_t i = 2; i <= num; i++) {
        result *= i;
    }
    return result;
}

int main() {
    unsigned int n;
    cout << "n: ";
    cin >> n;
    cout << "Result: " << factorial(n);
    return 0;
}