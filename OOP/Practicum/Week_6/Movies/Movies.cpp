#include "Movies.h"
#include <cstring>
#include <iostream>
using namespace std;

void Movies::copy(const Movies &other) {
    mMovies = new Movie[other.mCapacity];
    for (size_t i = 0; i < other.mCapacity; i++) {
        mMovies[i] = other.mMovies[i]; // op= for Movie
    }

    mSize = other.mSize;
    mCapacity = other.mCapacity;
}

void Movies::free() {
    delete[] mMovies; // destructor of Movie
}

void Movies::resize(size_t newCapacity) {
    Movie *save = mMovies;            // copy the pointer of the mMovies
    mMovies = new Movie[newCapacity]; // allocate larger block of memory
    for (size_t i = 0; i < mCapacity; i++) {
        mMovies[i] = save[i]; // op=
    }

    mCapacity = newCapacity;
    delete[] save;
}

bool Movies::alreadyAdded(const char *name) const {
    for (size_t i = 0; i < mSize; i++) {
        if (strcmp(mMovies[i].getMovieName(), name) == 0) {
            return true;
        }
    }
    return false;
}

int Movies::movieIndex(const char *name) const {
    for (int i = 0; i < mSize; i++) {
        if (strcmp(mMovies[i].getMovieName(), name) == 0) {
            return i;
        }
    }
    return -1;
}

Movies::Movies() : mMovies(nullptr), mCapacity(DEFAULT_CAPACITY), mSize(0) {
    mMovies = new Movie[mCapacity]; // calls the default constructor of Movie
}

Movies::Movies(const Movies &other) {
    copy(other);
}

Movies &Movies::operator=(const Movies &other) {
    if (this == &other) {
        return *this;
    }
    free();
    copy(other);
    return *this;
}

Movies::~Movies() {
    delete[] mMovies;
}

bool Movies::addMovie(const char *name, size_t rating, size_t watched) {
    if (alreadyAdded(name)) {
        cout << "Movie has already been added!\n";
        return false;
    } else {
        mSize++;
        if (mSize == mCapacity) {
            size_t newCapacity = mCapacity + 3;
            resize(newCapacity);
        }
        mMovies[mSize - 1].initAddedMovie(name, rating, watched);
        return true;
    }
}

bool Movies::incrementByOne(const char *name) {
    if (!alreadyAdded(name)) {
        cout << "This movie doesn't exist in the collection\n";
        return false;
    } else {
        mMovies[movieIndex(name)].incrementWatched();
        return true;
    }
}

ostream &operator<<(ostream &out, const Movies &collection) {
    if (collection.mSize == 0) {
        out << "No movies to be displayed!\n";
    } else {
        out << "Movie collection info\n"
            << "Size: " << collection.mSize << '\n'
            << "Capacity: " << collection.mCapacity << '\n'
            << "Films:\n";
        for (size_t i = 0; i < collection.mSize; i++) {
            out << "Name: " << collection.mMovies[i].getMovieName() << " Rating: " << collection.mMovies[i].getRating() << " Watched: " << collection.mMovies[i].getWatched() << ' ';
        }
    }
    return out;
}