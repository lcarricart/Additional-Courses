#include <iostream>

using namespace std;

/*
When I pass an array to a function, I'm giving the location address to the function (of the first value), but it doesn't know indeed how many values are stored on it.
So, if my intention is to create a functions which displays the values of an array, I'm gonna have to create a parameter which will be the size of the array, to know the number of iterations.
*/

void print_array(int numbers [], size_t size);

int main()
{
	int my_numbers [] {1,2,3,4,5};
    print_array(my_numbers, 5);
    
	return 0;
}

void print_array(int numbers[], size_t size) {
    for (size_t i{0}; i < size; i++)
        cout << numbers[i] << endl;
    /*
    Note that I can modify the array by calling the address location: array[0] = 0; I'm changing the value stored.
    If I want a function to NOT be able to modify an array, I specify a 'const' type for the array parameter, showing error each time somebody wants to modify it.
    */
}