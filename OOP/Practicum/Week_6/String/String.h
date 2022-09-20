#ifndef _STRING_H_
#define _STRING_H_
#include <cstdlib>
#include <fstream>

class String {
private:
    char *mData;      // the string
    size_t mCapacity; // the number of max symbols in the string
    void resize(size_t newCapacity);
    void copy(const String &other);
    void free();

public:
    // Big 4
    String();
    String(const char *string);
    String(const String &other);
    String &operator=(const String &other);
    ~String();

    // mem functions
    String &append(const String &other);
    String &append(const char *other);
    String *substr(size_t start, size_t end) const;
    void pushBack(char c);
    void erase();
    bool isEmpty() const;
    void swap(String &other);

    // getters
    const char *getData() const;
    size_t getSize() const;
    size_t getCapacity() const;

    // operator overloading
    String operator+(const String &rhs) const; // here we create a new object which we return as a copy
    String &operator+(const String &rhs);      // we return a ref so we can chain(also we concat the *this obj to rhs)
    String &operator+=(const String &rhs);
    char operator[](size_t index) const;
    char &operator[](size_t index);
    bool operator!=(const String &rhs) const;
    bool operator==(const String &rhs) const;
    friend std::ostream &operator<<(std::ostream &out, const String &str);
};

#endif