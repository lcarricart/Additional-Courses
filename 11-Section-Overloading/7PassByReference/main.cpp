#include <iostream>

using namespace std;

//To pass a parameter by reference we add a '&' at the beggining of the variable.

/*
Sometimes is useful to print() a vector by reference to not make multiple copies of the values inside the vector and wasting memory.
To accomplish this correctly (avoiding mistakes) it would be reccommended to define 'const vector<int> &vec'. I clarify this because it
doesn't seem to make sense to bring a constant by reference to a function, but it saves memory.
*/

void swap(int &a, int &b);

int main()
{
	int x{10}, y{20};
    cout << x << " " << y << endl;
    swap(x, y);
    cout << x << " " << y << endl;
     
	return 0;
}

void swap (int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}