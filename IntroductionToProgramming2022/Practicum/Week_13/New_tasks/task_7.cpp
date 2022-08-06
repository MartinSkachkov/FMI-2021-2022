#include <iostream>
using namespace std;

size_t fib(size_t n) {
    if (n == 0) {
        return 0;
    }
    if (n == 1) {
        return 1;
    }
    return fib(n - 2) + fib(n - 1);
}

int main() {
    size_t n;
    cout << "n: ";
    cin >> n;

    cout << "n-th fibonacci number is: " << fib(n);
    return 0;
}