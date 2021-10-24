#include <iostream>
using namespace std;

int main()
{
	int n, distance = 0;
	cout << "Въведи броя на трохите: ";
	cin >> n; // 2

	for (size_t i = 2; i <= (3 * n - 1); i += 3) //2 <= 5; 5=5
	{
		distance += 2 * i; // 4; 4 + (2*5)
	}

	cout << distance << endl;
	return 0;
}
