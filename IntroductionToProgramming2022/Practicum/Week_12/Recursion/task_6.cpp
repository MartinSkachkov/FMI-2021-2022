#include <iostream>
using namespace std;

int sumOfDigit(int num, int sum) {
    if (num == 0) {
        return sum;
    }
    sum += num % 10;
    sumOfDigit(num / 10, sum);
}

int main() {
    int num;
    cout << "num: ";
    cin >> num;
    size_t sum = 0;
    cout << "smallest digit: " << sumOfDigit(num, sum);

    return 0;
}
