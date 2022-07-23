// C++ program to compare
// floating point numbers correctly
 
#include <bits/stdc++.h>
using namespace std;
 
void compareFloatNum(double a, double b)
{
 
    // Correct method to compare
    // floating-point numbers
    if (abs(a - b) < 1e-9) {
        cout << "The numbers are equal "
             << endl;
    }
    else {
        cout << "The numbers are not equal "
             << endl;
    }
}
 
// Driver code
int main()
{
    double a = (0.3 * 3) + 0.1;
    double b = 1;
    compareFloatNum(a, b);
}
