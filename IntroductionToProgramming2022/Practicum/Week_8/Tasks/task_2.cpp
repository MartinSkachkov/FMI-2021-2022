#include <cmath>
#include <iostream>
using namespace std;

long long pow(int num, int power) {
    long long res = 1;
    for (int i = 0; i < power; i++) {
        res *= num;
    }
    return res;
}

int power(unsigned int exp, int base) { return pow(base, pow(exp, exp)); }

int main() {
    unsigned int n;
    int x;
    cout << "n: ";
    cin >> n;

    cout << "x: ";
    cin >> x;

    cout << "Result: " << power(n, x);
    return 0;
}