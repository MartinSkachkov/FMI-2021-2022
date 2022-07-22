#include <iostream>
#include <cstdlib>
using namespace std;

int minimumTime(int* times, int pancakes, int stoves){
	// Initialize time, items equal to 0.
	int minTime = 0;

	while (1)
	{
		int items = 0;

		// Calculating items at each second
		for (int i = 0; i < stoves; i++)
			items += (minTime / times[i]);

		// If items equal to m return time.
		if (items >= pancakes)
			return minTime;

		minTime++; // Increment time
	}
}

int main() {
	int stoves;
	do {
		cout << "Stoves: ";
		cin >> stoves;
	} while (stoves <= 0 || stoves >= 20);

	int pancakes;
	do {
		cout << "Pancakes: ";
		cin >> pancakes;
	} while (pancakes <= 0 || pancakes >= 1015);

	cout << "Time: ";
	int* times = new int[stoves];
	for (size_t i = 0; i < stoves; i++) {
		do
		{
			cin >> times[i];
		} while (times[i] >= 500);
	}

	cout << minimumTime(times, pancakes, stoves);

	delete[] times;

	return 0;
}
