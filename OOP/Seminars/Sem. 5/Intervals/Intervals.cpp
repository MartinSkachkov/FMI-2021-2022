#include <iostream>
using namespace std;

class Interval {
private:
    int mMin;
    int mMax;

public:
    Interval() : mMin(0), mMax(0) {} //[0,0]
    Interval(int min, int max);

    void setInterval(int min, int max);

    int getA() const;
    int getB() const;

    int intervalLength() const;
    bool isInInterval() const;
    int primeInInterval() const;
    int palindromesInInterval() const;
    int noMatchesInNumbers() const;

    bool powerOfTwo() const;
    Interval intersect(const Interval &interval) const;
    Interval intervalUnion(const Interval &interval) const;
    bool isSuperInterval(const Interval &interval) const;
};

Interval::Interval(int min, int max) {
    setInterval(min, max);
}

void Interval::setInterval(int min, int max) {
    if (min <= max) {
        this->mMin = min;
        this->mMax = max;
    } else {
        this->mMin = 0;
        this->mMax = 0;
    }
}

int Interval::getA() const {
    return this->mMin; // returns a copy
}

int Interval::getB() const {
    return this->mMax; // returns a copy
}

int Interval::intervalLength() const {
    unsigned int counter = 0;
    for (int i = this->mMin; i <= this->mMax; i++) {
        counter++;
    }
    return counter;
}

bool Interval::isInInterval() const {
    int input;
    cout << "Check if your number is in the interval: ";
    cin >> input;

    for (int i = this->mMin; i <= this->mMax; i++) {
        if (input == i) {
            return true;
        }
    }
    return false;
}

int Interval::primeInInterval() const {
    int flag;
    unsigned int counter = 0;
    for (int i = this->mMin; i <= this->mMax; i++) {
        if (i <= 0 || i == 1) { // skip <=0 and 1 as they are not prime
            continue;
        }
        flag = 0;

        for (int j = 2; j <= i / 2; j++) {
            if (i % j == 0) { // condition for not prime
                flag = 1;
            }
        }
        if (flag == 0) {
            counter++;
            // cout << i;
        }
    }
    return counter;
}

int Interval::palindromesInInterval() const {
    unsigned int counter = 0;
    for (int i = this->mMin; i <= this->mMax; i++) {
        int original = abs(i), reversed = 0, remainder = 0;
        while (original != 0) {
            remainder = original % 10;
            reversed = reversed * 10 + remainder;
            original /= 10;
        }
        if (i == reversed) { // Negative numbers are not palindromic
            counter++;
        }
    }
    return counter;
}

int Interval::noMatchesInNumbers() const {
    int counter = 0;
    for (int currentNumber = this->mMin; currentNumber <= this->mMax; currentNumber++) {
        int currentNumberCopy = abs(currentNumber);
        int arr[10] = {0};
        int digit, flag = 0;

        while (currentNumberCopy != 0) {
            digit = currentNumberCopy % 10;
            if (arr[digit] == 1) {
                flag = 1; // found number with matching digits
                break;
            } else {
                arr[digit] = 1;
            }
            currentNumberCopy /= 10;
        }
        if (flag == 0) {
            counter++;
        }
    }
    return counter;
}

bool isPowerOfTwo(int n) {
    if (n > 0) {
        while (n % 2 == 0) {
            n /= 2;
        }
        if (n == 1) {
            return true;
        }
    }
    if (n == 0 || n != 1) {
        return false;
    }
}

bool Interval::powerOfTwo() const {
    return isPowerOfTwo(getA()) && isPowerOfTwo(getB());
}

Interval Interval::intervalUnion(const Interval &secondInterval) const {
    Interval united; // the default constructor sets the values to [0,0]

    if (this->mMin <= secondInterval.mMax && secondInterval.mMin <= this->mMax) {
        united.mMin = min(this->mMin, secondInterval.mMin);
        united.mMax = max(this->mMax, secondInterval.mMax);
        return united;
    }
    return united;
}

Interval Interval::intersect(const Interval &secondInterval) const {
    Interval intersection;

    if (this->mMin <= secondInterval.mMax && this->mMax >= secondInterval.mMin) { // condition for intersection
        intersection.mMin = max(this->mMin, secondInterval.mMin);
        intersection.mMax = min(this->mMax, secondInterval.mMax);
    }
    return intersection;
}

bool Interval::isSuperInterval(const Interval &secondInterval) const {
    if (this->mMin <= secondInterval.mMin && secondInterval.mMax <= this->mMax) {
        return true;
    } else {
        return false;
    }
}

int main() {
    Interval t1(3, 10); // [3, 10]
    Interval t2(4, 14); // [4, 14]
    Interval t3;        // [0, 0]

    Interval result = t1.intersect(t2); // [4, 10]
    cout << result.getA() << ',' << result.getB() << endl;
    cout << boolalpha << t2.isSuperInterval(result) << endl; // true

    cout << result.primeInInterval(); // 2 (only 5 and 7)
    return 0;
}