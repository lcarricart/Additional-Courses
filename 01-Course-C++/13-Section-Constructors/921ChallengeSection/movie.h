#ifndef MOVIE_H
#define MOVIE_H
#include <iostream>
#include <string>

using namespace std;

class Movie {
    friend class Movies; //I include all the class 'cause I need the access for all the functions.
    std::string name;
    std::string rating;
    int watched;
public:
    Movie(string name_val, string rating_val, int watched_val); //Constructor
    Movie(const Movie &source);
    ~Movie();
};

#endif