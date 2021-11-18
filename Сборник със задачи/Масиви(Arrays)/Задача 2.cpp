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

	int counter0 = 0, counter1 = 0, counter2 = 0;

	for (int i = 0; i < n; i++)
	{
		if (arr[i] == 0) counter0++;
		else if (arr[i] == 1) counter1++;
		else if (arr[i] == 2) counter2++;
	}
	cout << endl;
	for (int i = 0; i < n; i++)
	{
		cout << arr[i] << " ";
	}
	cout << "(0) appears: " << counter0<<endl
		<< "(1) appears: " << counter1 << endl
		<< "(2) appears: " << counter2 << endl;
	return 0;
}
