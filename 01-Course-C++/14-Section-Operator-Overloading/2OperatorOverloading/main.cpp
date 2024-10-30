#include <iostream>
#include <Mystring.h>
#include <cstring>

/*READ: this could be significantly improved by creating global functions (non member functions) and allowing private access through friendships, avoiding getters.
There's an Udemy class in case I wanna see examples.
They're declared into the class when declaring the friendship (doesn't matter if in public or private), and implemented in the .cpp file.*/

using namespace std;

int main()
{

	cout << boolalpha << endl;
    
    Mystring larry{"Larry"};
    Mystring moe{"Moe"};
    
    Mystring stooge = larry;
    larry.display();
    moe.display();
    
    cout << (larry == moe) << endl;
    cout << (larry == stooge) << endl;
    
    larry.display();
    Mystring larry2 = -larry;
    larry2.display();
    
    Mystring stooges = larry + "Moe";
    //Mystring stooges = "Larry" + moe; Wouldn't wrok because of the order
    
    Mystring two_stooges = moe + " " + "Larry";
    two_stooges.display();
    
    Mystring three_stooges = moe + " " + larry + " " + "Curly";
    three_stooges.display();
    
	return 0;
}
