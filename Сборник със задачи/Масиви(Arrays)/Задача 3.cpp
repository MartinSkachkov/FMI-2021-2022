#include <iostream>;
using namespace std;

int main()
{
	const int ARR_SIZE = 1024;
	int arr[ARR_SIZE]; //arr[1024]

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

	int counter = 0;

	for (int i = 0; i < n; i++)
	{
		if (arr[i]%2==0 && i%2==1 )
		{
			counter++;
		}
	}
	cout << endl;
	for (int i = 0; i < n; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
	cout << "The number of even elements on  odd positions is: " << counter << endl;
	return 0;
}
