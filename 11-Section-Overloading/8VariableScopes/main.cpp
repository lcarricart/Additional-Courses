#include <iostream>

using namespace std;

int num {300}; //Global variable. Can be used in all functions below.

void funct() {
    static int num {5000}; //I think static is used to create global variables. Seems very useful.
}

int main()
{    
	return 0;
}
