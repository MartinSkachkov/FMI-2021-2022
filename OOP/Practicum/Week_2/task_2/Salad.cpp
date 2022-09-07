#include <cstring>
#include <iostream>
#define MAX_SIZE 20
using namespace std;

enum Taste {
    SOUR = 1,
    SWEET,
    BITTER,
    SPICY
};

struct Vegetable {
    char *mName;
    Taste mTaste;
    double mWeight;

    void init();
    void free();
};

void Vegetable::init() {
    cout << "Vegetable name: ";
    char name[MAX_SIZE] = {0};
    cin.ignore();
    cin.getline(name, MAX_SIZE);
    mName = new char[strlen(name) + 1];
    strcpy(mName, name);

    cout << "Tastes:\n"
         << "1) SOUR\n"
         << "2) SWEET\n"
         << "3) BITTER\n"
         << "4) SPICY\n"
         << "Choice: ";
    size_t choice;
    cin >> choice;

    switch (choice) {
    case 1:
        mTaste = SOUR;
        break;
    case 2:
        mTaste = SWEET;
        break;
    case 3:
        mTaste = BITTER;
        break;
    case 4:
        mTaste = SPICY;
        break;
    default:
        throw "Invalid input!";
        break;
    }

    cout << "Vegetable weight (gr): ";
    cin >> mWeight;
}

void Vegetable::free() {
    delete[] mName;
}

struct Dressing {
    char *mName;
    Taste mTaste;
    double mQuantity;
    char **mAlergens;
    size_t mAlergQuant;

    void init();
    void printAlrgens() const;
    void free();
};

void Dressing::init() {
    cout << "Dressing name: ";
    char name[MAX_SIZE] = {0};
    cin.ignore();
    cin.getline(name, MAX_SIZE);
    mName = new char[strlen(name) + 1];
    strcpy(mName, name);

    cout << "Tastes:\n"
         << "1) SOUR\n"
         << "2) SWEET\n"
         << "3) BITTER\n"
         << "4) SPICY\n"
         << "Choice: ";
    size_t choice;
    cin >> choice;

    switch (choice) {
    case 1:
        mTaste = SOUR;
        break;
    case 2:
        mTaste = SWEET;
        break;
    case 3:
        mTaste = BITTER;
        break;
    case 4:
        mTaste = SPICY;
        break;
    default:
        throw "Invalid input!";
        break;
    }

    cout << "Dressing quantity (ml): ";
    cin >> mQuantity;

    cout << "Number of alergens: ";
    cin >> mAlergQuant;

    cout << "Alergens\n";
    mAlergens = new (nothrow) char *[mAlergQuant];
    if (!mAlergens) {
        throw "Couldn't allocate mem";
    }
    cin.ignore();
    for (size_t i = 0; i < mAlergQuant; i++) {
        cout << "alergen " << '(' << i + 1 << ')' << ": ";
        char input[MAX_SIZE];
        cin.getline(input, MAX_SIZE);
        mAlergens[i] = new (nothrow) char[strlen(input) + 1];
        if (!mAlergens[i]) {
            throw "Couldn't allocate mem";
        }
        strcpy(mAlergens[i], input);
    }
}

void Dressing::free() {
    for (size_t i = 0; i < mAlergQuant; i++) {
        delete[] mAlergens[i];
    }
    delete[] mAlergens;
    delete[] mName;
}

void Dressing::printAlrgens() const {
    cout << "Alergens list:\n";
    for (size_t i = 0; i < mAlergQuant; i++) {
        cout << mAlergens[i] << '\n';
    }
}

struct Salad {
    char *mName;
    size_t mVegQuantity;
    Vegetable *vegetables;
    size_t mDresQuantity;
    Dressing *dressings;

    void initializeSalad();
    double getWeight() const;
    Taste getTaste() const;
    void printAlerg() const;
    void print() const;
    void free();
};

void Salad::initializeSalad() {
    cout << "===Salad Maker===\n"
         << "Salad name: ";
    char name[MAX_SIZE] = {0};
    cin.getline(name, MAX_SIZE);
    mName = new char[strlen(name) + 1];
    strcpy(mName, name);

    cout << "Number of veggies: ";
    cin >> mVegQuantity;
    vegetables = new Vegetable[mVegQuantity];
    for (size_t i = 0; i < mVegQuantity; i++) {
        vegetables[i].init();
    }

    cout << "Number of dressings: ";
    cin >> mDresQuantity;
    dressings = new Dressing[mDresQuantity];
    for (size_t i = 0; i < mDresQuantity; i++) {
        dressings[i].init();
    }
}

double Salad::getWeight() const {
    double total = 0;
    for (size_t i = 0; i < mVegQuantity; i++) {
        total += vegetables[i].mWeight;
    }

    for (size_t i = 0; i < mDresQuantity; i++) {
        total += dressings[i].mQuantity;
    }
    return total;
}

Taste Salad::getTaste() const {
    int tastes[4] = {0};
    for (size_t i = 0; i < mVegQuantity; i++) {
        tastes[vegetables[i].mTaste - 1]++;
    }
    for (size_t i = 0; i < mDresQuantity; i++) {
        tastes[dressings[i].mTaste - 1]++;
    }

    int max = tastes[0];
    int maxInd = 0;
    for (size_t i = 0; i < 4; i++) {
        if (max < tastes[i]) {
            max = tastes[i];
            maxInd = i;
        }
    }
    return (Taste)(maxInd + 1);
}

void Salad::printAlerg() const {
    for (size_t i = 0; i < mDresQuantity; i++) {
        cout << "Alergens for dressing (" << i + 1 << ") : ";
        dressings[i].printAlrgens();
        cout << '\n';
    }
}

void Salad::print() const {
    cout << "-----------------------" << mName << "-----------------------\n";
    cout << "Contents: ";
    for (size_t i = 0; i < mVegQuantity; i++) {
        cout << vegetables[i].mName << ", ";
    }
    cout << endl;
    for (size_t i = 0; i < mDresQuantity; i++) {
        cout << dressings[i].mName;
        if (i != mDresQuantity - 1) {
            cout << ", ";
        }
    }

    cout << endl
         << endl;
    cout << "Quantity: " << getWeight() << "\n";
    cout << endl;

    cout << "Description: " << getTaste() << "\n";
    cout << endl;

    cout << "Alergens:\n";
    printAlerg();
    cout << endl;
    cout << "----------------------- Bon appetit! -----------------------\n";
}

void Salad::free() {
    delete[] mName;
    for (size_t i = 0; i < mVegQuantity; i++) {
        vegetables[i].free();
    }
    for (size_t i = 0; i < mDresQuantity; i++) {
        dressings[i].free();
    }

    delete[] vegetables;
    delete[] dressings;
}

main() {
    Salad salad;
    salad.initializeSalad();
    salad.print();
    salad.free();
    return 0;
}