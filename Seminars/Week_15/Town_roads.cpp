bool hasFixedWay(bool** matrix, int n, int i, int j, int path) {
	if (path == 1)
	{
		return matrix[i][j] == 1;
	}

	int k = -1;
	bool hasWay = false;
	do {
		k++;
		if (matrix[i][k] == 1)
		{
			matrix[i][k] = matrix[k][i] = 0;
			hasWay = hasFixedWay(matrix, n, k, j, path - 1);
			matrix[i][k] = matrix[k][i] = 1;
		}
	} while (k <= n - 2 && !hasWay);
	return hasWay;
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

	int i, j, path;
	cout << "From ";
	cin >> i;
	cout << " to ";
	cin >> j;
	cout << " with path = ";
	cin >> path;
	cout << "There is way " << boolalpha << hasFixedWay(matrix, size, i ,j ,path);

	for (size_t i = 0; i < size; i++)
	{
		delete[] matrix[i];
	}
	delete[]matrix;

	return 0;
}
