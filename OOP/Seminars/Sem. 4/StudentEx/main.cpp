#include <iostream>
using namespace std;
#include "Student.h"

int main() {
    Student random;
    random.print();

    Student martin("Martin Skachkov", 20);
    martin.print();
    cout << "Name (through getter): " << martin.getName() << '\n';
    cout << "Age (through getter): " << martin.getAge() << '\n';

    random.setName();
    random.setAge();
    random.print();

    Student copy(random); // copy constructor
    cout << "Copy print\n";
    copy.print();

    cout << "Assignment print\n";
    martin = copy; // op=
    martin.print();

    return 0;
}