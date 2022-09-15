#include "Time.h"
#include <iostream>
using namespace std;

int main() {
    Time t(22, 45, 36);
    cout << "Current time\n";
    t.print();

    Time toMidnight = t.toMidnight(); // default copy constructor
    cout << "To midnight\n";
    toMidnight.print();

    Time random(20, 30, 30);
    Time diff = t.difference(random);
    cout << "Difference time\n";
    diff.print();

    Time party;
    cout << "Is party time? " << boolalpha << party.isPartyTime() << '\n';

    Time notParty(22, 0, 0);
    cout << "Is party time? " << boolalpha << notParty.isPartyTime() << '\n';

    Time dinner(20, 31, 0);
    cout << "Is dinner time? " << boolalpha << dinner.isDinnerTime() << '\n';

    Time notDinner(19, 20, 30);
    cout << "Is dinner time? " << boolalpha << notDinner.isDinnerTime() << '\n';

    return 0;
}