#include "Movies.h"
#include <iostream>
using namespace std;

void increment_watched(Movies &collection, const char *name) {
    if (collection.incrementByOne(name)) {
        cout << name << " successfully incremented by one!\n";
    } else {
        cout << name << "wasn't incremented by one!\n";
    }
}

void add_movie(Movies &collection, const char *name, size_t rating, size_t watched) {
    if (collection.addMovie(name, rating, watched)) {
        cout << name << " has been successfully added!\n";
    } else {
        cout << name << " hasn't been successfully added!\n";
    }
}

int main() {
    Movies my_movies; // calls the default constructor
    cout << my_movies;

    add_movie(my_movies, "Big", 1, 2);        // OK
    add_movie(my_movies, "Star Wars", 2, 5);  // OK
    add_movie(my_movies, "Cinderella", 3, 7); // OK

    cout << my_movies; // Big, Star Wars, Cinderella

    add_movie(my_movies, "Cinderella", 4, 7); // Already exists
    add_movie(my_movies, "Ice Age", 5, 12);   // OK

    cout << my_movies; // Big, Star Wars, Cinderella, Ice Age

    increment_watched(my_movies, "Big");     // OK
    increment_watched(my_movies, "Ice Age"); // OK

    cout << my_movies; // Big and Ice Age watched count incremented by 1

    increment_watched(my_movies, "XXX"); // XXX not found
    return 0;
}