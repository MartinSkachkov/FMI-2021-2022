#include "Nvector.h"
#include <fstream>
#include <iostream>

using namespace std;

int main() {
    Nvector v(4);
    cin >> v;
    cout << v;

    Nvector v2(4);
    cin >> v;
    cout << v;

    Nvector result = v + v2;
    cout << result << endl;

    v += v2;
    cout << v;
}