#ifndef _MOVIE_H_
#define _MOVIE_H
#include <cstdlib>

class Movie {
private:
    char *mMovieName;
    size_t mRating;
    size_t mWatched;

    void free();
    void copy(const Movie &other);

public:
    Movie(const char* name = "none", size_t rating = 0, size_t watched = 0);
    Movie(const Movie &other);
    Movie &operator=(const Movie &other);
    ~Movie();

    void initAddedMovie(const char *name, size_t rating, size_t watched);
    void incrementWatched();

    // setters
    void setName(const char *name);
    void setRating(size_t rating);
    void setWatched(size_t watched);

    // getters
    const char *getMovieName() const;
    size_t getRating() const;
    size_t getWatched() const;
};

#endif