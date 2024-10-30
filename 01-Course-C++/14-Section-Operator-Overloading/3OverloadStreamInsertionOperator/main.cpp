#include <iostream>
#include <cstring>
#include "Mystring.h"

using namespace std;

/*Declaring specific behaviour for the stream insertion and extraction operator could be very useful operating with objects. Lets see:
Player hero {"Hero", 100, 33};
cout << hero << endl; // {name: Hero, health: 100, xp: 33}
*/

int main()
{
	Mystring larry {"Larry"};
    Mystring moe {"Moe"};
    Mystring curly;
    
    cout << "Enter the third stooge's first name: ";
    cin >> curly;
    
    cout << "The three stooges are " << larry << ", " << moe << ", and " << curly << endl;
    
    cout << "\nEnter three stooges separated by a space: ";
    cin >> larry >> moe >> curly;
    
    cout << "The three stooges are " << larry << ", " << moe << ", and " << curly << endl;
    
	return 0;
}
