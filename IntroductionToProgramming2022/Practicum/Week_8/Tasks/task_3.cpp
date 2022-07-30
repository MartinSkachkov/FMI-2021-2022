#include <iostream>
#include <iomanip>
using namespace std;

double average(unsigned int n) {
    if (n == 0) {
        return 0;
    }
    int sum = 0, input;
    cout << "Enter " << n << " numbers\n";
    for (size_t i = 0; i < n; i++) {
        cin >> input;
        sum += input;
    }
    cout << "Average is: ";
    return (double)sum / n;
}

int main() {
    unsigned int n;
    cout << "n: ";
    cin >> n;

    cout << fixed << setprecision(2) << average(n);
    return 0;
}