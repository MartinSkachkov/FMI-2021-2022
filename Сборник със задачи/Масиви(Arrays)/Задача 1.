#include <iostream>;
using namespace std;

int main()
{
	const int ARR_SIZE = 1024;
	double arr[ARR_SIZE]; //arr[1024]

	int n;
	cout << "Enter the size of the array: ";
	cin >> n;

	try
	{
		if (n < 1 || n >1024)
		{
			throw "Invalid input\n";
		}
	}
	catch (const char* error)
	{
		cout << error;
		do
		{
			cout << "Enter a valid range between [1;30]: ";
			cin >> n;
		} while (n < 1 || n >1024);
	}
	for (int i = 0; i < n; i++)
	{
		cout << "arr[" << i << "]-";
		cin >> arr[i];
	}
	int maxEl = arr[0];
	for (int i = 0; i < n; i++)
	{
		if (maxEl<arr[i])
		{
			maxEl = arr[i];
		}
	}
	for (int i = 0; i < n; i++)
	{
		cout << arr[i] << " ";
	}
	cout << "Max element is: " << maxEl;
	return 0;
}
