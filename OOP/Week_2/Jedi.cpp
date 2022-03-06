#include <iostream>
#include <cstring>
using namespace std;
#define MAX_SIZE 1024


enum SaberType {
	SINGLEBLADED = 1,
	DOUBLE_BLADED,
	CROSSGUARD
};

struct Lightsaber {
	char* color;
	SaberType type;
};

struct Jedi {
	char* name;
	int age;
	int power;
	Lightsaber lightsaber;
	double health;
};

void initializeSaber(Jedi& jedi) {
	char color[MAX_SIZE];
	cout << "Input color: ";
	cin >> color;

	jedi.lightsaber.color = new char[strlen(color) + 1]; //aloc memory +1 for \0
	strcpy_s(jedi.lightsaber.color, sizeof(color), color);

	cout << "Choose your lightsaber:\n";
	cout << "1. SINGLEBLADED\n";
	cout << "2. DOUBLE_BLADED\n";
	cout << "3. CROSSGUARD\n";

	int choice;
	cin >> choice;

	switch (choice)
	{
	case 1: jedi.lightsaber.type = SaberType::SINGLEBLADED; break;
	case 2: jedi.lightsaber.type = SaberType::DOUBLE_BLADED; break;
	case 3: jedi.lightsaber.type = SaberType::CROSSGUARD; break;
	default: throw "INVALID INPUT!";
		break;
	}
}

void initializeJedi(Jedi& jedi) {
	char name[MAX_SIZE];
	cout << "Name of the Jedi: ";
	cin >> name;

	jedi.name = new char[strlen(name) + 1];
	strcpy_s(jedi.name, sizeof(name), name);

	cout << "Jedi age: ";
	cin >> jedi.age;

	cout << "Jedi power: ";
	cin >> jedi.power;

	initializeSaber(jedi);

	jedi.health = 100;
}

void printSaber(Lightsaber& lightSaber) {

	const char* types[] = { "SINGLEBLADED","DOUBLE_BLADED","CROSSGUARD" };
	cout << "Saber color: " << lightSaber.color << endl;
	cout << "Saber type: " << types[lightSaber.type - 1];


	/*switch (lightSaber.type)
	{
	case 1:cout << "SINGLEBLADED"; break;
	case 2:cout << "DOUBLE_BLADED"; break;
	case 3:cout << "CROSSGUARD"; break;
	default: throw "Error";
		break;
	}*/

}

void printJedi(Jedi& jedi) {
	cout << "Name: " << jedi.name << endl;
	cout << "Age: " << jedi.age << endl;
	cout << "Power: " << jedi.power << endl;
	printSaber(jedi.lightsaber);
	cout << "HP: " << jedi.health << endl;
}

void killJedi(Jedi& jedi) {
	delete[] jedi.name;
	delete[] jedi.lightsaber.color;
}

void battle(Jedi& jedi1, Jedi& jedi2) {

	cout << "Epic battle (" << jedi1.name << "vs" << jedi2.name << ")\n";


	double jedi1Dmg = jedi1.power * jedi1.lightsaber.type * strlen(jedi1.lightsaber.color) / jedi1.age;
	double jedi2Dmg = jedi2.power * jedi2.lightsaber.type * strlen(jedi2.lightsaber.color) / jedi2.age;

	while (jedi1.health > 0 && jedi2.health > 0)
	{
		jedi1.health -= jedi2Dmg > 0 ? jedi1.health - jedi2Dmg : 0;
		jedi2.health -= jedi1Dmg > 0 ? jedi2.health - jedi1Dmg : 0;
	}

	if (jedi1.health > 0 || jedi2.health > 0)
	{
		cout << "-----Winner-----\n";
		if (jedi1.health > 0)
		{
			printJedi(jedi1);
		}
		if (jedi2.health > 0)
		{
			printJedi(jedi2);
		}
		std::cout << "----------------\n";
	}
	else {
		cout << "No winner";
	}
}

int main() {
	Jedi jedi1, jedi2;
	initializeJedi(jedi1);
	printJedi(jedi1);

	initializeJedi(jedi2);
	printJedi(jedi2);

	battle(jedi1, jedi2);

	killJedi(jedi1);
	killJedi(jedi2);

	return 0;
}
