#include <iostream>
using namespace std;

int main() {
	int energy;
	cout << "Energy: ";
	bool energyLim = false;
	do {
		if (energyLim) {
			cout << "Invalid energy input. Try again: ";
		}
		cin >> energy;
		energyLim = energy < 1 || energy > 2'000'000;
	} while (energyLim);

	int distance;
	cout << "Distance: ";
	bool distanceLim = false;
	do {
		if (distanceLim) {
			cout << "Invalid distance input. Try again: ";
		}
		cin >> distance;
		distanceLim = distance < 1 || distance > 1'000'000;
	} while (distanceLim);

	int fatigue;
	cout << "Fatigue: ";
	bool fatigueLim = false;
	do {
		if (fatigueLim) {
			cout << "Invalid fatigue input. Try again: ";
		}
		cin >> fatigue;
		fatigueLim = fatigue < 1 || fatigue > 9;
	} while (fatigueLim);

	int energyCopy = energy;
	int counter = 0;
	while (energyCopy >= distance) {
		energyCopy -= distance;
		counter++;
		if (energyCopy * 2 == energy && fatigue != 0) {
			energyCopy /= fatigue;
		}
	}

	cout << "Energy left: " << energyCopy << endl << "Enemies defeated: " << counter;
	return 0;
}
