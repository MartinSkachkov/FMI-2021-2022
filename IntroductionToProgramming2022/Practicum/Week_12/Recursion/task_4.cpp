#include <iostream>
using namespace std;

double calc(size_t n) {
    if (n == 1) {
        return 1;
    }
    return (1.0 / n) + calc(n - 1);
}

int main() {
    size_t n;
    do {
        cout << "n: ";
        cin >> n;
    } while (n <= 0);

    cout << "result: " << calc(n);

    return 0;
}