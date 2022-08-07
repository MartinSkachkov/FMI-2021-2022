#include <iostream>
using namespace std;

bool linearSearch(const int* arr, int x, size_t n) {
    if (n == 0) {
        return false;
    }
    return *arr == x || linearSearch(arr + 1, x, n - 1);
}

int main() {
    size_t n;
    cout << "n: ";
    cin >> n;
    int* arr = new int[n];

    cout << "enter array elements: ";
    for (size_t i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int x;
    cout << "x: ";
    cin >> x;

    cout << boolalpha << linearSearch(arr, x, n);

    return 0;
}