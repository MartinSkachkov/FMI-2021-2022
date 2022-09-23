#include "Person.h"
#include <iostream>
using namespace std;

int main() {
    Person p("Ivan", 43);
    cout << p;
    cin >> p;
    cout << p;
}