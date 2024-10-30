#include <iostream>
#include <cstring>
#include "Mystring.h"

/*In this project we're trying to define a 'string' object that works the same way as the default one, to understan how self defined 
operators works. This allow us to operate with objects the way we want it to be.*/

using namespace std;

int main()
{
	Mystring empty;
    Mystring larry{"Larry"};
    Mystring stooge {larry};
    
    empty.display();
    larry.display();
    stooge.display();
    
    Mystring a {"Hello"};
    Mystring b;
    b = a;
    cout << b.get_str();
    
    /*The copy assignment is efficient for assigning objects to objects, but when it comes to r-values it could be improved using a move assignment.
    This is because on the move assignment we transfer the pointer (as it is not needed for the r-value), meanwhile in the copy assignment  
    we copy the value to a new pointer (because we gotta keep the pointer to both objects), which takes more work.*/
    
    //As the right hand value is an r-value, the compiler will take the overloaded operator referred to r-values (move constructor).
    b = "This is a test";
    cout << b.get_str();
    
    
	return 0;
}
