#include <iostream>

using namespace std;

/*
variable_type *pointer_name {nullptr};

int *int_ptr {};
double *double_ptr {nullptr};
string *string_ptr {nullptr}; 

Always initialize the pointers.
Initializing this way we are locating the pointers to 'nowhere', not to 0 or any number.
nullptr appears in C++11.
*/

/*
'sifeof variable_name' shows the ammount of bits necessary to store the variable, depending on it's type.
&num shows an hexagesimal expression of the location  of the variable (pointer).
*/

/*
The pointer can only store the type of variable for which is assigned. Although, this doesn't affect the size of the pointer,
'cause they're just positions. All pointers have 4 bits to be stored.
*/

int main()
{
	int *p;
    cout << "Value of p is: " << p << endl; //garbage
    cout << "Address of p is: " << &p << endl;
    cout << "Size of p is: " << sizeof p << endl;
    p = nullptr; //null value for pointers
    cout << "\nValue of p is: " << p << endl;
    //Before doing this I thought the value of the pointer should be the address related to it.
    

    
	return 0;
}
