#include <iostream>
#include <vector>
#include <string>
#include "movies.h"
//as I include the header, which includes also movie.h, it's also added for this file.

using namespace std;


Movies::Movies() { //I'll be creating the objects myself, by instance I want them empty at the beggining.
}

Movies::~Movies() {
}

void Movies::display() const { //That 'Movies::' tells the compiler to go look after the function in the header file.
    if (my_movies.size() != 0) {
        cout << "-----------------------------------------" << endl;
        for (auto &m : my_movies) { //Acá llamo a la dirección de mi variable, porque sino llamando la copia no puedo acceder a otras variables sujetas.
            cout << m.name << ", " << m.rating << ", " << m.watched << endl;
        };
        cout << "-----------------------------------------" << endl;
    } 
    else {
        cout << "No movies uploaded to the system." << endl << endl;
    }
}

bool Movies::add_movie_vector(string name_val, string rating_val, int watched_val) {
    for (const Movie &m: my_movies) { //Using the copy constructor inside a for???
        if (m.name == name_val)
            return false;
    }
    Movie temp {name_val, rating_val, watched_val};
    my_movies.push_back(temp);
    return true;
}

bool Movies::increment_watched_vector(string name_val) {
    for (Movie &m: my_movies) {
        if (m.name == name_val) {
            m.watched += 1;
            return true;
        }
    }
    return false;
}