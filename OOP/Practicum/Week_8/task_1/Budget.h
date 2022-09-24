#ifndef _BUDGET_H_
#define _BUDGET_H_
#include <fstream>

class Budget {
private:
    double mFacultyBudget;
    static double mUniBudget; // variable shared by all of the class instances
public:
    // we dont need Big 4 because we don't have dynamic mem
    Budget(double facultyBudget = 0);

    void addToBudget(double money);
    static void addFromAdmin(double money);

    double getFacultyBydget() const { return mFacultyBudget; }
    double getUniversityBudget() const { return mUniBudget; }

    Budget &operator+=(double money);
    Budget &operator-=(double money);
    bool operator==(const Budget &rhs) const;
    bool operator!=(const Budget &rhs) const;

    friend std::ostream &operator<<(std::ostream &out, const Budget &b);
    friend std::istream &operator>>(std::istream &in, Budget &b);
};

// const Budget operator+(const Budget &lhs, const Budget &rhs);
// const Budget operator-(const Budget &lhs, const Budget &rhs);

#endif