#include <iostream>
using namespace std;

//1 - запълнене; 0 - празна (координати i,j)

int sizeArea(bool** grid, int n, int i, int j) {
	if (i<0 || i>n - 1 || j<0 || j>n - 1 || grid[i][j] == 0) {
		return 0; // тогава размерът на областа е 0 || когато сме извън границите
	}

	grid[i][j] = 0; // вече сме обходили тази клетка, която преди това е била единица
	// и за да не зацикли я правим 0
	//когато всичко е наред и сме попаднали на клетка, която е 1
	return 1 + sizeArea(grid, n, i - 1, j - 1)
		+ sizeArea(grid, n, i - 1, j)
		+ sizeArea(grid, n, i - 1, j + 1)
		+ sizeArea(grid, n, i, j - 1)
		+ sizeArea(grid, n, i, j + 1)
		+ sizeArea(grid, n, i + 1, j - 1)
		+ sizeArea(grid, n, i + 1, j)
		+ sizeArea(grid, n, i + 1, j + 1);
}

int countAreas(bool** grid, int n) {
	int counter = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (grid[i][j] == 1) {
				int size = sizeArea(grid, n, i, j);
				cout << "Size of area: " << counter + 1 << " is " << size << endl;
				counter++;
			}
		}
	}
	return counter;
}

int main() {
	int size;
	cout << "Enter size: ";
	cin >> size;
	bool** matrix = new bool*[size];
	for (size_t i = 0; i < size; i++)
	{
		matrix[i] = new bool[size];
		for (size_t j = 0; j < size; j++)
		{
			cin >> matrix[i][j];
		}
	}

	int count = countAreas(matrix, size);
	cout << "Number of areas are: " << count << endl;

	for (size_t i = 0; i < size; i++)
	{
		delete[] matrix[i];
	}
	delete[]matrix;

	return 0;
}
