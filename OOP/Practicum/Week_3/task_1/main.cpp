#include "Animal.h"
#include "Zoo.h"
#include <iostream>

int main() {
    Zoo myZoo;
    myZoo.initialize();

    ofstream outfile("myZoo.txt", ios::trunc);
    myZoo.writeToStream(outfile);
    outfile.close();

    cout << "\nHas birds in the zoo?\n";
    cout << boolalpha << myZoo.hasType(Type::bird) << '\n';

    Zoo loadedZoo;
    ifstream infile("loadedZoo.txt");
    loadedZoo.loadFromStream(infile);
    loadedZoo.writeToStream(cout);
    infile.close();

    loadedZoo.free();
    myZoo.free();
    return 0;
}