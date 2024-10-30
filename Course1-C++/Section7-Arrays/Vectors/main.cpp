#include <iostream>

#include <vector>

using namespace std;

int main()
{
	//A vector is an object, that's why rules are different than arrays.
    //They're initialized automatically.
    vector <char> vowels {'a', 'e', 'i', 'o', 'u'};
    vector <int> test_scores {100, 98, 89};
    vector <double> temperatures (365, 80.1); //Sets size and the value of initialization.
    
    cout << vowels[2] << endl << vowels.at(2) << endl; 
    //Another way of working with objects, by using methods.
    
    //They present dinamyc size. Using push_back method we can add a value at the end of the vector.
    test_scores.push_back(80);
    cout << test_scores.at(3);
    
    //vector.size() is another useful method.
    
	return 0;
}
