#ifndef _Person_H
#define _Person_H

class Person {
private:
	char* name;
	int age;

	void copyFrom(const Person& source);
	void free();

public:
	//constructors
	Person();
	Person(const char* name, int age);

	//copy-constr and op=
	Person(const Person& source);
	Person& operator=(const Person& source);

	//getters
	const char* getName()const;
	int getAge()const;

	//setters
	void setName(const char* name);
	void setAge(int age);

	//destr
	~Person();
	void print() const;
};

#endif
