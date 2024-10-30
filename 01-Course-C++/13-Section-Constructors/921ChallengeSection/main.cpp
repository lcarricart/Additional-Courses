//Guidance code provided by the exercise. My task is to implement all the classes.

/******************************************************************
 * Section 13 Challenge
 * main.cpp
 * 
 * Test the Movies project
 * 
 * ***************************************************************/
#include <iostream>
#include "movies.h"

// Function prototypes
void increment_watched(Movies &movies, std::string name);
void add_movie(Movies &my_movies, std::string name, std::string rating, int watched);

/******************************************************************
 * increment_watched expects a reference to a Movies object 
 * and the name of the movie to increment the watched count
 *
 * If the watched count was incremented successfully it
 * displays a success message
 * otherwise the watched count could not be incremented
 * because the name of the movie was not found
 * ***************************************************************/

void increment_watched(Movies &my_movies, string name_val) {
    if (my_movies.increment_watched_vector(name_val)) {
        cout << name_val << " watch incremented" <<  endl;
    } else {
        cout << name_val << " not found" <<  endl;
    }
}

/******************************************************************
 * add_movie expects a reference to a Movies object 
 * and the name of the movie, the rating and the watched count
 *
 * If the movie was successfully added to the movies object it
 * displays a success message
 * otherwise the movie was not added 
 * because the name of the movie was already in movies
 * ***************************************************************/
void add_movie(Movies &my_movies, std::string name, std::string rating, int watched) {
    if (my_movies.add_movie_vector(name,rating,watched)) {
        std::cout << name << " added" << std::endl;
    } else {
        std::cout << name << " already exists" <<  std::endl;
    }
}

int main() {
    
    Movies my_movies;
    
    my_movies.display(); //There's no need to specify that the function (method) is from 'Movies' because my object already is.
    
    add_movie(my_movies, "Big", "PG-13", 2); 
    /*I wanted to do it directly by a method ('my_movies.add_movie_vector("Big", "PG-13", 2);') but there were many complications in the logic,
    is better doing it this way, against my willingness.*/
    add_movie(my_movies, "Star Wars", "PG", 5);
    add_movie(my_movies, "Cinderella", "PG", 7);
     
    my_movies.display();   // Big, Star Wars, Cinderella
    
    add_movie(my_movies, "Cinderella", "PG",7);     // Already exists
    add_movie(my_movies, "Ice Age", "PG",12);       // OK
 
    my_movies.display();    // Big, Star Wars, Cinderella, Ice Age
    
    increment_watched(my_movies,"Big");            // OK
    increment_watched(my_movies,"Ice Age");        // OK
    
    my_movies.display();    // Big and Ice Age watched count incremented by 1
    
    increment_watched(my_movies,"XXX");            // XXX not found

	return 0;
    /*!! Ahora que entendí cómo funciona todo, tengo que separar los archivos de clases para Movie y Movies, y hacer que
    los public y private queden bien definidos !! */
}
