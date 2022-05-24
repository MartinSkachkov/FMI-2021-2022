#include "House.h"

//biggest house
size_t biggestHouse(House** other, size_t n) {
	size_t maxHeight = 0;
	for (size_t i = 0; i < n; i++) {
		if (maxHeight < other[i]->getAverageHeight()) {
			maxHeight = other[i]->getAverageHeight();
		}
	}
	return maxHeight;
}

int main() {
	cout << "==== BUILDINGS PROGRAM ====\n";
	House** houses;
	size_t numberOfBuildings;

	cout << "Number of buildings: ";
	cin >> numberOfBuildings;

	houses = new House*[numberOfBuildings];
	for (size_t i = 0; i < numberOfBuildings; i++) {
		houses[i] = new House();
		cin >> *houses[i];
	}

	for (size_t i = 0; i < numberOfBuildings; i++) {
		cout << *houses[i];
	}

	size_t maxHeight = biggestHouse(houses, numberOfBuildings);
	cout << "MAX HEIGHT: " << maxHeight;

	for (size_t i = 0; i < numberOfBuildings; i++){
		delete[] houses[i];
	}
	delete[] houses;

	return 0;
}