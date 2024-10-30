#include <iostream>

/* If we don't wanna write this std::cout every time we have two choices:
 * 
 * using namespace std; --> command which will enable you to use the entire std namespace without calling it.
 * or
 * using std::cout; using std::cin; using std::endl; --> which will only enable that on these specific cases.
 * 
 * Second option might be useful for avoiding errors on using unporposed std's. */
 
using namespace std;
 
int main()
{
	int fav;
    
    cout << "Enter your fav number: ";
    cin >> fav;
    cout << "Amazing!! " << fav
         << " is also my favourite number!" << endl;
         
    return 0;
}
