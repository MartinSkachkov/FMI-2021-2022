#include <iostream>
using namespace std;

int concatDigits(int x, int y) {
    int yCopy = y;
    do {
        x *= 10;
        yCopy /= 10;
    } while (yCopy);

    return x + y;
}

int findNum(int sum, int difference, int x, int y) {
    // base case
    if (((x + y) == sum) &&
        ((concatDigits(y, x) - concatDigits(x, y)) == difference)) {
        return concatDigits(x, y);
    }
    y++;
    x = sum - y;
    return findNum(sum, difference, x, y);
}

int main() {
    int sum = 0, difference = 0, x = 0, y = 0;
    cout << "sum x + y = ";
    cin >> sum;

    cout << "difference yx - xy = ";
    cin >> difference;

    x = sum - y;
    cout << "the number xy is: " << findNum(sum, difference, x, 0);

    return 0;
}