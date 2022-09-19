#include "String.h"
#include <iostream>
using namespace std;

int main() {
    String s1;
    cout << s1;

    String s2("Marto");
    cout << s2;

    String s3("Picha");
    String appended = s2.append(s3);
    cout << appended;
    s2.append(s3);
    cout << s2;

    return 0;
}