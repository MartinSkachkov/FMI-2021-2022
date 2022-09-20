#include "String.h"
#include <iostream>
using namespace std;

int main() {
    // some tests
    String s1;
    cout << s1 << '\n';

    String s2("Marto");
    cout << s2 << '\n';

    s1 = s2;
    cout << boolalpha << (s1 == s2) << '\n';

    String s3("Picha");
    cout << boolalpha << (s3 != s2) << '\n';

    s2 + s3;
    cout << s1;
    cout << s2;
    cout << s3;

    /* String appended = s2.append(s3);
     cout << appended;
     s2.append(s3);
     cout << s2;*/

    return 0;
}