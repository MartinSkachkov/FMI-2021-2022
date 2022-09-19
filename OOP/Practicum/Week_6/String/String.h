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

    String &append(const String &other);
    String &append(const char *other);
    String *substr(size_t start, size_t end) const;

    void erase();
    bool isEmpty() const;
    void swap(String &other);

    // getters
    size_t getSize() const;
    size_t getCapacity() const;

    friend std::ostream &operator<<(std::ostream &out, const String &str);
};

#endif