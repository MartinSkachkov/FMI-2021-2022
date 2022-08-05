#include <iostream>
using namespace std;

/* for sum 1 till n
def sum_positive_numbers(n):
  if n <= 1:
       return n
  return n + sum_positive_numbers(n-1)
  */

int sum(int n, int offset, int base) {
    if (base >= n) {
        return 0;
    }
    return base + sum(n, offset, base + offset);
}

int main() {
    int offset;
    int n;
    cout << "n: ";
    cin >> n;
    cout << "offset: ";
    cin >> offset;
    int base = 1;
    cout << "sum: " << sum(n, offset, base);

    return 0;
}