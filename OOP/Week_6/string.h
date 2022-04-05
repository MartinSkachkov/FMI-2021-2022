#ifndef STRING_H
#define STRING_H
#define DEFAULT_CAPACITY 8
#include <iostream>
using namespace std;

class String {
private:
	char* mData;
	unsigned int mCapacity;
public:
	String();
	String(const char* s);
	String(const String& source);
	String& operator=(const String& source);
	~String();

	size_t getSize() const;
	unsigned int getCapacity() const;
	String& append(const String& rhs);
	String& append(const char* rhs);
	void pushBack(char c);
	void erase();
	bool isEmpty() const;
	String& swap(String& other);

	String& operator+(const String& rhs) const;
	String& operator+=(const String& rhs) const;
	char operator[](size_t index) const;

};


#endif
