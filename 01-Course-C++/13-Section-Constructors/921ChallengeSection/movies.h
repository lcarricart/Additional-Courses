#ifndef MOVIES_H
#define MOVIES_H
#include <iostream>
#include <vector>
#include <string>
#include "movie.h"

using namespace std;

class Movies {
    vector<Movie> my_movies;
public:
    void display() const; //Agrego el 'const' para asegurar que no modifique.
    bool add_movie_vector(string name_val, string rating_val, int watched_val);
    bool increment_watched_vector(string name_val);
    
    Movies();
    ~Movies();
};

#endif