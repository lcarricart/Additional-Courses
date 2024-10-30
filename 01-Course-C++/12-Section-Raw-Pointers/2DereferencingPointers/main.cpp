#include <iostream>
#include <string>
#include <vector>

using namespace std;

//Dereferencing pointers relates to get the information inside the address.

int main()
{
	int score {100}; //A regular value.
    int *score_ptr {&score}; //A parameter that points into score's direction. Or basically, I'm giving score by reference ('&').
    
    cout << *score_ptr << endl; //100
    
    *score_ptr = 200;
    cout << *score_ptr << endl; // This parameter (pointer) is defined as a reference of score, so they're the same value.
    cout << score << endl; //200. Asking for the value of a parameter.
    
    cout << "------------------------" << endl;
    
    vector<string> vec {"Larry", "Moe", "Curly"};
    vector<string> *vec_ptr {nullptr};
    
    vec_ptr = &vec;
    
    cout << "First value: " << (*vec_ptr).at(0) << endl; //Larry
    
    cout << "Vector content: ";
    for (auto contador: *vec_ptr) //counter: vec
        cout << contador << " ";
    cout << endl << endl;
    
    /*We can use variable_ptr = new (type) to allocate a variable on the heap (dynamic memory allocation).
    Then use delete variable_ptr to free the allocated storage to be used later again.*/
    
	return 0;
}
