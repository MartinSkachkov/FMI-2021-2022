#ifndef _STUDENT_H_
#define _STUDENT_H_
#include <cstdlib>

class Student {
private:
    char *mName;
    size_t mAge;

    void copy(const Student &other);
    void free();

public:
    Student(const char *name = "None", size_t age = 0);
    Student(const Student &other);
    Student &operator=(const Student &other);
    ~Student();

    void print() const;

    // setters - needed for the private attributes to access them
    void setName();
    void setAge();

    // getters - needed for the private attributes to access them
    const char *getName() const;
    size_t getAge() const;
};

#endif