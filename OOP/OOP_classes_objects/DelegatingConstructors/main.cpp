// Section 13
// Delegating Constructors
#include <iostream>
#include <string>

using namespace std;

class Player {
private:
    std::string name;
    int health;
    int xp;

public:
    // Overloaded Constructors
    Player();
    Player(std::string name_val);
    Player(std::string name_val, int health_val, int xp_val);
};

Player::Player()
    : Player{"None", 0, 0} { // calls three args-constructor and returns
    cout << "No-args constructor" << endl;
}

Player::Player(std::string name_val)
    : Player{name_val, 0, 0} { // calls three args-constructor and returns
    cout << "One-arg constructor" << endl;
}

Player::Player(std::string name_val, int health_val, int xp_val)
    : name{name_val}, health{health_val}, xp{xp_val} {
    cout << "Three-args constructor" << endl;
}

int main() {

    Player empty;          // calls no-args constuctor
    Player frank{"Frank"}; // calls one-arg constructor
    Player villain{"Villain", 100, 55};

    return 0;
}
