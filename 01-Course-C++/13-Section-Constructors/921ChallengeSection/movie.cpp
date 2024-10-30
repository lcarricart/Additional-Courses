/*At the beggining I had a big problem at separating the classes into two different header files, and the problem was all because of
including a header into a file when it was not necessary. I might have thought that shouldn't change much, but including extra files
results into this barely unspottable errors. (I was including 'movies.h' in 'movie.h').*/

#include <iostream>
#include <string>
#include "movie.h"

using namespace std;

Movie::Movie(string name_val, string rating_val, int watched_val)
    : name(name_val), rating(rating_val), watched(watched_val) {
    }

Movie::Movie(const Movie &source)
    : Movie(source.name, source.rating, source.watched) {
    }

Movie::~Movie() {
}
