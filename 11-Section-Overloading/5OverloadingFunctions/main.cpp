#include <iostream>

using namespace std;

/*The idea is to have two different function calls for the same function, depending on the type of the arguments.

int add_numbers (int, int) {
    return a + b;
}
double add_numbers(double, double) {
    return a + b;
}

int main()
{
	cout << add_numbers(10,20) << endl;
    cout << add_numbers(10.0,20.0) << endl;
	return 0;
}*/

/*
Another example would be with a display function.

void display(int n); 
void display(double d);
void display(std::string s);
void display(std::string s, std::string t);
void display(std::vector<int> v);
void display(std::vector<std::string> v);

If the program cannot match the type to any function and is also not able to convert the value to a useful one, then shows an error. 
Characters, if needed, are converted into integers.
C-style strings, if needed, are converted into C++ strings (objects).

We can still use default parameters on this kind of multiple functions, but as it's obvious, the default parameters can only be defined on one of them, for avoiding ambiguous situations.

Another error could be shown if we have: - int get_value(); - double get value(); and in the main program I just call the function. It doesn't know which to use.
Then this function selection doesn't work for return values, only with parameters.
*/