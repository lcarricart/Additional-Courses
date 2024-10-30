#include <iostream>

#include <vector>

using namespace std;

int main()
{
	//Example of a 2D vector. You have to create a vector of vectors.
    vector <vector<int>> movie_ratings
    {
        {1,2,3,4},
        {2,2,3,4},
        {3,2,3,4}
    };
    
    cout << "\nHere're the movie ratings for reviewer 1 using array syntax: " << endl;
    cout << movie_ratings[0][0] << endl;
    cout << movie_ratings[0][1] << endl;
    cout << movie_ratings[0][2] << endl;
    cout << movie_ratings[0][3] << endl;
    
    cout << "\nHere're the movie ratings for reviewer 1 using vector syntax: " << endl;
    cout << movie_ratings.at(0).at(0) << endl;
    cout << movie_ratings.at(0).at(1) << endl;
    cout << movie_ratings.at(0).at(2) << endl;
    cout << movie_ratings.at(0).at(3) << endl;
    
	return 0;
}
