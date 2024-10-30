#include <iostream>
#include "Base.h"
#include "Derived.h"

using namespace std;

int main()
{
	Base base;
    base.a = 100;
    //base.b = 200; 
    //base.c = 300;
    //Not possible.
    
    Derived d;
    d.a = 100; //Perfect.
    d.b = 200; //Can only modify its content through a member function. Its content would be accesible only via getters ins Base class.
    d.c = 300; //Dont have access.
    
	return 0;
}
