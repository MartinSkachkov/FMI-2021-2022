#include <iostream>
using namespace std;

int main()
{
	int sum = 0 , upper_limit, lower_limit;
        cout << "Въведете долната граница: " ;
        cin >> lower_limit;

        cout << "Въведете горната граница: ";
        cin >> upper_limit;

        
        for(int i = lower_limit; i <= upper_limit; i++)
        {
        sum += i;
        }

        cout<<"Сумата на числата от интервала [" << lower_limit << ";" << upper_limit << "] e: " << sum;
        return 0;
}
