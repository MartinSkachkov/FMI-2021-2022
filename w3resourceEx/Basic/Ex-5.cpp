#include <iostream>
#include <string>
using namespace std;

int main()
{
	cout << "Enter data type:";
	string type;
	cin >> type;
	if (type == "int")
	{
		cout << "The maximum limit of int data type : " << INT_MAX << endl;
		cout << "The minimum limit of int data type : " << INT_MIN << endl;
	}
	else if (type == "unsigned int")
	{
		cout << " The maximum limit of unsigned int data type : " << UINT_MAX << endl;
	}
	else if (type == "long")
	{
		cout << " The maximum limit of long long data type : " << LLONG_MAX << endl;
		cout << " The minimum limit of long long data type : " << LLONG_MIN << endl;
	}
	else if (type == "unsigned long")
	{
		cout << " The maximum limit of unsigned long long data type : " << ULLONG_MAX << endl;
	}
	// and so one 
  return 0;
}
