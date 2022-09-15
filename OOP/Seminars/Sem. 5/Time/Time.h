#ifndef _TIME_H_
#define _TIME_H_
#include <cstdlib>

class Time {
private:
    size_t mHours;
    size_t mMinutes;
    size_t mSeconds;

    size_t convertToSeconds() const;

public:
    Time();
    Time(size_t hours, size_t minutes, size_t seconds);

    void tick();
    void print() const;
    Time toMidnight() const;
    bool isDinnerTime() const;
    bool isPartyTime() const;
    Time difference(const Time &other) const;
    int compare(const Time &other) const;

    // getters - needed for the print func
    size_t getHours() const { return mHours; }
    size_t getMinutes() const { return mMinutes; }
    size_t getSeconds() const { return mSeconds; }

    // setters - needed for validation of the input
    void setHours(size_t hours);
    void setMinutes(size_t minutes);
    void setSeconds(size_t seconds);
};

#endif