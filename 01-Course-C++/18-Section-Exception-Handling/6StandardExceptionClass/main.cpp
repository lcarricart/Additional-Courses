#include <iostream>
#include "IllegalBalanceException.h"

using namespace std;

/*In this project we're showing that we can also derive our exception classes from the Standard Exception class, which might have benefits
as the C++ Standard Library defines a rich set of exception classes that are derived from it.
When implementing the 'catch' function, the code is a bit different for this cases:

catch (const IllegalBalanceException &ex) {
    cerr << ex.what() << endl; //Displays "Illegal balance exception".
}

*/

int main()
{
	
    
	return 0;
}
