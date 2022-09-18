#include "Movie.h"
#include <cstring>
#include <iostream>
using namespace std;

void Movie::free() {
    delete[] mMovieName;
}

void Movie::copy(const Movie &other) {
    mMovieName = new char[strlen(other.mMovieName) + 1];
    strcpy_s(mMovieName, strlen(other.mMovieName) + 1, other.mMovieName);

    mRating = other.mRating;
    mWatched = other.mWatched;
}

Movie::Movie(const char *name, size_t rating, size_t watched) : mRating(rating), mWatched(watched) {
    // deep copy (otherwise mMovieName = name copies the pointers)
    mMovieName = new char[strlen(name) + 1];
    strcpy_s(mMovieName, strlen(name) + 1, name);
}

Movie::Movie(const Movie &other) {
    copy(other);
}

Movie &Movie::operator=(const Movie &other) {
    if (this == &other) {
        return *this;
    }
    // deep copy
    free();      // deallocate old dynamic mem
    copy(other); // allocate ne dynamic mem and initialize it
    return *this;
}

Movie::~Movie() {
    free();
}

void Movie::initAddedMovie(const char *name, size_t rating, size_t watched) {
    setName(name);
    setRating(rating);
    setWatched(watched);
}

void Movie::incrementWatched() {
    mWatched++;
}

// setters
void Movie::setName(const char *name) {
    mMovieName = new char[strlen(name) + 1];
    strcpy_s(mMovieName, strlen(name) + 1, name);
}

void Movie::setRating(size_t rating) {
    mRating = rating;
}

void Movie::setWatched(size_t watched) {
    mWatched = watched;
}

// getters
const char *Movie::getMovieName() const {
    return mMovieName; // returns a copy of the pointer
}

size_t Movie::getRating() const {
    return mRating; // returns a copy of the rating
}

size_t Movie::getWatched() const {
    return mWatched; // returns a copy of watched
}