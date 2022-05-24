#include <iostream>

template <typename T, typename D>
class Pair {
private:
	T mFirst;
	D mSecond;
public:
	Pair() = default;
	Pair(const T& first, const D& second);

	const T& getFirst() const;
	const D& getSecond() const;
	void setFirst(const T& newFirst);
	void setSecond(const D& newSecond);
};

template<typename T, typename D>
Pair<T, D>::Pair(const T& first, const D& second) : mFirst(first), mSecond(second)
{}

template<typename T, typename D>
const T& Pair<T, D>::getFirst() const {
	return mFirst;
}

template <typename T, typename D>
const D& Pair<T, D>::getSecond() const {
	return mSecond;
}

template <typename T, typename D>
void Pair<T, D>::setFirst(const T& newFirst) {
	mFirst = newFirst;
}

template<typename T, typename D>
void Pair<T, D>::setSecond(const D& newSecond) {
	mSecond = newSecond;
}
