#include "House.h"
#include <iostream>
using namespace std;

double biggestHouse(House **other, size_t n) {
    double maxHeight = 0;
    for (size_t i = 0; i < n; i++) {
        if (maxHeight < other[i]->averageFloorHeight()) {
            maxHeight = other[i]->averageFloorHeight();
        }
    }
    return maxHeight;
}

int main() {
    /*Building b(5, 20, "Some str.");
    cout << b;

    Building b1(b);
    cout << b1;

    cin >> b1;
    b = b1;
    cout << b;*/

    /*House h(5, 20, "Some str.", 3, "Marto");
    cout << h;

    House h1(h);
    cout << h1;

    cin >> h1;
    h = h1;
    cout << h;*/

    cout << "==== BUILDINGS PROGRAM ====\n";
    House **houses;
    size_t numberOfBuildings;

    cout << "Number of buildings: ";
    cin >> numberOfBuildings;

    houses = new House *[numberOfBuildings];
    for (size_t i = 0; i < numberOfBuildings; i++) {
        houses[i] = new House();
        cin >> *houses[i];
    }

    for (size_t i = 0; i < numberOfBuildings; i++) {
        cout << *houses[i];
    }

    double maxHeight = biggestHouse(houses, numberOfBuildings);
    cout << "MAX HEIGHT: " << maxHeight;

    for (size_t i = 0; i < numberOfBuildings; i++) {
        delete[] houses[i];
    }
    delete[] houses; // calls the destructor of House class, which calls the destructor of Building class
    return 0;
}