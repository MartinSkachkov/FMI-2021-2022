#include <iostream>
using namespace std;

int sum(double x, int n) {
    if (n == 2) {
        return x + 2;
    } else {
        return n + x * sum(x, n-1);
    }
}

int main() {
    double x;
    cout << "x: ";
    cin >> x;
    int n;
    do {
        cout << "n: ";
        cin >> n;
    } while (n < 2);

    cout << "sum: " << sum(x, n);

    return 0;
}