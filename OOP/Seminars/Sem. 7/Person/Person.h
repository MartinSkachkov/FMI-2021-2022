#ifndef _PERSON_H_
#define _PERSON_H_
#include <cstdlib>
#include <fstream>

class Person {
private:
    char *mName = nullptr;
    size_t mAge = 0;

    void free();
    void copy(const Person &other);

public:
    Person(const char *name, size_t age);
    Person(const Person &other);
    Person &operator=(const Person &other);
    ~Person();

    friend std::ostream &operator<<(std::ostream &out, const Person &p);
    friend std::istream &operator>>(std::istream &in, Person &p);
};

#endif