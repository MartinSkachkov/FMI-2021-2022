#ifndef _MOVIES_H_
#define _MOVIES_H_
#include "Movie.h"
#include <fstream>
#define DEFAULT_CAPACITY 5

class Movies {
private:
    Movie *mMovies;
    size_t mSize;
    size_t mCapacity;

    void copy(const Movies &other);
    void free();
    void resize(size_t newCapacity);
    bool alreadyAdded(const char *name) const;
    int movieIndex(const char *name) const;

public:
    Movies(); // calls the Default constructor of Movie
    Movies(const Movies &other);
    Movies &operator=(const Movies &other);
    ~Movies();

    bool addMovie(const char *name, size_t rating, size_t watched);
    bool incrementByOne(const char *name);
    friend std::ostream &operator<<(std::ostream &out, const Movies &collection);
};

#endif