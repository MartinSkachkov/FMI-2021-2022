#include <cstring>
#include <iostream>
using namespace std;

class Student {
private:
    int age;
    char *name;

public:
    Student(int stAge = 0, const char *stName = "None") { // constructor (in this case it is also a default)
        age = stAge;
        name = new char[strlen(stName) + 1];
        strcpy(name, stName);

        // setName(stName);
        // setAge(stAge);
    }
    ~Student() { // destructor
        delete[] name;
    }

    // void setName(const char* name);
    // void setAge(int age);

    int getAge() { return age; }
    char *getName() { return name; }
};

int main() {
    Student st(20, "Martin");
    cout << st.getAge() << ' ' << st.getName();
}