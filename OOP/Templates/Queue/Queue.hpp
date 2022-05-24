#ifndef __QUEUE_H_
#define __QUEUE_H_
#include <iostream>
using namespace std;

template<typename T>
class Queue {
private:
	T* mData; //arr of type T
	size_t mSize;
	size_t mCapacity;
	size_t mGetPtr;
	size_t mPutPtr;

	void resize();
	void copy(const Queue<T>& other);
	void free();
public:
	Queue();
	Queue(const Queue<T>& other);
	Queue<T>& operator=(const Queue<T>& other);
	~Queue();

	void push(const T& value); //setter
	void push(T&& value);
	void pop();
	const T& peek() const; //getter
	bool isEmpty() const;
};

template<typename T>
void Queue<T>::resize() {
	T* resizedData = new T[mCapacity * 2];
	for (size_t i = 0; i < mSize; i++){
		resizedData[i] = mData[i];
	}
	mCapacity *= 2;
	delete[] mData;
	mData = resizedData;
	mGetPtr = 0;
	mPutPtr = mSize;
}

template<typename T>
void Queue<T>::copy(const Queue<T>& other) {
	mData = new T[other.mCapacity];
	for (size_t i = 0; i < other.mCapacity; i++) {
		mData[i] = other.mData[i];
	}
	mGetPtr = other.mGetPtr;
	mPutPtr = other.mPutPtr;
	mSize = other.mSize;
	mCapacity = other.mCapacity;
}

template <typename T>
void Queue<T>::free() {
	delete[] mData;
}

template <typename T>
Queue<T>::Queue() {
	mCapacity = 4;
	mData = new T[mCapacity];
	mSize = mGetPtr = mPutPtr = 0;
}

template <typename T>
Queue<T>::Queue(const Queue<T>& other) {
	copy(other);
}

template <typename T>
Queue<T>& Queue<T>::operator=(const Queue<T>& other) {
	if (this == &other) {
		return *this;
	}
	free();
	copy(other);
	return *this;
}

template<typename T>
Queue<T>::~Queue() {
	free();
}

template <typename T>
void Queue<T>::push(const T& value)
{
	if (mSize == mCapacity){
		resize();
	}

	mData[mPutPtr] = value; //operator=
	(++mPutPtr) %= mCapacity; //sets the put ptr to the last free position
	mSize++;
}

template <typename T>
void Queue<T>::push(T&& other) {
	if (mSize == mCapacity) {
		resize();
	}
	mData[mPutPtr] = move(other);
	(++mPutPtr) %= mCapacity;
	mSize++;
}

template <typename T>
bool Queue<T>::isEmpty() const {
	if (size == 0) {
		return true;
	}
	return false;
}

template <typename T>
void Queue<T>::pop() {
	if (isEmpty()) {
		throw logic_error("Empty queue!");
	}
	(++mGetPtr) %= mCapacity; //move it to the next position(the current where it was before will be overwritten)
	mSize--;
}


template <typename T>
const T& Queue<T>::peek() const {
	if (isEmpty()) {
		throw logic_error("Empty queue!");
	}
	return mData[mGetPtr];
}


#endif
