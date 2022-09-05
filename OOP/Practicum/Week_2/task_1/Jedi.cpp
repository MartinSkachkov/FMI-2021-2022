#include <iostream>
#define MAX_LEN 15
using namespace std;

size_t strlen(const char *str) {
    size_t len = 0;
    while (*str != 0) {
        str++;
        len++;
    }
    return len;
}

void strcpy(char *destination, const char *source) {
    size_t sourceLen = strlen(source);
    for (size_t i = 0; i < sourceLen; i++) {
        destination[i] = source[i];
    }
}

// An enum variable takes only one value out of many possible values
enum LightSaberType {
    SINGLEBLADED = 1,
    DOUBLE_BLADED,
    CROSSGUARD
};

struct LightSaber {
    char *color;
    LightSaberType type;
};

struct Jedi {
    char *name;
    size_t age;
    int strength;
    LightSaber lightSaber;
    double health;
};

void initializeSaber(Jedi &jedi) {
    cout << "Lightsaber types:\n"
         << "1) SINGLEBLADED\n"
         << "2) DOUBLE_BLADED\n"
         << "3) CROSSGUARD\n";

    int choice;
    cout << "Your choice: ";
    cin >> choice;

    switch (choice) {
    case 1:
        jedi.lightSaber.type = LightSaberType::SINGLEBLADED;
        break;
    case 2:
        jedi.lightSaber.type = LightSaberType::DOUBLE_BLADED;
        break;
    case 3:
        jedi.lightSaber.type = LightSaberType::CROSSGUARD;
        break;
    default:
        throw "Invalid input! Enter again!";
        break;
    }

    cout << "Color: ";
    char color[MAX_LEN];
    cin.ignore();
    cin.getline(color, MAX_LEN);

    jedi.lightSaber.color = new char[strlen(color) + 1];
    strcpy(jedi.lightSaber.color, color);
}

void initializeJedi(Jedi &jedi) {
    cout << "===Initialize_Jedi===\n";

    cout << "Name: ";
    char name[MAX_LEN];
    // cin.ignore();
    cin.getline(name, MAX_LEN);

    jedi.name = new char[strlen(name) + 1];
    strcpy(jedi.name, name);

    cout << "Age: ";
    cin >> jedi.age;

    cout << "Strength: ";
    cin >> jedi.strength;

    try {
        initializeSaber(jedi);
    } catch (const char *err) {
        cout << err;
        initializeSaber(jedi);
    }

    jedi.health = 100;
    cout << "Starting health: " << jedi.health;
}

void printSaber(const LightSaber &lightSaber) {
    cout << "Saber color: " << lightSaber.color << '\n';
    const char *types[] = {"SINGLEBLADED",
                           "DOUBLE_BLADED",
                           "CROSSGUARD"};

    cout << "Saber type: " << types[lightSaber.type - 1] << '\n';
}

void printJedi(const Jedi &jedi) {
    cout << "====Jedi_Info====\n"
         << "Name: " << jedi.name << '\n'
         << "Age: " << jedi.age << '\n'
         << "Strength: " << jedi.strength << '\n';
    printSaber(jedi.lightSaber);
    cout << "Health: " << jedi.health << '\n';
}

void turfOffLightSaber(LightSaber &lightSaber) {
    delete[] lightSaber.color;
}

void killJedi(Jedi &jedi) {
    delete[] jedi.name;
    turfOffLightSaber(jedi.lightSaber);
}

//(сила * тип на lightsaber * брой букви от цвета на lightsaber) / възраст
void battle(Jedi &jedi1, Jedi &jedi2) {
    cout << "Battle: " << jedi1.name << " vs " << jedi2.name << '\n';
    double jedi1Dmg = (jedi1.strength * jedi1.lightSaber.type * strlen(jedi1.lightSaber.color)) / jedi1.age;
    double jedi2Dmg = (jedi2.strength * jedi2.lightSaber.type * strlen(jedi2.lightSaber.color)) / jedi2.age;

    // while they are both alive - fight
    while (jedi1.health > 0 && jedi2.health > 0) {
        jedi1.health = jedi1.health - jedi2Dmg > 0 ? jedi1.health - jedi1Dmg : 0;
        jedi2.health = jedi2.health - jedi1Dmg > 0 ? jedi2.health - jedi2Dmg : 0;
    }

    if (jedi1.health > 0 || jedi2.health > 0) {
        cout << "===Winner===\n";
        if (jedi1.health > 0) {
            printJedi(jedi1);
            if (jedi2.health > 0) {
                printJedi(jedi2);
            }
        }
    } else {
        cout << "No winner!";
    }
}

int main() {
    Jedi jedi1, jedi2;
    initializeJedi(jedi1);
    cout << '\n';
    initializeJedi(jedi2);
    cout << '\n';

    printJedi(jedi1);
    printJedi(jedi2);
    cout << '\n';

    battle(jedi1, jedi2);

    killJedi(jedi1);
    killJedi(jedi2);

    return 0;
}
