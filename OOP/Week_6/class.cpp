#include "String.h"
#include <cstring>

size_t String::getSize() const {
	return strlen(mData);
}

unsigned int String::getCapacity() const {
	return mCapacity;
}

String& String::append(const String& rhs) {
	size_t buffSize = strlen(mData) + strlen(rhs.mData) + 1;
	char* buff = new char[buffSize];
	strcpy(buff, mData);
	strcat(buff, rhs.mData);
	buff[buffSize] = 0;
	delete[] mData;
	mData = buff;
	return *this;
}

String& String::append(const char* rhs) {
	size_t buffSize = strlen(mData) + strlen(rhs) + 1;
	char* buff = new char[buffSize];
	strcpy(buff, mData);
	strcat(buff, rhs);
	buff[buffSize] = 0;
	delete[] mData;
	mData = buff;
	return *this;
}

void String::pushBack(char c) {
	size_t size = getSize();
	size++;
	char* buff = new char[size + 1];
	strcpy(buff, mData);
	buff[size - 1] = c;
	buff[size] = 0;
	delete[] mData;
	mData = buff;
}

void String::erase() {
	for (int i = 0; i < getSize(); i++) {
		mData[i] = 0;
	}
	mCapacity = DEFAULT_CAPACITY;
}

bool String::isEmpty() const {
	if (getSize() == 0) {
		return true;
	}
	else {
		return false;
	}
}

String& String::swap(String& other) {
	unsigned int newSize;
	if (getSize() >= strlen(other.mData)) {
		newSize = getSize();
	}
	else {

	}
}

String& String::operator+(const String& rhs) const{
	return append(rhs);
}

String& String::operator+=(const String& rhs) const {
	String& newString(append(rhs));
	return newString;
}

char String::operator[](size_t index) const {
	return mData[index];
}
