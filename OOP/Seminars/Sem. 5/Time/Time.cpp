#include "Time.h"
#include <iostream>
using namespace std;

size_t Time::convertToSeconds() const {
    return 3600 * mHours + 60 * mMinutes + mSeconds;
}

Time::Time() : mHours(0), mMinutes(0), mSeconds(0) {}

Time::Time(size_t hours, size_t minutes, size_t seconds) : Time() {
    setHours(hours);
    setMinutes(minutes);
    setSeconds(seconds);
}

void Time::tick() {
    mSeconds++;

    if (mSeconds >= 60) {
        mMinutes++;
        mSeconds = mSeconds - 60; // update the real seconds
    }
    if (mMinutes >= 60) {
        mHours++;
        mMinutes = mMinutes - 60; // update the real minutes
    }
    if (mHours == 24) {
        mHours = 0;
    }
}

void Time::print() const {
    cout << "Hours: " << getHours() << '\n';
    cout << "Minutes: " << getMinutes() << '\n';
    cout << "Seconds: " << getSeconds() << '\n';
}

Time Time::toMidnight() const {
    Time midnight(23, 59, 59); // calls the default constructor which is exactrly midnight
    midnight.mHours -= mHours;
    midnight.mMinutes -= mMinutes;
    midnight.mSeconds -= mSeconds;
    midnight.tick();
    return midnight;
}

bool Time::isDinnerTime() const {
    Time lowerBound(20, 30, 0);
    Time upperBound(22, 0, 0);
    return compare(lowerBound) >= 0 && compare(upperBound) <= 0;
}

bool Time::isPartyTime() const {
    Time lowerBound(23, 0, 0);
    Time upperBound(6, 0, 0);
    return compare(lowerBound) >= 0 || compare(upperBound) <= 0;
}

Time Time::difference(const Time &other) const {
    Time diff;
    int hours = mHours - other.mHours;
    diff.mHours = abs(hours);
    int minutes = mMinutes - other.mMinutes;
    diff.mMinutes = abs(minutes);
    int seconds = mSeconds - other.mSeconds;
    diff.mSeconds = abs(seconds);
    return diff;
}

int Time::compare(const Time &other) const {
    size_t mySeconds = convertToSeconds();
    size_t otherSeconds = other.convertToSeconds();

    if (mySeconds > otherSeconds)
        return 1;
    else if (mySeconds < otherSeconds)
        return -1;
    else
        return 0;
}

// setters
void Time::setHours(size_t hours) {
    if (hours < 0 || hours > 24) {
        throw "Invalid hours!";
    } else {
        mHours = hours;
        if (hours == 0 || hours == 24) {
            mHours = 0;
        }
    }
}

void Time::setMinutes(size_t minutes) {
    if (minutes < 0 || minutes > 60) {
        throw "Invalid minutes!";
    } else {
        mMinutes = minutes;
        if (minutes == 0 || minutes == 60) {
            mMinutes = 0;
        }
    }
}

void Time::setSeconds(size_t seconds) {
    if (seconds < 0 || seconds > 60) {
        throw "Invalid seconds!";
    } else {
        mSeconds = seconds;
        if (seconds == 0 || seconds == 60) {
            mSeconds = 0;
        }
    }
}