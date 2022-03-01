#include <iostream>
using namespace std;

struct Part; //declare a structure

struct Part //define a structure
{
	int modelnumber; //дефиниц. на полета
	int partnumber;
	float cost;
};

int main() {
	
	Part part1, part2 = {53, 68, 4.25}; //defines structure variable //initialize variable part2
	cin>>part1.modelnumber; //gives values to structure members
	cin>>part1.partnumber;
	cin>>part1.cost;

	//part1 = part2; //structure variable can be assigned to another(the value of each
	//member of part1 is assigned to each member of part2

	cout << part1.modelnumber << endl << part1.partnumber << endl << part1.cost << endl;
	cout << "Part 2: " << endl << part2.modelnumber << endl << part2.partnumber << endl << part2.cost;
	cout << endl << sizeof(Part);
	return 0;
}
