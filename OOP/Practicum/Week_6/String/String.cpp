#include "String.h"
#include <cstring>
#include <iostream>
#define MAX_CAP 8
using namespace std;

void String::resize(size_t newCapacity) {
    char *copy = mData;
    mData = new char[newCapacity + 1]; // resizing
    strcpy_s(mData, strlen(copy) + 1, copy);
    delete[] copy;
}

void String::copy(const String &other) {
    mData = new char[other.mCapacity + 1];
    strcpy_s(mData, other.mCapacity + 1, other.mData);

    mCapacity = other.mCapacity;
}

void String::free() {
    delete[] mData;
}

// Big 4
String::String() : mData(nullptr), mCapacity(MAX_CAP) {
    mData = new char[mCapacity + 1];
    mData[0] = 0;
}

String::String(const char *string) : mData(nullptr), mCapacity(MAX_CAP) {
    if (mCapacity < strlen(string)) {
        resize(strlen(string));
        mCapacity = strlen(string);
    }

    mData = new char[mCapacity + 1];
    strcpy_s(mData, mCapacity + 1, string);
}

String::String(const String &other) {
    copy(other);
}

String &String::operator=(const String &other) {
    if (this == &other) {
        return *this;
    }
    free();
    copy(other);
    return *this;
}

String::~String() {
    free();
}

// mem-funcs
String &String::append(const String &other) {
    return append(other.mData);
}

String &String::append(const char *other) {
    if (mCapacity < (strlen(mData) + strlen(other))) {
        resize(strlen(mData) + strlen(other));
        mCapacity = strlen(mData) + strlen(other);
    }
    strcat_s(mData, mCapacity + 1, other);
    return *this;
}

void String::pushBack(char c) {
    if (mCapacity < strlen(mData) + 1) {
        resize(strlen(mData) + 1);
        mCapacity = strlen(mData) + 1;
    }
    mData[strlen(mData)] = c;
    mData[strlen(mData)] = 0;
}

void String::erase() {
    mCapacity = MAX_CAP;
    free();
    mData = new char[mCapacity + 1];
    mData[0] = 0;
}

bool String::isEmpty() const {
    if (strlen(mData) == 0) {
        return true;
    }
    return false;
}

void String::swap(String &other) {
    std::swap(mCapacity, other.mCapacity);
    // we redirect the pointers not the info
    char *tempData = mData;
    mData = other.mData;
    other.mData = tempData;
}

String *String::substr(size_t start, size_t end) const {
    String *substring = new String;
    if (substring->mCapacity < end - start + 1) {
        substring->resize(end - start + 1);
        substring->mCapacity = end - start + 1;
    }

    size_t index = 0;
    for (size_t i = start; i <= end; i++) {
        substring->mData[index++] = mData[i];
    }
    substring->mData[mCapacity + 1] = 0;
    return substring;
}

// getters
const char *String::getData() const {
    return mData;
}

size_t String::getSize() const {
    return strlen(mData);
}

size_t String::getCapacity() const {
    return mCapacity;
}

// operator overloading
String String::operator+(const String &rhs) const {
    char *buff = new char[strlen(mData) + strlen(rhs.mData) + 1];
    strcpy(buff, mData);
    strcat(buff, rhs.mData);
    String result(buff);
    delete[] buff;
    return result;
}

String &String::operator+(const String &rhs) {
    size_t concatLen = strlen(mData) + strlen(rhs.mData);
    if (mCapacity < concatLen) {
        resize(concatLen);
        mCapacity = concatLen;
    }
    strcat(mData, rhs.mData);
    return *this;
}

String &String::operator+=(const String &rhs) {
    return append(rhs);
}

char String::operator[](size_t index) const {
    if (index > strlen(mData)) {
        throw "Index out of bounds!\n";
    }
    return mData[index];
}

char &String::operator[](size_t index) {
    if (index > strlen(mData)) {
        throw "Index out of bounds!\n";
    }
    return mData[index];
}

bool String::operator!=(const String &rhs) const {
    return !(*this == rhs); // this will use operator==
}

bool String::operator==(const String &rhs) const {
    return strcmp(mData, rhs.mData) == 0 && mCapacity == rhs.mCapacity;
}

ostream &operator<<(ostream &out, const String &str) {
    out << "Capacity: " << str.mCapacity << '\n'
        << "String: " << str.mData << '\n';
    return out;
}
